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
/*!        \file  Fee_30_FlexNor_FlashAccess.c
 *        \brief  Flash access business logic implementation
 *      \details  Provides the implementation of the business logic for the flash access.
 *         \unit  FlashAccess
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define FEE_30_FLEXNOR_FLASHACCESS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_FlashAccess.h"
#include "Fee_30_FlexNor_FlashAccessMachine.h"
#include "Fee_30_FlexNor_FlashAccessInternal.h"

#include "Fee_30_FlexNor_ConfigInterface.h"
#include "Fee_30_FlexNor_FlsInterface.h"
#include "Fee_30_FlexNor_Scheduler.h"
#include "Fee_30_FlexNor_Cbk.h"

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
#define FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FEE_30_FLEXNOR_LOCAL Fee_30_FlexNor_FlashAccess_ContextType Fee_30_FlexNor_FlashAccessStmContext;

#define FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
 * Fee_30_FlexNor_FlashAccess_ProcessingHandler()
 *********************************************************************************************************************/
/*! \brief       Handles the processing event
 *  \details     Triggers the Process event at the local state machine.
 *  \return      FEE_30_FLEXNOR_STOP_SCHEDULE       In case the scheduling shall be stopped
 *               FEE_30_FLEXNOR_CONTINUE_SCHEDULE   In case the scheduling can be continued
 *  \pre         The flash access unit needs to be initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ProcessingHandler(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult()
 *********************************************************************************************************************/
