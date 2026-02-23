# -*- mode: python ; coding: utf-8 -*-
# ============================================================
# PyInstaller spec for Automotive ECU Tester
#
# Build command (from Automotive_Tester/ directory):
#   pyinstaller automotive_tester.spec
#
# Or use the helper script:
#   python build.py
# ============================================================

from pathlib import Path

ROOT = Path(SPECPATH)  # noqa: F821 – SPECPATH is injected by PyInstaller

# ---------------------------------------------------------------------------
# Data files bundled inside the executable
# ---------------------------------------------------------------------------
datas = [
    # Default configuration
    (str(ROOT / "config.json"), "."),
    # Example scripts shipped with the app
    (str(ROOT / "scripts"), "scripts"),
    # Application icon (also embedded in the exe via the icon= parameter)
    (str(ROOT / "assets" / "icon.ico"), "assets"),
]

# ---------------------------------------------------------------------------
# Hidden imports that PyInstaller's static analyser may miss
# ---------------------------------------------------------------------------
hidden_imports = [
    # tkinter internals
    "tkinter",
    "tkinter.ttk",
    "tkinter.filedialog",
    "tkinter.messagebox",
    "tkinter.scrolledtext",
    "tkinter.simpledialog",
    "_tkinter",
    # PIL / Pillow
    "PIL",
    "PIL.Image",
    "PIL.ImageTk",
    "PIL.ImageDraw",
    # pyserial – include platform-specific backends to ensure full bundling
    "serial",
    "serial.serialutil",
    "serial.serialwin32",   # Windows serial backend
    "serial.serialposix",   # Linux / macOS serial backend
    "serial.tools",
    "serial.tools.list_ports",
    # OpenCV (optional – camera support)
    "cv2",
    # Standard-library modules sometimes missed
    "logging.handlers",
    "queue",
    "threading",
    "json",
    "pathlib",
]

# ---------------------------------------------------------------------------
# Modules to exclude from the bundle to reduce size
# ---------------------------------------------------------------------------
excludes = [
    # Test frameworks – not needed at runtime
    "pytest",
    "pytest_mock",
    "_pytest",
    # IPython / Jupyter
    "IPython",
    "jupyter",
    "notebook",
    # Matplotlib (not used)
    "matplotlib",
    # Unused scipy / pandas
    "scipy",
    "pandas",
    # Unused web frameworks
    "flask",
    "django",
    "aiohttp",
    # Unused crypto
    "cryptography",
    "OpenSSL",
    # Unused image format plugins
    "PIL.FpxImagePlugin",
    "PIL.GribStubImagePlugin",
    "PIL.Hdf5StubImagePlugin",
    "PIL.MpegImagePlugin",
    "PIL.PcdImagePlugin",
    "PIL.XVThumbImagePlugin",
    # Unused test/dev
    "unittest",
    "doctest",
    "pdb",
    "pydoc",
    "xml",
    "xmlrpc",
    "html",
    "http",
    "ftplib",
    "smtplib",
    "imaplib",
    "poplib",
    "telnetlib",
    "nntplib",
    "socketserver",
]

# ---------------------------------------------------------------------------
# Analysis step
# ---------------------------------------------------------------------------
a = Analysis(  # noqa: F821
    [str(ROOT / "main.py")],
    pathex=[str(ROOT)],
    binaries=[],
    datas=datas,
    hiddenimports=hidden_imports,
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=excludes,
    noarchive=False,
    optimize=1,  # bytecode optimisation level (removes assert statements)
)

pyz = PYZ(a.pure)  # noqa: F821

# ---------------------------------------------------------------------------
# Single-file executable
# ---------------------------------------------------------------------------
exe = EXE(  # noqa: F821
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name="AutomotiveTester",
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,   # compress if UPX is available (reduces size further)
    upx_exclude=[],
    runtime_tmpdir=None,
    console=False,             # windowed – no black terminal behind the GUI
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
    icon=str(ROOT / "assets" / "icon.ico"),
    version_file=None,
)
