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
 *  \file  Os_Hal_Timer_Pit_ReloadTimer.h
 *  \brief  Primitives to work with Spansion 32-bit Reload Timer of the Traveo family.
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

#ifndef  OS_HAL_TIMER_PIT_RELOADTIMER_H
# define OS_HAL_TIMER_PIT_RELOADTIMER_H
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

/*! RLTn_TMCSR: Timer Control Status Register offset. */
# define OS_HAL_TIMER_RLT_CONTROL_STATUS_OFFSET       (0x8uL)
/*! RLT_TMCSR.INTE: Timer interrupt request enable bit. */
# define OS_HAL_TIMER_RLT_TMCSR_INTERRUPT_ENABLE_BIT           (1uL <<  3)
/*! RLT_TMCSR.RELD: Reload bit enables reload operation. */
# define OS_HAL_TIMER_TLR_TMCSR_RELOAD_ENABLE_BIT              (1uL <<  4)
/*! RLT_TMCSR.DBGE: Debug mode enable bit. */
# define OS_HAL_TIMER_TLR_TMCSR_DEBUG_MODE_ENABLE_BIT          (1uL <<  7)
/*! RLT_TMCSR.MOD: Operation mode field. */
# define OS_HAL_TIMER_TLR_TMCSR_MODE(x)                        ((x) << 13)
/*! RLT_TMCSR.UF: Timer interrupt request flag. */
# define OS_HAL_TIMER_TLR_TMCSR_UNDERFLOW_INTERRUPT_BIT        (1uL << 16)
/*! RLT_TMCSR.UFCLR: Underflow interrupt clear. */
# define OS_HAL_TIMER_TLR_TMCSR_UNDERFLOW_INTERRUPT_CLEAR_BIT  (1uL << 17)
/*! RLT_TMCSR.TRG: Software trigger bit. */
# define OS_HAL_TIMER_TLR_TMCSR_SOFTWARE_TRIGGER_BIT           (1uL << 18)
/*! RLT_TMCSR.CNTE: Timer count enable bit. */
# define OS_HAL_TIMER_TLR_TMCSR_COUNT_ENABLE_BIT               (1uL << 24)

/*! RLTn_TMRLR: Timer reload value. */
# define OS_HAL_TIMER_RLT_RELOAD_OFFSET               (0x10uL)

/*! RLTn_TMR: Current count value. */
# define OS_HAL_TIMER_RLT_TIMER_OFFSET                (0x14uL)


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
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_RLT_RELOAD_OFFSET) =                                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      TimerConfig->ReloadValue;

  /* #20 Trigger the timer. */
  /* #30 Clear the interrupt request flag. */
  /* #40 Enable debug mode. */
  /* #50 Enable reload operation. */
  /* #60 Enable interrupt requests. */
  /* #70 Enable the timer. */
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_RLT_CONTROL_STATUS_OFFSET) =                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      OS_HAL_TIMER_TLR_TMCSR_COUNT_ENABLE_BIT               |
      OS_HAL_TIMER_TLR_TMCSR_SOFTWARE_TRIGGER_BIT           |
      OS_HAL_TIMER_TLR_TMCSR_UNDERFLOW_INTERRUPT_CLEAR_BIT  |
      OS_HAL_TIMER_TLR_TMCSR_DEBUG_MODE_ENABLE_BIT          |
      OS_HAL_TIMER_TLR_TMCSR_RELOAD_ENABLE_BIT              |
      OS_HAL_TIMER_RLT_TMCSR_INTERRUPT_ENABLE_BIT;

  /* #80 Enable the timers' interrupt source. */
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
  /* #10 Clear the interrupt flag (RLT_TMCSR.UFCLR). */
  *(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_RLT_CONTROL_STATUS_OFFSET) |=                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER */
      OS_HAL_TIMER_TLR_TMCSR_UNDERFLOW_INTERRUPT_CLEAR_BIT;
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
  /* #10 Return the value of the interrupt flag (RLT_TMCSR.UFCLR). */
  return (*(volatile uint32*)(TimerConfig->TimerBaseAddress + OS_HAL_TIMER_RLT_CONTROL_STATUS_OFFSET) &                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
      OS_HAL_TIMER_TLR_TMCSR_UNDERFLOW_INTERRUPT_BIT);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_RELOADTIMER_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_HwTimer_Pit_ReloadTimer.h
 *********************************************************************************************************************/
