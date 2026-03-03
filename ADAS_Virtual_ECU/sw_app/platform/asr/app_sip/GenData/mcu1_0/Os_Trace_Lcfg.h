/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Trace_Lcfg.h
 *   Generation Time: 2024-02-13 12:17:22
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TRACE_LCFG_H
# define OS_TRACE_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trace_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */
# include "MeOsProfiling_ASR.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! \brief    Represents the identification of OS services for an external debugger supporting the
 *            OSEK Runtime Interface (ORTI) or AUTOSAR Runtime Interface (ARTI).
 *  \details  Start and end of a service are coded in the least significant bit according to the
 *            ORTI standard. Therefore, all IDs are even.
 *            We trace the service in a uint8. Therefore, at most 127 services are possible to
 *            trace currently.
 */
typedef enum
{
  OsOrtiApiIdGetApplicationID = 0x02u, /*!< GetApplicationID() */
  OsOrtiApiIdGetISRID = 0x04u, /*!< GetISRID() */
  OsOrtiApiIdCallTrustedFunction = 0x06u, /*!< CallTrustedFunction() */
  OsOrtiApiIdCheckISRMemoryAccess = 0x08u, /*!< CheckISRMemoryAccess() */
  OsOrtiApiIdCheckTaskMemoryAccess = 0x0Au, /*!< CheckTaskMemoryAccess() */
  OsOrtiApiIdCheckObjectAccess = 0x0Cu, /*!< CheckObjectAccess() */
  OsOrtiApiIdCheckObjectOwnership = 0x0Eu, /*!< CheckObjectOwnership() */
  OsOrtiApiIdStartScheduleTableRel = 0x10u, /*!< StartScheduleTableRel() */
  OsOrtiApiIdStartScheduleTableAbs = 0x12u, /*!< StartScheduleTableAbs() */
  OsOrtiApiIdStopScheduleTable = 0x14u, /*!< StopScheduleTable() */
  OsOrtiApiIdNextScheduleTable = 0x16u, /*!< NextScheduleTable() */
  OsOrtiApiIdStartScheduleTableSynchron = 0x18u, /*!< StartScheduleTableSynchron() */
  OsOrtiApiIdSyncScheduleTable = 0x1Au, /*!< SyncScheduleTable() */
  OsOrtiApiIdSetScheduleTableAsync = 0x1Cu, /*!< SetScheduleTableAsync() */
  OsOrtiApiIdGetScheduleTableStatus = 0x1Eu, /*!< GetScheduleTableStatus() */
  OsOrtiApiIdIncrementCounter = 0x20u, /*!< IncrementCounter() */
  OsOrtiApiIdGetCounterValue = 0x22u, /*!< GetCounterValue() */
  OsOrtiApiIdGetElapsedValue = 0x24u, /*!< GetElapsedValue() */
  OsOrtiApiIdTerminateApplication = 0x26u, /*!< TerminateApplication() */
  OsOrtiApiIdAllowAccess = 0x28u, /*!< AllowAccess() */
  OsOrtiApiIdGetApplicationState = 0x2Au, /*!< GetApplicationState() */
  OsOrtiApiIdGetNumberOfActivatedCores = 0x2Cu, /*!< GetNumberOfActivatedCores() */
  OsOrtiApiIdGetCoreID = 0x2Eu, /*!< GetCoreID() */
  OsOrtiApiIdStartCore = 0x30u, /*!< StartCore() */
  OsOrtiApiIdStartNonAutosarCore = 0x32u, /*!< StartNonAutosarCore() */
  OsOrtiApiIdGetSpinlock = 0x34u, /*!< GetSpinlock() */
  OsOrtiApiIdReleaseSpinlock = 0x36u, /*!< ReleaseSpinlock() */
  OsOrtiApiIdTryToGetSpinlock = 0x38u, /*!< TryToGetSpinlock() */
  OsOrtiApiIdShutdownAllCores = 0x3Au, /*!< ShutdownAllCores() */
  OsOrtiApiIdControlIdle = 0x3Cu, /*!< ControlIdle() */
  OsOrtiApiIdIocSend = 0x3Eu, /*!< IocSend() */
  OsOrtiApiIdIocWrite = 0x40u, /*!< IocWrite() */
  OsOrtiApiIdIocSendGroup = 0x42u, /*!< IocSendGroup() */
  OsOrtiApiIdIocWriteGroup = 0x44u, /*!< IocWriteGroup() */
  OsOrtiApiIdIocReceive = 0x46u, /*!< IocReceive() */
  OsOrtiApiIdIocRead = 0x48u, /*!< IocRead() */
  OsOrtiApiIdIocReceiveGroup = 0x4Au, /*!< IocReceiveGroup() */
  OsOrtiApiIdIocReadGroup = 0x4Cu, /*!< IocReadGroup() */
  OsOrtiApiIdIocEmptyQueue = 0x4Eu, /*!< IocEmptyQueue() */
  OsOrtiApiIdGetCurrentApplicationID = 0x50u, /*!< GetCurrentApplicationID() */
  OsOrtiApiIdCallNonTrustedFunction = 0x52u, /*!< CallNonTrustedFunction() */
  OsOrtiApiIdGetTaskStackUsage = 0x54u, /*!< Os_GetTaskStackUsage() */
  OsOrtiApiIdGetISRStackUsage = 0x56u, /*!< Os_GetISRStackUsage() */
  OsOrtiApiIdGetKernelStackUsage = 0x58u, /*!< Os_GetKernelStackUsage() */
  OsOrtiApiIdGetStartupHookStackUsage = 0x5Au, /*!< Os_GetStartupHookStackUsage() */
  OsOrtiApiIdGetErrorHookStackUsage = 0x5Cu, /*!< Os_GetErrorHookStackUsage() */
  OsOrtiApiIdGetShutdownHookStackUsage = 0x5Eu, /*!< Os_GetShutdownHookStackUsage() */
  OsOrtiApiIdGetProtectionHookStackUsage = 0x60u, /*!< Os_GetProtectionHookStackUsage() */
  OsOrtiApiIdGetSemaphore = 0x62u, /*!< GetSemaphore() */
  OsOrtiApiIdReleaseSemaphore = 0x64u, /*!< ReleaseSemaphore() */
  OsOrtiApiIdStartOS = 0x66u, /*!< StartOS() */
  OsOrtiApiIdGetActiveApplicationMode = 0x68u, /*!< GetActiveApplicationMode() */
  OsOrtiApiIdDisableAllInterrupts = 0x6Au, /*!< DisableAllInterrupts() */
  OsOrtiApiIdEnableAllInterrupts = 0x6Cu, /*!< EnableAllInterrupts() */
  OsOrtiApiIdSuspendAllInterrupts = 0x6Eu, /*!< SuspendAllInterrupts() */
  OsOrtiApiIdResumeAllInterrupts = 0x70u, /*!< ResumeAllInterrupts() */
  OsOrtiApiIdSuspendOSInterrupts = 0x72u, /*!< SuspendOSInterrupts() */
  OsOrtiApiIdResumeOSInterrupts = 0x74u, /*!< ResumeOSInterrupts() */
  OsOrtiApiIdActivateTask = 0x76u, /*!< ActivateTask() */
  OsOrtiApiIdTerminateTask = 0x78u, /*!< TerminateTask() */
  OsOrtiApiIdChainTask = 0x7Au, /*!< ChainTask() */
  OsOrtiApiIdGetTaskID = 0x7Cu, /*!< GetTaskID() */
  OsOrtiApiIdGetTaskState = 0x7Eu, /*!< GetTaskState() */
  OsOrtiApiIdSchedule = 0x80u, /*!< Schedule() */
  OsOrtiApiIdSetEvent = 0x82u, /*!< SetEvent() */
  OsOrtiApiIdClearEvent = 0x84u, /*!< ClearEvent() */
  OsOrtiApiIdGetEvent = 0x86u, /*!< GetEvent() */
  OsOrtiApiIdWaitEvent = 0x88u, /*!< WaitEvent() */
  OsOrtiApiIdGetAlarmBase = 0x8Au, /*!< GetAlarmBase() */
  OsOrtiApiIdGetAlarm = 0x8Cu, /*!< GetAlarm() */
  OsOrtiApiIdSetRelAlarm = 0x8Eu, /*!< SetRelAlarm() */
  OsOrtiApiIdSetAbsAlarm = 0x90u, /*!< SetAbsAlarm() */
  OsOrtiApiIdCancelAlarm = 0x92u, /*!< CancelAlarm() */
  OsOrtiApiIdGetResource = 0x94u, /*!< GetResource() */
  OsOrtiApiIdReleaseResource = 0x96u, /*!< ReleaseResource() */
  OsOrtiApiIdGetVersionInfo = 0x98u, /*!< GetVersionInfo() */
  OsOrtiApiIdEnterPreStartTask = 0x9Eu, /*!< EnterPreStartTask() */
  OsOrtiApiIdShutdownOS = 0xA0u, /*!< ShutdownOS() */
  OsOrtiApiIdGetUnhandledIrq = 0xA2u, /*!< GetUnhandledIrq() */
  OsOrtiApiIdGetUnhandledExc = 0xA4u, /*!< GetUnhandledExc() */
  OsOrtiApiIdDisableOSInterrupts = 0xA6u, /*!< DisableOSInterrupts() */
  OsOrtiApiIdEnableOSInterrupts = 0xA8u, /*!< EnableOSInterrupts() */
  OsOrtiApiIdReadPeripheral8 = 0xAAu, /*!< Os_ReadPeripheral8() */
  OsOrtiApiIdReadPeripheral16 = 0xACu, /*!< Os_ReadPeripheral16() */
  OsOrtiApiIdReadPeripheral32 = 0xAEu, /*!< Os_ReadPeripheral32() */
  OsOrtiApiIdWritePeripheral8 = 0xB0u, /*!< Os_WritePeripheral8() */
  OsOrtiApiIdWritePeripheral16 = 0xB2u, /*!< Os_WritePeripheral16() */
  OsOrtiApiIdWritePeripheral32 = 0xB4u, /*!< Os_WritePeripheral32() */
  OsOrtiApiIdModifyPeripheral8 = 0xB6u, /*!< Os_ModifyPeripheral8() */
  OsOrtiApiIdModifyPeripheral16 = 0xB8u, /*!< Os_ModifyPeripheral16() */
  OsOrtiApiIdModifyPeripheral32 = 0xBAu, /*!< Os_ModifyPeripheral32() */
  OsOrtiApiIdGetDetailedError = 0xBCu, /*!< GetDetailedError() */
  OsOrtiApiIdOSErrorGetServiceId = 0xBEu, /*!< OSErrorGetServiceId() */
  OsOrtiApiIdDisableInterruptSource = 0xC0u, /*!< Os_DisableInterruptSource() */
  OsOrtiApiIdEnableInterruptSource = 0xC2u, /*!< Os_EnableInterruptSource() */
  OsOrtiApiIdClearPendingInterrupt = 0xC4u, /*!< Os_ClearPendingInterrupt() */
  OsOrtiApiIdIsInterruptSourceEnabled = 0xC6u, /*!< Os_IsInterruptSourceEnabled() */
  OsOrtiApiIdIsInterruptPending = 0xC8u, /*!< Os_IsInterruptPending() */
  OsOrtiApiIdCallFastTrustedFunction = 0xCAu, /*!< Os_CallFastTrustedFunction() */
  OsOrtiApiIdBarrierSynchronize = 0xCCu, /*!< Os_BarrierSynchronize() */
  OsOrtiApiIdGetExceptionContext = 0xCEu, /*!< Os_GetExceptionContext() */
  OsOrtiApiIdSetExceptionContext = 0xD0u, /*!< Os_SetExceptionContext() */
  OsOrtiApiIdInitialEnableInterruptSources = 0xD2u, /*!< Os_InitialEnableInterruptSources() */
  OsOrtiApiIdGetCoreStartState = 0xD4u, /*!< Os_GetCoreStartState() */
  OsOrtiApiIdGetExceptionAddress = 0xD6u, /*!< Os_GetExceptionAddress() */
  OsOrtiApiIdGetNonTrustedFunctionStackUsage = 0xD8u, /*!< Os_GetNonTrustedFunctionStackUsage() */
  OsOrtiApiIdEnableInterruptsPreStart = 0xDAu, /*!< Os_EnableInterruptsPreStart() */
  OsOrtiApiIdGetInitHookStackUsage = 0xDCu, /*!< Os_GetInitHookStackUsage() */
  OsOrtiApiIdActivateTaskAsyn = 0xDEu, /*!< ActivateTaskAsyn() */
  OsOrtiApiIdSetEventAsyn = 0xDFu /*!< SetEventAsyn() */
} OsOrtiApiIdType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic trace data: OsCore0 */
extern VAR(Os_TraceCoreType, OS_VAR_NOINIT) OsCfg_Trace_OsCore0_Dyn;

