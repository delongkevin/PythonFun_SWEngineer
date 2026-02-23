"""
Timestamped log manager for Automotive Tester.

Creates a unique log directory for every test run and writes structured
entries to both a rotating file and the console.
"""
from __future__ import annotations

import json
import logging
import logging.handlers
import os
import time
from datetime import datetime
from typing import Any, Dict, Optional

# Public logger name used throughout the application
APP_LOGGER = "automotive_tester"


def _level_from_str(level: str) -> int:
    """Convert a level name string to a logging level integer."""
    return getattr(logging, level.upper(), logging.INFO)


class Logger:
    """Central logging manager.

    Creates a timestamped run directory and configures both a file handler
    (rotating, 5 MB × 3 backups) and a stream handler for the console.

    Usage::

        log_mgr = Logger(log_dir="logs", level="INFO")
        log_mgr.start_run("test_suite_1")
        log_mgr.log_result("example_test.py", "SUCCESS", {"voltage": 12.1})
        log_mgr.end_run()
    """

    def __init__(self, log_dir: str = "logs", level: str = "INFO") -> None:
        self._base_log_dir = os.path.abspath(log_dir)
        self._level = _level_from_str(level)
        self._run_dir: Optional[str] = None
        self._run_log_path: Optional[str] = None
        self._results_path: Optional[str] = None
        self._file_handler: Optional[logging.Handler] = None
        self._run_start_time: Optional[float] = None
        self._run_results: list = []

        # Configure root application logger
        self._logger = logging.getLogger(APP_LOGGER)
        self._logger.setLevel(self._level)

        # Console handler (always present)
        if not any(isinstance(h, logging.StreamHandler) for h in self._logger.handlers):
            ch = logging.StreamHandler()
            ch.setLevel(self._level)
            ch.setFormatter(_build_formatter())
            self._logger.addHandler(ch)

    # ------------------------------------------------------------------
    # Run lifecycle
    # ------------------------------------------------------------------

    def start_run(self, run_name: str = "") -> str:
        """Create a new timestamped directory for this test run.

        Args:
            run_name: Optional label appended to the directory name.

        Returns:
            Absolute path to the run log directory.
        """
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        dir_name = f"{timestamp}_{run_name}" if run_name else timestamp
        self._run_dir = os.path.join(self._base_log_dir, dir_name)
        os.makedirs(self._run_dir, exist_ok=True)

        self._run_log_path = os.path.join(self._run_dir, "run.log")
        self._results_path = os.path.join(self._run_dir, "results.json")
        self._run_start_time = time.monotonic()
        self._run_results = []

        # Add rotating file handler for this run
        self._remove_file_handler()
        fh = logging.handlers.RotatingFileHandler(
            self._run_log_path,
            maxBytes=5 * 1024 * 1024,
            backupCount=3,
            encoding="utf-8",
        )
        fh.setLevel(self._level)
        fh.setFormatter(_build_formatter())
        self._file_handler = fh
        self._logger.addHandler(fh)

        self._logger.info("=== Test run started: %s ===", run_name or timestamp)
        return self._run_dir

    def end_run(self) -> Optional[str]:
        """Finalise the run: flush results JSON and remove the file handler.

        Returns:
            Path to the results.json file, or None if no run was active.
        """
        if self._run_dir is None:
            return None

        elapsed = time.monotonic() - (self._run_start_time or 0)
        summary = {
            "run_dir": self._run_dir,
            "elapsed_seconds": round(elapsed, 2),
            "total": len(self._run_results),
            "passed": sum(1 for r in self._run_results if r.get("status") == "SUCCESS"),
            "failed": sum(1 for r in self._run_results if r.get("status") == "FAILED"),
            "errored": sum(1 for r in self._run_results if r.get("status") == "ERROR"),
            "results": self._run_results,
        }
        if self._results_path:
            with open(self._results_path, "w", encoding="utf-8") as fh:
                json.dump(summary, fh, indent=2)

        self._logger.info(
            "=== Run finished: %d passed / %d failed / %d errored (%.1fs) ===",
            summary["passed"],
            summary["failed"],
            summary["errored"],
            elapsed,
        )
        self._remove_file_handler()
        path = self._results_path
        self._run_dir = None
        return path

    # ------------------------------------------------------------------
    # Result recording
    # ------------------------------------------------------------------

    def log_result(
        self,
        test_name: str,
        status: str,
        details: Optional[Dict[str, Any]] = None,
    ) -> None:
        """Record the outcome of a single test item.

        Args:
            test_name: Name or path of the test.
            status:    'SUCCESS', 'FAILED', 'ERROR', or 'SKIPPED'.
            details:   Optional key/value telemetry or error info.
        """
        entry = {
            "test": test_name,
            "status": status,
            "timestamp": datetime.now().isoformat(),
            "details": details or {},
        }
        self._run_results.append(entry)
        self._logger.info(
            "[%s] %s – %s",
            status,
            test_name,
            json.dumps(details) if details else "",
        )

    def log_telemetry(self, source: str, data: Dict[str, Any]) -> None:
        """Write a telemetry snapshot to the run log.

        Args:
            source: Label identifying the data source (e.g. 'power_supply').
            data:   Dictionary of metric names → values.
        """
        self._logger.info("[TELEMETRY][%s] %s", source, json.dumps(data))

    def log_error(self, source: str, message: str) -> None:
        """Write an error entry to the run log."""
        self._logger.error("[ERROR][%s] %s", source, message)

    # ------------------------------------------------------------------
    # Convenience passthrough
    # ------------------------------------------------------------------

    @property
    def run_dir(self) -> Optional[str]:
        """Current run log directory, or None if no run is active."""
        return self._run_dir

    @property
    def logger(self) -> logging.Logger:
        """The underlying :class:`logging.Logger` instance."""
        return self._logger

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _remove_file_handler(self) -> None:
        """Detach and close the current file handler if any."""
        if self._file_handler is not None:
            self._logger.removeHandler(self._file_handler)
            self._file_handler.close()
            self._file_handler = None


def _build_formatter() -> logging.Formatter:
    """Return a consistent log formatter."""
    return logging.Formatter(
        fmt="%(asctime)s [%(levelname)-8s] %(name)s: %(message)s",
        datefmt="%Y-%m-%d %H:%M:%S",
    )


def get_logger(name: str = APP_LOGGER) -> logging.Logger:
    """Convenience function to retrieve a child logger.

    Args:
        name: Dotted logger name.

    Returns:
        A :class:`logging.Logger` instance.
    """
    return logging.getLogger(name)
