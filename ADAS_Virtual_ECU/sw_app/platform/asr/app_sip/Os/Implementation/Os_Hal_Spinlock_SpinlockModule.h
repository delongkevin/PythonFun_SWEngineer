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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Spinlock  HAL Spinlock mechanism
 *  \brief      Implements Spinlocks by using a hardware peripheral spinlock module
 *  \details
 *  \{
 *
 *  \file       Os_Hal_Spinlock_SpinlockModule.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_SPINLOCK_SPINLOCKMODULE_H
# define OS_HAL_SPINLOCK_SPINLOCKMODULE_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Core_Types.h"

/* Os kernel module dependencies */
# include "Os_CommonInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define OS_HAL_SPINLOCK_LOCK_REG_ADDRESS(x)   (OS_HAL_SPINLOCK_HW_BASEADDRESS + 0x800uL + ((x)*4uL))
# define OS_HAL_SPINLOCK_IS_NOT_TAKEN          0uL

/* spinlock number used by OS */
# define OS_HAL_SPINLOCK_GLOBAL_LOCK           0uL


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
 *  Os_Hal_SpinInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinInit,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  /* #10 Release the global lock. */
  *(volatile uint32*)(OS_HAL_SPINLOCK_LOCK_REG_ADDRESS(OS_HAL_SPINLOCK_GLOBAL_LOCK)) = OS_HAL_SPINLOCK_IS_NOT_TAKEN;    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
  /* #20 Set given spinlock to OS_HAL_SPINLOCK_FREE. */
  *Spinlock = OS_HAL_SPINLOCK_FREE;                                                                                     /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_SpinTryLock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                             /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinTryLock,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  Os_Hal_SpinlockResultType result = !(OS_HAL_SPINLOCKSUCCEEDED);                                                         /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  uint32 state;

  /* Disable global interrupt handling and store prior state */
  state = Os_Hal_DisableAndReturnPriorState();

  /* Acquire a global lock from HW spinlock module */
  if(*(volatile uint32*)(OS_HAL_SPINLOCK_LOCK_REG_ADDRESS(OS_HAL_SPINLOCK_GLOBAL_LOCK)) == OS_HAL_SPINLOCK_IS_NOT_TAKEN)  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* COV_OS_HALPPCSEMA4GLOBALLOCK */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  {
     if(*Spinlock == OS_HAL_SPINLOCK_FREE)
     {
        /* Lock the SW spinlock variable */
        *Spinlock = OS_HAL_SPINLOCK_LOCKED;                                                                               /* SBSW_OS_HAL_PWA_CALLER */

        /* Set the result to succeeded */
        result = OS_HAL_SPINLOCKSUCCEEDED;
     }

     /* Release the global lock */
     *(volatile uint32*)(OS_HAL_SPINLOCK_LOCK_REG_ADDRESS(OS_HAL_SPINLOCK_GLOBAL_LOCK)) = OS_HAL_SPINLOCK_IS_NOT_TAKEN;   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  }

  /* Restore global interrupt state */
  Os_Hal_RestorePriorIntState(state);                                                                                     /* SBSW_OS_HAL_FC_CALLER */

  return result;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                            /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_SPINLOCK_SPINLOCKMODULE_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Spinlock_SpinlockModule.h
 **********************************************************************************************************************/
