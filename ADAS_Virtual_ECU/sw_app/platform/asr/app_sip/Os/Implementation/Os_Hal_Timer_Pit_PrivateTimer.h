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
 *  \addtogroup  Os_Hal_Timer
 *  \{
 *
 *  \file  Os_Hal_Timer_Pit_PrivateTimer.h
 *  \brief Primitives to work with ARM Cortex-A9MP 32-bit Private Timer as Programmable Interval Timer.
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

#ifndef  OS_HAL_TIMER_PIT_PRIVATETIMER_H
# define OS_HAL_TIMER_PIT_PRIVATETIMER_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_Common.h"
# include "Os_Hal_Timer_Types.h"
# include "Os_Hal_Interrupt.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Private Timer count enable bit. */
#define OS_HAL_TIMER_PRIVATE_COUNT_ENABLE_BIT                 (1uL)
/*! Private Timer interrupt event flag. */
#define OS_HAL_TIMER_PRIVATE_INTERRUPT_EVENT_BIT              (1uL)
/*! Private Timer Auto reload enable bit. */
#define OS_HAL_TIMER_PRIVATE_AUTORELOAD_ENABLE_BIT            (1uL <<  1)
/*! Private Timer interrupt request enable bit. */
#define OS_HAL_TIMER_PRIVATE_INTERRUPT_ENABLE_BIT             (1uL <<  2)


/*! Private Timer Load Register offset. */
#define OS_HAL_TIMER_PRIVATE_LOAD_OFFSET                      (0x00uL)
/*! Private Timer Counter Register offset. */
#define OS_HAL_TIMER_PRIVATE_COUNTER_OFFSET                   (0x04uL)
/*! Private Timer Control Register offset. */
#define OS_HAL_TIMER_PRIVATE_CONTROL_OFFSET                   (0x08uL)
/*! Private Timer Interrupt Status Register offset. */
#define OS_HAL_TIMER_PRIVATE_INTERRUPT_OFFSET                 (0x0CuL)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Programmable interval timer configuration information for Reload timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  uint32 TimerBaseAddress; /*!< Timer base address. */
  uint32 ReloadValue;      /*!< Reload value. */
  uint32 InterruptSource;  /*!< Interrupt source. */
};


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                         /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerPitInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Set reload value. */
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_PRIVATE_LOAD_OFFSET) =                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      TimerConfig->ReloadValue;

  /* #20 Enable reload operation. */
  /* #30 Enable interrupt requests. */
  /* #40 Enable the timer. */
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_PRIVATE_CONTROL_OFFSET) =                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      OS_HAL_TIMER_PRIVATE_COUNT_ENABLE_BIT                 |
      OS_HAL_TIMER_PRIVATE_AUTORELOAD_ENABLE_BIT            |
      OS_HAL_TIMER_PRIVATE_INTERRUPT_ENABLE_BIT;

  /* #50 Enable Private Timer interrupt source in interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0,  OS_HAL_ISR_INTC_ROOT);
}


/***********************************************************************************************************************
 *  Os_Hal_TimerPitAckAndReload()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitAckAndReload,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Clear the interrupt event flag. */
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_PRIVATE_INTERRUPT_OFFSET) |=                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      OS_HAL_TIMER_PRIVATE_INTERRUPT_EVENT_BIT;
}


/***********************************************************************************************************************
 *  Os_Hal_TimerPitIsPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitIsPending,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Return the value of the interrupt flag. */
  return (*(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_PRIVATE_INTERRUPT_OFFSET) &                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
      OS_HAL_TIMER_PRIVATE_INTERRUPT_EVENT_BIT);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_PRIVATETIMER_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_PrivateTimer.h
 *********************************************************************************************************************/

