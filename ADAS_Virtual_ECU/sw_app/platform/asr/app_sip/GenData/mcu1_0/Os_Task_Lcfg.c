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
 *              File: Os_Task_Lcfg.c
 *   Generation Time: 2025-06-18 19:15:02
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Scheduler_Types.h"
#include "Os_Stack_Lcfg.h"
#include "Os_TaskInt.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


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

/*! Dynamic task data: BootAppOsTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_BootAppOsTask_Dyn;

/*! Dynamic task data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore0_Dyn;

/*! Dynamic task data: QM_ComTask_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_ComTask_10ms_Dyn;

/*! Dynamic task data: QM_ComTask_5ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_ComTask_5ms_Dyn;

/*! Dynamic task data: QM_DiagTask_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_DiagTask_10ms_Dyn;

/*! Dynamic task data: QM_MemTask_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_MemTask_10ms_Dyn;

/*! Dynamic task data: QM_Task_00_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_Task_00_10ms_Dyn;

/*! Dynamic task data: QM_Task_01_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_Task_01_10ms_Dyn;

/*! Dynamic task data: QM_Task_200ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_Task_200ms_Dyn;

/*! Dynamic task data: QM_Task_Init */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_QM_Task_Init_Dyn;

/*! Dynamic task data: Safety_Task_00_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Safety_Task_00_10ms_Dyn;

/*! Dynamic task data: Safety_Task_01_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Safety_Task_01_10ms_Dyn;

/*! Dynamic task data: Safety_Task_200ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Safety_Task_200ms_Dyn;

/*! Dynamic task data: Safety_Task_Init */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Safety_Task_Init_Dyn;

/*! Dynamic task data: Safety_WdgTask_10ms */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Safety_WdgTask_10ms_Dyn;

