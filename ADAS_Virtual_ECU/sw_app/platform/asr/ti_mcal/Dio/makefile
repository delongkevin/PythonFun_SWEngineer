include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = dio

SRCDIR = src
SRCDIR += ../../app_sip/GenData/$(CORE)/src


INCDIR =  ../../app_sip/Common/Implementation
INCDIR += ../../app_sip/VStdLib/Implementation
INCDIR += ../../app_sip/Com/Implementation
INCDIR += ../../app_sip/GenData/$(CORE)
INCDIR += ../../app_sip/GenData/$(CORE)/include
INCDIR += ../../app_sip/GenData/$(CORE)/Components
INCDIR += ../../app_sip/Os/Implementation
INCDIR += ../../app_sip/Det/Implementation
INCDIR += ../../app_sip/Dem/Implementation

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk
# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES = dio

MODULE_SRC_BASE_PATH := $($(CORE)_mcal_PATH)/Dio

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON += Dio.c DioApp.c Dio_Cfg.c Dio_Lcfg.c

ifeq ($(SOC),$(filter $(SOC), j721e))
SRCS_COMMON += Dio_PlatformJ721e.c
endif

ifeq ($(SOC),$(filter $(SOC), j7200))
SRCS_COMMON += Dio_PlatformJ7200.c
endif

ifeq ($(SOC),$(filter $(SOC), j721s2))
SRCS_COMMON += Dio_PlatformJ721s2.c
endif

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
