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
/*!        \file  Fee_30_FlexNor_SlimInstance.c
 *        \brief  Slim instance unit implementation
 *      \details  Implementation of the instance services based on the slim instance layout.
 *         \unit  SlimInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMINSTANCE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimInstance.h"
#include "Fee_30_FlexNor_SlimInstanceInternal.h"
#include "Fee_30_FlexNor_SlimInstanceMachine.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_Shared.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_30_FLEXNOR_CONTENT_STATUS_INDEX (0x0u)

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimInstance_ContextType Fee_30_FlexNor_SlimInstanceStmContext;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DataType Fee_30_FlexNorSlimInstanceBuffer[FEE_30_FLEXNOR_INSTANCEBUFFER_SIZE]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_SlimInstance_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Parses the metdata from the given buffer
 *  \details     Parses the instance marker from the data previously read from flash.
 *  \param[in]   ctx        Context containing the buffer that shall be parsed. Must not be NULL.
 *  \pre         The instance metadata must already be read from flash
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ParseInstanceMetadata(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the instance metadata
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \return      The aligned size of the instance metadata
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(uint16 pageAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_PreparePayloadStartBuffer()
 *********************************************************************************************************************/
/*! \brief       Prepares the buffer for the first payload write step according to the instance status
 *  \details     -
 *  \param[in]   ctx               Instance context
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_PreparePayloadStartBuffer(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SlimInstanceStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SlimInstanceStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ParseInstanceMetadata(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    ctx->Instance.CommitMarker = Fee_30_FlexNor_Shared_GetMarker(ctx->InstanceBuffer, 0); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(uint16 pageAlignment)
{
    return Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_CommitMarker), pageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_PreparePayloadStartBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_PreparePayloadStartBuffer(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType payloadIndex;
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->InstanceBuffer[FEE_30_FLEXNOR_CONTENT_STATUS_INDEX] = (Fee_30_FlexNor_DataType)ctx->Instance.ConstInstanceData->Status; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    
    if(ctx->Instance.ConstInstanceData->Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        for(payloadIndex = 0; (payloadIndex < ((uint32)ctx->PartitionConfig->PageAlignment - 1u)) && (payloadIndex < ctx->Instance.ConstInstanceData->PayloadSize); payloadIndex++)
        {
            ctx->InstanceBuffer[payloadIndex + 1u] = ctx->Instance.ConstInstanceData->WriteBuffer[payloadIndex]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            ctx->PayloadWritten++; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Init(void)
{
    Fee_30_FlexNor_SlimInstanceStmContext.InstanceBuffer = Fee_30_FlexNorSlimInstanceBuffer;    
    Fee_30_FlexNor_SlimInstance_InitState(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_GetTotalSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_GetTotalSize(Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    uint32 totalSize;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;    
    
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    totalSize = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(partitionConfig->PageAlignment);
    totalSize += Fee_30_FlexNor_Shared_Align(instance->PayloadSize + 1u, partitionConfig->InterferenceFreeAlignment);
    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Validate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Validate(Fee_30_FlexNor_InstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.InstanceData = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.ResultCallback = resultCbk;
    
    Fee_30_FlexNor_SlimInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_Validate_Initialize(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_Write()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_Write(Fee_30_FlexNor_ConstInstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.ConstInstanceData = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.PayloadWritten = 0;
    Fee_30_FlexNor_SlimInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_Write_Initialize(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SlimInstance_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadInstanceMetadataAndStatus(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    /* 
     * The status is also read because it is required to detect if the instance is empty or not. 
     * In case the instance allocation is interrupted before the commit marker is written, the validation can't decide
     * if the instance is empty or invalid without evaluating the instance status also.
     */
    Fee_30_FlexNor_LengthType readLength;
    readLength = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize((2u * ctx->PartitionConfig->PageAlignment));

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, readLength, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress, 
        ctx->InstanceBuffer, 
        readLength, 
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ValidateInstanceMetadata(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_MarkerType erasedMarker;
    Fee_30_FlexNor_LengthType alignedMetadataSize;
    boolean isStatusPageErased;
    
    Fee_30_FlexNor_SlimInstance_ParseInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    erasedMarker = Fee_30_FlexNor_Shared_GetEmptyMarker(ctx->PartitionConfig->ErasedValue);
    alignedMetadataSize = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment);
    isStatusPageErased = Fee_30_FlexNor_Shared_IsErased(&(ctx->InstanceBuffer[alignedMetadataSize]), alignedMetadataSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if((isStatusPageErased == TRUE) && (ctx->Instance.CommitMarker == erasedMarker))
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if(ctx->Instance.CommitMarker == Fee_30_FlexNor_CommitMarker)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadContent()
 *********************************************************************************************************************/
 /*! 
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadContent(Fee_30_FlexNor_InstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimInstanceStmContext.Instance.InstanceData = instance;
    Fee_30_FlexNor_SlimInstanceStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SlimInstance_ReadContent_Initialize(&Fee_30_FlexNor_SlimInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadStatus()
 *********************************************************************************************************************/
/*! 
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadStatus(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMetadataSize;
    alignedMetadataSize = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMetadataSize, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress + alignedMetadataSize, 
        ctx->InstanceBuffer, 
        ctx->PartitionConfig->PageAlignment,
        &Fee_30_FlexNor_SlimInstance_ResultHandler);  /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ParseInstanceStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ParseInstanceStatus(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(ctx->InstanceBuffer[FEE_30_FLEXNOR_CONTENT_STATUS_INDEX] == (uint8)FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        ctx->Instance.InstanceData->Status = FEE_30_FLEXNOR_INSTANCE_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }

    if(ctx->InstanceBuffer[FEE_30_FLEXNOR_CONTENT_STATUS_INDEX] == (uint8)FEE_30_FLEXNOR_INSTANCE_INVALIDATED)
    {
        ctx->Instance.InstanceData->Status = FEE_30_FLEXNOR_INSTANCE_INVALIDATED; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_ReadPayload()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_ReadPayload(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType contentOffset;
    contentOffset = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment) + 1u;

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress + contentOffset + ctx->Instance.InstanceData->PayloadOffset, 
        ctx->Instance.InstanceData->ReadBuffer, 
        (ctx->Instance.InstanceData->PayloadSize),
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayloadStart()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayloadStart(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment);
    Fee_30_FlexNor_AddressType targetAddress = ctx->Instance.ConstInstanceData->StartAddress + metadataSize;

    Fee_30_FlexNor_SlimInstance_PreparePayloadStartBuffer(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        targetAddress, 
        ctx->InstanceBuffer, 
        ctx->PartitionConfig->PageAlignment, 
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WritePayload()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WritePayload(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SlimInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment);
    Fee_30_FlexNor_AddressType targetAddress = ctx->Instance.ConstInstanceData->StartAddress + metadataSize + ctx->PayloadWritten + 1u;
    Fee_30_FlexNor_LengthType leftPayloadSize = ctx->Instance.ConstInstanceData->PayloadSize - ctx->PayloadWritten;

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        targetAddress, 
        &(ctx->Instance.ConstInstanceData->WriteBuffer[ctx->PayloadWritten]), 
        leftPayloadSize, 
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->PayloadWritten += leftPayloadSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimInstance_WriteCommitMarker(Fee_30_FlexNor_SlimInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize;    
    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_CommitMarker), ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMarkerSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_CommitMarker, ctx->InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress, 
        ctx->InstanceBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_SlimInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimInstance.c
 *********************************************************************************************************************/
