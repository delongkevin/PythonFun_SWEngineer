@echo off
REM ********************************************************************************************
REM  $Copyright: $
REM            MAGNA Electronics - C O N F I D E N T I A L
REM            This document in its entirety is CONFIDENTIAL and may not be
REM            disclosed, disseminated or distributed to parties outside MAGNA
REM            Electronics without written permission from MAGNA Electronics.
REM ********************************************************************************************
REM $Id: build.bat 1.2.1.4 2021/08/24 13:39:16CEST Martin Rachor (MEE_MRACHO) draft  $
REM ********************************************************************************************
REM 

echo.
echo :: %date% - %time:~0,2%:%time:~3,2%:%time:~6,2%
echo.
echo ^+------------------------------------------------^+
echo ^+   Envrionment for Toyota Build Process    ^|
echo ^+------------------------------------------------^+
echo.
Title Toyota_780B PuC Build

REM ******************************************
REM     (safe params)
REM ******************************************
@set PREV_CURDIR=%CURDIR%
@set CURDIR=%~dp0

echo.
echo ========================================================================================================
echo SET parameters
echo ========================================================================================================
:: Set environment variable
call %~dp0/setenv_qnx.bat

:SKIP_TOOLS_SETUP
REM ******************************************
REM Generate build system
REM ******************************************
cd /D %WORKSPACE_DIR%
set gen=false
if not exist %BUILD_BASE_DIR%\Release\Makefile (set gen=true)
if '%gen%'=='true' ( call %CURDIR%/generate_buildsys.bat %CURDIR%/setenv_qnx.bat)
echo.

REM Check for build system
if not exist %BUILD_BASE_DIR%\Debug\Makefile     ( echo ERROR in Build System Generation & echo. & goto EXIT_ERR)
if not exist %BUILD_BASE_DIR%\Release\Makefile   ( echo ERROR in Build System Generation & echo. & goto EXIT_ERR)
if not exist %BUILD_BASE_DIR%\Profile\Makefile   ( echo ERROR in Build System Generation & echo. & goto EXIT_ERR)

REM ******************************************
REm Build
REM ******************************************
set start=%time%
set custom-make="MAKE=mingw32-make -j -l%NUMBER_OF_PROCESSORS%"

set BIN_NAME=puc_app
set BIN_EXTN=out

if "%1"=="" (echo WARNING: Parameter 1 missing. Default is "debug" build mode & set BUILD_MODE=deb) else (set BUILD_MODE=%1)
if "%2"=="" (echo WARNING: Parameter 2 missing. Default is " build all"       & set TARGET=all)     else (set TARGET=%2)


set QNX_HOST=""
if exist %QNX_DIR%/host/win64/x86_64 (set QNX_HOST=%QNX_DIR%/host/win64/x86_64)
if %QNX_HOST%==""  ( echo ERROR: QNX installation path not found & goto EXIT_ERR ) else (echo QNX_HOST: %QNX_HOST%)
set compiler="%QNX_HOST%\usr\bin\qcc.exe"

set QNX_TARGET=""
if exist %QNX_DIR%/target/qnx7 (set QNX_TARGET=%QNX_DIR%/target/qnx7)
if %QNX_TARGET%=="" ( echo ERROR: QNX installation path not found & goto EXIT_ERR ) else (echo QNX_TARGET: %QNX_TARGET%)

echo. & echo.
echo Switch to Build dir..
cd /D %WORKSPACE_DIR%
echo Build dir is %CD%
echo. & echo.


REM Get ABS Path of output dir
set OUTPUT_BASE=%CD%\..\..\..\App\build
pushd %OUTPUT_BASE%
set OUTPUT_BASE=%CD%
popd

REM Make output dir writable
if exist %OUTPUT_BASE% (attrib -r %OUTPUT_BASE%\* /s /d)
	
if "%BUILD_MODE%"=="rel" (
    set OUTPATH=%OUTPUT_BASE%\out\release
    set LIBPATH=%OUTPUT_BASE%\libs\qnx\release
    set BUILD_DIR=%BUILD_BASE_DIR%\Release
    set MODE=RELEASE
) 

if "%BUILD_MODE%"=="deb" (
    set OUTPATH=%OUTPUT_BASE%\out\debug
    set LIBPATH=%OUTPUT_BASE%\libs\qnx\debug
    set BUILD_DIR=%BUILD_BASE_DIR%\Debug
    set MODE=DEBUG
) 

if "%BUILD_MODE%"=="pro" (
    set OUTPATH=%OUTPUT_BASE%\out\profile
    set LIBPATH=%OUTPUT_BASE%\libs\qnx\profile
    set BUILD_DIR=%BUILD_BASE_DIR%\profile
    set MODE=PROFILE
)

REM Remove previous lib and output files
if exist %LIBPATH%\%BIN_NAME%.%BIN_EXTN% ( del /f /q %LIBPATH%\%BIN_NAME%.%BIN_EXTN% )
if exist %LIBPATH%\TestTarget64.%BIN_EXTN% ( del /f /q %LIBPATH%\TestTarget64.%BIN_EXTN% )
if exist %OUTPATH%\%BIN_NAME%.%BIN_EXTN% ( del /f /q %OUTPATH%\%BIN_NAME%.%BIN_EXTN% )
if exist %OUTPATH%\%BIN_NAME%.map        ( del /f /q %OUTPATH%\%BIN_NAME%.map )
if exist %OUTPATH%\TestTarget64.%BIN_EXTN% ( del /f /q %OUTPATH%\TestTarget64.%BIN_EXTN% )

