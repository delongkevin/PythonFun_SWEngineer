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
/*!        \file  Fee_30_FlexNor_SlimChunkInternal.h
 *        \brief  Internal slim chunk business logic prototypes
 *      \details  Provides the internal prototypes for the business logic of the slim chunk implementation.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined(FEE_30_FLEXNOR_SLIMCHUNKINTERNAL_H)
# define FEE_30_FLEXNOR_SLIMCHUNKINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Fee_30_FlexNor_ConfigInterface.h"
# include "Fee_30_FlexNor_Types.h"
# include "Fee_30_FlexNor_Chunk.h"

# include "Fee_30_FlexNor_Instance.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct Fee_30_FlexNor_SlimChunk
{
    Fee_30_FlexNor_ChunkPtrType GenericChunk;                   /*!< Pointer to the generic chunk. */
    Fee_30_FlexNor_ConstChunkPtrType ConstGenericChunk;         /*!< Pointer to the const generic chunk. */
    Fee_30_FlexNor_ChecksumType MetadataChecksum;               /*!< Checksum over the data of the chunk metadata */
    Fee_30_FlexNor_ChecksumType ChunklinkChecksum;              /*!< Checksum over the data of the chunk link */
    Fee_30_FlexNor_MarkerType CommitMarker;                     /*!< Stores the commit marker of the chunk. */
} Fee_30_FlexNor_SlimChunkType;                                 /*!< Holds all information about the data used by the concrete type. */

typedef P2VAR(struct Fee_30_FlexNor_SlimChunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimChunk_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_SlimChunk_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimChunk_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_SlimChunk_ProcessEvt)(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_SlimChunk_FailEvt)(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_SlimChunk_State
{
    Fee_30_FlexNor_SlimChunk_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_SlimChunk_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_SlimChunk_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_SlimChunk_StateType, AUTOMATIC) Fee_30_FlexNor_SlimChunk_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_SlimChunk_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_SlimChunk_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_SlimChunk_Context
{
    Fee_30_FlexNor_SlimChunk_ConstStatePtrType CurrentState;    /*!< Current state of the state machine */

    Fee_30_FlexNor_SlimChunkType Chunk;                         /*!< Slim chunk data the unit operates on. */
    Fee_30_FlexNor_DataPtrType ChunkBuffer;                     /*!< Internal buffer to store the chunk header (metadata + link) data read from flash. */
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig; /*!< Pointer to the partition configuration of the processed chunk. */

    Fee_30_FlexNor_InstancePtrType InstanceToWrite;             /*!< Pointer to the instance that shall be written during the chunk allocation. */
    Fee_30_FlexNor_ChunkPtrType PredecessorChunk;               /*!< Pointer to the predecessor chunk whose link is updated to point to the allocated chunk. */
    Fee_30_FlexNor_ConstChunkPtrType SuccessorChunk;            /*!< Pointer to the successor chunk whose link is written into the chunk write link service is called for. */
    Fee_30_FlexNor_InstanceType Instance;                       /*!< Internal buffer to store the instance which is being operated on. */

    Fee_30_FlexNor_ResultCallback ResultCallback;               /*!< Result callback that is used to communicate the service result back to the caller. */
} Fee_30_FlexNor_SlimChunk_ContextType;                         /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result               Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Reads the chunk header (containing chunk metadata and chunk link) from flash.
 *  \details     -
 *  \param[in]   ctx        Context the chunk header shall be read in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadChunkHeader(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader()
 *********************************************************************************************************************/
/*! \brief       Validates the chunk header
 *  \details     Validates the chunk header previously read from flash. Validates metadata and chunk link.
 *  \param[in]   ctx            Context that contains the read chunk header that shall be validated. Must not be NULL.
 *  \return      E_OK           The chunk header was validated
 *               E_NOT_OK       The validation was not completed due to the unknown state of the first instance
 *  \pre         Chunk header must have been read from flash.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckInstanceValidity()
 *********************************************************************************************************************/
/*! \brief       Checks the validity of the given instance and triggers garbage collections accordingly.
 *  \details     -
 *  \param[in]   ctx               Context the instance is saved in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckInstanceValidity(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties()
 *********************************************************************************************************************/
/*! \brief       Writes the chunk properties to flash
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk properties that shall be written to flash. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker()
 *********************************************************************************************************************/
/*! \brief       Writes the chunk commit marker to flash
 *  \details     -
 *  \param[in]   ctx               Context that contains the chunk whose commit marker shall be written. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SLIMCHUNKINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunkInternal.h
 *********************************************************************************************************************/
