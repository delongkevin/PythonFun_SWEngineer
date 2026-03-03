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
 * \addtogroup   Os_Hal_Context
 * \{
 *
 * \file  Os_Hal_ContextAsm_v7r_ExcHandlers.inc
 * \brief  This component contains Cortex-R specific assembly functions.
 * \details
 * \internal
 *  Hardware manuals: See derivative specific header (Os_Hal_Derivative_*Int.h)
 *  Errata sheets: See derivative specific header
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

#ifndef OS_HAL_CONTEXTASM_V7R_EXC_HANDLERS_INC
# define OS_HAL_CONTEXTASM_V7R_EXC_HANDLERS_INC

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Os_Hal_ContextAsm_ExceptionContext.inc"
# if defined(OS_CFG_DERIVATIVEGROUP_E36XX)    || \
     defined(OS_CFG_DERIVATIVEGROUP_E34XX)    || \
     defined(OS_CFG_DERIVATIVEGROUP_G9X)      || \
     defined(OS_CFG_DERIVATIVEGROUP_AM26XX)   || \
     defined(OS_CFG_DERIVATIVEGROUP_JACINTO7) || \
     defined(OS_CFG_DERIVATIVEGROUP_ZUXXX)
#   include "Os_Hal_Core_MultiProcessorGroups.inc"
# else
#   include "Os_Hal_Core_OneProcessorGroup.inc"
# endif

/***********************************************************************************************************************
 *  CONSTANT MACROS
 **********************************************************************************************************************/
/*! Access right value used for stack region (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN |
 *  OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE | OS_HAL_MP_ACCESS_S_RW_U_RW). */
# define OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT   0x130B

/***********************************************************************************************************************
 *  FUNCTIONS
 **********************************************************************************************************************/
  OS_HAL_ASM_PRESERVE8
  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_EXPORT(Os_Hal_MemFault_PrefetchAbort)
  OS_HAL_ASM_EXPORT(Os_Hal_MemFault_DataAbort)
  OS_HAL_ASM_EXPORT(Os_Hal_SysCallHandler)
  OS_HAL_ASM_EXPORT(Os_Hal_SysCallHandler_Jacinto7)

  OS_HAL_ASM_IMPORT(OsCfg_Stack_KernelStacks)
  OS_HAL_ASM_IMPORT(Os_MemFault)
  OS_HAL_ASM_IMPORT(Os_TrapHandler)

/***********************************************************************************************************************
 *  Os_Hal_SysCallHandler()
 **********************************************************************************************************************/
/*! \brief          Low level system call handler which saves minimum of interrupted context to be able to call a
 *                  C-function.
 *  \details        -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_SysCallHandler)
  srsfd   sp!, #0x1f                        /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                             /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                 /* Store registers is the system stack */
  add     r1, sp, #0x20                     /* Store the trap parameter in R1 */
  bl      Os_TrapHandler                    /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                 /* Restore previously saved registers */
  rfefd   sp!                               /* Return from Exception: load PC, CPSR with the words in the system stack*/
  OS_HAL_ASM_FUNCTION_END(Os_Hal_SysCallHandler)

/***********************************************************************************************************************
 *  Os_Hal_SysCallHandler_Jacinto7()
 **********************************************************************************************************************/
/*! \brief          Low level system call handler which saves minimum of interrupted context to be able to call a
 *                  C-function.
 *  \details        -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_SysCallHandler_Jacinto7)
  cpsid   f                                 /* Disable FIQs */
  mov lr, r1                                /* Restore saved LR */
  srsfd   sp!, #0x1f                        /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                             /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                 /* Store registers is the system stack */
  add     r1, sp, #0x20                     /* Store the trap parameter in R1 */
  bl      Os_TrapHandler                    /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                 /* Restore previously saved registers */
  rfefd   sp!                               /* Return from Exception: load PC, CPSR with the words in the system stack*/
  OS_HAL_ASM_FUNCTION_END(Os_Hal_SysCallHandler_Jacinto7)

/***********************************************************************************************************************
 *  Os_Hal_MemFault_PrefetchAbort()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_MemFault_PrefetchAbort)

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
  
  bl     Os_Hal_CoreGetId_Asm           /* Note: LR_sys is overwritten by bl */            /* ( <----- R0 = Current Core Id) */
  
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
  
  mov    r1, #3                         /* R1 = Exception Id */                  /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_MemFault()     */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_MemFault() */
    
  ldr    r0, [r3, #0x18]                          /* r0 = LR_exc */  
  sub    r0, r0, #4                               /* r0 = (LR_exc - 4) is the instruction address that caused the Prefetch Abort */

  ldr    r1, [r3, #0x1C]                          /* r1 = SPSR_exc */
  and    r1, r1, #0x0F                            /* r1 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_MemFault() call:                   */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = (LR_exc - 4) is the instruction address that caused the Prefetch Abort */
  /*   - r1 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_MemFault      /* Jump to the C-function Os_MemFault() */
  
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
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_MemFault_PrefetchAbort)

/***********************************************************************************************************************
 *  Os_Hal_MemFault_DataAbort()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_MemFault_DataAbort)

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

  bl     Os_Hal_CoreGetId_Asm           /* Note: LR_sys is overwritten by bl */            /* ( <----- R0 = Current Core Id) */
  
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
  
  mov    r1, #4                         /* R1 = Exception Id */                  /* ( <----- R1 = Exception Id   ) */
  
  /* Passed parameters: */
  /*   - R0 holding the core Id */
  /*   - R1 holding the exception Id */
  /*   - R3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */

  bl     Os_Hal_Context_SaveExcContext  /* Note: LR_sys is overwritten by bl */
  
  /* Jump to the C-function Os_MemFault()     */
  /* ---------------------------------------- */
  
  /* Note: Before leaving Os_Hal_Context_SaveExcContext the mode was changed to SYS. */
  
  /* Prepare parameters for Os_MemFault() */
    
  ldr    r0, [r3, #0x18]                          /* r0 = LR_exc */  
  sub    r0, r0, #8                               /* r0 = (LR_exc - 8) is the instruction address that caused the Data Abort */

  ldr    r1, [r3, #0x1C]                          /* r1 = SPSR_exc */
  and    r1, r1, #0x0F                            /* r1 gets 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  /* Save registers which are not preserved by Os_MemFault() call:                   */
  /*  - R0-R5, LR_exc are already saved in OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn  */  
  /*  - R4-R8, r10, R11 and SP are preserved by a subroutine call                    */
    
  push   {r9, r12}        /* Push r9, r12 to kernel stack */
  
  /* Passed parameters: */
  /*   - r0 = (LR_exc - 8) is the instruction address that caused the Data Abort */
  /*   - r1 = 0 (User mode was active) , !0 (one of the other privileged modes was active) */
  
  bl     Os_MemFault      /* Jump to the C-function Os_MemFault() */
  
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
  
  OS_HAL_ASM_FUNCTION_END(Os_Hal_MemFault_DataAbort)

#endif /* defined(OS_HAL_CONTEXTASM_V7R_EXC_HANDLERS_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_ContextAsm_v7r_ExcHandlers.inc
 *********************************************************************************************************************/
