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
 * \addtogroup   Os_Hal_Entry
 * \{
 *
 * \file  Os_Hal_Entry_ExcHandlers.inc
 * \brief  This component handles hardware exceptions and interrupts.
 * \internal
 *  Hardware manuals: See derivative specific header (Os_Hal_Derivative_*Int.h)
 *  Errata sheets:    See derivative specific header
 *  Specifics: -
 *  Used registers and bits: General Purpose and System Registers
 *  Operating modes: -
 *  Hardware features related to independence or partitioning: -
 *  Access mechanism: Core special function registers
 *  Hardware diagnostics: -
 * \endinternal
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_ENTRY_EXC_HANDLERS_INC
# define OS_HAL_ENTRY_EXC_HANDLERS_INC

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Os_Hal_MemoryProtection_Cfg.h"
# include "Os_Hal_Compiler.inc"
# include "Os_Hal_ContextAsm_ExceptionContext.inc"
# if defined(OS_CFG_DERIVATIVEGROUP_E36XX)    || \
     defined(OS_CFG_DERIVATIVEGROUP_E34XX)    || \
     defined(OS_CFG_DERIVATIVEGROUP_RCARV4H)  || \
     defined(OS_CFG_DERIVATIVEGROUP_G9X)      || \
     defined(OS_CFG_DERIVATIVEGROUP_AM26XX)   || \
     defined(OS_CFG_DERIVATIVEGROUP_JACINTO7) || \
     defined(OS_CFG_DERIVATIVEGROUP_ZUXXX)
#   include "Os_Hal_Core_MultiProcessorGroups.inc"
# else
#   include "Os_Hal_Core_OneProcessorGroup.inc"
# endif

/***********************************************************************************************************************
 *  EXTERNAL DECLARATIONS
 **********************************************************************************************************************/
  OS_HAL_ASM_IMPORT(OsCfg_Stack_KernelStacks)
  OS_HAL_ASM_IMPORT(Os_UnhandledExc)

/***********************************************************************************************************************
 *  CONSTANT MACROS
 **********************************************************************************************************************/
/*! Access right value used for stack region. */
# define OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT        0x130B

/***********************************************************************************************************************
 *  FUNCTIONS
 **********************************************************************************************************************/
  OS_HAL_ASM_CODE_SECTION(OS_CODE)
  
  OS_HAL_ASM_EXPORT(Os_Hal_UnhandledExceptionEntry)  
  OS_HAL_ASM_EXPORT(Os_Hal_UnhandledSysCallExceptionEntry)
  OS_HAL_ASM_EXPORT(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection)
  OS_HAL_ASM_EXPORT(Os_Hal_UndefinedInstructionExceptionEntry)
  OS_HAL_ASM_EXPORT(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection)
  OS_HAL_ASM_EXPORT(Os_Hal_DataAbortExceptionEntry)
  OS_HAL_ASM_EXPORT(Os_Hal_PrefetchAbortExceptionEntry)

/***********************************************************************************************************************
 *  Os_Hal_Sub2FromReg()
 **********************************************************************************************************************/
/*! \brief           Substruct 2 from the value of the passed register r1.
 *  \details         Needed to avoid the usage of conditional instructions which not accepted by thumb mode unless 
 *                   they are located under an IT block.
 *  \param[in, out]  r1 is the passed register from which 2 is substructed
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Sub2FromReg)
  sub     r1, r1, #2                   /* substruct 2 from r1 */
  bx      lr                           /* Return to the caller */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Sub2FromReg)

/***********************************************************************************************************************
 *  Os_Hal_Sub4FromReg()
 **********************************************************************************************************************/
/*! \brief           Substruct 4 from the value of the passed register r1.
 *  \details         Needed to avoid the usage of conditional instructions which not accepted by thumb mode unless 
 *                   they are located under an IT block.
 *  \param[in, out]  r1 is the passed register from which 4 is substructed
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Sub4FromReg)
  sub     r1, r1, #4                   /* substruct 4 from r1 */
  bx      lr                           /* Return to the caller */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Sub4FromReg)

/***********************************************************************************************************************
 *  Os_Hal_UnhandledExceptionEntry()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UnhandledExceptionEntry)

  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */ 
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #7                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #7                                   /* r0 = Exception Id */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */
  cmp    r0, #7                                   /* Check if the exception is an FIQ of a derivative which does not support FIQs */
  bleq   Os_Hal_Sub4FromReg                       /* sub r1, r1, #4 */ /* r1 = LR_exc - 4 */ /* (LR_exc - 4) is the return address if the exception is an unhandled FIQ */
  
  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */

  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = LR_exc or (LR_exc - 4) if the exception is an unhandled FIQ  */  
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */

  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UnhandledExceptionEntry)

