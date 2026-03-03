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
 *  \brief    HAL interface to work with the v8R Generic Timer module as a free running timer.
 *  \detail   Using either the EL1 physical timer or the virtual timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_FRT_V8RGENERIC_H)
# define OS_HAL_TIMER_FRT_V8RGENERIC_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_TimerInt.h"
# include "Os_Hal_Interrupt.h"
# include "Os_Hal_Timer_Frt_V8RGeneric_Physical.h"
# include "Os_Hal_Timer_Frt_V8RGeneric_Virtual.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerGetCntFrq()
 **********************************************************************************************************************/
/*! \brief        Get generic timer counter frequency register (CNTFRQ)
 *  \details      Read from coprocessor register.
 *  \return       Counter frequency.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerGetCntFrq()    Os_Hal_ReadFromCoprocessor(15, 0, 14, 0, 0)

/***********************************************************************************************************************
 *  Os_Hal_TimerSetCntFrq()
 **********************************************************************************************************************/
/*! \brief        Set generic timer counter frequency register (CNTFRQ)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerSetCntFrq(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 14, 0, 0)

/***********************************************************************************************************************
 *  Os_Hal_TimerGetCntKctl()
 **********************************************************************************************************************/
/*! \brief        Get counter timer kernel control register  (CNTKCTL)
 *  \details      Read from coprocessor register.
 *  \return       Control value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerGetCntKctl()    Os_Hal_ReadFromCoprocessor(15, 0, 14, 1, 0)

/***********************************************************************************************************************
 *  Os_Hal_TimerSetCntKctl()
 **********************************************************************************************************************/
/*! \brief        Set counter timer kernel control register  (CNTKCTL)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerSetCntKctl(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 14, 1, 0)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Function pointer data type for initializing FRT timer. */
typedef P2FUNC(void, OS_CODE, Os_Hal_TimerFrtInitType)(void);

/*! Function pointer data type for getting counter value. */
typedef P2FUNC(Os_Hal_TimerFrtTickType, OS_CODE, Os_Hal_TimerFrtGetCounterValueType)(void);

/*! Function pointer data type for getting compare value. */
typedef P2FUNC(Os_Hal_TimerFrtTickType, OS_CODE, Os_Hal_TimerFrtGetCompareValueType)(void);

/*! Function pointer data type for setting compare value. */
typedef P2FUNC(void, OS_CODE, Os_Hal_TimerFrtSetCompareValueType)(Os_Hal_TimerFrtTickType ExpirationTime);

/*! High resolution timer configuration information for Arm-v8R Generic timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  Os_Hal_TimerFrtInitType TimerFrtInit;
  Os_Hal_TimerFrtGetCounterValueType TimerFrtGetCounterValue;
  Os_Hal_TimerFrtSetCompareValueType TimerFrtSetCompareValue;
  Os_Hal_TimerFrtGetCompareValueType TimerFrtGetCompareValue;
  uint32 InterruptSource;  /*!< Interrupt source. */
  uint32 InterruptLevel;  /*!< Interrupt level. */
};

/*! Generic Timer Register Layout. */
/* Module is accessed using the system register interface */
typedef struct
{
  uint32 CntFrq;                           /* Counter-timer Frequency register.*/
  uint64 CntPct;                           /* Counter-timer Physical count register. */
  uint32 CntKctl;                          /* Counter-timer Kernel control register.*/
  uint32 Cntp_Tval;                        /* Counter-timer Physical timervalue register.*/
  uint32 Cntp_Ctl;                         /* Counter-timer Physical control register.*/
  uint32 Cntv_Tval;                        /* Counter-timer Virtual timervalue register.*/
  uint32 Cntv_Ctl;                         /* Counter-timer Virtual control register.*/
  uint64 Cntvct;                           /* Counter-timer Virtual count register.*/
  uint64 Cntp_Cval;                        /* Counter-timer Physical compareValue register.*/
  uint64 Cntv_Cval;                        /* Counter-timer virtual compareValue register.*/
  uint64 CntVoff;                          /* Counter-timer virtual offset register.*/
} Os_Hal_GenericTimerModuleType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtInit_Physical()
 **********************************************************************************************************************/
