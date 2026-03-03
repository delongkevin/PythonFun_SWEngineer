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
 * \file  Os_Hal_Entry_Pmsa8.inc
 * \brief  This component handles hardware exceptions and interrupts.
 * \internal
 *  Hardware manuals: See derivative specific header (Os_Hal_Derivative_Generic_CortexR52Int.h)
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

#ifndef OS_HAL_ENTRY_PMSA8_INC
# define OS_HAL_ENTRY_PMSA8_INC

# include "Os_Hal_MemoryProtection_Cfg.h"

/*! Access right value used for stack region. = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_RW_U_RW) */
# define OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHTS   0x03

/*! Access right value of stack protection region. = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_R_U_R) */
# define OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT   0x06

/*! Stack region attributes. = (OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE | OS_HAL_MP_REGION_SIZE_ENABLE) */
# define OS_HAL_ENTRY_MP_STACK_ATTRS   0x01

/*! Mask to access EN bit of PRLAR register. */
# define OS_HAL_ENTRY_MP_DISABLE_REGION_MASK 0xFFFFFFFE

/***********************************************************************************************************************
 *  EXTERNAL DECLARATIONS
 **********************************************************************************************************************/
  OS_HAL_ASM_IMPORT(OsCfg_Stack_KernelStacks)
  OS_HAL_ASM_IMPORT(Os_UnhandledExc)

