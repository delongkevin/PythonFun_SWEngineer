@echo off

:: WORKSPACE
IF NOT DEFINED WORKSPACE_DIR (set WORKSPACE_DIR=%~dp0)

:: PACKAGER
set TOOLS_DIR=C:\prjtools
set PACKAGER_EXE=%TOOLS_DIR%\packager.exe
set PACKAGER_CONFIG=%WORKSPACE_DIR%\packager\config_package.json
set REMOTE_PACKAGER_EXE=\\magna.global\electronics\Europe\Sailauf\FBEE\30_ToolsBuildEnvironment\packager.exe

:: LOCAL TOOLS
set ODXCREATE_DIR=%WORKSPACE_DIR%\config\ODXCreate

:: PACKAGER TOOLS
set CMAKE_EXE=%TOOLS_DIR%\cmake\ver_3.16.6\bin\cmake.exe
set GIT_EXE=%TOOLS_DIR%\git\ver_1.2\bin\git.exe
set GIT_PATH=%TOOLS_DIR%\git\ver_1.2\bin
set CONAN_EXE=%TOOLS_DIR%\conan\ver_1.30.2\conan.exe
set PYTHON_EXE=%TOOLS_DIR%\python\ver_3.7.6_p0\python.exe
set 7ZIP_EXE=%TOOLS_DIR%\7zip\ver_1.0\App\7-Zip64\7z.exe
set HEXVIEW_EXE=%TOOLS_DIR%\hexview\ver_1.06.00\hexview.exe
set TASKING_DIR=%TOOLS_DIR%\tasking\ver_6.2.2\
set CCACHE_DIR=%TOOLS_DIR%\ccache\ver_3.7.9\
set QNX_DIR=%TOOLS_DIR%\qnx\ver_7.1.0
set QNX_TARGET=%QNX_DIR%\target\qnx7
  
:: HYDRA3 GLOBAL SWITCHES
set BUILD_VARIANT=qnxbuild
set BUILD_BASE_DIR=%WORKSPACE_DIR%\build\%BUILD_VARIANT%
set BUILD_SYS="MinGW Makefiles"
set BUILD_SYS_PATH=%TOOLS_DIR%\mingw32\ver_3.82.90\bin
set ME_DONOTUSE_CCACHE=1
set BUILD_MODES=Release Debug Profile

set TOOLCHAIN="%WORKSPACE_DIR%/../addons/toolchain.cmake"
set CMAKE_EXTRA=-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_RULE_MESSAGES:BOOL=ON -DCMAKE_TOOLCHAIN_FILE="%TOOLCHAIN%" -DCMAKE_SH="CMAKE_SH-NOTFOUND" -DQNX_DIR=%QNX_DIR%

:: PATH
set PATH=%BUILD_SYS_PATH%;%CCACHE_DIR%;%TASKING_DIR%\ctc\bin;%PATH%
