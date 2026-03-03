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
/*!        \file  Fee_30_FlexNor_PartitionMachine.c
 *        \brief  Partition state machine implementation
 *      \details  Provides the implementation of the state machine logic for the partition unit.
 *         \unit  Partition
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
#include "Fee_30_FlexNor_PartitionMachine.h"
#include "Fee_30_FlexNor_PartitionInternal.h"

#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_SectorContainer.h"
#include "Fee_30_FlexNor_GarbageCollection.h"

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
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionDefaultState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_DefaultProcessEvent, 
    Fee_30_FlexNor_Partition_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionFinishGarbageCollectionState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_FinishGarbageCollection_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionReadSectorHeadersState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGetLookupTableState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionSearchLatestChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionRecoverLookupTableState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionSearchLatestInstanceState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionAllocateInExistingChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionAllocateNewChunkState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionScanSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_ScanSector_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGetNewSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Partition_ConstStateType Fee_30_FlexNor_PartitionGarbageCollectionState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent, 
    Fee_30_FlexNor_Partition_JobFailEvent
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
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
 * Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that no chunk was found for the block during a read job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that the latest chunk for the block was found during a read job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that no chunk was found for the block during a write job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*! \brief       Handels the event that the latest chunk for the block was found during a write job
 *  \details     -
 *  \param[in]   ctx    Pointer to the context that contains the data for handling the event. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsLinkInvalid()
 *********************************************************************************************************************/
