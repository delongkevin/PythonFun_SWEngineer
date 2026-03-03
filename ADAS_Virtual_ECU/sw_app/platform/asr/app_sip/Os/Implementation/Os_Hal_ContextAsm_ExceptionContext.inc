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
 *  \addtogroup   Os_Hal_Context
 *  \{
 *
 *  \file    Os_Hal_ContextAsm_ExceptionContext.inc
 *  \brief   This component contains Cortex-R specific assembly functions.
 *  \details -
 *  \internal
 *   Hardware manuals: See derivative specific header (Os_Hal_Derivative_*Int.h)
 *   Errata sheets: -
 *   Access mechanism: -
 *   Used registers: -
 *   Hardware features related to independence or partitioning: -
 *   Operating modes: -
 *   Hardware diagnostics: -
 *   Specifics: -
 *  \endinternal
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_EXCEPTION_CONTEXT_INC
# define OS_HAL_EXCEPTION_CONTEXT_INC

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Os_Hal_Compiler.inc"
# include "Os_Hal_Core_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  ...
 *********************************************************************************************************************/
  OS_HAL_ASM_PRESERVE8

  OS_HAL_ASM_IMPORT(Os_Hal_CoreExceptionGetInterruptLockLevel)
  OS_HAL_ASM_IMPORT(Os_Hal_CoreExceptionSetInterruptLockLevel)

  OS_HAL_ASM_CODE_SECTION(OS_CODE)

/***********************************************************************************************************************
 *  Helper functions needed to perform conditional execution compatible with ARM and thumb instruction sets.
 ***********************************************************************************************************************
 *
 *  Notes: 
 *   - Conditional instructions (e.g.: movne) are allowed in thumb mode if they are located in an IT block.
 *   - Adding IT instructions to the code is not accepted by some compilers when compiling in ARM mode.
 *   - Branching instructions (e.g.: bl) are allowed in thumb mode outside an IT block.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_WriteSysModeToReg()
 **********************************************************************************************************************/
/*! \brief        Writes the System mode bits 0x1F to a register
 *  \details      -
 *  \param[out]   r0 : destination register
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/ 
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_WriteSysModeToReg)
  mov r0, #0x1F                  /* r0 gets SYS mode */
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_WriteSysModeToReg)

/***********************************************************************************************************************
 *  Os_Hal_Copy_SP_sys_FromVarToReg()
 **********************************************************************************************************************/
/*! \brief        Copies System Stack Pointer from a variabe to a register
 *  \details      -
 *  \param[out]   r2 : destination register
 *  \param[in]    r3 : holds address of the variable that intermediately saves registers at exception entry
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/  
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Copy_SP_sys_FromVarToReg)
  ldr  r2, [r3, #0x20]           /* r2 gets SP_sys from OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  bx   lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Copy_SP_sys_FromVarToReg)

/***********************************************************************************************************************
 *  Os_Hal_Copy_LR_sys_FromVarToReg()
 **********************************************************************************************************************/
/*! \brief        Copies System Link Register from a variabe to a register
 *  \details      -
 *  \param[out]   r2 : destination register
 *  \param[in]    r3 : holds address of the variable that intermediately saves registers at exception entry
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/ 
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Copy_LR_sys_FromVarToReg)
  ldr  r2, [r3, #0x24]           /* r2 gets LR_sys from OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  bx   lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Copy_LR_sys_FromVarToReg)

/***********************************************************************************************************************
 *  Os_Hal_WriteDummyToReg()
 **********************************************************************************************************************/
/*! \brief        Writes a dummy value (0xDEAD) to a register
 *  \details      -
 *  \param[out]   r2 : destination register
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/   
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_WriteDummyToReg)
  movw r2, #0xDEAD               /* r2 = 0xDEAD */
  bx   lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_WriteDummyToReg)
  
/***********************************************************************************************************************
 *  Os_Hal_StoreDataFaultRegisters()
 **********************************************************************************************************************/
