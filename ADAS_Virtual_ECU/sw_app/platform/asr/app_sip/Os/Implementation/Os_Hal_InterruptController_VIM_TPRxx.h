/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup  Os_Hal_Interrupt
 *  \{
 *
 *  \file
 *  \brief   HAL interface to work with the Vectored Interrupt Manager (VIM).
 *  \details
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
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_INTERRUPTCONTROLLER_VIM_TPR_H
# define OS_HAL_INTERRUPTCONTROLLER_VIM_TPR_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL EXTERN CONST
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/

/*! Define the Interrupt Vectors Enable bit (bit 24 of the SCTLR register) */
# define OS_HAL_SCTLR_VE_BIT        (uint32)(1uL << 24uL)

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Trigger peripheral interrupt by software supported*/
# define OS_HAL_INTC_SWT_SUPPORTED                          (0u)

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
/*                Both IRQs and FIQs are not masked */
# define OS_HAL_TASK_LEVEL                                  (0x0u)

/*! The interrupt controller does not support priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                         0u

/*! VIM interrupt controller index. */
# define OS_HAL_INTC_VIM_ID                                 (0x0uL)

/* ------------------------------------------------------------------------------------- */
/* VIM Registers */
/* ------------------------------------------------------------------------------------- */

/*! VIM INTC base address */
/* VIM INTC base address is located in Os_Hal_Derivative_TPRxxInt.h */

/*! Prioritized IRQ register */
/* It contains the number of the highest priority pending IRQ and its prio. */
#define OS_HAL_TPRXX_INTC_VIM_PRIIRQ   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x8uL))

/*! Prioritized FIQ register */
/* It contains the number of the highest priority pending FIQ and its prio. */
#define OS_HAL_TPRXX_INTC_VIMPRIFIQ    (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0xCuL))

/*! IRQ group status register */
#define OS_HAL_TPRXX_INTC_VIM_IRQGSTS  (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x10uL))

/*! FIQ group status register */
#define OS_HAL_TPRXX_INTC_VIM_FIQGSTS  (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x14uL))

/*! Currently pending IRQ vector address register */
/* Only valid if the VIM_PRIIRQ[31] VALID flag is set.
   Reading this register masks all IRQ interrupts of an equivalent or lower priority ;
   loads VIM_ACTIRQ.
   Writing any value to this register removes the mask on all IRQ priorities.
 */
#define OS_HAL_TPRXX_INTC_VIM_IRQVEC  (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x18uL))

/*! Currently pending FIQ vector address register */
/* Only valid if the VIM_PRIFIQ[31] VALID flag is set.
   Reading this register masks all FIQ interrupts of an equivalent or lower priority ;
   loads VIM_ACTFIQ.
   Writing any value to this register removes the mask on all FIQ priorities.
 */
#define OS_HAL_TPRXX_INTC_VIM_FIQVEC  (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x1CuL))

/*! Active IRQ register */
/* Contains the number of the active IRQ and its prio.
   Only valid if the VALID flag of this register is set.
   VALID field is set whenever the VIM_IRQVEC is read.
   It is cleared whenever the VIM_IRQVEC is written.
 */
#define OS_HAL_TPRXX_INTC_VIM_ACTIRQ    (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x20uL))

/*! Active FIQ register */
/* Contains the number of the active FIQ and its prio.
   Only valid if the VALID flag of this register is set.
   VALID field is set whenever the VIM_FIQVEC is read.
   It is cleared whenever the VIM_FIQVEC is written.
 */
#define OS_HAL_TPRXX_INTC_VIM_ACTFIQ  (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x24uL))

/*! Raw status/set registers */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit indicates the raw status of the corresponding interrupt
   (Inactive, Active/pending).
 */
#define OS_HAL_TPRXX_INTC_VIM_RAW_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE             \
                                                                      + 0x400uL + ((IntSrc / 32uL) * 0x20uL)))
/*! Interrupt enable status/clear registers  */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit indicates the masked status of the corresponding interrupt
   (Inactive or disabled, Active/pending and enabled).
 */
#define OS_HAL_TPRXX_INTC_VIM_STS_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE             \
                                                                      + 0x404uL + ((IntSrc / 32uL) * 0x20uL)))
