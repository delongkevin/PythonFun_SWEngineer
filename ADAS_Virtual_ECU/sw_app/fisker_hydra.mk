#
#
# Copyright (c) 2019 Texas Instruments Incorporated
#
# All rights reserved not granted herein.
#
# Limited License.
#
# Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
# license under copyrights and patents it now or hereafter owns or controls to make,
# have made, use, import, offer to sell and sell ("Utilize") this software subject to the
# terms herein.  With respect to the foregoing patent license, such license is granted
# solely to the extent that any such patent is necessary to Utilize the software alone.
# The patent license shall not apply to any combinations which include this software,
# other than combinations with devices manufactured by or for TI ("TI Devices").
# No hardware patent is licensed hereunder.
#
# Redistributions must preserve existing copyright notices and reproduce this license
# (including the above copyright notice and the disclaimer and (if applicable) source
# code license limitations below) in the documentation and/or other materials provided
# with the distribution
#
# Redistribution and use in binary form, without modification, are permitted provided
# that the following conditions are met:
#
# *       No reverse engineering, decompilation, or disassembly of this software is
# permitted with respect to any software provided in binary form.
#
# *       any redistribution and use are licensed by TI for use only with TI Devices.
#
# *       Nothing shall obligate TI to provide you with source code for the software
# licensed and provided to you in object code.
#
# If software source code is provided to you, modification and redistribution of the
# source code are permitted provided that the following conditions are met:
#
# *       any redistribution and use of the source code, including any resulting derivative
# works, are licensed by TI for use only with TI Devices.
#
# *       any redistribution and use of any object code compiled from the source code
# and any resulting derivative works, are licensed by TI for use only with TI Devices.
#
# Neither the name of Texas Instruments Incorporated nor the names of its suppliers
#
# may be used to endorse or promote products derived from this software without
# specific prior written permission.
#
# DISCLAIMER.
#
# THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#


# File: component.mk
#       This file is component include make file of MCUSW.
# List of variables set in this file and their purpose:
# <mod>_RELPATH        - This is the relative path of the module, typically from
#                        top-level directory of the package
# <mod>_PATH           - This is the absolute path of the module. It derives from
#                        absolute path of the top-level directory (set in env.mk)
#                        and relative path set above
# <mod>_INCLUDE        - This is the path that has interface header files of the
#                        module. This can be multiple directories (space separated)
# <mod>_PKG_LIST       - Names of the modules (and sub-modules) that are a part
#                        part of this module, including itself.
# <mod>_BOARD_DEPENDENCY    - "yes": means the code for this module depends on
#                             board and the compiled obj/lib has to be kept
#                             under <board> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no board dependent code and hence
#                             the obj/libs are not kept under <board> dir.
# <mod>_CORE_DEPENDENCY     - "yes": means the code for this module depends on
#                             core and the compiled obj/lib has to be kept
#                             under <core> directory
#                             "no" or "" or if this variable is not defined: means
#                             this module has no core dependent code and hence
#                             the obj/libs are not kept under <core> dir.
# <mod>_APP_STAGE_FILES     - List of source files that belongs to the module
#                             <mod>, but that needs to be compiled at application
#                             build stage (in the context of the app). This is
#                             primarily for link time configurations or if the
#                             source file is dependent on options/defines that are
#                             application dependent. This can be left blank or
#                             not defined at all, in which case, it means there
#                             no source files in the module <mod> that are required
#                             to be compiled in the application build stage.
# <mod>_FP_DEPENDENCY       - "yes": means the code for this module depends on
#                             target toolchain floating point support.  Enabling
#                             this option will enable floating point print
#                             support for toolchains which link out floating
#                             point print support to save memory.
#
ifeq ($(fisker_hydra_mcusw_make_include), )

fisker_hydra_default_SOCLIST          = j721s2
fisker_hydra_default_BOARDLIST        = j721e_sim j721e_hyd j721s2_evm j721s2_hyd
fisker_hydra_default_j721e_CORELIST   = mcu1_0 mcu1_1
fisker_hydra_j721e_CORELIST_ALL       = mcu1_0 mcu1_1 mcu2_0 mcu2_1 mcu3_0 mcu3_1

