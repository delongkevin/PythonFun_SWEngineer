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
 *  \ingroup  Os_Hal
 *  \addtogroup  Os_Hal_Context
 *  \{
 *
 *  \file  Os_Hal_Context_v8r.h
 *  \brief  Context switching primitives for Cortex-R.
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

#ifndef  OS_HAL_CONTEXT_V8R_H
# define OS_HAL_CONTEXT_V8R_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* Os Hal dependencies */
# include "Os_Hal_ContextInt.h"
# include "Os_Hal_Context_vXr.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

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
 *  Os_Hal_ContextReset()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextReset,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Set SP and stack region to configured values. */
  Context->Sp = Config->StackRegionEnd;                                                                                 /* SBSW_OS_HAL_PWA_CALLER */
  Context->StackRegionStart = Config->StackRegionStart;                                                                 /* SBSW_OS_HAL_PWA_CALLER */
  Context->StackRegionInfo = Config->StackRegionEnd;                                                                   /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Set CPSR and interrupt level to configured values. */
  Context->Psr = ((Config->Psr & (~OS_HAL_CORE_MSR_USER_BIT_MSK)) |
                  (Context->Psr & OS_HAL_CORE_MSR_USER_BIT_MSK));                                                       /* SBSW_OS_HAL_PWA_CALLER */ /* COMP_WARN_OS_HAL_UNINITIALIZED_VAR */

  Context->IntLevel = Config->IntLevel;                                                                                 /* SBSW_OS_HAL_PWA_CALLER */

  /* #30 Set PC and LR to configured values. */
  Context->Pc = Config->Entry;                                                                                          /* SBSW_OS_HAL_PWA_CALLER */
  Context->Lr = Config->ReturnAddress;                                                                                  /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetStack()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
))
{
  /* #10 Set SP and stack region of given context to given stack configuration. */
  Context->Sp = Stack->StackRegionEnd;                                                                                  /* SBSW_OS_HAL_PWA_CALLER */
  Context->StackRegionStart = Stack->StackRegionStart;                                                                  /* SBSW_OS_HAL_PWA_CALLER */
  Context->StackRegionInfo = Stack->StackRegionEnd;                                                                     /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextIsExceptionContextReadingSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextIsExceptionContextReadingSupported,
(
  void
))
{
  return (Os_StdReturnType)(0u);
}


/***********************************************************************************************************************
 *  Os_Hal_ContextIsExceptionContextModificationSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextIsExceptionContextModificationSupported,
(
  void
))
{
  return (Os_StdReturnType)(0u);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CONTEXT_V8R_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_v8r.h
 **********************************************************************************************************************/
