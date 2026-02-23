"""
Unit tests for hardware interfaces.

All hardware dependencies (serial, cv2, win32com, lauterbach) are mocked so
these tests pass without any physical equipment.
"""
from __future__ import annotations

import sys
import types
import unittest
from unittest.mock import MagicMock, patch

# ---------------------------------------------------------------------------
# Stub heavy optional packages before importing project modules
# ---------------------------------------------------------------------------


def _make_lauterbach_stub() -> None:
    """Insert a minimal lauterbach.trace32.rcl stub into sys.modules."""
    pkg = types.ModuleType("lauterbach")
    sub = types.ModuleType("lauterbach.trace32")
    rcl_mod = types.ModuleType("lauterbach.trace32.rcl")
    rcl_mod.connect = MagicMock()
    pkg.trace32 = sub  # type: ignore[attr-defined]
    sub.rcl = rcl_mod  # type: ignore[attr-defined]
    sys.modules.setdefault("lauterbach", pkg)
    sys.modules.setdefault("lauterbach.trace32", sub)
    sys.modules.setdefault("lauterbach.trace32.rcl", rcl_mod)


def _make_cv2_stub() -> None:
    cv2_mod = types.ModuleType("cv2")
    cap_mock = MagicMock()
    cap_mock.isOpened.return_value = True
    cap_mock.read.return_value = (True, MagicMock())
    cap_mock.release = MagicMock()
    cv2_mod.VideoCapture = MagicMock(return_value=cap_mock)
    cv2_mod.imwrite = MagicMock(return_value=True)
    cv2_mod.cvtColor = MagicMock()
    cv2_mod.COLOR_BGR2RGB = 4
    sys.modules.setdefault("cv2", cv2_mod)


def _make_pil_stub() -> None:
    pil_mod = types.ModuleType("PIL")
    image_mod = types.ModuleType("PIL.Image")
    imagetk_mod = types.ModuleType("PIL.ImageTk")
    image_mod.fromarray = MagicMock(return_value=MagicMock())
    imagetk_mod.PhotoImage = MagicMock()
    pil_mod.Image = image_mod          # type: ignore[attr-defined]
    pil_mod.ImageTk = imagetk_mod      # type: ignore[attr-defined]
    sys.modules.setdefault("PIL", pil_mod)
    sys.modules.setdefault("PIL.Image", image_mod)
    sys.modules.setdefault("PIL.ImageTk", imagetk_mod)


def _make_win32com_stub() -> None:
    win32_mod = types.ModuleType("win32com")
    client_mod = types.ModuleType("win32com.client")
    client_mod.Dispatch = MagicMock()
    win32_mod.client = client_mod  # type: ignore[attr-defined]
    sys.modules.setdefault("win32com", win32_mod)
    sys.modules.setdefault("win32com.client", client_mod)


_make_lauterbach_stub()
_make_cv2_stub()
_make_pil_stub()
_make_win32com_stub()

# ---------------------------------------------------------------------------
# Now import project code
# ---------------------------------------------------------------------------
import os  # noqa: E402
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from interfaces.trace32_interface import Trace32Interface  # noqa: E402
from interfaces.power_supply_interface import PowerSupplyInterface  # noqa: E402
from interfaces.camera_interface import CameraInterface  # noqa: E402
from interfaces.serial_interface import SerialInterface, SerialPort  # noqa: E402
from interfaces.canoe_interface import CANoeInterface  # noqa: E402


# ===========================================================================
# Trace32
# ===========================================================================

