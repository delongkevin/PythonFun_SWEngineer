/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_ConfigInterface.c
 *        \brief  Configuration interface implementation
 *      \details  Provides the implementation for the configuration interface.
 *         \unit  ConfigInterface
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_CONFIGINTERFACE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;     /*!< Configuration of the partition the block is configured for */
    Fee_30_FlexNor_ConstBlockConfigPtrType BlockConfig;             /*!< Configuration of the block */
} Fee_30_FlexNor_ConfigInterface_BlockConfigSearchResultType;       /*!< Combines the block and partition configuration into one type */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_StartMarker = 0xAAAAAAAAu;
Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_SealMarker = 0x55555555u;
Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_CommitMarker = 0xCCCCCCCCu;
Fee_30_FlexNor_MarkerConstType Fee_30_FlexNor_EraseMarker = 0xEEEEEEEEu;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ConstConfigPtrType Fee_30_FlexNor_ActiveConfigPtr;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_FindBlockInConfig()
 *********************************************************************************************************************/
/*! \brief       Searches for the partition and block configuration for the given block number
 *  \details     -
 *  \param[in]   blockNumber        The block number whose configuration shall be determined
 *  \return      The combined partition and block configuration for the given block number. In case no configuration 
 *               was found for the block, both members of the search result struct are NULL_PTRs. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ConfigInterface_BlockConfigSearchResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_FindBlockInConfig(
    Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_FindBlockInConfig()
 *********************************************************************************************************************/
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
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ConfigInterface_BlockConfigSearchResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_FindBlockInConfig(
    Fee_30_FlexNor_BlockNumberType blockNumber)
{
    boolean configFound = FALSE;
    uint32 partitionIndex, blockIndex;
    Fee_30_FlexNor_ConfigInterface_BlockConfigSearchResultType searchResult;

    searchResult.BlockConfig =  NULL_PTR;
    searchResult.PartitionConfig = NULL_PTR;

    for(partitionIndex = 0; partitionIndex < Fee_30_FlexNor_ActiveConfigPtr->PartitionCount; partitionIndex++)
    {
        Fee_30_FlexNor_ConstPartitionConfigPtrType partition = &Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionIndex];

        for(blockIndex = 0; blockIndex < partition->BlockCount; blockIndex++)
        {
            if(partition->Blocks[blockIndex].Number == blockNumber)
            {
                configFound = TRUE;
                searchResult.BlockConfig = &(partition->Blocks[blockIndex]);
                searchResult.PartitionConfig = partition;
                break;
            }
        }

        if(configFound == TRUE)
        {
            break;
        }
    }

    return searchResult;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_SetConfig()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_SetConfig(Fee_30_FlexNor_ConstConfigPtrType cfgPtr)
{
    Fee_30_FlexNor_ActiveConfigPtr = cfgPtr;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetConfig()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ConstConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetConfig(void)
{
    return Fee_30_FlexNor_ActiveConfigPtr;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetBlockConfig()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ConstBlockConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetBlockConfig(
    Fee_30_FlexNor_BlockNumberType blockNumber)
{
    return Fee_30_FlexNor_ConfigInterface_FindBlockInConfig(blockNumber).BlockConfig;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetBlockConfigById()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ConstBlockConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetBlockConfigById(
    Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_BlockIdType blockId)
{
    uint32 blockIndex;
    Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = NULL_PTR;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    for(blockIndex = 0; blockIndex < partitionConfig->BlockCount; blockIndex++)
    {
        if(partitionConfig->Blocks[blockIndex].Id == blockId)
        {
            blockConfig = &partitionConfig->Blocks[blockIndex];
        }
    }

    return blockConfig;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetTotalConfiguredPayloadSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetTotalConfiguredPayloadSize(Fee_30_FlexNor_PartitionIdType partitionId)
{
    uint32 blockIndex;
    uint32 totalPayload = 0u;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    for(blockIndex = 0; blockIndex < partitionConfig->BlockCount; blockIndex++)
    {
        totalPayload += partitionConfig->Blocks[blockIndex].Length;
    }

    return totalPayload;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ConstPartitionConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetPartitionConfigOfBlock(
    Fee_30_FlexNor_BlockNumberType blockNumber)
{
    return Fee_30_FlexNor_ConfigInterface_FindBlockInConfig(blockNumber).PartitionConfig;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionConfig()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ConstPartitionConfigPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(
    Fee_30_FlexNor_PartitionIdType partitionId)
{
    return &Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId];
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetPartitionLayout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_LayoutOptionType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetPartitionLayout(Fee_30_FlexNor_PartitionIdType partitionId)
{
    return Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].Layout;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetSectorLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetSectorLength(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType startAddress)
{
    uint8 index;
    Fee_30_FlexNor_LengthType sectorLength = 0;

    for(index = 0; index < Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].SectorCount; index++)
    {
        if(Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].Sectors[index].StartAddress == startAddress)
        {
            sectorLength = Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].Sectors[index].Length;
            break;
        }
    }

    return sectorLength;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ConfigInterface_GetSectorStartAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_AddressType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_ConfigInterface_GetSectorStartAddress(
    Fee_30_FlexNor_PartitionIdType partitionId, 
    Fee_30_FlexNor_AddressType targetAddress)
{
    uint8 sIndex;
    Fee_30_FlexNor_AddressType startAddress = 0u;

    for(sIndex = 0; sIndex < Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].SectorCount; sIndex++)
    {
        Fee_30_FlexNor_AddressType sectorStart = Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].Sectors[sIndex].StartAddress;
        Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ActiveConfigPtr->Partitions[partitionId].Sectors[sIndex].Length;

        if((targetAddress >= sectorStart) && (targetAddress < (sectorStart + sectorLength)))
        {
            startAddress = sectorStart;
            break;
        }
    }

    return startAddress;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ConfigInterface.c
 *********************************************************************************************************************/
