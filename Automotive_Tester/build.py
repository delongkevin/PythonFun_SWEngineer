"""
build.py – Offline build helper for Automotive ECU Tester
==========================================================

Usage (from the Automotive_Tester/ directory or its parent):

    python build.py              # install deps + build release exe
    python build.py --dev        # include console window for debugging
    python build.py --clean      # remove previous build artifacts first
    python build.py --no-install # skip pip install step

The finished executable is placed in:
    Automotive_Tester/dist/AutomotiveTester.exe   (Windows)
    Automotive_Tester/dist/AutomotiveTester       (Linux/macOS)
"""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
SCRIPT_DIR = Path(__file__).resolve().parent   # Automotive_Tester/
SPEC_FILE = SCRIPT_DIR / "automotive_tester.spec"
DIST_DIR = SCRIPT_DIR / "dist"
BUILD_DIR = SCRIPT_DIR / "build"

# ---------------------------------------------------------------------------
# Minimum required packages
# ---------------------------------------------------------------------------
BUILD_DEPS = [
    "pyinstaller>=6.0",
    "pyserial>=3.5",
    "Pillow>=10.0.0",
]


def run(cmd: list[str], **kwargs) -> int:
    """Run a subprocess command and return the exit code."""
    print(f"\n>>> {' '.join(str(c) for c in cmd)}")
    result = subprocess.run(cmd, **kwargs)
    return result.returncode


def install_deps() -> None:
    """Install build dependencies via pip."""
    print("\n[build.py] Installing build dependencies …")
    rc = run([sys.executable, "-m", "pip", "install", "--upgrade"] + BUILD_DEPS)
    if rc != 0:
        print("[build.py] ERROR: pip install failed.")
        sys.exit(rc)
    print("[build.py] Dependencies installed successfully.")


def clean_artifacts() -> None:
    """Remove previous dist/ and build/ directories."""
    for directory in (DIST_DIR, BUILD_DIR):
        if directory.exists():
            print(f"[build.py] Removing {directory} …")
            shutil.rmtree(directory)


def build_exe(dev: bool = False) -> None:
    """Run PyInstaller to produce the executable."""
    print("\n[build.py] Starting PyInstaller build …")

    cmd: list[str] = [
        sys.executable, "-m", "PyInstaller",
        "--noconfirm",          # overwrite existing dist without asking
        str(SPEC_FILE),
    ]

    # In dev/debug mode override the console flag from the spec
    if dev:
        cmd += ["--console"]

    rc = run(cmd, cwd=str(SCRIPT_DIR))
    if rc != 0:
        print("[build.py] ERROR: PyInstaller build failed.")
        sys.exit(rc)


def print_summary() -> None:
    """Print a summary of the built artefacts."""
    exe_name = "AutomotiveTester.exe" if sys.platform == "win32" else "AutomotiveTester"
    # onedir build: executable lives inside dist/AutomotiveTester/
    exe_path = DIST_DIR / "AutomotiveTester" / exe_name
    dist_dir = DIST_DIR / "AutomotiveTester"

    print("\n" + "=" * 60)
    if exe_path.exists():
        size_mb = exe_path.stat().st_size / (1024 * 1024)
        print("[build.py] Build SUCCESSFUL")
        print(f"  Output dir : {dist_dir}")
        print(f"  Executable : {exe_path}")
        print(f"  Launcher   : {size_mb:.1f} MB  (dependencies in _internal/)")
    else:
        print(f"[build.py] WARNING: expected output not found at {exe_path}")
    print("=" * 60)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Build Automotive ECU Tester as a standalone executable."
    )
    parser.add_argument(
        "--dev",
        action="store_true",
        help="Build with a visible console window (useful for debugging).",
    )
    parser.add_argument(
        "--clean",
        action="store_true",
        help="Remove previous build artefacts before building.",
    )
    parser.add_argument(
        "--no-install",
        action="store_true",
        dest="no_install",
        help="Skip the 'pip install' step (assumes deps are already present).",
    )
    args = parser.parse_args()

    # Change to the Automotive_Tester directory so relative paths resolve
    os.chdir(SCRIPT_DIR)

    print(f"[build.py] Working directory : {SCRIPT_DIR}")
    print(f"[build.py] Python executable : {sys.executable}")
    print(f"[build.py] Platform          : {sys.platform}")

    if args.clean:
        clean_artifacts()

    if not args.no_install:
        install_deps()

    build_exe(dev=args.dev)
    print_summary()


if __name__ == "__main__":
    main()
