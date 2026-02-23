"""
Automotive Tester – Main GUI entry point.

Provides a tkinter-based UI for:
  - Loading test files (Python, CMM, CANoe) into a run queue
  - Configuring and monitoring hardware interfaces
  - Starting / stopping the test queue
  - Viewing live serial port output
  - Camera preview
  - Power supply status
  - Debug / script editing for failing tests
  - Vector CAN/CAN-FD diagnostic automation & sequencer (CAN/Diag tab)
"""
from __future__ import annotations

import json
import logging
import os
import sys
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext, ttk
from typing import Any, Dict, List, Optional

# ---------------------------------------------------------------------------
# Ensure project root is on the path when launched directly
# ---------------------------------------------------------------------------
_ROOT = os.path.dirname(os.path.abspath(__file__))
if _ROOT not in sys.path:
    sys.path.insert(0, _ROOT)

from core.debugger import DebugPanel, ScriptEditor  # noqa: E402
from core.logger import Logger  # noqa: E402
from core.test_runner import TestItem, TestResult, TestRunner, TestStatus, TestType  # noqa: E402
from core.can_diag import CanDiagPanel  # noqa: E402
from interfaces.camera_interface import CameraInterface  # noqa: E402
from interfaces.canoe_interface import CANoeInterface  # noqa: E402
from interfaces.power_supply_interface import PowerSupplyInterface  # noqa: E402
from interfaces.serial_interface import SerialInterface  # noqa: E402
from interfaces.trace32_interface import Trace32Interface  # noqa: E402

logger = logging.getLogger("automotive_tester.main")

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
_CONFIG_PATH = os.path.join(_ROOT, "config.json")
_DEFAULT_CONFIG: Dict[str, Any] = {
    "trace32": {"host": "localhost", "port": 20000},
    "power_supply": {"port": "COM3", "baud_rate": 9600, "timeout": 2},
    "camera": {"index": 0},
    "serial_ports": [
        {"name": "DUT1", "port": "COM4", "baud_rate": 115200},
        {"name": "DUT2", "port": "COM5", "baud_rate": 115200},
        {"name": "DUT3", "port": "COM6", "baud_rate": 115200},
        {"name": "DUT4", "port": "COM7", "baud_rate": 115200},
    ],
    "logging": {"log_dir": "logs", "level": "INFO"},
    "test_runner": {"auto_retry": True, "retry_count": 1, "timeout": 300},
}

_STATUS_COLORS = {
    TestStatus.QUEUED: "#6c757d",
    TestStatus.RUNNING: "#007bff",
    TestStatus.SUCCESS: "#28a745",
    TestStatus.FAILED: "#dc3545",
    TestStatus.ERROR: "#fd7e14",
    TestStatus.SKIPPED: "#6c757d",
}

_FILE_TYPES = [
    ("All Test Files", "*.py *.cmm *.can"),
    ("Python Scripts", "*.py"),
    ("CMM Scripts", "*.cmm"),
    ("CANoe Scripts", "*.can"),
    ("All Files", "*.*"),
]


# ===========================================================================
# Settings dialog
# ===========================================================================

