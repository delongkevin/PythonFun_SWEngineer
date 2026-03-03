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
/*!        \file  Fee_30_FlexNor_SlimChunk.c
 *        \brief  Slim chunk unit implementation
 *      \details  Implementation of the chunk services based on the slim chunk layout.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMCHUNK_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimChunk.h"
#include "Fee_30_FlexNor_SlimChunkInternal.h"
#include "Fee_30_FlexNor_SlimChunkMachine.h"
#include "Fee_30_FlexNor_ChunkInternal.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_InstanceFactory.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_Shared.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SLIMCHUNKHEADER_RESERVED_INDEX 0x06u

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SlimChunk_ContextType Fee_30_FlexNor_SlimChunkStmContext;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DataType Fee_30_FlexNor_SlimChunkBuffer[FEE_30_FLEXNOR_CHUNKBUFFER_SIZE]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_SlimChunk_GetAlignedLinkSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the chunk link
 *  \details     -
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the chunk link 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedLinkSize(uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize()
 *********************************************************************************************************************/
/*! \brief       Gets the accumulated unaligend size of the chunk properties.
 *  \details     -
 *  \return      The aligned size of the header data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*! \brief       Gets the offset of the commit marker relative to the chunk's start address
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \return      The commit marker offset in bytes
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset(uint16 pageAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the metadata. Does not contain the chunk link.
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the metadata
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize()
 *********************************************************************************************************************/
/*! \brief       Gets the aligned size of the header. Contains the metadata and the chunk link.
 *  \details     -
 *  \param[in]   pageAlignment               Page alignment in bytes
 *  \param[in]   interferenceFreeAlignment   Interference free alignment in bytes
 *  \return      The aligned size of the header
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize(uint16 pageAlignment, uint16 interferenceFreeAlignment);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseProperties()
 *********************************************************************************************************************/
/*! \brief       Parses the chunk properties from the given chunk buffer.
 *  \details     -
 *  \param[in]   ctx               Context that contains the buffer where the chunk properties are parsed from. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseChunkMetadata()
 *********************************************************************************************************************/
/*! \brief       Parses the metadata of the given context and saves the value of the read markers.
 *  \details     -
 *  \param[in]   ctx               Context the chunk header shall be parsed in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseChunkMetadata(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidatePropertiesChecksum()
 *********************************************************************************************************************/
/*! \brief       Validates the chunk properties checksum
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk buffer that is used for the checksum validation. Must not be NULL.
 *  \return      E_OK              The read checksum in the buffer matches the calculated checksum over the properties
 *               E_NOT_OK          The read checksum doesn't match the calculates checksum
 *  \pre         Chunk header must already be read from flash
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidatePropertiesChecksum(Fee_30_FlexNor_SlimChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateLinkChecksum()
 *********************************************************************************************************************/
/*! \brief       Validates the chunk links checksum.
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk buffer that is used for the checksum validation. Must not be NULL.
 *  \return      E_OK              The read checksum in the buffer matches the calculated checksum over the chunk link
 *               E_NOT_OK          The read checksum doesn't match the calculates checksum
 *  \pre         Chunk header must already be read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateLinkChecksum(Fee_30_FlexNor_SlimChunk_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_SetChunkPropertiesToBuffer()
 *********************************************************************************************************************/
/*! \brief       Copies BlockId, PayloadSize and Instance Count to their proprer position in the chunk buffer.
 *  \details     -
 *  \param[in]   ctx               Context of the chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_SetChunkPropertiesToBuffer(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseChunkLink()
 *********************************************************************************************************************/
