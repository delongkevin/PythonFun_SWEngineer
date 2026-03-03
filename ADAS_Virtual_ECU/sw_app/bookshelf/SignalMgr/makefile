

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = signalmgr

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR += ./gen
SRCDIR += ./src

INCDIR += ../../platform/inc
INCDIR += ../../bookshelf/includes
INCDIR += ../../bookshelf/SSM/inc
INCDIR += ../../bookshelf/SSM/cfg
INCDIR += ../../bookshelf/CalDataProvider/inc
INCDIR += ../../mcu2_1/App/USS/US_Includes
INCDIR += ../../bookshelf/WdgFw/Wdg/inc
INCDIR += $(autopark_INCLUDE)
INCDIR += $(tha_sm_vc_INCLUDE)

INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += ../../bookshelf/magna_apps/mecl
INCDIR += ../../bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += ../../bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/meal
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc

ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCDIR += ../../platform/asr/app_sip/GenData/$(CORE)
INCDIR += ../../platform/asr/app_sip/Common/Implementation
endif

SRCS_CPP_COMMON    += 	SignalDef.cpp 
SRCS_CPP_COMMON    +=		SignalMgrBase.cpp 

SRCS_COMMON        +=   	SignalMgr.c
SRCS_COMMON        +=			SigMgr_IpcBridge.c

INCLUDE_EXTERNAL_INTERFACES += pdk bios xdc
INCLUDE_INTERNAL_INTERFACES += signalmgr errormanager systemstate_manager ipc_manager CalDataProvider console_io

UtilsPriv_INCLUDE =

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
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
