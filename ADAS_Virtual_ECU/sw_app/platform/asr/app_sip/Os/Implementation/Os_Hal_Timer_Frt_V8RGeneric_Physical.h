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
 *  \detail   Using the EL1 physical timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_FRT_V8RGENERIC_PHYSICAL_H)
# define OS_HAL_TIMER_FRT_V8RGENERIC_PHYSICAL_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#define OS_HAL_TIMER_GENERICTIMER_FRT_ENABLE_BIT          0x1UL << 0uL

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerSetCntPctl()
 **********************************************************************************************************************/
/*! \brief        Set Counter Timer Physical Timer control register  (CNTP_CTL)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerSetCntPctl(Value)     Os_Hal_WriteToCoprocessor(Value, 15, 0, 14, 2, 1)

/***********************************************************************************************************************
 *  Os_Hal_TimerGetCntPct()
 **********************************************************************************************************************/
/*! \brief        Get Counter Timer Physical count register  (CNTPCT)
 *  \details      Read from coprocessor register.
 *  \return       Count value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerGetCntPct()    Os_Hal_ReadFromCoprocessor64(15, 0, 14)

/***********************************************************************************************************************
 *  Os_Hal_TimerSetCntPct()
 **********************************************************************************************************************/
/*! \brief        Set Counter Timer Physical count register  (CNTPCT)
 *  \details      Write to coprocessor register.
 *  \return       Count value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerSetCntPct(Value)    Os_Hal_WriteToCoprocessor64(Value, 15, 0, 14)

/***********************************************************************************************************************
 *  Os_Hal_TimerGetCnpCval()
 **********************************************************************************************************************/
/*! \brief        Get Counter Timer Physical compare register  (CNTP_CVAL)
 *  \details      Read from coprocessor register.
 *  \return       Compare value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerGetCnpCval()    Os_Hal_ReadFromCoprocessor64(15, 2, 14)

/***********************************************************************************************************************
 *  Os_Hal_TimerSetCntpCval()
 **********************************************************************************************************************/
/*! \brief        Set Counter Timer Physical Timer Compare value register (CNTP_CVAL)
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_TimerSetCntpCval(Value)     Os_Hal_WriteToCoprocessor64(Value, 15, 2, 14)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

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
 *  Os_Hal_TimerFrtInit_Physical()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtInit_Physical,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */
{
  /* #10 Reset the compare value to zero. */
  Os_Hal_TimerSetCntpCval((Os_Hal_TimerFrtTickType)0u);

  /* #20 Enable the EL1 physical timer and unmask the interrupt. */
  Os_Hal_TimerSetCntPctl(OS_HAL_TIMER_GENERICTIMER_FRT_ENABLE_BIT);
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue_Physical()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue_Physical,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */
{
  /* #10 Return free running counter value. */
  return (Os_Hal_TimerFrtTickType)Os_Hal_TimerGetCntPct();
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCompareValue_Physical()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCompareValue_Physical,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */
{
  /* #10 Return free running compare value. */
  return (Os_Hal_TimerFrtTickType)Os_Hal_TimerGetCnpCval();
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue_Physical()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtSetCompareValue_Physical,
(
  Os_Hal_TimerFrtTickType ExpirationTime
))                                                                                                                      /* COV_OS_HALPLATFORMTIMERFRTCALLBACK */
{
  /* #10 Set the compare value. */
  Os_Hal_TimerSetCntpCval(ExpirationTime);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_FRT_V8RGENERIC_PHYSICAL_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_V8RGeneric_Physical.h
 **********************************************************************************************************************/
