/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  ARMStartup_CortexR.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for all platforms with ARM core Cortex-R
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.00]
 *
 *  \brief Description:  This file contains the assembler part of the BRS StartUpCode.
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to ARMBrsHw_CortexR.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsHw.h"
#include "BrsMain.h"
#include "vLinkGen_Lcfg.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (ARMBRSHW_CORTEXR_VERSION != 0x0104u)
  #error "Header and source file are inconsistent!"
#endif
#if (ARMBRSHW_CORTEXR_BUGFIX_VERSION != 0x06u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)

#else
  #error "Unknown compiler specified!"
#endif

#if (BRS_CPU_CORE_AMOUNT > 6)
  #error "Only up to 6 cores are supported by this StartupCode yet!"
#endif

#if (VLINKGEN_CFG_MAJOR_VERSION != 2u)
  #error "This StartUpCode is dependent to the vLinkGen version! vLinkGen major version does not fit!"
#else
# if (VLINKGEN_CFG_MINOR_VERSION < 0u)
  #error "This StartUpCode is dependent to the vLinkGen version! Your vLinkGen minor version is too old!"
# endif
#endif

/* =========================================================================== */
/* Definitions                                                                 */
/* =========================================================================== */



/* =========================================================================== */
/*                                                                             */
/* Description: Definition of external functions                               */
/*                                                                             */
/* =========================================================================== */

/* =========================================================================== */
/*                                                                             */
/* Description: Entry point for all cores                                      */
/*                                                                             */
/* =========================================================================== */


BRS_SECTION_CODE(brsStartup)
/* reset */
 BRS_GLOBAL(brsStartupEntry)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsStartupEntry)
#if defined (BRSHW_PRE_ASM_STARTUP_HOOK_AVAILABLE)
#endif

 BRS_BRANCH(brsPreAsmStartupHook)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()


/* =========================================================================== */
/*                                                                             */
/* Description: Optional hook for platform specific tasks                      */
/*                                                                             */
/* =========================================================================== */
#if !defined (BRSHW_PRE_ASM_STARTUP_HOOK_AVAILABLE)
 BRS_GLOBAL(brsPreAsmStartupHook)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsPreAsmStartupHook)
/* Nothing to do here */

 BRS_BRANCH(coreRegisterInit)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
#endif /*!BRSHW_PRE_ASM_STARTUP_HOOK_AVAILABLE*/

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize core ID independent core registers                  */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit)

 __as1(LDR  r0, =BrsStartupInstSetInit)