/*! \brief       Checks if the given link is invalid
 *  \details     The link is invalid in case it consists of an invalid sector id or offset.
 *  \param[in]   link       Link that shall be checked 
 *  \return      TRUE       The given link is invalid
 *               FALSE      The given link is valid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsLinkInvalid(Fee_30_FlexNor_LookupTable_ConstLinkPtrType link);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentJob->JobResult = MEMIF_BLOCK_INCONSISTENT;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndJob();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->TargetSector = Fee_30_FlexNor_SectorContainer_GetOldestValid(ctx->CurrentJob->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateInExistingChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_AllocateInExistingChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_IsLinkInvalid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_IsLinkInvalid(Fee_30_FlexNor_LookupTable_ConstLinkPtrType link)
{
    return ((link->SectorId == 0u) || (link->ChunkOffset == 0u)) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_InitState(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_DefaultFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_JobFailEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->CurrentJob->JobResult = MEMIF_JOB_FAILED;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    Fee_30_FlexNor_Partition_EndJob();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadBlock_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadBlock_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->NoChunkFoundAction = &Fee_30_FlexNor_Partition_ReadBlock_NoChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LatestChunkFoundAction = &Fee_30_FlexNor_Partition_ReadBlock_LatestChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Partition_StartJob();

    if(ctx->Flags[ctx->CurrentJob->PartitionId].StartupExecuted == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionReadSectorHeadersState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_ReadSectorHeaders_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_FinishGarbageCollection_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_FinishGarbageCollection_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_TriggerGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_FinishGarbageCollection_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_FinishGarbageCollection_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_LinkType lutLink;
    boolean isLinkInvalid;

    lutLink = Fee_30_FlexNor_LookupTable_GetLink(ctx->CurrentJob->PartitionId, ctx->CurrentJob->BlockId);
    isLinkInvalid = Fee_30_FlexNor_Partition_IsLinkInvalid(&lutLink); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */
    /* 
     * An invalid link has the default value (0x0) for its sector id or chunk offset. 
     * A link is invalid in case the block was not written to flash yet or it was not read yet during the current cycle.
     */

    ctx->LatestChunkFound = FALSE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if(lutLink.IsValidated == TRUE)
    {
        if(isLinkInvalid == TRUE)
        {
            ctx->NoChunkFoundAction(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            Fee_30_FlexNor_Partition_ReadChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else
    {
        if(isLinkInvalid == TRUE)
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_RecoverLookupTableState_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else 
        {
            Fee_30_FlexNor_Partition_FollowLinks(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_StructureValidityType chunkValidity = ctx->LatestChunk.Data.Validity;
    Fee_30_FlexNor_StructureValidityType linkValidity = ctx->LatestChunk.Data.ChunkLink.Validity;

    /* The link validity can only be INVALID or EMPTY here due to the way the ChunkSearch works. */
    if((chunkValidity == FEE_30_FLEXNOR_INVALID) || (linkValidity == FEE_30_FLEXNOR_INVALID))
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionRecoverLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_RecoverLookupTableState_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else /* FEE_30_FLEXNOR_EMPTY */
    {
        ctx->LatestChunkFound = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->LatestChunkFoundAction(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_ReadSectorHeaders(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ReadSectorHeaders_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionGetLookupTableState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_GetLookupTable_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_GetLookupTable(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetLookupTable_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    boolean gcPending = Fee_30_FlexNor_GarbageCollection_IsPending(ctx->CurrentJob->PartitionId);

    ctx->Flags[ctx->CurrentJob->PartitionId].StartupExecuted = TRUE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if((ctx->CurrentJob->Service == FEE_30_FLEXNOR_SID_WRITE) && (gcPending == TRUE))
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionFinishGarbageCollectionState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_FinishGarbageCollection_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestInstance_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestInstance_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_GetLatestValidInstanceFromChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_SearchLatestInstance_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(ctx->Instance.Data.Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    }
    else
    {
        ctx->CurrentJob->JobResult = MEMIF_BLOCK_INVALID;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    }

    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_EndJob();

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_RecoverLookupTableState_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_RecoverLookupTableState_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_TriggerLookupTableRecovery(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_RecoverLookupTable_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_WriteBlock_Initialize()
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
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_WriteBlock_Initialize(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->NoChunkFoundAction = &Fee_30_FlexNor_Partition_WriteBlock_NoChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->LatestChunkFoundAction = &Fee_30_FlexNor_Partition_WriteBlock_LatestChunkFound; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_Partition_StartJob();

    if(ctx->Flags[ctx->CurrentJob->PartitionId].StartupExecuted == TRUE)
    {
        if(Fee_30_FlexNor_GarbageCollection_IsPending(ctx->CurrentJob->PartitionId) == TRUE)
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionFinishGarbageCollectionState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_FinishGarbageCollection_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else 
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionSearchLatestChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_SearchLatestChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */ 
        }
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionReadSectorHeadersState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_ReadSectorHeaders_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateInExistingChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateInExistingChunk_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_TriggerInstanceAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateInExistingChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->AllocationSucceeded == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK; /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        Fee_30_FlexNor_Partition_EndJob();
    }
    else
    {
        ctx->TargetSector = Fee_30_FlexNor_SectorContainer_Get(ctx->CurrentJob->PartitionId, ctx->LatestChunk.Data.SectorId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->TargetSector != NULL_PTR)
    {
        if(ctx->TargetSector->NextFreeAddress == 0u)
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionScanSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_ScanSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            Fee_30_FlexNor_Partition_TriggerChunkAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionGetNewSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_GetNewSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }    
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent()
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
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_AllocateNewChunk_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    if(ctx->AllocationSucceeded == TRUE)
    {
        ctx->CurrentJob->JobResult = MEMIF_JOB_OK;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
        ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
        Fee_30_FlexNor_Partition_EndJob();
    }
    else
    {
        ctx->TargetSector = Fee_30_FlexNor_SectorContainer_GetNextNewerValid(ctx->TargetSector); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        if(ctx->TargetSector != NULL_PTR)
        {
            Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            ctx->CurrentState = &Fee_30_FlexNor_PartitionGetNewSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Partition_GetNewSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ScanSector_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ScanSector_OnEnter(Fee_30_FlexNor_Partition_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_TriggerSectorScan(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_ScanSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_ScanSector_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_PartitionAllocateNewChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Partition_AllocateNewChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_OnEnter()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->TargetSector = Fee_30_FlexNor_Partition_GetAvailableSector(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(ctx->TargetSector != NULL_PTR)
    {
        Fee_30_FlexNor_Partition_TriggerSectorAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_PartitionGarbageCollectionState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Partition_GarbageCollection_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GetNewSector_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentJob->JobResult = MEMIF_JOB_OK;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
    Fee_30_FlexNor_Partition_EndJob();

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GarbageCollection_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GarbageCollection_OnEnter(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    Fee_30_FlexNor_Partition_TriggerGarbageCollection(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Partition_GarbageCollection_ProcessEvent(Fee_30_FlexNor_Partition_ContextPtrType ctx)
{
    ctx->CurrentJob->JobResult = MEMIF_JOB_OK;  /* SBSW_Fee_30_FlexNor_ParamPointerJobResultWriteAccess */
    ctx->CurrentState = &Fee_30_FlexNor_PartitionDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ 
    Fee_30_FlexNor_Partition_EndJob();

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_PartitionMachine.c
 *********************************************************************************************************************/
