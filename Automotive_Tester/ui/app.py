"""
Automotive ECU Tester - Main UI
Built with tkinter (no external UI deps required).

Layout:
  ┌──────────────────────────────────────────────────┐
  │  Toolbar: Connect / Start / Stop / Debug          │
  ├──────────────────────────┬───────────────────────┤
  │  Test Queue (left panel) │  Log Output (right)   │
  │  + Script type badges    │  Real-time streaming  │
  ├──────────────────────────┴───────────────────────┤
  │  Status Bar: PSU V/I · Ports · Camera · T32      │
  └──────────────────────────────────────────────────┘

Tabs:
  1. Test Runner  2. Debug Console  3. Hardware Config  4. Results
"""

import tkinter as tk
from tkinter import ttk, filedialog, messagebox, scrolledtext
import threading
import time
import sys
from pathlib import Path

# Add parent to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from core.logger import TesterLogger  # noqa: E402
from core.queue_manager import TestQueueManager, TestItem, TestType, TestStatus  # noqa: E402
from core.debug_console import DebugConsole  # noqa: E402
from interfaces.trace32_interface import Trace32Interface  # noqa: E402
from interfaces.power_supply import BKPrecision1687B  # noqa: E402
from interfaces.serial_manager import SerialManager  # noqa: E402
from interfaces.camera_interface import CameraInterface  # noqa: E402
from interfaces.canoe_interface import CANoeInterface  # noqa: E402


# ── Color palette ────────────────────────────────────────────────────────────
COLORS = {
    "bg": "#1e1e2e",
    "surface": "#2a2a3e",
    "surface2": "#313145",
    "accent": "#7c6af7",
    "accent2": "#5bc8af",
    "text": "#cdd6f4",
    "text_dim": "#6c7086",
    "success": "#a6e3a1",
    "warning": "#f9e2af",
    "error": "#f38ba8",
    "info": "#89dceb",
    "pending": "#6c7086",
}

TYPE_COLORS = {
    "python": "#3572A5",
    "cmm": "#e67e22",
    "canoe": "#e74c3c",
}

STATUS_COLORS = {
    "PENDING": COLORS["pending"],
    "RUNNING": COLORS["info"],
    "PASSED": COLORS["success"],
    "FAILED": COLORS["error"],
    "SKIPPED": COLORS["warning"],
    "ABORTED": COLORS["error"],
}


