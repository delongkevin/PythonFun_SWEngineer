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
/*!        \file  Fee_30_FlexNor_SlimChunkMachine.h
 *        \brief  State machine prototypes for slim chunk
 *      \details  Provides the prototypes for the state machine implementation of the slim chunk unit.
 *         \unit  SlimChunk
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SLIMCHUNKMACHINE_H)
# define FEE_30_FLEXNOR_SLIMCHUNKMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SlimChunkInternal.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_30_FLEXNOR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Default Process event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_STOP_SCHEDULE  Always stops the scheduler
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_DefaultFailEvent()
 *********************************************************************************************************************/
/*! \brief          Default Fail event handler
 *  \details        This function is never called in normal operation. It exists to be able to set the state machine
 *                  to a defined state in case no job is being executed.
 *  \param[in,out]  ctx                           Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_DefaultFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx            Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_JobFailEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx         Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_InitState(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize read header state machine
 *  \details        Initializes and starts the asynchronous state machine for reading and validating the chunk header.
 *  \param[in,out]  ctx         Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ReadHeader_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for ValidateChunkHeader state
 *  \details        -
 *  \param[in,out]  ctx     Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ValidateChunkHeader state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_ValidateChunkHeader_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckFirstInstance_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for CheckFirstInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckFirstInstance_OnEnter(
    Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the CheckFirstInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_CheckFirstInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_Allocate_Initialize()
 *********************************************************************************************************************/
/*! \brief       Initializes the state machine for the allocation service
 *  \details     -
 *  \param[in]   ctx               Context the state machine shall be initialized in. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_Allocate_Initialize(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteProperties state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteProperties state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteProperties_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WritePredecessorLink_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WritePredecessorLink state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WritePredecessorLink_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WritePredecessorLink state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WritePredecessorLink_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteInstance state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteInstance_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteInstance_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker_OnEnter(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SlimChunk_WriteCommitMarker_ProcessEvent(Fee_30_FlexNor_SlimChunk_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SLIMCHUNKMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SlimChunkMachine.h
 *********************************************************************************************************************/
