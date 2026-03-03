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

echo ========================================================================================================
echo     (safe params)
echo ========================================================================================================
@set PREV_CURDIR=%CURDIR%
@set CURDIR=%CD%

echo.
echo ========================================================================================================
echo SET parameters
echo ========================================================================================================
:: Set environment variable
call %~dp0/setenv_safertos.bat

:SKIP_TOOLS_SETUP
REM ******************************************
REM Generate build system
REM ******************************************
cd /D %WORKSPACE_DIR%
set gen=false
if not exist %BUILD_BASE_DIR%\Release\Makefile (set gen=true)
if '%gen%'=='true' ( call %CURDIR%/generate_buildsys.bat %CURDIR%/setenv_safertos.bat)
echo.

REM Check for build system
if not exist %BUILD_BASE_DIR%\Debug\Makefile     ( echo ERROR in Build System Generation & echo. & goto EXIT_ERR)
if not exist %BUILD_BASE_DIR%\Release\Makefile   ( echo ERROR in Build System Generation & echo. & goto EXIT_ERR)

if "%1"=="rel" (
mingw32-make -C%BUILD_BASE_DIR%\Release
) else (
mingw32-make -C%BUILD_BASE_DIR%\Debug
)

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

