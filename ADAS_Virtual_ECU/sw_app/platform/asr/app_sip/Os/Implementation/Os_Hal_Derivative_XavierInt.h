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

#ifndef OS_HAL_DERIVATIVE_XAVIERINT_H
# define OS_HAL_DERIVATIVE_XAVIERINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Xavier
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Core
 *********************************************************************************************************************/
/*! Defines whether ARM V7R Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_ARCH_V7R     (STD_ON)

/*! Defines whether XAVIER Exceptions Handling is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_EXCEPTIONS_XAVIER     (STD_ON)



/**********************************************************************************************************************
 *  Core ID Shift for Affinity level 1
 *********************************************************************************************************************/
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1

/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! Defines whether AVIC interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_AVIC     (STD_ON)

/*! Interrupt controller AVIC, AVIC0  base address. */
# define OS_HAL_INTC_AVIC_AVIC0_BASE     (0x0B020000uL)

/*! Interrupt controller AVIC, AVIC0_FIQSTATUS  base address. */
# define OS_HAL_INTC_AVIC_AVIC0_FIQSTATUS_BASE     (0x0B020004uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (32uL)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (2uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines TKE module base address for the SCE cluster. */
# define OS_HAL_TIMER_TKE_BASE    (0x0B0F0000uL)
/*! Defines whether PIT_TMR Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_TMR     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_XAVIERINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_XavierInt.h
 *********************************************************************************************************************/
