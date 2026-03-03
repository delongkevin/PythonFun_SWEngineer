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
 * \ingroup    Os_Hal
 * \addtogroup Os_Hal_Compiler
 * \{
 *
 * \file    Os_Hal_StaticCodeAnalysis.h
 * \brief   Compiler abstraction of the ANSI C compiler used for MISRA and ReviewHelper
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_STATICCODEANALYSIS_H
# define OS_HAL_STATICCODEANALYSIS_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"


/**********************************************************************************************************************
 *  QAC PRAGMAS
 *********************************************************************************************************************/
# if !defined(OS_STATIC_CODE_ANALYSIS_FETA)                                                                             /* COV_OS_STATICCODEANALYSIS */
# pragma PRQA_NO_RETURN Os_ErrKernelPanic
# endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/*! \brief      Declares a function with a compiler specific attribute.
 *  \details    The implementations prototype has to be created with OS_FUNC_ATTRIBUTE_DEFINITION.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
#define OS_FUNC_ATTRIBUTE_DECLARATION(rettype, memclass, attribute, functionName, arguments)                            \
  FUNC(rettype, memclass) functionName arguments                                                                        /* PRQA S 3410, 0850 */ /* MD_Os_Rule20.7_3410_Decl, MD_MSR_MacroArgumentEmpty */


/*! \brief      Provides a function prototype for function definitions with a compiler specific attribute.
 *  \details    The declaration has to be created with OS_FUNC_ATTRIBUTE_DECLARE.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
#define OS_FUNC_ATTRIBUTE_DEFINITION(rettype, memclass, attribute, functionName, arguments)                             \
  FUNC(rettype, memclass) functionName arguments                                                                        /* PRQA S 3410, 0850 */ /* MD_Os_Rule20.7_3410_Decl, MD_MSR_MacroArgumentEmpty */


/*! \brief    Abstraction for HAL specific compiler attribute to prevent from inlining a function. */
# define OS_HAL_NOINLINE

/*! \brief    Force the compiler to inline a function.
 *  \details  This attribute forces the compiler to inline the specified function,
 *            regardless of the optimization strategy of the compiler itself.
 *            On some compilers you may be able to disable even this kind of inlining, using debugging options.
 */
# define OS_ALWAYS_INLINE


/*! \brief    This attribute tells the compiler that a function never returns.
 *  \details  It can then optimize without regard to what would happen if the function ever did return.
 *            This makes slightly better code. More importantly, it helps avoid spurious warnings of uninitialized variables.
 */
# define OS_NORETURN


/*! \brief    This attribute forces inlining of all function calls in a function, including nested function calls.
 * \details   Whether the function itself is considered for inlining depends on its size and the current inlining parameters.
 */
# define OS_FLATTEN


/*! \brief    This attribute tells that a function has no side effects and will not access global data.
 *  \details  This can help the compiler to optimize code. Such functions do not examine any values except their arguments,
 *            and have no effects except the return value. This is just slightly more strict class than the OS_PURE attribute,
 *            since function is not allowed to read global memory.
 */
# define OS_NOSIDEEFFECTS


/*! \brief    This attribute tells that a function has no side effects, although it may read global data.
 *  \details  Such pure functions can be subject to common subexpression elimination and loop optimization.
 */
# define OS_PURE


/*! \note The specified function will not have prologue/epilogue sequences generated by the compiler.
 *      Return instruction is still needed. I'm not sure whether this is usable.
 */
# define OS_NAKED


/*! \brief        Triggers a side effect and returns a non constant value.
 *  \details      Can be used to avoid MISRA findings about functions with no side effects and MISRA detecting constant
 *                expressions in conditions.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 */
static inline uint32 Os_Hal_DummySideEffect(void);
static inline uint32 Os_Hal_DummySideEffect(void)                                                                       /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  static uint32 x = 0;
  x++;
  return x;
}

