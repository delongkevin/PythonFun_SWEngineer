
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = autopark

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

FEATURE_SRC_DIR = ./CVADAS_AutoPark_ert_rtw
CODE_DIR = ./code

#Accommodating Changes for introducing multiple Tool Chains

SRCDIR += code
SRCDIR += ./CVADAS_AutoPark_ert_rtw/_sharedutils
SRCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_APA
SRCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_VC
SRCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_AP_StateMachine
SRCDIR += ./CVADAS_AutoPark_ert_rtw/DT24_CVADAS_AP_CodGen
SRCDIR += ./CVADAS_AutoPark_ert_rtw/DT24_CVADAS_AutoPark_Func
SRCDIR += ./CVADAS_AutoPark_ert_rtw/Rear_ObjectDection

INCDIR = code
INCDIR += ./CVADAS_AutoPark_ert_rtw/_sharedutils
INCDIR += ./CVADAS_AutoPark_ert_rtw/common/inc
INCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_VC
INCDIR += ./CVADAS_AutoPark_ert_rtw/SWC_AP_StateMachine
INCDIR += ./CVADAS_AutoPark_ert_rtw/DT24_CVADAS_AP_CodGen
INCDIR += ./CVADAS_AutoPark_ert_rtw/DT24_CVADAS_AutoPark_Func
INCDIR += ./CVADAS_AutoPark_ert_rtw/Rear_ObjectDection
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(tha_sm_vc_PATH)/algo/_sharedutils
INCDIR += $(tha_sm_vc_PATH)/algo/common

INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/SSM/cfg

INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/meal
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/TRSC_OutputAdapter
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc



SRCS_COMMON  = ${wildcard $(FEATURE_SRC_DIR)/_sharedutils/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/SWC_APA/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/SWC_VC/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/SWC_AP_StateMachine/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/Rear_ObjectDection/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/DT24_CVADAS_AP_CodGen/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/DT24_CVADAS_AutoPark_Func/*.c}
SRCS_CPP_COMMON += ${wildcard $(CODE_DIR)/*.cpp}

ifeq ($(CORE),$(filter $(CORE), mcu2_1 mcu3_0))
INCLUDE_INTERNAL_INTERFACES += signalmgr errormanager CalDataProvider systemstate_manager autopark
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCLUDE_INTERNAL_INTERFACES += os gendata cddipc CalDataProvider
endif

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk uart 

# List all the components required by the application
#ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
#COMP_LIST_COMMON = cddipc
#endif

UtilsPriv_INCLUDE =

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON += $(MCUSW_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
