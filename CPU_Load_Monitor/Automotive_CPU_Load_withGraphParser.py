import subprocess
import serial
import time
import os
import re
import json
import threading
import queue
import tkinter as tk
from tkinter import messagebox, scrolledtext, ttk, filedialog
from datetime import datetime
from functools import partial
import logging
import traceback
from typing import Dict, List, Tuple, Any, Optional
import sys
import shlex
import base64
import matplotlib.pyplot as plt
import openpyxl
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import webbrowser
from PIL import Image, ImageTk

# ─── Constants ────────────────────────────────────────────────────────────────
CONFIG_FILE          = "cpu_load_config.json"
QUEUE_PRESET_FILE    = "queue_preset.json"
GRAPH_PARSER_CONFIG_FILE = "graph_parser_config.txt"
LOG_FILE             = "cpu_load_tool.log"

# ─── Global state ─────────────────────────────────────────────────────────────
message_queue  = queue.Queue()
lock           = threading.Lock()
execution_queue: list = []
stop_requested  = False
pause_output    = False
pending_logs: list = []
timestamp_enabled = True
config: Dict[str, Any] = {}


# ─── Color Scheme ─────────────────────────────────────────────────────────────
class ColorScheme:
    PRIMARY        = "#2C3E50"
    SECONDARY      = "#34495E"
    ACCENT         = "#3498DB"
    SUCCESS        = "#27AE60"
    WARNING        = "#F39C12"
    ERROR          = "#E74C3C"
    INFO           = "#3498DB"
    BACKGROUND     = "#ECF0F1"
    SURFACE        = "#FFFFFF"
    TEXT_PRIMARY   = "#2C3E50"
    TEXT_SECONDARY = "#7F8C8D"
    BORDER         = "#BDC3C7"
    DATA_1         = "#2980B9"
    DATA_2         = "#27AE60"
    DATA_3         = "#8E44AD"
    DATA_4         = "#E67E22"
    DATA_5         = "#E74C3C"


# ─── UI Density Presets ───────────────────────────────────────────────────────
DENSITY_PRESETS = {
    "Compact": {
        "pad_x": 4, "pad_y": 2, "btn_pad": (8, 3),
        "header_h": 50, "font_size": 9, "title_size": 14,
        "section_pad": 6, "inner_pad": 4,
    },
    "Normal": {
        "pad_x": 8, "pad_y": 5, "btn_pad": (12, 6),
        "header_h": 70, "font_size": 10, "title_size": 16,
        "section_pad": 10, "inner_pad": 8,
    },
    "Spacious": {
        "pad_x": 14, "pad_y": 8, "btn_pad": (16, 8),
        "header_h": 90, "font_size": 10, "title_size": 18,
        "section_pad": 15, "inner_pad": 12,
    },
}

_density = DENSITY_PRESETS["Normal"]   # active density — mutated by settings


def D(key):
    """Shortcut to get a density value."""
    return _density[key]


# ─── Logging ──────────────────────────────────────────────────────────────────
def setup_logging():
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s - %(levelname)s - %(message)s',
        handlers=[
            logging.FileHandler(LOG_FILE, encoding='utf-8'),
            logging.StreamHandler(),
        ],
    )


def timestamp():
    return datetime.now().strftime('%Y-%m-%d %H:%M:%S')


def log_message(msg: str, color: str = 'black', level: str = 'INFO'):
    global timestamp_enabled
    formatted = f"[{timestamp()}] {msg}" if timestamp_enabled else msg
    message_queue.put(('log', formatted, color))
    logging.log(getattr(logging, level.upper(), logging.INFO), msg)


# ─── JSON helpers ─────────────────────────────────────────────────────────────
def safe_json_load(filepath: str, default: Any) -> Any:
    try:
        if os.path.exists(filepath):
            with open(filepath, 'r', encoding='utf-8') as f:
                return json.load(f)
    except (json.JSONDecodeError, IOError, UnicodeDecodeError) as e:
        logging.error(f"Error loading {filepath}: {e}")
    return default


def safe_json_save(filepath: str, data: Any) -> bool:
    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4, ensure_ascii=False)
        return True
    except (IOError, TypeError) as e:
        logging.error(f"Error saving {filepath}: {e}")
        return False


# ─── Config ───────────────────────────────────────────────────────────────────
DEFAULT_CONFIG: Dict[str, Any] = {
    "trace32_path":   "C:/T32/bin/windows64/t32marm.exe",
    "cmm_directory":  "CMM",
    "cert_directory": "certs",
    "com_port":       "COM33",
    "baud_rate":      115200,
    "timeout":        600,
    "serial_timeout": 1,
    "ui_density":     "Normal",
    "show_startup_info": True,
    "custom_tasks":   {},
    "graph_parser": {
        "default_input_file":    "",
        "default_output_folder": "graph_output",
        "default_search_strings": ["Idle", "CPU Load"],
        "include_cpu_load":      True,
        "show_labels":           True,
    },
}


def _merge_config(base: Dict, overlay: Dict) -> Dict:
    """Deep-merge overlay into base, returning a new dict."""
    result = base.copy()
    for k, v in overlay.items():
        if isinstance(v, dict) and isinstance(result.get(k), dict):
            result[k] = _merge_config(result[k], v)
        else:
            result[k] = v
    return result


def load_config() -> Dict[str, Any]:
    if not os.path.exists(CONFIG_FILE):
        save_config(DEFAULT_CONFIG)
        return dict(DEFAULT_CONFIG)

    loaded = safe_json_load(CONFIG_FILE, {})
    # Merge over defaults so new keys always exist
    merged = _merge_config(DEFAULT_CONFIG, loaded)

    # Ensure directories exist
    for dir_key in ("cmm_directory", "cert_directory"):
        try:
            os.makedirs(merged.get(dir_key, ""), exist_ok=True)
        except OSError:
            pass

    return merged


def save_config(cfg: Dict[str, Any]) -> bool:
    """Save config with backup of previous file."""
    if os.path.exists(CONFIG_FILE):
        try:
            os.replace(CONFIG_FILE, f"{CONFIG_FILE}.bak")
        except OSError:
            pass
    return safe_json_save(CONFIG_FILE, cfg)


# ─── Graph / Parser helpers ───────────────────────────────────────────────────
def clean_text(text):
    return "".join(c for c in text if c.isprintable())


def format_filename(search_string, file_path):
    base = os.path.splitext(os.path.basename(file_path))[0]
    safe = search_string.replace(" ", "_").replace(":", "_").replace("/", "_")
    return f"{base}_{safe}"


def normalize_spaces(text):
    return " ".join(text.split())


def extract_first_numeric(line, search_string):
    search_string = normalize_spaces(search_string)
    if search_string in normalize_spaces(line):
        modified = line.replace(search_string, "").strip()
        numbers = re.findall(r"\d+\.\d+|\d+", modified)
        return float(numbers[0]) if numbers else None
    return None


def create_output_folder(base_folder="graph_output"):
    ts = datetime.now().strftime("%Y_%m_%d_%H%M%S_%f")
    path = os.path.join(base_folder, f"output_{ts}")
    os.makedirs(path, exist_ok=True)
    return path


def save_to_excel(extracted_data, search_string, file_path, include_cpu_load, output_folder):
    safe = format_filename(search_string, file_path)
    filename = os.path.join(output_folder, f"output_{safe}.xlsx")
    wb = openpyxl.Workbook()
    ws = wb.active
    ws.title = "Extracted Data"
    ws.append(["Iteration", "Idle Value (%)"] + (["CPU Load (%)"] if include_cpu_load else []))
    for record in extracted_data:
        ws.append(record)
    wb.save(filename)
    return filename


def generate_graph(x_values, idle_values, cpu_load_values, search_string,
                   file_path, include_cpu_load, title, xlabel, ylabel,
                   show_labels, output_folder):
    if not idle_values:
        return None

    safe = format_filename(search_string, file_path)
    graph_filename = os.path.join(output_folder, f"graph_{safe}.jpg")

    plt.figure(figsize=(10, 5))
    plt.plot(x_values, idle_values, marker='o', linestyle='-', color='b',
             label=f"{search_string} %")

    if include_cpu_load and cpu_load_values:
        plt.plot(x_values, cpu_load_values, marker='s', linestyle='--', color='r',
                 label="CPU Load %")
        for i, val in enumerate(cpu_load_values):
            if val > 80:
                plt.plot(x_values[i], val, 'rx', markersize=10)

    min_idle = min(idle_values); max_idle = max(idle_values)
    avg_idle = sum(idle_values) / len(idle_values)

    all_vals = idle_values + (cpu_load_values if include_cpu_load and cpu_load_values else [])
    min_y    = min(all_vals)
    y_range  = max(all_vals) - min_y
    bottom_y = min_y - (y_range * 0.15)
    left_x   = x_values[0]  - (max(x_values) * 0.05)
    right_x  = x_values[-1] + (max(x_values) * 0.05)

    stats_idle = f"Idle Min: {min_idle:.2f}%\nIdle Max: {max_idle:.2f}%\nIdle Avg: {avg_idle:.2f}%"
    plt.text(left_x, bottom_y, stats_idle, fontsize=10, va='top', ha='left',
             bbox=dict(boxstyle='round,pad=0.4', edgecolor='black', facecolor='white'))

    if include_cpu_load and cpu_load_values:
        min_cpu = min(cpu_load_values); max_cpu = max(cpu_load_values)
        avg_cpu = sum(cpu_load_values) / len(cpu_load_values)
        stats_cpu = f"CPU Min: {min_cpu:.2f}%\nCPU Max: {max_cpu:.2f}%\nCPU Avg: {avg_cpu:.2f}%"
        plt.text(right_x, bottom_y, stats_cpu, fontsize=10, va='top', ha='right',
                 bbox=dict(boxstyle='round,pad=0.4', edgecolor='black', facecolor='white'))

    plt.xlabel(xlabel); plt.ylabel(ylabel)
    plt.title(f"{title} - {search_string}")
    plt.legend(); plt.grid(True)

    if show_labels:
        for i, v in enumerate(idle_values):
            plt.text(x_values[i], v, f"{v:.2f}", fontsize=9, ha='right', va='bottom', color='blue')
        if include_cpu_load and cpu_load_values:
            for i, v in enumerate(cpu_load_values):
                plt.text(x_values[i], v, f"{v:.2f}", fontsize=9, ha='right', va='top', color='red')

    plt.savefig(graph_filename, format='jpg', bbox_inches='tight')
    plt.close()
    return graph_filename