REM Create the out folder if missing
if not exist %OUTPATH%\NUL (mkdir %OUTPATH%)
if not exist %LIBPATH%\NUL (mkdir %LIBPATH%)


echo. & echo.
echo INFO: Used Compiler version & echo.
%compiler% -V

echo. & echo.
echo INFO: Start %MODE% Build
cd /D %BUILD_DIR%
echo %MODE% Build dir is %CD%
echo. & echo.

if "%TARGET%"=="clean" (
    echo INFO: Clean previous build artifacts
    del /f /q %LIBPATH%\*.*
    ping 1.1.1.1 -n 1 -w 500> nul
    goto EXIT_OK
) else (
    echo INFO: Build new artifacts
)

echo. & echo.
if not "%USERNAME%"=="srv_hudsonci" (set MAKEFLAGS=sj%NUMBER_OF_PROCESSORS%)
mingw32-make %custom-make% %TARGET%
if errorlevel 1 goto EXIT_ERR

echo. & echo.

if "%TARGET%"=="all" (
    echo INFO: Test Build Results
    if exist %LIBPATH%\%BIN_NAME%.%BIN_EXTN% (
        echo INFO: Build Successful
        echo INFO: Copy binaries...
        echo.
        copy /Y /V %LIBPATH%\%BIN_NAME%.%BIN_EXTN% %OUTPATH%
        copy /Y /V %LIBPATH%\%BIN_NAME%.%BIN_EXTN%.map %OUTPATH%\%BIN_NAME%.map
        copy /Y /V %LIBPATH%\TestTarget64.%BIN_EXTN% %OUTPATH%
        echo.
        echo Files copied to: %OUTPATH%
    ) else (
    echo File missing: %LIBPATH%\%BIN_NAME%.%BIN_EXTN%
    echo ERROR: build failed. please check.
    goto EXIT_ERR
    )
)
echo. & echo.


set end=%time%
set options="tokens=1-4 delims=:.,"
for /f %options% %%a in ("%start%") do set start_h=%%a&set /a start_m=100%%b %% 100&set /a start_s=100%%c %% 100&set /a start_ms=100%%d %% 100
for /f %options% %%a in ("%end%") do set end_h=%%a&set /a end_m=100%%b %% 100&set /a end_s=100%%c %% 100&set /a end_ms=100%%d %% 100

set /a hours=%end_h%-%start_h%
set /a mins=%end_m%-%start_m%
set /a secs=%end_s%-%start_s%
set /a ms=%end_ms%-%start_ms%
if %ms% lss 0 set /a secs = %secs% - 1 & set /a ms = 100%ms%
if %secs% lss 0 set /a mins = %mins% - 1 & set /a secs = 60%secs%
if %mins% lss 0 set /a hours = %hours% - 1 & set /a mins = 60%mins%
if %hours% lss 0 set /a hours = 24%hours%
if 1%ms% lss 100 set ms=0%ms%

set /a totalsecs = %hours%*3600 + %mins%*60 + %secs%
::echo Build took %hours%:%mins%:%secs%.%ms% (%totalsecs%.%ms%s total)
echo Build took %hours%:%mins%:%secs% (%totalsecs%.%ms%s total)
echo. & echo.

cd /D %WORKSPACE_DIR%
REM dont close when started with double click
if %0 == "%~0"  pause

REM mingw32 with -j call occasionally modifies color. to reset color must be called again.
color


goto EXIT_OK


:MY_DELAY
::usage --> Call with no.of seconds

setlocal
REM Backspace Alt-08
SET BKSPC=
SET /a WAIT=%1
REM echo Received %1 and Wait will be %WAIT%	& echo %TIME% & echo %WAIT%

FOR /L %%J IN (1 1 %WAIT%) DO (
	SET/P Z=^|<NUL
	ping 1.1.1.1 -n 1 -w 250> nul
    SET/P Z=%BKSPC%<NUL
    SET/P Z=/<NUL
	ping 1.1.1.1 -n 1 -w 250> nul
    SET/P Z=%BKSPC%<NUL
    SET/P Z=-<NUL
	ping 1.1.1.1 -n 1 -w 250> nul
    SET/P Z=%BKSPC%<NUL
    SET/P Z=\<NUL
    ping 1.1.1.1 -n 1 -w 250> nul
	SET/P Z=%BKSPC%<NUL
)
SET/P Z=%BKSPC%<NUL
::echo COMPLETED


:EXIT_OK
@set CURDIR=%PREV_CURDIR%
cd /D %CURDIR%
echo 0 > build.bat.ret
endlocal
exit /B 0

:EXIT_ERR
@set CURDIR=%PREV_CURDIR%
cd /D %CURDIR%
echo 1 > build.bat.ret
endlocal
exit /B 1

