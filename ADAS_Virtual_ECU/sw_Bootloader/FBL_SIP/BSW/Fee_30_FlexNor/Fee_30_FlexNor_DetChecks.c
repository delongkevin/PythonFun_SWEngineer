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
/*!        \file  Fee_30_FlexNor_DetChecks.c
 *        \brief  DET checks implementations
 *      \details  Provides the implementation for DET check functions of API parameters.
 *         \unit  DetChecks
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
#include "Fee_30_FlexNor.h"
#include "Fee_30_FlexNor_DetChecks.h"
#include "Fee_30_FlexNor_ConfigInterface.h"

#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

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
 * Fee_30_FlexNor_DetChecks_CheckInitialized()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckInitialized(void)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    if(Fee_30_FlexNor_GetStatus() == MEMIF_UNINIT)
    {
        errorCode = FEE_30_FLEXNOR_E_UNINIT;
    }
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckBlockNumber()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckBlockNumber(Fee_30_FlexNor_BlockNumberType blockNumber)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);

    if((blockConfig == NULL_PTR) || (blockConfig->Id == FEE_30_FLEXNOR_LUTBLOCKID))
    {
        errorCode = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
    }
#else
    FEE_DUMMY_STATEMENT(blockNumber);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckOffset()
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
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckOffset(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_BlockOffsetType blockOffset)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);

    if(blockConfig != NULL_PTR)
    {
        if(blockOffset >= blockConfig->Length)
        {
            errorCode = FEE_30_FLEXNOR_E_INVALID_BLOCK_OFS;
        }
    }
#else
    FEE_DUMMY_STATEMENT(blockNumber);
    FEE_DUMMY_STATEMENT(blockOffset);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckLength()
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
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckLength(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_BlockOffsetType blockOffset, 
    Fee_30_FlexNor_LengthType readLength)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);

    if(blockConfig != NULL_PTR)
    {
        if(((blockOffset + readLength) > blockConfig->Length) || (readLength == 0u))
        {
            errorCode = FEE_30_FLEXNOR_E_INVALID_BLOCK_LEN;
        }
    }
#else
    FEE_DUMMY_STATEMENT(blockNumber);
    FEE_DUMMY_STATEMENT(blockOffset);
    FEE_DUMMY_STATEMENT(readLength);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckImmediate()
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
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckImmediate(Fee_30_FlexNor_BlockNumberType blockNumber)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    Fee_30_FlexNor_ConstBlockConfigPtrType blockConfig = Fee_30_FlexNor_ConfigInterface_GetBlockConfig(blockNumber);

    if(blockConfig != NULL_PTR)
    {
        if(blockConfig->HasImmediateData == STD_OFF)
        {
            errorCode = FEE_30_FLEXNOR_E_INVALID_BLOCK_NO;
        }
    }
#else
    FEE_DUMMY_STATEMENT(blockNumber);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckParamPointer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckParamPointer(Fee_30_FlexNor_ConstParamPtrType dataPtr)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    if(dataPtr == NULL_PTR)
    {
        errorCode = FEE_30_FLEXNOR_E_PARAM_POINTER;
    }
#else
    FEE_DUMMY_STATEMENT(dataPtr);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckPartitionId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckPartitionId(Fee_30_FlexNor_PartitionIdType partitionId)
{
    Fee_30_FlexNor_DetErrorCode errorCode = FEE_30_FLEXNOR_E_NO_ERROR;

#if (FEE_30_FLEXNOR_DEV_ERROR_DETECT == STD_ON)
    if( partitionId >= FEE_30_FLEXNOR_CONFIGURED_PARTITIONS)
    {
        errorCode = FEE_30_FLEXNOR_E_INVALID_PARTITION_ID;
    }
#else
    FEE_DUMMY_STATEMENT(partitionId);
#endif

    return errorCode;
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_ReportDetError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_ReportDetError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_DetErrorCode errorCode)
{
#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(FEE_30_FLEXNOR_MODULE_ID, FEE_30_FLEXNOR_INSTANCE_ID_DET, (uint8)serviceId, (uint8)errorCode);
#else
    FEE_DUMMY_STATEMENT(serviceId);
    FEE_DUMMY_STATEMENT(errorCode);
#endif
}

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportRuntimeError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_ReportRuntimeError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_DetErrorCode errorCode)
{
#if (FEE_30_FLEXNOR_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportRuntimeError(FEE_30_FLEXNOR_MODULE_ID, FEE_30_FLEXNOR_INSTANCE_ID_DET, (uint8)serviceId, (uint8)errorCode);
#else
    FEE_DUMMY_STATEMENT(serviceId);
    FEE_DUMMY_STATEMENT(errorCode);
#endif
}

#define FEE_30_FLEXNOR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_DetChecks.c
 *********************************************************************************************************************/
