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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.c
 *        \brief  Instance data recoverer source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_LL_INSTANCEDATARECOVERER_SOURCE

/*********************************************************************************************************************
 *  INLCUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_IntShared.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined(VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
#define VMEM_30_VXSPI_NAND_LOCAL static
#endif

/*! This enum defines the InstanceDataRecoverers states. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE = 0,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_SELECT_DIE,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_INITIATE_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_EXECUTE_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_WRITE_ENABLE,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_PROGRAM_EXECUTE,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PROGRAM_EXECUTE,
  VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_RESULT
} vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgressType;

/*! Instance's DataRecoverer job type to group an instance's job parameters. */
typedef struct
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;
  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgressType JobProgress;
  vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType BusyCheckTimeoutCounter;
  vMem_30_vXSpi_Nand_vXSpiDataType ResultBitMask;
  vMem_30_vXSpi_Nand_AddressType SourceAddress;
  vMem_30_vXSpi_Nand_AddressType TargetAddress;
  vMem_30_vXSpi_Nand_LL_EccErrorType EccErrorType;
  vMem_30_vXSpi_Nand_PageSizeOfMemSectorType PageSize;
  uint32 NumberOfPages;
  uint8 PageCounter;
} vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobType;

typedef P2VAR(vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobType, VMEM_30_VXSPI_NAND_VAR_NOINIT)
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

/*! Defines a buffer for each configured flash device to store the content of read device registers. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR_NOINIT)
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded()
 *********************************************************************************************************************/
/*! \brief        Resets the instance specific state machine and notifies the vMem_LL about the successfully finished
                  erase operation and if an ECC Error occurred.
 *  \details      -
 *  \param[in]    processedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType processedRecoverDataInstance);


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady()
 *********************************************************************************************************************/
/*! \brief        Checks if the memory device is ready to accept further requests.
 *  \details      -
 *  \param[in]    InstanceId        ID of the related vMem_30_vXSpi_Nand instance.
 *  \return       E_OK              The device is ready.
 *  \return       E_NOT_OK          The device is busy.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors()
 *********************************************************************************************************************/
/*! \brief        Checks if the memory device status register indicates any ECC Errors.
 *  \details      -
 *  \param[in]    InstanceId        ID of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck()
 *********************************************************************************************************************/
/*! \brief        Triggers the check for the busy flag in the status register.
 *  \details      -
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead()
 *********************************************************************************************************************/
/*! \brief        Checks the current progress of the page data read operation after the device's status register
 *                has been read.
 *  \details      Checks the previously read device's BUSY flag.
 *                If the device is still busy, the status register is read once again.
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute()
 *********************************************************************************************************************/
/*! \brief        Checks the current progress of the program execute operation after the device's status register
 *                has been read.
 *  \details      Checks the previously read device's BUSY flag.
 *                If the device is still busy, the status register is read once again.
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess()
 *********************************************************************************************************************/
/*! \brief        Checks if the write error flag is set.
 *  \details      If the write error flag is set the previously performed operation is failed. Else the operations gets 
 *                triggered again from the beginning with the next page of the sector. If all pages are copied the 
 *                operation succeeded.
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage()
 *********************************************************************************************************************/
