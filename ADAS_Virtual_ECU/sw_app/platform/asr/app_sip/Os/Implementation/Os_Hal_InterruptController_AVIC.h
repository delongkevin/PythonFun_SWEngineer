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
 *  \file    Os_Hal_InterruptController_AVIC.h
 *  \brief   HAL interface to work with the ARM daisy chained VIC Controller used by NVIDIA.
 *  \details -
 *
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

#if !defined(OS_HAL_INTERRUPTCONTROLLER_AVIC_H)
# define OS_HAL_INTERRUPTCONTROLLER_AVIC_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL                                  (16)

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR2_DISABLE_LEVEL)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR1_DISABLE_LEVEL)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_CFG_HAL_TP_DISABLE_LEVEL)

/*! Trigger peripheral interrupt by software supported */
# define OS_HAL_INTC_SWT_SUPPORTED                          1UL

/*! The interrupt controller supports priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        1UL

/*! Interrupt Vectors Enable Value (SCTLR.VE). */
# define OS_HAL_SCTLR_VE_ENABLE                             1UL << 24

/*! AVIC0 interrupt controller index. */
# define OS_HAL_INTC_AVIC0                                  0x0uL

/*! AVIC1 interrupt controller index. */
# define OS_HAL_INTC_AVIC1                                  0x1uL

/*! Mask for the bit 0. */
# define OS_HAL_INT_MASK_BIT_0                              0x1uL

/*! Dummy value to write into VICADDRESS register. */
# define OS_HAL_INT_VICADDRESS_DUMMY                        0x1uL

