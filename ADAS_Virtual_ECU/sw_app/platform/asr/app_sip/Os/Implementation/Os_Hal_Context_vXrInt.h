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
 *  \addtogroup  Os_Hal_Context
 *  \{
 *
 *  \file  Os_Hal_Context_vXrInt.h
 *  \brief  Context data structures definition for Cortex-R.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_CONTEXT_VXRINT_H
# define OS_HAL_CONTEXT_VXRINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_Hal_Derivative.h"
# include "Os_Hal_Context_Types.h"

# include "Os_MemoryProtection_Cfg.h"
# include "Os_CommonInt.h"
# include "Os_Core_Types.h"

/* Os Hal dependencies */
# include "Os_Hal_Cfg.h"
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_CoreInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Number of permanent registers. */
# define OS_HAL_CONTEXT_NUMBER_OF_PERMANENT_REGISTERS  (8)
/*! Number of 32-bit FPU registers. */
# define OS_HAL_CONTEXT_NUMBER_OF_FPU_REGISTERS        (32)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  Os_Hal_ContextSuspend()
 *********************************************************************************************************************/
/*! \brief        Store current context to given address except PC and permament registers.
 *  \details      PC and permanent register will be stored in the assembly functions:
 *                - Os_Hal_ContextRestorePermanentAndGoWithReturn
 *                - Os_Hal_ContextGoWithParameter
 *                - Os_Hal_ContextGoWithParameterMpSwitch
 *  \param[out]   Current       Address where to store current register values.
 *                               Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextSuspend,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current
));

/***********************************************************************************************************************
 *  Os_Hal_ContextResume()
 **********************************************************************************************************************/
/*! \brief        Restore context from given address.
 *  \details      -

 *  \param[in]    Next        Address where to load register values from. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));

/**********************************************************************************************************************
 *  Os_Hal_ContextGo()
 *********************************************************************************************************************/
/*! \brief        Set PC, LR and switch mode, stack and eventually stack region.
 *  \details      This is an assembler function.
 *  \param[in]    Next      Future context address.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Stack has to be already prepared.
 *  \pre          Future mode has to be already prepared.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_ContextGo
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
);

/**********************************************************************************************************************
 *  Os_Hal_ContextRestorePermanentAndGo()
 *********************************************************************************************************************/
/*! \brief        Load permanent registers, set PC, LR and switch mode, stack and eventually stack region.
 *  \details      This is an assembler function.
 *  \param[in]    Next          Pointer to the next context.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Stack has to be already prepared.
 *  \pre          Future mode has to be already prepared.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_ContextRestorePermanentAndGo
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
);

/***********************************************************************************************************************
 *  Os_Hal_ContextCallSetNextIntLevel()
 **********************************************************************************************************************/
/*! \brief        Restore interrupt level of Next.
 *  \details      Called from Os_Hal_ContextCall().
 *  \param[in]    Next   Pointer to the next context. Parameter must not be NULL.
 *  \param[in]    Addr   Address where the next SP value will be stored. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(                                                                                           
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextCallSetNextIntLevel,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next,
  CONSTP2VAR(volatile uint32, AUTOMATIC, OS_VAR_NOINIT) Addr
));

/***********************************************************************************************************************
 *  Os_Hal_ContextCallOnStackSetNextIntLevel()
 **********************************************************************************************************************/
/*! \brief        Restore interrupt level of Next.
 *  \details      Called from Os_Hal_ContextCallOnStack().
 *  \param[in]    Next   Pointer to the next context. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(                                                                                           
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextCallOnStackSetNextIntLevel,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Minimal set of hardware registers to be able to suspend and resume a thread.
   StackRegionInfo depending on the platform holds different values
   v7r : StackRegionSize, the size of the stack region for the context.
   v8r : StackRegionEnd, the End address of the stack region for the context.
*/
struct Os_Hal_ContextType_Tag
{
  uint32 Pc;                      /*!< Program Counter (PC). */
  uint32 Psr;                     /*!< Current Program Status Register (CPSR). */
  uint32 Sp;                      /*!< Stack Pointer (SP). */
  uint32 Lr;                      /*!< Link Register (LR). */
  uint32 Parameter;               /*!< Parameter register (r0). */
  uint32 PermanentRegisters[OS_HAL_CONTEXT_NUMBER_OF_PERMANENT_REGISTERS]; /*!< Permanent registers (r4-r11). */
  uint32 IntLevel;                /*!< Interrupt level. */
  uint32 StackRegionStart;        /*!< Stack region start (low address). */
  uint32 StackRegionInfo;         /*!< Stack region info. */
};


/*! Information needed to initialize the context of a thread. */
struct Os_Hal_ContextConfigType_Tag
{
  uint32 StackRegionEnd;          /*!< Stack regions end. */
  uint32 Psr;                     /*!< Current Program Status Register (CPSR). */
  uint32 IntLevel;                /*!< Interrupt level. */
  uint32 Entry;                   /*!< Entry function (initial program counter value). */
  uint32 ReturnAddress;           /*!< Initial link register value. */
  uint32 StackRegionStart;        /*!< Stack region start (low address). */
  uint32 StackRegionSize;         /*!< Stack region size. */
};


/*! Information needed to perform a stack switch. */
struct Os_Hal_ContextStackConfigType_Tag
{
  uint32 StackRegionEnd;          /*!< Stack end address (high address) */
  uint32 StackRegionStart;        /*!< Stack start address (low address) */
  uint32 StackRegionSize;         /*!< Stack size. */
};

/*! Set of floating point registers to be able to suspend and resume a thread. */
struct Os_Hal_ContextFpuContextType_Tag
{
    uint32 FpuRegisters[OS_HAL_CONTEXT_NUMBER_OF_FPU_REGISTERS]; /*!< FPU registers (s0-s31). */
    uint32 Fpscr;                   /* Floating point status and control register (FPSCR). */
    uint32 Fpexc;                   /* Floating point exception control register (FPEXC). */
};

#endif /* OS_HAL_CONTEXT_VXRINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_vXrInt.h
 **********************************************************************************************************************/
