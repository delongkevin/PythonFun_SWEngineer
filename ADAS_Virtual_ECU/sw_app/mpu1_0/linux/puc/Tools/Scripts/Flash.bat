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
@rem #    Created on: 21.11.2019                                                      #
@rem #        Author: Roman Berngardt (Roman.Berngardt@magna.com)                     #
@rem #--------------------------------------------------------------------------------#

@title Toyota_780B PuC flash SW stack over JTAG

@set INPUT_IMAGES_DIR=./../../App/code/OS/BSP/images
@set BOOT_IMAGE=%INPUT_IMAGES_DIR%/flashimage.bin
@set FSBL_ELF_FILE=%INPUT_IMAGES_DIR%/zynqmp_fsbl.elf

@call python flash.py --image %BOOT_IMAGE% --fsbl %FSBL_ELF_FILE%

@pause