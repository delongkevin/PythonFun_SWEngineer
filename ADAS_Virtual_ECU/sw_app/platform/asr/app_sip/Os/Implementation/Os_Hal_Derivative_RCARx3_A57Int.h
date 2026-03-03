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

#ifndef OS_HAL_DERIVATIVE_RCARX3_A57INT_H
# define OS_HAL_DERIVATIVE_RCARX3_A57INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  RCARx3_A57
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Core
 *********************************************************************************************************************/
/*! Defines whether ARM V7A Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_ARCH_V7A     (STD_ON)

/*! Defines whether V7A Exceptions Handling is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_EXCEPTIONS_V7A     (STD_ON)



/**********************************************************************************************************************
 *  Core ID Shift for Affinity level 1
 *********************************************************************************************************************/
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! Defines whether GIC interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_GIC     (STD_ON)

/*! Interrupt controller GIC, DISTRIBUTOR  base address. */
# define OS_HAL_INTC_GIC_DISTRIBUTOR_BASE     (0xF1010000uL)

/*! Interrupt controller GIC, CPUIF  base address. */
# define OS_HAL_INTC_GIC_CPUIF_BASE     (0xF1020000uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (512uL)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)

/*! Lowest interrupt priority */
# define OS_HAL_INTC_GIC_LOWEST_INTERRUPT_PRIORITY    (0x000000F0uL)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines TMU Timer Unit 0 base address. */
# define OS_HAL_TIMER_TMU0_BASE    (0xE61E0004uL)

/*! Defines TMU Timer Unit 1 base address. */
# define OS_HAL_TIMER_TMU1_BASE    (0xE6FC0004uL)

/*! Defines TMU Timer Unit 2 base address. */
# define OS_HAL_TIMER_TMU2_BASE    (0xE6FD0004uL)

/*! Defines TMU Timer Unit 3 base address. */
# define OS_HAL_TIMER_TMU3_BASE    (0xE6FE0004uL)

/*! Defines TMU Timer Unit 4 base address. */
# define OS_HAL_TIMER_TMU4_BASE    (0xFFC00004uL)

/*! Defines whether PIT_TMU Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_TMU     (STD_ON)

/*! Defines whether FRT_V8R_GENERICTIMER Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_FRT_V8R_GENERICTIMER     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines that no Memory Protection Architecture is supported. */
# define OS_HAL_MEMORY_PROTECTION_CORE_MPU_UNSUPPORTED     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_RCARX3_A57INT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RCARx3_A57Int.h
 *********************************************************************************************************************/
