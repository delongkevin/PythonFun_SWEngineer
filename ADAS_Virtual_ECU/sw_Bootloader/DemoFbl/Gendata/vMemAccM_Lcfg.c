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
 *            Module: vMemAccM
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMemAccM_Lcfg.c
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


/* macro identifying this compilation unit */
#define VMEMACCM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

extern CONST(vMemAccM_vMemApiType, VMEMACCM_CONST) vMem_30_vXSpi_Nand_FunctionPointerTable; 


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
  vMemAccM_AddressArea
**********************************************************************************************************************/
/** 
  \var    vMemAccM_AddressArea
  \details
  Element                       Description
  ReadLength                    Maximal length that can be requested of underlying MemDrv for read requests
  AddressAreaVariantEndIdx      the end index of the 1:n relation pointing to vMemAccM_AddressAreaVariant
  AddressAreaVariantLength      the number of relations pointing to vMemAccM_AddressAreaVariant
  AddressAreaVariantStartIdx    the start index of the 1:n relation pointing to vMemAccM_AddressAreaVariant
  Priority                      Priority of AddressArea - determines which job is processed first
  JobEndNotification            Notification that will be called upon asynchronous job completion.
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_AddressAreaType, VMEMACCM_CONST) vMemAccM_AddressArea[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ReadLength  AddressAreaVariantEndIdx  AddressAreaVariantLength  AddressAreaVariantStartIdx  Priority  JobEndNotification        Referable Keys */
  { /*     0 */      4096u,                       1u,                       1u,                         0u,       0u, NULL_PTR           }   /* [/ActiveEcuC/vMemAccM/vMemAccMAddressAreaConfiguration_Active] */
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_AddressAreaVariant
**********************************************************************************************************************/
/** 
  \var    vMemAccM_AddressAreaVariant
  \details
  Element                   Description
  Id                        Variant identifier.
  SubAddressAreaEndIdx      the end index of the 1:n relation pointing to vMemAccM_SubAddressArea
  SubAddressAreaLength      the number of relations pointing to vMemAccM_SubAddressArea
  SubAddressAreaStartIdx    the start index of the 1:n relation pointing to vMemAccM_SubAddressArea
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_AddressAreaVariantType, VMEMACCM_CONST) vMemAccM_AddressAreaVariant[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  SubAddressAreaEndIdx  SubAddressAreaLength  SubAddressAreaStartIdx        Referable Keys */
  { /*     0 */ 0u,                   2u,                   2u,                     0u }   /* [/ActiveEcuC/vMemAccM/vMemAccMAddressAreaConfiguration_Active] */
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_SubAddressArea
**********************************************************************************************************************/
/** 
  \var    vMemAccM_SubAddressArea
  \details
  Element                   Description
  PhysicalStartAddress      Physical start address of SubAddressArea
  SectorSize                Size of a sector in bytes
  VirtualEndAddress         Virtual end address of SubAddressArea
  VirtualStartAddress       Virtual start address of SubAddressArea
  NumberOfSectors           Number of sectors of SubAddressArea
  PageSize                  Size of a page in bytes
  UsePageBurst              vMem page/ write burst shall be used or not.
  UseSectorBurst            vMem sector/ erase burst shall be used or not.
  NumberOfEraseRetries      Number of erase retries in case of a failed vMem job
  NumberOfWriteRetries      Number of write retries in case of a failed vMem job
  PageBurstRamAlignment     Alignment for page burst ram - Zero if not configured
  PageBurstSize             Size of page burst in bytes - Zero if not configured
  SectorBurstSize           Size of sector burst in bytes - Zero if not configured
  SynchronizationGroupId    Id of the synchronization group. All SubAddressAreas within one group must be synchronized
  vMemTableIndex            Index pointing to the entry within the configured vMem table.
  HardwareId                Numeric identifier of vMem hardware, used in hardware specific requests
  vMemInstanceId            Numeric identifier of vMem instance, used as parameter in vMem API
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_SubAddressAreaType, VMEMACCM_CONST) vMemAccM_SubAddressArea[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PhysicalStartAddress  SectorSize  VirtualEndAddress  VirtualStartAddress  NumberOfSectors  PageSize  UsePageBurst  UseSectorBurst  NumberOfEraseRetries  NumberOfWriteRetries  PageBurstRamAlignment  PageBurstSize  SectorBurstSize  SynchronizationGroupId  vMemTableIndex  HardwareId                                         vMemInstanceId        Referable Keys */
  { /*     0 */                   0u,    262144u,        131596287u,                  0u,            502u,    4096u,        FALSE,          FALSE,                   0u,                   1u,                    0u,            0u,              0u,                     0u, 0u            , VMEMACCM_VMEM_30_VXSPI_NAND_VMEMINSTANCE_EXTFLASH, 0u             },  /* [/ActiveEcuC/vMemAccM/vMemAccMAddressAreaConfiguration_Active/NoVariant] */
  { /*     1 */           131596288u,    262144u,        134217727u,          131596288u,             10u,    4096u,        FALSE,          FALSE,                   0u,                   0u,                    0u,            0u,              0u,                     0u, 0u            , VMEMACCM_VMEM_30_VXSPI_NAND_VMEMINSTANCE_EXTFLASH, 0u             }   /* [/ActiveEcuC/vMemAccM/vMemAccMAddressAreaConfiguration_Active/NoVariant] */
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_vMemPointerTable
**********************************************************************************************************************/
/** 
  \var    vMemAccM_vMemPointerTable
  \brief  Table containing all vMem function table pointers.
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_ConstvMemApiPtrType, VMEMACCM_CONST) vMemAccM_vMemPointerTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     vMemPointerTable                          */
  /*     0 */ &vMem_30_vXSpi_Nand_FunctionPointerTable 
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: PARTITION LOCAL DATA
**********************************************************************************************************************/
/* Master variables, visible only for multi partition master, local RAM. */
#define VMEMACCM_START_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

