"""
Queue-based test runner.

Accepts a heterogeneous queue of test items (Python, CMM, CANoe) and executes
them sequentially, with optional retry, status callbacks, and logging.
"""
from __future__ import annotations

import importlib.util
import logging
import os
import queue
import sys
import threading
import time
import traceback
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Callable, Dict, List, Optional

from core.logger import Logger

logger = logging.getLogger(__name__)


# ---------------------------------------------------------------------------
# Data types
# ---------------------------------------------------------------------------

class TestType(str, Enum):
    """Supported test item types."""
    PYTHON = "python"
    CMM = "cmm"
    CANOE = "canoe"


class TestStatus(str, Enum):
    """Lifecycle states for a single test item."""
    QUEUED = "QUEUED"
    RUNNING = "RUNNING"
    SUCCESS = "SUCCESS"
    FAILED = "FAILED"
    ERROR = "ERROR"
    SKIPPED = "SKIPPED"


@dataclass
class TestItem:
    """Describes a single test to be executed.

    Attributes:
        name:       Human-readable label.
        test_type:  One of :class:`TestType`.
        path:       Absolute path to the script/config file.
        params:     Optional key-value parameters passed to Python tests.
        retry_count: Number of additional attempts on failure (0 = no retry).
    """
    name: str
    test_type: TestType
    path: str
    params: Dict[str, Any] = field(default_factory=dict)
    retry_count: int = 0


@dataclass
class TestResult:
    """Outcome of a single test execution attempt."""
    item: TestItem
    status: TestStatus
    message: str = ""
    telemetry: Dict[str, Any] = field(default_factory=dict)
    duration_s: float = 0.0


# Type alias for the status-update callback
StatusCallback = Callable[[TestResult], None]


# ---------------------------------------------------------------------------
# Runner
# ---------------------------------------------------------------------------

