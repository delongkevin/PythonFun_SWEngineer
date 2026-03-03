/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup  Os_Hal_Timer
 *  \{
 *
 *  \file  Os_Hal_Timer_Pit_DualTimer.h
 *  \brief  HAL interface to work with the 32-bit Dual Timer of the LG6110 family.
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
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_DUALTIMER_H
# define OS_HAL_TIMER_PIT_DUALTIMER_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Timer_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Timer control register */
/* Timer enable bit */
# define Os_Hal_Timer_Pit_DualTimer_Enable                            (1uL << 7)
/* Timer mode: 1 = timer is in periodic mode, 0 = timer is in free-running mode */
# define Os_Hal_Timer_Pit_DualTimer_TimerMode                         (1uL << 6)
/* Interrupt enable bit */
# define Os_Hal_Timer_Pit_DualTimer_InterruptEnable                   (1uL << 5)
/* Prescale bits: 00 = 0 stages of prescale, clock is divided by 1 */
# define Os_Hal_Timer_Pit_DualTimer_TimerPre                          (1uL << 2)
/* Timer size: 1 = 32-bit counter */
# define Os_Hal_Timer_Pit_DualTimer_TimerSize                         (1uL << 1)
/* One Shot Count: 0 = wrapping mode */
# define Os_Hal_Timer_Pit_DualTimer_CounterMode                       (1uL << 0)

/* Timer interrupt status register */
# define Os_Hal_Timer_Pit_Interrupt_Status                            (0x1uL)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
 /*! Memory mapped Dual Timer registers corresponding to the memory layout */
typedef struct
{
  uint32 TimerLoad;          /* Load Value for Timer. (32 bit read/write). */
  uint32 TimerValue;         /* The current value for Timer. (32 bit read). */
  uint32 TimerControl;       /* Timer control register. (32 bit read/write). */
  uint32 TimerIntClr;        /* Timer interrupt clear register. (32 bit write).*/
  uint32 TimerRIS;           /* Timer raw interrupt status. (32 bit read). */
  uint32 TimerMIS;           /* Timer masked interrupt status. (32 bit read). */
  uint32 TimerBGLoad;        /* Background load value for Timer. (32 bit read/write). */
} Os_Hal_LGDualTimerType;

 /*! Periodic interrupt timer configuration information for LG6110 32-bit Dual Timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  /*! The LG Dual Timer base address. */
  volatile Os_Hal_LGDualTimerType * const DualTimer;
  /*! The timer reload value. */
  uint32 ReloadValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
};

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Disable the timer before starting the initialization process. */
  TimerConfig->DualTimer->TimerControl &= ~Os_Hal_Timer_Pit_DualTimer_Enable;                                           /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Configure the counter reload value. */
  TimerConfig->DualTimer->TimerLoad = TimerConfig->ReloadValue;                                                         /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #30 Configure the timer in periodic mode. */
  TimerConfig->DualTimer->TimerControl |= Os_Hal_Timer_Pit_DualTimer_TimerMode;                                         /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #40 Configure the timer prescale, clock is divided by 1. */
  TimerConfig->DualTimer->TimerControl &= ~Os_Hal_Timer_Pit_DualTimer_TimerPre;                                         /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #50 Configure the timer size to 32-bit counter. */
  TimerConfig->DualTimer->TimerControl |= Os_Hal_Timer_Pit_DualTimer_TimerSize;                                         /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #60 Configure the timer as wrapping mode. */
  TimerConfig->DualTimer->TimerControl &= ~Os_Hal_Timer_Pit_DualTimer_CounterMode;                                      /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #70 Enable the underflow interrupt. */
  TimerConfig->DualTimer->TimerControl |= Os_Hal_Timer_Pit_DualTimer_InterruptEnable;                                   /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #80 Enable the interrupt source for the counter. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, OS_HAL_ISR_INTC_ROOT);

  /* #90 Start the timer. */
  TimerConfig->DualTimer->TimerControl |= Os_Hal_Timer_Pit_DualTimer_Enable;                                            /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  /* #10 Write interrupt clear register. */
  TimerConfig->DualTimer->TimerIntClr = 0xFFuL;                                                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  /* #10 Return masked interrupt status from the counter.  */
  return ((TimerConfig->DualTimer->TimerMIS) & Os_Hal_Timer_Pit_Interrupt_Status);                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_DUALTIMER_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_DualTimer.h
 *********************************************************************************************************************/