class TestTrace32Interface(unittest.TestCase):

    def setUp(self) -> None:
        self.t32 = Trace32Interface(host="localhost", port=20000)

    def test_connect_success(self) -> None:
        import lauterbach.trace32.rcl as rcl
        mock_dbg = MagicMock()
        rcl.connect = MagicMock(return_value=mock_dbg)
        self.assertTrue(self.t32.connect())
        self.assertTrue(self.t32.is_connected)

    def test_connect_failure_raises(self) -> None:
        import lauterbach.trace32.rcl as rcl
        rcl.connect = MagicMock(side_effect=ConnectionError("refused"))
        self.assertFalse(self.t32.connect())
        self.assertFalse(self.t32.is_connected)

    def test_run_cmm_not_connected(self) -> None:
        self.assertFalse(self.t32.run_cmm("/nonexistent.cmm"))

    def test_run_cmm_file_missing(self, tmp_path=None) -> None:
        import lauterbach.trace32.rcl as rcl
        mock_dbg = MagicMock()
        rcl.connect = MagicMock(return_value=mock_dbg)
        self.t32.connect()
        self.assertFalse(self.t32.run_cmm("/nonexistent_file.cmm"))

    def test_run_cmm_success(self, tmp_path=None) -> None:
        import lauterbach.trace32.rcl as rcl
        import tempfile
        import os
        mock_dbg = MagicMock()
        mock_dbg.fnc.return_value = ""          # no error message
        rcl.connect = MagicMock(return_value=mock_dbg)
        self.t32.connect()
        # Create a temp cmm file so the path check passes
        with tempfile.NamedTemporaryFile(suffix=".cmm", delete=False) as tf:
            tf.write(b"; test")
            tf_path = tf.name
        try:
            self.assertTrue(self.t32.run_cmm(tf_path))
        finally:
            os.unlink(tf_path)

    def test_get_error_not_connected(self) -> None:
        self.assertEqual(self.t32.get_error(), "")

    def test_read_variable_not_connected(self) -> None:
        self.assertIsNone(self.t32.read_variable("g_RPM"))

    def test_disconnect_safe_when_not_connected(self) -> None:
        self.t32.disconnect()   # should not raise

    def test_read_variable_success(self) -> None:
        import lauterbach.trace32.rcl as rcl
        mock_dbg = MagicMock()
        mock_var = MagicMock()
        mock_var.value = 3000
        mock_dbg.variable.read.return_value = mock_var
        rcl.connect = MagicMock(return_value=mock_dbg)
        self.t32.connect()
        self.assertEqual(self.t32.read_variable("g_RPM"), 3000)


# ===========================================================================
# Power Supply
# ===========================================================================

class TestPowerSupplyInterface(unittest.TestCase):

    def _connected_ps(self) -> PowerSupplyInterface:
        ps = PowerSupplyInterface()
        mock_ser = MagicMock()
        mock_ser.is_open = True
        with patch("interfaces.power_supply_interface.serial.Serial", return_value=mock_ser):
            ps.connect("COM3", baud=9600)
        ps._serial = mock_ser
        return ps

    def test_connect_success(self) -> None:
        ps = PowerSupplyInterface()
        mock_ser = MagicMock()
        mock_ser.is_open = True
        with patch("interfaces.power_supply_interface.serial.Serial", return_value=mock_ser):
            self.assertTrue(ps.connect("COM3"))
        self.assertTrue(ps.is_connected)

    def test_connect_failure(self) -> None:
        ps = PowerSupplyInterface()
        with patch(
            "interfaces.power_supply_interface.serial.Serial",
            side_effect=Exception("no port"),
        ):
            self.assertFalse(ps.connect("COM99"))
        self.assertFalse(ps.is_connected)

    def test_set_voltage_sends_command(self) -> None:
        ps = self._connected_ps()
        ps.set_voltage(12.0)
        ps._serial.write.assert_called()
        cmd_arg = ps._serial.write.call_args[0][0]
        self.assertIn(b"VSET1:12.000", cmd_arg)

    def test_set_current_sends_command(self) -> None:
        ps = self._connected_ps()
        ps.set_current(1.5)
        cmd_arg = ps._serial.write.call_args[0][0]
        self.assertIn(b"ISET1:1.500", cmd_arg)

    def test_output_on_off(self) -> None:
        ps = self._connected_ps()
        ps.output_on()
        ps._serial.write.assert_called_with(b"OUTPUT ON\r\n")
        ps.output_off()
        ps._serial.write.assert_called_with(b"OUTPUT OFF\r\n")

    def test_read_status_returns_tuple(self) -> None:
        ps = self._connected_ps()
        ps._serial.in_waiting = 8
        ps._serial.readline.side_effect = [b"12.050\r\n", b"1.500\r\n"]
        v, i = ps.read_status()
        self.assertIsNotNone(v)
        self.assertIsNotNone(i)

    def test_set_voltage_not_connected(self) -> None:
        ps = PowerSupplyInterface()
        self.assertFalse(ps.set_voltage(5.0))

    def test_disconnect_safe(self) -> None:
        ps = self._connected_ps()
        ps.disconnect()
        self.assertFalse(ps._connected)


