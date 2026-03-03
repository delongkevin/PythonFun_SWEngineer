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

#ifndef OS_HAL_DERIVATIVE_E31XX_E32XX_E33XXINT_H
# define OS_HAL_DERIVATIVE_E31XX_E32XX_E33XXINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  E31xx_E32xx_E33xx
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
/* Defines whether VIC_E3 interrupt controller is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_INTC_VIC_E3    (STD_ON)


/*!  Number of available vector tables for each core. */
# define OS_HAL_NUMBER_OF_VECTOR_TABLES   (1uL)


/*! All available interrupt controller registers(address setting to 0x0uL means not available for current derivative) */
# define OS_HAL_E3_VIC_BASE_ADDRESS_CoreSF    (0xF1C00000uL)
# define OS_HAL_E3_VIC_BASE_ADDRESS_CoreSP0   (0x0uL)
# define OS_HAL_E3_VIC_BASE_ADDRESS_CoreSP1   (0x0uL)
# define OS_HAL_E3_VIC_BASE_ADDRESS_CoreSX0   (0x0uL)
# define OS_HAL_E3_VIC_BASE_ADDRESS_CoreSX1   (0x0uL)

/**********************************************************************************************************************
 *  Timer
 *********************************************************************************************************************/
/*! Defines whether PIT_ETMR_SEMIDRIVE Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_PIT_ETMR_SEMIDRIVE     (STD_ON)

/*! Defines whether FRT_BTM_SEMIDRIVE Timer Unit is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_TIMER_FRT_BTM_SEMIDRIVE     (STD_ON)


/**********************************************************************************************************************
 *  Memory Protection
 *********************************************************************************************************************/
/*! Defines whether PMSAV7 Memory Protection Architecture is supported (STD_ON) or not (STD_OFF). */
# define OS_HAL_MEMORY_PROTECTION_PMSAV7     (STD_ON)



#endif /* OS_HAL_DERIVATIVE_E31XX_E32XX_E33XXINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_E31xx_E32xx_E33xxInt.h
 *********************************************************************************************************************/
