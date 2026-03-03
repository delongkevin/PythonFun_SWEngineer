
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


SAFERTOS_PATH = $(TOOLS_INSTALL_PATH)/ti-psdk-rtos-j721s2-08_05_00_11/SafeRTOS_TI_CR5_Clang_TDA4VL_DAP_v9.4.1_SAFECheckpoints/source_code_and_projects/SafeRTOS
INCDIR += $(SAFERTOS_PATH)/api/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/config
INCDIR += $(SAFERTOS_PATH)/kernel/include_api
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5
INCDIR += $(SAFERTOS_PATH)/portable/199_TI_CR5/024_Clang
INCDIR += $(SAFERTOS_PATH)/api/PrivWrapperStd
INCDIR += $(SAFERTOS_PATH)/checkpoints
#INCDIR += $(MCUSW_INSTALL_PATH)/common/includes
INCDIR += $(MCUSW_INSTALL_PATH)/bookshelf/includes
INCDIR += $(MCUSW_INSTALL_PATH)/common/magna_basesw/WdgFw/WdgIf_Magna/inc

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk

UtilsPriv_INCLUDE =

SRCS_COMMON += WdgM.c
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
