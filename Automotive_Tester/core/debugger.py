"""
Debug / troubleshoot helpers for the Automotive Tester.

Provides a :class:`ScriptEditor` popup (analogous to the one in
Trace32_Executor.py) that lets a tester view, edit, and re-run any failing
script – Python, CMM, or CANoe .can – without leaving the application.
"""
from __future__ import annotations

import logging
import os
import tkinter as tk
from tkinter import messagebox, scrolledtext
from typing import Any, Callable, Optional

logger = logging.getLogger(__name__)

# Recognised file type → display label
_SCRIPT_LABELS = {
    ".py": "Python Script",
    ".cmm": "CMM Script",
    ".can": "CANoe Script",
}


class ScriptEditor(tk.Toplevel):
    """Popup editor that lets the user fix a failing script and re-queue it.

    Matches the style of the ScriptEditor in Trace32_Executor.py.

    Args:
        parent:            Parent tkinter widget.
        file_path:         Absolute path to the script to edit.
        on_save_callback:  Called with the (possibly changed) file_path when
                           the user clicks *Save & Re-run*.
    """

    def __init__(
        self,
        parent: tk.Widget,
        file_path: str,
        on_save_callback: Callable[[str], None],
    ) -> None:
        super().__init__(parent)
        ext = os.path.splitext(file_path)[1].lower()
        label = _SCRIPT_LABELS.get(ext, "Script")
        self.title(f"Debug/Edit {label}: {os.path.basename(file_path)}")
        self.geometry("720x520")
        self.resizable(True, True)
        self.file_path = file_path
        self._on_save = on_save_callback

        self._build_ui()
        self._load_file()

    # ------------------------------------------------------------------
    # UI construction
    # ------------------------------------------------------------------

    def _build_ui(self) -> None:
        """Construct the editor widgets."""
        # ── Header bar ────────────────────────────────────────────────
        header = tk.Frame(self, bg="#343a40")
        tk.Label(
            header,
            text=f"📝  {os.path.basename(self.file_path)}",
            bg="#343a40",
            fg="white",
            font=("Segoe UI", 10, "bold"),
            padx=8,
        ).pack(side=tk.LEFT, pady=4)
        header.pack(fill=tk.X)

        # ── Editor area ────────────────────────────────────────────────
        editor_frame = tk.Frame(self)
        editor_frame.pack(fill=tk.BOTH, expand=True, padx=4, pady=4)

        self._line_numbers = tk.Text(
            editor_frame,
            width=4,
            padx=4,
            bg="#f8f9fa",
            fg="#6c757d",
            font=("Consolas", 10),
            state=tk.DISABLED,
            takefocus=False,
        )
        self._line_numbers.pack(side=tk.LEFT, fill=tk.Y)

        self.text_area = scrolledtext.ScrolledText(
            editor_frame,
            wrap=tk.NONE,
            font=("Consolas", 10),
            undo=True,
        )
        self.text_area.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        self.text_area.bind("<KeyRelease>", self._update_line_numbers)
        self.text_area.bind("<MouseWheel>", self._sync_scroll)

        # ── Status / error summary ────────────────────────────────────
        self._status_var = tk.StringVar(value="Ready to edit.")
        tk.Label(
            self,
            textvariable=self._status_var,
            anchor=tk.W,
            padx=6,
            fg="#495057",
            font=("Segoe UI", 9),
        ).pack(fill=tk.X)

        # ── Button bar ─────────────────────────────────────────────────
        btn_bar = tk.Frame(self, bd=1, relief=tk.GROOVE)
        tk.Button(
            btn_bar,
            text="💾  Save & Re-run",
            bg="#28a745",
            fg="white",
            font=("Segoe UI", 9, "bold"),
            command=self._save_and_close,
        ).pack(side=tk.LEFT, padx=4, pady=4)
        tk.Button(
            btn_bar,
            text="↩  Reload from disk",
            command=self._load_file,
        ).pack(side=tk.LEFT, padx=4, pady=4)
        tk.Button(
            btn_bar,
            text="✖  Cancel",
            bg="#dc3545",
            fg="white",
            command=self.destroy,
        ).pack(side=tk.RIGHT, padx=4, pady=4)
        btn_bar.pack(fill=tk.X, side=tk.BOTTOM)

    # ------------------------------------------------------------------
    # File I/O
    # ------------------------------------------------------------------

    def _load_file(self) -> None:
        """Read the file from disk and populate the editor."""
        if not os.path.isfile(self.file_path):
            self._status_var.set(f"File not found: {self.file_path}")
            return
        try:
            with open(self.file_path, "r", encoding="utf-8", errors="replace") as fh:
                content = fh.read()
            self.text_area.delete("1.0", tk.END)
            self.text_area.insert(tk.INSERT, content)
            self._update_line_numbers()
            self._status_var.set(f"Loaded: {self.file_path}")
        except OSError as exc:
            self._status_var.set(f"Load error: {exc}")
            logger.error("ScriptEditor load error: %s", exc)

    def _save_and_close(self) -> None:
        """Write the editor contents back to disk and invoke the callback."""
        try:
            with open(self.file_path, "w", encoding="utf-8") as fh:
                fh.write(self.text_area.get("1.0", tk.END))
            logger.info("Script saved: %s", self.file_path)
        except OSError as exc:
            messagebox.showerror("Save Error", str(exc), parent=self)
            return
        self._on_save(self.file_path)
        self.destroy()

    # ------------------------------------------------------------------
    # Line number helpers
    # ------------------------------------------------------------------

    def _update_line_numbers(self, _event: Optional[object] = None) -> None:
        """Recompute and redraw line numbers."""
        total = int(self.text_area.index(tk.END).split(".")[0]) - 1
        self._line_numbers.config(state=tk.NORMAL)
        self._line_numbers.delete("1.0", tk.END)
        self._line_numbers.insert(tk.END, "\n".join(str(i) for i in range(1, total + 1)))
        self._line_numbers.config(state=tk.DISABLED)

    def _sync_scroll(self, _event: Optional[object] = None) -> None:
        """Keep line numbers in sync with the scrolled text widget."""
        self._line_numbers.yview_moveto(self.text_area.yview()[0])


