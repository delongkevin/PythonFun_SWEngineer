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
/*!        \file  Fee_30_FlexNor_SectorInternal.h
 *        \brief  Internal sector business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the sector implementation.
 *         \unit  Sector
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_CHUNKINTERNAL_H)
# define FEE_30_FLEXNOR_CHUNKINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Sector.h"
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
typedef P2VAR(struct Fee_30_FlexNor_Sector_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_Sector_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_Sector_ProcessEvt)(Fee_30_FlexNor_Sector_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_Sector_FailEvt)(Fee_30_FlexNor_Sector_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_Sector_State
{
    Fee_30_FlexNor_Sector_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_Sector_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_Sector_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_Sector_StateType, AUTOMATIC) Fee_30_FlexNor_Sector_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_Sector_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_Sector_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_Sector_Context
{
    Fee_30_FlexNor_Sector_ConstStatePtrType CurrentState;           /*!< Current state of the state machine */
    
    Fee_30_FlexNor_SectorPtrType Sector;                            /*!< Sector to operates on */
    Fee_30_FlexNor_DataPtrType SectorBuffer;                        /*!< Internal buffer to store the sector header data read from flash. */

    Fee_30_FlexNor_ChunkPtrType Chunk;                              /*!< Object used for chunk operations depending on the currently executed service. */
    Fee_30_FlexNor_InstancePtrType Instance;                        /*!< Object used to store the instance that is required for a chunk allocation. */
    Fee_30_FlexNor_ChunkPtrType PredecessorChunk;                   /*!< Pointer to the predecessor of the chunk that shall be allocated. */
    Fee_30_FlexNor_ResultCallback ResultCallback;                   /*!< Result callback that is used to communicate the service result back to the caller. */
} Fee_30_FlexNor_Sector_ContextType;                                /*!< Represents the context for the internal state machine of the unit */

typedef enum
{
    FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE,                            /*!< Sector Scan is not over yet */
    FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED                             /*!< Sector Scan is over */
}Fee_30_FlexNor_Sector_ScanCurrentResult;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadMetadata()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header meta data from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateMetadata()
 *********************************************************************************************************************/
/*! \brief       Validates the sector header meta data previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the read sector header meta data that shall be validated. Must not be NULL.
 *  \return      Result of the validation (see enum Fee_30_FlexNor_Sector_MetadataValidationResultType).
 *  \pre         Sector header meta data must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ErrorLocation, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateMetadata(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadAdditionalInfo()
 *********************************************************************************************************************/
/*! \brief         Request reading the sector header addtional info from flash access layer and store them in given buffer.
 *  \details       -
 *  \param[in,out] ctx               Context that contains the sector whose header shall be read. Must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ParseAdditionalInfo()
 *********************************************************************************************************************/
/*! \brief       Parses the sector header additional info previously read from flash.
 *  \details     -
 *  \param[in]   ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre         Sector header additional info must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ParseAdditionalInfo(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadFirstChunk()
 *********************************************************************************************************************/
/*! \brief       Requests reading the first chunk.
 *  \details     -
 *  \param[in]   ctx            Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ReadFirstChunk(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ValidateFirstChunk()
 *********************************************************************************************************************/
/*! \brief       Gets the result of the validation of the first chunk.
 *  \details     -
 *  \param[in]   ctx         Context that contains the read sector header additional info that shall be validated. Must not be NULL.
 *  \return      TRUE        The chunk is valid
 *               FALSE       The chunk is invalid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_ValidateFirstChunk(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the erase marker to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose erase marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteEraseMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteLutLinkToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the lut link to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose lut link shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteLutLinkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteSourceSectorToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the source sector to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose source sector shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteSourceSectorToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_EraseSector()
 *********************************************************************************************************************/
/*! \brief       Erases the corresponding sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector which shall be erased. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_EraseSector(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WritePropertiesToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the properties to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose properties shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WritePropertiesToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteFirstChunkToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the first chunk to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose first chunk shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteFirstChunkToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory()
 *********************************************************************************************************************/
/*! \brief       Writes the commit marker to the corresponding address of the sector.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector whose commit marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_WriteCommitMarkerToMemory(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Reads the next chunk header for the scan sector service.
 *  \details     -
 *  \param[in]   ctx            Context that contains the sector for which the scan shall be done. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_ProcessReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Evaluates the chunk header that has just been read and decides how to go on with sector scan.
 *  \details     Also updates the next free address and - if chunk is valid - the lut entry.
 *  \param[in]   ctx            Context that contains the sector for which the scan shall be done. Must not be NULL.
 *  \return      FEE_30_FLEXNOR_SECTOR_SCAN_CONTINUE: Not the last chunk, continue with next chunk.
 *  \return      FEE_30_FLEXNOR_SECTOR_SCAN_FINISHED: Latest chunk, sector scan is finished.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_Sector_ScanCurrentResult, FEE_30_FLEXNOR_CODE)Fee_30_FlexNor_Sector_ProcessReadChunkHeader(Fee_30_FlexNor_Sector_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_DoesChunkFitInSector()
 *********************************************************************************************************************/
/*! \brief       Checks if the chunk still fits into the sector
 *  \details     Calculates the target chunk size of the chunk that shall be allocated and check if it still fits
 *               into the sector.
 *  \param[in]   ctx            Context that contains the chunk as well as the sector that are required for the check. 
 *                              Must not be NULL.
 *  \return      TRUE           The chunk fits into the sector.
 *               FALSE          The chunk doesn't fit into the sector anymore.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_DoesChunkFitInSector(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_TriggerChunkAllocation()
 *********************************************************************************************************************/
/*! \brief       Trigger the allocation of the chunk at the next free address of the sector
 *  \details     -
 *  \param[in]   ctx            Context that contains sector and the chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_TriggerChunkAllocation(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateLookupTable()
 *********************************************************************************************************************/
/*! \brief       Updates the next free address of the sector and the lookup table after successfull allocating a chunk
 *  \details     -
 *  \param[in]   ctx            Context that contains the current sector and the allocated chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateLookupTable(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_Sector_UpdateNextFreeAddress()
 *********************************************************************************************************************/
/*! \brief       Updates the next free address of the sector according to the currently written chunk
 *  \details     -
 *  \param[in]   ctx            Context that contains the current sector and the allocated chunk. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_Sector_UpdateNextFreeAddress(Fee_30_FlexNor_Sector_ConstContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_CHUNKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_ChunkInternal.h
 *********************************************************************************************************************/
