"""
Unit tests for TestRunner and Logger.

All hardware dependencies are mocked.
"""
from __future__ import annotations

import os
import sys
import tempfile
import time
import types
import unittest
from unittest.mock import MagicMock, patch

# ---------------------------------------------------------------------------
# Stubs for optional heavy packages (same approach as test_interfaces.py)
# ---------------------------------------------------------------------------

def _stub(name: str) -> None:
    if name not in sys.modules:
        sys.modules[name] = types.ModuleType(name)

for _pkg in ("lauterbach", "lauterbach.trace32", "lauterbach.trace32.rcl",
             "cv2", "PIL", "PIL.Image", "PIL.ImageTk",
             "win32com", "win32com.client"):
    _stub(_pkg)

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from core.logger import Logger
from core.test_runner import TestItem, TestRunner, TestStatus, TestType


# ===========================================================================
# Logger tests
# ===========================================================================

class TestLogger(unittest.TestCase):

    def setUp(self) -> None:
        self._tmp = tempfile.mkdtemp()
        self.log_mgr = Logger(log_dir=self._tmp, level="DEBUG")

    def test_start_run_creates_directory(self) -> None:
        run_dir = self.log_mgr.start_run("smoke")
        self.assertTrue(os.path.isdir(run_dir))
        self.log_mgr.end_run()

    def test_end_run_writes_results_json(self) -> None:
        import json
        self.log_mgr.start_run("test_end")
        self.log_mgr.log_result("example.py", "SUCCESS", {"v": 12.1})
        results_path = self.log_mgr.end_run()
        self.assertIsNotNone(results_path)
        self.assertTrue(os.path.isfile(results_path))
        with open(results_path) as fh:
            data = json.load(fh)
        self.assertEqual(data["passed"], 1)
        self.assertEqual(data["failed"], 0)

    def test_multiple_results(self) -> None:
        import json
        self.log_mgr.start_run("multi")
        self.log_mgr.log_result("a.py", "SUCCESS")
        self.log_mgr.log_result("b.cmm", "FAILED", {"err": "timeout"})
        self.log_mgr.log_result("c.can", "ERROR")
        path = self.log_mgr.end_run()
        with open(path) as fh:
            data = json.load(fh)
        self.assertEqual(data["total"], 3)
        self.assertEqual(data["passed"], 1)
        self.assertEqual(data["failed"], 1)
        self.assertEqual(data["errored"], 1)

    def test_log_run_creates_run_log(self) -> None:
        run_dir = self.log_mgr.start_run("logfile")
        log_path = os.path.join(run_dir, "run.log")
        self.log_mgr.logger.info("hello from test")
        self.log_mgr.end_run()
        self.assertTrue(os.path.isfile(log_path))

    def test_run_dir_none_before_start(self) -> None:
        mgr = Logger(log_dir=self._tmp)
        self.assertIsNone(mgr.run_dir)

    def test_end_run_without_start_returns_none(self) -> None:
        mgr = Logger(log_dir=self._tmp)
        self.assertIsNone(mgr.end_run())

    def test_log_telemetry(self) -> None:
        self.log_mgr.start_run("telem")
        self.log_mgr.log_telemetry("power_supply", {"voltage": 12.0, "current": 1.5})
        self.log_mgr.end_run()  # should not raise

    def test_log_error(self) -> None:
        self.log_mgr.start_run("errors")
        self.log_mgr.log_error("trace32", "Connection refused")
        self.log_mgr.end_run()


# ===========================================================================
# TestRunner tests
# ===========================================================================