/*! Highest interrupt priority value. */
# define OS_HAL_INT_VIC_HIGHEST_PRIO                        0x0uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! Get the corresponding interrupt controller instance base address (SCE_VIC_0 or SCE_VIC_1). */
#define OS_HAL_INTC_AVIC_INSTANCE(x)  ((volatile Os_Hal_IntcVicType*)(OS_HAL_INTC_AVIC_AVIC0_BASE + (x * 0x10000UL)))


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! VIC register map. */
typedef struct
{
  uint32 VicIrqStatus;                              /*!< Offset: 0x00  IRQ Status Register. */
  uint32 VicFiqStatus;                              /*!< Offset: 0x04  FIQ Status Register. */
  uint32 VicRawIntr;                                /*!< Offset: 0x08  Raw Interrupt Status Register. */
  uint32 VicIntSelect;                              /*!< Offset: 0x0C  Interrupt Select Register. */
  uint32 VicIntEnable;                              /*!< Offset: 0x10  Interrupt Enable Register. */
  uint32 VicIntEnClear;                             /*!< Offset: 0x14  Interrupt Enable Clear Register. */
  uint32 VicSoftInt;                                /*!< Offset: 0x18  Software Interrupt Register. */
  uint32 VicSoftIntClear;                           /*!< Offset: 0x1C  Software Interrupt Clear Register. */
  uint32 VicProtection;                             /*!< Offset: 0x20  Protection Enable Register (1 bit Register). */
  uint16 VicSwPriorityMask;                         /*!< Offset: 0x24  Software Priority Mask Register. */
  uint16 Reserved;                                  /*!< Offset: 0x26  Reserved. */
  uint32 VicPriorityDaisy;                          /*!< Offset: 0x28  Vector Priority Register for Daisy Chain (4 bit Register). */
  uint32 Reserved0[53];                             /*!< Offset: 0x2C  Reserved. */
  uint32 VicVectAddr[OS_HAL_INTC_NUMBER_OF_IRQS];   /*!< Offset: 0x100 Vector Address Register. */
  uint32 Reserved1[32];                             /*!< Offset: 0x180 Reserved. */
  uint32 VicVectPrio[OS_HAL_INTC_NUMBER_OF_IRQS];   /*!< Offset: 0x200 Vector Priority Registers (each one has 4 bit width). */
  uint32 Reserved2[800];                            /*!< Offset: 0x280 Reserved. */
  uint32 VicAddress;                                /*!< Offset: 0xF00 Vector Address Register. */
  uint32 Reserved3[55];                             /*!< Offset: 0xF04 Reserved. */
  uint32 VicPeriphId[4];                            /*!< Offset: 0xFE0 Peripheral Identification Register (each one has 8 bit width). */
  uint32 VicPCellId[4];                             /*!< Offset: 0xFF0 PrimeCell Identification Register (each one has 8 bit width). */
} Os_Hal_IntcVicType;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  /* #10 Set VE bit in STCLR Register. */
  volatile uint32 i;
  volatile uint32 systemControl = Os_Hal_GetSystemControl();
  systemControl |= OS_HAL_SCTLR_VE_ENABLE;
  Os_Hal_SetSystemControl(systemControl);

  /* #20 For each AVIC0 available interrupt source. */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_IRQS; i++)
  {
    /* #30 Set the AVIC0 VICVECTADDR register to the configured handler function address. */
    OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicVectAddr[i] = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_AVIC0][i]);
  }

  /* #40 For each AVIC1 available interrupt source. */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_IRQS; i++)
  {
    /* #50 Set the AVIC1 VICVECTADDR register to the configured handler function address. */
    OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicVectAddr[i] = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_AVIC1][i]);
  }
    /* #60 Set the AVIC0 VICPRIORITYDAISY register to the max priority to enable nesting. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicPriorityDaisy = OS_HAL_INT_VIC_HIGHEST_PRIO;

  /* #70 Execute data sync barrier instruction. */
  Os_Hal_DataSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_InitSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  const Os_Hal_IntControllerType interruptControllerId = InterruptConfig->InterruptController;
  const Os_Hal_IntSourceType source = InterruptConfig->Source;

  /* #10 Set the interrupt priority. */
  OS_HAL_INTC_AVIC_INSTANCE(interruptControllerId)->VicVectPrio[source] = (uint16)InterruptConfig->Level;

  /* #20 Set the interrupt type (0=IRQ; 1=FIQ). */
  OS_HAL_INTC_AVIC_INSTANCE(interruptControllerId)->VicIntSelect |= ((~InterruptConfig->Type & OS_HAL_INT_MASK_BIT_0)
      << source);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_EnableSource,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntLevelType Level,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable given interrupt source by setting the corresponding bit in VICINTENABLE. */
  OS_HAL_INTC_AVIC_INSTANCE(InterruptController)->VicIntEnable = 1uL << Source;
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_EnableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  const Os_Hal_IntControllerType InterruptControllerId = InterruptConfig->InterruptController;
  const Os_Hal_IntSourceType Source = InterruptConfig->Source;

  /* #10 Disable given interrupt source by setting the corresponding VICINTENCLEAR. */
  OS_HAL_INTC_AVIC_INSTANCE(InterruptControllerId)->VicIntEnClear = 1uL << Source;
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_DisableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableMappedSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))
{
  /* #10 Set interrupt priority mask register to given level for AVIC0. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicSwPriorityMask = (uint16)((1uL << Level) - 1);

  /* #20 Set interrupt priority mask register to given level for AVIC1. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicSwPriorityMask = (uint16)((1uL << Level) - 1);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_SetCurrentLevelException,
(
  Os_Hal_IntLevelType Level
))
{
  /* #10 Set interrupt priority mask register to given level for AVIC0. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicSwPriorityMask = (uint16)((1uL << Level) - 1);

  /* #20 Set interrupt priority mask register to given level for AVIC1. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicSwPriorityMask = (uint16)((1uL << Level) - 1);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_GetCurrentLevel,
(
  void
))
{
  const uint32 Avic0Level = OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicSwPriorityMask;
  const uint32 Avic1Level = OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicSwPriorityMask;

  /* #10 Assert both interrupt controller have the same level mask values. */
  Os_Assert(Avic0Level == Avic1Level);

  /* #20 Return first 0 bit starting from the least significant one. */
  return (32uL - Os_Hal_CountLeadingZeros(Avic0Level));
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_GetCurrentLevelException,
(
  void
))
{
  const uint32 Avic0Level = OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicSwPriorityMask;
  const uint32 Avic1Level = OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicSwPriorityMask;

  /* #10 Assert both interrupt controller have the same level mask values. */
  Os_Assert(Avic0Level == Avic1Level);

  /* #20 Return first 0 bit starting from the least significant one. */
  return (32uL - Os_Hal_CountLeadingZeros(Avic0Level));
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_ClearPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_ClearPending,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID,
  Os_Hal_IntControllerType InterruptController
))
{
  /* #10 Dummy implementation: not supported by VIC. */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EndOfInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_EndOfInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID
))
{
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Write to the VICADDRESS registers to acknowledge the interrupt. */
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC0)->VicAddress = OS_HAL_INT_VICADDRESS_DUMMY;
  OS_HAL_INTC_AVIC_INSTANCE(OS_HAL_INTC_AVIC1)->VicAddress = OS_HAL_INT_VICADDRESS_DUMMY;
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntEndOfInterruptMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_IntEndOfInterruptMapped,
(
  Os_Hal_IntSourceType Source
))
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
  /* #10 Trigger the corresponding software interrupt (same effect). */
  OS_HAL_INTC_AVIC_INSTANCE(InterruptController)->VicSoftInt = 1uL << Source;
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
  /* #10 Dummy implementation: only single core supported. */
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  const Os_Hal_IntControllerType InterruptControllerId = InterruptConfig->InterruptController;
  const Os_Hal_IntSourceType Source = InterruptConfig->Source;

  /* #10 Return if the interrupt source is enabled in the corresponding controller. */
  return ((OS_HAL_INTC_AVIC_INSTANCE(InterruptControllerId)->VicIntEnable & (1uL << Source)) != 0);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IsMappedInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsMappedInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))
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
  const Os_Hal_IntControllerType InterruptControllerId = InterruptConfig->InterruptController;
  const Os_Hal_IntSourceType Source = InterruptConfig->Source;

  /* #10 Return whether the given interrupt source is pending (VICRAWINTR). */
  return ((OS_HAL_INTC_AVIC_INSTANCE(InterruptControllerId)->VicRawIntr & (1uL << Source)) != 0);
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
  /* #10 Return !0 if LevelX is greater than LevelY. */
  return (Os_StdReturnType)(LevelX < LevelY);
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
  /* #10 Return 0 (clear pending interrupt not supported). */
  return (Os_StdReturnType)(0u);
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
  /* #10 No central interrupt handler for AVIC. Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Address);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsPrivileged);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_IntClearPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_IntClearPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY */
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMLEVELSUPPORT */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
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
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_AVIC_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_AVIC.h
 *********************************************************************************************************************/