/*! \brief        Executes the page data read sequence.
 *  \details      -
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to select another die.
 *  \details      -
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to execute the programming.
 *  \details      -
 *  \param[in]    ProcessedRecoverDataInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance);

/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType processedRecoverDataInstance)
{
  processedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;

  if(processedRecoverDataInstance->EccErrorType == VMEM_30_VXSPI_NAND_CORRECTED_ECC_ERROR)
  {
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(processedRecoverDataInstance->InstanceId, VMEM_READ_CORRECTED_ERRORS, VMEM_30_VXSPI_NAND_NO_FAIL);
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(processedRecoverDataInstance->InstanceId, VMEM_JOB_OK, VMEM_30_VXSPI_NAND_NO_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBusyFlagBitMask(InstanceId))) == 0x00u)
  {
    retVal = E_OK;
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc0BitMask(ProcessedRecoverDataInstance->InstanceId))) != 0x00u)
  {
    ProcessedRecoverDataInstance->EccErrorType = VMEM_30_VXSPI_NAND_CORRECTED_ECC_ERROR;
  }

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc1BitMask(ProcessedRecoverDataInstance->InstanceId))) != 0x00u)
  {
    ProcessedRecoverDataInstance->EccErrorType = VMEM_30_VXSPI_NAND_UNCORRECTABLE_ECC_ERROR;
  }
  /*! If the second if condition holds true, the EccErrorType is set to UNCORRECTABLE_ECC_ERROR regardless of the first
      if condition. 
      For the continuous read mode, the W25N01GV device differentiates the third case that both ECC Error flags are set
      true. If the continuous read mode should be implemented this must be kept in mind (datasheet 7.3.2 Notes).
       */
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(ProcessedRecoverDataInstance->InstanceId,
      (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedRecoverDataInstance->InstanceId),
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId], 
      (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedRecoverDataInstance->InstanceId));

  if (sequenceResult == E_OK)
  {
    if(ProcessedRecoverDataInstance->JobProgress == VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_EXECUTE_PAGE_DATA_READ)
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PAGE_DATA_READ;
    }
    else /* Coming from VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_PROGRAM_EXECUTE. */
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PROGRAM_EXECUTE;
    }
  }
  else
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck */


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  /* Check if device is idle. */
  if (vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady(ProcessedRecoverDataInstance->InstanceId) == E_OK)
  {
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckForEccErrors(ProcessedRecoverDataInstance);
    if(ProcessedRecoverDataInstance->EccErrorType == VMEM_30_VXSPI_NAND_UNCORRECTABLE_ECC_ERROR)
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_READ_UNCORRECTABLE_ERRORS, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    } 
    else
    { 
      /* Issue program execute sequence. */
      Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(
          ProcessedRecoverDataInstance->InstanceId);
      
      if (sequenceResult == E_OK)
      {
        ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_WRITE_ENABLE;
      }
      else
      {
        ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
    }
  }
  else
  {
    /* Check timeout. */
    ProcessedRecoverDataInstance->BusyCheckTimeoutCounter--;
    if (ProcessedRecoverDataInstance->BusyCheckTimeoutCounter > 0u)
    {
      /* Read status register. */
      Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
          ProcessedRecoverDataInstance->InstanceId, 
          (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedRecoverDataInstance->InstanceId), 
          vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId], 
          (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedRecoverDataInstance->InstanceId));

      if (sequenceResult == E_NOT_OK)
      {
        ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
    }
    else
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  /* Check if device is idle. */
  if (vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_IsDeviceReady(ProcessedRecoverDataInstance->InstanceId) == E_OK)
  {
    Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
        ProcessedRecoverDataInstance->InstanceId, 
        (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedRecoverDataInstance->InstanceId), 
        vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId], 
        (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedRecoverDataInstance->InstanceId));
    
    if (sequenceResult == E_OK)
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_RESULT;
    }
    else
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    /* Check timeout. */
    ProcessedRecoverDataInstance->BusyCheckTimeoutCounter--;
    if (ProcessedRecoverDataInstance->BusyCheckTimeoutCounter > 0u)
    {
      /* Read status register. */
      Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
          ProcessedRecoverDataInstance->InstanceId, 
          (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedRecoverDataInstance->InstanceId), 
          vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId], 
          (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedRecoverDataInstance->InstanceId));

      if (sequenceResult == E_NOT_OK)
      {
        ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
    }
    else
    {
      ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  if ((((*vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_RegisterDataBuffers[ProcessedRecoverDataInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_vXSpiDataType)(ProcessedRecoverDataInstance->ResultBitMask)) == 0x00u)
  {
    ProcessedRecoverDataInstance->PageCounter++;
    if(ProcessedRecoverDataInstance->PageCounter < ProcessedRecoverDataInstance->NumberOfPages)
    {
      ProcessedRecoverDataInstance->SourceAddress = ProcessedRecoverDataInstance->SourceAddress + ProcessedRecoverDataInstance->PageSize;
      ProcessedRecoverDataInstance->TargetAddress = ProcessedRecoverDataInstance->TargetAddress + ProcessedRecoverDataInstance->PageSize;

      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage(ProcessedRecoverDataInstance); /* PRQA S 3200 */ /* MD_vMem_30_vXSpi_Nand_ReturnNotUsed */
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_JobSucceeded(ProcessedRecoverDataInstance);
    }
  }
  else
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_P_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence(
                              ProcessedRecoverDataInstance->InstanceId, 
                              ProcessedRecoverDataInstance->SourceAddress); /* PRQA S 0316, 0311 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr, MD_vMem_30_vXSpi_Nand_PtrCastLossOfConst */

  if (sequenceResult == E_OK)
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_EXECUTE_PAGE_DATA_READ;
  }
  else
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedRecoverDataInstance->InstanceId, ProcessedRecoverDataInstance->TargetAddress);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
      ProcessedRecoverDataInstance->InstanceId, dieIndex);

  if (sequenceResult == E_OK)
  {
    vMem_30_vXSpi_Nand_ActiveDie[ProcessedRecoverDataInstance->InstanceId] = dieIndex; /* VCA_VXSPI_VALID_INSTANCE_ID */
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_INITIATE_PAGE_DATA_READ;
  }
  else
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute(
    vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType ProcessedRecoverDataInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence(
      ProcessedRecoverDataInstance->InstanceId,
      ProcessedRecoverDataInstance->TargetAddress);

  if (sequenceResult == E_OK)
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_PROGRAM_EXECUTE;
  }
  else
  {
    ProcessedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedRecoverDataInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute */


/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_AddressType TargetAddress
    )
{
  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType processedRecoverDataInstance =
    &vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobInfo[InstanceId];

  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, SourceAddress);
  vMem_30_vXSpi_Nand_PageSizeOfMemSectorType pageSize = vMem_30_vXSpi_Nand_LL_CfgSector_GetPageSizeOfMemSector(sectorIndex);

  processedRecoverDataInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->BusyCheckTimeoutCounter = vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceId); /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->ResultBitMask = (vMem_30_vXSpi_Nand_vXSpiDataType)vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProgramErrorBitMask( /* VCA_VXSPI_VALID_INSTANCE_ID */
        InstanceId);
  processedRecoverDataInstance->SourceAddress = SourceAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->TargetAddress = TargetAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->PageCounter = 0; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->PageSize = pageSize; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->NumberOfPages = vMem_30_vXSpi_Nand_GetSectorSizeOfMemSector(sectorIndex) / pageSize; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->EccErrorType = VMEM_30_VXSPI_NAND_NO_ECC_ERROR; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_SELECT_DIE; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_PerformRecoverData() */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing(vMem_30_vXSpi_Nand_InstanceIdType InstanceId) /* vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_Processing */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
{
  vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobPtrType processedRecoverDataInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_InstanceJobInfo[InstanceId];

  switch (processedRecoverDataInstance->JobProgress)
  {
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_SELECT_DIE:
    {
      uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(processedRecoverDataInstance->InstanceId,
          processedRecoverDataInstance->TargetAddress);
      vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

      if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(processedRecoverDataInstance->InstanceId))
         && (vMem_30_vXSpi_Nand_ActiveDie[processedRecoverDataInstance->InstanceId] != dieIndex))
      {
        vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_SelectDie(processedRecoverDataInstance);
      }
      else
      {
        processedRecoverDataInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_INITIATE_PAGE_DATA_READ;
        vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
      }
    }
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_INITIATE_PAGE_DATA_READ:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ReadPage(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_EXECUTE_PAGE_DATA_READ:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PAGE_DATA_READ:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressPageDataRead(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_WRITE_ENABLE:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_ProgramExecute(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_PROGRAM_EXECUTE:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_TriggerProgressCheck(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_PROGRESS_PROGRAM_EXECUTE:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckProgressProgramExecute(processedRecoverDataInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_CHECK_RESULT:
      vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer_CheckOperationSuccess(processedRecoverDataInstance);
      break;
    default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* VMEM_30_VXSPI_NAND_INSTANCEDATARECOVERER_IDLE */
      break;
  }
}

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.c
 *********************************************************************************************************************/
