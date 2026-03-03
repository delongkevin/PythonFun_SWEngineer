#
#   Copyright (c) 2021, Texas Instruments Incorporated
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#   *  Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   *  Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
#   *  Neither the name of Texas Instruments Incorporated nor the names of
#      its contributors may be used to endorse or promote products derived
#      from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

#NAME = mpu10ipc-ipcmgr
NAME = ipcmgr
INSTALLDIR = bin
USEFILE=$(PROJECT_ROOT)/$(NAME).use

define PINFO
PINFO DESCRIPTION=TI IPC-LLD Ipc Manager
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CCOPTS += -fPIC
CCOPTS += -D$(SOC_UPPER) -DBUILD_MPU1_0 -DIPC_SUPPORT_SCICLIENT -DQNX_OS -DBUILD_MCUQNX
CCOPTS += -DVISION_APPS_BUILD_FLAGS_MAK=$(VISION_APPS_BUILD_FLAGS_MAK)

#Add extra include path	sw/bookshelf/ipc_manager/inc/
EXTRA_INCVPATH += $(PDK_QNX_PATH)/packages
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/ipc_manager/inc
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/ookshelf/ipc_manager/inc
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/ipc_manager/cfg
EXTRA_INCVPATH += $(PROJECT_ROOT)/src/qnx_inc
EXTRA_INCVPATH += $(PROJECT_ROOT)/sw/bookshelf/magna_apps/AutoPark/Include/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/magna_apps/AutoPark/Include/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/includes/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/SignalMgr/gen/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/SignalMgr/inc/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/SSM/inc
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/SSM/cfg
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/includes
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/magna_apps
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/magna_apps/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/apa
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/apa/common
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/apa/fpa
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/cd
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/common
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/hsf
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/lsf
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/mecl
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/CalDataProvider/inc/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/gen/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/inc/
EXTRA_INCVPATH += $(ME_REPO_ROOT)/sw/bookshelf/ErrorManager/cfg/
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/common_includes
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/algo/_sharedutils
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/code
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/_sharedutils
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/tha_sm_vc/algo/common
EXTRA_INCVPATH += ${PSDK_RTOS_PATH}/vision_apps/platform/j721s2/qnx
EXTRA_INCVPATH += ${PSDK_RTOS_PATH}/vision_apps/platform/j721s2/rtos
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/KM/code
EXTRA_INCVPATH += $(ME_SDK_INSTALL_PATH)/vision_apps/utils/console_io/include
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/WdgFw/Wdg/inc
#Add source path
EXTRA_SRCVPATH +=$(ME_REPO_ROOT)/sw/bookshelf/ipc_manager/src
EXTRA_SRCVPATH +=$(PROJECT_ROOT)/src/os/
EXTRA_INCVPATH += $(ME_BOOKSHELF_PATH)/../mcu2_1/App/USS/US_Includes

LIBS = c
#LIBS       += $(PDK_QNX_PATH)/../../qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/

#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/../qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/
#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/drv/ipc/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/
#EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/csl/lib/$(BOOTMODE)/$(SOC)/qnx_a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/ti/board/lib/$(BOOTMODE)/$(BOARD)/a72/$(BUILD_PROFILE)/
EXTRA_LIBVPATH += $(PDK_QNX_PATH)/packages/ti/board/lib/$(BOOTMODE)/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/

EXTRA_LIBVPATH += ${PSDK_RTOS_PATH}/vision_apps/lib/J721S2/A72/QNX/release/
EXTRA_LIBVPATH += ${PSDK_RTOS_PATH}/vision_apps/out/J721S2/A72/QNX/release/
EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/a.le/

LIBS +=:libapp_rtos_qnx_mpu1_common.a
LIBS +=:libapp_utils_mem.a
LIBS +=:libapp_utils_ipc.a
LIBS +=:libapp_utils_console_io.a
LIBS +=:libapp_utils_remote_service.a
LIBS +=:libapp_utils_perf_stats.a

LIBS +=:libsharedmemallocator.a

LIBS +=:ti.osal.aa72fg
#LIBS +=:ipc.aa72fg
LIBS +=:ti.csl.aa72fg
LIBS +=:sciclient.aa72fg
LIBS +=:ti.csl.aa72fg
LIBS +=:ti.osal.aa72fg
LIBS +=:ti.board.aa72fg
LIBS +=:libtiipc-usr.a

include $(MKFILES_ROOT)/qtargets.mk

