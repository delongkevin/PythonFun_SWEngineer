

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = systemstate_manager

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

SRCDIR += ./src

INCDIR += ../../bookshelf/includes
INCDIR += ../../bookshelf/CalDataProvider/inc
INCDIR += ../../bookshelf/ipc_manager/inc
INCDIR += ../../mcu2_1/App/USS/US_Includes
INCDIR += $(autopark_INCLUDE)
INCDIR += $(tha_sm_vc_INCLUDE)
INCDIR += ../../bookshelf/includes/WdgFw/Wdg/inc
INCDIR += ../../bookshelf/main_domain/console_io/include
INCDIR += ../../mcu1_0/app/boot
INCDIR += ./../../common/pmic
INCDIR += $(PSDK_INSTALL_PATH)/pdk_j721s2_08_05_00_36/packages/ti/drv/pmic/include

INCDIR += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/mecl
INCDIR += $(fisker_hydra_PATH)/mpu1_0/linux/puc/App/code/Framework/CoreLibs/meal
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA

INCLUDE_INTERNAL_INTERFACES += errormanager systemstate_manager CalDataProvider

#include signal manager dependencies
ifeq ($(CORE),$(filter $(CORE), mcu2_1))
INCLUDE_INTERNAL_INTERFACES += signalmgr 
endif

#include RTE Depenencies
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCLUDE_INTERNAL_INTERFACES += gendata os bswm
endif

SRCS_COMMON    +=   	SSM_Slave.c \
						SSM_Slave_app.c \
						SSM_Master.c \
						SSM_Master_app.c



INCLUDE_EXTERNAL_INTERFACES += pdk bios xdc


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




