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
/*!        \file  Fee_30_FlexNor_Chunk.c
 *        \brief  Chunk unit implementation
 *      \details  Implementation of the generic chunk services.
 *         \unit  Chunk
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
#include "Fee_30_FlexNor_ChunkInternal.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_ChunkMachine.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_FlashAccess.h"

#include "Fee_30_FlexNor_Chunk.h"
#include "Fee_30_FlexNor_InstanceFactory.h"

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

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Chunk_ContextType Fee_30_FlexNor_ChunkStmContext;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DataType Fee_30_FlexNor_ChunkBuffer[FEE_30_FLEXNOR_CHUNKBUFFER_SIZE]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32
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
 * Fee_30_FlexNor_Chunk_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ProcessingHandler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ProcessingHandler(void)
{
    return Fee_30_FlexNor_ChunkStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_ChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_ChunkStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_ChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_Init(void)
{
    Fee_30_FlexNor_ChunkStmContext.ChunkBuffer = Fee_30_FlexNor_ChunkBuffer;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_Chunk_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_GetAlignedLinkSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_GetAlignedLinkSize(uint16 interferenceFreeAlignment)
{
    return Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_ChunkLocationType) + 
        sizeof(Fee_30_FlexNor_ChecksumType), interferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ValidateInstanceAt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ValidateInstanceAt(
    Fee_30_FlexNor_ChunkInstanceIndex index,
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_InstancePtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_AddressType instanceOffset;
    Fee_30_FlexNor_AddressType instanceAddress;
    Fee_30_FlexNor_AddressType chunkStartAddress;

    Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0u /* dummyValue */, chunk->Data.PartitionId, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */

    chunkStartAddress = chunk->Data.StartAddress;
    instanceOffset = instance->Services.GetTotalSize(&instance->Data) * index; /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
    instanceAddress = chunkStartAddress + chunk->Services.GetHeaderSize(chunk) + instanceOffset; /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */

    instance->Data.StartAddress = instanceAddress; /* SBSW_Fee_30_FlexNor_Factory */
    instance->Data.PayloadSize = chunk->Data.PayloadSize; /* SBSW_Fee_30_FlexNor_Factory */
    instance->Services.Validate(&instance->Data, resultCbk); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteInstanceAt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteInstanceAt(
    Fee_30_FlexNor_ChunkInstanceIndex targetIndex, 
    Fee_30_FlexNor_ConstChunkPtrType chunk,
    Fee_30_FlexNor_InstancePtrType instance,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_LengthType instanceOffset;

    /* Create dummy instance so the type of the instance is known. */
    Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0u /* Dummy value */, chunk->Data.PartitionId, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    /* Fill instance start address which is now known due to the type of the instance. */
    instanceOffset = targetIndex * instance->Services.GetTotalSize(&instance->Data); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
    instance->Data.StartAddress = chunk->Data.StartAddress + chunk->Services.GetHeaderSize(chunk) + instanceOffset;  /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */

    instance->Services.Write(&instance->Data, resultCbk); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_SearchInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_SearchInstance(
    Fee_30_FlexNor_InstanceSearchType searchType,
    Fee_30_FlexNor_ChunkJobType jobType)
{
    Fee_30_FlexNor_ChunkStmContext.SearchType = searchType;
    Fee_30_FlexNor_ChunkStmContext.ChunkJob = jobType;
    Fee_30_FlexNor_Chunk_BinarySearch_Initialize(&Fee_30_FlexNor_ChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DoBinarySearchStep()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DoBinarySearchStep(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_ChunkInstanceIndex startIndex = ctx->SearchContext.StartIndex;
    Fee_30_FlexNor_ChunkInstanceIndex endIndex = ctx->SearchContext.EndIndex;
    
    if(startIndex >= endIndex)
    {
        ctx->SearchContext.CurrentIndex = startIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->SearchContext.SearchStatus = FEE_30_FLEXNOR_SEARCH_FINISHED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else 
    {
        ctx->SearchContext.CurrentIndex = (Fee_30_FlexNor_ChunkInstanceIndex)((startIndex + endIndex) / 2u); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
   
    Fee_30_FlexNor_Chunk_ValidateInstanceAt(ctx->SearchContext.CurrentIndex, ctx->ConstChunk, ctx->InstanceToCheck, &Fee_30_FlexNor_Chunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateBinarySearchEmpty()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateBinarySearchEmpty(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    if(ctx->InstanceToCheck->Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        /* We don't want to search at current index again, since we know that it is already empty. Hence, we can start one position left
          Since empty chunks are not allowed, we exclude that the instance at index 0 is empty. So there is no danger of an underflow */
        ctx->SearchContext.EndIndex = ctx->SearchContext.CurrentIndex - 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->SearchContext.ValidIndex = ctx->SearchContext.CurrentIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else /* FEE_30_FLEXNOR_VALID, FEE_30_FLEXNOR_INVALID */ 
    {
        /* Same as in the above case, we don't want to check a checked instance again, so continue one position right
          We also don't care about whether the instance is invalid or valid. In both cases, the empty slot must be right. */
        ctx->SearchContext.StartIndex = ctx->SearchContext.CurrentIndex + 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateBinarySearchValid()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateBinarySearchValid(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    if(ctx->InstanceToCheck->Data.Validity == FEE_30_FLEXNOR_VALID)
    {
        /* We don't want to search at current index again, since we know that it is already valid. Hence, we can start one position right */
        ctx->SearchContext.StartIndex = ctx->SearchContext.CurrentIndex + 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->SearchContext.ValidIndex = ctx->SearchContext.CurrentIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if(ctx->InstanceToCheck->Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        /* We don't want to search at current index again, since we know that it is already empty. Hence, we can start one position left
          Since empty chunks are not allowed, we exclude that the instance at index 0 is empty. So there is no danger of an underflow */
        ctx->SearchContext.EndIndex = ctx->SearchContext.CurrentIndex - 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else /* FEE_30_FLEXNOR_INVALID */
    {
       ctx->SearchContext.SearchStatus = FEE_30_FLEXNOR_SEARCH_ABORTED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_FindLatestValidInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_FindLatestValidInstance(
    Fee_30_FlexNor_ConstChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_ChunkStmContext.InstanceToCheck = instance;
    Fee_30_FlexNor_ChunkStmContext.ReadLength = instance->Data.PayloadSize;
    Fee_30_FlexNor_ChunkStmContext.ConstChunk = chunk;
    Fee_30_FlexNor_ChunkStmContext.ResultCallback = resultCbk;
    
    Fee_30_FlexNor_Chunk_FindLatestValidInstance_Initialize();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_ReadInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_ReadInstance(Fee_30_FlexNor_Chunk_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType instanceOffset;
    Fee_30_FlexNor_ConstChunkPtrType chunk = ctx->ConstChunk;
    Fee_30_FlexNor_InstancePtrType instance = ctx->InstanceToCheck;

    /* Instance index is ALWAYS valid, since there is no valid chunk if there is not atleast one valid instance in it. */
    Fee_30_FlexNor_ChunkInstanceIndex instanceIndex = ctx->SearchContext.ValidIndex;

    /* Create dummy instance so the type of the instance is known. */
    Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0u /* Dummy value */, chunk->Data.PartitionId, instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */

    /* Fill instance start address which is now known due to the type of the instance. */
    instanceOffset = instanceIndex * instance->Services.GetTotalSize(&instance->Data); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
    instance->Data.StartAddress = chunk->Data.StartAddress + chunk->Services.GetHeaderSize(chunk) + instanceOffset; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */

    /* Explictly set the instance to valid because the instance was validatd before and found to be valid. */
    instance->Data.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    /* Set the amount of bytes that shall be read explicitly because the payload size of the instance was previously overwritten for the instance size calculation. */
    instance->Data.PayloadSize = ctx->ReadLength; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    /* Validation before reading the content is not necessary, because the SearchInstance state validates all searched instances! */
    instance->Services.ReadContent(&instance->Data, Fee_30_FlexNor_Chunk_ResultHandler);  /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_DoLinearSearchStep()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_DoLinearSearchStep(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    ctx->SearchContext.CurrentIndex = ctx->SearchContext.StartIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Chunk_ValidateInstanceAt(ctx->SearchContext.CurrentIndex, ctx->ConstChunk, ctx->InstanceToCheck, &Fee_30_FlexNor_Chunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(ctx->SearchContext.CurrentIndex == ctx->SearchContext.EndIndex)
    {
        ctx->SearchContext.SearchStatus = FEE_30_FLEXNOR_SEARCH_FINISHED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_EvaluateLinearSearchValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_EvaluateLinearSearchValid(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    if(ctx->InstanceToCheck->Data.Validity == FEE_30_FLEXNOR_VALID)
    {
        ctx->SearchContext.StartIndex = ctx->SearchContext.CurrentIndex + 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->SearchContext.ValidIndex = ctx->SearchContext.CurrentIndex; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if(ctx->InstanceToCheck->Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        ctx->SearchContext.SearchStatus = FEE_30_FLEXNOR_SEARCH_FINISHED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else /* FEE_30_FLEXNOR_INVALID */
    {
      ctx->SearchContext.StartIndex = ctx->SearchContext.CurrentIndex + 1u; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_TryAllocateInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_TryAllocateInstance(
    Fee_30_FlexNor_ConstChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_ChunkStmContext.InstanceToCheck = instance;
    Fee_30_FlexNor_ChunkStmContext.ConstChunk = chunk;
    Fee_30_FlexNor_ChunkStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_Chunk_TryAllocateInstance_Initialize();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_AllocateInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_AllocateInstance(Fee_30_FlexNor_Chunk_ContextPtrType ctx)
{
    ctx->AllocationSuccessful = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if(ctx->SearchContext.ValidIndex != FEE_30_FLEXNOR_INVALID_INDEX)
    {
        Fee_30_FlexNor_Chunk_WriteInstanceAt(ctx->SearchContext.ValidIndex, ctx->ConstChunk, ctx->InstanceToCheck, Fee_30_FlexNor_Chunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        ctx->AllocationSuccessful = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLink(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ConstChunkPtrType targetChunk, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_ChunkStmContext.Chunk = chunk;
    Fee_30_FlexNor_ChunkStmContext.ConstChunk = targetChunk;
    Fee_30_FlexNor_ChunkStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_ChunkStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);

    Fee_30_FlexNor_Chunk_WriteLink_Initialize(&Fee_30_FlexNor_ChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_BuildLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_BuildLink(Fee_30_FlexNor_Chunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChunkLocationType relativeLink;

    Fee_30_FlexNor_SectorIdType targetSectorId = ctx->ConstChunk->Data.SectorId;
    Fee_30_FlexNor_AddressType targetAddress = ctx->ConstChunk->Data.StartAddress;
    Fee_30_FlexNor_AddressType targetSectorStartAddress = Fee_30_FlexNor_ConfigInterface_GetSectorStartAddress(ctx->Chunk->Data.PartitionId, targetAddress);

    uint32 alignedLinkSize = Fee_30_FlexNor_Chunk_GetAlignedLinkSize(ctx->PartitionConfig->InterferenceFreeAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, alignedLinkSize, 0x0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->ChunkBuffer[0] = targetSectorId; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    relativeLink = ((targetAddress - targetSectorStartAddress) / ctx->PartitionConfig->PageAlignment);

    /* According to the memory layout the relative link address is only three bytes wide. */
    Fee_30_FlexNor_Shared_SetValueToBuffer(relativeLink, ctx->ChunkBuffer, 0x3u, sizeof(Fee_30_FlexNor_SectorIdType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->Chunk->Data.ChunkLink.Target = (Fee_30_FlexNor_ChunkLocationType)Fee_30_FlexNor_Shared_GetValueFromBuffer(
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_ChunkLocationType), 
        0x0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */ /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_WriteLinkToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Chunk_WriteLinkToMemory(Fee_30_FlexNor_Chunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChecksumType linkChecksum;

    Fee_30_FlexNor_LengthType metadataLength = ctx->Chunk->Services.GetHeaderSize(ctx->Chunk) - 
        Fee_30_FlexNor_Chunk_GetAlignedLinkSize(ctx->PartitionConfig->InterferenceFreeAlignment); /* SBSW_Fee_30_FlexNor_FunctionPointerCallWithGivenPointer */
        
    Fee_30_FlexNor_LengthType relativeLinkAddress = ctx->Chunk->Data.StartAddress + metadataLength;
    Fee_30_FlexNor_LengthType totalLinkLength = Fee_30_FlexNor_Shared_Align(
        sizeof(Fee_30_FlexNor_ChunkLocationType) + sizeof(Fee_30_FlexNor_ChecksumType), 
        ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, totalLinkLength, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Copy link target to the buffer */
    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Chunk->Data.ChunkLink.Target, 
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_ChunkLocationType),
        0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
    linkChecksum = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->ChunkBuffer, sizeof(Fee_30_FlexNor_ChunkLocationType), 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetValueToBuffer(linkChecksum, 
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_ChecksumType),
        sizeof(Fee_30_FlexNor_ChunkLocationType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Chunk->Data.PartitionId,
        relativeLinkAddress, 
        ctx->ChunkBuffer, 
        totalLinkLength, 
        &Fee_30_FlexNor_Chunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Chunk.c
 *********************************************************************************************************************/
