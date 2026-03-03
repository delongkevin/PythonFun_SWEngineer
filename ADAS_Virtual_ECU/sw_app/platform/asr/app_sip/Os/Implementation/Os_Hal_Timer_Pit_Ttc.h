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
 *  \file  Os_Hal_Timer_Pit_Ttc.h
 *  \brief  HAL interface to work with the triple-time counter (TTC) module as a periodic interval timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_TTC_H
# define OS_HAL_TIMER_PIT_TTC_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_TtcInt.h"

/* Os module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Interrupt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Programmable interval timer configuration information for TTC timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  volatile Os_Hal_TtcModuleType * const Ttc;  /*!< TTC module base address. */
  uint32 CounterId;                           /*!< Counter ID. */
  uint32 ReloadValue;                         /*!< Reload value. */
  uint32 InterruptSource;                     /*!< Interrupt source. */
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile Os_Hal_TtcModuleType * const ttc = TimerConfig->Ttc;
  const uint32 counterId = TimerConfig->CounterId;

  /* #10 Write reset value to counter control register (no waveform, counter stopped). */
  ttc->CounterControl[counterId] = OS_HAL_TIMER_TTC_COUNTER_CONTROL_WAVE_EN | OS_HAL_TIMER_TTC_COUNTER_CONTROL_DIS;     /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #20 Set interval count value to zero. */
  ttc->IntervalCounter[counterId] = 0uL;                                                                                /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #30 Reset IER. */
  ttc->InterruptEnable[counterId] = 0uL;                                                                                /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #40 Reset ISR. */
  ttc->InterruptRegister[counterId] = 0uL;                                                                              /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #50 Reset counter. */
  ttc->CounterControl[counterId] |= OS_HAL_TIMER_TTC_COUNTER_CONTROL_RST;                                               /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #60 Set interval count value to reload value. */
  ttc->IntervalCounter[counterId] = TimerConfig->ReloadValue;                                                           /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #70 Select down counting interval mode. */
  ttc->CounterControl[counterId] |= OS_HAL_TIMER_TTC_COUNTER_CONTROL_INT | OS_HAL_TIMER_TTC_COUNTER_CONTROL_DEC;        /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #80 Enable interrupt generation for interval. */
  ttc->InterruptEnable[counterId] = OS_HAL_TIMER_TTC_INTERRUPT_ENABLE_IV;                                               /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */

  /* #90 Enable triple-timer counter interrupt in interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0,  OS_HAL_ISR_INTC_ROOT);

  /* #100 Start timer (Clear CounterControl.DIS). */
  ttc->CounterControl[counterId] &= ~OS_HAL_TIMER_TTC_COUNTER_CONTROL_DIS;                                              /* SBSW_OS_HAL_PWA_PITCONFIG_TTC */
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
  volatile uint32 forceRead;

  /* #10 Read from Interrupt_Register of configured counter. */
  forceRead = TimerConfig->Ttc->InterruptRegister[TimerConfig->CounterId];
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
  /* #10 Return value of Interrupt_Register of configured counter. */
  return TimerConfig->Ttc->InterruptRegister[TimerConfig->CounterId];
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_TTC_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_Ttc.h
 **********************************************************************************************************************/
