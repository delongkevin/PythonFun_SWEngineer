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
ifeq ($(autosar_stack_make_include), )

############################
# Library
# List of components included under fisker lib
# The components included here are built and will be part of fisker lib
############################
autosar_mcusw_LIB_LIST =

#Bswm
bswm_COMP_LIST = bswm
bswm_RELPATH = common/autosar/$(CORE)
bswm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/BswM
bswm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export bswm_MAKEFILE
bswm_BOARD_DEPENDENCY = no
bswm_CORE_DEPENDENCY = no
export bswm_COMP_LIST
export bswm_BOARD_DEPENDENCY
export bswm_CORE_DEPENDENCY
bswm_PKG_LIST = bswm
export bswm_PKG_LIST
bswm_INCLUDE += $(bswm_PATH)/../BswM/Implementation
bswm_INCLUDE += $(bswm_PATH)/../Common/Implementation
bswm_SOCLIST = j721s2
export bswm_SOCLIST
bswm_j721s2_CORELIST = $(autosar_bswm_CORELIST)
export bswm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += bswm

#EthIf
ethif_COMP_LIST = ethif
ethif_RELPATH = common/autosar/$(CORE)
ethif_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/EthIf
ethif_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ethif_MAKEFILE
ethif_BOARD_DEPENDENCY = no
ethif_CORE_DEPENDENCY = no
export ethif_COMP_LIST
export ethif_BOARD_DEPENDENCY
export ethif_CORE_DEPENDENCY
ethif_PKG_LIST = ethif
export ethif_PKG_LIST
ethif_INCLUDE += $(ethif_PATH)/Implementation
ethif_SOCLIST = j721s2
export ethif_SOCLIST
ethif_j721s2_CORELIST = $(ethif_CORELIST)
export ethif_j721s2_CORELIST
autosar_mcusw_LIB_LIST += ethif

#EthSM
ethsm_COMP_LIST = ethsm
ethsm_RELPATH = common/autosar/$(CORE)
ethsm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/EthSM
ethsm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ethsm_MAKEFILE
ethsm_BOARD_DEPENDENCY = no
ethsm_CORE_DEPENDENCY = no
export ethsm_COMP_LIST
export ethsm_BOARD_DEPENDENCY
export ethsm_CORE_DEPENDENCY
ethsm_PKG_LIST = ethsm
export ethsm_PKG_LIST
ethsm_INCLUDE += $(ethsm_PATH)/Implementation
ethsm_SOCLIST = j721s2
export ethsm_SOCLIST
ethsm_j721s2_CORELIST = $(ethsm_CORELIST)
export ethsm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += ethsm


#TcpIp
tcpip_COMP_LIST = tcpip
tcpip_RELPATH = common/autosar/$(CORE)
tcpip_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/TcpIp
tcpip_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export tcpip_MAKEFILE
tcpip_BOARD_DEPENDENCY = no
tcpip_CORE_DEPENDENCY = no
export tcpip_COMP_LIST
export tcpip_BOARD_DEPENDENCY
export tcpip_CORE_DEPENDENCY
tcpip_PKG_LIST = tcpip
export tcpip_PKG_LIST
tcpip_INCLUDE += $(tcpip_PATH)/Implementation
tcpip_SOCLIST = j721s2
export tcpip_SOCLIST
tcpip_j721s2_CORELIST = $(tcpip_CORELIST)
export tcpip_j721s2_CORELIST
autosar_mcusw_LIB_LIST += tcpip

#SoAd
soad_COMP_LIST = soad
soad_RELPATH = common/autosar/$(CORE)
soad_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/SoAd
soad_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export soad_MAKEFILE
soad_BOARD_DEPENDENCY = no
soad_CORE_DEPENDENCY = no
export soad_COMP_LIST
export soad_BOARD_DEPENDENCY
export soad_CORE_DEPENDENCY
soad_PKG_LIST = soad
export soad_PKG_LIST
soad_INCLUDE += $(soad_PATH)/Implementation
soad_SOCLIST = j721s2
export soad_SOCLIST
soad_j721s2_CORELIST = $(soad_CORELIST)
export soad_j721s2_CORELIST
autosar_mcusw_LIB_LIST += soad

#IpBase
ipbase_COMP_LIST = ipbase
ipbase_RELPATH = common/autosar/$(CORE)
ipbase_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/ipbase
ipbase_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ipbase_MAKEFILE
ipbase_BOARD_DEPENDENCY = no
ipbase_CORE_DEPENDENCY = no
export ipbase_COMP_LIST
export ipbase_BOARD_DEPENDENCY
export ipbase_CORE_DEPENDENCY
ipbase_PKG_LIST = ipbase
export ipbase_PKG_LIST
ipbase_INCLUDE += $(ipbase_PATH)/Implementation
ipbase_SOCLIST = j721s2
export ipbase_SOCLIST
ipbase_j721s2_CORELIST = $(ipbase_CORELIST)
export ipbase_j721s2_CORELIST
autosar_mcusw_LIB_LIST += ipbase

