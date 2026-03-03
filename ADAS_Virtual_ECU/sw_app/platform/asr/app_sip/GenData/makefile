
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = gendata

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = Implementation
SRCDIR += ../GenData/$(CORE) ../GenData/$(CORE)/src ../GenData/$(CORE)/Components

INCDIR = ../BswM/Implementation
INCDIR += ../vDam/Implementation
INCDIR += ../CanIf/Implementation
INCDIR += ../Can_30_Mcan/Implementation
INCDIR += ../CanXcp/Implementation
INCDIR += ../Xcp/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../vRoE/Implementation
INCDIR += ../stubs/$(CORE)
INCDIR += ../CryIf/Implementation
INCDIR += ../WdgIf/Implementation
INCDIR += ../WdgM/Implementation
INCDIR += ../../../../bookshelf/WdgFw/Wdg/inc
INCDIR += ../../../../bookshelf/SSM/inc
INCDIR += ../Crypto_30_vHsm/Implementation
INCDIR += ../Csm/Implementation
INCDIR += ../VStdLib/Implementation
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../../ti_mcal/Dio/include
INCDIR += ../../ti_mcal/Adc/include
INCDIR += ../../ti_mcal/CddIpc/include
INCDIR += ../Dcm/Implementation
#Added following line Dem/Implementation for compile : ShruthiRaghavan
INCDIR += ../Dem/Implementation
#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/EepManager
#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/Diagnostics
#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/PowerManagement
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
INCDIR += ../CanTrcv_30_Generic/Implementation
INCDIR += ../EthIf/Implementation
INCDIR += ../EthSM/Implementation
INCDIR += ../IpBase/Implementation
INCDIR += ../TcpIp/Implementation
INCDIR += ../SoAd/Implementation
endif

INCLUDE_INTERNAL_INTERFACES = gendata
UtilsPriv_INCLUDE =

SRCS_COMMON += Rte.c Rte_SystemApplication_OsCore0.c Rte_OsApplication_QM.c Rte_OsApplication_Safety.c# Rte_OsApplication_Trusted_Core0.c


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
