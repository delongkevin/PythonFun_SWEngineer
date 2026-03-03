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
 * \file  Os_Hal_Entry_IAR.inc
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

/*! Higher significant bits of the ILEV1.CMASK address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH     0x1000
/*! Lower significant bits of the ILEV1.CMASK address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW      0x0104
/*! Higher significant bits of the ICLR address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_HIGH     0x1000
/*! Lower significant bits of the ICLR address. */
# define OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_LOW      0x0100
/*! Higher significant bits of the Traveo interrupt controller base address. */
# define OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_HIGH     0xB040
/*! Lower significant bits of the Traveo interrupt controller base address. */
# define OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_LOW      0x0000

# if defined(OS_CFG_DERIVATIVEGROUP_XAVIER)
#  include "Os_Hal_Entry_IAR_Xavier.inc"
# endif /* OS_CFG_DERIVATIVEGROUP_XAVIER */

  OS_HAL_ASM_IMPORT(Os_IsrRun)
  OS_HAL_ASM_IMPORT(Os_UnhandledIrq)

/***********************************************************************************************************************
 *  Os_Hal_Handle_Traveo_Spurious_Interrupt()
 **********************************************************************************************************************/
/*! \brief          Handling of spurious interrupts.
 *  \details        The active IRQ priority is not consistent to the IRQPLM value.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Handle_Traveo_Spurious_Interrupt)
  movw    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_LOW
  movt    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_HIGH       ; Load interrupt controller base address 
  ldrh    r1, [r0, #0xC]                                        ; Load the last accepted IRQ channel (IRQST.IRQSN).
  str     r1, [r0, #0xC48]                                      ; Store it to the IRQ Hold Clear Register (IRQHC). 
  pop     {r0-r3,r8,r12,lr}                                     ; Restore previously saved registers 
  rfefd   sp!                             ; Return from Exception: load PC, CPSR with the words in the system stack
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Handle_Traveo_Spurious_Interrupt)


/***********************************************************************************************************************
 *  Os_Hal_Handle_E3_Spurious_Interrupt()
 **********************************************************************************************************************/
/*! \brief          Handling of spurious interrupts.
 *  \details        The active IRQ raw status bit is not equal to 1.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
**********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_Handle_E3_Spurious_Interrupt)
  str     r0, [r2, #0xF00]                ; Write a random value (r0) to the VICADDRESS (r2 + 0xF00) register
  pop     {r0-r3,r8,r12,lr}               ; Restore previously saved registers
  rfefd   sp!                             ; Return from Exception: load PC, CPSR with the words in the system stack
  OS_HAL_ASM_FUNCTION_END(Os_Hal_Handle_E3_Spurious_Interrupt) 


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
Os_Hal_Cat2Entry_SiintcInterrupt MACRO IsrConfig
  sub     lr,lr,#4          ; LR = LR - 4
  srsfd   sp!, #0x1f        ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f             ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr} ; Store registers on the system stack
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH
  mov     r0, #0
  str     r0, [r2]           ; Force the hardware to ignore the current level: it will be set by Os later
  dsb
  movw    r0, #IsrConfig
  movt    r0, #IsrConfig
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_ICLR_HIGH
  ldr     r1,[r0, #4]       ; Get the source number for the IsrConfig */
  lsl      r1, r1, #2
  str     r1, [r2]          ; Acknowledge the interrupt: Needed for to support nesting. */
  bl      Os_IsrRun         ; Jump to the high level ISR handler
  pop     {r0-r3,r8,r12,lr} ; Restore previously saved registers
  rfefd   sp!               ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


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
Os_Hal_CatEntry_SiintcInterrupt MACRO JumpTarget
  sub     lr,lr,#4                         ;LR = LR - 4
  srsfd   sp!, #0x1f                       ;Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                            ;Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}                ;Store registers on the system stack
  movw    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_LOW
  movt    r2, #OS_HAL_ENTRY_SIINTC_ADDRESS_CMASK_HIGH
  mov     r0, #0
  str     r0, [r2]                         ;Force the hardware to ignore the current level: it will be set by Os later
  dsb
  bl      JumpTarget                       ;Jump to the C-function
  pop     {r0-r3,r8,r12,lr}                ;Restore previously saved registers
  rfefd   sp!                              ;Return from Exception: load PC, CPSR with the words in the system stack
  ENDM

