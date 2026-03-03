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
 *  \brief   HAL interface to work with the Vectored Interrupt Controllor (VIC).
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
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_INTERRUPTCONTROLLER_VIC_E3X_H
# define OS_HAL_INTERRUPTCONTROLLER_VIC_E3X_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_Hal_Core_E3.h"

/**********************************************************************************************************************
 *  GLOBAL EXTERN CONST
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/
/*! Define the interrupt controller specific cat2 ISR disable level. */
# define OS_HAL_ISR2_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR2_DISABLE_LEVEL)

/*! Define the interrupt controller specific cat1 ISR disable level. */
# define OS_HAL_ISR1_DISABLE_LEVEL_ABSTRACT                 (OS_CFG_HAL_ISR1_DISABLE_LEVEL)

/*! Define the interrupt controller specific Timing Protection ISR disable level. */
# define OS_HAL_TIMING_PROTECTION_DISABLE_LEVEL_ABSTRACT    (OS_CFG_HAL_TP_DISABLE_LEVEL)

/*! Trigger peripheral interrupt by software supported */
# define OS_HAL_INTC_SWT_SUPPORTED                          (1u)

/*! \brief    Logical interrupt level used for tasks.
 *  \details  The logically lowest interrupt level(a dummy priority of 16 will be used) */
/*            No mask operation will be done, keep the same as after initialization */
# define OS_HAL_TASK_LEVEL                                  (16u)

/*! The interrupt controller supports mutilple priority levels using IRQ. */
# define OS_HAL_INTC_LEVEL_SUPPORTED                        (1u)

/*! Interrupt Vectors Enable Value (SCTLR.VE). */
# define OS_HAL_SCTLR_VE_ENABLE                             ((1uL) << 24)

/*! Interrupt source total number. */
# define OS_HAL_INTC_SOURCE_TOTAL                           256uL

/* ------------------------------------------------------------------------------------------------------------------ */
/* VIC Registers */
/* ------------------------------------------------------------------------------------------------------------------ */
/*! IRQ interrupt status of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_IRQSTATUS_BASE           (0x0uL)

/*! FIQ interrupt status of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_FIQSTATUS_BASE           (0x40uL)

/*! RAW interrupt status of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_RAWTATUS_BASE            (0x80uL)

/*! Interrupt select bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_SELECT_BASE              (0xC0uL)

/*! Interrupt enable bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_ENABLE_BASE              (0x100uL)

/*! Software interrupt trigger bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_SOFT_TRIGGER_BASE        (0x140uL)

/*! Software interrupt mask bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_SOFT_MASK_BASE           (0x180uL)

/*! Interrupt enable clear bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_ENABLE_CLEAR_BASE        (0x1C0uL)

/*! Interrupt clear bit of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_CLEAR_BASE               (0x200uL)

/*! Interrupt softerware priority mask. */
# define OS_HAL_E3X_INTC_VIC_PRIORITY_MASK_BASE       (0x3C8uL)

/*! Interrupt priority register of each interrupt source. */
# define OS_HAL_E3X_INTC_VIC_PRIORITY_BASE            (0x400uL)

/*! Interrupt vector base address register. */
# define OS_HAL_E3X_INTC_VIC_Vector_BASE_ADDRESS_REG  (0xF00uL)

/*! Interrupt vector address register. */
# define OS_HAL_E3X_INTC_VIC_Vector_ADDRESS_REG       (0xF000uL)


/* ------------------------------------------------------------------------------------------------------------------*/
/* VIC generic Macros */
/* ----------------------------------------------------------------------------------------------------------------- */
/*! Get the Pointer to level register(vic softerware priority mask) which representing current core interrupt level */
# define OS_HAL_E3X_GET_LEVEL_REGISTER_ADDRESS(CorePhysicalID)                                                         \
         (*(volatile Os_Hal_IntLevelType*)(                                                                            \
                               Os_Hal_E3_InterruptControllerBaseAddress[CorePhysicalID] +                              \
                               OS_HAL_E3X_INTC_VIC_PRIORITY_MASK_BASE )                                                \
                             )

# define OS_HAL_E3X_INTC_VIC_GET_ADDRESS(Type, IntSrc)                                                                 \
         (*(volatile uint32*)(                                                                                         \
                               Os_Hal_E3_InterruptControllerBaseAddress[Os_Hal_CoreGetId()] +                          \
                               Type +                                                                                  \
                               ((IntSrc / 32uL) * 4uL))                                                                \
                             )

