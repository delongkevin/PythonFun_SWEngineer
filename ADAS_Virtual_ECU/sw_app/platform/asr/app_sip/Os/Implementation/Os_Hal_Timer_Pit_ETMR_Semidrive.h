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
 *  \brief  HAL interface to work with the eTimer(ETMR) Programmable Interval Timer of the Semidrive E3 family.
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

#ifndef  OS_HAL_TIMER_PIT_ETMR_SEMIDRIVE_H
# define OS_HAL_TIMER_PIT_ETMR_SEMIDRIVE_H

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
/*! Initial reset value for LCNT A configuration register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_INIT_VALUE                   (0x0uL)

/*! Initial reset value for LCNT A enable register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_EN_INIT_VALUE                       (0x0uL)

/*! LCNT_A enable bit inside LCNT A enable register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_ENABLE                              (1uL << 0)

/*! Interrupt enable bit for LCNT A inside function interrupt singal/status enable register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_INT_EN                              (1uL << 10)

/*! Counter event enable bit inside LCNT A configuration register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_CE_EN                        (1uL << 7)

/*! Init value update bit inside LCNT A configuration register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_INIT_UPDATE                  (1uL << 16)

/*! Overflow value update bit inside LCNT A configuration register. */
# define OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_OVF_UPDATE                   (1uL << 17)
 

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Periodic interrupt timer configuration information for ETMR timer module. */
struct Os_Hal_TimerPitConfigType_Tag
{
  /*! The timer base address. */
  uint32 TimerBaseAddr;
  /*! The timer reload value. */
  uint32 ReloadValue;
  /*! The timer interrupt source. */
  uint32 InterruptSource;
};

 /*! Memory mapped ETMR timer registers corresponding to the memory layout */
struct Os_Hal_TimerETMRSemidriveType_Tag
{
  uint32 INT_STA;           /*! < +00h Interrupt status register. (32 bit read/write). */
  uint32 INT_STA_EN;        /*! < +04h Interrupt status enable register. (32 bit read/write). */
  uint32 INT_SIG_EN;        /*! < +08h Interrupt signal enable register. (32 bit read/write). */
  uint32 DUMMY1[77];        /*! < +0Ch-13Ch Unused registers. */
  uint32 LCNT_A_INIT;       /*! < +140h Channel A initial value register. (32 bit read/write). */
  uint32 LCNT_A_OVF;        /*! < +144h Channel A overflow value register. (32 bit read/write). */
  uint32 LCNT_A_CFG ;       /*! < +148h Channel A counter configuration register. (32 bit read/write). */
  uint32 LCNT_A_EN;         /*! < +14Ch Channel A counter enable register. (32 bit read/write). */
  uint32 LCNT_A;            /*! < +150h Channel A counter register. (32 bit read). */
};

/*! Forward declaration of platform specific Semidrive E3 ETMR timer type. */
typedef struct Os_Hal_TimerETMRSemidriveType_Tag Os_Hal_TimerETMRSemidriveType;

/*! Pointer to platform specific Semidrive E3 ETMR timer type. */
typedef CONSTP2VAR(volatile Os_Hal_TimerETMRSemidriveType, AUTOMATIC, OS_CONST) Os_Hal_TimerETMRSemidriveRefType;

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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  Os_Hal_TimerETMRSemidriveRefType TimerRef = (Os_Hal_TimerETMRSemidriveRefType)(TimerConfig->TimerBaseAddr);           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  /* #10 Initialize the to be uesd registers with reset value. */
  TimerRef->LCNT_A_EN = OS_HAL_TIMER_PIT_ETMR_LCNT_A_EN_INIT_VALUE;                                                     /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  TimerRef->LCNT_A_CFG = OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_INIT_VALUE;                                                /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #20 Set Initial value of counter. */
  TimerRef->LCNT_A_INIT = (uint32)0x0;                                                                                  /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  /* #30 Update the counter with init value and wait until it is done. */
  TimerRef->LCNT_A_CFG = OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_INIT_UPDATE;                                               /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  while((TimerRef->LCNT_A_CFG & OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_INIT_UPDATE) != 0uL)                                /* FETA_OS_HAL_ARM_SEMIDRIVEPITINIT */
  {
    Os_Hal_Nop();
  }

  /* #40 Configure the counter reload value. */
  TimerRef->LCNT_A_OVF = TimerConfig->ReloadValue;                                                                      /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  /* #50 Update the counter with overflow value and wait until it is done. */
  TimerRef->LCNT_A_CFG = OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_OVF_UPDATE;                                                /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  while((TimerRef->LCNT_A_CFG & OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_OVF_UPDATE) != 0uL)                                 /* FETA_OS_HAL_ARM_SEMIDRIVEPITINIT */
  {
    Os_Hal_Nop();
  }

  /* #60 Counter (overflow) event enable. */
  TimerRef->LCNT_A_CFG |= OS_HAL_TIMER_PIT_ETMR_LCNT_A_CONFIG_CE_EN;                                                    /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #70 Enable the overflow interrupt. */
  TimerRef->INT_STA_EN |= OS_HAL_TIMER_PIT_ETMR_LCNT_A_INT_EN;                                                          /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  TimerRef->INT_SIG_EN |= OS_HAL_TIMER_PIT_ETMR_LCNT_A_INT_EN;                                                          /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #80 Enable the interrupt source for the counter. */
  Os_Hal_INTC_EnableSource(TimerConfig->InterruptSource, 0, (Os_Hal_IntControllerType)Os_Hal_CoreGetId());              /* PRQA S 4342 */ /* MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType */

  /* #90 Start the timer. */
  TimerRef->LCNT_A_EN |= OS_HAL_TIMER_PIT_ETMR_LCNT_A_ENABLE;                                                            /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

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
  ((Os_Hal_TimerETMRSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STA |= OS_HAL_TIMER_PIT_ETMR_LCNT_A_INT_EN;       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

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
           ((Os_Hal_TimerETMRSemidriveRefType)TimerConfig->TimerBaseAddr)->INT_STA                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
           &
           OS_HAL_TIMER_PIT_ETMR_LCNT_A_INT_EN
         );

}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_PIT_ETMR_SEMIDRIVE_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_Pit_ETMR_Semidrive.h
 **********************************************************************************************************************/
