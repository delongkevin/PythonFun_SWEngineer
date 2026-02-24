import tkinter as tk
from tkinter import filedialog, messagebox, ttk, scrolledtext, simpledialog
import threading
import queue
import os
import subprocess
import sys
import time

try:
    from lauterbach.trace32 import rcl as _rcl
    _TRACE32_AVAILABLE = True
except ImportError:
    _rcl = None  # type: ignore[assignment]
    _TRACE32_AVAILABLE = False

# ---------------------------------------------------------------------------
# Auto-detect T32 installation (C:\T32 or D:\T32)
# ---------------------------------------------------------------------------
_DEFAULT_DRIVES = ["C", "D"]
_BIN_SUBDIRS = [os.path.join("bin", "windows64"), os.path.join("bin", "windows"), "bin"]
_EXE_CANDIDATES = ["t32marm64.exe", "t32marm.exe", "t32mppc.exe", "t32mtc.exe"]
_CONFIG_CANDIDATES = ["config_usb3.t32", "config_usb.t32", "config.t32"]

# Package name required for RCL communication
_RCL_PACKAGE_INSTALL_NAME = "lauterbach-trace32-rcl"
_RCL_PACKAGE_IMPORT_PATH = "lauterbach.trace32.rcl"
# Seconds to wait for a user to respond to the package-install dialog.
_DIALOG_TIMEOUT_SECONDS = 60
# Maximum characters of error detail shown to the user in dialogs.
_MAX_ERROR_DETAIL_LENGTH = 400


def _find_python_with_rcl():
    """Search candidate Python executables for one that has lauterbach.trace32 installed.

    Returns the path to the first Python interpreter where the import succeeds,
    or ``None`` if none are found.
    """
    import platform
    import shutil

    # Build a prioritised candidate list: current interpreter first, then PATH,
    # then common Windows install locations.
    candidates = [sys.executable]

    path_python = shutil.which("python")
    if path_python and path_python not in candidates:
        candidates.append(path_python)
    path_python3 = shutil.which("python3")
    if path_python3 and path_python3 not in candidates:
        candidates.append(path_python3)

    if platform.system() == "Windows":
        # Enumerate version-specific launchers and common install roots
        for ver in ("313", "312", "311", "310", "39", "38"):
            major, minor = ver[0], ver[1:]
            versioned = shutil.which(f"py -{major}.{minor}")
            if versioned and versioned not in candidates:
                candidates.append(versioned)

        appdata = os.environ.get("LOCALAPPDATA", "")
        programfiles = os.environ.get("PROGRAMFILES", "C:\\Program Files")
        programfiles86 = os.environ.get("PROGRAMFILES(X86)", "C:\\Program Files (x86)")
        for root in (appdata, programfiles, programfiles86):
            if not root:
                continue
            py_root = os.path.join(root, "Programs", "Python")
            if os.path.isdir(py_root):
                for entry in sorted(os.listdir(py_root), reverse=True):
                    exe = os.path.join(py_root, entry, "python.exe")
                    if os.path.isfile(exe) and exe not in candidates:
                        candidates.append(exe)

    check_code = (
        "import sys; "
        f"import importlib.util; "
        f"sys.exit(0 if importlib.util.find_spec('{_RCL_PACKAGE_IMPORT_PATH}') is not None else 1)"
    )
    for exe in candidates:
        try:
            ret = subprocess.run(
                [exe, "-c", check_code],
                timeout=10,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            if ret.returncode == 0:
                return exe
        except Exception:  # noqa: BLE001
            continue
    return None


def _install_rcl_package(python_exe=None):
    """Attempt to install *lauterbach-trace32-rcl* via pip.

    Parameters
    ----------
    python_exe:
        Path to the Python interpreter whose pip should be used.
        Falls back to ``sys.executable`` when *None*.

    Returns
    -------
    tuple[bool, str]
        ``(success, message)`` where *message* is human-readable output or
        error text.  When a permission/access-denied error is detected,
        *success* is ``False`` and *message* starts with ``"PERMISSION_ERROR:"``.
    """
    exe = python_exe or sys.executable
    cmd = [exe, "-m", "pip", "install", "--upgrade", _RCL_PACKAGE_INSTALL_NAME]
    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=120,
        )
        combined = (result.stdout + result.stderr).strip()
        if result.returncode == 0:
            return True, combined
        lower = combined.lower()
        if any(kw in lower for kw in ("access is denied", "permissionerror",
                                      "errno 13", "permission denied")):
            return False, f"PERMISSION_ERROR:{combined}"
        return False, combined
    except subprocess.TimeoutExpired:
        return False, "pip install timed out after 120 seconds."
    except Exception as exc:  # noqa: BLE001
        return False, str(exc)


