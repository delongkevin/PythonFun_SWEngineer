"""
Lauterbach Trace32 interface using lauterbach.trace32.rcl.

Gracefully degrades if the lauterbach package is not installed.
"""
from __future__ import annotations

import logging
import os
from typing import Any, Optional

logger = logging.getLogger(__name__)

try:
    from lauterbach.trace32 import rcl as _rcl
    _TRACE32_AVAILABLE = True
except ImportError:
    _rcl = None  # type: ignore[assignment]
    _TRACE32_AVAILABLE = False
    logger.warning("lauterbach.trace32 not available – Trace32 features disabled.")


class Trace32Interface:
    """Manages a connection to a Lauterbach Trace32 debugger via RCL."""

    def __init__(self, host: str = "localhost", port: int = 20000) -> None:
        self._host = host
        self._port = port
        self._dbg: Any = None
        self._connected = False

    # ------------------------------------------------------------------
    # Connection lifecycle
    # ------------------------------------------------------------------

    def connect(self) -> bool:
        """Open a connection to the Trace32 remote API.

        Returns:
            True if the connection succeeded, False otherwise.
        """
        if not _TRACE32_AVAILABLE:
            logger.error("Cannot connect: lauterbach.trace32 package is missing.")
            return False
        try:
            self._dbg = _rcl.connect(node=self._host, port=self._port)
            self._connected = True
            logger.info("Connected to Trace32 at %s:%d", self._host, self._port)
            return True
        except Exception as exc:
            logger.error("Trace32 connect failed: %s", exc)
            self._connected = False
            return False

    def disconnect(self) -> None:
        """Close the Trace32 connection."""
        if self._connected and self._dbg is not None:
            try:
                self._dbg.close()
            except Exception as exc:
                logger.warning("Trace32 disconnect warning: %s", exc)
            finally:
                self._dbg = None
                self._connected = False
                logger.info("Trace32 disconnected.")

    # ------------------------------------------------------------------
    # Script execution
    # ------------------------------------------------------------------

    def run_cmm(self, path: str) -> bool:
        """Execute a CMM script on the connected Trace32 instance.

        Args:
            path: Absolute or relative path to the .cmm file.

        Returns:
            True if the script ran without reported errors, False otherwise.
        """
        if not self._connected or self._dbg is None:
            logger.error("run_cmm called but Trace32 is not connected.")
            return False
        if not os.path.isfile(path):
            logger.error("CMM script not found: %s", path)
            return False
        try:
            self._dbg.cmm(path)
            error = self.get_error()
            if error:
                logger.error("CMM script reported error: %s", error)
                return False
            logger.info("CMM script completed successfully: %s", path)
            return True
        except Exception as exc:
            logger.error("CMM script execution exception: %s", exc)
            return False

    # ------------------------------------------------------------------
    # Diagnostics
    # ------------------------------------------------------------------

    def get_error(self) -> str:
        """Retrieve the last error message from Trace32.

        Returns:
            Error string, or empty string if none.
        """
        if not self._connected or self._dbg is None:
            return ""
        try:
            return self._dbg.fnc("MESSAGE.ERROR()") or ""
        except Exception as exc:
            logger.warning("get_error exception: %s", exc)
            return ""

    def read_variable(self, name: str) -> Optional[Any]:
        """Read a target variable value via Trace32.

        Args:
            name: Variable name as known to Trace32 (e.g. 'g_EngineRPM').

        Returns:
            The variable value, or None on failure.
        """
        if not self._connected or self._dbg is None:
            logger.warning("read_variable called but Trace32 is not connected.")
            return None
        try:
            return self._dbg.variable.read(name).value
        except Exception as exc:
            logger.warning("read_variable('%s') failed: %s", name, exc)
            return None

    @property
    def is_connected(self) -> bool:
        """True if currently connected to Trace32."""
        return self._connected
