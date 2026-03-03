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
/*!        \file  Fee_30_FlexNor_Sector.c
 *        \brief  Sector unit implementation
 *      \details  Implementation of the sector services.
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
#include "Fee_30_FlexNor_Sector.h"
#include "Fee_30_FlexNor_SectorInternal.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_SectorMachine.h"

#include "Fee_30_FlexNor_ChunkFactory.h"
#include "Fee_30_FlexNor_Shared.h"
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_LookupTable.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECTORHEADER_SECTORID_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_GCREASON_SIZE_IN_BITS 2u
#define FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS 2u
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE 7u              /*!< Properties include Sector Id, erase cycle counter, 4 reserved bits, gc reason and layout type */
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_COMMITMARKER_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE 4u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE 1u
#define FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE 1u

/* Indices of the single parts in the buffer after the sector header meta data was read in */

/* Indices inside the first write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX 0u
#define FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX 1u
#define FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX 5u
#define FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX 6u

/* Indices inside the second write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_INDEX 0u

/* Indices inside the third write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_COMMITMARKER_INDEX 0u

/* Indices of the single parts in the buffer after the sector header additional info was read in */

/* Indices inside the first write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX 0u
#define FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX 4u

/* Indices inside the second write alignment */
#define FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_INDEX 0u

#define FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK 3u  /* Both informations are 2 bits, so we need a mask with lowest 2 bits set */

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_Sector_ContextType Fee_30_FlexNor_SectorStmContext;
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_ChunkType Fee_30_FlexNor_Chunk; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_DataType Fee_30_FlexNor_SectorHeaderBuffer[FEE_30_FLEXNOR_SECTORBUFFER_SIZE]; /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */

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
 * Fee_30_FlexNor_Sector_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*! \brief       Computes the aligned length of the meta data part of the sector header
 *  \details     -
 *  \param[in]   sector Sector whose meta data size shall be computed.
 *  \return      Aligned length of the meta data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedMetadataSize(
    Fee_30_FlexNor_ConstSectorPtrType sector);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataProperties()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data first alignment part previously read from flash.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data erase marker part previously read from flash.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker()
 *********************************************************************************************************************/
/*! \brief          Validates the sector header meta data commit marker previously read from flash.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink()
 *********************************************************************************************************************/
/*! \brief          Parses the lookup table link from the read additional sector data
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre            Sector header additional info must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector()
 *********************************************************************************************************************/
/*! \brief          Parses the source sector id from the read additional sector data
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre            Sector header additional info must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateGcReason()
 *********************************************************************************************************************/
/*! \brief          Tries to parse the GcReason.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateGcReason(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateLayoutType()
 *********************************************************************************************************************/
/*! \brief          Tries to parse the LayoutType.
 *  \details        -
 *  \param[in,out]  ctx            Context that contains the read sector header meta data. Must not be NULL.
 *  \return         Result of the validation (see enum Fee_30_FlexNor_StructureValidityType).
 *  \pre            Sector header meta data must have been read from flash.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateLayoutType(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessingHandler()
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
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReached()
 *********************************************************************************************************************/
/*! \brief       Checks if the end of the sector was reached with the next free address
 *  \details     The end was reached if no chunk would fit into the space between next free address and sector end anymore.
 *  \param[in]   ctx        Context that contains the chunk the end check shall be executed for. Must not be NULL.
 *  \return      TRUE       The end of the sector was reached with the next free address.
 *               FALSE      There could still fit a chunk between the next free address and the sector end. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReached(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetInstanceCount()
 *********************************************************************************************************************/
