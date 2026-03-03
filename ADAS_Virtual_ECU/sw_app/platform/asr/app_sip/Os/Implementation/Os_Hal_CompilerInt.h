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
 *  \ingroup    Os_Hal
 *  \addtogroup Os_Hal_Compiler  HAL Compiler
 *  \brief      Abstraction of compiler specific keywords to allow the compiler to generate more efficient code.
 *  \details
 *  The kernel should be able to give the compiler meta information to generate more efficient code.
 *  It also needs to tell the linker where to put data and code to implement Memory Protection.
 *  In multi core systems there may be the need for data/code duplication.
 *  The keywords to provide this information are not part of ANSI-C and are highly compiler dependent.
 *
 *  AUTOSAR already defines concepts to abstract compiler specifics:
 *  - [AUTOSAR Compiler Abstraction](http:\\www.autosar.org/fileadmin/files/releases/4-2/software-architecture/implementation-integration/standard/AUTOSAR_SWS_CompilerAbstraction.pdf)
 *  - [AUTOSAR Memory Mapping](http:\\www.autosar.org/fileadmin/files/releases/3-2/software-architecture/implementation-integration/standard/AUTOSAR_SWS_MemoryMapping.pdf)
 *
 *  They are used in MICROSAR OS. This module defines additional compiler abstraction keywords for MICROSAR OS.
 *  They are relevant to provide OS functionality or improve efficiency.
 *
 *  \{
 *
 *  \file
 *  \brief      Additional services defined here are available to the user.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_COMPILERINT_H
# define OS_HAL_COMPILERINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* Os kernel module dependencies */
# include "Os_Cfg.h"
# include "Os_CommonInt.h"

# include "Os_Hal_Derivative.h"

# if defined(OS_STATIC_CODE_ANALYSIS)                                                                                   /* COV_OS_STATICCODEANALYSIS */
#  include "Os_Hal_StaticCodeAnalysis.h"
# else
#  if defined (OS_CFG_COMPILER_GNU)                                                                                     /* COV_OS_DERIVATIVEBETAMODULE */
#   include <Os_Hal_Compiler_HighTecInt.h>
#  elif defined (OS_CFG_COMPILER_IAR)                                                                                   /* COV_OS_DERIVATIVEBETAMODULE */
#   include "Os_Hal_Compiler_IarInt.h"
#  elif defined (OS_CFG_COMPILER_TEXASINSTRUMENTS)                                                                      /* COV_OS_DERIVATIVEBETAMODULE */
#   include "Os_Hal_Compiler_TiInt.h"
#  elif defined (OS_CFG_COMPILER_ARM)                                                                                   /* COV_OS_DERIVATIVEBETAMODULE */
#   include <Os_Hal_Compiler_ArmInt.h>
#  elif defined (OS_CFG_COMPILER_ARM6)                                                                                  /* COV_OS_DERIVATIVEBETAMODULE */
#   include <Os_Hal_Compiler_Arm6Int.h>
#  elif defined (OS_CFG_COMPILER_LLVMDIAB)                                                                              /* COV_OS_DERIVATIVEBETAMODULE */
#   include <Os_Hal_Compiler_LlvmDiabInt.h>
#  elif defined (OS_CFG_COMPILER_LLVMHIGHTEC)                                                                           /* COV_OS_DERIVATIVEBETAMODULE */
#   include <Os_Hal_Compiler_LlvmHighTecInt.h>
#  elif defined (OS_CFG_COMPILER_GREENHILLS)
#   include "Os_Hal_Compiler_GreenhillsInt.h"
#  elif defined (OS_CFG_COMPILER_LINARO)
#   include <Os_Hal_Compiler_GccInt.h>
#  elif defined (OS_CFG_COMPILER_GCCNXP)
#   include "Os_Hal_Compiler_GccNxpInt.h"
#  elif defined (OS_CFG_COMPILER_LLVMTEXASINSTRUMENTS)
#   include <Os_Hal_Compiler_LlvmTIInt.h>
#  else
#   error "Undefined or unsupported compiler"
#  endif
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief      Tells the compiler that the conditional statement is likely to be true.
 *  \details    The compiler, in turn, can then perform block reordering, and other optimization to
 *              improve the performance of conditional branches.
 *  \param[in]  CONDITION   The condition which is likely to be true
 */
# define OS_LIKELY(CONDITION)       (CONDITION)

/*! \brief      Tells the compiler that the conditional statement is likely to be false.
 *  \details    The compiler, in turn, can then perform block reordering, and other optimization to
 *              improve the performance of conditional branches.
 *  \param[in]  CONDITION   The condition which is likely to be false
 */
# define OS_UNLIKELY(CONDITION)     (CONDITION)


# if !defined (OS_ALWAYS_INLINE)
#  error "OS_ALWAYS_INLINE is undefined!"
# endif


# if !defined (OS_NORETURN)
#  error "OS_NORETURN is undefined!"
# endif


# if !defined (OS_FLATTEN)
#  error "OS_FLATTEN undefined"
# endif


# if !defined (OS_NOSIDEEFFECTS)
#  error "OS_NOSIDEEFFECTS undefined"
# endif


# if !defined (OS_PURE)
#  error "OS_PURE undefined"
# endif


# if !defined (OS_NAKED)
#  error "OS_NAKED undefined"
# endif


# if !defined (OS_LIKELY)
#  error "OS_LIKELY(Condition) undefined"
# endif


# if !defined (OS_UNLIKELY)
#  error "OS_UNLIKELY(Condition) undefined"
# endif


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_COMPILERINT_H */

/* module specific MISRA deviations:

  MD_Os_Hal_Rule8.13_3673:
      Reason:     The parameter may be modified in other HAL implementations, thus it is necessary to keep it
                  as "pointer to non-const". 
                  Or, the object addressed by the pointer parameter is modified by assembly code (not interpreted 
                  by the tool) and so the pointer shall be of type 'pointer to var'.                  
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.1_0305:
      Reason:     This statement converts a function pointer to an integral address or vice versa. This is unavoidable to
                  use the function pointer address.
      Risk:       The risk for incompatibility is low here as the code is used on a specific hardware platform only with
                  known sizes of pointer types and integral types.
      Prevention: The code is tested with all compilers it shall be compiled with.

  MD_Os_Hal_Rule11.2_0324:
      Reason:     This statement converts an incomplete pointer to an integral type or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       none
      Prevention: none

  MD_Os_Hal_Rule11.4_0303:
      Reason:     This statement converts an integral address to a pointer or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.4_0306:
      Reason:     This statement converts an integral address to a pointer or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       The risk for incompatibility is low here as the code is used on a specific hardware platform only with
                  known sizes of pointer types and integral types.
      Prevention: The code is tested with all compilers it shall be compiled with.

  MD_Os_Hal_Dir1.1_0314:
      Reason:     The object pointer is safely converted to a void pointer.
      Risk:       None, because there are no violations of alignment requirements.
      Prevention: None.

  MD_Os_Hal_Rule11.5_0316:
      Reason:     This statement converts a pointer to void into a pointer to an object type.
      Risk:       Allignment rules for the object pointer might be stricter than for void pointer.
      Prevention: The type of the pointer to cast to is stored in a separat variable, so the correct alignement rules will
                  always be followed.

  MD_Os_Hal_Rule11.8_0311:
      Reason:     This statement performs a conversion which results in the loss of a const qualification.
      Risk:       The compiler does not prevent to generate code to change the content.
      Prevention: The constants are linked into ROM so that modification of the content will not happen.

  MD_Os_Hal_Rule2.1_2880_NonReturning:
      Reason:     The code is never reached, as a non-returning function is executed before the code.
                  In terms of defensive programming, the code is required anyway.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule10.5_4332:
      Reason:     An expression of 'essentially signed' type is being cast to enum type, to initialze a local variable
                  with a value the enum  data type.
      Risk:       The essentially signed type value may have no representation in the enum type.
      Prevention: These enum types are designed to be used to address array elements and therefore, to have all values
                  from 0 to OS_...ID_COUNT.

  MD_Os_Hal_Rule10.5_4342_E3_CoreIdToINCType:
      Reason:     The return type of Os_Hal_CoreGetId is being cast to the enum type Os_Hal_IntControllerType.
      Risk:       None.
      Prevention: The returned core id of Os_Hal_CoreGetId on E3 platform is within the range from 0 to 5. Thus it is
                  always within the range of the enum type. This is ensured via code review.

  MD_Os_Hal_Rule12.2_2791_E3_LevelRange:
      Reason:     The right hand operand of shift operator uses subtraction.
      Risk:       None.
      Prevention: The Level range is from 0 to 15, thus the right hand operand of shift operator will never be negative
                  or too large. This is ensured via code review.
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_CompilerInt.h
 **********************************************************************************************************************/