############################
# Library
# List of components included under fisker lib
# The components included here are built and will be part of fisker lib
############################
fisker_hydra_mcusw_LIB_LIST =

############################
# mcal example
# List of components included under mcal
# The components included here are built and will be part of fisker binary
############################
fisker_hydra_mcusw_APP_LIST =


#Library IPC_MANAGER
ipc_manager_COMP_LIST = ipc_manager
ipc_manager_RELPATH = bookshelf/ipc_manager/$(CORE)
ipc_manager_PATH = $(fisker_hydra_PATH)/bookshelf/ipc_manager
ipc_manager_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ipc_manager_MAKEFILE
ipc_manager_BOARD_DEPENDENCY = no
ipc_manager_CORE_DEPENDENCY = no
export ipc_manager_COMP_LIST
export ipc_manager_BOARD_DEPENDENCY
export ipc_manager_CORE_DEPENDENCY
ipc_manager_PKG_LIST = ipc_manager
export ipc_manager_PKG_LIST
ipc_manager_INCLUDE += $(ipc_manager_PATH)/inc
ipc_manager_INCLUDE += $(ipc_manager_PATH)/cfg
#ipc_manager_INCLUDE += $(ipc_manager_PATH)/../../includes
ipc_manager_INCLUDE += $(fisker_hydra_PATH)/../../platform/asr/app_sip/Common/Implementation
ipc_manager_INCLUDE += $(PDK_INSTALL_PATH)/ti/drv/ipc
ipc_manager_INCLUDE += $(PDK_INSTALL_PATH)/ti/drv/ipc/include/
ipc_manager_SOCLIST = j721e
export ipc_manager_SOCLIST
ipc_manager_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export ipc_manager_j721e_CORELIST
fisker_hydra_mcusw_LIB_LIST += ipc_manager

#Library WDG Magna
wdg_magna_COMP_LIST = wdg_magna
wdg_magna_RELPATH = bookshelf/WdgFw/$(CORE)
wdg_magna_PATH = $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg
wdg_magna_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdg_magna_MAKEFILE
wdg_magna_BOARD_DEPENDENCY = no
wdg_magna_CORE_DEPENDENCY = no
export wdg_magna_COMP_LIST
export wdg_magna_BOARD_DEPENDENCY
export wdg_magna_CORE_DEPENDENCY
wdg_magna_PKG_LIST = wdg_magna
export wdg_magna_PKG_LIST
wdg_magna_INCLUDE += $(wdg_magna_PATH)/inc
wdg_magna_INCLUDE += $(wdg_magna_PATH)/cfg
wdg_magna_SOCLIST = j721e
export wdg_magna_SOCLIST
wdg_magna_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export wdg_magna_j721e_CORELIST
fisker_hydra_mcusw_LIB_LIST += wdg_magna

#Library WDGM Magna 
wdgm_magna_COMP_LIST = wdgm_magna
wdgm_magna_RELPATH = bookshelf/WdgFw/$(CORE)
wdgm_magna_PATH = $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgM_Magna
wdgif_magna_PATH = $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgIf_Magna
wdgm_magna_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdgm_magna_MAKEFILE
wdgm_magna_BOARD_DEPENDENCY = no
wdgm_magna_CORE_DEPENDENCY = no
export wdgm_magna_COMP_LIST
export wdgm_magna_BOARD_DEPENDENCY
export wdgm_magna_CORE_DEPENDENCY
wdgm_magna_PKG_LIST = wdgm_magna
export wdgm_magna_PKG_LIST
wdgm_magna_INCLUDE += $(wdgm_magna_PATH)/inc
wdgm_magna_INCLUDE += $(wdgm_magna_PATH)/cfg
wdgm_magna_INCLUDE += $(wdgm_magna_PATH)/cfg/$(CORE)
wdgm_magna_INCLUDE += $(wdgif_magna_PATH)/inc
wdgm_magna_INCLUDE += $(wdgif_magna_PATH)/cfg
wdgm_magna_SOCLIST = j721e
export wdgm_magna_SOCLIST
wdgm_magna_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export wdgm_magna_j721e_CORELIST
fisker_hydra_mcusw_LIB_LIST += wdgm_magna


