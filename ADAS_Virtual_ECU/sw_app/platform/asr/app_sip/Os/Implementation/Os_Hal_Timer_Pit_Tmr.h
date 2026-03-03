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
 *  \file  Os_Hal_Timer_Pit_Tmr.h
 *  \brief  HAL interface to work with the NVIDIA TMR module as a periodic interval timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_TRM_H
# define OS_HAL_TIMER_PIT_TRM_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_InterruptController_AVIC.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! TMR Control Register Enable bit. */
# define OS_HAL_TIMER_TMRCR_EN                 (31uL)
/*! TMR Control Register Periodic bit. */
# define OS_HAL_TIMER_TMRCR_PER                (30uL)
/*! TMR Clock Source Selection Register value (usecCnt[29:0]). */
# define OS_HAL_TIMER_TMRCSSR_USECCNT_29_0     (0uL)
/*! TMR Status Register bit. */
# define OS_HAL_TIMER_TMRSR_INT_CLR            (30uL)
/*! TMR Counter Mask value. */
# define OS_HAL_TIMER_TMR_COUNTER_MSK          0x0FFFFFFFuL


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! TMR Module base address macro. */
# define OS_HAL_TIMER_TMR_MODULE(x)           (volatile uint32*)(OS_HAL_TIMER_TKE_BASE + 0x10000uL + (x * 0x10000uL))

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Programmable interval timer configuration information for TMR timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  uint32 ChannelId;                           /*!< Timer channel id. */
  uint32 ReloadValue;                         /*!< Reload value. */
  uint32 InterruptSource;                     /*!< Interrupt source. */
};

/*! TMR module Layout. */
typedef struct
{
  uint32 Tmrcr;                     /*!< Timer configuration register. */
  uint32 Tmrsr;                     /*!< Timer status register. */
  uint32 Tmrcssr;                   /*!< Timer clock source selection register. */
  uint32 Tmrscr;                    /*!< Timer security configuration register. */
} Os_Hal_TmrModuleType;

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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile CONSTP2VAR(Os_Hal_TmrModuleType, AUTOMATIC, OS_CONST) tmr =
      (Os_Hal_TmrModuleType*)(OS_HAL_TIMER_TMR_MODULE(TimerConfig->ChannelId));                                         /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  const uint32 reloadValue = TimerConfig->ReloadValue - 1;

  /* #10 Stop the counter before starting the initialization process. */
  tmr->Tmrcr &= ~(1uL << OS_HAL_TIMER_TMRCR_EN);

  /* #20 Set clock source to 1MHz. */
  tmr->Tmrcssr = OS_HAL_TIMER_TMRCSSR_USECCNT_29_0;

  /* #30 Set periodic behavior and the reload value. */
  tmr->Tmrcr |= ((1uL << OS_HAL_TIMER_TMRCR_PER) | (reloadValue & OS_HAL_TIMER_TMR_COUNTER_MSK));

  /* #40 Enable the interrupt source. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0,  OS_HAL_ISR_INTC_ROOT);

  /* #50 Start the timer. */
  tmr->Tmrcr |= (1uL << OS_HAL_TIMER_TMRCR_EN);

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
  volatile CONSTP2VAR(Os_Hal_TmrModuleType, AUTOMATIC, OS_CONST) tmr =
      (Os_Hal_TmrModuleType*)(OS_HAL_TIMER_TMR_MODULE(TimerConfig->ChannelId));                                         /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #10 Set the clear pending interrupt bit. */
  tmr->Tmrsr |= (1uL << OS_HAL_TIMER_TMRSR_INT_CLR);
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
  return ((OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicRawIntr &
      (1uL << TimerConfig->InterruptSource)) != 0);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_TMR_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_Tmr.h
 **********************************************************************************************************************/
