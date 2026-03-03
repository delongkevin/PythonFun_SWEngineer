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
/*!        \file  Fee_30_FlexNor_SectorMachine.c
 *        \brief  Sector state machine implementation
 *      \details  Provides the implementation of the state machine logic for the sector unit.
 *         \unit  Sector
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
#include "Fee_30_FlexNor_SectorMachine.h"
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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorDefaultState = {
    Fee_30_FlexNor_Sector_DefaultProcessEvent, 
    Fee_30_FlexNor_Sector_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadMetadataState = {   /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorReadAdditionalInfoState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorValidateFirstChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_ValidateFirstChunk_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteEraseMarkerState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteLutLinkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteSourceSectorState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorEraseSectorState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_EraseSector_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWritePropertiesState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteFirstChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteFirstChunk_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorWriteCommitMarkerState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorValidateChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ConstStateType Fee_30_FlexNor_SectorAllocateChunkState = {    /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent, 
    Fee_30_FlexNor_Sector_JobFailEvent
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
 * Fee_30_FlexNor_Sector_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_InitState(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DefaultFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Chunk_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_JobFailEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{

    Fee_30_FlexNor_Sector_StartJob(); 
    ctx->CurrentState = &Fee_30_FlexNor_SectorReadMetadataState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_ReadMetadata_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ReadMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ErrorLocation validationResult;
    validationResult = Fee_30_FlexNor_Sector_ValidateMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(validationResult == FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR)
    {
        Fee_30_FlexNor_Sector_ReadAdditionalInfo_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else if(validationResult == FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKERBROKEN)
    {
        Fee_30_FlexNor_Sector_ValidateFirstChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorReadAdditionalInfoState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_ReadAdditionalInfo(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ParseAdditionalInfo(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateFirstChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateFirstChunk_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorValidateFirstChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_ReadFirstChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateFirstChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateFirstChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    boolean firstChunkValid = Fee_30_FlexNor_Sector_ValidateFirstChunk(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(firstChunkValid == TRUE)
    {
        Fee_30_FlexNor_Sector_ReadAdditionalInfo_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob(); 
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteEraseMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteEraseMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob(); 
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteLutLinkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteLutLink_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteLutLinkToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob(); 
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteSourceSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteSourceSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SectorEraseSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EraseSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EraseSector_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_EraseSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EraseSector_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteProperties_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteProperties_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteProperties_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWritePropertiesState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WritePropertiesToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteProperties_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_WriteFirstChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteFirstChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteFirstChunk_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteFirstChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteFirstChunkToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteFirstChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteFirstChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_UpdateLookupTable(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Sector_UpdateNextFreeAddress(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_Sector_WriteCommitMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteCommitMarker_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SectorWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();

    ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->ErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Scan_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Scan_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_StartJob(); 
    ctx->CurrentState = &Fee_30_FlexNor_SectorValidateChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_Sector_ValidateChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateChunk_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ScanCurrentResult currentResult;
    currentResult = Fee_30_FlexNor_Sector_ProcessReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    
    if(currentResult == FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE)
    {
        Fee_30_FlexNor_Sector_ReadChunkHeader(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_Sector_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    if((ctx->Sector->Validity == FEE_30_FLEXNOR_VALID) && (ctx->Sector->NextFreeAddress != 0x0u))
    {
        boolean chunkFits = Fee_30_FlexNor_Sector_DoesChunkFitInSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(chunkFits == TRUE)
        {
            Fee_30_FlexNor_Sector_StartJob();
            ctx->CurrentState = &Fee_30_FlexNor_SectorAllocateChunkState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Sector_AllocateChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        }
        else
        {
            ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
        }
    }
    else
    {
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_OnEnter(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_TriggerChunkAllocation(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_AllocateChunk_ProcessEvent(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_UpdateLookupTable(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    Fee_30_FlexNor_Sector_EndJob();
    ctx->CurrentState = &Fee_30_FlexNor_SectorDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkMachine.c
 *********************************************************************************************************************/