# define OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trace configuration data: OsApplication_QM */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_QM;

/*! Trace configuration data: OsApplication_Safety */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_Safety;

/*! Trace configuration data: OsApplication_Trusted_Core0 */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_OsApplication_Trusted_Core0;

/*! Trace configuration data: SystemApplication_OsCore0 */
extern CONST(Os_TraceAppConfigType, OS_CONST) OsCfg_Trace_SystemApplication_OsCore0;

/*! Trace configuration data: BootAppOsTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_BootAppOsTask;

/*! Trace configuration data: IdleTask_OsCore0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore0;

/*! Trace configuration data: QM_ComTask_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_ComTask_10ms;

/*! Trace configuration data: QM_ComTask_5ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_ComTask_5ms;

/*! Trace configuration data: QM_DiagTask_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_DiagTask_10ms;

/*! Trace configuration data: QM_MemTask_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_MemTask_10ms;

/*! Trace configuration data: QM_Task_00_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_00_10ms;

/*! Trace configuration data: QM_Task_01_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_01_10ms;

/*! Trace configuration data: QM_Task_200ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_200ms;

/*! Trace configuration data: QM_Task_Init */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_QM_Task_Init;

/*! Trace configuration data: Safety_Task_00_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_00_10ms;

/*! Trace configuration data: Safety_Task_01_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_01_10ms;

/*! Trace configuration data: Safety_Task_200ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_200ms;

/*! Trace configuration data: Safety_Task_Init */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_Task_Init;

