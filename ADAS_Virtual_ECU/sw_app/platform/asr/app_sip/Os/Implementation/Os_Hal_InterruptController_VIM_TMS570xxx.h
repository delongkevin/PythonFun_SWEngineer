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
 *  \addtogroup  Os_Hal_Interrupt
 *  \{
 *
 *  \file
 *  \brief   HAL interface to work with the Vectored Interrupt Manager (VIM).
 *  \details
 *  Internal comment removed.
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

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_INTERRUPTCONTROLLER_VIM_TMS570_H
# define OS_HAL_INTERRUPTCONTROLLER_VIM_TMS570_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_Hal_InterruptController_VIM_General.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! VIM system software interrupt request register. */
#define OS_HAL_SSIR1                    (*(volatile uint32*)0xFFFFFFB0uL)

/*! VIM system software interrupt vector register. */
#define OS_HAL_SSIVECT                  (*(volatile uint32*)0xFFFFFFF4uL)

/*! VIM system software interrupt request key value. */
#define OS_HAL_SSKEY1                            0x7500uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/*! VIM channel control registers. */
# define OS_HAL_INTC_VIM_CHANNCTRL(x) (*(volatile uint8*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x80uL + (((x)/4uL) * 4uL) + ((x)%4uL)))


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_INTC_InitSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_InitSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Set the interrupt priority for given IRQ source to given level. */
  OS_HAL_INTC_VIM_CHANNCTRL(InterruptConfig->Level) = (uint8)(InterruptConfig->Source);                                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_VIM_CHANNCTRL */
  OS_HAL_INTC_VIM_FIRQPR(InterruptConfig->Level) &= (~(uint32)(1uL << (InterruptConfig->Level % 32uL)));                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_VIM_FIRQPR */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerCrossCoreInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerCrossCoreInterrupt,
(
  uint32 CoreID,
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Not supported: single core derivative.*/
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_VIM_TMS570_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_VIM_TMS570xxx.h
 *********************************************************************************************************************/

