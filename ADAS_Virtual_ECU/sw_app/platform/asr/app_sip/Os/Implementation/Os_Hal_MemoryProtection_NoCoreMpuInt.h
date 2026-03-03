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
 * \ingroup    Os_Hal
 * \defgroup   Os_Hal_MemoryProtection  HAL Memory Protection
 * \{
 *
 * \brief      Internal functions and data types related to memory protection.
 * \file       Os_Hal_MemoryProtection_NoCoreMpuInt.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_MEMORYPROTECTION_NO_COREMPU_INT_H
# define OS_HAL_MEMORYPROTECTION_NO_COREMPU_INT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Base address of the temporary startup region: not used */
#  define OS_HAL_MP_STARTUP_REGION_BASE              (0uL)
/*! End address of the temporary startup region: not used */
#  define OS_HAL_MP_STARTUP_REGION_END               (0uL)
/*! Size of the temporary startup region: not used */
#  define OS_HAL_MP_STARTUP_REGION_SIZE              (0uL)


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Description of a single region: not used */
struct Os_Hal_MpRegionType_Tag
{
  uint32 DummyRegion;
};


# endif /* OS_HAL_MEMORYPROTECTION_NO_COREMPU_INT_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_NoCoreMpuInt.h
 **********************************************************************************************************************/