#Can_30_Mcan
mcan_COMP_LIST = mcan
mcan_RELPATH = common/autosar/$(CORE)
mcan_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Can_30_Mcan
mcan_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export mcan_MAKEFILE
mcan_BOARD_DEPENDENCY = no
mcan_CORE_DEPENDENCY = no
export mcan_COMP_LIST
export mcan_BOARD_DEPENDENCY
export mcan_CORE_DEPENDENCY
mcan_PKG_LIST = mcan
export mcan_PKG_LIST
mcan_INCLUDE += $(mcan_PATH)/Implementation
mcan_SOCLIST = j721s2
export mcan_SOCLIST
mcan_j721s2_CORELIST = $(mcan_CORELIST)
export mcan_j721s2_CORELIST
autosar_mcusw_LIB_LIST += mcan

#CanSM
cansm_COMP_LIST = cansm
cansm_RELPATH = common/autosar/$(CORE)
cansm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanSM
cansm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cansm_MAKEFILE
cansm_BOARD_DEPENDENCY = no
cansm_CORE_DEPENDENCY = no
export cansm_COMP_LIST
export cansm_BOARD_DEPENDENCY
export cansm_CORE_DEPENDENCY
cansm_PKG_LIST = cansm
export cansm_PKG_LIST
cansm_INCLUDE += $(cansm_PATH)/Implementation
cansm_SOCLIST = j721s2
export cansm_SOCLIST
cansm_j721s2_CORELIST = $(cansm_CORELIST)
export cansm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += cansm

#CanTrcv_30_Tja1043
cantrcv_tja1043_COMP_LIST = cantrcv_tja1043
cantrcv_tja1043_RELPATH = common/autosar/$(CORE)
cantrcv_tja1043_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanTrcv_30_Tja1043
cantrcv_tja1043_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cantrcv_tja1043_MAKEFILE
cantrcv_tja1043_BOARD_DEPENDENCY = no
cantrcv_tja1043_CORE_DEPENDENCY = no
export cantrcv_tja1043_COMP_LIST
export cantrcv_tja1043_BOARD_DEPENDENCY
export cantrcv_tja1043_CORE_DEPENDENCY
cantrcv_tja1043_PKG_LIST = cantrcv_tja1043
export cantrcv_tja1043_PKG_LIST
cantrcv_tja1043_INCLUDE += $(cantrcv_tja1043_PATH)/Implementation
cantrcv_tja1043_SOCLIST = j721s2
export cantrcv_tja1043_SOCLIST
cantrcv_tja1043_j721s2_CORELIST = $(cantrcv_tja1043_CORELIST)
export cantrcv_tja1043_j721s2_CORELIST
autosar_mcusw_LIB_LIST += cantrcv_tja1043

#CanTrcv_30_GenericCan_TJA1057
CanTrcv_30_GenericCan_tja1057_COMP_LIST = CanTrcv_30_GenericCan_tja1057
CanTrcv_30_GenericCan_tja1057_RELPATH = common/autosar/$(CORE)

CanTrcv_30_GenericCan_tja1057_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanTrcv_30_Generic
CanTrcv_30_GenericCan_tja1057_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export CanTrcv_30_GenericCan_tja1057_MAKEFILE
CanTrcv_30_GenericCan_tja1057_BOARD_DEPENDENCY = no
CanTrcv_30_GenericCan_tja1057_CORE_DEPENDENCY = no
export CanTrcv_30_GenericCan_tja1057_COMP_LIST
export CanTrcv_30_GenericCan_tja1057_BOARD_DEPENDENCY
export CanTrcv_30_GenericCan_tja1057_CORE_DEPENDENCY
CanTrcv_30_GenericCan_tja1057_PKG_LIST = CanTrcv_30_GenericCan_tja1057
export CanTrcv_30_GenericCan_tja1057_PKG_LIST
CanTrcv_30_GenericCan_tja1057_INCLUDE += $(CanTrcv_30_GenericCan_tja1057_PATH)/Implementation
CanTrcv_30_GenericCan_tja1057_SOCLIST = j721s2
export CanTrcv_30_GenericCan_tja1057_SOCLIST
CanTrcv_30_GenericCan_tja1057_j721s2_CORELIST = $(CanTrcv_30_GenericCan_tja1057_CORELIST)
export CanTrcv_30_GenericCan_tja1057_j721s2_CORELIST
autosar_mcusw_LIB_LIST += CanTrcv_30_GenericCan_tja1057

#Com
com_COMP_LIST = com
com_RELPATH = common/autosar/$(CORE)
com_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Com
com_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export com_MAKEFILE
com_BOARD_DEPENDENCY = no
com_CORE_DEPENDENCY = no
export com_COMP_LIST
export com_BOARD_DEPENDENCY
export com_CORE_DEPENDENCY
com_PKG_LIST = com
export com_PKG_LIST
com_INCLUDE += $(com_PATH)/Implementation
com_SOCLIST = j721s2
export com_SOCLIST
com_j721s2_CORELIST = $(com_CORELIST)
export com_j721s2_CORELIST
autosar_mcusw_LIB_LIST += com

