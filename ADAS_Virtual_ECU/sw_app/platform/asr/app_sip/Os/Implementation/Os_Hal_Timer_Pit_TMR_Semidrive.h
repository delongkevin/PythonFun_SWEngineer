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
 *  \brief  HAL interface to work with the TMR Programmable Timer of the Semidrive G9 family.
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

#ifndef  OS_HAL_TIMER_PIT_TMR_SEMIDRIVE_H
# define OS_HAL_TIMER_PIT_TMR_SEMIDRIVE_H

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
/*! Initial reset value for timer counter configuration register. */
# define OS_HAL_TIMER_PIT_TMR_CNT_CONFIG_INIT_VALUE                   (0x0uL)

/*! SW force reload for CNT_LOCAL_A bit inside CNT_CONFIG register. */
# define OS_HAL_TIMER_PIT_TMR_CNT_CONFIG_CNT_LOCAL_A_RLD              (1uL << 2)

/*! Interrupt enable bit for CNT_LOCAL_A overflow inside function interrupt singal/status enable register. */
# define OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN                  (1uL << 10)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Periodic interrupt timer configuration information for TMR timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer reload value. */
  uint32 ReloadValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
};

 /*! Memory mapped TMR timer registers corresponding to the memory layout */
struct Os_Hal_TimerTMRSemidriveType_Tag
{
  uint32 INT_STA;           /*! < +00h Interrupt status register. (32 bit read/write). */
  uint32 INT_STA_EN;        /*! < +04h Interrupt status enable register. (32 bit read/write). */
  uint32 INT_SIG_EN;        /*! < +08h Interrupt signal enable register. (32 bit read/write). */
  uint32 DUMMY1[6];         /*! < +0Ch-20h Unused registers. */
  uint32 CNT_CONFIG;        /*! < +24h Timer counter configuration register. (32 bit read/write). */
  uint32 DUMMY2[2];         /*! < +28h-2Ch Unused registers. */
  uint32 CNT_LOCAL_A_OVF;   /*! < +30h Channel A overflow value register. (32 bit read/write). */
  uint32 DUMMY3[5];         /*! < +34h-44h Unused registers. */
  uint32 CNT_LOCAL_A;       /*! < +48h Channel A local counter register. (32 bit read/write). */
  uint32 DUMMY4[27];        /*! < +4Ch-B4h Unused registers. */
  uint32 CNT_LOCAL_A_INIT;  /*! < +B8h Channel A initial value register. (32 bit read/write). */
};

/*! Forward declaration of platform specific Semidrive G9 TMR timer type. */
typedef struct Os_Hal_TimerTMRSemidriveType_Tag Os_Hal_TimerTMRSemidriveType;

/*! Pointer to platform specific Semidrive G9 TMR timer type. */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  Os_Hal_TimerTMRSemidriveRefType TimerRef = (Os_Hal_TimerTMRSemidriveRefType)(TimerConfig->TimerBaseAddr);             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Initialize the to be uesd registers with reset value. */
  TimerRef->CNT_CONFIG = OS_HAL_TIMER_PIT_TMR_CNT_CONFIG_INIT_VALUE;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Set Initial value of counter. */
  TimerRef->CNT_LOCAL_A_INIT = (uint32)0x0;                                                                             /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #30 Configure the reload value, it won't take effect until the next auto overflow or software force reload. */
  TimerRef->CNT_LOCAL_A_OVF = TimerConfig->ReloadValue;                                                                 /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #40 Enable the overflow interrupt. */
  TimerRef->INT_STA_EN |= OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN;                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  TimerRef->INT_SIG_EN |= OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN;                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #50 Clear(write 1) the possible overflow interrupt in case it happened before if necessary. */
  TimerRef->INT_STA |= OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN;

  /* #60 Start the timer. CNT_LOCAL_A will be reset to 0 and new OVF_VAL set in step #30 will be effective. */
  TimerRef->CNT_CONFIG |= OS_HAL_TIMER_PIT_TMR_CNT_CONFIG_CNT_LOCAL_A_RLD;                                              /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  /* #70 Wait until it is done. */
  while((TimerRef->CNT_CONFIG & OS_HAL_TIMER_PIT_TMR_CNT_CONFIG_CNT_LOCAL_A_RLD) != 0uL)                                /* FETA_OS_HAL_ARM_SEMIDRIVEPITINIT */
  {
    Os_Hal_Nop();
  }

  /* #80 Enable the interrupt source for the timer OVERFLOW IRQ. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, (Os_Hal_IntControllerType)Os_Hal_CoreGetId());              /* PRQA S 4342 */ /* MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType */
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
  ((Os_Hal_TimerTMRSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STA |= OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN;/* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
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
  return (
           ((Os_Hal_TimerTMRSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STA                                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
           &
           OS_HAL_TIMER_PIT_TMR_CNT_LOCAL_A_OVF_INT_EN
         );
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_TMR_SEMIDRIVE_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_TMR_Semidrive.h
 **********************************************************************************************************************/