class AutomotiveTesterApp:
    """Main application class."""

    def __init__(self):
        self.root = tk.Tk()
        self.root.title("🚗 Automotive ECU Tester")
        self.root.geometry("1400x900")
        self.root.configure(bg=COLORS["bg"])
        self.root.protocol("WM_DELETE_WINDOW", self._on_close)

        # ── Core services ────────────────────────────────────────────────────
        self.tester_logger = TesterLogger(log_dir="logs")
        self.logger = self.tester_logger.get_logger("ui")

        # ── Hardware interfaces (init with defaults; user configures in Settings tab)
        self.psu = BKPrecision1687B(port="COM3")
        _t32_detected = Trace32Interface.detect_installation()
        self.trace32 = Trace32Interface(
            host="localhost",
            port=20000,
            t32_exe=_t32_detected.get("t32_exe"),
            config_file=_t32_detected.get("config_file"),
        )
        self.serial_mgr = SerialManager(log_dir=self.tester_logger.session_path)
        self.camera = CameraInterface(snapshot_dir=self.tester_logger.session_path / "camera")
        self.canoe = CANoeInterface()

        self.context = {
            "power_supply": self.psu,
            "trace32": self.trace32,
            "serial_manager": self.serial_mgr,
            "camera": self.camera,
            "canoe": self.canoe,
            "logger": self.tester_logger,
        }

        self.queue_mgr = TestQueueManager(self.tester_logger, self.context)
        self.queue_mgr.set_status_callback(self._refresh_queue_display)
        self.debug = DebugConsole(self.context, self.tester_logger)

        # ── Build UI ─────────────────────────────────────────────────────────
        self._build_toolbar()
        self._build_notebook()
        self._build_status_bar()

        # Start status polling
        self._poll_status()

    # ════════════════════════════════════════════════════════════════════════
    #  UI Construction
    # ════════════════════════════════════════════════════════════════════════

    def _build_toolbar(self):
        bar = tk.Frame(self.root, bg=COLORS["surface"], height=50)
        bar.pack(fill=tk.X, padx=0, pady=0)
        bar.pack_propagate(False)

        title = tk.Label(bar, text="⚡ ECU Tester", bg=COLORS["surface"],
                         fg=COLORS["accent"], font=("Consolas", 14, "bold"))
        title.pack(side=tk.LEFT, padx=16, pady=8)

        # Separator
        tk.Frame(bar, bg=COLORS["accent"], width=2).pack(side=tk.LEFT, fill=tk.Y, pady=8)

        btns = [
            ("🔌 Connect All", self._connect_all, COLORS["accent"]),
            ("▶ Start Queue", self._start_queue, COLORS["success"]),
            ("⏹ Stop", self._stop_queue, COLORS["error"]),
            ("🐛 Debug", self._show_debug, COLORS["warning"]),
            ("📸 Snapshot", self._take_snapshot, COLORS["info"]),
            ("🔄 Power Cycle", self._power_cycle, COLORS["warning"]),
        ]
        for label, cmd, color in btns:
            b = tk.Button(bar, text=label, command=cmd,
                          bg=COLORS["surface2"], fg=color,
                          font=("Consolas", 10, "bold"),
                          relief=tk.FLAT, padx=12, pady=6,
                          activebackground=COLORS["surface"],
                          activeforeground=color, cursor="hand2")
            b.pack(side=tk.LEFT, padx=4, pady=8)

        # Session ID label
        self.session_label = tk.Label(
            bar, text=f"Session: {self.tester_logger.session_id}",
            bg=COLORS["surface"], fg=COLORS["text_dim"], font=("Consolas", 9))
        self.session_label.pack(side=tk.RIGHT, padx=16)

    def _build_notebook(self):
        style = ttk.Style()
        style.theme_use("default")
        style.configure("Custom.TNotebook", background=COLORS["bg"])
        style.configure("Custom.TNotebook.Tab",
                        background=COLORS["surface2"], foreground=COLORS["text"],
                        padding=[12, 6], font=("Consolas", 10))
        style.map("Custom.TNotebook.Tab",
                  background=[("selected", COLORS["accent"])],
                  foreground=[("selected", "white")])

        self.notebook = ttk.Notebook(self.root, style="Custom.TNotebook")
        self.notebook.pack(fill=tk.BOTH, expand=True, padx=8, pady=(4, 0))

        self._build_runner_tab()
        self._build_debug_tab()
        self._build_config_tab()
        self._build_results_tab()

    # ── Tab 1: Test Runner ───────────────────────────────────────────────────

    def _build_runner_tab(self):
        frame = tk.Frame(self.notebook, bg=COLORS["bg"])
        self.notebook.add(frame, text="  🧪 Test Runner  ")

        # Left: Queue panel
        left = tk.Frame(frame, bg=COLORS["surface"], width=500)
        left.pack(side=tk.LEFT, fill=tk.BOTH, padx=(8, 4), pady=8)
        left.pack_propagate(False)

        # Queue header
        hdr = tk.Frame(left, bg=COLORS["surface"])
        hdr.pack(fill=tk.X, padx=8, pady=(8, 4))
        tk.Label(hdr, text="Test Queue", bg=COLORS["surface"],
                 fg=COLORS["accent"], font=("Consolas", 12, "bold")).pack(side=tk.LEFT)

        for lbl, cmd in [("+ Add", self._add_test_dialog), ("✕ Clear", self._clear_queue)]:
            tk.Button(hdr, text=lbl, command=cmd,
                      bg=COLORS["surface2"], fg=COLORS["text"],
                      font=("Consolas", 9), relief=tk.FLAT, padx=8,
                      cursor="hand2").pack(side=tk.RIGHT, padx=2)

        # Queue listbox
        list_frame = tk.Frame(left, bg=COLORS["surface"])
        list_frame.pack(fill=tk.BOTH, expand=True, padx=8, pady=4)

        self.queue_tree = ttk.Treeview(
            list_frame,
            columns=("type", "status", "duration"),
            show="tree headings", selectmode="browse"
        )
        style = ttk.Style()
        style.configure("Treeview", background=COLORS["surface2"],
                        fieldbackground=COLORS["surface2"],
                        foreground=COLORS["text"], font=("Consolas", 10),
                        rowheight=28)
        style.configure("Treeview.Heading", background=COLORS["surface"],
                        foreground=COLORS["accent"], font=("Consolas", 9, "bold"))
        style.map("Treeview", background=[("selected", COLORS["accent"])])

        self.queue_tree.heading("#0", text="Test Name")
        self.queue_tree.heading("type", text="Type")
        self.queue_tree.heading("status", text="Status")
        self.queue_tree.heading("duration", text="Duration")
        self.queue_tree.column("#0", width=180)
        self.queue_tree.column("type", width=70, anchor=tk.CENTER)
        self.queue_tree.column("status", width=90, anchor=tk.CENTER)
        self.queue_tree.column("duration", width=80, anchor=tk.CENTER)

        vsb = ttk.Scrollbar(list_frame, orient="vertical", command=self.queue_tree.yview)
        self.queue_tree.configure(yscrollcommand=vsb.set)
        vsb.pack(side=tk.RIGHT, fill=tk.Y)
        self.queue_tree.pack(fill=tk.BOTH, expand=True)

        # Queue controls
        ctrl = tk.Frame(left, bg=COLORS["surface"])
        ctrl.pack(fill=tk.X, padx=8, pady=4)
        for lbl, cmd in [("↑ Up", self._move_up), ("↓ Down", self._move_down),
                         ("🗑 Remove", self._remove_selected),
                         ("⏭ Skip", self._skip_selected)]:
            tk.Button(ctrl, text=lbl, command=cmd, bg=COLORS["surface2"],
                      fg=COLORS["text"], font=("Consolas", 9),
                      relief=tk.FLAT, padx=8, cursor="hand2").pack(side=tk.LEFT, padx=2)

        # Right: Log output
        right = tk.Frame(frame, bg=COLORS["bg"])
        right.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(4, 8), pady=8)

        log_hdr = tk.Frame(right, bg=COLORS["bg"])
        log_hdr.pack(fill=tk.X)
        tk.Label(log_hdr, text="Live Log Output", bg=COLORS["bg"],
                 fg=COLORS["accent"], font=("Consolas", 12, "bold")).pack(side=tk.LEFT)
        tk.Button(log_hdr, text="Clear", command=self._clear_log,
                  bg=COLORS["surface2"], fg=COLORS["text_dim"],
                  font=("Consolas", 9), relief=tk.FLAT, padx=8,
                  cursor="hand2").pack(side=tk.RIGHT)

        self.log_output = scrolledtext.ScrolledText(
            right, bg=COLORS["surface2"], fg=COLORS["text"],
            font=("Consolas", 10), state=tk.DISABLED,
            insertbackground=COLORS["accent"], relief=tk.FLAT
        )
        self.log_output.pack(fill=tk.BOTH, expand=True, pady=(4, 0))

        # Tag colors for log
        for tag, color in [("PASS", COLORS["success"]), ("FAIL", COLORS["error"]),
                            ("WARN", COLORS["warning"]), ("INFO", COLORS["info"]),
                            ("DEBUG", COLORS["text_dim"]), ("RUN", COLORS["accent"])]:
            self.log_output.tag_config(tag, foreground=color)

        # Start log tail thread
        self._start_log_tail()

    # ── Tab 2: Debug Console ─────────────────────────────────────────────────

    def _build_debug_tab(self):
        frame = tk.Frame(self.notebook, bg=COLORS["bg"])
        self.notebook.add(frame, text="  🐛 Debug  ")

        # Top: Connection status grid
        status_frame = tk.LabelFrame(frame, text=" Hardware Status ",
                                     bg=COLORS["bg"], fg=COLORS["accent"],
                                     font=("Consolas", 10, "bold"))
        status_frame.pack(fill=tk.X, padx=8, pady=8)

        self.hw_status_labels = {}
        hw_items = [
            ("power_supply", "PSU (BK1687B)"),
            ("trace32", "Trace32/T32"),
            ("canoe", "Vector CANoe"),
            ("camera", "USB Camera"),
        ]
        for i, (key, label) in enumerate(hw_items):
            tk.Label(status_frame, text=label + ":", bg=COLORS["bg"],
                     fg=COLORS["text"], font=("Consolas", 10)).grid(
                row=i // 2, column=(i % 2) * 2, padx=16, pady=4, sticky=tk.W)
            lbl = tk.Label(status_frame, text="● UNKNOWN",
                           bg=COLORS["bg"], fg=COLORS["text_dim"],
                           font=("Consolas", 10, "bold"))
            lbl.grid(row=i // 2, column=(i % 2) * 2 + 1, padx=4, pady=4, sticky=tk.W)
            self.hw_status_labels[key] = lbl

        tk.Button(status_frame, text="🔍 Test All Connections",
                  command=self._test_connections,
                  bg=COLORS["accent"], fg="white",
                  font=("Consolas", 10, "bold"), relief=tk.FLAT, padx=16, pady=4,
                  cursor="hand2").grid(row=2, column=0, columnspan=4, pady=8)

        # Middle: Command injection
        cmd_frame = tk.LabelFrame(frame, text=" Manual Command Injection ",
                                  bg=COLORS["bg"], fg=COLORS["accent"],
                                  font=("Consolas", 10, "bold"))
        cmd_frame.pack(fill=tk.X, padx=8, pady=4)

        row1 = tk.Frame(cmd_frame, bg=COLORS["bg"])
        row1.pack(fill=tk.X, padx=8, pady=4)
        tk.Label(row1, text="Target:", bg=COLORS["bg"], fg=COLORS["text"],
                 font=("Consolas", 10)).pack(side=tk.LEFT)
        self.cmd_target = ttk.Combobox(row1, values=["PSU", "Trace32", "Serial-1",
                                                       "Serial-2", "Serial-3", "Serial-4"],
                                        width=14, font=("Consolas", 10))
        self.cmd_target.set("PSU")
        self.cmd_target.pack(side=tk.LEFT, padx=8)
        tk.Label(row1, text="Command:", bg=COLORS["bg"], fg=COLORS["text"],
                 font=("Consolas", 10)).pack(side=tk.LEFT)
        self.cmd_entry = tk.Entry(row1, bg=COLORS["surface2"], fg=COLORS["text"],
                                   font=("Consolas", 11), relief=tk.FLAT,
                                   insertbackground=COLORS["accent"], width=50)
        self.cmd_entry.pack(side=tk.LEFT, padx=8, fill=tk.X, expand=True)
        self.cmd_entry.bind("<Return>", lambda e: self._send_debug_command())
        tk.Button(row1, text="Send ↵", command=self._send_debug_command,
                  bg=COLORS["accent"], fg="white", font=("Consolas", 10),
                  relief=tk.FLAT, padx=12, cursor="hand2").pack(side=tk.LEFT)

        # Script validation
        val_frame = tk.LabelFrame(frame, text=" Script Validation ",
                                  bg=COLORS["bg"], fg=COLORS["accent"],
                                  font=("Consolas", 10, "bold"))
        val_frame.pack(fill=tk.X, padx=8, pady=4)

        row2 = tk.Frame(val_frame, bg=COLORS["bg"])
        row2.pack(fill=tk.X, padx=8, pady=4)
        self.validate_path = tk.Entry(row2, bg=COLORS["surface2"], fg=COLORS["text"],
                                       font=("Consolas", 10), relief=tk.FLAT,
                                       insertbackground=COLORS["accent"], width=60)
        self.validate_path.pack(side=tk.LEFT, padx=4)
        tk.Button(row2, text="Browse", command=self._browse_validate,
                  bg=COLORS["surface2"], fg=COLORS["text"], font=("Consolas", 9),
                  relief=tk.FLAT, padx=8, cursor="hand2").pack(side=tk.LEFT, padx=4)
        tk.Button(row2, text="Validate", command=self._validate_script,
                  bg=COLORS["accent2"], fg="black", font=("Consolas", 10, "bold"),
                  relief=tk.FLAT, padx=12, cursor="hand2").pack(side=tk.LEFT, padx=4)
        tk.Button(row2, text="Dry Run", command=self._dry_run_script,
                  bg=COLORS["warning"], fg="black", font=("Consolas", 10, "bold"),
                  relief=tk.FLAT, padx=12, cursor="hand2").pack(side=tk.LEFT, padx=4)

        # Debug output
        self.debug_output = scrolledtext.ScrolledText(
            frame, bg=COLORS["surface2"], fg=COLORS["text"],
            font=("Consolas", 10), height=12, relief=tk.FLAT
        )
        self.debug_output.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

    # ── Tab 3: Hardware Config ───────────────────────────────────────────────

    def _build_config_tab(self):
        frame = tk.Frame(self.notebook, bg=COLORS["bg"])
        self.notebook.add(frame, text="  ⚙ Hardware Config  ")

        canvas = tk.Canvas(frame, bg=COLORS["bg"], highlightthickness=0)
        scroll = ttk.Scrollbar(frame, orient="vertical", command=canvas.yview)
        canvas.configure(yscrollcommand=scroll.set)
        scroll.pack(side=tk.RIGHT, fill=tk.Y)
        canvas.pack(fill=tk.BOTH, expand=True)
        inner = tk.Frame(canvas, bg=COLORS["bg"])
        canvas.create_window((0, 0), window=inner, anchor="nw")
        inner.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))

        self.config_vars = {}

        sections = [
            ("🔌 BK Precision 1687B Power Supply", [
                ("psu_port", "COM Port", "COM3"),
                ("psu_baud", "Baud Rate", "9600"),
                ("psu_voltage", "Default Voltage (V)", "12.0"),
                ("psu_current", "Current Limit (A)", "5.0"),
            ]),
            ("🔬 Trace32 / Lauterbach", [
                ("t32_host", "Host", "localhost"),
                ("t32_port", "Port", "20000"),
                ("t32_exe", "T32 Executable Path", self.trace32.t32_exe or ""),
                ("t32_config", "T32 Config File", self.trace32.config_file or ""),
            ]),
            ("📡 Vector CANoe", [
                ("canoe_config", "CANoe Config (.cfg)", ""),
            ]),
            ("🎥 USB Camera", [
                ("cam_index", "Device Index", "0"),
                ("cam_width", "Resolution Width", "1280"),
                ("cam_height", "Resolution Height", "720"),
            ]),
        ]

        for section_title, fields in sections:
            sf = tk.LabelFrame(inner, text=f" {section_title} ",
                               bg=COLORS["bg"], fg=COLORS["accent"],
                               font=("Consolas", 11, "bold"))
            sf.pack(fill=tk.X, padx=16, pady=8)
            for key, label, default in fields:
                row = tk.Frame(sf, bg=COLORS["bg"])
                row.pack(fill=tk.X, padx=12, pady=3)
                tk.Label(row, text=label + ":", bg=COLORS["bg"], fg=COLORS["text"],
                         font=("Consolas", 10), width=28, anchor=tk.W).pack(side=tk.LEFT)
                var = tk.StringVar(value=default)
                ent = tk.Entry(row, textvariable=var, bg=COLORS["surface2"],
                               fg=COLORS["text"], font=("Consolas", 10),
                               relief=tk.FLAT, insertbackground=COLORS["accent"], width=40)
                ent.pack(side=tk.LEFT, padx=8)
                self.config_vars[key] = var

        # Serial Ports section
        serial_frame = tk.LabelFrame(inner, text=" 🔗 Serial Terminal Ports (up to 4) ",
                                     bg=COLORS["bg"], fg=COLORS["accent"],
                                     font=("Consolas", 11, "bold"))
        serial_frame.pack(fill=tk.X, padx=16, pady=8)

        for i in range(1, 5):
            row = tk.Frame(serial_frame, bg=COLORS["bg"])
            row.pack(fill=tk.X, padx=12, pady=3)
            tk.Label(row, text=f"Port {i}:", bg=COLORS["bg"], fg=COLORS["text"],
                     font=("Consolas", 10), width=8, anchor=tk.W).pack(side=tk.LEFT)
            port_var = tk.StringVar(value=f"COM{i + 3}")
            baud_var = tk.StringVar(value="115200")
            tk.Entry(row, textvariable=port_var, bg=COLORS["surface2"], fg=COLORS["text"],
                     font=("Consolas", 10), relief=tk.FLAT, width=12).pack(side=tk.LEFT, padx=4)
            tk.Label(row, text="Baud:", bg=COLORS["bg"], fg=COLORS["text"],
                     font=("Consolas", 10)).pack(side=tk.LEFT, padx=4)
            tk.Entry(row, textvariable=baud_var, bg=COLORS["surface2"], fg=COLORS["text"],
                     font=("Consolas", 10), relief=tk.FLAT, width=10).pack(side=tk.LEFT, padx=4)
            self.config_vars[f"serial_{i}_port"] = port_var
            self.config_vars[f"serial_{i}_baud"] = baud_var

        # ── Trace32 quick-action buttons ─────────────────────────────────────
        t32_act = tk.LabelFrame(inner, text=" 🔬 Trace32 Actions ",
                                bg=COLORS["bg"], fg=COLORS["accent"],
                                font=("Consolas", 11, "bold"))
        t32_act.pack(fill=tk.X, padx=16, pady=8)

        t32_btn_row = tk.Frame(t32_act, bg=COLORS["bg"])
        t32_btn_row.pack(fill=tk.X, padx=12, pady=6)

        tk.Button(
            t32_btn_row, text="🔍 Auto-detect T32",
            command=self._auto_detect_t32,
            bg=COLORS["surface2"], fg=COLORS["info"],
            font=("Consolas", 10), relief=tk.FLAT, padx=12, cursor="hand2"
        ).pack(side=tk.LEFT, padx=4)

        tk.Button(
            t32_btn_row, text="🚀 Launch T32",
            command=self._launch_t32,
            bg=COLORS["surface2"], fg=COLORS["success"],
            font=("Consolas", 10), relief=tk.FLAT, padx=12, cursor="hand2"
        ).pack(side=tk.LEFT, padx=4)

        tk.Button(
            t32_btn_row, text="🔬 Sanity Check",
            command=self._t32_sanity_check,
            bg=COLORS["surface2"], fg=COLORS["warning"],
            font=("Consolas", 10), relief=tk.FLAT, padx=12, cursor="hand2"
        ).pack(side=tk.LEFT, padx=4)

        self.t32_action_result = tk.Label(
            t32_act, text="", bg=COLORS["bg"], fg=COLORS["text"],
            font=("Consolas", 9), wraplength=600, justify=tk.LEFT)
        self.t32_action_result.pack(fill=tk.X, padx=12, pady=(0, 6))

        tk.Button(inner, text="💾 Apply Configuration",
                  command=self._apply_config,
                  bg=COLORS["accent"], fg="white",
                  font=("Consolas", 12, "bold"), relief=tk.FLAT, padx=20, pady=8,
                  cursor="hand2").pack(pady=16)

    # ── Tab 4: Results ───────────────────────────────────────────────────────

    def _build_results_tab(self):
        frame = tk.Frame(self.notebook, bg=COLORS["bg"])
        self.notebook.add(frame, text="  📊 Results  ")

        hdr = tk.Frame(frame, bg=COLORS["bg"])
        hdr.pack(fill=tk.X, padx=8, pady=8)
        tk.Label(hdr, text="Test Results", bg=COLORS["bg"],
                 fg=COLORS["accent"], font=("Consolas", 14, "bold")).pack(side=tk.LEFT)
        tk.Button(hdr, text="🔄 Refresh", command=self._refresh_results,
                  bg=COLORS["surface2"], fg=COLORS["text"], font=("Consolas", 10),
                  relief=tk.FLAT, padx=12, cursor="hand2").pack(side=tk.RIGHT)
        tk.Button(hdr, text="📁 Open Log Folder", command=self._open_log_folder,
                  bg=COLORS["surface2"], fg=COLORS["text"], font=("Consolas", 10),
                  relief=tk.FLAT, padx=12, cursor="hand2").pack(side=tk.RIGHT, padx=4)

        # Summary badges
        self.summary_frame = tk.Frame(frame, bg=COLORS["bg"])
        self.summary_frame.pack(fill=tk.X, padx=8, pady=4)

        # Results tree
        cols = ("timestamp", "test", "status", "details")
        self.results_tree = ttk.Treeview(frame, columns=cols, show="headings")
        for col, width in [("timestamp", 140), ("test", 250), ("status", 100), ("details", 400)]:
            self.results_tree.heading(col, text=col.title())
            self.results_tree.column(col, width=width)

        style = ttk.Style()
        style.configure("Results.Treeview", background=COLORS["surface2"],
                         fieldbackground=COLORS["surface2"],
                         foreground=COLORS["text"], font=("Consolas", 10), rowheight=26)
        self.results_tree.configure(style="Results.Treeview")
        vsb = ttk.Scrollbar(frame, orient="vertical", command=self.results_tree.yview)
        self.results_tree.configure(yscrollcommand=vsb.set)
        vsb.pack(side=tk.RIGHT, fill=tk.Y)
        self.results_tree.pack(fill=tk.BOTH, expand=True, padx=8, pady=4)

        # Color tags
        self.results_tree.tag_configure("PASSED", foreground=COLORS["success"])
        self.results_tree.tag_configure("FAILED", foreground=COLORS["error"])
        self.results_tree.tag_configure("SKIPPED", foreground=COLORS["warning"])

    def _build_status_bar(self):
        bar = tk.Frame(self.root, bg=COLORS["surface"], height=28)
        bar.pack(fill=tk.X, side=tk.BOTTOM)
        bar.pack_propagate(False)

        self.status_psu = tk.Label(bar, text="PSU: --", bg=COLORS["surface"],
                                    fg=COLORS["text_dim"], font=("Consolas", 9))
        self.status_psu.pack(side=tk.LEFT, padx=12)
        self.status_t32 = tk.Label(bar, text="T32: --", bg=COLORS["surface"],
                                    fg=COLORS["text_dim"], font=("Consolas", 9))
        self.status_t32.pack(side=tk.LEFT, padx=12)
        self.status_serial = tk.Label(bar, text="Serial: --", bg=COLORS["surface"],
                                       fg=COLORS["text_dim"], font=("Consolas", 9))
        self.status_serial.pack(side=tk.LEFT, padx=12)
        self.status_cam = tk.Label(bar, text="Camera: --", bg=COLORS["surface"],
                                    fg=COLORS["text_dim"], font=("Consolas", 9))
        self.status_cam.pack(side=tk.LEFT, padx=12)
        self.status_queue = tk.Label(bar, text="Queue: idle", bg=COLORS["surface"],
                                      fg=COLORS["text_dim"], font=("Consolas", 9))
        self.status_queue.pack(side=tk.RIGHT, padx=12)

    # ════════════════════════════════════════════════════════════════════════
    #  Toolbar Actions
    # ════════════════════════════════════════════════════════════════════════

    def _connect_all(self):
        threading.Thread(target=self.__connect_all_bg, daemon=True).start()

    def __connect_all_bg(self):
        self._log("🔌 Connecting to all hardware...", "INFO")
        cfg = self.config_vars

        # PSU
        self.psu.port = cfg.get("psu_port", tk.StringVar()).get() or "COM3"
        if self.psu.connect():
            self.psu.set_voltage(float(cfg.get("psu_voltage", tk.StringVar(value="12")).get()))
            self.psu.set_current(float(cfg.get("psu_current", tk.StringVar(value="5")).get()))
            self._log("✓ PSU connected", "PASS")
        else:
            self._log("✗ PSU connect failed", "FAIL")

        # Trace32
        self.trace32.host = cfg.get("t32_host", tk.StringVar(value="localhost")).get()
        self.trace32.port = int(cfg.get("t32_port", tk.StringVar(value="20000")).get())
        if self.trace32.connect():
            self._log("✓ Trace32 connected", "PASS")
        else:
            self._log("✗ Trace32 connect failed (check TRACE32 is running)", "WARN")

        # Camera
        idx = int(cfg.get("cam_index", tk.StringVar(value="0")).get())
        self.camera.device_index = idx
        if self.camera.connect():
            self._log("✓ Camera connected", "PASS")
        else:
            self._log("✗ Camera connect failed", "WARN")

        # Serial ports
        for i in range(1, 5):
            port = cfg.get(f"serial_{i}_port", tk.StringVar()).get()
            baud = cfg.get(f"serial_{i}_baud", tk.StringVar(value="115200")).get()
            if port:
                name = f"Serial-{i}"
                try:
                    term = self.serial_mgr.add_terminal(name, port, int(baud), autoconnect=True)
                    if term.is_connected:
                        self._log(f"✓ {name} connected ({port})", "PASS")
                    else:
                        self._log(f"✗ {name} failed ({port})", "WARN")
                except ValueError:
                    pass

        self._log("Connection sequence complete.", "INFO")

    def _start_queue(self):
        if not self.queue_mgr._queue:
            messagebox.showwarning("Empty Queue", "No tests in queue.")
            return
        self.queue_mgr.start()
        self._log("▶ Test queue started.", "RUN")

    def _stop_queue(self):
        self.queue_mgr.stop()
        self._log("⏹ Queue stopped.", "WARN")

    def _show_debug(self):
        self.notebook.select(1)

    def _take_snapshot(self):
        if self.camera.is_connected:
            path = self.camera.snapshot(label="manual")
            if path:
                self._log(f"📸 Snapshot saved: {path}", "INFO")
        else:
            self._log("Camera not connected.", "WARN")

    def _power_cycle(self):
        if self.psu.is_connected:
            self.psu.power_cycle(off_time=2.0)
            self._log("🔄 Power cycle executed (2s off).", "WARN")
        else:
            self._log("PSU not connected.", "WARN")

    # ════════════════════════════════════════════════════════════════════════
    #  Queue Actions
    # ════════════════════════════════════════════════════════════════════════

    def _add_test_dialog(self):
        dlg = tk.Toplevel(self.root)
        dlg.title("Add Test")
        dlg.geometry("560x320")
        dlg.configure(bg=COLORS["bg"])
        dlg.grab_set()

        fields = {}
        rows = [
            ("Test Name", "My Test"),
            ("Script Path", ""),
            ("Parameters (key=val,...)", ""),
            ("Timeout (s)", "300"),
        ]
        for i, (label, default) in enumerate(rows):
            tk.Label(dlg, text=label + ":", bg=COLORS["bg"], fg=COLORS["text"],
                     font=("Consolas", 10)).grid(row=i, column=0, padx=16, pady=6, sticky=tk.W)
            var = tk.StringVar(value=default)
            row_frame = tk.Frame(dlg, bg=COLORS["bg"])
            row_frame.grid(row=i, column=1, padx=4, pady=6, sticky=tk.EW)
            ent = tk.Entry(row_frame, textvariable=var, bg=COLORS["surface2"], fg=COLORS["text"],
                           font=("Consolas", 10), relief=tk.FLAT, width=38,
                           insertbackground=COLORS["accent"])
            ent.pack(side=tk.LEFT)
            if "Path" in label:
                tk.Button(row_frame, text="...", command=lambda v=var: self._browse_script(v),
                          bg=COLORS["surface2"], fg=COLORS["text"], font=("Consolas", 9),
                          relief=tk.FLAT, cursor="hand2").pack(side=tk.LEFT, padx=4)
            fields[label] = var

        tk.Label(dlg, text="Script Type:", bg=COLORS["bg"], fg=COLORS["text"],
                 font=("Consolas", 10)).grid(row=4, column=0, padx=16, pady=6, sticky=tk.W)
        type_var = tk.StringVar(value="python")
        type_frame = tk.Frame(dlg, bg=COLORS["bg"])
        type_frame.grid(row=4, column=1, padx=4, pady=6, sticky=tk.W)
        for val, lbl in [("python", "Python (.py)"), ("cmm", "Trace32 (.cmm)"), ("canoe", "CANoe")]:
            tk.Radiobutton(type_frame, text=lbl, variable=type_var, value=val,
                           bg=COLORS["bg"], fg=COLORS["text"], selectcolor=COLORS["surface2"],
                           font=("Consolas", 10)).pack(side=tk.LEFT, padx=8)

        def _add():
            name = fields["Test Name"].get().strip()
            path = fields["Script Path"].get().strip()
            if not name or not path:
                messagebox.showerror("Error", "Name and Script Path required.", parent=dlg)
                return
            # Parse parameters
            params = {}
            for part in fields["Parameters (key=val,...)"].get().split(","):
                if "=" in part:
                    k, v = part.split("=", 1)
                    params[k.strip()] = v.strip()
            type_map = {"python": TestType.PYTHON, "cmm": TestType.CMM, "canoe": TestType.CANOE}
            item = TestItem(
                name=name, script_path=path,
                test_type=type_map[type_var.get()],
                parameters=params,
                timeout=int(fields["Timeout (s)"].get() or 300)
            )
            self.queue_mgr.add_test(item)
            self._refresh_queue_display()
            dlg.destroy()

        tk.Button(dlg, text="Add to Queue", command=_add,
                  bg=COLORS["accent"], fg="white", font=("Consolas", 11, "bold"),
                  relief=tk.FLAT, padx=20, pady=8, cursor="hand2").grid(
            row=5, column=0, columnspan=2, pady=16)

    def _browse_script(self, var: tk.StringVar):
        path = filedialog.askopenfilename(
            filetypes=[("All supported", "*.py *.cmm *.cfg"),
                       ("Python", "*.py"), ("CMM", "*.cmm"), ("All", "*.*")])
        if path:
            var.set(path)

    def _clear_queue(self):
        if messagebox.askyesno("Clear Queue", "Remove all tests from queue?"):
            self.queue_mgr.clear_queue()
            self._refresh_queue_display()

    def _remove_selected(self):
        sel = self.queue_tree.selection()
        if sel:
            idx = self.queue_tree.index(sel[0])
            self.queue_mgr.remove_test(idx)
            self._refresh_queue_display()

    def _move_up(self):
        sel = self.queue_tree.selection()
        if sel:
            idx = self.queue_tree.index(sel[0])
            if idx > 0:
                self.queue_mgr.move_test(idx, idx - 1)
                self._refresh_queue_display()

    def _move_down(self):
        sel = self.queue_tree.selection()
        if sel:
            idx = self.queue_tree.index(sel[0])
            self.queue_mgr.move_test(idx, idx + 1)
            self._refresh_queue_display()

    def _skip_selected(self):
        sel = self.queue_tree.selection()
        if sel:
            idx = self.queue_tree.index(sel[0])
            items = self.queue_mgr.get_queue()
            if 0 <= idx < len(items):
                items[idx].status = TestStatus.SKIPPED
                self._refresh_queue_display()

    def _refresh_queue_display(self):
        self.root.after(0, self.__refresh_queue_display_main)

    def __refresh_queue_display_main(self):
        for item in self.queue_tree.get_children():
            self.queue_tree.delete(item)
        for test in self.queue_mgr.get_queue():
            duration_str = f"{test.duration}s" if test.duration else "--"
            self.queue_tree.insert(
                "", tk.END, text=test.name,
                values=(test.test_type.value, test.status.name, duration_str),
                tags=(test.status.name,)
            )
        # Apply status colors
        for status, color in STATUS_COLORS.items():
            self.queue_tree.tag_configure(status, foreground=color)

    # ════════════════════════════════════════════════════════════════════════
    #  Debug Actions
    # ════════════════════════════════════════════════════════════════════════

    def _test_connections(self):
        threading.Thread(target=self.__test_connections_bg, daemon=True).start()

    def __test_connections_bg(self):
        results = self.debug.test_all_connections()
        self.root.after(0, lambda: self.__update_hw_status(results))

    def __update_hw_status(self, results: dict):
        for key, lbl in self.hw_status_labels.items():
            r = results.get(key, {})
            status = r.get("status", "UNKNOWN") if isinstance(r, dict) else str(r)
            color = COLORS["success"] if status in ("OK", "CONNECTED") else \
                    COLORS["warning"] if status == "NOT_CONFIGURED" else COLORS["error"]
            extra = ""
            if isinstance(r, dict) and "voltage" in r:
                extra = f" {r['voltage']:.2f}V / {r.get('current', 0):.3f}A"
            lbl.config(text=f"● {status}{extra}", fg=color)

    def _send_debug_command(self):
        target = self.cmd_target.get()
        cmd = self.cmd_entry.get().strip()
        if not cmd:
            return
        self.cmd_entry.delete(0, tk.END)

        def _run():
            if target == "PSU":
                result = self.debug.send_psu_command(cmd)
            elif target == "Trace32":
                result = self.debug.send_trace32_command(cmd)
            elif target.startswith("Serial-"):
                result = self.debug.send_serial_command(target, cmd)
            else:
                result = "Unknown target"
            self.root.after(0, lambda: self._debug_log(f"[{target}] {cmd!r} → {result}"))

        threading.Thread(target=_run, daemon=True).start()

    def _browse_validate(self):
        path = filedialog.askopenfilename(
            filetypes=[("Scripts", "*.py *.cmm"), ("All", "*.*")])
        if path:
            self.validate_path.delete(0, tk.END)
            self.validate_path.insert(0, path)

    def _validate_script(self):
        path = self.validate_path.get().strip()
        if not path:
            return
        if path.endswith(".py"):
            result = self.debug.validate_python_script(path)
        elif path.endswith(".cmm"):
            result = self.debug.validate_cmm_script(path)
        else:
            result = {"error": "Unsupported file type"}
        self._debug_log(f"Validation: {path}\n{result}")

    def _dry_run_script(self):
        path = self.validate_path.get().strip()
        if not path:
            return
        if path.endswith(".py"):
            result = self.debug.dry_run_python(path)
            self._debug_log(f"Dry Run: {path}\n{result}")
        else:
            self._debug_log("Dry run only supported for Python scripts.")

    def _debug_log(self, msg: str):
        self.debug_output.insert(tk.END, msg + "\n")
        self.debug_output.see(tk.END)

    # ════════════════════════════════════════════════════════════════════════
    #  Config Actions
    # ════════════════════════════════════════════════════════════════════════

    def _apply_config(self):
        cfg = self.config_vars
        self.psu.port = cfg["psu_port"].get()
        self.psu.baud = int(cfg["psu_baud"].get())
        self.trace32.host = cfg["t32_host"].get()
        self.trace32.port = int(cfg["t32_port"].get())
        self.trace32.t32_exe = cfg["t32_exe"].get() or None
        self.trace32.config_file = cfg["t32_config"].get() or None
        self.canoe.config_path = cfg["canoe_config"].get() or None
        self.camera.device_index = int(cfg["cam_index"].get())
        messagebox.showinfo("Config Applied", "Hardware configuration updated.\nReconnect devices to apply.")

    def _auto_detect_t32(self):
        """Scan default drives for a Trace32 installation and populate fields."""
        detected = self.trace32.detect_installation()
        if not detected:
            self.t32_action_result.config(
                text="⚠  No T32 installation found on C:\\T32 or D:\\T32.",
                fg=COLORS["warning"])
            return
        if "t32_exe" in detected:
            self.config_vars["t32_exe"].set(detected["t32_exe"])
            self.trace32.t32_exe = detected["t32_exe"]
        if "config_file" in detected:
            self.config_vars["t32_config"].set(detected["config_file"])
            self.trace32.config_file = detected["config_file"]
        self.t32_action_result.config(
            text=(
                f"✓  Detected: {detected.get('install_dir', '')}\n"
                f"   Exe: {detected.get('t32_exe', 'not found')}\n"
                f"   Config: {detected.get('config_file', 'not found')}"
            ),
            fg=COLORS["success"])

    def _launch_t32(self):
        """Apply current config then launch the T32 executable in a background thread."""
        self._apply_config()
        if not self.trace32.t32_exe:
            messagebox.showwarning(
                "T32 Executable Missing",
                "T32 executable path is not set.\n"
                "Use 'Auto-detect T32' or enter the path manually.")
            return
        self.t32_action_result.config(
            text="⏳ Launching T32, waiting for RCL connection…", fg=COLORS["info"])

        def _bg():
            ok = self.trace32.launch(wait_seconds=8.0)
            msg = "✓ T32 launched and connected." if ok else \
                  "✗ T32 launch failed or RCL connection timed out."
            color = COLORS["success"] if ok else COLORS["error"]
            self.root.after(0, lambda: self.t32_action_result.config(text=msg, fg=color))
            self.root.after(0, lambda: self._log(msg, "PASS" if ok else "FAIL"))

        threading.Thread(target=_bg, daemon=True).start()

    def _t32_sanity_check(self):
        """Run the hello_world.cmm sanity check against the connected T32."""
        if not self.trace32.is_connected:
            messagebox.showwarning(
                "Not Connected",
                "Trace32 is not connected.\n"
                "Use 'Connect All' or 'Launch T32' first.")
            return
        import pathlib
        script = pathlib.Path(__file__).parent.parent / "scripts" / "hello_world.cmm"
        self.t32_action_result.config(
            text="⏳ Running sanity check…", fg=COLORS["info"])

        def _bg():
            ok = self.trace32.run_hello_world(
                script_path=str(script) if script.is_file() else None
            )
            msg = "✓ Sanity check PASSED." if ok else "✗ Sanity check FAILED – check T32 log."
            color = COLORS["success"] if ok else COLORS["error"]
            self.root.after(0, lambda: self.t32_action_result.config(text=msg, fg=color))
            self.root.after(0, lambda: self._log(msg, "PASS" if ok else "FAIL"))

        threading.Thread(target=_bg, daemon=True).start()

    # ════════════════════════════════════════════════════════════════════════
    #  Results Actions
    # ════════════════════════════════════════════════════════════════════════

    def _refresh_results(self):
        for item in self.results_tree.get_children():
            self.results_tree.delete(item)
        rows = self.debug.get_test_results_summary()
        counts = {"PASSED": 0, "FAILED": 0, "SKIPPED": 0}
        for row in rows:
            status = row["status"]
            counts[status] = counts.get(status, 0) + 1
            self.results_tree.insert("", tk.END, values=(
                row["timestamp"], row["test"], row["status"], row["details"]
            ), tags=(status,))

        # Update summary
        for w in self.summary_frame.winfo_children():
            w.destroy()
        for status, color in [("PASSED", COLORS["success"]),
                               ("FAILED", COLORS["error"]),
                               ("SKIPPED", COLORS["warning"])]:
            tk.Label(self.summary_frame,
                     text=f"  {status}: {counts.get(status, 0)}  ",
                     bg=color, fg="black", font=("Consolas", 11, "bold"),
                     padx=8, pady=4).pack(side=tk.LEFT, padx=4)

    def _open_log_folder(self):
        import subprocess
        import platform
        path = str(self.tester_logger.session_path)
        if platform.system() == "Windows":
            subprocess.Popen(["explorer", path])
        elif platform.system() == "Darwin":
            subprocess.Popen(["open", path])
        else:
            subprocess.Popen(["xdg-open", path])

    # ════════════════════════════════════════════════════════════════════════
    #  Log Tail & Status Polling
    # ════════════════════════════════════════════════════════════════════════

    def _log(self, msg: str, tag: str = "INFO"):
        self.logger.info(msg)
        self.root.after(0, lambda: self._append_log(msg, tag))

    def _append_log(self, msg: str, tag: str = "INFO"):
        self.log_output.configure(state=tk.NORMAL)
        ts = time.strftime("%H:%M:%S")
        self.log_output.insert(tk.END, f"[{ts}] {msg}\n", tag)
        self.log_output.see(tk.END)
        self.log_output.configure(state=tk.DISABLED)

    def _clear_log(self):
        self.log_output.configure(state=tk.NORMAL)
        self.log_output.delete("1.0", tk.END)
        self.log_output.configure(state=tk.DISABLED)

    def _start_log_tail(self):
        def _tail():
            last_size = 0
            log_path = self.tester_logger.session_path / "main.log"
            while True:
                try:
                    if log_path.exists():
                        size = log_path.stat().st_size
                        if size > last_size:
                            with open(log_path) as f:
                                f.seek(last_size)
                                new_lines = f.read()
                            last_size = size
                            for line in new_lines.splitlines():
                                tag = "PASS" if "PASSED" in line else \
                                      "FAIL" if "FAILED" in line or "ERROR" in line else \
                                      "WARN" if "WARNING" in line else \
                                      "RUN" if "Running" in line else "INFO"
                                self.root.after(0, lambda ln=line, t=tag: self._append_log(ln, t))
                except Exception:
                    pass
                time.sleep(0.5)
        threading.Thread(target=_tail, daemon=True).start()

    def _poll_status(self):
        """Update status bar every 2 seconds."""
        try:
            # PSU
            if self.psu.is_connected:
                v = self.psu.measure_voltage()
                i = self.psu.measure_current()
                self.status_psu.config(
                    text=f"PSU: {v:.2f}V / {i:.3f}A" if v and i else "PSU: ●",
                    fg=COLORS["success"]
                )
            else:
                self.status_psu.config(text="PSU: ✕", fg=COLORS["error"])

            # Trace32
            self.status_t32.config(
                text="T32: ●" if self.trace32.is_connected else "T32: ✕",
                fg=COLORS["success"] if self.trace32.is_connected else COLORS["text_dim"]
            )

            # Serial
            connected_serials = sum(1 for t in self.serial_mgr.terminals.values() if t.is_connected)
            total = len(self.serial_mgr.terminals)
            self.status_serial.config(
                text=f"Serial: {connected_serials}/{total}",
                fg=COLORS["success"] if connected_serials > 0 else COLORS["text_dim"]
            )

            # Camera
            self.status_cam.config(
                text="Cam: ●" if self.camera.is_connected else "Cam: ✕",
                fg=COLORS["success"] if self.camera.is_connected else COLORS["text_dim"]
            )

            # Queue
            items = self.queue_mgr.get_queue()
            pending = sum(1 for i in items if i.status.name == "PENDING")
            running = sum(1 for i in items if i.status.name == "RUNNING")
            if running:
                self.status_queue.config(text=f"Queue: RUNNING ({pending} pending)",
                                          fg=COLORS["info"])
            elif pending:
                self.status_queue.config(text=f"Queue: {pending} pending",
                                          fg=COLORS["warning"])
            else:
                self.status_queue.config(text="Queue: idle", fg=COLORS["text_dim"])
        except Exception:
            pass

        self.root.after(2000, self._poll_status)

    # ════════════════════════════════════════════════════════════════════════
    #  Lifecycle
    # ════════════════════════════════════════════════════════════════════════

    def _on_close(self):
        self.queue_mgr.stop()
        self.serial_mgr.disconnect_all()
        if self.psu.is_connected:
            self.psu.output_off()
            self.psu.disconnect()
        self.trace32.disconnect()
        if self.camera.is_connected:
            self.camera.disconnect()
        self.root.destroy()

    def run(self):
        self.root.mainloop()
