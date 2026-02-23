"""
Vector CANoe interface via COM automation (win32com).

Gracefully degrades on non-Windows platforms or when pywin32 is not installed.
"""
from __future__ import annotations

import logging
import os
from typing import Any, Optional

logger = logging.getLogger(__name__)

try:
    import win32com.client as _win32com  # type: ignore[import]
    _WIN32_AVAILABLE = True
except ImportError:
    _win32com = None  # type: ignore[assignment]
    _WIN32_AVAILABLE = False
    logger.warning("win32com not available – CANoe features disabled (Windows only).")

# CANoe COM ProgID
_CANOE_PROGID = "CANoe.Application"

# Measurement state constants returned by CANoe COM
_MEASUREMENT_RUNNING = 0
_MEASUREMENT_STOPPED = 1


class CANoeInterface:
    """Automates Vector CANoe via its COM interface.

    Usage::

        coe = CANoeInterface()
        coe.connect()
        coe.run_script("path/to/test.can")
        state = coe.get_measurement_state()
        coe.stop()
        coe.disconnect()
    """

    def __init__(self) -> None:
        self._app: Optional[Any] = None
        self._connected: bool = False

    # ------------------------------------------------------------------
    # Connection lifecycle
    # ------------------------------------------------------------------

    def connect(self) -> bool:
        """Attach to a running CANoe instance via COM.

        Returns:
            True on success, False if win32com unavailable or CANoe not running.
        """
        if not _WIN32_AVAILABLE:
            logger.error("Cannot connect to CANoe: win32com is not available.")
            return False
        try:
            self._app = _win32com.Dispatch(_CANOE_PROGID)
            self._connected = True
            logger.info("Connected to CANoe via COM (%s).", _CANOE_PROGID)
            return True
        except Exception as exc:
            logger.error("CANoe COM connect failed: %s", exc)
            self._connected = False
            return False

    def disconnect(self) -> None:
        """Release the COM reference."""
        self._app = None
        self._connected = False
        logger.info("CANoe COM reference released.")

    # ------------------------------------------------------------------
    # Script execution
    # ------------------------------------------------------------------

    def run_script(self, path: str) -> bool:
        """Open and execute a CANoe .can test configuration or CAPL script.

        The method opens the configuration file then starts the measurement.
        It waits for the measurement to start before returning.

        Args:
            path: Absolute path to the .can or .cfg file.

        Returns:
            True if the measurement was started successfully.
        """
        if not self._connected or self._app is None:
            logger.error("run_script called but CANoe is not connected.")
            return False
        if not os.path.isfile(path):
            logger.error("CANoe script/config not found: %s", path)
            return False
        try:
            self._app.Open(path)
            self._app.Measurement.Start()
            logger.info("CANoe measurement started for: %s", path)
            return True
        except Exception as exc:
            logger.error("CANoe run_script exception: %s", exc)
            return False

    def stop(self) -> bool:
        """Stop the current CANoe measurement.

        Returns:
            True if stop command was sent successfully.
        """
        if not self._connected or self._app is None:
            logger.error("stop called but CANoe is not connected.")
            return False
        try:
            self._app.Measurement.Stop()
            logger.info("CANoe measurement stopped.")
            return True
        except Exception as exc:
            logger.error("CANoe stop exception: %s", exc)
            return False

    # ------------------------------------------------------------------
    # State / diagnostics
    # ------------------------------------------------------------------

    def get_measurement_state(self) -> Optional[str]:
        """Return the current measurement state as a human-readable string.

        Returns:
            'running', 'stopped', or None on error.
        """
        if not self._connected or self._app is None:
            logger.warning("get_measurement_state: CANoe not connected.")
            return None
        try:
            state = self._app.Measurement.Running
            return "running" if state else "stopped"
        except Exception as exc:
            logger.error("get_measurement_state exception: %s", exc)
            return None

    @property
    def is_connected(self) -> bool:
        """True if a COM connection to CANoe is active."""
        return self._connected
