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
/*!        \file  Fee_30_FlexNor_LookupTableInternal.h
 *        \brief  Internal lookup table prototypes
 *      \details  Provides the internal prototypes for the business logic of the lookup table implementation.
 *         \unit  LookupTable
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_LOOKUPTABLEINTERNAL_H)
# define FEE_30_FLEXNOR_LOOKUPTABLEINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_LookupTable.h"
#include "Fee_30_FlexNor_Types.h"
#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_Sector.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(struct Fee_30_FlexNor_LookupTable_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_LookupTable_ContextPtrType;
typedef P2CONST(struct Fee_30_FlexNor_LookupTable_Context, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_LookupTable_ConstContextPtrType;

/* Module state */
typedef P2FUNC(Fee_30_FlexNor_ScheduleBehaviorType, AUTOMATIC, Fee_30_FlexNor_LookupTable_ProcessEvt)(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);
typedef P2FUNC(void, AUTOMATIC, Fee_30_FlexNor_LookupTable_FailEvt)(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

typedef struct Fee_30_FlexNor_LookupTable_State
{
    Fee_30_FlexNor_LookupTable_ProcessEvt ProcessEvent;     /*!< Pointer to the handler for the process event of the state */
    Fee_30_FlexNor_LookupTable_FailEvt FailEvent;           /*!< Pointer to the handler for the fail event of the state */
} Fee_30_FlexNor_LookupTable_StateType;                     /*!< Represents a state of the internal unit state machine */

typedef CONST(Fee_30_FlexNor_LookupTable_StateType, AUTOMATIC) Fee_30_FlexNor_LookupTable_ConstStateType;
typedef P2CONST(Fee_30_FlexNor_LookupTable_StateType, AUTOMATIC, FEE_30_FLEXNOR_VAR) Fee_30_FlexNor_LookupTable_ConstStatePtrType;

/* Module context */
typedef struct Fee_30_FlexNor_LookupTable_Context
{
    Fee_30_FlexNor_LookupTable_ConstStatePtrType CurrentState;       /*!< Current state of the state machine */
    Fee_30_FlexNor_ConstPartitionConfigPtrType PartitionConfig;      /*!< Pointer to the partition configuration that is currently in use */
    Fee_30_FlexNor_SectorPtrType NextSectorToProcess;                /*!< Pointer to the next sector that shall be processed for the recovery. NULL in case there is no further sector */
    Fee_30_FlexNor_ResultCallback ResultCallback;                    /*!< Result callback that is used to communicate the service result back to the caller */
    Fee_30_FlexNor_JobType LutJob;                                   /*!< Job object used for loading and persisting the lut block */
    boolean LutChunkSearchSucceeded;                                 /*!< Signals whether a valid lut chunk has been found during lut load operation */
    Fee_30_FlexNor_ChunkType LutChunk;                               /*!< Chunk that is used for LUT chunk search */
    Fee_30_FlexNor_InstanceType LutInstance;                         /*!< Instance that is used for LUT instance search */
} Fee_30_FlexNor_LookupTable_ContextType;                            /*!< Represents the context for the internal state machine of the unit */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_StartJob()
 *********************************************************************************************************************/
/*! \brief       Start a job for the unit
 *  \details     Registers the unit at the scheduler to start the asynchronous processing for the unit.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_StartJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_EndJob()
 *********************************************************************************************************************/
/*! \brief       Ends a job for the unit
 *  \details     Unregisters the unit from the scheduler.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_EndJob(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ResultHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the result of a called service
 *  \details     This function is used as a result callback for services called by this unit.
 *  \param[in]   result     Result of the called service
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ResultHandler(Fee_30_FlexNor_ServiceResult result);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerSectorScan
 *********************************************************************************************************************/
/*! \brief          Scan the next sector which the pointer in the context points to
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerSectorScan(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ValidateAll
 *********************************************************************************************************************/
/*! \brief          Validates all lookup table entries
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ValidateAll(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite
 *********************************************************************************************************************/
/*! \brief          Uses partition module to write the lut block to flash
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite
 *********************************************************************************************************************/
/*! \brief          Uses sector module to write the lut shortcut link to sector header in flash
 *  \details        -
 *  \param[in]      ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite(Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_IsShortcutNecessary
 *********************************************************************************************************************/
/*! \brief          Checks whether the shortcut must be written
 *  \details        -
 *  \param[in]      ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         True: Shortcut is necessary
 *                  False: Shortcut is not necessary
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_IsShortcutNecessary(Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch
 *********************************************************************************************************************/
/*! \brief          Searches the most recent LUT chunk by using the link search starting with the link in the most recent sector header
                    containing a valid lut link.
 *  \details        Also determines the sector with most recent LUT link. If no such sector is available, the search will be skipped.
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch
 *********************************************************************************************************************/
/*! \brief          Searches the most recent instance in the given chunk.
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead
 *********************************************************************************************************************/
/*! \brief          Reads the content of the recently found instance. The direct target buffer is the LUT in RAM.
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead(Fee_30_FlexNor_LookupTable_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_LOOKUPTABLEINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTableInternal.h
 *********************************************************************************************************************/
