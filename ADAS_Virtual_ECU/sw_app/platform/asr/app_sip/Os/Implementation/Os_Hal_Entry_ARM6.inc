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
 * \file  Os_Hal_Entry_ARM6.inc
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

#ifndef OS_HAL_ENTRY_INC
# define OS_HAL_ENTRY_INC

# include "Os_Hal_Derivative.h"
# include "Os_Hal_Entry_Cfg.h"
# include "Os_Hal_Compiler.inc"
# include "Os_Hal_Entry_ExcHandlers.inc"

  OS_HAL_ASM_CODE_SECTION(OS_CODE)

# if defined(OS_CFG_DERIVATIVEGROUP_XAVIER)
#  include "Os_Hal_Entry_ARM6_Xavier.inc"
# elif defined(OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXR52)
#  include "Os_Hal_Entry_Pmsa8.inc"
# elif defined(OS_CFG_DERIVATIVEGROUP_SR6XX)
#  include "Os_Hal_Entry_Pmsa8.inc"
# elif defined(OS_CFG_DERIVATIVEGROUP_RCARV4H) 
#  include "Os_Hal_Entry_Pmsa8.inc"
# endif /* OS_CFG_DERIVATIVEGROUP */

/*! More significant bits of the ILEV1.CMASK address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH     0x1000
/*! Lower significant bits of the ILEV1.CMASK address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW      0x0104
  /*! Higher significant bits of the ICLR address. */
  # define OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_HIGH     0x1000
  /*! Lower significant bits of the ICLR address. */
  # define OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_LOW      0x0100

  OS_HAL_ASM_PRESERVE8
  OS_HAL_ASM_IMPORT(Os_IsrRun)
  OS_HAL_ASM_IMPORT(Os_UnhandledIrq)

/***********************************************************************************************************************
 *  Os_Hal_ARM6_Sub2FromReg()
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
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ARM6_Sub2FromReg)
  sub     r1, r1, #2                   /* substruct 2 from r1 */
  bx      lr                           /* Return to the caller */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ARM6_Sub2FromReg)

/***********************************************************************************************************************
 *  Os_Hal_ARM6_Sub4FromReg()
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
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ARM6_Sub4FromReg)
  sub     r1, r1, #4                   /* substruct 4 from r1 */
  bx      lr                           /* Return to the caller */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ARM6_Sub4FromReg)
  
