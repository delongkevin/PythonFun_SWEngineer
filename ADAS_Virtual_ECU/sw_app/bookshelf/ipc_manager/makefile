
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = ipc_manager

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains

SRCDIR = ./src

INCDIR = ../../platform/inc
INCDIR += ../../bookshelf/includes
INCDIR += ../../bookshelf/SignalMgr/gen
INCDIR += ../../bookshelf/SignalMgr/inc
INCDIR += ../../bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += ../../bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += ../../bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR += ../../bookshelf/magna_apps/trsc/code
INCDIR += ../../bookshelf/ErrorManager/gen
INCDIR += ../../bookshelf/ErrorManager/inc
INCDIR += ../../bookshelf/ErrorManager/cfg
INCDIR += ../../bookshelf/SSM/inc
INCDIR += ../../bookshelf/SSM/cfg
INCDIR += ../../bookshelf/CalDataProvider/inc
INCDIR += ../../mcu2_1/App/USS/US_Includes
INCDIR += $(autopark_INCLUDE)
INCDIR += $(tha_sm_vc_INCLUDE)
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += ../../bookshelf/magna_apps/mecl
INCDIR += ../../bookshelf/WdgFw/Wdg/inc

INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/meal
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw

ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCDIR += ../../platform/asr/app_sip/GenData/$(CORE)
INCDIR += ../../platform/asr/app_sip/stubs/$(CORE)
INCDIR += ../../platform/asr/app_sip/Com/Implementation
INCDIR += ../../platform/asr/app_sip/Det/Implementation
INCDIR += ../../platform/asr/ti_mcal/CddIpc/include
INCDIR += ../../platform/asr/ti_mcal/Bsw_Stubs/Dem/inc
INCDIR += ../../platform/asr/app_sip/GenData/mcu1_0
INCDIR += ../../platform/asr/app_sip/Common/Implementation
endif

INCLUDE_INTERNAL_INTERFACES += ipc_manager

ifeq ($(CORE),$(filter $(CORE), mcu2_1 mcu3_0))
INCLUDE_INTERNAL_INTERFACES += signalmgr uart errormanager CalDataProvider systemstate_manager
endif

ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
INCLUDE_INTERNAL_INTERFACES += os gendata cddipc CalDataProvider
endif

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

# List all the components required by the application
#ifeq ($(CORE),$(filter $(CORE), mcu1_0 mcu3_1))
#COMP_LIST_COMMON = cddipc
#endif

UtilsPriv_INCLUDE =

SRCS_COMMON = ipc_manager.c
SRCS_COMMON += ipc_large_buff_mgr.c
SRCS_COMMON += ipc_lookup_table.c
SRCS_COMMON += ipc_crc.c
SRCS_COMMON += ipc_diag.c
SRCS_COMMON += ipc_error.c
#ifeq ($(CORE),$(filter $(CORE), mcu1_0))
#SRCS_COMMON += Rte_Dummy.c
#endif
PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS)

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
