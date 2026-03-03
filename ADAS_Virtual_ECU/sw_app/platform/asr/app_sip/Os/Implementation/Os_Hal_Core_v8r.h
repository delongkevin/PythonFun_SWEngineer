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
 *  \addtogroup Os_Hal_Core
 *  \{
 *
 *  \file
 *  \brief      ARMv8 related primitives.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_CORE_V8R_H
# define OS_HAL_CORE_V8R_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Common.h"
# include "Os_Hal_MemoryProtection_PMSAv8.h"

/* Os HAL dependencies */
# if defined(OS_CFG_DERIVATIVEGROUP_RCARV4H)
#  include "Os_Hal_Core_MultiProcessorGroups.h"
# else
#  include "Os_Hal_Core_OneProcessorGroup.h"
# endif

# if (OS_CFG_MEMORY_PROTECTION == STD_ON)
#  include "Os_Hal_Core_v8r_MpuOn.h"
# else
#  include "Os_Hal_Core_v8r_MpuOff.h"
# endif

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Exception vector table layout for ARMv8-R Architectures. */
typedef struct
{
  uint32 Reserved0;                   /*!< Offset: 0x00   Reset Exception. */
  uint32 UndefinedInstruction;        /*!< Offset: 0x04   Undefined Instruction Exception. */
  uint32 SupervisorCall;              /*!< Offset: 0x08   Software Interrupt Exception. */
  uint32 AbortPrefetch;               /*!< Offset: 0x0C   Abort (prefetch) Exception. */
  uint32 AbortData;                   /*!< Offset: 0x10   Abort (data) Exception. */
  uint32 Hyp_Trap;                    /*!< Offset: 0x14   Reserved. */
  uint32 IRQ;                         /*!< Offset: 0x18   IRQ Exception. */
  uint32 FIQ;                         /*!< Offset: 0x1C   FIQ Exception. */
} Os_Hal_CoreV8ExceptionVectorTableType;


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
  /* Set the Vector Base Offset register */
  Os_Hal_Set_VBAR((uint32)(Config->ExceptionTable));                                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
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
  /* #10 Return not readable in user mode. */
  return 0u;                                                                                                           /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CORE_V8R_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_v8r.h
 **********************************************************************************************************************/

