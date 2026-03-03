
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = Arbiter

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

FEATURE_SRC_DIR = ./FeatureArbiter_ert_rtw
CODE_DIR = ./code

#Accommodating Changes for introducing multiple Tool Chains

SRCDIR += code
SRCDIR += ./FeatureArbiter_ert_rtw

INCDIR = code
INCDIR += ./FeatureArbiter_ert_rtw
INCDIR += ./FeatureArbiter_ert_rtw/_sharedutils

INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/common
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc

SRCS_COMMON  = ${wildcard $(FEATURE_SRC_DIR)/*.c}
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
