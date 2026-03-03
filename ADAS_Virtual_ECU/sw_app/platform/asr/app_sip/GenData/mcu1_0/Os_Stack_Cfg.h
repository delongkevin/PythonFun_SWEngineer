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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2025-06-18 19:15:02
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_ON)

/* Configured stack sizes (Total: 110592 Byte) */
# define OS_CFG_SIZE_BOOTAPPOSTASK_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_PROTECTION_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO100_STACK     (2048u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (1024u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK     (16384u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO54_STACK     (4096u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO78_STACK     (32768u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO79_STACK     (8192u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO88_STACK     (2048u)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO90_STACK     (8192u)
# define OS_CFG_SIZE_QM_COMTASK_10MS_STACK     (4096u)
# define OS_CFG_SIZE_QM_COMTASK_5MS_STACK     (1024u)
# define OS_CFG_SIZE_QM_DIAGTASK_10MS_STACK     (4096u)
# define OS_CFG_SIZE_QM_MEMTASK_10MS_STACK     (1024u)
# define OS_CFG_SIZE_QM_TASK_200MS_STACK     (2048u)
# define OS_CFG_SIZE_SAFETY_TASK_200MS_STACK     (1024u)
# define OS_CFG_SIZE_SAFETY_WDGTASK_10MS_STACK     (4096u)
# define OS_CFG_SIZE_SCISERVERHIGHOSTASK_STACK     (4096u)
# define OS_CFG_SIZE_SCISERVERLOWOSTASK_STACK     (4096u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
