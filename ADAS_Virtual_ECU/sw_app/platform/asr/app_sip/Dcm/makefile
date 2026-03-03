
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = dcm

ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/platform.mk

#Accommodating Changes for introducing multiple Tool Chains
SRCDIR = Implementation
SRCDIR += ../GenData/$(CORE) ../GenData/$(CORE)/Components

INCDIR = ../Dcm/Implementation
INCDIR += ../BswM/Implementation
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
INCDIR += ../CanTp/Implementation
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
INCDIR += ../vRoE/Implementation
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
endif
INCDIR += ../Os/Implementation
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation

INCLUDE_INTERNAL_INTERFACES = dcm
UtilsPriv_INCLUDE =

#Static Files from SIP
SRCS_COMMON += Dcm.c
SRCS_COMMON += Dcm_CfgWrapper.c
SRCS_COMMON += Dcm_Debug.c
SRCS_COMMON += Dcm_DemIf.c
SRCS_COMMON += Dcm_Diag.c
SRCS_COMMON += Dcm_DidMgr.c
SRCS_COMMON += Dcm_Ext.c
SRCS_COMMON += Dcm_FblMgr.c
SRCS_COMMON += Dcm_MemMgr.c
SRCS_COMMON += Dcm_ModeMgr.c
SRCS_COMMON += Dcm_Network.c
SRCS_COMMON += Dcm_ObdDtcMgr.c
SRCS_COMMON += Dcm_ObdIdMgr.c
SRCS_COMMON += Dcm_PagedBuffer.c
SRCS_COMMON += Dcm_Repeater.c
SRCS_COMMON += Dcm_RidMgr.c
SRCS_COMMON += Dcm_RsrcMgr.c
SRCS_COMMON += Dcm_State.c
SRCS_COMMON += Dcm_Svc01.c
SRCS_COMMON += Dcm_Svc02.c
SRCS_COMMON += Dcm_Svc03.c
SRCS_COMMON += Dcm_Svc04.c
SRCS_COMMON += Dcm_Svc06.c
SRCS_COMMON += Dcm_Svc07.c
SRCS_COMMON += Dcm_Svc08.c
SRCS_COMMON += Dcm_Svc09.c
SRCS_COMMON += Dcm_Svc0A.c
SRCS_COMMON += Dcm_Svc11.c
SRCS_COMMON += Dcm_Svc14.c
SRCS_COMMON += Dcm_Svc19.c
SRCS_COMMON += Dcm_Svc19Utils.c
SRCS_COMMON += Dcm_Svc23.c
SRCS_COMMON += Dcm_Svc28.c
SRCS_COMMON += Dcm_Svc31.c
SRCS_COMMON += Dcm_Svc34.c
SRCS_COMMON += Dcm_Svc36.c
SRCS_COMMON += Dcm_Svc37.c
SRCS_COMMON += Dcm_Svc3D.c
SRCS_COMMON += Dcm_Svc3E.c
SRCS_COMMON += Dcm_Svc85.c
SRCS_COMMON += Dcm_TskMgr.c
SRCS_COMMON += Dcm_Utils.c
SRCS_COMMON += Dcm_VarMgr.c

#Generated Files
SRCS_COMMON += Dcm_Lcfg.c Dcm_PBcfg.c


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
