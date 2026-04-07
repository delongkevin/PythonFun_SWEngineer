from pathlib import Path

import build


def test_build_python_candidates_excludes_missing_paths(monkeypatch):
    monkeypatch.setattr(build.sys, "executable", "/tmp/current-python")
    monkeypatch.setattr(build.sys, "platform", "linux")
    monkeypatch.setattr(build.shutil, "which", lambda name: None)
    monkeypatch.setattr(build.Path, "exists", lambda self: str(self) != "/usr/bin/python3")

    candidates = build.build_python_candidates()

    assert candidates == ["/tmp/current-python"]


def test_select_build_python_prefers_windows_runtime_python(monkeypatch):
    monkeypatch.setattr(build.sys, "platform", "win32")
    monkeypatch.setattr(build, "build_python_candidates", lambda: [r"C:\Python311\python.exe"])

    selected = build.select_build_python()

    assert selected == r"C:\Python311\python.exe"