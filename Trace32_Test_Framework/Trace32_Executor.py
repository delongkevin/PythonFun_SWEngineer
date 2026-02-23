import tkinter as tk
from tkinter import filedialog, messagebox, ttk, scrolledtext
import threading
import queue
import os
import time
from lauterbach.trace32 import rcl

class AppSettings:
    def __init__(self):
        self.watch_variables = ["g_EngineRPM", "g_BatteryVoltage"]
        self.auto_retry = True

class ScriptEditor(tk.Toplevel):
    """A popup window to fix CMM scripts on the fly."""
    def __init__(self, parent, file_path, on_save_callback):
        super().__init__(parent)
        self.title(f"Debug/Edit: {os.path.basename(file_path)}")
        self.geometry("600x400")
        self.file_path = file_path
        self.on_save = on_save_callback

        self.text_area = scrolledtext.ScrolledText(self, wrap=tk.WORD, font=("Consolas", 10))
        self.text_area.pack(fill="both", expand=True)
        
        with open(file_path, 'r') as f:
            self.text_area.insert(tk.INSERT, f.read())

        tk.Button(self, text="Save & Re-run", bg="#d4edda", 
                  command=self.save_and_close).pack(fill="x")

    def save_and_close(self):
        with open(self.file_path, 'w') as f:
            f.write(self.text_area.get("1.0", tk.END))
        self.on_save(self.file_path)
        self.destroy()

class Trace32Worker(threading.Thread):
    def __init__(self, file_queue, status_callback, settings, error_callback):
        super().__init__()
        self.file_queue = file_queue
        self.status_callback = status_callback
        self.error_callback = error_callback
        self.settings = settings
        self.daemon = True
        self.dbg = rcl.connect(node="localhost")

    def run(self):
        while True:
            try:
                script_path = self.file_queue.get(timeout=1)
                self.execute(script_path)
                self.file_queue.task_done()
            except queue.Empty:
                continue

    def execute(self, script_path):
        name = os.path.basename(script_path)
        self.status_callback(name, "RUNNING", "...")
        
        try:
            self.dbg.cmm(script_path)
            error_msg = self.dbg.fnc("MESSAGE.ERROR()")
            
            if error_msg:
                self.status_callback(name, "FAILED", error_msg)
                # Trigger the UI to open the Editor for the tester
                self.error_callback(script_path)
            else:
                telemetry = self.get_telemetry()
                self.status_callback(name, "SUCCESS", telemetry)
        except Exception as e:
            self.status_callback(name, "ERROR", str(e))

    def get_telemetry(self):
        results = []
        for var in self.settings.watch_variables:
            try:
                val = self.dbg.variable.read(var).value
                results.append(f"{var}={val}")
            except: continue
        return " | ".join(results)

class MainApp:
    def __init__(self, root):
        self.root = root
        self.settings = AppSettings()
        self.script_queue = queue.Queue()
        self.setup_ui()

    def setup_ui(self):
        self.root.title("Automotive Test Executor & Debugger")
        
        # Toolbar
        toolbar = tk.Frame(self.root, bd=1, relief=tk.RAISED)
        tk.Button(toolbar, text="📂 Load CMM", command=self.add_scripts).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(toolbar, text="⚙️ Settings", command=self.open_settings).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(toolbar, text="▶ Start Queue", bg="#28a745", fg="white", command=self.start_worker).pack(side=tk.LEFT, padx=2, pady=2)
        toolbar.pack(side=tk.TOP, fill=tk.X)

        # Main Table
        self.tree = ttk.Treeview(self.root, columns=("File", "Status", "Telemetry"), show="headings")
        self.tree.heading("File", text="CMM Script")
        self.tree.heading("Status", text="Status / Error")
        self.tree.heading("Telemetry", text="ECU Values")
        self.tree.pack(fill="both", expand=True)

    def open_settings(self):
        # Quick popup to change variable watch list
        new_vars = tk.simpledialog.askstring("Settings", "Enter variables to watch (comma separated):",
                                            initialvalue=",".join(self.settings.watch_variables))
        if new_vars:
            self.settings.watch_variables = [v.strip() for v in new_vars.split(",")]

    def add_scripts(self):
        files = filedialog.askopenfilenames(filetypes=[("CMM Scripts", "*.cmm")])
        for f in files:
            self.script_queue.put(f)
            self.tree.insert("", "end", values=(os.path.basename(f), "QUEUED", ""))

    def handle_error(self, script_path):
        """Bridge the learning curve: Open editor so tester can fix and re-run."""
        self.root.after(0, lambda: ScriptEditor(self.root, script_path, self.re_queue))

    def re_queue(self, script_path):
        self.script_queue.put(script_path)
        messagebox.showinfo("Queue", "Script updated and added back to queue.")

    def start_worker(self):
        Trace32Worker(self.script_queue, self.update_ui, self.settings, self.handle_error).start()

    def update_ui(self, name, status, telemetry):
        self.root.after(0, self._sync, name, status, telemetry)

    def _sync(self, name, status, telemetry):
        for item in self.tree.get_children():
            if self.tree.item(item)["values"][0] == name:
                self.tree.item(item, values=(name, status, telemetry))

if __name__ == "__main__":
    root = tk.Tk()
    app = MainApp(root)
    root.mainloop()