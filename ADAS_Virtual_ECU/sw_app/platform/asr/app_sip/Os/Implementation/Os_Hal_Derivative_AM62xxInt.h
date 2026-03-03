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

#ifndef OS_HAL_DERIVATIVE_AM62XXINT_H
# define OS_HAL_DERIVATIVE_AM62XXINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AM62xx
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
/*! Defines whether TwoLevelSupprt is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_VIM_TWOLEVEL     (STD_ON)
/*! Defines whether VIM_JACINTO7 interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_VIM_JACINTO7    (STD_ON)

/*! VIM INTC base address. */
# define OS_HAL_JACINTO7_MCU_INTC_VIM_BASE    (0x2FFF0000uL)
# define OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE   (0x00000000uL)

/*! Higher significant bits of Jacinto7 MCU Vectored Interrupt Manager base address. */
# define OS_HAL_JACINTO7_MCU_INTC_VIM_BASE_ADDRESS_HIGH     0x2FFF
/*! Lower significant bits of Jacinto7 MCU Vectored Interrupt Manager base address. */
# define OS_HAL_JACINTO7_MCU_INTC_VIM_BASE_ADDRESS_LOW      0x0000

/*! Higher significant bits of Jacinto7 MAIN Vectored Interrupt Manager base address. */
# define OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE_ADDRESS_HIGH    0x0000
/*! Lower significant bits of Jacinto7 MAIN Vectored Interrupt Manager base address. */
# define OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE_ADDRESS_LOW     0x0000

/*! VIM dummy interrupt source. */
# define OS_HAL_INTC_VIM_DUMMY_SOURCE            (99uL)

/*! Number of available IRQ. */
# define OS_HAL_JACINTO7_MCU_INTC_NUMBER_OF_IRQS    (256uL)
# define OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS   (0uL)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines whether FRT_TIMER_JACINTO7 Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_FRT_TIMER_JACINTO7     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_AM62XXINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_AM62xxInt.h
 *********************************************************************************************************************/