/*! \brief        Returns the current SP register value.
 *  \details      -
 *  \return       SP register value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_StoreStackPointer(uint32 Addr);
static void Os_Hal_StoreStackPointer(uint32 Addr)                                                                       /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Addr);                                                                                          /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Executes data memory barrier instruction "dmb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_DataMemoryBarrier(void);
static void Os_Hal_DataMemoryBarrier(void)                                                                              /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Executes data sync barrier instruction "dsb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_DataSyncBarrier(void);
static void Os_Hal_DataSyncBarrier(void)                                                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Executes instruction sync barrier instruction "isb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_InstructionSyncBarrier(void);
static void Os_Hal_InstructionSyncBarrier(void)                                                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Returns the link register value.
 *  \details      -
 *  \return       Link register value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_StoreLinkRegister(uint32 Addr);
static void Os_Hal_StoreLinkRegister(uint32 Addr)                                                                       /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Addr);                                                                                          /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Bypass given pointer and execute SVC instruction.
 *  \details      -
 *  \param[in]    TrapPacket  Value which shall be passed in parameter register. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_SysCall(uint32 TrapPacket);
static void Os_Hal_SysCall(uint32 TrapPacket)                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(TrapPacket);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/*! \brief        Bypass given pointer and execute SVC instruction.
 *  \details      -
 *  \param[in]    TrapPacket  Value which shall be passed in parameter register. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_SysCallTwoLevel(uint32 TrapPacket, uint32 RegBlock);
static void Os_Hal_SysCallTwoLevel(uint32 TrapPacket, uint32 RegBlock)                                                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(TrapPacket);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(RegBlock);                                                                                      /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/*! \brief        Executes "no operation" instruction.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_Nop(void);
static void Os_Hal_Nop(void)                                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Changes the current processor mode in CPSR to System.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_ChangeToSystemMode(void);
static void Os_Hal_ChangeToSystemMode(void)                                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  (void) Os_Hal_DummySideEffect();
}

/*! \fn           void Os_Hal_SetAbortModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the abort mode (SP_abt).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_abt.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 */
static void Os_Hal_SetAbortModeStackPointer(uint32 Var_Address);
static void Os_Hal_SetAbortModeStackPointer(uint32 Var_Address)                                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Var_Address);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \fn           void Os_Hal_SetUndModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the UND mode (SP_und).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_und.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 */
static void Os_Hal_SetUndModeStackPointer(uint32 Var_Address);
static void Os_Hal_SetUndModeStackPointer(uint32 Var_Address)                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Var_Address);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
} 
 
/*! \fn           void Os_Hal_SetFiqModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the FIQ mode (SP_fiq).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_fiq.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 */
static void Os_Hal_SetFiqModeStackPointer(uint32 Var_Address);
static void Os_Hal_SetFiqModeStackPointer(uint32 Var_Address)                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Var_Address);                                                                                   /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Sets stack pointer for the current mode and afterwards changes the mode in CPSR to Supervisor
 *                preserving the previous stack pointer value.
 *  \details      -
 *  \param[in]    NewSp  Value which shall be written to stack pointer.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_SetSpAndChangeToSupervisorMode(uint32 NewSp);
static void Os_Hal_SetSpAndChangeToSupervisorMode(uint32 NewSp)                                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(NewSp);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Sets the Floating-Point Status and Control Register (FPSCR).
 *  \details      -
 *  \param[in]    NewFpscr  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WriteFpscr(uint32 NewFpscr);
static void Os_Hal_WriteFpscr(uint32 NewFpscr)                                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(NewFpscr);                                                                                      /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Returns the FPSCR.
 *  \details      -
 *  \return       FPSCR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_ReadFpscr(void);
static uint32 Os_Hal_ReadFpscr(void)                                                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}