#ComM
comm_COMP_LIST = comm
comm_RELPATH = common/autosar/$(CORE)
comm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/ComM
comm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export comm_MAKEFILE
comm_BOARD_DEPENDENCY = no
comm_CORE_DEPENDENCY = no
export comm_COMP_LIST
export comm_BOARD_DEPENDENCY
export comm_CORE_DEPENDENCY
comm_PKG_LIST = comm
export comm_PKG_LIST
comm_INCLUDE += $(comm_PATH)/Implementation
comm_SOCLIST = j721s2
export comm_SOCLIST
comm_j721s2_CORELIST = $(comm_CORELIST)
export comm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += comm

#Det
det_COMP_LIST = det
det_RELPATH = common/autosar/$(CORE)
det_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Det
det_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export det_MAKEFILE
det_BOARD_DEPENDENCY = no
det_CORE_DEPENDENCY = no
export det_COMP_LIST
export det_BOARD_DEPENDENCY
export det_CORE_DEPENDENCY
det_PKG_LIST = det
export det_PKG_LIST
det_INCLUDE += $(det_PATH)/Implementation
det_SOCLIST = j721s2
export det_SOCLIST
det_j721s2_CORELIST = $(det_CORELIST)
export det_j721s2_CORELIST
autosar_mcusw_LIB_LIST += det

#EcuM
ecum_COMP_LIST = ecum
ecum_RELPATH = common/autosar/$(CORE)
ecum_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/EcuM
ecum_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ecum_MAKEFILE
ecum_BOARD_DEPENDENCY = no
ecum_CORE_DEPENDENCY = no
export ecum_COMP_LIST
export ecum_BOARD_DEPENDENCY
export ecum_CORE_DEPENDENCY
ecum_PKG_LIST = ecum
export ecum_PKG_LIST
ecum_INCLUDE += $(ecum_PATH)/Implementation
ecum_SOCLIST = j721s2
export ecum_SOCLIST
ecum_j721s2_CORELIST = $(ecum_CORELIST)
export ecum_j721s2_CORELIST
autosar_mcusw_LIB_LIST += ecum

#Os
os_COMP_LIST = os
os_RELPATH = common/autosar/$(CORE)
os_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Os
os_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export os_MAKEFILE
os_BOARD_DEPENDENCY = no
os_CORE_DEPENDENCY = no
export os_COMP_LIST
export os_BOARD_DEPENDENCY
export os_CORE_DEPENDENCY
os_PKG_LIST = os
export os_PKG_LIST
os_INCLUDE += $(os_PATH)/Implementation
os_SOCLIST = j721s2
export os_SOCLIST
os_j721s2_CORELIST = $(os_CORELIST)
export os_j721s2_CORELIST
autosar_mcusw_LIB_LIST += os

#PduR
pdur_COMP_LIST = os
pdur_RELPATH = common/autosar/$(CORE)
pdur_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/PduR
pdur_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export pdur_MAKEFILE
pdur_BOARD_DEPENDENCY = no
pdur_CORE_DEPENDENCY = no
export pdur_COMP_LIST
export pdur_BOARD_DEPENDENCY
export pdur_CORE_DEPENDENCY
pdur_PKG_LIST = pdur
export pdur_PKG_LIST
pdur_INCLUDE += $(pdur_PATH)/Implementation
pdur_SOCLIST = j721s2
export pdur_SOCLIST
pdur_j721s2_CORELIST = $(pdur_CORELIST)
export pdur_j721s2_CORELIST
autosar_mcusw_LIB_LIST += pdur

#Stubs
stubs_COMP_LIST = os
stubs_RELPATH = common/autosar/$(CORE)
stubs_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/stubs
stubs_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export stubs_MAKEFILE
stubs_BOARD_DEPENDENCY = no
stubs_CORE_DEPENDENCY = no
export stubs_COMP_LIST
export stubs_BOARD_DEPENDENCY
export stubs_CORE_DEPENDENCY
stubs_PKG_LIST = stubs
export stubs_PKG_LIST
stubs_INCLUDE += $(stubs_PATH)/$(CORE)
stubs_SOCLIST = j721s2
export stubs_SOCLIST
stubs_j721s2_CORELIST = $(stubs_CORELIST)
export stubs_j721s2_CORELIST
autosar_mcusw_LIB_LIST += stubs

#VStdLib
vstdlib_COMP_LIST = vstdlib
vstdlib_RELPATH = common/autosar/$(CORE)
vstdlib_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/VStdLib
vstdlib_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export vstdlib_MAKEFILE
vstdlib_BOARD_DEPENDENCY = no
vstdlib_CORE_DEPENDENCY = no
export vstdlib_COMP_LIST
export vstdlib_BOARD_DEPENDENCY
export vstdlib_CORE_DEPENDENCY
vstdlib_PKG_LIST = vstdlib
export vstdlib_PKG_LIST
vstdlib_INCLUDE += $(vstdlib_PATH)/Implementation
vstdlib_SOCLIST = j721s2
export vstdlib_SOCLIST
vstdlib_j721s2_CORELIST = $(vstdlib_CORELIST)
export vstdlib_j721s2_CORELIST
autosar_mcusw_LIB_LIST += vstdlib

