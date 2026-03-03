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
 *  \file  Os_Hal_Timer_Pit_TMU.h
 *  \brief  HAL interface to work with the TMU module as a periodic interval timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_PIT_TTC_H
# define OS_HAL_TIMER_PIT_TTC_H
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

/*! TMU_TCR.UNIE Timer Underflow interrupt enable */
#define OS_HAL_TIMER_TMU_OVERFLOW_INTERRUPT_ENABLE_BIT  (((uint16)1) << 5u)
/*! TMU_TCR.UNF Timer Underflow clear pending */
#define OS_HAL_TIMER_TMU_OVERFLOW_INTERRUPT_CLEAR_BIT   (((uint16)1) << 8u)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! TMU Channel number types. */
typedef enum
{
  OS_HAL_TMU_CHANNEL_0 = 0u,      /*! TMU Channel Nummber 0. */
  OS_HAL_TMU_CHANNEL_1 = 1u,      /*! TMU Channel Nummber 1. */
  OS_HAL_TMU_CHANNEL_2 = 2u,      /*! TMU Channel Nummber 2. */
  OS_HAL_TMU_CHANNEL_COUNT = 3u   /*! TMU Channel Number count. */
}Os_Hal_TmuChannelNumType;

/*! TMU Channel Layout. */
typedef struct
{
  uint32 Constant;           /*!< Channel Constant register. */
  uint32 Counter;            /*!< Channel Counter register. */
  uint16 Control;            /*!< Channel Control register. */
  uint16 Reserved;           /*!< Reserved. */
} Os_Hal_TmuChannelType;

/*! TMU module Layout. */
typedef struct
{
  uint8 Start;                                                 /*!< Timer Start register. */
  uint8 Reserved[3];                                           /*!< Reserved. */
  Os_Hal_TmuChannelType Channels[OS_HAL_TMU_CHANNEL_COUNT];   /*!< Timer Channels registers */
} Os_Hal_TmuModuleType;

/*! PIT Configuration for TMU timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  volatile Os_Hal_TmuModuleType * const Tmu;  /*!< TMU module base address. */
  uint32 ReloadValue;                         /*!< Reload value. */
  uint32 InterruptSource;                     /*!< Interrupt source. */
  Os_Hal_TmuChannelNumType ChannelIndex;      /*!< Channel offset. */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  volatile Os_Hal_TmuModuleType * const tmu = TimerConfig->Tmu;
  const Os_Hal_TmuChannelNumType channelIndex = TimerConfig->ChannelIndex;

  /* #10 Enable interrupt request. */
  tmu->Channels[channelIndex].Control |= OS_HAL_TIMER_TMU_OVERFLOW_INTERRUPT_ENABLE_BIT;                                /* SBSW_OS_HAL_TMU_MODULETYPE */ /* SBSW_OS_HAL_TMU_CHANNEL */

  /* #20 Set reload value. */
  tmu->Channels[channelIndex].Constant = TimerConfig->ReloadValue;                                                      /* SBSW_OS_HAL_TMU_MODULETYPE */ /* SBSW_OS_HAL_TMU_CHANNEL */

  /* #30 Set initial counter value. */
  tmu->Channels[channelIndex].Counter =  TimerConfig->ReloadValue;                                                      /* SBSW_OS_HAL_TMU_MODULETYPE */ /* SBSW_OS_HAL_TMU_CHANNEL */

  /* #40 Enable the timer. */
  tmu->Start |= (uint8) (1u << (uint8)channelIndex);                                                                    /* SBSW_OS_HAL_TMU_MODULETYPE */

  /* #50 Enable the interrupt in the interrupt controller. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, OS_HAL_ISR_INTC_ROOT);
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
  const Os_Hal_TmuChannelNumType channelIndex = TimerConfig->ChannelIndex;
  /*#10 Clear the underflow flag. */
  TimerConfig->Tmu->Channels[channelIndex].Control &= (~OS_HAL_TIMER_TMU_OVERFLOW_INTERRUPT_CLEAR_BIT);                 /* SBSW_OS_HAL_TMU_MODULETYPE */ /* SBSW_OS_HAL_TMU_CHANNEL */
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
  const Os_Hal_TmuChannelNumType channelIndex = TimerConfig->ChannelIndex;
  /* #10 Read the underflow flag. */
  return (uint32) TimerConfig->Tmu->Channels[channelIndex].Control & OS_HAL_TIMER_TMU_OVERFLOW_INTERRUPT_CLEAR_BIT;
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
