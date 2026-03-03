
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = wdgm_magna

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = ./src
SRCDIR += ./cfg ./cfg/$(CORE)
INCLUDE_INTERNAL_INTERFACES += wdgm_magna

INCDIR += ./../Common
INCDIR += ./../../../includes
INCDIR += $(fisker_hydra_PATH)/bookshelf/includes


# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

UtilsPriv_INCLUDE =

SRCS_COMMON += WdgM.c WdgM_Checkpoint.c WdgM_Intr.c
SRCS_COMMON += WdgM_Cfg.c


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
