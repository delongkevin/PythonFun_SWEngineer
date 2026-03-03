
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = wdgif_magna

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = ./src
#SRCDIR += ./cfg
INCLUDE_INTERNAL_INTERFACES += wdgif_magna

#INCDIR += ./../Common
INCDIR += ./../../../includes
INCDIR += ../Wdg/inc
INCDIR += $(fisker_hydra_PATH)/bookshelf/WdgFw/WdgIf/inc
INCDIR += $(fisker_hydra_PATH)/platform/inc
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/Common/Implementation
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/GenData/mcu1_0
#INCDIR += $(fisker_hydra_PATH)/bookshelf/ErrorManager/inc


#INCDIR += ../Wdg/inc


UtilsPriv_INCLUDE =

SRCS_COMMON += WdgIf.c


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