def _detect_t32_installation(drives=None):
    """Return dict with 'install_dir', 't32_exe', 'config_file' if found."""
    import platform
    if platform.system() != "Windows":
        return {}
    for drive in (drives or _DEFAULT_DRIVES):
        install_dir = f"{drive}:\\T32"
        if not os.path.isdir(install_dir):
            continue
        result = {"install_dir": install_dir}
        for sub in _BIN_SUBDIRS:
            bin_dir = os.path.join(install_dir, sub)
            if not os.path.isdir(bin_dir):
                continue
            for exe in _EXE_CANDIDATES:
                path = os.path.join(bin_dir, exe)
                if os.path.isfile(path):
                    result["t32_exe"] = path
                    break
            if "t32_exe" in result:
                break
        for cfg in _CONFIG_CANDIDATES:
            path = os.path.join(install_dir, cfg)
            if os.path.isfile(path):
                result["config_file"] = path
                break
        return result
    return {}


# Seconds to wait for the Trace32 RCL port after launching the executable.
# T32 typically needs 5-8 seconds to initialise and bind the RCL listener.
_T32_STARTUP_WAIT_SECONDS = 8
# Retry configuration for RCL connection attempts after launch.
_T32_CONNECT_MAX_RETRIES = 10
_T32_CONNECT_RETRY_INTERVAL_SECONDS = 3


def _try_connect_t32(max_retries=_T32_CONNECT_MAX_RETRIES,
                     interval=_T32_CONNECT_RETRY_INTERVAL_SECONDS,
                     status_callback=None):
    """Attempt to connect to the T32 RCL server, retrying on failure.

    Parameters
    ----------
    max_retries:
        Maximum number of connection attempts.
    interval:
        Seconds to wait between attempts.
    status_callback:
        Optional callable receiving ``(attempt, max_retries, exc)`` so callers
        can surface progress to the UI.

    Returns
    -------
    An open RCL connection object on success.

    Raises
    ------
    Exception
        The last exception raised after all retries are exhausted.
    """
    if not _TRACE32_AVAILABLE:
        raise RuntimeError("lauterbach.trace32 package is not installed")
    last_exc: Exception = RuntimeError("No connection attempted")
    for attempt in range(1, max_retries + 1):
        try:
            return _rcl.connect(node="localhost")
        except (OSError, ConnectionError) as exc:
            last_exc = exc
            if status_callback is not None:
                status_callback(attempt, max_retries, exc)
            if attempt < max_retries:
                time.sleep(interval)
        except Exception:  # noqa: BLE001 – re-raise non-network errors immediately
            raise
    raise last_exc


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
        self.dbg = None
        self._connect()

    def _connect(self):
        """Attempt to connect to the Trace32 RCL server, with retries."""
        if not _TRACE32_AVAILABLE:
            return

        def _on_retry(attempt, max_retries, exc):
            self.status_callback(
                "(init)", "CONNECTING",
                f"RCL attempt {attempt}/{max_retries} failed: {exc} – retrying…"
            )

        try:
            self.dbg = _try_connect_t32(status_callback=_on_retry)
        except Exception as exc:
            self.dbg = None
            self.status_callback("(init)", "ERROR", f"T32 connect failed: {exc}")

    def run(self):
        while True:
            try:
                script_path = self.file_queue.get(timeout=1)
                self.execute(script_path)
                self.file_queue.task_done()
            except queue.Empty:
                continue

    def execute(self, script_path):
        if self.dbg is None:
            self.status_callback(os.path.basename(script_path), "ERROR",
                                 "Trace32 not connected")
            return
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
            except Exception:
                continue
        return " | ".join(results)


