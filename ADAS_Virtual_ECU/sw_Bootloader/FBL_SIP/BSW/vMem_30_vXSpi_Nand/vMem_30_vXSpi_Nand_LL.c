/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_vXSpi_Nand_LL.c
 *        \brief  vMem_30_vXSpi_Nand LowLevel source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL.h
 *
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_LL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_DetChecks.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceInitializer.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceModifier.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define VMEM_30_VXSPI_NAND_LOCAL static
#endif

#if !defined (VMEM_30_VXSPI_NAND_LOCAL_INLINE) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define VMEM_30_VXSPI_NAND_LOCAL_INLINE LOCAL_INLINE
#endif

/*! Internal state machine type to indicate the instance-specific job progress. */
typedef enum
{
  VMEM_30_VXSPI_NAND_IDLE = 0,
  VMEM_30_VXSPI_NAND_INIT_HW,
  VMEM_30_VXSPI_NAND_EXECUTE_READ,
  VMEM_30_VXSPI_NAND_EXECUTE_MODIFICATION,
  VMEM_30_VXSPI_NAND_EXECUTE_BLANK_CHECK,
  VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR,
  VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA
} vMem_30_vXSpi_Nand_JobProgressType;

/*! Instance job type to group an instance's job result and job progress. */
typedef struct
{
  vMem_30_vXSpi_Nand_JobResultType JobResult;
  vMem_30_vXSpi_Nand_JobProgressType JobProgress;
  vMem_30_vXSpi_Nand_InstanceIdType AffectedSectorIndex;
  vMem_30_vXSpi_Nand_LengthType Length;
  boolean ProcessFlag;
} vMem_30_vXSpi_Nand_InstanceJobType;
typedef P2VAR(vMem_30_vXSpi_Nand_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_InstanceJobPtrType;
typedef P2CONST(vMem_30_vXSpi_Nand_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_ConstInstanceJobPtrType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Contains instance specific status parameters like the JobResult, the JobProgress and the ProcessFlag. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_InstanceJobType, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_InstanceJobInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

/*! Job parameters for backup purposes. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_JobParamBackupType, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_JobParamBackup[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_AutomatedBadBlockInfoType, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_AutomatedBadBlockInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* This is not simply commented code but an example how to publish hardware specific jobs (an array of size zero
 * leads to compiler warnings):
 *
 * CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC) vMem_30_vXSpi_Nand_HwSpecificFunctions[VMEM_30_VXSPI_NAND_EXTENDED_FUNCTION_COUNT] =
 * {
 *   &Func
 * };
 *
*/

CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC) vMem_30_vXSpi_Nand_HwSpecificFunctions[VMEM_30_VXSPI_NAND_EXTENDED_FUNCTION_COUNT] = { 
  vMem_30_vXSpi_Nand_ReplaceLogicalSector,
  vMem_30_vXSpi_Nand_GetLastErrorState,
  vMem_30_vXSpi_Nand_RecoverData
};

#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

vMem_30_vXSpi_Nand_DieIndexType vMem_30_vXSpi_Nand_ActiveDie[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()] = {0u};

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLPerformBlankCheck()
 *********************************************************************************************************************/
/*! \brief       Compares the previously read page byte-wise with the instance specific erase value.
 *  \details     -
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLPerformBlankCheck(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob()
 *********************************************************************************************************************/
/*! \brief        This function triggers the execution of the previously stored user job.
 *  \details      This function is called after an instance is successfully initialized. The previously stored
 *                user job parameters are passed to one of the service functions vMem_LLRead(), vMem_LLWrite()
 *                or vMem_LLErase() according to the job type.
 *  \param[in]    InstanceId       ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

#if (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLIsSameDie()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed addresses lie in the same vMemDie.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]   Address1          First memory address to check.
 * \param[in]   Address2          Second memory address to check.
 * \return      TRUE, if the addresses are located on the same vMemDie; FALSE otherwise.
 * \pre         VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT enabled.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEM_30_VXSPI_NAND_LOCAL_INLINE FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLIsSameDie(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address1,
    vMem_30_vXSpi_Nand_AddressType Address2
  );

#endif /* (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * \brief      Asynchronous service to replace a logical sector.
 * \details    If requested sector is replaceable this service replaces this sector with an available replacement
 *             sector. Parameter checks are done within vMem_30_vXSpi_Nand_ReplaceLogicalSector.
 * \param[in]  InstanceId  ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]  ReqSpecificData  Pointer to a variable of type vMem_30_vXSpi_Nand_ReplaceSectorType.
 *                                 Contains the address of the sector which shall be replaced.
 *                                 After job is processed contains information if no available replacing sector is 
 *                                 remaining or if sector is replaceable and if so, the startaddress of the replacing
 *                                 sector which is used.
 * \param[in]  SizeOfData          Size of ReqSpecificData in this case size of vMem_30_vXSpi_Nand_ReplaceSectorType.
 * \return      E_OK job accepted, E_NOT_OK otherwise (only in case runtime pending check fails).
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLReplaceLogicalSector(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
  );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLRecoverData()
 *********************************************************************************************************************/
/*!
 * \brief      Asynchronous service to recover data from one sector to another.
 * \details    Mirrors the data from one sector completely to another sector. Parameter checks are done within
 *             vMem_30_vXSpi_Nand_RecoverData.
 * \param[in]  InstanceId       ID of the related vMem_30_vXSpi_Nand instance, must be valid.
 * \param[in]  ReqSpecificData  Pointer to a variable of type vMem_30_vXSpi_Nand_RecoverDataType.
 *                              Contains the startaddresses of the sector from which data should be recovered and to 
 *                              which the data should be recovered.
 * \param[in]  SizeOfData       Size of ReqSpecificData in this case size of vMem_30_vXSpi_Nand_RecoverDataType.
 * \return     E_OK job accepted, E_NOT_OK otherwise (only in case runtime pending check fails).
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLRecoverData(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_RecoverDataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
  );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLStatemachineProcessing()
 *********************************************************************************************************************/
/*! \brief       Processes the LowLevel state machine for the given instance.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLStatemachineProcessing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId
   );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail()
 *********************************************************************************************************************/
/*! \brief       Handles failed jobs.
 *  \details     Resets the jobProgress, saves JobResult and JobError if no further actions are required.
 *               Triggers subsequent sub state machines if further jobs shall be executed automatically. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/   
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError
  );

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail()
 *********************************************************************************************************************/
/*! \brief       Handles successful jobs.
 *  \details     Resets the jobProgress, saves JobResult and JobError if no further actions are required.
 *               Triggers subsequent sub state machines if further jobs shall be executed automatically. 
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/     
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError
  );

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLPerformBlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLPerformBlankCheck(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType blankCheckBuffer = (vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType)vMem_30_vXSpi_Nand_LL_Cfg_GetBlankCheckBufferArrayOfPCConfig();
  vMem_30_vXSpi_Nand_EraseValueOfvMemDeviceConfigType eraseValue = vMem_30_vXSpi_Nand_LL_CfgDevice_GetEraseValue(InstanceId);
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstanceType blankCheckBufferStartIdx = vMem_30_vXSpi_Nand_LL_CfgInstance_GetBlankCheckBufferArrayStartIdxOfvMemInstance(InstanceId);
  vMem_30_vXSpi_Nand_BlankCheckBufferArrayOne2SortedNStartIdxOfvMemInstanceType bufferIterator;
  vMem_30_vXSpi_Nand_PageSizeOfMemSectorType pageSize = vMem_30_vXSpi_Nand_LL_CfgSector_GetPageSizeOfMemSector(processedInstance->AffectedSectorIndex);

  processedInstance->JobResult = VMEM_JOB_OK; /* VCA_VXSPI_VALID_INSTANCE_ID */

  for (bufferIterator = blankCheckBufferStartIdx; bufferIterator < (blankCheckBufferStartIdx + pageSize); bufferIterator++)
  {
    if (blankCheckBuffer[bufferIterator] != (vMem_30_vXSpi_Nand_vXSpiDataType) eraseValue)
    {
      processedInstance->JobResult = VMEM_MEM_NOT_BLANK; /* VCA_VXSPI_VALID_INSTANCE_ID */
      break;
    }
  }
  processedInstance->JobProgress = VMEM_30_VXSPI_NAND_IDLE; /* VCA_VXSPI_VALID_INSTANCE_ID */
} /* vMem_30_vXSpi_Nand_LLPerformBlankCheck */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_JobParamBackupPtrType JobParametersPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  vMem_30_vXSpi_Nand_JobParamBackupPtrType jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[InstanceId];

  jobParamBackupPtr->Address = JobParametersPtr->Address; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->SourceAddressPtr = JobParametersPtr->SourceAddressPtr; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->TargetAddressPtr = JobParametersPtr->TargetAddressPtr; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->Length = JobParametersPtr->Length; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->AccessType = JobParametersPtr->AccessType; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->ErrorType = JobParametersPtr->ErrorType; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->ReplaceSectorInfo = JobParametersPtr->ReplaceSectorInfo; /* VCA_VXSPI_VALID_INSTANCE_ID */
  jobParamBackupPtr->RecoverDataInfo = JobParametersPtr->RecoverDataInfo; /* VCA_VXSPI_VALID_INSTANCE_ID */
} /* vMem_30_vXSpi_Nand_LLStoreUserRequestedJob */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_ConstJobParamBackupPtrType jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[InstanceId];

  switch (jobParamBackupPtr->AccessType)
  {
  case VMEM_30_VXSPI_NAND_ERASE_ACCESS:
    (void) vMem_30_vXSpi_Nand_LLErase(InstanceId, 
             jobParamBackupPtr->Address, 
             jobParamBackupPtr->Length);
    break;
  case VMEM_30_VXSPI_NAND_WRITE_ACCESS:
    (void) vMem_30_vXSpi_Nand_LLWrite(InstanceId, /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInLoadUserRequestedJob */
             jobParamBackupPtr->Address, 
             jobParamBackupPtr->SourceAddressPtr, 
             jobParamBackupPtr->Length);
    break;
  case VMEM_30_VXSPI_NAND_READ_ACCESS:
    (void) vMem_30_vXSpi_Nand_LLRead(InstanceId, /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInLoadUserRequestedJob */
             jobParamBackupPtr->Address, 
             jobParamBackupPtr->TargetAddressPtr, 
             jobParamBackupPtr->Length);
    break;
  case VMEM_30_VXSPI_NAND_REPLACE_LOGICAL_SECTOR_ACCESS:
    (void) vMem_30_vXSpi_Nand_LLReplaceLogicalSector(InstanceId, /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInLoadUserRequestedJob */
             jobParamBackupPtr->ReplaceSectorInfo, 
             jobParamBackupPtr->Length);
    break;
  case VMEM_30_VXSPI_NAND_RECOVER_DATA_ACCESS:
    (void) vMem_30_vXSpi_Nand_LLRecoverData(InstanceId, /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInLoadUserRequestedJob */
             jobParamBackupPtr->RecoverDataInfo, 
             jobParamBackupPtr->Length);
    break;
  default: /* VMEM_30_VXSPI_NAND_BLANK_CHECK_ACCESS */
    (void) vMem_30_vXSpi_Nand_LLIsBlank(InstanceId, /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInLoadUserRequestedJob */
             jobParamBackupPtr->Address, 
             jobParamBackupPtr->Length);
    break;
  }
} /* vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob */

#if (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLIsSameDie()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL_INLINE FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLIsSameDie(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address1,
    vMem_30_vXSpi_Nand_AddressType Address2)
{
  uint32 sectorIndex1 = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, Address1);
  uint32 sectorIndex2 = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, Address2);
  uint32 dieIndex1 = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex1);
  uint32 dieIndex2 = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex2);
  return (dieIndex1 == dieIndex2) ? TRUE : FALSE;
} /* vMem_30_vXSpi_Nand_LLIsSameDie */

#endif /* (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLStatemachineProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLStatemachineProcessing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId
)
{
  vMem_30_vXSpi_Nand_ConstInstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];

  switch (processedInstance->JobProgress)
  {
      case VMEM_30_VXSPI_NAND_INIT_HW:
        vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing(InstanceId);
        break;
      case VMEM_30_VXSPI_NAND_EXECUTE_READ:
        vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing(InstanceId);
        break;
      case VMEM_30_VXSPI_NAND_EXECUTE_MODIFICATION:
        vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing(InstanceId);
        break;
      case VMEM_30_VXSPI_NAND_EXECUTE_BLANK_CHECK:
        vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing(InstanceId);
        break;
      case VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR:
        vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_Processing(InstanceId);
        break;
      case VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA:
        vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing(InstanceId);
        break;
      default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
        break;
  }
} /* vMem_30_vXSpi_Nand_LLStatemachineProcessing */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLReplaceLogicalSector(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
  )
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;

  jobParam.Address = ReqSpecificData->TargetSectorAddress;
  jobParam.SourceAddressPtr = NULL_PTR;
  jobParam.TargetAddressPtr = NULL_PTR;
  jobParam.Length = SizeOfData;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_REPLACE_LOGICAL_SECTOR_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = ReqSpecificData;
  jobParam.RecoverDataInfo = NULL_PTR;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);

  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector(InstanceId, ReqSpecificData);

    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLReplaceLogicalSector */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLRecoverData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLRecoverData(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_RecoverDataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
  )
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;

  jobParam.Address = ReqSpecificData->SourceSectorAddress;
  jobParam.SourceAddressPtr = NULL_PTR;
  jobParam.TargetAddressPtr = NULL_PTR;
  jobParam.Length = SizeOfData;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_RECOVER_DATA_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = NULL_PTR;
  jobParam.RecoverDataInfo = ReqSpecificData;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);

  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData(InstanceId, 
               ReqSpecificData->SourceSectorAddress,
               ReqSpecificData->TargetSectorAddress);

    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    /*! When the return value is E_NOT_OK, vMem_30_vXSpi_Nand_LL_Cbk_JobFinished was already called inside 
        vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData, therefore an else path like in the other 
        service functions is not necessary here. */
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLRecoverData */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_SetProcessFlag()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_SetProcessFlag(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
} /* vMem_30_vXSpi_Nand_LL_SetProcessFlag */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded(vMem_30_vXSpi_Nand_InstanceIdType instanceId)
{
   vMem_30_vXSpi_Nand_LLTriggerUserRequestedJob(instanceId);
}/* vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail()
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
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError
  )
{
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupPtrType jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[InstanceId];
  vMem_30_vXSpi_Nand_AutomatedBadBlockInfoPtrType automatedBadBlockInfoPtr = &vMem_30_vXSpi_Nand_AutomatedBadBlockInfo[InstanceId];

  if(processedInstance->JobProgress == VMEM_30_VXSPI_NAND_EXECUTE_BLANK_CHECK)
  {
    vMem_30_vXSpi_Nand_LLPerformBlankCheck(InstanceId);
  }
  else if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsAutomatedBadBlockManagmentUsedOfvMemInstance(InstanceId))
         && (processedInstance->JobProgress == VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR))
  {
    if((automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError == VMEM_30_VXSPI_NAND_P_FAIL)
      || (automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError == VMEM_30_VXSPI_NAND_R_FAIL))
    {
      (void)vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData(InstanceId, 
           automatedBadBlockInfoPtr->ReplaceSectorInfo.RecoverDataSourceAddress,
           automatedBadBlockInfoPtr->ReplaceSectorInfo.TargetSectorAddress);

      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else /* E_FAIL */
    {
      processedInstance->JobResult = VMEM_JOB_OK; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_IDLE; /* VCA_VXSPI_VALID_INSTANCE_ID */
      automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError = VMEM_30_VXSPI_NAND_NO_FAIL; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
  }
  else if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsAutomatedBadBlockManagmentUsedOfvMemInstance(InstanceId))
    && (processedInstance->JobProgress == VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA))
  {
    processedInstance->JobResult = VMEM_JOB_FAILED; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_IDLE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError = VMEM_30_VXSPI_NAND_NO_FAIL; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
  else{
    processedInstance->JobResult = JobResult; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_IDLE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    jobParamBackupPtr->ErrorType = JobError; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
} /* vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail()
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
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError
  )
{
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupPtrType jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[InstanceId];
  vMem_30_vXSpi_Nand_AutomatedBadBlockInfoPtrType automatedBadBlockInfoPtr = &vMem_30_vXSpi_Nand_AutomatedBadBlockInfo[InstanceId];

#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
  if (processedInstance->JobProgress == VMEM_30_VXSPI_NAND_INIT_HW)
  {
    (void) Det_ReportRuntimeError(VMEM_30_VXSPI_NAND_MODULE_ID, VMEM_30_VXSPI_NAND_INSTANCE_ID_DET,
        VMEM_30_VXSPI_NAND_SID_MAIN_FUNCTION, VMEM_30_VXSPI_NAND_RUNTIME_E_INITIALIZATION_FAILED);
  }
#endif
  if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsAutomatedBadBlockManagmentUsedOfvMemInstance(InstanceId))
     && (processedInstance->JobProgress == VMEM_30_VXSPI_NAND_EXECUTE_RECOVER_DATA))
  {
    /* at this place automatedBadBlockInfoPtr->ReplaceSectorInfo.TargetSectorAddress
      is already set from previous replace logical sector. */
    automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError = VMEM_30_VXSPI_NAND_R_FAIL; /* VCA_VXSPI_VALID_INSTANCE_ID */
    (void)vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector(InstanceId, &automatedBadBlockInfoPtr->ReplaceSectorInfo);
    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
  else if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsAutomatedBadBlockManagmentUsedOfvMemInstance(InstanceId))
    && ((JobError == VMEM_30_VXSPI_NAND_P_FAIL) || (JobError == VMEM_30_VXSPI_NAND_E_FAIL)))
  {
    automatedBadBlockInfoPtr->ReplaceSectorInfo.TargetSectorAddress = jobParamBackupPtr->Address; /* VCA_VXSPI_VALID_INSTANCE_ID */
    automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError = JobError; /* VCA_VXSPI_VALID_INSTANCE_ID */
    (void)vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_PerformReplaceLogicalSector(InstanceId, &automatedBadBlockInfoPtr->ReplaceSectorInfo);
    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_REPLACE_LOGICAL_SECTOR; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
  else
  {
    processedInstance->JobResult = JobResult; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedInstance->JobProgress = VMEM_30_VXSPI_NAND_IDLE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    jobParamBackupPtr->ErrorType = JobError; /* VCA_VXSPI_VALID_INSTANCE_ID */
  }
} /* vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_JobFinished()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_JobResultType JobResult,
  vMem_30_vXSpi_Nand_JobErrorType JobError
  )
{
  if(JobError == VMEM_30_VXSPI_NAND_NO_FAIL) /* vMem job succeeded. */
  {
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedNoFail(InstanceId, JobResult, JobError);
  }
  else /* vMem job failed */
  {
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinishedFail(InstanceId, JobResult, JobError);
  }
} /* vMem_30_vXSpi_Nand_LL_Cbk_JobFinished */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance;

  processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];

  if (vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult(InstanceId) == VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_FAILED)
  {
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
  else
  {
    processedInstance->ProcessFlag = TRUE;
  }
} /* vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLRead(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType SourceAddress,
  vMem_30_vXSpi_Nand_DataPtrType TargetAddressPtr,
  vMem_30_vXSpi_Nand_LengthType Length)
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;

  jobParam.Address = SourceAddress;
  jobParam.SourceAddressPtr = NULL_PTR;
  jobParam.TargetAddressPtr = TargetAddressPtr;
  jobParam.Length = Length;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_READ_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = NULL_PTR;
  jobParam.RecoverDataInfo = NULL_PTR;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);

  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess(InstanceId, SourceAddress,
        (vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType) TargetAddressPtr, Length); /* PRQA S 0316 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */

    if (retVal == E_OK)
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_READ; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLRead */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLWrite(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_ConstDataPtrType SourceAddressPtr,
  vMem_30_vXSpi_Nand_LengthType Length)
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;

  jobParam.Address = TargetAddress;
  jobParam.SourceAddressPtr = SourceAddressPtr;
  jobParam.TargetAddressPtr = NULL_PTR;
  jobParam.Length = Length;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_WRITE_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = NULL_PTR;
  jobParam.RecoverDataInfo = NULL_PTR;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);

  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess(InstanceId, TargetAddress,
        (vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType) SourceAddressPtr, Length); /* PRQA S 0316 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */

    if (retVal == E_OK)
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_MODIFICATION; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLWrite */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLErase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLErase(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_LengthType Length)
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;

  jobParam.Address = TargetAddress;
  jobParam.SourceAddressPtr = NULL_PTR;
  jobParam.TargetAddressPtr = NULL_PTR;
  jobParam.Length = Length;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_ERASE_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = NULL_PTR;
  jobParam.RecoverDataInfo = NULL_PTR;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);


  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess(InstanceId, TargetAddress);

    if (retVal == E_OK)
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_MODIFICATION; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLErase */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLIsBlank
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLIsBlank(
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
  vMem_30_vXSpi_Nand_AddressType TargetAddress,
  vMem_30_vXSpi_Nand_LengthType Length)
{
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId];
  vMem_30_vXSpi_Nand_JobParamBackupType jobParam;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType blankCheckBuffer = (vMem_30_vXSpi_Nand_vXSpiDataPtrType)vMem_30_vXSpi_Nand_LL_Cfg_GetBlankCheckBufferArrayOfPCConfig();

  jobParam.Address = TargetAddress;
  jobParam.SourceAddressPtr = NULL_PTR;
  jobParam.TargetAddressPtr = NULL_PTR;
  jobParam.Length = Length;
  jobParam.AccessType = VMEM_30_VXSPI_NAND_BLANK_CHECK_ACCESS;
  jobParam.ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;
  jobParam.ReplaceSectorInfo = NULL_PTR;
  jobParam.RecoverDataInfo = NULL_PTR;
  vMem_30_vXSpi_Nand_LLStoreUserRequestedJob(InstanceId, &jobParam);

  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(InstanceId) == TRUE)
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess(InstanceId, TargetAddress,
        &blankCheckBuffer[vMem_30_vXSpi_Nand_LL_CfgInstance_GetBlankCheckBufferArrayStartIdxOfvMemInstance(InstanceId)], /* PRQA S 0316 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
        Length);

    if (retVal == E_OK)
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_EXECUTE_BLANK_CHECK; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->AffectedSectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, TargetAddress); /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    retVal = vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(InstanceId); /* SBSW_vMem_30_vXSpi_Nand_FunctionCallInitiateHwInitialization */
    if(retVal == E_OK) 
    {
      processedInstance->JobProgress = VMEM_30_VXSPI_NAND_INIT_HW; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->JobResult = VMEM_JOB_PENDING; /* VCA_VXSPI_VALID_INSTANCE_ID */
      processedInstance->ProcessFlag = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LLIsBlank */

/**********************************************************************************************************************
 * vMem_30_vXSpi_Nand_LLGetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMem_30_vXSpi_Nand_JobResultType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLGetJobResult(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  return vMem_30_vXSpi_Nand_InstanceJobInfo[InstanceId].JobResult;
} /* vMem_30_vXSpi_Nand_LLGetJobResult */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_ReplaceLogicalSector
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
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_ReplaceLogicalSector( /* vMem_30_vXSpi_Nand_ReplaceLogicalSector */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_VXSPI_NAND_E_NO_ERROR;
  Std_ReturnType retVal;

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_vXSpi_Nand_IsInstanceIdValid(InstanceId) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_vXSpi_Nand_LLGetJobResult(InstanceId) == VMEM_JOB_PENDING)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PENDING;
  }
  else if (ReqSpecificData == NULL_PTR)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_POINTER;
  }
  /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
  else if(vMem_30_vXSpi_Nand_IsAddressPageAligned(InstanceId, ((vMem_30_vXSpi_Nand_ReplaceSectorPtrType)ReqSpecificData)->TargetSectorAddress) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_ADDRESS;
  }
  else if (SizeOfData != sizeof(vMem_30_vXSpi_Nand_ReplaceSectorType))
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* If Checks passed attempt the sector replacement for the requested address. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
    retVal = vMem_30_vXSpi_Nand_LLReplaceLogicalSector(InstanceId, (vMem_30_vXSpi_Nand_ReplaceSectorPtrType)ReqSpecificData, SizeOfData);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_VXSPI_NAND_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_VXSPI_NAND_MODULE_ID, VMEM_30_VXSPI_NAND_INSTANCE_ID_DET, VMEM_30_VXSPI_NAND_SID_REPLACE_LOGICAL_SECTOR, errorId);
  }