/*! \brief          Initialize the physical free running timer.
 *  \details        The generic free running timer uses this function during FRT initialization to initialize
 *                  the physical timer.
 *  \param[in]      -
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtInit_Physical,
(
  void
));

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtInit_Virtual()
 **********************************************************************************************************************/
/*! \brief          Initialize the virtual free running timer.
 *  \details        The generic free running timer uses this function during FRT initialization to initialize
 *                  the virtual timer.
 *  \param[in]      -
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtInit_Virtual,
(
  void
));

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue_Physical()
 **********************************************************************************************************************/
/*! \brief          Return the current counter register value of the physical free running timer.
 *  \details        The generic free running timer uses this function to read the counter value of the physical timer.
 *  \param[in]      -
 *  \return         Current counter register value.
 *  \context        OS_INTERNAL|ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue_Physical,
(
  void
));

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue_Virtual()
 **********************************************************************************************************************/
/*! \brief          Return the current counter register value of the virtual free running timer.
 *  \details        The generic free running timer uses this function to read the counter value of the virtual timer.
 *  \param[in]      -
 *  \return         Current counter register value.
 *  \context        OS_INTERNAL|ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue_Virtual,
(
  void
));

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue_Physical()
 **********************************************************************************************************************/
/*! \brief          Set the compare value of the physical free running timer.
 *  \details        The generic free running timer uses this function to set the compare value of the physical timer.
 *  \param[in]      ExpirationTime  The new compare value.
 *  \context        ISR2|OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtSetCompareValue_Physical,
(
  Os_Hal_TimerFrtTickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue_Virtual()
 **********************************************************************************************************************/
/*! \brief          Set the compare value of the virtual free running timer.
 *  \details        The generic free running timer uses this function to set the compare value of the virtual timer.
 *  \param[in]      ExpirationTime  The new compare value.
 *  \context        ISR2|OS_INTERNAL
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtSetCompareValue_Virtual,
(
  Os_Hal_TimerFrtTickType ExpirationTime
));


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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Call the corresponding callback. */
  TimerConfig->TimerFrtInit();                                                                                          /* SBSW_OS_HAL_FC_POINTER2FUCNTION */

  /* #20 Enable counter interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, TimerConfig->InterruptLevel,  OS_HAL_ISR_INTC_ROOT);
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Perform dsb and isb instructions to get actual value of counter register. */
  Os_Hal_DataSyncBarrier();
  Os_Hal_InstructionSyncBarrier();

  /* #20 Return free running counter value from the corresponding callback. */
  return TimerConfig->TimerFrtGetCounterValue();                                                                        /* SBSW_OS_HAL_FC_POINTER2FUCNTION */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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
  /* #10 Perform dsb and isb instructions to get actual value of counter register. */
  Os_Hal_DataSyncBarrier();
  Os_Hal_InstructionSyncBarrier();

  /* #20 Return free running counter value from the corresponding callback. */
  return TimerConfig->TimerFrtGetCompareValue();                                                                        /* SBSW_OS_HAL_FC_POINTER2FUCNTION */
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Set the compare value. */
  TimerConfig->TimerFrtSetCompareValue(ExpirationTime);                                                                 /* SBSW_OS_HAL_FC_POINTER2FUCNTION */
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
 /* #10 Clear the corresponding interrupt flag. */
  Os_Hal_INTC_ClearPending(TimerConfig->InterruptSource, 0, OS_HAL_ISR_INTC_ROOT);
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

#endif /* OS_HAL_TIMER_FRT_V8RGENERIC_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_V8RGeneric.h
 **********************************************************************************************************************/