#if defined (BRS_INSTRUCTION_SET_THUMB)
# if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ORR  r0 ,r0, 1)
# else
 __as2(ORR  r0 ,r0, #1)
# endif
 ___asm(BX  r0)

#elif defined (BRS_INSTRUCTION_SET_ARM)
# if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ORR  r0 ,r0, 0)
# else
 __as2(ORR  r0 ,r0, #0)
# endif
 ___asm(BX  r0)
#endif /*BRS_INSTRUCTION_SET_x*/


BRS_LABEL(BrsStartupInstSetInit)

#if defined (BRS_FPU_USED)
 /* Allow full access to coprocessors 10,11 */
 /* r0 gets the content of the Coprocessor Access Control Register */
# if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as5(MRC  p15, 0, r0, c1, c0, 2)
# else
 __as5(MRC  p15, #0x00, r0, c1, c0, #0x02)
# endif

 __as2(ORR  r0, r0, #0x00F00000)
 /* Write Coprocessor Access Control Register to set access rights for coprocessor cp10, cp11 to full access
    Note: Coprocessors cp10 and cp11 support floating-point and vector operations, and the control and configuration of
          the Floating-point and Advanced SIMD architecture extensions. */
# if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as5(MCR  p15, 0, r0, c1, c0, 2)
# else
 __as5(MCR  p15, #0x00, r0, c1, c0, #0x02)
# endif

/* Enable Advanced SIMD and Floating-point Extensions */
 __as1(VMRS r0, FPEXC)
 __as1(MOV  r1, #0x40000000)
 __as2(ORR  r0, r0, r1)
 __as1(VMSR FPEXC, r0)
#endif /*BRS_FPU_USED*/

/* Switch to System Mode */
 __as1(MRS  r0, CPSR)
#if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ORR  r0, r0, 0x1f)
 __as1(MSR  CPSR, r0)
#else
 __as2(ORR  r0, r0, #0x1f)
 __as1(MSR  cpsr_cxsf, r0)
#endif

 BRS_BRANCH(coreRegisterInit2)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core ID dependent core registers                */
/*              Configure INTBP and EBASE address.                             */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit2)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit2)
/* Nothing to do for Cortex-A/R */

 BRS_BRANCH(brsStartupZeroInitLoop)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize memory blocks and groups with zero                  */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(brsStartupZeroInitLoop)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(brsStartupZeroInitLoop)

 BRS_READ_COREID(R0)

/* Initialize memory sections blocks with zeros */
#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL)
 __as1(LDR  R1, =vLinkGen_ZeroInit_Early_Blocks)

BRS_LABEL(startup_block_zero_init_start)
 __as1(MOV  R2, R1)

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ADD  R1, R1, 16)
#  else
 __as2(ADD  R1, R1, #16)
#  endif

 __as1(LDR  R3, [R2])      /* vLinkGen_ZeroInit_Early_Blocks->start */
 __as2(LDR  R4, [R2,#4])   /* vLinkGen_ZeroInit_Early_Blocks->end */
 __as2(LDR  R5, [R2, #8])  /* vLinkGen_ZeroInit_Early_Blocks->core */
 __as2(LDR  R6, [R2, #12]) /* vLinkGen_ZeroInit_Early_Blocks->alignment */

/* Verify if the end of struct vLinkGen_ZeroInit_Early_Blocks is reached, by checking if start == 0, end == 0 and core == 0 */
#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as1(MOV  R7, 0)
#  else
 __as1(MOV  R7, #0)
#  endif

 __as2(ORR  R7, R7, R3) /* Or with vLinkGen_ZeroInit_Early_Blocks->start */
 __as2(ORR  R7, R7, R4) /* Or with vLinkGen_ZeroInit_Early_Blocks->end */
 __as2(ORR  R7, R7, R5) /* Or with vLinkGen_ZeroInit_Early_Blocks->core */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 BRS_BRANCH_EQUAL(R7, 0, startup_block_zero_init_end) /* If start address, end address and core are equal to zero -> Finished */
#  else
 BRS_BRANCH_EQUAL(R7, #0, startup_block_zero_init_end) /* If start address, end address and core are equal to zero -> Finished */
#  endif

 BRS_BRANCH_NOT_EQUAL(R0, R5, startup_block_zero_init_start) /* If InitCore is not running -> go to the next array entry */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as1(MOV  R7, 0) /* set R7 to '0', as value to write in memory later */
 __as1(MOV  R8, 0) /* set R8 to '0', as value to write in memory later */
#  else
 __as1(MOV  R7, #0) /* set R7 to '0', as value to write in memory later */
 __as1(MOV  R8, #0) /* set R8 to '0', as value to write in memory later */
#  endif

 BRS_BRANCH_EQUAL(R6, #8, startup_block_zero_init_8byte_loop_start) /* if block is 8-Byte aligned, use specific init loop */

BRS_LABEL(startup_block_zero_init_loop_start)
 BRS_BRANCH_GREATER_THAN_OR_EQUAL(R3, R4, startup_block_zero_init_start) /* if start address is same with or higher than end address-> Finished. */

 __as1(STR  R7, [R3]) /* write value of R7 ('0') to address of R3 (4-byte access); must be an aligned memory access! */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ADD  R3, R3, 4) /* increase address value of R3 by '4' */
#  else
 __as2(ADD  R3, R3, #4) /* increase address value of R3 by '4' */
#  endif

/* End address of this block was not yet reached. Run through the loop again */
 BRS_BRANCH(startup_block_zero_init_loop_start)

/* ================================================================ */
/* 8-Byte aligned initialization, to support 8-Byte aligned ECC RAM */
/* ================================================================ */
BRS_LABEL(startup_block_zero_init_8byte_loop_start)
 BRS_BRANCH_GREATER_THAN_OR_EQUAL(R3, R4, startup_block_zero_init_start) /* if start address is same with or higher than end address-> Finished. */

/* Address stored in R3 must be 8 Byte aligned at this point! */
 __as2(STMIA R3!, {R7, R8}) /* 8 Byte alignment store for ECC, R3 would be automatically updated after the write */

/* End address of this block was not yet reached. Run through the loop again */
 BRS_BRANCH(startup_block_zero_init_8byte_loop_start)

/* Zero-Init loop of blocks end label */
BRS_LABEL(startup_block_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS*/

/* Initialize memory sections groups with zeros */
#if defined (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS)
# if (VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL)
 __as1(LDR  R1, =vLinkGen_ZeroInit_Early_Groups)

BRS_LABEL(startup_group_zero_init_start)
 __as1(MOV  R2, R1)

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ADD  R1, R1, 16)
#  else
 __as2(ADD  R1, R1, #16)
#  endif

 __as1(LDR  R3, [R2])      /* vLinkGen_ZeroInit_Early_Groups->start */
 __as2(LDR  R4, [R2,#4])   /* vLinkGen_ZeroInit_Early_Groups->end */
 __as2(LDR  R5, [R2, #8])  /* vLinkGen_ZeroInit_Early_Groups->core */
 __as2(LDR  R6, [R2, #12]) /* vLinkGen_ZeroInit_Early_Groups->alignment */

/* Verify if the end of struct vLinkGen_ZeroInit_Early_Groups is reached, by checking if start == 0, end == 0 and core == 0 */
#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as1(MOV  R7, 0)
#  else
 __as1(MOV  R7, #0)
#  endif

 __as2(ORR  R7, R7, R3) /* Or with vLinkGen_ZeroInit_Early_Groups->start */
 __as2(ORR  R7, R7, R4) /* Or with vLinkGen_ZeroInit_Early_Groups->end */
 __as2(ORR  R7, R7, R5) /* Or with vLinkGen_ZeroInit_Early_Groups->core */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 BRS_BRANCH_EQUAL(R7, 0,  startup_group_zero_init_end) /* If start address, end address and core are equal to zero -> Finished */
#  else
 BRS_BRANCH_EQUAL(R7, #0,  startup_group_zero_init_end) /* If start address, end address and core are equal to zero -> Finished */
#  endif

 BRS_BRANCH_NOT_EQUAL(R0, R5, startup_group_zero_init_start) /* If InitCore is not running -> go to the next array entry */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as1(MOV  R7, 0) /* set R7 to '0', as value to write in memory later */
 __as1(MOV  R8, 0) /* set R8 to '0', as value to write in memory later */
#  else
 __as1(MOV  R7, #0) /* set R7 to '0', as value to write in memory later */
 __as1(MOV  R8, #0) /* set R8 to '0', as value to write in memory later */
#  endif

 BRS_BRANCH_EQUAL(R6, #8, startup_group_zero_init_8byte_loop_start) /* if group is 8-Byte aligned, use specific init loop */

BRS_LABEL(startup_group_zero_init_loop_start)
 BRS_BRANCH_GREATER_THAN_OR_EQUAL(R3, R4, startup_group_zero_init_start) /* if start address is same with or higher than end address-> Finished. */

 __as1(STR  R7, [R3]) /* write value of R7 ('0') to address of R3 (4-byte access); must be an aligned memory access! */

#  if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as2(ADD  R3, R3, 4) /* increase address value of R3 by '4' */
#  else
 __as2(ADD  R3, R3, #4) /* increase address value of R3 by '4' */
#  endif

/* End address of this group was not yet reached. Run through the loop again */
 BRS_BRANCH(startup_group_zero_init_loop_start)

/* ================================================================ */
/* 8-Byte aligned initialization, to support 8-Byte aligned ECC RAM */
/* ================================================================ */
BRS_LABEL(startup_group_zero_init_8byte_loop_start)
 BRS_BRANCH_GREATER_THAN_OR_EQUAL(R3, R4, startup_group_zero_init_start) /* if start address is same with or higher than end address-> Finished. */

/* Address stored in R3 must be 8 Byte aligned at this point! */
 __as2(STMIA R3!, {R7, R8}) /* 8 Byte alignment store for ECC, R3 would be automatically updated after the write */

/* End address of this group was not yet reached. Run through the loop again */
 BRS_BRANCH(startup_group_zero_init_8byte_loop_start)

/* Zero-Init loop of groups end label */
BRS_LABEL(startup_group_zero_init_end)
# endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS>1uL*/

#else
  #error "Mandatory define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS missing within vLinkGen configuration!"
#endif /*VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS*/

/* Branch to the core ID specific stack pointer init routines */
#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
#  if (BRS_CPU_CORE_AMOUNT > 5)
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE5_ID,StackPointerInit_c5)
#  endif
#  if (BRS_CPU_CORE_AMOUNT > 4)
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE4_ID,StackPointerInit_c4)
#  endif
#  if (BRS_CPU_CORE_AMOUNT > 3)
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE3_ID,StackPointerInit_c3)
#  endif
#  if (BRS_CPU_CORE_AMOUNT > 2)
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE2_ID,StackPointerInit_c2)
#  endif
#  if (BRS_CPU_CORE_AMOUNT > 1)
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE1_ID,StackPointerInit_c1)
#  endif
 BRS_BRANCH_EQUAL(r0,#BRSHW_DERIVATIVE_CORE0_ID,StackPointerInit_c0)

 /* Still here? ID is not supported yet -> BrsMainExceptionStartup */
 BRS_EXTERN_BRANCH(BrsMainExceptionStartup)
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* Jump to Core0 init function for singlecore derivatives */
 BRS_BRANCH(StackPointerInit_c0)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
# if (BRS_CPU_CORE_AMOUNT > 5)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 5).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c5)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c5)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c5_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>5*/

# if (BRS_CPU_CORE_AMOUNT > 4)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 4).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c4)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c4)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c4_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>4*/

# if (BRS_CPU_CORE_AMOUNT > 3)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 3).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c3)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c3)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c3_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>3*/

# if (BRS_CPU_CORE_AMOUNT > 2)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 2).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c2)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c2)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c2_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>2*/

# if (BRS_CPU_CORE_AMOUNT > 1)
/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 1).                                                      */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c1)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c1)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c1_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()
# endif /*BRS_CPU_CORE_AMOUNT>1*/
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize all core registers with specific init values        */
/*              (Core 0). Also used for singlecore derivatives                 */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(StackPointerInit_c0)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(StackPointerInit_c0)


/* Initialization of this core stack pointer (system mode only here) */
 __as1(LDR  R0, =__section_stack_c0_end)
 __as1(MOV  SP, R0)

 BRS_BRANCH(coreRegisterInit3)
BRS_MULTILINE_ASM_END()
BRS_GLOBAL_END()

/* =========================================================================== */
/*                                                                             */
/* Description: Initialize additional core registers                           */
/*                                                                             */
/* =========================================================================== */
 BRS_GLOBAL(coreRegisterInit3)
BRS_MULTILINE_ASM_BEGIN()
BRS_LABEL(coreRegisterInit3)
BRS_MULTILINE_ASM_END()

#if defined (BRS_DERIVATIVE_TDA4VM88) || defined (BRS_DERIVATIVE_TDA4VE88)
/* Disable TCM - needed for Jacinto7 platform, previous to stack usage */
 __as1(MOV  R0, #0)
# if defined (BRS_COMP_LLVMTEXASINSTRUMENTS)
 __as5(MCR  p15, 0, r0, c9, c1, 1)
# else
 __as5(MCR  p15, #0x00, r0, c9, c1, #0x01)
# endif
#endif /*BRS_DERIVATIVE_x*/

#if defined (BRS_DERIVATIVE_TDA4VM88) || defined (BRS_DERIVATIVE_TDA4VE88) || defined (BRS_DERIVATIVE_TPR12)
 BRS_GLOBAL(__mpu_init)
 ___asm(BL __mpu_init)
#endif

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to Brs_PreMainStartup() (BrsMainStartup.c)                */
/*                                                                             */
/* =========================================================================== */
// BRS_EXTERN_BRANCH(Brs_PreMainStartup)

/* =========================================================================== */
/*                                                                             */
/* Description: Jump to BrsMainExceptionStartup() in case of an unexpected     */
/*              return from PreMain/main                                       */
/*                                                                             */
/* =========================================================================== */
// BRS_EXTERN_BRANCH(BrsMainExceptionStartup)



