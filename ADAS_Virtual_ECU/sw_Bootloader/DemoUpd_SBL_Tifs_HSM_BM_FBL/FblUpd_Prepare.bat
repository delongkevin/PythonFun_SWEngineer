@echo off
rem **********************************************************************************************************************
rem    FILE DESCRIPTION
rem  --------------------------------------------------------------------------------------------------------------------
rem    \file
rem    \brief        Prepare updater script
rem  --------------------------------------------------------------------------------------------------------------------
rem  COPYRIGHT
rem  --------------------------------------------------------------------------------------------------------------------
rem    \par Copyright
rem    \verbatim
rem    Copyright (c) 2021 by Vector Informatik GmbH.                                                 All rights reserved.
rem
rem                This software is copyright protected and proprietary to Vector Informatik GmbH.
rem                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
rem                All other rights remain with Vector Informatik GmbH.
rem    \endverbatim
rem
rem **********************************************************************************************************************

rem **********************************************************************************************************************
rem  REVISION HISTORY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Version   Date        Author  Change Id          Description
rem  --------------------------------------------------------------------------------------------------------------------
rem  01.00.00  2016-08-18  visrie  -                  First implementation
rem  01.01.00  2021-10-08  visrie  -                  Rework based on new delivery structure / usage of ScriptHelper
rem **********************************************************************************************************************
if "%1" == "" goto end

rem *****************************************************************************
rem * Prepare FBL update
rem *****************************************************************************
echo Prepare the BM update

set work_direct=.\

rem Current directory
set local_dir=%work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL

rem *** Configuration section for files and directories *************************

rem Relative root directory of the SIP
set root_dir=%local_dir%..\..\..
rem Hexview executable
set hexview_exe=C:\prjtools\HexView\hexview.exe
rem Location of new fbl hex file
REM set NEW_FBL_DIR=%local_dir%
set NEW_FBL_DIR=%work_direct%

rem Overwrite variables in case ScriptHelper is present
::if exist %local_dir%..\..\ScriptHelper.bat call %local_dir%..\..\ScriptHelper.bat
::if "%RootDir%" NEQ "" (
::   set root_dir=%RootDir%
::   set hexview_exe=%HexViewExecutable%
::)

rem *** End of configuration section ********************************************

rem Call hardware specific batch file if available
if exist FblUpd_Prepare_Hw.bat call FblUpd_Prepare_Hw.bat %1

rem Generate ini-file for HexView
@echo [C_EXPORT]            > %NEW_FBL_DIR%\%~n1.ini
@echo Decryptvalue=0       >> %NEW_FBL_DIR%\%~n1.ini
@echo Prefix=FblUpdate     >> %NEW_FBL_DIR%\%~n1.ini
@echo Decryption=0         >> %NEW_FBL_DIR%\%~n1.ini
@echo WordSize=0           >> %NEW_FBL_DIR%\%~n1.ini
@echo WordType=-1          >> %NEW_FBL_DIR%\%~n1.ini
@echo StrictAnsiC=0        >> %NEW_FBL_DIR%\%~n1.ini
@echo CreateFAR=0          >> %NEW_FBL_DIR%\%~n1.ini
@echo CreateMemmap=1       >> %NEW_FBL_DIR%\%~n1.ini
@echo CreateStruct=1       >> %NEW_FBL_DIR%\%~n1.ini
@echo MaxBlockSize=        >> %NEW_FBL_DIR%\%~n1.ini
@echo Metrowerks=0         >> %NEW_FBL_DIR%\%~n1.ini

rem Create C-File for new Bootloader before generating the Update-FBL application.
echo Start Hexview to convert new BM into C-Array.
%hexview_exe% %NEW_FBL_DIR%\%~n1%~x1 -s -e:%~n1_err.log -xc

rem Copy prepared files into source directory of Update-FBL
move %NEW_FBL_DIR%\%~n1.c %local_dir%\Source\%~n1.c
move %NEW_FBL_DIR%\%~n1.h %local_dir%\Include\%~n1.h
move %NEW_FBL_DIR%\%~n1.ini %local_dir%\%~n1.ini

Echo New BM successfully prepared
::pause
:end

