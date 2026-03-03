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
 *  \file  Os_Hal_Context.c
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
                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#define OS_HAL_CONTEXT_V7_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os kernel module dependencies */
# include "Os_Hal_MemoryProtection.h"

/* Os Hal dependencies */
# include "Os_Hal_Context.h"

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
 ***********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Hal_ContextSwitch()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_ContextSwitch,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Suspend Current. */
  Os_Hal_ContextSuspend(Current);                                                                                       /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_FC_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Restore SP, interrupt level, stack region and prepare SPSR. */
  Os_Hal_ContextResume(Next);                                                                                           /* SBSW_OS_HAL_FC_CALLER */ /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #30 Restore permanent registers, store PC, set new PC, LR, set CPSR = SPSR and new stack region, if needed. */
  Os_Hal_ContextRestorePermanentAndGoWithReturn(Next, Current);                                                         /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextCall()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_ContextCall,                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */ /* PRQA S 3673 */ /* MD_Os_Hal_Rule8.13_3673 */
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  volatile uint32 spValue;
  /* #10 Suspend Current context. */
  Os_Hal_ContextSuspend(Current);                                                                                       /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_FC_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Disable global interrupt flags. */
  Os_Hal_Disable_Core_Interrupts();

  /* #30 Restore interrupt level of Next. */
  Os_Hal_ContextCallSetNextIntLevel(Next, &spValue);                                                                    /* SBSW_OS_HAL_FC_CALLER */ /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #40 Switch to Next without stack switch. */
  Os_Hal_ContextGoWithParameter(Next->Parameter, Next->Pc, Next->Lr, (uint32)Current);                                  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextCallOnStack()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_ContextCallOnStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Suspend Current context. */
  Os_Hal_ContextSuspend(Current);                                                                                       /* COV_OS_HALPLATFORMCONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_FC_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */ /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Disable global interrupt flags. */
  Os_Hal_Disable_Core_Interrupts();

  /* #30 Restore interrupt level of Next. */
  Os_Hal_ContextCallOnStackSetNextIntLevel(Next);                                                                       /* SBSW_OS_HAL_FC_CALLER */

  /* #40 Switch to Next with stack switch. */

  if(Os_MpIsEnabled() != 0u)                                                                                            /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
     Os_Hal_ContextGoWithParameterMpSwitch(Next->StackRegionStart, Next->StackRegionInfo, (uint32)Current, (uint32)Next); /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  }
  else
  {
     Os_Hal_ContextGoWithParameter(Next->Parameter, Next->Pc, Next->Lr, (uint32)(Current));                             /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  }
}



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context.c
 **********************************************************************************************************************/
