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
@rem #    Created on: 19.03.2019                                                      #
@rem #      Author: Martin Rachor (martin.rachor@magna.com)                           #
@rem #--------------------------------------------------------------------------------#

@set ROOT_PATH=%~dp0\..\..
@set BSP_PATH=%ROOT_PATH%\App\code\OS\BSP
@set IFS_IMAGE_PATH=%BSP_PATH%\images
@set IFS_PUC_PATH=%BSP_PATH%\prebuilt\aarch64le\usr\bin\puc_app
@set PUC_PATH=%ROOT_PATH%\App\build\libs\qnx



@echo ###############################################
@echo Build 'n' Flash
@echo ROOT_Path = %ROOT_PATH%
@echo.

if [%1] == [deb] goto deb

:rel
@echo ###############################################
@echo Copy 'puc_app.out' (release) into BSP
copy %PUC_PATH%\release\puc_app.out %IFS_PUC_PATH%\puc_app.out
@echo.

goto build

:deb
@echo ###############################################
@echo Copy 'puc_app.out' (debug) into BSP
copy %PUC_PATH%\debug\puc_app.out %IFS_PUC_PATH%\puc_app.out
@echo.


:build

@call %IFS_IMAGE_PATH%\build_ifs.bat %IFS_IMAGE_PATH%

@call GenerateBootImage.bat

@call FastDeploy.bat


@echo ###############################################
@echo Finished
@echo ###############################################
@echo.