#Library WDG Slave
wdgSlave_COMP_LIST = wdgSlave
wdgSlave_RELPATH = bookshelf/WdgFw/$(CORE)
wdgSlave_PATH = $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgSlave
wdgSlave_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdgSlave_MAKEFILE
wdgSlave_BOARD_DEPENDENCY = no
wdgSlave_CORE_DEPENDENCY = no
export wdgSlave_COMP_LIST
export wdgSlave_BOARD_DEPENDENCY
export wdgSlave_CORE_DEPENDENCY
wdgSlave_PKG_LIST = wdgSlave
export wdgSlave_PKG_LIST
wdgSlave_SOCLIST = j721e
export wdgSlave_SOCLIST
wdgSlave_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export wdgSlave_j721e_CORELIST
fisker_hydra_mcusw_LIB_LIST += wdgSlave

#Library WDGIF Magna
wdgif_magna_COMP_LIST = wdgif_magna
wdgif_magna_RELPATH = bookshelf/WdgFw/$(CORE)
wdgif_magna_PATH = $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgIf_Magna
wdgif_magna_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdgif_magna_MAKEFILE
wdgif_magna_BOARD_DEPENDENCY = no
wdgif_magna_CORE_DEPENDENCY = no
export wdgif_magna_COMP_LIST
export wdgif_magna_BOARD_DEPENDENCY
export wdgif_magna_CORE_DEPENDENCY
wdgif_magna_PKG_LIST = wdgif_magna
export wdgif_magna_PKG_LIST
wdgif_magna_INCLUDE += $(wdgif_magna_PATH)/inc
wdgif_magna_INCLUDE += $(wdgif_magna_PATH)/cfg
wdgif_magna_SOCLIST = j721e
export wdgif_magna_SOCLIST
wdgif_magna_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export wdgif_magna_j721e_CORELIST
fisker_hydra_mcusw_LIB_LIST += wdgif_magna

#Library CONSOLE_IO
console_io_COMP_LIST = console_io
console_io_RELPATH = bookshelf/main_domain/console_io
console_io_PATH = $(fisker_hydra_PATH)/bookshelf/main_domain/console_io
console_io_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export console_io_MAKEFILE
console_io_BOARD_DEPENDENCY = no
console_io_CORE_DEPENDENCY = no
export console_io_COMP_LIST
export console_io_BOARD_DEPENDENCY
export console_io_CORE_DEPENDENCY
console_io_PKG_LIST = console_io
export console_io_PKG_LIST
console_io_INCLUDE += $(console_io_PATH)/include
console_io_INCLUDE += $(fisker_hydra_PATH)/platform/asr/app_sip/Common/Implementation
console_io_SOCLIST = j721s2
export console_io_SOCLIST
console_io_j721e_CORELIST = $(mcusw_mcal_default_j721e_CORELIST)
export fisker_hydra_mcu1_0_boot_app_ti_rtos_j721e_CORELIST = mcu1_0
fisker_hydra_mcusw_LIB_LIST += console_io

# Utilities

# example utilities


