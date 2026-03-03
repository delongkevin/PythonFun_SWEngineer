/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain wi:wth Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Hal_Core
 * \{
 *
 *  \file       Os_Hal_Core_Xavier.h
 *  \brief      Core related primitives specific to NVIDIA Xavier derivative family, SCE cluster.
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
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_CORE_XAVIER_H
# define OS_HAL_CORE_XAVIER_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Core_OneProcessorGroup.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! Xavier SCE EVP : Exception vector pointer base address. */
# define OS_HAL_SCE_ATCM_EVP_BASE            (0x0B000000uL)

/*! Xavier SCE EVP: Undefined exception handler. */
# define OS_HAL_SCE_ATCM_EVP_UNDEF      (*(volatile uint32*) (OS_HAL_SCE_ATCM_EVP_BASE + 0x24uL))

/*! Xavier SCE EVP: SVC exception handler. */
# define OS_HAL_SCE_ATCM_EVP_SVC        (*(volatile uint32*) (OS_HAL_SCE_ATCM_EVP_BASE + 0x28uL))

/*! Xavier SCE EVP PABORT: Prefetch abort exception handler. */
# define OS_HAL_SCE_ATCM_EVP_PABORT     (*(volatile uint32*) (OS_HAL_SCE_ATCM_EVP_BASE + 0x2CuL))

/*! Xavier SCE EVP: Data abort exception handler. */
# define OS_HAL_SCE_ATCM_EVP_DABORT     (*(volatile uint32*) (OS_HAL_SCE_ATCM_EVP_BASE + 0x30uL))

/*! Xavier SCE FIQ: Fiq handler. */
# define OS_HAL_SCE_ATCM_EVP_FIQ        (*(volatile uint32*) (OS_HAL_SCE_ATCM_EVP_BASE + 0x3CuL))

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_Core_InitExceptions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Core_InitExceptions,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
))
{
  /* #10 Set exception vectors. */
  OS_HAL_SCE_ATCM_EVP_UNDEF  = (uint32)Config->ExceptionTable[1];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
  OS_HAL_SCE_ATCM_EVP_SVC    = (uint32)Config->ExceptionTable[2];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
  OS_HAL_SCE_ATCM_EVP_PABORT = (uint32)Config->ExceptionTable[3];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
  OS_HAL_SCE_ATCM_EVP_DABORT = (uint32)Config->ExceptionTable[4];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
  OS_HAL_SCE_ATCM_EVP_FIQ    = (uint32)Config->ExceptionTable[7];                                                       /* PRQA S 0303, 0305 */ /* MD_Os_Hal_Rule11.4_0303, MD_Os_Hal_Rule11.1_0305 */
}


/***********************************************************************************************************************
 *  Os_Hal_Core_InitStackProtectionRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Core_InitStackProtectionRegions,
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
))
{
  /* #10 Nothing to do here. */
  OS_IGNORE_UNREF_PARAM(Config);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreIsThreadPointerUserReadable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreIsThreadPointerUserReadable,
(
  void
))
{
  /* #10 Return readable in user mode. */
  return (Os_StdReturnType)(1u);
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_HAL_CORE_XAVIER_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_Xavier.h
 **********************************************************************************************************************/

