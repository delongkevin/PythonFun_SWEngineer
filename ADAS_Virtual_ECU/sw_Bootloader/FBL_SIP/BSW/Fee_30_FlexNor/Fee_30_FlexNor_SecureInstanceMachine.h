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
/*!        \file  Fee_30_FlexNor_SecureInstanceMachine.h
 *        \brief  state machine prototypes for secure instance
 *      \details  Provides the prototypes for the state machine implementation of the secure instance unit.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_SECUREINSTANCEMACHINE_H)
# define FEE_30_FLEXNOR_SECUREINSTANCEMACHINE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureInstanceInternal.h"

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
 * Fee_30_FlexNor_SecureInstance_InitState()
 *********************************************************************************************************************/
/*! \brief          Initialize the internal state machine
 *  \details        -
 *  \param[in,out]  ctx                   Pointer to the context that shall be initialized. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_InitState(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultProcessEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultFailEvent()
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
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_JobFailEvent()
 *********************************************************************************************************************/
/*! \brief       Fail event handler
 *  \details     Ends the current job and notifies the caller about the fail of the service.
 *  \param[in]   ctx               Pointer to the context of the service that failed. Must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_JobFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Validate_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize validate state machine
 *  \details        Initializes and starts the asynchronous state machine for validating the instances.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Validate_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstance_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for ValidateInstance state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstance_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstance_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ValidateInstance state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstance_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);
    
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Write_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize write state machine
 *  \details        Initializes and starts the asynchronous state machine for writing the instance to the flash.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Write_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteStartMarker state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteStartMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WritePayload state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteSealMarker state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the WriteSealMarker state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for WriteCommitMarker state
 *  \details        -
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent()
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadContent_Initialize()
 *********************************************************************************************************************/
/*! \brief          Initialize read content state machine
 *  \details        Initializes and starts the asynchronous state machine for reading the instance content.
 *  \param[in,out]  ctx                 Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadContent_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for ReadStatus state
 *  \details        -
 *  \param[in,out]  ctx                Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus_OnEnter(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadStatus state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadPayload_OnEnter()
 *********************************************************************************************************************/
/*! \brief          OnEnter function for ReadPayload state
 *  \details        -
 *  \param[in,out]  ctx                Pointer to the context for the state machine processing. Must not be NULL.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload_OnEnter(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadPayload_ProcessEvent()
 *********************************************************************************************************************/
/*! \brief          Event handler for the Process event of the ReadPayload state
 *  \details        -
 *  \param[in,out]  ctx                               Pointer to the context for the state machine processing. Must not be NULL.
 *  \return         FEE_30_FLEXNOR_CONTINUE_SCHEDULE  Let the execution continue
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_SECUREINSTANCEMACHINE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstanceMachine.h
 *********************************************************************************************************************/
