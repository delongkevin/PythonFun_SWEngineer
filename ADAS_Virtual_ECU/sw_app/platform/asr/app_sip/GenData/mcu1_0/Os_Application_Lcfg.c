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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2025-01-23 15:17:24
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: OsApplication_QM */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_QM_Dyn;

/*! Dynamic application data: OsApplication_Safety */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_Safety_Dyn;

/*! Dynamic application data: OsApplication_Trusted_Core0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_Trusted_Core0_Dyn;

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: OsApplication_QM */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_QM_ComTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_QM_ComTask_5ms_5_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_QM_DiagTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_QM_MemTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_QM_Task_200ms_0_200ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_ComTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_ComTask_5ms_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_DiagTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_MemTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_Task_00_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_Task_01_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_QM_Task_200ms_0_200ms),
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_QM */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_QM */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_QM */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_QM */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_QM */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_QM */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_ComTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_ComTask_5ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_DiagTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_MemTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_00_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_01_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_200ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_Init),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_QM */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_QM_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_QM_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsApplication_QM */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_QM =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_QM_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_QM),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_QM_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_QM_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_QM_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_QM_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_QM_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_QM_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_QM_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_QM_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_QM_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_OsApplication_QM,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ FALSE,
  /* .IsPriveleged         = */ FALSE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_QM
};

/*! Object reference table for application alarms: OsApplication_Safety */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Safety_Task_00_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Safety_Task_01_10ms_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Safety_Task_200ms_0_200ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Safety_WdgTask_10ms_0_10ms),
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_Safety */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_Safety */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_Safety */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_Safety */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_Safety */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_Safety */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_00_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_01_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_200ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_WdgTask_10ms),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_Safety */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_Safety_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsApplication_Safety */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_Safety =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_Safety_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_Safety),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_Safety_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_Safety_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_Safety_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_Safety_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_Safety_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_Safety_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_Safety_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_Safety_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_SAFETY_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_OsApplication_Safety,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ FALSE,
  /* .IsPriveleged         = */ FALSE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_Safety
};

/*! Object reference table for application alarms: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ALARMS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_TASKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_Trusted_Core0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SERVICES + 1u] =
{
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Appl_vDamRemapNrcCalloutFunc),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_CanWUp_Val_CheckPN),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_CanWUp_Val_StartWakeUpValidation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_CanWUp_Val_StopWakeUpValidation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_CddIpcHandler_Init),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_CddIpcHandler_Main),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_DcmCalloutStub_CompareKey),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_DcmCalloutStub_GetSeed),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_DcmCalloutStub_SessionCallback),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Det_UserReportError),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_PMIC_EnterLongWindow_DisableWdg),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Pmic_AppEnterInLongWindow),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Pmic_F_SafeState2_v),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamCalibReset),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_DID2023_ProxiData),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_IntrinsicCameraSN_Readblock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_IpcTxData),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_MCUReadDeviceReg),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_MCUReadDeviceRegData),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_MCUWriteDeviceReg),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_RE_ReportErrorStatus1_0_B),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_ShutdownOS),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_CDD_IPCHandler_MirrorBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_CalDataProvider_MirrorBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_Cdd_Safety_MirrorBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_ComCallout_FlagStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_Proxi_MirrorBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Update_SafetyGuard_MirrorBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_f_Send_Dbg_SDLFault_CanTx),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_f_Send_Dbg_SSMFault_CanTx),
  NULL_PTR
};

/*! Application configuration data: OsApplication_Trusted_Core0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_Trusted_Core0 =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_Trusted_Core0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_Trusted_Core0),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_Trusted_Core0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_Trusted_Core0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_Trusted_Core0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_Trusted_Core0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_Trusted_Core0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_Trusted_Core0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUSTED_CORE0_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_OsApplication_Trusted_Core0,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_Trusted_Core0
};

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Can_30_McanIsr_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Can_30_McanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2c_IrqUnit0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_I2c_IrqUnit1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IPC_mailbox1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IPC_mailbox2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MAIN_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn2),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SciServer_OsIsr_UserMsgHwiFxn4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_CFG_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_HI_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WKUP_ESM0_ESM_INT_LOW_LVL_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BootAppOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SciServerHighOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SciServerLowOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ShutdownTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_StartUpTask),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .TraceAppl            = */ &OsCfg_Trace_SystemApplication_OsCore0,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_OsApplication_QM,
  &OsCfg_App_OsApplication_Safety,
  &OsCfg_App_OsApplication_Trusted_Core0,
  &OsCfg_App_SystemApplication_OsCore0,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
