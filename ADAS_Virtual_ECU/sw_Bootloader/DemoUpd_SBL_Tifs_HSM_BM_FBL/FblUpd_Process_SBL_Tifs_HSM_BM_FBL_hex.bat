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

rem *** Configuration section for files and directories *************************

rem Hexview executable
set hexview_exe=C:\prjtools\HexView\hexview.exe
set SBL_NAND_START_ADDR=0x0
set SBL_APP_IMAGE_START=0x0
set SBL_APP_IMAGE_END=0x7FFFF

set TIFS_NAND_START_ADDR=0x80000
set TIFS_BIN_IMAGE_START=0x0
set TIFS_BIN_IMAGE_END=0x3FFFF

set HSM_BM_NAND_START_ADDR=0xC0000
set HSM_BM_APP_IMAGE_START=0x0
set HSM_BM_APP_IMAGE_END=0x1BFFFF

set FBL_NAND_START=0x280000
set FBL_BIN_START=0x0
set FBL_BIN_END=0x2FFFFF

set work_direct=%~dp0
set ERROR_LEVEL_PROCCESS=1

set INPUT_HSM_BM_IMAGE=%work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\Input\HSMBoot.signed
set INPUT_SBL_IMAGE=%work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\Input\sbl_ospi_img_mcu1_0_release.tiimage
set INPUT_TIFS_IMAGE=%work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\Input\tifs-hs-enc.bin
set INPUT_FBL_IMAGE=%work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\Input\DemoFbl.bin.signed

IF NOT EXIST  "%INPUT_SBL_IMAGE%" (echo Input file "%INPUT_SBL_IMAGE%" missing. Aborting Process to create C Source code array
exit /b %ERROR_LEVEL_PROCCESS%)

IF NOT EXIST "%INPUT_TIFS_IMAGE%" (echo Input file "%INPUT_TIFS_IMAGE%" missing. Aborting Process to create C Source code array
exit /b %ERROR_LEVEL_PROCCESS%)

IF NOT EXIST "%INPUT_HSM_BM_IMAGE%" (echo Input file "%INPUT_HSM_BM_IMAGE%" missing. Aborting Process to create C Source code array
exit /b %ERROR_LEVEL_PROCCESS%)

IF NOT EXIST "%INPUT_FBL_IMAGE%" (echo Input file "%INPUT_FBL_IMAGE%" missing. Aborting Process to create C Source code array
exit /b %ERROR_LEVEL_PROCCESS%)

set ERROR_LEVEL_PROCCESS=0

rem convert SBL appimage into hex file (NAND version)
%hexview_exe% /s /MT:%INPUT_SBL_IMAGE%;%SBL_NAND_START_ADDR%:!%SBL_APP_IMAGE_START%!-!%SBL_APP_IMAGE_END%! /XI -o L2H4060_SBL_temp.hex
%hexview_exe% /s /MT:.\L2H4060_SBL_temp.hex;/FA /AL /AD4 /XI -o  L2H4060_SBL.hex
rem convert TIFS bin into hex file (NOR version)
%hexview_exe% /s /MT:%INPUT_TIFS_IMAGE%;%TIFS_NAND_START_ADDR%:!%TIFS_BIN_IMAGE_START%!-!%TIFS_BIN_IMAGE_END%! /XI -o L2H4060_TIFS_temp.hex
%hexview_exe% /s /MT:.\L2H4060_TIFS_temp.hex;/FA /AL /AD4 /XI -o  L2H4060_TIFS.hex

rem Merge SBL and TIFS into single hex file.
%hexview_exe% /S  /XI /MO:L2H4060_SBL.hex+L2H4060_TIFS.hex;0:0x80000-0xBFFFF -o .\L2H4060_SBL_TIFS.hex
REM %hexview_exe% .\L2H4060_SBL_TIFS.hex /s /FA /AFFF /XI -o .\L2H4060_SBL_TIFS.hex

rem convert HSM+BM appimage into hex file (NAND version)
%hexview_exe% /s /MT:%INPUT_HSM_BM_IMAGE%;%HSM_BM_NAND_START_ADDR%:!%HSM_BM_APP_IMAGE_START%!-!%HSM_BM_APP_IMAGE_END%! /XI /FA /AfFF -o L2H4060_BM_temp.hex
REM %hexview_exe% L2H4060_BM_temp.hex /FP:%MAGIC_FLAG% /FR:%MODULE_PATTERN_ADDR%,0x7 /s /XI -o L2H4060_BM_temp.hex
%hexview_exe% /s /MT:.\L2H4060_BM_temp.hex;/FA /AL /AD4 /XI -o  L2H4060_BM_HSM.hex
REM %hexview_exe% L2H4060_BM_temp.hex /s /FA /AFFF /XI -o L2H4060_BM_HSM.hex


rem Merge SBL and TIFS , HSM+BM into single hex file.
%hexview_exe% /S  /XI /MO:L2H4060_SBL_TIFS.hex+L2H4060_BM_HSM.hex;0:0xC0000-0x27FFFF -o .\L2H4060_SBL_TIFS_HSM_BM.hex
REM %hexview_exe% .\L2H4060_SBL_TIFS_HSM_BM.hex /s /FA /AFFF /XI -o .\L2H4060_SBL_TIFS_HSM_BM.hex


rem convert FBL bin image into hex file (NAND version)
%hexview_exe% /s /MT:%INPUT_FBL_IMAGE%;%FBL_NAND_START%:!%FBL_BIN_START%!-!%FBL_BIN_END%! /XI /FA /AFFF -o L2H4060_FBL.hex

rem Merge SBL and TIFS , HSM+BM and FBL into single hex file.
%hexview_exe% /S  /XI /MO:L2H4060_SBL_TIFS_HSM_BM.hex+L2H4060_FBL.hex;0:0x280000-0x2FFFFF -o .\L2H4060_SBL_TIFS_HSM_BM_FBL.hex



set IMG_HEX=L2H4060_SBL_TIFS_HSM_BM_FBL.hex

rem cleanup
del L2H4060_SBL_temp.hex
del L2H4060_SBL.hex
del L2H4060_TIFS_temp.hex
del L2H4060_TIFS.hex
del L2H4060_SBL_TIFS_HSM_BM.hex
del L2H4060_FBL.hex
del L2H4060_SBL_TIFS.hex
del L2H4060_BM_temp.hex
del L2H4060_BM_HSM.hex

rem Now call FblUpd_Prepare.bat
REM call %work_direct%\..\DemoUpd_HSM_BM\FblUpd_Prepare.bat %IMG_HEX%
call %work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\FblUpd_Prepare.bat %IMG_HEX%

move %IMG_HEX%  %work_direct%\..\DemoUpd_SBL_Tifs_HSM_BM_FBL\%IMG_HEX%

REM del .\%IMG_HEX%
:end

ECHO END
exit /b %ERROR_LEVEL_PROCCESS%