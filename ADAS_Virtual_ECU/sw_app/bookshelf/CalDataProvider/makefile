

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = CalDataProvider

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk



SRCDIR += ./src
INCDIR += ./../../../common/includes/
INCDIR += ../../mcu1_0/app/boot
INCDIR += ../includes





SRCS_COMMON    +=   	CalDataProvider_impl.c



INCLUDE_EXTERNAL_INTERFACES += pdk bios xdc

INCLUDE_INTERNAL_INTERFACES = CalDataProvider systemstate_manager ipc_manager


#include RTE Depenencies
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCLUDE_INTERNAL_INTERFACES += gendata os bswm nvm
endif

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




