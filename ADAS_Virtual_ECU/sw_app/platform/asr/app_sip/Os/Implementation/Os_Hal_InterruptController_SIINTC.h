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
 *  \file    Os_Hal_InterruptController_SIINTC.h
 *  \brief   HAL interface to work with the Toshiba Interrupt Controller for Safe Island on TMPV770x derivatives.
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

#if !defined(OS_HAL_INTERRUPTCONTROLLER_SIINTC_H)
# define OS_HAL_INTERRUPTCONTROLLER_SIINTC_H
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
# define OS_HAL_TASK_LEVEL                                  (0x0u)

/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR2_DISABLE_LEVEL)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR1_DISABLE_LEVEL)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_CFG_HAL_TP_DISABLE_LEVEL)

/*! Trigger peripheral interrupt by software supported */
# define OS_HAL_INTC_SWT_SUPPORTED                          0u

/*! The interrupt controller supports priority level handling. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        1u

/*! Interrupt Vectors Enable Value (SCTLR.VE). */
# define OS_HAL_SCTLR_VE_ENABLE                             1uL << 24

/*! Interrupt priority mask (SIINTC.IR.EXTx). */
# define OS_HAL_INTC_SIINTC_IR_PRIORITY_MSK                 0xFuL

/*! Interrupt priority value to disable the interrupt (SIINTC.IR.EXTx). */
# define OS_HAL_INTC_SIINTC_IR_DISABLE                      0x0uL

/*! Interrupt level/edge detection mask (SIINTC.IR.EIMx). */
# define OS_HAL_INTC_SIINTC_IR_DETECTION_MSK                0xF0u

/*! Interrupt level/edge detection mask (SIINTC.IR.EXTx). */
# define OS_HAL_INTC_SIINTC_IR_LEVEL_MSK                          0x0Fu

/*! Value to configure the interrupt level detection high (SIINTC.IR.EIMx). */
# define OS_HAL_INTC_SIINTC_IR_LEVEL_DETECTION              1u << 5

/*! Priority value to disable the interrupt (SIINTC.ICLR.IV). */
# define OS_HAL_INTC_SIINTC_ICLR_IV_OFFSET                  0x2uL

/*! Bit mask for the current priority threshold  (SIINTC.ILEV1.CMASK). */
# define OS_HAL_INTC_SIINTC_ILEV1_CMASK_MSK                 0xFuL

/*! Bit offset of the MLEV field.  (SIINTC.ILEV1.MLEV). */
# define OS_HAL_INTC_SIINTC_MLEV_BIT                        31uL

/*! Value to be written in ILEV1 Register at the end of interrupt processing. */
# define OS_HAL_INTC_SIINTC_ILEV1_EOI                       0x0uL

/*! Value to be written in INT_SET_R00D01x Register to trigger an inter processor interrupt. */
# define OS_HAL_INTC_SICOMM_SET_R00DX_INTSICOMMCH0          0x1uL

/*! Maximum interrupt source value for software interrupts. */
# define OS_HAL_INTC_SIINTC_MAX_SWI                         15uL

/*! Minimum interrupt source value for software interrupts. */
# define OS_HAL_INTC_SIINTC_MIN_SWI                         8uL

/*! Access the interrupt controller registers (SIINTC0).  */
# define OS_HAL_INTC_SIINTC0           ((volatile Os_Hal_IntcSiintcType *)OS_HAL_INTC_SIINTC_CORE_BASE)

/*! Access the interrupt set register of the corresponding core (SICOMM.INT_SET_R00D0x).  */
# define OS_HAL_INTC_SICOMM_SET_R0D    *((volatile uint32 *)(OS_HAL_INTC_SIINTC_SICOMM_BASE + 0x1000uL))

/*! Access the clear pending interrupt of the corresponding core (SICOMM.INT_CLR_R00D0x).  */
# define OS_HAL_INTC_SICOMM_CLR_R0D    *((volatile uint32 *)(OS_HAL_INTC_SIINTC_SICOMM_BASE + 0x3000uL))

/*! Toshiba SI interrupt controller index. */
# define OS_HAL_INTC_SIINTC_ID                              0x0uL

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! Macro to get the software interrupt index out of the interrupt source number.
 *  \details  The software triggered interrupt sources are in the interval [8...15]. */