#Gendata
gendata_COMP_LIST = gendata
gendata_RELPATH = common/autosar/$(CORE)
gendata_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/GenData
gendata_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export gendata_MAKEFILE
gendata_BOARD_DEPENDENCY = no
gendata_CORE_DEPENDENCY = no
export gendata_COMP_LIST
export gendata_BOARD_DEPENDENCY
export gendata_CORE_DEPENDENCY
gendata_PKG_LIST = gendata
export gendata_PKG_LIST
gendata_INCLUDE += $(gendata_PATH)/$(CORE)
gendata_INCLUDE += $(gendata_PATH)/$(CORE)/Components
gendata_INCLUDE += $(gendata_PATH)/$(CORE)/include
gendata_SOCLIST = j721s2
export gendata_SOCLIST
gendata_j721s2_CORELIST = $(gendata_CORELIST)
export gendata_j721s2_CORELIST
autosar_mcusw_LIB_LIST += gendata

#Canif
canif_COMP_LIST = canif
canif_RELPATH = common/autosar/$(CORE)
canif_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanIf
canif_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export canif_MAKEFILE
canif_BOARD_DEPENDENCY = no
canif_CORE_DEPENDENCY = no
export canif_COMP_LIST
export canif_BOARD_DEPENDENCY
export canif_CORE_DEPENDENCY
canif_PKG_LIST = canif
export canif_PKG_LIST
canif_INCLUDE += $(canif_PATH)/Implementation
canif_SOCLIST = j721s2
export canif_SOCLIST
canif_j721s2_CORELIST = $(canif_CORELIST)
export canif_j721s2_CORELIST
autosar_mcusw_LIB_LIST += canif


#CanNm
cannm_COMP_LIST = cannm
cannm_RELPATH = common/autosar/$(CORE)
cannm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanNm
cannm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cannm_MAKEFILE
cannm_BOARD_DEPENDENCY = no
cannm_CORE_DEPENDENCY = no
export cannm_COMP_LIST
export cannm_BOARD_DEPENDENCY
export cannm_CORE_DEPENDENCY
cannm_PKG_LIST = cannm
export cannm_PKG_LIST
cannm_INCLUDE += $(cannm_PATH)/Implementation
cannm_SOCLIST = j721s2
export cannm_SOCLIST
cannm_j721s2_CORELIST = $(cannm_CORELIST)
export cannm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += cannm

#nm
nm_COMP_LIST = nm
nm_RELPATH = common/autosar/$(CORE)
nm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Nm
nm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export nm_MAKEFILE
nm_BOARD_DEPENDENCY = no
nm_CORE_DEPENDENCY = no
export nm_COMP_LIST
export nm_BOARD_DEPENDENCY
export nm_CORE_DEPENDENCY
nm_PKG_LIST = nm
export nm_PKG_LIST
nm_INCLUDE += $(nm_PATH)/Implementation
nm_SOCLIST = j721s2
export nm_SOCLIST
nm_j721s2_CORELIST = $(nm_CORELIST)
export nm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += nm

#dio
dio_COMP_LIST = dio
dio_RELPATH = common/autosar/$(CORE)
dio_PATH = $(fisker_hydra_PATH)/platform/asr/ti_mcal/Dio
dio_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export dio_MAKEFILE
dio_BOARD_DEPENDENCY = no
dio_CORE_DEPENDENCY = no
export dio_COMP_LIST
export dio_BOARD_DEPENDENCY
export dio_CORE_DEPENDENCY
dio_PKG_LIST = dio
export dio_PKG_LIST
dio_INCLUDE += $(dio_PATH)/include
dio_SOCLIST = j721s2
export dio_SOCLIST
dio_j721s2_CORELIST = $(dio_CORELIST)
export dio_j721s2_CORELIST
autosar_mcusw_LIB_LIST += dio

#Eth
eth_COMP_LIST = eth
eth_RELPATH = common/autosar/$(CORE)
eth_PATH = $(fisker_hydra_PATH)/platform/asr/ti_mcal/Eth
eth_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export eth_MAKEFILE
eth_BOARD_DEPENDENCY = no
eth_CORE_DEPENDENCY = no
export eth_COMP_LIST
export eth_BOARD_DEPENDENCY
export eth_CORE_DEPENDENCY
eth_PKG_LIST = eth
export eth_PKG_LIST
eth_INCLUDE += $(eth_PATH)/include
eth_INCLUDE += $(eth_PATH)/../Eth/src/cpsw/include
eth_INCLUDE += $(eth_PATH)/../Bsw_Stubs/Dem/inc
eth_INCLUDE += $(eth_PATH)/../Bsw_Stubs/MemMap/inc
eth_INCLUDE += $(eth_PATH)/../../vector_stack/GenData/$(CORE)
eth_SOCLIST = j721s2
export eth_SOCLIST
eth_j721s2_CORELIST = $(eth_CORELIST)
export eth_j721s2_CORELIST
autosar_mcusw_LIB_LIST += eth

