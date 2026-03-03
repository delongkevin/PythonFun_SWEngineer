
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = tha_sm_vc

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

FEATURE_SRC_DIR = ./algo
CODE_DIR = ./code

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR += code
SRCDIR += algo/_sharedutils
SRCDIR += algo/THA_SM_Ref
SRCDIR += algo/THA_SmVc_Ref
SRCDIR += algo/THA_VC_Ref
SRCDIR += THA_SWC_ert_rtw

INCDIR += code
INCDIR += algo/_sharedutils
INCDIR += algo/THA_SM_Ref
INCDIR += algo/THA_SmVc_Ref
INCDIR += algo/THA_VC_Ref
INCDIR += algo/common
INCDIR += THA_SWC_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/meal
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc
#dependant AutoPark
INCDIR += $(autopark_INCLUDE)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw

#src
SRCS_COMMON  = ${wildcard $(FEATURE_SRC_DIR)/_sharedutils/*.c}      
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/THA_SM_Ref/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/THA_SmVc_Ref/*.c}
SRCS_COMMON += ${wildcard $(FEATURE_SRC_DIR)/THA_VC_Ref/*.c}
SRCS_COMMON += ${wildcard THA_SWC_ert_rtw/*.c}
SRCS_COMMON += ${wildcard $(CODE_DIR)/*.c}

#depenandant
THA_SM_VC_OFFLINE_TESTING = no

ifeq ($(THA_SM_VC_OFFLINE_TESTING), yes)
CFLAGS_LOCAL_COMMON += -DTHA_SM_VC_OFFLINE_TESTING
SRCDIR += simulation
INCDIR += simulation
SRCS_COMMON  += ${wildcard simulation/*.c}
endif

ifeq ($(CORE),$(filter $(CORE), mcu2_1 mcu3_0))
INCLUDE_INTERNAL_INTERFACES += signalmgr errormanager CalDataProvider systemstate_manager tha_sm_vc
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCLUDE_INTERNAL_INTERFACES += os gendata cddipc CalDataProvider
endif

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk uart 

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
