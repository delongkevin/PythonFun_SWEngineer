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
 * \addtogroup  Os_Hal_Core
 * \{
 *
 * \file
 * \brief   Core and multi-core related primitives.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_CORE_H
# define OS_HAL_CORE_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_CoreInt.h"
# include "Os_Hal_Interrupt.h"
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Context.h"
# include "Os_Hal_Derivative.h"

# if defined(OS_HAL_EXCEPTIONS_V7A)                                                                                     /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Core_v7a.h"
# elif defined(OS_HAL_EXCEPTIONS_V7R)                                                                                   /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Core_v7r.h"
# elif defined(OS_HAL_EXCEPTIONS_V8R)                                                                                   /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Core_v8r.h"
# elif defined(OS_HAL_EXCEPTIONS_XAVIER)                                                                                /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Core_Xavier.h"
# elif defined(OS_HAL_EXCEPTIONS_TRAVEO)                                                                                /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Core_Traveo.h"
# else
#  error "Undefined or unsupported exception type"
# endif

# if defined(OS_CFG_DERIVATIVEGROUP_ZUXXX_A53)                                                                          /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_CoreStart_ZUxxx_A53.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_ZUXXX)                                                                            /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_CoreStart_ZUxxx.h"
# elif defined(OS_HAL_E3XXX_MULTICORE)                                                                                  /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_CoreStart_E3.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_G9X)                                                                              /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_CoreStart_G9x.h"
# else
#  include "Os_Hal_CoreStart_Empty.h"
# endif

/* Select the platform specific Spinlock module */
# if defined(OS_CFG_DERIVATIVEGROUP_JACINTO7) || defined(OS_CFG_DERIVATIVEGROUP_AM26XX)                                 /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Spinlock_SpinlockModule.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_G9X)                                                                              /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_Spinlock_Mailbox.h"
# else
#  include "Os_Hal_Spinlock_StrexLdrex.h"
# endif

/* Select the platform specific X-Signals module */
# if defined(OS_CFG_DERIVATIVEGROUP_JACINTO7)                                                                           /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_Jacinto7.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_AM26XX)                                                                           /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_AM26xx.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXR52)                                                                /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_GenericCortexR52.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_SR6XX)                                                                            /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_GenericCortexR52.h"
# elif defined(OS_HAL_E3XXX_MULTICORE)                                                                                  /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_E3x.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARV4H)                                                                          /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_RCARV4H.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_G9X)                                                                              /* COV_OS_DERIVATIVEBETAMODULE */
#  include "Os_Hal_XSignals_G9x.h"
# else
#  include "Os_Hal_XSignals_Dummy.h"
# endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


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
 *  Os_Hal_CoreIsCoreIdUserReadable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMCOREIDUSERREADABLE */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreIsCoreIdUserReadable,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMCOREIDUSERREADABLE */
{
  /* #10 Core ID is not readable in user mode. */
  return 0;
}


/***********************************************************************************************************************
 *  Os_Hal_CoreSetThread()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_CoreSetThread,
(
  P2CONST(Os_Hal_Core2ThreadConfigType, AUTOMATIC, OS_CONST) Core2Thread,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Set thread pointer in special purpose register. */
  OS_IGNORE_UNREF_PARAM(Core2Thread);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  Os_Hal_SetThreadIdRegister((uint32)Thread);                                                                           /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreGetThread()
 **********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_CoreGetThread,
(
  P2CONST(Os_Hal_Core2ThreadConfigType, AUTOMATIC, OS_CONST) Core2Thread
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) threadConfig;

  /* #10 Return thread pointer from special purpose register. */
  threadConfig = (P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST))Os_Hal_GetThreadIdRegister();                       /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  OS_IGNORE_UNREF_PARAM(Core2Thread);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  return threadConfig;
}


/***********************************************************************************************************************
 *  Os_Hal_CoreIsPrivilegedModeUserReadable()
 **********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreIsPrivilegedModeUserReadable,
(
  void
))
{
  /* #10 Return 0 (Privileges not readable in user mode). */
  return 0;
}


/***********************************************************************************************************************
 *  Os_Hal_CoreGetPrivilegedMode()
 **********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreGetPrivilegedMode,
(
  void
))                                                                                                                      /* COV_OS_HALPRIVILEGEMODEUSERREADABILITY_XX */
{
  /*! Internal comment removed.
 *
 *
   */
  /* #10 Return !0 (Api must only be called in privileged mode). */
  return (Os_StdReturnType)(1u);
}


/***********************************************************************************************************************
 *  Os_Hal_CountLeadingZeros()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CountLeadingZeros,
(
  Os_Hal_BitFieldType BitField
))
{
  /* #10 Execute CLZ instruction. */
  return (uint8)Os_Hal_CLZ(BitField);
}


/***********************************************************************************************************************
 *  Os_Hal_StackEndGet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackEndGet,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) LowAddress,
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) HighAddress
))
{
  OS_IGNORE_UNREF_PARAM(HighAddress);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Return LowAddress. */
  return LowAddress;
}


/***********************************************************************************************************************
 *  Os_Hal_StackBottomGet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackBottomGet,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) LowAddress,
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) HighAddress
))
{
  OS_IGNORE_UNREF_PARAM(LowAddress);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Return HighAddress. */
  return HighAddress;
}


/***********************************************************************************************************************
 *  Os_Hal_StackTopGet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackTopGet,
(
  void
))
{
  volatile uint32 spValue;
  Os_Hal_StoreStackPointer((uint32)(&spValue));                                                                         /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* #10 Return SP value. */
  return (P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT))(spValue);                                                  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */  /* COMP_WARN_OS_HAL_UNINITIALIZED_VAR */
}


/***********************************************************************************************************************
 *  Os_Hal_StackPointerMoveDown()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackPointerMoveDown,
(
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackPointer
))
{
  P2VAR(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) localStackPtr = StackPointer;/* extra copy for MISRA */

  /* #10 Increment given address. */
  localStackPtr++;
  return localStackPtr;
}


/***********************************************************************************************************************
 *  Os_Hal_StackCalculateUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_StackCalculateUsage,
(
  P2CONST(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackBottom,
  P2CONST(Os_Hal_StackType, AUTOMATIC, OS_VAR_NOINIT) StackTop
))
{
  /* #10 Return (Bottom-Top)*SizeOf(Element). */
  return ((uint32)StackBottom - (uint32)StackTop);                                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
}


/***********************************************************************************************************************
 *  Os_Hal_SpinIsLocked()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_SpinIsLocked,
(
  P2CONST(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  /* #10 Return spinlock value. */
  return (Os_StdReturnType)(*Spinlock);
}


/***********************************************************************************************************************
 *  Os_Hal_SpinUnlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_SpinUnlock,
(
  P2VAR(volatile Os_Hal_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  /* #10 Memory barrier. */
  Os_Hal_DataMemoryBarrier();

  /* #20 Set spinlock to OS_HAL_SPINLOCK_FREE. */
  *Spinlock = OS_HAL_SPINLOCK_FREE;                                                                                                        /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreIdle()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreIdle, (void))
{
  /* #10 Do nothing. */
  Os_Hal_CoreNop();
}


/***********************************************************************************************************************
 *  Os_Hal_CoreNop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreNop, (void))
{
  /* #10 Do nothing. */
  Os_Hal_Nop();
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CORE_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core.h
 **********************************************************************************************************************/

