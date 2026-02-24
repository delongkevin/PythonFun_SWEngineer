"""
Unit tests for Trace32_Executor.

All hardware (Trace32 RCL) and GUI (tkinter) dependencies are mocked so
that the tests run cleanly on headless CI runners.
"""
from __future__ import annotations

import os
import sys
import types
import unittest
from unittest.mock import patch

# ---------------------------------------------------------------------------
# Stub optional / platform-specific modules before importing the module under
# test so that the import succeeds on Linux CI without a display.
# ---------------------------------------------------------------------------


def _make_widget_class(name: str):
    """Return a minimal tkinter-like widget class."""
    return type(name, (), {
        "__init__": lambda self, *a, **kw: None,
        "pack": lambda self, *a, **kw: None,
        "config": lambda self, *a, **kw: None,
        "title": lambda self, *a, **kw: None,
        "geometry": lambda self, *a, **kw: None,
        "destroy": lambda self, *a, **kw: None,
        "after": lambda self, *a, **kw: None,
        "get": lambda self, *a, **kw: "",
        "insert": lambda self, *a, **kw: None,
        "heading": lambda self, *a, **kw: None,
        "get_children": lambda self: [],
        "item": lambda self, *a, **kw: {"values": []},
    })


# Build a fake tkinter module
_tk_mod = types.ModuleType("tkinter")
_tk_mod.Frame = _make_widget_class("Frame")
_tk_mod.Button = _make_widget_class("Button")
_tk_mod.Label = _make_widget_class("Label")
_tk_mod.Toplevel = _make_widget_class("Toplevel")
_tk_mod.Tk = _make_widget_class("Tk")
_tk_mod.RAISED = "raised"
_tk_mod.LEFT = "left"
_tk_mod.TOP = "top"
_tk_mod.X = "x"
_tk_mod.WORD = "word"
_tk_mod.INSERT = "insert"
_tk_mod.END = "end"

_ttk_mod = types.ModuleType("tkinter.ttk")
_ttk_mod.Treeview = _make_widget_class("Treeview")

_fd_mod = types.ModuleType("tkinter.filedialog")
_mb_mod = types.ModuleType("tkinter.messagebox")
_sd_mod = types.ModuleType("tkinter.scrolledtext")
_sd_mod.ScrolledText = _make_widget_class("ScrolledText")
_simp_mod = types.ModuleType("tkinter.simpledialog")
_tkinter_mod = types.ModuleType("_tkinter")

for _name, _mod in [
    ("tkinter", _tk_mod),
    ("tkinter.ttk", _ttk_mod),
    ("tkinter.filedialog", _fd_mod),
    ("tkinter.messagebox", _mb_mod),
    ("tkinter.scrolledtext", _sd_mod),
    ("tkinter.simpledialog", _simp_mod),
    ("_tkinter", _tkinter_mod),
    ("lauterbach", types.ModuleType("lauterbach")),
    ("lauterbach.trace32", types.ModuleType("lauterbach.trace32")),
    ("lauterbach.trace32.rcl", types.ModuleType("lauterbach.trace32.rcl")),
]:
    if _name not in sys.modules:
        sys.modules[_name] = _mod

# Now import the module under test
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
import Trace32_Executor as te  # noqa: E402


# ===========================================================================
# Constants
# ===========================================================================

class TestModuleConstants(unittest.TestCase):

    def test_default_drives(self):
        self.assertIn("C", te._DEFAULT_DRIVES)
        self.assertIn("D", te._DEFAULT_DRIVES)

    def test_exe_candidates_not_empty(self):
        self.assertTrue(len(te._EXE_CANDIDATES) > 0)
        for name in te._EXE_CANDIDATES:
            self.assertTrue(name.endswith(".exe"))

    def test_config_candidates_not_empty(self):
        self.assertTrue(len(te._CONFIG_CANDIDATES) > 0)
        for name in te._CONFIG_CANDIDATES:
            self.assertTrue(name.endswith(".t32"))

    def test_startup_wait_positive(self):
        self.assertGreater(te._T32_STARTUP_WAIT_SECONDS, 0)

    def test_trace32_available_is_bool(self):
        self.assertIsInstance(te._TRACE32_AVAILABLE, bool)