class TestTestRunner(unittest.TestCase):

    def setUp(self) -> None:
        self._tmp = tempfile.mkdtemp()
        self.log_mgr = Logger(log_dir=self._tmp, level="DEBUG")
        self.log_mgr.start_run("runner_tests")

    def tearDown(self) -> None:
        self.log_mgr.end_run()

    # ------------------------------------------------------------------
    # Python test execution
    # ------------------------------------------------------------------

    def _make_python_script(self, content: str) -> str:
        """Write content to a temp .py file and return its path."""
        f = tempfile.NamedTemporaryFile(suffix=".py", delete=False, mode="w", dir=self._tmp)
        f.write(content)
        f.close()
        return f.name

    def test_run_python_success(self) -> None:
        path = self._make_python_script("def run(**p): return {'ok': True}\n")
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("success_test", TestType.PYTHON, path)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(len(results), 1)
        self.assertEqual(results[0].status, TestStatus.SUCCESS)

    def test_run_python_assertion_failure(self) -> None:
        path = self._make_python_script(
            "def run(**p): raise AssertionError('bad value')\n"
        )
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("fail_test", TestType.PYTHON, path)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.FAILED)
        self.assertIn("bad value", results[0].message)

    def test_run_python_exception_gives_error(self) -> None:
        path = self._make_python_script("def run(**p): raise RuntimeError('crash')\n")
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("error_test", TestType.PYTHON, path)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.ERROR)

    def test_run_python_no_run_function(self) -> None:
        path = self._make_python_script("x = 1\n")
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("no_run", TestType.PYTHON, path)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.ERROR)

    def test_run_python_file_missing(self) -> None:
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("missing", TestType.PYTHON, "/nonexistent/path.py")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.ERROR)

    def test_run_python_with_params(self) -> None:
        path = self._make_python_script(
            "def run(**p): return p.get('target_voltage', 0) == 12.0\n"
        )
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("param_test", TestType.PYTHON, path, params={"target_voltage": 12.0})
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.SUCCESS)

    # ------------------------------------------------------------------
    # CMM test execution
    # ------------------------------------------------------------------

    def test_run_cmm_no_interface(self) -> None:
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("boot", TestType.CMM, "/scripts/boot.cmm")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.ERROR)
        self.assertIn("Trace32", results[0].message)

    def test_run_cmm_success(self) -> None:
        mock_t32 = MagicMock()
        mock_t32.run_cmm.return_value = True
        mock_t32.get_error.return_value = ""
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        runner.set_interfaces(trace32=mock_t32)
        item = TestItem("boot", TestType.CMM, "/fake/boot.cmm")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.SUCCESS)

    def test_run_cmm_failure(self) -> None:
        mock_t32 = MagicMock()
        mock_t32.run_cmm.return_value = False
        mock_t32.get_error.return_value = "Breakpoint not reached"
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        runner.set_interfaces(trace32=mock_t32)
        item = TestItem("boot", TestType.CMM, "/fake/boot.cmm")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.FAILED)

    # ------------------------------------------------------------------
    # CANoe test execution
    # ------------------------------------------------------------------

    def test_run_canoe_no_interface(self) -> None:
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("canoe_test", TestType.CANOE, "/fake/test.can")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.ERROR)

    def test_run_canoe_success(self) -> None:
        mock_coe = MagicMock()
        mock_coe.run_script.return_value = True
        mock_coe.get_measurement_state.return_value = "running"
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        runner.set_interfaces(canoe=mock_coe)
        item = TestItem("canoe_test", TestType.CANOE, "/fake/test.can")
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.SUCCESS)

    # ------------------------------------------------------------------
    # Retry logic
    # ------------------------------------------------------------------

    def test_retry_on_failure(self) -> None:
        call_count = []
        path = self._make_python_script(
            "def run(**p):\n"
            "    raise AssertionError('retry me')\n"
        )
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=True, retry_count=2)
        item = TestItem("retry_test", TestType.PYTHON, path)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=10.0)
        # Should still be FAILED after retries
        self.assertEqual(results[0].status, TestStatus.FAILED)

    def test_no_retry_when_disabled(self) -> None:
        path = self._make_python_script("def run(**p): raise AssertionError('x')\n")
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        item = TestItem("no_retry", TestType.PYTHON, path, retry_count=0)
        results = []
        runner.add(item)
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=5.0)
        self.assertEqual(results[0].status, TestStatus.FAILED)

    # ------------------------------------------------------------------
    # Queue management
    # ------------------------------------------------------------------

    def test_clear_queue(self) -> None:
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        for i in range(5):
            runner.add(TestItem(f"t{i}", TestType.PYTHON, "/fake/t.py"))
        runner.clear()
        self.assertTrue(runner._queue.empty())

    def test_multiple_tests_in_sequence(self) -> None:
        p1 = self._make_python_script("def run(**p): return True\n")
        p2 = self._make_python_script("def run(**p): return True\n")
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        runner.add(TestItem("t1", TestType.PYTHON, p1))
        runner.add(TestItem("t2", TestType.PYTHON, p2))
        results = []
        runner.start(status_callback=lambda r: results.append(r))
        runner.wait(timeout=10.0)
        self.assertEqual(len(results), 2)
        self.assertTrue(all(r.status == TestStatus.SUCCESS for r in results))

    def test_stop_runner(self) -> None:
        runner = TestRunner(log_manager=self.log_mgr, auto_retry=False)
        runner.start()
        runner.stop()
        self.assertFalse(runner.is_running)


if __name__ == "__main__":
    unittest.main()
