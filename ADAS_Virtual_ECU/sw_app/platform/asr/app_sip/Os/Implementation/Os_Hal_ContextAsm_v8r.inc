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
 * \file  Os_Hal_ContextAsm_v8r.inc
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

#ifndef OS_HAL_CONTEXTASM_V7R_INC
# define OS_HAL_CONTEXTASM_V7R_INC

# include "Os_Hal_MemoryProtection_Cfg.h"
# include "Os_Hal_Compiler.inc"

/*! Access right value used for stack region. = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_RW_U_RW) */
# define OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT   0x03

/*! Access right value of stack protection region. = (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_R_U_R) */
# define OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT   0x06

/*! Stack region attributes. = (OS_HAL_MP_ACCESS_TYPE_NORMAL_MEMORY_INNER_NON_CACHEABLE_OUTER_NON_CACHEABLE | OS_HAL_MP_REGION_SIZE_ENABLE) */
# define OS_HAL_ENTRY_MP_STACK_ATTR   0x01

/*! Mask to access EN bit of PRLAR register. */
# define OS_HAL_ENTRY_MP_DISABLE_REGION_MASK 0xFFFFFFFE

  OS_HAL_ASM_PRESERVE8
  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_EXPORT(Os_Hal_StorePermanentRegisters)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGoWithParameter)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGoWithParameterMpSwitch)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextRestorePermanentAndGo)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGo)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextRestorePermanentAndGoWithReturn)
  OS_HAL_ASM_EXPORT(Os_Hal_SysCallHandler)
  OS_HAL_ASM_EXPORT(Os_Hal_MemFault_PrefetchAbort)
  OS_HAL_ASM_EXPORT(Os_Hal_MemFault_DataAbort)


  OS_HAL_ASM_IMPORT(Os_TrapHandler)
  OS_HAL_ASM_IMPORT(OsCfg_Stack_KernelStacks)
  OS_HAL_ASM_IMPORT(Os_MemFault)

/***********************************************************************************************************************
 *  Os_Hal_StorePermanentRegisters()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_StorePermanentRegisters)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StorePermanentRegisters)
  stm  r0, {r4-r11}
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StorePermanentRegisters)

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
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_SysCallHandler)
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
 *  Os_Hal_ContextGoWithParameter()
 **********************************************************************************************************************/
 /*! \brief      Stores the return value in the current PC, the current stack pointer and permanent registers
                 in the current context.
                 Then switches execution to the next thread, passing a parameter.
 *   \details    Expected register content:
                 r0 = Parameter for new context
                 r1 = Next->Pc
                 r2 = Next->Lr
                 r3 = Current
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_ContextGoWithParameter)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextGoWithParameter)
  str  lr, [r3]              /* Current->Pc = LR */
  str  sp, [r3, #0x8]        /* Current->Sp = SP */
  add  r3, r3, #0x14         /* Offset of the Current->PermanentRegisters relatively to Current->Pc */
  stm  r3, {r4-r11}          /* Store permanent registers in the current context */
  /* Set the temporary "return" address */
  Os_Hal_Asm_LoadRegister32 lr, ret_label_1
  movs pc, lr                /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_1)
  mov  lr, r2                /* Set the return address from the next context */
  bx   r1                    /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextGoWithParameter)