# ===========================================================================
# Camera
# ===========================================================================

class TestCameraInterface(unittest.TestCase):
    """Tests for CameraInterface.

    cv2 is not installed in CI, so we patch the module-level availability flag
    and the cv2 reference directly on the camera_interface module.
    """

    def _make_cap_mock(self) -> MagicMock:
        cap = MagicMock()
        cap.isOpened.return_value = True
        cap.read.return_value = (True, MagicMock())
        cap.release = MagicMock()
        return cap

    def _cv2_patches(self, cap_mock: MagicMock):
        """Return a context-manager stack that patches cv2 availability."""
        import interfaces.camera_interface as cam_mod
        cv2_stub = sys.modules["cv2"]
        cv2_stub.VideoCapture = MagicMock(return_value=cap_mock)
        cv2_stub.imwrite = MagicMock(return_value=True)
        cv2_stub.cvtColor = MagicMock(return_value=MagicMock())
        cv2_stub.COLOR_BGR2RGB = 4
        p1 = patch.object(cam_mod, "_CV2_AVAILABLE", True)
        p2 = patch.object(cam_mod, "_cv2", cv2_stub)
        return p1, p2

    def test_connect_success(self) -> None:
        cap = self._make_cap_mock()
        p1, p2 = self._cv2_patches(cap)
        with p1, p2:
            cam = CameraInterface()
            self.assertTrue(cam.connect(0))
            self.assertTrue(cam.is_connected)
            cam.disconnect()

    def test_connect_failure_cap_not_open(self) -> None:
        bad_cap = MagicMock()
        bad_cap.isOpened.return_value = False
        p1, p2 = self._cv2_patches(bad_cap)
        with p1, p2:
            cam = CameraInterface()
            self.assertFalse(cam.connect(99))

    def test_capture_frame_returns_frame(self) -> None:
        cap = self._make_cap_mock()
        p1, p2 = self._cv2_patches(cap)
        with p1, p2:
            cam = CameraInterface()
            cam.connect(0)
            frame = cam.capture_frame()
            self.assertIsNotNone(frame)
            cam.disconnect()

    def test_capture_frame_not_connected(self) -> None:
        cam = CameraInterface()
        self.assertIsNone(cam.capture_frame())

    def test_save_frame(self) -> None:
        import tempfile
        cap = self._make_cap_mock()
        p1, p2 = self._cv2_patches(cap)
        with p1, p2:
            cam = CameraInterface()
            cam.connect(0)
            frame = cam.capture_frame()
            with tempfile.TemporaryDirectory() as td:
                path = os.path.join(td, "snap.png")
                cam.save_frame(path, frame)
            cam.disconnect()

    def test_stream_start_stop(self) -> None:
        import time
        cap = self._make_cap_mock()
        p1, p2 = self._cv2_patches(cap)
        with p1, p2:
            cam = CameraInterface()
            cam.connect(0)
            frames: list = []
            cam.start_stream(callback=lambda f: frames.append(f))
            self.assertTrue(cam.is_streaming)
            time.sleep(0.05)
            cam.stop_stream()
            self.assertFalse(cam.is_streaming)
            cam.disconnect()

    def test_disconnect_stops_stream(self) -> None:
        cap = self._make_cap_mock()
        p1, p2 = self._cv2_patches(cap)
        with p1, p2:
            cam = CameraInterface()
            cam.connect(0)
            cam.start_stream()
            cam.disconnect()
            self.assertFalse(cam.is_streaming)
            self.assertFalse(cam.is_connected)


# ===========================================================================
# Serial Interface
# ===========================================================================