#cdd_ipc
cdd_ipc_COMP_LIST = cdd_ipc
cdd_ipc_RELPATH = common/autosar/$(CORE)
cdd_ipc_PATH = $(fisker_hydra_PATH)/platform/asr/ti_mcal/CddIpc
cdd_ipc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cdd_ipc_MAKEFILE
cdd_ipc_BOARD_DEPENDENCY = no
cdd_ipc_CORE_DEPENDENCY = no
export cdd_ipc_COMP_LIST
export cdd_ipc_BOARD_DEPENDENCY
export cdd_ipc_CORE_DEPENDENCY
cdd_ipc_PKG_LIST = cdd_ipc
export cdd_ipc_PKG_LIST
cdd_ipc_INCLUDE += $(cdd_ipc_PATH)/include
cdd_ipc_SOCLIST = j721s2
export cdd_ipc_SOCLIST
cdd_ipc_j721s2_CORELIST = $(cdd_ipc_CORELIST)
export cdd_ipc_j721s2_CORELIST
autosar_mcusw_LIB_LIST += cdd_ipc

#DemStub
demstub_COMP_LIST = demstub
demstub_RELPATH = common/autosar/$(CORE)
demstub_PATH = $(fisker_hydra_PATH)/platform/asr/ti_mcal/Bsw_Stubs/Dem
demstub_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export demstub_MAKEFILE
demstub_BOARD_DEPENDENCY = no
demstub_CORE_DEPENDENCY = no
export demstub_COMP_LIST
export demstub_BOARD_DEPENDENCY
export demstub_CORE_DEPENDENCY
demstub_PKG_LIST = demstub
export demstub_PKG_LIST
demstub_INCLUDE += $(demstub_PATH)/../Bsw_Stubs/Dem/inc
demstub_SOCLIST = j721s2
export demstub_SOCLIST
demstub_j721s2_CORELIST = $(demstub_CORELIST)
export demstub_j721s2_CORELIST
autosar_mcusw_LIB_LIST += demstub

#cantp
cantp_COMP_LIST = cantp
cantp_RELPATH = common/autosar/$(CORE)
cantp_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanTp
cantp_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cantp_MAKEFILE
cantp_BOARD_DEPENDENCY = no
cantp_CORE_DEPENDENCY = no
export cantp_COMP_LIST
export cantp_BOARD_DEPENDENCY
export cantp_CORE_DEPENDENCY
cantp_PKG_LIST = cantp
export cantp_PKG_LIST
cantp_INCLUDE += $(cantp_PATH)/Implementation
cantp_SOCLIST = j721s2
export cantp_SOCLIST
cantp_j721s2_CORELIST = $(cantp_CORELIST)
export cantp_j721s2_CORELIST
autosar_mcusw_LIB_LIST += cantp

#dcm
dcm_COMP_LIST = dcm
dcm_RELPATH = common/autosar/$(CORE)
dcm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Dcm
dcm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export dcm_MAKEFILE
dcm_BOARD_DEPENDENCY = no
dcm_CORE_DEPENDENCY = no
export dcm_COMP_LIST
export dcm_BOARD_DEPENDENCY
export dcm_CORE_DEPENDENCY
dcm_PKG_LIST = dcm
export dcm_PKG_LIST
dcm_INCLUDE += $(dcm_PATH)/Implementation
dcm_SOCLIST = j721s2
export dcm_SOCLIST
dcm_j721s2_CORELIST = $(dcm_CORELIST)
export dcm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += dcm

#dem
dem_COMP_LIST = dem
dem_RELPATH = common/autosar/$(CORE)
dem_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Dem
dem_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export dem_MAKEFILE
dem_BOARD_DEPENDENCY = no
dem_CORE_DEPENDENCY = no
export dem_COMP_LIST
export dem_BOARD_DEPENDENCY
export dem_CORE_DEPENDENCY
dem_PKG_LIST = dem
export dem_PKG_LIST
dem_INCLUDE += $(dem_PATH)/Implementation
dem_SOCLIST = j721s2
export dem_SOCLIST
dem_j721s2_CORELIST = $(dem_CORELIST)
export dem_j721s2_CORELIST
autosar_mcusw_LIB_LIST += dem

#vRoE
vRoE_COMP_LIST = vRoE
vRoE_RELPATH = common/autosar/$(CORE)
vRoE_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/vRoE
vRoE_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export vRoE_MAKEFILE
vRoE_BOARD_DEPENDENCY = no
vRoE_CORE_DEPENDENCY = no
export vRoE_COMP_LIST
export vRoE_BOARD_DEPENDENCY
export vRoE_CORE_DEPENDENCY
vRoE_PKG_LIST = vRoE
export vRoE_PKG_LIST
vRoE_INCLUDE += $(vRoE_PATH)/Implementation
vRoE_SOCLIST = j721s2
export vRoE_SOCLIST
vRoE_j721s2_CORELIST = $(vRoE_CORELIST)
export vRoE_j721s2_CORELIST
autosar_mcusw_LIB_LIST += vRoE

