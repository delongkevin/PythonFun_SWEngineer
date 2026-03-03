/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Implementation of pattern/mask based non-volatile information storage
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.04.00   2019-01-25  viskjs  ESCAN00101824    Added patterns that can be validated multiple times
 *                                 ESCAN00101823    Added feature to store arbitrary values at end of logical block
 *  01.04.01   2019-03-26  viskjs  ESCAN00102200    No changes
 *                                 ESCAN00102204    No changes
 *                                 ESCAN00102646    No changes
 *  01.04.02   2019-07-22  vistbe  ESCAN00103605    No changes
 *  01.04.03   2020-05-07  visjdn  ESCAN00106002    No changes
 *  01.04.04   2021-03-03  visrie  ESCAN00108616    No changes
 *                                 ESCAN00108753    No changes
 *                                 FBL-3129         Added/adapted MemMap sections
 *                                                  Update to MISRA 2012
 *  01.04.05   2021-03-16  visrie  ESCAN00108859    No changes
 *  01.05.00   2021-06-16  visrie  FBL-3641         Support OTA use case and user extension
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.02.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *                                 ESCAN00106775    No changes
 *  02.02.01   2020-11-02  visrcn  ESCAN00105639    No changes
 *  02.03.00   2020-12-17  vistbe  FBL-1352         No changes
 *  02.04.00   2021-04-14  vistmo  FBL-2961         Added/adapted MemMap sections
 *  02.04.01   2021-08-18  vistbe  ESCAN00109813    No changes
 *  02.05.00   2021-08-24  vishor  FBL-3800         Updated to latest template revision
 *  02.05.01   2021-11-09  visrie  ESCAN00110248    No changes
 *  02.06.00   2022-01-20  vistmo  FBL-4156         No changes
 *  02.06.01   2022-02-16  visrie  ESCAN00110576    No changes
 *                                 ESCAN00110609    No changes
 *  02.07.00   2022-06-14  visrie  ESCAN00111989    No changes
 *  02.07.01   2022-07-27  vismix  ESCAN00109293    No changes
 *  02.07.02   2022-10-14  visjns  ESCAN00112112    No changes
 *  02.07.03   2022-11-16  vismix  ESCAN00112841    No changes
 *                                 ESCAN00112884    No changes
 *  02.07.04   2022-11-21  vismix  ESCAN00112934    No changes
 *  02.08.00   2022-12-02  visjdn  FBL-6117         No changes
 *                                 ESCAN00110368    No changes
 *                                 ESCAN00112786    No changes
 *                                 ESCAN00113224    No changes
 **********************************************************************************************************************/

#define FBL_NVPATTERN_OEM_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "fbl_nvpattern_oem.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined ( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 fblNvPatternMultiplicity[] =
{
   1u /**< kFblNvPatternId_PartitionValidity can be validated/invalidated once after erasure */
  ,1u /**< kFblNvPatternId_ModuleValidity can be validated/invalidated once after erasure */
# if defined( FBL_ENABLE_OTA )
  ,FBL_NVPATTERN_ACTIVATION_PENDING_NUM  /**< kFblNvPatternId_ActivationPending can be validated/invalidated a
                                              configurable amount of times */
# endif /* FBL_ENABLE_OTA */
   FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY
};
#endif /* FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
V_MEMROM0 V_MEMROM1 tFblBlockProperty V_MEMROM2 fblNvBlockProperties[] =
{
# if defined( FBL_ENABLE_OTA )
   {
      FBL_NVPATTERN_REVISION_SIZE,      /**< Size of kFblNvProperty_PartitionRev in bytes */
      kFblNvPatternId_PartitionValidity /**< Property only valid if partition is valid. The partition validity is always
                                             set in the same module as the partition revision. */
   },
   {
      FBL_NVPATTERN_REVISION_SIZE,   /**< Size of kFblNvProperty_ModuleRev in bytes */
      kFblNvPatternId_ModuleValidity /**< Property only valid if module is valid. */
   }
# endif /* FBL_ENABLE_OTA */
   FBL_NVPATTERN_USER_PROPERTY_ENTRY
};
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblNvPatternOem_0724_EnumValNotUnique:
     Reason: The same numerical value is associated to different enum entries, to allows each entry value to be used in
      the appropriate context, keeping a better code structure and understanding.
     Risk: Enum values can potentially be assigned with the same value unintentionally.
     Prevention: Correct design.

   MD_FblNvPatternOem_3684:
     Reason: The size of the array is determined only at compile time.
     Risk: The code is less clear and require more analysis for a deep understanding.
     Prevention: No prevention defined.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN_OEM.C
 **********************************************************************************************************************/
