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
/*!        \file  Fee_30_FlexNor_SecureInstance.c
 *        \brief  Secure instance unit implementation
 *      \details  Implementation of the instance services based on the secure instance layout.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECUREINSTANCE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureInstance.h"
#include "Fee_30_FlexNor_SecureInstanceInternal.h"
#include "Fee_30_FlexNor_SecureInstanceMachine.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ContextType Fee_30_FlexNor_SecureInstanceStmContext;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DataType Fee_30_FlexNor_SecureInstanceBuffer[FEE_30_FLEXNOR_INSTANCEBUFFER_SIZE]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_SecureInstance_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*! \brief       Parses the metdata from the given buffer
 *  \details     Parses the instance markers from the data previously read from flash.
 *  \param[in]   ctx        Context containing the buffer that shall be parsed. Must not be NULL.
 *  \pre         The instance metadata must already be read from flash
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the instance metadata
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the instance metadata
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset()
 *********************************************************************************************************************/
/*! \brief       Gets the offset of the seal marker relative to the instances start address
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \return      The seal marker offset in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset(uint16 pageAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*! \brief       Gets the offset of the commit marker relative to the instances start address
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \return      The commit marker offset in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(uint16 pageAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_PreparePayloadStartBuffer()
 *********************************************************************************************************************/
