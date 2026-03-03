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
 *  01.00.00   2017-02-24  visci   -                Initial version
 *  01.01.00   2018-06-15  visci   ESCAN00099699    No changes
 *  01.02.00   2018-09-24  visrr   ESCAN00100837    No changes
 *  01.03.00   2018-12-07  visshs  ESCAN00101559    No changes
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
 *  02.00.00   2020-03-25  vistbe  FBL-1510         Initial version based on template revision 1.04.00
 *                                 ESCAN00105933    No changes
 *                                 ESCAN00105934    No changes
 *                                 ESCAN00105730    No changes
 *                                 ESCAN00105864    No changes
 *  02.00.01   2020-05-26  visjdn  ESCAN00105865    No changes
 *  02.01.00   2020-06-16  vistbe  FBL-1919         No changes
 *  02.02.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *                                 ESCAN00106775    No changes
 *  02.02.01   2020-11-02  visrcn  ESCAN00105639    No changes
 *  02.03.00   2020-12-17  vistbe  FBL-1352         No changes
 *  02.04.00   2021-04-14  vistmo  FBL-2961         No changes
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

#ifndef FBLLIB_NVPATTERN_OEM_H
#define FBLLIB_NVPATTERN_OEM_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Check if multiple validation feature was explicitly enabled externally */
# if !defined( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
/* Disables NvPatterns which can be validated multiple times after erasing a logical block */
#  define FBL_NVPATTERN_DISABLE_MULTIPLE_VALIDATION
# endif /* !FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */

/* Check if block properties feature was explicitly enabled externally */
# if !defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
/* Disables storing arbitrary data at the end of logical blocks */
#  define FBL_NVPATTERN_DISABLE_BLOCK_PROPERTIES
# endif /* !FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

/* Disable user patterns if they are not explicitly defined */
#if !defined( FBL_NVPATTERN_USER_PATTERN_ID )
# define FBL_NVPATTERN_USER_PATTERN_ID
#endif /* FBL_NVPATTERN_USER_PATTERN_ID */
#if !defined( FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY )
# define FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY
#endif /* FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY */
#if !defined( FBL_NVPATTERN_USER_PROPERTY_ID )
# define FBL_NVPATTERN_USER_PROPERTY_ID
#endif /* FBL_NVPATTERN_USER_PROPERTY_ID */
#if !defined( FBL_NVPATTERN_USER_PROPERTY_ENTRY )
# define FBL_NVPATTERN_USER_PROPERTY_ENTRY
#endif /* FBL_NVPATTERN_USER_PROPERTY_ENTRY */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/*
 *   This module is used to store NvPatterns and block properties at the end of logical blocks.
 *   Block properties are used to store arbitrary data of the length defined in fblNvPatternElementLength to memory.
 *   Block properties can be written once after erasure of the logical block.
 *   NvPatterns are used to store a boolean value (valid/invalid). They can be set to valid
 *   several times if the respective value in fblNvPatternMultiplicity is set to > 1.
 *
 *   MEMORY LAYOUT:
 *
 *   |--------------------------------| <-- UPPER END of pattern/property area (usually end of logical block)
 *   | kFblNvPatternId_First          | First NvPattern
 *   | ...                            |
 *   | kFblNvPatternId_Final          |
 *   | kFblNvPatternId_Separator      | <-- SEPARATOR between patterns and block properties (do NOT delete this entry)
 *   | kFblNvProperty_First           | First block property
 *   | ...                            |
 *   | kFblNvProperty_Final           |
 *   | kFblNvPatternId_Last           | <-- LOWER END of pattern/property area (do NOT delete this entry)
 *   | <Data of logical block>        |
 *
 *   Note: the actual pattern/block property size is determined by the page size.
 *         All data elements are aligned to multiples of the page size of the respective device!
 */

/* PRQA S 0724 TAG_FblNvPatternOem_0724 */ /* MD_FblNvPatternOem_0724_EnumValNotUnique */
/* Identifiers for patterns and block properties */
typedef enum
{
    kFblNvPatternId_Invalid = 0u /* do NOT change this entry */

   /* PartitionValidity (OTA) and ApplValidity (BM) uses the same value */
   ,kFblNvPatternId_PartitionValidity
   ,kFblNvPatternId_ApplValidity = kFblNvPatternId_PartitionValidity

   /* ModuleValidity (OTA) and BlockValidity (BM) uses the same value */
   ,kFblNvPatternId_ModuleValidity
   ,kFblNvPatternId_BlockValidity = kFblNvPatternId_ModuleValidity
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   , kFblNvPatternId_ErasedState
#endif

   FBL_NVPATTERN_USER_PATTERN_ID

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
   ,kFblNvPatternId_Separator /* do NOT delete this entry */
   FBL_NVPATTERN_USER_PROPERTY_ID
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */
   ,kFblNvPatternId_Last /* do NOT delete this entry */
} tFblNvPatternId;
/* PRQA L:TAG_FblNvPatternOem_0724 */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
typedef struct
{
   IO_SizeType length;
   tFblNvPatternId dependentPattern;
} tFblBlockProperty;
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined ( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
/* PRQA S 3684 1 */ /* MD_FblNvPatternOem_3684 */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 fblNvPatternMultiplicity[];
#endif /* FBL_NVPATTERN_ENABLE_MULTIPATTERNS */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
/* PRQA S 3684 1 */ /* MD_FblNvPatternOem_3684 */
V_MEMROM0 extern V_MEMROM1 tFblBlockProperty V_MEMROM2 fblNvBlockProperties[];
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBLLIB_NVPATTERN_OEM_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN_OEM.H
 **********************************************************************************************************************/