/*! Interrupt enable set registers */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit of each register corresponds to an interrupt
 */
#define OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE     \
                                                                              + 0x408uL + ((IntSrc / 32uL) * 0x20uL)))
/*! IRQ interrupt enable status/clear register */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit indicates the masked status of the corresponding IRQ
   interrupt (Inactive or disabled, Active/pending and enabled).
 */
#define OS_HAL_TPRXX_INTC_VIM_IRQSTS_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE          \
                                                                         + 0x410uL + ((IntSrc / 32uL) * 0x20uL)))
/*! FIQ interrupt enable status/clear register */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit indicates the masked status of the corresponding FIQ
   interrupt (Inactive or disabled, Active/pending and enabled).
 */
#define OS_HAL_TPRXX_INTC_VIM_FIQSTS_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE          \
                                                                         + 0x414uL + ((IntSrc / 32uL) * 0x20uL)))
/*! Interrupt enabled clear registers */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit of each register corresponds to an interrupt
 */
#define OS_HAL_TPRXX_INTC_VIM_INTR_EN_CLR_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE     \
                                                                              + 0x40CuL + ((IntSrc / 32uL) * 0x20uL)))
/*! Interrupt map registers. */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each register maps 32 interrupts as IRQ or FIQ.
 */
#define OS_HAL_TPRXX_INTC_VIM_INTMAP_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE          \
                                                                         + 0x418uL + ((IntSrc / 32uL) * 0x20uL)))

/*! Interrupt type registers */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 16 registers [0..15] identified by IntGrp = (IntSrc / 32uL).
   Each bit indicates whether the source of an interrupt is
   a level (0: default) or a pulse.
 */
#define OS_HAL_TPRXX_INTC_VIM_INTTYPE_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE         \
                                                                          + 0x41CuL + ((IntSrc / 32uL) * 0x20uL)))
/*! Interrupt priority registers */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 255 registers (1 reg per int) identified by IntSrc: 0..255.
   Priority value: 0..15
   -> For each Interrupt the priority field is the 4 LSB bits of its register.

   Note:
   The interrupt with the lower index wins the arbitration
   between 2 interrupts having the same priority.
 */
#define OS_HAL_TPRXX_INTC_VIM_PRI_INT_J(IntSrc)   (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE         \
                                                                          + 0x1000uL + (IntSrc * 0x04uL)))
/*! Interrupt vector registers. */
/* This macro returns the content of the register related to the interrupt source identified by IntSrc.
   There are 255 registers (1 reg per int) identified by IntSrc: 0..255.
   Each register contains the vector address of its corresponding interrupt.
 */
