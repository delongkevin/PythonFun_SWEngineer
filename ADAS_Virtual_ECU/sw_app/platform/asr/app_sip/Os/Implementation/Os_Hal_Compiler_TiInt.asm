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
 *  \addtogroup Os_Hal_Compiler
 *  \{
 *
 *  \file
 *  \brief        Compiler abstraction for Texas Instruments compiler (assembler functions).
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

  OS_HAL_ASM_CODE_SECTION(OS_CODE)
  OS_HAL_ASM_DUMMY_NOP

# if defined(OS_CFG_COMPILER_TEXASINSTRUMENTS)
#  if !defined(OS_STATIC_CODE_ANALYSIS)
  OS_HAL_ASM_EXPORT(Os_Hal_ReadFpscr)
  OS_HAL_ASM_EXPORT(Os_Hal_ReadFpexc)

/***********************************************************************************************************************
 *  Os_Hal_ReadFpscr()
 **********************************************************************************************************************/

OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ReadFpscr)
  .if __TI_VFP_SUPPORT__
  vmrs r0, FPSCR
  .endif
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ReadFpscr)

/***********************************************************************************************************************
 *  Os_Hal_ReadFpexc()
**********************************************************************************************************************/

OS_HAL_ASM_FUNCTION_BEGIN(Os_Hal_ReadFpexc)
  .if __TI_VFP_SUPPORT__
  vmrs r0, FPEXC
  .endif
  bx   lr
  OS_HAL_ASM_FUNCTION_END(Os_Hal_ReadFpexc)


#  endif /* !defined(OS_STATIC_CODE_ANALYSIS) */
# endif /* defined(OS_CFG_COMPILER_TEXASINSTRUMENTS) */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_TiInt.asm
 *********************************************************************************************************************/

  OS_HAL_ASM_MODULE_END

