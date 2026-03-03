set TOOLS_DIR=c:\prjtools
set CMAKE_EXE=%TOOLS_DIR%\cmake\ver_3.8.0\bin\cmake.exe
set QNX_HOST=%TOOLS_DIR%\qnx\ver_7.0.0\host\win64\x86_64
set QNX_TARGET=%TOOLS_DIR%\qnx\ver_7.0.0\target\qnx7
set MAKE_APP=%QNX_HOST%\usr\bin\make.exe
set BUILD_SYS="MinGW Makefiles"
set PATH=%TOOLS_DIR%\mingw32\ver_3.82.90\bin;%PATH%

rmdir /S /Q  build
mkdir build
cd build

%CMAKE_EXE% -DCMAKE_BUILD_TYPE=Release -G%BUILD_SYS% -DCMAKE_TOOLCHAIN_FILE=..\cmake\qnx.toolchain.cmake ..
%MAKE_APP%
cd ..