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
/*!        \file  Fee_30_FlexNor_LookupTable.c
 *        \brief  Lookup table implementation
 *      \details  Provides the business logic for the lookup table services.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_LookupTableInternal.h"
#include "Fee_30_FlexNor_LookupTableMachine.h"

#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Partition.h"
#include "Fee_30_FlexNor_ChunkFactory.h"
#include "Fee_30_FlexNor_ChunkSearch.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK (0xFFFFFFu) /*!< The first byte will be used for the sector id for the offset we need the following 3 bytes */
#define FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE (0x0u) /*!< The default value for a lookup table link */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (FEE_30_FLEXNOR_LOCAL) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL static
#endif

#if !defined (FEE_30_FLEXNOR_LOCAL_INLINE) /* COV_FEE_30_FLEXNOR_COMPATIBILITY */
# define FEE_30_FLEXNOR_LOCAL_INLINE LOCAL_INLINE
#endif

/* Sets the k bit in the given array A */
#define SetBit(A, k) (A[(k/8u)] |= (1u << (k%8u))) 

/* Clears the k bit in the given array A */
#define ClearBit(A, k) (A[(k/8u)] &= ~(1u << (k%8u))) 

/* Tests the k bit in the given array A */
#define TestBit(A, k) ((A[(k/8u)] & (1u << (k%8u))) >> (k%8u))


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ContextType Fee_30_FlexNor_LookupTableStmContext;   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToLookupTableLink()
 *********************************************************************************************************************/
/*! \brief       Converts the given chunk location to a lookup table link.
 *  \details     -
 *  \param[in]   chunkLocation  Chunk location that shall be converted
 *  \return      The converted lookup table link
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ToLookupTableLink(Fee_30_FlexNor_ChunkLocationType chunkLocation);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToChunkLocation()
 *********************************************************************************************************************/
/*! \brief       Converts a given lookup table link to a chunk location
 *  \details     -
 *  \param[in]   link   Given link that shall be converted
 *  \return      The converted chunk location
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ChunkLocationType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ToChunkLocation(Fee_30_FlexNor_LookupTable_LinkType link);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock
 *********************************************************************************************************************/
/*! \brief       Returns a pointer to the sector object the latest lut block was written
 *  \details     -
 *  \param[in]   partitionConfig Partition the lut block belongs to.
 *  \return      Pointer to the sector. Never NULL.
 *  \pre         Lut block was written before.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_CreateLutJob
 *********************************************************************************************************************/
/*! \brief       Sets the relevant parameters in the job object that are necessary for loading and persisting the lut
 *  \details     -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_CreateLutJob(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called chunk search service
 *  \details     This function is used as a result callback for chunk search services called by this unit.
 *               Chunk search result handling requires a different implementation than the generic result handler.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink()
 *********************************************************************************************************************/
