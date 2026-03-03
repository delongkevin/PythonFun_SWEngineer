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
 *  \file       Os_Hal_Compiler_TiInt.inc
 *  \brief      Additional Texax Instruments assembler compiler abstraction.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILERTIINT_INC
# define OS_HAL_COMPILERTIINT_INC

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/*! \brief    Directive used for assembler parameter definition.
 */
# define OS_HAL_ASM_MACRO_PARAM_IN_HEADER(Param)               Param

/*! \brief    Directive used for assembler parameter definition.
 */
# define OS_HAL_ASM_MACRO_PARAMS_IN_HEADER(Param1, Param2, Param3, Param4)        Param1, Param2, Param3, Param4

/*! \brief    Directive used for assembler parameter definition.
 */
# define OS_HAL_ASM_MACRO_PARAM_IN_BODY(Param)                 Param

/*! \brief
 */
# define OS_HAL_ASM_MACRO_WITHOUT_PARAM_BEGIN(MacroName) MacroName .macro

/*! \brief
 */
# define OS_HAL_ASM_MACRO_BEGIN_1(MacroName, Params) MacroName .macro  Params

/*! \brief    Directive used to mark the beginning of a macro
 */
# define OS_HAL_ASM_MACRO_BEGIN_2(MacroName, Params)

/*! \brief    Directive used to mark the end of a macro
 */
# define OS_HAL_ASM_MACRO_END                        .endm

/*! \brief    Causes the identifier Label to be visible externally.
 *  \details  If the identifier is defined in the current module, this directive allows the linker to resolve
 *            references by other modules. If the identifier is not defined in the current module,
 *            the assembler resolves it externally.
 */
# define OS_HAL_ASM_EXPORT(Label)                    .def Label

/*! \brief     You usually use this directive when you want to explicitly declare Label as defined in another module.
 *  \details   The assembler does not require this usage, however.
 */
# define OS_HAL_ASM_IMPORT(Label)                    .global Label

/*! \brief     Directs assembly output into the section named SectionName, which should have memory allocated for it.
 *             and contains executable code.
 */
# define OS_HAL_ASM_CODE_SECTION(SectionName)        .sect .SectionName, RO

/*! \brief     Directs assembly output into the section named SectionName, which should have memory allocated for it.
 */
# define OS_HAL_ASM_CONST_SECTION(SectionName)       .sect .SectionName, RO

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
# define OS_HAL_ASM_FUNCTION_BEGIN(FunctionName)     FunctionName .asmfunc

/*! \brief    Directive used to mark the end of an assembler function.
 */
# define OS_HAL_ASM_FUNCTION_END(FunctionName)       .endasmfunc

/*! \brief    Directive used to mark the end of the current module.
 */
# define OS_HAL_ASM_MODULE_END                       .end

/*! \brief    Macro used to load a register with an immediate value
 */
Os_Hal_Asm_Load_Register_Immediate .macro Register, Immediate
  movw Register, Immediate
  movt Register, Immediate
  .endm

/*! \brief    Directive used to define a label.
 */
# define OS_HAL_ASM_DEFINE_LABEL(Label)              Label

/*! \brief    Directive used to define a constant.
 */
# define OS_HAL_ASM_EQU(Label, Value)                Label .equ Value

/*! \brief    Directive used to place a 32 bit constant in memory.
 */
# define OS_HAL_ASM_DEFINE_WORD(Value)               .long Value

/*! \brief    Directive used to specify that the current file preserves 8-bytes alignment of the stack.
 */
# define OS_HAL_ASM_PRESERVE8

/*! \brief    Directive used to specify that the current file requires 8-bytes alignment of the stack.
 */
# define OS_HAL_ASM_REQUIRE8

/*! \brief    Directive used to specify the alignment of 4.
 */
# define OS_HAL_ASM_ALIGN4

Os_Hal_Asm_LoadRegister32 .macro Register, Value
  movw Register, Value
  movt Register, Value
  .endm

/*! \brief    Directive used for no operation (NOP).
 */
# define OS_HAL_ASM_DUMMY_NOP  NOP

#endif /* OS_HAL_COMPILERTIINT_INC */

/*!
 * \}
 */
 /***********************************************************************************************************************
 *  END OF FILE: Os_Hal_CompilerTiInt.inc
 **********************************************************************************************************************/