/*! \brief        Stores data fault registers (DFSR, ADFSR, DFAR) to exception context structure variable
 *  \details      r0 is overwritten in this function
 *  \param[out]   Data fault registers attributes of the exception context structure variable 
 *  \param[in]    r5 : holds address of the exception context structure variable
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/ 
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StoreDataFaultRegisters)
  mrc  p15, #0, r0, c5, c0, #0   /* Read DFSR into r0 */
  str  r0, [r5, #0x94]           /* Store DFSR */
  mrc  p15, #0, r0, c5, c1, #0   /* Read ADFSR into r0 */
  str  r0, [r5, #0x98]           /* Store ADFSR */  
  mrc  p15, #0, r0, c6, c0, #0   /* Read DFAR into r0 */
  str  r0, [r5, #0x9C]           /* Store DFAR */ 
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StoreDataFaultRegisters)

/***********************************************************************************************************************
 *  Os_Hal_StoreDummyForDataFaultRegisters()
 **********************************************************************************************************************/
/*! \brief        Writes a dummy value to data fault registers (DFSR, ADFSR, DFAR) attributes of the exception context 
 *                structure variable
 *  \details      r0 is overwritten in this function
 *  \param[out]   Data fault registers attributes of the exception context structure variable
 *  \param[in]    r5 : holds address of the exception context structure variable
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/   
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StoreDummyForDataFaultRegisters)  
  movw r0, #0xDEAD
  str  r0, [r5, #0x94]           /* ContextVar.DFSR  = 0xDEAD */
  str  r0, [r5, #0x98]           /* ContextVar.ADFSR = 0xDEAD */
  str  r0, [r5, #0x9C]           /* ContextVar.DFAR  = 0xDEAD */
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StoreDummyForDataFaultRegisters)

/***********************************************************************************************************************
 *  Os_Hal_StoreInstructionFaultRegisters()
 **********************************************************************************************************************/
/*! \brief        Stores instruction fault registers (IFSR, AIFSR, IFAR) to exception context structure variable
 *  \details      r0 is overwritten in this function
 *  \param[out]   Instruction fault registers attributes of the exception context structure variable 
 *  \param[in]    r5 : holds address of the exception context structure variable
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/  
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StoreInstructionFaultRegisters)
  mrc  p15, #0, r0, c5, c0, #1   /* Read IFSR into r0 */
  str  r0, [r5, #0xA0]           /* Store IFSR */  
  mrc  p15, #0, r0, c5, c1, #1   /* Read AIFSR into r0 */
  str  r0, [r5, #0xA4]           /* Store AIFSR */
  mrc  p15, #0, r0, c6, c0, #2   /* Read IFAR into r0 */
  str  r0, [r5, #0xA8]           /* Store IFAR */
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StoreInstructionFaultRegisters)

/***********************************************************************************************************************
 *  Os_Hal_StoreDummyForInstructionFaultRegisters()
 **********************************************************************************************************************/
/*! \brief        Writes a dummy value to instruction fault registers (DFSR, ADFSR, DFAR) attributes of the exception 
 *                context structure variable
 *  \details      r0 is overwritten in this function
 *  \param[out]   Instruction fault registers attributes of the exception context structure variable
 *  \param[in]    r5 : holds address of the exception context structure variable
 *  \param[in]    lr : link register holding the return address
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/ 
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StoreDummyForInstructionFaultRegisters)  
  movw r0, #0xDEAD
  str  r0, [r5, #0xA0]           /* ContextVar.IFSR  = 0xDEAD */
  str  r0, [r5, #0xA4]           /* ContextVar.AIFSR = 0xDEAD */
  str  r0, [r5, #0xA8]           /* ContextVar.IFAR  = 0xDEAD */
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StoreDummyForInstructionFaultRegisters)

/***********************************************************************************************************************
 *  Os_Hal_RetAddr_Und_Svc_Thumb()
 **********************************************************************************************************************/
/*! \brief           Stores the return address for Undefined-Inst Exc and SVC to a register when the mode was Thumb.
 *  \details         Needed to avoid the usage of conditional instructions which not accepted by thumb mode unless 
 *                   they are located under an IT block.
 *  \param[in,out]   r0 : holds (LR_exc - 4) when entering this function - will hold (LR_exc - 2) when leaving
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/ 
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_RetAddr_Und_Svc_Thumb)
  add r0, r0, #2    /* r0 = (LR_exc - 4) + 2 = (LR_exc - 2) */
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_RetAddr_Und_Svc_Thumb)

/***********************************************************************************************************************
 *  Os_Hal_RetAddr_Und_Svc()
 **********************************************************************************************************************/
/*! \brief           Stores the return address for Undefined-Inst Exc and SVC to a register.
 *  \details         Needed to avoid the usage of conditional instructions which not accepted by thumb mode unless 
 *                   they are located under an IT block.
 *  \param[in,out]   r0 : holds (LR_exc - 4) when entering this function - will hold the return address when leaving
 *  \param[in]       r4 : holds previous instruction set (0: ARM, 1: Thumb)
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_RetAddr_Und_Svc)  
  cmp   r4, #0                        /* Check if the mode was ARM or Thumb : R4 = 0 (ARM),  R4 != 0 (Thumb) */
  
  push  {lr}                          /* Push LR_sys to kernel stack to be able to return from this function */
  blne  Os_Hal_RetAddr_Und_Svc_Thumb  /* r0 = (LR_exc - 2) [Thumb] */ /* LR_sys is overwritten by blne */
  pop   {lr}                          /* Pop LR_sys from kernel stack to be able to return from this function */  
  
  bx lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_RetAddr_Und_Svc)

/***********************************************************************************************************************
 *  Os_Hal_RetAddr_DABT()
 **********************************************************************************************************************/
/*! \brief           Stores the return address for DABT exc to a register.
 *  \details         Needed to avoid the usage of conditional instructions which not accepted by thumb mode unless 
 *                   they are located under an IT block.
 *  \param[in,out]   r0 : holds (LR_exc - 4) when entering this function - will hold (LR_exc - 8) when leaving
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_RetAddr_DABT)  
  sub r0, r0, #4  
  bx lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_RetAddr_DABT)

/***********************************************************************************************************************
 *  Os_Hal_RetAddr_Fiq()
 **********************************************************************************************************************/
/*! \brief           Stores the return address of an FIQ exc to a register.
 *  \details         The return address is the address of the instruction that was not executed because FIQ took 
 *                   priority. When the FIQ exception occurs, LR is assigned (Instruction Address + 4).
 *                   This function needed to avoid the usage of conditional instructions which not accepted by thumb 
 *                   mode unless they are located under an IT block.
 *  \param[in,out]   r0 : holds LR_exc when entering this function - will hold (LR_exc - 4) when leaving
 *  \param[in]       lr : link register holding the return address
 *  \context         OS_INTERNAL
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *  \pre             -
**********************************************************************************************************************/
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_RetAddr_Fiq)  
  sub r0, r0, #4  
  bx  lr
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_RetAddr_Fiq)
  
/***********************************************************************************************************************
 *  Os_Hal_Context_SaveExcContext()
 **********************************************************************************************************************/
/*! \brief        Saves the exception context in a variable of type structure.
 *  \details      Called from exception handlers.
 *                r5 is used to hold &OsCfg_Hal_Context_OsCoreX_ExceptionContext along this function. 
 *                {r3,r6..r12, sp, lr} shall not be modified by this function.
 *  \param[in]    r0 : holds the Core Id
 *  \param[in]    r1 : holds the Exception Id
 *  \param[in]    r3 : holds address of the variable that intermediately saves registers at exception entry
 *  \param[in]    LR_sys : System mode link register holding the return address
 *  \param[out]   Destination exception context structure variable
 *  \context      OS_INTERNAL
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Context_SaveExcContext)

  push {lr}  /* LR_sys will be overwritten when calling the helper aub-function -> Store it to in kernel stack (SYS stack) */

  /* Get the address of the destination struct var in r5  */
  /* ---------------------------------------------------- */
  
  OS_HAL_ASM_IMPORT(OsCfg_Hal_Context_ExceptionContextRef)                      /* Declare OsCfg_Hal_Context_ExceptionContextRef defined in Os_Hal_Context_Lcfg.c */ 
  Os_Hal_Asm_Load_Register_Immediate r5, OsCfg_Hal_Context_ExceptionContextRef  /* r5 gets the address of the array OsCfg_Hal_Context_ExceptionContextRef[] */
  
  /* (1) r0 = CoreId << 2 = (4 * CoreId) : r0 gets the offset to &OsCfg_Hal_Context_OsCoreX_ExceptionContext element in OsCfg_Hal_Context_ExceptionContextRef[] array */
  /* (2) r5 = &OsCfg_Hal_Context_ExceptionContextRef[0] + (4 * CoreId) = &OsCfg_Hal_Context_ExceptionContextRef[CoreId] */
  /* (3) r5 = OsCfg_Hal_Context_ExceptionContextRef[CoreId] = &OsCfg_Hal_Context_OsCoreX_ExceptionContext ; X = CoreId */
  
  ldr  r5, [r5, r0, lsl #2]

  /* Copy Exception Id */
  /* ----------------- */
  
  str r1, [r5]             /* ContextVar.ExceptionId = r1 (r1 holds the exception Id) */
  
  /* Change the mode to the previous mode or to SYS mode if previous mode was User    */
  /* -------------------------------------------------------------------------------- */
  
  /* Note: The current cpu mode is SYS mode. */
  /* Note: Some registers are not accessible in User mode (e.g.: TPIDRURO, DFSR, DFAR) */
  /*       -> Stay in SYS mode if the previous mode was User.*/
  
  ldr   r0, [r3, #0x1C]    /* r0 = SPSR_exc */
  and   r0, r0, #0x1F      /* r0 gets the previous cpu mode bits. */
  cmp   r0, #0x10          /* Check if the previous mode was User mode. */
  bleq  Os_Hal_WriteSysModeToReg  /* mov r0, #0x1F */ /* LR_sys is overwritten by bleq */ /* If the previous mode was User, r0 gets SYS mode instead. */       /* ( <----- r0 = previous mode) */
  
  mrs   r2, cpsr           /* r2 gets CPSR content */  
  movw  r4, #0xFFE0        /* Save mode mask in r4 (LSB bits) */
  movt  r4, #0xFFFF        /* Save mode mask in r4 (MSB bits) */
  and   r2, r2, r4         /* r2 = CPSR with mode bits set to 0 */
  orr   r2, r2, r0         /* Fill mode bits with previous mode or with SYS mode if the previous mode was User */
  msr   cpsr_cxsf, r2      /* Write CPSR to change the cpu mode to the mode previous to the exception or to SYS if the previous mode was User.*/
  
  /* Copy previous mode GP registers to StructVar         */
  /* ---------------------------------------------------- */
  
  /* Note: The current cpu mode is the mode previous to the exception or SYS mode if the previous mode was User. */
  
  /* Store R0..R5 */
  ldr r4, [r3]             /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R0 */
  str r4, [r5, #0x04]      /* Store R0 of previous mode */
  
  ldr r4, [r3, #0x04]      /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R1 */
  str r4, [r5, #0x08]      /* Store R1 of previous mode */
  
  ldr r4, [r3, #0x08]      /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R2 */
  str r4, [r5, #0x0C]      /* Store R2 of previous mode */
  
  ldr r4, [r3, #0x0C]      /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R3 */
  str r4, [r5, #0x10]      /* Store R3 of previous mode */
  
  ldr r4, [r3, #0x10]      /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R4 */
  str r4, [r5, #0x14]      /* Store R4 of previous mode */
  
  ldr r4, [r3, #0x14]      /* r4 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.R5 */
  str r4, [r5, #0x18]      /* Store R5 of previous mode */
  
  /* Store R6..R12 */
  str  r6,  [r5, #0x1C]
  str  r7,  [r5, #0x20]
  str  r8,  [r5, #0x24]
  str  r9,  [r5, #0x28]
  str  r10, [r5, #0x2C]
  str  r11, [r5, #0x30]
  str  r12, [r5, #0x34]
 
  /* Store SP */
  /* Note: r0 was assigned previous mode bits above. When previus mode was User, r0 was assigned SYS mode bits. */
  
  mov   r2, sp             /* r2 = SP of previous mode */

  cmp   r0, #0x1F          /* Compare previous mode with SYS mode */
  bleq  Os_Hal_Copy_SP_sys_FromVarToReg  /* ldr r2, [r3, #0x20] */ /* LR_sys is overwritten by bleq */ /* SP_sys was overwritten and is used for kernel stack -> Get it from OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn if pervious mode was User or SYS */  

  cmp   r0, #0x11          /* Compare previous mode with FIQ mode */
  mov   r4, lr             /* Save lr in r4 in order to restore it after the bleq instruction. */
  bleq  Os_Hal_WriteDummyToReg           /* mov r2, #0xDEAD     */ /* LR_fiq is overwritten by bleq */ /* SP_Fiq was used to save OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn address -> Write 0xDEAD to StructVar.PreviousModeGpRegisters.SP  */
  mov   lr, r4             /* Restore lr from r4 */

  str    r2, [r5, #0x38]   /* Store SP of previous mode or 0xDEAD if previous mode was one of {FIQ, ABT, UND} */
  
  /* Store LR */
  /* Note: r0 was assigned previous mode bits above. When previus mode was User, r0 was assigned SYS mode bits. */
  
  mov  r2, lr              /* r2 = LR of previous mode */
  cmp  r0, #0x1F           /* Compare previous mode with SYS mode */  
  bleq Os_Hal_Copy_LR_sys_FromVarToReg   /* ldr  r2, [r3, #0x24] */ /* LR_sys is overwritten by bleq */ /* LR_sys was overwritten already when branching to this function -> Get it from OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn if pervious mode was User or SYS */    
  str  r2, [r5, #0x3C]     /* Store LR of previous mode */

  /* Copy Banked Registers                                */
  /* ---------------------------------------------------- */
  
  /* Copy FIQ mode banked registers */
  
  cps  #0x11             /* change to FIQ mode */
  str  r8,  [r5, #0x40]  /* Store R8_fiq - Note: The stm instruction cannot be used for R8_fiq..R14_fiq. */
  str  r9,  [r5, #0x44]  /* Store R9_fiq */
  str  r10, [r5, #0x48]  /* Store R10_fiq */
  str  r11, [r5, #0x4C]  /* Store R11_fiq */
  str  r12, [r5, #0x50]  /* Store R12_fiq */
  movw r0,  #0xDEAD
  str  r0,  [r5, #0x54]  /* StructVar.SP_fiq = 0xDEAD since SP_fiq was used to store OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn adddress. */
  str  lr,  [r5, #0x58]  /* Sore LR_fiq */
  mrs  r0,  spsr         /* r0 = SPSR_fiq */
  str  r0,  [r5, #0x5C]  /* Store SPSR_fiq */
  
  /* Copy IRQ mode banked registers */
  
  cps  #0x12             /* change to IRQ mode */
  str  sp, [r5, #0x60]   /* Sore SP_irq */
  str  lr, [r5, #0x64]   /* Sore LR_irq */
  mrs  r0, spsr          /* r0 = SPSR_irq */
  str  r0, [r5, #0x68]   /* Store SPSR_irq */
  
  /* Copy ABT mode banked registers */
  
  cps  #0x17             /* change to ABT mode */
  movw r0,  #0xDEAD
  str  r0, [r5, #0x6C]   /* StructVar.SP_abt = 0xDEAD since SP_fiq was used to store OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn address. */
  str  lr, [r5, #0x70]   /* Sore LR_abt */
  mrs  r0, spsr          /* r0 = SPSR_abt */
  str  r0, [r5, #0x74]   /* Store SPSR_abt */
  
  /* Copy SVC mode banked registers */
  
  cps  #0x13             /* change to SVC mode */
  str  sp, [r5, #0x78]   /* Sore SP_svc */
  str  lr, [r5, #0x7C]   /* Sore LR_svc */
  mrs  r0, spsr          /* r0 = SPSR_svc */
  str  r0, [r5, #0x80]   /* Store SPSR_svc */
  
  /* Copy UND mode banked registers */
  
  cps  #0x1B             /* change to UND mode */
  movw r0,  #0xDEAD
  str  r0, [r5, #0x84]   /* StructVar.SP_und = 0xDEAD since SP_fiq was used to store OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn address. */
  str  lr, [r5, #0x88]   /* Sore LR_und */
  mrs  r0, spsr          /* r0 = SPSR_und */
  str  r0, [r5, #0x8C]   /* Store SPSR_und */

  /* Change mode to SYS mode at the end of this section. When BL instruction is used afterwards, LR_sys will be overwritten. */
  
  cps #0x1F
  
  /* Copy Thread ID Register TPIDRURO                     */
  /* ---------------------------------------------------- */  
  
  mrc  p15, #0, r0, c13, c0, #3  /* r0 = TPIDRURO content */
  str  r0, [r5, #0x90]           /* StructVar.ThreadId = TPIDRURO content */

  /* Copy Data Fault Registers                            */
  /* ---------------------------------------------------- */
  
  cmp r1, #4 /* Check if the exception is Data Abort (r1 holds the exception Id) */
  
  /* Store Data Fault registers DFSR, ADFSR, DFAR if the exception is Data Abort */
  bleq Os_Hal_StoreDataFaultRegisters  /* LR_sys is overwritten by bleq */
  
  /* Write 0xDEAD to ContextVar.DFSR, ADFSR, DFAR if the exception is not Data Abort */
  blne  Os_Hal_StoreDummyForDataFaultRegisters /* LR_sys is overwritten by blne */
  
  /* Copy Instruction Fault Registers                     */
  /* ---------------------------------------------------- */
  
  cmp r1, #3 /* Check if the exception is Prefetch Abort (r1 holds the exception Id) */
  
  /* Store Instruction Fault registers IFSR, IDFSR, IFAR if the exception is Prefetch Abort */
  bleq  Os_Hal_StoreInstructionFaultRegisters /* LR_sys is overwritten by bleq */
  
  /* Write 0xDEAD to ContextVar.IFSR, AIFSR, IFAR if the exception is not Prefetch Abort */
  blne Os_Hal_StoreDummyForInstructionFaultRegisters /* LR_sys is overwritten by blne */
  
  /* Copy FPU registers                                   */
  /* ---------------------------------------------------- */
  
# if defined(OS_CFG_THREAD_FPU_CONTEXT_ENABLED_ASM) 
  
  /* FP context supported  -> Copy FPU registers to destination StructVar */

  add  r0, r5, #0xAC             /* r0 gets the address of StructVar.S0 */
  vstm r0, {s0-s31}              /* Store S0..S31 */

  vmrs r2, FPSCR                 /* Read FPSCR into r2 */
  str  r2, [r5, #0x130]          /* Store FPSCR in StructVar */

  vmrs r0, FPEXC                 /* Read FPEXC */
  str  r0, [r5, #0x12C]          /* Store FPEXC */

# else

  /* FP context not supported -> Write 0xDEAD to StructVar FP registers */
  
  movw r2, #0xDEAD
  
  mov r4, #0xAC                  /* r4 = StructVar.S0 offset. r4 is used as offset to FP registers in the next loop. */

  OS_HAL_ASM_ALIGN4  
OS_HAL_ASM_DEFINE_LABEL(Dead_FP_Registers_Loop)  
  str r2, [r5, r4]               /* Write 0xDEAD to StructVar.Sx */
  add r4, r4, #4                 /* Increment the offset by 4 bytes to write the next StructVar.Sx */
  cmp r4, #0x12C                 /* Check if StructVar.S31 was reached and filled */
  bne Dead_FP_Registers_Loop     /* Stay in the loop till StructVar.S0 .. StructVar.S31 are filled */

  str r2, [r5, #0x12C]           /* Write 0xDEAD to StructVar.FPEXC */
  str r2, [r5, #0x130]           /* Write 0xDEAD to StructVar.FPSCR */
  
# endif

  
  /* Copy MPU info if MPU is supported                    */
  /* ---------------------------------------------------- */
  
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)

  mov r0, #OS_HAL_MP_STACK_REGION_NUMBER_ASM  /* r0 gets the MPU stack region number */
  str r0, [r5, #0x134]                        /* StructVar.RGNR = Stack region RGNR */  
    
  ldr r0, [r3, #0x28]                         /* r0 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.StackRegion_DRBAR */
  str r0, [r5, #0x138]                        /* StructVar.DRBAR = User thread stack region DRBAR */
   
  ldr r0, [r3, #0x2C]                         /* r0 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.StackRegion_DRACR */
  str r0, [r5, #0x13C]                        /* StructVar.DRACR = User thread stack region DRACR */
  
  ldr r0, [r3, #0x30]                         /* r0 = OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn.StackRegion_DRSR */
  str r0, [r5, #0x140]                        /* StructVar.DRSR = User thread stack region DRSR register */

# else /* MPU is not configured/supported -> Write 0xDEAD to ThreadStackMpuRegionDetails */

  movw r0, #0xDEAD                            /* r0 = 0xDEAD */
  str  r0, [r5, #0x134]                       /* StructVar.RGNR  = 0xDEAD */ 
  str  r0, [r5, #0x138]                       /* StructVar.DRBAR = 0xDEAD */
  str  r0, [r5, #0x13C]                       /* StructVar.DRACR = 0xDEAD */
  str  r0, [r5, #0x140]                       /* StructVar.DRSR  = 0xDEAD */

# endif  /* #  if defined(OS_HAL_CFG_MEMORY_PROTECTION_ASM) */

  /* Store the Exception Address                          */
  /* ---------------------------------------------------- */
  
  /* Note: At this level, the mode is SYS mode */
  
  /* Note:                                                                                                         */
  /* The exception address depends on the type of the exception and the instruction set previous to the exception: */
  /*                                                                                                               */
  /*   Exc    Exc-Id    ARM           Thumb        */
  /*   -----------------------------------------   */
  /*   UND    1         LR_exc - 4    LR_exc - 2   */
  /*   SVC    2         LR_exc - 4    LR_exc - 2   */
  /*   PABT   3         LR_exc - 4    LR_exc - 4   */
  /*   FIQ    7         LR_exc - 4    LR_exc - 4   */
  /*   DABT   4         LR_exc - 8    LR_exc - 8   */
  
  ldr   r0, [r3, #0x18]         /* r0 = LR_exc */
  sub   r0, r0, #4              /* r0 = (LR_exc - 4) */
  
  ldr   r2, [r3, #0x1C]         /* r2 = SPSR_exc */  
  and   r4, r2, #0x20           /* Check the T bit of SPSR_exc to find out the previous instruction set state (0: ARM, !=0: Thumb) */
  
  cmp   r1, #1                  /* Check if it's an Undefined Instruction exception */
  bleq  Os_Hal_RetAddr_Und_Svc  /* r0 = (LR_exc - 2) [Thumb], (LR_exc - 4) [ARM]    */ /* Passed params: r0, r4, lr */ /* LR_sys is overwritten by bleq */
  
  cmp   r1, #2                  /* Check if it's a SVC call exception when MPU is inactive */
  bleq  Os_Hal_RetAddr_Und_Svc  /* r0 = (LR_exc - 2) [Thumb], (LR_exc - 4) [ARM]   */ /* Passed params: r0, r4, lr */ /* LR_sys is overwritten by bleq */
  
  cmp   r1, #4                  /* Check if it's a Data Abort exception */
  bleq  Os_Hal_RetAddr_DABT     /* r0 = (LR_exc - 8) */ /* Passed params: r0, lr */ /* LR_sys is overwritten by bleq */
  
  str   r0, [r5, #0x144]        /* Store the exception address to StructVar.ExceptionAddress */

  /* Store the Return Address                             */
  /* ---------------------------------------------------- */
  
  ldr   r0, [r3, #0x18]     /* r0 = LR_exc */
  
  cmp   r1, #7
  bleq  Os_Hal_RetAddr_Fiq  /* r0 = (LR_exc - 4) */ /* Passed params: r0, lr */ /* LR_sys is overwritten by bleq */
  
  str   r0, [r5, #0x148]    /* Store the return address to StructVar.ReturnAddress */
  
  /* Save interrupt lock level                            */
  /* ---------------------------------------------------- */
  
  /* . {r0-r3, r9, r12, lr} are not preserved by a routine call */
  /* . {r3, r6-r12, sp, lr} shall not be modified by Os_Hal_Context_SaveExcContext */
  /* . lr is already pushed to the stack */
  /* -> Save {r3, r9, r12} to the kernel stack before calling Os_Hal_CoreExceptionGetInterruptLockLevel() */  
  
  push  {r3, r9, r12}
  bl    Os_Hal_CoreExceptionGetInterruptLockLevel  /* LR_sys is overwritten by bl */ /* r0 will hold the return value i.e. the IntC Interrupt Level. */
  pop   {r3, r9, r12}
  
  str   r0, [r5, #0x14C]    /* Store the IntC interrupt lock level to StructVar.InterruptLevel */
  
  /* Branch back to the exception handler                 */
  /* ---------------------------------------------------- */
  
  cps  #0x1F    /* Change mode to SYS mode */
  pop  {lr}     /* Restore LR_sys from kernel stack (SYS mode stack) to branch back to exception handler */
  bx   lr       /* Branch back to the exception entry using LR_sys */
  
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Context_SaveExcContext)


/***********************************************************************************************************************
 *  Os_Hal_Context_RestoreUpdatedExcContext()
 **********************************************************************************************************************/
/*! \brief          Writes the updated exception context to HW registers.
 *  \details        Called from exception handlers.
 *                  r4 saves the value of LR_sys and is used athe end to return to the exc handler.
 *  \param[in]      r0 : holds the Core Id
 *  \param[in]      LR_sys : System mode link register holding the return address
 *  \param[out]     r5 is used to hold &OsCfg_Hal_Context_OsCoreX_ExceptionContext along this function.
 *  \param[out]     r3 holding &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_ALIGN4
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Context_RestoreUpdatedExcContext)
  
  mov  r4, lr  /* r4 = LR_sys */ /* LR_sys value when entering this fct is needed at the end to return to the exception handler. */             /* ( <----- r4 = LR_sys     ) */
  
  /* Get the address of the destination struct var in r5  */
  /* ---------------------------------------------------- */
  
  OS_HAL_ASM_IMPORT(OsCfg_Hal_Context_ExceptionContextRef)                      /* Declare OsCfg_Hal_Context_ExceptionContextRef defined in Os_Hal_Context_Lcfg.c */ 
  Os_Hal_Asm_Load_Register_Immediate r5, OsCfg_Hal_Context_ExceptionContextRef  /* r5 gets the address of the array OsCfg_Hal_Context_ExceptionContextRef[] */
  
  /* (1) r0 = CoreId << 2 = (4 * CoreId) : r0 gets the offset to &OsCfg_Hal_Context_OsCoreX_ExceptionContext element in OsCfg_Hal_Context_ExceptionContextRef[] array */
  /* (2) r5 = &OsCfg_Hal_Context_ExceptionContextRef[0] + (4 * CoreId) = &OsCfg_Hal_Context_ExceptionContextRef[CoreId] */
  /* (3) r5 = OsCfg_Hal_Context_ExceptionContextRef[CoreId] = &OsCfg_Hal_Context_OsCoreX_ExceptionContext ; X = CoreId */
  
  ldr  r5, [r5, r0, lsl #2]                                                                                                                     /* ( <----- r5 = &OsCfg_Hal_Context_OsCoreX_ExceptionContext) */

  /* Restore the saved interrupt lock level.              */
  /* ---------------------------------------------------- */
  
  ldr  r0, [r5, #0x14C] /* r0 gets the IntC interrupt lock level from StructVar.InterruptLevel. r0 is passed as parameter to the following IntC fct. */
  
  bl   Os_Hal_CoreExceptionSetInterruptLockLevel /* LR_sys is overwritten by bl */

  /* Update FPU registers                                 */
  /* ---------------------------------------------------- */

# if defined(OS_CFG_THREAD_FPU_CONTEXT_ENABLED_ASM)

  add  r0, r5, #0xAC    /* r0 gets the address of StructVar.S0 */
  vldm r0, {s0-s31}     /* Copy StructVar.S0 .. StructVar.S31 to S0 .. S31 */  

# endif
 
  /* Update Banked Registers                              */
  /* ---------------------------------------------------- */
  
  /* Copy FIQ mode banked registers */
  
  cps  #0x11             /* Change to FIQ mode */
  add  r0, r5, #0x40     /* r0 gets the address of StructVar.Os_Hal_BankedFiqRegisters.R8 */
  ldm  r0, {r8-r12}      /* Copy StructVar.R8_fiq .. StructVar.R12_fiq to R8_fiq .. R12_fiq */
  /* Note: The user is not allowed to touch SP_fiq */
  ldr  lr, [r5, #0x58]   /* LR_fiq = StructVar.LR_fiq */
  ldr  r0, [r5, #0x5C]   /* r0 = StructVar.SPSR_fiq */
  msr  spsr_cxsf, r0     /* SPSR_fiq gets StructVar.SPSR_fiq */
  
  /* Update IRQ mode banked registers */
  
  cps  #0x12             /* change to IRQ mode */
  ldr  sp, [r5, #0x60]   /* SP_irq = StructVar.SP_irq */
  ldr  lr, [r5, #0x64]   /* LR_irq = StructVar.LR_irq */
  ldr  r0, [r5, #0x68]   /* r0 = StructVar.SPSR_irq */
  msr  spsr_cxsf, r0     /* SPSR_irq gets StructVar.SPSR_irq */
  
  /* Update ABT mode banked registers */
  
  cps  #0x17             /* change to ABT mode */
  /* Note: The user is not allowed to touch SP_fiq */
  ldr  lr, [r5, #0x70]   /* LR_irq = StructVar.LR_irq */
  ldr  r0, [r5, #0x74]   /* r0 = StructVar.SPSR_abt */
  msr  spsr_cxsf, r0     /* SPSR_abt gets StructVar.SPSR_abt */
  
  /* Update SVC mode banked registers */
  
  cps  #0x13             /* change to SVC mode */
  /* Note: The user is not allowed to touch SP_svc */
  ldr  lr, [r5, #0x7C]   /* LR_svc = StructVar.LR_svc */
  ldr  r0, [r5, #0x80]   /* r0 = StructVar.SPSR_svc */
  msr  spsr_cxsf, r0     /* SPSR_svc gets StructVar.SPSR_svc */
  
  /* Update UND mode banked registers */
  
  cps  #0x13             /* change to UND mode */
  /* Note: The user is not allowed to touch SP_und */
  ldr  lr, [r5, #0x88]   /* LR_und = StructVar.LR_und */
  ldr  r0, [r5, #0x8C]   /* r0 = StructVar.SPSR_und */
  msr  spsr_cxsf, r0     /* SPSR_und gets StructVar.SPSR_und */
  
  /* Update previous mode GP registers                    */
  /* ---------------------------------------------------- */
  
  /* Note: There is no need to switch to previous mode to update the previous mode GP registers. */
  /*       Updating the SYS mode GP registers is sufficient because: */
  /*          - R0..R7 are the same for all modes, */
  /*          - R8..R12 are the same for all modes (except FIQ mode), */
  /*          - banked registers were updated above, */
  /*          - SYS and USR mode have the same GP registers. */
  
  /* r0-r5 will be used afterwards to hold return values or to perform some operations e.g. stack switch  */  
  /* -> Do not write r0-r5 back now. Write them back later after returning to the exception handler       */
  
  /* Change back to SYS mode to update {r6-r12, lr} from {StructVar.PreviousModeGpRegisters.R6-R12, LR} */
  
  cps  #0x1F
  
  /* Update {r6-r12, lr} from {StructVar.PreviousModeGpRegisters.R6-R12, LR} */
  
  add  r0, r5, #0x1C      /* r0 gets the address of StructVar.PreviousModeGpRegisters.R6 */
  ldm  r0, {r6-r12}       /* r6..r12 get StructVar.PreviousModeGpRegisters.R6..R12 */  
  
  ldr  lr, [r5, #0x3C]    /* LR_sys gets StructVar.PreviousModeGpRegisters.LR */

  /* Reprogram the MPU stack region with the previous thread stack region attributes */
  /* ------------------------------------------------------------------------------- */

#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  
  mov  r0, #OS_HAL_MP_STACK_REGION_NUMBER_ASM
  mcr  p15,#0,r0,c6,c2,#0  /* RGNR = STACK_REGION_NUMBER : select the region to reprogram by wrting RGNR register */
  
  mov  r0, #0
  mcr  p15,#0,r0,c6,c1,#2  /* DRSR = 0 : Disable the MPU region before reprogramming it */  
  
  ldr  r0, [r5, #0x138]    /* r0 = StructVar.ThreadStackMpuRegionDetails.DRBAR */
  mcr  p15,#0,r0,c6,c1,#0  /* DRBAR = StructVar.ThreadStackMpuRegionDetails.DRBAR (DRBAR gets the previous thread stack region base address) */
  
  ldr  r0, [r5, #0x13C]    /* r0 = StructVar.ThreadStackMpuRegionDetails.DRACR */
  mcr  p15,#0,r0,c6,c1,#4  /* DRACR = StructVar.ThreadStackMpuRegionDetails.DRACR (DRACR gets the previous thread stack region Access Control */
  
  ldr  r0, [r5, #0x140]    /* r0 = StructVar.ThreadStackMpuRegionDetails.DRSR */
  mcr  p15,#0,r0,c6,c1,#2  /* DRSR = StructVar.ThreadStackMpuRegionDetails.DRSR (DRSR gets the previous thread stack region Size and Enable and Subregion Disable Register */
  
#endif

  /* Write &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn to output parmater r3 */
  /* --------------------------------------------------------------------- */
    
  cps  #0x17              /* Change to ABT mode to access OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn using SP_abt */ 
  mov  r3, sp             /* r3 = &OsCfg_Hal_ExcEntryRegSaveVar_OsCoreX_Dyn */
  cps  #0x1F                                                                                                                                    /* ( <----- SYS Mode     ) */
  
  /* Switch from kernel stack back to the previous thread stack  */
  /* ----------------------------------------------------------- */
  
  ldr  sp, [r5, #0x38]
  
  /* Branch back to the exception handler                 */
  /* ---------------------------------------------------- */
  
  bx   r4                 /* Branch back to the exception entry using r4 holding the value of lr when entering this fct. */
  
  OS_HAL_ASM_ALIGN4
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Context_RestoreUpdatedExcContext)

  
#endif /* defined(OS_HAL_EXCEPTION_CONTEXT_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_ContextAsm_ExceptionContext.inc
 *********************************************************************************************************************/
