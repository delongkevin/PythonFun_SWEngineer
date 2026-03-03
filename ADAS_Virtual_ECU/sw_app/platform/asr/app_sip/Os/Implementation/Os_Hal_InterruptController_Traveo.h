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
 *  \brief   HAL interface to work with the Spansion InterRupt Controller (IRC) of the Traveo family.
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
#ifndef  OS_HAL_INTERRUPTCONTROLLER_TRAVEO_H
# define OS_HAL_INTERRUPTCONTROLLER_TRAVEO_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR2_DISABLE_LEVEL)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR1_DISABLE_LEVEL)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_CFG_HAL_TP_DISABLE_LEVEL)

/*! Trigger peripheral interrupt by software supported*/
# define OS_HAL_INTC_SWT_SUPPORTED                          1u

/*! The interrupt controller supports priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        1u

/*! Traveo interrupt controller index. */
# define OS_HAL_INTC_TRAVEO_ID                              0x0uL

/*! Traveo interrupt controller CSR IRQEN enable bit. */
# define OS_HAL_INTC_TRAVEO_CSR_IRQEN_SET                   1uL

/*! Traveo interrupt controller CSR IRQEN disable bit. */
# define OS_HAL_INTC_TRAVEO_CSR_IRQEN_RESET                 0uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/*! NMI vector address status register (NMIVAS). */
# define OS_HAL_INTC_TRAVEO_NMIVAS      (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0x0uL))

/*! NMI status register (NMIST). */
# define OS_HAL_INTC_TRAVEO_NMIST       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0x4uL))

/*! IRQ vector address status register (IRQVAS). */
# define OS_HAL_INTC_TRAVEO_IRQVAS      (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0x8uL))

/*! IRQ status register (IRQST). */
# define OS_HAL_INTC_TRAVEO_IRQST       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xCuL))

/*! NMI vector address register (NMIVA). */
# define OS_HAL_INTC_TRAVEO_NMIVA(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0x10uL + ((x) * 4uL)))

/*! IRQ vector address register (IRQVA). */
# define OS_HAL_INTC_TRAVEO_IRQVA(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0x90uL + ((x) * 4uL)))

/*! Set NMIPL or IRQPL depending on interrupt type x to level y.*/
#define OS_HAL_INTC_TRAVEO_PRIORITY_LEVEL(x, y)  (*(volatile uint8*)(                                                   \
                                                  OS_HAL_INTC_TRAVEO_BASE + 0x890uL + ((x) * 0x20uL) + (y)))

/*! NMI priority level register (NMIPL). */
# define OS_HAL_INTC_TRAVEO_NMIPL(x)    (*(volatile uint8*) (OS_HAL_INTC_TRAVEO_BASE + 0x890uL + (x)))

/*! IRQ priority level register (IRQPL). */
# define OS_HAL_INTC_TRAVEO_IRQPL(x)    (*(volatile uint8*) (OS_HAL_INTC_TRAVEO_BASE + 0x8B0uL + (x)))

/*! NMI software interrupt set register (NMIS). */
# define OS_HAL_INTC_TRAVEO_NMIS        (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xAB0uL))

/*! NMI software interrupt reset register (NMIR). */
# define OS_HAL_INTC_TRAVEO_NMIR        (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xAB4uL))

/*! NMI software interrupt status register (NMISIS). */
# define OS_HAL_INTC_TRAVEO_NMISIS      (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xAB8uL))

/*! IRQ software interrupt set register (IRQS). */
# define OS_HAL_INTC_TRAVEO_IRQS(x)     (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xAC0uL + ((x) * 4uL)))

/*! IRQ software interrupt reset register (IRQR). */
# define OS_HAL_INTC_TRAVEO_IRQR(x)     (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xB00uL + ((x) * 4uL)))

/*! IRQ software interrupt status register (IRQSIS). */
# define OS_HAL_INTC_TRAVEO_IRQSIS(x)   (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xB40uL + ((x) * 4uL)))

/*! IRQ channel enable set register (IRQCES). */
# define OS_HAL_INTC_TRAVEO_IRQCES(x)   (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xB80uL + ((x) * 4uL)))

/*! IRQ channel enable clear register (IRQCEC). */
# define OS_HAL_INTC_TRAVEO_IRQCEC(x)   (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xBC0uL + ((x) * 4uL)))

/*! IRQ channel enable setting register (IRQCE). */
# define OS_HAL_INTC_TRAVEO_IRQCE(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC00uL + ((x) * 4uL)))

/*! NMI hold clear register (NMIHC). */
# define OS_HAL_INTC_TRAVEO_NMIHC       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC40uL))

