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

#ifndef OS_HAL_DERIVATIVE_AM26XXINT_H
# define OS_HAL_DERIVATIVE_AM26XXINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AM26xx
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Core
 *********************************************************************************************************************/
/*! Defines whether ARM V7R Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_ARCH_V7R     (STD_ON)

/*! Defines whether V7R Exceptions Handling is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_EXCEPTIONS_V7R     (STD_ON)

/*! Defines SPINLOCK module base address. */
# define OS_HAL_SPINLOCK_HW_BASEADDRESS     (0x50E00000uL)


/**********************************************************************************************************************
 *  Core ID Shift for Affinity level 1
 *********************************************************************************************************************/
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1    (7)


/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/* Defines whether VIM_TPRXX interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_VIM_TPRXX    (STD_ON)

/*! Interrupt controller VIM_TPRXX, CTRL  base address. */
# define OS_HAL_INTC_VIM_CTRL_BASE    (0x50F00000uL)

/*! Higher significant bits of AM26xx Vectored Interrupt Manager base address. */
# define OS_HAL_TPRXX_INTC_VIM_BASE_ADDRESS_HIGH     0x50F0
/*! Lower significant bits of AM26xx Vectored Interrupt Manager base address. */
# define OS_HAL_TPRXX_INTC_VIM_BASE_ADDRESS_LOW      0x0000

/*! VIM dummy interrupt source. */
# define OS_HAL_INTC_VIM_DUMMY_SOURCE            (255uL)

/*! Number of avaiable IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (256uL)

/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines RTI Timer Unit Base Address. */
# define OS_HAL_TIMER_RTI_BASE    (0x52180000uL)

/*! Defines whether PIT_RTI Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_RTI     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_AM26XXINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_AM26xxInt.h
 *********************************************************************************************************************/