class MainApp:
    def __init__(self, root):
        self.root = root
        self.settings = AppSettings()
        self.script_queue = queue.Queue()
        # Auto-detect T32 installation on startup
        self._t32_detected = _detect_t32_installation()
        self.setup_ui()

    def setup_ui(self):
        self.root.title("Automotive Test Executor & Debugger")

        # Toolbar
        toolbar = tk.Frame(self.root, bd=1, relief=tk.RAISED)
        tk.Button(toolbar, text="📂 Load CMM", command=self.add_scripts).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(toolbar, text="⚙️ Settings", command=self.open_settings).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(toolbar, text="▶ Start Queue", bg="#28a745", fg="white", command=self.start_worker).pack(side=tk.LEFT, padx=2, pady=2)
        tk.Button(toolbar, text="🔍 Detect & Launch T32", command=self.detect_and_launch_t32).pack(side=tk.LEFT, padx=2, pady=2)
        toolbar.pack(side=tk.TOP, fill=tk.X)

        # T32 status label
        install_info = self._t32_detected.get("install_dir", "Not found")
        self.t32_status = tk.Label(self.root, text=f"T32: {install_info}",
                                   anchor="w", fg="#555")
        self.t32_status.pack(fill=tk.X, padx=4)

        # Main Table
        self.tree = ttk.Treeview(self.root, columns=("File", "Status", "Telemetry"), show="headings")
        self.tree.heading("File", text="CMM Script")
        self.tree.heading("Status", text="Status / Error")
        self.tree.heading("Telemetry", text="ECU Values")
        self.tree.pack(fill="both", expand=True)

    def open_settings(self):
        # Quick popup to change variable watch list
        new_vars = simpledialog.askstring("Settings", "Enter variables to watch (comma separated):",
                                          initialvalue=",".join(self.settings.watch_variables))
        if new_vars:
            self.settings.watch_variables = [v.strip() for v in new_vars.split(",")]

    def detect_and_launch_t32(self):
        """Auto-detect T32 installation and launch it if not already running."""
        detected = _detect_t32_installation()
        if not detected:
            messagebox.showwarning("T32 Not Found",
                                   "No Trace32 installation found on C:\\T32 or D:\\T32.\n"
                                   "Please install Trace32 or configure the path manually.")
            return

        install_dir = detected.get("install_dir", "")
        exe = detected.get("t32_exe", "")
        cfg = detected.get("config_file", "")
        self.t32_status.config(
            text=f"T32: {install_dir}  |  Exe: {os.path.basename(exe) if exe else 'n/a'}  |  Config: {os.path.basename(cfg) if cfg else 'n/a'}",
            fg="#006600")

        if not exe:
            messagebox.showinfo("T32 Detected",
                                f"Installation found at {install_dir} but no executable located.\n"
                                "Start Trace32 manually and then use 'Start Queue'.")
            return

        if not _TRACE32_AVAILABLE:
            self._handle_missing_rcl_package()
            return

        def _launch_bg():
            cmd = [exe]
            if cfg and os.path.isfile(cfg):
                cmd += ["-c", cfg]
            try:
                subprocess.Popen(cmd)
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Launched – waiting for RCL…", fg="#0055aa"))
                # Give T32 a short initial settle time before the first attempt
                time.sleep(_T32_STARTUP_WAIT_SECONDS)

                def _on_retry(attempt, max_retries, exc):
                    msg = (f"T32: RCL attempt {attempt}/{max_retries} – "
                           f"retrying in {_T32_CONNECT_RETRY_INTERVAL_SECONDS}s…")
                    self.root.after(0, lambda m=msg: self.t32_status.config(
                        text=m, fg="#cc6600"))

                try:
                    dbg = _try_connect_t32(status_callback=_on_retry)
                    dbg.close()
                    self.root.after(0, lambda: self.t32_status.config(
                        text=f"T32: Ready ({install_dir})", fg="#006600"))
                    self.root.after(0, lambda: messagebox.showinfo(
                        "T32 Ready", "Trace32 started and RCL connection verified."))
                except Exception as exc:
                    err = str(exc)
                    self.root.after(0, lambda e=err: self.t32_status.config(
                        text=f"T32: RCL not reachable – {e}", fg="#cc0000"))
                    self.root.after(0, lambda e=err: messagebox.showerror(
                        "RCL Connection Failed",
                        f"Trace32 launched but could not connect to RCL after "
                        f"{_T32_CONNECT_MAX_RETRIES} attempts:\n{e}\n\n"
                        "Ensure the Trace32 config enables the RCL port "
                        "(e.g. RCL=NETASSIST, PORT=20000) and try again."))
            except Exception as exc:
                err = str(exc)
                self.root.after(0, lambda e=err: messagebox.showerror(
                    "Launch Failed", f"Could not start Trace32:\n{e}"))

        threading.Thread(target=_launch_bg, daemon=True).start()

    def _handle_missing_rcl_package(self):
        """Guide the user through installing lauterbach-trace32-rcl.

        1. Check whether any Python on this machine already has the package.
        2. If found, show a targeted "restart the app with that Python" message.
        3. If not found, offer to install automatically; handle permission errors
           by instructing the user to run the app as Administrator.
        """
        self.t32_status.config(text="T32: Checking Python environments…", fg="#cc6600")

        def _bg():
            found_python = _find_python_with_rcl()
            if found_python:
                msg = (
                    f"The lauterbach.trace32 package was found in:\n  {found_python}\n\n"
                    "This application is currently running under a different Python interpreter "
                    f"({sys.executable}) where the package is not available.\n\n"
                    "Troubleshooting options:\n"
                    f"  1. Run this application directly with the Python above:\n"
                    f"     {found_python} Trace32_Executor.py\n"
                    f"  2. Or install the package for the current interpreter:\n"
                    f"     {sys.executable} -m pip install {_RCL_PACKAGE_INSTALL_NAME}"
                )
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Package found in different Python – see dialog", fg="#cc6600"))
                self.root.after(0, lambda: messagebox.showwarning("Python Interpreter Mismatch", msg))
                return

            # Package not found anywhere – ask the user if they want to install it now
            answer = [None]

            def _ask():
                answer[0] = messagebox.askyesno(
                    "Package Not Installed",
                    f"The '{_RCL_PACKAGE_INSTALL_NAME}' package is not installed.\n\n"
                    f"Would you like to install it now using:\n"
                    f"  {sys.executable} -m pip install {_RCL_PACKAGE_INSTALL_NAME}\n\n"
                    "Click Yes to install automatically, or No for manual instructions."
                )

            self.root.after(0, _ask)
            # Poll until the dialog is dismissed
            deadline = time.time() + _DIALOG_TIMEOUT_SECONDS
            while answer[0] is None and time.time() < deadline:
                time.sleep(0.1)

            if not answer[0]:
                # User chose No – show manual instructions
                manual_msg = (
                    "To install the required package manually, open a command prompt and run:\n\n"
                    f"  {sys.executable} -m pip install {_RCL_PACKAGE_INSTALL_NAME}\n\n"
                    "If you have multiple Python versions installed, run the same command for "
                    "each Python until the install succeeds, then restart this application.\n\n"
                    "If you get a 'Permission Denied' error, open the command prompt as "
                    "Administrator and try again."
                )
                self.root.after(0, lambda: messagebox.showinfo("Manual Installation Steps", manual_msg))
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Package not installed – see instructions", fg="#cc0000"))
                return

            # Attempt automatic installation
            self.root.after(0, lambda: self.t32_status.config(
                text=f"T32: Installing {_RCL_PACKAGE_INSTALL_NAME}…", fg="#0055aa"))
            success, output = _install_rcl_package()
            if success:
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Package installed – please restart the application", fg="#006600"))
                self.root.after(0, lambda: messagebox.showinfo(
                    "Installation Successful",
                    f"'{_RCL_PACKAGE_INSTALL_NAME}' was installed successfully.\n\n"
                    "Please restart this application so the new package is loaded, "
                    "then click 'Detect & Launch T32' again."
                ))
            elif output.startswith("PERMISSION_ERROR:"):
                details = output[len("PERMISSION_ERROR:"):].strip()
                admin_msg = (
                    "Installation failed due to a permission error.\n\n"
                    "To fix this, run the application (or the installer) as Administrator:\n"
                    "  1. Close this application.\n"
                    "  2. Right-click the application icon and choose 'Run as Administrator'.\n"
                    "  3. Click 'Detect & Launch T32' again.\n\n"
                    "Alternatively, install the package manually in an elevated command prompt:\n"
                    f"  {sys.executable} -m pip install {_RCL_PACKAGE_INSTALL_NAME}\n\n"
                    f"Details: {details[:_MAX_ERROR_DETAIL_LENGTH]}"
                )
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Permission error during install – run as Admin", fg="#cc0000"))
                self.root.after(0, lambda: messagebox.showerror("Permission Error", admin_msg))
            else:
                error_msg = (
                    f"Automatic installation of '{_RCL_PACKAGE_INSTALL_NAME}' failed.\n\n"
                    "Please install it manually:\n"
                    f"  {sys.executable} -m pip install {_RCL_PACKAGE_INSTALL_NAME}\n\n"
                    "If the error persists, check your internet connection or proxy settings.\n\n"
                    f"Error details:\n{output[:_MAX_ERROR_DETAIL_LENGTH]}"
                )
                self.root.after(0, lambda: self.t32_status.config(
                    text="T32: Package install failed – see dialog", fg="#cc0000"))
                self.root.after(0, lambda: messagebox.showerror("Installation Failed", error_msg))

        threading.Thread(target=_bg, daemon=True).start()

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
