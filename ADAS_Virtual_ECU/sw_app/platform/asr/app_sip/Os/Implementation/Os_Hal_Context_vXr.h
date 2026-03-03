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
 *  \file  Os_Hal_Context_vXr.h
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

#ifndef  OS_HAL_CONTEXT_VXR_H
# define OS_HAL_CONTEXT_VXR_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"
# include "Os_Hal_Derivative.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os Hal dependencies */
# include "Os_Hal_ContextInt.h"
# include "Os_Hal_Compiler.h"
# include "Os_Hal_CoreInt.h"
# include "Os_Hal_MemoryProtection.h"

# if defined (OS_HAL_INTC_VIM_TWOLEVEL)                                                                                 /* COV_OS_DERIVATIVEBETAMODULE */ 
#  include "Os_Hal_Context_vXr_IrqFiqTwoIntLevelLock.h"
# else
#  include "Os_Hal_Context_vXr_MultiIntLevelLock.h"
# endif

# if (OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON)
#  include "Os_Hal_Context_vXr_FpuOn.h"
# else
#  include "Os_Hal_Context_FpuOff.h"
# endif

# if (OS_CFG_MEMORY_PROTECTION == STD_ON)
#  include "Os_Hal_Context_vXr_MpuOn.h"
# else
#  include "Os_Hal_Context_MpuOff.h"
# endif

/* dependency to service functions */
# include "Os_ServiceFunction_Types.h"


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
 *  Os_Hal_ContextInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInit,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Reset given context. */
  Os_Hal_ContextReset(Config, Context);                                                                                 /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetParameter()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetParameter,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter
))
{
  /* #10 Set parameter register of given context to given value. */
  Context->Parameter = (uint32)Parameter;                                                                               /* PRQA S 0326 */ /* MD_Os_Rule11.6_0326 */ /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextGetStack()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextGetStack,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Context,
  P2VAR(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
))
{
  /* #10 Get stack config from given context config. */
  Stack->StackRegionEnd   = Context->StackRegionEnd;                                                                    /* SBSW_OS_HAL_PWA_CALLER */
  Stack->StackRegionStart = Context->StackRegionStart;                                                                  /* SBSW_OS_HAL_PWA_CALLER */
  Stack->StackRegionSize  = Context->StackRegionSize;                                                                   /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetInterruptState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetInterruptState,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  /* #10 Set interrupt flags to given state. */
  Context->Psr = (Context->Psr & (~OS_HAL_PSR_INTERRUPTS_MASKED) & (~OS_HAL_PSR_INTERRUPTS_MASKED_FIQ)) |               /* SBSW_OS_HAL_PWA_CALLER */
                 (InterruptState->GlobalInterruptFlag &
                     (OS_HAL_PSR_INTERRUPTS_MASKED | OS_HAL_PSR_INTERRUPTS_MASKED_FIQ));

  /* #20 Set interrupt level to given level. */
  Context->IntLevel = InterruptState->InterruptLevel;                                                                   /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetUserMsrBits()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextSetUserMsrBits,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Update PSR according to user settings. */
  Context->Psr = ((Context->Psr & (~OS_HAL_CORE_MSR_USER_BIT_MSK)) |                                                    /* SBSW_OS_HAL_PWA_CALLER */
                  (Os_Hal_ReadPsr() & OS_HAL_CORE_MSR_USER_BIT_MSK));
}


/***********************************************************************************************************************
 *  Os_Hal_ContextFirstResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextFirstResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Restore SP, interrupt level, stack region and prepare SPSR. */
  Os_Hal_ContextResume(Next);                                                                                           /* SBSW_OS_HAL_FC_CALLER */ /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #20 Set new PC, LR, set CPSR = SPSR and restore stack region, if needed. This results in a switch to next. */
  Os_Hal_ContextGo(Next);                                                                                               /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextResetAndResume()
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
Os_Hal_ContextResetAndResume,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Reset given Current context. */
  Os_Hal_ContextReset(CurrentConfig, Current);                                                                          /* SBSW_OS_HAL_FC_CALLER */

  /* #20 Restore SP, interrupt level, stack region and prepare SPSR. */
  Os_Hal_ContextResume(Next);                                                                                           /* SBSW_OS_HAL_FC_CALLER */ /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #30 Restore permanent registers, set new PC, LR, set CPSR = SPSR and restore stack region, if needed. This results in a switch to next. */
  Os_Hal_ContextRestorePermanentAndGo(Next);                                                                            /* SBSW_OS_HAL_FC_CALLER */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* Function never returns. */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextAbort()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextAbort,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Reset given context. */
  Os_Hal_ContextReset(Config, Context);                                                                                 /* SBSW_OS_HAL_FC_CALLER */

  /* #20 Set PC to configured return address. */
  Context->Pc = Config->ReturnAddress;                                                                                  /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextReturn()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextReturn,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  OS_IGNORE_UNREF_PARAM(Current);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  /* #10 Restore SP, interrupt level, stack region and prepare SPSR. */
  Os_Hal_ContextResume(Next);                                                                                           /* SBSW_OS_HAL_FC_CALLER */ /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #20 Restore permanent registers, set new PC, LR, set CPSR = SPSR and restore stack region, if needed. */
  Os_Hal_ContextRestorePermanentAndGo(Next);                                                                            /* COV_OS_HALPLATFORMCONTEXT */ /* SBSW_OS_HAL_FC_CALLER */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  /* Function never returns. */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CONTEXT_VXR_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_vXr.h
 **********************************************************************************************************************/