/*! \brief        Sets the Floating-Point Exception Control Register (FPEXC).
 *  \details      -
 *  \param[in]    NewFpexc  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WriteFpexc(uint32 NewFpexc);
static void Os_Hal_WriteFpexc(uint32 NewFpexc)                                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(NewFpexc);                                                                                      /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Returns the FPEXC.
 *  \details      -
 *  \return       FPEXC value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_ReadFpexc(void);
static uint32 Os_Hal_ReadFpexc(void)                                                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}

/*! \brief        Stores FPU registers (d0-d15) to given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to store.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_StoreFpuRegisters(uint32 FpuRegs);
static void Os_Hal_StoreFpuRegisters(uint32 FpuRegs)                                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(FpuRegs);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Stores FPU registers (d0-d31) to given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to store.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_StoreExtendedFpuRegisters(uint32 FpuRegs);
static void Os_Hal_StoreExtendedFpuRegisters(uint32 FpuRegs)                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(FpuRegs);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Restores FPU registers (d0-d15) from given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to load from.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_RestoreFpuRegisters(uint32 FpuRegs);
static void Os_Hal_RestoreFpuRegisters(uint32 FpuRegs)                                                                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(FpuRegs);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Restores FPU registers (d0-d31) from given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to load from.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_RestoreExtendedFpuRegisters(uint32 FpuRegs);
static void Os_Hal_RestoreExtendedFpuRegisters(uint32 FpuRegs)                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(FpuRegs);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Set the System Control Coprocessor's User Read-Only Thread ID Register (TPIDRURO).
 *  \details      -
 *  \param[in]    Thread  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_SetThreadIdRegister(uint32 Thread);
static void Os_Hal_SetThreadIdRegister(uint32 Thread)                                                                   /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Thread);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Returns the System Control Coprocessor's User Read-Only Thread ID Register (TPIDRURO) value.
 *  \details      -
 *  \return       TPIDRURO value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_GetThreadIdRegister(void);
static uint32 Os_Hal_GetThreadIdRegister(void)                                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return Os_Hal_DummySideEffect();
}

/*! \brief        Returns the System Control Coprocessor's Multiprocessor Affinity Register (MPIDR).
 *  \details      -
 *  \return       MPIDR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_GetMultiprocessorIdRegister(void);
static uint32 Os_Hal_GetMultiprocessorIdRegister(void)                                                                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return Os_Hal_DummySideEffect();
}

/*! \brief        Set the Saved Program Status Register (SPSR).
 *  \details      -
 *  \param[in]    NewSPSR  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WriteSavedPsr(uint32 NewSPSR);
static void Os_Hal_WriteSavedPsr(uint32 NewSPSR)                                                                        /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(NewSPSR);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Returns the Current Program Status Register (CPSR).
 *  \details      -
 *  \return       CPSR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_ReadPsr(void);
static uint32 Os_Hal_ReadPsr(void)                                                                                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return Os_Hal_DummySideEffect();
}


/*! \brief        Writes the Current Program Status Register (CPSR).
 *  \details      -
 *  \param[in]    NewPSR  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WritePsr(uint32 NewPsr);
static void Os_Hal_WritePsr(uint32 NewPsr)                                                                              /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(NewPsr);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Enables core local interrupts.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static inline void Os_Hal_Enable_Core_Interrupts(void);
static inline void Os_Hal_Enable_Core_Interrupts(void)
{
  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Disables core local interrupts.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static inline void Os_Hal_Disable_Core_Interrupts(void);
static inline void Os_Hal_Disable_Core_Interrupts(void)
{
  (void) Os_Hal_DummySideEffect();
}

 /*! \brief        Disable core local interrupts and returns the state of interrupts prior to the operation.
 *  \details      -
 *  \return       Previous interrupt state.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_DisableAndReturnPriorState(void);
static uint32 Os_Hal_DisableAndReturnPriorState(void)                                                                   /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}

/*! \brief        Restores the given interrupt state.
 *  \details      -
 *  \param[in]    IntState  Value which shall be restored.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_RestorePriorIntState(uint32 IntState);
static void Os_Hal_RestorePriorIntState(uint32 IntState)                                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(IntState);                                                                                      /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  (void) Os_Hal_DummySideEffect();
}

/* General function / macros */

/*! \brief        Takes a 32-bit integer argument and returns the count of leading zeros, which is a number from 0 to
 *                32.
 *  \details      -
 *  \param[in]    X  Integer which shall be inspected.
 *  \return       Count of leading zeros.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_CLZ(uint32 val);
static uint32 Os_Hal_CLZ(uint32 val)                                                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(val);                                                                                           /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  return Os_Hal_DummySideEffect();
}

/*! \brief        Uses a load exclusive synchronization instruction for the address, which attempts to mark the address
 *                for exclusive access by the current processor, and return the result.
 *  \details      -
 *  \param[in]    Addr  Address value to read from.
 *  \return       Value at Addr.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_LoadExclusive(const volatile uint32* Addr);
static uint32 Os_Hal_LoadExclusive(const volatile uint32* Addr)                                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return (uint32)(*Addr);
}

/*! \brief        Uses a store exclusive synchronization instruction, which attempts to store the value to the address.
 *                Returns 0 on success or 1 otherwise.
 *  \details      -
 *  \param[out]   Addr    Address to write to. Parameter must not be NULL.
 *  \param[in]    Value   Value which shall be written.
 *  \retval       0       Success.
 *  \retval       1       No success.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_StoreExclusive(volatile uint32* Addr, uint32 Value);
static uint32 Os_Hal_StoreExclusive(volatile uint32* Addr, uint32 Value)                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Addr);                                                                                          /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(Value);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  (*Addr) = Value;                                                                                                      /* SBSW_OS_HAL_PWA_CALLER */
  return (uint32)(*Addr);
}

