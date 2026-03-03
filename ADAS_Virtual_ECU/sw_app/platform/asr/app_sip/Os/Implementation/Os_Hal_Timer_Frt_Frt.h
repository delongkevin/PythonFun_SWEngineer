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
 *  \brief  HAL interface to work with the Spansion 32-bit Free-run Timer of the Traveo family.
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

#ifndef  OS_HAL_TIMER_FRT_FRT_H
# define OS_HAL_TIMER_FRT_FRT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_Common.h"
# include "Os_Hal_Timer_Types.h"
# include "Os_Hal_Interrupt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Timer Data Register / Counter value (TCDT). */
# define OS_HAL_TIMER_FRT_TCDT_OFFSET     (0x0uL)

/*! Timer State Control Register (TCCS). */
# define OS_HAL_TIMER_FRT_TCCS_OFFSET     (0x4uL)
/*! Timer clear bit (SCLR). */
# define OS_HAL_TIMER_FRT_TCCS_SCLR       (1uL << 4)
/*! Timer counter mode bit (MODE). */
# define OS_HAL_TIMER_FRT_TCCS_MODE       (1uL << 5)
/*! Timer disable bit (STOP). */
# define OS_HAL_TIMER_FRT_TCCS_STOP       (1uL << 6)
/*! Compare clear buffer enable bit (BFE). */
# define OS_HAL_TIMER_FRT_TCCS_BFE        (1uL << 7)
/*! Compare clear interrupt request enable bit (ICRE). */
# define OS_HAL_TIMER_FRT_TCCS_ICRE       (1uL << 8)
/*! Compare clear interrupt flag bit (ICLR). */
# define OS_HAL_TIMER_FRT_TCCS_ICLR       (1uL << 9)

/*! Timer State Control Clear Register (TCCSC). */
# define OS_HAL_TIMER_FRT_TCCSC_OFFSET    (0xCuL)

/*! Timer State Control Set Register (TCCSS). */
# define OS_HAL_TIMER_FRT_TCCSS_OFFSET    (0x10uL)

/*! Output Compare Register (Channel 0) */
# define OS_HAL_TIMER_OUTCMP_OCCP0_OFFSET  (0x0uL)
/*! Output Compare Register (Channel 1) */
# define OS_HAL_TIMER_OUTCMP_OCCP1_OFFSET  (0x4uL)
/*! Compare Control Register */
# define OS_HAL_TIMER_OUTCMP_OCS_OFFSET    (0x8uL)
/*! Compare Control Clear Register */
# define OS_HAL_TIMER_OUTCMP_OCSC_OFFSET   (0xCuL)
/*! Compare Control Set Register */
# define OS_HAL_TIMER_OUTCMP_OCSS_OFFSET  (0x10uL)

/*! Compare operation enable bit (Channel 0) */
# define OS_HAL_TIMER_OUTCMP_OCS_CST0     (1uL << 0)
/*! Compare operation enable bit (Channel 1) */
# define OS_HAL_TIMER_OUTCMP_OCS_CST1     (1uL << 1)
/*! Compare buffer disable bit (Channel 0) */
# define OS_HAL_TIMER_OUTCMP_OCS_BUF0     (1uL << 2)
/*! Compare buffer disable bit (Channel 1) */
# define OS_HAL_TIMER_OUTCMP_OCS_BUF1     (1uL << 3)
/*! Compare match interrupt enable bit (Channel 0) */
# define OS_HAL_TIMER_OUTCMP_OCS_IOE0     (1uL << 4)
/*! Compare match interrupt enable bit (Channel 1) */
# define OS_HAL_TIMER_OUTCMP_OCS_IOE1     (1uL << 5)
/*! Compare match interrupt flag bit (Channel 0) */
# define OS_HAL_TIMER_OUTCMP_OCS_IOP0     (1uL << 6)
/*! Compare match interrupt flag bit (Channel 1) */
# define OS_HAL_TIMER_OUTCMP_OCS_IOP1     (1uL << 7)



/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! High resolution timer configuration information for Spansion timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  uint32 CounterRegisterAddress;  /*!< Counter register address. */
  uint32 CompareRegisterAddress;  /*!< Compare register address. */
  uint32 InterruptSource;         /*!< Interrupt source. */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Set up the counter to the up count mode. */
  /* #20 Start counter. */
  *(volatile uint32*)(TimerConfig->CounterRegisterAddress + OS_HAL_TIMER_FRT_TCCSC_OFFSET) =                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_FRTCONFIG_TRAVEO */
        OS_HAL_TIMER_FRT_TCCS_MODE | OS_HAL_TIMER_FRT_TCCS_STOP;

  /* #30 Enable the compare interrupt. */
  /* #40 Enable the compare operation. */
  *(volatile uint32*)(TimerConfig->CompareRegisterAddress + OS_HAL_TIMER_OUTCMP_OCSS_OFFSET) =                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_FRTCONFIG_TRAVEO */
        OS_HAL_TIMER_OUTCMP_OCS_IOE0 | OS_HAL_TIMER_OUTCMP_OCS_CST0;

  /* #50 Enable the interrupt source for the counter. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, OS_HAL_ISR_INTC_ROOT);
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
  /* #10 Return configured counter register value. */
  return *(volatile uint32*)(TimerConfig->CounterRegisterAddress);                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  /* #10 Return configured compare register value. */
  return *(volatile uint32*)(TimerConfig->CompareRegisterAddress);                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  /* #10 Set configured compare register to given value. */
  *(volatile uint32*)(TimerConfig->CompareRegisterAddress) = (uint32)ExpirationTime;                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_FRTCONFIG_TRAVEO */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtAcknowledge()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtAcknowledge,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Acknowledge interrupt at the configured timer. */
  *(volatile uint32*)(TimerConfig->CompareRegisterAddress + OS_HAL_TIMER_OUTCMP_OCSC_OFFSET) =                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_FRTCONFIG_TRAVEO */
        OS_HAL_TIMER_OUTCMP_OCS_IOP0;

  /* #20 Acknowledge interrupt at interrupt controller. */
  Os_Hal_INTC_ClearPending(TimerConfig->InterruptSource,0, OS_HAL_ISR_INTC_ROOT);
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

#endif /* OS_HAL_TIMER_FRT_FRT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_Frt.h
 *********************************************************************************************************************/
