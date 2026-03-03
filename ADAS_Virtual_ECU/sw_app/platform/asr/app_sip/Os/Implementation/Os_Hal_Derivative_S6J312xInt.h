/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Derivative
 * \{
 *
 * \file
 * \brief  This file contains derivative specific information.
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#ifndef OS_HAL_DERIVATIVE_S6J312XINT_H
# define OS_HAL_DERIVATIVE_S6J312XINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  S6J312x
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Core
 *********************************************************************************************************************/
/*! Defines whether ARM V7R Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_ARCH_V7R     (STD_ON)

/*! Defines whether TRAVEO Exceptions Handling is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_EXCEPTIONS_TRAVEO     (STD_ON)



/**********************************************************************************************************************
 *  Core ID Shift for Affinity level 1
 *********************************************************************************************************************/
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! Defines whether TRAVEO interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_TRAVEO     (STD_ON)

/*! TRAVEO interrupt controller base address. */
# define OS_HAL_INTC_TRAVEO_BASE     (0xB0400000uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (512uL)


/*! Number of available FIQ. */
# define OS_HAL_INTC_NUMBER_OF_FIQS       (32uL)

/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines whether PIT_RELOADTIMER Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_RELOADTIMER     (STD_ON)

/*! Defines whether FRT_FRT Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_FRT_FRT     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_S6J312XINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_S6J312xInt.h
 *********************************************************************************************************************/
