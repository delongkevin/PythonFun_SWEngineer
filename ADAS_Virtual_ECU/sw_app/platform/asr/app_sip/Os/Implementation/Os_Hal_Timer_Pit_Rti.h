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
 *  \file  Os_Hal_Timer_Pit_Rti.h
 *  \brief  HAL interface to work with the Real-Time Interface counter (RTI) module as a periodic interval timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_RTI_H
# define OS_HAL_TIMER_PIT_RTI_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_RtiInt.h"

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
/*! Programmable interval timer configuration information for RTI timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  Os_Hal_RtiCompareUnitType CompareUnitId;    /*!< Compare Unit ID. */
  uint32 BaseAddress;                         /*!< Timer Unit base address. */
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile CONSTP2VAR(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress; /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  const uint8 compareId = (uint8)TimerConfig->CompareUnitId;
  const uint32 reloadValue = TimerConfig->ReloadValue;

  /* #10 Stop the counter before starting the initialization process. */
  rti->GlobalControl &= ~(OS_HAL_TIMER_RTI_ENABLE_BIT << OS_HAL_TIMER_PIT_RTI_COUNTER_ID);                              /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #20 Bind the configured compare register to the counter. */
  rti->CompareControl |= (OS_HAL_TIMER_PIT_RTI_COUNTER_ID << (compareId * 4u));                                         /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #30 Set the frequency of the Free Running Counter to Rticlk/2. */
  rti->Counter[OS_HAL_TIMER_PIT_RTI_COUNTER_ID].UpCounterCompare = OS_HAL_TIMER_RTI_PRESCALER_RTICLK_DIV_2;            /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #40 Set the compare value. */
  rti->Compare[compareId].CompareValue = reloadValue;                                                                   /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COMPAREUNITID */

  /* #50 Set the reload value. */
  rti->Compare[compareId].UpdateCompareValue = reloadValue;                                                             /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COMPAREUNITID */

  /* #60 Reset Free running counter value. */
  rti->Counter[OS_HAL_TIMER_PIT_RTI_COUNTER_ID].FreeRunningCounterValue = 0;                                            /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #70 Reset Up counter value. */
  rti->Counter[OS_HAL_TIMER_PIT_RTI_COUNTER_ID].UpCounterValue = 0;                                                     /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #80 Enable the RTI to generate an interrupt if compare match occurs. */
  rti->SetInterruptEnable |= (OS_HAL_TIMER_RTI_INTERRUPT_ENABLE_BIT << compareId);                                      /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #90 Clear Interrupt Flag Register. */
  rti->InterruptFlag = (uint32)(OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT << (compareId));                                   /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #100 Enable RTI counter interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0,  OS_HAL_ISR_INTC_ROOT);

  /* #110 Start the counter. */
  rti->GlobalControl |= OS_HAL_TIMER_RTI_ENABLE_BIT << OS_HAL_TIMER_PIT_RTI_COUNTER_ID;                                 /* SBSW_OS_HAL_RTI_MODULETYPE */
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
  /* #10 Set the clear pending interrupt bit. */
  volatile CONSTP2VAR(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress; /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  rti->InterruptFlag = (uint32)(OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT << (uint8)(TimerConfig->CompareUnitId));           /* SBSW_OS_HAL_RTI_MODULETYPE */
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
  /* #10 Return pending state of interrupt flag register. */
  volatile CONSTP2CONST(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress;  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  return rti->InterruptFlag & ((uint32)(OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT << (uint8)(TimerConfig->CompareUnitId)));  /* SBSW_OS_HAL_RTI_MODULETYPE */
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
