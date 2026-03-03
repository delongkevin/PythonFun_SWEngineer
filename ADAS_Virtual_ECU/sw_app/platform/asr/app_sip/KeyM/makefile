
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = KeyM

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
INCDIR += ../Can_30_Mcan/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../stubs/$(CORE)
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/Components
INCDIR += ../../ti_mcal/Adc/include
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../CanTp/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../IoHwAb/Implementation
INCDIR += ../../ti_mcal/Dio/Include
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
INCDIR += ../CanTrcv_30_Generic/Implementation
endif



INCLUDE_INTERNAL_INTERFACES = KeyM
UtilsPriv_INCLUDE =


SRCS_COMMON += KeyM.c
SRCS_COMMON += KeyM_Asn1.c
SRCS_COMMON += KeyM_Cert.c
SRCS_COMMON += KeyM_Remote.c
#gendata
SRCS_COMMON += KeyM_Cfg.c

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