/*! NMI hold status register (NMIHS). */
# define OS_HAL_INTC_TRAVEO_NMIHS       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC44uL))

/*! IRQ hold clear register (IRQHC). */
# define OS_HAL_INTC_TRAVEO_IRQHC       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC48uL))

/*! IRQ hold status register (IRQHS). */
# define OS_HAL_INTC_TRAVEO_IRQHS(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC50uL + ((x) * 4uL)))

/*! IRQ priority level mask register (IRQPLM). */
# define OS_HAL_INTC_TRAVEO_IRQPLM      (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC90uL))

/*! Control/status register (CSR). */
# define OS_HAL_INTC_TRAVEO_CSR         (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xC98uL))

/*! NMI RAW status register (NMIRS). */
# define OS_HAL_INTC_TRAVEO_NMIRS       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xCA8uL))

/*! NMI preprocessed status register (NMIPS). */
# define OS_HAL_INTC_TRAVEO_NMIPS       (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xCACuL))

/*! IRQ RAW status register (IRQRS). */
# define OS_HAL_INTC_TRAVEO_IRQRS(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xCB0uL + ((x) * 4uL)))

/*! IRQ preprocessed status register (IRQPS). */
# define OS_HAL_INTC_TRAVEO_IRQPS(x)    (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xCF0uL + ((x) * 4uL)))

/*! Unlock register. */
# define OS_HAL_INTC_TRAVEO_UNLOCK      (*(volatile uint32*) (OS_HAL_INTC_TRAVEO_BASE + 0xD30uL))

/*! Unlock key value. */
# define OS_HAL_INTC_TRAVEO_KEY_UNLOCK  (0x17ACC911uL)

/*! Lock key value. */
# define OS_HAL_INTC_TRAVEO_KEY_LOCK    (0x17B10C11uL)

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL              (32u)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************************************************************
 *  Os_Hal_INTC_Unlock()
 **********************************************************************************************************************/
