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
::if "%1" == "" goto end

rem *****************************************************************************
rem * Prepare FBL update
rem *****************************************************************************

rem Current directory
set local_dir=%~d0%~p0

rem *** Configuration section for files and directories *************************

rem Hexview executable
set hexview_exe=C:\prjtools\HexView\hexview.exe

cd..\
Set DEMO_FBL_HEX_PATH=%cd%\Binary\DemoFbl
Set DEMO_FBL_HEX=DemoFbl.hex

IF NOT EXIST "%DEMO_FBL_HEX_PATH%\%DEMO_FBL_HEX%" (echo Input file "%DEMO_FBL_HEX_PATH%\%DEMO_FBL_HEX%" missing. Aborting Process to create C Source code array
pause
exit /b)

copy %DEMO_FBL_HEX_PATH%\%DEMO_FBL_HEX% %local_dir%

rem Overwrite variables in case ScriptHelper is present
::if exist %local_dir%..\..\ScriptHelper.bat call %local_dir%..\..\ScriptHelper.bat
::if "%RootDir%" NEQ "" (
::   set root_dir=%RootDir%
::   set hexview_exe=%HexViewExecutable%
::)

rem Cut all content of .hex below this address space (excluding this byte)
::set LowerBound=0x970FFFFF
rem Cut all content of .hex above this address (including this byte)
::set UpperBound=0x97200000

rem *** End of configuration section ********************************************
rem cut everything out of bounds of DemoFbl
::%hexview_exe% %~n1%~x1 /CR:0x0-%LowerBound%:%UpperBound%-0xFFFFFFFF /S /XI -o %local_dir%\%~n1%~x1

rem now we should do a FA
%hexview_exe% %local_dir%\%DEMO_FBL_HEX% /s /FA /AFFF -e:%local_dir%error.txt  /XI -o %local_dir%\%DEMO_FBL_HEX%
::pause
rem Now we must move it to the ROM addresses
rem 0x1 0000 0000 + targetRomAddress - compiledRAMAddress = RamToFlashAddrOffset
set RamToFlashAddrOffset=0x6F980000

echo Translate RAM (execution) address to FLASH (storage) address
%hexview_exe% /MO:%local_dir%\%DEMO_FBL_HEX%;%RamToFlashAddrOffset% /S /XI -o %local_dir%\%DEMO_FBL_HEX%

rem Now call FblUpd_Prepare.bat
call %local_dir%/FblUpd_Prepare.bat %DEMO_FBL_HEX%
del %local_dir%\%DEMO_FBL_HEX%
:end
ECHO END