# MCU Domain applications
# mcu1_0: Boot loader, and other app (tirtos)
fisker_hydra_mcu1_0_boot_app_rtos_COMP_LIST = fisker_hydra_mcu1_0_boot_app_rtos
fisker_hydra_mcu1_0_boot_app_rtos_RELPATH = mcu1_0/app
fisker_hydra_mcu1_0_boot_app_rtos_PATH = $(fisker_hydra_PATH)/mcu1_0/app
fisker_hydra_mcu1_0_boot_app_rtos_MAKEFILE = -f$(fisker_hydra_PATH)/mcu1_0/app/makefile XDC_DISABLE_THUMB_MODE=yes
export fisker_hydra_mcu1_0_boot_app_rtos_MAKEFILE
fisker_hydra_mcu1_0_boot_app_rtos_BOARD_DEPENDENCY = yes
fisker_hydra_mcu1_0_boot_app_rtos_CORE_DEPENDENCY = no
fisker_hydra_mcu1_0_boot_app_rtos_XDC_CONFIGURO = yes
export fisker_hydra_mcu1_0_boot_app_rtos_COMP_LIST
export fisker_hydra_mcu1_0_boot_app_rtos_BOARD_DEPENDENCY
export fisker_hydra_mcu1_0_boot_app_rtos_CORE_DEPENDENCY
fisker_hydra_mcu1_0_boot_app_rtos_PKG_LIST = fisker_hydra_mcu1_0_boot_app_rtos
fisker_hydra_mcu1_0_boot_app_rtos_INCLUDE = $(fisker_hydra_mcu1_0_boot_app_rtos_PATH)
fisker_hydra_mcu1_0_boot_app_rtos_BOARDLIST = j721e_evm j721e_hyd j721s2_evm j721s2_hyd
export fisker_hydra_can_boot_app_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_mcu1_0_boot_app_rtos_j721e_CORELIST = mcu1_0
fisker_hydra_mcu1_0_boot_app_rtos_j721s2_CORELIST = mcu1_0
endif
export fisker_hydra_mcu1_0_boot_app_rtos_j721e_CORELIST
export fisker_hydra_mcu1_0_boot_app_rtos_j721s2_CORELIST
fisker_hydra_mcu1_0_boot_app_rtos_SBL_APPIMAGEGEN = yes
fisker_hydra_mcu1_0_boot_app_rtos_APP_SMP_CONFIG = yes
export fisker_hydra_mcu1_0_boot_app_rtos_SBL_APPIMAGEGEN
export fisker_hydra_mcu1_0_boot_app_rtos_APP_SMP_CONFIG
fisker_hydra_mcusw_APP_LIST += fisker_hydra_mcu1_0_boot_app_rtos


# MCU Domain applications
# mcu1_0: Boot loader, and other app (tirtos)
fisker_hydra_mcu1_0_boot_app_ti_rtos_COMP_LIST = fisker_hydra_mcu1_0_boot_app_ti_rtos
fisker_hydra_mcu1_0_boot_app_ti_rtos_RELPATH = mcu1_0_ti/source
fisker_hydra_mcu1_0_boot_app_ti_rtos_PATH = $(fisker_hydra_PATH)/mcu1_0_ti/source
fisker_hydra_mcu1_0_boot_app_ti_rtos_BOARD_DEPENDENCY = yes
fisker_hydra_mcu1_0_boot_app_ti_rtos_CORE_DEPENDENCY = no
fisker_hydra_mcu1_0_boot_app_ti_rtos_XDC_CONFIGURO = yes
export fisker_hydra_mcu1_0_boot_app_ti_rtos_COMP_LIST
export fisker_hydra_mcu1_0_boot_app_ti_rtos_BOARD_DEPENDENCY
export fisker_hydra_mcu1_0_boot_app_ti_rtos_CORE_DEPENDENCY
fisker_hydra_mcu1_0_boot_app_ti_rtos_PKG_LIST = fisker_hydra_mcu1_0_boot_app_ti_rtos
fisker_hydra_mcu1_0_boot_app_ti_rtos_INCLUDE = $(fisker_hydra_mcu1_0_boot_app_ti_rtos_PATH)
fisker_hydra_mcu1_0_boot_app_ti_rtos_BOARDLIST = j721e_evm j721e_hyd j721s2_evm j721s2_hyd
export fisker_hydra_can_boot_app_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_mcu1_0_boot_app_ti_rtos_j721e_CORELIST = mcu1_0
endif
export fisker_hydra_mcu1_0_boot_app_ti_rtos_j721e_CORELIST
fisker_hydra_mcu1_0_boot_app_ti_rtos_SBL_APPIMAGEGEN = yes
export fisker_hydra_mcu1_0_boot_app_ti_rtos_SBL_APPIMAGEGEN
#fisker_hydra_mcusw_APP_LIST += fisker_hydra_mcu1_0_boot_app_ti_rtos

