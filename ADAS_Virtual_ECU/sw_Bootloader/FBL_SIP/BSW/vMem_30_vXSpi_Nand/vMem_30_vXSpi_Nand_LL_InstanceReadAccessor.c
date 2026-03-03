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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.c
 *        \brief  Instance read accessor source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_LL_INSTANCEREADACCESSOR_SOURCE

/*********************************************************************************************************************
 *  INLCUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_IntShared.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined(VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
#define VMEM_30_VXSPI_NAND_LOCAL static
#endif

/*! This enum defines the InstanceReadAccessor's states. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE = 0,
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_SELECT_DIE,
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_INITIATE_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_CHECK_PROGRESS_PAGE_DATA_READ,
  VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_READ_DATA
} vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_ProgressType;

/*! Instance's read job type to group an instance's job parameters. */
typedef struct
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_ProgressType JobProgress;
  vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType BusyCheckTimeoutCounter;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType TargetAddressPtr;
  vMem_30_vXSpi_Nand_AddressType SourceAddress;
  vMem_30_vXSpi_Nand_LengthType Length;
  vMem_30_vXSpi_Nand_LengthType LengthToReadInThisCycle;
  vMem_30_vXSpi_Nand_LL_EccErrorType EccErrorType;
} vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobType;

typedef P2VAR(vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Defines a buffer for each configured flash device to store the content of read device registers. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded()
 *********************************************************************************************************************/
/*! \brief        Resets the instance specific state machine and notifies the vMem_LL about the successfully finished
                  erase operation and if a ECC Error occured.
 *  \details      -
 *  \param[in]    processedReadAccessorInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType processedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors()
 *********************************************************************************************************************/
/*! \brief        Checks if the memory device status register indicates any ECC Errors.
 *  \details      -
 *  \param[in]    InstanceId        ID of the related vMem_30_vXSpi_Nand instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck()
 *********************************************************************************************************************/
/*! \brief        Triggers the check for the busy flag in the status register.
 *  \details      -
 *  \param[in]    ProcessedReadAccessorInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead()
 *********************************************************************************************************************/
/*! \brief        Checks the current page data read progress after the device's status register has been read.
 *  \details      Checks the previously read device's BUSY flag.
 *                If the device is still busy, the status register is read once again.
 *  \param[in]    ProcessedReadAccessorInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to select another die.
 *  \details      -
 *  \param[in]    ProcessedReadAccessorInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie(
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence for a "page data read".
 *  \details      -
 *  \param[in]    ProcessedReadAccessorInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead(
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance);

/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType processedReadAccessorInstance)
{
  processedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;

  switch (processedReadAccessorInstance->EccErrorType)
  {
  case VMEM_30_VXSPI_NAND_CORRECTED_ECC_ERROR:
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(processedReadAccessorInstance->InstanceId, VMEM_READ_CORRECTED_ERRORS, VMEM_30_VXSPI_NAND_NO_FAIL);
    break;
  case VMEM_30_VXSPI_NAND_UNCORRECTABLE_ECC_ERROR:
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(processedReadAccessorInstance->InstanceId, VMEM_READ_UNCORRECTABLE_ERRORS, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* VMEM_30_VXSPI_NAND_NO_ECC_ERROR */
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(processedReadAccessorInstance->InstanceId, VMEM_JOB_OK, VMEM_30_VXSPI_NAND_NO_FAIL);
    break;
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[ProcessedReadAccessorInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBusyFlagBitMask(ProcessedReadAccessorInstance->InstanceId))) == 0x00u)
  {
    retVal = E_OK;

    /* Check if the device's status register indicates an ECC Error. */
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors(ProcessedReadAccessorInstance);
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  ProcessedReadAccessorInstance->EccErrorType = VMEM_30_VXSPI_NAND_NO_ECC_ERROR;

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[ProcessedReadAccessorInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc0BitMask(ProcessedReadAccessorInstance->InstanceId))) != 0x00u)
  {
    ProcessedReadAccessorInstance->EccErrorType = VMEM_30_VXSPI_NAND_CORRECTED_ECC_ERROR;
  }

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[ProcessedReadAccessorInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEcc1BitMask(ProcessedReadAccessorInstance->InstanceId))) != 0x00u)
  {
    ProcessedReadAccessorInstance->EccErrorType = VMEM_30_VXSPI_NAND_UNCORRECTABLE_ECC_ERROR;
  }
  /*! If the second if condition holds true, the EccErrorType is set to UNCORRECTABLE_ECC_ERROR regardless of the first
      if condition. 
      For the continuous read mode, the W25N01GV device differentiates the third case that both ECC Error flags are set
      true. If the continuous read mode should be implemented this must be kept in mind (datasheet 7.3.2 Notes).
       */
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckForEccErrors */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
      ProcessedReadAccessorInstance->InstanceId, (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedReadAccessorInstance->InstanceId), 
      vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[ProcessedReadAccessorInstance->InstanceId], 
      (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedReadAccessorInstance->InstanceId));

  if (sequenceResult == E_OK)
  {
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_CHECK_PROGRESS_PAGE_DATA_READ;
  }
  else
  {
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead(
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedReadAccessorInstance->InstanceId, ProcessedReadAccessorInstance->SourceAddress);
  uint32 pageSize = vMem_30_vXSpi_Nand_LL_CfgSector_GetPageSizeOfMemSector(sectorIndex);
  uint32 lengthTillNextPage = pageSize - (ProcessedReadAccessorInstance->SourceAddress % pageSize);
  ProcessedReadAccessorInstance->LengthToReadInThisCycle = ProcessedReadAccessorInstance->Length;

  if(lengthTillNextPage < ((uint32)ProcessedReadAccessorInstance->Length))
  {
    /* If the length of the data beeing read is crossing page boundaries, read only until the page boundaries. */
    ProcessedReadAccessorInstance->LengthToReadInThisCycle = lengthTillNextPage;
  }

  /* Check if device is idle. */
  if (vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_IsDeviceReady(ProcessedReadAccessorInstance) == E_OK)
  {
    /* Issue read page data sequence. */
    Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence(
            ProcessedReadAccessorInstance->InstanceId,
            ProcessedReadAccessorInstance->SourceAddress,
            (vMem_30_vXSpi_Nand_vXSpiDataPtrType)(ProcessedReadAccessorInstance->TargetAddressPtr), /* PRQA S 0316, 0311 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr, MD_vMem_30_vXSpi_Nand_PtrCastLossOfConst */
            (vMem_30_vXSpi_Nand_vXSpiDataLengthType)(ProcessedReadAccessorInstance->LengthToReadInThisCycle));
    if (sequenceResult == E_OK)
    {
      ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_READ_DATA;
    }
    else
    {
      ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    }
  }
  else
  {
    /* Check timeout. */
    ProcessedReadAccessorInstance->BusyCheckTimeoutCounter--;
    if (ProcessedReadAccessorInstance->BusyCheckTimeoutCounter > 0u)
    {
      /* Read status register. */
      Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
          ProcessedReadAccessorInstance->InstanceId, (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedReadAccessorInstance->InstanceId), 
          vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_RegisterDataBuffers[ProcessedReadAccessorInstance->InstanceId], 
          (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedReadAccessorInstance->InstanceId));

      if (sequenceResult == E_OK)
      {
        ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_CHECK_PROGRESS_PAGE_DATA_READ;
      }
      else
      {
        ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
    }
    else
    {
      ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    } 
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie(
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedReadAccessorInstance->InstanceId, ProcessedReadAccessorInstance->SourceAddress);
  vMem_30_vXSpi_Nand_vMemDieIdxOfMemSectorType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
      ProcessedReadAccessorInstance->InstanceId, dieIndex);

  if (sequenceResult == E_OK)
  {
    vMem_30_vXSpi_Nand_ActiveDie[ProcessedReadAccessorInstance->InstanceId] = dieIndex; /* VCA_VXSPI_VALID_INSTANCE_ID */
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_INITIATE_PAGE_DATA_READ;
  }
  else
  {
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead(
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType ProcessedReadAccessorInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence(ProcessedReadAccessorInstance->InstanceId,
      ProcessedReadAccessorInstance->SourceAddress); /* PRQA S 0316, 0311 */ /* MD_vMem_30_vXSpi_Nand_VoidPtrTypedPtr, MD_vMem_30_vXSpi_Nand_PtrCastLossOfConst */

  if (sequenceResult == E_OK)
  {
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_PAGE_DATA_READ;
  }
  else
  {
    ProcessedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedReadAccessorInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead */

/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType TargetAddressPtr, vMem_30_vXSpi_Nand_LengthType Length)
{
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType processedReadAccessorInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobInfo[InstanceId];

    processedReadAccessorInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_SELECT_DIE; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedReadAccessorInstance->BusyCheckTimeoutCounter =  /* VCA_VXSPI_VALID_INSTANCE_ID */
        vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceId);
    processedReadAccessorInstance->TargetAddressPtr = TargetAddressPtr; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedReadAccessorInstance->SourceAddress = SourceAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
    processedReadAccessorInstance->Length = Length; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_PerformReadAccess */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobPtrType processedReadAccessorInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InstanceJobInfo[InstanceId];

  switch (processedReadAccessorInstance->JobProgress)
  {
  case VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_SELECT_DIE:
    {
      uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(processedReadAccessorInstance->InstanceId, processedReadAccessorInstance->SourceAddress);
      uint32 dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

      if(vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(processedReadAccessorInstance->InstanceId)
          && (vMem_30_vXSpi_Nand_ActiveDie[processedReadAccessorInstance->InstanceId] != dieIndex))
      {
        vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_SelectDie(processedReadAccessorInstance);
      }
      else
      {
        processedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_INITIATE_PAGE_DATA_READ;
        vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
      }
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_INITIATE_PAGE_DATA_READ:
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_InitiatePageDataRead(processedReadAccessorInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_PAGE_DATA_READ:
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_TriggerProgressCheck(processedReadAccessorInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_CHECK_PROGRESS_PAGE_DATA_READ:
    vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_CheckProgressPageDataRead(processedReadAccessorInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_EXECUTE_READ_DATA:
    processedReadAccessorInstance->SourceAddress += processedReadAccessorInstance->LengthToReadInThisCycle;
    processedReadAccessorInstance->TargetAddressPtr = &processedReadAccessorInstance->TargetAddressPtr[processedReadAccessorInstance->LengthToReadInThisCycle];
    processedReadAccessorInstance->Length -= processedReadAccessorInstance->LengthToReadInThisCycle;

    if(processedReadAccessorInstance->Length != 0u)
    {
      /* If there is still data left to be read (in case of multiple pages) */
      processedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_INITIATE_PAGE_DATA_READ;
      vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
    }
    else
    {
      /* Reading finished */
      processedReadAccessorInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE;
      vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_JobSucceeded(processedReadAccessorInstance);
    }
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* VMEM_30_VXSPI_NAND_INSTANCEREADACCESSOR_IDLE */
    break;
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceReadAccessor_Processing */

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.c
 *********************************************************************************************************************/
