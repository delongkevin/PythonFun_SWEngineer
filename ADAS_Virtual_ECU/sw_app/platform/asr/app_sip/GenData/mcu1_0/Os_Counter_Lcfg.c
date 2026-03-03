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
 *              File: Os_Counter_Lcfg.c
 *   Generation Time: 2024-02-13 13:07:49
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_COUNTER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_CollectionInt.h"
#include "Os_PriorityQueue.h"
#include "Os_ArrayList.h"
#include "Os_Timer.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Timer_Lcfg.h"


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

/*! Dynamic counter data: SystemTimer */

OS_LOCAL VAR(Os_CollectionNodeType, OS_VAR_NOINIT)
OsCfg_Counter_SystemTimer_PriorityQueue_Collection_Nodes_Dyn[OS_CFG_NUM_COUNTER_SYSTEMTIMER_JOBS + 1u];
OS_LOCAL VAR(Os_CollectionType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_PriorityQueue_Collection_Dyn;
OS_LOCAL VAR(Os_TimerPfrtType, OS_VAR_NOINIT) OsCfg_Counter_SystemTimer_Dyn;

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


/*! Counter configuration data: SystemTimer */

CONST(Os_PriorityQueueConfigType, OS_CONST) OsCfg_Counter_SystemTimer_PriorityQueue =
{
  /* .Nodes = */ OsCfg_Counter_SystemTimer_PriorityQueue_Collection_Nodes_Dyn,
  /* .Dyn   = */ &OsCfg_Counter_SystemTimer_PriorityQueue_Collection_Dyn,
  /* .Size  = */ (Os_CollectionNodeIdxType)OS_CFG_NUM_COUNTER_SYSTEMTIMER_JOBS
};

CONST(Os_TimerPfrtConfigType, OS_CONST) OsCfg_Counter_SystemTimer =
{
  /* .SwCounter            = */
  {
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_SystemTimer,
      /* .MaxCountingValue     = */ OS_TIMERPFRT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_SystemTimer),
      /* .MaxDifferentialValue = */ OS_TIMERPFRT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_SystemTimer),
      /* .MinCycle             = */ OSMINCYCLE_SystemTimer,
      /* .TicksPerBase         = */ OSTICKSPERBASE_SystemTimer
    },
    /* .Collection            = */ OS_COUNTER_CASTCONFIG_PRIORITYQUEUE_2_COLLECTION(OsCfg_Counter_SystemTimer_PriorityQueue),
    /* .CollectionType        = */ OS_COLLECTIONTYPE_PRIORITYQUEUE,
    /* .DriverType            = */ OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .AccessingApplications = */ (OS_APPID2MASK(OsApplication_QM) | OS_APPID2MASK(OsApplication_Safety) | OS_APPID2MASK(OsApplication_Trusted_Core0) | OS_APPID2MASK(SystemApplication_OsCore0))  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  },
  /* .Dyn     = */ OS_ISR_CASTDYN_TIMERSW_2_TIMERPFRT(OsCfg_Counter_SystemTimer_Dyn)
  },
  /* .Period               = */ 19200UL,
  /* .MaxDifferentialValue = */ OS_TIMERPFRT_HARDWAREGETMAXDIFFERENTIALVALUE(1073741823UL),
  /* .MaxCountingValue     = */ OS_TIMERPFRT_HARDWAREGETMAXCOUNTINGVALUE(1073741823UL),
  /* .HwConfig             = */ &OsCfg_Hal_TimerFrt_SystemTimer
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for counters. */
CONSTP2CONST(Os_CounterConfigType, OS_CONST, OS_CONST) OsCfg_CounterRefs[OS_COUNTERID_COUNT + 1u] =            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer),
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
 *  END OF FILE: Os_Counter_Lcfg.c
 *********************************************************************************************************************/
