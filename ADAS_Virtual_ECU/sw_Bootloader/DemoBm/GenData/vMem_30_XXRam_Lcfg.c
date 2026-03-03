/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vMem_30_XXRam
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_XXRam_Lcfg.c
 *   Generation Time: 2024-11-25 13:00:27
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define VMEM_30_XXRAM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_XXRam_Cfg.h"




/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMem_30_XXRam_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_XXRam_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element           Description
  EraseBurstSize    Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize        Size of this sector in bytes.
  StartAddress      Physical start address of the first sector.
  PageSize          Size of one page of this sector in bytes.
  WriteBurstSize    Burst size for write jobs, if configured. Otherwise page size
  NrOfSectors       Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  RamAlignment      In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
*/ 
#define VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_XXRam_MemSectorType, VMEM_30_XXRAM_CONST) vMem_30_XXRam_MemSector[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseBurstSize  SectorSize  StartAddress  PageSize  WriteBurstSize  NrOfSectors  RamAlignment        Referable Keys */
  { /*     0 */      16384000u,  16384000u,  0x97000000u,    1000u,          1000u,          1u,           1u }   /* [/ActiveEcuC/vMem_30_XXRam/vMem_XXRam_vMemInstance] */
};
#define VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_XXRam_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_XXRam_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element              Description
  Id                   Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx      the end index of the 1:n relation pointing to vMem_30_XXRam_MemSector
  MemSectorLength      the number of relations pointing to vMem_30_XXRam_MemSector
  MemSectorStartIdx    the start index of the 1:n relation pointing to vMem_30_XXRam_MemSector
*/ 
#define VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_XXRam_vMemInstanceType, VMEM_30_XXRAM_CONST) vMem_30_XXRam_vMemInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  MemSectorEndIdx  MemSectorLength  MemSectorStartIdx        Referable Keys */
  { /*     0 */ 0u,              1u,              1u,                0u }   /* [/ActiveEcuC/vMem_30_XXRam/vMem_XXRam_vMemInstance] */
};
#define VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


