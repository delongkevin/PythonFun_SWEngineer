
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = bswm

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = Implementation
SRCDIR += ../GenData/$(CORE) ../GenData/$(CORE)/Components

INCDIR = ../Can_30_Mcan/Implementation
INCDIR += ../vDiagSecAcc/Implementation
INCDIR += ../vDam/Implementation
INCDIR += ../CanIf/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Xcp/Implementation
INCDIR += ../CanXcp/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/include
INCDIR += ../GenData/$(CORE)/Components
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../CanTp/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
INCDIR += ../IoHwAb/Implementation
INCDIR += ../vRoE/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../CryIf/Implementation
INCDIR += ../WdgIf/Implementation
INCDIR += ../WdgM/Implementation
INCDIR += ../../../../bookshelf/WdgFw/Wdg/inc
INCDIR += ../../../../bookshelf/SSM/inc
INCDIR += ../Crypto_30_vHsm/Implementation
INCDIR += ../Csm/Implementation
INCDIR += ../stubs/$(CORE)
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../../ti_mcal/Dio/include
INCDIR += ../../ti_mcal/Adc/include
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../CanTrcv_30_Tja1043/Implementation
#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/VehicleComms
endif


INCLUDE_INTERNAL_INTERFACES = bswm
UtilsPriv_INCLUDE =

SRCS_COMMON += BswM.c BswM_Lcfg.c


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
