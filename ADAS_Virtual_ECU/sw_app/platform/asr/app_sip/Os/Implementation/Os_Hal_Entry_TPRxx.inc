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
 * \file  Os_Hal_Entry_TPRxx.inc
 * \brief  -
 * \internal
 *  Hardware manuals: See derivative specific header (Os_Hal_Derivative_TPRxxInt.h)
 *  Errata sheets:    See derivative specific header
 *  Specifics: -
 *  Used registers and bits: General Purpose and System Registers
 *  Operating modes: -
 *  Hardware features related to independence or partitioning: -
 *  Access mechanism: -
 *  Hardware diagnostics: -
 * \endinternal
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_ENTRY_TPRXX_INC
# define OS_HAL_ENTRY_TPRXX_INC

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Os_Hal_Compiler.inc"

/***********************************************************************************************************************
 *  EXTERNAL DECLARATIONS
 **********************************************************************************************************************/
  OS_HAL_ASM_IMPORT(Os_UnhandledIrq)
  OS_HAL_ASM_IMPORT(OsCfg_Hal_Context_ExceptionContextRef)

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/
/*! Access right value used for stack region. */
# define OS_HAL_ENTRY_MP_TPRXX_STACK_ACCESS_RIGHT     0x130B

/***********************************************************************************************************************
 *  Os_Hal_TPR_SpuriousIRQ_Handler()
 **********************************************************************************************************************/
/*! \brief          Handling of spurious interrupts.
 *  \details        The interrupt number of the active IRQ/FIQ interrupt is invaid.
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_TPR_SpuriousIRQ_Handler)
  pop     {r0-r3,r8,r12,lr}         /* Restore previously saved registers */
  rfefd   sp!                       /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_TPR_SpuriousIRQ_Handler)

