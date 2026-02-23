# -*- mode: python ; coding: utf-8 -*-
# ============================================================
# PyInstaller spec for Trace32 Test Framework
#
# Build command (from Trace32_Test_Framework/ directory):
#   pyinstaller trace32_executor.spec
#
# Or use the helper script:
#   python build.py
# ============================================================

from pathlib import Path

ROOT = Path(SPECPATH)  # noqa: F821 – SPECPATH is injected by PyInstaller

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
    # Standard-library modules sometimes missed
    "logging.handlers",
    "queue",
    "threading",
    "pathlib",
    "subprocess",
    "time",
]

# ---------------------------------------------------------------------------
# Modules to exclude from the bundle to reduce size
# ---------------------------------------------------------------------------
excludes = [
    # Test frameworks – not needed at runtime
    "pytest",
    "_pytest",
    # IPython / Jupyter
    "IPython",
    "jupyter",
    "notebook",
    # Unused heavy packages
    "matplotlib",
    "scipy",
    "pandas",
    "numpy",
    "flask",
    "django",
    "aiohttp",
    "cryptography",
    "OpenSSL",
    # Unused dev tools
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
    "nntplib",
    "socketserver",
]

# ---------------------------------------------------------------------------
# Analysis step
# ---------------------------------------------------------------------------
a = Analysis(  # noqa: F821
    [str(ROOT / "Trace32_Executor.py")],
    pathex=[str(ROOT)],
    binaries=[],
    datas=[],
    hiddenimports=hidden_imports,
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=excludes,
    noarchive=False,
    optimize=1,
)

pyz = PYZ(a.pure)  # noqa: F821

# ---------------------------------------------------------------------------
# Directory-based distribution (onedir) – smaller launcher + dependency folder
# ---------------------------------------------------------------------------
exe = EXE(  # noqa: F821
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,
    name="Trace32Executor",
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)

coll = COLLECT(  # noqa: F821
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name="Trace32Executor",
)
