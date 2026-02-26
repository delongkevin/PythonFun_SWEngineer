"""Full-featured tkinter GUI for CAN log visualisation."""

import os
import io
import base64
import json
import threading

import tkinter as tk
from tkinter import ttk, filedialog, messagebox

try:
    import matplotlib
    matplotlib.use("TkAgg")
    from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
    from matplotlib.figure import Figure
    _MPL_OK = True
except Exception:
    try:
        import matplotlib
        matplotlib.use("Agg")
        from matplotlib.figure import Figure
        _MPL_OK = False
    except Exception:
        _MPL_OK = False

import pandas as pd
import numpy as np

from . import parser as log_parser
from . import analytics

_MAX_TREE_ROWS = 10_000


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _embed_figure(parent: tk.Widget, fig) -> "FigureCanvasTkAgg":
    """Embed a matplotlib Figure in a tkinter widget and return the canvas."""
    canvas = FigureCanvasTkAgg(fig, master=parent)
    canvas.draw()
    canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
    toolbar = NavigationToolbar2Tk(canvas, parent)
    toolbar.update()
    return canvas


def _fig_to_b64(fig) -> str:
    """Render a Figure to a base-64 encoded PNG string."""
    buf = io.BytesIO()
    fig.savefig(buf, format="png", bbox_inches="tight")
    buf.seek(0)
    return base64.b64encode(buf.read()).decode()


def _export_html_report(df: pd.DataFrame, output_path: str) -> None:
    """Generate a self-contained HTML analysis report."""
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    summary = analytics.compute_summary(df)
    freq_df = analytics.compute_frequency_per_id(df)
    rate_df = analytics.compute_message_rate_timeseries(df)

    # Plot 1: message rate
    fig1, ax1 = plt.subplots(figsize=(10, 4))
    if not rate_df.empty:
        ax1.plot(rate_df["time_sec"], rate_df["rate"], color="steelblue")
    ax1.set_xlabel("Time (s)")
    ax1.set_ylabel("Rate (msg/s)")
    ax1.set_title("Message Rate over Time")
    ax1.grid(True, alpha=0.3)
    rate_b64 = _fig_to_b64(fig1)
    plt.close(fig1)

    # Plot 2: frequency per ID
    fig2, ax2 = plt.subplots(figsize=(10, 4))
    if not freq_df.empty:
        ax2.bar(freq_df["can_id"].astype(str), freq_df["freq_hz"], color="darkorange")
    ax2.set_xlabel("CAN ID")
    ax2.set_ylabel("Frequency (Hz)")
    ax2.set_title("Message Frequency per CAN ID")
    plt.xticks(rotation=45, ha="right")
    freq_b64 = _fig_to_b64(fig2)
    plt.close(fig2)

    iat_df = analytics.compute_inter_arrival_times(df)

    html = f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>CAN Log Analysis Report</title>
