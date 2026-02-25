"""
Lauterbach Trace32 interface using lauterbach.trace32.rcl.

Gracefully degrades if the lauterbach package is not installed.

Auto-detection searches the default Lauterbach installation directories
(C:\\T32 and D:\\T32) on Windows so that the T32 executable and config file
can be located without manual configuration.

PowerDebug Pro via USB 3.0 is supported: after calling detect_installation()
or setting t32_exe / config_file manually, call launch() to start the T32
process and establish the RCL connection automatically.

Remote API protocol notes
--------------------------
TRACE32 supports two RCL transport modes, configured in ``config.t32``:

* **UDP / NETASSIST** (recommended for most setups)::

      RCL=NETASSIST
      PORT=20000
      PACKLEN=1024

* **TCP / NETTCP**::

      RCL=NETTCP
      PORT=20000

Pass ``protocol="UDP"`` (default) or ``protocol="TCP"`` to
:class:`Trace32Interface` to match your ``config.t32``.

.. note::
   ``Test-NetConnection`` (PowerShell) and tools like ``telnet`` only check
   TCP.  A "connection refused" from those tools does **not** mean TRACE32 is
   unreachable when using UDP/NETASSIST.  Use :meth:`Trace32Interface.connect`
   with ``protocol="UDP"`` to verify UDP connectivity.
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
    """Manages a connection to a Lauterbach Trace32 debugger via RCL.

    Args:
        host: Hostname or IP address of the TRACE32 instance.
        port: RCL port number (must match ``PORT=`` in ``config.t32``).
        protocol: Transport protocol – ``"UDP"`` (default, matches
            ``RCL=NETASSIST``) or ``"TCP"`` (matches ``RCL=NETTCP``).
        packlen: RCL packet length in bytes (must match ``PACKLEN=`` in
            ``config.t32``).  Ignored for TCP connections.
        connect_timeout: Seconds to wait for the RCL handshake before
            raising a timeout error.
        t32_exe: Full path to the TRACE32 executable.  Can be populated
            automatically via :meth:`detect_installation`.
        config_file: Full path to the ``config.t32`` configuration file
            passed to the TRACE32 executable on startup.
    """

    def __init__(
        self,
        host: str = "localhost",
        port: int = 20000,
        protocol: str = "UDP",
        packlen: int = 1024,
        connect_timeout: float = 5.0,
        t32_exe: Optional[str] = None,
        config_file: Optional[str] = None,
        **_kwargs: Any,
    ) -> None:
        self._host = host
        self._port = port
        self._protocol = protocol.upper()
        self._packlen = packlen
        self._connect_timeout = connect_timeout
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

        The connection parameters (``protocol``, ``packlen``, ``port``, and
        ``connect_timeout``) are taken from the instance attributes set at
        construction time or via the respective properties.

        For **UDP / NETASSIST** setups the ``config.t32`` file should contain::

            RCL=NETASSIST
            PORT=20000
            PACKLEN=1024

        For **TCP / NETTCP** setups::

            RCL=NETTCP
            PORT=20000

        Returns:
            True if the connection succeeded, False otherwise.
        """
        if not _TRACE32_AVAILABLE:
            logger.error(
                "Cannot connect: lauterbach.trace32 package is missing. "
                "Install it with: pip install lauterbach-trace32-rcl"
            )
            return False
        try:
            kwargs: Dict[str, Any] = dict(
                node=self._host,
                port=str(self._port),
                protocol=self._protocol,
                timeout=self._connect_timeout,
            )
            # packlen is only relevant for UDP (NETASSIST)
            if self._protocol == "UDP":
                kwargs["packlen"] = self._packlen
            self._dbg = _rcl.connect(**kwargs)
            self._connected = True
            logger.info(
                "Connected to Trace32 at %s:%s via %s",
                self._host, self._port, self._protocol,
            )
            return True
        except Exception as exc:
            hint = (
                "Verify TRACE32 is running and config.t32 has "
                f"RCL={'NETASSIST' if self._protocol == 'UDP' else 'NETTCP'}, "
                f"PORT={self._port}"
            )
            if self._protocol == "UDP":
                hint += f", PACKLEN={self._packlen}"
            logger.error("Trace32 connect failed: %s — %s", exc, hint)
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

        When connected via RCL the script is executed through the remote API.
        If the RCL connection is not available but a T32 executable is
        configured (or auto-detected), the script is executed by launching the
        T32 executable directly with the ``-s`` flag so the CMM script takes
        full control — all paths, flashing logic, etc. are handled inside the
        script itself.  64-bit ``t32marm64.exe`` is tried first; the tool
        falls back to 32-bit ``t32marm.exe`` when the 64-bit binary is not
        found (mirrors the approach used by the Magna CPU-Load tool).

        Args:
            path: Absolute or relative path to the .cmm file.

        Returns:
            True if the script ran without reported errors, False otherwise.
        """
        if not os.path.isfile(path):
            logger.error("CMM script not found: %s", path)
            return False

        if self._connected and self._dbg is not None:
            # Primary path: use the RCL API.
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

        # Fallback: launch T32 with -s <script> so the CMM script takes full control.
        return self._run_cmm_subprocess(path)

    def _resolve_t32_exe(self) -> Optional[str]:
        """Return the T32 executable path to use for subprocess invocation.

        Preference order:

        1. ``self.t32_exe`` when set and the file exists.
        2. Auto-scan ``C:\\T32`` and ``D:\\T32`` on Windows, preferring the
           64-bit binary (``t32marm64.exe``) before the 32-bit one
           (``t32marm.exe``).

        Returns:
            Absolute path string, or ``None`` when no executable is found.
        """
        if self.t32_exe and os.path.isfile(self.t32_exe):
            return self.t32_exe

        if platform.system() != "Windows":
            return None

        for drive in _DEFAULT_INSTALL_DRIVES:
            install_dir = f"{drive}:\\{_DEFAULT_INSTALL_ROOT}"
            if not os.path.isdir(install_dir):
                continue
            for bin_sub in _BIN_SUBDIRS:
                bin_dir = os.path.join(install_dir, bin_sub)
                if not os.path.isdir(bin_dir):
                    continue
                for exe in _EXE_CANDIDATES:
                    candidate = os.path.join(bin_dir, exe)
                    if os.path.isfile(candidate):
                        logger.info("Resolved T32 exe (auto-detect): %s", candidate)
                        return candidate
        return None

    def _run_cmm_subprocess(self, path: str, timeout: float = 120.0) -> bool:
        """Launch the T32 executable with *path* as the startup script (``-s`` flag).

        This mirrors the approach used by the Magna CPU-Load tool:
        ``subprocess.Popen([t32_exe, "-s", cmm_path], ...)``.

        Args:
            path:    Absolute path to the ``.cmm`` script.
            timeout: Seconds to wait for the process to finish before
                     forcibly terminating it.

        Returns:
            ``True`` when the process exits with return-code 0, ``False``
            otherwise.
        """
        exe = self._resolve_t32_exe()
        if not exe:
            logger.error(
                "run_cmm: Trace32 is not connected and no T32 executable is "
                "configured – set t32_exe or use detect_installation()."
            )
            return False

        cmd = [exe, "-s", path]
        logger.info("Launching T32 with CMM script (subprocess): %s", " ".join(cmd))
        try:
            proc = subprocess.Popen(
                cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            try:
                _stdout, stderr = proc.communicate(timeout=timeout)
                rc = proc.returncode
                if stderr:
                    logger.debug(
                        "T32 subprocess stderr: %s",
                        stderr.decode("utf-8", errors="replace"),
                    )
                if rc == 0:
                    logger.info(
                        "CMM script completed (subprocess, rc=0): %s", path
                    )
                    return True
                logger.warning(
                    "CMM script subprocess exited with rc=%d: %s", rc, path
                )
                return False
            except subprocess.TimeoutExpired:
                logger.error(
                    "T32 subprocess timed out after %.0fs for script: %s",
                    timeout,
                    path,
                )
                proc.kill()
                try:
                    proc.communicate()
                except Exception:
                    pass
                return False
        except Exception as exc:
            logger.error("T32 subprocess launch failed: %s", exc)
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

    @property
    def protocol(self) -> str:
        """Transport protocol: ``"UDP"`` (NETASSIST) or ``"TCP"`` (NETTCP)."""
        return self._protocol

    @protocol.setter
    def protocol(self, value: str) -> None:
        self._protocol = value.upper()

    @property
    def packlen(self) -> int:
        """UDP packet length (bytes) – must match ``PACKLEN=`` in config.t32."""
        return self._packlen

    @packlen.setter
    def packlen(self, value: int) -> None:
        self._packlen = int(value)

    @property
    def connect_timeout(self) -> float:
        """Seconds to wait for the RCL handshake."""
        return self._connect_timeout

    @connect_timeout.setter
    def connect_timeout(self, value: float) -> None:
        self._connect_timeout = float(value)

    # ------------------------------------------------------------------
    # Preflight / diagnostics
    # ------------------------------------------------------------------

    def preflight_check(self) -> Dict[str, Any]:
        """Run lightweight diagnostics before attempting to connect.

        Checks are performed in this order:

        1. ``lauterbach.trace32`` package availability.
        2. Existence of :attr:`t32_exe` (if set).
        3. Existence of :attr:`config_file` (if set).
        4. (Optional) That ``config_file`` contains the expected ``RCL=``
           directive for the configured ``protocol``.

        Returns:
            A dict with keys:

            * ``"ok"`` (bool) – ``True`` if all checks passed.
            * ``"issues"`` (list[str]) – Human-readable problem descriptions.
            * ``"suggestions"`` (list[str]) – Actionable remediation hints.
        """
        issues: List[str] = []
        suggestions: List[str] = []

        if not _TRACE32_AVAILABLE:
            issues.append("lauterbach.trace32 package is not installed.")
            suggestions.append(
                "Install it with: pip install lauterbach-trace32-rcl"
            )

        if self.t32_exe:
            if not os.path.isfile(self.t32_exe):
                issues.append(f"T32 executable not found: {self.t32_exe}")
                suggestions.append(
                    "Run 'Auto-detect T32' or set the correct path in Hardware Config."
                )
        else:
            issues.append("T32 executable path is not configured.")
            suggestions.append(
                "Run 'Auto-detect T32' or set t32_exe manually."
            )

        if self.config_file:
            if not os.path.isfile(self.config_file):
                issues.append(f"T32 config file not found: {self.config_file}")
                suggestions.append(
                    "Check the config file path in Hardware Config."
                )
            else:
                self._check_config_rcl(issues, suggestions)
        else:
            issues.append("T32 config file path is not configured.")
            suggestions.append(
                "Set config_file to your config.t32 path in Hardware Config."
            )

        return {"ok": len(issues) == 0, "issues": issues, "suggestions": suggestions}

    def _check_config_rcl(
        self, issues: List[str], suggestions: List[str]
    ) -> None:
        """Parse config_file and warn if the RCL mode mismatches protocol."""
        expected_rcl = "NETASSIST" if self._protocol == "UDP" else "NETTCP"
        try:
            with open(self.config_file, "r", errors="replace") as fh:
                content = fh.read().upper()
            if f"RCL={expected_rcl}" not in content:
                # Check what it actually has
                actual = None
                for candidate in ("NETASSIST", "NETTCP"):
                    if f"RCL={candidate}" in content:
                        actual = candidate
                        break
                if actual:
                    issues.append(
                        f"config.t32 has RCL={actual} but protocol is set to "
                        f"{self._protocol} (expects RCL={expected_rcl})."
                    )
                    opposite = "TCP" if self._protocol == "UDP" else "UDP"
                    suggestions.append(
                        f"Either change protocol to '{opposite}' in Hardware Config, "
                        f"or update config.t32 to use RCL={expected_rcl}."
                    )
                else:
                    logger.debug(
                        "config.t32 does not contain an RCL= line; skipping RCL check."
                    )
        except OSError as exc:
            logger.warning("preflight_check: could not read config file: %s", exc)

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