# define OS_HAL_INTC_SIINTC_SOURCE2SICOMM_INT(x)          (x % 0x8uL)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! SIINTC register map. */
typedef struct
{
  uint8 Ir[OS_HAL_INTC_NUMBER_OF_IRQS];     /*!< Offset: 0x00       Interrupt Setting Register (IRx). */
  uint32 Iclr;                              /*!< Offset: 0x100      Interrupt Clear Register (ICLR). */
  uint32 Ilev1;                             /*!< Offset: 0x104      Interrupt Level Register 1 (ILEV1). */
  uint32 Ilev2;                             /*!< Offset: 0x108      Interrupt Level Register 2 (ILEV2). */
  uint32 Reserved0[29];                      /*!< Offset: 0x10C      Reserved. */
  uint32 Irrest[8];                         /*!< Offset: 0x180      Interrupt Request Status Register (IRRESTx). */
  uint32 Cint;                              /*!< Offset: 0x1A0      Current Interrupt Request Number Register (CINT).*/
  uint32 Reserved1[23];                      /*!< Offset: 0x1A4      Reserved. */
  uint32 IsrAddr[OS_HAL_INTC_NUMBER_OF_IRQS];    /*!< Offset: 0x200 ISR Start Address Register (ISRxADDR). */
  uint32 Reserved2[2];                       /*!< Offset: 0x600      Reserved. */
  uint32 Alclr;                             /*!< Offset: 0x608      Fault Flag Clear Register (AL_CLR). */
  uint32 Reserved3[4];                       /*!< Offset: 0x60C      Reserved. */
  uint32 Flgalarm;                          /*!< Offset: 0x61C      ECC Alarm Flag Register (FLG_ALARM). */
  uint32 Reserved4[631];                     /*!< Offset: 0x620      Reserved. */
  uint32 Wperr;                             /*!< Offset: 0xFFC      Write Protection Access Alarm Flag Clear Register.*/
} Os_Hal_IntcSiintcType;




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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  /* #10 Set VE bit in STCLR Register. */
  uint32 i;
  volatile uint32 systemControl = Os_Hal_GetSystemControl();
  systemControl |= OS_HAL_SCTLR_VE_ENABLE;
  Os_Hal_SetSystemControl(systemControl);

  /* #20 For each available interrupt source. */
  for(i = 0; i < OS_HAL_INTC_NUMBER_OF_IRQS; i++)
  {
    /* #30 Set ISRxADDR to the configured handler function address. */
    OS_HAL_INTC_SIINTC0->IsrAddr[i] = (uint32)(Core->IrqVectorTable[OS_HAL_INTC_SIINTC_ID][i]);                         /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_AWA_SIINTC0 */
  }

  /* #40 Execute data sync barrier instruction. */
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
   volatile uint8 detectionValue = OS_HAL_INTC_SIINTC0->Ir[InterruptConfig->Source] &                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
       OS_HAL_INTC_SIINTC_IR_LEVEL_MSK;

   /* #10 Set the interrupt edge detection. */
  OS_HAL_INTC_SIINTC0->Ir[InterruptConfig->Source] =                                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_AWA_SIINTC0 */
      (uint8)(OS_HAL_INTC_SIINTC_IR_LEVEL_DETECTION)  | detectionValue;

  /* #20 Execute data sync barrier instruction. */
  Os_Hal_DataSyncBarrier();
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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
  volatile uint8 detectionValue = OS_HAL_INTC_SIINTC0->Ir[Source] & OS_HAL_INTC_SIINTC_IR_DETECTION_MSK;                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */

  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Enable given interrupt source by writing the configured level to IRx register. */
  OS_HAL_INTC_SIINTC0->Ir[Source] = (uint8)(Level) | detectionValue;                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_AWA_SIINTC0 */

  /* #20 Execute data sync barrier instruction. */
  Os_Hal_DataSyncBarrier();
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  volatile uint8 detectionValue = OS_HAL_INTC_SIINTC0->Ir[InterruptConfig->Source] &                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
      OS_HAL_INTC_SIINTC_IR_DETECTION_MSK;

  /* #10 Disable given interrupt source by writing the level 0 to IRx register. */
  OS_HAL_INTC_SIINTC0->Ir[InterruptConfig->Source] = (uint8)OS_HAL_INTC_SIINTC_IR_DISABLE | detectionValue;             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_AWA_SIINTC0 */

  /* #20 Execute data sync barrier instruction. */
  Os_Hal_DataSyncBarrier();
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))
{
  Os_Hal_IntGlobalStateType state;

  /* #10 Disable interrupts and save interrupt state. */
  state = Os_Hal_DisableAndReturnPriorState();

  /* #20 Set interrupt priority mask register to given level. */
  OS_HAL_INTC_SIINTC0->Ilev1 = (Level | (1UL << OS_HAL_INTC_SIINTC_MLEV_BIT));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SIINTC0 */

  /* #30 Perform data synchronization barrier. */
  Os_Hal_DataSyncBarrier();

  /* #40 Restore interrupt state. */
  Os_Hal_RestorePriorIntState(state);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_SetCurrentLevelException()
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
Os_Hal_INTC_SetCurrentLevelException,
(
  Os_Hal_IntLevelType Level
))
{
  Os_Hal_IntGlobalStateType state;

  /* #10 Disable interrupts and save interrupt state. */
  state = Os_Hal_DisableAndReturnPriorState();

  /* #20 Set interrupt priority mask register to given level. */
  OS_HAL_INTC_SIINTC0->Ilev1 = (Level | (1UL << OS_HAL_INTC_SIINTC_MLEV_BIT));                                          /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SIINTC0 */

  /* #30 Perform data synchronization barrier. */
  Os_Hal_DataSyncBarrier();

  /* #40 Restore interrupt state. */
  Os_Hal_RestorePriorIntState(state);
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_GetCurrentLevel,
(
  void
))
{
  /* #10 Return current value of interrupt priority mask register. */
  return OS_HAL_INTC_SIINTC0->Ilev1 & OS_HAL_INTC_SIINTC_ILEV1_CMASK_MSK;                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


/***********************************************************************************************************************
 *  Os_Hal_INTC_GetCurrentLevelException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_GetCurrentLevelException,
(
  void
))
{
  /* #10 Return current value of interrupt priority mask register. */
  return OS_HAL_INTC_SIINTC0->Ilev1 & OS_HAL_INTC_SIINTC_ILEV1_CMASK_MSK;                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_ClearPending,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntIsrSenderCoreID SenderCoreID,
  Os_Hal_IntControllerType InterruptController
))
{
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  if ((Source <= OS_HAL_INTC_SIINTC_MAX_SWI) && (Source >= OS_HAL_INTC_SIINTC_MIN_SWI))
  {
    /* #10 If it is a software interrupt, reset it. */
    OS_HAL_INTC_SICOMM_CLR_R0D = (1uL << (uint32)OS_HAL_INTC_SIINTC_SOURCE2SICOMM_INT(Source));                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SICOMM */
  }

  /* #20 Clear interrupt pending flag. */
  OS_HAL_INTC_SIINTC0->Iclr = Source << OS_HAL_INTC_SIINTC_ICLR_IV_OFFSET;                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SIINTC0 */
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
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Clear pending interrupt. */
  OS_HAL_INTC_SIINTC0->Iclr = Source << OS_HAL_INTC_SIINTC_ICLR_IV_OFFSET;                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_SIINTC0 */

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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerPeripheralInterrupt,
(
  Os_Hal_IntSourceType Source,
  Os_Hal_IntControllerType InterruptController
))                                                                                                                      /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */
{
  /* #10 Nothing to be done here. Not supported by hardware. */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(InterruptController);                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptSourceEnabled,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Return whether given interrupt source is enabled by inspecting the corresponding bit
   *     in the Interrupt Setting Registers (IRn). */
  return (Os_StdReturnType)(OS_HAL_INTC_SIINTC0->Ir[InterruptConfig->Source] & OS_HAL_INTC_SIINTC_IR_PRIORITY_MSK);    /* PRQA S 0303  */ /* MD_Os_Hal_Rule11.4_0303 */
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
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IsInterruptPending,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Return whether the given interrupt source is pending by reading the corresponding bit
   *     in the Interrupt Request Status Registers (IRRESTx). */
  return (Os_StdReturnType)((OS_HAL_INTC_SIINTC0->Irrest[InterruptConfig->Source/32u] &                                 /* PRQA S 0303, 4304 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_C90BooleanCompatibility */
    (1uL << (InterruptConfig->Source%32u))) != 0u);
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
  return (Os_StdReturnType)(LevelX > LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
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
  /* #10 No central interrupt handler for SIINTC. Nothing to do here. */
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
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_SIINTC_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_SIINTC.h
 *********************************************************************************************************************/
