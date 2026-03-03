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
 *  \file  Os_Hal_Timer_TtcInt.h
 *  \brief  Data types and interfaces to work with the triple-time counter (TTC).
 *  \details  TTC module features:
 *              - Can be used as FRT or PIT.
 *              - Three independent 32-bit timer/counters.
 *              - 16-bit prescaler per clock.
 *              - Three interrupts, one for each timer/counter.
 *              - Increment or decrement counting.
 *
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
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_TTCINT_H
# define OS_HAL_TIMER_TTCINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_TimerInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Number of counters in timer module. */
# define OS_HAL_TIMER_TTC_COUNTER_COUNT           (3)

/*! Counter_Control register, DIS field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_DIS     (1uL << 0)
/*! Counter_Control register, INT field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_INT     (1uL << 1)
/*! Counter_Control register, DEC field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_DEC     (1uL << 2)
/*! Counter_Control register, Match field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_MATCH   (1uL << 3)
/*! Counter_Control register, RST field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_RST     (1uL << 4)
/*! Counter_Control register, Wave_en field. */
# define OS_HAL_TIMER_TTC_COUNTER_CONTROL_WAVE_EN (1uL << 5)

/*! Interrupt_Register register, M1 field. */
# define OS_HAL_TIMER_TTC_INTERRUPT_REGISTER_M1   (1uL << 1)

/*! Interrupt_Enable register, interval interrupt. */
# define OS_HAL_TIMER_TTC_INTERRUPT_ENABLE_IV     (1uL << 0)
/*! Interrupt_Enable register, match1 interrupt. */
# define OS_HAL_TIMER_TTC_INTERRUPT_ENABLE_M1     (1uL << 1)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! TTC module Layout. */
typedef struct
{
  uint32 ClockControl[OS_HAL_TIMER_TTC_COUNTER_COUNT];            /*!< Clock Control register. */
  uint32 CounterControl[OS_HAL_TIMER_TTC_COUNTER_COUNT];          /*!< Operational mode and reset. */
  uint32 CounterValue[OS_HAL_TIMER_TTC_COUNTER_COUNT];            /*!< Current counter value. */
  uint32 IntervalCounter[OS_HAL_TIMER_TTC_COUNTER_COUNT];         /*!< Interval value. */
  uint32 Match1[OS_HAL_TIMER_TTC_COUNTER_COUNT];                  /*!< Match1 value. */
  uint32 Match2[OS_HAL_TIMER_TTC_COUNTER_COUNT];                  /*!< Match2 value. */
  uint32 Match3[OS_HAL_TIMER_TTC_COUNTER_COUNT];                  /*!< Match3 value. */
  uint32 InterruptRegister[OS_HAL_TIMER_TTC_COUNTER_COUNT];       /*!< Counter Interval, Match, Overflow and Events.. */
  uint32 InterruptEnable[OS_HAL_TIMER_TTC_COUNTER_COUNT];         /*!< ANDed with corresponding Interrupt Register.. */
  uint32 EventControl[OS_HAL_TIMER_TTC_COUNTER_COUNT];            /*!< Enable, pulse and overflow. */
  uint32 EventRegister[OS_HAL_TIMER_TTC_COUNTER_COUNT];           /*!< Pclk cycle count for event. */
} Os_Hal_TtcModuleType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#endif /* OS_HAL_TIMER_TTCINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_TtcInt.h
 **********************************************************************************************************************/
