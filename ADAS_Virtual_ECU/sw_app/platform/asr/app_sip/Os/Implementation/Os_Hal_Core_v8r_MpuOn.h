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

#ifndef  OS_HAL_CORE_V8R_MPUON_H
# define OS_HAL_CORE_V8R_MPUON_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

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

/***********************************************************************************************************************
 *  Os_Hal_Core_InitStackProtectionRegions()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
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
  /* #10 Select the Stack Protection MPU Region 0 for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_PROTECTION_REGION_0_NUMBER);

  /* #20 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  /* #30 Write base address to the MPU region. */
  Os_Hal_MpSetRegionBaseAddressAndAccessRights((uint32)(Config->StackProtectionStartLabel)                              /* PRQA S 0326 */ /* MD_Os_Rule11.6_0326 */
                                                    | OS_HAL_MP_ACCESS_EXECUTE_FORBIDDEN | OS_HAL_MP_ACCESS_S_R_U_R);

  /* #40 Select the Stack Protection MPU Region 1 for reprogramming. */
  Os_Hal_MpSetRegionNumber(OS_HAL_MP_STACK_PROTECTION_REGION_1_NUMBER);

  /* #50 Disable the MPU region for the duration of reprogramming. */
  Os_Hal_MpSetRegionEndAddressAndEnable(0);

  /* #60 Write end address to MPU region. */
  Os_Hal_MpSetRegionEndAddressAndEnable((uint32)(Config->StackProtectionLimitLabel));                                   /* PRQA S 0326 */ /* MD_Os_Rule11.6_0326 */

  /* #70 Instruction sync barrier. */
  Os_Hal_InstructionSyncBarrier();
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CORE_V8R_MPUON_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_v8r_MpuOn.h
 **********************************************************************************************************************/

