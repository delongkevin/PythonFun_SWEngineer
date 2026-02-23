"""
Centralized logging system for the Automotive Tester.
All sessions are logged to timestamped files in the logs/ directory.
"""

import logging
import os
from datetime import datetime
from pathlib import Path


class TesterLogger:
    """Manages all logging for a test session."""

    def __init__(self, log_dir: str = "logs"):
        self.log_dir = Path(log_dir)
        self.log_dir.mkdir(parents=True, exist_ok=True)
        self.session_id = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.session_dir = self.log_dir / self.session_id
        self.session_dir.mkdir(parents=True, exist_ok=True)
        self._loggers: dict[str, logging.Logger] = {}
        self.main_log = self._create_logger("main", "main.log")

    def _create_logger(self, name: str, filename: str) -> logging.Logger:
        logger = logging.getLogger(f"tester.{self.session_id}.{name}")
        logger.setLevel(logging.DEBUG)
        # File handler
        fh = logging.FileHandler(self.session_dir / filename)
        fh.setLevel(logging.DEBUG)
        # Console handler
        ch = logging.StreamHandler()
        ch.setLevel(logging.INFO)
        formatter = logging.Formatter(
            "%(asctime)s [%(levelname)s] %(name)s: %(message)s",
            datefmt="%Y-%m-%d %H:%M:%S",
        )
        fh.setFormatter(formatter)
        ch.setFormatter(formatter)
        logger.addHandler(fh)
        logger.addHandler(ch)
        self._loggers[name] = logger
        return logger

    def get_logger(self, name: str) -> logging.Logger:
        if name not in self._loggers:
            return self._create_logger(name, f"{name}.log")
        return self._loggers[name]

    def log_test_result(self, test_name: str, status: str, details: str = ""):
        result_log = self.get_logger("test_results")
        result_log.info(f"TEST: {test_name} | STATUS: {status} | {details}")
        # Also write a structured CSV entry
        csv_path = self.session_dir / "results.csv"
        write_header = not csv_path.exists()
        with open(csv_path, "a") as f:
            if write_header:
                f.write("timestamp,test_name,status,details\n")
            ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            f.write(f'{ts},"{test_name}","{status}","{details}"\n')

    @property
    def session_path(self) -> Path:
        return self.session_dir