class SettingsDialog(tk.Toplevel):
    """Modal dialog for editing application configuration."""

    def __init__(self, parent: tk.Widget, config: Dict[str, Any]) -> None:
        super().__init__(parent)
        self.title("Settings")
        self.geometry("520x440")
        self.resizable(False, False)
        self.grab_set()
        self._config = json.loads(json.dumps(config))   # deep copy
        self._result: Optional[Dict[str, Any]] = None
        self._build_ui()

    def _build_ui(self) -> None:
        nb = ttk.Notebook(self)
        nb.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

        # ── Trace32 tab ────────────────────────────────────────────
        t32_frame = ttk.Frame(nb)
        nb.add(t32_frame, text="Trace32")
        self._t32_host = self._labeled_entry(t32_frame, "Host:", self._config["trace32"]["host"], 0)
        self._t32_port = self._labeled_entry(t32_frame, "Port:", str(self._config["trace32"]["port"]), 1)

        # ── Power Supply tab ───────────────────────────────────────
        ps_frame = ttk.Frame(nb)
        nb.add(ps_frame, text="Power Supply")
        self._ps_port = self._labeled_entry(ps_frame, "COM Port:", self._config["power_supply"]["port"], 0)
        self._ps_baud = self._labeled_entry(ps_frame, "Baud Rate:", str(self._config["power_supply"]["baud_rate"]), 1)

        # ── Camera tab ─────────────────────────────────────────────
        cam_frame = ttk.Frame(nb)
        nb.add(cam_frame, text="Camera")
        self._cam_index = self._labeled_entry(cam_frame, "Device Index:", str(self._config["camera"]["index"]), 0)

        # ── Serial Ports tab ───────────────────────────────────────
        ser_frame = ttk.Frame(nb)
        nb.add(ser_frame, text="Serial Ports")
        self._ser_entries: List[Dict[str, tk.Entry]] = []
        for row, sp in enumerate(self._config["serial_ports"]):
            ttk.Label(ser_frame, text=sp["name"]).grid(row=row, column=0, sticky=tk.W, padx=8, pady=3)
            port_var = tk.StringVar(value=sp["port"])
            baud_var = tk.StringVar(value=str(sp["baud_rate"]))
            ttk.Entry(ser_frame, textvariable=port_var, width=10).grid(row=row, column=1, padx=4)
            ttk.Entry(ser_frame, textvariable=baud_var, width=10).grid(row=row, column=2, padx=4)
            self._ser_entries.append({"port": port_var, "baud": baud_var})

        # ── Runner tab ─────────────────────────────────────────────
        run_frame = ttk.Frame(nb)
        nb.add(run_frame, text="Test Runner")
        self._retry_var = tk.BooleanVar(value=self._config["test_runner"]["auto_retry"])
        self._retry_count = self._labeled_entry(run_frame, "Retry Count:", str(self._config["test_runner"]["retry_count"]), 1)
        ttk.Checkbutton(run_frame, text="Auto-retry on failure", variable=self._retry_var).grid(
            row=0, column=0, columnspan=2, sticky=tk.W, padx=8, pady=4
        )

        # ── Buttons ────────────────────────────────────────────────
        btn_bar = tk.Frame(self)
        tk.Button(btn_bar, text="✔  Save", bg="#28a745", fg="white", command=self._save).pack(side=tk.LEFT, padx=4, pady=4)
        tk.Button(btn_bar, text="✖  Cancel", bg="#dc3545", fg="white", command=self.destroy).pack(side=tk.LEFT, padx=4, pady=4)
        btn_bar.pack(fill=tk.X)

    def _labeled_entry(self, parent: tk.Widget, label: str, value: str, row: int) -> tk.StringVar:
        var = tk.StringVar(value=value)
        ttk.Label(parent, text=label).grid(row=row, column=0, sticky=tk.W, padx=8, pady=4)
        ttk.Entry(parent, textvariable=var, width=28).grid(row=row, column=1, padx=4, pady=4)
        return var

    def _save(self) -> None:
        try:
            self._config["trace32"]["host"] = self._t32_host.get()
            self._config["trace32"]["port"] = int(self._t32_port.get())
            self._config["power_supply"]["port"] = self._ps_port.get()
            self._config["power_supply"]["baud_rate"] = int(self._ps_baud.get())
            self._config["camera"]["index"] = int(self._cam_index.get())
            for i, entry in enumerate(self._ser_entries):
                self._config["serial_ports"][i]["port"] = entry["port"].get()
                self._config["serial_ports"][i]["baud_rate"] = int(entry["baud"].get())
            self._config["test_runner"]["auto_retry"] = self._retry_var.get()
            self._config["test_runner"]["retry_count"] = int(self._retry_count.get())
        except ValueError as exc:
            messagebox.showerror("Invalid input", str(exc), parent=self)
            return
        self._result = self._config
        self.destroy()

    @property
    def result(self) -> Optional[Dict[str, Any]]:
        """Returns the edited config dict, or None if cancelled."""
        return self._result


# ===========================================================================
# Main Application
# ===========================================================================

