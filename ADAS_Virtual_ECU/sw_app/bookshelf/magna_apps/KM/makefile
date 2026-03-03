include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = KM

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

FEATURE_SRC_DIR = ./algo
WRAPPER_DIR = ./code

#Accommodating Changes for introducing multiple Tool Chains

INCDIR += ./algo/include/
INCDIR += ./algo/include/simulink/


INCDIR += ${wildcard $(FEATURE_SRC_DIR)/code/*}
INCDIR += ${wildcard $(FEATURE_SRC_DIR)/include/*.h}
INCDIR += ${wildcard $(FEATURE_SRC_DIR)/include/simulink/*}

INCDIR += $(fisker_hydra_PATH)/mcu2_1/App/USS/US_Includes
#depandant
INCDIR += ./../mecl
INCDIR += ./../
INCDIR += ./../platform


INCDIR += ../../includes/

# SRCS_CPP_COMMON += ./code/DataProviderKM.cpp
# SRCS_CPP_COMMON += ./code/JobKM.cpp
# SRCS_CPP_COMMON += ./code/KM.cpp

SRCS_COMMON += ./code/JobKM.c
SRCS_COMMON +=  ${wildcard $(FEATURE_SRC_DIR)/src/*.c}
SRCS_COMMON +=  ${wildcard $(FEATURE_SRC_DIR)/include/simulink/*.c}

INCLUDE_INTERNAL_INTERFACES = KM errormanager systemstate_manager ipc_manager apfusion
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