/*! \brief       Prepares the buffer for the first payload write step according to the instance status
 *  \details     -
 *  \param[in]   ctx               Instance context
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_PreparePayloadStartBuffer(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SecureInstanceStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SecureInstanceStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType sealMarkerOffset;
    Fee_30_FlexNor_LengthType commitMarkerOffset;

    sealMarkerOffset = Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset(ctx->PartitionConfig->PageAlignment);
    commitMarkerOffset = Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment);

    ctx->Instance.StartMarker = Fee_30_FlexNor_Shared_GetMarker(ctx->InstanceBuffer, 0); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Instance.SealMarker = Fee_30_FlexNor_Shared_GetMarker(ctx->InstanceBuffer, sealMarkerOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Instance.CommitMarker = Fee_30_FlexNor_Shared_GetMarker(ctx->InstanceBuffer, commitMarkerOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 alignedStartMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_StartMarker), pageAlignment);
    uint32 alignedStartAndSealMarkerSize = Fee_30_FlexNor_Shared_Align(alignedStartMarkerSize + sizeof(Fee_30_FlexNor_SealMarker), interferenceFreeAlignment);
    uint32 alignedCommitMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_CommitMarker), interferenceFreeAlignment);
    
    return alignedStartAndSealMarkerSize + alignedCommitMarkerSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset(uint16 pageAlignment)
{
    return Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_StartMarker), pageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(uint16 pageAlignment)
{
    uint32 sealMarkerOffset = Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset(pageAlignment);
    return Fee_30_FlexNor_Shared_Align(sealMarkerOffset + sizeof(Fee_30_FlexNor_SealMarker), pageAlignment);
}


/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_PreparePayloadStartBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_PreparePayloadStartBuffer(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
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
 * Fee_30_FlexNor_SecureInstance_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Init(void)
{
    Fee_30_FlexNor_SecureInstanceStmContext.InstanceBuffer = Fee_30_FlexNor_SecureInstanceBuffer;    
    Fee_30_FlexNor_SecureInstance_InitState(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_GetTotalSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_GetTotalSize(Fee_30_FlexNor_ConstInstanceDataPtrType instance)
{
    uint32 totalSize;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;    
    
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    totalSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(partitionConfig->PageAlignment, partitionConfig->InterferenceFreeAlignment);
    totalSize += Fee_30_FlexNor_Shared_Align(instance->PayloadSize + 1u, partitionConfig->InterferenceFreeAlignment);
    return totalSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Validate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Validate(Fee_30_FlexNor_InstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.InstanceData = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.ResultCallback = resultCbk;
    
    Fee_30_FlexNor_SecureInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_Validate_Initialize(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Write()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Write(Fee_30_FlexNor_ConstInstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.ConstInstanceData = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.PayloadWritten = 0;
    Fee_30_FlexNor_SecureInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_Write_Initialize(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadContent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadContent(Fee_30_FlexNor_InstanceDataPtrType instance, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SecureInstanceStmContext.Instance.InstanceData = instance;
    Fee_30_FlexNor_SecureInstanceStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SecureInstanceStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(instance->PartitionId);

    Fee_30_FlexNor_SecureInstance_ReadContent_Initialize(&Fee_30_FlexNor_SecureInstanceStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SecureInstance_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType metadataLength;
    metadataLength = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, metadataLength, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress, 
        ctx->InstanceBuffer, 
        metadataLength, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata()
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
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_MarkerType erasedMarker;
    Fee_30_FlexNor_SecureInstance_ParseInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

     erasedMarker = Fee_30_FlexNor_Shared_GetEmptyMarker(ctx->PartitionConfig->ErasedValue);

    if(ctx->Instance.StartMarker == erasedMarker)
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if(ctx->Instance.StartMarker == Fee_30_FlexNor_StartMarker)
    {
        if(ctx->Instance.CommitMarker == erasedMarker)
        {
            ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
        else if (ctx->Instance.CommitMarker == Fee_30_FlexNor_CommitMarker)
        {
            ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }            
        else
        {
            Fee_30_FlexNor_Evt_TriggerGarbageCollection(ctx->PartitionConfig->PartitionId);
            ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }            
    }
    else
    {
        ctx->Instance.InstanceData->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }        
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize;    
    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_StartMarker), ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMarkerSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_StartMarker, ctx->InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress, 
        ctx->InstanceBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayloadStart()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayloadStart(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);
    Fee_30_FlexNor_AddressType targetAddress = ctx->Instance.ConstInstanceData->StartAddress + metadataSize;

    Fee_30_FlexNor_SecureInstance_PreparePayloadStartBuffer(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        targetAddress, 
        ctx->InstanceBuffer, 
        ctx->PartitionConfig->PageAlignment, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType metadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);
    Fee_30_FlexNor_AddressType targetAddress = ctx->Instance.ConstInstanceData->StartAddress + metadataSize + ctx->PayloadWritten + 1u;
    Fee_30_FlexNor_LengthType leftPayloadSize = ctx->Instance.ConstInstanceData->PayloadSize - ctx->PayloadWritten;

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        targetAddress, 
        &(ctx->Instance.ConstInstanceData->WriteBuffer[ctx->PayloadWritten]), 
        leftPayloadSize, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    ctx->PayloadWritten += leftPayloadSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize; 
    Fee_30_FlexNor_LengthType sealMarkerOffset;

    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_SealMarker), ctx->PartitionConfig->PageAlignment);
    sealMarkerOffset = Fee_30_FlexNor_SecureInstance_GetSealMarkerOffset(ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMarkerSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_SealMarker, ctx->InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress + sealMarkerOffset, 
        ctx->InstanceBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize;
    Fee_30_FlexNor_LengthType commitMarkerOffset;
    
    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_CommitMarker), ctx->PartitionConfig->PageAlignment);
    commitMarkerOffset = Fee_30_FlexNor_SecureInstance_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMarkerSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_CommitMarker, ctx->InstanceBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Instance.ConstInstanceData->PartitionId,
        ctx->Instance.ConstInstanceData->StartAddress + commitMarkerOffset, 
        ctx->InstanceBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMetadataSize;
    alignedMetadataSize = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->InstanceBuffer, alignedMetadataSize, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress + alignedMetadataSize,  
        ctx->InstanceBuffer, 
        ctx->PartitionConfig->PageAlignment,
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ParseInstanceStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ParseInstanceStatus(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
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
 * Fee_30_FlexNor_SecureInstance_ReadPayload()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType contentOffset;
    contentOffset = Fee_30_FlexNor_SecureInstance_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment) + 1u;

    Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(ctx->Instance.InstanceData->PartitionId,
        ctx->Instance.InstanceData->StartAddress + contentOffset + ctx->Instance.InstanceData->PayloadOffset, 
        ctx->Instance.InstanceData->ReadBuffer, 
        (ctx->Instance.InstanceData->PayloadSize),
        &Fee_30_FlexNor_SecureInstance_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstance.c
 *********************************************************************************************************************/
