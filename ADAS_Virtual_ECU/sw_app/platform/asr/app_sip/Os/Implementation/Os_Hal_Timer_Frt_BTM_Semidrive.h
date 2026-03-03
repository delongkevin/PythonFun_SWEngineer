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
 *  \brief  HAL interface to work with the BTM Free-run Timer of the Semidrive E3 family.
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

#ifndef  OS_HAL_TIMER_FRT_BTM_SEMIDRIVE_H
# define OS_HAL_TIMER_FRT_BTM_SEMIDRIVE_H

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
/*! Initial reset value of G0 timer configure register. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_CFG_INIT_VALUE           (0x1010000uL)

/*! Initial reset value of G0 timer enbale control register. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_ENABLE_INIT_VALUE        (0x0uL)

/*! Initial compare value of G0 timer. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_CMP_INIT_VALUE           (0x0uL)

/*! Initial overflow value of G0 timer. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_OVF_INIT_VALUE           (0xFFFFFFFFuL)

/*! Enable bit of G0 timer. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_ENABLE                   (1uL << 0)

/*! Continuous mode bit of G0 timer configure register. */
#define OS_HAL_TIMER_FRT_BTM_CNT_G0_CFG_CNT_MODE             (1uL << 0)

/*! Counter interval value last bit of G0 timer configure register */
#define OS_HAL_TIMER_PIT_BTM_CNT_G0_CFG_SI_VAL_LAST          (1uL << 24)

/*! Compare event bit of interrupt status register. */
#define OS_HAL_TIMER_FRT_BTM_INT_STAT_CE_G0                  (1uL << 0)

/*! Interrupt enable bit for G0 compare event inside function interrupt singal/status enable register. */
#define OS_HAL_TIMER_FRT_BTM_INT_EN                          (1uL << 0)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! High resolution timer configuration information BTM timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer compare value. */
  uint32 CompareValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
};

 /*! Memory mapped BTM timer registers corresponding to the memory layout */
struct Os_Hal_TimerBTMSemidriveType_Tag
{
  uint32 COM_CTRL;          /*! < +00h G0 and G1 timer common control register. (32 bit read/write). */
  uint32 CNT_G0_EN;         /*! < +04h G0 timer enbale control register. (32 bit read/write). */
  uint32 CNT_G0_CFG;        /*! < +08h G0 timer configure register. (32 bit read/write). */
  uint32 CNT_G0_OVF;        /*! < +0Ch G0 timer terminal value. (32 bit read/write).*/
  uint32 CNT_G0_CMP;        /*! < +10h G0 timer compare value. (32 bit read/write). */
  uint32 CNT_G0;            /*! < +14h G0 counter value. (32 bit read). */
  uint32 HOLD_G0;           /*! < +18h Counter hold register. (32 bit read). */
  uint32 DUMMY1[9];         /*! < +1Ch-3Ch Unused registers. */
  uint32 INT_STAT;          /*! < +40h Interrupt status register. (32 bit read/write). */
  uint32 INT_STAT_EN;       /*! < +44h Interrupt status enable register. (32 bit read/write). */
  uint32 INT_SIG_EN;        /*! < +48h Interrupt signal enable register. (32 bit read/write). */
};

/*! Forward declaration of platform specific Semidrive BTM timer type. */
typedef struct Os_Hal_TimerBTMSemidriveType_Tag Os_Hal_TimerBTMSemidriveType;

/*! Pointer to platform specific Semidrive BTM timer type. */
typedef CONSTP2VAR(volatile Os_Hal_TimerBTMSemidriveType, AUTOMATIC, OS_CONST) Os_Hal_TimerBTMSemidriveRefType;


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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  Os_Hal_TimerBTMSemidriveRefType TimerRef = (Os_Hal_TimerBTMSemidriveRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Initialize the to be uesd registers with reset value, counter G0 will be disabled for counting. */
  TimerRef->CNT_G0_EN = OS_HAL_TIMER_FRT_BTM_CNT_G0_ENABLE_INIT_VALUE;                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  TimerRef->CNT_G0_CFG = OS_HAL_TIMER_FRT_BTM_CNT_G0_CFG_INIT_VALUE;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Initialize overflow value to 0xFFFFFFFF. */
  TimerRef->CNT_G0_OVF = OS_HAL_TIMER_FRT_BTM_CNT_G0_OVF_INIT_VALUE;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #30 Initialize compare value to 0. */
  TimerRef->CNT_G0_CMP = OS_HAL_TIMER_FRT_BTM_CNT_G0_CMP_INIT_VALUE;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #40 Configure the counter to continuous mode. */
  TimerRef->CNT_G0_CFG |= OS_HAL_TIMER_FRT_BTM_CNT_G0_CFG_CNT_MODE;                                                     /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #50 Configure the counter interval value to 0. */
  TimerRef->CNT_G0_CFG &= ~(OS_HAL_TIMER_PIT_BTM_CNT_G0_CFG_SI_VAL_LAST);                                               /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #60 Enable only the compare interrupt as all share the same interrupt source. */
  TimerRef->INT_STAT_EN = OS_HAL_TIMER_FRT_BTM_INT_EN;                                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  TimerRef->INT_SIG_EN  = OS_HAL_TIMER_FRT_BTM_INT_EN;                                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #70 Enable the interrupt source for the counter. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, (Os_Hal_IntControllerType)Os_Hal_CoreGetId());              /* PRQA S 4342 */ /* MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType */

  /* #80 Start the timer. */
  TimerRef->CNT_G0_EN |= OS_HAL_TIMER_FRT_BTM_CNT_G0_ENABLE;                                                            /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

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
  return ((Os_Hal_TimerBTMSemidriveRefType)TimerConfig->TimerBaseAddr)->CNT_G0;                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  return ((Os_Hal_TimerBTMSemidriveRefType)TimerConfig->TimerBaseAddr)->CNT_G0_CMP;                                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
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

  Os_Hal_TimerBTMSemidriveRefType TimerRef = (Os_Hal_TimerBTMSemidriveRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Set configured compare register to given value. */
  TimerRef->CNT_G0_CMP = (uint32)ExpirationTime;                                                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Execute data sync barrier to ensure compare value is actually stored into register before returning. */
  Os_Hal_DataSyncBarrier();


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
  ((Os_Hal_TimerBTMSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STAT |= OS_HAL_TIMER_FRT_BTM_INT_STAT_CE_G0;       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Acknowledge interrupt at VIC due to software triggered interrupts when ExpirationTime is already reached. */
  Os_Hal_INTC_ClearPending(TimerConfig->InterruptSource,0, (Os_Hal_IntControllerType)Os_Hal_CoreGetId());               /* PRQA S 4342 */ /* MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType */
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
  Os_Hal_INTC_TriggerPeripheralInterrupt(TimerConfig->InterruptSource, (Os_Hal_IntControllerType)Os_Hal_CoreGetId());   /* PRQA S 4342 */ /* MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_FRT_BTM_SEMIDRIVE_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_BTM_Semidrive.h
 *********************************************************************************************************************/