/*! \brief       Calculates the instance count for the chunk that shall be allocated.
 *  \details     -
 *  \param[in]   ctx        The context that contains the required information for the instance count calculation.
 *                          Must not be NULL.
 *  \return      The instance count of the chunk that shall be allocated
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_InstanceCountType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetInstanceCount(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedMetadataSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedMetadataSize(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_LengthType alignedPropertiesSize, alignedEraseMarkerSize, alignedCommitMarkerSize, totalSize;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;

    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);
    alignedPropertiesSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);
    alignedEraseMarkerSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE, partitionConfig->PageAlignment);
    alignedCommitMarkerSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_COMMITMARKER_SIZE, partitionConfig->PageAlignment);
    totalSize = alignedPropertiesSize + alignedEraseMarkerSize + alignedCommitMarkerSize;

    return Fee_30_FlexNor_Shared_Align(totalSize, partitionConfig->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_LengthType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(
    Fee_30_FlexNor_ConstSectorPtrType sector)
{
    Fee_30_FlexNor_LengthType alignedLutLinkSize, alignedSourceSectorSize, totalSize;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(sector->PartitionId);

    alignedLutLinkSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE + FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE, 
        partitionConfig->PageAlignment);

    alignedSourceSectorSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE, partitionConfig->PageAlignment);

    totalSize = alignedLutLinkSize + alignedSourceSectorSize;

    return Fee_30_FlexNor_Shared_Align(totalSize, partitionConfig->InterferenceFreeAlignment);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateGcReason()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateGcReason(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint8 value;
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_VALID;
    
    value = (ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] >> FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS) & 
            FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK;

    if(value == (uint8)FEE_30_FLEXNOR_GC_REASON_SPACE)
    {
        ctx->Sector->GcReason = FEE_30_FLEXNOR_GC_REASON_SPACE; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if (value == (uint8)FEE_30_FLEXNOR_GC_REASON_RECOVERY)
    {
        ctx->Sector->GcReason = FEE_30_FLEXNOR_GC_REASON_RECOVERY; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        retVal = FEE_30_FLEXNOR_INVALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateLayoutType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateLayoutType(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    uint8 value;
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_VALID;

    value = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] & FEE_30_FLEXNOR_SECTORHEADER_GCREASONLAYOUTYPE_MASK;

    if(value == (uint8)FEE_30_FLEXNOR_SECURELAYOUT)
    {
        ctx->Sector->Layout = FEE_30_FLEXNOR_SECURELAYOUT; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else if (value == (uint8)FEE_30_FLEXNOR_SLIMLAYOUT)
    {
        ctx->Sector->Layout = FEE_30_FLEXNOR_SLIMLAYOUT; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        retVal = FEE_30_FLEXNOR_INVALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataProperties(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChecksumType checksum;
    Fee_30_FlexNor_ChecksumType checksumExpected;
    Fee_30_FlexNor_StructureValidityType gcReasonValidationResult;
    Fee_30_FlexNor_StructureValidityType layoutTypeValidationResult;
    Fee_30_FlexNor_StructureValidityType retVal = FEE_30_FLEXNOR_VALID;
    
    ctx->Sector->SectorId = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->Sector->EraseCycle = Fee_30_FlexNor_Shared_GetMarker(ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    checksum = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX];
    checksumExpected = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer, /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
                FEE_30_FLEXNOR_SECTORHEADER_SECTORID_SIZE + FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE + FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_SIZE, 
                FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX);

    gcReasonValidationResult = Fee_30_FlexNor_Sector_ValidateGcReason(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    layoutTypeValidationResult = Fee_30_FlexNor_Sector_ValidateLayoutType(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    if((gcReasonValidationResult == FEE_30_FLEXNOR_INVALID) || 
       (layoutTypeValidationResult == FEE_30_FLEXNOR_INVALID) || 
       (checksum != checksumExpected))
    {
        retVal = FEE_30_FLEXNOR_INVALID;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker()
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
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_MarkerType emptyMarker;
    Fee_30_FlexNor_MarkerType eraseMarkerInFlash;
    Fee_30_FlexNor_AddressType alignedEraseMarkerStartIndex;
    Fee_30_FlexNor_StructureValidityType eraseMarkerValidity;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedEraseMarkerStartIndex = Fee_30_FlexNor_Shared_Align(
        FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);

    eraseMarkerInFlash = Fee_30_FlexNor_Shared_GetMarker(ctx->SectorBuffer, alignedEraseMarkerStartIndex); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    emptyMarker = Fee_30_FlexNor_Shared_GetEmptyMarker(partitionConfig->ErasedValue);

    if(eraseMarkerInFlash == emptyMarker)
    {
        eraseMarkerValidity = FEE_30_FLEXNOR_EMPTY;
    }
    else if(eraseMarkerInFlash == Fee_30_FlexNor_EraseMarker)
    {
        eraseMarkerValidity = FEE_30_FLEXNOR_VALID;
    }
    else
    {
        eraseMarkerValidity = FEE_30_FLEXNOR_INVALID;
    }
    

    return eraseMarkerValidity;    
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_StructureValidityType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType alignedEraseMarkerStartIndex;
    Fee_30_FlexNor_AddressType alignedCommitMarkerStartIndex;
    Fee_30_FlexNor_MarkerType commitMarkerInFlash;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedEraseMarkerStartIndex = Fee_30_FlexNor_Shared_Align(
        FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);

    alignedCommitMarkerStartIndex = alignedEraseMarkerStartIndex + Fee_30_FlexNor_Shared_Align(
        FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE, partitionConfig->PageAlignment);

    commitMarkerInFlash = Fee_30_FlexNor_Shared_GetMarker(ctx->SectorBuffer, alignedCommitMarkerStartIndex); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    return (commitMarkerInFlash == Fee_30_FlexNor_CommitMarker) ? FEE_30_FLEXNOR_VALID : FEE_30_FLEXNOR_INVALID;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChecksumType checksum;

    ctx->Sector->LutChunkLink.Target = Fee_30_FlexNor_Shared_GetMarker(ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    checksum = ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX];

    if(checksum == Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE, FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX)) /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    {
        ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    else
    {
        ctx->Sector->LutChunkLink.Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType alignedSourceSectorStartIndex;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedSourceSectorStartIndex = Fee_30_FlexNor_Shared_Align(
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE + FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE, partitionConfig->PageAlignment);

    ctx->Sector->SourceSectorId = ctx->SectorBuffer[alignedSourceSectorStartIndex]; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ProcessingHandler(void)
{
    return Fee_30_FlexNor_SectorStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResultHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResultHandler(Fee_30_FlexNor_ServiceResult result)
{
    if(result == FEE_30_FLEXNOR_SERVICE_FAIL)
    {
        Fee_30_FlexNor_SectorStmContext.CurrentState->FailEvent(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndReached()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndReached(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean endReached = TRUE;
    Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(ctx->Sector->PartitionId, ctx->Sector->StartAddress);
    Fee_30_FlexNor_AddressType sectorEndAddress = ctx->Sector->StartAddress + sectorLength;
    uint32 chunkHeaderSize = ctx->Chunk->Services.GetHeaderSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    
    if((ctx->Sector->NextFreeAddress + chunkHeaderSize) < sectorEndAddress)
    {
        endReached = FALSE;
    }

    return endReached;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_GetInstanceCount()
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
FUNC(Fee_30_FlexNor_InstanceCountType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_GetInstanceCount(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_InstanceCountType targetInstanceCount = 1u;

    if(ctx->PredecessorChunk != NULL_PTR)
    {
        targetInstanceCount = ctx->PredecessorChunk->Data.InstanceCount + 1u;
        
        if(ctx->Sector->SectorId != ctx->PredecessorChunk->Data.SectorId)
        {
            targetInstanceCount = targetInstanceCount / 2u;
        }
    }
    
    return targetInstanceCount;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Init(void)
{
    Fee_30_FlexNor_SectorStmContext.SectorBuffer = Fee_30_FlexNor_SectorHeaderBuffer;
    Fee_30_FlexNor_SectorStmContext.Chunk = &Fee_30_FlexNor_Chunk;
    Fee_30_FlexNor_Sector_InitState(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_IsUsed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_IsUsed(Fee_30_FlexNor_ConstSectorPtrType sector)
{
    return (sector->Validity == FEE_30_FLEXNOR_VALID) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_Sector_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadHeader(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_ReadHeader_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMetadataLength = Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        ctx->Sector->StartAddress, 
        ctx->SectorBuffer, 
        alignedMetadataLength, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadata()
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
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ErrorLocation metadataErrorLocation;
    Fee_30_FlexNor_StructureValidityType partialValidationResult;

    partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataProperties(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(partialValidationResult == FEE_30_FLEXNOR_VALID)
    {
        partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        if(partialValidationResult == FEE_30_FLEXNOR_VALID)
        {
            partialValidationResult = Fee_30_FlexNor_Sector_ValidateMetadataEraseMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

            if(partialValidationResult == FEE_30_FLEXNOR_EMPTY)
            {
                metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_NOERROR;
                ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
            else
            {
                metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_ERASEMARKERSET;
                ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
            }
        }
        else
        {
            metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_COMMITMARKERBROKEN;
            ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        }
    }
    else
    {
        metadataErrorLocation = FEE_30_FLEXNOR_SECTOR_ERROR_PROPERTIESINVALID;
        ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    }
    
    ctx->Sector->ErrorLocation = metadataErrorLocation; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    return metadataErrorLocation;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType startAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_LengthType alignedAdditionalInfoLength = Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_ReadFlash(ctx->Sector->PartitionId,
        startAddress, 
        ctx->SectorBuffer, 
        alignedAdditionalInfoLength, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateAdditionalInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx)
{
    Fee_30_FlexNor_Sector_ParseAdditionalInfoLutLink(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    Fee_30_FlexNor_Sector_ParseAdditionalInfoSourceSector(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadFirstChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadFirstChunk(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType firstChunkStartAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector) + /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_ChunkFactory_CreateChunk(firstChunkStartAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Chunk->Services.ReadHeader(ctx->Chunk, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateFirstChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateFirstChunk(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    boolean firstChunkValid = FALSE;
    ctx->Sector->Validity = FEE_30_FLEXNOR_INVALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    if(ctx->Chunk->Data.Validity == FEE_30_FLEXNOR_VALID)
    {
        /* A garbage collection needs to be triggered because the sector contains valid data but the commit marker is invalid. */
        Fee_30_FlexNor_Evt_TriggerGarbageCollection(ctx->Sector->PartitionId);
        ctx->Sector->Validity = FEE_30_FLEXNOR_VALID; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        firstChunkValid = TRUE;
    }

    return firstChunkValid;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarker()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteEraseMarker(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteEraseMarker_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize;
    Fee_30_FlexNor_AddressType eraseMarkerAddress;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE, partitionConfig->PageAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedMarkerSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    eraseMarkerAddress = ctx->Sector->StartAddress + 
        Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetValueToBuffer(Fee_30_FlexNor_EraseMarker, ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        eraseMarkerAddress, 
        ctx->SectorBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLink()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteLutLink(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteLutLink_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLinkToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteLutLinkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedLutLinkSize;
    Fee_30_FlexNor_AddressType lutLinkAddress;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedLutLinkSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE + FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE, partitionConfig->PageAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedLutLinkSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    lutLinkAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Sector->LutChunkLink.Target, ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE, 0u); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_INDEX] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer, /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE,    
        FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_INDEX);

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        lutLinkAddress, 
        ctx->SectorBuffer, 
        alignedLutLinkSize, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_WriteSourceSector(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_WriteSourceSector_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSectorToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedSourceSectorSize;
    Fee_30_FlexNor_AddressType sourceSectorAddress;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedSourceSectorSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_SIZE, partitionConfig->PageAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedSourceSectorSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    sourceSectorAddress = ctx->Sector->StartAddress + 
        Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector) +  /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_LUTLINK_SIZE + FEE_30_FLEXNOR_SECTORHEADER_LUTLINKCHECKSUM_SIZE, partitionConfig->PageAlignment);

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SOURCESECTOR_INDEX] = ctx->Sector->SourceSectorId;    /* SBSW_Fee_30_FlexNor_ModifyContextArray */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        sourceSectorAddress, 
        ctx->SectorBuffer,
        alignedSourceSectorSize, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Allocate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Allocate(Fee_30_FlexNor_SectorPtrType sector, 
    Fee_30_FlexNor_ChunkPtrType firstChunk, 
    Fee_30_FlexNor_InstancePtrType firstInstance, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.Chunk = firstChunk;
    Fee_30_FlexNor_SectorStmContext.PredecessorChunk = predecessorChunk;
    Fee_30_FlexNor_SectorStmContext.Instance = firstInstance;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_Allocate_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_EraseSector(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(ctx->Sector->PartitionId, ctx->Sector->StartAddress);
    Fee_30_FlexNor_FlashAccess_EraseFlash(ctx->Sector->PartitionId, ctx->Sector->StartAddress, sectorLength, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WritePropertiesToMemory()
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
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WritePropertiesToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedProperties;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);
    
    alignedProperties = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedProperties, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX] = ctx->Sector->SectorId; /* SBSW_Fee_30_FlexNor_ModifyContextArray */

    Fee_30_FlexNor_Shared_SetValueToBuffer(ctx->Sector->EraseCycle, ctx->SectorBuffer, FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_SIZE,
        FEE_30_FLEXNOR_SECTORHEADER_ERASECYCLECOUNTER_INDEX); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_MULTIFIELD_INDEX] = ((uint8)ctx->Sector->GcReason << FEE_30_FLEXNOR_SECTORHEADER_TYPE_SIZE_IN_BITS) | /* SBSW_Fee_30_FlexNor_ModifyContextArray */
        (uint8)ctx->Sector->Layout;

    ctx->SectorBuffer[FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_INDEX] = Fee_30_FlexNor_Shared_CalculateChecksum(ctx->SectorBuffer,  /* SBSW_Fee_30_FlexNor_ModifyContextArray */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE - FEE_30_FLEXNOR_SECTORHEADER_PROPERTIESCHECKSUM_SIZE, FEE_30_FLEXNOR_SECTORHEADER_SECTORID_INDEX);

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        ctx->Sector->StartAddress, 
        ctx->SectorBuffer, 
        alignedProperties,
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteFirstChunkToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteFirstChunkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_AddressType firstChunkStartAddress = ctx->Sector->StartAddress + Fee_30_FlexNor_Sector_GetAlignedMetadataSize(ctx->Sector) + /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(ctx->Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->Sector->NextFreeAddress = firstChunkStartAddress; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */

    Fee_30_FlexNor_ChunkFactory_CreateChunk(firstChunkStartAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->Chunk->Data.InstanceCount = Fee_30_FlexNor_Sector_GetInstanceCount(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    ctx->Chunk->Services.Allocate(ctx->Chunk, ctx->PredecessorChunk, ctx->Instance, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx)    /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType alignedMarkerSize;
    Fee_30_FlexNor_AddressType commitMarkerAddress;

    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;
    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    alignedMarkerSize = Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_COMMITMARKER_SIZE, partitionConfig->PageAlignment);
    Fee_30_FlexNor_Shared_SetBufferValues(ctx->SectorBuffer, alignedMarkerSize, partitionConfig->ErasedValue); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    commitMarkerAddress = ctx->Sector->StartAddress + 
        Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_PROPERTIES_SIZE, partitionConfig->PageAlignment) +   
        Fee_30_FlexNor_Shared_Align(FEE_30_FLEXNOR_SECTORHEADER_ERASEMARKER_SIZE, partitionConfig->PageAlignment);

    Fee_30_FlexNor_Shared_SetMarker(Fee_30_FlexNor_CommitMarker, ctx->SectorBuffer); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_FlashAccess_WriteFlash(ctx->Sector->PartitionId,
        commitMarkerAddress, 
        ctx->SectorBuffer, 
        alignedMarkerSize, 
        &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_Scan()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_Scan(Fee_30_FlexNor_SectorPtrType sector, Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_SectorStmContext.Chunk = &Fee_30_FlexNor_Chunk;

    Fee_30_FlexNor_SectorStmContext.Sector->NextFreeAddress = Fee_30_FlexNor_SectorStmContext.Sector->StartAddress + 
        Fee_30_FlexNor_Sector_GetAlignedMetadataSize(Fee_30_FlexNor_SectorStmContext.Sector) + /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        Fee_30_FlexNor_Sector_GetAlignedAdditionalInfoSize(Fee_30_FlexNor_SectorStmContext.Sector); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Sector_Scan_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadChunkHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ChunkFactory_CreateChunk(ctx->Sector->NextFreeAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Chunk->Services.ReadHeader(ctx->Chunk, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessReadChunkHeader()
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
FUNC(Fee_30_FlexNor_Sector_ScanCurrentResult, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ProcessReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx)  /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_Sector_ScanCurrentResult retVal = FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED;
    boolean endReached = Fee_30_FlexNor_Sector_EndReached(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if((ctx->Chunk->Data.Validity != FEE_30_FLEXNOR_EMPTY) && (endReached == FALSE))
    {
        if(ctx->Chunk->Data.Validity == FEE_30_FLEXNOR_VALID)
        {
            Fee_30_FlexNor_LookupTable_LinkType chunkLink;
            Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

            chunkLink.SectorId = ctx->Sector->SectorId;
            chunkLink.ChunkOffset = (ctx->Chunk->Data.StartAddress - ctx->Sector->StartAddress) / partitionConfig->PageAlignment;

            Fee_30_FlexNor_LookupTable_SetLinkIfNewer(ctx->Sector->PartitionId, ctx->Chunk->Data.BlockId, chunkLink);
        }

        ctx->Sector->NextFreeAddress += ctx->Chunk->Services.GetTotalSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
        retVal = FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE;
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TryAllocateChunk()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TryAllocateChunk(Fee_30_FlexNor_SectorPtrType sector, 
    Fee_30_FlexNor_ChunkPtrType chunk, 
    Fee_30_FlexNor_InstancePtrType instance, 
    Fee_30_FlexNor_ChunkPtrType predecessorChunk,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_SectorStmContext.Sector = sector;
    Fee_30_FlexNor_SectorStmContext.Chunk = chunk;
    Fee_30_FlexNor_SectorStmContext.Instance = instance;
    Fee_30_FlexNor_SectorStmContext.PredecessorChunk = predecessorChunk;
    Fee_30_FlexNor_SectorStmContext.ResultCallback = resultCbk;
    Fee_30_FlexNor_Sector_TryAllocateChunk_Initialize(&Fee_30_FlexNor_SectorStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */   
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DoesChunkFitInSector()
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
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DoesChunkFitInSector(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    boolean doesChunkFit = FALSE;
    Fee_30_FlexNor_LengthType totalChunkSize;
    Fee_30_FlexNor_LengthType sectorLength;

    Fee_30_FlexNor_ChunkFactory_CreateChunk(0u, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    ctx->Chunk->Data.InstanceCount = Fee_30_FlexNor_Sector_GetInstanceCount(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    totalChunkSize = ctx->Chunk->Services.GetTotalSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    sectorLength = Fee_30_FlexNor_ConfigInterface_GetSectorLength(ctx->Sector->PartitionId, ctx->Sector->StartAddress);

    if((ctx->Sector->StartAddress + sectorLength) > (ctx->Sector->NextFreeAddress + totalChunkSize))
    {
        doesChunkFit = TRUE;
    }

    return doesChunkFit;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TriggerChunkAllocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TriggerChunkAllocation(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_AddressType targetChunkAddress = ctx->Sector->NextFreeAddress;
    Fee_30_FlexNor_ChunkFactory_CreateChunk(targetChunkAddress, ctx->Sector->PartitionId, ctx->Sector->SectorId, ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */

    Fee_30_FlexNor_Sector_UpdateNextFreeAddress(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->Chunk->Data.InstanceCount = Fee_30_FlexNor_Sector_GetInstanceCount(ctx); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    ctx->Chunk->Services.Allocate(ctx->Chunk, ctx->PredecessorChunk, ctx->Instance, &Fee_30_FlexNor_Sector_ResultHandler); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateLookupTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateLookupTable(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_LinkType updatedLink;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;

    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->Sector->PartitionId);

    updatedLink.SectorId = ctx->Sector->SectorId;
    updatedLink.ChunkOffset = (ctx->Chunk->Data.StartAddress - ctx->Sector->StartAddress) / partitionConfig->PageAlignment;
    updatedLink.IsValidated = TRUE;

    Fee_30_FlexNor_LookupTable_SetLinkIfNewer(ctx->Chunk->Data.PartitionId, ctx->Chunk->Data.BlockId, updatedLink);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateNextFreeAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateNextFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LengthType totalChunkSize = ctx->Chunk->Services.GetTotalSize(ctx->Chunk); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    ctx->Sector->NextFreeAddress = ctx->Sector->NextFreeAddress + totalChunkSize; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_Sector.c
 *********************************************************************************************************************/
