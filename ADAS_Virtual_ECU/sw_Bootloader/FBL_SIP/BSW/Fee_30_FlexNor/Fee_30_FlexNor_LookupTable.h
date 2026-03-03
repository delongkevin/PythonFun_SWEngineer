/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Fee_30_FlexNor_LookupTable.h
 *        \brief  Lookup table interface
 *      \details  Provides the interface for accessing and handling the lookup table.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_LOOKUPTABLE_H)
# define FEE_30_FLEXNOR_LOOKUPTABLE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    Fee_30_FlexNor_SectorIdType SectorId;                  /*!< Sector id of the sector where the chunk lies.*/
    Fee_30_FlexNor_PagebasedOffsetType ChunkOffset;        /*!< Offset of the chunk in pages relative to the sector start address.*/
    boolean IsValidated;                                   /*!< Signs if the lookup table entry is validated.*/
} Fee_30_FlexNor_LookupTable_LinkType;                     /*!< Structure for easy access to the lookup table entry of a corresponding block.*/

typedef P2VAR(Fee_30_FlexNor_LookupTable_LinkType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_LookupTable_LinkPtrType;
typedef P2CONST(Fee_30_FlexNor_LookupTable_LinkType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_LookupTable_ConstLinkPtrType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the lookup table unit
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Init(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_GetLink()
 *********************************************************************************************************************/
/*! \brief       Gets the stored lookup table link for a given block in a given partition.
 *  \details     -
 *  \param[in]   partitionId    Id of the partition the given block resides in
 *  \param[in]   blockId        Id of the block whose link shall be get
 *  \return      The link currently stored in the lookup table for the block.
 *               If no entry was found for the given partition and block, the link is 0.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_LookupTable_LinkType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_GetLink(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_SetLinkIfNewer()
 *********************************************************************************************************************/
/*! \brief       Updates the link in the lookup table for a given block in a given partition
 *  \details     The link is updated if the given chunk location is chronological newer than the currently stored one.
 *               This automatically also leads to the link being marked as verified.
 *  \param[in]   partitionId    Id of the partition the given block resides in
 *  \param[in]   blockId        Id of the block whose link shall be set
 *  \param[in]   link           Link to the chunk
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_SetLinkIfNewer(
    Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_BlockIdType blockId, Fee_30_FlexNor_LookupTable_LinkType link);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsFullyValidated()
 *********************************************************************************************************************/
/*! \brief       Checks if all lookup table links of the given partition are validated
 *  \details     -
 *  \param[in]   partitionId    Id of the partition whose lookup table link validity shall be checked
 *  \return      TRUE           All links were validated
 *               FALSE          There are still some unvalidated links
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsFullyValidated(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_InvalidateAll()
 *********************************************************************************************************************/
/*! \brief       Invalidates all lookup table links for the given partition
 *  \details     Sets all links to an invalid value and resets the validation flags.
 *  \param[in]   partitionId    Id of the partition whose lookup table links shall be invalidated
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InvalidateAll(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Recover()
 *********************************************************************************************************************/
/*! \brief       Scan every available sector of the partition and build up the lookup table out of it
 *  \details     In case the lookup table is lost (or never written), this service will build it up again.
 *  \param[in]   partitionId    Id of the partition the recovery shall be made
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Recover(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Persist()
 *********************************************************************************************************************/
/*! \brief       Persist the content of the lookup table for the given partition
 *  \details     Handles every possible situation (startup, aborted gc,...), so this can be called from any context.
 *  \param[in]   partitionId    Id of the target partition
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Persist(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load()
 *********************************************************************************************************************/
/*! \brief       Loads the content of the lookup table for the given partition
 *  \details     Searches for the most recent LUT chunk and loads its content into the RAM.
 *  \param[in]   partitionId    Id of the target partition
 *  \param[in]   resultCbk      The result callback that is called in case the service is complete. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load(Fee_30_FlexNor_PartitionIdType partitionId, Fee_30_FlexNor_ResultCallback resultCbk);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_LOOKUPTABLE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTable.h
 *********************************************************************************************************************/
