"""
Lauterbach Trace32 interface using lauterbach.trace32.rcl.

Gracefully degrades if the lauterbach package is not installed.

Auto-detection searches the default Lauterbach installation directories
(C:\\T32 and D:\\T32) on Windows so that the T32 executable and config file
can be located without manual configuration.

PowerDebug Pro via USB 3.0 is supported: after calling detect_installation()
or setting t32_exe / config_file manually, call launch() to start the T32
process and establish the RCL connection automatically.
"""
from __future__ import annotations

import logging
import os
import platform
import subprocess
import tempfile
import time
from typing import Any, Dict, List, Optional

logger = logging.getLogger(__name__)

try:
    from lauterbach.trace32 import rcl as _rcl
    _TRACE32_AVAILABLE = True
except ImportError:
    _rcl = None  # type: ignore[assignment]
    _TRACE32_AVAILABLE = False
    logger.warning("lauterbach.trace32 not available – Trace32 features disabled.")

# ---------------------------------------------------------------------------
# Default T32 installation layout (Windows)
# ---------------------------------------------------------------------------
_DEFAULT_INSTALL_DRIVES: List[str] = ["C", "D"]
_DEFAULT_INSTALL_ROOT: str = "T32"
_BIN_SUBDIRS: List[str] = [
    os.path.join("bin", "windows64"),
    os.path.join("bin", "windows"),
    "bin",
]
# Ordered by popularity; first match wins
_EXE_CANDIDATES: List[str] = [
    "t32marm64.exe",
    "t32marm.exe",
    "t32mppc.exe",
    "t32mtc.exe",
    "t32mqdsp6.exe",
]
# Default config file names to look for
_CONFIG_CANDIDATES: List[str] = [
    "config_usb3.t32",
    "config_usb.t32",
    "config.t32",
]


