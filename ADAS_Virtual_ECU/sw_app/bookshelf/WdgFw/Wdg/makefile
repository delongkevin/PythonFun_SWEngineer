
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = wdg_magna

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = ./src
INCLUDE_INTERNAL_INTERFACES += wdg_magna


ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCDIR += ./../../../platform/asr/app_sip/WdgM/Implementation
INCDIR += ./../../../platform/asr/app_sip/WdgIf/Implementation
INCDIR += ./../../../platform/asr/app_sip/Common/Implementation
INCDIR += ./../../../platform/asr/app_sip/GenData/$(CORE)
INCDIR += ./../../../platform/asr/app_sip/Dem/Implementation
INCDIR += ./../../../platform/asr/app_sip/GenData/$(CORE)/Components
INCDIR += ./../../../platform/asr/app_sip/Os/Implementation
INCDIR += ./../../../platform/asr/app_sip/VStdLib/Implementation
INCDIR += ./../../../platform/asr/app_sip/Com/Implementation
INCDIR += ./../../../platform/asr/app_sip/Det/Implementation
INCDIR += ./../../../mcu1_0/app/boot
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(PDK_INSTALL_PATH)/
else
INCDIR += ./../Common
INCDIR += ./../../../includes
ifeq ($(CORE),$(filter $(CORE), mcu2_1 mcu3_0))
INCDIR += ./../WdgM_Magna/inc
INCDIR += ./../WdgM_Magna/cfg
INCDIR += ./../WdgM_Magna/cfg/$(CORE)
else
INCDIR += ./../WdgM/inc
INCDIR += ./../WdgM/cfg
INCDIR += ./../WdgM/cfg/$(CORE)
endif
INCDIR += ./../WdgIf/inc
INCDIR += ./../../SignalMgr/gen
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/gen
INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/cfg
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += ./../../../mcu1_0/app/boot
INCDIR += $(fisker_hydra_PATH)/platform/inc
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/Common/Implementation
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/GenData/mcu1_0
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/common/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/common 
#C:\git\L2H4060_Software\sw\bookshelf\magna_apps\Arbiter\FeatureArbiter_ert_rtw\_sharedutils

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw


#INCDIR += $(fisker_hydra_PATH)/common/magna_apps/hsf/algo/Sq1/_sharedutils
#INCDIR += $(fisker_hydra_PATH)/common/magna_apps/hsf/algo/Sq2/_sharedutils
#INCDIR += $(fisker_hydra_PATH)/common/magna_apps/hsf/algo/Sq3/_sharedutils
#INCDIR += $(fisker_hydra_PATH)/common/magna_apps/hsf/algo/Sq4/_sharedutils
#INCDIR += $(fisker_hydra_PATH)/common/magna_apps/hsf/algo/Sq5/_sharedutils

INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/cfg
INCLUDE_INTERNAL_INTERFACES += signalmgr
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../WdgSlave/inc
endif

ifeq ($(CORE),$(filter $(CORE), mcu3_1))
INCDIR += $(fisker_hydra_PATH)bookshelf/ipc_manager/inc
endif

UtilsPriv_INCLUDE =

SRCS_COMMON += Wdg.c


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