#ea
ea_COMP_LIST = ea
ea_RELPATH = common/autosar/$(CORE)
ea_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Ea
ea_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ea_MAKEFILE
ea_BOARD_DEPENDENCY = no
ea_CORE_DEPENDENCY = no
export ea_COMP_LIST
export ea_BOARD_DEPENDENCY
export ea_CORE_DEPENDENCY
ea_PKG_LIST = ea
export ea_PKG_LIST
ea_INCLUDE += $(ea_PATH)/Implementation
ea_SOCLIST = j721s2
export ea_SOCLIST
ea_j721s2_CORELIST = $(ea_CORELIST)
export ea_j721s2_CORELIST
autosar_mcusw_LIB_LIST += ea

#eep
eep_COMP_LIST = eep
eep_RELPATH = common/autosar/$(CORE)
eep_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Eep_30_XXi2c01
eep_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export eep_MAKEFILE
eep_BOARD_DEPENDENCY = no
eep_CORE_DEPENDENCY = no
export eep_COMP_LIST
export eep_BOARD_DEPENDENCY
export eep_CORE_DEPENDENCY
eep_PKG_LIST = eep
export eep_PKG_LIST
eep_INCLUDE += $(eep_PATH)/Implementation
eep_SOCLIST = j721s2
export eep_SOCLIST
eep_j721s2_CORELIST = $(eep_CORELIST)
export eep_j721s2_CORELIST
autosar_mcusw_LIB_LIST += eep

#vi2c
vi2c_COMP_LIST = vi2c
vi2c_RELPATH = common/autosar/$(CORE)
vi2c_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/I2c
vi2c_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export vi2c_MAKEFILE
vi2c_BOARD_DEPENDENCY = no
vi2c_CORE_DEPENDENCY = no
export vi2c_COMP_LIST
export vi2c_BOARD_DEPENDENCY
export vi2c_CORE_DEPENDENCY
vi2c_PKG_LIST = vi2c
export vi2c_PKG_LIST
vi2c_INCLUDE += $(vi2c_PATH)/Implementation
vi2c_SOCLIST = j721s2
export vi2c_SOCLIST
vi2c_j721s2_CORELIST = $(vi2c_CORELIST)
export vi2c_j721s2_CORELIST
autosar_mcusw_LIB_LIST += vi2c

#memif
memif_COMP_LIST = memif
memif_RELPATH = common/autosar/$(CORE)
memif_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/MemIf
memif_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export memif_MAKEFILE
memif_BOARD_DEPENDENCY = no
memif_CORE_DEPENDENCY = no
export memif_COMP_LIST
export memif_BOARD_DEPENDENCY
export memif_CORE_DEPENDENCY
memif_PKG_LIST = memif
export memif_PKG_LIST
memif_INCLUDE += $(memif_PATH)/Implementation
memif_SOCLIST = j721s2
export memif_SOCLIST
memif_j721s2_CORELIST = $(memif_CORELIST)
export memif_j721s2_CORELIST
autosar_mcusw_LIB_LIST += memif

#nvm
nvm_COMP_LIST = nvm
nvm_RELPATH = common/autosar/$(CORE)
nvm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/NvM
nvm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export nvm_MAKEFILE
nvm_BOARD_DEPENDENCY = no
nvm_CORE_DEPENDENCY = no
export nvm_COMP_LIST
export nvm_BOARD_DEPENDENCY
export nvm_CORE_DEPENDENCY
nvm_PKG_LIST = nvm
export nvm_PKG_LIST
nvm_INCLUDE += $(nvm_PATH)/Implementation
nvm_SOCLIST = j721s2
export nvm_SOCLIST
nvm_j721s2_CORELIST = $(nvm_CORELIST)
export nvm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += nvm

#crc
crc_COMP_LIST = crc
crc_RELPATH = common/autosar/$(CORE)
crc_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Crc
crc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export crc_MAKEFILE
crc_BOARD_DEPENDENCY = no
crc_CORE_DEPENDENCY = no
export crc_COMP_LIST
export crc_BOARD_DEPENDENCY
export crc_CORE_DEPENDENCY
crc_PKG_LIST = crc
export crc_PKG_LIST
crc_INCLUDE += $(crc_PATH)/Implementation
crc_SOCLIST = j721s2
export crc_SOCLIST
crc_j721s2_CORELIST = $(crc_CORELIST)
export crc_j721s2_CORELIST
autosar_mcusw_LIB_LIST += crc


#Csm
Csm_COMP_LIST = Csm
Csm_RELPATH = common/autosar/$(CORE)
Csm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Csm
Csm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export Csm_MAKEFILE
Csm_BOARD_DEPENDENCY = no
Csm_CORE_DEPENDENCY = no
export Csm_COMP_LIST
export Csm_BOARD_DEPENDENCY
export Csm_CORE_DEPENDENCY
Csm_PKG_LIST = Csm
export Csm_PKG_LIST
Csm_INCLUDE += $(Csm_PATH)/Implementation
Csm_SOCLIST = j721s2
export Csm_SOCLIST
Csm_j721s2_CORELIST = $(Csm_CORELIST)
export Csm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += Csm