#define OS_HAL_TPRXX_INTC_VIM_VEC_INT_J(IntSrc)    (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE        \
                                                                           + 0x2000uL + (IntSrc * 0x04uL)))

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_INTC_InitSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_InitSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Set the interrupt priority of a given IRQ source. */
  OS_HAL_TPRXX_INTC_VIM_PRI_INT_J(InterruptConfig->Source) = (InterruptConfig->Level);                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_PRI_INT_J */ /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Map the interrupt as IRQ or FIQ (represented by InterruptConfig->Type) */
  /* Keeping the default value: IRQ for now */

  /* #30 Map the interrupt as Pulse or Level (represented by InterruptConfig->TriggerType) */
  OS_HAL_TPRXX_INTC_VIM_INTTYPE_J(InterruptConfig->Source) &= ~(uint32)(0x01uL << (InterruptConfig->Source % 32uL));    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
  OS_HAL_TPRXX_INTC_VIM_INTTYPE_J(InterruptConfig->Source) |= (uint32)(((uint32)(InterruptConfig->TriggerType)) <<      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_INTMAP_J */ /* SBSW_OS_HAL_PWA_CALLER */
                                                                          (InterruptConfig->Source % 32uL) );
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerCrossCoreInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORCROSSCOREUNSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerCrossCoreInterrupt,
(
  uint32 CoreID,
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORCROSSCOREUNSUPPORTED */
{
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerPeripheralInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORCROSSCOREUNSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerPeripheralInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntControllerType InterruptController
))                                                                                                                      /* COV_OS_HALPLATFORCROSSCOREUNSUPPORTED */
{
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_IntDisableAndReturnGlobalState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntGlobalStateType, OS_CODE, OS_ALWAYS_INLINE,                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntDisableAndReturnGlobalState, (void))
{
   Os_Hal_IntGlobalStateType psr;
   Os_Hal_IntGlobalStateType previousGlobalState;

  /* #10 Get current FIQ and IRQ bits from CPSR. */
  psr = Os_Hal_ReadPsr();
  previousGlobalState = (psr & (OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ));

  /* #20 Set FIQ and IRQ of CPSR (global interrupt disable). */
  Os_Hal_WritePsr(psr | (OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ));

  /* #30 Return the previously read global state. */
  return previousGlobalState;
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_InitIntVectors()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  uint16 IntSrc;
  
  /* #10 Get the content of SCTLR register */
  uint32 systemControl = Os_Hal_GetSystemControl();
  
  /* #20 Prepare the value to be written back to SCTLR having VE bit set to 0 */
  systemControl &= ~(OS_HAL_SCTLR_VE_BIT);
  
  /* #30 Enable the usage of FIQ and IRQ vectors of the exception table */
  Os_Hal_SetSystemControl(systemControl);

  /* #40 Set the handler function address of a given core related interrupt source. */
  for(IntSrc = 0; IntSrc < OS_HAL_INTC_NUMBER_OF_IRQS; IntSrc++)
  {
    OS_HAL_TPRXX_INTC_VIM_VEC_INT_J(IntSrc) = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_VIM_ID][IntSrc]);               /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* OS_HAL_TPRXX_INTC_VIM_VEC_INT_J */ /* SBSW_OS_HAL_PWA_CALLER */
  }

  /* Handle hardware bug in back-2-back activation of the same interrupt. */
  /* #50 Set the interrupt priority of the dummy source to the highest priority. */
  OS_HAL_TPRXX_INTC_VIM_PRI_INT_J(OS_HAL_INTC_VIM_DUMMY_SOURCE) = (uint32)(0);                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_PRI_INT_J */ /* SBSW_OS_HAL_PWA_CALLER */

  /* #60 Map the interrupt as IRQ. */
  OS_HAL_TPRXX_INTC_VIM_INTMAP_J(OS_HAL_INTC_VIM_DUMMY_SOURCE) &= ~(uint32)(0x01uL <<                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
                                                                              (OS_HAL_INTC_VIM_DUMMY_SOURCE % 32uL));

  /* #70 Enable interrupt handling for the dummy source. */
  OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J(OS_HAL_INTC_VIM_DUMMY_SOURCE) |= (uint32)(0x01uL <<                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J */ /* SBSW_OS_HAL_PWA_CALLER */
                                                                               (OS_HAL_INTC_VIM_DUMMY_SOURCE % 32uL));
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IrqHandler()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IrqHandler, (
  uint32 Address,
  uint32 IsPrivileged
))                                                                                                                      /* COV_OS_HALPLATFORMNOCENTRALECXEPTIONHANDLER */
{
  /* #10 This kind of interrupt handler is required for some interrupt controllers (e.g. GIC). Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Address);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsPrivileged);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_EnableSource,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntLevelType Level,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable interrupt handling for a given interrupt source. */
  OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J(Source) |= (uint32)(1uL << (Source % 32uL));                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J */ /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
Os_Hal_INTC_EnableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* Empty for now */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Disable interrupt handling for for given interrupt. */
  OS_HAL_TPRXX_INTC_VIM_INTR_EN_CLR_J(InterruptConfig->Source) = (uint32)(1uL << (InterruptConfig->Source % 32uL));     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* OS_HAL_TPRXX_INTC_VIM_INTR_EN_CLR_J */ /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
Os_Hal_INTC_DisableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* Empty for now */

}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Level handling not supported. */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
Os_Hal_INTC_SetCurrentLevelException,
(
  Os_Hal_IntLevelType Level
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  /* #10 Ignore the passed level, as the hardware does not support interrupt level switching */
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_GetCurrentLevel,
(
  void
))
{
  /* #10 Level handling not supported. */
  return (Os_Hal_IntLevelType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* COV_OS_HALPLATFORMLEVELSUPPORT */
Os_Hal_INTC_GetCurrentLevelException,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  /* #10 Return always 0 as the hardware does not support interrupt level switching. */

  return (Os_Hal_IntLevelType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EndOfInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_EndOfInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID
))
{
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /*
     - If it is a pulse interrupt (1):
     . Clearing the status is done in assembly when entering the interrupt
     . Clearing the interrupt at the source is done by the User in the User Int Handler (called in Int Entry
       previous to this step)

     - If it is a level interrupt (0):
     . Clearing the interrupt at the source is done by the User in the User Int Handler (called in Int Entry
       previous to this step)
     . The status is cleared by a call of Os_Hal_IntPostAction() previuos to this function in the core code.

     Ref: SPRUIJ7, 6.3.3.6.9.2 Servicing IRQ Through MMR Interface, 3.
  */

  /*
     - For Cat2 interrupts, Write any value to VIM_IRQVEC register to:
        . clear VIM_ACTIRQ register and,
        . unmask lower priority interrupts

     - For Cat0/1, the same is to be done by the user.
  */

  OS_HAL_TPRXX_INTC_VIM_IRQVEC = (uint32)(0xFF);                                                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntEndOfInterruptMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
Os_Hal_INTC_IntEndOfInterruptMapped,
(
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* Empty */

}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{

  /* #10 Return the Enabled/Disabled setting of a given interrupt source. */
  return (Os_StdReturnType)((OS_HAL_TPRXX_INTC_VIM_INTR_EN_SET_J(InterruptConfig->Source) &                             /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
                            (1uL << (InterruptConfig->Source % 32uL))) != 0uL);
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IsMappedInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsMappedInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  return 0;

  /* Empty */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_ClearPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_ClearPending,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID,
  Os_Hal_IntControllerType InterruptController
))                                                                                                                      /* COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY */
{
  volatile uint32 forceRead = 0;                                                                                        /* COMP_WARN_UNUSED_VARIABLE */

  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Clear pending state of given interrupt source. */
  forceRead = OS_HAL_TPRXX_INTC_VIM_IRQVEC;                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  OS_HAL_TPRXX_INTC_VIM_IRQSTS_J(Source) = (1uL << (Source % 32uL));                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
  OS_HAL_TPRXX_INTC_VIM_IRQVEC = (uint32)(0xFF);                                                                        /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntClearPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
Os_Hal_INTC_IntClearPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* Empty */

}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMLEVELSUPPORT */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  /* #10 Return pending state of a given IRQ interrupt source. */
  return (Os_StdReturnType)((OS_HAL_TPRXX_INTC_VIM_IRQSTS_J(InterruptConfig->Source) &                                  /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
                            (1uL << (InterruptConfig->Source % 32uL))) != 0u);
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMLEVELSUPPORT */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  return (Os_StdReturnType)(0u);
  /* Empty */
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IsClearPendingSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsClearPendingSupported, ( void ))
{
  /* #10 Return 1 (clear pending is possible). */
  return (Os_StdReturnType)(1u);
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptMappingSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptMappingSupported, ( void ))
{
  /* #10 Check whether interrupt mapping is supported. */
  return (Os_StdReturnType)(0u);
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntLevelIsGt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_IntLevelIsGt,
(
  CONST(Os_Hal_IntLevelType, OS_CONST) LevelX,
  CONST(Os_Hal_IntLevelType, OS_CONST) LevelY
))
{
  /* #10 Returns whether given interrupt priority level LevelX is logically greater than LevelY. */
  /* Note: Lower priority/Level value has higher priority */
  return (Os_StdReturnType)(LevelX > LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_Hal_IntIsInterruptPostActionSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntIsInterruptPostActionSupported, ( void ))
{
  /* #10 Return 1 as the hardware supports interrupt post action handling. */
  return (Os_StdReturnType)(1u);
}


/***********************************************************************************************************************
 *  Os_Hal_IntPostAction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntPostAction,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig
))
{
  /* #10 Clear the status flag for IRQ source. */
  OS_HAL_TPRXX_INTC_VIM_IRQSTS_J(IsrConfig->Source) = (1uL << (IsrConfig->Source % 32uL));                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_IntPostActionMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntPostActionMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  /* Empty */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_VIM_TPR_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_VIM_TPRxx.h
 *********************************************************************************************************************/

