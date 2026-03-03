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
 *  \brief  HAL interface to work with the TMR Free-run Timer of the Semidrive G9 family.
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

#ifndef  OS_HAL_TIMER_FRT_TMR_SEMIDRIVE_H
# define OS_HAL_TIMER_FRT_TMR_SEMIDRIVE_H
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


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/*! Compare Enable bit (EN). */
# define OS_HAL_TIMER_TMR_FRT_CONFIG_EN       (1uL << 0)

/*! Single Mode enable bit (SINGLE_MODE). */
# define OS_HAL_TIMER_TMR_FRT_SINGLE_MODE     (1uL << 1)

/*! Software Update Bit (UPT). */
# define OS_HAL_TIMER_TMR_FRT_UPT_BIT         (1uL << 0)

/*! Local Counter Select (CNT_SEL). */
# define OS_HAL_TIMER_TMR_FRT_CNT_SEL         (1uL << 3)

/*! High resolution timer configuration information TMR timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer compare value. */
  uint32 CompareValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
};

 /*! Memory mapped TMR timer registers corresponding to the memory layout */
struct Os_Hal_TimerTMRSemidriveType_Tag
{
  uint32 INT_STA;           /*! < +00h Interrupt status register. (32 bit read/write). */
  uint32 INT_STA_EN;        /*! < +04h Interrupt status enable register. (32 bit read/write). */
  uint32 INT_SIG_EN;        /*! < +08h Interrupt signal enable register. (32 bit read/write). */
  uint32 DUMMY1[6];         /*! < +0Ch-20 Unused registers. */
  uint32 CNT_CONFIG;        /*! < +24h Timer counter configuration register. (32 bit read/write). */
  uint32 DUMMY2[2];         /*! < +28h-2C Unused registers. */
  uint32 CNT_LOCAL_A_OVF;   /*! < +30h Channel A overflow value register. (32 bit read/write). */
  uint32 DUMMY3[5];         /*! < +34h-44 Unused registers. */
  uint32 CNT_LOCAL_A;       /*! < +48h Channel A local counter register. (32 bit read/write). */
  uint32 DUMMY4[5];         /*! < +4Ch-5C Unused registers. */
  uint32 CMP_A_VAL_UPT;     /*! < +60h Update compare value register. (32 bit read/write). */
  uint32 CMP0_A_VAL;        /*! < +64h Channel A compare value 0 register. (32 bit read/write). */
  uint32 DUMMY5[20];        /*! < +68h-B4h Unused registers. */
  uint32 CNT_LOCAL_A_INIT;  /*! < +B8h Channel A initial value register. (32 bit read/write). */
  uint32 DUMMY6[21];        /*! < +BCh-10Ch Unused registers. */
  uint32 CMP_A_CONFIG;      /*! < +110h Channel A compare config register. (32 bit read/write). */
};

/*! Forward declaration of platform specific TCC803x MICOM timer type. */
typedef struct Os_Hal_TimerTMRSemidriveType_Tag Os_Hal_TimerTMRSemidriveType;

/*! Pointer to platform specific TCC803x MICOM timer type. */
typedef CONSTP2VAR(volatile Os_Hal_TimerTMRSemidriveType, AUTOMATIC, OS_CONST) Os_Hal_TimerTMRSemidriveRefType;


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
  Os_Hal_TimerTMRSemidriveRefType TimerRef = (Os_Hal_TimerTMRSemidriveRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  
  /* #10 Set Initial value of counter. */
  TimerRef->CNT_LOCAL_A_INIT = (uint32)0x0;

  /* #20 Enable the compare interrupt. */
  TimerRef->INT_STA_EN |= 1uL << 4;
  TimerRef->INT_SIG_EN |= 1uL << 4;

  /* #30 Enable the compare funtion in the timer. */
  TimerRef->CMP_A_CONFIG = OS_HAL_TIMER_TMR_FRT_CONFIG_EN | OS_HAL_TIMER_TMR_FRT_CNT_SEL;

  /* #40 Start the timer. */
  TimerRef->CNT_CONFIG = 1uL << 2;

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
  return ((Os_Hal_TimerTMRSemidriveRefType)TimerConfig->TimerBaseAddr)->CNT_LOCAL_A;                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  return ((Os_Hal_TimerTMRSemidriveRefType)TimerConfig->TimerBaseAddr)->CMP0_A_VAL;                                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
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

  Os_Hal_TimerTMRSemidriveRefType TimerRef = (Os_Hal_TimerTMRSemidriveRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  
  /* #10 Disable the compare function. */
  TimerRef->CMP_A_CONFIG &= ~(OS_HAL_TIMER_TMR_FRT_CONFIG_EN);
  
  /* #20 Set configured compare register to given value. */
  TimerRef->CMP0_A_VAL = (uint32)ExpirationTime;                                                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  TimerRef->CMP_A_VAL_UPT = OS_HAL_TIMER_TMR_FRT_UPT_BIT;                                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #30 Re-enable the compare function. */
  TimerRef->CMP_A_CONFIG |= OS_HAL_TIMER_TMR_FRT_CONFIG_EN;
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
  ((Os_Hal_TimerTMRSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STA = 1uL << 4;                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

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

#endif /* OS_HAL_TIMER_FRT_TMR_SEMIDRIVE_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_TMR_Semidrive.h
 *********************************************************************************************************************/