/***********************************************************************************************************************
 *  Os_Hal_UnhandledSysCallExceptionEntry()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UnhandledSysCallExceptionEntry)

  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  cps    #0x17              /* Change mode to ABT to save R0-R5 to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn since SP_svc does not hold the address of this var */
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  
  mov    r3, sp             /* r3 = SP_abt = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dy */   /* ( <----- R3 = Var Addr) */
  
  cps    #0x13              /* Change mode back to SVC to save LR_exc, SPSR_exc to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  str    lr, [r3, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [r3, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */

  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */  
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #2                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #2                                   /* r0 = Exception Id */

  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */  
  sub    r1, r1, #2                               /* r1 = (LR_exc - 2) is the undefined instruction address if the instruction set state was Thumb. */  
  and    r4, r2, #0x20                            /* Check the T bit of SPSR_exc to find out the previous instruction set state (ARM or thumb) */  
  cmp    r4, #0                                   /* Check if the mode was ARM or Thumb : R4 = 0 (ARM),  R4 = 1 (Thumb) */  
  bleq   Os_Hal_Sub2FromReg                       /* r1 = (LR_exc - 4) is the undefined instruction address if the instruction set state was ARM. */                           

  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = (LR_exc - 2) if instruction set state was Thumb, (LR_exc - 4) if instruction set state was ARM  */  
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */
    
  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UnhandledSysCallExceptionEntry)  
  