/*! Trace configuration data: Safety_WdgTask_10ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Safety_WdgTask_10ms;

/*! Trace configuration data: SciServerHighOsTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServerHighOsTask;

/*! Trace configuration data: SciServerLowOsTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServerLowOsTask;

/*! Trace configuration data: ShutdownTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ShutdownTask;

/*! Trace configuration data: StartUpTask */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_StartUpTask;

/*! Trace configuration data: ADC0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ADC0;

/*! Trace configuration data: ADC1 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_ADC1;

/*! Trace configuration data: Can_30_McanIsr_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Can_30_McanIsr_0;

/*! Trace configuration data: Can_30_McanIsr_1 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Can_30_McanIsr_1;

/*! Trace configuration data: CounterIsr_SystemTimer */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CounterIsr_SystemTimer;

/*! Trace configuration data: I2c_IrqUnit0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2c_IrqUnit0;

/*! Trace configuration data: I2c_IrqUnit1 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_I2c_IrqUnit1;

/*! Trace configuration data: IPC_mailbox1 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IPC_mailbox1;

/*! Trace configuration data: IPC_mailbox2 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IPC_mailbox2;

/*! Trace configuration data: MAIN_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_CFG_LVL_0;

/*! Trace configuration data: MAIN_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_HI_LVL_0;

/*! Trace configuration data: MAIN_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MAIN_ESM0_ESM_INT_LOW_LVL_0;

/*! Trace configuration data: MCU_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_CFG_LVL_0;

/*! Trace configuration data: MCU_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_HI_LVL_0;

/*! Trace configuration data: MCU_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_ESM0_ESM_INT_LOW_LVL_0;

/*! Trace configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78;

/*! Trace configuration data: MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304;

/*! Trace configuration data: SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305;

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn1 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn1;

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn2 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn2;

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn3 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn3;

/*! Trace configuration data: SciServer_OsIsr_UserMsgHwiFxn4 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_SciServer_OsIsr_UserMsgHwiFxn4;

/*! Trace configuration data: WKUP_ESM0_ESM_INT_CFG_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_CFG_LVL_0;

/*! Trace configuration data: WKUP_ESM0_ESM_INT_HI_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_HI_LVL_0;

/*! Trace configuration data: WKUP_ESM0_ESM_INT_LOW_LVL_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_WKUP_ESM0_ESM_INT_LOW_LVL_0;

/*! Trace configuration data: vHsmResponseIsr */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_vHsmResponseIsr;

/*! Trace configuration data: OsCore0_Hooks */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsCore0_Hooks;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TRACE_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Trace_Lcfg.h
 *********************************************************************************************************************/
