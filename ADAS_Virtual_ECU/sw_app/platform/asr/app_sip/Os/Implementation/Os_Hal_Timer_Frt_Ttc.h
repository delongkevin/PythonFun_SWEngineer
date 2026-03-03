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
 *  \file  Os_Hal_Timer_Frt_Ttc.h
 *  \brief  HAL interface to work with the triple-time counter(TTC) module as a free running timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_FRT_TTC_H
# define OS_HAL_TIMER_FRT_TTC_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_TtcInt.h"

/* Os kernel module dependencies */

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
/*! High resolution timer configuration information for TTC timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  volatile Os_Hal_TtcModuleType * const Ttc;  /*!< TTC module base address. */
  uint32 CounterId;                           /*!< Counter ID. */
  uint32 CompareValue;                        /*!< Compare value. */
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
 *  Os_Hal_TimerFrtInit()
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
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile Os_Hal_TtcModuleType * const ttc = TimerConfig->Ttc;
  const uint32 counterId = TimerConfig->CounterId;

  /* #10 Write reset value to counter control register (no waveform, counter stopped). */
  ttc->CounterControl[counterId] = OS_HAL_TIMER_TTC_COUNTER_CONTROL_WAVE_EN | OS_HAL_TIMER_TTC_COUNTER_CONTROL_DIS;     /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #20 Load timer compare value. */
  ttc->Match1[counterId] = TimerConfig->CompareValue;                                                                   /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #30 Reset IER. */
  ttc->InterruptEnable[counterId] = 0uL;                                                                                /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #40 Reset ISR. */
  ttc->InterruptRegister[counterId] = 0uL;                                                                              /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #50 Reset counter. */
  ttc->CounterControl[counterId] |= OS_HAL_TIMER_TTC_COUNTER_CONTROL_RST;                                               /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #60 Select match mode. */
  ttc->CounterControl[counterId] |= OS_HAL_TIMER_TTC_COUNTER_CONTROL_MATCH;                                             /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #70 Enable interrupt generation for match1. */
  ttc->InterruptEnable[counterId] = OS_HAL_TIMER_TTC_INTERRUPT_ENABLE_M1;                                               /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */

  /* #80 Enable triple-timer counter interrupt in interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0u,  OS_HAL_ISR_INTC_ROOT);

  /* #90 Start timer (Clear CounterControl.DIS). */
  ttc->CounterControl[counterId] &= ~OS_HAL_TIMER_TTC_COUNTER_CONTROL_DIS;                                              /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Return value of Counter_Value register of configured counter. */
  return TimerConfig->Ttc->CounterValue[TimerConfig->CounterId];
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCompareValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Return value of Compare_Value register of configured counter. */
  return TimerConfig->Ttc->Match1[TimerConfig->CounterId];
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtSetCompareValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig,
  Os_Hal_TimerFrtTickType ExpirationTime
))
{
  /* #10 Set Match1 register of configured counter. */
  TimerConfig->Ttc->Match1[TimerConfig->CounterId] = ExpirationTime;                                                    /* SBSW_OS_HAL_PWA_FRTCONFIG_TTC */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtAcknowledge()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtAcknowledge,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile uint32 forceRead;

  /* #10 Read from Interrupt_Register of configured counter. */
  forceRead = TimerConfig->Ttc->InterruptRegister[TimerConfig->CounterId];
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtTriggerIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtTriggerIrq,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Trigger interrupt source of the given timer. */
  Os_Hal_INTC_TriggerPeripheralInterrupt(TimerConfig->InterruptSource, OS_HAL_ISR_INTC_ROOT);
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_FRT_TTC_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_Ttc.h
 **********************************************************************************************************************/