/***********************************************************************************************************************
 *  Os_Hal_UnhandledExceptionEntry_WithMemoryProtection()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection)  

  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */
  
  /* Save the user thread stack MPU registers to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn before programming the MPU stack region registers with kernel stack attributes */
  
  mov    r0, #OS_HAL_MP_STACK_REGION_NUMBER_ASM  /* r0 gets the MPU stack region number */
  mcr    p15,#0,r0,c6,c2,#0             /* Write STACK_REGION_NUMBER to RGNR register to be able to access the stack region mpu registers afterwards */
  
  mrc    p15,#0,r0,c6,c1,#0             /* r0 = Stack region DRBAR */
  str    r0, [r3, #0x28]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRBAR = Stack region DRBAR */
  
  mrc    p15,#0,r0,c6,c1,#4             /* r0 = Stack region DRACR */
  str    r0, [r3, #0x2C]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRACR = Stack region DRACR */
  
  mrc    p15,#0,r0,c6,c1,#2             /* r0 = Stack region DRSR */
  str    r0, [r3, #0x30]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRSR = Stack region DRSR register */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Reprogram the MPU stack region with the kernel stack region attributes. */

  ldr    r1, [r2, #4]                   /* r1 = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionStart */
  ldr    r4, [r2, #8]                   /* r4 = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionSize */  
  mov    r2, #0
  mcr    p15,#0,r2,c6,c1,#2             /* DRSR = 0 : Disable the MPU stack region before reprogramming it */ /* Note: Writing the MPU stack region number to RGNR was done above */
  mcr    p15,#0,r1,c6,c1,#0             /* DRBAR = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionStart */
  movw   r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT
  movt   r2, #0
  mcr    p15,#0,r2,c6,c1,#4             /* DRACR = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE | OS_HAL_MP_ACCESS_S_RW_U_RW) */
  mcr    p15,#0,r4,c6,c1,#2             /* DRSR = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionSize - This also enables the stack region (StackRegionSize attribute has the region enable bit set) */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #7                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #7                                   /* r0 = Exception Id */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */
  cmp    r0, #7                                   /* Check if the exception is an FIQ of a derivative which does not support FIQs */
  bleq   Os_Hal_Sub4FromReg                       /* sub r1, r1, #4 */ /* r1 = LR_exc - 4 */ /* (LR_exc - 4) is the return address if the exception is an unhandled FIQ */
  
  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */

  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = LR_exc or (LR_exc - 4) if the exception is an unhandled FIQ  */  
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */

  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection)

/***********************************************************************************************************************
*  Os_Hal_UndefinedInstructionExceptionEntry()
**********************************************************************************************************************/
/*! \brief          Low level undefined instruction exception handler which saves minimum of interrupted context to be
 *                  able to call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \param[in]      Addr  Address of the executing instruction when the undefined instruction exception happened.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UndefinedInstructionExceptionEntry)
  
  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */  
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #1                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #1                                   /* r0 = Exception Id */

  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */  
  sub    r1, r1, #2                               /* r1 = (LR_exc - 2) is the undefined instruction address if the instruction set state was Thumb. */  
  and    r4, r2, #0x20                            /* Check the T bit of SPSR_exc to find out the previous instruction set state (ARM or thumb) */  
  cmp    r4, #0                                   /* Check if the mode was ARM or Thumb : R4 = 0 (ARM),  R4 = 1 (Thumb) */  
  bleq   Os_Hal_Sub2FromReg                       /* r1 = (LR_exc - 4) is the undefined instruction address if the instruction set state was ARM. */                           

  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = (LR_exc - 2) if instruction set state was Thumb, (LR_exc - 4) if instruction set state was ARM  */  
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */

  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UndefinedInstructionExceptionEntry)

/***********************************************************************************************************************
 *  Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection)
  
  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */
  
  /* Save the user thread stack MPU registers to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn before programming the MPU stack region registers with kernel stack attributes */
  
  mov    r0, #OS_HAL_MP_STACK_REGION_NUMBER_ASM  /* r0 gets the MPU stack region number */
  mcr    p15,#0,r0,c6,c2,#0             /* Write STACK_REGION_NUMBER to RGNR register to be able to access the stack region mpu registers afterwards */
  
  mrc    p15,#0,r0,c6,c1,#0             /* r0 = Stack region DRBAR */
  str    r0, [r3, #0x28]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRBAR = Stack region DRBAR */
  
  mrc    p15,#0,r0,c6,c1,#4             /* r0 = Stack region DRACR */
  str    r0, [r3, #0x2C]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRACR = Stack region DRACR */
  
  mrc    p15,#0,r0,c6,c1,#2             /* r0 = Stack region DRSR */
  str    r0, [r3, #0x30]                /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.DRSR = Stack region DRSR register */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Reprogram the MPU stack region with the kernel stack region attributes. */

  ldr    r1, [r2, #4]                   /* r1 = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionStart */
  ldr    r4, [r2, #8]                   /* r4 = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionSize */  
  mov    r2, #0
  mcr    p15,#0,r2,c6,c1,#2             /* DRSR = 0 : Disable the MPU stack region before reprogramming it */ /* Note: Writing the MPU stack region number to RGNR was done above */
  mcr    p15,#0,r1,c6,c1,#0             /* DRBAR = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionStart */
  movw   r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT
  movt   r2, #0
  mcr    p15,#0,r2,c6,c1,#4             /* DRACR = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE | OS_HAL_MP_ACCESS_S_RW_U_RW) */
  mcr    p15,#0,r4,c6,c1,#2             /* DRSR = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionSize - This also enables the stack region (StackRegionSize attribute has the region enable bit set) */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #1                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #1                                   /* r0 = Exception Id */

  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */  
  sub    r1, r1, #2                               /* r1 = (LR_exc - 2) is the undefined instruction address if the instruction set state was Thumb. */  
  and    r4, r2, #0x20                            /* Check the T bit of SPSR_exc to find out the previous instruction set state (ARM or thumb) */  
  cmp    r4, #0                                   /* Check if the mode was ARM or Thumb : R4 = 0 (ARM),  R4 = 1 (Thumb) */  
  bleq   Os_Hal_Sub2FromReg                       /* r1 = (LR_exc - 4) is the undefined instruction address if the instruction set state was ARM. */                           

  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = (LR_exc - 2) if instruction set state was Thumb, (LR_exc - 4) if instruction set state was ARM  */  
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */

  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection)

/***********************************************************************************************************************
*  Os_Hal_DataAbortExceptionEntry()
**********************************************************************************************************************/
/*! \brief          Low level data abort exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \param[in]      Addr  Address of the executing instruction when the data abort exception happened.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_DataAbortExceptionEntry)
  
  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */  
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #4                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #4                                   /* r0 = Exception Id */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */  
  sub    r1, r1, #8                               /* r1 = (LR_exc - 8) is the instruction address that caused the Data Abort */

  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = (LR_exc - 8) is the instruction address that caused the Data Abort */
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */
    
  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_DataAbortExceptionEntry)

/***********************************************************************************************************************
*  Os_Hal_PrefetchAbortExceptionEntry()
**********************************************************************************************************************/
/*! \brief          Low level data abort exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \param[in]      Addr  Address of the executing instruction when the prefetch abort exception happened.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_PrefetchAbortExceptionEntry)

  /* Save registers to the var OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  /* ------------------------------------------------------------------ */
  
  /* . The Registers to save intermediately are: R0,.., R5, LR_exc, SPSR_exc, SP_sys, LR_sys.            */
  /* . SP_und, SP_abt, SP_fiq, initialised in Os_Hal_CoreInit(), contain the address                     */
  /*   of OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.                                                      */
  
  stm    sp, {r0-r5}        /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0-R5 = R0-R5 */
  str    lr, [sp, #0x18]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_exc = LR_exc */
  mrs    r0, spsr           /* R0 = SPSR */
  str    r0, [sp, #0x1C]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SPSR_exc = SPSR_exc */
  
  /* Save SP_sys,LR_sys to OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys,LR_sys */
  
  mov    r3, sp             /* R3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */           /* ( <----- R3 = Var Addr) */
  cps    #0x1F              /* Change mode to SYS mode to save LR_sys */                   /* ( <----- SYS Mode     ) */
  str    sp, [r3, #0x20]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.SP_sys = SP_sys */
  str    lr, [r3, #0x24]    /* OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.LR_sys = LR_sys */
  
  /* Switch to kernel stack */
  /* ---------------------- */
  
  /* Note: The current processor mode is SYS mode. */  
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */                     /* ( <----- R0 = Current Core Id) */
  
  /* Set SP_sys to point to the end of kernel stack. */
  
  Os_Hal_Asm_LoadRegister32 r1, OsCfg_Stack_KernelStacks   /* r1 = &OsCfg_Stack_KernelStacks[0] */  
  mov    r2, #0x4                       /* OsCfg_Stack_KernelStacks has offset size of 4 */  
  mul    r2, r2, r0                     /* r2 = r2 * r0 = 4 * CoreId */  
  add    r1, r1, r2                     /* r1 = r1 + r2 = &OsCfg_Stack_KernelStacks[0] + 4 * CoreId = &OsCfg_Stack_KernelStacks[CoreId] */  
  ldr    r2, [r1, #0]                   /* r2 = OsCfg_Stack_KernelStacks[CoreId] = &OsCfg_Hal_Stack_OsCoreX_Kernel */
  ldr    sp, [r2, #0]                   /* SP_sys = OsCfg_Hal_Stack_OsCoreX_Kernel.StackRegionEnd */
  
  /* Save the exception context */
  /* -------------------------- */
  
  mov    r1, #3                         /* R1 = Exception Id */                            /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_UnhandledExc() */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_UnhandledExc() */
  
  mov    r0, #3                                   /* r0 = Exception Id */
  
  ldr    r1, [r3, #0x18]                          /* r1 = LR_exc */  
  sub    r1, r1, #4                               /* r1 = (LR_exc - 4) is the instruction address that caused the Prefetch Abort */

  ldr    r2, [r3, #0x1C]                          /* r2 = SPSR_exc */
  and    r2, r2, #0x0F                            /* r2 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_UnhandledExc() call:               */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = Exception Id */
  /*   - r1 = (LR_exc - 4) is the instruction address that caused the Prefetch Abort */
  /*   - r2 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_UnhandledExc  /* Jump to the C-function Os_UnhandledExc() */
  
  pop    {r9, r12}        /* Pop r9, r12 from kernel stack */
    
  /* Write modified Exc Context to HW Regs */
  /* ------------------------------------- */

  /* Prepare parameters for Os_Hal_Context_RestoreUpdatedExcContext() */
  
  /* Get the core ID */
  
  bl     Os_Hal_CoreGetId_Asm  /* Note: LR_sys is overwritten by bl */
  
  /* Passed parameter: */
  /*   - R0 holding the core Id */
  
  bl     Os_Hal_Context_RestoreUpdatedExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Return from exception */
  /* --------------------- */
  
  /* Notes:       */
  /*   - r5 holds &OsCfg_Hal_Context_ExceptionContextRef */
  /*   - r3 holds &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */  
  /*   - The current SP is the previous thread SP */
  /*   - The current processor mode is SYS mode. */
  
  /* Prepare SPSR_exc and ReturnAddress for rfefd at the end */  
  
  ldr    r2, [r3, #0x1C]     /* r2 = SPSR_exc */  
  ldr    r1, [r5, #0x148]    /* r1 gets StructVar.ReturnAddress */  
  
  push   {r1-r2}             /* Push ReturnAddress, SPSR_exc to the previous stack (needed for rfefd at the end) */
  
  /* Update r0-r5 from StructVar.PreviousModeGpRegisters.r0-r5 */
  
  add    r5, r5, #4          /* r5 gets the address of StructVar.PreviousModeGpRegisters.R0 */
  ldm    r5, {r0-r5}         /* r0-r5 = StructVar.PreviousModeGpRegisters.r0-r5 */
  
  /* Leave the exception handler */
  
  rfefd  sp!                /* Return from Exception : pop {r1-r2} i.e. (PC = StructVar.ReturnAddress ; CPSR = SPSR_exc) */
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_PrefetchAbortExceptionEntry)


#endif /* defined(OS_HAL_ENTRY_EXC_HANDLERS_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_ExcHandlers.inc
 *********************************************************************************************************************/