/*! \brief        Returns a 32-bit value from given coprocessor Coproc.
 *  \details      -
 *  \param[in]    Coproc    Coprocessor to read from.
 *  \param[in]    Opcode1   Coprocessor specific opcode.
 *  \param[in]    CRn       Coprocessor register that contains the first operand.
 *  \param[in]    CRm       Additional source or destination coprocessor register.
 *  \param[in]    Opcode2   Coprocessor specific opcode.
 *  \return       Value read from coprocessor.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_ReadFromCoprocessor(uint32 x0, uint32 x1, uint32 x2, uint32 x3, uint32 x4);
static uint32 Os_Hal_ReadFromCoprocessor(uint32 x0, uint32 x1, uint32 x2, uint32 x3, uint32 x4)                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(x0);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x1);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x2);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x3);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x4);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  return Os_Hal_DummySideEffect();
}

/*! \brief        Pass a 32-bit value to given coprocessor Coproc.
 *  \details      -
 *  \param[in]    Value     Value which shall be passed.
 *  \param[in]    Coproc    Coprocessor to pass given value to.
 *  \param[in]    Opcode1   Coprocessor specific opcode.
 *  \param[in]    CRn       Destination coprocessor register.
 *  \param[in]    CRm       Additional destination coprocessor register.
 *  \param[in]    Opcode2   Coprocessor specific opcode.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WriteToCoprocessor(uint32 x0, uint32 x1, uint32 x2, uint32 x3, uint32 x4, uint32 x5);
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
static void Os_Hal_WriteToCoprocessor(uint32 x0, uint32 x1, uint32 x2, uint32 x3, uint32 x4, uint32 x5)                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(x0);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x1);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x2);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x3);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x4);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x5);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Set the SCTLR of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_SetSystemControl(uint32 Value);
static void Os_Hal_SetSystemControl(uint32 Value)                                                                       /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Value);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Returns the SCTLR of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       SCTLR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint32 Os_Hal_GetSystemControl(void);
static uint32 Os_Hal_GetSystemControl(void)                                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 1;
}

/*! \brief        Sets the VBAR.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_Set_VBAR(uint32 Value);
static void Os_Hal_Set_VBAR(uint32 Value)                                                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(Value);                                                                                         /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}

/*! \brief        Pass a 64-bit value to given coprocessor Coproc.
 *  \details      -
 *  \param[in]    Value     Value which shall be passed.
 *  \param[in]    Coproc    Coprocessor to pass given value to.
 *  \param[in]    Opcode1   Coprocessor specific opcode.
 *  \param[in]    CRm       Additional destination coprocessor register.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static void Os_Hal_WriteToCoprocessor64(uint64 x0, uint32 x1, uint32 x2, uint32 x3);
static void Os_Hal_WriteToCoprocessor64(uint64 x0, uint32 x1, uint32 x2, uint32 x3)                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(x0);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x1);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x2);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x3);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  (void) Os_Hal_DummySideEffect();
}

/*! \brief        Returns a 64-bit value from given coprocessor Coproc.
 *  \details      -
 *  \param[in]    Coproc    Coprocessor to read from.
 *  \param[in]    Opcode1   Coprocessor specific opcode.
 *  \param[in]    CRm       Additional source or destination coprocessor register.
 *  \return       Value read from coprocessor.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 */
static uint64 Os_Hal_ReadFromCoprocessor64(uint32 x0, uint32 x1, uint32 x2);
static uint64 Os_Hal_ReadFromCoprocessor64(uint32 x0, uint32 x1, uint32 x2)                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  OS_IGNORE_UNREF_PARAM(x0);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x1);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(x2);                                                                                            /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  return Os_Hal_DummySideEffect();
}

/*! \brief      Abstraction for declaring a CAT1 ISR. */
# define DeclareCat1Isr(core, level, name)  void name(void)

/*! \brief      Abstraction for defining a CAT1 ISR. */
# define DefineCat1Isr(core, level, name)   void name(void)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* OS_HAL_STATICCODEANALYSIS_H */

/*!
 * \}
 */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_StaticCodeAnalysis.h
 *********************************************************************************************************************/

