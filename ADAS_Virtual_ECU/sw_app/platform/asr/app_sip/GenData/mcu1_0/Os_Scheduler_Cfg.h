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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2024-02-13 13:07:51
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_SCHEDULER_CFG_H
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether round robin scheduling is enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_SCHEDULE_ROUND_ROB_ENABLED       (STD_OFF)

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (18u)

/* Number of task queue activation slots: OsCore0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS     (4u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE9_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE10_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE11_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE12_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE13_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE14_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE15_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE16_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE17_OSCORE0_SLOTS     (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
