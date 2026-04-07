from pathlib import Path

from PyInstaller.utils.hooks import collect_data_files


project_dir = Path(SPECPATH)
datas = collect_data_files("monitor_server")


a = Analysis(
    [str(project_dir / "server.py")],
    pathex=[str(project_dir)],
    binaries=[],
    datas=datas,
    hiddenimports=["waitress", "monitor_server.state", "monitor_server.report_parser"],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
)
pyz = PYZ(a.pure)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name="SoftwareTestServer",
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=True,
)
