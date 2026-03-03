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
 *  \file  Os_Hal_Timer_Pit_Sicmpt.h
 *  \brief  HAL interface to work with the Safe Island Compare Timer module as a periodic interval timer.
 *  \detail Only SICMPT Module 0, Compare 0 is available, since all compare units are using the same interrupt source.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_PIT_SICMPT_H)
# define OS_HAL_TIMER_PIT_SICMPT_H
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

/*! Compare Control Register value: CNTCLEN=1, CMPDBEN=0, CMPEN=1. */
#define OS_HAL_TIMER_SICMPT_PIT_CMPCR_VALUE         0x5UL

/*! Timer Run Register value: TBTPSEN=1, DIVRUN=1, TBTRUN=1 */
#define OS_HAL_TIMER_SICMPT_TBTRUN_VALUE            0x13UL

/*! Software Reset Register value: SWRST=1 */
#define OS_HAL_TIMER_SICMPT_SWRST_VALUE             0x1UL

/*! Compare 0 Interrupt Bit. */
#define OS_HAL_TIMER_SICMPT_CMP0_INT_BIT            0x1UL

/*! Frequency Divider = 15 (TBTCR.DIVSEL = 14). */
#define OS_HAL_TIMER_SICMPT_PIT_TBTCR_DIV_15        0xE0UL

/*! Interrupt Clear Value. */
#define OS_HAL_TIMER_SICMPT_PIT_INTCLR_VALUE        0x1UL

/*! SICMPT0 Timer Run Register. */
#define OS_HAL_TIMER_SICMPT_PIT_TBTRUN     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE))

/*! SICMPT0 Timer Control Register. */
#define OS_HAL_TIMER_SICMPT_PIT_TBTCR      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x4UL))

/*! SICMPT0 Timer Counter Register. */
#define OS_HAL_TIMER_SICMPT_PIT_TBTCNT     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x8UL))

/*! SICMPT0 Timer Software Reset Register. */
#define OS_HAL_TIMER_SICMPT_PIT_SWRST      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0xCUL))

/*! SICMPT0 Timer Interrupt Status Register. */
#define OS_HAL_TIMER_SICMPT_PIT_INTSTATUS  (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x10UL))

/*! SICMPT0 Timer Interrupt Clear Register. */
#define OS_HAL_TIMER_SICMPT_PIT_INTCLR     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x14UL))

/*! SICMPT0 Timer Clock Select Register. */
#define OS_HAL_TIMER_SICMPT_PIT_CLKSEL     (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x18UL))

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! SICMPT0 Timer Compare Control Register. */
#define OS_HAL_TIMER_SICMPT_PIT_CMPCR      (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x800UL))

/*! SICMPT0 Timer Compare Value Register. */
#define OS_HAL_TIMER_SICMPT_PIT_CMP        (*(volatile uint32*)(OS_HAL_TIMER_SICMPT0_BASE + 0x808UL))

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Pit timer configuration information for SICMPT timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  uint32 CompareValue;
  uint32 InterruptSource;
  uint32 InterruptLevel;
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Trigger a timer software reset.  */
  OS_HAL_TIMER_SICMPT_PIT_SWRST = OS_HAL_TIMER_SICMPT_SWRST_VALUE;                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */

  /* #20 Set compare value. */
  OS_HAL_TIMER_SICMPT_PIT_CMP = TimerConfig->CompareValue;                                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */

  /* #30 Enable counter clear operation and disable double buffer, enables compare match detection.   */
  OS_HAL_TIMER_SICMPT_PIT_CMPCR = OS_HAL_TIMER_SICMPT_PIT_CMPCR_VALUE;                                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */

  /* #40 Enable SICMPT counter interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, TimerConfig->InterruptLevel,  OS_HAL_ISR_INTC_ROOT);

  /* #50 Set frequency divider to 15. */
  OS_HAL_TIMER_SICMPT_PIT_TBTCR = OS_HAL_TIMER_SICMPT_PIT_TBTCR_DIV_15;                                                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */

  /* #60 Enable preset of counter register and start the counter. */
  OS_HAL_TIMER_SICMPT_PIT_TBTRUN = OS_HAL_TIMER_SICMPT_TBTRUN_VALUE;                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */


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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /*#10 Clear the interrupt flag. */
  OS_HAL_TIMER_SICMPT_PIT_INTCLR |= OS_HAL_TIMER_SICMPT_PIT_INTCLR_VALUE;                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICMPT0 */
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
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Read the interrupt status flag. */
  return (OS_HAL_TIMER_SICMPT_PIT_INTSTATUS & OS_HAL_TIMER_SICMPT_CMP0_INT_BIT);                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */         
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_SICMPT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_Sicmpt.h
 **********************************************************************************************************************/