class TestSerialInterface(unittest.TestCase):

    def _mock_serial(self) -> MagicMock:
        mock_ser = MagicMock()
        mock_ser.is_open = True
        mock_ser.in_waiting = 0
        return mock_ser

    def test_add_port(self) -> None:
        si = SerialInterface()
        sp = si.add_port("DUT1")
        self.assertIsInstance(sp, SerialPort)

    def test_add_port_max_exceeded(self) -> None:
        si = SerialInterface()
        for i in range(4):
            si.add_port(f"DUT{i+1}")
        with self.assertRaises(ValueError):
            si.add_port("DUT5")

    def test_connect_port(self) -> None:
        si = SerialInterface()
        mock_ser = self._mock_serial()
        with patch("interfaces.serial_interface.serial.Serial", return_value=mock_ser):
            ok = si.connect_port("DUT1", "COM4", 115200)
        self.assertTrue(ok)

    def test_connect_failure(self) -> None:
        si = SerialInterface()
        with patch(
            "interfaces.serial_interface.serial.Serial",
            side_effect=Exception("port busy"),
        ):
            ok = si.connect_port("DUT1", "COM4")
        self.assertFalse(ok)

    def test_start_stop_logging(self) -> None:
        import tempfile
        import os
        import time
        si = SerialInterface()
        mock_ser = self._mock_serial()
        with patch("interfaces.serial_interface.serial.Serial", return_value=mock_ser):
            si.connect_port("DUT1", "COM4")
        sp = si.get_port("DUT1")
        with tempfile.TemporaryDirectory() as td:
            log_path = os.path.join(td, "logs", "DUT1_serial.log")
            os.makedirs(os.path.join(td, "logs"))
            sp.start_logging(log_path)
            self.assertTrue(sp.is_logging)
            time.sleep(0.05)
            sp.stop_logging()
            self.assertFalse(sp.is_logging)

    def test_list_available_ports(self) -> None:
        with patch(
            "interfaces.serial_interface.serial.tools.list_ports.comports",
            return_value=[],
        ):
            ports = SerialInterface.list_available_ports()
        self.assertIsInstance(ports, list)

    def test_disconnect_all(self) -> None:
        si = SerialInterface()
        mock_ser = self._mock_serial()
        with patch("interfaces.serial_interface.serial.Serial", return_value=mock_ser):
            si.connect_port("DUT1", "COM4")
        si.disconnect_all()


# ===========================================================================
# CANoe Interface
# ===========================================================================

class TestCANoeInterface(unittest.TestCase):

    def _connected_canoe(self) -> CANoeInterface:
        coe = CANoeInterface()
        import win32com.client as wc
        mock_app = MagicMock()
        wc.Dispatch = MagicMock(return_value=mock_app)
        coe.connect()
        return coe

    def test_connect_success(self) -> None:
        coe = CANoeInterface()
        import win32com.client as wc
        mock_app = MagicMock()
        wc.Dispatch = MagicMock(return_value=mock_app)
        self.assertTrue(coe.connect())
        self.assertTrue(coe.is_connected)

    def test_connect_failure(self) -> None:
        coe = CANoeInterface()
        import win32com.client as wc
        wc.Dispatch = MagicMock(side_effect=Exception("COM error"))
        self.assertFalse(coe.connect())

    def test_run_script_file_missing(self) -> None:
        coe = self._connected_canoe()
        self.assertFalse(coe.run_script("/no/such/file.can"))

    def test_run_script_success(self) -> None:
        import tempfile
        import os
        coe = self._connected_canoe()
        with tempfile.NamedTemporaryFile(suffix=".can", delete=False) as tf:
            tf.write(b"// canoe test")
            path = tf.name
        try:
            self.assertTrue(coe.run_script(path))
            coe._app.Measurement.Start.assert_called_once()
        finally:
            os.unlink(path)

    def test_stop(self) -> None:
        coe = self._connected_canoe()
        self.assertTrue(coe.stop())
        coe._app.Measurement.Stop.assert_called_once()

    def test_get_measurement_state_running(self) -> None:
        coe = self._connected_canoe()
        coe._app.Measurement.Running = True
        self.assertEqual(coe.get_measurement_state(), "running")

    def test_get_measurement_state_stopped(self) -> None:
        coe = self._connected_canoe()
        coe._app.Measurement.Running = False
        self.assertEqual(coe.get_measurement_state(), "stopped")

    def test_disconnect(self) -> None:
        coe = self._connected_canoe()
        coe.disconnect()
        self.assertFalse(coe.is_connected)


if __name__ == "__main__":
    unittest.main()