class TestRunner:
    """Executes a queue of :class:`TestItem` objects in a background thread.

    Usage::

        runner = TestRunner(log_manager=my_logger)
        runner.set_interfaces(trace32=t32, canoe=coe)
        runner.add(TestItem("boot_check", TestType.CMM, "/tests/boot.cmm"))
        runner.add(TestItem("voltage_test", TestType.PYTHON, "/tests/volts.py"))
        runner.start(status_callback=my_callback)
        # … later …
        runner.stop()
    """

    def __init__(
        self,
        log_manager: Optional[Logger] = None,
        auto_retry: bool = True,
        retry_count: int = 1,
        timeout: float = 300.0,
    ) -> None:
        self._log_manager = log_manager
        self._auto_retry = auto_retry
        self._default_retry_count = retry_count if auto_retry else 0
        self._timeout = timeout

        self._queue: queue.Queue[TestItem] = queue.Queue()
        self._results: List[TestResult] = []
        self._worker_thread: Optional[threading.Thread] = None
        self._stop_event = threading.Event()
        self._running = False

        # Optional interface references injected externally
        self._trace32: Optional[Any] = None
        self._canoe: Optional[Any] = None

    # ------------------------------------------------------------------
    # Configuration
    # ------------------------------------------------------------------

    def set_interfaces(
        self,
        trace32: Optional[Any] = None,
        canoe: Optional[Any] = None,
    ) -> None:
        """Inject hardware interface objects.

        Args:
            trace32: :class:`~interfaces.trace32_interface.Trace32Interface` instance.
            canoe:   :class:`~interfaces.canoe_interface.CANoeInterface` instance.
        """
        self._trace32 = trace32
        self._canoe = canoe

    # ------------------------------------------------------------------
    # Queue management
    # ------------------------------------------------------------------

    def add(self, item: TestItem) -> None:
        """Enqueue a test item.

        Args:
            item: :class:`TestItem` to append to the run queue.
        """
        self._queue.put(item)
        logger.debug("Queued: [%s] %s", item.test_type.value, item.name)

    def clear(self) -> None:
        """Drain the pending queue (does not affect a running test)."""
        while not self._queue.empty():
            try:
                self._queue.get_nowait()
            except queue.Empty:
                break
        logger.info("Test queue cleared.")

    # ------------------------------------------------------------------
    # Execution
    # ------------------------------------------------------------------

    def start(self, status_callback: Optional[StatusCallback] = None) -> None:
        """Start the worker thread that drains the queue.

        Args:
            status_callback: Called after each test completes with its :class:`TestResult`.
        """
        if self._running:
            logger.warning("TestRunner is already running.")
            return
        self._stop_event.clear()
        self._running = True
        self._worker_thread = threading.Thread(
            target=self._worker,
            args=(status_callback,),
            daemon=True,
            name="TestRunnerWorker",
        )
        self._worker_thread.start()
        logger.info("TestRunner started.")

    def stop(self) -> None:
        """Signal the worker to stop after the current test finishes."""
        self._stop_event.set()
        self._running = False
        logger.info("TestRunner stop requested.")

    def wait(self, timeout: Optional[float] = None) -> None:
        """Block until the worker thread exits or *timeout* seconds pass."""
        if self._worker_thread is not None:
            self._worker_thread.join(timeout=timeout)

    @property
    def is_running(self) -> bool:
        """True while the worker thread is active."""
        return self._running

    @property
    def results(self) -> List[TestResult]:
        """Accumulated results for all completed tests in this session."""
        return list(self._results)

    # ------------------------------------------------------------------
    # Worker internals
    # ------------------------------------------------------------------

    def _worker(self, callback: Optional[StatusCallback]) -> None:
        """Main loop executed in the background thread."""
        while not self._stop_event.is_set():
            try:
                item = self._queue.get(timeout=0.5)
            except queue.Empty:
                continue

            result = self._execute_with_retry(item)
            self._results.append(result)

            if self._log_manager:
                self._log_manager.log_result(
                    item.name,
                    result.status.value,
                    {"message": result.message, "duration_s": result.duration_s, **result.telemetry},
                )

            if callback:
                try:
                    callback(result)
                except Exception as exc:
                    logger.warning("Status callback raised: %s", exc)

            self._queue.task_done()

        self._running = False
        logger.info("TestRunner worker exited.")

    def _execute_with_retry(self, item: TestItem) -> TestResult:
        """Run *item*, retrying up to item.retry_count times on failure."""
        max_attempts = 1 + (
            item.retry_count if item.retry_count > 0 else self._default_retry_count
        )
        result = TestResult(item=item, status=TestStatus.ERROR)
        for attempt in range(1, max_attempts + 1):
            if attempt > 1:
                logger.info("Retrying [%s] %s (attempt %d/%d)…", item.test_type.value, item.name, attempt, max_attempts)
            result = self._execute_once(item)
            if result.status == TestStatus.SUCCESS:
                break
        return result

    def _execute_once(self, item: TestItem) -> TestResult:
        """Dispatch a single test execution and capture timing + outcome."""
        start = time.monotonic()
        result = TestResult(item=item, status=TestStatus.RUNNING)
        try:
            if item.test_type == TestType.PYTHON:
                result = self._run_python(item)
            elif item.test_type == TestType.CMM:
                result = self._run_cmm(item)
            elif item.test_type == TestType.CANOE:
                result = self._run_canoe(item)
            else:
                result.status = TestStatus.ERROR
                result.message = f"Unknown test type: {item.test_type}"
        except Exception as exc:
            result.status = TestStatus.ERROR
            result.message = traceback.format_exc()
            logger.error("Unhandled exception running %s: %s", item.name, exc)
        result.duration_s = round(time.monotonic() - start, 3)
        return result

    # ------------------------------------------------------------------
    # Type-specific runners
    # ------------------------------------------------------------------

    def _run_python(self, item: TestItem) -> TestResult:
        """Import and run a Python test script as a module.

        The script must expose a ``run(**params)`` function that returns
        a truthy value on success.
        """
        result = TestResult(item=item, status=TestStatus.ERROR)
        if not os.path.isfile(item.path):
            result.message = f"File not found: {item.path}"
            return result
        spec = importlib.util.spec_from_file_location(item.name, item.path)
        if spec is None or spec.loader is None:
            result.message = "Could not load module spec."
            return result
        module = importlib.util.module_from_spec(spec)
        try:
            spec.loader.exec_module(module)  # type: ignore[attr-defined]
        except Exception as exc:
            result.message = f"Module load error: {exc}"
            return result
        if not hasattr(module, "run"):
            result.message = "Python test has no 'run()' function."
            return result
        try:
            ret = module.run(**item.params)
            if ret:
                result.status = TestStatus.SUCCESS
                result.message = str(ret) if not isinstance(ret, bool) else "OK"
                if isinstance(ret, dict):
                    result.telemetry = ret
            else:
                result.status = TestStatus.FAILED
                result.message = "run() returned falsy value."
        except AssertionError as exc:
            result.status = TestStatus.FAILED
            result.message = f"Assertion failed: {exc}"
        except Exception as exc:
            result.status = TestStatus.ERROR
            result.message = traceback.format_exc()
        return result

    def _run_cmm(self, item: TestItem) -> TestResult:
        """Execute a Trace32 CMM script."""
        result = TestResult(item=item, status=TestStatus.ERROR)
        if self._trace32 is None:
            result.message = "Trace32 interface not set."
            return result
        success = self._trace32.run_cmm(item.path)
        if success:
            result.status = TestStatus.SUCCESS
            result.message = "CMM completed."
        else:
            result.status = TestStatus.FAILED
            result.message = self._trace32.get_error() or "CMM script failed."
        return result

    def _run_canoe(self, item: TestItem) -> TestResult:
        """Run a Vector CANoe configuration/script."""
        result = TestResult(item=item, status=TestStatus.ERROR)
        if self._canoe is None:
            result.message = "CANoe interface not set."
            return result
        success = self._canoe.run_script(item.path)
        if success:
            result.status = TestStatus.SUCCESS
            state = self._canoe.get_measurement_state() or "unknown"
            result.message = f"CANoe measurement state: {state}"
        else:
            result.status = TestStatus.FAILED
            result.message = "CANoe script/measurement failed to start."
        return result
