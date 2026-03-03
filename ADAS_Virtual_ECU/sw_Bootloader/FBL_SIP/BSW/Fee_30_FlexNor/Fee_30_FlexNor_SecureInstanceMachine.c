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
/*!        \file  Fee_30_FlexNor_SecureInstanceMachine.c
 *        \brief  Secure instance state machine implementation
 *      \details  Provides the implementation of the state machine logic for the secure instance unit.
 *         \unit  SecureInstance
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_SECUREINSTANCEMACHINE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_SecureInstanceMachine.h"
#include "Fee_30_FlexNor_Scheduler.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

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
#define FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceDefaultState = {
    Fee_30_FlexNor_SecureInstance_DefaultProcessEvent, 
    Fee_30_FlexNor_SecureInstance_DefaultFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceValidateInstanceState = { 
    Fee_30_FlexNor_SecureInstance_ValidateInstance_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
}; 

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteStartMarkerState = {  
    Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWritePayloadState = {
    Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
}; 

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteSealMarkerState = {
    Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
}; 

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceWriteCommitMarkerState = {
    Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
};

/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadStatusState = {
    Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
}; 
    
/* PRQA S 3218 1 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_SecureInstance_ConstStateType Fee_30_FlexNor_SecureInstanceReadPayloadState = {
    Fee_30_FlexNor_SecureInstance_ReadPayload_ProcessEvent, 
    Fee_30_FlexNor_SecureInstance_JobFailEvent
};

#define FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_InitState(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultProcessEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_DefaultFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_JobFailEvent(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Validate_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Validate_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceValidateInstanceState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_ValidateInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstance_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstance_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_ReadInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ValidateInstance_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ValidateInstance_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_ValidateInstanceMetadata(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_Write_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_Write_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();
    Fee_30_FlexNor_Scheduler_DenyCancel();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteStartMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteStartMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_WriteStartMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteStartMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_WritePayloadStart(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWritePayloadState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WritePayload_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_Scheduler_AllowCancel();

    if(ctx->PayloadWritten < ctx->Instance.ConstInstanceData->PayloadSize)
    {
        Fee_30_FlexNor_SecureInstance_WritePayload(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteSealMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_WriteSealMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_WriteSealMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteSealMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceWriteCommitMarkerState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_WriteCommitMarker_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker_OnEnter(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_WriteCommitMarker(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_WriteCommitMarker_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{    
    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_EndJob();    

    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadContent_Initialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadContent_Initialize(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_StartJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadStatusState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_SecureInstance_ReadStatus_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus_OnEnter(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_ReadStatus(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadStatus_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_ParseInstanceStatus(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(ctx->Instance.InstanceData->Status == FEE_30_FLEXNOR_INSTANCE_VALID)
    {
        ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceReadPayloadState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_SecureInstance_ReadPayload_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
       Fee_30_FlexNor_SecureInstance_EndJob();

       ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
       ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadPayload_OnEnter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload_OnEnter(Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_ReadPayload(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_SecureInstance_ReadPayload_ProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_SecureInstance_ReadPayload_ProcessEvent(
    Fee_30_FlexNor_SecureInstance_ContextPtrType ctx)
{
    Fee_30_FlexNor_SecureInstance_EndJob();

    ctx->CurrentState = &Fee_30_FlexNor_SecureInstanceDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */

    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_SecureInstanceMachine.c
 *********************************************************************************************************************/
