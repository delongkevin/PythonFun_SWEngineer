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
 *              File: Os_Trace_Cfg.h
 *   Generation Time: 2024-02-13 12:17:22
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TRACE_CFG_H
# define OS_TRACE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether ORTI is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ORTI                             (STD_ON)

/*! Defines whether ORTI tracing is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ORTI_ADDITIONAL                  (STD_ON)

/*! Defines whether Vector timing hooks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_OSTIMINGHOOKS                    (STD_ON)

/*! Defines whether ARTI tracing is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ARTI                             (STD_OFF)

/*! Defines whether ARTI hooks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ARTI_HOOKS_APPLICATION           (STD_OFF)
# define OS_CFG_ARTI_HOOKS_TASK                  (STD_OFF)
# define OS_CFG_ARTI_HOOKS_CAT2ISR               (STD_OFF)
# define OS_CFG_ARTI_HOOKS_SPINLOCK              (STD_OFF)
# define OS_CFG_ARTI_HOOKS_PROTECTIONHOOK        (STD_OFF)
# define OS_CFG_ARTI_HOOKS_SERVICECALLS          (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_TRACE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Trace_Cfg.h
 *********************************************************************************************************************/