#CryIf
CryIf_COMP_LIST = CryIf
CryIf_RELPATH = common/autosar/$(CORE)
CryIf_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CryIf
CryIf_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export CryIf_MAKEFILE
CryIf_BOARD_DEPENDENCY = no
CryIf_CORE_DEPENDENCY = no
export CryIf_COMP_LIST
export CryIf_BOARD_DEPENDENCY
export CryIf_CORE_DEPENDENCY
CryIf_PKG_LIST = CryIf
export CryIf_PKG_LIST
CryIf_INCLUDE += $(CryIf_PATH)/Implementation
CryIf_SOCLIST = j721s2
export CryIf_SOCLIST
CryIf_j721s2_CORELIST = $(CryIf_CORELIST)
export CryIf_j721s2_CORELIST
autosar_mcusw_LIB_LIST += CryIf

#Crypto_30_vHsm 
Crypto_30_vHsm_COMP_LIST = Crypto_30_vHsm	
Crypto_30_vHsm_RELPATH = common/autosar/$(CORE)
Crypto_30_vHsm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Crypto_30_vHsm
Crypto_30_vHsm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export Crypto_30_vHsm_MAKEFILE
Crypto_30_vHsm_BOARD_DEPENDENCY = no
Crypto_30_vHsm_CORE_DEPENDENCY = no
export Crypto_30_vHsm_COMP_LIST
export Crypto_30_vHsm_BOARD_DEPENDENCY
export Crypto_30_vHsm_CORE_DEPENDENCY
Crypto_30_vHsm_PKG_LIST = Crypto_30_vHsm
export Crypto_30_vHsm_PKG_LIST
Crypto_30_vHsm_INCLUDE += $(Crypto_30_vHsm_PATH)/Implementation
Crypto_30_vHsm_SOCLIST = j721s2
export Crypto_30_vHsm_SOCLIST
Crypto_30_vHsm_j721s2_CORELIST = $(Crypto_30_vHsm_CORELIST)
export Crypto_30_vHsm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += Crypto_30_vHsm

#E2E
E2E_COMP_LIST = E2E
E2E_RELPATH = common/autosar/$(CORE)
E2E_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/E2E
E2E_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export E2E_MAKEFILE
E2E_BOARD_DEPENDENCY = no
E2E_CORE_DEPENDENCY = no
export E2E_COMP_LIST
export E2E_BOARD_DEPENDENCY
export E2E_CORE_DEPENDENCY
E2E_PKG_LIST = E2E
export E2E_PKG_LIST
E2E_INCLUDE += $(E2E_PATH)/Implementation
E2E_SOCLIST = j721s2
export E2E_SOCLIST
E2E_j721s2_CORELIST = $(E2E_CORELIST)
export E2E_j721s2_CORELIST
autosar_mcusw_LIB_LIST += E2E

#adc
adc_COMP_LIST = adc
adc_RELPATH = common/autosar/$(CORE)
adc_PATH = $(fisker_hydra_PATH)/platform/asr/ti_mcal/Adc
adc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export adc_MAKEFILE
adc_BOARD_DEPENDENCY = no
adc_CORE_DEPENDENCY = no
export adc_COMP_LIST
export adc_BOARD_DEPENDENCY
export adc_CORE_DEPENDENCY
adc_PKG_LIST = adc
export adc_PKG_LIST
adc_INCLUDE += $(adc_PATH)/include
adc_SOCLIST = j721s2
export adc_SOCLIST
adc_j721s2_CORELIST = $(adc_CORELIST)
export adc_j721s2_CORELIST
autosar_mcusw_LIB_LIST += adc

#wdgm
wdgm_COMP_LIST = wdgm
wdgm_RELPATH = common/autosar/$(CORE)
wdgm_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/WdgM
wdgm_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdgm_MAKEFILE
wdgm_BOARD_DEPENDENCY = no
wdgm_CORE_DEPENDENCY = no
export wdgm_COMP_LIST
export wdgm_BOARD_DEPENDENCY
export wdgm_CORE_DEPENDENCY
wdgm_PKG_LIST = wdgm
export wdgm_PKG_LIST
wdgm_INCLUDE += $(wdgm_PATH)/Implementation
wdgm_SOCLIST = j721s2
export wdgm_SOCLIST
wdgm_j721s2_CORELIST = $(wdgm_CORELIST)
export wdgm_j721s2_CORELIST
autosar_mcusw_LIB_LIST += wdgm