#else
  VMEM_30_VXSPI_NAND_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_GetLastErrorState
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
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_GetLastErrorState(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData
    )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_VXSPI_NAND_E_NO_ERROR;
  uint8 columnAddressLength;
  Std_ReturnType retVal;
  vMem_30_vXSpi_Nand_ConvertedAddressType convertedAddress;

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_vXSpi_Nand_IsInstanceIdValid(InstanceId) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_INSTANCE_ID;
  }
  else if (ReqSpecificData == NULL_PTR)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_POINTER;
  }
  else if (SizeOfData != sizeof(vMem_30_vXSpi_Nand_ErrorStateType))
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_LENGTH;
  }
  else
#else
  /* The signature of the extended hardware specific functionality is defined by the vMemAccM.
   * For this service the parameter SizeOfData is not needed if Development Error Checks are disabled.
   */
  VMEM_30_VXSPI_NAND_DUMMY_STATEMENT(SizeOfData);
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    vMem_30_vXSpi_Nand_ConstJobParamBackupPtrType jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[InstanceId];
    
    /* convert the last requested address to the startAddress of the corresponding sector. */
    vMem_30_vXSpi_Nand_ConvertAddress(InstanceId, jobParamBackupPtr->Address, &convertedAddress);
    columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(InstanceId, jobParamBackupPtr->Address);

    /* fill the ReSpecificData Pointer with informations about the last error. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
    ((vMem_30_vXSpi_Nand_ErrorStateType*)ReqSpecificData)->currentJob = jobParamBackupPtr->AccessType; /* VCA_VXSPI_VALID_INSTANCE_ID, VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */
    /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
    ((vMem_30_vXSpi_Nand_ErrorStateType*)ReqSpecificData)->currentErrorAddressOrigin = /* VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */
      ((vMem_30_vXSpi_Nand_AddressType)convertedAddress.SectorStartAddress) << columnAddressLength;
    /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
    ((vMem_30_vXSpi_Nand_ErrorStateType*)ReqSpecificData)->currentErrorState = jobParamBackupPtr->ErrorType; /* VCA_VXSPI_VALID_INSTANCE_ID, VCA_VXSPI_VALID_REQ_SPECIFIC_DATA */

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_VXSPI_NAND_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_VXSPI_NAND_MODULE_ID, VMEM_30_VXSPI_NAND_INSTANCE_ID_DET, VMEM_30_VXSPI_NAND_SID_GET_LAST_ERROR_STATE, errorId);
  }
