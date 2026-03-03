@echo off

set BASE_DIR=%~dp0
cd /D %BASE_DIR%

echo. & echo.
echo INFO: Remove write protection of %CD%

attrib -r *.* /S
attrib -r ..\..\..\App\build\out\*.* /S

echo. & echo.
echo finished.
echo. & echo.

timeout /T 3

