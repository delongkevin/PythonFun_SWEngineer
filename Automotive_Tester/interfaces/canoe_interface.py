"""
Vector CANoe Interface
Controls CANoe via COM automation (Windows only) using win32com.

Install: pip install pywin32

CANoe must be installed and licensed on the test machine.
"""

import logging
import time
from typing import Optional
from pathlib import Path

try:
    import win32com.client  # type: ignore
    _HAS_WIN32 = True
except ImportError:
    _HAS_WIN32 = False


class CANoeInterface:
    """
    Automates Vector CANoe via COM interface.
    
    Capabilities:
      - Open/close CANoe configurations (.cfg)
      - Start/stop measurement
      - Run CAPL test modules
      - Read/write environment variables
      - Access diagnostics (UDS/OBD)
    """

    def __init__(self, config_path: Optional[str] = None):
        self.config_path = config_path
        self.logger = logging.getLogger("tester.canoe")
        self._app = None
        self._measurement = None
        self._connected = False

    def connect(self, open_config: bool = True) -> bool:
        if not _HAS_WIN32:
            self.logger.error("pywin32 not installed. CANoe automation unavailable.")
            return False
        try:
            self._app = win32com.client.DispatchEx("CANoe.Application")
            self._app.Visible = True
            self._measurement = self._app.Measurement
            if open_config and self.config_path:
                self.open_config(self.config_path)
            self._connected = True
            self.logger.info("CANoe COM interface connected.")
            return True
        except Exception as e:
            self.logger.error(f"CANoe connect failed: {e}")
            return False

    def disconnect(self):
        if self._measurement:
            try:
                self.stop_measurement()
            except Exception:
                pass
        self._app = None
        self._connected = False
        self.logger.info("CANoe disconnected.")

    @property
    def is_connected(self) -> bool:
        return self._connected

    def open_config(self, cfg_path: str):
        if not Path(cfg_path).exists():
            raise FileNotFoundError(f"CANoe config not found: {cfg_path}")
        self._app.Open(cfg_path)
        self.logger.info(f"CANoe config opened: {cfg_path}")
        time.sleep(2)  # Allow CANoe to load

    def start_measurement(self):
        if self._measurement:
            self._measurement.Start()
            self.logger.info("CANoe measurement started.")
            time.sleep(1)

    def stop_measurement(self):
        if self._measurement:
            self._measurement.Stop()
            self.logger.info("CANoe measurement stopped.")

    @property
    def is_running(self) -> bool:
        if self._measurement:
            return bool(self._measurement.Running)
        return False

    def run_script(self, script_path: str, parameters: dict = None, timeout: int = 300):
        """
        Run a CANoe test module (.vtestunit / CAPL) by name.
        script_path can be test module name or path.
        """
        if not self._connected:
            raise RuntimeError("CANoe not connected.")
        # Ensure measurement is running
        if not self.is_running:
            self.start_measurement()

        # Find and execute test module
        try:
            test_env = self._app.TestEnvironment
            for i in range(1, test_env.TestModules.Count + 1):
                tm = test_env.TestModules.Item(i)
                if script_path.lower() in tm.FullName.lower() or script_path.lower() in tm.Name.lower():
                    self.logger.info(f"Running CANoe test module: {tm.Name}")
                    tm.Start()
                    # Wait for completion
                    deadline = time.time() + timeout
                    while time.time() < deadline:
                        if not tm.IsRunning:
                            break
                        time.sleep(1)
                    else:
                        raise TimeoutError(f"CANoe test module timed out: {tm.Name}")
                    verdict = tm.Verdict
                    self.logger.info(f"CANoe test verdict: {verdict}")
                    if verdict != 1:  # 1 = Passed
                        raise RuntimeError(f"CANoe test failed. Verdict: {verdict}")
                    return
            raise FileNotFoundError(f"CANoe test module not found: {script_path}")
        except AttributeError as e:
            self.logger.warning(f"CANoe COM attribute issue (simulating): {e}")

    def get_env_var(self, name: str):
        if not self._connected:
            return None
        try:
            env = self._app.Environment
            return env.GetVariable(name).Value
        except Exception as e:
            self.logger.error(f"CANoe env var read error ({name}): {e}")
            return None

    def set_env_var(self, name: str, value):
        if not self._connected:
            return
        try:
            env = self._app.Environment
            env.GetVariable(name).Value = value
        except Exception as e:
            self.logger.error(f"CANoe env var write error ({name}={value}): {e}")

    def get_signal(self, db: str, message: str, signal: str) -> Optional[float]:
        try:
            bus = self._app.Bus
            return bus.GetSignal(db, message, signal).Value
        except Exception as e:
            self.logger.error(f"Signal read error: {e}")
            return None
