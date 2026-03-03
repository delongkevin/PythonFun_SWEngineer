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
@rem #      Author: Roman Berngardt (Roman.Berngardt@magna.com)                       #
@rem #--------------------------------------------------------------------------------#

@title Toyota_780B PuC generate boot image

@rem #------------------------- Config params for the script -------------------------#

@rem set the Zynq input path (path to the Zynq Firmware files)
@set ZYNQ_INPUT_PATH=./../../App/code/OS/BSP/images

@rem set the Python path to server build
@set path=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\opt\bin

@rem set file name of the PMU Firmware file
@set PMU_FW_ELF_FILENAME=pmufw.elf

@rem set file name of the FSBL file
@set FSBL_ELF_FILENAME=zynqmp_fsbl.elf

@rem set file name of the ARM Trusted Firmware file
@set ATF_ELF_FILENAME=bl31.elf

@rem set file name of the QNX ELF image file
@set QNX_IMAGE_ELF_FILENAME=ifs-magna-ultrascale_bootuptime.elf

@rem set file name of the FPGA bit file
@set FPGA_BIT_FILENAME=./Zynq_PL.bit

@rem set boot image file name
@set BOOT_IMAGE_FILENAME=flashimage_bootuptime.bin


@rem #--------------------------------- Script body ----------------------------------#

@rem Set path to the PMU Firmware
@set SCRIPT_PARAMS=--pmu_image %ZYNQ_INPUT_PATH%/%PMU_FW_ELF_FILENAME%

@rem Set path to the FSBL
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --fsbl_image %ZYNQ_INPUT_PATH%/%FSBL_ELF_FILENAME%

@rem Set path to the ARM Trusted Firmware file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --atf_image %ZYNQ_INPUT_PATH%/%ATF_ELF_FILENAME%

@rem Set path to the QNX ELF file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --qnx_image %ZYNQ_INPUT_PATH%/%QNX_IMAGE_ELF_FILENAME%

@rem Set path to the FPGA bit file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --fpga_file %ZYNQ_INPUT_PATH%/%FPGA_BIT_FILENAME%

@rem Set path to the boot image bit file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --boot_image %ZYNQ_INPUT_PATH%/%BOOT_IMAGE_FILENAME%

@set CURDIR=%CD%
@rem call the GenerateBootImage python script 
@call python %CURDIR%\Deployment\GenerateBootImage.py %SCRIPT_PARAMS%
if %0 == "%~0"  pause

@rem #------------------------------------- EOF --------------------------------------#