@echo off
REM ********************************************************************************************
REM  $Copyright: $
REM            MAGNA Electronics - C O N F I D E N T I A L
REM            This document in its entirety is CONFIDENTIAL and may not be
REM            disclosed, disseminated or distributed to parties outside MAGNA
REM            Electronics without written permission from MAGNA Electronics.
REM ********************************************************************************************
REM $Id: build_bsp.bat 1.1.2.1 2021/08/18 12:10:19CEST Martin Rachor (MEE_MRACHO) draft  $
REM ********************************************************************************************
REM 

echo.
echo :: %date% - %time:~0,2%:%time:~3,2%:%time:~6,2%
echo.
echo ^+-------------------------------------^+
echo ^+   Environment for Toyota PuC BSP   ^|
echo ^+-------------------------------------^+
echo.
Title Toyota PuC BSP Build

setlocal

set ORIGDIR=%~dp0
cd /D %ORIGDIR%
cd /D %CD%\..\..\..\App\code\OS\BSP
set BSP_ROOT_DIR=%CD%

set TOOLS_DIR=c:\prjtools


REM begin sourcing %TOOLS_DIR%\qnx\ver_7.0.0\qnxsdp-env.bat ----------
REM (a better solution would source the settings, but at DOS this has 
REM  the same risk as having a redundancy here - maybe a checksum of 
REM  the qnxsdp-env.bat should be compared...)
set QNX_BASE=%TOOLS_DIR%\qnx\Toyota_EV7.0

@echo on

set QNX_BASE=%QNX_BASE:\=/%
set QNX_TARGET=%QNX_BASE%/target/qnx7
set QNX_HOST=%QNX_BASE%/host/win64/x86_64

set QNX_CONFIGURATION=%USERPROFILE%/.qnx


set MAKEFLAGS=-I%QNX_TARGET%/usr/include
set PATH=%QNX_HOST%/usr/bin;%QNX_BASE%/jre/bin;%PATH%

set TMPDIR=%TMP%
REM end of sourcing -------------------------------------------------

make clean
make all

endlocal