<style>
  body {{ font-family: sans-serif; margin: 30px; }}
  h1 {{ color: #333; }}
  h2 {{ color: #555; border-bottom: 1px solid #ccc; padding-bottom: 4px; }}
  table {{ border-collapse: collapse; width: 100%; margin-bottom: 20px; }}
  td, th {{ border: 1px solid #ccc; padding: 6px 10px; text-align: left; }}
  th {{ background: #f0f0f0; }}
  img {{ max-width: 100%; margin: 10px 0; }}
</style>
</head>
<body>
<h1>CAN Log Analysis Report</h1>
<h2>Summary</h2>
<table>
{''.join(f'<tr><th>{k}</th><td>{v}</td></tr>' for k, v in summary.items())}
</table>
<h2>Message Rate</h2>
<img src="data:image/png;base64,{rate_b64}" alt="Message Rate">
<h2>Frequency per CAN ID</h2>
<img src="data:image/png;base64,{freq_b64}" alt="Frequency per CAN ID">
<h2>Frequency Table</h2>
{freq_df.to_html(index=False)}
<h2>Inter-Arrival Times</h2>
{iat_df.to_html(index=False)}
</body>
</html>"""

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(html)


# ---------------------------------------------------------------------------
# Main Application
# ---------------------------------------------------------------------------

class CANLogAnalyzerApp:
    """Professional CAN log visualisation application."""

    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("CAN Log Analyzer v0.1.0")
        self.root.geometry("1400x900")

        self.df: pd.DataFrame = None        # full parsed DataFrame
        self.df_filtered: pd.DataFrame = None  # filtered view

        # Sorting state for Frames treeview
        self._sort_col: str = ""
        self._sort_reverse: bool = False

        # Rate plot per-ID selection state
        self._rate_canvas = None
        self._rate_fig = None
        self._byte_canvas = None
        self._byte_fig = None

        self._setup_ui()

    # ------------------------------------------------------------------
    # UI Construction
    # ------------------------------------------------------------------

    def _setup_ui(self) -> None:
        self._build_toolbar()
        self._build_summary_bar()
        self._build_main_area()
        self._build_status_bar()

    def _build_toolbar(self) -> None:
        toolbar = ttk.Frame(self.root, relief=tk.RAISED, padding=4)
        toolbar.pack(side=tk.TOP, fill=tk.X)

        ttk.Button(toolbar, text="📂 Load File", command=self.load_file).pack(side=tk.LEFT, padx=2)
        ttk.Button(toolbar, text="💾 Export CSV", command=self.export_csv).pack(side=tk.LEFT, padx=2)
        ttk.Button(toolbar, text="📄 Export JSON", command=self.export_json).pack(side=tk.LEFT, padx=2)
        ttk.Button(toolbar, text="🌐 Export HTML Report", command=self.export_html_report).pack(side=tk.LEFT, padx=2)

    def _build_summary_bar(self) -> None:
        bar = ttk.Frame(self.root, padding=(6, 2))
        bar.pack(side=tk.TOP, fill=tk.X)

        ttk.Label(bar, text="Duration:").pack(side=tk.LEFT)
        self._lbl_duration = ttk.Label(bar, text="—", foreground="navy")
        self._lbl_duration.pack(side=tk.LEFT, padx=(2, 14))

        ttk.Label(bar, text="Messages:").pack(side=tk.LEFT)
        self._lbl_messages = ttk.Label(bar, text="—", foreground="navy")
        self._lbl_messages.pack(side=tk.LEFT, padx=(2, 14))

        ttk.Label(bar, text="CAN IDs:").pack(side=tk.LEFT)
        self._lbl_ids = ttk.Label(bar, text="—", foreground="navy")
        self._lbl_ids.pack(side=tk.LEFT, padx=(2, 14))

    def _build_main_area(self) -> None:
        paned = ttk.PanedWindow(self.root, orient=tk.HORIZONTAL)
        paned.pack(fill=tk.BOTH, expand=True, padx=4, pady=4)

        # Left panel – filters
        filter_frame = ttk.LabelFrame(paned, text="Filters", padding=8)
        paned.add(filter_frame, weight=0)
        self._build_filter_panel(filter_frame)

        # Right panel – notebook
        right_frame = ttk.Frame(paned)
        paned.add(right_frame, weight=1)
        self._build_notebook(right_frame)

    def _build_filter_panel(self, parent: ttk.LabelFrame) -> None:
        parent.columnconfigure(1, weight=1)

        def row(lbl, widget_factory, r):
            ttk.Label(parent, text=lbl).grid(row=r, column=0, sticky=tk.W, pady=2)
            w = widget_factory(parent)
            w.grid(row=r, column=1, sticky=tk.EW, pady=2, padx=(4, 0))
            return w

        self._flt_can_id = row("CAN ID", lambda p: ttk.Entry(p, width=16), 0)
        self._flt_time_from = row("Time From (s)", lambda p: ttk.Entry(p, width=16), 1)
        self._flt_time_to = row("Time To (s)", lambda p: ttk.Entry(p, width=16), 2)
        self._flt_dlc = row("DLC", lambda p: ttk.Entry(p, width=16), 3)
        self._flt_pattern = row("Data pattern (hex)", lambda p: ttk.Entry(p, width=16), 4)

        btn_frame = ttk.Frame(parent)
        btn_frame.grid(row=5, column=0, columnspan=2, pady=8)
        ttk.Button(btn_frame, text="Apply", command=self.apply_filters).pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_frame, text="Clear", command=self.clear_filters).pack(side=tk.LEFT, padx=4)

    def _build_notebook(self, parent: ttk.Frame) -> None:
        self._notebook = ttk.Notebook(parent)
        self._notebook.pack(fill=tk.BOTH, expand=True)

        # Tab 1 – Frames
        frames_tab = ttk.Frame(self._notebook)
        self._notebook.add(frames_tab, text="Frames")
        self._build_frames_tab(frames_tab)

        # Tab 2 – Rate Plot
        rate_tab = ttk.Frame(self._notebook)
        self._notebook.add(rate_tab, text="Rate Plot")
        self._build_rate_plot_tab(rate_tab)

        # Tab 3 – Byte Analysis
        byte_tab = ttk.Frame(self._notebook)
        self._notebook.add(byte_tab, text="Byte Analysis")
        self._build_byte_analysis_tab(byte_tab)

    def _build_frames_tab(self, parent: ttk.Frame) -> None:
        # Row count label
        self._frames_count_var = tk.StringVar(value="No data loaded.")
        ttk.Label(parent, textvariable=self._frames_count_var).pack(anchor=tk.W, padx=4, pady=2)

        tree_frame = ttk.Frame(parent)
        tree_frame.pack(fill=tk.BOTH, expand=True)

        columns = ("#", "Timestamp", "CAN ID", "DLC",
                   "Byte0", "Byte1", "Byte2", "Byte3",
                   "Byte4", "Byte5", "Byte6", "Byte7", "Hex Data")
        col_widths = {"#": 55, "Timestamp": 90, "CAN ID": 60, "DLC": 40,
                      "Byte0": 45, "Byte1": 45, "Byte2": 45, "Byte3": 45,
                      "Byte4": 45, "Byte5": 45, "Byte6": 45, "Byte7": 45,
                      "Hex Data": 160}

        self._tree = ttk.Treeview(tree_frame, columns=columns, show="headings",
                                   selectmode="browse")
        for col in columns:
            self._tree.heading(col, text=col,
                               command=lambda c=col: self._treeview_sort_column(c))
            self._tree.column(col, width=col_widths.get(col, 60), minwidth=30,
                              anchor=tk.CENTER)

        vsb = ttk.Scrollbar(tree_frame, orient=tk.VERTICAL, command=self._tree.yview)
        hsb = ttk.Scrollbar(tree_frame, orient=tk.HORIZONTAL, command=self._tree.xview)
        self._tree.configure(yscrollcommand=vsb.set, xscrollcommand=hsb.set)

        self._tree.grid(row=0, column=0, sticky="nsew")
        vsb.grid(row=0, column=1, sticky="ns")
        hsb.grid(row=1, column=0, sticky="ew")
        tree_frame.rowconfigure(0, weight=1)
        tree_frame.columnconfigure(0, weight=1)

    def _build_rate_plot_tab(self, parent: ttk.Frame) -> None:
        top = ttk.Frame(parent)
        top.pack(fill=tk.BOTH, expand=True)

        # Left: ID listbox for overlay selection
        side = ttk.LabelFrame(top, text="CAN IDs (overlay)", padding=4)
        side.pack(side=tk.RIGHT, fill=tk.Y, padx=4, pady=4)

        self._rate_id_listbox = tk.Listbox(side, selectmode=tk.MULTIPLE,
                                            width=12, exportselection=False)
        lsb = ttk.Scrollbar(side, orient=tk.VERTICAL,
                             command=self._rate_id_listbox.yview)
        self._rate_id_listbox.configure(yscrollcommand=lsb.set)
        self._rate_id_listbox.pack(side=tk.LEFT, fill=tk.Y)
        lsb.pack(side=tk.LEFT, fill=tk.Y)
        self._rate_id_listbox.bind("<<ListboxSelect>>", lambda _e: self._update_rate_plot())

        ttk.Button(side, text="Export PNG",
                   command=self._export_rate_png).pack(pady=4)

        # Right: matplotlib canvas
        self._rate_plot_frame = ttk.Frame(top)
        self._rate_plot_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        if _MPL_OK:
            self._rate_fig = Figure(figsize=(8, 4))
            self._rate_canvas = FigureCanvasTkAgg(self._rate_fig, master=self._rate_plot_frame)
            self._rate_canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
            tb = NavigationToolbar2Tk(self._rate_canvas, self._rate_plot_frame)
            tb.update()

    def _build_byte_analysis_tab(self, parent: ttk.Frame) -> None:
        ctrl = ttk.Frame(parent)
        ctrl.pack(fill=tk.X, padx=6, pady=4)

        ttk.Label(ctrl, text="CAN ID:").pack(side=tk.LEFT)
        self._byte_id_combo = ttk.Combobox(ctrl, state="readonly", width=14)
        self._byte_id_combo.pack(side=tk.LEFT, padx=4)
        self._byte_id_combo.bind("<<ComboboxSelected>>",
                                  lambda _e: self._update_byte_analysis(
                                      self._byte_id_combo.get()))

        ttk.Label(ctrl, text="Byte:").pack(side=tk.LEFT, padx=(16, 2))
        self._byte_sel_combo = ttk.Combobox(ctrl, state="readonly", width=8,
                                             values=[f"byte{i}" for i in range(8)])
        self._byte_sel_combo.current(0)
        self._byte_sel_combo.pack(side=tk.LEFT)
        self._byte_sel_combo.bind("<<ComboboxSelected>>",
                                   lambda _e: self._update_byte_analysis(
                                       self._byte_id_combo.get()))

        body = ttk.PanedWindow(parent, orient=tk.HORIZONTAL)
        body.pack(fill=tk.BOTH, expand=True)

        # Left: byte stats treeview
        stats_frame = ttk.LabelFrame(body, text="Byte Statistics", padding=4)
        body.add(stats_frame, weight=0)

        stat_cols = ("Byte", "Min", "Max", "Mean", "Changes")
        self._byte_tree = ttk.Treeview(stats_frame, columns=stat_cols,
                                        show="headings", height=10)
        for col in stat_cols:
            self._byte_tree.heading(col, text=col)
            self._byte_tree.column(col, width=70, anchor=tk.CENTER)
        bvsb = ttk.Scrollbar(stats_frame, orient=tk.VERTICAL,
                              command=self._byte_tree.yview)
        self._byte_tree.configure(yscrollcommand=bvsb.set)
        self._byte_tree.pack(side=tk.LEFT, fill=tk.BOTH)
        bvsb.pack(side=tk.LEFT, fill=tk.Y)

        # Right: matplotlib (histogram + timeseries)
        self._byte_plot_frame = ttk.Frame(body)
        body.add(self._byte_plot_frame, weight=1)
        if _MPL_OK:
            self._byte_fig = Figure(figsize=(7, 5))
            self._byte_canvas = FigureCanvasTkAgg(self._byte_fig,
                                                   master=self._byte_plot_frame)
            self._byte_canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)
            tb = NavigationToolbar2Tk(self._byte_canvas, self._byte_plot_frame)
            tb.update()

    def _build_status_bar(self) -> None:
        bar = ttk.Frame(self.root, relief=tk.SUNKEN, padding=(4, 2))
        bar.pack(side=tk.BOTTOM, fill=tk.X)

        self._status_var = tk.StringVar(value="Ready")
        ttk.Label(bar, textvariable=self._status_var, anchor=tk.W).pack(
            side=tk.LEFT, fill=tk.X, expand=True)

        self._progress = ttk.Progressbar(bar, mode="indeterminate", length=140)
        self._progress.pack(side=tk.RIGHT, padx=4)

    # ------------------------------------------------------------------
    # File Loading
    # ------------------------------------------------------------------

    def load_file(self, file_path: str = None) -> None:
        if file_path is None:
            file_path = filedialog.askopenfilename(
                title="Open CAN log file",
                filetypes=[("CAN log files", "*.asc *.blf *.txt"),
                           ("All files", "*.*")],
            )
        if not file_path:
            return

        self._status_var.set(f"Loading: {os.path.basename(file_path)} …")
        self._progress.start(10)
        t = threading.Thread(target=self._parse_thread, args=(file_path,), daemon=True)
        t.start()

    def _parse_thread(self, file_path: str) -> None:
        try:
            df = log_parser.parse_log(file_path)
            self.root.after(0, lambda: self._on_parse_complete(df, file_path))
        except FileNotFoundError as err:
            msg = str(err)
            self.root.after(0, lambda: self._on_parse_error(msg))
        except Exception as err:
            msg = str(err)
            self.root.after(0, lambda: self._on_parse_error(msg))

    def _on_parse_complete(self, df: pd.DataFrame, file_path: str) -> None:
        self._progress.stop()
        self.df = df
        self.df_filtered = df.copy()
        self._status_var.set(
            f"Loaded {len(df):,} messages from {os.path.basename(file_path)}"
        )
        self._update_summary_bar()
        self._populate_frames_tab()
        self._populate_rate_id_listbox()
        self._update_rate_plot()
        self._populate_byte_id_combo()

    def _on_parse_error(self, msg: str) -> None:
        self._progress.stop()
        self._status_var.set(f"Error: {msg}")
        messagebox.showerror("Parse Error", msg)

    # ------------------------------------------------------------------
    # Summary Bar
    # ------------------------------------------------------------------

    def _update_summary_bar(self) -> None:
        if self.df is None or self.df.empty:
            return
        s = analytics.compute_summary(self.df)
        self._lbl_duration.config(text=f"{s['duration_sec']:.3f} s")
        self._lbl_messages.config(text=f"{s['total_messages']:,}")
        self._lbl_ids.config(text=str(len(s["unique_can_ids"])))

    # ------------------------------------------------------------------
    # Filters
    # ------------------------------------------------------------------

    def apply_filters(self) -> None:
        if self.df is None:
            return

        df = self.df.copy()

        # CAN ID filter
        cid_text = self._flt_can_id.get().strip().upper()
        if cid_text:
            ids = [x.strip() for x in cid_text.split(",") if x.strip()]
            df = df[df["can_id"].isin(ids)]

        # Time range
        t_from = self._flt_time_from.get().strip()
        t_to = self._flt_time_to.get().strip()
        try:
            if t_from:
                df = df[df["timestamp_sec"] >= float(t_from)]
        except ValueError:
            pass
        try:
            if t_to:
                df = df[df["timestamp_sec"] <= float(t_to)]
        except ValueError:
            pass

        # DLC filter
        dlc_text = self._flt_dlc.get().strip()
        try:
            if dlc_text:
                df = df[df["dlc"] == int(dlc_text)]
        except ValueError:
            pass

        # Data pattern (hex substring match)
        pattern = self._flt_pattern.get().strip().upper()
        if pattern:
            df = df[df["hex_data"].str.contains(pattern, na=False)]

        self.df_filtered = df.reset_index(drop=True)
        self._populate_frames_tab()
        self._update_rate_plot()
        self._status_var.set(
            f"Filter applied – {len(self.df_filtered):,} / {len(self.df):,} messages shown."
        )

    def clear_filters(self) -> None:
        for entry in (self._flt_can_id, self._flt_time_from,
                      self._flt_time_to, self._flt_dlc, self._flt_pattern):
            entry.delete(0, tk.END)
        if self.df is not None:
            self.df_filtered = self.df.copy()
            self._populate_frames_tab()
            self._update_rate_plot()
            self._status_var.set("Filters cleared.")

    # ------------------------------------------------------------------
    # Frames Tab
    # ------------------------------------------------------------------

    def _populate_frames_tab(self) -> None:
        # Clear existing rows
        for item in self._tree.get_children():
            self._tree.delete(item)

        df = self.df_filtered
        if df is None or df.empty:
            self._frames_count_var.set("No data.")
            return

        total = len(df)
        display_df = df.head(_MAX_TREE_ROWS)

        if total > _MAX_TREE_ROWS:
            self._frames_count_var.set(
                f"Showing first {_MAX_TREE_ROWS:,} of {total:,} messages."
            )
        else:
            self._frames_count_var.set(f"Total: {total:,} messages.")

        def _fmt_byte(val):
            if pd.isna(val):
                return "—"
            return f"{int(val):02X}"

        for idx, row in display_df.iterrows():
            values = (
                idx + 1,
                f"{row['timestamp_sec']:.6f}",
                row["can_id"],
                int(row["dlc"]) if pd.notna(row["dlc"]) else "—",
                _fmt_byte(row["byte0"]),
                _fmt_byte(row["byte1"]),
                _fmt_byte(row["byte2"]),
                _fmt_byte(row["byte3"]),
                _fmt_byte(row["byte4"]),
                _fmt_byte(row["byte5"]),
                _fmt_byte(row["byte6"]),
                _fmt_byte(row["byte7"]),
                row["hex_data"],
            )
            self._tree.insert("", tk.END, values=values)

    def _treeview_sort_column(self, col: str) -> None:
        if self.df_filtered is None or self.df_filtered.empty:
            return

        reverse = (self._sort_col == col) and (not self._sort_reverse)
        self._sort_col = col
        self._sort_reverse = reverse

        col_map = {
            "#": "timestamp_sec",  # row number – sort by time
            "Timestamp": "timestamp_sec",
            "CAN ID": "can_id",
            "DLC": "dlc",
            "Byte0": "byte0", "Byte1": "byte1", "Byte2": "byte2", "Byte3": "byte3",
            "Byte4": "byte4", "Byte5": "byte5", "Byte6": "byte6", "Byte7": "byte7",
            "Hex Data": "hex_data",
        }
        df_col = col_map.get(col)
        if df_col and df_col in self.df_filtered.columns:
            self.df_filtered = self.df_filtered.sort_values(
                df_col, ascending=not reverse, kind="stable"
            ).reset_index(drop=True)
            self._populate_frames_tab()

    # ------------------------------------------------------------------
    # Rate Plot Tab
    # ------------------------------------------------------------------

    def _populate_rate_id_listbox(self) -> None:
        self._rate_id_listbox.delete(0, tk.END)
        if self.df is None:
            return
        for cid in sorted(self.df["can_id"].dropna().unique()):
            self._rate_id_listbox.insert(tk.END, cid)

    def _update_rate_plot(self) -> None:
        if not _MPL_OK or self._rate_fig is None:
            return
        if self.df_filtered is None or self.df_filtered.empty:
            return

        self._rate_fig.clear()
        ax = self._rate_fig.add_subplot(111)

        # Total rate
        rate_df = analytics.compute_message_rate_timeseries(self.df_filtered, bin_size_sec=0.1)
        if not rate_df.empty:
            ax.plot(rate_df["time_sec"], rate_df["rate"],
                    label="All", color="steelblue", linewidth=1.5)

        # Per-ID overlay from listbox selection
        selected_indices = self._rate_id_listbox.curselection()
        for idx in selected_indices:
            cid = self._rate_id_listbox.get(idx)
            sub = self.df_filtered[self.df_filtered["can_id"] == cid]
            if not sub.empty:
                per_id = analytics.compute_message_rate_timeseries(sub, bin_size_sec=0.1)
                if not per_id.empty:
                    ax.plot(per_id["time_sec"], per_id["rate"],
                            label=f"ID {cid}", linewidth=1)

        ax.set_xlabel("Time (s)")
        ax.set_ylabel("Rate (msg/s)")
        ax.set_title("Message Rate")
        ax.legend(fontsize=8)
        ax.grid(True, alpha=0.3)
        self._rate_fig.tight_layout()
        self._rate_canvas.draw()

    def _export_rate_png(self) -> None:
        if self._rate_fig is None:
            return
        path = filedialog.asksaveasfilename(
            defaultextension=".png",
            filetypes=[("PNG image", "*.png")],
        )
        if path:
            self._rate_fig.savefig(path, bbox_inches="tight")
            self._status_var.set(f"Rate plot saved to {path}")

    # ------------------------------------------------------------------
    # Byte Analysis Tab
    # ------------------------------------------------------------------

    def _populate_byte_id_combo(self) -> None:
        if self.df is None:
            return
        ids = sorted(self.df["can_id"].dropna().unique().tolist())
        self._byte_id_combo["values"] = ids
        if ids:
            self._byte_id_combo.current(0)
            self._update_byte_analysis(ids[0])

    def _update_byte_analysis(self, can_id: str) -> None:
        if not can_id or self.df is None:
            return

        # Update stats treeview
        for item in self._byte_tree.get_children():
            self._byte_tree.delete(item)

        stats_df = analytics.compute_byte_statistics(self.df, can_id=can_id)
        if not stats_df.empty and can_id in stats_df.index:
            row_stats = stats_df.loc[can_id]
            for b in range(8):
                col = f"byte{b}"
                bmin = row_stats.get(f"{col}_min", np.nan)
                bmax = row_stats.get(f"{col}_max", np.nan)
                bmean = row_stats.get(f"{col}_mean", np.nan)
                bchg = row_stats.get(f"{col}_changes", 0)

                def _fmt(v):
                    return "—" if pd.isna(v) else f"{v:.1f}"

                self._byte_tree.insert("", tk.END, values=(
                    f"byte{b}", _fmt(bmin), _fmt(bmax), _fmt(bmean), int(bchg)
                ))

        # Update matplotlib plots
        if not _MPL_OK or self._byte_fig is None:
            return

        sel_byte = self._byte_sel_combo.get() or "byte0"
        sub = self.df[self.df["can_id"] == can_id]

        self._byte_fig.clear()
        ax_hist = self._byte_fig.add_subplot(2, 1, 1)
        ax_ts = self._byte_fig.add_subplot(2, 1, 2)

        if not sub.empty and sel_byte in sub.columns:
            vals = sub[sel_byte].dropna()
            if not vals.empty:
                ax_hist.hist(vals, bins=min(32, vals.nunique()), color="steelblue",
                             edgecolor="white")
                ax_hist.set_title(f"ID {can_id} – {sel_byte} distribution")
                ax_hist.set_xlabel("Value")
                ax_hist.set_ylabel("Count")
                ax_hist.grid(True, alpha=0.3)

                ax_ts.plot(sub["timestamp_sec"].values, vals.values,
                           color="darkorange", linewidth=0.8, marker=".", markersize=2)
                ax_ts.set_title(f"ID {can_id} – {sel_byte} over time")
                ax_ts.set_xlabel("Time (s)")
                ax_ts.set_ylabel("Value")
                ax_ts.grid(True, alpha=0.3)
            else:
                ax_hist.text(0.5, 0.5, "No data for this byte",
                             ha="center", va="center", transform=ax_hist.transAxes)
                ax_ts.text(0.5, 0.5, "No data for this byte",
                           ha="center", va="center", transform=ax_ts.transAxes)
        else:
            ax_hist.text(0.5, 0.5, "No data", ha="center", va="center",
                         transform=ax_hist.transAxes)
            ax_ts.text(0.5, 0.5, "No data", ha="center", va="center",
                       transform=ax_ts.transAxes)

        self._byte_fig.tight_layout()
        self._byte_canvas.draw()

    # ------------------------------------------------------------------
    # Export
    # ------------------------------------------------------------------

    def export_csv(self) -> None:
        if self.df_filtered is None or self.df_filtered.empty:
            messagebox.showwarning("No data", "No data loaded to export.")
            return
        path = filedialog.asksaveasfilename(
            defaultextension=".csv",
            filetypes=[("CSV files", "*.csv")],
        )
        if path:
            self.df_filtered.to_csv(path, index=False)
            self._status_var.set(f"CSV exported to {path}")

    def export_json(self) -> None:
        if self.df_filtered is None or self.df_filtered.empty:
            messagebox.showwarning("No data", "No data loaded to export.")
            return
        path = filedialog.asksaveasfilename(
            defaultextension=".json",
            filetypes=[("JSON files", "*.json")],
        )
        if path:
            summary = analytics.compute_summary(self.df_filtered)
            data = {
                "summary": {k: str(v) for k, v in summary.items()},
                "frames": self.df_filtered.to_dict(orient="records"),
            }
            with open(path, "w", encoding="utf-8") as f:
                json.dump(data, f, indent=2, default=str)
            self._status_var.set(f"JSON exported to {path}")

    def export_html_report(self) -> None:
        if self.df_filtered is None or self.df_filtered.empty:
            messagebox.showwarning("No data", "No data loaded to export.")
            return
        path = filedialog.asksaveasfilename(
            defaultextension=".html",
            filetypes=[("HTML files", "*.html")],
        )
        if path:
            try:
                _export_html_report(self.df_filtered, path)
                self._status_var.set(f"HTML report exported to {path}")
            except Exception as exc:
                messagebox.showerror("Export Error", str(exc))


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main(file_path: str = None) -> None:
    """Launch the CAN Log Analyzer GUI."""
    try:
        root = tk.Tk()
    except Exception:
        print("No display available – cannot launch GUI")
        return
    app = CANLogAnalyzerApp(root)
    if file_path:
        root.after(100, lambda: app.load_file(file_path))
    root.mainloop()
