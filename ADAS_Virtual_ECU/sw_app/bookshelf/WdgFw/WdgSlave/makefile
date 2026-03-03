
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = wdgSlave

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = ./src
INCLUDE_INTERNAL_INTERFACES += wdgSlave


INCDIR += ./inc
INCDIR += ./../../../platform/asr/app_sip/WdgM/Implementation
INCDIR += ./../../../platform/asr/app_sip/WdgIf/Implementation
INCDIR += ./../../../platform/asr/app_sip/Common/Implementation
INCDIR += ./../../../platform/asr/app_sip/GenData/$(CORE)
INCDIR += ./../../../platform/asr/app_sip/GenData/mcu1_0
INCDIR += ./../../../platform/asr/app_sip/VStdLib/Implementation
INCDIR += ./../../../platform/asr/app_sip/Dem/Implementation
INCDIR += ./../../../platform/asr/app_sip/Com/Implementation
INCDIR += ./../../../platform/asr/app_sip/Det/Implementation
INCDIR += ./../../../platform/asr/app_sip/GenData/$(CORE)/Components
INCDIR += ./../../../platform/asr/app_sip/Os/Implementation
INCDIR += ./../../SignalMgr/gen
INCDIR += ./../Wdg/inc
INCDIR += ./../Wdg/cfg
INCDIR += ./../../includes

INCDIR += $(fisker_hydra_PATH)/mcu1_0/source/boot/



UtilsPriv_INCLUDE =

SRCS_COMMON += WdgSlave.c

INCDIR += ./../../../../common/includes/
INCDIR += ./../../FuSa/fusa_app
INCDIR += $(PDK_SDL_COMP_PATH)/
INCDIR += $(PDK_SDL_COMP_PATH)/src/sdl
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
