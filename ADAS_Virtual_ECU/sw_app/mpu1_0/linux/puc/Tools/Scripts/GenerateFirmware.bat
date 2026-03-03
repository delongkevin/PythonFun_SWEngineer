@echo off

@REM #--------------------------------------------------------------------------#
@REM #              __                                                          #
@REM #             //\\               (C) Copyright 2021                        #
@REM #             \\//                                                         #
@REM #                                Magna Electronics Europe GmbH & Co. OHG   #
@REM #          \\\\\ \\\\\                                                     #
@REM #        /\ \\\\\ \\\\\          Am Saegewerk 10                           #
@REM #       //\\ \\\\\ \\\\\         63773 Goldbach, Germany                   #
@REM #      ///\\\ \\\\\ \\\\\        All rights reserved.                      #
@REM #     ////\\\\ \\\\\ \\\\\                                                 #
@REM #    /////\\\\\ \\\\\ \\\\\      http://www.magna.com                      #
@REM #                                                                          #
@REM #--------------------------------------------------------------------------#
@REM #    MAGNA Electronics - C O N F I D E N T I A L                           #
@REM #      This document in its entirety is CONFIDENTIAL and may not be        #
@REM #      disclosed, disseminated or distributed to parties outside MAGNA     #
@REM #      Electronics without written permission from MAGNA Electronics.      #
@REM #--------------------------------------------------------------------------#
@REM #    Created on: 2021-03-03                                                #
@REM #        Author: Roman Berngardt (Roman.Berngardt@magna.com)               #
@REM #--------------------------------------------------------------------------#

@REM #--------------------------------------------------------------------------#
@REM #                             CONFIG PARAMS                                #
@REM #--------------------------------------------------------------------------#

@set MAIN_TITLE=TOYOTA :: MPSoC FirmWare Generating
@set START_TIMESTAMP= :: %date% - %time:~0,2%:%time:~3,2%:%time:~6,2% ::
@set CR=@echo.
@set CURDIR=%CD%
@set CALL_FILE=Generate_FW.bat
@set CALL_PATH=%CURDIR%\MPSoC_FW_Generation\%CALL_FILE%
@set ERR_001_TEXT=ERROR: The batch file '%CALL_FILE%' is not found!
@set NTE_001_TEXT=NOTE: Please check the script global CALL_PATH variable.
@set STATUS_TEXT_FAIL=STATUS: FAIL.
@set STATUS_TEXT_DONE=STATUS: SUCCESS.

@REM #--------------------------------------------------------------------------#
@REM #                            SCRIPT BODY                                   #
@REM #--------------------------------------------------------------------------#
@title %MAIN_TITLE%

@%CR%
@echo %START_TIMESTAMP%
%CR%
@echo. ^+--------------------------------------------------------^+
@echo. ^+     Generating of the MPSoC FirmWare for Toyota ECU    ^|
@echo. ^+--------------------------------------------------------^+
@%CR%

@if not exist %CALL_PATH%   (goto ERROR_001)

@call %CALL_PATH%
@if %ERRORLEVEL% NEQ 0 (@goto EXIT_ERR)
@goto EXIT_OK

:ERROR_001
@%CR% %ERR_001_TEXT%
@%CR% %NTE_001_TEXT%
@goto EXIT_ERR

:ERROR_002
@%CR% %ERR_002_TEXT%
@%CR% %NTE_002_TEXT%
@goto EXIT_ERR

:EXIT_OK
@%CR%
@%CR% %STATUS_TEXT_DONE%
@cd /D %CURDIR%
@endlocal
@if %0 == "%~0"  pause
@exit /B 0

:EXIT_ERR
%CR%
%CR% %STATUS_TEXT_FAIL%
@cd /D %CURDIR%
@endlocal
@if %0 == "%~0" pause
@exit /B 1

@REM #--------------------------------------------------------------------------#
@REM #                                   EOF                                    #
@REM #--------------------------------------------------------------------------#