def generate_html_report(output_folder, summary_results):
    html_filename = os.path.join(output_folder, "CPU_Load_SW_Test_Report.html")
    image_files   = sorted(f for f in os.listdir(output_folder) if f.endswith(".jpg"))

    with open(html_filename, "w") as f:
        f.write("""<html><head><title>CPU Load Report</title><style>
            body{font-family:Arial,sans-serif;margin:20px}
            .summary-table{width:100%;border-collapse:collapse;margin-bottom:20px}
            .summary-table th,.summary-table td{border:1px solid #ccc;padding:8px;text-align:center}
            .fail{background:#f8d7da;color:#721c24}.pass{background:#d4edda;color:#155724}
            .grid-container{display:grid;grid-template-columns:repeat(auto-fit,minmax(500px,1fr));gap:10px}
            .grid-container img{width:100%;border:1px solid #ddd;border-radius:5px;padding:5px;background:#f9f9f9}
        </style></head><body><h2>CPU Load Summary Report</h2>
        <table class="summary-table"><tr><th>Search String</th><th>Status</th></tr>""")

        for search, status in summary_results:
            cls = "fail" if status == "FAIL" else "pass"
            f.write(f"<tr class='{cls}'><td>{search}</td><td>{status}</td></tr>")

        f.write("</table><div class='grid-container'>")
        for image in image_files:
            with open(os.path.join(output_folder, image), "rb") as img_file:
                b64 = base64.b64encode(img_file.read()).decode("utf-8")
                f.write(f'<img src="data:image/jpeg;base64,{b64}" alt="{image}">\n')
        f.write("</div></body></html>")

    return html_filename


def process_and_graph(file_path, search_strings, include_cpu_load,
                      title, xlabel, ylabel, show_labels, output_folder,
                      log_callback=None):
    summary_results = []
    global_failure  = False

    for search_string in search_strings:
        if log_callback:
            log_callback(f"Processing: {search_string}", 'blue')

        extracted_data, x_values, idle_values, cpu_load_values = [], [], [], []
        try:
            with open(file_path, "r", encoding='utf-8', errors='ignore') as file:
                iteration = 1
                for line in file:
                    val = extract_first_numeric(line, search_string)
                    if val is not None:
                        cpu = 100 - val if include_cpu_load else None
                        extracted_data.append(
                            (iteration, val, cpu) if include_cpu_load else (iteration, val))
                        x_values.append(iteration)
                        idle_values.append(val)
                        if include_cpu_load:
                            cpu_load_values.append(cpu)
                        iteration += 1

            if extracted_data:
                excel_file = save_to_excel(extracted_data, search_string, file_path,
                                           include_cpu_load, output_folder)
                graph_file = generate_graph(x_values, idle_values, cpu_load_values,
                                            search_string, file_path, include_cpu_load,
                                            title, xlabel, ylabel, show_labels, output_folder)
                if log_callback:
                    log_callback(f"Excel: {os.path.basename(excel_file)}", 'green')
                    if graph_file:
                        log_callback(f"Graph: {os.path.basename(graph_file)}", 'green')

                fail_detected = any(v > 80 for v in cpu_load_values) if include_cpu_load else False
                summary_results.append((search_string, "FAIL" if fail_detected else "PASS"))
                if fail_detected:
                    global_failure = True
            else:
                summary_results.append((search_string, "NO DATA"))
                if log_callback:
                    log_callback(f"No data found for: {search_string}", 'orange')

        except Exception as e:
            summary_results.append((search_string, f"ERROR: {e}"))
            if log_callback:
                log_callback(f"Error processing {search_string}: {e}", 'red')

    return summary_results, global_failure


