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
/*!        \file  Fee_30_FlexNor_DetChecks.h
 *        \brief  Provides DET checks
 *      \details  Provides the declarations for DET check functions of API parameters.
 *         \unit  DetChecks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (FEE_30_FLEXNOR_DETCHECKS_H)
# define FEE_30_FLEXNOR_DETCHECKS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_30_FlexNor_Types.h"

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
 * Fee_30_FlexNor_DetChecks_CheckInitialized()
 *********************************************************************************************************************/
/*! \brief       Checks if the component was already initialized in case DET checks are enabled
 *  \details     -
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR  The component is initialized
 *               FEE_30_FLEXNOR_E_UNINIT    The component is not initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckInitialized(void);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckBlockNumber()
 *********************************************************************************************************************/
/*! \brief       Checks if the given block number is part of the configuration in case DET checks are enabled
 *  \details     -
 *  \param[in]   blockNumber    Block number that shall be checked
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR          The block number is part of the config
 *               FEE_30_FLEXNOR_E_INVALID_BLOCK_NO  The block number is invalid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckBlockNumber(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckOffset()
 *********************************************************************************************************************/
/*! \brief       Checks if the given block offset is valid for the block in case DET checks are enabled
 *  \details     -
 *  \param[in]   blockNumber    Block number the offset belongs to
 *  \param[in]   blockOffset    Given offset that shall be checked
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR           The block offset is ok
 *               FEE_30_FLEXNOR_E_INVALID_BLOCK_OFS  The block offset exceeds the block length
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckOffset(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_BlockOffsetType blockOffset);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckLength()
 *********************************************************************************************************************/
/*! \brief       Checks if the given block length and offset doesn't exceed the configure block length
 *               in case DET checks are enabled
 *  \details     -
 *  \param[in]   blockNumber    Block number the length belongs to
 *  \param[in]   blockOffset    Given offset the reading starts from
 *  \param[in]   readLength    Given length that shall be read
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR           The block offset is ok
 *               FEE_30_FLEXNOR_E_INVALID_BLOCK_LEN  The given block offset and length exceed the configured block length
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckLength(
    Fee_30_FlexNor_BlockNumberType blockNumber, 
    Fee_30_FlexNor_BlockOffsetType blockOffset, 
    Fee_30_FlexNor_LengthType readLength);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckImmediate()
 *********************************************************************************************************************/
/*! \brief       Checks if the block with the given block number has immediate data configured
 *  \details     -
 *  \param[in]   blockNumber    Block number that shall be checked for immediate data
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR           The block has immediate data configured
 *               FEE_30_FLEXNOR_E_INVALID_BLOCK_NO   The block doesn't have immediate data configured
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckImmediate(Fee_30_FlexNor_BlockNumberType blockNumber);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckPartitionId()
 *********************************************************************************************************************/
/*! \brief       Checks if there is a valid partition matching to the given partitionId
 *  \details     -
 *  \param[in]   partitionId    Id of the partition that shall be checked
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR               The partitionId is valid
 *               FEE_30_FLEXNOR_E_INVALID_PARTITION_ID   The partitionId is not valid.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckPartitionId(Fee_30_FlexNor_PartitionIdType partitionId);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_CheckParamPointer()
 *********************************************************************************************************************/
/*! \brief       Checks if the given param pointer is valid in case DET checks are enabled
 *  \details     -
 *  \param[in]   dataPtr        Pointer to the given param pointer
 *  \return      FEE_30_FLEXNOR_E_NO_ERROR          The given data pointer is ok
 *               FEE_30_FLEXNOR_E_PARAM_POINTER     The given data pointer is invalid
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Fee_30_FlexNor_DetErrorCode, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_CheckParamPointer(Fee_30_FlexNor_ConstParamPtrType dataPtr);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportDetError()
 *********************************************************************************************************************/
/*! \brief       Reports an error to the DET in case DET error reporting is enabled
 *  \details     -
 *  \param[in]   serviceId  Id of the service reporting the error
 *  \param[in]   errorCode  Error code that needs to be reported
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_ReportDetError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_DetErrorCode errorCode);

/**********************************************************************************************************************
 * Fee_30_FlexNor_DetChecks_ReportRuntimeError()
 *********************************************************************************************************************/
/*! \brief       Reports the given error as runtime error
 *  \details     -
 *  \param[in]   serviceId  Id of the service reporting the error
 *  \param[in]   errorCode  Error code that needs to be reported
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_DetChecks_ReportRuntimeError(Fee_30_FlexNor_ServiceId serviceId, Fee_30_FlexNor_DetErrorCode errorCode);

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FEE_30_FLEXNOR_DETCHECKS_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_FlexNor_DetChecks.h
 *********************************************************************************************************************/