/***********************************************************************************************************************
 *  Os_Hal_Cat2Entry_Interrupt_Traveo()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call high level ISR
 *                  handler.
 *  \details        It is used in case CAT2 IRQ interrupts are configured using Traveo interrupt controller (including
 *                  the spurious interrupts handling).
 *  \param[in]      IsrConfig      ISR configuration which shall be executed by high level ISR handler.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
Os_Hal_Cat2Entry_Interrupt_Traveo MACRO IsrConfig
  sub     lr,lr,#4          ; LR = LR - 4
  srsfd   sp!, #0x1f        ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f              ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr} ; Store registers on the system stack
  movw    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_LOW
  movt    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_HIGH  
  ldrb    r1, [r0, #0xE]     ; Load the last accepted IRQ priority (IRQST.IRQPS).
  ldr     r0, [r0, #0xC90]   ; Load the current priority threshold (IRQPLM)
  cmp     r0, r1             ; Ensure this is not a spurious interrupt, otherwise ignore it.
  bls     Os_Hal_Handle_Traveo_Spurious_Interrupt ; Inconsistency detected: IRQPS >= IRQPLM
  movw    r0, #IsrConfig
  movt    r0, #IsrConfig
  bl      Os_IsrRun         ; Jump to the high level ISR handler 
  pop     {r0-r3,r8,r12,lr} ; Restore previously saved registers 
  rfefd   sp!               ; Return from Exception: load PC, CPSR with the words in the system stack 
  ENDM
  
/***********************************************************************************************************************
 *  Os_Hal_CatEntry_Interrupt_Traveo()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details        It is used in case CAT0 or CAT1 IRQ interrupts are configured using Traveo interrupt controller (
 *                  including the spurious interrupts handling).
 *  \param[in]      JumpTarget     Function which shall be called.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
Os_Hal_CatEntry_Interrupt_Traveo MACRO JumpTarget
  sub     lr,lr,#4                         ; LR = LR - 4
  srsfd   sp!, #0x1f                       ; Store Retun State (LR, SPSR) to the system stack 
  cps     #0x1f                             ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}                ; Store registers on the system stack
  movw    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_LOW
  movt    r0, #OS_HAL_ENTRY_TRAVEO_INTC_BASE_ADDRESS_HIGH  
  ldrb    r1, [r0, #0xE]     ; Load the last accepted IRQ priority (IRQST.IRQPS).
  ldr     r0, [r0, #0xC90]   ; Load the current priority threshold
  cmp     r0, r1             ; Ensure this is not a spurious interrupt, otherwise ignore it.
  bls     Os_Hal_Handle_Traveo_Spurious_Interrupt ; Inconsistency detected: IRQPS >= IRQPLM
  bl      JumpTarget  ; Jump to the C-function
  pop     {r0-r3,r8,r12,lr}                ; Restore previously saved registers
  rfefd   sp!                              ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


/***********************************************************************************************************************
 *  Os_Hal_Cat2Entry_Interrupt_E3()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call high level ISR
 *                  handler.
 *  \details        It is used in case CAT2 IRQ interrupts are configured using E3X VIC interrupt controller (including
 *                  the spurious interrupts handling).
 *  \param[in]      IsrConfig      ISR configuration which shall be executed by high level ISR handler.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
Os_Hal_Cat2Entry_Interrupt_E3 MACRO IsrConfig, SourceId, BaseAddr, CurrentPrio
  sub     lr,lr,#4             ; LR = LR - 4
  srsfd   sp!, #0x1f           ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}    ; Store registers on the system stack
  movw    r1, #SourceId        ; r1 = SourceId
  mov32   r2, #BaseAddr        ; r2 = BaseAddr
  add     r2, r2, #0x80        ; Load raw interrupt status register base address r2 = r2 + 0x80
  lsr     r0, r1, #0x5         ; Calculate the register number of the current interrupt r0 = r1 / 32uL
  add     r0, r2, r0, lsl #0x2 ; Load raw interrupt status register with offset r0 = r2 + r0 * 4uL
  ldr     r3, [r0]             ; r3 = [r0] = current raw status bit
  mov     r2, #0x1             ; Load 0x1 to r2, r2 = 0x1
  and     r1, r1, #0x1F        ; Calculate the shifted bit of raw interrupt status register r1 = r1 & 0x1F
  lsl     r1, r2, r1           ; Load the current bit of raw interrupt status register for the current interrupt r1 = r2 << r1
  and     r0, r3, r1           ; Compare this bit with 1, r0 = r3 & r1
  cmp     r0, r1               ; Ensure this is not a spurious interrupt, otherwise ignore it.
  mov32   r2, #BaseAddr        ; r2 = BaseAddr, r2 will be used in Os_Hal_Handle_E3_Spurious_Interrupt
  bne     Os_Hal_Handle_E3_Spurious_Interrupt ; Inconsistency detected: RAW STATUS != 1
  movw    r0, #IsrConfig
  movt    r0, #IsrConfig
  mov32   r2, #BaseAddr        ; r2 = BaseAddr
  add     r2, r2, #0x3C8       ; Load vic softerware priority mask register r2 = r2 + 0x3C8
  ldr     r3, [r2]             ; r3 = [r2] = current SW priority mask value
  clz     r2, r3               ; r2 =  Count of leading zeros in r3
  mov     r3, #0x20            ; r3 = 32
  sub     r1, r3, r2           ; r1 = r3 - r2 = LevelStatus of current core
  movw    r2, #CurrentPrio     ; r2 = Isr priority of current core
  cmp     r1, r2               ; R1 = LevelRegisterSim_Core0; R2 = Priority of current isr
  mov32   r2, #BaseAddr        ; r2 = BaseAddr, r2 will be used in Os_Hal_Handle_E3_Spurious_Interrupt
  bls     Os_Hal_Handle_E3_Spurious_Interrupt ; Detected Case 2: (R1 <R2), ISR which is not allowed by current level, ignore it
  bl      Os_IsrRun            ; Jump to the high level ISR handler
  pop     {r0-r3,r8,r12,lr}    ; Restore previously saved registers
  rfefd   sp!                  ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM

/***********************************************************************************************************************
 *  Os_Hal_CatEntry_Interrupt_E3()
 **********************************************************************************************************************/
