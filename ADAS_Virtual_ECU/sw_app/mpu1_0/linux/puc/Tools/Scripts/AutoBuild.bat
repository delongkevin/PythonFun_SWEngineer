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
@rem #    Created on: 25.11.2019                                                      #
@rem #        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
@rem #--------------------------------------------------------------------------------#


@set PREV_CURDIR=%CURDIR%
@set CURDIR=%CD%

@set ROOT_PATH=%~dp0\..\..
@set BSP_PATH=%ROOT_PATH%/App/code/OS/BSP
@set IFS_IMAGE_PATH=%BSP_PATH%/images
@set IFS_PUC_PATH=%BSP_PATH%/prebuilt/aarch64le/usr/bin/puc_app
@set PUC_PATH=%ROOT_PATH%/App/build/libs/qnx

@copy "%PUC_PATH%\release\puc_app.out" "%IFS_PUC_PATH%\puc_app.out"

if %1==-gb ( goto gen_buildsys )
  
if %1==rel ( goto build_rel )
if %1==deb ( goto build_deb )

:gen_buildsys
@call %CURDIR%/../cmake_buildsys/app/generate_buildsys.bat 0
if %2==rel ( goto build_rel )
if %2==deb ( goto build_deb )

:build_rel
@rem build release
@call %CURDIR%/../cmake_buildsys/app/build.bat rel
@copy "%PUC_PATH%\release\puc_app.out" "%IFS_PUC_PATH%\puc_app.out"
@call %CURDIR%//BuildIFS.bat
@call %CURDIR%//GenerateBootImage.bat
goto end

:build_deb
@rem build release
@call %CURDIR%/../cmake_buildsys/app/build.bat deb
@call %CURDIR%//BuildDebugIFS.bat
@call %CURDIR%//GenerateDebugBootImage.bat
goto end

:end
if %0 == "%~0"  pause