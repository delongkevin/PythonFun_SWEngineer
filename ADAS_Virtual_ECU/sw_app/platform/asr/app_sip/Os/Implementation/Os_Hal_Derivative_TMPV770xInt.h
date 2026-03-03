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
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#ifndef OS_HAL_DERIVATIVE_TMPV770XINT_H
# define OS_HAL_DERIVATIVE_TMPV770XINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TMPV770x
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
/*! Defines whether SIINTC interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_SIINTC     (STD_ON)

/*! Interrupt controller SIINTC, SICOMM  base address. */
# define OS_HAL_INTC_SIINTC_SICOMM_BASE     (0x10020000uL)

/*! Interrupt controller SIINTC, CORE  base address. */
# define OS_HAL_INTC_SIINTC_CORE_BASE     (0x10000000uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (256uL)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines SICMPT Timer Unit 0 base address. */
# define OS_HAL_TIMER_SICMPT0_BASE    (0x100A0000uL)

/*! Defines SICMPT Timer Unit 1 base address. */
# define OS_HAL_TIMER_SICMPT1_BASE    (0x100A8000uL)

/*! Defines whether FRT_SICMPT Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_FRT_SICMPT     (STD_ON)

/*! Defines whether PIT_SICMPT Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_SICMPT     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_TMPV770XINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_TMPV770xInt.h
 *********************************************************************************************************************/