/*! Get the address of the word, which contains the bit of the given interrupt resource, based on a given core id. */
# define OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(CorePhysicalID, Type, IntSrc)                                         \
         (*(volatile uint32*)(                                                                                         \
                               Os_Hal_E3_InterruptControllerBaseAddress[CorePhysicalID] +                              \
                               Type +                                                                                  \
                               ((IntSrc / 32uL) * 4uL))                                                                \
                             )

/*! Get the address of the software mask register,  based on a given core id. */
# define OS_HAL_E3X_INTC_VIC_GET_SOFT_MASK_ADDRESS_WITH_ID(CorePhysicalID, IntSrc)                                     \
         (*(volatile uint32*)(                                                                                         \
                               Os_Hal_E3_InterruptControllerBaseAddress[CorePhysicalID] +                              \
                               OS_HAL_E3X_INTC_VIC_SOFT_MASK_BASE +                                                    \
                               (IntSrc * 4uL))                                                                         \
                             )

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
 *(volatile uint32*)(                                                                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                       Os_Hal_E3_InterruptControllerBaseAddress[InterruptConfig->CoreID] + 
                       OS_HAL_E3X_INTC_VIC_PRIORITY_BASE + 
                       (4uL * (InterruptConfig->Source))
                    )
                    =  InterruptConfig->Level;

  /* #20 Configure interrupt source as FIQ or IRQ. */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID,OS_HAL_E3X_INTC_VIC_SELECT_BASE,                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                          InterruptConfig->Source)
                                          &= (uint32)(~(0x1uL << (InterruptConfig->Source % 32uL)));
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID, OS_HAL_E3X_INTC_VIC_SELECT_BASE,                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                          InterruptConfig->Source)
                                          |=
                                          (uint32)(
                                                    ((~(uint32)(InterruptConfig->Type)) & 0x1uL) 
                                                    << (InterruptConfig->Source % 32uL)
                                                  );

  /* #30 Unmask the interrupt source. */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID, OS_HAL_E3X_INTC_VIC_SOFT_MASK_BASE,                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                          InterruptConfig->Source)
                                          &= (uint32)(~(0x1uL << (InterruptConfig->Source % 32uL)));

}

