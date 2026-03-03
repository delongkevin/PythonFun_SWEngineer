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
 *  \file
 *  \brief        HAL interface to work with the Real-time Interrupt (RTI) module as a free running timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_FRT_RTI_H
# define OS_HAL_TIMER_FRT_RTI_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os HAL dependencies */
# include "Os_Hal_Interrupt.h"
# include "Os_Hal_Timer_RtiInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! High resolution timer configuration information for RTI timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  Os_Hal_RtiCompareUnitType CompareUnitId;   /*!< Compare Unit ID. */
  uint32 BaseAddress;                         /*!< Timer Unit base address. */
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

  volatile CONSTP2VAR(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress; /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  const Os_Hal_RtiCompareUnitType compareId = TimerConfig->CompareUnitId;

  /* #10 Stop the counter before starting the initialization process. */
  rti->GlobalControl &= ~(uint32)(OS_HAL_TIMER_RTI_ENABLE_BIT << OS_HAL_TIMER_FRT_RTI_COUNTER_ID);                      /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #20 Bind the configured compare register to the counter. */
  rti->CompareControl |= (uint32)(OS_HAL_TIMER_FRT_RTI_COUNTER_ID << ((uint8)compareId << 2u));                         /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #30 Set the frequency of the Free Running Counter to Rticlk/2. */
  rti->Counter[OS_HAL_TIMER_FRT_RTI_COUNTER_ID].UpCounterCompare = OS_HAL_TIMER_RTI_PRESCALER_RTICLK_DIV_2;            /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #40 Set the compare value. */
  rti->Compare[compareId].CompareValue = 0;                                                                             /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COMPAREUNITID */

  /* #50 Set the reload value. */
  rti->Compare[compareId].UpdateCompareValue = 0;                                                                       /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COMPAREUNITID */

  /* #60 Reset Free running counter value. */
  rti->Counter[OS_HAL_TIMER_FRT_RTI_COUNTER_ID].FreeRunningCounterValue = 0;                                            /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #70 Reset Up counter value. */
  rti->Counter[OS_HAL_TIMER_FRT_RTI_COUNTER_ID].UpCounterValue = 0;                                                     /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */

  /* #80 Enable the RTI to generate an interrupt if compare match occurs. */
  rti->SetInterruptEnable |= (uint32)(OS_HAL_TIMER_RTI_INTERRUPT_ENABLE_BIT << (uint8)compareId);                       /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #90 Enable RTI counter interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0,  OS_HAL_ISR_INTC_ROOT);

  /* #100 Clear Interrupt Flag Register. */
  rti->InterruptFlag = (uint32)(OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT << (uint8)compareId);                              /* SBSW_OS_HAL_RTI_MODULETYPE */

  /* #110 Start the counter. */
  rti->GlobalControl |= OS_HAL_TIMER_RTI_ENABLE_BIT << OS_HAL_TIMER_FRT_RTI_COUNTER_ID;                                 /* SBSW_OS_HAL_RTI_MODULETYPE */
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
  volatile CONSTP2CONST(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress;  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Return free running counter value. */
  return rti->Counter[OS_HAL_TIMER_FRT_RTI_COUNTER_ID].FreeRunningCounterValue;                                         /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */
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
  volatile CONSTP2CONST(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress;  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  const Os_Hal_RtiCompareUnitType compareId = TimerConfig->CompareUnitId;

  /* #10 Return free running compare value. */
  return rti->Compare[compareId].CompareValue;                                                                          /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COUNTER */
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
  volatile CONSTP2VAR(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress; /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  const Os_Hal_RtiCompareUnitType compareId = TimerConfig->CompareUnitId;

  /* #10 Set the compare value. */
  rti->Compare[compareId].CompareValue = ExpirationTime;                                                                /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_HAL_RTI_MODULETYPE */ /* SBSW_OS_HAL_RTI_COMPAREUNITID */
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
  volatile CONSTP2VAR(Os_Hal_RtiModuleType, AUTOMATIC, OS_CONST) rti = (Os_Hal_RtiModuleType*)TimerConfig->BaseAddress; /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #10 Clear the corresponding interrupt flag bit. */
  rti->InterruptFlag = (uint32)(OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT << (uint8)(TimerConfig->CompareUnitId));           /* SBSW_OS_HAL_RTI_MODULETYPE */
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
))                                                                                                                      /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */
{
  /* #10 Trigger interrupt source of the given timer. */
  Os_Hal_INTC_TriggerPeripheralInterrupt(TimerConfig->InterruptSource, OS_HAL_ISR_INTC_ROOT);
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_FRT_RTI_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_Rti.h
 **********************************************************************************************************************/