/*! \brief       Parses the chunk link from a given chunk buffer.
 *  \details     -
 *  \param[in]   ctx               Context that contains the buffer where the chunk link is parsed from. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseChunkLink(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetAlignedLinkSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedLinkSize(uint16 interferenceFreeAlignment)
{
    return Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_ChunkLocationType) + 
        sizeof(Fee_30_FlexNor_ChecksumType), interferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize(void)
{
    return sizeof(Fee_30_FlexNor_BlockIdType) + 
           sizeof(Fee_30_FlexNor_PayloadSizeType) + 
           sizeof(Fee_30_FlexNor_InstanceCountType) + 
           sizeof(uint8) + /* Reserved byte */
           sizeof(Fee_30_FlexNor_ChecksumType);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 chunkPropertiesSize = Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize();
    uint32 alignedPropertiesSize = Fee_30_FlexNor_Shared_Align(chunkPropertiesSize, pageAlignment);

    return Fee_30_FlexNor_Shared_Align(alignedPropertiesSize + sizeof(Fee_30_FlexNor_CommitMarker), interferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize(uint16 pageAlignment, uint16 interferenceFreeAlignment)
{
    uint32 alignedMetadataSize = Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize(pageAlignment, interferenceFreeAlignment);
    uint32 alignedLinkSize = Fee_30_FlexNor_SlimChunk_GetAlignedLinkSize(interferenceFreeAlignment);
    return alignedMetadataSize + alignedLinkSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL_INLINE FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset(uint16 pageAlignment)
{
    uint32 chunkPropertiesSize = Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize();
    return Fee_30_FlexNor_Shared_Align(chunkPropertiesSize, pageAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_ChunkDataPtrType genericChunk = &ctx->Chunk.GenericChunk->Data;

    Fee_30_FlexNor_AddressType blockIdBeginOffset = 0;
    Fee_30_FlexNor_AddressType payloadSizeBeginOffset = blockIdBeginOffset + sizeof(Fee_30_FlexNor_BlockIdType);
    Fee_30_FlexNor_AddressType instanceCountBeginOffset = payloadSizeBeginOffset + sizeof(Fee_30_FlexNor_PayloadSizeType);
    Fee_30_FlexNor_AddressType metadataChecksumBeginOffset = instanceCountBeginOffset + sizeof(Fee_30_FlexNor_InstanceCountType) + sizeof(uint8); /* Reserved byte */

    genericChunk->BlockId = (Fee_30_FlexNor_BlockIdType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_BlockIdType), 
        blockIdBeginOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    genericChunk->PayloadSize = (Fee_30_FlexNor_PayloadSizeType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer,
        sizeof(Fee_30_FlexNor_PayloadSizeType), 
        payloadSizeBeginOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    genericChunk->InstanceCount = (Fee_30_FlexNor_InstanceCountType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_InstanceCountType), 
        instanceCountBeginOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        
    ctx->Chunk.MetadataChecksum = (Fee_30_FlexNor_ChecksumType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_ChecksumType), 
        metadataChecksumBeginOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_SlimChunk_ParseChunkLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseChunkMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseChunkMetadata(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType commitMarkerOffset = Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment);

    ctx->Chunk.CommitMarker = Fee_30_FlexNor_Shared_GetMarker(ctx->ChunkBuffer, commitMarkerOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_SlimChunk_ParseProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidatePropertiesChecksum()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidatePropertiesChecksum(Fee_30_FlexNor_SlimChunk_ConstContextPtrType ctx)
{
    Std_ReturnType checkResult = E_NOT_OK;

    Fee_30_FlexNor_LengthType propertiesOffset = 0; /* 0 according to the memory layout */
    Fee_30_FlexNor_LengthType propertiesLengthWithoutChecksum = (Fee_30_FlexNor_LengthType)Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize() - sizeof(Fee_30_FlexNor_ChecksumType);

    Fee_30_FlexNor_ChecksumType calculatedChecksum = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->ChunkBuffer, propertiesLengthWithoutChecksum, propertiesOffset); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(ctx->Chunk.MetadataChecksum == calculatedChecksum)
    {
        checkResult = E_OK;
    }

    return checkResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateLinkChecksum()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateLinkChecksum(Fee_30_FlexNor_SlimChunk_ConstContextPtrType ctx)
{
    Std_ReturnType checkResult = E_NOT_OK;
    Fee_30_FlexNor_LengthType linkOffset = Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);
    
    Fee_30_FlexNor_ChecksumType calculatedChecksum = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->ChunkBuffer, sizeof(Fee_30_FlexNor_ChunkLocationType), linkOffset); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if(ctx->Chunk.ChunklinkChecksum == calculatedChecksum)
    {
        checkResult = E_OK;
    }

    return checkResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SlimChunkStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SlimChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SlimChunkStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SlimChunkStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_SetChunkPropertiesToBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_SetChunkPropertiesToBuffer(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    /* Set the chunk properties to the buffer */
    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Chunk.ConstGenericChunk->Data.BlockId, 
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_BlockIdType),
        0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Chunk.ConstGenericChunk->Data.PayloadSize, 
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_PayloadSizeType), 
        sizeof(Fee_30_FlexNor_BlockIdType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Chunk.ConstGenericChunk->Data.InstanceCount, 
        ctx->ChunkBuffer, 
        sizeof(Fee_30_FlexNor_InstanceCountType), 
        sizeof(Fee_30_FlexNor_BlockIdType) + sizeof(Fee_30_FlexNor_PayloadSizeType)); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ParseChunkLink()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ParseChunkLink(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_ChunkDataPtrType genericChunk = &ctx->Chunk.GenericChunk->Data;
        
    uint32 chunklinkOffsetBegin = Fee_30_FlexNor_SlimChunk_GetAlignedMetadataSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);
    uint32 chunklinkChecksumBeginOffset = chunklinkOffsetBegin + sizeof(Fee_30_FlexNor_ChunkLocationType);

    if(Fee_30_FlexNor_Shared_IsErased(&ctx->ChunkBuffer[chunklinkOffsetBegin], 
        ctx->PartitionConfig->InterferenceFreeAlignment, 
        ctx->PartitionConfig->ErasedValue) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    {
        ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else 
    {
        genericChunk->ChunkLink.Target = (Fee_30_FlexNor_ChunkLocationType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer, 
            sizeof(Fee_30_FlexNor_ChunkLocationType), 
            chunklinkOffsetBegin); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        ctx->Chunk.ChunklinkChecksum = (Fee_30_FlexNor_ChecksumType)Fee_30_FlexNor_Shared_GetValueFromBuffer(ctx->ChunkBuffer, 
            sizeof(Fee_30_FlexNor_ChecksumType), 
            chunklinkChecksumBeginOffset); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

        if(Fee_30_FlexNor_SlimChunk_ValidateLinkChecksum(ctx) == E_OK) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
        {
            ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
        else 
        {
            ctx->Chunk.GenericChunk->Data.ChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
    }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Init(void)
{
    Fee_30_FlexNor_SlimChunkStmContext.ChunkBuffer = Fee_30_FlexNor_SlimChunkBuffer;    
    Fee_30_FlexNor_SlimChunk_InitState(&Fee_30_FlexNor_SlimChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_SlimChunk_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadHeader()
 *********************************************************************************************************************/
 /*! 
 * Internal comment removed. *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadHeader(
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimChunkStmContext.Chunk.GenericChunk = chunk;
    Fee_30_FlexNor_SlimChunkStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimChunkStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);

    Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize(&Fee_30_FlexNor_SlimChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckInstanceValidity()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckInstanceValidity(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(ctx->Instance.Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded(ctx->PartitionConfig->PartitionId);
    }
    else
    {
        Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded(ctx->PartitionConfig->PartitionId);
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader()
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
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType headerLength;
    Std_ReturnType validationComplete = E_OK;
    Fee_30_FlexNor_ChunkDataPtrType genericChunkDataPtr = &ctx->Chunk.GenericChunk->Data;

    headerLength = Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    /* Empty chunk header */
    if(Fee_30_FlexNor_Shared_IsErased(ctx->ChunkBuffer, headerLength, ctx->PartitionConfig->ErasedValue) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    {
        genericChunkDataPtr->Validity = FEE_30_FLEXNOR_EMPTY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        genericChunkDataPtr->ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else 
    {
        Fee_30_FlexNor_MarkerType erasedMarker;
        erasedMarker = Fee_30_FlexNor_Shared_GetEmptyMarker(ctx->PartitionConfig->ErasedValue);

        Fee_30_FlexNor_SlimChunk_ParseChunkMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(ctx->Chunk.CommitMarker == Fee_30_FlexNor_CommitMarker)
        {
            /* Valid commit marker */
            genericChunkDataPtr->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            genericChunkDataPtr->ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_NOERROR; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
        else if (ctx->Chunk.CommitMarker == erasedMarker)
        {
            /* Commit marker empty */
            genericChunkDataPtr->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            genericChunkDataPtr->ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            
            if(Fee_30_FlexNor_SlimChunk_ValidatePropertiesChecksum(ctx) == E_OK) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
            {
                /* Metadata is valid */
                validationComplete = E_NOT_OK;
                genericChunkDataPtr->ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
            else 
            {
                /* Metadata is invalid */
                Fee_30_FlexNor_Evt_TriggerGarbageCollectionExcluded(ctx->PartitionConfig->PartitionId);
            }
        }
        else
        {
            /* Commit marker invalid */
            genericChunkDataPtr->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            genericChunkDataPtr->ErrorLocation = FEE_30_FLEXNOR_CHUNK_ERROR_COMMITMARKER; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            Fee_30_FlexNor_Evt_TriggerGarbageCollectionIncluded(ctx->PartitionConfig->PartitionId);
        }
    }
    return validationComplete;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadChunkHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadChunkHeader(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType headerLength;
    headerLength = Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize(ctx->PartitionConfig->PageAlignment, ctx->PartitionConfig->InterferenceFreeAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, headerLength, 0x0); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Chunk.GenericChunk->Data.PartitionId,
        ctx->Chunk.GenericChunk->Data.StartAddress, 
        ctx->ChunkBuffer, 
        headerLength, 
        &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetHeaderSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetHeaderSize(
    Fee_30_FlexNor_ConstChunkPtrType chunk)
{
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfigPtr;
    partitionConfigPtr = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);
    return Fee_30_FlexNor_SlimChunk_GetAlignedHeaderSize(partitionConfigPtr->PageAlignment, partitionConfigPtr->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_GetTotalSize()
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
FUNC(uint32, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_GetTotalSize(Fee_30_FlexNor_ConstChunkPtrType chunk)
{
    uint32 totalChunkSize;
    uint32 alignedHeaderSize = Fee_30_FlexNor_SlimChunk_GetHeaderSize(chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithGivenPointer */;

    if(chunk->Data.Validity == FEE_30_FLEXNOR_EMPTY)
    {
        totalChunkSize = 0u;
    }
    else if(chunk->Data.ErrorLocation == FEE_30_FLEXNOR_CHUNK_ERROR_PROPERTIES)
    {
        totalChunkSize = alignedHeaderSize;
    }
    else
    {
        Fee_30_FlexNor_InstanceType instance;
        Fee_30_FlexNor_InstanceFactory_CreateInstance(0x0, chunk->Data.PartitionId, &instance); /* SBSW_Fee_30_FlexNor_FunctionCallWithPointerToLocal */
        instance.Data.PayloadSize = chunk->Data.PayloadSize;
        totalChunkSize = alignedHeaderSize + (chunk->Data.InstanceCount * instance.Services.GetTotalSize(&instance.Data)); /* SBSW_Fee_30_FlexNor_FunctionPointerCallFromCreatedObject */
    }

    return totalChunkSize;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Allocate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Allocate(
    Fee_30_FlexNor_ConstChunkPtrType chunk, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk, 
    Fee_30_FlexNor_InstancePtrType instanceToWrite, 
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SlimChunkStmContext.Chunk.ConstGenericChunk = chunk;
    Fee_30_FlexNor_SlimChunkStmContext.PredecessorChunk = predecessorChunk;
    Fee_30_FlexNor_SlimChunkStmContext.InstanceToWrite = instanceToWrite;
    Fee_30_FlexNor_SlimChunkStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_SlimChunkStmContext.PartitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(chunk->Data.PartitionId);

    Fee_30_FlexNor_SlimChunk_Allocate_Initialize(&Fee_30_FlexNor_SlimChunkStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType propertiesSize;
    Fee_30_FlexNor_LengthType alignedPropertiesSize;
    Fee_30_FlexNor_LengthType checksumOffset;

    propertiesSize = Fee_30_FlexNor_SlimChunk_GetChunkPropertiesSize();
    alignedPropertiesSize = Fee_30_FlexNor_Shared_Align(propertiesSize, ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, alignedPropertiesSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_SlimChunk_SetChunkPropertiesToBuffer(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Explicitly set the reserved byte to zero */
    ctx->ChunkBuffer[FEE_30_FLEXNOR_SLIMCHUNKHEADER_RESERVED_INDEX] = 0x0u; /* SBSW_Fee_30_FlexNor_ModifyContextArray */ 

    /* Calculate and set the checksum */
    checksumOffset = sizeof(Fee_30_FlexNor_BlockIdType) + sizeof(Fee_30_FlexNor_PayloadSizeType) + sizeof(Fee_30_FlexNor_InstanceCountType) + 1u; /* +1u because of the reserved byte */

    /* The checksum offset acts as the length for the checksum calculation because all previous data shall be included in the checksum. */
    ctx->ChunkBuffer[checksumOffset] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->ChunkBuffer, checksumOffset, 0); /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    /* Write properties to flash */
    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Chunk.ConstGenericChunk->Data.PartitionId, 
        ctx->Chunk.ConstGenericChunk->Data.StartAddress, 
        ctx->ChunkBuffer,
        alignedPropertiesSize,
        &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType commitMarkerOffset;
    Fee_30_FlexNor_LengthType alignedCommitMarkerSize;
    commitMarkerOffset = Fee_30_FlexNor_SlimChunk_GetCommitMarkerOffset(ctx->PartitionConfig->PageAlignment);
    alignedCommitMarkerSize = Fee_30_FlexNor_Shared_Align(sizeof(Fee_30_FlexNor_CommitMarker), ctx->PartitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetBufferValues(ctx->ChunkBuffer, alignedCommitMarkerSize, ctx->PartitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_CommitMarker, ctx->ChunkBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Chunk.ConstGenericChunk->Data.PartitionId,
        ctx->Chunk.ConstGenericChunk->Data.StartAddress + commitMarkerOffset, 
        ctx->ChunkBuffer, 
        ctx->PartitionConfig->PageAlignment, 
        &Fee_30_FlexNor_SlimChunk_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunk.c
 *********************************************************************************************************************/
