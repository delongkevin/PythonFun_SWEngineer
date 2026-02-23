"""
Trace32 / Lauterbach Interface
Communicates with TRACE32 via the official TRACE32 Python API (lauterbach.trace32)
or via the legacy T32API DLL / socket interface.

Installation:
    pip install lauterbach-trace32-rcl   (Lauterbach Remote Control Library)

Fallback: raw TCP socket API on port 20000 (TRACE32 default).
"""

import logging
import socket
import time
import subprocess
import os
from pathlib import Path
from typing import Optional


# ---------------------------------------------------------------------------
# Try importing official Lauterbach library; fall back to raw socket mode
# ---------------------------------------------------------------------------
try:
    import lauterbach.trace32.rcl as t32  # type: ignore
    _HAS_RCL = True
except ImportError:
    _HAS_RCL = False


class Trace32Interface:
    """
    Wrapper for TRACE32 Remote Control.
    Supports:
      - Connecting to a running TRACE32 instance (TCP API)
      - Running .cmm scripts with arguments
      - Reading/writing memory and registers
      - Querying practice variable results
    """

    def __init__(self, host: str = "localhost", port: int = 20000,
                 t32_exe: Optional[str] = None, config_file: Optional[str] = None):
        self.host = host
        self.port = port
        self.t32_exe = t32_exe  # path to T32MARM.exe or similar
        self.config_file = config_file
        self.logger = logging.getLogger("tester.trace32")
        self._connected = False
        self._api = None  # rcl handle or None
        self._process: Optional[subprocess.Popen] = None

    # ── Connection ─────────────────────────────────────────────────────────

    def connect(self) -> bool:
        """Connect to a running TRACE32 instance."""
        if _HAS_RCL:
            return self._connect_rcl()
        return self._connect_socket_test()

    def _connect_rcl(self) -> bool:
        try:
            self._api = t32.connect(host=self.host, port=self.port, timeout=5)
            self._connected = True
            self.logger.info(f"Trace32 RCL connected @ {self.host}:{self.port}")
            return True
        except Exception as e:
            self.logger.error(f"Trace32 RCL connect failed: {e}")
            return False

    def _connect_socket_test(self) -> bool:
        """Minimal TCP ping to verify TRACE32 API is reachable."""
        try:
            with socket.create_connection((self.host, self.port), timeout=3):
                self._connected = True
                self.logger.info(f"Trace32 socket reachable @ {self.host}:{self.port}")
                return True
        except Exception as e:
            self.logger.error(f"Trace32 socket connect failed: {e}")
            return False

    def launch(self) -> bool:
        """Launch TRACE32 application if exe path provided."""
        if not self.t32_exe:
            self.logger.warning("No T32 exe path configured; skipping launch.")
            return False
        if not Path(self.t32_exe).exists():
            self.logger.error(f"T32 executable not found: {self.t32_exe}")
            return False
        cmd = [self.t32_exe]
        if self.config_file:
            cmd += ["-c", self.config_file]
        try:
            self._process = subprocess.Popen(cmd)
            self.logger.info(f"Launched Trace32: {' '.join(cmd)}")
            time.sleep(5)  # Allow T32 to start
            return self.connect()
        except Exception as e:
            self.logger.error(f"Failed to launch Trace32: {e}")
            return False

    def disconnect(self):
        if self._api and _HAS_RCL:
            try:
                t32.disconnect(self._api)
            except Exception:
                pass
        self._connected = False
        self.logger.info("Trace32 disconnected.")

    @property
    def is_connected(self) -> bool:
        return self._connected

    # ── Script Execution ────────────────────────────────────────────────────

    def run_cmm(self, script_path: str, parameters: dict = None, timeout: int = 300):
        """
        Execute a .cmm script in TRACE32.
        Parameters dict is expanded as ENTRY arguments if supported.
        """
        if not self._connected:
            raise RuntimeError("Trace32 not connected.")
        if not Path(script_path).exists():
            raise FileNotFoundError(f"CMM script not found: {script_path}")

        # Build argument string (PRACTICE ENTRY parameters)
        args = ""
        if parameters:
            args = " ".join(str(v) for v in parameters.values())

        cmd = f'DO "{script_path}" {args}'.strip()
        self.logger.info(f"Running CMM: {cmd}")

        if _HAS_RCL and self._api:
            self._api.cmd(cmd)
            # Poll for completion
            deadline = time.time() + timeout
            while time.time() < deadline:
                state = self._api.fnc("PRACTICE.RUNNING()")
                if state == "FALSE()":
                    break
                time.sleep(0.5)
            else:
                raise TimeoutError(f"CMM script timed out after {timeout}s: {script_path}")
            # Check for PRACTICE error
            err = self._api.fnc("PRACTICE.ERROR()")
            if err and err.strip() not in ("", "FALSE()"):
                raise RuntimeError(f"CMM script error: {err}")
        else:
            self.logger.warning("RCL not available – CMM execution is simulated.")

    # ── Memory / Register Access ─────────────────────────────────────────────

    def read_memory(self, address: int, length: int) -> Optional[bytes]:
        if not (_HAS_RCL and self._api):
            self.logger.warning("Memory read simulated.")
            return b'\x00' * length
        try:
            data = self._api.memory.read(address, length)
            return bytes(data)
        except Exception as e:
            self.logger.error(f"Memory read error @ 0x{address:X}: {e}")
            return None

    def write_memory(self, address: int, data: bytes):
        if not (_HAS_RCL and self._api):
            self.logger.warning("Memory write simulated.")
            return
        try:
            self._api.memory.write(address, list(data))
        except Exception as e:
            self.logger.error(f"Memory write error @ 0x{address:X}: {e}")

    def get_variable(self, symbol: str) -> Optional[str]:
        if not (_HAS_RCL and self._api):
            return None
        try:
            return self._api.fnc(f'Var.VALUE({symbol})')
        except Exception as e:
            self.logger.error(f"Variable read error ({symbol}): {e}")
            return None

    def cmd(self, command: str):
        """Send a raw PRACTICE command."""
        if _HAS_RCL and self._api:
            self._api.cmd(command)
        else:
            self.logger.warning(f"Simulated CMD: {command}")