class MainApp:
    """Root application class: constructs the UI and owns all interface objects."""

    def __init__(self, root: tk.Tk) -> None:
        self.root = root
        self.root.title("Automotive Tester")
        self.root.geometry("1100x720")
        self.root.minsize(900, 600)

        self._config = self._load_config()
        self._log_manager = Logger(
            log_dir=self._resolve_log_dir(),
            level=self._config["logging"]["level"],
        )

        # Hardware interfaces
        self._trace32 = Trace32Interface(**self._config["trace32"])
        self._power_supply = PowerSupplyInterface()
        self._camera = CameraInterface()
        self._serial = SerialInterface()
        self._canoe = CANoeInterface()

        # Test runner
        rc = self._config["test_runner"]
        self._runner = TestRunner(
            log_manager=self._log_manager,
            auto_retry=rc["auto_retry"],
            retry_count=rc["retry_count"],
            timeout=rc["timeout"],
        )
        self._runner.set_interfaces(trace32=self._trace32, canoe=self._canoe)

        # Track treeview item IDs by test name
        self._tree_ids: Dict[str, str] = {}

        # Camera update job handle
        self._camera_job: Optional[str] = None

        self._setup_serial_ports()
        self._build_ui()
        self.root.protocol("WM_DELETE_WINDOW", self._on_close)

    # ------------------------------------------------------------------
    # Configuration
    # ------------------------------------------------------------------

    def _load_config(self) -> Dict[str, Any]:
        if os.path.isfile(_CONFIG_PATH):
            try:
                with open(_CONFIG_PATH, "r", encoding="utf-8") as fh:
                    return json.load(fh)
            except (json.JSONDecodeError, OSError) as exc:
                logger.warning("Could not load config.json (%s); using defaults.", exc)
        return json.loads(json.dumps(_DEFAULT_CONFIG))

    def _save_config(self) -> None:
        try:
            with open(_CONFIG_PATH, "w", encoding="utf-8") as fh:
                json.dump(self._config, fh, indent=2)
        except OSError as exc:
            logger.warning("Could not save config.json: %s", exc)

    def _resolve_log_dir(self) -> str:
        raw = self._config["logging"].get("log_dir", "logs")
        return raw if os.path.isabs(raw) else os.path.join(_ROOT, raw)

    def _setup_serial_ports(self) -> None:
        for sp_cfg in self._config["serial_ports"]:
            self._serial.add_port(sp_cfg["name"])

    # ------------------------------------------------------------------
    # UI construction
    # ------------------------------------------------------------------

    def _build_ui(self) -> None:
        self._build_toolbar()

        # Top-level notebook: Tab 1 = Automotive Tester, Tab 2 = CAN/Diag
        notebook = ttk.Notebook(self.root)
        notebook.pack(fill=tk.BOTH, expand=True)

        # --- Tab 1: Automotive Tester ---
        auto_tab = tk.Frame(notebook)
        notebook.add(auto_tab, text="🧪  Automotive Tester")
        self._build_auto_tester_tab(auto_tab)

        # --- Tab 2: CAN / Diag Tester ---
        can_tab = CanDiagPanel(notebook)
        notebook.add(can_tab, text="🔌  CAN / Diag Tester")

        self._build_status_bar()

    def _build_auto_tester_tab(self, parent: tk.Widget) -> None:
        """Builds the Automotive Tester content inside *parent*."""
        # Horizontal paned: left = tests+debug, right = status panels
        paned = tk.PanedWindow(parent, orient=tk.HORIZONTAL, sashrelief=tk.RAISED)
        paned.pack(fill=tk.BOTH, expand=True)

        left_frame = tk.Frame(paned)
        paned.add(left_frame, minsize=600)

        right_frame = tk.Frame(paned, width=280)
        paned.add(right_frame, minsize=250)

        self._build_test_table(left_frame)
        self._build_debug_panel(left_frame)
        self._build_log_panel(left_frame)
        self._build_right_panels(right_frame)

    def _build_toolbar(self) -> None:
        toolbar = tk.Frame(self.root, bd=1, relief=tk.RAISED, bg="#343a40")
        toolbar.pack(side=tk.TOP, fill=tk.X)

        def _btn(text: str, cmd: Any, bg: str = "#495057", fg: str = "white") -> None:
            tk.Button(
                toolbar, text=text, command=cmd,
                bg=bg, fg=fg, relief=tk.FLAT,
                padx=8, pady=4, font=("Segoe UI", 9),
            ).pack(side=tk.LEFT, padx=2, pady=2)

        _btn("📂  Load Tests", self._load_tests)
        _btn("⚙️  Settings", self._open_settings)
        tk.Frame(toolbar, width=12, bg="#343a40").pack(side=tk.LEFT)  # spacer
        _btn("▶  Start Queue", self._start_queue, bg="#28a745")
        _btn("■  Stop Queue", self._stop_queue, bg="#dc3545")
        tk.Frame(toolbar, width=12, bg="#343a40").pack(side=tk.LEFT)  # spacer
        _btn("🔍  Debug", self._open_debug, bg="#ffc107", fg="#212529")
        _btn("🗑  Clear Queue", self._clear_queue)

        # Connection buttons
        tk.Frame(toolbar, bg="#343a40").pack(side=tk.LEFT, expand=True)
        _btn("🔌  Connect All", self._connect_all, bg="#17a2b8")

    def _build_test_table(self, parent: tk.Widget) -> None:
        header = tk.Frame(parent, bg="#495057")
        tk.Label(
            header, text="📋  Test Queue", bg="#495057", fg="white",
            font=("Segoe UI", 10, "bold"), padx=8,
        ).pack(side=tk.LEFT, pady=3)
        header.pack(fill=tk.X)

        cols = ("File", "Type", "Status", "Result", "Duration")
        self._tree = ttk.Treeview(parent, columns=cols, show="headings", height=14)
        self._tree.heading("File", text="Script File")
        self._tree.heading("Type", text="Type")
        self._tree.heading("Status", text="Status")
        self._tree.heading("Result", text="Result / Message")
        self._tree.heading("Duration", text="Duration (s)")
        self._tree.column("File", width=260, anchor=tk.W)
        self._tree.column("Type", width=70, anchor=tk.CENTER)
        self._tree.column("Status", width=80, anchor=tk.CENTER)
        self._tree.column("Result", width=280, anchor=tk.W)
        self._tree.column("Duration", width=90, anchor=tk.CENTER)

        # Tag colours per status
        for status, colour in _STATUS_COLORS.items():
            self._tree.tag_configure(status.value, foreground=colour)

        scrollbar = ttk.Scrollbar(parent, orient=tk.VERTICAL, command=self._tree.yview)
        self._tree.configure(yscrollcommand=scrollbar.set)
        self._tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.LEFT, fill=tk.Y)

        # Right-click context menu
        self._context_menu = tk.Menu(self.root, tearoff=0)
        self._context_menu.add_command(label="📝  Edit Script", command=self._edit_selected)
        self._context_menu.add_command(label="↩  Re-queue", command=self._requeue_selected)
        self._context_menu.add_separator()
        self._context_menu.add_command(label="🗑  Remove", command=self._remove_selected)
        self._tree.bind("<Button-3>", self._show_context_menu)

    def _build_debug_panel(self, parent: tk.Widget) -> None:
        self._debug_panel = DebugPanel(parent, requeue_callback=self._requeue_path, bg="#fff3cd", relief=tk.GROOVE, bd=1)
        self._debug_panel.pack(fill=tk.X, padx=2, pady=2)

    def _build_log_panel(self, parent: tk.Widget) -> None:
        header = tk.Frame(parent, bg="#343a40")
        tk.Label(
            header, text="📜  Log Output", bg="#343a40", fg="white",
            font=("Segoe UI", 9, "bold"), padx=8,
        ).pack(side=tk.LEFT, pady=2)
        tk.Button(
            header, text="Clear", bg="#6c757d", fg="white",
            font=("Segoe UI", 8), relief=tk.FLAT,
            command=self._clear_log,
        ).pack(side=tk.RIGHT, padx=4, pady=2)
        header.pack(fill=tk.X)

        self._log_text = scrolledtext.ScrolledText(
            parent, height=8, state=tk.DISABLED,
            font=("Consolas", 9), bg="#1e1e1e", fg="#d4d4d4",
        )
        self._log_text.pack(fill=tk.BOTH, expand=False)

        # Wire a logging handler to write to this widget
        handler = _TkLogHandler(self._append_log)
        handler.setLevel(logging.DEBUG)
        logging.getLogger("automotive_tester").addHandler(handler)

    def _build_right_panels(self, parent: tk.Widget) -> None:
        # ── Power Supply ───────────────────────────────────────────
        ps_frame = tk.LabelFrame(parent, text=" ⚡ Power Supply ", font=("Segoe UI", 9, "bold"), padx=6, pady=4)
        ps_frame.pack(fill=tk.X, padx=4, pady=4)

        self._ps_status_var = tk.StringVar(value="Not connected")
        tk.Label(ps_frame, textvariable=self._ps_status_var, font=("Consolas", 9)).pack(anchor=tk.W)

        ps_ctrl = tk.Frame(ps_frame)
        ps_ctrl.pack(fill=tk.X, pady=2)
        tk.Label(ps_ctrl, text="Voltage (V):").grid(row=0, column=0, sticky=tk.W)
        self._ps_volt_var = tk.StringVar(value="12.0")
        tk.Entry(ps_ctrl, textvariable=self._ps_volt_var, width=8).grid(row=0, column=1, padx=2)
        tk.Label(ps_ctrl, text="Current (A):").grid(row=1, column=0, sticky=tk.W)
        self._ps_curr_var = tk.StringVar(value="1.0")
        tk.Entry(ps_ctrl, textvariable=self._ps_curr_var, width=8).grid(row=1, column=1, padx=2)
        tk.Button(ps_ctrl, text="Set", command=self._ps_apply, width=5).grid(row=0, column=2, rowspan=2, padx=4)
        tk.Button(ps_frame, text="Output ON", bg="#28a745", fg="white", command=self._ps_on).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(ps_frame, text="Output OFF", bg="#dc3545", fg="white", command=self._ps_off).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(ps_frame, text="Refresh", command=self._ps_refresh).pack(side=tk.RIGHT, padx=2)

        # ── Serial Ports ───────────────────────────────────────────
        ser_frame = tk.LabelFrame(parent, text=" 🔌 Serial Ports ", font=("Segoe UI", 9, "bold"), padx=6, pady=4)
        ser_frame.pack(fill=tk.X, padx=4, pady=4)

        self._ser_status_vars: Dict[str, tk.StringVar] = {}
        for sp_cfg in self._config["serial_ports"]:
            name = sp_cfg["name"]
            row_frame = tk.Frame(ser_frame)
            row_frame.pack(fill=tk.X, pady=1)
            tk.Label(row_frame, text=f"{name}:", width=6, anchor=tk.W).pack(side=tk.LEFT)
            var = tk.StringVar(value="●  Disconnected")
            self._ser_status_vars[name] = var
            tk.Label(row_frame, textvariable=var, fg="#6c757d", font=("Consolas", 8)).pack(side=tk.LEFT)
            tk.Button(
                row_frame, text="Connect",
                command=lambda n=name, cfg=sp_cfg: self._connect_serial(n, cfg),
                relief=tk.FLAT, bg="#17a2b8", fg="white", font=("Segoe UI", 8),
            ).pack(side=tk.RIGHT, padx=2)

        # ── Camera ─────────────────────────────────────────────────
        cam_frame = tk.LabelFrame(parent, text=" 📷 Camera Preview ", font=("Segoe UI", 9, "bold"), padx=4, pady=4)
        cam_frame.pack(fill=tk.BOTH, expand=True, padx=4, pady=4)

        self._cam_label = tk.Label(cam_frame, text="Camera not started", bg="#1e1e1e", fg="#6c757d")
        self._cam_label.pack(fill=tk.BOTH, expand=True)

        cam_btns = tk.Frame(cam_frame)
        cam_btns.pack(fill=tk.X)
        tk.Button(cam_btns, text="▶ Start", command=self._cam_start, bg="#28a745", fg="white").pack(side=tk.LEFT, padx=2)
        tk.Button(cam_btns, text="■ Stop", command=self._cam_stop, bg="#dc3545", fg="white").pack(side=tk.LEFT, padx=2)
        tk.Button(cam_btns, text="📸 Snapshot", command=self._cam_snapshot).pack(side=tk.LEFT, padx=2)

    def _build_status_bar(self) -> None:
        bar = tk.Frame(self.root, bd=1, relief=tk.SUNKEN, bg="#f8f9fa")
        bar.pack(side=tk.BOTTOM, fill=tk.X)
        self._statusbar_var = tk.StringVar(value="Ready.")
        tk.Label(bar, textvariable=self._statusbar_var, anchor=tk.W, padx=8, font=("Segoe UI", 8), bg="#f8f9fa").pack(side=tk.LEFT)
        self._queue_count_var = tk.StringVar(value="Queue: 0")
        tk.Label(bar, textvariable=self._queue_count_var, anchor=tk.E, padx=8, font=("Segoe UI", 8), bg="#f8f9fa").pack(side=tk.RIGHT)

    # ------------------------------------------------------------------
    # Toolbar actions
    # ------------------------------------------------------------------

    def _load_tests(self) -> None:
        files = filedialog.askopenfilenames(
            title="Select test files",
            filetypes=_FILE_TYPES,
        )
        for path in files:
            ext = os.path.splitext(path)[1].lower()
            test_type = {".py": TestType.PYTHON, ".cmm": TestType.CMM, ".can": TestType.CANOE}.get(ext)
            if test_type is None:
                logger.warning("Skipping unsupported file type: %s", path)
                continue
            name = os.path.basename(path)
            item = TestItem(name=name, test_type=test_type, path=path)
            self._runner.add(item)
            iid = self._tree.insert(
                "", "end",
                values=(name, test_type.value.upper(), TestStatus.QUEUED.value, "", ""),
                tags=(TestStatus.QUEUED.value,),
            )
            self._tree_ids[name] = iid
        self._update_queue_count()

    def _open_settings(self) -> None:
        dlg = SettingsDialog(self.root, self._config)
        self.root.wait_window(dlg)
        if dlg.result:
            self._config = dlg.result
            self._save_config()
            self._set_status("Settings saved.")

    def _start_queue(self) -> None:
        if self._runner.is_running:
            self._set_status("Queue already running.")
            return
        run_dir = self._log_manager.start_run("auto")
        self._set_status(f"Queue started. Logs → {run_dir}")
        # Start serial logging
        self._serial.start_all_logging(run_dir)
        self._runner.start(status_callback=self._on_test_result)

    def _stop_queue(self) -> None:
        self._runner.stop()
        self._serial.stop_all_logging()
        self._log_manager.end_run()
        self._set_status("Queue stopped.")

    def _clear_queue(self) -> None:
        self._runner.clear()
        for iid in self._tree.get_children():
            self._tree.delete(iid)
        self._tree_ids.clear()
        self._update_queue_count()

    def _open_debug(self) -> None:
        sel = self._tree.selection()
        if not sel:
            messagebox.showinfo("Debug", "Select a test item first.", parent=self.root)
            return
        values = self._tree.item(sel[0])["values"]
        # Find the matching TestItem path via name
        name = values[0]
        # Search runner results for the path
        for result in self._runner.results:
            if result.item.name == name:
                ScriptEditor(self.root, result.item.path, self._requeue_path)
                return
        messagebox.showinfo("Debug", "No completed run data found for this item.", parent=self.root)

    def _connect_all(self) -> None:
        t32_cfg = self._config["trace32"]
        self._trace32 = Trace32Interface(**t32_cfg)
        ok = self._trace32.connect()
        self._set_status(f"Trace32: {'connected' if ok else 'not available'}.")

        ps_cfg = self._config["power_supply"]
        ok_ps = self._power_supply.connect(ps_cfg["port"], ps_cfg["baud_rate"])
        self._set_status(f"Power supply: {'connected' if ok_ps else 'not available'}.")

        cam_cfg = self._config["camera"]
        ok_cam = self._camera.connect(cam_cfg["index"])
        self._set_status(f"Camera: {'connected' if ok_cam else 'not available'}.")

        self._runner.set_interfaces(trace32=self._trace32, canoe=self._canoe)

    # ------------------------------------------------------------------
    # Power supply controls
    # ------------------------------------------------------------------

    def _ps_apply(self) -> None:
        if not self._power_supply.is_connected:
            self._set_status("Power supply not connected.")
            return
        try:
            v = float(self._ps_volt_var.get())
            a = float(self._ps_curr_var.get())
        except ValueError:
            messagebox.showerror("Input Error", "Invalid voltage or current value.", parent=self.root)
            return
        self._power_supply.set_voltage(v)
        self._power_supply.set_current(a)
        self._set_status(f"Power supply set to {v:.2f} V / {a:.2f} A.")

    def _ps_on(self) -> None:
        if self._power_supply.output_on():
            self._set_status("Power supply output ON.")
        else:
            self._set_status("Power supply not connected.")

    def _ps_off(self) -> None:
        if self._power_supply.output_off():
            self._set_status("Power supply output OFF.")
        else:
            self._set_status("Power supply not connected.")

    def _ps_refresh(self) -> None:
        v, i = self._power_supply.read_status()
        if v is not None and i is not None:
            self._ps_status_var.set(f"{v:.3f} V  |  {i:.3f} A")
        else:
            self._ps_status_var.set("Not connected / no data")

    # ------------------------------------------------------------------
    # Serial port controls
    # ------------------------------------------------------------------

    def _connect_serial(self, name: str, cfg: Dict[str, Any]) -> None:
        ok = self._serial.connect_port(name, cfg["port"], cfg["baud_rate"])
        text = f"●  {cfg['port']} @ {cfg['baud_rate']}" if ok else "●  Failed"
        var = self._ser_status_vars.get(name)
        if var:
            var.set(text)
            # Update label colour via a fresh Label (StringVar can't hold fg)

    # ------------------------------------------------------------------
    # Camera controls
    # ------------------------------------------------------------------

    def _cam_start(self) -> None:
        if not self._camera.is_connected:
            idx = self._config["camera"]["index"]
            if not self._camera.connect(idx):
                self._set_status("Camera not available.")
                return
        self._camera.start_stream(callback=self._on_camera_frame)
        self._set_status("Camera stream started.")

    def _cam_stop(self) -> None:
        self._camera.stop_stream()
        if self._camera_job:
            self.root.after_cancel(self._camera_job)
            self._camera_job = None
        self._cam_label.config(image="", text="Camera stopped.")
        self._set_status("Camera stream stopped.")

    def _cam_snapshot(self) -> None:
        if not self._camera.is_connected:
            self._set_status("Camera not connected.")
            return
        run_dir = self._log_manager.run_dir or _ROOT
        import time as _time
        ts = _time.strftime("%Y%m%d_%H%M%S")
        path = os.path.join(run_dir, f"snapshot_{ts}.png")
        if self._camera.save_frame(path):
            self._set_status(f"Snapshot saved: {path}")
        else:
            self._set_status("Snapshot failed.")

    def _on_camera_frame(self, frame: Any) -> None:
        """Receive a new frame from the camera stream thread."""
        photo = CameraInterface.frame_to_photoimage(frame)
        if photo is not None:
            self.root.after(0, self._update_cam_label, photo)

    def _update_cam_label(self, photo: Any) -> None:
        self._cam_label.config(image=photo, text="")
        self._cam_label.image = photo  # type: ignore[attr-defined]  # keep reference

    # ------------------------------------------------------------------
    # Test result callback
    # ------------------------------------------------------------------

    def _on_test_result(self, result: TestResult) -> None:
        """Called from the runner worker thread; marshals update to the UI thread."""
        self.root.after(0, self._apply_result, result)

    def _apply_result(self, result: TestResult) -> None:
        name = result.item.name
        iid = self._tree_ids.get(name)
        status = result.status.value
        message = result.message[:120] if result.message else ""
        duration = f"{result.duration_s:.2f}"
        if iid:
            self._tree.item(
                iid,
                values=(name, result.item.test_type.value.upper(), status, message, duration),
                tags=(status,),
            )
        if result.status in (TestStatus.FAILED, TestStatus.ERROR):
            self._debug_panel.set_failure(result.item.path, result.message)
        self._update_queue_count()

    # ------------------------------------------------------------------
    # Context menu / tree actions
    # ------------------------------------------------------------------

    def _show_context_menu(self, event: tk.Event) -> None:
        row = self._tree.identify_row(event.y)
        if row:
            self._tree.selection_set(row)
            self._context_menu.post(event.x_root, event.y_root)

    def _edit_selected(self) -> None:
        sel = self._tree.selection()
        if not sel:
            return
        name = self._tree.item(sel[0])["values"][0]
        for result in self._runner.results:
            if result.item.name == name:
                ScriptEditor(self.root, result.item.path, self._requeue_path)
                return
        # If not in results, search through queued items
        self._set_status(f"No completed run data found for {name}.")

    def _requeue_selected(self) -> None:
        sel = self._tree.selection()
        if not sel:
            return
        name = self._tree.item(sel[0])["values"][0]
        for result in self._runner.results:
            if result.item.name == name:
                self._requeue_path(result.item.path)
                return

    def _remove_selected(self) -> None:
        sel = self._tree.selection()
        for iid in sel:
            name = self._tree.item(iid)["values"][0]
            self._tree.delete(iid)
            self._tree_ids.pop(name, None)
        self._update_queue_count()

    def _requeue_path(self, path: str) -> None:
        ext = os.path.splitext(path)[1].lower()
        test_type = {".py": TestType.PYTHON, ".cmm": TestType.CMM, ".can": TestType.CANOE}.get(ext, TestType.PYTHON)
        name = os.path.basename(path)
        item = TestItem(name=name, test_type=test_type, path=path)
        self._runner.add(item)
        iid = self._tree.insert(
            "", "end",
            values=(name, test_type.value.upper(), TestStatus.QUEUED.value, "Re-queued", ""),
            tags=(TestStatus.QUEUED.value,),
        )
        self._tree_ids[name] = iid
        messagebox.showinfo("Queue", f"{name} updated and re-added to queue.", parent=self.root)
        self._update_queue_count()

    # ------------------------------------------------------------------
    # Log panel
    # ------------------------------------------------------------------

    def _append_log(self, msg: str) -> None:
        self._log_text.config(state=tk.NORMAL)
        self._log_text.insert(tk.END, msg + "\n")
        self._log_text.see(tk.END)
        self._log_text.config(state=tk.DISABLED)

    def _clear_log(self) -> None:
        self._log_text.config(state=tk.NORMAL)
        self._log_text.delete("1.0", tk.END)
        self._log_text.config(state=tk.DISABLED)

    # ------------------------------------------------------------------
    # Status bar
    # ------------------------------------------------------------------

    def _set_status(self, msg: str) -> None:
        self._statusbar_var.set(msg)
        logger.info(msg)

    def _update_queue_count(self) -> None:
        count = len(self._tree.get_children())
        self._queue_count_var.set(f"Queue: {count}")

    # ------------------------------------------------------------------
    # Shutdown
    # ------------------------------------------------------------------

    def _on_close(self) -> None:
        self._runner.stop()
        self._camera.disconnect()
        self._serial.disconnect_all()
        self._power_supply.disconnect()
        self._trace32.disconnect()
        self._canoe.disconnect()
        self._log_manager.end_run()
        self.root.destroy()


# ===========================================================================
# Logging → tkinter bridge
# ===========================================================================

class _TkLogHandler(logging.Handler):
    """Forwards log records to a tkinter text widget via a thread-safe callback."""

    def __init__(self, append_fn: Any) -> None:
        super().__init__()
        self._append = append_fn
        self.setFormatter(
            logging.Formatter("%(asctime)s [%(levelname)s] %(message)s", datefmt="%H:%M:%S")
        )

    def emit(self, record: logging.LogRecord) -> None:
        try:
            msg = self.format(record)
            self._append(msg)
        except Exception:
            self.handleError(record)


# ===========================================================================
# Entry point
# ===========================================================================

if __name__ == "__main__":
    root = tk.Tk()
    app = MainApp(root)
    root.mainloop()
