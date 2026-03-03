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
 *              File: Os_Task_Lcfg.h
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TASK_LCFG_H
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task configuration data: BootAppOsTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_BootAppOsTask;

/*! Task configuration data: IdleTask_OsCore0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0;

/*! Task configuration data: QM_ComTask_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_ComTask_10ms;

/*! Task configuration data: QM_ComTask_5ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_ComTask_5ms;

/*! Task configuration data: QM_DiagTask_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_DiagTask_10ms;

/*! Task configuration data: QM_MemTask_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_MemTask_10ms;

/*! Task configuration data: QM_Task_00_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_00_10ms;

/*! Task configuration data: QM_Task_01_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_01_10ms;

/*! Task configuration data: QM_Task_200ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_200ms;

/*! Task configuration data: QM_Task_Init */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_QM_Task_Init;

/*! Task configuration data: Safety_Task_00_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_00_10ms;

/*! Task configuration data: Safety_Task_01_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_01_10ms;

/*! Task configuration data: Safety_Task_200ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_200ms;

/*! Task configuration data: Safety_Task_Init */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_Task_Init;

/*! Task configuration data: Safety_WdgTask_10ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Safety_WdgTask_10ms;

/*! Task configuration data: SciServerHighOsTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_SciServerHighOsTask;

/*! Task configuration data: SciServerLowOsTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_SciServerLowOsTask;

/*! Task configuration data: ShutdownTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_ShutdownTask;

/*! Task configuration data: StartUpTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_StartUpTask;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