/***********************************************************************************************************************
 *  Os_Hal_Cat2Entry_SiintcInterrupt()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call high level ISR
 *                  handler.
 *  \details        The ILEV1.CMASK register has to be set to 0 in order to avoid that the hardware set the level
 *                  threshold automatically.
 *  \param[in]      IsrConfig      ISR configuration which shall be executed by high level ISR handler.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_Cat2Entry_SiintcInterrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_Cat2Entry_SiintcInterrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
  sub     lr,lr,#4          /* LR = LR - 4 */
  srsfd   sp!, #0x1f        /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f             /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr} /* Store registers on the system stack */
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH
  mov     r0, #0
  str     r0, [r2]           /* Force the hardware to ignore the current level: it will be set by Os later. */
  dsb
  Os_Hal_Asm_LoadRegister32 r0, OS_HAL_ASM_MACRO_PARAM_IN_BODY(IsrConfig)
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_HIGH
  ldr     r1,[r0, #4]       /* Get the source number for the IsrConfig */
  lsl      r1, r1, #2
  str     r1, [r2]          /* Acknowledge the interrupt: Needed for to support nesting. */
  bl      Os_IsrRun         /* Jump to the high level ISR handler */
  pop     {r0-r3,r8,r12,lr} /* Restore previously saved registers */
  rfefd   sp!               /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_CatEntry_SiintcInterrupt()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details        The ILEV1.CMASK register has to be set to 0 in order to avoid that the hardware set the level
 *                  threshold automatically.
 *  \param[in]      JumpTarget     Function which shall be called.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_CatEntry_SiintcInterrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_CatEntry_SiintcInterrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
  sub     lr,lr,#4                         /* LR = LR - 4 */
  srsfd   sp!, #0x1f                       /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                            /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                /* Store registers on the system stack */
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH
  mov     r0, #0
  str     r0, [r2]           /* Force the hardware to ignore the current level: it will be set by Os later. */
  dsb
  bl      OS_HAL_ASM_MACRO_PARAM_IN_BODY(JumpTarget)  /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                /* Restore previously saved registers */
  rfefd   sp!                              /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_Cat2Entry_Interrupt()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call high level ISR
 *                  handler.
 *  \details        -
 *  \param[in]      IsrConfig      ISR configuration which shall be executed by high level ISR handler.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_Cat2Entry_Interrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_Cat2Entry_Interrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(IsrConfig))
  sub     lr,lr,#4          /* LR = LR - 4 */
  srsfd   sp!, #0x1f        /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f             /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr} /* Store registers on the system stack */
  Os_Hal_Asm_LoadRegister32 r0, OS_HAL_ASM_MACRO_PARAM_IN_BODY(IsrConfig)
  bl      Os_IsrRun         /* Jump to the high level ISR handler */
  pop     {r0-r3,r8,r12,lr} /* Restore previously saved registers */
  rfefd   sp!               /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_CatEntry_Interrupt()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details        It is used in case CAT0 or CAT1 interrupts are configured.
 *  \param[in]      JumpTarget     Function which shall be called.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_CatEntry_Interrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_CatEntry_Interrupt, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
  sub     lr,lr,#4                         /* LR = LR - 4 */
  srsfd   sp!, #0x1f                       /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                            /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                /* Store registers on the system stack */
  bl      OS_HAL_ASM_MACRO_PARAM_IN_BODY(JumpTarget)  /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                /* Restore previously saved registers */
  rfefd   sp!                              /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_IsrEntry_Interrupt_Gic()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details
 *  \param[in]      JumpTarget       C-function which shall be called.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_IsrEntry_Interrupt_Gic, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_IsrEntry_Interrupt_Gic, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(JumpTarget))
  sub     lr,lr,#4                             /*  LR = LR - 4 */
  srsfd   sp!, #0x1f                           /*  Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                                /*  Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                    /*  Store registers on the system stack */
  ldr     r0, [sp, #0x1C]                      /* Load the LR value at exception entry -4 */
  ldr     r1, [sp, #0x20]                      /* Load the CPSR value at exception entry */
  and     r1, r1, #0xF                         /* Get 0(User) !0(Others) and pass to the C function */
  bl      OS_HAL_ASM_MACRO_PARAM_IN_BODY(JumpTarget)   /*  Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                    /*  Restore previously saved registers */
  rfefd   sp!                                  /*  Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END


/***********************************************************************************************************************
 *  Os_Hal_UnhandledInterruptEntry()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled interrupt handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled interrupt
 *  \param[in]      Addr  Address of the instruction interrupted by the unhandled irq.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
  OS_HAL_ASM_MACRO_BEGIN_1(Os_Hal_UnhandledInterruptEntry, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Id))
OS_HAL_ASM_MACRO_BEGIN_2(Os_Hal_UnhandledInterruptEntry, OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Id))
  srsfd   sp!, #0x1f                       /*  Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                            /*  Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                /*  Store registers on the system stack */
  mov     r0, #OS_HAL_ASM_MACRO_PARAM_IN_BODY(Id)      /*  Store the Id as function parameter */
  ldr     r1, [sp, #0x1C]                              /* Load the LR value at exception entry */
  ldr     r2, [sp, #0x20]                  /* Load the CPSR value at exception entry */
  and     r2, r2, #0xF                     /* Get 0(User) !0(Others) and pass to the C function */
  sub     r1, r1, #4                       /* Subtract 4 to get the instruction address where irq happened and pass to the C function */
  bl      Os_UnhandledIrq                  /*  Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                /*  Restore previously saved registers */
  rfefd   sp!                              /*  Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_MACRO_END

#endif /* defined(OS_HAL_ENTRY_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry.inc
 *********************************************************************************************************************/
