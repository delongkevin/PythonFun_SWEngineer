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
 *  \brief    HAL interface to work with the Safe Island Compare Timer (SICMPT) module as a free running timer.
 *  \detail   Only SICMPT Module 1, Compare 0 is available, since all compare units are using the same interrupt source.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_FRT_SICMPT_H)
# define OS_HAL_TIMER_FRT_SICMPT_H
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

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Compare Control Register value: CNTCLEN=0, CMPDBEN=0, CMPEN=1. */
#define OS_HAL_TIMER_SICMPT_FRT_CMPCR_VALUE         0x1UL

/*! Timer Run Register value: TBTPSEN=1, DIVRUN=1, TBTRUN=1 */
#define OS_HAL_TIMER_SICMPT_TBTRUN_VALUE            0x13UL

/*! Software Reset Register value: SWRST=1 */
#define OS_HAL_TIMER_SICMPT_SWRST_VALUE             0x1UL

/*! Interrupt Clear Value. */
#define OS_HAL_TIMER_SICMPT_FRT_INTCLR_VALUE            0x1UL

/*! Frequency Divider = 3 (TBTCR.DIVSEL = 2). */
#define OS_HAL_TIMER_SICMPT_FRT_TBTCR_DIV_3             0x20UL

/*! SICMPT1 Timer Run Register. */
#define OS_HAL_TIMER_SICMPT_FRT_TBTRUN     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE))

/*! SICMPT1 Timer Control Register. */
#define OS_HAL_TIMER_SICMPT_FRT_TBTCR      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x4UL))

/*! SICMPT1 Timer Counter Register. */
#define OS_HAL_TIMER_SICMPT_FRT_TBTCNT     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x8UL))

/*! SICMPT1 Timer Software Reset Register. */
#define OS_HAL_TIMER_SICMPT_FRT_SWRST      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0xCUL))

/*! SICMPT1 Timer Interrupt Status Register. */
#define OS_HAL_TIMER_SICMPT_FRT_INTSTATUS  (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x10UL))

/*! SICMPT1 Timer Interrupt Clear Register. */
#define OS_HAL_TIMER_SICMPT_FRT_INTCLR     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x14UL))

/*! SICMPT1 Timer Clock Select Register. */
#define OS_HAL_TIMER_SICMPT_FRT_CLKSEL     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x18UL))

/*! SICMPT1 Timer Compare Control Register. */
#define OS_HAL_TIMER_SICMPT_FRT_CMPCR      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x800UL))

/*! SICMPT1 Timer Compare Value Register. */
#define OS_HAL_TIMER_SICMPT_FRT_CMP        (*(volatile uint32*)(OS_HAL_TIMER_SICMPT1_BASE + 0x808UL))

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! High resolution timer configuration information for SICMPT timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  uint32 InterruptSource;                        /*!< Interrupt source. */
  uint32 InterruptLevel;                         /*!< Interrupt level. */
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
  /* #10 Trigger a timer software reset.  */
  OS_HAL_TIMER_SICMPT_FRT_SWRST = OS_HAL_TIMER_SICMPT_SWRST_VALUE;                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */

  /* #20 Disable counter clear operation and double buffer, enables compare match detection.   */
  OS_HAL_TIMER_SICMPT_FRT_CMPCR = OS_HAL_TIMER_SICMPT_FRT_CMPCR_VALUE;                                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */

  /* #30 Enable SICMPT counter interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, TimerConfig->InterruptLevel,  OS_HAL_ISR_INTC_ROOT);

  /* #40 Set frequency divider to 3. */
  OS_HAL_TIMER_SICMPT_FRT_TBTCR = OS_HAL_TIMER_SICMPT_FRT_TBTCR_DIV_3;                                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */

  /* #50 Enable preset of counter register and start the counter. */
  OS_HAL_TIMER_SICMPT_FRT_TBTRUN = OS_HAL_TIMER_SICMPT_TBTRUN_VALUE;                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Return free running counter value. */
  return OS_HAL_TIMER_SICMPT_FRT_TBTCNT;                                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */     
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Return free running counter value. */
  return OS_HAL_TIMER_SICMPT_FRT_CMP;                                                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */     
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
  OS_HAL_TIMER_SICMPT_FRT_CMP = ExpirationTime;                                                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Clear the corresponding interrupt flag bit. */
  OS_HAL_TIMER_SICMPT_FRT_INTCLR |= OS_HAL_TIMER_SICMPT_FRT_INTCLR_VALUE;                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT1 */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtTriggerIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
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

#endif /* OS_HAL_TIMER_FRT_SICMPT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_Sicmpt.h
 **********************************************************************************************************************/
