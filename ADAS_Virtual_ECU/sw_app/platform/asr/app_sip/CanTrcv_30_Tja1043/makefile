#TODO : Copied some patches over from Fisker - need to re-evaluate later on if needed.
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = cantrcv_tja1043

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = Implementation
SRCDIR += ../GenData/$(CORE) ../GenData/$(CORE)/Components

INCDIR = ../BswM/Implementation
INCDIR += ../CanIf/Implementation
INCDIR += ../Can_30_Mcan/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../stubs/$(CORE)
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/include
INCDIR += ../GenData/$(CORE)/Components
INCDIR += ../../ti_mcal/Dio/include
INCDIR += ../CanTp/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
endif
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation




INCLUDE_INTERNAL_INTERFACES = cantrcv_tja1043
UtilsPriv_INCLUDE =

SRCS_COMMON += CanTrcv_30_Tja1043.c CanTrcv_30_Tja1043_Cfg.c


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
