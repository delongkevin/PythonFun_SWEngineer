@echo off
REM ============================================================
REM  build.bat – Windows convenience launcher for build.py
REM  Run from any directory; it locates build.py automatically.
REM  
REM  Usage:
REM    build.bat              - install deps and build release exe
REM    build.bat --dev        - build with console window (debug)
REM    build.bat --clean      - clean previous artifacts, then build
REM    build.bat --no-install - skip pip install step
REM ============================================================

setlocal
set SCRIPT_DIR=%~dp0

echo [build.bat] Building Automotive ECU Tester ...
python "%SCRIPT_DIR%build.py" %*

if %ERRORLEVEL% NEQ 0 (
    echo [build.bat] Build FAILED with exit code %ERRORLEVEL%.
    exit /b %ERRORLEVEL%
)
echo [build.bat] Done.
endlocal
