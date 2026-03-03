#Default App Log Levels
APP_LOG_LEVEL ?= 1

include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = stubs

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk


#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = $(CORE)
SRCDIR += ../GenData/$(CORE) ../GenData/$(CORE)/Components


INCDIR = ../BswM/Implementation
INCDIR += ../vDiagSecAcc/Implementation
INCDIR += ../vDam/Implementation
INCDIR += ../CanIf/Implementation
INCDIR += ../Can_30_Mcan/Implementation
INCDIR += ../CanSM/Implementation
INCDIR += ../Com/Implementation
INCDIR += ../Xcp/Implementation
INCDIR += ../CanXcp/Implementation
INCDIR += ../ComM/Implementation
INCDIR += ../Det/Implementation
INCDIR += ../EcuM/Implementation
INCDIR += ../IoHwAb/Implementation
INCDIR += ../stubs/$(CORE)
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/include
INCDIR += ../GenData/$(CORE)/Components
INCDIR += ../vRoE/Implementation
INCDIR += ../CryIf/Implementation
INCDIR += ../WdgIf/Implementation
INCDIR += ../WdgM/Implementation
INCDIR += ../../../../bookshelf/SSM/inc
INCDIR += ../../../../bookshelf/WdgFw/Wdg/inc
INCDIR += ../Crypto_30_vHsm/Implementation
INCDIR += ../Csm/Implementation
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../CanTp/Implementation
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../../ti_mcal/Dio/include
INCDIR += ../../ti_mcal/Adc/include
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
INCDIR += ../../../../common/pmic

INCDIR += ../../../../common/pmic/pmic_thermal_warning_and_shutdown
INCDIR +=../../../../bookshelf/main_domain/console_io/include
INCDIR +=../../../../mcu1_0/app/boot


INCDIR += $(PDK_INSTALL_PATH)/ti/drv/pmic
INCDIR += $(PDK_INSTALL_PATH)/ti/drv/pmic/include
INCDIR +=../../../../bookshelf/includes

#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/VehicleComms
#INCDIR += $(MCUSW_INSTALL_PATH)/mcu1_0/app/Diagnostics
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
INCDIR += ../CanTrcv_30_Generic/Implementation
INCDIR += ../../ti_mcal/Bsw_Stubs/Dem/inc
INCDIR += ../EthIf/Implementation
INCDIR += ../EthSM/Implementation
INCDIR += ../IpBase/Implementation
INCDIR += ../TcpIp/Implementation
INCDIR += ../SoAd/Implementation
INCDIR += ../../../includes
endif
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../../ti_mcal/CddIpc/include
INCDIR += ../../ti_mcal/Eth/include
INCDIR += ../../ti_mcal/Eth/src/cpsw/include
INCDIR += ../../ti_mcal/output/include
INCDIR += ../../ti_mcal/Bsw_Stubs/MemMap/inc



INCLUDE_EXTERNAL_INTERFACES = pdk

INCLUDE_INTERNAL_INTERFACES = stubs
UtilsPriv_INCLUDE =

SRCS_COMMON += BswM_Callout_Stubs.c EcuM_Callout_Stubs.c Os_Callout_Stubs.c AppDiag_Services.c IPC_Stubs.c NvM_Callout_Stubs.c
#IPC_Stubs.c
ifeq ($(CORE),$(filter $(CORE), mcu3_1))
SRCS_COMMON += Dio_Stub.c
#SRCS_COMMON += EthVirtmacApp.c SchM_Eth.c
#SRCS_COMMON += EthTrcv_30_Generic.c Eth_30_Generic.c Dem.c L2H5010_PrivateFCM_SWC.c
endif
#SRCS_COMMON += arti.c arti_t32_logger.c


PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS)

ifneq ($(APP_LOG_LEVEL), "")
    CFLAGS_LOCAL_COMMON += -DAPP_LOG_LEVEL=$(APP_LOG_LEVEL)
endif

#CFLAGS_LOCAL_COMMON += --diag_suppress=112
#CFLAGS_LOCAL_COMMON += --diag_suppress=552
#CFLAGS_LOCAL_COMMON += --diag_suppress=225 #ignore implicit functions
#CFLAGS_LOCAL_COMMON += --diag_suppress=190 #ignore differentse between enumerated types (TI uses enum, vector uses macros)
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
