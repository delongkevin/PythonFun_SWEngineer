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
/*!        \file  Fee_30_FlexNor_SlimChunkMachine.c
 *        \brief  Slim chunk state machine implementation
 *      \details  Provides the implementation of the state machine logic for the slim chunk unit.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMCHUNKMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimChunkMachine.h"
#include "Fee_30_FlexNor_ChunkInternal.h"
#include "Fee_30_FlexNor_Scheduler.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkDefaultState = {
    Fee_30_FlexNor_SlimChunk_DefaultProcessEvent, 
    Fee_30_FlexNor_SlimChunk_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkValidateChunkHeaderState = {
    Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkCheckFirstInstanceState = {
    Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWritePropertiesState = {
    Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWritePredecessorLinkState = {
    Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWriteInstanceState = {
    Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ConstStateType Fee_30_FlexNor_SlimChunkWriteCommitMarkerState = {
    Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent, 
    Fee_30_FlexNor_SlimChunk_JobFailEvent
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_InitState(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_JobFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkValidateChunkHeaderState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_OnEnter(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_ProcessEvent(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Std_ReturnType validationComplete;
    validationComplete = Fee_30_FlexNor_SlimChunk_ValidateChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(validationComplete == E_NOT_OK)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkCheckFirstInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_CheckFirstInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else 
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

        Fee_30_FlexNor_SlimChunk_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckFirstInstance_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckFirstInstance_OnEnter(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    const Fee_30_FlexNor_ChunkInstanceIndex firstIndex = 0u;
    Fee_30_FlexNor_Chunk_ValidateInstanceAt(firstIndex, ctx->Chunk.GenericChunk, &ctx->Instance, &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_CheckInstanceValidity(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_SlimChunk_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Allocate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Allocate_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWritePropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_WriteProperties_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_WriteProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    if(ctx->PredecessorChunk == NULL_PTR)
    {
        /* Cancellation is allowed again because only writing the predecessor link is protected from here on. */
        Fee_30_FlexNor_Scheduler_AllowCancel();

        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else 
    {
        ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWritePredecessorLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SlimChunk_WritePredecessorLink_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WritePredecessorLink_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WritePredecessorLink_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->PredecessorChunk->Services.WriteLink(ctx->PredecessorChunk, ctx->Chunk.ConstGenericChunk, &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Chunk_WriteInstanceAt(0u, ctx->Chunk.ConstGenericChunk, ctx->InstanceToWrite, &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SlimChunk_WriteCommitMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_WriteCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_SlimChunk_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SlimChunkDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunkMachine.c
 *********************************************************************************************************************/