#wdgif
wdgif_COMP_LIST = wdgif
wdgif_RELPATH = common/autosar/$(CORE)
wdgif_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/WdgIf
wdgif_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export wdgif_MAKEFILE
wdgif_BOARD_DEPENDENCY = no
wdgif_CORE_DEPENDENCY = no
export wdgif_COMP_LIST
export wdgif_BOARD_DEPENDENCY
export wdgif_CORE_DEPENDENCY
wdgif_PKG_LIST = wdgif
export wdgif_PKG_LIST
wdgif_INCLUDE += $(wdgif_PATH)/Implementation
wdgif_SOCLIST = j721s2
export wdgif_SOCLIST
wdgif_j721s2_CORELIST = $(wdgif_CORELIST)
export wdgif_j721s2_CORELIST
autosar_mcusw_LIB_LIST += wdgif 

#Xcp
xcp_COMP_LIST = xcp
xcp_RELPATH = common/autosar/$(CORE)
xcp_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/Xcp
xcp_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export xcp_MAKEFILE
xcp_BOARD_DEPENDENCY = no
xcp_CORE_DEPENDENCY = no
export xcp_COMP_LIST
export xcp_BOARD_DEPENDENCY
export xcp_CORE_DEPENDENCY
xcp_PKG_LIST = xcp
export xcp_PKG_LIST
xcp_INCLUDE += $(xcp_PATH)/Implementation
xcp_SOCLIST = j721s2
export xcp_SOCLIST
xcp_j721s2_CORELIST = $(xcp_CORELIST)
export xcp_j721s2_CORELIST
autosar_mcusw_LIB_LIST += xcp

#canxcp
canxcp_COMP_LIST = canxcp
canxcp_RELPATH = common/autosar/$(CORE)
canxcp_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/CanXcp
canxcp_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export canxcp_MAKEFILE
canxcp_BOARD_DEPENDENCY = no
canxcp_CORE_DEPENDENCY = no
export canxcp_COMP_LIST
export canxcp_BOARD_DEPENDENCY
export canxcp_CORE_DEPENDENCY
canxcp_PKG_LIST = canxcp
export canxcp_PKG_LIST
canxcp_INCLUDE += $(canxcp_PATH)/Implementation
canxcp_SOCLIST = j721s2
export canxcp_SOCLIST
canxcp_j721s2_CORELIST = $(canxcp_CORELIST)
export canxcp_j721s2_CORELIST
autosar_mcusw_LIB_LIST += canxcp

#TcpIpXcp
tcpipxcp_COMP_LIST = tcpipxcp
tcpipxcp_RELPATH = common/autosar/$(CORE)
tcpipxcp_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/TcpIpXcp
tcpipxcp_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export tcpipxcp_MAKEFILE
tcpipxcp_BOARD_DEPENDENCY = no
tcpipxcp_CORE_DEPENDENCY = no
export tcpipxcp_COMP_LIST
export tcpipxcp_BOARD_DEPENDENCY
export tcpipxcp_CORE_DEPENDENCY
tcpipxcp_PKG_LIST = tcpipxcp
export tcpipxcp_PKG_LIST
tcpipxcp_INCLUDE += $(tcpipxcp_PATH)/Implementation
tcpipxcp_SOCLIST = j721s2
export tcpipxcp_SOCLIST
tcpipxcp_j721s2_CORELIST = $(tcpipxcp_CORELIST)
export tcpipxcp_j721s2_CORELIST
autosar_mcusw_LIB_LIST += tcpipxcp

#vDiagSecAcc
vdiagsecacc_COMP_LIST = vdiagsecacc
vdiagsecacc_RELPATH = common/autosar/$(CORE)
vdiagsecacc_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/vDiagSecAcc
vdiagsecacc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export vdiagsecacc_MAKEFILE
vdiagsecacc_BOARD_DEPENDENCY = no
vdiagsecacc_CORE_DEPENDENCY = no
export vdiagsecacc_COMP_LIST
export vdiagsecacc_BOARD_DEPENDENCY
export vdiagsecacc_CORE_DEPENDENCY
vdiagsecacc_PKG_LIST = vdiagsecacc
export vdiagsecacc_PKG_LIST
vdiagsecacc_INCLUDE += $(vdiagsecacc_PATH)/Implementation
vdiagsecacc_SOCLIST = j721s2
export vdiagsecacc_SOCLIST
vdiagsecacc_j721s2_CORELIST = $(vdiagsecacc_CORELIST)
export vdiagsecacc_j721s2_CORELIST
autosar_mcusw_LIB_LIST += vdiagsecacc

#vDam
vdam_COMP_LIST = vdam
vdam_RELPATH = common/autosar/$(CORE)
vdam_PATH = $(fisker_hydra_PATH)/platform/asr/app_sip/vDam
vdam_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export vdam_MAKEFILE
vdam_BOARD_DEPENDENCY = no
vdam_CORE_DEPENDENCY = no
export vdam_COMP_LIST
export vdam_BOARD_DEPENDENCY
export vdam_CORE_DEPENDENCY
vdam_PKG_LIST = vdam
export vdam_PKG_LIST
vdam_INCLUDE += $(vdam_PATH)/Implementation
vdam_SOCLIST = j721s2
export vdam_SOCLIST
vdam_j721s2_CORELIST = $(vdam_CORELIST)
export vdam_j721s2_CORELIST
autosar_mcusw_LIB_LIST += vdam

autosar_stack_make_include := 1
endif
