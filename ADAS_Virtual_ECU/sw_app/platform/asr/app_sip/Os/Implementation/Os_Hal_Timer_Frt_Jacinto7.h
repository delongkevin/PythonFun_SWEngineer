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
 *  \brief  HAL interface to work with the Jacinto7 timer module as a free running timer.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_FRT_JACINTO7_H)
# define OS_HAL_TIMER_FRT_JACINTO7_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os HAL dependencies */
# include "Os_Hal_TimerInt.h"
# include "Os_Hal_InterruptInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Timer Jacinto7 software reset bit mask */
#define OS_HAL_TIMER_JACINTO7_SOFTWARERESETMASK (0x00000001uL)

/*! Timer Jacinto7 smart idle mode */
#define OS_HAL_TIMER_JACINTO7_SMARTIDLEMODE     (0x00000008uL)

/*! Timer Jacinto7 wake-up generation for compare mode bit mask */
#define OS_HAL_TIMER_JACINTO7_COMPAREWAKEUPMASK (0x00000004uL)

/*! Timer Jacinto7 posted mode selection */
#define OS_HAL_TIMER_JACINTO7_POSTEDMODE        (0x00000004uL)

/*! Timer Jacinto7 autoreload mode mask bit mask */
#define OS_HAL_TIMER_JACINTO7_AUTORELOADMASK    (0x00000002uL)

/*! Timer Jacinto7 match interrupt bit mask */
#define OS_HAL_TIMER_JACINTO7_MATCHINTMASK      (0x00000001uL)

/*! Timer Jacinto7 compare mode enable bit mask */
#define OS_HAL_TIMER_JACINTO7_COMPAREENABLEMASK (0x00000040uL)

/*! Timer Jacinto7 start bit mask */
#define OS_HAL_TIMER_JACINTO7_STARTMASK         (0x00000001uL)

/*! Timer Jacinto7 TMAR write pending bit mask */
#define OS_HAL_TIMER_JACINTO7_TMARWRITEPENDING  (0x00000010uL)

/*! Timer Jacinto7 TCLR write pending bit mask */
#define OS_HAL_TIMER_JACINTO7_TCLRWRITEPENDING  (0x00000001uL)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! High resolution timer configuration information for RTI timer module. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer compare value. */
  uint32 CompareValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
  /*! The timer interrupt level. */
  uint32 InterruptLevel;
};


 /*! Memory mapped Timer Jacinto7 registers corresponding to the memory layout */
struct Os_Hal_TimerJacinto7Type_Tag
{
  uint32 TimerTIDR;         /*!< +00h Revision register. (32 bit read) */
  uint32 reserved1;         /*!< +04h unused */
  uint32 reserved2;         /*!< +08h unused */
  uint32 reserved3;         /*!< +0Ch unused */
  uint32 TimerTIOCPCFG;     /*!< +10h CBASS0 configuration register. (32 bit read/write) */
  uint32 reserved4;         /*!< +14h unused */
  uint32 reserved5;         /*!< +18h unused */
  uint32 reserved6;         /*!< +1Ch unused */
  uint32 TimerIRQEOI;       /*!< +20h End-Of-Interrupt register. (32 bit read/write) */
  uint32 TimerIRQSTATUSRAW; /*!< +24h Timer raw status register. (32 bit read/write) */
  uint32 TimerIRQSTATUS;    /*!< +28h Timer status register. (32 bit read/write) */
  uint32 TimerIRQSTATUSSET; /*!< +2Ch Interrupt enable register. (32 bit read/write) */
  uint32 TimerIRQSTATUSCLR; /*!< +30h Interrupt disable register. (32 bit read/write) */
  uint32 TimerIRQWAKEEN;    /*!< +34h Wake-up enable register. (32 bit read/write) */
  uint32 TimerTCLR;         /*!< +38h Timer control register. (32 bit read/write) */
  uint32 TimerTCRR;         /*!< +3Ch Timer counter register. (32 bit read/write) */
  uint32 TimerTLDR;         /*!< +40h Timer load register. (32 bit read/write) */
  uint32 TimerTTGR;         /*!< +44h Timer trigger register. (32 bit read/write) */
  uint32 TimerTWPS;         /*!< +48h Timer write-posted register. (32 bit read) */
  uint32 TimerTMAR;         /*!< +4Ch Timer match register. (32 bit read/write) */
  uint32 TimerTCAR1;        /*!< +50h First captured value of the timer counter. (32 bit read) */
  uint32 TimerTSICR;        /*!< +54h Timer synchronous interface control register. (32 bit read/write) */
  uint32 TimerTCAR2;        /*!< +58h Second captured value of the timer counter. (32 bit read) */
  uint32 TimerTPIR;         /*!< +5Ch Timer positive increment register (32 bit read/write) */
  uint32 TimerTNIR;         /*!< +60h Timer negative increment register (32 bit read/write) */
  uint32 TimerTCVR;         /*!< +64h Timer CVR counter register (32 bit read/write) */
  uint32 TimerTOCR;         /*!< +68h Timer overflow counter register (32 bit read/write) */
  uint32 TimerTOWR;         /*!< +6Ch Timer overflow wrapping register (32 bit read/write) */
};


