
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = console_io

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains

SRCDIR = ./src
INCDIR = ./include

INCLUDE_INTERNAL_INTERFACES += console_io  os gendata
ifeq ($(BUILD_OS_TYPE),$(filter $(BUILD_OS_TYPE), autosaros))
INCLUDE_INTERNAL_INTERFACES += os gendata
endif


# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk xdc bios


SRCS_COMMON = app_log_reader.c app_log_writer.c app_get.c app_log_autosar.c
ifeq ($(BUILD_OS_TYPE),$(filter $(BUILD_OS_TYPE), tirtos))
SRCS_COMMON += app_log_sysbios.c
else ifeq ($(BUILD_OS_TYPE),$(filter $(BUILD_OS_TYPE), autosaros))
SRCS_COMMON += app_log_autosar.c
else ifeq ($(BUILD_OS_TYPE),$(filter $(BUILD_OS_TYPE), freertos))
SRCS_COMMON += app_log_freertos.c
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
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