# ─── Task execution ───────────────────────────────────────────────────────────
def run_trace32_core(cfg: Dict, core_name: str, cmm_script: str, log):
    trace32_path = cfg["trace32_path"]
    cmm_full     = os.path.join(cfg["cmm_directory"], cmm_script)

    if not os.path.exists(trace32_path):
        log(f"TRACE32 not found: {trace32_path}", 'red', 'ERROR'); return False
    if not os.path.exists(cmm_full):
        log(f"CMM script not found: {cmm_full}", 'red', 'ERROR'); return False

    log(f"Launching {core_name} TRACE32 with {cmm_script}")
    try:
        proc = subprocess.Popen([trace32_path, "-s", cmm_full], shell=True,
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        timeout = cfg.get("timeout", 600)
        rc = proc.wait(timeout=timeout)
        if rc == 0:
            log(f"{core_name} completed successfully.", 'green'); return True
        else:
            out, err = proc.communicate()
            if out: log(f"{core_name} stdout: {out}", 'orange')
            if err: log(f"{core_name} stderr: {err}", 'red')
            log(f"{core_name} exited with code {rc}", 'red'); return False
    except subprocess.TimeoutExpired:
        proc.terminate()
        try: proc.wait(timeout=5)
        except subprocess.TimeoutExpired: proc.kill()
        try: subprocess.run(["taskkill", "/IM", "t32marm.exe", "/F"],
                            timeout=10, capture_output=True)
        except Exception: pass
        log(f"{core_name} timed out after {timeout}s.", 'red'); return False
    except Exception as e:
        log(f"Error launching {core_name}: {e}", 'red', 'ERROR'); return False


def unlock_ecu(cfg: Dict, log):
    unlock_script = os.path.join(cfg["cmm_directory"], "J721S2_secure_unlock.cmm")
    if not os.path.exists(unlock_script):
        log(f"Unlock script not found: {unlock_script}", 'red', 'ERROR'); return False
    log(f"Unlocking ECU using: {unlock_script}")
    try:
        proc = subprocess.Popen([cfg["trace32_path"], "-s", unlock_script],
                                shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        time.sleep(10)
        if proc.poll() is None:
            proc.terminate()
            try: proc.wait(timeout=5)
            except subprocess.TimeoutExpired: proc.kill()
        log("ECU Unlock completed.", 'green'); return True
    except Exception as e:
        log(f"Error unlocking ECU: {e}", 'red', 'ERROR'); return False


def run_a72_capture(cfg: Dict, log):
    COM_PORT      = cfg["com_port"]
    BAUD_RATE     = cfg["baud_rate"]
    SERIAL_TIMEOUT= cfg.get("serial_timeout", 1)
    OUTPUT_FILE   = f"A72_CPU_Load_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
    RUN_TIME      = 10
    COMMANDS      = ["top -z 40 -t 40"]
    ansi_escape   = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')

    for attempt in range(3):
        try:
            with serial.Serial(COM_PORT, BAUD_RATE, timeout=SERIAL_TIMEOUT,
                               bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE,
                               stopbits=serial.STOPBITS_ONE) as ser:
                log(f"Connected to {COM_PORT} @ {BAUD_RATE} baud (attempt {attempt+1}/3)")
                time.sleep(2)
                ser.reset_input_buffer(); ser.reset_output_buffer()

                with open(OUTPUT_FILE, "w", encoding="utf-8") as out:
                    out.write(f"A72 CPU Load Capture - {datetime.now()}\n{'='*60}\n\n")
                    for cmd in COMMANDS:
                        log(f"Sending: {cmd.strip()}")
                        ser.reset_input_buffer(); time.sleep(0.5)
                        ser.write((cmd + "\r\n").encode()); ser.flush()
                        out.write(f"\n[{datetime.now()}] Command: {cmd.strip()}\n{'='*50}\n")
                        start = time.time(); bytes_rx = 0
                        while (time.time() - start) < RUN_TIME:
                            if ser.in_waiting > 0:
                                try:
                                    data = ser.readline().decode('utf-8', errors='replace').strip()
                                    if data:
                                        clean = ansi_escape.sub('', data)
                                        log(clean); out.write(clean + "\n")
                                        out.flush(); bytes_rx += len(data)
                                except UnicodeDecodeError as e:
                                    log(f"Decode error: {e}", 'orange'); continue
                            time.sleep(0.05)
                        log(f"Command done. {bytes_rx} bytes received.")
                        try: ser.send_break(duration=0.25)
                        except Exception: pass

            log(f"Saved to {OUTPUT_FILE}", 'green'); return True

        except serial.SerialException as e:
            log(f"Serial error (attempt {attempt+1}/3): {e}", 'red', 'ERROR')
            if attempt == 2:
                log("Max retries reached.", 'red', 'ERROR'); return False
            time.sleep(2 ** attempt)
        except Exception as e:
            log(f"Unexpected error during A72 capture: {e}", 'red', 'ERROR'); return False

    return False


def run_custom_script(task_key: str, cfg: Dict, log):
    """Execute a custom Python script by task_key."""
    custom_tasks = cfg.get('custom_tasks', {})
    if task_key not in custom_tasks:
        log(f"Custom task not found: {task_key}", 'red'); return False

    task_info    = custom_tasks[task_key]
    script_path  = task_info['file_path']
    display_name = task_info['display_name']

    # Normalize path separators
    script_path = os.path.normpath(script_path)

    if not os.path.exists(script_path):
        log(f"Script file not found: {script_path}", 'red'); return False

    log(f"Executing: {display_name}", 'blue')
    try:
        result = subprocess.run(
            [sys.executable, script_path],
            capture_output=True, text=True, timeout=300,
            cwd=os.path.dirname(script_path) or os.getcwd(),
        )
        for line in result.stdout.splitlines():
            if line.strip(): log(f"[{display_name}] {line}", 'black')
        for line in result.stderr.splitlines():
            if line.strip(): log(f"[{display_name} ERR] {line}", 'red')
        if result.returncode == 0:
            log(f"{display_name} completed.", 'green'); return True
        else:
            log(f"{display_name} failed (code {result.returncode}).", 'red'); return False
    except subprocess.TimeoutExpired:
        log(f"{display_name} timed out.", 'red'); return False
    except Exception as e:
        log(f"Error in {display_name}: {e}", 'red'); return False


def task_runner(task_name: str, cfg: Dict, log):
    try:
        if task_name == "MCU2_0":
            return run_trace32_core(cfg, "MCU2_0", "_J721S2_r5_mcu2_0_CpuLoad.cmm", log)
        elif task_name == "MCU2_1":
            return run_trace32_core(cfg, "MCU2_1", "_J721S2_r5_mcu2_1-CpuLoad.cmm", log)
        elif task_name == "MCU1_0":
            return run_trace32_core(cfg, "MCU1_0", "_J721S2_r5_mcu1_0_CpuLoad.cmm", log)
        elif task_name == "A72":
            return run_a72_capture(cfg, log)
        elif task_name == "UnlockECU":
            return unlock_ecu(cfg, log)
        elif task_name.startswith("CUSTOM_"):
            return run_custom_script(task_name, cfg, log)
        else:
            log(f"Unknown task: {task_name}", 'red', 'ERROR'); return False
    except Exception as e:
        log(f"Unexpected error in {task_name}: {e}", 'red', 'ERROR')
        log(traceback.format_exc(), 'red', 'ERROR'); return False


def process_queue(cfg: Dict, log, progress, completion_callback=None):
    global stop_requested
    try:
        with lock:
            stop_requested = False
            queue_copy = execution_queue.copy()

        if not queue_copy:
            log("[QUEUE] No tasks in queue.", 'orange')
            message_queue.put(('progress', 100)); return

        total_tasks    = sum(c for _, c in queue_copy)
        completed_tasks = 0

        log(f"[QUEUE] Starting {total_tasks} task(s)…", 'blue')

        for task_idx, (task, count) in enumerate(queue_copy):
            if stop_requested:
                log("[QUEUE] Stop requested.", 'red'); break

            log(f"[QUEUE] {task} × {count}", 'blue')

            for i in range(count):
                if stop_requested: break
                num = completed_tasks + i + 1
                message_queue.put(('progress', (num / total_tasks) * 100))
                log(f"[QUEUE] {task} instance {i+1}/{count}", 'blue')
                success = task_runner(task, cfg, log)
                log(f"[QUEUE] {task} #{i+1} {'OK' if success else 'FAILED'}",
                    'green' if success else 'red')
                if not stop_requested and i < count - 1:
                    time.sleep(1)

            completed_tasks += count
            if not stop_requested and task_idx < len(queue_copy) - 1:
                time.sleep(2)

        if stop_requested:
            log("[QUEUE] Stopped.", 'red')
            message_queue.put(('progress', 0))
        else:
            log("[QUEUE] All tasks completed.", 'green')
            message_queue.put(('progress', 100))
            with lock:
                execution_queue.clear()
    finally:
        if completion_callback:
            completion_callback()


# ─── Config Editor ────────────────────────────────────────────────────────────
class ConfigEditor:
    # Keys that should NOT be shown/edited as plain text entries
    _SKIP_KEYS = {'custom_tasks', 'graph_parser'}

    def __init__(self, parent, cfg: Dict[str, Any], on_save):
        self.parent   = parent
        self.config   = cfg
        self.on_save  = on_save
        self.entries: Dict[str, ttk.Entry] = {}

        self.window = tk.Toplevel(parent)
        self.window.title("Edit Configuration")
        self.window.geometry("640x420")
        self.window.transient(parent)
        self.window.grab_set()
        self._build()

    def _build(self):
        px, py = D('pad_x'), D('pad_y')
        main = ttk.Frame(self.window, padding=px)
        main.pack(fill=tk.BOTH, expand=True)

        canvas  = tk.Canvas(main)
        scrollbar = ttk.Scrollbar(main, orient="vertical", command=canvas.yview)
        self.sf = ttk.Frame(canvas)
        self.sf.bind("<Configure>",
                     lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0, 0), window=self.sf, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)

        row = 0
        for key, value in self.config.items():
            if key in self._SKIP_KEYS:
                continue
            ttk.Label(self.sf, text=key.replace('_', ' ').title()).grid(
                row=row, column=0, sticky="e", padx=px, pady=py)
            entry = ttk.Entry(self.sf, width=50, font=("Consolas", 9))
            entry.insert(0, str(value))
            entry.grid(row=row, column=1, padx=px, pady=py, sticky="ew")
            self.entries[key] = entry
            if any(k in key.lower() for k in ('path', 'dir', 'file')):
                ttk.Button(self.sf, text="…", width=4,
                           command=partial(self._browse, key, entry)).grid(
                    row=row, column=2, padx=2)
            row += 1

        self.sf.columnconfigure(1, weight=1)

        btn_frame = ttk.Frame(main)
        btn_frame.pack(fill=tk.X, pady=py)
        ttk.Button(btn_frame, text="Save",   command=self._save).pack(side=tk.RIGHT, padx=4)
        ttk.Button(btn_frame, text="Cancel", command=self.window.destroy).pack(side=tk.RIGHT, padx=4)

        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.window.bind("<Return>", lambda e: self._save())
        self.window.bind("<Escape>", lambda e: self.window.destroy())

    def _browse(self, key: str, entry: ttk.Entry):
        cur = entry.get()
        if any(k in key.lower() for k in ('dir', 'directory')):
            path = filedialog.askdirectory(initialdir=cur)
        else:
            path = filedialog.askopenfilename(initialdir=os.path.dirname(cur))
        if path:
            entry.delete(0, tk.END)
            entry.insert(0, path)

    def _save(self):
        new_cfg = dict(self.config)          # start with full config (preserves custom_tasks, graph_parser, etc.)
        for key, entry in self.entries.items():
            value = entry.get().strip()
            original = self.config.get(key, "")
            if isinstance(original, int):
                try: value = int(value)
                except ValueError:
                    messagebox.showerror("Invalid Value", f"'{key}' must be an integer.")
                    return
            elif isinstance(original, float):
                try: value = float(value)
                except ValueError:
                    messagebox.showerror("Invalid Value", f"'{key}' must be a number.")
                    return
            elif isinstance(original, bool):
                value = value.lower() in ('true', '1', 'yes')
            new_cfg[key] = value

        if self.on_save(new_cfg):
            self.window.destroy()


def open_config_editor(root, log_cb):
    """Open the config editor, updating global config on save."""
    cfg = load_config()

    def on_save(new_cfg):
        global config
        if save_config(new_cfg):
            config.update(new_cfg)
            log_cb("Configuration saved.", "green")
            return True
        return False

    ConfigEditor(root, cfg, on_save)


# ─── Graph Parser Tab ─────────────────────────────────────────────────────────
class GraphParserTab:
    def __init__(self, parent, log_callback):
        self.parent            = parent
        self.log_callback      = log_callback
        self.current_output_folder = None
        self.generated_graphs: list = []
        self.current_graph_index = 0
        self.graph_images: list = []
        self._build()

    def _build(self):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        main = ttk.Frame(self.parent)
        main.pack(fill=tk.BOTH, expand=True, padx=px, pady=py)

        # ── Configuration ─────────────────────────────────────────────────────
        cfg_frame = ttk.LabelFrame(main, text="Graph Parser Configuration",
                                   padding=sp)
        cfg_frame.pack(fill=tk.X, pady=(0, py))

        ttk.Label(cfg_frame, text="Input File:").grid(
            row=0, column=0, sticky="w", pady=py)
        self.input_file_var = tk.StringVar()
        ttk.Entry(cfg_frame, textvariable=self.input_file_var, width=60).grid(
            row=0, column=1, padx=px, pady=py, sticky="ew")
        ttk.Button(cfg_frame, text="Browse",
                   command=self._browse_input).grid(row=0, column=2, padx=px, pady=py)

        ttk.Label(cfg_frame, text="Output Folder:").grid(
            row=1, column=0, sticky="w", pady=py)
        self.output_folder_var = tk.StringVar(value="graph_output")
        ttk.Entry(cfg_frame, textvariable=self.output_folder_var, width=60).grid(
            row=1, column=1, padx=px, pady=py, sticky="ew")
        ttk.Button(cfg_frame, text="Browse",
                   command=self._browse_output).grid(row=1, column=2, padx=px, pady=py)

        ttk.Label(cfg_frame, text="Search Strings\n(one per line):").grid(
            row=2, column=0, sticky="nw", pady=py)
        self.search_strings_text = scrolledtext.ScrolledText(
            cfg_frame, width=40, height=3)
        self.search_strings_text.grid(row=2, column=1, columnspan=2,
                                      padx=px, pady=py, sticky="ew")
        self.search_strings_text.insert("1.0", "Idle\nCPU Load")

        # Options row
        opts = ttk.Frame(cfg_frame)
        opts.grid(row=3, column=0, columnspan=3, sticky="ew", pady=py)

        self.include_cpu_load_var = tk.BooleanVar(value=True)
        ttk.Checkbutton(opts, text="Include CPU Load Calculation",
                        variable=self.include_cpu_load_var).pack(side=tk.LEFT, padx=px)
        self.show_labels_var = tk.BooleanVar(value=True)
        ttk.Checkbutton(opts, text="Show Data Labels",
                        variable=self.show_labels_var).pack(side=tk.LEFT, padx=px)

        # Title / axis labels row
        titles = ttk.Frame(cfg_frame)
        titles.grid(row=4, column=0, columnspan=3, sticky="ew", pady=py)

        for col, (lbl, attr, default, w) in enumerate([
            ("Title:",   "title_var",  "CPU Load Analysis", 22),
            ("X Label:", "xlabel_var", "Iteration",          14),
            ("Y Label:", "ylabel_var", "Percentage (%)",     14),
        ]):
            ttk.Label(titles, text=lbl).grid(row=0, column=col*2,   sticky="w", padx=4)
            setattr(self, attr, tk.StringVar(value=default))
            ttk.Entry(titles, textvariable=getattr(self, attr), width=w).grid(
                row=0, column=col*2+1, padx=4, sticky="w")

        cfg_frame.columnconfigure(1, weight=1)

        # ── Buttons ───────────────────────────────────────────────────────────
        btn_bar = ttk.Frame(main)
        btn_bar.pack(fill=tk.X, pady=(0, py))
        ttk.Button(btn_bar, text="▶  Run Graph Parser",
                   command=self._run_parser, style="Success.TButton").pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_bar, text="Load Recent A72 File",
                   command=self._load_recent_a72).pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_bar, text="Save Settings",
                   command=self._save_config).pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_bar, text="Clear",
                   command=self._clear_output).pack(side=tk.LEFT, padx=4)

        # ── Paned output + preview ────────────────────────────────────────────
        paned = ttk.PanedWindow(main, orient=tk.VERTICAL)
        paned.pack(fill=tk.BOTH, expand=True)

        out_frame = ttk.LabelFrame(paned, text="Parser Output", padding=4)
        paned.add(out_frame, weight=1)

        self.parser_output = scrolledtext.ScrolledText(
            out_frame, wrap=tk.WORD, height=7,
            font=("Consolas", D('font_size')),
            bg=ColorScheme.SURFACE)
        self.parser_output.pack(fill=tk.BOTH, expand=True)
        for color in ('black', 'red', 'green', 'blue', 'orange'):
            self.parser_output.tag_config(color, foreground=color)

        preview_frame = ttk.LabelFrame(paned, text="Graph Preview", padding=4)
        paned.add(preview_frame, weight=3)

        nav = ttk.Frame(preview_frame)
        nav.pack(fill=tk.X, pady=(0, 4))

        ttk.Button(nav, text="◀ Prev",
                   command=self._prev_graph, width=10).pack(side=tk.LEFT, padx=2)
        self.graph_info_label = ttk.Label(nav, text="No graphs generated")
        self.graph_info_label.pack(side=tk.LEFT, padx=8, expand=True)
        ttk.Button(nav, text="Open HTML Report",
                   command=self._open_html,       width=16).pack(side=tk.RIGHT, padx=2)
        ttk.Button(nav, text="Open in Viewer",
                   command=self._open_external,   width=14).pack(side=tk.RIGHT, padx=2)
        ttk.Button(nav, text="Next ▶",
                   command=self._next_graph,       width=10).pack(side=tk.RIGHT, padx=2)

        graph_disp = ttk.Frame(preview_frame)
        graph_disp.pack(fill=tk.BOTH, expand=True)

        self.graph_canvas = tk.Canvas(
            graph_disp, bg='white',
            highlightthickness=1, highlightbackground=ColorScheme.BORDER)
        self.graph_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        v_sb = ttk.Scrollbar(graph_disp, orient=tk.VERTICAL,   command=self.graph_canvas.yview)
        v_sb.pack(side=tk.RIGHT, fill=tk.Y)
        h_sb = ttk.Scrollbar(graph_disp, orient=tk.HORIZONTAL, command=self.graph_canvas.xview)
        h_sb.pack(side=tk.BOTTOM, fill=tk.X)
        self.graph_canvas.configure(yscrollcommand=v_sb.set, xscrollcommand=h_sb.set)

        self.graph_image_frame = ttk.Frame(self.graph_canvas)
        self._canvas_window = self.graph_canvas.create_window(
            (0, 0), window=self.graph_image_frame, anchor="nw")
        self.graph_image_frame.bind("<Configure>",
            lambda e: self.graph_canvas.configure(
                scrollregion=self.graph_canvas.bbox("all")))
        self.graph_canvas.bind("<Configure>",
            lambda e: self.graph_canvas.itemconfig(self._canvas_window, width=e.width))

        self._load_config()

    # ── Config persistence ────────────────────────────────────────────────────
    def _load_config(self):
        global config
        gp = config.get('graph_parser', {})
        self.input_file_var.set(gp.get('default_input_file', ''))
        self.output_folder_var.set(gp.get('default_output_folder', 'graph_output'))
        self.include_cpu_load_var.set(gp.get('include_cpu_load', True))
        self.show_labels_var.set(gp.get('show_labels', True))
        ss = gp.get('default_search_strings', ["Idle", "CPU Load"])
        self.search_strings_text.delete("1.0", tk.END)
        self.search_strings_text.insert("1.0", "\n".join(ss))
        self.title_var.set(gp.get('graph_title',  'CPU Load Analysis'))
        self.xlabel_var.set(gp.get('graph_xlabel', 'Iteration'))
        self.ylabel_var.set(gp.get('graph_ylabel', 'Percentage (%)'))

    def _save_config(self):
        global config
        config.setdefault('graph_parser', {}).update({
            'default_input_file':    self.input_file_var.get(),
            'default_output_folder': self.output_folder_var.get(),
            'include_cpu_load':      self.include_cpu_load_var.get(),
            'show_labels':           self.show_labels_var.get(),
            'default_search_strings': [
                s.strip()
                for s in self.search_strings_text.get("1.0", tk.END).strip().splitlines()
                if s.strip()
            ],
            'graph_title':  self.title_var.get(),
            'graph_xlabel': self.xlabel_var.get(),
            'graph_ylabel': self.ylabel_var.get(),
        })
        if save_config(config):
            self._log("Graph parser settings saved.", 'green')

    # ── Browse helpers ────────────────────────────────────────────────────────
    def _browse_input(self):
        f = filedialog.askopenfilename(
            title="Select Input File",
            filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
        if f:
            self.input_file_var.set(os.path.normpath(f))

    def _browse_output(self):
        d = filedialog.askdirectory(title="Select Output Folder")
        if d:
            self.output_folder_var.set(os.path.normpath(d))

    def _load_recent_a72(self):
        try:
            files = [f for f in os.listdir(".")
                     if f.startswith("A72_CPU_Load_") and f.endswith(".txt")]
            if files:
                latest = max(files, key=lambda f: os.path.getctime(f))
                self.input_file_var.set(os.path.abspath(latest))
                self._log(f"Loaded: {latest}", 'green')
            else:
                self._log("No A72 files found in current directory.", 'orange')
        except Exception as e:
            self._log(f"Error: {e}", 'red')

    # ── Parser runner ─────────────────────────────────────────────────────────
    def _run_parser(self):
        input_file = os.path.normpath(self.input_file_var.get().strip())
        if not input_file or input_file == '.':
            messagebox.showerror("Error", "Please select an input file."); return
        if not os.path.isfile(input_file):
            messagebox.showerror("Error",
                f"Input file not found:\n{input_file}\n\n"
                "Please verify the path is correct."); return

        ss = [s.strip()
              for s in self.search_strings_text.get("1.0", tk.END).strip().splitlines()
              if s.strip()]
        if not ss:
            messagebox.showerror("Error", "Please enter at least one search string."); return

        self._save_config()
        self.parser_output.delete(1.0, tk.END)
        self._clear_preview()

        def run():
            try:
                self._log("Starting graph parser…", 'blue')
                out_folder = create_output_folder(self.output_folder_var.get())
                self.current_output_folder = out_folder
                self._log(f"Output folder: {out_folder}", 'blue')

                summary, had_failure = process_and_graph(
                    input_file, ss,
                    self.include_cpu_load_var.get(),
                    self.title_var.get(), self.xlabel_var.get(), self.ylabel_var.get(),
                    self.show_labels_var.get(), out_folder, self._log)

                html = generate_html_report(out_folder, summary)
                self._log(f"HTML report: {html}", 'green')

                self._log("\n=== SUMMARY ===", 'blue')
                for search, status in summary:
                    color = 'red' if status == 'FAIL' else 'green' if status == 'PASS' else 'orange'
                    self._log(f"  {search}: {status}", color)

                msg = "\n⚠ Some data exceeded 80% CPU load!" if had_failure else "\n✔ All tests passed."
                self._log(msg, 'red' if had_failure else 'green')
                self._log(f"Results saved to: {out_folder}", 'blue')
                self._load_graphs(out_folder)

            except Exception as e:
                self._log(f"Error: {e}", 'red')
                self._log(traceback.format_exc(), 'red')

        threading.Thread(target=run, daemon=True).start()

    # ── Graph preview ─────────────────────────────────────────────────────────
    def _load_graphs(self, folder):
        try:
            files = sorted(f for f in os.listdir(folder) if f.lower().endswith('.jpg'))
            self.generated_graphs = [os.path.join(folder, f) for f in files]
            self.graph_images = []
            for gf in self.generated_graphs:
                try: self.graph_images.append(Image.open(gf))
                except Exception as e: self._log(f"Could not load {gf}: {e}", 'red')
            if self.graph_images:
                self.current_graph_index = 0
                self._show_graph()
                self._log(f"Loaded {len(self.graph_images)} graph(s) for preview.", 'green')
            else:
                self.graph_info_label.config(text="No graphs generated")
        except Exception as e:
            self._log(f"Error loading graphs: {e}", 'red')

    def _show_graph(self):
        if not self.graph_images or self.current_graph_index >= len(self.graph_images):
            return
        for w in self.graph_image_frame.winfo_children():
            w.destroy()
        img = self.graph_images[self.current_graph_index]
        cw  = self.graph_canvas.winfo_width()
        ch  = self.graph_canvas.winfo_height()
        if cw > 1 and ch > 1:
            mw, mh = int(cw * 0.95), int(ch * 0.95)
            r = img.width / img.height
            if r > mw / mh:
                dw, dh = mw, int(mw / r)
            else:
                dh, dw = mh, int(mh * r)
            disp = img.resize((dw, dh), Image.Resampling.LANCZOS)
        else:
            disp = img.resize((600, 400), Image.Resampling.LANCZOS)
        photo = ImageTk.PhotoImage(disp)
        lbl   = ttk.Label(self.graph_image_frame, image=photo)
        lbl.image = photo
        lbl.pack(padx=4, pady=4)
        name = os.path.basename(self.generated_graphs[self.current_graph_index])
        self.graph_info_label.config(
            text=f"Graph {self.current_graph_index+1}/{len(self.generated_graphs)}: {name}")

    def _prev_graph(self):
        if len(self.generated_graphs) > 1:
            self.current_graph_index = (self.current_graph_index - 1) % len(self.generated_graphs)
            self._show_graph()

    def _next_graph(self):
        if len(self.generated_graphs) > 1:
            self.current_graph_index = (self.current_graph_index + 1) % len(self.generated_graphs)
            self._show_graph()

    def _open_external(self):
        if not self.generated_graphs:
            messagebox.showinfo("Info", "No graph to open"); return
        try: webbrowser.open(self.generated_graphs[self.current_graph_index])
        except Exception as e: messagebox.showerror("Error", f"Could not open graph: {e}")

    def _open_html(self):
        if not self.current_output_folder:
            messagebox.showinfo("Info", "No output folder available"); return
        html = os.path.join(self.current_output_folder, "CPU_Load_SW_Test_Report.html")
        if os.path.exists(html):
            try: webbrowser.open(html)
            except Exception as e: messagebox.showerror("Error", f"Could not open report: {e}")
        else:
            messagebox.showinfo("Info", "HTML report not found.")

    def _clear_preview(self):
        self.generated_graphs = []; self.graph_images = []
        self.current_graph_index = 0; self.current_output_folder = None
        for w in self.graph_image_frame.winfo_children(): w.destroy()
        self.graph_info_label.config(text="No graphs generated")

    def _clear_output(self):
        self.parser_output.delete(1.0, tk.END)
        self._clear_preview()

    def _log(self, msg, color='black'):
        ts  = datetime.now().strftime('%H:%M:%S')
        fmt = f"[{ts}] {msg}\n"
        def _upd():
            self.parser_output.insert(tk.END, fmt, color)
            self.parser_output.see(tk.END)
            self.parser_output.update_idletasks()
        self.parent.after(0, _upd)


# ─── Settings Dialog ──────────────────────────────────────────────────────────
class SettingsDialog:
    """UI customization settings — density, fonts, theme."""

    def __init__(self, parent, app):
        self.parent = parent
        self.app    = app
        self.win    = tk.Toplevel(parent)
        self.win.title("UI Settings")
        self.win.geometry("360x260")
        self.win.transient(parent)
        self.win.grab_set()
        self._build()

    def _build(self):
        px, py = 10, 6
        frame  = ttk.Frame(self.win, padding=px)
        frame.pack(fill=tk.BOTH, expand=True)

        # Density
        ttk.Label(frame, text="Layout Density:").grid(row=0, column=0, sticky="w", pady=py)
        self.density_var = tk.StringVar(value=config.get('ui_density', 'Normal'))
        cb = ttk.Combobox(frame, textvariable=self.density_var,
                          values=list(DENSITY_PRESETS.keys()), state="readonly", width=14)
        cb.grid(row=0, column=1, sticky="w", padx=8, pady=py)

        # Output font size
        ttk.Label(frame, text="Output Font Size:").grid(row=1, column=0, sticky="w", pady=py)
        self.font_size_var = tk.IntVar(value=config.get('output_font_size', 9))
        ttk.Spinbox(frame, from_=7, to=16, textvariable=self.font_size_var,
                    width=6).grid(row=1, column=1, sticky="w", padx=8, pady=py)

        # Window size
        ttk.Label(frame, text="Default Window Size:").grid(row=2, column=0, sticky="w", pady=py)
        self.win_size_var = tk.StringVar(value=config.get('window_size', '1300x800'))
        ttk.Entry(frame, textvariable=self.win_size_var, width=14).grid(
            row=2, column=1, sticky="w", padx=8, pady=py)

        # Show timestamps
        ttk.Label(frame, text="Show Timestamps:").grid(row=3, column=0, sticky="w", pady=py)
        self.ts_var = tk.BooleanVar(value=config.get('timestamps_default', True))
        ttk.Checkbutton(frame, variable=self.ts_var).grid(row=3, column=1, sticky="w", padx=8)

        # Show startup info
        ttk.Label(frame, text="Show Startup Info:").grid(row=4, column=0, sticky="w", pady=py)
        self.startup_var = tk.BooleanVar(value=config.get('show_startup_info', True))
        ttk.Checkbutton(frame, variable=self.startup_var).grid(row=4, column=1, sticky="w", padx=8)

        # Buttons
        btn_frame = ttk.Frame(self.win)
        btn_frame.pack(fill=tk.X, pady=py, padx=px)
        ttk.Button(btn_frame, text="Apply & Restart Styles",
                   command=self._apply).pack(side=tk.RIGHT, padx=4)
        ttk.Button(btn_frame, text="Cancel",
                   command=self.win.destroy).pack(side=tk.RIGHT, padx=4)

    def _apply(self):
        global config, _density, timestamp_enabled
        density_name = self.density_var.get()
        _density = DENSITY_PRESETS[density_name]

        config['ui_density']          = density_name
        config['output_font_size']    = self.font_size_var.get()
        config['window_size']         = self.win_size_var.get()
        config['timestamps_default']  = self.ts_var.get()
        config['show_startup_info']   = self.startup_var.get()
        timestamp_enabled = self.ts_var.get()

        save_config(config)
        self.app._apply_density()
        log_message(f"UI settings saved (density: {density_name})", 'green')
        self.win.destroy()


# ─── Main Application ─────────────────────────────────────────────────────────
class CPULoadApp:

    TASK_DISPLAY = {
        "MCU2_0":    "MCU Core 2_0",
        "MCU2_1":    "MCU Core 2_1",
        "MCU1_0":    "MCU Core 1_0",
        "A72":       "A72 Capture",
        "UnlockECU": "Unlock ECU",
    }

    def __init__(self, root):
        self.root = root
        self._setup_density()
        self._setup_ui()
        self._create_menu()
        self._show_startup_info()
        self._setup_bindings()
        self._start_message_loop()

    # ── Density / styles ──────────────────────────────────────────────────────
    def _setup_density(self):
        global _density
        density_name = config.get('ui_density', 'Normal')
        _density = DENSITY_PRESETS.get(density_name, DENSITY_PRESETS['Normal'])

    def _apply_density(self):
        """Re-apply style values after density change (no full rebuild)."""
        style = ttk.Style()
        style.configure("TButton",
                        padding=(D('btn_pad')[0], D('btn_pad')[1]),
                        font=("Segoe UI", D('font_size')))
        # Update output font
        if hasattr(self, 'output_text'):
            self.output_text.configure(font=("Consolas", D('font_size')))
        log_message("Density applied – restart app for full layout refresh.", 'blue')

    def _setup_styles(self):
        style = ttk.Style()
        style.theme_use('clam')

        bp = D('btn_pad')
        fs = D('font_size')

        style.configure(".", foreground="black", background=ColorScheme.BACKGROUND)
        style.configure("TFrame",        background=ColorScheme.BACKGROUND)
        style.configure("TLabel",        background=ColorScheme.BACKGROUND,
                         foreground=ColorScheme.TEXT_PRIMARY)
        style.configure("TButton",       padding=bp, relief="flat",
                         font=("Segoe UI", fs))
        style.configure("TLabelframe",   background=ColorScheme.BACKGROUND,
                         bordercolor=ColorScheme.BORDER)
        style.configure("TLabelframe.Label",
                         background=ColorScheme.BACKGROUND,
                         foreground=ColorScheme.PRIMARY,
                         font=("Segoe UI", fs, "bold"))
        style.configure("TCheckbutton",  background=ColorScheme.BACKGROUND,
                         foreground=ColorScheme.TEXT_PRIMARY)
        style.configure("TRadiobutton",  background=ColorScheme.BACKGROUND,
                         foreground=ColorScheme.TEXT_PRIMARY)
        style.configure("TEntry",        fieldbackground=ColorScheme.SURFACE,
                         foreground=ColorScheme.TEXT_PRIMARY,
                         bordercolor=ColorScheme.BORDER)
        style.configure("TCombobox",     fieldbackground=ColorScheme.SURFACE,
                         foreground=ColorScheme.TEXT_PRIMARY)
        style.configure("Horizontal.TProgressbar",
                         background=ColorScheme.ACCENT,
                         troughcolor=ColorScheme.BACKGROUND,
                         bordercolor=ColorScheme.BORDER)

        for name, bg in [("Primary", ColorScheme.PRIMARY),
                          ("Success", ColorScheme.SUCCESS),
                          ("Danger",  ColorScheme.ERROR),
                          ("Warning", ColorScheme.WARNING),
                          ("Info",    ColorScheme.INFO)]:
            style.configure(f"{name}.TButton", background=bg, foreground="white",
                             padding=bp, font=("Segoe UI", fs))
            style.map(f"{name}.TButton",
                      background=[("active", bg), ("pressed", bg)])

    # ── UI build ──────────────────────────────────────────────────────────────
    def _setup_ui(self):
        self.root.title("CPU Load Test Tool – Kevin")
        win_size = config.get('window_size', '1300x800')
        self.root.geometry(win_size)
        self.root.minsize(900, 600)
        self.root.configure(background=ColorScheme.PRIMARY)

        self._setup_styles()

        self.notebook = ttk.Notebook(self.root)
        self.notebook.pack(fill=tk.BOTH, expand=True,
                           padx=D('pad_x'), pady=D('pad_y'))

        self.main_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.main_frame, text="CPU Load Testing")

        self.graph_parser_frame = ttk.Frame(self.notebook)
        self.notebook.add(self.graph_parser_frame, text="Graph Parser")

        self._build_main_tab()
        self.graph_parser_tab = GraphParserTab(
            self.graph_parser_frame, self._relay_log)

    def _build_main_tab(self):
        px, py = D('pad_x'), D('pad_y')

        # Header
        self._create_header(self.main_frame)

        # Content container
        self.main_container = ttk.Frame(self.main_frame)
        self.main_container.pack(fill=tk.BOTH, expand=True, padx=px, pady=py)

        self._create_task_section()
        self._create_custom_task_section()
        self._create_control_section()
        self._create_main_content()

        self.timestamp_var = tk.BooleanVar(value=timestamp_enabled)

    def _create_header(self, parent):
        hh  = D('header_h')
        ts  = D('title_size')
        bg  = ColorScheme.PRIMARY

        header = tk.Frame(parent, bg=bg, height=hh)
        header.pack(fill=tk.X)
        header.pack_propagate(False)

        title_frame = tk.Frame(header, bg=bg)
        title_frame.pack(side=tk.LEFT, padx=20, pady=int(hh * 0.18))

        tk.Label(title_frame, text="CPU Load Test Tool",
                 font=("Segoe UI", ts, "bold"), bg=bg, fg="white").pack(anchor="w")
        tk.Label(title_frame, text="CPU Load Testing Application – Kevin",
                 font=("Segoe UI", 9), bg=bg, fg="#BDC3C7").pack(anchor="w")

        status_frame = tk.Frame(header, bg=bg)
        status_frame.pack(side=tk.RIGHT, padx=20)
        self.connection_status = tk.Label(status_frame, text="● Ready",
                                          font=("Segoe UI", 10, "bold"),
                                          bg=bg, fg=ColorScheme.SUCCESS)
        self.connection_status.pack(anchor="e")

    def _create_task_section(self):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        self.task_frame = ttk.LabelFrame(self.main_container,
                                         text="Available Test Tasks",
                                         padding=sp)
        self.task_frame.pack(fill=tk.X, pady=(0, py))

        grid = ttk.Frame(self.task_frame)
        grid.pack(fill=tk.X)

        tasks = [
            ("MCU2_0",    "MCU Core 2_0", "Primary.TButton"),
            ("MCU2_1",    "MCU Core 2_1", "Primary.TButton"),
            ("MCU1_0",    "MCU Core 1_0", "Primary.TButton"),
            ("A72",       "A72 Capture",  "Info.TButton"),
            ("UnlockECU", "Unlock ECU",   "Warning.TButton"),
        ]
        for i, (key, label, sty) in enumerate(tasks):
            ttk.Button(grid, text=label, command=partial(self._add_to_queue, key),
                       style=sty, width=14).grid(row=0, column=i,
                                                  padx=px, pady=py, sticky="ew")
            grid.columnconfigure(i, weight=1)

    def _create_custom_task_section(self):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        frame = ttk.LabelFrame(self.main_container, text="Custom Tasks", padding=sp)
        frame.pack(fill=tk.X, pady=(0, py))

        top = ttk.Frame(frame)
        top.pack(fill=tk.X)
        ttk.Button(top, text="+ Add Custom Task",
                   command=self._add_custom_task,
                   style="Success.TButton").pack(side=tk.LEFT, padx=px)
        ttk.Button(top, text="Clear All",
                   command=self._clear_custom_tasks,
                   style="Danger.TButton").pack(side=tk.LEFT, padx=px)

        tasks_container = ttk.Frame(frame)
        tasks_container.pack(fill=tk.X, pady=(py, 0))

        self.custom_tasks_canvas = tk.Canvas(tasks_container, height=52,
                                             bg=ColorScheme.BACKGROUND)
        sb = ttk.Scrollbar(tasks_container, orient=tk.HORIZONTAL,
                           command=self.custom_tasks_canvas.xview)
        self.custom_tasks_canvas.configure(xscrollcommand=sb.set)

        self.custom_tasks_frame = ttk.Frame(self.custom_tasks_canvas)
        self._ct_window = self.custom_tasks_canvas.create_window(
            (0, 0), window=self.custom_tasks_frame, anchor="nw")

        self.custom_tasks_canvas.pack(side=tk.TOP, fill=tk.X)
        sb.pack(side=tk.BOTTOM, fill=tk.X)

        self.custom_tasks_frame.bind("<Configure>",
            lambda e: self.custom_tasks_canvas.configure(
                scrollregion=self.custom_tasks_canvas.bbox("all")))
        self.custom_tasks_canvas.bind("<Configure>",
            lambda e: self.custom_tasks_canvas.itemconfig(self._ct_window, width=e.width))

        self._refresh_custom_tasks()

    def _create_control_section(self):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        row = ttk.Frame(self.main_container)
        row.pack(fill=tk.X, pady=(0, py))

        exec_frame = ttk.LabelFrame(row, text="Execution Controls", padding=sp)
        exec_frame.pack(side=tk.LEFT, fill=tk.X, expand=True, padx=(0, px))

        for text, cmd, sty in [
            ("▶  Start Queue", self._start_queue, "Success.TButton"),
            ("■  Stop",        self._stop_queue,  "Danger.TButton"),
            ("⏸  Pause Output",self._toggle_pause,"Warning.TButton"),
            ("Clear Output",   self._clear_output,"Info.TButton"),
        ]:
            ttk.Button(exec_frame, text=text, command=cmd, style=sty).pack(
                side=tk.LEFT, padx=2)

        util_frame = ttk.LabelFrame(row, text="Utilities", padding=sp)
        util_frame.pack(side=tk.RIGHT, fill=tk.X, expand=True, padx=(px, 0))

        for text, cmd in [
            ("Export Log",  self._export_log),
            ("Save Queue",  self._save_queue),
            ("Load Queue",  self._load_queue),
            ("Edit Config", self._edit_config),
            ("⚙ Settings",  self._open_settings),
        ]:
            ttk.Button(util_frame, text=text, command=cmd).pack(side=tk.LEFT, padx=2)

    def _create_main_content(self):
        content = ttk.Frame(self.main_container)
        content.pack(fill=tk.BOTH, expand=True)
        self._create_queue_section(content)
        self._create_output_section(content)

    def _create_queue_section(self, parent):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        container = ttk.LabelFrame(parent, text="Execution Queue", padding=sp)
        container.pack(side=tk.LEFT, fill=tk.BOTH, padx=(0, px))

        list_frame = ttk.Frame(container)
        list_frame.pack(fill=tk.BOTH, expand=True)

        self.queue_listbox = tk.Listbox(
            list_frame,
            font=("Consolas", D('font_size')),
            bg=ColorScheme.SURFACE, fg=ColorScheme.TEXT_PRIMARY,
            selectbackground=ColorScheme.ACCENT, selectforeground="white",
            relief="solid", borderwidth=1, highlightthickness=0, width=22)

        sb = ttk.Scrollbar(list_frame, orient=tk.VERTICAL,
                           command=self.queue_listbox.yview)
        self.queue_listbox.configure(yscrollcommand=sb.set)
        self.queue_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        sb.pack(side=tk.RIGHT, fill=tk.Y)

        ctrl = ttk.Frame(container)
        ctrl.pack(fill=tk.X, pady=(py, 0))
        for text, cmd in [
            ("↑ Up",      lambda: self._move_selected(-1)),
            ("↓ Down",    lambda: self._move_selected(1)),
            ("✕ Remove",  self._remove_selected),
            ("Clear All", self._clear_queue),
        ]:
            sty = "Danger.TButton" if text in ("✕ Remove", "Clear All") else "TButton"
            ttk.Button(ctrl, text=text, command=cmd, style=sty).pack(
                fill=tk.X, pady=1)

    def _create_output_section(self, parent):
        px, py = D('pad_x'), D('pad_y')
        sp     = D('section_pad')

        container = ttk.LabelFrame(parent, text="Execution Output & Monitoring",
                                   padding=sp)
        container.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True)

        ctrl_row = ttk.Frame(container)
        ctrl_row.pack(fill=tk.X, pady=(0, py))
        ttk.Button(ctrl_row, text="Clear",  command=self._clear_output).pack(side=tk.LEFT, padx=2)
        ttk.Button(ctrl_row, text="Export", command=self._export_log).pack(side=tk.LEFT, padx=2)

        self.timestamp_var = tk.BooleanVar(value=timestamp_enabled)
        ttk.Checkbutton(ctrl_row, text="Show Timestamps",
                        variable=self.timestamp_var,
                        command=self._toggle_timestamp).pack(side=tk.RIGHT, padx=2)

        text_frame = ttk.Frame(container)
        text_frame.pack(fill=tk.BOTH, expand=True)

        self.output_text = scrolledtext.ScrolledText(
            text_frame, wrap=tk.WORD,
            font=("Consolas", config.get('output_font_size', D('font_size'))),
            bg=ColorScheme.SURFACE, fg=ColorScheme.TEXT_PRIMARY,
            insertbackground=ColorScheme.ACCENT,
            selectbackground=ColorScheme.ACCENT,
            relief="solid", borderwidth=1, padx=6, pady=6)
        self.output_text.pack(fill=tk.BOTH, expand=True)

        for tag, color in {
            'black':  ColorScheme.TEXT_PRIMARY,
            'red':    ColorScheme.ERROR,
            'green':  ColorScheme.SUCCESS,
            'blue':   ColorScheme.INFO,
            'orange': ColorScheme.WARNING,
            'gray':   ColorScheme.TEXT_SECONDARY,
        }.items():
            self.output_text.tag_config(tag, foreground=color)

        self._create_status_area(container)

    def _create_status_area(self, parent):
        px, py = D('pad_x'), D('pad_y')
        area   = ttk.Frame(parent)
        area.pack(fill=tk.X, pady=(py, 0))

        self.progress_var = tk.DoubleVar()
        self.progress_bar = ttk.Progressbar(area, variable=self.progress_var,
                                            mode='determinate',
                                            style="Horizontal.TProgressbar")
        self.progress_bar.pack(fill=tk.X, pady=(0, 3))

        self.progress_label = ttk.Label(area, text="Ready",
                                        font=("Segoe UI", 9),
                                        foreground=ColorScheme.TEXT_SECONDARY)
        self.progress_label.pack(anchor="w")

        status_bar = ttk.Frame(area, relief="sunken", borderwidth=1)
        status_bar.pack(fill=tk.X)

        self.status_var = tk.StringVar(value="System Ready")
        ttk.Label(status_bar, textvariable=self.status_var,
                  font=("Segoe UI", 9),
                  foreground=ColorScheme.TEXT_SECONDARY).pack(side=tk.LEFT, padx=5, pady=2)

        self.time_var = tk.StringVar()
        ttk.Label(status_bar, textvariable=self.time_var,
                  font=("Segoe UI", 9),
                  foreground=ColorScheme.TEXT_SECONDARY).pack(side=tk.RIGHT, padx=5, pady=2)
        self._tick_clock()

    def _tick_clock(self):
        self.time_var.set(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        self.root.after(1000, self._tick_clock)

    # ── Menu ──────────────────────────────────────────────────────────────────
    def _create_menu(self):
        menubar = tk.Menu(self.root)
        self.root.config(menu=menubar)

        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="Export Log",  command=self._export_log)
        file_menu.add_command(label="Save Queue",  command=self._save_queue)
        file_menu.add_command(label="Load Queue",  command=self._load_queue)
        file_menu.add_separator()
        file_menu.add_command(label="Exit",        command=self.root.quit)

        view_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="View", menu=view_menu)
        view_menu.add_command(label="Clear Output", command=self._clear_output)

        tools_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Tools", menu=tools_menu)
        tools_menu.add_command(label="Edit Configuration", command=self._edit_config)
        tools_menu.add_command(label="UI Settings",        command=self._open_settings)
        tools_menu.add_command(label="Clear Custom Tasks", command=self._clear_custom_tasks)
        tools_menu.add_separator()
        tools_menu.add_command(label="Unlock ECU", command=lambda: self._add_to_queue("UnlockECU"))

        help_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Help", menu=help_menu)
        help_menu.add_command(label="User Guide",  command=self._show_user_guide)
        help_menu.add_command(label="Quick Start", command=self._show_quick_start)
        help_menu.add_separator()
        help_menu.add_command(label="About",       command=self._show_about)

    def _setup_bindings(self):
        self.root.bind('<Control-s>', lambda e: self._start_queue())
        self.root.bind('<Control-q>', lambda e: self._stop_queue())
        self.root.bind('<Control-e>', lambda e: self._export_log())
        self.root.bind('<Control-l>', lambda e: self._clear_output())
        self.root.bind('<Delete>',    lambda e: self._remove_selected())
        self.root.bind('<F1>',        lambda e: self._show_user_guide())
        self.root.bind('<Control-h>', lambda e: self._show_quick_start())

    # ── Message loop ──────────────────────────────────────────────────────────
    def _start_message_loop(self):
        self._process_messages()

    def _process_messages(self):
        while not message_queue.empty():
            try:
                msg_type, *args = message_queue.get_nowait()
                if msg_type == 'log':
                    msg, color = args
                    if pause_output:
                        with lock:
                            pending_logs.append((msg, color))
                    else:
                        self.output_text.insert(tk.END, msg + "\n", color)
                        self.output_text.see(tk.END)
                elif msg_type == 'progress':
                    v = args[0]
                    self.progress_var.set(v)
                    if v == 0 or v >= 100:
                        lbl = "Ready" if v == 0 else "Completed"
                    else:
                        lbl = f"Processing… {v:.1f}%"
                    self.progress_label.config(text=lbl)
            except queue.Empty:
                break
        self._update_queue_stats()
        self.root.after(100, self._process_messages)

    def _update_queue_stats(self):
        n = len(execution_queue)
        total = sum(c for _, c in execution_queue)
        self.status_var.set(
            f"Queue: {n} task(s) | {total} total run(s)"
            if n else "System Ready – No active tasks")

    def _relay_log(self, msg, color='black'):
        log_message(msg, color)

    # ── Queue operations ──────────────────────────────────────────────────────
    def _add_to_queue(self, task):
        dlg = tk.Toplevel(self.root)
        dlg.title(f"Add {task}")
        dlg.geometry("280x130")
        dlg.transient(self.root)
        dlg.grab_set()
        dlg.geometry("+{}+{}".format(
            self.root.winfo_x() + 200, self.root.winfo_y() + 200))

        px, py = D('pad_x'), D('pad_y')
        ttk.Label(dlg, text="Number of times to run:").pack(pady=py+4)
        count_var = tk.IntVar(value=1)
        spin = ttk.Spinbox(dlg, from_=1, to=100, textvariable=count_var,
                           width=10, font=("Segoe UI", 10))
        spin.pack(pady=py)
        spin.select_range(0, tk.END)
        spin.focus_set()

        def confirm(event=None):
            try:
                count = count_var.get()
                if count < 1: raise ValueError
            except (ValueError, tk.TclError):
                messagebox.showerror("Invalid Input", "Please enter a valid positive number.")
                return
            with lock:
                execution_queue.append((task, count))
            display = self.TASK_DISPLAY.get(task, task)
            self.queue_listbox.insert(tk.END, f"{display} × {count}")
            dlg.destroy()

        bf = ttk.Frame(dlg); bf.pack(pady=py)
        ttk.Button(bf, text="OK",     command=confirm).pack(side=tk.LEFT, padx=4)
        ttk.Button(bf, text="Cancel", command=dlg.destroy).pack(side=tk.LEFT, padx=4)
        dlg.bind("<Return>", confirm)
        dlg.bind("<Escape>", lambda e: dlg.destroy())

    def _clear_queue(self):
        if not execution_queue:
            messagebox.showinfo("Info", "Queue is already empty."); return
        if messagebox.askyesno("Confirm", "Clear the entire queue?"):
            with lock: execution_queue.clear()
            self.queue_listbox.delete(0, tk.END)
            log_message("Queue cleared.", 'blue')

    def _remove_selected(self):
        sel = self.queue_listbox.curselection()
        if not sel:
            messagebox.showinfo("Info", "Select an item to remove."); return
        idx  = sel[0]
        text = self.queue_listbox.get(idx)
        if messagebox.askyesno("Confirm", f"Remove '{text}' from queue?"):
            with lock:
                if 0 <= idx < len(execution_queue):
                    del execution_queue[idx]
            self.queue_listbox.delete(idx)
            log_message(f"Removed: {text}", 'orange')

    def _move_selected(self, offset):
        sel = self.queue_listbox.curselection()
        if not sel: return
        idx     = sel[0]
        new_idx = idx + offset
        if new_idx < 0 or new_idx >= self.queue_listbox.size(): return
        with lock:
            if 0 <= idx < len(execution_queue) and 0 <= new_idx < len(execution_queue):
                execution_queue[idx], execution_queue[new_idx] = \
                    execution_queue[new_idx], execution_queue[idx]
        text = self.queue_listbox.get(idx)
        self.queue_listbox.delete(idx)
        self.queue_listbox.insert(new_idx, text)
        self.queue_listbox.selection_clear(0, tk.END)
        self.queue_listbox.selection_set(new_idx)
        self.queue_listbox.see(new_idx)

    def _start_queue(self):
        if not execution_queue:
            messagebox.showinfo("Info", "Execution queue is empty."); return
        with lock:
            if any(t.name == "queue_processor" for t in threading.enumerate()):
                messagebox.showinfo("Info", "Queue is already running."); return

        self.progress_var.set(0)

        def done_cb():
            self.root.after(0, lambda: self.progress_label.config(text="Completed"))

        threading.Thread(
            target=process_queue,
            args=(config, log_message, self.progress_var, done_cb),
            daemon=True, name="queue_processor").start()
        log_message("Queue execution started.", 'green')

    def _stop_queue(self):
        global stop_requested
        with lock:
            if not any(t.name == "queue_processor" for t in threading.enumerate()):
                messagebox.showinfo("Info", "No queue is currently running."); return
            stop_requested = True
        log_message("Stop requested…", 'orange')

    def _toggle_pause(self):
        global pause_output
        with lock:
            pause_output = not pause_output
            if not pause_output:
                pending = pending_logs[:]
                pending_logs.clear()
                for msg, color in pending:
                    message_queue.put(('log', msg, color))
                log_message("Output resumed.", 'green')
            else:
                log_message("Output paused – buffering messages.", 'orange')

    def _toggle_timestamp(self):
        global timestamp_enabled
        timestamp_enabled = self.timestamp_var.get()
        log_message(f"Timestamps {'enabled' if timestamp_enabled else 'disabled'}.", 'blue')

    def _save_queue(self):
        if not execution_queue:
            messagebox.showinfo("Info", "Cannot save empty queue."); return
        if safe_json_save(QUEUE_PRESET_FILE, list(execution_queue)):
            log_message(f"Queue saved ({len(execution_queue)} items).", 'green')
        else:
            log_message("Failed to save queue.", 'red')

    def _load_queue(self):
        if not os.path.exists(QUEUE_PRESET_FILE):
            messagebox.showinfo("Info", f"No saved queue found: {QUEUE_PRESET_FILE}"); return
        if execution_queue and not messagebox.askyesno(
                "Confirm", "Replace the current queue?"):
            return
        loaded = safe_json_load(QUEUE_PRESET_FILE, [])
        if not loaded:
            messagebox.showinfo("Info", "Saved queue is empty."); return
        with lock: execution_queue.clear()
        self.queue_listbox.delete(0, tk.END)
        for task, count in loaded:
            with lock: execution_queue.append((task, count))
            display = self.TASK_DISPLAY.get(task, task)
            self.queue_listbox.insert(tk.END, f"{display} × {count}")
        log_message(f"Queue loaded ({len(loaded)} items).", 'green')

    # ── Custom tasks ──────────────────────────────────────────────────────────
    def _add_custom_task(self):
        global config
        tasks = config.get('custom_tasks', {})
        if len(tasks) >= 20:
            messagebox.showwarning("Limit", "Maximum 20 custom tasks allowed."); return

        fp = filedialog.askopenfilename(
            title="Select Python Script",
            filetypes=[("Python files", "*.py"), ("All files", "*.*")],
            initialdir=os.getcwd())
        if not fp: return
        if not fp.lower().endswith('.py'):
            messagebox.showerror("Invalid File", "Please select a .py file."); return

        script_name = os.path.splitext(os.path.basename(fp))[0]
        task_key    = f"CUSTOM_{script_name.upper()}_{int(time.time())}"
        fp_norm     = os.path.normpath(fp)

        config.setdefault('custom_tasks', {})[task_key] = {
            'display_name': script_name,
            'file_path':    fp_norm,
            'added_date':   datetime.now().isoformat(),
        }
        if save_config(config):
            log_message(f"Custom task added: {script_name}", 'green')
            self._refresh_custom_tasks()
        else:
            log_message("Failed to save custom task.", 'red')

    def _refresh_custom_tasks(self):
        for w in self.custom_tasks_frame.winfo_children():
            w.destroy()

        tasks = config.get('custom_tasks', {})
        if not tasks:
            ttk.Label(self.custom_tasks_frame,
                      text="No custom tasks. Click '+ Add Custom Task' to begin.",
                      foreground=ColorScheme.TEXT_SECONDARY).pack(pady=6)
            return

        for key, info in tasks.items():
            name = info.get('display_name', key)
            fp   = info.get('file_path', '')
            exists = os.path.isfile(os.path.normpath(fp))
            display = (name[:17] + "…") if len(name) > 20 else name

            bf = ttk.Frame(self.custom_tasks_frame)
            bf.pack(side=tk.LEFT, padx=2, pady=2)

            btn = ttk.Button(bf, text=display,
                             command=partial(self._add_to_queue, key),
                             width=14,
                             style="Info.TButton" if exists else "Danger.TButton")
            btn.pack(side=tk.LEFT)
            if not exists:
                btn.configure(text=f"⚠ {display}")

            ttk.Button(bf, text="×",
                       command=partial(self._remove_custom_task, key),
                       width=3, style="Danger.TButton").pack(side=tk.LEFT, padx=(1, 0))

    def _remove_custom_task(self, key):
        global config
        info = config.get('custom_tasks', {}).get(key, {})
        name = info.get('display_name', key)
        if messagebox.askyesno("Confirm", f"Remove custom task '{name}'?"):
            config['custom_tasks'].pop(key, None)
            if save_config(config):
                log_message(f"Removed: {name}", 'orange')
                self._refresh_custom_tasks()
            else:
                log_message("Failed to save after removal.", 'red')

    def _clear_custom_tasks(self):
        global config
        tasks = config.get('custom_tasks', {})
        if not tasks:
            messagebox.showinfo("Info", "No custom tasks to clear."); return
        if messagebox.askyesno("Confirm", f"Remove all {len(tasks)} custom tasks?"):
            config['custom_tasks'] = {}
            if save_config(config):
                self._refresh_custom_tasks()
                log_message("All custom tasks cleared.", 'orange')
            else:
                log_message("Failed to save configuration.", 'red')

    # ── Output controls ───────────────────────────────────────────────────────
    def _clear_output(self):
        if messagebox.askyesno("Confirm", "Clear all output?"):
            self.output_text.delete(1.0, tk.END)

    def _export_log(self):
        filename = f"CPU_Load_Log_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
        content  = self.output_text.get(1.0, tk.END)
        if not content.strip():
            messagebox.showinfo("Info", "No log content to export."); return
        try:
            with open(filename, 'w', encoding='utf-8') as f:
                f.write(f"CPU Load Test Tool – Log Export\n{'='*50}\n"
                        f"Export Time: {datetime.now()}\n{'='*50}\n\n{content}")
            log_message(f"Log exported: {filename}", 'green')
            messagebox.showinfo("Exported", f"Log saved to:\n{filename}")
        except Exception as e:
            messagebox.showerror("Error", f"Export failed: {e}")

    # ── Config / settings ─────────────────────────────────────────────────────
    def _edit_config(self):
        open_config_editor(self.root, log_message)

    def _open_settings(self):
        SettingsDialog(self.root, self)

    # ── About / Help ──────────────────────────────────────────────────────────
    def _show_startup_info(self):
        if config.get('show_startup_info', True):
            log_message("Application started. Press F1 for the user guide.", 'green')

    def _show_about(self):
        win = tk.Toplevel(self.root)
        win.title("About"); win.geometry("480x340")
        win.resizable(False, False); win.transient(self.root); win.grab_set()

        hdr = tk.Frame(win, bg=ColorScheme.PRIMARY, height=60)
        hdr.pack(fill=tk.X); hdr.pack_propagate(False)
        tk.Label(hdr, text="CPU Load Test Tool",
                 font=("Segoe UI", 15, "bold"),
                 bg=ColorScheme.PRIMARY, fg="white").pack(pady=14)

        txt = tk.Text(win, wrap=tk.WORD, font=("Segoe UI", 10),
                      bg=ColorScheme.BACKGROUND, fg="black",
                      relief="flat", borderwidth=0, padx=12, pady=10)
        txt.pack(fill=tk.BOTH, expand=True, padx=12, pady=8)
        txt.insert(tk.END,
            "Professional CPU Load Testing Application\n\n"
            "Version: 2.0.0\nCreated by: Kevin Delong\n\n"
            "Supports multi-core CPU load testing (MCU1_0, MCU2_0, MCU2_1, A72),\n"
            "serial communication, custom script execution, queue-based testing,\n"
            "and integrated graph parsing / report generation.\n\n"
            "© Kevin . All rights reserved.")
        txt.config(state=tk.DISABLED)

        ttk.Button(win, text="Close", command=win.destroy).pack(pady=8)

    def _show_user_guide(self):
        win = tk.Toplevel(self.root)
        win.title("User Guide"); win.geometry("680x540")
        win.transient(self.root); win.grab_set()

        nb = ttk.Notebook(win)
        nb.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        tabs = {
            "Quick Start": (
                "1. CONFIGURATION\n"
                "   • Tools → Edit Configuration → set TRACE32 path & COM port\n\n"
                "2. ADD TASKS\n"
                "   • Click a task button (MCU2_0, A72, etc.) → set run count\n\n"
                "3. CUSTOM TASKS\n"
                "   • Click '+ Add Custom Task' → select a .py file\n\n"
                "4. EXECUTE\n"
                "   • Click '▶ Start Queue' → monitor the output panel\n\n"
                "5. RESULTS\n"
                "   • Export logs, use Graph Parser tab for analysis\n\n"
                "Shortcuts: F1=Guide  Ctrl+S=Start  Ctrl+Q=Stop  Ctrl+E=Export"
            ),
            "Task Types": (
                "STANDARD TASKS:\n\n"
                "• MCU2_0  – _J721S2_r5_mcu2_0_CpuLoad.cmm (TRACE32)\n"
                "• MCU2_1  – _J721S2_r5_mcu2_1-CpuLoad.cmm (TRACE32)\n"
                "• MCU1_0  – _J721S2_r5_mcu1_0_CpuLoad.cmm (TRACE32)\n"
                "• A72     – serial capture via COM port\n"
                "• UnlockECU – J721S2_secure_unlock.cmm\n\n"
                "CUSTOM TASKS:\n\n"
                "• Any .py script; output captured in real-time\n"
                "• Max 20 custom tasks\n"
                "• Scripts with missing files shown with ⚠ warning"
            ),
            "Configuration": (
                "CONFIG KEYS (cpu_load_config.json):\n\n"
                "• trace32_path    – path to t32marm.exe\n"
                "• cmm_directory   – folder containing .cmm scripts\n"
                "• cert_directory  – certificate folder\n"
                "• com_port        – serial port (e.g. COM33)\n"
                "• baud_rate       – default 115200\n"
                "• timeout         – TRACE32 timeout (seconds)\n"
                "• serial_timeout  – serial read timeout\n"
                "• ui_density      – Compact / Normal / Spacious\n\n"
                "Config is auto-backed up to cpu_load_config.json.bak on each save."
            ),
        }

        for tab_name, text in tabs.items():
            frame = ttk.Frame(nb, padding=10)
            nb.add(frame, text=tab_name)
            lbl = tk.Text(frame, wrap=tk.WORD, font=("Consolas", 9),
                          bg=ColorScheme.BACKGROUND, relief="flat",
                          borderwidth=0, padx=6, pady=6)
            lbl.insert(tk.END, text)
            lbl.config(state=tk.DISABLED)
            lbl.pack(fill=tk.BOTH, expand=True)

        ttk.Button(win, text="Close", command=win.destroy).pack(pady=8)

    def _show_quick_start(self):
        messagebox.showinfo("Quick Start",
            "1. Edit Config → set TRACE32 path & COM port\n"
            "2. Click task buttons → add to queue\n"
            "3. Click ▶ Start Queue → monitor output\n"
            "4. Use Graph Parser tab for analysis\n\n"
            "Press F1 for the full user guide.")


# ─── Entry point ──────────────────────────────────────────────────────────────
def launch_gui():
    global config
    setup_logging()
    config = load_config()

    root = tk.Tk()
    CPULoadApp(root)
    root.mainloop()


if __name__ == "__main__":
    launch_gui()