#Vector Stack

# Main Domain applications for (tirtos), loaded by fisker_hydra_mcu1_0_boot_app_rtos application

# mcu2_0: fisker_hydra_app_mcu2_0 (tirtos)
fisker_hydra_app_mcu2_0_COMP_LIST = fisker_hydra_app_mcu2_0
fisker_hydra_app_mcu2_0_RELPATH = mcu2_0/source
fisker_hydra_app_mcu2_0_PATH = $(fisker_hydra_PATH)/mcu2_0/source
fisker_hydra_app_mcu2_0_MAKEFILE = -f$(fisker_hydra_PATH)/mcu2_0/app/makefile
export fisker_hydra_app_mcu2_0_MAKEFILE
fisker_hydra_app_mcu2_0_BOARD_DEPENDENCY = yes
fisker_hydra_app_mcu2_0_CORE_DEPENDENCY = yes
fisker_hydra_app_mcu2_0_XDC_CONFIGURO = yes
export fisker_hydra_app_mcu2_0_COMP_LIST
export fisker_hydra_app_mcu2_0_BOARD_DEPENDENCY
export fisker_hydra_app_mcu2_0_CORE_DEPENDENCY
export fisker_hydra_app_mcu2_0_XDC_CONFIGURO
fisker_hydra_app_mcu2_0_PKG_LIST = fisker_hydra_app_mcu2_0
fisker_hydra_app_mcu2_0_INCLUDE = $(fisker_hydra_app_mcu2_0_PATH)
fisker_hydra_app_mcu2_0_BOARDLIST = j721e_evm j721e_hyd j7221s2_evm
export fisker_hydra_app_mcu2_0_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_app_mcu2_0_j721e_CORELIST = mcu2_0
endif
export fisker_hydra_app_mcu2_0_j721e_CORELIST
#fisker_hydra_mcusw_APP_LIST += fisker_hydra_app_mcu2_0

# mcu2_1: fisker_hydra_app_mcu2_1 (tirtos)
fisker_hydra_app_mcu2_1_COMP_LIST = fisker_hydra_app_mcu2_1
fisker_hydra_app_mcu2_1_RELPATH = mcu2_1
fisker_hydra_app_mcu2_1_PATH = $(fisker_hydra_PATH)/mcu2_1
fisker_hydra_app_mcu2_1_MAKEFILE = -f$(fisker_hydra_PATH)/mcu2_1/makefile CPLUSPLUS_BUILD=yes
export fisker_hydra_app_mcu2_1_MAKEFILE
fisker_hydra_app_mcu2_1_BOARD_DEPENDENCY = yes
fisker_hydra_app_mcu2_1_CORE_DEPENDENCY = yes
fisker_hydra_app_mcu2_1_XDC_CONFIGURO = $(if $(findstring tirtos,$(BUILD_OS_TYPE)),yes,no)
export fisker_hydra_app_mcu2_1_COMP_LIST
export fisker_hydra_app_mcu2_1_BOARD_DEPENDENCY
export fisker_hydra_app_mcu2_1_CORE_DEPENDENCY
export fisker_hydra_app_mcu2_1_XDC_CONFIGURO
fisker_hydra_app_mcu2_1_PKG_LIST = fisker_hydra_app_mcu2_1
fisker_hydra_app_mcu2_1_INCLUDE = $(fisker_hydra_app_mcu2_1_PATH)
fisker_hydra_app_mcu2_1_BOARDLIST = j721e_evm j721e_hyd j721s2_evm j721s2_hyd
export fisker_hydra_app_mcu2_1_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_app_mcu2_1_j721e_CORELIST = mcu2_1
fisker_hydra_app_mcu2_1_j721s2_CORELIST = mcu2_1
endif
export fisker_hydra_app_mcu2_1_j721e_CORELIST
export fisker_hydra_app_mcu2_1_j721s2_CORELIST
fisker_hydra_mcusw_APP_LIST += fisker_hydra_app_mcu2_1