#else
  VMEM_30_VXSPI_NAND_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_vXSpi_Nand_GetLastErrorState */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_RecoverData
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
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_RecoverData( /* vMem_30_vXSpi_Nand_RecoverData */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DataPtrType ReqSpecificData,
    vMem_30_vXSpi_Nand_LengthType SizeOfData)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_VXSPI_NAND_E_NO_ERROR;
  Std_ReturnType retVal;

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_vXSpi_Nand_IsInstanceIdValid(InstanceId) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_vXSpi_Nand_LLGetJobResult(InstanceId) == VMEM_JOB_PENDING)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PENDING;
  }
  else if (ReqSpecificData == NULL_PTR)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_POINTER;
  }
  /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
  else if(vMem_30_vXSpi_Nand_IsAddressPageAligned(InstanceId, ((vMem_30_vXSpi_Nand_RecoverDataPtrType)ReqSpecificData)->SourceSectorAddress) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_ADDRESS;
  }
  /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
  else if(vMem_30_vXSpi_Nand_IsAddressPageAligned(InstanceId, ((vMem_30_vXSpi_Nand_RecoverDataPtrType)ReqSpecificData)->TargetSectorAddress) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_ADDRESS;
  }
  /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
  else if (vMem_30_vXSpi_Nand_LLIsSameDie(InstanceId, ((vMem_30_vXSpi_Nand_RecoverDataPtrType)ReqSpecificData)->SourceSectorAddress, ((vMem_30_vXSpi_Nand_RecoverDataPtrType)ReqSpecificData)->TargetSectorAddress) == FALSE)
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_ADDRESS;
  }
  else if (SizeOfData != sizeof(vMem_30_vXSpi_Nand_RecoverDataType))
  {
    retVal = E_NOT_OK;
    errorId = VMEM_30_VXSPI_NAND_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* If Checks passed attempt to recover data for the requested address. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr */
    retVal = vMem_30_vXSpi_Nand_LLRecoverData(InstanceId, (vMem_30_vXSpi_Nand_RecoverDataPtrType)ReqSpecificData, SizeOfData);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_VXSPI_NAND_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_VXSPI_NAND_MODULE_ID, VMEM_30_VXSPI_NAND_INSTANCE_ID_DET, VMEM_30_VXSPI_NAND_SID_RECOVER_DATA, errorId);
  }