/*! \brief       Get the result of the latest flash job
 *  \details     Gets the result of the latest flash job from the flash driver and maps it to the FEE result type.
 *  \return      FEE_30_FLEXNOR_OK          The job was completed successfully
                 FEE_30_FLEXNOR_FAIL        The job failed
                 FEE_30_FLEXNOR_PENDING     The job is still pending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ProcessingHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ScheduleBehaviorType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ProcessingHandler(void)
{
    return Fee_30_FlexNor_FlashAccessStmContext.CurrentState->ProcessEvent(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_TriggerEventAtState */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_GetFlashJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FEE_30_FLEXNOR_LOCAL FUNC(Fee_30_FlexNor_ResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult(void)
{    
    Fee_30_FlexNor_ResultType jobProgress;
    MemIf_JobResultType flsJobResult = FEE_30_FLEXNOR_FLS_GETJOBRESULT();

    switch(flsJobResult)
    {
        case MEMIF_JOB_OK:
            jobProgress = FEE_30_FLEXNOR_OK;
            break;
        case MEMIF_JOB_PENDING:
            jobProgress = FEE_30_FLEXNOR_PENDING;
            break;
        case MEMIF_JOB_FAILED:
        default:
            jobProgress = FEE_30_FLEXNOR_FAIL;
            break;
    }

    return jobProgress;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Init(void)
{
    Fee_30_FlexNor_FlashAccess_InitState(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlash()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_FlashAccess_Read_Initialize(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_ReadFlashImmediate()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_ReadFlashImmediate(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_DataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;
    
    Fee_30_FlexNor_FlashAccess_ReadImmediate_Initialize(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_WriteFlash()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_WriteFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_ConstDataPtrType data, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobConstData = data;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_FlashAccess_Write_Initialize(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EraseFlash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EraseFlash(Fee_30_FlexNor_PartitionIdType partitionId,
    Fee_30_FlexNor_AddressType address, 
    Fee_30_FlexNor_LengthType length,
    Fee_30_FlexNor_ResultCallback resultCbk)
{
    Fee_30_FlexNor_FlashAccessStmContext.PartitionId = partitionId;
    Fee_30_FlexNor_FlashAccessStmContext.JobAddress = address;
    Fee_30_FlexNor_FlashAccessStmContext.JobLength = length;
    Fee_30_FlexNor_FlashAccessStmContext.ResultCallback = resultCbk;

    Fee_30_FlexNor_FlashAccess_Erase_Initialize(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_Cancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_Cancel(void)
{
    Fee_30_FlexNor_ResultType flsResult = Fee_30_FlexNor_FlashAccess_CheckJobResult(&Fee_30_FlexNor_FlashAccessStmContext); /* SBSW_Fee_30_FlexNor_FunctionCallWithContext */

    if(flsResult == FEE_30_FLEXNOR_PENDING)
    {
        FEE_30_FLEXNOR_FLS_CANCEL();
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_StartJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_StartJob(void)
{
    Fee_30_FlexNor_Scheduler_RegisterUnit(&Fee_30_FlexNor_FlashAccess_ProcessingHandler); /* SBSW_Fee_30_FlexNor_RegisterUnit */
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_EndJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_EndJob(void)
{
    Fee_30_FlexNor_Scheduler_UnregisterUnit();
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_IsFlashBlank()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_BlankCheckResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_IsFlashBlank(void)
{
    Fee_30_FlexNor_BlankCheckResultType blankCheckResult;
    MemIf_JobResultType flsJobResult = FEE_30_FLEXNOR_FLS_GETJOBRESULT();

    switch (flsJobResult)
    {
        case MEMIF_JOB_OK:
            blankCheckResult = FEE_30_FLEXNOR_ISBLANK;
            break;
        case MEMIF_BLOCK_INCONSISTENT:
            blankCheckResult = FEE_30_FLEXNOR_ISNOTBLANK;
            break;
        default:
            blankCheckResult = FEE_30_FLEXNOR_BLANKCHECK_FAILED;
            break;
    }

    return blankCheckResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_CheckJobResult()
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
FUNC(Fee_30_FlexNor_ResultType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_CheckJobResult(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_ResultType jobResult = FEE_30_FLEXNOR_PENDING;

#if(FEE_30_FLEXNOR_CFG_POLLING_MODE == STD_ON)
    if(FEE_30_FLEXNOR_FLS_GETSTATUS() == MEMIF_IDLE)
    {
        jobResult = Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult();
    }

    FEE_DUMMY_STATEMENT(ctx);
#else
    if(ctx->FlashJobStatus == FEE_30_FLEXNOR_IDLE)
    {
        jobResult = Fee_30_FlexNor_FlashAccess_GetMappedFlashJobResult();
    } 
#endif

    return jobResult;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetBufferToErasedValue(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Fee_30_FlexNor_LengthType index;
    Fee_30_FlexNor_ConstPartitionConfigPtrType partitionConfig;

    partitionConfig = Fee_30_FlexNor_ConfigInterface_GetPartitionConfig(ctx->PartitionId);

    for(index = 0; index < ctx->JobLength; index++)
    {
        ctx->JobData[index] = partitionConfig->ErasedValue; /* SBSW_Fee_30_FlexNor_ModifyContextArray */
    }
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupReadJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupReadJob(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal;
    retVal = FEE_30_FLEXNOR_FLS_READ((Fls_AddressType)ctx->JobAddress, ctx->JobData, (Fls_LengthType)ctx->JobLength); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupBlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupBlankCheck(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal;
#if(FEE_30_FLEXNOR_CFG_BLANKCHECK_ENABLED == STD_ON)
    retVal = FEE_30_FLEXNOR_FLS_BLANKCHECK((Fls_AddressType)ctx->JobAddress, (Fls_LengthType)ctx->JobLength);
#else
    /*
     * If the blank check feature is disabled for all partitions, the default return value for setting up a blank check is E_NOT_OK.
     * During runtime the function is never called if no partition requires a blank check due to a runtime check in the state machine. 
     * The intention behind this solution is to reduce the preprocessor variance by using only preprocessor switches where it is necessary.
     */
    FEE_DUMMY_STATEMENT(ctx);
    retVal = E_NOT_OK;
#endif
    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupWriteJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupWriteJob(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal;
    retVal = FEE_30_FLEXNOR_FLS_WRITE((Fls_AddressType)ctx->JobAddress, ctx->JobConstData, (Fls_LengthType)ctx->JobLength); /* SBSW_Fee_30_FlexNor_FunctionCallWithContextPointer */
    return retVal;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_FlashAccess_SetupEraseJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_FlashAccess_SetupEraseJob(Fee_30_FlexNor_FlashAccess_ContextPtrType ctx) /* PRQA S 3673 */ /* MD_Fee_30_FlexNor_CouldBeConstPointer */
{
    Std_ReturnType retVal;
    retVal = FEE_30_FLEXNOR_FLS_ERASE((Fls_AddressType)ctx->JobAddress, (Fls_LengthType)ctx->JobLength);
    return retVal;
}

/**********************************************************************************************************************
 * Fee_JobErrorNotification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobErrorNotification(void)
{
    Fee_30_FlexNor_FlashAccessStmContext.FlashJobStatus = FEE_30_FLEXNOR_IDLE;
}

/**********************************************************************************************************************
 * Fee_JobEndNotification
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_JobEndNotification(void)
{
    Fee_30_FlexNor_FlashAccessStmContext.FlashJobStatus = FEE_30_FLEXNOR_IDLE;
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_FlashAccess.c
 *********************************************************************************************************************/