vMemAccM_PartitionPublishRequestType vMemAccM_PublishReq_vMemAccMMasterPartitionConfiguration_Id0 = 
    {
      VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST /*  Published job priority  */ , 
      0x00000000u /*  Published type of the job process  */ , 
      0x00000000u /*  Published address area identifier  */ , 
      0x00000000u /*  Published virtual address  */ , 
      NULL_PTR /*  Master partition does not publish any data  */ , 
      0x00000000u /*  Published job length  */ , 
      0x00000000u /*  Published job result  */ 
    };

#define VMEMACCM_STOP_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/* Each partition accesses the NV RAM access token via a pointer to abstract from actual symbol/ address. */
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

vMemAccM_PartitionPublishRequestPtrType vMemAccM_MultiPartitionPublishedRequests[VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS] = 
    {
      &vMemAccM_PublishReq_vMemAccMMasterPartitionConfiguration_Id0, 
      &vMemAccM_PublishReq_Satellite_Id1
    };


vMemAccM_NVRAMAccessTokenPtrType vMemAccM_NVRAMAccessTokenPtr = &vMemAccM_NVRAMAccessToken; 
vMemAccM_PartitionPublishRequestPtrType vMemAccM_PartitionPublishRequestPtr = &vMemAccM_PublishReq_vMemAccMMasterPartitionConfiguration_Id0; 


#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */


#define VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: MULTI PARTITION GLOBAL DATA
**********************************************************************************************************************/
/* Master variables published to all partitions. */
#define VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0 
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */ 
vMemAccM_NVRAMAccessTokenType vMemAccM_NVRAMAccessToken = VMEMACCM_MULTIPARTITION_SYNC_TOKEN; 
#define VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0 
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */ 

 
#define VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1 
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */ 
vMemAccM_PublishRequestDataType vMemAccM_PublishReq_Satellite_Id1_Data[VMEMACCM_MULTI_PARTITION_PUBLISH_DATA_SIZE] = {0}; 
vMemAccM_PartitionPublishRequestType vMemAccM_PublishReq_Satellite_Id1 = 
    {
      VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST /*  Published job priority  */ , 
      0x00000000u /*  Published type of the job process  */ , 
      0x00000000u /*  Published address area identifier  */ , 
      0x00000000u /*  Published virtual address  */ , 
      vMemAccM_PublishReq_Satellite_Id1_Data /*  Data buffer to get data from or set data to. Not used as multipartition satellite!  */ , 
      0x00000000u /*  Published job length  */ , 
      0x00000000u /*  Published job result  */ 
    }; 
#define VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1 
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */ 

 


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


/**********************************************************************************************************************
  END OF FILE: vMemAccM_Lcfg.c
**********************************************************************************************************************/

