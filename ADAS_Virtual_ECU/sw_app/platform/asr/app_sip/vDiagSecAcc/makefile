
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = vdiagsecacc

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
INCDIR += ../vDiagSecAcc/Implementation
INCDIR += ../Csm/Implementation
INCDIR += ../Crypto_30_vHsm/Implementation
INCDIR += ../Crypto_30_vHsm/Implementation
INCDIR += ../CanIf/Implementation
INCDIR += ../Can_30_Mcan/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
INCDIR += ../stubs/$(CORE)
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/Components
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
#INCDIR += ../CanTrcv_30_Generic/Implementation
INCDIR += ../CanTp/Implementation
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../Crc/Implementation
endif
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation


INCLUDE_INTERNAL_INTERFACES = vdiagsecacc
UtilsPriv_INCLUDE =

#Static Files from SIP
SRCS_COMMON += vDiagSecAcc.c

#Generated Files
SRCS_COMMON += vDiagSecAcc_Cfg.c


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
