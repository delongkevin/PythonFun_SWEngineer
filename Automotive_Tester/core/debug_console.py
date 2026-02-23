"""
Debug & Diagnostics Module
Provides interactive debugging tools for troubleshooting:
  - Interface connection tests
  - Manual command injection (serial, trace32, canoe, PSU)
  - Real-time log viewer
  - Script dry-run / syntax check
  - Hardware status dashboard
"""

import logging
import traceback
import importlib.util
import ast
from pathlib import Path
from typing import Optional
from datetime import datetime


class DebugConsole:
    """
    Interactive debug/diagnostics engine.
    Can be driven by the UI or used headlessly via its API.
    """

    def __init__(self, context: dict, logger):
        self.context = context  # hardware handles
        self.tester_logger = logger
        self.logger = logger.get_logger("debug")
        self._command_history: list[str] = []

    # ── Connection Tests ────────────────────────────────────────────────────

    def test_all_connections(self) -> dict:
        results = {}
        results["power_supply"] = self._test_psu()
        results["trace32"] = self._test_trace32()
        results["canoe"] = self._test_canoe()
        results["serial_ports"] = self._test_serial()
        results["camera"] = self._test_camera()
        return results

    def _test_psu(self) -> dict:
        psu = self.context.get("power_supply")
        if psu is None:
            return {"status": "NOT_CONFIGURED"}
        if not psu.is_connected:
            ok = psu.connect()
            return {"status": "CONNECTED" if ok else "FAILED"}
        try:
            v = psu.measure_voltage()
            i = psu.measure_current()
            return {"status": "OK", "voltage": v, "current": i}
        except Exception as e:
            return {"status": "ERROR", "error": str(e)}

    def _test_trace32(self) -> dict:
        t32 = self.context.get("trace32")
        if t32 is None:
            return {"status": "NOT_CONFIGURED"}
        if not t32.is_connected:
            ok = t32.connect()
            return {"status": "CONNECTED" if ok else "FAILED"}
        return {"status": "OK", "connected": t32.is_connected}

    def _test_canoe(self) -> dict:
        canoe = self.context.get("canoe")
        if canoe is None:
            return {"status": "NOT_CONFIGURED"}
        return {"status": "OK" if canoe.is_connected else "DISCONNECTED"}

    def _test_serial(self) -> dict:
        mgr = self.context.get("serial_manager")
        if mgr is None:
            return {"status": "NOT_CONFIGURED"}
        return mgr.status()

    def _test_camera(self) -> dict:
        cam = self.context.get("camera")
        if cam is None:
            return {"status": "NOT_CONFIGURED"}
        return {"status": "OK" if cam.is_connected else "DISCONNECTED"}

    # ── Manual Command Injection ────────────────────────────────────────────

    def send_serial_command(self, terminal_name: str, command: str) -> Optional[str]:
        mgr = self.context.get("serial_manager")
        if not mgr:
            return "Error: Serial manager not initialized."
        term = mgr.get(terminal_name)
        if not term:
            return f"Error: Terminal '{terminal_name}' not found."
        term.send(command)
        # Wait briefly for response
        resp = term.wait_for("", timeout=1.0)
        self._log_cmd(f"SERIAL[{terminal_name}] TX: {command!r}")
        return resp or "(no response)"

    def send_psu_command(self, command: str) -> Optional[str]:
        psu = self.context.get("power_supply")
        if not psu:
            return "Error: PSU not initialized."
        result = psu._send(command)
        self._log_cmd(f"PSU CMD: {command!r} → {result!r}")
        return result

    def send_trace32_command(self, command: str) -> str:
        t32 = self.context.get("trace32")
        if not t32:
            return "Error: Trace32 not initialized."
        try:
            t32.cmd(command)
            self._log_cmd(f"T32 CMD: {command!r}")
            return "OK"
        except Exception as e:
            return f"Error: {e}"

    # ── Script Validation ───────────────────────────────────────────────────

    def validate_python_script(self, script_path: str) -> dict:
        path = Path(script_path)
        if not path.exists():
            return {"valid": False, "error": "File not found"}
        try:
            source = path.read_text()
            tree = ast.parse(source, filename=script_path)
            # Check for required run() function
            has_run = any(
                isinstance(node, ast.FunctionDef) and node.name == "run"
                for node in ast.walk(tree)
            )
            return {
                "valid": True,
                "has_run_function": has_run,
                "lines": len(source.splitlines()),
                "warning": None if has_run else "Missing run() function",
            }
        except SyntaxError as e:
            return {"valid": False, "error": f"SyntaxError line {e.lineno}: {e.msg}"}

    def validate_cmm_script(self, script_path: str) -> dict:
        path = Path(script_path)
        if not path.exists():
            return {"valid": False, "error": "File not found"}
        source = path.read_text(errors="ignore")
        issues = []
        # Basic checks
        if "ENTRY" not in source.upper() and ";" not in source:
            issues.append("No ENTRY declaration or comments found — may not be valid CMM")
        return {
            "valid": True,
            "lines": len(source.splitlines()),
            "issues": issues,
        }

    def dry_run_python(self, script_path: str) -> dict:
        """Import-check only (no execution)."""
        validation = self.validate_python_script(script_path)
        if not validation["valid"]:
            return validation
        try:
            spec = importlib.util.spec_from_file_location("__dry_run__", script_path)
            mod = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(mod)
            return {"valid": True, "dry_run": "PASS", "has_run": hasattr(mod, "run")}
        except Exception as e:
            return {"valid": False, "dry_run": "FAIL", "error": traceback.format_exc()}

    # ── Log Viewer ──────────────────────────────────────────────────────────

    def get_recent_logs(self, n_lines: int = 100) -> list[str]:
        log_path = self.tester_logger.session_path / "main.log"
        if not log_path.exists():
            return []
        with open(log_path) as f:
            lines = f.readlines()
        return lines[-n_lines:]

    def get_test_results_summary(self) -> list[dict]:
        csv_path = self.tester_logger.session_path / "results.csv"
        if not csv_path.exists():
            return []
        rows = []
        with open(csv_path) as f:
            lines = f.readlines()[1:]  # skip header
        for line in lines:
            parts = line.strip().split(",", 3)
            if len(parts) == 4:
                rows.append({
                    "timestamp": parts[0],
                    "test": parts[1].strip('"'),
                    "status": parts[2].strip('"'),
                    "details": parts[3].strip('"'),
                })
        return rows

    def _log_cmd(self, msg: str):
        self._command_history.append(f"[{datetime.now().strftime('%H:%M:%S')}] {msg}")
        self.logger.debug(msg)

    @property
    def command_history(self) -> list[str]:
        return list(self._command_history)