# ===========================================================================
# AppSettings
# ===========================================================================

class TestAppSettings(unittest.TestCase):

    def test_default_watch_variables(self):
        settings = te.AppSettings()
        self.assertIsInstance(settings.watch_variables, list)
        self.assertTrue(len(settings.watch_variables) > 0)

    def test_default_auto_retry(self):
        settings = te.AppSettings()
        self.assertTrue(settings.auto_retry)

    def test_watch_variables_are_strings(self):
        settings = te.AppSettings()
        for var in settings.watch_variables:
            self.assertIsInstance(var, str)

    def test_watch_variables_mutable(self):
        settings = te.AppSettings()
        original_len = len(settings.watch_variables)
        settings.watch_variables.append("g_TestVar")
        self.assertEqual(len(settings.watch_variables), original_len + 1)


# ===========================================================================
# _detect_t32_installation
# ===========================================================================

class TestDetectT32Installation(unittest.TestCase):

    def test_returns_empty_on_non_windows(self):
        with patch("platform.system", return_value="Linux"):
            result = te._detect_t32_installation()
        self.assertEqual(result, {})

    def test_returns_empty_when_no_t32_dir(self):
        with patch("platform.system", return_value="Windows"), \
             patch("os.path.isdir", return_value=False):
            result = te._detect_t32_installation()
        self.assertEqual(result, {})

    def test_returns_install_dir_when_found(self):
        install_dir = "C:\\T32"
        bin_dir = os.path.join(install_dir, "bin", "windows64")
        exe_path = os.path.join(bin_dir, "t32marm64.exe")

        def fake_isdir(path):
            return path in (install_dir, bin_dir)

        def fake_isfile(path):
            return path == exe_path

        with patch("platform.system", return_value="Windows"), \
             patch("os.path.isdir", side_effect=fake_isdir), \
             patch("os.path.isfile", side_effect=fake_isfile):
            result = te._detect_t32_installation()

        self.assertEqual(result.get("install_dir"), install_dir)
        self.assertIn("t32_exe", result)
        self.assertIn("t32marm64.exe", result["t32_exe"])

    def test_custom_drives(self):
        with patch("platform.system", return_value="Windows"), \
             patch("os.path.isdir", return_value=False):
            result = te._detect_t32_installation(drives=["E", "F"])
        self.assertEqual(result, {})

    def test_config_file_detected(self):
        install_dir = "C:\\T32"
        cfg_path = os.path.join(install_dir, "config_usb.t32")

        def fake_isdir(path):
            return path == install_dir

        def fake_isfile(path):
            return path == cfg_path

        with patch("platform.system", return_value="Windows"), \
             patch("os.path.isdir", side_effect=fake_isdir), \
             patch("os.path.isfile", side_effect=fake_isfile):
            result = te._detect_t32_installation()

        self.assertIn("config_file", result)
        self.assertIn("config_usb.t32", result["config_file"])


# ===========================================================================
# Trace32Worker (no-op when Trace32 unavailable)
# ===========================================================================

class TestTrace32WorkerNoT32(unittest.TestCase):

    def setUp(self):
        self._orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = False

    def tearDown(self):
        te._TRACE32_AVAILABLE = self._orig

    def test_worker_dbg_is_none_when_unavailable(self):
        import queue
        q = queue.Queue()
        settings = te.AppSettings()
        statuses = []
        worker = te.Trace32Worker(q, lambda *a: statuses.append(a), settings, lambda p: None)
        self.assertIsNone(worker.dbg)

    def test_execute_reports_error_when_not_connected(self):
        import queue
        q = queue.Queue()
        settings = te.AppSettings()
        statuses = []
        worker = te.Trace32Worker(q, lambda *a: statuses.append(a), settings, lambda p: None)
        worker.execute("/fake/script.cmm")
        self.assertEqual(len(statuses), 1)
        self.assertEqual(statuses[0][1], "ERROR")
        self.assertIn("not connected", statuses[0][2])


