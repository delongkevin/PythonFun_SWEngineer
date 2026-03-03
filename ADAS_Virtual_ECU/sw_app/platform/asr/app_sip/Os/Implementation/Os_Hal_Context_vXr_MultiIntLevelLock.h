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
 *  \file  Os_Hal_Context_vXr_MultiIntLevelLock.h
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

#ifndef  OS_HAL_CONTEXT_VXR_MULTIINTLEVELLOCK_H
# define OS_HAL_CONTEXT_VXR_MULTIINTLEVELLOCK_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* Os Hal dependencies */
# include "Os_Hal_ContextInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
 
/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
 
# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_ContextResume()
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
Os_Hal_ContextResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /*#10 Disable global interrupt flag. */            
  Os_Hal_Disable_Core_Interrupts();                  
                                                     
  /*#20 Restore SP and interrupt level. */           
  Os_Hal_INTC_SetCurrentLevel((Next)->IntLevel);     
  Os_Hal_SetSpAndChangeToSupervisorMode((Next)->Sp); 
                                                     
  /* #30 Prepare SPSR for switching into Next. */    
  Os_Hal_WriteSavedPsr((Next)->Psr);   
}

/***********************************************************************************************************************
 *  Os_Hal_ContextCallSetNextIntLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextCallSetNextIntLevel,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next,
  CONSTP2VAR(volatile uint32, AUTOMATIC, OS_VAR_NOINIT) Addr
))
{
  Os_Hal_INTC_SetCurrentLevel(Next->IntLevel);
  Os_Hal_StoreStackPointer((uint32)(Addr));                                                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  Os_Hal_SetSpAndChangeToSupervisorMode(*Addr);
  Os_Hal_WriteSavedPsr(Next->Psr);
}

/***********************************************************************************************************************
 *  Os_Hal_ContextCallOnStackSetNextIntLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextCallOnStackSetNextIntLevel,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  Os_Hal_INTC_SetCurrentLevel(Next->IntLevel);
  Os_Hal_SetSpAndChangeToSupervisorMode(Next->Sp);
  Os_Hal_WriteSavedPsr(Next->Psr);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"


#endif /* OS_HAL_CONTEXT_VXR_MULTIINTLEVELLOCK_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_vXr_MultiIntLevelLock.h
 **********************************************************************************************************************/
