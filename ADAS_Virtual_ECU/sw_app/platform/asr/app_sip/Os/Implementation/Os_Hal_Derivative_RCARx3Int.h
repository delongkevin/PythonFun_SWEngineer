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

#ifndef OS_HAL_DERIVATIVE_RCARX3INT_H
# define OS_HAL_DERIVATIVE_RCARX3INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  RCARx3
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Core
 *********************************************************************************************************************/
/*! Defines whether ARM V7R Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_ARCH_V7R     (STD_ON)

/*! Defines whether V7R Exceptions Handling is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_EXCEPTIONS_V7R     (STD_ON)



/**********************************************************************************************************************
 *  Core ID Shift for Affinity level 1
 *********************************************************************************************************************/
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! Defines whether GIC_NESTED interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_GIC_NESTED     (STD_ON)

/*! Interrupt controller GIC_NESTED, RT_DISTRIBUTOR  base address. */
# define OS_HAL_INTC_GIC_NESTED_RT_DISTRIBUTOR_BASE     (0xF1110000uL)

/*! Interrupt controller GIC_NESTED, RT_CPUIF  base address. */
# define OS_HAL_INTC_GIC_NESTED_RT_CPUIF_BASE     (0xF1120000uL)

/*! Interrupt controller GIC_NESTED, CORE_DISTRIBUTOR  base address. */
# define OS_HAL_INTC_GIC_NESTED_CORE_DISTRIBUTOR_BASE     (0xF0001000uL)

/*! Interrupt controller GIC_NESTED, CORE_CPUIF  base address. */
# define OS_HAL_INTC_GIC_NESTED_CORE_CPUIF_BASE     (0xF0000100uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (512uL)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


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

/*! Defines whether PIT_TMU Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_TMU     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_RCARX3INT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_RCARx3Int.h
 *********************************************************************************************************************/