/***********************************************************************************************************************
 *  Os_Hal_UnhandledExceptionEntry_WithMemoryProtection_PMSA8()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \param[in]      Addr  Instruction address where the unhandled exception was taken.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection_PMSA8)
  srsfd   sp!, #0x1f           /*  Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                /*  Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}    /*  Store registers on the system stack */
  ldr     r4, [sp, #0x20]      /* Load the CPSR value at exception entry */
  ldr     r5, [sp, #0x1C]      /* Load the LR value at exception entry */
  /* Perform Kernel stack switch and reprogram stack window */
  mrc     p15,#0,r1,c0,c0,#5   /* r1 = MPIDR, get core id */
  and  r0, r1, #0xff           /* r0 = r1 & 0xff, mask bits [7,0] */
  and  r1, r1, #0xff00         /* r1 = r1 & 0xff00, mask bits [15,8] */
  orr  r1, r0, r1, lsr #0x8    /* r1 = (r1 >> 8) | r0 */
  mov     r2, #0x4             /* OsCfg_Stack_KernelStacks has offset size of 4 */
  mul     r1, r2, r1           /* r1 = r2 * r1 */
  Os_Hal_Asm_LoadRegister32 r0, OsCfg_Stack_KernelStacks   /* r0 = &OsCfg_Stack_KernelStacks[0] */
  add     r0, r0, r1           /* r0 = r0 + r1 */
  ldr     r2, [r0, #0]         /* r2 = OsCfg_Stack_KernelStacks[CurrentCore] */
  ldr     sp, [r2, #0]         /* sp = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  ldr     r0, [r2, #4]         /* r0 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionStart */
  ldr     r1, [r2, #0]         /* r1 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  mov     r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov     r8, #0
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr     r12, r0, #OS_HAL_ENTRY_MP_STACK_ATTRS /* r12 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTRS */
  sub     r12, r12, #0x40      /* Align stack protection end address */
  mcr     p15,#0,r12,c6,c3,#1  /* PRLAR = r12, Os_Hal_MpSetRegionEndAddressAndEnable(r12) */
  isb
  mov     r12, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr     r0, r0, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHTS /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHTS */
  mcr     p15,#0,r0,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr     r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTRS /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTRS */
  mcr     p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov     r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc     p15,#0,r8,c6,c3,#1   /* r8 = PRLAR */
  and     r8, r8, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = r8, Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  ldr     r1, [r2, #0]         /* r1 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  orr     r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add     r12, r12, #0x40      /* Align stack protection start address */
  mcr     p15,#0,r12,c6,c3,#0  /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr     r8, r8, #OS_HAL_ENTRY_MP_STACK_ATTRS /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTRS */
  mcr     p15,#0,r8,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
  mov     r0, #7               /*  Store the Id as function parameter */
  mov     r1, r5               /* Load the LR value at exception entry */
  mov     r2, r4               /* Get 0(User) !0(Others) and pass to the C function */
  and     r2, r2, #0xF         /* Get 0(User) !0(Others) and pass to the C function */
  bl      Os_UnhandledExc      /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}    /* Restore previously saved registers */
  rfefd   sp!                  /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UnhandledExceptionEntry_WithMemoryProtection_PMSA8)

/***********************************************************************************************************************
 *  Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection_PMSA8()
 **********************************************************************************************************************/
/*! \brief          Low level unhandled exception handler which saves minimum of interrupted context to be able to
 *                  call a C-function.
 *  \details        -
 *  \param[in]      Id    Id of the unhandled exception
 *  \param[in]      Addr  Instruction address where the unhandled exception was taken.
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection_PMSA8)
  srsfd   sp!, #0x1f           /*  Store Return State (LR, SPSR) to the system stack */
  cps     #0x1f                /*  Change the cpu mode to system */
  push    {r0-r3,r8,r12,lr}    /*  Store registers on the system stack */
  ldr     r4, [sp, #0x20]      /* Load the CPSR value at exception entry */
  ldr     r5, [sp, #0x1C]      /* Load the LR value at exception entry */
  /* Perform Kernel stack switch and reprogram stack window */
  mrc     p15,#0,r1,c0,c0,#5   /* r1 = MPIDR, get core id */
  and  r0, r1, #0xff           /* r0 = r1 & 0xff, mask bits [7,0] */
  and  r1, r1, #0xff00         /* r1 = r1 & 0xff00, mask bits [15,8] */
  orr  r1, r0, r1, lsr #0x8    /* r1 = (r1 >> 8) | r0 */
  mov     r2, #0x4             /* OsCfg_Stack_KernelStacks has offset size of 4 */
  mul     r1, r2, r1           /* r1 = r2 * r1 */
  Os_Hal_Asm_LoadRegister32 r0, OsCfg_Stack_KernelStacks   /* r0 = &OsCfg_Stack_KernelStacks[0] */
  add     r0, r0, r1           /* r0 = r0 + r1 */
  ldr     r2, [r0, #0]         /* r2 = OsCfg_Stack_KernelStacks[CurrentCore] */
  ldr     sp, [r2, #0]         /* sp = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  ldr     r0, [r2, #4]         /* r0 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionStart */
  ldr     r1, [r2, #0]         /* r1 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  mov     r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov     r8, #0
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr     r12, r0, #OS_HAL_ENTRY_MP_STACK_ATTRS /* r12 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTRS */
  sub     r12, r12, #0x40      /* Align stack protection end address */
  mcr     p15,#0,r12,c6,c3,#1  /* PRLAR = r12, Os_Hal_MpSetRegionEndAddressAndEnable(r12) */
  isb
  mov     r12, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr     r0, r0, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHTS /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHTS */
  mcr     p15,#0,r0,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr     r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTRS /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTRS */
  mcr     p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov     r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr     p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc     p15,#0,r8,c6,c3,#1   /* r8 = PRLAR */
  and     r8, r8, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr     p15,#0,r8,c6,c3,#1   /* PRLAR = r8, Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  ldr     r1, [r2, #0]         /* r1 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  orr     r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add     r12, r12, #0x40      /* Align stack protection start address */
  mcr     p15,#0,r12,c6,c3,#0  /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr     r8, r8, #OS_HAL_ENTRY_MP_STACK_ATTRS /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTRS */
  mcr     p15,#0,r8,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
  mov     r0, #1               /*  Store the Id as function parameter */
  mov     r1, r5               /* Load the LR value at exception entry */
  sub     r1, r1, #2           /* LR-2 at exception entry is the undefined instruction address (thumb mode) */
  ands    r3, r2, #0x20        /* R2 = 0(ARM)  !0(thumb) */
  subne   r1, r1, #2           /* LR-4 at exception entry is the undefined instruction address (ARM mode) */
  mov     r2, r4               /* Get 0(User) !0(Others) and pass to the C function */
  and     r2, r2, #0xF         /* Get 0(User) !0(Others) and pass to the C function */
  bl      Os_UnhandledExc      /* Jump to the C-function */
  pop     {r0-r3,r8,r12,lr}    /* Restore previously saved registers */
  rfefd   sp!                  /* Return from Exception: load PC, CPSR with the words in the system stack */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_UndefinedInstructionExceptionEntry_WithMemoryProtection_PMSA8)

#endif /* defined(OS_HAL_ENTRY_PMSA8_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Pmsa8.inc
 *********************************************************************************************************************/