/***********************************************************************************************************************
 *  Os_Hal_IrqInterruptEntry_TPRxx
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler that loads the address of currently active IRQ interrupt to call the
 *                  corresponding ISR handler
 *  \details        It is used in case of IRQ interrupts are configured using Vectored Interrupt
 *                  Manager, including invalid interrupts handling.
 *  \param[in]      -
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_MACRO_WITHOUT_PARAM_BEGIN(Os_Hal_IrqInterruptEntry_TPRxx)
  sub     lr,lr,#4          /* LR = LR - 4 */
  srsfd   sp!, #0x1f        /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f             /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr} /* Store registers on the system stack */
  movw    r2, #OS_HAL_TPRXX_INTC_VIM_BASE_ADDRESS_LOW
  movt    r2, #OS_HAL_TPRXX_INTC_VIM_BASE_ADDRESS_HIGH
  ldr     r8, [r2, #0x18]   /* Load IRQ vector address register */
  ldr     r1, [r2, #0x20]   /* Load active IRQ register */
  lsrs    r1, r1, #31       /* Check VALID bit in VIM_ACTIRQ register */
  cmp     r1, #0
  beq     Os_Hal_TPR_SpuriousIRQ_Handler  /* Invalid IRQ interrupt */

# if defined OS_HAL_TPRXX_INTC_VIM_IRQ_NESTING
  /* Handle hardware bug in back-2-back activation of the same interrupt. */
  mov     r1, r1, lsl #31   /* Load value of (1<< OS_HAL_INTC_VIM_DUMMY_SOURCE%32). */
  str     r1, [r2, #0x4E0]  /* Set the dummy interrupt (IRQ#255) raw status. */
  dsb  /* Add DSB to guarantee that the VIM takes the dummy interrupt. */
  isb  /* Add DSB to guarantee that the VIM takes the dummy interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM takes the dummy interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM takes the dummy interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM takes the dummy interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM takes the dummy interrupt. */
  ldr     r3, [r2, #0x18]   /* Load IRQ vector address register. */
  str     r1, [r2, #0x4E4]  /* Clear the status of the dummy interrupt (IRQ#255). */
  str     r1, [r2, #0x18]   /* Write any value to IRQ vector address register. */  
  nop  /* Add 4 NOPs to guarantee that the VIM gets back to the original interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM gets back to the original interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM gets back to the original interrupt. */
  nop  /* Add 4 NOPs to guarantee that the VIM gets back to the original interrupt. */
# endif /* OS_HAL_TPRXX_INTC_VIM_IRQ_NESTING */

  /* Pre-action: Clearing of status flag in case of pulse interrupt */ 
  ldr     r0, [r2, #0x20]      /* r0 = Load active IRQ register */
  movw    r3, #0x3FF           /* r3 = Load the bit mask for the NUM field */
  and     r0, r0, r3           /* r0 = Mask out the NUM field */
  lsr     r1, r0, #0x5         /* r1 = Mod 32 */
  and     r0, r0, #0x1F        /* r0 = Only retain the last 5 bits(31 decimal) of the NUM field */
  add     r1, r2, r1, lsl #0x5 /* r1 = Calculate register offset for the interrupt source */
  mov     r3, #0x1             /* r3 = 0x1 */
  lsl     r0, r3, r0           /* r0 = Create the bit mask for the source inside the register */
  ldr     r3, [r1, #0x41C]     /* r3 = Read the Interrupt type register for the respective source */
  ands    r3, r3, r0           /* r3 = Check if the corresponding bit for the interrupt is set */
  cmp     r3, #0               /* ESCAN00108726 fix */
  blne    Os_Hal_TPRx_PulseIntClear
  mov     pc, r8               /* Goto to the interrupt handler */

  OS_HAL_ASM_MACRO_END

/***********************************************************************************************************************
 *  Os_Hal_CatEntry_Interrupt_TPRxx()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which calls a C-function.
 *  \details        It is used in case CAT0 or CAT1 interrupts are configured.
 *  \param[in]      JumpTarget     Function which shall be called.
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_CatEntry_Interrupt_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
  OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_CatEntry_Interrupt_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
  bl      OS_HAL_ASM_MACRO_PARAM_IN_BODY(JumpTarget)  /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                /* Restore previously saved registers */
  rfefd   sp!                              /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_Cat2Entry_Interrupt_TPRxx()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which calls a high level ISR handler.
 *  \details        -
 *  \param[in]      IsrConfig      ISR configuration which shall be executed by high level ISR handler.
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_Cat2Entry_Interrupt_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
  OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_Cat2Entry_Interrupt_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
  Os_Hal_Asm_LoadRegister32 r0, OS_HAL_ASM_MACRO_PARAM_IN_BODY(IsrConfig)
  bl      Os_IsrRun         /* Jump to the high level ISR handler */
  pop     {r0-r3,r8,r12,lr} /* Restore previously saved registers */
  rfefd   sp!               /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_UnhandledInterruptEntry_TPRxx()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled interrupt handler which saves minimum of interrupted context to
 *                  be able to call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled interrupt
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_UnhandledInterruptEntry_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Id))
  OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_UnhandledInterruptEntry_TPRxx, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Id))
  bl      Os_Hal_CoreGetId_Asm
  /* (1) r0 = CoreId << 2 = (4 * CoreId) : r0 gets the offset to &OsCfg_Hal_Context_OsCoreX_ExceptionContext element in OsCfg_Hal_Context_ExceptionContextRef[] array */
  /* (2) r3 = &OsCfg_Hal_Context_ExceptionContextRef[0] + (4 * CoreId) = &OsCfg_Hal_Context_ExceptionContextRef[CoreId] */
  /* (3) r3 = OsCfg_Hal_Context_ExceptionContextRef[CoreId] = &OsCfg_Hal_Context_OsCoreX_ExceptionContext ; X = CoreId */
  Os_Hal_Asm_Load_Register_Immediate r3, OsCfg_Hal_Context_ExceptionContextRef
  ldr  r3, [r3, r0, lsl #2]
  mov     r0, #OS_HAL_ASM_MACRO_PARAM_IN_BODY(Id)      /*  Store the Id as function parameter */
  ldr     r1, [sp, #0x1C]                              /* Load the LR value at exception entry */
  ldr     r2, [sp, #0x20]     /* Load the CPSR value at exception entry */
  and     r2, r2, #0xF        /* Get 0(User) !0(Others) and pass to the C function */
  sub     r1, r1, #4          /* Subtract 4 to get the instruction address where irq happened and pass to the C function */
  str     r1, [r3, #0x64]     /* Store instruction address to LR_irq */
  bl      Os_UnhandledIrq     /*  Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}   /*  Restore previously saved registers */
  rfefd   sp!                 /*  Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END

/***********************************************************************************************************************
 *  Os_Hal_TPRx_PulseIntClear()
 **********************************************************************************************************************/
/*! \brief          Clear pending bit.
 *  \details        Clear the pending bit in case of pulse interrupt.
 *  \context        -
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_TPRx_PulseIntClear)
  str     r0, [r1, #0x410]     /* Clear the pending bit in case of pulse interrupt */
  bx      lr                   /* Return to the caller */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_TPRx_PulseIntClear)




#endif /* defined(OS_HAL_ENTRY_TPRXX_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_TPRxx.inc
 *********************************************************************************************************************/
