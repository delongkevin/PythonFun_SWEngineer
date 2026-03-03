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
@rem #      Author: Roman Berngardt (Roman.Berngardt@magna.com)                       #
@rem #--------------------------------------------------------------------------------#

@rem #------------------------- Config params for the script -------------------------#

@rem set the Zynq input path (path to the Zynq Firmware files)
@set ZYNQ_INPUT_PATH=./../../App/code/OS/BSP/images

@rem set file name of the PMU Firmware file
@set PMU_FW_ELF_FILENAME=pmufw.elf

@rem set file name of the FSBL file
@set FSBL_ELF_FILENAME=zynqmp_fsbl.elf

@rem set file name of the ARM Trusted Firmware file
@set ATF_ELF_FILENAME=bl31.elf

@rem set file name of the QNX ELF image file
@set QNX_IMAGE_ELF_FILENAME=ifs-magna-ultrascale.elf

@rem set file name of the HDF file
@set HDF_FILENAME=./Zynq_HDF.hdf

@rem set file name of the FPGA bit file
@set FPGA_BIT_FILENAME=./Zynq_PL.bit


@rem #--------------------------------- Script body ----------------------------------#

@rem Set loading mode (i.e. mode:JTAG)
@set SCRIPT_PARAMS=--mode
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% JTAG

@rem Set path to the PMU Firmware
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --pmu_image %ZYNQ_INPUT_PATH%/%PMU_FW_ELF_FILENAME%

@rem Set path to the FSBL
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --fsbl_image %ZYNQ_INPUT_PATH%/%FSBL_ELF_FILENAME%

@rem Set path to the ARM Trusted Firmware file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --atf_image %ZYNQ_INPUT_PATH%/%ATF_ELF_FILENAME%

@rem Set path to the QNX ELF file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --qnx_image %ZYNQ_INPUT_PATH%/%QNX_IMAGE_ELF_FILENAME%

@rem Set path to the HDF file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --hdf_file %ZYNQ_INPUT_PATH%/%HDF_FILENAME%

@rem Set path to the FPGA bit file
@set SCRIPT_PARAMS=%SCRIPT_PARAMS% --fpga_file %ZYNQ_INPUT_PATH%/%FPGA_BIT_FILENAME%

@rem call the Deploy_SW python script 
@call python ./Deployment/Deploy_SW.py %SCRIPT_PARAMS%

@rem #------------------------------------- EOF --------------------------------------#