#else
  VMEM_30_VXSPI_NAND_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLProcessing(void)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId;

  for (instanceId = 0; instanceId < vMem_30_vXSpi_Nand_GetSizeOfvMemInstance(); instanceId++)
  {
    vMem_30_vXSpi_Nand_InstanceJobPtrType processedInstance = &vMem_30_vXSpi_Nand_InstanceJobInfo[instanceId];

    vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing(instanceId);

    while (processedInstance->ProcessFlag == TRUE)
    {
      processedInstance->ProcessFlag = FALSE;
      vMem_30_vXSpi_Nand_LLStatemachineProcessing(instanceId);
      vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing(instanceId);
#ifdef VMEM_30_VXSPI_NAND_TEST_SUITE_CODE /* COV_TEST_SUITE */
      break;
#endif /* VMEM_30_VXSPI_NAND_TEST_SUITE_CODE */
    }
  }
} /* vMem_30_vXSpi_Nand_LLProcessing */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LLInit
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
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LLInit(void)
{
  vMem_30_vXSpi_Nand_JobParamBackupPtrType jobParamBackupPtr;
  vMem_30_vXSpi_Nand_AutomatedBadBlockInfoPtrType automatedBadBlockInfoPtr;
  vMem_30_vXSpi_Nand_InstanceIdType instanceId;

  for (instanceId = 0; instanceId < vMem_30_vXSpi_Nand_GetSizeOfvMemInstance(); instanceId++)
  {
    vMem_30_vXSpi_Nand_InstanceJobInfo[instanceId].JobProgress = VMEM_30_VXSPI_NAND_IDLE;
    vMem_30_vXSpi_Nand_InstanceJobInfo[instanceId].JobResult = VMEM_JOB_OK;
    vMem_30_vXSpi_Nand_InstanceJobInfo[instanceId].ProcessFlag = FALSE;

    jobParamBackupPtr = &vMem_30_vXSpi_Nand_JobParamBackup[instanceId];
    jobParamBackupPtr->AccessType = VMEM_30_VXSPI_NAND_NO_JOB;
    jobParamBackupPtr->ErrorType = VMEM_30_VXSPI_NAND_NO_FAIL;

    automatedBadBlockInfoPtr = &vMem_30_vXSpi_Nand_AutomatedBadBlockInfo[instanceId];
    automatedBadBlockInfoPtr->ReplaceSectorInfo.LastJobError = VMEM_30_VXSPI_NAND_NO_FAIL;
  }

  vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init();

  return E_OK;
} /* vMem_30_vXSpi_Nand_LLInit */

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:
 MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr: rule 11.5
    Reason:     vMem accepts untyped void pointers in its hardware specific functionality, to provide a compatible
                interface for different hardware specific function implementations: one may get a structure of type A,
                the other of type B etc. With a void pointer interface the signature of all the functions keeps the same
                as can be used in one typed function pointer array.
                vMem also accepts void pointers for user buffers. During a write job vMem has to split the passed
                buffer into words. Therefore, the buffer is cast to a pointer of type uint32.
    Risk:       Possible mismatch of pointer type and given length parameter after cast of untyped void pointer.
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.

 MD_vMem_30_vXSpi_Nand_PtrCastLossOfConst: rule 11.5
    Reason:     Dangerous pointer cast results in loss of const qualification.
    Risk:       An element the pointer is pointing to can be manipulated without a const qualifier.
    Prevention: vMem ensures that the element the pointer is pointing to is never manipulated.

 MD_CRC_2.1_StaticFunctionNotUsed:
    Reason: These inline functions are defined as a utility functionality and shall be accessible by each translation
            unit of the component. In some cases this functionality might not be used. This is not a problem as the
            compiler will optimize this code away in this case.
    Risk: No risk.
    Prevention: A compile switch could be introduced.

  MD_vMem_30_vXSpi_Nand_ReturnNotUsed:
    Reason:     vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage must return a value if and only if it is called for the 
                first time, because only then the jobProgress of the first level state machine is set. Within the second 
                level statemachine vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage gets then called multiple times to
                copy all remaining pages of a sector. The return value must not be used then, since the jobProgress is
                already set.
    Risk:       No risk.
    Prevention: Implementation ensures that return value is used when needed.
 */

