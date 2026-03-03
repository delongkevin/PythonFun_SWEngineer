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
 *  \brief      Compiler abstraction of the Llvm Texas Instruments compiler
 *  \details
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_COMPILER_LLVMTEXASINSTRUMENTS_SOURCE

# ifdef CDK_CHECK_MISRA                                                                                                 /* COV_OS_STATICCODEANALYSIS */
#  ifndef OS_STATIC_CODE_ANALYSIS                                                                                       /* COV_OS_STATICCODEANALYSIS */
#    define OS_STATIC_CODE_ANALYSIS
#  endif
# endif


#ifndef OS_STATIC_CODE_ANALYSIS                                                                                         /* COV_OS_STATICCODEANALYSIS */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os hal module dependencies */
# include "Os_Hal_Compiler.h"

# if defined (OS_CFG_COMPILER_LLVMTEXASINSTRUMENTS)                                                                      /* COV_OS_DERIVATIVEBETAMODULE */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_1_0_0()
 **********************************************************************************************************************/
/*! \brief        Function like MACRO used to define multiple variants of the Os_Hal_ReadFromCoprocessor function.
 *  \details      The variants are used to have a single implementation that can be reviewed instead of having multiple
 *                implementations using different registers.
 *                Multiple implementations are needed as the  __MRC intrinsic is not available ,
 *                and the mrc assembly instruction needs p and c prefixed to the coprocessor and registers respectively.
 *                Which makes it very difficult to implementation these functions without string concactenation using
 *                preprocessor MACROS.
 *  \param[in]    1     Coprocessor register used as first postfix.
 *  \param[in]    0     Additional Coprocessor register used as second postfix.
 *  \param[in]    0     Coprocessor OpCode2 used as third postfix to form the variant name.
 **********************************************************************************************************************/
uint32 Os_Hal_RFC_variant_1_0_0(void)
{
  uint32 ret = 0;
  __asm volatile (" MRC p15, 0, %0, c1, c0, 0"
                    : "=r" (ret)
                    :
                    : );
  return ret;
}

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_0_0_4()
 **********************************************************************************************************************/
/*! \brief        Function like MACRO used to define multiple variants of the Os_Hal_ReadFromCoprocessor function.
 *  \details      The variants are used to have a single implementation that can be reviewed instead of having multiple
 *                implementations using different registers.
 *                Multiple implementations are needed as the  __MRC intrinsic is not available,
 *                and the mrc assembly instruction needs p and c prefixed to the coprocessor and registers respectively.
 *                Which makes it very difficult to implementation these functions without string concactenation using
 *                preprocessor MACROS.
 *  \param[in]    0     Coprocessor register used as first postfix.
 *  \param[in]    4     Additional Coprocessor register used as second postfix.
 *  \param[in]    4     Coprocessor OpCode2 used as third postfix to form the variant name.
 **********************************************************************************************************************/
uint32 Os_Hal_RFC_variant_0_0_4(void)
{
  uint32 ret = 0;
  __asm volatile (" MRC p15, 0, %0, c0, c0, 4"
                    : "=r" (ret)
                    :
                    : );
  return ret;
}

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_6_1_0()
 **********************************************************************************************************************/
/*! \brief        Function like MACRO used to define multiple variants of the Os_Hal_ReadFromCoprocessor function.
 *  \details      The variants are used to have a single implementation that can be reviewed instead of having multiple
 *                implementations using different registers.
 *                Multiple implementations are needed as the  __MRC intrinsic is not available,
 *                and the mrc assembly instruction needs p and c prefixed to the coprocessor and registers respectively.
 *                Which makes it very difficult to implementation these functions without string concactenation using
 *                preprocessor MACROS.
 *  \param[in]    6     Coprocessor register used as first postfix.
 *  \param[in]    1     Additional Coprocessor register used as second postfix.
 *  \param[in]    0     Coprocessor OpCode2 used as third postfix to form the variant name.
 **********************************************************************************************************************/
uint32 Os_Hal_RFC_variant_6_1_0(void)
{
  uint32 ret = 0;
  __asm volatile (" MRC p15, 0, %0, c6, c1, 0"
                    : "=r" (ret)
                    :
                    : );
  return ret;
}

/***********************************************************************************************************************
 *  Os_Hal_RFC_variant_6_1_2()
 **********************************************************************************************************************/
/*! \brief        Function like MACRO used to define multiple variants of the Os_Hal_ReadFromCoprocessor function.
 *  \details      The variants are used to have a single implementation that can be reviewed instead of having multiple
 *                implementations using different registers.
 *                Multiple implementations are needed as the  __MRC intrinsic is not available,
 *                and the mrc assembly instruction needs p and c prefixed to the coprocessor and registers respectively.
 *                Which makes it very difficult to implementation these functions without string concactenation using
 *                preprocessor MACROS.
 *  \param[in]    6     Coprocessor register used as first postfix.
 *  \param[in]    1     Additional Coprocessor register used as second postfix.
 *  \param[in]    2     Coprocessor OpCode2 used as third postfix to form the variant name.
 **********************************************************************************************************************/
uint32 Os_Hal_RFC_variant_6_1_2(void)
{
  uint32 ret = 0;
  __asm volatile (" MRC p15, 0, %0, c6, c1, 2"
                    : "=r" (ret)
                    :
                    : );
  return ret;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# endif /* if defined (OS_CFG_COMPILER_LLVMTEXASINSTRUMENTS) */

#endif /* #ifndef (CDK_CHECK_MISRA) */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_LlvmTI.c
 *********************************************************************************************************************/