class Trace32Interface:
    """Manages a connection to a Lauterbach Trace32 debugger via RCL."""

    def __init__(
        self,
        host: str = "localhost",
        port: int = 20000,
        t32_exe: Optional[str] = None,
        config_file: Optional[str] = None,
    ) -> None:
        self._host = host
        self._port = port
        self._dbg: Any = None
        self._connected = False
        self._process: Optional[subprocess.Popen] = None  # type: ignore[type-arg]
        # Paths supplied by caller or discovered via detect_installation()
        self.t32_exe: Optional[str] = t32_exe
        self.config_file: Optional[str] = config_file

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

    # Public host / port attributes expected by the UI layer
    @property
    def host(self) -> str:
        return self._host

    @host.setter
    def host(self, value: str) -> None:
        self._host = value

    @property
    def port(self) -> int:
        return self._port

    @port.setter
    def port(self, value: int) -> None:
        self._port = int(value)

    # ------------------------------------------------------------------
    # Auto-detection
    # ------------------------------------------------------------------

    @classmethod
    def detect_installation(
        cls, drives: Optional[List[str]] = None
    ) -> Dict[str, str]:
        """Auto-detect a Trace32 installation on Windows.

        Searches ``<drive>:\\T32`` on *drives* (defaults to ``["C", "D"]``).
        All T32 files are expected at the root of the labelled directory, with
        binaries under ``T32\\bin\\windows64`` (or ``bin\\windows`` / ``bin``).

        Returns:
            A dict with some or all of the keys ``install_dir``, ``t32_exe``,
            and ``config_file``.  Empty dict if no installation is found.
        """
        if drives is None:
            drives = _DEFAULT_INSTALL_DRIVES

        if platform.system() != "Windows":
            logger.debug("T32 auto-detect: not running on Windows, skipping.")
            return {}

        for drive in drives:
            install_dir = f"{drive}:\\{_DEFAULT_INSTALL_ROOT}"
            if not os.path.isdir(install_dir):
                continue

            logger.info("Found T32 installation directory: %s", install_dir)
            result: Dict[str, str] = {"install_dir": install_dir}

            # Locate executable
            for bin_sub in _BIN_SUBDIRS:
                bin_dir = os.path.join(install_dir, bin_sub)
                if not os.path.isdir(bin_dir):
                    continue
                for exe in _EXE_CANDIDATES:
                    candidate = os.path.join(bin_dir, exe)
                    if os.path.isfile(candidate):
                        result["t32_exe"] = candidate
                        logger.info("T32 executable found: %s", candidate)
                        break
                if "t32_exe" in result:
                    break

            # Locate config file
            for cfg_name in _CONFIG_CANDIDATES:
                candidate = os.path.join(install_dir, cfg_name)
                if os.path.isfile(candidate):
                    result["config_file"] = candidate
                    logger.info("T32 config file found: %s", candidate)
                    break

            return result

        logger.info("T32 auto-detect: no installation found on drives %s.", drives)
        return {}

    # ------------------------------------------------------------------
    # Launch
    # ------------------------------------------------------------------

    def launch(self, wait_seconds: float = 8.0) -> bool:
        """Start the Trace32 executable and wait for the RCL port to become available.

        The executable path must be set on ``self.t32_exe`` (either manually or
        via :meth:`detect_installation`).  An optional ``self.config_file`` is
        passed as the ``-c`` argument so that the RCL server and USB 3.0
        interface are configured before the connection attempt.

        Args:
            wait_seconds: Seconds to wait for the RCL port before giving up.

        Returns:
            True if Trace32 started and became reachable, False otherwise.
        """
        if self._connected:
            logger.info("Trace32 already connected; skipping launch.")
            return True

        if not self.t32_exe:
            logger.error(
                "launch() called but t32_exe is not set. "
                "Call detect_installation() or set t32_exe manually."
            )
            return False

        if not os.path.isfile(self.t32_exe):
            logger.error("T32 executable not found: %s", self.t32_exe)
            return False

        cmd = [self.t32_exe]
        if self.config_file and os.path.isfile(self.config_file):
            cmd += ["-c", self.config_file]

        try:
            self._process = subprocess.Popen(cmd)
            logger.info("Launched T32: %s", " ".join(cmd))
        except Exception as exc:
            logger.error("Failed to launch T32: %s", exc)
            return False

        # Wait for the RCL port to become available
        deadline = time.monotonic() + wait_seconds
        while time.monotonic() < deadline:
            if self.connect():
                return True
            time.sleep(1.0)

        logger.error(
            "T32 launched but RCL connection not established within %.0fs.", wait_seconds
        )
        return False

    # ------------------------------------------------------------------
    # Sanity check
    # ------------------------------------------------------------------

    def run_hello_world(self, script_path: Optional[str] = None) -> bool:
        """Run a minimal CMM 'Hello World' script to verify T32 connectivity.

        If *script_path* is ``None``, an inline script is written to a
        temporary file and cleaned up automatically.  This method requires an
        active connection (call :meth:`connect` or :meth:`launch` first).

        Args:
            script_path: Path to an existing ``.cmm`` file, or ``None`` to use
                the built-in inline script.

        Returns:
            True if the script executed without reported errors.
        """
        if not self._connected or self._dbg is None:
            logger.error("run_hello_world called but Trace32 is not connected.")
            return False

        cleanup = False
        if script_path is None:
            cmm_content = (
                '; Hello World sanity check – auto-generated\n'
                'PRINT "Hello World from Trace32!"\n'
                'PRINT "  Version: " VERSION.BUILD()\n'
                'ENDDO\n'
            )
            tmp = tempfile.NamedTemporaryFile(
                mode="w", suffix=".cmm", delete=False
            )
            tmp.write(cmm_content)
            tmp.close()
            script_path = tmp.name
            cleanup = True

        try:
            return self.run_cmm(script_path)
        finally:
            if cleanup:
                try:
                    os.unlink(script_path)
                except OSError:
                    pass
