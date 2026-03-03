include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = RunTimeStats

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  # MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

SRCDIR  += ./src
INCDIR  += ./inc

INCDIR  += ../../bookshelf/includes
INCDIR  += ../../bookshelf/PerformanceStats/AddRuntimeStats/inc
INCDIR  += ../../bookshelf/SignalMgr/gen
INCDIR  += ../../bookshelf/SignalMgr/inc

INCDIR += $(fisker_hydra_PATH)/mcu2_1/os/
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/AddRuntimeStats/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/RuntimeStats/inc
INCDIR += $(fisker_hydra_PATH)/platform/inc/
INCDIR += $(fisker_hydra_PATH)/platform/utils/
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Common
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/Us_Csm
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Platform/US_Platform_Source

INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Apps/MOTIntgr/MOT/algo/common
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgIf/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/gen
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/cfg
INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/cfg


INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/PerformanceStats/cpu_load/inc
INCDIR += $(PDK_BOARD_COMP_PATH)/src/j721s2_hyd/include
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/common
INCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/vim
INCDIR += $(fisker_hydra_PATH)/bookshelf/FuSa/magna/timers
INCDIR += $(fisker_hydra_PATH)/bookshelf/main_domain/console_io/include
SAFERTOS_PATH = $(TOOLS_INSTALL_PATH)/ti-psdk-rtos-j721s2-08_05_00_11/SafeRTOS_TI_CR5_Clang_TDA4VL_DAP_v9.4.1_SAFECheckpoints/source_code_and_projects/SafeRTOS
INCDIR += $(SAFERTOS_PATH)/api/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/config
INCDIR += $(SAFERTOS_PATH)/kernel/include_api
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5/024_Clang
INCDIR += $(SAFERTOS_PATH)/api/PrivWrapperStd
INCDIR += $(SAFERTOS_PATH)/checkpoints


SRCS_COMMON  += RunTimeStats.c

MCUSW_CFLAGS += -DADDRUNTIMESTATS

INCLUDE_EXTERNAL_INTERFACES += pdk bios xdc
INCLUDE_INTERNAL_INTERFACES += RunTimeStats signalmgr errormanager systemstate_manager ipc_manager CalDataProvider console_io app_utils_console_io

ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../../platform/asr/app_sip/GenData/$(CORE)
INCDIR += ../../platform/asr/app_sip/stubs/$(CORE)
INCDIR += ../../platform/asr/app_sip/Com/Implementation
INCDIR += ../../platform/asr/app_sip/Det/Implementation
INCDIR += ../../platform/asr/ti_mcal/CddIpc/include
INCDIR += ../../platform/asr/ti_mcal/Bsw_Stubs/Dem/inc
INCDIR += ../../platform/asr/app_sip/GenData/mcu1_0
INCDIR += ../../platform/asr/app_sip/Common/Implementation
endif

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
    # MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point


