include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = AddRuntimeStats

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  # MAKERULEDIR := $(ME_PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

SRCDIR  += ./src
INCDIR  += ./inc

INCDIR  += ../../../bookshelf/includes
INCDIR  += $(fisker_hydra_PATH)/bookshelf/includes
INCDIR  += $(fisker_hydra_PATH)/mcu2_1/os/

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

SRCS_COMMON    +=   	AddRuntimeStats.c

MCUSW_CFLAGS += -DADDRUNTIMESTATS

INCLUDE_EXTERNAL_INTERFACES += pdk bios xdc

INCLUDE_INTERNAL_INTERFACES = AddRuntimeStats console_io uart app_utils_console_io console_io

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


