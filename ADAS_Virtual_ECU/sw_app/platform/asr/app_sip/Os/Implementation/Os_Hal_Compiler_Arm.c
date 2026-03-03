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
 *  \brief        Compiler abstraction for Arm compiler.
 *  \details
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
 *
 *
 *
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_COMPILER_ARM_SOURCE

# ifdef CDK_CHECK_MISRA                                                                                                 /* COV_OS_STATICCODEANALYSIS */
#  ifndef OS_STATIC_CODE_ANALYSIS                                                                                       /* COV_OS_STATICCODEANALYSIS */
#    define OS_STATIC_CODE_ANALYSIS
#  endif
# endif


#ifndef OS_STATIC_CODE_ANALYSIS                                                                                         /* COV_OS_STATICCODEANALYSIS */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os hal module dependencies */
# include "Os_Hal_Compiler.h"

# if defined (OS_CFG_COMPILER_ARM)                                                                                      /* COV_OS_DERIVATIVEBETAMODULE */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
__asm void Os_Hal_StoreStackPointer(uint32 Addr)
{
  str  sp, [r0]
  bx   lr
}

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
__asm void Os_Hal_StoreLinkRegister(uint32 Addr)
{
  str  lr, [r0]
  bx   lr
}

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
__asm void Os_Hal_SetAbortModeStackPointer(uint32 Var_Address)
{
  cps  #0x17
  mov  sp, r0
  cps  #0x1F
  bx   lr
}

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
__asm void Os_Hal_SetUndModeStackPointer(uint32 Var_Address)

{
  cps  #0x1B
  mov  sp, r0
  cps  #0x1F
  bx   lr
}

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
__asm void Os_Hal_SetFiqModeStackPointer(uint32 Var_Address)

{
  cps  #0x11
  mov  sp, r0
  cps  #0x1F
  bx   lr
}

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
__asm void Os_Hal_ChangeToSystemMode(void)
{
  mov  r0, sp
  mov  r1, lr
  cps  #0x1f
  mov  sp, r0
  mov  lr, r1
  bx   lr
}

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
__asm void Os_Hal_SetSpAndChangeToSupervisorMode(uint32 NewSp)
{
  mov  r1, sp
  mov  r2, lr
  mov  sp, r0
  cps  #0x13
  mov  sp, r1
  mov  lr, r2
  bx   lr
}

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
__asm void Os_Hal_WriteSavedPsr(uint32 NewSPSR)
{
  msr  spsr_cxsf, r0
  bx   lr
}

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
__asm uint32 Os_Hal_LoadExclusive(const volatile uint32* Addr)
{
  ldrex r0, [r0]
  bx    lr
}

/***********************************************************************************************************************
 *  Os_Hal_StoreExclusive()
 **********************************************************************************************************************/
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
 **********************************************************************************************************************/
__asm uint32 Os_Hal_StoreExclusive(volatile uint32* Addr, uint32 Value)
{
  strex r2, r1, [r0]
  mov   r0, r2
  bx    lr
}


/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_1_0_0()
 **********************************************************************************************************************/
/*! \brief        Function definition of one of the used ReadFromCoprocessor variants.
 **********************************************************************************************************************/
Os_Hal_RFC_variant_Definition(1, 0, 0)

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_0_0_4()
 **********************************************************************************************************************/
/*! \brief        Function definition of one of the used ReadFromCoprocessor variants.
 **********************************************************************************************************************/
Os_Hal_RFC_variant_Definition(0, 0, 4)

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_6_1_0()
 **********************************************************************************************************************/
/*! \brief        Function definition of one of the used ReadFromCoprocessor variants.
 **********************************************************************************************************************/
Os_Hal_RFC_variant_Definition(6, 1, 0)

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_6_1_2()
 **********************************************************************************************************************/
/*! \brief        Function definition of one of the used ReadFromCoprocessor variants.
 **********************************************************************************************************************/
Os_Hal_RFC_variant_Definition(6, 1, 2)

#if (OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON)                                                                       /* COV_OS_DERIVATIVEBETAMODULE */

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
__asm void Os_Hal_StoreFpuRegisters(uint32 FpuRegs)
{                                            
  vstm  r0, {d0-d15}                   
  bx    lr
}                                            

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
__asm void Os_Hal_RestoreFpuRegisters(uint32 FpuRegs)
{                                          
  vldm  r0, {d0-d15}                 
  bx    lr
}                                          

# endif /* OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON */

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# endif /* if defined (OS_CFG_COMPILER_ARM) */

#endif /* #ifndef (CDK_CHECK_MISRA) */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_Arm.c
 *********************************************************************************************************************/