/*! \brief          Low level ISR handler which saves minimum of interrupted context to be able to call a C-function.
 *  \details        It is used in case CAT0 or CAT1 IRQ interrupts are configured using E3X VIC interrupt controller (
 *                  including the spurious interrupts handling).
 *  \param[in]      JumpTarget     Function which shall be called.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
Os_Hal_CatEntry_Interrupt_E3 MACRO JumpTarget, SourceId, BaseAddr, CurrentPrio
  sub     lr,lr,#4             ; LR = LR - 4
  srsfd   sp!, #0x1f           ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}    ; Store registers on the system stack
  movw    r1, #SourceId        ; r1 = SourceId
  mov32   r2, #BaseAddr        ; r2 = BaseAddr
  add     r2, r2, #0x80        ; Load raw interrupt status register base address r2 = r2 + 0x80
  lsr     r0, r1, #0x5         ; Calculate the register number of the current interrupt r0 = r1 / 32uL
  add     r0, r2, r0, lsl #0x2 ; Load raw interrupt status register with offset r0 = r2 + r0 * 4uL
  ldr     r3, [r0]             ; r3 = [r0] = current raw status bit
  mov     r2, #0x1             ; Load 0x1 to r2, r2 = 0x1
  and     r1, r1, #0x1F        ; Calculate the shifted bit of raw interrupt status register r1 = r1 & 0x1F
  lsl     r1, r2, r1           ; Load the current bit of raw interrupt status register for the current interrupt r1 = r2 << r1
  and     r0, r3, r1           ; Compare this bit with 1, r0 = r3 & r1
  cmp     r0, r1               ; Ensure this is not a spurious interrupt, otherwise ignore it.
  mov32   r2, #BaseAddr        ; r2 = BaseAddr
  bne     Os_Hal_Handle_E3_Spurious_Interrupt ; Inconsistency detected: RAW STATUS != 1
  mov32   r2, #BaseAddr        ; r2 = BaseAddr
  add     r2, r2, #0x3C8       ; Load vic softerware priority mask register r2 = r2 + 0x3C8
  ldr     r3, [r2]             ; r3 = [r2] = current SW priority mask value
  clz     r2, r3               ; r2 =  Count of leading zeros in r3
  mov     r3, #0x20            ; r3 = 32
  sub     r1, r3, r2           ; r1 = r3 - r2 = LevelStatus of current core
  movw    r2, #CurrentPrio     ; r2 = Isr priority of current core
  cmp     r1, r2               ; R1 = LevelRegisterSim_Core0; R2 = Priority of current isr
  mov32   r2, #BaseAddr        ; r2 = BaseAddr, r2 will be used in Os_Hal_Handle_E3_Spurious_Interrupt
  bls     Os_Hal_Handle_E3_Spurious_Interrupt ; Detected Case 2: (R1 <R2), ISR which is not allowed by current level, ignore it
  bl      JumpTarget           ; Jump to the C-function
  pop     {r0-r3,r8,r12,lr}    ; Restore previously saved registers
  rfefd   sp!                  ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


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
Os_Hal_Cat2Entry_Interrupt MACRO IsrConfig
  sub     lr,lr,#4          ; LR = LR - 4
  srsfd   sp!, #0x1f        ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f             ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr} ; Store registers on the system stack
  movw    r0, #IsrConfig
  movt    r0, #IsrConfig
  bl      Os_IsrRun         ; Jump to the high level ISR handler
  pop     {r0-r3,r8,r12,lr} ; Restore previously saved registers
  rfefd   sp!               ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


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
Os_Hal_CatEntry_Interrupt MACRO JumpTarget
  sub     lr,lr,#4                         ;LR = LR - 4
  srsfd   sp!, #0x1f                       ;Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                            ;Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}                ;Store registers on the system stack
  bl      JumpTarget                       ;Jump to the C-function
  pop     {r0-r3,r8,r12,lr}                ;Restore previously saved registers
  rfefd   sp!                              ;Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


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
Os_Hal_IsrEntry_Interrupt_Gic MACRO JumpTarget
  sub     lr,lr,#4                             ; LR = LR - 4
  srsfd   sp!, #0x1f                           ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                                ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}                    ; Store registers on the system stack
  ldr     r0, [sp, #0x1C]                      ; Load the LR value at exception entry -4
  ldr     r1, [sp, #0x20]                      ; Load the CPSR value at exception entry
  and     r1, r1, #0xF                         ; Get 0(User) !0(Others) and pass to the C function
  bl      JumpTarget                           ; Jump to the C-function
  pop     {r0-r3,r8,r12,lr}                    ; Restore previously saved registers
  rfefd   sp!                                  ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM


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
Os_Hal_UnhandledInterruptEntry MACRO Id
  srsfd   sp!, #0x1f              ; Store Return State (LR, SPSR) to the system stack
  cps     #0x1f                   ; Change the cpu mode to system
  push    {r0-r3,r8,r12,lr}       ; Store registers on the system stack
  movw    r0, #Id                 ; Store the Id as function parameter
  ldr     r1, [sp, #0x1C]         ; Load the LR value at exception entry
  ldr     r2, [sp, #0x20]         ; Load the CPSR value at exception entry
  and     r2, r2, #0xF            ; Get 0(User) !0(Others) and pass to the C function
  sub     r1, r1, #4              ; Subtract 4 to get the instruction address when irq occurs and pass to the C function
  bl      Os_UnhandledIrq         ; Jump to the C-function
  pop     {r0-r3,r8,r12,lr}       ; Restore previously saved registers
  rfefd   sp!                     ; Return from Exception: load PC, CPSR with the words in the system stack
  ENDM

#endif /* defined(OS_HAL_ENTRY_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry.inc
 *********************************************************************************************************************/
