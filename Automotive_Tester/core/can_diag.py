"""
CAN / Diagnostic Tester panel.

Provides a tk.Frame-based panel that embeds the Vector CAN/CAN-FD
Test-Automation & Sequencer (originally Automotive_CAN_Tester /
Automotive_Diag_Tester.py) so it can be hosted as a tab inside the
consolidated Automotive Tester application.

Bug fixes vs. the standalone original:
  - _create_editor_popup: bank rebuild now updates only the edited
    entry instead of reconstructing bank_data from the (possibly
    filtered) treeview, which would silently drop hidden rows.
  - connect_hardware: data_bitrate keyword is omitted entirely when
    CAN-FD is disabled, avoiding a None-argument error in python-can.
  - Optional import guard around ``can`` / ``cantools`` so the panel
    can be imported even when those packages are absent (hardware
    features are disabled gracefully at runtime).
"""
from __future__ import annotations

import datetime
import json
import os
import re
import threading
import time
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext, ttk
from typing import Any, Dict, List, Optional

try:
    import can
    import cantools
    _CAN_AVAILABLE = True
except ImportError:  # pragma: no cover
    _CAN_AVAILABLE = False

# Config file lives next to the Automotive_Tester project root (one level up
# from this file's parent "core/" directory).
_MODULE_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.dirname(_MODULE_DIR)
_CONFIG_FILE = os.path.join(_PROJECT_ROOT, "can_diag_config.json")


