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
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#ifndef OS_HAL_DERIVATIVE_G9XINT_H
# define OS_HAL_DERIVATIVE_G9XINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  G9x
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
# define OS_HAL_CORE_ID_SHIFT_LEVEL_1    (8)


/**********************************************************************************************************************
 *  Interrupt Controller
 *********************************************************************************************************************/
/*! Defines whether GIC interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_GIC    (STD_ON)

/*! Interrupt controller GIC, DISTRIBUTOR  base address. */
# define OS_HAL_INTC_GIC_DISTRIBUTOR_BASE_CORE_SAF      (0xF5401000uL)
# define OS_HAL_INTC_GIC_DISTRIBUTOR_BASE_CORE_SEC      (0xF5411000uL)
# define OS_HAL_INTC_GIC_DISTRIBUTOR_BASE_CORE_MP       (0xF5421000uL)

/*! Interrupt controller GIC, CPUIF  base address. */
# define OS_HAL_INTC_GIC_CPUIF_BASE_CORE_SAF            (0xF5402000uL)
# define OS_HAL_INTC_GIC_CPUIF_BASE_CORE_SEC            (0xF5412000uL)
# define OS_HAL_INTC_GIC_CPUIF_BASE_CORE_MP             (0xF5422000uL)

/*! Number of available IRQ. */
# define OS_HAL_INTC_NUMBER_OF_IRQS       (276uL)

/*! Lowest interrupt priority */
# define OS_HAL_INTC_GIC_LOWEST_INTERRUPT_PRIORITY    (0x000000F8uL)

/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)




/**********************************************************************************************************************
 *  Mailbox Controller
 *********************************************************************************************************************/
/*! Mailbox controller base address. */
# define OS_HAL_MAILBOX_BASE_ADDRESS                    (0xF4040000uL)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines whether PIT_TMR_SEMIDRIVE Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_TMR_SEMIDRIVE     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_G9XINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_G9xInt.h
 *********************************************************************************************************************/