/*! \brief        Unlock the interrupt controller.
 *  \details      Unlocking enables the writing to the interrupt controller's configuration registers.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_Unlock,
(void));

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_INTC_Unlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_Unlock,
(void))
{
  /* #10 Write unlock key to UNLOCK register. */
  OS_HAL_INTC_TRAVEO_UNLOCK = OS_HAL_INTC_TRAVEO_KEY_UNLOCK;                                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_UNLOCK */
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
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_Hal_IntGlobalStateType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_IntDisableAndReturnGlobalState, (void))
{
   Os_Hal_IntGlobalStateType psr;
   Os_Hal_IntGlobalStateType previousGlobalState;


  /* #10 Get current IRQ and FIQ bits from CPSR. */
  psr = Os_Hal_ReadPsr();
  previousGlobalState = (psr & (OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ));

  /* #20 Set IRQ and FIQ bits of CPSR (global interrupt disable). */
  Os_Hal_WritePsr(psr | OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ);

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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  uint16_least i;

  /* #10 Unlock interrupt controller. */
  Os_Hal_INTC_Unlock();

  /* #20 For each physically available external IRQ source: */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_IRQS; i++)
  {
    /* #30 Set IRQVA to configured handler function address. */
    OS_HAL_INTC_TRAVEO_IRQVA(i) = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_TRAVEO_ID][i]);                             /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_IRQVA */
  }

  /* #40 For each physically available external FIQ source: */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_FIQS; i++)
  {
    /* #50 Set IRQVA to configured handler function address. */
    OS_HAL_INTC_TRAVEO_NMIVA(i) = (uint32)(Core->FiqVectorTable[i]);                                                    /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_IRQVA */
  }

  /* #60 Enable IRQ processing by setting CSR.IRQEN flag. */
  OS_HAL_INTC_TRAVEO_CSR = 1uL;                                                                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_CSR */

}


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
  /* #10 Unlock the interrupt controller. */
  Os_Hal_INTC_Unlock();

  if ((InterruptConfig->Type == OS_HAL_ISR_TYPE_FIQ) && (InterruptConfig->Source == 0u)){
    /* #20 If the FIQ channel 0 is configured do nothing (changing priority hardwired to 0 leads to exception). */
  }
  else{
    /* #30 Else set the interrupt priority for given interrupt source to given level. */
    OS_HAL_INTC_TRAVEO_PRIORITY_LEVEL((uint32)(InterruptConfig->Type), InterruptConfig->Source) =                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
      (uint8)(InterruptConfig->Level);                                                                                  /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_PRIO */
  }
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

  /* #10 Enable interrupt handling (IRQCES) for given interrupt source. */
  OS_HAL_INTC_TRAVEO_IRQCES(Source >> 5) = (1uL << (Source & 31uL));                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_ENABLE */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_EnableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  /* #10 Disable interrupt handling (IRQCEC) for given interrupt source. */
  OS_HAL_INTC_TRAVEO_IRQCEC(InterruptConfig->Source >> 5) = (1uL << (InterruptConfig->Source & 31uL));                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_ENABLE */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_DisableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))
{
  /* #10 Disable IRQ processing by setting CSR.IRQEN flag to 0. */
  OS_HAL_INTC_TRAVEO_CSR = OS_HAL_INTC_TRAVEO_CSR_IRQEN_RESET;                                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_CSR */

  /* #20 Set current level (IRQPLM) to given level. */
  OS_HAL_INTC_TRAVEO_IRQPLM = Level;                                                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_PRIO */ /* COMP_WARN_OS_HAL_UNINITIALIZED_VAR */

  /* #30 Enable IRQ processing by setting CSR.IRQEN flag to 1. */
  OS_HAL_INTC_TRAVEO_CSR = OS_HAL_INTC_TRAVEO_CSR_IRQEN_SET;                                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_CSR */
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
  /* #10 Return value of IRQPLM. */
  return (Os_Hal_IntLevelType)OS_HAL_INTC_TRAVEO_IRQPLM;                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_GetCurrentLevelException,
(
  void
))
{
  /* #10 Return value of IRQPLM. */
  return (Os_Hal_IntLevelType)OS_HAL_INTC_TRAVEO_IRQPLM;                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevelException,
(
  Os_Hal_IntLevelType LockLevel
))
{
  /* #10 Set current level (IRQPLM) to given level. */
  OS_HAL_INTC_TRAVEO_IRQPLM = LockLevel;                                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_PRIO */ /* COMP_WARN_OS_HAL_UNINITIALIZED_VAR */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_ClearPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_ClearPending,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Reset given interrupt source by setting its bit in IRQR. */
  OS_HAL_INTC_TRAVEO_IRQR(Source >> 5) = (1uL << (Source & 31uL));                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_SFTW */

  /* #20 Signal end of interrupt for the given source. */
  Os_Hal_INTC_EndOfInterrupt(Source, SenderCoreID);
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
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Write given source number to IRQHC. */
  OS_HAL_INTC_TRAVEO_IRQHC = Source;                                                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_HOLD */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntEndOfInterruptMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntEndOfInterruptMapped,
(
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerPeripheralInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Trigger given source by setting its bit in IRQS. */
  OS_HAL_INTC_TRAVEO_IRQS(Source >> 5) = (1uL << (Source & 31uL));                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_SFTW */
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
  /* #10 Return enable setting of given interrupt source by reading its bit in IRQCE. */
  return (Os_StdReturnType)((OS_HAL_INTC_TRAVEO_IRQCE(InterruptConfig->Source >> 5) &                                   /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
      (1uL << (InterruptConfig->Source & 31uL))) != 0u);
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
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Mapped interrupt feauture is not supported. */
  return (Os_StdReturnType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsInterruptPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Return pending state of given interrupt source by reading its bit in IRQSIS. */
  return (Os_StdReturnType)((OS_HAL_INTC_TRAVEO_IRQSIS(InterruptConfig->Source >> 5) &                                  /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
      (1uL << (InterruptConfig->Source & 31uL))) != 0u);
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
  /* #10 Return !0 if LevelX is smaller than LevelY. */
  return (Os_StdReturnType)(LevelX < LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
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
  /* #10 Return 1 (clear pending interrupt is always possible). */
   return (Os_StdReturnType)(1u);
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
Os_Hal_INTC_IrqHandler,
(
  uint32 Address,
  uint32 IsPrivileged
))                                                                                                                      /* COV_OS_HALPLATFORMNOCENTRALECXEPTIONHANDLER */
{
  /* #10 No central interrupt handler for Spansion. Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Address);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsPrivileged);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerCrossCoreInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
  Os_Hal_INTC_TriggerCrossCoreInterrupt,
(
  uint32 CoreID,
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Not supported: single core derivative.*/
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntClearPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntClearPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  /* #10 Mapped interrupt feauture is not supported. */
  return (Os_StdReturnType)(0u);
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
  /* #10 Return 0 as the hardware does not support interrupt post action handling. */
  return 0u;
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
))                                                                                                                      /* COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY */
{
  /* #10 Nothing to do on this hardware. */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_IntPostActionMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_IntPostActionMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) IsrConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY */
{
  /* #10 Nothing to do on this hardware. */
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                     /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_TRAVEO_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_Traveo.h
 *********************************************************************************************************************/