# mcu3_0: fisker_hydra_app_mcu3_0 (tirtos)
fisker_hydra_app_mcu3_0_COMP_LIST = fisker_hydra_app_mcu3_0
fisker_hydra_app_mcu3_0_RELPATH = mcu3_0/source
fisker_hydra_app_mcu3_0_PATH = $(fisker_hydra_PATH)/mcu3_0/source
fisker_hydra_app_mcu3_0_MAKEFILE = -f$(fisker_hydra_PATH)/mcu3_0/app/makefile CPLUSPLUS_BUILD=yes
export fisker_hydra_app_mcu3_0_MAKEFILE
fisker_hydra_app_mcu3_0_BOARD_DEPENDENCY = yes
fisker_hydra_app_mcu3_0_CORE_DEPENDENCY = yes
fisker_hydra_app_mcu3_0_XDC_CONFIGURO = yes
export fisker_hydra_app_mcu3_0_COMP_LIST
export fisker_hydra_app_mcu3_0_BOARD_DEPENDENCY
export fisker_hydra_app_mcu3_0_CORE_DEPENDENCY
export fisker_hydra_app_mcu3_0_XDC_CONFIGURO
fisker_hydra_app_mcu3_0_PKG_LIST = fisker_hydra_app_mcu3_0
fisker_hydra_app_mcu3_0_INCLUDE = $(fisker_hydra_app_mcu3_0_PATH)
fisker_hydra_app_mcu3_0_BOARDLIST = j721e_evm j721e_hyd j721s2_evm j721s2_hyd
export fisker_hydra_app_mcu3_0_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_app_mcu3_0_j721e_CORELIST = mcu3_0
endif
export fisker_hydra_app_mcu3_0_j721e_CORELIST
fisker_hydra_mcusw_APP_LIST += fisker_hydra_app_mcu3_0

# mcu3_1: fisker_hydra_app_mcu3_1 (tirtos)
fisker_hydra_app_mcu3_1_COMP_LIST = fisker_hydra_app_mcu3_1
fisker_hydra_app_mcu3_1_RELPATH = mcu3_1/source
fisker_hydra_app_mcu3_1_PATH = $(fisker_hydra_PATH)/mcu3_1/source
fisker_hydra_app_mcu3_1_MAKEFILE = -f$(fisker_hydra_PATH)/mcu3_1/app/makefile XDC_DISABLE_THUMB_MODE=yes
export fisker_hydra_app_mcu3_1_MAKEFILE
fisker_hydra_app_mcu3_1_BOARD_DEPENDENCY = yes
fisker_hydra_app_mcu3_1_CORE_DEPENDENCY = yes
fisker_hydra_app_mcu3_1_XDC_CONFIGURO = no
export fisker_hydra_app_mcu3_1_COMP_LIST
export fisker_hydra_app_mcu3_1_BOARD_DEPENDENCY
export fisker_hydra_app_mcu3_1_CORE_DEPENDENCY
export fisker_hydra_app_mcu3_1_XDC_CONFIGURO
fisker_hydra_app_mcu3_1_PKG_LIST = fisker_hydra_app_mcu3_1
fisker_hydra_app_mcu3_1_INCLUDE = $(fisker_hydra_app_mcu3_1_PATH)
fisker_hydra_app_mcu3_1_BOARDLIST = j721e_evm j721e_hyd j721s2_evm j721s2_hyd
export fisker_hydra_app_mcu3_1_BOARDLIST
ifeq ($(BOARD),$(filter $(BOARD), j721e_evm j721e_hyd j721s2_evm j721s2_hyd))
fisker_hydra_app_mcu3_1_j721e_CORELIST = mcu3_1
endif
export fisker_hydra_app_mcu3_1_j721e_CORELIST
fisker_hydra_mcusw_APP_LIST += fisker_hydra_app_mcu3_1


export fisker_hydra_mcusw_LIB_LIST
export fisker_hydra_mcusw_APP_LIST

fisker_hydra_mcusw_make_include := 1
endif