/***********************************************************************************************************************
 *  Os_Hal_INTC_TriggerCrossCoreInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_TriggerCrossCoreInterrupt,
(
  uint32 CoreID,
  Os_Hal_IntSourceType Source
))                                                                                                                      /* COV_OS_HALARMCROSSCOREUNSUPPORTED */
{
  OS_IGNORE_UNREF_PARAM(CoreID);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Source);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_InitIntVectors,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Core
))
{
  /* #10 Set VE bit in STCLR Register. */
  uint32 IntSrc;
  volatile uint32 systemControl = Os_Hal_GetSystemControl();
  systemControl |= OS_HAL_SCTLR_VE_ENABLE;
  Os_Hal_SetSystemControl(systemControl);
  
  /* #20 Configure the VIC vector addresses. */
  for(IntSrc=0uL; IntSrc<OS_HAL_INTC_SOURCE_TOTAL; IntSrc++)
  {
    *(volatile uint32*)(                                                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                         Os_Hal_E3_InterruptControllerBaseAddress[Os_Hal_CoreGetId()] + 
                         OS_HAL_E3X_INTC_VIC_Vector_ADDRESS_REG + 
                         (4uL*IntSrc)
                       )
                         = (uint32)((*(Core->IrqVectorTable))[IntSrc]);                                                 /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
  }
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

  /* #10 Enable interrupt handling for a given interrupt source(write 0 to this register has no effect). */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptController, OS_HAL_E3X_INTC_VIC_ENABLE_BASE, Source)                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                 = (0x1uL << (Source % 32uL));
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_EnableMappedSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_DisableSource,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig
))
{
  /* #10 Disable interrupt handling for for given interrupt(write 0 to this register has no effect). */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID, OS_HAL_E3X_INTC_VIC_ENABLE_CLEAR_BASE,               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                          InterruptConfig->Source)
                                          = (0x1uL << (InterruptConfig->Source % 32uL));
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
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_SetCurrentLevel,
(
  Os_Hal_IntLevelType Level
))
{
  uint32 PSR_previous = 0uL;
  uint32 Current_CoreId = Os_Hal_CoreGetId();
  uint32 VICSWPRIORITYMASK = 0xFFFFuL;

  /* #10 Save current PSR status and then disable IRQ */
  PSR_previous= Os_Hal_ReadPsr() ;
  Os_Hal_WritePsr(Os_Hal_ReadPsr() | (OS_HAL_PSR_INTERRUPTS_MASKED ));

  /* #20 Set value for vic softerware priority mask register(level register) */
  OS_HAL_E3X_GET_LEVEL_REGISTER_ADDRESS(Current_CoreId) = VICSWPRIORITYMASK >> (16uL - Level);                          /* PRQA S 0303, 2791 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule12.2_2791_E3_LevelRange */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */

  /* #30 Restore the saved PSR IRQ status */
  Os_Hal_WritePsr((Os_Hal_ReadPsr() & (~OS_HAL_PSR_INTERRUPTS_MASKED)) | (PSR_previous & OS_HAL_PSR_INTERRUPTS_MASKED));
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
  Os_Hal_IntLevelType Level
))
{
  /* #10 Set current level for exception handling */
  Os_Hal_INTC_SetCurrentLevel(Level);
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_IntLevelType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_INTC_GetCurrentLevel,
(
  void
))
{
  Os_Hal_IntLevelType Level_Get;
  uint32 VICSWPRIORITYMASK_Get;
  /* #10 Get the value from vic softerware priority mask register(level register) */
  VICSWPRIORITYMASK_Get = OS_HAL_E3X_GET_LEVEL_REGISTER_ADDRESS(Os_Hal_CoreGetId());                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ 

  /* #20 Calculate the current level from the priority mask value and retrun */
  Level_Get = 32uL - Os_Hal_CLZ(VICSWPRIORITYMASK_Get);
  return  Level_Get;
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
  /* #10 Return the level from Os_Hal_INTC_GetCurrentLevel */
  return Os_Hal_INTC_GetCurrentLevel();
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

  *(volatile uint32*)(                                                                                                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                       Os_Hal_E3_InterruptControllerBaseAddress[Os_Hal_CoreGetId()] +
                       OS_HAL_E3X_INTC_VIC_Vector_BASE_ADDRESS_REG
                     ) 
                     = (uint32)(0xFF);
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
  /* #10 Trigger interrupt via software for a given interrupt source(write 0 to this register has no effect). */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptController, OS_HAL_E3X_INTC_VIC_SOFT_TRIGGER_BASE, Source)           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                 = (0x1uL << (Source % 32uL));
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
  return (Os_StdReturnType)
              (
                (OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID, OS_HAL_E3X_INTC_VIC_ENABLE_BASE,      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
                                                         InterruptConfig->Source))
                &
                (1uL << (InterruptConfig->Source % 32uL))
              );
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IsMappedInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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
  return (Os_StdReturnType)(0u);
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
))
{
  OS_IGNORE_UNREF_PARAM(SenderCoreID);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Clear pending state of given interrupt source(write 0 to this register has no effect). */
  OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptController, OS_HAL_E3X_INTC_VIC_CLEAR_BASE, Source)                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
                                 = (0x1uL << (Source % 32uL));
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntClearPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
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
  return (Os_StdReturnType)
              (
                (OS_HAL_E3X_INTC_VIC_GET_ADDRESS_WITH_ID(InterruptConfig->CoreID, OS_HAL_E3X_INTC_VIC_RAWTATUS_BASE,    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
                                                         InterruptConfig->Source))
                &
                (1uL << (InterruptConfig->Source % 32uL))
              );
}

/***********************************************************************************************************************
 *  Os_Hal_INTC_IntIsInterruptPendingMapped()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_INTC_IntIsInterruptPendingMapped,
(
  P2CONST(Os_Hal_IntIsrConfigType, AUTOMATIC, OS_APPL_DATA) InterruptConfig,
  P2CONST(Os_Hal_IntIsrMapConfigType, AUTOMATIC, OS_APPL_DATA) IsrMapConfig
))                                                                                                                      /* COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY */
{
  OS_IGNORE_UNREF_PARAM(InterruptConfig);                                                                               /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  return (Os_StdReturnType)(0u);
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
  return (Os_StdReturnType)(LevelX < LevelY);                                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
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
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
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
  OS_IGNORE_UNREF_PARAM(IsrConfig);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(IsrMapConfig);                                                                                 /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* OS_HAL_INTERRUPTCONTROLLER_VIC_E3X_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_VIC_E3x.h
 *********************************************************************************************************************/

