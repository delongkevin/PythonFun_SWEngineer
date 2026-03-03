@echo on
REM ********************************************************************************************
REM  $Copyright: $
REM            MAGNA Electronics - C O N F I D E N T I A L
REM            This document in its entirety is CONFIDENTIAL and may not be
REM            disclosed, disseminated or distributed to parties outside MAGNA
REM            Electronics without written permission from MAGNA Electronics.
REM ********************************************************************************************
REM  $Id: build_winsim.bat 1.1 2019/01/16 11:12:30CET Andreas1 Graf (andrgraf) draft  $
REM ********************************************************************************************
REM

set SOLFILE=.\build\vs10build\puc_app.sln
IF EXIST %SOLFILE% GOTO HAVE_SOL
echo ERROR - Missing solutions-file %SOLFILE%!
exit /B 1

:HAVE_SOL
set EXECUTABLE=..\..\..\App\build\libs\vs10\Debug\puc_app.out.exe
set MSBUILD=C:\Windows\Microsoft.NET\Framework64\v4.0.30319\MSBuild.exe

IF EXIST %MSBUILD% GOTO HAVE_MSBUILD
echo ERROR - Missing msbuild.exe at %MSBUILD%!
exit /B 1

:HAVE_MSBUILD
%MSBUILD% %SOLFILE%

IF EXIST %EXECUTABLE% GOTO SUCCESS
echo ERROR - Creation of the executable %EXECUTABLE% failed!
exit /B 1


:SUCCESS
echo Executable %EXECUTABLE% successfully created
EXIT /B 0

