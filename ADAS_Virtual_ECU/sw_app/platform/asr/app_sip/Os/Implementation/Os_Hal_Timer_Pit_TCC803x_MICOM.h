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
 *  \file  Os_Hal_Timer_Pit_TCC803x_MICOM.h
 *  \brief  HAL interface to work with the TCC803x Timer module as a periodic interrupt timer.
 *  \details
 *  Internal comment removed.
 *
 *
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_TCC803X_MICOM_H
# define OS_HAL_TIMER_PIT_TCC803X_MICOM_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os HAL dependencies */
# include "Os_Hal_Timer_TCC803x_MICOMInt.h"
# include "Os_Hal_TimerInt.h"
# include "Os_Hal_InterruptInt.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Timer TCC803x MICOM end of main count interrupt mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_PITINTPEND    (0x00000400uL)

/*! Timer TCC803x MICOM interrupt main count end enable mask. */
# define OS_HAL_TIMER_TCC803X_MICOM_CNTIRQEN     (0x00040000uL)

/*! Timer TCC803x MICOM PIT max count value. */
# define OS_HAL_TIMER_TCC803X_MICOM_PITMAXCNT    (0xFFFFFFFFuL)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Periodic interrupt timer configuration information for TCC803x MICOM timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer reload value. */
  uint32 ReloadValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
  /*! The timer interrupt level. */
  uint32 InterruptLevel;
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  Os_Hal_TimerTCC803xMICOMRefType TimerRef = (Os_Hal_TimerTCC803xMICOMRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Stop the timer. */
  TimerRef->TimerOPENCFG   &= OS_HAL_TIMER_TCC803X_MICOM_STOPMSK;                                                       /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Configure operation mode. */
  TimerRef->TimerOPENCFG   &= OS_HAL_TIMER_TCC803X_MICOM_OPMODE;                                                        /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #30 Reset pre-scale counter load value. */
  TimerRef->TimerOPENCFG   &= OS_HAL_TIMER_TCC803X_MICOM_PRESCALEMSK;                                                   /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #40 Configure pre-scale counter load value. */
  TimerRef->TimerOPENCFG   |= OS_HAL_TIMER_TCC803X_MICOM_PRESCALEVAL;                                                   /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #50 Configure main counter load value. */
  TimerRef->TimerMAINCNTLVD = (OS_HAL_TIMER_TCC803X_MICOM_PITMAXCNT - TimerConfig->ReloadValue);                        /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #60 Configure interrupt control register. */
  TimerRef->TimerIRQCTRL   |= OS_HAL_TIMER_TCC803X_MICOM_IRQCLR;                                                        /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #70 Enable main count end interrupt. */
  TimerRef->TimerIRQCTRL   |= OS_HAL_TIMER_TCC803X_MICOM_CNTIRQEN;                                                      /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #80 Enable interrupt source. */
  Os_Hal_INTC_EnableSource((Os_Hal_IntSourceType)TimerConfig->InterruptSource, (Os_Hal_IntLevelType)TimerConfig->InterruptLevel, (Os_Hal_IntControllerType)0); /* PRQA S 4332 */ /* MD_Os_Hal_Rule10.5_4332 */

  /* #90 Start the timer. */
  TimerRef->TimerOPENCFG |= OS_HAL_TIMER_TCC803X_MICOM_STARTMSK;                                                        /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  /* #10 Clear the interrupt flag. */
  ((Os_Hal_TimerTCC803xMICOMRefType)TimerConfig->TimerBaseAddr)->TimerIRQCTRL |= OS_HAL_TIMER_TCC803X_MICOM_INTCLRVAL;  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  return (((Os_Hal_TimerTCC803xMICOMRefType)TimerConfig->TimerBaseAddr)->TimerIRQCTRL & OS_HAL_TIMER_TCC803X_MICOM_PITINTPEND);   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_TCC803X_MICOM_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_TCC803x_MICOM.h
 *********************************************************************************************************************/
