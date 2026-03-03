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

#ifndef  OS_HAL_INTERRUPTCONTROLLER_VIM_GENERAL_H
# define OS_HAL_INTERRUPTCONTROLLER_VIM_GENERAL_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_HAL_PSR_INTERRUPTS_MASKED)

/*! Trigger peripheral interrupt by software supported*/
# define OS_HAL_INTC_SWT_SUPPORTED                          0u

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level. */
# define OS_HAL_TASK_LEVEL                                  (0u)

/*! The interrupt controller does not support priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        0u

/*! VIM interrupt controller index. */
# define OS_HAL_INTC_VIM_ID                                 0x0uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! VIM interrupt handler address for each channel. */
# define OS_HAL_INTC_VIM_CHANNEL_HANDLER(x)  (*(volatile uint32*)(OS_HAL_INTC_VIM_RAM_BASE + ((x) * 4uL)))

/*! VIM FIQ/IRQ program control registers. */
# define OS_HAL_INTC_VIM_FIRQPR(x) (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x10uL + (((x) / 32uL) * 4uL)))

/*! VIM channel enable set registers. */
# define OS_HAL_INTC_VIM_REQENASET(x) (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x30uL + (((x) / 32uL) * 4uL)))

/*! VIM channel enable clear registers. */
# define OS_HAL_INTC_VIM_REQENACLR(x) (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x40uL + (((x) / 32uL) * 4uL)))

/*! VIM channel pending registers. */
# define OS_HAL_INTC_VIM_INTREQ(x) (*(volatile uint32*)(OS_HAL_INTC_VIM_CTRL_BASE + 0x20uL + (((x) / 32uL) * 4uL)))


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern CONSTP2CONST(VIMChannel, OS_CONST, OS_CONST) OsCfg_Hal_SourceToChannelTableRefs[];                              /* PRQA S 3684 */ /* MD_Os_Rule8.11_3684_LinkerSymbol */


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


  /* #10 Get current IRQ bits from CPSR. */
  psr = Os_Hal_ReadPsr();
  previousGlobalState = (psr & OS_HAL_PSR_INTERRUPTS_MASKED);

  /* #20 Set IRQ of CPSR (global interrupt disable). */
  Os_Hal_WritePsr(psr | OS_HAL_PSR_INTERRUPTS_MASKED);

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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  uint16_least i;

  /* #10 For each physically available external interrupt source, except the phantom vector (the first one): */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_IRQS; i++)
  {
    /* #20 Set IRQVA to configured handler function address. */
    OS_HAL_INTC_VIM_CHANNEL_HANDLER(i + 1uL) = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_VIM_ID][i]);                   /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_VIMCHANNELHANDLER */
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
  const uint8 channel = OsCfg_Hal_SourceToChannelTableRefs[Os_Hal_CoreGetId()][(uint8)Source];
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable interrupt handling for given interrupt source. */
  OS_HAL_INTC_VIM_REQENASET(channel) = (1uL << (channel % 32uL));                                                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_VIMREQENASET */
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  Os_Hal_IntSourceType source;
  uint8 channel;

  source = InterruptConfig->Source;
  channel = OsCfg_Hal_SourceToChannelTableRefs[Os_Hal_CoreGetId()][(uint8)source];

  /* #10 Enable interrupt handling for given interrupt source. */
  OS_HAL_INTC_VIM_REQENACLR(channel) = (1uL << (channel % 32uL));                                                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_VIMREQENACLR */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  /* #10 Ignore the passed level, as the hardware does not support interrupt level switching */
  OS_IGNORE_UNREF_PARAM(Level);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  /* #10 Return always 0 as the hardware does not support interrupt level switching. */

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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
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
  /* #10 Nothing to do. */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
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

  /* #10 Return enable setting of given interrupt source. */
  const uint8 channel = OsCfg_Hal_SourceToChannelTableRefs[Os_Hal_CoreGetId()][(uint8)InterruptConfig->Source];
  return (Os_StdReturnType)((OS_HAL_INTC_VIM_REQENASET(channel) & (1uL << (channel % 32uL))) != 0u);                    /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMLEVELSUPPORT */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))                                                                                                                      /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  /* #10 Return pending state of given interrupt source. */
  const uint8 channel = OsCfg_Hal_SourceToChannelTableRefs[Os_Hal_CoreGetId()][(uint8)InterruptConfig->Source];
  return (Os_StdReturnType)((OS_HAL_INTC_VIM_INTREQ(channel) & (1uL << (channel % 32uL))) != 0u);                       /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
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
  /* #10 Return 0 (clear pending is not possible). */
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
  /* #10 Return !0 if LevelX is smaller than LevelY. */
  return (Os_StdReturnType)(LevelX > LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
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
  /* #10 Using the Hardware VectoredInterrupts mode. Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Address);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsPrivileged);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
))                                                                                                                      /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */
{
  /* #10 Nothing to be done here. Not supported by VIM. */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  return (Os_StdReturnType)(0u);
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

#endif /* OS_HAL_INTERRUPTCONTROLLER_VIM_GENERAL_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_VIM_General.h
 *********************************************************************************************************************/

