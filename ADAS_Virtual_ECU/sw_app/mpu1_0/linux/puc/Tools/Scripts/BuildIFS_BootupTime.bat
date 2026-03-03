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


if [%1] == [] (
  set ELF_PATH=%cd%\..\..\App\code\OS\BSP\images\
) else (
  set ELF_PATH=%1
)


@echo ###############################################
@echo Delete old QNX ifs (%ELF_PATH%\ifs-magna-ultrascale_rrs.elf)
del %ELF_PATH%\.\ifs-magna-ultrascale_rrs.elf
@echo.


@echo ###############################################
@echo Build QNX ifs
@call C:\prjtools\qnx\Toyota_EV7.0\qnxsdp-env.bat >NUL

make -C%ELF_PATH% ifs-magna-ultrascale_bootuptime.elf
@goto done


:fail
@echo ###############################################
@echo ** Failed **
@echo.

:done

@echo ###############################################
@echo Done Build QNX ifs
@echo.