/* VCA_JUSTIFICATION_BEGIN
\ID VCA_VXSPI_VALID_INSTANCE_ID
  \DESCRIPTION Write access to a pointer indirectly using the passed indexing parameter 'InstanceId'.
  \COUNTERMEASURE \R The caller ensures that the passed 'InstanceId' is always valid.
\ID VCA_VXSPI_VALID_REQ_SPECIFIC_DATA
  \DESCRIPTION Write access to a ReqSpecificData pointer which could be null.
  \COUNTERMEASURE \R The DET check in vMem_30_vXSpi_Nand_ReplaceLogicalSector() ensures that the ReqSpecificData is not a NULL pointer.
\ID VCA_VXSPI_VALID_ADDRESS
  \DESCRIPTION given address pointer could be invalid.
  \COUNTERMEASURE \R vMem_30_vXSpi_Nand_IsAddressPageAligned() DET check ensures that the TargetSectorAddress is existing in the porper
                     sector and is page aligned.
                  \R bounds in the vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer_FindFirstAvailableReplacingSectorAddress() while loops
                     ensure that the replacingSectorAddress is not out of bounds
\ID VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION
  \DESCRIPTION A function with pointer parameters is directly called, but the function is not defined within the analyzed sources. VCA is unable to determine the
               behavior of the function.
  \COUNTERMEASURE \R The vXSpi component ensures that the passed pointer parameters are properly handled.

\ID VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX
  \DESCRIPTION A function with pointer parameters is directly called, it needs to be ensured that the given DataBuffer and DataLength
  in the given parameter dataAndLength are corresponding to each other. The given dataBuffer array needs to be long at least as the
  given parameter DataLength.
  \COUNTERMEASURE \N Since in the underlying function it is only beeing read from the DataBuffer, there is no danger
                   of the driver overwriting some other memory space, even if the DataBuffer and DataLength do not match.

\ID VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX
  \DESCRIPTION A function with a pointer to the local structure is directly called. 
               The structure holds the pointer to the data buffer and the data buffer length variable.
               The function expects that the given data buffer and data length in the given function parameter are corresponding to each other.
               The given data buffer array shall have size at least as the given parameter data length.
  \COUNTERMEASURE \S Verify that the user data buffer(TargetAddressPtr) passed to the vMem_30_vXSpi_Nand_Read()
                    is greater than or equal to the length of data to be read.
                     Verify that the values in the StatusRegisterDataBufferLength column of the generated vMem_30_vXSpi_Nand_vMemDeviceConfig table 
                    are not bigger than the VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH.
                     Verify that the values in the VolatileConfigurationRegisterDataBufferLength column of the generated vMem_30_vXSpi_Nand_vMemDeviceConfig table 
                    are not bigger than the VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH.
                     Verify that the values in the LutDataBufferLength column of the generated vMem_30_vXSpi_Nand_vMemDeviceConfig table 
                    are not bigger than the VMEM_30_VXSPI_NAND_LUT_DATA_BUFFER_LENGTH.
                    SMI-1259035

  VCA_JUSTIFICATION_END */
/* COV_JUSTIFICATION_BEGIN

  \ID COV_VMEM_30_VXSPI_NAND_COMPATIBILITY
    \ACCEPT TX
    \REASON COV_MSR_COMPATIBILITY

  \ID COV_TEST_SUITE
    \ACCEPT XF
    \REASON This code is only used by the test suite for testing purpose. To check the states of the driver.
 COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL.c
 *********************************************************************************************************************/
