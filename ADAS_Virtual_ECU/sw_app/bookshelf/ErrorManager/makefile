

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = errormanager

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains


SRCDIR += ./gen
SRCDIR += ./src
INCDIR += ./../../platform/inc/
INCDIR += ../../bookshelf/SSM/inc
INCDIR += ../../bookshelf/SSM/cfg
INCDIR += ../../bookshelf/CalDataProvider/inc
INCDIR += ../../mcu2_1/App/USS/US_Includes
INCDIR += ../../bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += ../../bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA

INCDIR += $(autopark_INCLUDE)
INCDIR += $(tha_sm_vc_INCLUDE)
INCDIR += $(fisker_hydra_PATH)/bookshelf/ipc_manager/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc


INCLUDE_INTERNAL_INTERFACES = errormanager systemstate_manager CalDataProvider ipc_manager

ifeq ($(CORE),$(filter $(CORE), mcu2_1 mcu3_0))
INCLUDE_INTERNAL_INTERFACES += signalmgr
endif

#ifeq ($(CORE),mcu1_0)
#INCLUDE_INTERNAL_INTERFACES += gendata os bswm
#endif

INCLUDE_EXTERNAL_INTERFACES = pdk



SRCS_COMMON = ErrorManagerAggDef.c
SRCS_COMMON += ErrorManagerAggregatorDef_B.c
SRCS_COMMON += ErrorManagerAggregatorDef_QM.c
SRCS_COMMON += ErrorManagerCallbacks_QM.c
SRCS_COMMON += ErrorManagerCallbacks_B.c
SRCS_COMMON += ErrorManagerAggregator.c
SRCS_COMMON += ErrorManagerAggregatorApp.c
SRCS_COMMON += ErrorManagerDef.c
SRCS_COMMON += ErrorManagerSatDef.c
SRCS_COMMON += ErrorManagerSatelliteDef_B.c
SRCS_COMMON += ErrorManagerSatelliteDef_QM.c
SRCS_COMMON += ErrorManagerSatellite.c
SRCS_COMMON += ErrorManagerSatelliteApp.c





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
