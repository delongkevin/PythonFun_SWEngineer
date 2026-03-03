
include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = os

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
INCDIR += ../stubs/$(CORE)
INCDIR += ../GenData/$(CORE)
INCDIR += ../GenData/$(CORE)/Components
INCDIR += ../../ti_mcal/CddIpc/include
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += ../CanTrcv_30_Tja1043/Implementation
INCDIR += ../CanNm/Implementation
INCDIR += ../Nm/Implementation
INCDIR += ../NvM/Implementation
INCDIR += ../MemIf/Implementation
INCDIR += ../I2c/Implementation
INCDIR += ../Eep_30_XXi2c01/Implementation
INCDIR += ../Ea/Implementation
INCDIR += ../Crc/Implementation
else ifeq ($(CORE),$(filter $(CORE), mcu3_1))
INCDIR += ../CanTrcv_30_Generic/Implementation
INCDIR += ../EthIf/Implementation
INCDIR += ../EthSM/Implementation
INCDIR += ../IpBase/Implementation
INCDIR += ../TcpIp/Implementation
INCDIR += ../SoAd/Implementation
endif
INCDIR += ../PduR/Implementation
INCDIR += ../VStdLib/Implementation
INCDIR += ../Common/Implementation
INCDIR += ../Dem/Implementation
INCDIR += ../Dcm/Implementation
INCDIR += ../../../../mcu1_0/app/MeOsProfiling

INCLUDE_INTERNAL_INTERFACES = os
UtilsPriv_INCLUDE =


SRCS_COMMON+= Os_AccessCheck.c
SRCS_COMMON+= Os_Alarm.c
SRCS_COMMON+= Os_Application.c
SRCS_COMMON+= Os_Barrier.c
SRCS_COMMON+= Os_Bit.c
SRCS_COMMON+= Os_BitArray.c
SRCS_COMMON+= Os_Core.c
SRCS_COMMON+= Os_Counter.c
SRCS_COMMON+= Os_Deque.c
SRCS_COMMON+= Os_Error.c
SRCS_COMMON+= Os_Event.c
SRCS_COMMON+= Os_Fifo.c
SRCS_COMMON+= Os_Fifo08.c
SRCS_COMMON+= Os_Fifo16.c
SRCS_COMMON+= Os_Fifo32.c
SRCS_COMMON+= Os_FifoRef.c
SRCS_COMMON+= Os_Hook.c
SRCS_COMMON+= Os_Interrupt.c
SRCS_COMMON+= Os_Ioc.c
SRCS_COMMON+= Os_Isr.c
SRCS_COMMON+= Os_Job.c
SRCS_COMMON+= Os_Lock.c
SRCS_COMMON+= Os_MemoryProtection.c
SRCS_COMMON+= Os_Peripheral.c
SRCS_COMMON+= Os_PriorityQueue.c
SRCS_COMMON+= Os_Resource.c
SRCS_COMMON+= Os_Scheduler.c
SRCS_COMMON+= Os_ScheduleTable.c
SRCS_COMMON+= Os_ServiceFunction.c
SRCS_COMMON+= Os_Spinlock.c
SRCS_COMMON+= Os_Stack.c
SRCS_COMMON+= Os_Task.c
SRCS_COMMON+= Os_Thread.c
SRCS_COMMON+= Os_Timer.c
SRCS_COMMON+= Os_TimingProtection.c
SRCS_COMMON+= Os_Trace.c
SRCS_COMMON+= Os_Trap.c
SRCS_COMMON+= Os_XSignal.c
SRCS_COMMON+= Os_ArrayList.c

#OS HAL Static Files
SRCS_COMMON+= Os_Hal_Core.c
SRCS_COMMON+= Os_Hal_Entry.c
SRCS_COMMON+= Os_Hal_Context.c
SRCS_COMMON+= Os_Hal_Compiler_Arm.c
SRCS_COMMON+= Os_Hal_Compiler_LlvmDiab.c
SRCS_COMMON+= Os_Hal_Compiler_LlvmTI.c
SRCS_COMMON+= Os_Hal_Compiler_LlvmHighTec.c
SRCS_COMMON+= Os_Hal_Core_Jacinto7.c

#OS ASM File
#SAK:-Workaround
SRCS_ASM_COMMON+= Os_Hal_ContextAsm_llvm.asm
SRCS_ASM_COMMON+= Os_Hal_Compiler_TiInt_llvm.asm


#OS Generated files
SRCS_COMMON+= Os_AccessCheck_Lcfg.c
SRCS_COMMON+= Os_Alarm_Lcfg.c
SRCS_COMMON+= Os_Application_Lcfg.c
SRCS_COMMON+= Os_Barrier_Lcfg.c
SRCS_COMMON+= Os_Core_Lcfg.c
SRCS_COMMON+= Os_Counter_Lcfg.c
SRCS_COMMON+= Os_Error_Lcfg.c
SRCS_COMMON+= Os_Hook_Lcfg.c
SRCS_COMMON+= Os_Ioc_Lcfg.c
SRCS_COMMON+= Os_Isr_Lcfg.c
SRCS_COMMON+= Os_MemoryProtection_Lcfg.c
SRCS_COMMON+= Os_Peripheral_Lcfg.c
SRCS_COMMON+= Os_Resource_Lcfg.c
SRCS_COMMON+= Os_Scheduler_Lcfg.c
SRCS_COMMON+= Os_ScheduleTable_Lcfg.c
SRCS_COMMON+= Os_ServiceFunction_Lcfg.c
SRCS_COMMON+= Os_Spinlock_Lcfg.c
SRCS_COMMON+= Os_Stack_Lcfg.c
SRCS_COMMON+= Os_Task_Lcfg.c
SRCS_COMMON+= Os_TimingProtection_Lcfg.c
SRCS_COMMON+= Os_Trace_Lcfg.c
SRCS_COMMON+= Os_XSignal_Lcfg.c

#OS HAL Generated Files
SRCS_COMMON+= Os_Hal_Context_Lcfg.c
SRCS_COMMON+= Os_Hal_Core_Lcfg.c
SRCS_COMMON+= Os_Hal_Entry_Lcfg.c
SRCS_COMMON+= Os_Hal_Interrupt_Lcfg.c
SRCS_COMMON+= Os_Hal_Kernel_Lcfg.c
SRCS_COMMON+= Os_Hal_MemoryProtection_Lcfg.c
SRCS_COMMON+= Os_Hal_Timer_Lcfg.c
#SAK:-Workaround
SRCS_ASM_COMMON += Os_Hal_EntryAsm_Lcfg_llvm.asm
SRCS_ASM_COMMON += Os_Hal_MemoryProtection_PMSAv7_CacheMaintenance_llvm.asm


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
