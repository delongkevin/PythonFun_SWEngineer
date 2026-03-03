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
 *  \addtogroup Os_Hal_Compiler
 *  \{
 *
 *  \file
 *  \brief        Compiler abstraction for GCC compiler.
 *  \details
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILER_HIGHTECINT_H
# define OS_HAL_COMPILER_HIGHTECINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Compiler specific Header for the usage of intrinsic functions */
# include <arm_acle.h>

# include "Std_Types.h"
# include "Os_Core_Cfg.h"
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Entry_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! CPSR Register: IRQ Interrupt state bit mask. */
# define OS_HAL_PSR_IRQ_FLAG       (1uL << 7)
/*! CPSR Register: FIQ Interrupt state bit mask. */
# define OS_HAL_PSR_FIQ_FLAG       (1uL << 6)

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
# define OS_FUNC_ATTRIBUTE_DECLARATION(rettype, memclass, attribute, functionName, arguments) \
  FUNC(rettype, memclass) functionName arguments attribute                                                              /* PRQA S 3410 */ /* MD_Os_Rule20.7_3410 */


/*! \brief      Provides a function prototype for function definitions with a compiler specific attribute.
 *  \details    The declaration has to be created with OS_FUNC_ATTRIBUTE_DECLARE.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
# define OS_FUNC_ATTRIBUTE_DEFINITION(rettype, memclass, attribute, functionName, arguments) \
  attribute FUNC(rettype, memclass) functionName arguments                                                              /* PRQA S 3410 */ /* MD_Os_Rule20.7_3410 */

/*! \brief    Abstraction for HAL specific compiler attribute to prevent from inlining a function.
 *  \details  This attribute excludes certain functions from inlining within a C++ file, even if they are member
 *            functions defined inside a class,
 */
# define OS_HAL_NOINLINE             __NO_INLINE__

/*! \brief    Force the compiler to inline a function.
 *  \details  This attribute forces the compiler to inline the specified function,
 *            regardless of the optimization strategy of the compiler itself.
 *            On some compilers you may be able to disable even this kind of inlining, using debugging options.
 */
# define OS_ALWAYS_INLINE


/*! \brief    This attribute tells the compiler that a function never returns.
 *  \details  Therefore any code following the function call may be considered dead code and optimized away.
              For example, this attribute can be used on the standard library functions exit(), abort(), and longjmp().
 */
# define OS_NORETURN


/*! \brief    This attribute forces inlining of all function calls in a function, including nested function calls.
 *  \details   Whether the function itself is considered for inlining depends on its size and the current inlining parameters.
 */
# define OS_FLATTEN


/*! \brief    This attribute tells that a function has no side effects and will not access global data.
 *  \details  This can help the compiler to optimize code. Such functions do not examine any values except their arguments,
 *            and have no effects except the return value. This is just slightly more strict class than the OS_PURE attribute,
 *            since function is not allowed to read global memory.
 */
# define OS_NOSIDEEFFECTS


/*! \brief    This attribute tells that a function has no side effects, although it may read global data.
 *  \details  Tells the compiler that this function is pure: the state of the world is the same before and
 *            after a call to this function. A pure function may read memory, throw a C++ exception, or even enter an infinite loop,
 *            but a pure function may not modify global memory (for example, it may not write to a global variable, or write
 *            through a pointer). Marking a function as pure may improve the compiler's ability to perform alias analysis optimizations.
 */
# define OS_PURE


/*! \note     The specified function will not have prologue/epilogue sequences generated by the compiler.
 *            Return instruction is still needed. I'm not sure whether this is usable.
 */
# define OS_NAKED


/***********************************************************************************************************************
 *  Os_Hal_StoreStackPointer()
 **********************************************************************************************************************/
/*! \brief        Store the current SP register value into the given address.
 *  \details      -
 *  \param[in]    Addr  Address where the current SP value will be stored.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_StoreStackPointer(Addr)       \
  __asm__ volatile ("str sp, [%0]"            \
  :                                           \
  : "r" (Addr)                                \
  : )


/***********************************************************************************************************************
 *  Os_Hal_DataMemoryBarrier()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_DataMemoryBarrier(void)
 *  \brief        Executes data memory barrier instruction "dmb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_DataMemoryBarrier() \
  __asm__ volatile (" dmb ")


/***********************************************************************************************************************
 *  Os_Hal_DataSyncBarrier()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_DataSyncBarrier(void)
 *  \brief        Executes data sync barrier instruction "dsb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_DataSyncBarrier() \
  __asm__ volatile (" dsb ")


/***********************************************************************************************************************
 *  Os_Hal_InstructionSyncBarrier()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_InstructionSyncBarrier(void)
 *  \brief        Executes instruction sync barrier instruction "isb".
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_InstructionSyncBarrier() \
  __asm__ volatile (" isb ")


/***********************************************************************************************************************
 *  Os_Hal_StoreLinkRegister()
 **********************************************************************************************************************/
/*! \brief        Store the current LR register value into the given address.
 *  \details      -
 *  \param[in]    Addr  Address where the current LR value will be stored.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_StoreLinkRegister(Addr)       \
  __asm__ volatile ("str lr, [%0]"            \
  :                                           \
  : "r" (Addr)                                \
  : )


/***********************************************************************************************************************
 *  Os_Hal_SysCall()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SysCall(uint32 TrapPacket)
 *  \brief        Bypass given pointer and execute SVC instruction.
 *  \details      -
 *  \param[in]    TrapPacket  Value which shall be passed in parameter register. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline void Os_Hal_SysCall(volatile uint32 TrapPacket)
{
  __asm__ volatile (" mov r0, %0 \n"
                    " svc #0       "
  :
  : "r" (TrapPacket)
  : "r0", "memory");
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_Nop()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_Nop(void)
 *  \brief        Executes "no operation" instruction.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_Nop() \
  __asm__ volatile( "nop" )


/***********************************************************************************************************************
 *  Os_Hal_SetAbortModeStackPointer()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetAbortModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the abort mode (SP_abt).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_abt.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 **********************************************************************************************************************/
# define Os_Hal_SetAbortModeStackPointer(Var_Address)  \
  __asm__ volatile (" cps #0x17  \n"                   \
                    " mov sp, %0 \n"                   \
                    " cps #0x1F  \n"                   \
                    :                                  \
                    : "r" (Var_Address)                \
                    : "memory" )


/***********************************************************************************************************************
 *  Os_Hal_SetUndModeStackPointer()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetUndModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the UND mode (SP_und).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_und.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 **********************************************************************************************************************/
# define Os_Hal_SetUndModeStackPointer(Var_Address)  \
  __asm__ volatile (" cps #0x1B  \n"                 \
                    " mov sp, %0 \n"                 \
                    " cps #0x1F  \n"                 \
                    :                                \
                    : "r" (Var_Address)              \
                    : "memory" )


/***********************************************************************************************************************
 *  Os_Hal_SetFiqModeStackPointer()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetFiqModeStackPointer(uint32 Var_Address)
 *  \brief        Writes the address of a variable to the stack pointer of the FIQ mode (SP_fiq).
 *  \details      This macro is intended to be used to write the address of the generated core specific variable, used 
 *                to intermediately save a number of registers at exception entry, to SP_fiq.
 *  \param[in]    Var_Address Address of a variable.
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          PL1 mode (User mode cannot use this macro)
 **********************************************************************************************************************/
# define Os_Hal_SetFiqModeStackPointer(Var_Address)  \
  __asm__ volatile (" cps #0x11  \n"                 \
                    " mov sp, %0 \n"                 \
                    " cps #0x1F  \n"                 \
                    :                                \
                    : "r" (Var_Address)              \
                    : "memory" )


/***********************************************************************************************************************
 *  Os_Hal_ChangeToSystemMode()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_ChangeToSystemMode(void)
 *  \brief        Changes the current processor mode in CPSR to System.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_ChangeToSystemMode()           \
   __asm volatile( "mov  r0, sp   \n"          \
                   "mov  r1, lr   \n"          \
                   "cps  #0x1f    \n"          \
                   "mov  sp, r0   \n"          \
                   "mov  lr, r1   \n"          \
                   :                           \
                   :                           \
                   : "r0", "r1" )


/***********************************************************************************************************************
 *  Os_Hal_SetSpAndChangeToSupervisorMode()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetSpAndChangeToSupervisorMode(uint32 NewSp)
 *  \brief        Sets stack pointer for the current mode and afterwards changes the mode in CPSR to Supervisor
 *                preserving the previous stack pointer value.
 *  \details      -
 *  \param[in]    NewSp  Value which shall be written to stack pointer.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_SetSpAndChangeToSupervisorMode(NewSp)   \
   __asm volatile( "mov  r1, sp   \n"                   \
                   "mov  r2, lr   \n"                   \
                   "mov  sp, %0   \n"                   \
                   "cps  #0x13    \n"                   \
                   "mov  sp, r1   \n"                   \
                   "mov  lr, r2   \n"                   \
                   :                                    \
                   : "r"(NewSp)                         \
                   : "r1", "r2" )


# if (OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON)

/***********************************************************************************************************************
 *  Os_Hal_WriteFpscr()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_WriteFpscr(uint32 NewFpscr)
 *  \brief        Sets the Floating-Point Status and Control Register (FPSCR).
 *  \details      -
 *  \param[in]    NewFpscr  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_WriteFpscr(NewFpscr)    \
  __asm__ volatile( " vmsr FPSCR, %0 "  \
  :                                     \
  : "r" (NewFpscr)                      \
  :)


/***********************************************************************************************************************
 *  Os_Hal_ReadFpscr()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_ReadFpscr(void)
 *  \brief        Returns the FPSCR.
 *  \details      -
 *  \return       FPSCR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_ReadFpscr(void)
{
  uint32 ret;
  __asm__ volatile( " vmrs %0, FPSCR "
  : "=r" (ret)
  :
  : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_WriteFpexc()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_WriteFpexc(uint32 NewFpexc)
 *  \brief        Sets the Floating-Point Exception Control Register (FPEXC).
 *  \details      -
 *  \param[in]    NewFpexc  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_WriteFpexc(NewFpexc)  \
  __asm__ volatile(" vmsr FPEXC, %0 " \
  :                                   \
  : "r" (NewFpexc)                    \
  :)


/***********************************************************************************************************************
 *  Os_Hal_ReadFpexc()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_ReadFpexc(void)
 *  \brief        Returns the FPEXC.
 *  \details      -
 *  \return       FPEXC value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_ReadFpexc(void)
{
  uint32 ret;
  __asm__ volatile( " vmrs %0, FPEXC "
  : "=r" (ret)
  :
  :);
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_StoreFpuRegisters()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_StoreFpuRegisters(uint32 FpuRegs)
 *  \brief        Stores FPU registers (d0-d15) to given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to store. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_StoreFpuRegisters(FpuRegs)    \
  __asm__ volatile( " vstm %0, {d0-d15}"      \
  :                                           \
  :  "r" (FpuRegs)                            \
  :)


/***********************************************************************************************************************
 *  Os_Hal_StoreExtendedFpuRegisters()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_StoreExtendedFpuRegisters(uint32 FpuRegs)
 *  \brief        Stores FPU registers (d0-d31) to given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to store. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_StoreExtendedFpuRegisters(FpuRegs) \
  __asm__ volatile( " vstm %0!, {d0-d15} \n"  \
                    " vstm  %0, {d16-d31}"    \
  :                                           \
  :  "r" (FpuRegs)                            \
  :)


/***********************************************************************************************************************
 *  Os_Hal_RestoreFpuRegisters()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_RestoreFpuRegisters(uint32 FpuRegs)
 *  \brief        Restores FPU registers (d0-d15) from given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to load from. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_RestoreFpuRegisters(FpuRegs)  \
  __asm__ volatile( " vldm %0, {d0-d15} "     \
  :                                           \
  : "r" (FpuRegs)                             \
  : )


/***********************************************************************************************************************
 *  Os_Hal_RestoreExtendedFpuRegisters()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_RestoreExtendedFpuRegisters(uint32 FpuRegs)
 *  \brief        Restores FPU registers (d0-d31) from given address.
 *  \details      -
 *  \param[in]    FpuRegs  Address where to load from. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_RestoreExtendedFpuRegisters(FpuRegs) \
  __asm__ volatile( " vldm %0!, {d0-d15} \n "  \
                    " vldm %0, {d16-d31} "     \
  :                                            \
  : "r" (FpuRegs)                              \
  : )

# endif /* OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON */


/***********************************************************************************************************************
 *  Os_Hal_SetThreadIdRegister()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetThreadIdRegister(uint32 Thread)
 *  \brief        Set the System Control Coprocessor's User Read-Only Thread ID Register (TPIDRURO).
 *  \details      -
 *  \param[in]    Thread  Value which shall be written. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_SetThreadIdRegister(Thread)        \
  __asm__ volatile( " MCR p15, 0, %0, c13, c0, 3 " \
  :                                                \
  : "r" (Thread)                                   \
  : )


/***********************************************************************************************************************
 *  Os_Hal_GetThreadIdRegister()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetThreadIdRegister(void)
 *  \brief        Returns the System Control Coprocessor's User Read-Only Thread ID Register (TPIDRURO) value.
 *  \details      -
 *  \return       TPIDRURO value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_GetThreadIdRegister(void)
{
  uint32 ret;
  __asm__ volatile(" MRC p15, 0, %0, c13, c0, 3 "
  : "=r" (ret)
  :
  : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_GetMultiprocessorIdRegister()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetMultiprocessorIdRegister(void)
 *  \brief        Returns the System Control Coprocessor's Multiprocessor Affinity Register (MPIDR).
 *  \details      -
 *  \return       MPIDR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_GetMultiprocessorIdRegister(void)
{
  uint32 ret;
  __asm__ volatile(" MRC p15, 0, %0, c0, c0, 5 "
  : "=r" (ret)
  :
  : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_WriteSavedPsr()
 **********************************************************************************************************************/
/*! \brief        Set the Saved Program Status Register (SPSR).
 *  \details      -
 *  \param[in]    NewSPSR  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_WriteSavedPsr(NewSPSR)        \
  __asm__ volatile( " msr  spsr_cxsf, %0 "    \
  :                                           \
  : "r" (NewSPSR)                             \
  : )


/***********************************************************************************************************************
 *  Os_Hal_ReadPsr()
 **********************************************************************************************************************/
/*! \brief        Returns the Current Program Status Register (CPSR).
 *  \details      -
 *  \return       CPSR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_ReadPsr(void)
{
  uint32 ret;
  __asm__ volatile( " mrs %0, cpsr"
  : "=r" (ret)
  :
  : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_WritePsr()
 **********************************************************************************************************************/
/*! \brief        Set the Current Program Status Register (CPSR).
 *  \details      -
 *  \param[in]    NewPSR  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_WritePsr(NewPSR)              \
  __asm__ volatile( " msr  cpsr_cxsf, %0 "    \
  :                                           \
  : "r" (NewPSR)                              \
  : )


/***********************************************************************************************************************
 *  Os_Hal_Enable_Core_Interrupts()
 **********************************************************************************************************************/
/*! \brief        Enables core local interrupts.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_Enable_Core_Interrupts() __asm__ volatile(" cpsie if ")


/***********************************************************************************************************************
 *  Os_Hal_Disable_Core_Interrupts()
 **********************************************************************************************************************/
/*! \brief        Disables core local interrupts.
 *  \details      -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_Disable_Core_Interrupts() __asm__ volatile(" cpsid if ")


/***********************************************************************************************************************
 *  Os_Hal_DisableAndReturnPriorState()
 **********************************************************************************************************************/
/*! \brief        Disable core local interrupts and returns the state of interrupts prior to the operation.
 *  \details      -
 *  \return       Previous interrupt state.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_DisableAndReturnPriorState(void)
{
  uint32 ret;
  __asm__ volatile( " mrs %0, cpsr \n"
                    " cpsid if       "
  : "=r" (ret)
  :
  : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_RestorePriorIntState()
 **********************************************************************************************************************/
/*! \brief        Restores the given interrupt state.
 *  \details      -
 *  \param[in]    IntState  Value which shall be restored.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline void Os_Hal_RestorePriorIntState(uint32 IntState)
{

  volatile uint32 mask = (uint32)~OS_HAL_PSR_IRQ_FLAG & (uint32)~OS_HAL_PSR_FIQ_FLAG;
  volatile uint32 state = IntState & (OS_HAL_PSR_IRQ_FLAG | OS_HAL_PSR_FIQ_FLAG);                                       /* COMP_WARN_OS_HAL_UNINITIALIZED_VAR */
  __asm__ volatile (" mrs r1, cpsr   \n"
                    " and r1, %0, r1 \n"
                    " orr r1, r1, %1 \n"
                    " msr cpsr_cxsf, r1"
                     :
                     : "r" (mask), "r" (state)
                     : "r1" );
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_CLZ()
 **********************************************************************************************************************/
/*! \brief        Takes a 32-bit integer argument and returns the count of leading zeros, which is a number from 0 to
 *                32.
 *  \details      -
 *  \param[in]    X  Integer which shall be inspected.
 *  \return       Count of leading zeros.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_CLZ(uint32 x)
{
  uint32 ret;
  __asm__ volatile("clz %0, %1" : "=r" (ret) : "r" (x) : );
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_LoadExclusive()
 **********************************************************************************************************************/
/*! \brief        Uses a load exclusive synchronization instruction for the address, which attempts to mark the address
 *                for exclusive access by the current processor, and return the result.
 *  \details      -
 *  \param[in]    Addr  Address value to read from. Parameter must not be NULL.
 *  \return       Value at Addr.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_LoadExclusive(volatile uint32* Addr)
{
  uint32 ret;
  __asm__ volatile( "ldrex %0, [%1]"
  : "=r" (ret)
  : "r"  (Addr)
  :);
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_StoreExclusive()
 **********************************************************************************************************************/
/*! \brief        Uses a store exclusive synchronization instruction, which attempts to store the value to the address.
 *                Returns 0 on success or 1 otherwise.
 *  \details      -
 *  \param[in]    Addr    Address to write to. Parameter must not be NULL.
 *  \param[in]    Value   Value which shall be written.
 *  \retval       0       Success.
 *  \retval       1       No success.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
static inline uint32 Os_Hal_StoreExclusive(volatile uint32* Addr, uint32 Value)
{
  uint32 ret;
  __asm__ volatile( " strex %0, %1, [%2] "
  : "=&r" (ret)
  : "r" (Value), "r" (Addr)
  :);
  return ret;
}
/* ECO_IGNORE_BLOCK_END */


/***********************************************************************************************************************
 *  Os_Hal_ReadFromCoprocessor()
 **********************************************************************************************************************/
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
 **********************************************************************************************************************/
# define Os_Hal_ReadFromCoprocessor(Coproc, Opcode1, CRn, CRm, Opcode2) \
                          __arm_mrc(Coproc, Opcode1, CRn, CRm, Opcode2)


/***********************************************************************************************************************
 *  Os_Hal_WriteToCoprocessor()
 **********************************************************************************************************************/
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
 **********************************************************************************************************************/
# define Os_Hal_WriteToCoprocessor(Value, Coproc, Opcode1, CRn, CRm, Opcode2) \
                         __arm_mcr(Coproc, Opcode1, Value, CRn, CRm, Opcode2)

/***********************************************************************************************************************
 *  Os_Hal_Set_VBAR()
 **********************************************************************************************************************/
/*! \brief        Sets the VBAR (Vector Base Address Register).
 *  \details      -
 *  \param[in]    Value     Address of the exception vector table.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_Set_VBAR(Value)    __asm__ volatile ("mcr p15, 0, %0, c12, c0, 0" ::"r"(Value):);


/***********************************************************************************************************************
 *  Os_Hal_SetSystemControl()
 **********************************************************************************************************************/
/*! \brief        Set the SCTLR of the PMSA.
 *  \details      Write to coprocessor register.
 *  \param[in]    Value  Value which shall be written.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_SetSystemControl(Value)         Os_Hal_WriteToCoprocessor(Value, 15, 0, 1, 0, 0)


/***********************************************************************************************************************
 *  Os_Hal_GetSystemControl()
 **********************************************************************************************************************/
/*! \brief        Returns the SCTLR of the PMSA.
 *  \details      Read from coprocessor register.
 *  \return       SCTLR value.
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
# define Os_Hal_GetSystemControl()              Os_Hal_ReadFromCoprocessor(15, 0, 1, 0, 0)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* OS_HAL_COMPILER_HIGHTECINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_HighTecInt.h
 *********************************************************************************************************************/
