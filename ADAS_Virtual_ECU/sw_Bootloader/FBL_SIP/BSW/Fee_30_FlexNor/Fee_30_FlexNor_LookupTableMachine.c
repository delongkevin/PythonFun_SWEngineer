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
/*!        \file  Fee_30_FlexNor_LookupTableMachine.c
 *        \brief  Lookup table state machine implementation
 *      \details  Provides the implementation of the state machine logic for the lookup table unit.
 *         \unit  LookupTable
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
#include "Fee_30_FlexNor_LookupTableMachine.h"
#include "Fee_30_FlexNor_SectorContainer.h"

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

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableDefaultState = {
    Fee_30_FlexNor_LookupTable_DefaultProcessEvent, 
    Fee_30_FlexNor_LookupTable_DefaultFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableScanSectorState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableWriteBlockState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableWriteShortcutState = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableFindMostRecentLutChunk = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableFindMostRecentLutInstance = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
};

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_LookupTable_ConstStateType Fee_30_FlexNor_LookupTableReadMostRecentLutPayload = { /* PRQA S 3218 */ /* MD_Fee_30_FlexNor_StateFileScopeStatic */
    Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent, 
    Fee_30_FlexNor_LookupTable_JobFailEvent
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
 * Fee_30_FlexNor_LookupTable_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_InitState(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultProcessEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
    return FEE_30_FLEXNOR_STOP_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_DefaultFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_DefaultFailEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    FEE_DUMMY_STATEMENT(ctx);
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_JobFailEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_JobFailEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_FAIL); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Recover_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Recover_Initialize(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableScanSectorState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_ScanSector_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ScanSector_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ScanSector_OnEnter(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetFirst(ctx->PartitionConfig->PartitionId); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_TriggerSectorScan(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent
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
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ScanSector_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->NextSectorToProcess = Fee_30_FlexNor_SectorContainer_GetNext(ctx->NextSectorToProcess); /* SBSW_Fee_30_FlexNor_ContextPointerAccess */ /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    
    if(ctx->NextSectorToProcess == NULL_PTR)
    {
        /*
         * After scanning each sector all blocks have validated lookup table entries that were discovered in the flash.
         * Because the whole partition was scanned, the state of the flash image is known and all blocks that were not written to flash yet 
         * still have unverified and invalid (they still have the value 0u for sector id and chunk offset) lookup table entries.
         * Therefore they need to be verified too.
         */
        Fee_30_FlexNor_LookupTable_ValidateAll(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    else
    {
        Fee_30_FlexNor_LookupTable_TriggerSectorScan(ctx);   /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Persist_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Persist_Initialize(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableWriteBlockState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_WriteBlock_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteBlock_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteBlock_OnEnter(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_TriggerLutBlockWrite(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteBlock_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(Fee_30_FlexNor_LookupTable_IsShortcutNecessary(ctx) == TRUE) /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableWriteShortcutState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_WriteShortcut_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteShortcut_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteShortcut_OnEnter(Fee_30_FlexNor_LookupTable_ConstContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_TriggerLutShortcutWrite(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_WriteShortcut_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
 
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_Load_Initialize
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_Load_Initialize(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{   
    Fee_30_FlexNor_LookupTable_StartJob();
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableFindMostRecentLutChunk; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_OnEnter(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_TriggerLutChunkSearch(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FindMostRecentLutChunk_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    if(ctx->LutChunkSearchSucceeded == TRUE)
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableFindMostRecentLutInstance; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    }
    else
    {
        ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
        Fee_30_FlexNor_LookupTable_EndJob();
        ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_NOT_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    }
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_OnEnter(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_TriggerLutInstanceSearch(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_FindMostRecentLutInstance_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    ctx->CurrentState = &Fee_30_FlexNor_LookupTableReadMostRecentLutPayload; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_OnEnter(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_OnEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_OnEnter(Fee_30_FlexNor_LookupTable_ContextPtrType ctx)
{
    Fee_30_FlexNor_LookupTable_TriggerLutPayloadRead(ctx); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_LookupTable_ReadMostRecentLutPayload_ProcessEvent(Fee_30_FlexNor_LookupTable_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{

    ctx->CurrentState = &Fee_30_FlexNor_LookupTableDefaultState; /* SBSW_Fee_30_FlexNor_ContextPointerAccess */
    Fee_30_FlexNor_LookupTable_EndJob();
    ctx->ResultCallback(FEE_30_FLEXNOR_SERVICE_OK); /* SBSW_Fee_30_FlexNor_ContextFunctionPointerCall */
    return FEE_30_FLEXNOR_CONTINUE_SCHEDULE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_Flexnor_LookupTableMachine.c
 *********************************************************************************************************************/
