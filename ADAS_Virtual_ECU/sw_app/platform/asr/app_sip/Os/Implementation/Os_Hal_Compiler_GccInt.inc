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
 *  \addtogroup Os_Hal_Compiler
 *  \{
 *
 *  \file       Os_Hal_Compiler_GccInt.inc
 *  \brief      Additional GCC assembler compiler abstraction.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILER_GCCINT_INC
# define OS_HAL_COMPILER_GCCINT_INC

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/*! \brief    Directive used for assembler parameter definition.
 */
# define OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Param)               Param

/*! \brief    Directive used for assembler parameter definition.
 */
# define OS_HAL_ASM_MACRO_PARAMS_IN_HEADER(Param1, Param2, Param3, Param4)        Param1, Param2, Param3, Param4

/*! \brief    Directive used for assembler parameter usage.
 */
# define OS_HAL_ASM_MACRO_PARAM_IN_BODY(Param)                \Param

/*! \brief
 */
# define OS_HAL_ASM_MACRO_WITHOUT_PARAM_BEGIN(MacroName) .macro MacroName

/*! \brief
 */
# define OS_HAL_ASM_MACRO_BEGIN_1(MacroName, Params)

/*! \brief    Directive used to mark the beginning of a macro
 */
# define OS_HAL_ASM_MACRO_BEGIN_2(MacroName, Params) .macro MacroName Params

/*! \brief    Directive used to mark the end of a macro
 */
# define OS_HAL_ASM_MACRO_END                        .endm

/*! \brief    Causes the identifier Label to be visible externally.
 *  \details  If the identifier is defined in the current module, this directive allows the linker to resolve
 *            references by other modules. If the identifier is not defined in the current module,
 *            the assembler resolves it externally.
 */
# define OS_HAL_ASM_EXPORT(Label)                    .global Label

/*! \brief     You usually use this directive when you want to explicitly declare Label as defined in another module.
 *  \details   The assembler does not require this usage, however.
 */
# define OS_HAL_ASM_IMPORT(Label)

/*! \brief     Directs assembly output into the section named SectionName, which should have memory allocated for it.
 *             and contains executable code.
 */
# define OS_HAL_ASM_CODE_SECTION(SectionName)        .section .SectionName, "ax"

/*! \brief     Directs assembly output into the section named SectionName, which should have memory allocated for it.
 */
# define OS_HAL_ASM_CONST_SECTION(SectionName)       .section .SectionName, "a"

/*! \brief     Specifies the given assembly label as function, so interworking between arm and thumb mode works correctly.
 */
# define OS_HAL_ASM_FUNCTION_TYPE(FunctionName)

/*! \brief    Switches to the 32-bit ARM code
 */
# define OS_HAL_ASM_ARM_CODE                         .arm

/*! \brief    Switches to mixed 16-bit and 32-bit Thumb-2 code
 */
# define OS_HAL_ASM_THUMB_CODE                       .thumb

/*! \brief    Directive used to mark the beginning of an assembler function.
 */
# define OS_HAL_ASM_FUNCTION_BEGIN(FunctionName)     FunctionName:

/*! \brief    Directive used to mark the end of an assembler function.
 *  \details  In this case the macro includes a directive (.ltorg) to collect all the literals belonging to the section,
 *            otherwise compile errors could occurs depending where they are going to be allocated.
 */
# define OS_HAL_ASM_FUNCTION_END(FunctionName)       .ltorg

/*! \brief    Directive used to mark the end of the current module.
 */
# define OS_HAL_ASM_MODULE_END                       .end

/*! \brief    Macro used to load a register with an immediate value
 */
.macro Os_Hal_Asm_Load_Register_Immediate Register, Immediate
  ldr \Register, =\Immediate
  .endm

/*! \brief    Directive used to define a constant.
 */
# define OS_HAL_ASM_EQU(Label, Value)                 .equ Label, Value

/*! \brief    Directive used to define a label.
 */
# define OS_HAL_ASM_DEFINE_LABEL(Label)               Label:

/*! \brief    Directive used to place a 32 bit constant in memory.
 */
# define OS_HAL_ASM_DEFINE_WORD(Value)                .word Value

/*! \brief    Directive used to specify that the current file preserves 8-bytes alignment of the stack.
 */
# define OS_HAL_ASM_PRESERVE8

/*! \brief    Directive used to specify that the current file requires 8-bytes alignment of the stack.
 */
# define OS_HAL_ASM_REQUIRE8

  .macro Os_Hal_Asm_LoadRegister32 Register, Value
  ldr \Register, =\Value
  .endm
  
/*! \brief    Directive used to specify the alignment of 4.
 */
# define OS_HAL_ASM_ALIGN4

/*! \brief    Directive used for no operation (NOP).
 */
# define OS_HAL_ASM_DUMMY_NOP  NOP

#endif /* OS_HAL_COMPILER_GCCINT_INC */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_GccInt.inc
 **********************************************************************************************************************/