class CanDiagPanel(tk.Frame):
    """Vector CAN/CAN-FD diagnostic automation panel.

    Drop this frame into any parent widget (e.g. a ttk.Notebook tab).
    All Vector hardware interaction, command bank management, script
    sequencing and traffic logging are fully self-contained.
    """

    def __init__(self, parent: tk.Widget) -> None:
        super().__init__(parent)

        self.buses: List[Any] = []
        self.vector_channels: List[Any] = []
        self.is_connected: bool = False
        self.is_script_running: bool = False
        self.dbs: Dict[int, Any] = {0: None, 1: None}

        self.log_filename = (
            f"can_log_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
        )

        self.config: Dict[str, Any] = {
            "bitrate": "500000",
            "data_bitrate": "2000000",
            "is_fd": False,
            "dbc_paths": {"0": "", "1": ""},
            "fc_enabled": False,
            "fc_rx_id": "7E8",
            "fc_tx_id": "7E0",
            "bank_data": [],
            "script_data": [],
        }
        self.load_config()
        self._setup_gui()
        self._apply_config_to_gui()

    # ------------------------------------------------------------------
    # Helpers
    # ------------------------------------------------------------------

    def _root(self) -> tk.Misc:
        """Return the top-level Tk window (used as parent for dialogs)."""
        return self.winfo_toplevel()

    # ------------------------------------------------------------------
    # Config persistence
    # ------------------------------------------------------------------

    def load_config(self) -> None:
        if os.path.exists(_CONFIG_FILE):
            try:
                with open(_CONFIG_FILE, "r", encoding="utf-8") as fh:
                    self.config.update(json.load(fh))
            except Exception as exc:  # pragma: no cover
                print(f"[CanDiag] Error loading config: {exc}")

    def save_config(self) -> None:
        try:
            with open(_CONFIG_FILE, "w", encoding="utf-8") as fh:
                json.dump(self.config, fh, indent=4)
        except OSError as exc:  # pragma: no cover
            print(f"[CanDiag] Error saving config: {exc}")

    def force_save_config(self) -> None:
        self.config["bitrate"] = self.bitrate_entry.get()
        self.config["data_bitrate"] = self.data_bitrate_entry.get()
        self.config["is_fd"] = self.is_fd_var.get()
        self.config["fc_enabled"] = self.is_fc_enabled.get()
        self.config["fc_rx_id"] = self.fc_rx_entry.get()
        self.config["fc_tx_id"] = self.fc_tx_entry.get()

        self.config["script_data"] = []
        for child in self.script_tree.get_children():
            name, arb_id, data = self.script_tree.item(child, "values")
            self.config["script_data"].append(
                {"name": name, "id": arb_id, "data": data}
            )

        self.save_config()
        self.write_log("Configuration and Sequences saved successfully.")

    # ------------------------------------------------------------------
    # GUI construction
    # ------------------------------------------------------------------

    def _setup_gui(self) -> None:
        # --- Top Frame: Global Configs ---
        top_frame = tk.Frame(self)
        top_frame.pack(padx=10, pady=5, fill="x")

        # 1. Hardware & ISO-TP
        hw_frame = ttk.LabelFrame(top_frame, text="Hardware & ISO-TP Config")
        hw_frame.pack(side="left", fill="both", expand=True, padx=(0, 5))

        ttk.Label(hw_frame, text="Bitrate:").grid(
            row=0, column=0, padx=2, pady=5, sticky="e"
        )
        self.bitrate_entry = ttk.Entry(hw_frame, width=8)
        self.bitrate_entry.grid(row=0, column=1, padx=2, pady=5)

        ttk.Label(hw_frame, text="FD Bitrate:").grid(
            row=0, column=2, padx=2, pady=5, sticky="e"
        )
        self.data_bitrate_entry = ttk.Entry(hw_frame, width=8)
        self.data_bitrate_entry.grid(row=0, column=3, padx=2, pady=5)

        self.is_fd_var = tk.BooleanVar()
        ttk.Checkbutton(hw_frame, text="CAN-FD", variable=self.is_fd_var).grid(
            row=0, column=4, padx=5, pady=5
        )

        self.is_fc_enabled = tk.BooleanVar()
        ttk.Checkbutton(
            hw_frame, text="Auto Flow-Control", variable=self.is_fc_enabled
        ).grid(row=1, column=0, columnspan=2, sticky="w", padx=5)
        ttk.Label(hw_frame, text="Watch RX:").grid(row=1, column=2, padx=2, sticky="e")
        self.fc_rx_entry = ttk.Entry(hw_frame, width=6)
        self.fc_rx_entry.grid(row=1, column=3, padx=2)
        ttk.Label(hw_frame, text="Reply TX:").grid(row=1, column=4, padx=2, sticky="e")
        self.fc_tx_entry = ttk.Entry(hw_frame, width=6)
        self.fc_tx_entry.grid(row=1, column=5, padx=2)

        self.btn_connect = ttk.Button(
            hw_frame, text="Connect Hardware", command=self.connect_hardware
        )
        self.btn_connect.grid(row=0, column=6, rowspan=2, padx=15, pady=5, ipady=10)
        self.btn_disconnect = ttk.Button(
            hw_frame,
            text="Disconnect",
            command=self.disconnect_hardware,
            state="disabled",
        )
        self.btn_disconnect.grid(row=0, column=7, rowspan=2, padx=5, pady=5, ipady=10)

        # 2. Databases & Importer
        db_frame = ttk.LabelFrame(top_frame, text="Databases & Log Importer")
        db_frame.pack(side="right", fill="both", expand=True, padx=(5, 0))

        ttk.Label(db_frame, text="Map DBC to:").grid(
            row=0, column=0, padx=5, pady=5, sticky="e"
        )
        self.dbc_map_cb = ttk.Combobox(
            db_frame,
            values=["Channel Index 0", "Channel Index 1"],
            state="readonly",
            width=15,
        )
        self.dbc_map_cb.current(0)
        self.dbc_map_cb.grid(row=0, column=1, padx=5, pady=5)
        ttk.Button(db_frame, text="Load .dbc", command=self.load_dbc).grid(
            row=0, column=2, padx=5, pady=5
        )

        self.dbc_label_0 = ttk.Label(db_frame, text="Ch 0: None", foreground="gray")
        self.dbc_label_0.grid(row=0, column=3, padx=5, pady=2, sticky="w")
        self.dbc_label_1 = ttk.Label(db_frame, text="Ch 1: None", foreground="gray")
        self.dbc_label_1.grid(row=1, column=3, padx=5, pady=2, sticky="w")

        ttk.Button(
            db_frame,
            text="Import Diag Log (.asc/.txt)",
            command=self.import_log,
        ).grid(row=1, column=0, columnspan=3, padx=5, pady=5, sticky="ew")

        # --- Middle Frame: Dual Pane (Builder vs Script) ---
        paned_window = ttk.PanedWindow(self, orient=tk.HORIZONTAL)
        paned_window.pack(padx=10, pady=5, fill="both", expand=True)

        # === LEFT PANE: COMMAND BUILDER & BANK ===
        left_pane = tk.Frame(paned_window)
        paned_window.add(left_pane, weight=1)

        # Composer
        tx_frame = ttk.LabelFrame(left_pane, text="1. Manual Composer")
        tx_frame.pack(fill="x", padx=(0, 5), pady=(0, 5))

        ttk.Label(tx_frame, text="Ch:").grid(row=0, column=0, padx=2, sticky="e")
        self.tx_channel_cb = ttk.Combobox(tx_frame, state="readonly", width=10)
        self.tx_channel_cb.grid(row=0, column=1, padx=2)
        self.tx_channel_cb.bind("<<ComboboxSelected>>", self.on_tx_channel_change)

        ttk.Label(tx_frame, text="DBC Msg:").grid(row=0, column=2, padx=2, sticky="e")
        self.dbc_msg_cb = ttk.Combobox(tx_frame, state="readonly", width=20)
        self.dbc_msg_cb.grid(row=0, column=3, padx=2)
        self.dbc_msg_cb.bind("<<ComboboxSelected>>", self.on_dbc_msg_select)

        ttk.Label(tx_frame, text="ID (Hex):").grid(
            row=1, column=0, padx=2, sticky="e", pady=5
        )
        self.arb_id_entry = ttk.Entry(tx_frame, width=8)
        self.arb_id_entry.grid(row=1, column=1, padx=2, sticky="w", pady=5)

        ttk.Label(tx_frame, text="Payload (Hex):").grid(
            row=1, column=2, padx=2, sticky="e", pady=5
        )
        self.data_entry = ttk.Entry(tx_frame, width=25)
        self.data_entry.grid(row=1, column=3, padx=2, sticky="w", pady=5)

        ttk.Button(
            tx_frame, text="Send Now", command=lambda: self.send_command()
        ).grid(row=2, column=1, pady=5)
        ttk.Button(
            tx_frame, text="Save to Bank \u2193", command=self.add_to_bank
        ).grid(row=2, column=3, sticky="w", pady=5)

        # Command Bank
        bank_frame = ttk.LabelFrame(
            left_pane, text="2. Command Bank (Available Messages)"
        )
        bank_frame.pack(fill="both", expand=True, padx=(0, 5))

        search_frame = tk.Frame(bank_frame)
        search_frame.pack(fill="x", padx=5, pady=5)
        ttk.Label(search_frame, text="\U0001F50D Search:").pack(side="left")
        self.search_var = tk.StringVar()
        self.search_var.trace("w", self.filter_bank)
        ttk.Entry(search_frame, textvariable=self.search_var, width=30).pack(
            side="left", padx=5
        )

        self.bank_tree = ttk.Treeview(
            bank_frame, columns=("Name", "ID", "Data"), show="headings", height=8
        )
        self.bank_tree.heading("Name", text="Name")
        self.bank_tree.heading("ID", text="ID")
        self.bank_tree.heading("Data", text="Data")
        self.bank_tree.column("Name", width=120)
        self.bank_tree.column("ID", width=60)
        self.bank_tree.column("Data", width=150)
        self.bank_tree.pack(side="left", fill="both", expand=True, padx=5, pady=5)
        self.bank_tree.bind("<Double-1>", self.edit_bank_item)

        b_btn_frame = tk.Frame(bank_frame)
        b_btn_frame.pack(side="right", fill="y", padx=5, pady=5)
        ttk.Button(
            b_btn_frame, text=">> Add to Script >>", command=self.move_to_script
        ).pack(pady=2, ipady=5)
        ttk.Button(b_btn_frame, text="Edit", command=self.edit_bank_item).pack(pady=2)
        ttk.Button(b_btn_frame, text="Delete", command=self.delete_from_bank).pack(
            pady=2
        )
        ttk.Button(b_btn_frame, text="Clear Bank", command=self.clear_bank).pack(
            side="bottom", pady=2
        )

        # === RIGHT PANE: TEST SCRIPT QUEUE ===
        right_pane = tk.Frame(paned_window)
        paned_window.add(right_pane, weight=1)

        script_frame = ttk.LabelFrame(
            right_pane, text="3. Test Script Queue (Execution Sequence)"
        )
        script_frame.pack(fill="both", expand=True, padx=(5, 0))

        self.script_tree = ttk.Treeview(
            script_frame,
            columns=("Name", "ID", "Data"),
            show="headings",
            height=12,
        )
        self.script_tree.heading("Name", text="Sequence Step")
        self.script_tree.heading("ID", text="ID")
        self.script_tree.heading("Data", text="Data")
        self.script_tree.column("Name", width=150)
        self.script_tree.column("ID", width=60)
        self.script_tree.column("Data", width=150)
        self.script_tree.pack(side="left", fill="both", expand=True, padx=5, pady=5)
        self.script_tree.bind("<Double-1>", self.edit_script_item)

        s_btn_frame = tk.Frame(script_frame)
        s_btn_frame.pack(side="right", fill="y", padx=5, pady=5)

        ttk.Label(s_btn_frame, text="Delay (ms):").pack()
        self.delay_entry = ttk.Entry(s_btn_frame, width=8)
        self.delay_entry.insert(0, "500")
        self.delay_entry.pack(pady=(0, 10))

        self.btn_run_script = ttk.Button(
            s_btn_frame,
            text="\u25B6 Run Script",
            command=self.start_script,
            state="disabled",
        )
        self.btn_run_script.pack(pady=2, ipady=5)

        self.btn_stop_script = ttk.Button(
            s_btn_frame,
            text="\u23F9 Stop",
            command=self.stop_script,
            state="disabled",
        )
        self.btn_stop_script.pack(pady=2)

        ttk.Separator(s_btn_frame, orient="horizontal").pack(fill="x", pady=10)

        ttk.Button(
            s_btn_frame, text="Move Up", command=lambda: self.move_item(-1)
        ).pack(pady=2)
        ttk.Button(
            s_btn_frame, text="Move Down", command=lambda: self.move_item(1)
        ).pack(pady=2)
        ttk.Button(
            s_btn_frame, text="Remove Step", command=self.remove_from_script
        ).pack(pady=2)
        ttk.Button(s_btn_frame, text="Clear Script", command=self.clear_script).pack(
            pady=2
        )
        ttk.Button(
            s_btn_frame, text="\U0001F4BE Save Layout", command=self.force_save_config
        ).pack(side="bottom", pady=2)

        # --- Bottom Frame: Logging ---
        log_frame = ttk.LabelFrame(self, text="Traffic Log (Parsed UDS & ASCII)")
        log_frame.pack(padx=10, pady=5, fill="both", expand=True)

        self.log_text = scrolledtext.ScrolledText(
            log_frame,
            state="disabled",
            bg="#1e1e1e",
            fg="#00ff00",
            font=("Consolas", 10),
        )
        self.log_text.pack(padx=5, pady=5, fill="both", expand=True)

    def _apply_config_to_gui(self) -> None:
        self.bitrate_entry.insert(0, self.config.get("bitrate", "500000"))
        self.data_bitrate_entry.insert(0, self.config.get("data_bitrate", "2000000"))
        self.is_fd_var.set(self.config.get("is_fd", False))
        self.is_fc_enabled.set(self.config.get("fc_enabled", False))
        self.fc_rx_entry.insert(0, self.config.get("fc_rx_id", "7E8"))
        self.fc_tx_entry.insert(0, self.config.get("fc_tx_id", "7E0"))

        for ch_index in ["0", "1"]:
            path = self.config["dbc_paths"].get(ch_index, "")
            if path and os.path.exists(path):
                self.process_dbc(path, int(ch_index))

        self.refresh_bank_tree()
        for item in self.config.get("script_data", []):
            self.script_tree.insert(
                "", "end", values=(item["name"], item["id"], item["data"])
            )

    # ------------------------------------------------------------------
    # Bank & Script data management
    # ------------------------------------------------------------------

    def refresh_bank_tree(self, filter_text: str = "") -> None:
        self.bank_tree.delete(*self.bank_tree.get_children())
        filter_text = filter_text.lower()
        for item in self.config.get("bank_data", []):
            if (
                filter_text in item["name"].lower()
                or filter_text in item["id"].lower()
                or filter_text in item["data"].lower()
            ):
                self.bank_tree.insert(
                    "", "end", values=(item["name"], item["id"], item["data"])
                )

    def filter_bank(self, *_args: Any) -> None:
        self.refresh_bank_tree(self.search_var.get())

    def add_to_bank(self) -> None:
        arb_id = self.arb_id_entry.get().strip()
        data = self.data_entry.get().strip()
        if not arb_id or not data:
            return
        name = (
            self.dbc_msg_cb.get()
            if self.dbc_msg_cb.get() and self.dbc_msg_cb.get() != "No DBC mapped"
            else f"Custom {arb_id}"
        )
        self.config["bank_data"].append({"name": name, "id": arb_id, "data": data})
        self.refresh_bank_tree(self.search_var.get())

    def move_to_script(self) -> None:
        """Copy selected items from Bank into the Script queue."""
        for item_id in self.bank_tree.selection():
            name, arb_id, data = self.bank_tree.item(item_id, "values")
            self.script_tree.insert("", "end", values=(name, arb_id, data))

    def delete_from_bank(self) -> None:
        selected = self.bank_tree.selection()
        if not selected:
            return
        items_to_remove = {self.bank_tree.item(sel, "values") for sel in selected}
        self.config["bank_data"] = [
            item
            for item in self.config["bank_data"]
            if (item["name"], item["id"], item["data"]) not in items_to_remove
        ]
        self.refresh_bank_tree(self.search_var.get())

    def clear_bank(self) -> None:
        if messagebox.askyesno(
            "Confirm",
            "Are you sure you want to clear the entire Command Bank?",
            parent=self._root(),
        ):
            self.config["bank_data"] = []
            self.refresh_bank_tree()

    def remove_from_script(self) -> None:
        for item in self.script_tree.selection():
            self.script_tree.delete(item)

    def clear_script(self) -> None:
        for item in self.script_tree.get_children():
            self.script_tree.delete(item)

    def move_item(self, direction: int) -> None:
        """Move an item up (-1) or down (+1) in the script tree."""
        selected = self.script_tree.selection()
        if not selected:
            return
        for item in selected:
            idx = self.script_tree.index(item)
            self.script_tree.move(item, self.script_tree.parent(item), idx + direction)

    def edit_bank_item(self, event: Optional[tk.Event] = None) -> None:
        self._create_editor_popup(self.bank_tree, is_bank=True)

    def edit_script_item(self, event: Optional[tk.Event] = None) -> None:
        self._create_editor_popup(self.script_tree, is_bank=False)

    def _create_editor_popup(
        self, treeview: ttk.Treeview, is_bank: bool
    ) -> None:
        selected = treeview.selection()
        if not selected:
            return

        item_id = selected[0]
        current_name, current_arb_id, current_data = treeview.item(item_id, "values")

        edit_win = tk.Toplevel(self._root())
        edit_win.title("Edit Command")
        edit_win.geometry("350x220")
        edit_win.transient(self._root())
        edit_win.grab_set()

        ttk.Label(edit_win, text="Command Name:").pack(pady=(10, 2))
        name_entry = ttk.Entry(edit_win, width=35)
        name_entry.insert(0, current_name)
        name_entry.pack(pady=2)

        ttk.Label(edit_win, text="Arbitration ID (Hex):").pack(pady=2)
        id_entry = ttk.Entry(edit_win, width=15)
        id_entry.insert(0, current_arb_id)
        id_entry.pack(pady=2)

        ttk.Label(edit_win, text="Data Payload (Hex):").pack(pady=2)
        data_entry_w = ttk.Entry(edit_win, width=35)
        data_entry_w.insert(0, current_data)
        data_entry_w.pack(pady=2)

        def save_edits() -> None:
            new_name = name_entry.get().strip()
            new_id = id_entry.get().strip().replace("x", "").replace("X", "")
            new_data = data_entry_w.get().strip()

            if not new_id or not new_data:
                return

            treeview.item(item_id, values=(new_name, new_id, new_data))

            # Bug fix: update only the matching entry in bank_data instead of
            # rebuilding the list from the treeview (which only contains visible
            # / unfiltered rows and would silently drop hidden items).
            if is_bank:
                for entry in self.config["bank_data"]:
                    if (
                        entry["name"] == current_name
                        and entry["id"] == current_arb_id
                        and entry["data"] == current_data
                    ):
                        entry["name"] = new_name
                        entry["id"] = new_id
                        entry["data"] = new_data
                        break

            edit_win.destroy()

        ttk.Button(edit_win, text="Save Changes", command=save_edits).pack(pady=15)

    # ------------------------------------------------------------------
    # Script execution
    # ------------------------------------------------------------------

    def start_script(self) -> None:
        if not self.is_connected or self.is_script_running:
            return
        if not self.script_tree.get_children():
            return

        try:
            delay_ms = int(self.delay_entry.get())
        except ValueError:
            messagebox.showerror(
                "Error",
                "Delay must be an integer (milliseconds).",
                parent=self._root(),
            )
            return

        self.is_script_running = True
        self.btn_run_script.config(state="disabled")
        self.btn_stop_script.config(state="normal")
        self.write_log(">>> TEST SCRIPT STARTED <<<")

        threading.Thread(
            target=self._run_script_thread, args=(delay_ms,), daemon=True
        ).start()

    def _run_script_thread(self, delay_ms: int) -> None:
        delay_sec = delay_ms / 1000.0

        for child in self.script_tree.get_children():
            if not self.is_script_running:
                break

            self.after(0, lambda c=child: self.script_tree.selection_set(c))
            self.after(0, lambda c=child: self.script_tree.see(c))

            name, arb_id, data = self.script_tree.item(child, "values")
            clean_id = arb_id.replace("x", "").replace("X", "")

            self.send_command(clean_id, data)
            time.sleep(delay_sec)

        self.after(0, self._finalize_script)

    def _finalize_script(self) -> None:
        self.is_script_running = False
        self.write_log(">>> TEST SCRIPT FINISHED <<<")
        self.btn_run_script.config(state="normal")
        self.btn_stop_script.config(state="disabled")

    def stop_script(self) -> None:
        self.is_script_running = False

    # ------------------------------------------------------------------
    # Log import
    # ------------------------------------------------------------------

    def import_log(self) -> None:
        filepath = filedialog.askopenfilename(
            filetypes=[("Vector Logs", "*.asc *.txt"), ("All Files", "*.*")]
        )
        if not filepath:
            return

        try:
            added = 0
            seen: set = set()
            with open(filepath, "r", encoding="utf-8", errors="replace") as fh:
                for line in fh:
                    if " Tx " in line and "[" in line and "]" in line:
                        parts = line.split()
                        try:
                            tx_idx = parts.index("Tx")
                            can_id = parts[tx_idx + 1].replace("x", "")
                            start = line.find("[") + 1
                            end = line.find("]")
                            payload = line[start:end].strip()

                            key = (can_id, payload)
                            if key not in seen and payload:
                                seen.add(key)
                                sid = payload.split()[0].upper()
                                name = "UDS Command"
                                if sid == "10":
                                    name = "Session Control (10)"
                                elif sid == "11":
                                    name = "ECU Reset (11)"
                                elif sid == "14":
                                    name = "Clear DTCs (14)"
                                elif sid == "19":
                                    name = "Read DTCs (19)"
                                elif sid == "22":
                                    name = f"Read Data (22) {payload.replace(' ', '')[2:6]}"
                                elif sid == "2E":
                                    name = "Write Data (2E)"
                                elif sid == "31":
                                    name = "Routine Control (31)"
                                elif sid == "3E":
                                    name = "Tester Present (3E)"

                                self.config["bank_data"].append(
                                    {"name": name, "id": can_id, "data": payload}
                                )
                                added += 1
                        except Exception:
                            continue

            self.refresh_bank_tree()
            self.write_log(
                f">> Log Imported: Added {added} unique Tx commands to Bank."
            )

        except Exception as exc:
            messagebox.showerror(
                "Import Error",
                f"Failed to parse log:\n{exc}",
                parent=self._root(),
            )

    # ------------------------------------------------------------------
    # DBC loading
    # ------------------------------------------------------------------

    def load_dbc(self) -> None:
        filepath = filedialog.askopenfilename(filetypes=[("DBC Files", "*.dbc")])
        if filepath:
            ch_index = self.dbc_map_cb.current()
            self.process_dbc(filepath, ch_index)
            self.config["dbc_paths"][str(ch_index)] = filepath
            self.on_tx_channel_change(None)

    def process_dbc(self, filepath: str, ch_index: int) -> None:
        if not _CAN_AVAILABLE:
            self.write_log("[CanDiag] cantools not installed – DBC loading disabled.")
            return
        try:
            self.dbs[ch_index] = cantools.database.load_file(filepath)
            filename = os.path.basename(filepath)
            if ch_index == 0:
                self.dbc_label_0.config(
                    text=f"Ch 0: {filename}", foreground="blue"
                )
            else:
                self.dbc_label_1.config(
                    text=f"Ch 1: {filename}", foreground="blue"
                )
        except Exception as exc:
            self.write_log(f"[CanDiag] DBC load error: {exc}")

    def on_tx_channel_change(self, event: Optional[tk.Event]) -> None:
        if not self.tx_channel_cb.get():
            return
        tx_ch_index = self.tx_channel_cb.current()
        db = self.dbs.get(tx_ch_index)
        if db:
            self.dbc_msg_cb["values"] = [msg.name for msg in db.messages]
            self.dbc_msg_cb.set("")
        else:
            self.dbc_msg_cb["values"] = []
            self.dbc_msg_cb.set("No DBC mapped")

    def on_dbc_msg_select(self, event: Optional[tk.Event]) -> None:
        db = self.dbs.get(self.tx_channel_cb.current())
        if not db:
            return
        try:
            msg = db.get_message_by_name(self.dbc_msg_cb.get())
            self.arb_id_entry.delete(0, tk.END)
            self.arb_id_entry.insert(0, f"{msg.frame_id:X}")
            self.data_entry.delete(0, tk.END)
            self.data_entry.insert(0, " ".join(["00"] * msg.length))
        except Exception:
            pass

    # ------------------------------------------------------------------
    # Logging
    # ------------------------------------------------------------------

    def write_log(self, message: str) -> None:
        timestamp = datetime.datetime.now().strftime("%H:%M:%S.%f")[:-3]
        log_entry = f"[{timestamp}] {message}\n"
        self.log_text.configure(state="normal")

        if "\u2705 PASS" in message:
            self.log_text.insert(tk.END, log_entry, "pass")
            self.log_text.tag_config("pass", foreground="lightgreen")
        elif "\u274C FAIL" in message:
            self.log_text.insert(tk.END, log_entry, "fail")
            self.log_text.tag_config("fail", foreground="red")
        else:
            self.log_text.insert(tk.END, log_entry)

        self.log_text.see(tk.END)
        self.log_text.configure(state="disabled")
        try:
            with open(self.log_filename, "a", encoding="utf-8") as fh:
                fh.write(log_entry)
        except OSError:
            pass

    # ------------------------------------------------------------------
    # Hardware connection
    # ------------------------------------------------------------------

    def connect_hardware(self) -> None:
        if self.is_connected:
            return
        if not _CAN_AVAILABLE:
            messagebox.showerror(
                "Dependency Missing",
                "The 'python-can' package is not installed.\n"
                "Run:  pip install python-can cantools",
                parent=self._root(),
            )
            return
        try:
            configs = can.detect_available_configs("vector")
            if len(configs) < 2:
                raise ValueError("Minimum of 2 Vector channels required.")

            self.buses, self.vector_channels, channel_names = [], [], []

            for i, cfg in enumerate(configs[:2]):
                ch_id = cfg.get("channel")
                # Bug fix: only pass data_bitrate when CAN-FD is enabled to
                # avoid passing None which some python-can versions reject.
                bus_kwargs: Dict[str, Any] = dict(
                    interface="vector",
                    channel=ch_id,
                    bitrate=int(self.bitrate_entry.get()),
                    fd=self.is_fd_var.get(),
                )
                if self.is_fd_var.get():
                    bus_kwargs["data_bitrate"] = int(
                        self.data_bitrate_entry.get()
                    )
                bus = can.interface.Bus(**bus_kwargs)
                self.buses.append(bus)
                self.vector_channels.append(ch_id)
                channel_names.append(f"Vector Ch {ch_id} (Idx {i})")
                threading.Thread(
                    target=self.rx_loop, args=(bus, ch_id, i), daemon=True
                ).start()

            self.tx_channel_cb["values"] = channel_names
            if channel_names:
                self.tx_channel_cb.current(0)
                self.on_tx_channel_change(None)

            self.is_connected = True
            self.btn_connect.config(state="disabled")
            self.btn_disconnect.config(state="normal")
            self.btn_run_script.config(state="normal")
            self.write_log("Connected to Vector hardware.")

        except Exception as exc:
            messagebox.showerror(
                "Connection Error", str(exc), parent=self._root()
            )

    def disconnect_hardware(self) -> None:
        for bus in self.buses:
            bus.shutdown()
        self.buses.clear()
        self.vector_channels.clear()
        self.is_connected = False
        self.btn_connect.config(state="normal")
        self.btn_disconnect.config(state="disabled")
        self.btn_run_script.config(state="disabled")
        self.write_log("Hardware disconnected.")

    # ------------------------------------------------------------------
    # RX loop (background thread)
    # ------------------------------------------------------------------

    def rx_loop(self, bus: Any, channel_id: Any, list_index: int) -> None:
        while self.is_connected:
            try:
                msg = bus.recv(timeout=1.0)
                if not msg:
                    continue

                data_bytes = list(msg.data)
                hex_out = " ".join(f"{b:02X}" for b in data_bytes)

                uds_status = ""
                ascii_trans = ""
                uds_payload: list = []

                if data_bytes:
                    pci_type = data_bytes[0] >> 4
                    if pci_type == 0 and len(data_bytes) > 1:
                        length = data_bytes[0] & 0x0F
                        uds_payload = data_bytes[1:1 + length]
                    elif pci_type == 1 and len(data_bytes) > 2:
                        uds_payload = data_bytes[2:]
                    elif pci_type == 2 and len(data_bytes) > 1:
                        uds_payload = data_bytes[1:]

                    if uds_payload:
                        if pci_type in (0, 1):
                            sid = uds_payload[0]
                            if sid == 0x7F:
                                nrc = (
                                    uds_payload[2]
                                    if len(uds_payload) > 2
                                    else 0x00
                                )
                                uds_status = (
                                    f" | \u274C FAIL (7F) [NRC: {nrc:02X}]"
                                )
                            elif 0x50 <= sid <= 0x7E:
                                uds_status = " | \u2705 PASS"

                        ascii_chars = [
                            chr(b) if 32 <= b <= 126 else "." for b in uds_payload
                        ]
                        ascii_candidate = "".join(ascii_chars).replace(".", "")
                        if re.search(r"[a-zA-Z0-9]{3,}", ascii_candidate):
                            ascii_trans = f" | ASCII: '{ascii_candidate}'"

                self.write_log(
                    f"RX [Ch {channel_id}] | ID: {msg.arbitration_id:X}"
                    f" | Data: {hex_out}{uds_status}{ascii_trans}"
                )

                if self.is_fc_enabled.get() and data_bytes:
                    try:
                        watch_id = int(self.fc_rx_entry.get(), 16)
                        reply_id = int(self.fc_tx_entry.get(), 16)

                        if (
                            msg.arbitration_id == watch_id
                            and (data_bytes[0] & 0xF0) == 0x10
                        ):
                            fc_payload = bytes(
                                [0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
                            )
                            fc_msg = can.Message(
                                arbitration_id=reply_id,
                                data=fc_payload,
                                is_extended_id=(reply_id > 0x7FF),
                                is_fd=self.is_fd_var.get(),
                                bitrate_switch=self.is_fd_var.get(),
                            )
                            bus.send(fc_msg)
                            self.write_log(
                                f"TX [Ch {channel_id}] (Auto-FC)"
                                f" | ID: {reply_id:X}"
                                " | Data: 30 00 00 00 00 00 00 00"
                            )
                    except ValueError:
                        pass
            except Exception:
                break

    # ------------------------------------------------------------------
    # TX
    # ------------------------------------------------------------------

    def send_command(
        self,
        arb_id_str: Optional[str] = None,
        data_str: Optional[str] = None,
    ) -> None:
        if not self.is_connected:
            return

        arb_id_str = arb_id_str or self.arb_id_entry.get()
        data_str = data_str or self.data_entry.get()

        try:
            arb_id = int(arb_id_str, 16)
            data_bytes = bytes.fromhex(data_str.replace(" ", ""))
            is_fd = self.is_fd_var.get()

            tx_ch_index = self.tx_channel_cb.current()
            target_bus = self.buses[tx_ch_index]
            hw_channel_id = self.vector_channels[tx_ch_index]

            msg = can.Message(
                arbitration_id=arb_id,
                data=data_bytes,
                is_extended_id=(arb_id > 0x7FF),
                is_fd=is_fd,
                bitrate_switch=is_fd,
            )
            target_bus.send(msg)
            hex_out = " ".join(f"{b:02X}" for b in data_bytes)
            self.write_log(
                f"TX [Ch {hw_channel_id}] | ID: {arb_id:X} | Data: {hex_out}"
            )

        except ValueError:
            pass
        except Exception as exc:
            print(f"[CanDiag] TX Error: {exc}")