# ---------------------------------------------------------------------------
# Diagnostic panel (embedded in the main window)
# ---------------------------------------------------------------------------

class DebugPanel(tk.Frame):
    """A collapsible panel showing the last failure details.

    Provides a *Open Editor* button that spawns a :class:`ScriptEditor` for
    the most recently failed script.
    """

    def __init__(
        self,
        parent: tk.Widget,
        requeue_callback: Callable[[str], None],
        **frame_kwargs: Any,
    ) -> None:
        super().__init__(parent, **frame_kwargs)
        self._requeue = requeue_callback
        self._last_failed_path: Optional[str] = None
        self._build_ui()

    def _build_ui(self) -> None:
        header = tk.Frame(self, bg="#ffc107")
        tk.Label(
            header,
            text="🔍  Debug / Troubleshoot",
            bg="#ffc107",
            fg="#212529",
            font=("Segoe UI", 9, "bold"),
            padx=8,
        ).pack(side=tk.LEFT, pady=2)
        header.pack(fill=tk.X)

        body = tk.Frame(self)
        body.pack(fill=tk.BOTH, padx=4, pady=4)

        self._info_var = tk.StringVar(value="No failures yet.")
        tk.Label(body, textvariable=self._info_var, anchor=tk.W, font=("Segoe UI", 9)).pack(
            fill=tk.X
        )

        self._edit_btn = tk.Button(
            body,
            text="📝  Open Script Editor",
            state=tk.DISABLED,
            command=self._open_editor,
        )
        self._edit_btn.pack(anchor=tk.W, pady=2)

    def set_failure(self, file_path: str, error_message: str) -> None:
        """Record a failed script and enable the editor button.

        Args:
            file_path:     Path to the script that failed.
            error_message: Error or assertion message to display.
        """
        self._last_failed_path = file_path
        short = os.path.basename(file_path)
        preview = error_message[:120] + "…" if len(error_message) > 120 else error_message
        self._info_var.set(f"❌ {short}: {preview}")
        self._edit_btn.config(state=tk.NORMAL)

    def clear(self) -> None:
        """Reset the panel to its idle state."""
        self._last_failed_path = None
        self._info_var.set("No failures yet.")
        self._edit_btn.config(state=tk.DISABLED)

    def _open_editor(self) -> None:
        if self._last_failed_path:
            ScriptEditor(self, self._last_failed_path, self._requeue)
