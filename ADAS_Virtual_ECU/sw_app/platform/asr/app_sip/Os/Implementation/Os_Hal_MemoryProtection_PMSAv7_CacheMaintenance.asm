/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_MemoryProtection  HAL Memory Protection
 *  \{
 *
 *  \file
 *  \brief        Internal functions and data types related to memory protection.
 *  \details
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Os_Hal_CompilerInt.inc"

# if !defined(OS_STATIC_CODE_ANALYSIS)
  OS_HAL_ASM_EXPORT(Os_Hal_FlushInstructionCache)
  OS_HAL_ASM_EXPORT(Os_Hal_FlushDataCache)

  OS_HAL_ASM_CODE_SECTION(OS_CODE)
  OS_HAL_ASM_ARM_CODE

/***********************************************************************************************************************
 *  Os_Hal_FlushInstructionCache()
 **********************************************************************************************************************/

OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_FlushInstructionCache)
  push {r0}
  mov  r0, #0
  mcr p15,#0,r0,c7,c5,#0      /* Invalidate instruction cache. */
  mcr p15,#0,r0,c7,c5,#6      /* Invalidate branch prediction. */
  isb
  pop  {r0}
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_FlushInstructionCache)


/***********************************************************************************************************************
 *  Os_Hal_FlushDataCache()
**********************************************************************************************************************/

OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_FlushDataCache)
  push {r0-r12}
  mrc p15,#1,r0,c0,c0,#1      /* Read CLIDR into r0. */
  ands r3, r0, #0x07000000    /* Get LoC bit field. */
  mov r3, r3, LSR #23         /* Cache level value (aligned). */
  beq Finished                /* If r3=0 --> jump to Finished */
  mov r10, #0
OS_HAL_ASM_DEFINE_LABEL(Loop1)
  add r2, r10, r10, LSR #1    /* Work out 3 x cachelevel */
  mov r1, r0, LSR r2          /* Bottom 3 bits are the cache type for this level. */
  and r1, r1, #7              /* Get only 3 bottom bits. */
  cmp r1, #2
  blt Skip                    /* No cache or olny instruction cache at this level. */
  mcr p15,#2,r10,c0,c0,#0     /* Write CSSELR from r10. (selects cache level, for R7 only one level present). */
  isb                         /* Sync change to CCSIDR register. */
  mrc p15,#1,r1,c0,c0,#0      /* Read current CCSIDR register to r1. */
  and r2, r1, #7              /* Extract the line length field. */
  add r2, r2, #4              /* Add 4 for the line length offset (log2 16 bytes). */
  movw r4, #0x03FF
  movt r4, #0x0000
  ands r4, r4, r1, LSR #3     /* r4 = max number on the way size (right aligned). */
  clz r5, r4                  /* r5 = bit position of the way size increment. */
  mov r9, r4                  /* r9 = working copy of the max way size (right aligned). */
OS_HAL_ASM_DEFINE_LABEL(Loop2)
  movw r7, #0x7fff
  movt r7, #0x0000
  ands r7, r7, r1, LSR #13    /* r7 = max num of the index size (right aligned). */
OS_HAL_ASM_DEFINE_LABEL(Loop3)
  orr r11, r10, r9, LSL r5    /* Factor in the way number and cache number into r11. */
  orr r11, r11, r7, LSL r2    /* Factor in the index number. */
  mcr p15,#0,r11,c7,c10,#2    /* DCCSW, clean by set/way. */
  subs r7, r7, #1             /* Decrement the index. */
  bge Loop3
  subs r9, r9, #1             /* Decrement the way number. */
  bge Loop2
OS_HAL_ASM_DEFINE_LABEL(Skip)
  add r10, r10, #2            /* Increment the cache number. */
  cmp r3, r10
  bgt Loop1
  dsb
OS_HAL_ASM_DEFINE_LABEL(Finished)
  pop {r0-r12}
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_FlushDataCache)


# endif /* !defined(OS_STATIC_CODE_ANALYSIS) */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_PMSAv7_CacheMaintenance.asm
 *********************************************************************************************************************/

  OS_HAL_ASM_MODULE_END

