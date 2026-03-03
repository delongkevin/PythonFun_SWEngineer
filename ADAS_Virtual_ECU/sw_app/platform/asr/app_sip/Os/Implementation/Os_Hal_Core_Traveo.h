/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain wi:wth Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Hal_Core
 * \{
 *
 *  \file       Os_Hal_Core_Traveo.h
 *  \brief      Core related primitives specific to Spansion Traveo derivative family.
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

#ifndef  OS_HAL_CORE_TRAVEO_H
# define OS_HAL_CORE_TRAVEO_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Core_OneProcessorGroup.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! Traveo BootROM: Base address. */
# define OS_HAL_BOOTROM_BASE            (0xFFFEFC00uL)

/*! Traveo BootROM: UNLOCK register. */
# define OS_HAL_BOOTROM_UNLOCK          (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x358uL))

/*! Traveo BootROM: CNFG register. */
# define OS_HAL_BOOTROM_CNFG            (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x360uL))

/*! Traveo BootROM: UNDEFINACT register. */
# define OS_HAL_BOOTROM_UNDEFINACT      (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x384uL))

/*! Traveo BootROM: SVCINACT register. */
# define OS_HAL_BOOTROM_SVCINACT        (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x388uL))

/*! Traveo BootROM: PABORTINACT register. */
# define OS_HAL_BOOTROM_PABORTINACT     (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x38CuL))

/*! Traveo BootROM: DABORTINACT register. */
# define OS_HAL_BOOTROM_DABORTINACT     (*(volatile uint32*) (OS_HAL_BOOTROM_BASE + 0x390uL))


/*! Traveo BootROM: Unlock key value. */
# define OS_HAL_BOOTROM_KEY_UNLOCK      (0xACC5B007uL)

/*! Traveo BootROM: Lock key value. */
# define OS_HAL_BOOTROM_KEY_LOCK        (0xB007ECF6uL)


/*! Traveo BootROM: CNFG register bit mask: locked flag. */
# define OS_HAL_BOOTROM_CNFG_LOCKED     (1uL << 0)

/*! Traveo BootROM: CNFG register bit mask: switch set flag. */
# define OS_HAL_BOOTROM_CNFG_SWITCH_SET (1uL << 8)



/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


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
 *  Os_Hal_Core_InitExceptions()
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
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Core_InitExceptions,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
))
{
  Os_Hal_IntGlobalStateType state;

  /* #10 Disable interrupts and save old interrupt state. */
  state = Os_Hal_DisableAndReturnPriorState();

  /* #20 Unlock BootROM. */
  OS_HAL_BOOTROM_UNLOCK = OS_HAL_BOOTROM_KEY_UNLOCK;                                                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_LOCK */

  /* #30 Wait until unlock was completed. */
  while((OS_HAL_BOOTROM_CNFG & OS_HAL_BOOTROM_CNFG_LOCKED) != 0u)                                                       /* COV_OS_HALPLATFORMINVSTATE */ /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* FETA_OS_HAL_ARM_TRAVEOBOOTROMINIT */
  {
    ;
  }

  /* #40 Set exception vectors. */
  OS_HAL_BOOTROM_UNDEFINACT  = (uint32)Config->ExceptionTable[1];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_EXCEPTION */
  OS_HAL_BOOTROM_SVCINACT    = (uint32)Config->ExceptionTable[2];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_EXCEPTION */
  OS_HAL_BOOTROM_PABORTINACT = (uint32)Config->ExceptionTable[3];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_EXCEPTION */
  OS_HAL_BOOTROM_DABORTINACT = (uint32)Config->ExceptionTable[4];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_EXCEPTION */

  /* #50 Set BootROM switch flag. */
  OS_HAL_BOOTROM_CNFG = OS_HAL_BOOTROM_CNFG_SWITCH_SET;                                                                 /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_CNFG */

  /* #60 Lock BootROM. */
  OS_HAL_BOOTROM_UNLOCK = OS_HAL_BOOTROM_KEY_LOCK;                                                                      /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_LOCK */

  /* #70 Restore old interrupt state. */
  Os_Hal_RestorePriorIntState(state);
}


/***********************************************************************************************************************
 *  Os_Hal_Core_InitStackProtectionRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Core_InitStackProtectionRegions,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
))
{
  /* #10 Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Config);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreIsThreadPointerUserReadable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreIsThreadPointerUserReadable,
(
  void
))
{
  /* #10 Return readable in user mode. */
  return (Os_StdReturnType)(1u);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_HAL_CORE_TRAVEO_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_Traveo.h
 **********************************************************************************************************************/