/***********************************************************************************************************************
 *  Os_Hal_ContextGoWithParameterMpSwitch()
 **********************************************************************************************************************/
 /*! \brief      Stores the return value in the current PC, the current stack pointer and the permanent registers
                 in the current context.
                 Then switches execution to the next thread, passing a parameter.
                 In addition MPU switch is also taken into account.
 *   \details    Expected register content at the function entry point:
                 r0 = Next->StackRegionStart
                 r1 = Next->StackRegionInfo
                 r2 = Current
                 r3 = Next
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_ContextGoWithParameterMpSwitch)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextGoWithParameterMpSwitch)
  str  lr, [r2, #0x00]      /* Current->Pc = LR */
  str  sp, [r2, #0x8]       /* Current->Sp = SP */
  add  r2, r2, #0x14        /* Offset of the Current->PermanentRegisters relatively to Current->Pc */
  stm  r2, {r4-r11}         /* Store permanent registers in the current context */
  mov  r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r12, #0
  mcr  p15,#0,r12,c6,c3,#1  /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r0, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r12, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r12, #0
  mcr  p15,#0,r12,c6,c3,#1  /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr  r0, r0, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r0,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r12, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r12,c6,c2,#1  /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r12,c6,c3,#1  /* r12 = PRLAR */
  and  r12, r12, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r12,c6,c3,#1  /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r2, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r2 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r2, r2, #0x40        /* Align stack protection start address */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r2) */
  orr  r12, r12, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r12,c6,c3,#1  /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
  ldr  r0, [r3, #0x10]      /* r0 = Next->Parameter */
  ldr  r1, [r3, #0x00]      /* r1 = Next->Pc */
  ldr  r2, [r3, #0x0C]      /* r2 = Next->Lr */
  /* Set the temporary "return" address */
  Os_Hal_Asm_LoadRegister32 lr, ret_label_1B
  movs pc, lr               /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_1B)
  mov  lr, r2               /* Set the return address from the next context */
  bx   r1                   /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextGoWithParameterMpSwitch)

/***********************************************************************************************************************
 *  Os_Hal_ContextRestorePermanentAndGo()
 **********************************************************************************************************************/
 /*! \brief      Restore permanent registers and switches execution to the next thread.
 *   \details    Expected register content:
                 r0 = Next
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_ContextRestorePermanentAndGo)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextRestorePermanentAndGo)
  add  r1, r0, #0x14        /* Offset of the Next->PermanentRegisters relatively to Next->Pc */
  ldm  r1, {r4-r11}         /* Load the permanent registers */
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr  r1, [r0, #0x3C]      /* r1 = Next->StackRegionInfo */
  ldr  r2, [r0, #0x38]      /* r2 = Next->StackRegionStart */
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  ldr  r2, [r0, #0x38]      /* r2 = Next->StackRegionStart */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r3,c6,c3,#1   /* r3 = PRLAR */
  and  r3, r3, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r12, r12, #0x40      /* Align stack protection start address */
  mcr p15,#0,r12,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr  r3, r3, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
#endif
  ldr r2, [r0, #0xc]        /* Set the return address from the next context (r2 = Next->lr)*/
  ldr r3, [r0]              /* (r2 = Next->pc)*/

  Os_Hal_Asm_LoadRegister32 lr, ret_label_2   /* Set the temporary "return" address */
  movs pc, lr               /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_2)
  mov  lr, r2               /* Set the return address from the next context (lr = r2)*/
  bx   r3                   /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextRestorePermanentAndGo)

/***********************************************************************************************************************
 *  Os_Hal_ContextGo()
 **********************************************************************************************************************/
 /*! \brief      Switches execution to the next thread.
 *   \details    Expected register content:
                 r0 = Next
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_ContextGo)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextGo)
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr  r1, [r0, #0x3C]      /*r1 = Next->StackRegionInfo */
  ldr  r2, [r0, #0x38]      /*r2 = Next->StackRegionStart */
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r3,c6,c3,#1   /* r3 = PRLAR */
  and  r3, r3, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r12, r12, #0x40      /* Align stack protection start address */
  mcr p15,#0,r12,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr  r3, r3, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
#endif
  ldr r2, [r0, #0xc]        /* Set the return address from the next context (r2 = Next->lr)*/
  ldr r3, [r0]              /* (r3 = Next->pc)*/

  /* Set the temporary "return" address */
  Os_Hal_Asm_LoadRegister32 lr, ret_label_2B
  movs pc, lr               /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_2B)
  mov  lr, r2               /* Set the return address from the next context (lr = r2)*/
  bx   r3                   /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextGo)

/***********************************************************************************************************************
 *  Os_Hal_ContextRestorePermanentAndGoWithReturn()
 **********************************************************************************************************************/
 /*! \brief      Store current PC, permanent regeister, then restores next permanent registers and switches execution
                 to the next thread.
 *   \details    Expected register content:
                 r0 = Next
                 r1 = Current
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_ContextRestorePermanentAndGoWithReturn)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextRestorePermanentAndGoWithReturn)
  str  lr, [r1]             /* Current->Pc = LR */
  str  sp, [r1, #0x8]       /* Current->Sp = SP */
  add  r1, r1, #0x14        /* Offset of the Current->PermanentRegisters relatively to Current->Pc */
  stm  r1, {r4-r11}         /* Store the current permanent register */
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr  r1, [r0, #0x3C]      /*r1 = Next->StackRegionInfo */
  ldr  r2, [r0, #0x38]      /*r2 = Next->StackRegionStart */
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r3, #0
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  ldr  r2, [r0, #0x38]      /*r2 = Next->StackRegionStart */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r3, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r3,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r3,c6,c3,#1   /* r3 = PRLAR */
  and  r3, r3, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r12, r12, #0x40      /* Align stack protection start address */
  mcr p15,#0,r12,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr  r3, r3, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r3,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
#endif
  ldr r2, [r0, #0xc]        /* Set the return address from the next context (r2 = Next->lr)*/
  ldr r3, [r0]              /* (r3 = Next->pc)*/
  add  r1, r0, #0x14        /* Offset of the Next->PermanentRegisters relatively to Current->Pc */
  ldm  r1, {r4-r11}         /* Load the next permanent registers */

  /* Set the temporary "return" address */
  Os_Hal_Asm_LoadRegister32 lr, ret_label_3 
  movs pc, lr               /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_3)
  mov  lr, r2               /* Set the return address from the next context */
  bx   r3                   /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextRestorePermanentAndGoWithReturn)

/***********************************************************************************************************************
 *  Os_Hal_MemFault_PrefetchAbort()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_MemFault_PrefetchAbort)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_MemFault_PrefetchAbort)
  sub  r3, lr, #4           /* r3 = instruction address that caused exception */
  mrs  r4, spsr             /* r4 = CPSR before exception happened */
  cps  #0x1f                /* switch to system mode */
  mrc  p15,#0,r1,c0,c0,#5   /* r1 = MPIDR, get core id */
  and  r0, r1, #0xff        /* r0 = r1 & 0xff, mask bits [7,0] */
  and  r1, r1, #0xff00      /* r1 = r1 & 0xff00, mask bits [15,8] */
  orr  r1, r0, r1, lsr #0x8 /* r1 = (r1 >> 8) | r0 */
  mov  r2, #0x4             /* OsCfg_Stack_KernelStacks has offset size of 4 */
  mul  r1, r2, r1           /* r1 = r2 * r1 */
  Os_Hal_Asm_LoadRegister32 r0, OsCfg_Stack_KernelStacks   /* r0 = &OsCfg_Stack_KernelStacks[0] */
  add  r0, r0, r1           /* r0 = r0 + r1 */
  ldr  r2, [r0, #0]         /* r2 = OsCfg_Stack_KernelStacks[CurrentCore] */
  ldr  sp, [r2, #0]         /* sp = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  ldr  r0, [r2, #4]         /* r0 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionStart */
  mov  r5, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r5, #0
  mcr  p15,#0,r5,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r0, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r5, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r5, #0
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, r1, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r5, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r5,c6,c3,#1   /* r5 = PRLAR */
  and  r5, r5, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r12, r12, #0x40      /* Align stack protection start address */
  mcr  p15,#0,r12,c6,c3,#0  /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr  r5, r5, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
  mov  r0, r3               /* r0 = instruction address that caused exception */
  and  r1, r4, #0xf         /* r1 = 0(User) !0(Supervisor) */
  b    Os_MemFault
  OS_HAL_ASM_FUNCTION_END(Os_Hal_MemFault_PrefetchAbort)

/***********************************************************************************************************************
 *  Os_Hal_MemFault_DataAbort()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_TYPE(Os_Hal_MemFault_DataAbort)
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_MemFault_DataAbort)
  sub  r3, lr, #8           /* r3 = instruction address that caused exception */
  mrs  r4, spsr             /* r4 = CPSR before exception happened */
  cps  #0x1f                /* switch to system mode */
  mrc  p15,#0,r1,c0,c0,#5   /* r1 = MPIDR, get core id */
  and  r0, r1, #0xff        /* r0 = r1 & 0xff, mask bits [7,0] */
  and  r1, r1, #0xff00      /* r1 = r1 & 0xff00, mask bits [15,8] */
  orr  r1, r0, r1, lsr #0x8 /* r1 = (r1 >> 8) | r0 */
  mov  r2, #0x4             /* OsCfg_Stack_KernelStacks has offset size of 4 */
  mul  r1, r2, r1           /* r1 = r2 * r1 */
  Os_Hal_Asm_LoadRegister32 r0, OsCfg_Stack_KernelStacks   /* r0 = &OsCfg_Stack_KernelStacks[0] */
  add  r0, r0, r1           /* r0 = r0 + r1 */
  ldr  r2, [r0, #0]         /* r2 = OsCfg_Stack_KernelStacks[CurrentCore] */
  ldr  sp, [r2, #0]         /* sp = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionEnd */
  ldr  r0, [r2, #4]         /* r0 = OsCfg_Hal_Stack_OsCore0_Kernel->StackRegionStart */
  mov  r5, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  mov  r5, #0
  mcr  p15,#0,r5,c6,c3,#1   /* PRLAR = 0, disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_0_NUMBER */
  orr  r2, r0, #OS_HAL_ENTRY_MP_STACK_ATTR /* r2 = StackRegionStart | OS_HAL_ENTRY_MP_STACK_ATTR */
  sub  r2, r2, #0x40        /* Align stack protection end address */
  mcr  p15,#0,r2,c6,c3,#1   /* PRLAR = r2, Os_Hal_MpSetRegionEndAddressAndEnable(r2) */
  isb
  mov  r5, #OS_HAL_ASM_MP_STACK_REGION_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  mov  r5, #0
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_REGION_NUMBER */
  orr  r2, r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* StackRegionStart |= OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  mcr  p15,#0,r2,c6,c3,#0   /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(StackRegionStart) */
  orr  r1, sp, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackRegionInfo |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r1,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackRegionInfo) */
  isb
  mov  r5, #OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER
  mcr  p15,#0,r5,c6,c2,#1   /* PRSELR = OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  mrc  p15,#0,r5,c6,c3,#1   /* r5 = PRLAR */
  and  r5, r5, #OS_HAL_ENTRY_MP_DISABLE_REGION_MASK
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(0), Disable OS_HAL_ASM_MP_STACK_PROTECTION_REGION_1_NUMBER */
  orr  r12, r1, #OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT /* r12 = StackRegionEnd | OS_HAL_ENTRY_MP_STACK_PROTECTION_ACCESS_RIGHT */
  add  r12, r12, #0x40      /* Align stack protection start address */
  mcr  p15,#0,r12,c6,c3,#0  /* Os_Hal_MpSetRegionBaseAddressAndAccessRights(r12) */
  orr  r5, r5, #OS_HAL_ENTRY_MP_STACK_ATTR /* StackProtectionRegionEnd |= OS_HAL_ENTRY_MP_STACK_ATTR */
  mcr  p15,#0,r5,c6,c3,#1   /* Os_Hal_MpSetRegionEndAddressAndEnable(StackProtectionRegionEnd) */
  isb
  mov  r0, r3               /* r0 = instruction address that caused exception */
  and  r1, r4, #0xf         /* r1 = 0(User) !0(Supervisor) */
  b    Os_MemFault
  OS_HAL_ASM_FUNCTION_END(Os_Hal_MemFault_DataAbort)

#endif /* defined(OS_HAL_CONTEXTASM_V8R_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_ContextAsm_v8r.inc
 *********************************************************************************************************************/