/*! \brief       Gets the sector with the most recent LUT link 
 *  \details     -
 *  \param[in]   partitionId    Id of the partition
 *  \return      Pointer to the sector. NULL, if no sector is found.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ProcessingHandler(void)
{
    return Fee_30_FlexNor_LookupTableStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_LookupTableStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToLookupTableLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ToLookupTableLink(Fee_30_FlexNor_ChunkLocationType chunkLocation)
{
    Fee_30_FlexNor_LookupTable_LinkType link;
    link.SectorId = (Fee_30_FlexNor_SectorIdType)(chunkLocation >> 24u);
    link.ChunkOffset = (Fee_30_FlexNor_PagebasedOffsetType)(chunkLocation & FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK);
    link.IsValidated = FALSE;
    return link;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ToChunkLocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ChunkLocationType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ToChunkLocation(Fee_30_FlexNor_LookupTable_LinkType link)
{
    Fee_30_FlexNor_ChunkLocationType chunkLocation = (((Fee_30_FlexNor_ChunkLocationType)link.SectorId) << 24u);
    chunkLocation |= (link.ChunkOffset & FEE_30_FLEXNOR_LOOKUPTABLE_OFFSET_MASK);
    return chunkLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig)
{
    Fee_30_FlexNor_LookupTable_LinkType lutEntry;
    lutEntry = Fee_30_FlexNor_LookupTable_GetLink(partitionConfig->PartitionId, FEE_30_FLEXNOR_LUTBLOCKID);

    /* Here it is assured that there is a lut entry, because the precondition of this function states that the lut block has been written. */
    return Fee_30_FlexNor_SectorContainer_Get(partitionConfig->PartitionId, lutEntry.SectorId);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_CreateLutJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_CreateLutJob(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    /* The service id does not matter here. We can use it for write and for read...*/
    ctx->LutJob.Service = FEE_30_FLEXNOR_SID_WRITE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.BlockId = FEE_30_FLEXNOR_LUTBLOCKID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.PartitionId = ctx->PartitionConfig->PartitionId; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.WriteBuffer = (Fee_30_FlexNor_ConstDataPtrType)ctx->PartitionConfig->LookupTable; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.ReadBuffer = (Fee_30_FlexNor_DataPtrType)ctx->PartitionConfig->LookupTable; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.Length = sizeof(*ctx->PartitionConfig->LookupTable) * ctx->PartitionConfig->LookupTableSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutJob.Offset = 0u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_OK)
    {
        Fee_30_FlexNor_LookupTableStmContext.LutChunkSearchSucceeded = TRUE;
    }
    else
    {
        Fee_30_FlexNor_LookupTableStmContext.LutChunkSearchSucceeded = FALSE;
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_SectorPtrType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_SectorPtrType matchingSector = NULL_PTR;
    Fee_30_FlexNor_SectorPtrType currentSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(partitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    while(currentSector != NULL_PTR)
    {
        if(currentSector->LutChunkLink.Validity == FEE_30_FLEXNOR_VALID)
        {
            matchingSector = currentSector;
        }
        currentSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(currentSector); /* SBSW_Fee_30_FlexNor_LoopStoredSectors */
    }

    return matchingSector;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Init(void)
{
    uint8 pIndex;
    Fee_30_FlexNor_ConstConfigPtrType config = Fee_30_FlexNor_ConfigInterface_GetConfig();

    for(pIndex = 0; pIndex < config->PartitionCount; pIndex++)
    {
        Fee_30_FlexNor_LookupTable_InvalidateAll(config->Partitions[pIndex].PartitionId);
    }

    Fee_30_FlexNor_LookupTable_InitState(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_LookupTable_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLink()
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
 */
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLink(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId)
{
    Fee_30_FlexNor_LookupTable_LinkType link;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    link.SectorId = 0u;
    link.ChunkOffset = 0u;
    link.IsValidated = FALSE;
    
    if(blockId < partitionConfig->LookupTableSize)
    {
        Fee_30_FlexNor_ChunkLocationType chunkLocation = partitionConfig->LookupTable[blockId];
        link = Fee_30_FlexNor_LookupTable_ToLookupTableLink(chunkLocation);
        link.IsValidated = (boolean)TestBit(partitionConfig->LookupTableVerificationFlags, blockId);
    }

    return link;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetLinkIfNewer()
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
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetLinkIfNewer(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, Fee_30_FlexNor_LookupTable_LinkType link)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    
    if(blockId < partitionConfig->LookupTableSize)
    {
        boolean isStoredSectorOlder;
        Fee_30_FlexNor_LookupTable_LinkType storedLink;

        storedLink = Fee_30_FlexNor_LookupTable_ToLookupTableLink(partitionConfig->LookupTable[blockId]);
        isStoredSectorOlder = Fee_30_FlexNor_SectorContainer_IsOlder(storedLink.SectorId, link.SectorId);

        if((isStoredSectorOlder == TRUE) || 
           (storedLink.SectorId == FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE) ||
           ((storedLink.SectorId == link.SectorId) && (link.ChunkOffset > storedLink.ChunkOffset)))
        {
            Fee_30_FlexNor_ChunkLocationType chunkLocation = Fee_30_FlexNor_LookupTable_ToChunkLocation(link);
            partitionConfig->LookupTable[blockId] = chunkLocation; /* SBSW_Fee_30_FlexNor_LookupTableModifications */
            SetBit(partitionConfig->LookupTableVerificationFlags, blockId); /* SBSW_Fee_30_FlexNor_LookupTableModifications */
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsFullyValidated()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsFullyValidated(Fee_30_FlexNor_PartitionIdType partitionId)
{
    uint32 lutIndex;
    boolean allValidated = TRUE;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    
    for(lutIndex = 0u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        boolean isLinkValidated = (boolean)TestBit(partitionConfig->LookupTableVerificationFlags, lutIndex);

        if(isLinkValidated == FALSE)
        {
            allValidated = FALSE;
        }
    }

    return allValidated;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InvalidateAll()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InvalidateAll(Fee_30_FlexNor_PartitionIdType partitionId)
{
    uint32 lutIndex;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);

    for(lutIndex = 0u; lutIndex < partitionConfig->LookupTableSize; lutIndex++)
    {
        partitionConfig->LookupTable[lutIndex] = FEE_30_FLEXNOR_LOOKUPTABLE_LINK_DEFAULT_VALUE; /* SBSW_Fee_30_FlexNor_LookupTableModifications */
        ClearBit(partitionConfig->LookupTableVerificationFlags, lutIndex); /* SBSW_Fee_30_FlexNor_LookupTableModifications */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Recover()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Recover(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_LookupTable_Recover_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerSectorScan()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerSectorScan(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(Fee_30_FlexNor_Sector_IsUsed(ctx->NextSectorToProcess) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    {
        Fee_30_FlexNor_Sector_Scan(ctx->NextSectorToProcess, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ValidateAll
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ValidateAll(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint32 lutIndex;
    
    for(lutIndex = 0u; lutIndex < ctx->PartitionConfig->LookupTableSize; lutIndex++)
    {
        SetBit(ctx->PartitionConfig->LookupTableVerificationFlags, lutIndex); /* SBSW_Fee_30_FlexNor_LookupTableModifications */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Persist()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Persist(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_LookupTable_Persist_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_CreateLutJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Partition_WriteBlock(&ctx->LutJob); /* SBSW_Fee_30_FlexNor_FunctionCallWithJobPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite(Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_SectorPtrType sector;
    Fee_30_FlexNor_LookupTable_LinkType lutLink;
    sector = Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    lutLink = Fee_30_FlexNor_LookupTable_GetLink(ctx->PartitionConfig->PartitionId, FEE_30_FLEXNOR_LUTBLOCKID); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    sector->LutChunkLink.Target = Fee_30_FlexNor_LookupTable_ToChunkLocation(lutLink); /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
    sector->LutChunkLink.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
    Fee_30_FlexNor_Sector_WriteLutLink(sector, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_SectorContainer_GetSector */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsShortcutNecessary
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsShortcutNecessary(Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_ConstSectorPtrType sector;
    sector = Fee_30_FlexNor_LookupTable_GetSectorOfLatestLutBlock(ctx->PartitionConfig); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return (sector->LutChunkLink.Validity == FEE_30_FLEXNOR_EMPTY) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LookupTableStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(partitionId);
    Fee_30_FlexNor_LookupTableStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_LookupTable_Load_Initialize(&Fee_30_FlexNor_LookupTableStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_ConstSectorPtrType mostRecentLutSector;
    Fee_30_FlexNor_LookupTable_CreateLutJob(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    mostRecentLutSector =  Fee_30_FlexNor_LookupTable_GetSectorWithLatestLutLink(ctx->PartitionConfig->PartitionId);

    if(mostRecentLutSector != NULL_PTR)
    {
        Fee_30_FlexNor_ChunkFactory_CreateChunk(0u, ctx->PartitionConfig->PartitionId, mostRecentLutSector->SectorId, &ctx->LutChunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
        Fee_30_FlexNor_ChunkSearch_FollowLink(
            ctx->PartitionConfig->PartitionId,
            mostRecentLutSector->LutChunkLink,
            &ctx->LutChunk,
            Fee_30_FlexNor_LookupTable_LutChunkSearchResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    }
    else
    {
        ctx->LutChunkSearchSucceeded = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_InstanceFactory_CreateInstance(0u, ctx->PartitionConfig->PartitionId, &ctx->LutInstance); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->LutInstance.Data.ReadBuffer = ctx->LutJob.ReadBuffer; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutInstance.Data.PayloadSize = ctx->LutJob.Length; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutInstance.Data.PayloadOffset = ctx->LutJob.Offset; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LutChunk.Services.FindLatestValidInstance(&ctx->LutChunk, &ctx->LutInstance, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->LutInstance.Services.ReadContent(&ctx->LutInstance.Data, &Fee_30_FlexNor_LookupTable_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTable.c
 *********************************************************************************************************************/
