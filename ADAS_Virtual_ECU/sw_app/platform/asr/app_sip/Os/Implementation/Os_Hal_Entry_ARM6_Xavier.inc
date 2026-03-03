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
 * \file  Os_Hal_Entry_ARM6_Xavier.inc
 * \brief  This component handles hardware exceptions and interrupts.
 * \internal
 *  Hardware manuals: See derivative specific header (Os_Hal_Derivative_XavierInt.h)
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

#ifndef OS_HAL_ENTRY_ARM6_XAVIER_INC
# define OS_HAL_ENTRY_ARM6_XAVIER_INC

OS_HAL_ASM_EQU(Os_Hal_Avic0_VicFiqStatus_Label, OS_HAL_INTC_AVIC_AVIC0_FIQSTATUS_ASM)

  OS_HAL_ASM_IMPORT(OsCfg_Hal_Core_OsCore0_VectorTable_Avic0)
  OS_HAL_ASM_IMPORT(OsCfg_Hal_Core_OsCore0_VectorTable_Avic1)
  OS_HAL_ASM_EXPORT(Os_Hal_FiqEntry_Avic)

/***********************************************************************************************************************
 *  Os_Hal_FiqEntry_Avic()
 **********************************************************************************************************************/
/*! \brief          Low level FIQ handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details        The active FIQ has to be fetched from both the interrupt controllers.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_FiqEntry_Avic)
  sub     lr,lr,#4                         /* LR = LR - 4 */
  srsfd   sp!, #0x1f                       /* Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                            /* Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}                /* Store registers on the system stack */
  Os_Hal_Asm_LoadRegister32 r3, Os_Hal_Avic0_VicFiqStatus_Label /* Load Avic0 fiq status register address */
  ldr     r3, [r3]                         /* Load Avic0 fiq status register value*/
  mov     r2, #0x0                         /* R2 == 0 ? AVIC0 : AVIC1 */
OS_HAL_ASM_DEFINE_LABEL(VicFiqStatusRead)  /* Get the available active FIQ source on AVIC0 first */
  clz     r8, r3
  cmp     r8, #0x20                        /* Check if all bits are zero in the VICFIQSTATUS register */
  ittt eq
  moveq   r2, #0x10000                     /* Offset between two AVICs */
  addeq   r3, r2, r3
  beq     VicFiqStatusRead                 /* If all active bits are 0 continue search on the AVIC1 */
  mov     r1, #0x1F
  sub     r1, r1, r8                       /* R1 = Index of the callout in the vector table. */
  Os_Hal_Asm_LoadRegister32 r8, OsCfg_Hal_Core_OsCore0_VectorTable_Avic0
  cmp     r2, #0
  it ne
  ldrne   r8, =OsCfg_Hal_Core_OsCore0_VectorTable_Avic1
  add     r0, r8, r1, lsl#2                /* R0 = Address of the ISR entry in the table. */
  ldr     r0, [r0]                         /* R0 = ISR function address. */
  blx     r0                               /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}                /* Restore previously saved registers */
  rfefd   sp!                              /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_FiqEntry_Avic)


#endif /* defined(OS_HAL_ENTRY_ARM6_XAVIER_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_ARM6_Xavier.inc
 *********************************************************************************************************************/
