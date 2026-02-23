"""
Test Queue Manager
Handles ordering, execution, retry logic, and status tracking for test scripts.
Supports: Python scripts, Vector CANoe scripts, Lauterbach .cmm scripts
"""

import queue
import threading
import time
from dataclasses import dataclass, field
from enum import Enum, auto
from pathlib import Path
from typing import Callable, Optional
import traceback


class TestType(Enum):
    PYTHON = "python"
    CANOE = "canoe"
    CMM = "cmm"  # Trace32/Lauterbach


class TestStatus(Enum):
    PENDING = auto()
    RUNNING = auto()
    PASSED = auto()
    FAILED = auto()
    SKIPPED = auto()
    ABORTED = auto()


@dataclass
class TestItem:
    name: str
    script_path: str
    test_type: TestType
    parameters: dict = field(default_factory=dict)
    retries: int = 0
    max_retries: int = 1
    timeout: int = 300  # seconds
    status: TestStatus = TestStatus.PENDING
    result_message: str = ""
    start_time: Optional[float] = None
    end_time: Optional[float] = None
    enabled: bool = True

    @property
    def duration(self) -> Optional[float]:
        if self.start_time and self.end_time:
            return round(self.end_time - self.start_time, 2)
        return None

    def to_dict(self) -> dict:
        return {
            "name": self.name,
            "script": self.script_path,
            "type": self.test_type.value,
            "status": self.status.name,
            "result": self.result_message,
            "duration": self.duration,
            "enabled": self.enabled,
        }


class TestQueueManager:
    """
    Queue-based test execution engine.
    Tests run sequentially; each runner is dispatched to the correct executor.
    """

    def __init__(self, logger, context: dict):
        self.logger = logger.get_logger("queue")
        self.tester_logger = logger
        self.context = context  # shared hardware handles
        self._queue: list[TestItem] = []
        self._lock = threading.Lock()
        self._running = False
        self._stop_event = threading.Event()
        self._current_test: Optional[TestItem] = None
        self._on_status_change: Optional[Callable] = None

    # ── Public API ────────────────────────────────────────────────────────────

    def add_test(self, item: TestItem):
        with self._lock:
            self._queue.append(item)
        self.logger.info(f"Queued: {item.name} ({item.test_type.value})")

    def remove_test(self, index: int):
        with self._lock:
            if 0 <= index < len(self._queue):
                removed = self._queue.pop(index)
                self.logger.info(f"Removed from queue: {removed.name}")

    def move_test(self, from_idx: int, to_idx: int):
        with self._lock:
            items = self._queue
            if 0 <= from_idx < len(items) and 0 <= to_idx < len(items):
                items.insert(to_idx, items.pop(from_idx))

    def clear_queue(self):
        with self._lock:
            self._queue.clear()

    def get_queue(self) -> list[TestItem]:
        with self._lock:
            return list(self._queue)

    def set_status_callback(self, cb: Callable):
        self._on_status_change = cb

    def start(self):
        if self._running:
            return
        self._running = True
        self._stop_event.clear()
        threading.Thread(target=self._run_loop, daemon=True).start()
        self.logger.info("Test queue started.")

    def stop(self):
        self._stop_event.set()
        self._running = False
        self.logger.info("Test queue stop requested.")

    def abort_current(self):
        if self._current_test:
            self._current_test.status = TestStatus.ABORTED
            self.logger.warning(f"Aborted: {self._current_test.name}")

    # ── Internal ──────────────────────────────────────────────────────────────

    def _run_loop(self):
        while not self._stop_event.is_set():
            item = self._next_pending()
            if item is None:
                time.sleep(0.5)
                continue
            self._execute(item)
        self._running = False

    def _next_pending(self) -> Optional[TestItem]:
        with self._lock:
            for item in self._queue:
                if item.status == TestStatus.PENDING and item.enabled:
                    return item
        return None

    def _execute(self, item: TestItem):
        self._current_test = item
        item.status = TestStatus.RUNNING
        item.start_time = time.time()
        self.logger.info(f"▶ Running: {item.name}")
        self._notify()

        try:
            if item.test_type == TestType.PYTHON:
                self._run_python(item)
            elif item.test_type == TestType.CANOE:
                self._run_canoe(item)
            elif item.test_type == TestType.CMM:
                self._run_cmm(item)
        except Exception as e:
            item.result_message = traceback.format_exc()
            item.status = TestStatus.FAILED
            self.logger.error(f"✘ FAILED: {item.name}\n{item.result_message}")
        finally:
            item.end_time = time.time()
            self._current_test = None
            self.tester_logger.log_test_result(
                item.name, item.status.name, item.result_message
            )
            self._notify()

    def _run_python(self, item: TestItem):
        import importlib.util
        spec = importlib.util.spec_from_file_location("test_module", item.script_path)
        mod = importlib.util.module_from_spec(spec)
        # Inject context (hardware handles) into the module namespace
        mod.__dict__.update(self.context)
        spec.loader.exec_module(mod)
        if hasattr(mod, "run"):
            result = mod.run(item.parameters)
            if result is False:
                raise RuntimeError("Script run() returned False (test failed).")
            item.result_message = str(result) if result else "PASS"
            item.status = TestStatus.PASSED
        else:
            raise AttributeError(f"Python script {item.script_path} has no run() function.")

    def _run_canoe(self, item: TestItem):
        canoe = self.context.get("canoe")
        if canoe is None:
            raise RuntimeError("CANoe interface not initialized.")
        canoe.run_script(item.script_path, item.parameters, item.timeout)
        item.result_message = "CANoe script completed."
        item.status = TestStatus.PASSED

    def _run_cmm(self, item: TestItem):
        trace32 = self.context.get("trace32")
        if trace32 is None:
            raise RuntimeError("Trace32 interface not initialized.")
        trace32.run_cmm(item.script_path, item.parameters, item.timeout)
        item.result_message = "CMM script completed."
        item.status = TestStatus.PASSED

    def _notify(self):
        if self._on_status_change:
            try:
                self._on_status_change()
            except Exception:
                pass