# ===========================================================================
# _try_connect_t32 retry helper
# ===========================================================================

class TestTryConnectT32(unittest.TestCase):

    def test_raises_when_trace32_unavailable(self):
        orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = False
        try:
            with self.assertRaises(RuntimeError):
                te._try_connect_t32(max_retries=1, interval=0)
        finally:
            te._TRACE32_AVAILABLE = orig

    def test_returns_connection_on_first_success(self):
        orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = True
        mock_conn = object()
        with patch.object(te._rcl, "connect", return_value=mock_conn, create=True):
            result = te._try_connect_t32(max_retries=3, interval=0)
        te._TRACE32_AVAILABLE = orig
        self.assertIs(result, mock_conn)

    def test_retries_on_connection_error_then_succeeds(self):
        orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = True
        mock_conn = object()
        call_count = [0]
        retry_calls = []

        def _side_effect(**kwargs):
            call_count[0] += 1
            if call_count[0] < 3:
                raise ConnectionRefusedError("refused")
            return mock_conn

        def _on_retry(attempt, max_retries, exc):
            retry_calls.append((attempt, max_retries))

        with patch.object(te._rcl, "connect", side_effect=_side_effect, create=True):
            result = te._try_connect_t32(max_retries=5, interval=0,
                                         status_callback=_on_retry)
        te._TRACE32_AVAILABLE = orig
        self.assertIs(result, mock_conn)
        self.assertEqual(call_count[0], 3)
        # status_callback fired for the two failures
        self.assertEqual(len(retry_calls), 2)
        self.assertEqual(retry_calls[0], (1, 5))
        self.assertEqual(retry_calls[1], (2, 5))

    def test_raises_last_exception_after_all_retries_exhausted(self):
        orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = True
        exc_sentinel = ConnectionRefusedError("always refused")

        with patch.object(te._rcl, "connect", side_effect=exc_sentinel, create=True):
            with self.assertRaises(ConnectionRefusedError) as ctx:
                te._try_connect_t32(max_retries=3, interval=0)
        te._TRACE32_AVAILABLE = orig
        self.assertIs(ctx.exception, exc_sentinel)

    def test_retry_constants_are_positive(self):
        self.assertGreater(te._T32_CONNECT_MAX_RETRIES, 0)
        self.assertGreater(te._T32_CONNECT_RETRY_INTERVAL_SECONDS, 0)

    def test_worker_emits_connecting_status_on_each_retry(self):
        """Worker._connect should surface per-attempt CONNECTING status messages."""
        import queue as _queue
        orig = te._TRACE32_AVAILABLE
        te._TRACE32_AVAILABLE = True
        call_count = [0]
        mock_conn = object()

        def _side_effect(**kwargs):
            call_count[0] += 1
            if call_count[0] < 3:
                raise ConnectionRefusedError("refused")
            return mock_conn

        statuses = []
        q = _queue.Queue()
        settings = te.AppSettings()
        with patch.object(te._rcl, "connect", side_effect=_side_effect, create=True):
            worker = te.Trace32Worker(q, lambda *a: statuses.append(a), settings,
                                      lambda p: None)
        te._TRACE32_AVAILABLE = orig
        # The two failed attempts should have produced CONNECTING messages
        connecting = [s for s in statuses if s[1] == "CONNECTING"]
        self.assertEqual(len(connecting), 2)
        # Worker should have a live connection
        self.assertIs(worker.dbg, mock_conn)


# ===========================================================================
# Source file quality
# ===========================================================================

class TestSourceQuality(unittest.TestCase):

    def test_syntax_valid(self):
        """Verify the executor script parses without SyntaxError."""
        import ast
        path = os.path.join(os.path.dirname(__file__), "..", "Trace32_Executor.py")
        with open(path) as fh:
            source = fh.read()
        ast.parse(source)  # raises SyntaxError on failure


if __name__ == "__main__":
    unittest.main()
