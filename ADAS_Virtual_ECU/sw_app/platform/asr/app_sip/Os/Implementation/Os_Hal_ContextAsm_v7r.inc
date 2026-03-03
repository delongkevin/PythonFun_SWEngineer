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
 * \file  Os_Hal_ContextAsm_v7r.inc
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

# include "Os_Hal_ContextAsm_v7r_ExcHandlers.inc"

/*! Access right value used for stack region (OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN |
 *  OS_HAL_MP_ACCESS_TYPE_CACHEABLE_WRITEBACK_ALLOCATE | OS_HAL_MP_ACCESS_S_RW_U_RW). */
# define OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT   0x130B

  OS_HAL_ASM_PRESERVE8
  OS_HAL_ASM_CODE_SECTION(OS_CODE)

  OS_HAL_ASM_EXPORT(Os_Hal_StorePermanentRegisters)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGoWithParameter)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGoWithParameterMpSwitch)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextRestorePermanentAndGo)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextGo)
  OS_HAL_ASM_EXPORT(Os_Hal_ContextRestorePermanentAndGoWithReturn)


/***********************************************************************************************************************
 *  Os_Hal_StorePermanentRegisters()
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_StorePermanentRegisters)
  stm  r0, {r4-r11}
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_StorePermanentRegisters)


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
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextGoWithParameterMpSwitch)
  str  lr, [r2, #0x00]      /* Current->Pc = LR */
  str  sp, [r2, #0x8]       /* Current->Sp = SP */
  add  r2, r2, #0x14        /* Offset of the Current->PermanentRegisters relatively to Current->Pc */
  stm  r2, {r4-r11}         /* Store permanent registers in the current context */
  mov  r2, #OS_HAL_MP_STACK_REGION_NUMBER_ASM
  mcr  p15,#0,r2,c6,c2,#0   /* Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER_ASM) */
  mov  r2, #0               /* r2[0..7] = 0 */
  mcr  p15,#0,r2,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(0) */
  mcr  p15,#0,r0,c6,c1,#0   /* Os_Hal_MpSetRegionBaseAddress(StackRegionStart) */
  movw r2, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* r2[0..15] = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  movt r2, #0               /* r2[16..31] = 0 */
  mcr  p15,#0,r2,c6,c1,#4   /* Os_Hal_MpSetRegionAccessControl(OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT) */
  mcr  p15,#0,r1,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(StackRegionInfo) */
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
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextRestorePermanentAndGo)
  add  r1, r0, #0x14         /* Offset of the Next->PermanentRegisters relatively to Next->Pc */
  ldm  r1, {r4-r11}          /* Load the permanent registers */
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr r1, [r0, #0x3C]      /*r1 = Next->StackRegionInfo */
  ldr r2, [r0, #0x38]      /*r2 = Next->StackRegionStart */
  mov  r3, #OS_HAL_MP_STACK_REGION_NUMBER_ASM
  mcr  p15,#0,r3,c6,c2,#0   /* Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER_ASM) */
  mov  r3, #0               /* r2[0..7] = 0 */
  mcr  p15,#0,r3,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(0) */
  mcr  p15,#0,r2,c6,c1,#0   /* Os_Hal_MpSetRegionBaseAddress(StackRegionStart) */
  movw r3, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* r2[0..15] = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  movt r3, #0               /* r2[16..31] = 0 */
  mcr  p15,#0,r3,c6,c1,#4   /* Os_Hal_MpSetRegionAccessControl(OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT) */
  mcr  p15,#0,r1,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(StackRegionInfo) */
  isb
#endif
  ldr r2, [r0, #0xc]        /* Set the return address from the next context (r2 = Next->lr)*/
  ldr r3, [r0]              /* (r2 = Next->pc)*/
  Os_Hal_Asm_LoadRegister32 lr, ret_label_2   /* Set the temporary "return" address */
  movs pc, lr                /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_2)
  mov  lr, r2                /* Set the return address from the next context (lr = r2)*/
  bx   r3                    /* Jump to the entry point */
  /* does not return */
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ContextRestorePermanentAndGo)

/***********************************************************************************************************************
 *  Os_Hal_ContextGo()
 **********************************************************************************************************************/
 /*! \brief      Switches execution to the next thread.
 *   \details    Expected register content:
                 r0 = Next
 **********************************************************************************************************************/
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextGo)
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr r1, [r0, #0x3C]      /*r1 = Next->StackRegionInfo */
  ldr r2, [r0, #0x38]      /*r0 = Next->StackRegionStart */
  mov  r3, #OS_HAL_MP_STACK_REGION_NUMBER_ASM
  mcr  p15,#0,r3,c6,c2,#0   /* Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER_ASM) */
  mov  r3, #0               /* r2[0..7] = 0 */
  mcr  p15,#0,r3,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(0) */
  mcr  p15,#0,r2,c6,c1,#0   /* Os_Hal_MpSetRegionBaseAddress(StackRegionStart) */
  movw r3, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* r2[0..15] = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  movt r3, #0               /* r2[16..31] = 0 */
  mcr  p15,#0,r3,c6,c1,#4   /* Os_Hal_MpSetRegionAccessControl(OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT) */
  mcr  p15,#0,r1,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(StackRegionInfo) */
  isb
#endif
  ldr r2, [r0, #0xc]        /* Set the return address from the next context (r2 = Next->lr)*/
  ldr r3, [r0]              /* (r3 = Next->pc)*/

  /* Set the temporary "return" address */
  Os_Hal_Asm_LoadRegister32 lr, ret_label_2B
  movs pc, lr                /* Changes CPU mode and switches stack */
OS_HAL_ASM_DEFINE_LABEL(ret_label_2B)
  mov  lr, r2                /* Set the return address from the next context (lr = r2)*/
  bx   r3                    /* Jump to the entry point */
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
OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ContextRestorePermanentAndGoWithReturn)
  str  lr, [r1]             /* Current->Pc = LR */
  str  sp, [r1, #0x8]       /* Current->Sp = SP */
  add  r1, r1, #0x14        /* Offset of the Current->PermanentRegisters relatively to Current->Pc */
  stm  r1, {r4-r11}         /* Store the current permanent register */
#if defined (OS_HAL_CFG_MEMORY_PROTECTION_ASM)
  ldr  r1, [r0, #0x3C]      /* r1 = Next->StackRegionInfo */
  ldr  r2, [r0, #0x38]      /* r2 = Next->StackRegionStart */
  mov  r3, #OS_HAL_MP_STACK_REGION_NUMBER_ASM
  mcr  p15,#0,r3,c6,c2,#0   /* Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_REGION_NUMBER_ASM) */
  mov  r3, #0               /* r3[0..7] = 0 */
  mcr  p15,#0,r3,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(0) */
  mcr  p15,#0,r2,c6,c1,#0   /* Os_Hal_MpSetRegionBaseAddress(StackRegionStart) */
  movw r3, #OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT /* r3[0..15] = OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT */
  movt r3, #0               /* r3[16..31] = 0 */
  mcr  p15,#0,r3,c6,c1,#4   /* Os_Hal_MpSetRegionAccessControl(OS_HAL_ENTRY_MP_STACK_ACCESS_RIGHT) */
  mcr  p15,#0,r1,c6,c1,#2   /* Os_Hal_MpSetRegionSizeAndEnable(StackRegionInfo) */
  isb
#endif
  ldr  r2, [r0, #0xc]       /* Set the return address from the next context (r2 = Next->lr)*/
  ldr  r3, [r0]             /* (r3 = Next->pc)*/
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

#endif /* defined(OS_HAL_CONTEXTASM_V7R_INC) */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_ContextAsm_v7r.inc
 *********************************************************************************************************************/