/*! Forward declaration of platform specific Jacinto7 timer type. */
typedef struct Os_Hal_TimerJacinto7Type_Tag Os_Hal_TimerJacinto7Type;

/*! Pointer to platform specific Jacinto7 timer type. */
typedef CONSTP2VAR(volatile Os_Hal_TimerJacinto7Type, AUTOMATIC, OS_CONST) Os_Hal_TimerJacinto7RefType;


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
  Os_Hal_TimerJacinto7RefType TimerRef = (Os_Hal_TimerJacinto7RefType)(TimerConfig->TimerBaseAddr);                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Execute software reset. */
  TimerRef->TimerTIOCPCFG    |= OS_HAL_TIMER_JACINTO7_SOFTWARERESETMASK;                                                /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Wait until reset release. */
  while(((TimerRef->TimerTIOCPCFG) & OS_HAL_TIMER_JACINTO7_SOFTWARERESETMASK) == 1u)                                    /* FETA_OS_HAL_ARM_JACINTO7FRTINIT */
  {
    /* Wait */
  }

  /* #30 Configure idle mode. */
  TimerRef->TimerTIOCPCFG    |= OS_HAL_TIMER_JACINTO7_SMARTIDLEMODE;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #40 Enable wake-up interrupt events. */
  TimerRef->TimerIRQWAKEEN   |= OS_HAL_TIMER_JACINTO7_COMPAREWAKEUPMASK;                                                /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #50 Select posted mode. */
  TimerRef->TimerTSICR        = OS_HAL_TIMER_JACINTO7_POSTEDMODE;                                                       /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #60 Select autoreload mode. */
  TimerRef->TimerTCLR        |= OS_HAL_TIMER_JACINTO7_AUTORELOADMASK;                                                   /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #70 Wait until pending write accesses are finished. */
  while(((((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerTWPS) & OS_HAL_TIMER_JACINTO7_TCLRWRITEPENDING) == 0x1uL) /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* FETA_OS_HAL_ARM_JACINTO7FRTINIT */
  {
    /* Wait */
  }

  /* #80 Enable match interrupt. */
  TimerRef->TimerIRQSTATUSSET = OS_HAL_TIMER_JACINTO7_MATCHINTMASK;                                                     /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #90 Load timer counter value. */
  TimerRef->TimerTCRR         = 0x0uL;                                                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #100 Load timer compare value. */
  TimerRef->TimerTMAR         = TimerConfig->CompareValue;                                                              /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #110 Enable compare mode. */
  TimerRef->TimerTCLR        |= OS_HAL_TIMER_JACINTO7_COMPAREENABLEMASK;                                                /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #120 Wait until pending write accesses are finished. */
  while(((((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerTWPS) & OS_HAL_TIMER_JACINTO7_TCLRWRITEPENDING) == 0x1uL) /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* FETA_OS_HAL_ARM_JACINTO7FRTINIT */
  {
    /* Wait */
  }

  /* #130 Enable interrupt. */
  Os_Hal_INTC_EnableSource((Os_Hal_IntSourceType)TimerConfig->InterruptSource, (Os_Hal_IntLevelType)TimerConfig->InterruptLevel, (Os_Hal_IntControllerType)0); /* PRQA S 4332 */ /* MD_Os_Rule10.5_4332 */

  /* #140 Start the timer. */
  TimerRef->TimerTCLR        |= OS_HAL_TIMER_JACINTO7_STARTMASK;                                                        /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  /* #10 Return counter value. */
  return ((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerTCRR;                                           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  /* #10 Return compare value. */
  return ((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerTMAR;                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
  /* #10 Set new compare value. */
  ((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerTMAR = ExpirationTime;                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Execute data sync barrier to ensure compare value is actually stored in TMAR register before returning. */
  Os_Hal_DataSyncBarrier();

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
  /* #10 Clear pending interrupt flag. */
  ((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerIRQSTATUS = OS_HAL_TIMER_JACINTO7_MATCHINTMASK;       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  /* #10 Trigger Irq. */
  ((Os_Hal_TimerJacinto7RefType)TimerConfig->TimerBaseAddr)->TimerIRQSTATUSRAW = OS_HAL_TIMER_JACINTO7_MATCHINTMASK;    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_FRT_JACINTO7_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Frt_Jacinto7.h
 **********************************************************************************************************************/