/*! Dynamic task data: SciServerHighOsTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_SciServerHighOsTask_Dyn;

/*! Dynamic task data: SciServerLowOsTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_SciServerLowOsTask_Dyn;

/*! Dynamic task data: ShutdownTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_ShutdownTask_Dyn;

/*! Dynamic task data: StartUpTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_StartUpTask_Dyn;

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


/*! Task configuration data: BootAppOsTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BootAppOsTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_BootAppOsTask,
    /* .Context               = */ &OsCfg_Hal_Context_BootAppOsTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_BootAppOsTask,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_BootAppOsTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_BootAppOsTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_BootAppOsTask,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_BootAppOsTask_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)3u,
  /* .TaskId                 = */ BootAppOsTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)3u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: IdleTask_OsCore0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio4294967295,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_IdleTask_OsCore0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_IdleTask_OsCore0,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)17u,
  /* .TaskId                 = */ IdleTask_OsCore0,
  /* .RunningPriority        = */ (Os_TaskPrioType)17u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_ANY,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_ComTask_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_ComTask_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_ComTask_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_ComTask_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_QM_ComTask_10ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_ComTask_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_ComTask_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_ComTask_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_ComTask_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)8u,
  /* .TaskId                 = */ QM_ComTask_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)8u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_ComTask_5ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_ComTask_5ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_ComTask_5ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_ComTask_5ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_QM_ComTask_5ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_ComTask_5ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_ComTask_5ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_ComTask_5ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_ComTask_5ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)6u,
  /* .TaskId                 = */ QM_ComTask_5ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)6u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_DiagTask_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_DiagTask_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_DiagTask_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_DiagTask_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_QM_DiagTask_10ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_DiagTask_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_DiagTask_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_DiagTask_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_DiagTask_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)11u,
  /* .TaskId                 = */ QM_DiagTask_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)11u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_MemTask_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_MemTask_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_MemTask_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_MemTask_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_QM_MemTask_10ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_MemTask_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_MemTask_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_MemTask_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_MemTask_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)12u,
  /* .TaskId                 = */ QM_MemTask_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)12u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_Task_00_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_00_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_Task_00_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_Task_00_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio54,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_Task_00_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_Task_00_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_Task_00_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_Task_00_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)13u,
  /* .TaskId                 = */ QM_Task_00_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)13u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_Task_01_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_01_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_Task_01_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_Task_01_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio50,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_Task_01_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_Task_01_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_Task_01_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_Task_01_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)14u,
  /* .TaskId                 = */ QM_Task_01_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)14u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_Task_200ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_200ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_Task_200ms,
    /* .Context               = */ &OsCfg_Hal_Context_QM_Task_200ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_QM_Task_200ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_Task_200ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_Task_200ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_Task_200ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_Task_200ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)15u,
  /* .TaskId                 = */ QM_Task_200ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)15u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: QM_Task_Init */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_Init =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_QM_Task_Init,
    /* .Context               = */ &OsCfg_Hal_Context_QM_Task_Init_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio88,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_QM_Task_Init_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_QM,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_QM_Task_Init,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_QM_Task_Init,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_QM_Task_Init_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)5u,
  /* .TaskId                 = */ QM_Task_Init,
  /* .RunningPriority        = */ (Os_TaskPrioType)5u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Safety_Task_00_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_00_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Safety_Task_00_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_Safety_Task_00_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio79,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Safety_Task_00_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Safety,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Safety_Task_00_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Safety_Task_00_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_Safety_Task_00_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)9u,
  /* .TaskId                 = */ Safety_Task_00_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)9u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Safety_Task_01_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_01_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Safety_Task_01_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_Safety_Task_01_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio78,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Safety_Task_01_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Safety,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Safety_Task_01_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Safety_Task_01_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_Safety_Task_01_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)10u,
  /* .TaskId                 = */ Safety_Task_01_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)10u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Safety_Task_200ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_200ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Safety_Task_200ms,
    /* .Context               = */ &OsCfg_Hal_Context_Safety_Task_200ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Safety_Task_200ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Safety_Task_200ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Safety,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Safety_Task_200ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Safety_Task_200ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_Safety_Task_200ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)16u,
  /* .TaskId                 = */ Safety_Task_200ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)16u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Safety_Task_Init */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_Init =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Safety_Task_Init,
    /* .Context               = */ &OsCfg_Hal_Context_Safety_Task_Init_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio90,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Safety_Task_Init_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Safety,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Safety_Task_Init,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Safety_Task_Init,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_Safety_Task_Init_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)4u,
  /* .TaskId                 = */ Safety_Task_Init,
  /* .RunningPriority        = */ (Os_TaskPrioType)4u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: Safety_WdgTask_10ms */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_WdgTask_10ms =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Safety_WdgTask_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_Safety_WdgTask_10ms_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_Safety_WdgTask_10ms,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Safety_WdgTask_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Safety,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Safety_WdgTask_10ms,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_Safety_WdgTask_10ms,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_Safety_WdgTask_10ms_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)7u,
  /* .TaskId                 = */ Safety_WdgTask_10ms,
  /* .RunningPriority        = */ (Os_TaskPrioType)7u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: SciServerHighOsTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_SciServerHighOsTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServerHighOsTask,
    /* .Context               = */ &OsCfg_Hal_Context_SciServerHighOsTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_SciServerHighOsTask,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_SciServerHighOsTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServerHighOsTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServerHighOsTask,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_SciServerHighOsTask_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)1u,
  /* .TaskId                 = */ SciServerHighOsTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)1u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: SciServerLowOsTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_SciServerLowOsTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SciServerLowOsTask,
    /* .Context               = */ &OsCfg_Hal_Context_SciServerLowOsTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_SciServerLowOsTask,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_SciServerLowOsTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SciServerLowOsTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_SciServerLowOsTask,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_SciServerLowOsTask_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)2u,
  /* .TaskId                 = */ SciServerLowOsTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)2u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: ShutdownTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ShutdownTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ShutdownTask,
    /* .Context               = */ &OsCfg_Hal_Context_ShutdownTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio100,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_ShutdownTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ShutdownTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_ShutdownTask,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_ShutdownTask_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)0u,
  /* .TaskId                 = */ ShutdownTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: StartUpTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_StartUpTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_StartUpTask,
    /* .Context               = */ &OsCfg_Hal_Context_StartUpTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio100,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_StartUpTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_StartUpTask,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_StartUpTask,
    /* .FpuContext            = */ &OsCfg_Hal_FpuContext_StartUpTask_Dyn,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ TRUE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)0u,
  /* .TaskId                 = */ StartUpTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)0u,
  /* .MaxActivations         = */ (Os_ActivationCntType)1u,
  /* .AutostartModes         = */ OSDEFAULTAPPMODE,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0)),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0u,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BootAppOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_ComTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_ComTask_5ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_DiagTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_MemTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_00_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_01_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_200ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_QM_Task_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_00_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_01_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_200ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_Task_Init),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Safety_WdgTask_10ms),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SciServerHighOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SciServerLowOsTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_ShutdownTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_StartUpTask),
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
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
