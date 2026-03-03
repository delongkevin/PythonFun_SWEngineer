@echo off

@rem #--------------------------------------------------------------------------------#
@rem #              __                                                                #
@rem #             //\\               (C) Copyright 2019                              #
@rem #             \\//                                                               #
@rem #                                Magna Electronics Europe GmbH & Co. OHG         #
@rem #          \\\\\ \\\\\                                                           #
@rem #        /\ \\\\\ \\\\\          Am Saegewerk 10                                 #
@rem #       //\\ \\\\\ \\\\\         63773 Goldbach, Germany                         #
@rem #      ///\\\ \\\\\ \\\\\        All rights reserved.                            #
@rem #     ////\\\\ \\\\\ \\\\\                                                       #
@rem #    /////\\\\\ \\\\\ \\\\\      http://www.magna.com                            #
@rem #                                                                                #
@rem #--------------------------------------------------------------------------------#
@rem #    MAGNA Electronics - C O N F I D E N T I A L                                 #
@rem #      This document in its entirety is CONFIDENTIAL and may not be              #
@rem #      disclosed, disseminated or distributed to parties outside MAGNA           #
@rem #      Electronics without written permission from MAGNA Electronics.            #
@rem #--------------------------------------------------------------------------------#
@rem #    Created on: 27.11.2019                                                      #
@rem #      Author: Martin Rachor (martin.rachor@magna.com)                           #
@rem #--------------------------------------------------------------------------------#

@set PREV_CURDIR=%CURDIR%
@set CURDIR=%CD%

REM -- Variant ---
@set INPUT_VARIANT_DIR=..\..\App\code\Framework\CoreLibs\variants\variants
@set INPUT_YEAR=%1
@set INPUT_WEEK=%2
@set INPUT_DAY=%3
@set INPUT_BUILD=%4

cd %INPUT_VARIANT_DIR_0%

for /d %%d in (*) do (
  "%CURDIR%\..\GDE\GenericDataEditor.exe" %CURDIR%/%INPUT_VARIANT_DIR%/%%d %INPUT_YEAR% %INPUT_WEEK% %INPUT_DAY% %INPUT_BUILD% 
)

cd %CURDIR%

@set CURDIR=%PREV_CURDIR%

REM once more variants are available, call GDE again for each variant
REM set INPUT_VARIANT_DIR_1=C:\_mks\L2H0480\KP03_ProductEngineering\40_Software\20_Construction\L2H0480_780B\PuC\App\code\Framework\CoreLibs\variants\variants\Variant1
REM GenericDataEditor.exe %INPUT_VARIANT_DIR_1%