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
 *  \brief      Implements Spinlocks by using a hardware semaphore feature in mailbox module
 *  \details
 *  \{
 *
 *  \file       Os_Hal_Spinlock_Mailbox.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_SPINLOCK_MAILBOX_H
# define OS_HAL_SPINLOCK_MAILBOX_H
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
/*! Semaphore Gate Register in Mailbox module */
# define OS_HAL_MB_SEMAG_REG(x)       (*(volatile uint32 *)(OS_HAL_MAILBOX_BASE_ADDRESS + 0x200uL + ((x)*8uL)))
/*! Semaphore Gate Reset Register in Mailbox module */
# define OS_HAL_MB_SGR_REG            (*(volatile uint32 *)(OS_HAL_MAILBOX_BASE_ADDRESS + 0x400uL))

/*! Semaphore Gate Control Bit, set SGC bit to request lock of a semaphore gate, clear SGC bit to unlock this gate */
# define OS_HAL_MB_SEMAG_SGC          0x1uL
/*! Semaphore Gate Lock Status, read SGLS to check if semaphore gate is successfully locked.
 *  Each bit in SGLS[7:0] indicates which processor has locked this semaphore gates */
# define OS_HAL_MB_SEMAG_SGLS_MASK    (0x1uL << (Os_Hal_CoreGetId() + 16u))
/*! Global Semaphore Gate Reset Enable Bit */
# define OS_HAL_MB_SGR_GSGRE          (0x1uL << 24u)
/*! Global Semaphore Gate Reset Bit, Write 1 to all the 8 GSRG bits will reset all the semaphore gates */
# define OS_HAL_MB_SGR_GSGR           (0xFFuL << 16u)
/*! hardware semaphore gate number used by OS */
# define OS_HAL_SEMAPHORE_GATE        0uL


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
  /* #10 Reset Global Semaphore Gate. */
  OS_HAL_MB_SGR_REG = (OS_HAL_MB_SGR_GSGRE | OS_HAL_MB_SGR_GSGR);

  /* #20 Set given spinlock to OS_HAL_SPINLOCK_FREE. */
  *Spinlock = OS_HAL_SPINLOCK_FREE;                                                                                     /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_SpinTryLock()
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
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinTryLock,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  Os_Hal_SpinlockResultType result = !(OS_HAL_SPINLOCKSUCCEEDED);                                                       /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  uint32 state;

  /* #10 Disable global interrupt handling and store prior state */
  state = Os_Hal_DisableAndReturnPriorState();

  /* #20 Acquire a semaphore gate lock */
  OS_HAL_MB_SEMAG_REG(OS_HAL_SEMAPHORE_GATE) = OS_HAL_MB_SEMAG_SGC;

  /* #30 Check if semaphore gate is locked by current processor */
  if((OS_HAL_MB_SEMAG_REG(OS_HAL_SEMAPHORE_GATE) & OS_HAL_MB_SEMAG_SGLS_MASK) != 0u)                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* COV_OS_HALPPCSEMA4GLOBALLOCK */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  {
    /* #40 Check if spinlock is free */
    if(*Spinlock == OS_HAL_SPINLOCK_FREE)
    {
      /* #50 Lock the SW spinlock variable */
      *Spinlock = OS_HAL_SPINLOCK_LOCKED;                                                                               /* SBSW_OS_HAL_PWA_CALLER */

      /* #60 Set the result to succeeded */
      result = OS_HAL_SPINLOCKSUCCEEDED;
    }
    /* #70 Release the semaphore gate */
    OS_HAL_MB_SEMAG_REG(OS_HAL_SEMAPHORE_GATE) = 0uL;                                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PERIPHERAL_ACCESS */
  }
  /* #80 Restore global interrupt state */
  Os_Hal_RestorePriorIntState(state);                                                                                   /* SBSW_OS_HAL_FC_CALLER */

  return result;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_SPINLOCK_MAILBOX_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Spinlock_Mailbox.h
 **********************************************************************************************************************/
