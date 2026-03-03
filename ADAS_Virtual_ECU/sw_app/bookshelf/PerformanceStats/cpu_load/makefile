

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = cpu_load

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk
# Uncomment this label for printing CPU load on UART
LOG_CPU_LOAD_MCU2_1  = no


SRCDIR += ./src
INCDIR += ./inc

INCDIR  += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/SWC_APA
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/common_includes
INCDIR  += $(fisker_hydra_PATH)/bookshelf/SSM/inc
INCDIR  += $(fisker_hydra_PATH)/bookshelf/SSM/cfg
INCDIR  += $(fisker_hydra_PATH)/bookshelf/CalDataProvider/inc
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/KM/code
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark/CVADAS_AutoPark_ert_rtw/_sharedutils
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/_sharedutils
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/algo/_sharedutils
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc/algo/common
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc/TRSC_SM_VC_Int_ert_rtw
INCDIR  += $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter/FeatureArbiter_ert_rtw/_sharedutils
INCDIR  += $(fisker_hydra_PATH)/bookshelf/ErrorManager/gen
INCDIR  += $(fisker_hydra_PATH)/bookshelf/ErrorManager/inc
INCDIR  += $(fisker_hydra_PATH)/bookshelf/ErrorManager/cfg
INCDIR  += ../../../mcu2_1/App/USS/US_Includes
INCDIR  += $(fisker_hydra_PATH)/bookshelf/WdgFw/Wdg/inc



SRCS_COMMON    +=   	cpu_load.c

ifeq ($(LOG_CPU_LOAD_MCU2_1), yes)
MCUSW_CFLAGS += -DLOG_CPU_LOAD_MCU2_1
endif

INCLUDE_EXTERNAL_INTERFACES += pdk

INCLUDE_INTERNAL_INTERFACES = cpu_load console_io uart app_utils_console_io signalmgr 

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




