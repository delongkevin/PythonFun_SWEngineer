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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceModifier.c
 *        \brief  Instance modifier source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_InstanceModifier.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_LL_INSTANCEMODIFIER_SOURCE

/*********************************************************************************************************************
 *  INLCUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_IntShared.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceModifier.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined(VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
#define VMEM_30_VXSPI_NAND_LOCAL static
#endif

/*! This enum defines the InstanceModifier's states. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE = 0,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_SELECT_DIE,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_ENABLE,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_LOAD_PROGRAM_DATA,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE_LOAD_PROGRAM_DATA,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_INITIATE_ERASE,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_PROGRESS,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_RESULT
} vMem_30_vXSpi_Nand_LL_InstanceModifier_ProgressType;

typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_JOB,
  VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_ERASE_JOB
}vMem_30_vXSpi_Nand_LL_InstanceModifier_JobType;

/*! Instance's write/erase job type to group an instance's job parameters. */
typedef struct
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;
  vMem_30_vXSpi_Nand_LL_InstanceModifier_ProgressType JobProgress;
  vMem_30_vXSpi_Nand_BusyCheckTimeoutThresholdOfvMemInstanceType BusyCheckTimeoutCounter;
  vMem_30_vXSpi_Nand_vXSpiDataType ResultBitMask;
  vMem_30_vXSpi_Nand_AddressType TargetAddress;
  vMem_30_vXSpi_Nand_JobErrorType ErrorType;
  vMem_30_vXSpi_Nand_LL_InstanceModifier_JobType JobType;
  vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr;
  vMem_30_vXSpi_Nand_LengthType SourceAddressPtrLength;

} vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobType;

typedef P2VAR(vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
  vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobInfo[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Defines a buffer for each configured flash device to store the content of read device registers. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to perform a memory program execute access at the
 *                external flash device.
 *  \details      -
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess()
 *********************************************************************************************************************/
/*! \brief        Checks if the write/erase error flag is set.
 *  \details      If the write/erase error flag is set the previously performed operation is failed.
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress()
 *********************************************************************************************************************/
/*! \brief        Checks the current write/erase progress after the device's status register has been read.
 *  \details      Checks the previously read device's BUSY flag.
 *                If the device is still busy, the status register is read once again.
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to select another die.
 *  \details      -
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to enable the write.
 *  \details      -
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to load program data.
 *  \details      -
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi erase sequence.
 *  \details      -
 *  \param[in]    ProcessedModifierInstance           Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance);

/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  Std_ReturnType retVal = E_NOT_OK;

  if ((((vMem_30_vXSpi_Nand_vXSpiDataType)(*vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[InstanceId]))
      & vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBusyFlagBitMask(InstanceId)) == 0x00u)
  {
    retVal = E_OK;
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence(
      ProcessedModifierInstance->InstanceId, ProcessedModifierInstance->TargetAddress);

  if (sequenceResult == E_OK)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE;
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(ProcessedModifierInstance->InstanceId, ProcessedModifierInstance->TargetAddress);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
      ProcessedModifierInstance->InstanceId, dieIndex);

  if (sequenceResult == E_OK)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_ENABLE;
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(ProcessedModifierInstance->InstanceId);

  if (sequenceResult == E_OK)
  {
    if(ProcessedModifierInstance->JobType == VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_JOB)
    {
      ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_LOAD_PROGRAM_DATA;
    }
    /* Otherwise current job type is an erase job. */
    else
    {
      ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_INITIATE_ERASE;
    }
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_TriggerProgressCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_TriggerProgressCheck(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
      ProcessedModifierInstance->InstanceId, (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedModifierInstance->InstanceId), 
      vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[ProcessedModifierInstance->InstanceId], 
      (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedModifierInstance->InstanceId));

  if (sequenceResult == E_OK)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_PROGRESS;
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_TriggerProgressCheck */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  if ((((*vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[ProcessedModifierInstance->InstanceId]))
      & (vMem_30_vXSpi_Nand_vXSpiDataType)(ProcessedModifierInstance->ResultBitMask)) == 0x00u)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_OK, VMEM_30_VXSPI_NAND_NO_FAIL);
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, ProcessedModifierInstance->ErrorType);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress()
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
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  /* Check if device is idle. */
  if (vMem_30_vXSpi_Nand_LL_InstanceModifier_IsDeviceReady(ProcessedModifierInstance->InstanceId) == E_OK)
  {
      /* Read result status register. */
    Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
          ProcessedModifierInstance->InstanceId, 
          (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedModifierInstance->InstanceId), 
          vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[ProcessedModifierInstance->InstanceId], 
          (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedModifierInstance->InstanceId));

      if (sequenceResult  == E_OK)
      {
        ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_RESULT;
      }
      else
      {
        ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
  }
  else /* Device still busy */
  {
    /* Check timeout. */
    ProcessedModifierInstance->BusyCheckTimeoutCounter--;
    if (ProcessedModifierInstance->BusyCheckTimeoutCounter > 0u)
    {
      /* Read status register. */
      Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
          ProcessedModifierInstance->InstanceId, (vMem_30_vXSpi_Nand_AddressType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister3Address(ProcessedModifierInstance->InstanceId), 
          vMem_30_vXSpi_Nand_LL_InstanceModifier_RegisterDataBuffers[ProcessedModifierInstance->InstanceId], 
          (vMem_30_vXSpi_Nand_vXSpiDataLengthType) vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedModifierInstance->InstanceId));

      if (sequenceResult == E_OK)
      {
        ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_PROGRESS;
      }
      else
      {
        ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
        vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
      }
    }
    else
    {
      ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
      vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
    } 
  }

} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence(
      ProcessedModifierInstance->InstanceId, ProcessedModifierInstance->TargetAddress,
      ProcessedModifierInstance->SourceAddressPtr, /* PRQA S 0311 */ /* MD_vMem_30_vXSpi_Nand_PtrCastLossOfConst */
      (vMem_30_vXSpi_Nand_vXSpiDataLengthType) ProcessedModifierInstance->SourceAddressPtrLength);

  if (sequenceResult == E_OK)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE_LOAD_PROGRAM_DATA;
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase(
    vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType ProcessedModifierInstance)
{
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence(
      ProcessedModifierInstance->InstanceId, ProcessedModifierInstance->TargetAddress);

  if (sequenceResult == E_OK)
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE;
  }
  else
  {
    ProcessedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE;
    vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedModifierInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase */

/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr, vMem_30_vXSpi_Nand_LengthType Length)
{
  vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType processedModifierInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobInfo[InstanceId];

  processedModifierInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->ResultBitMask = (vMem_30_vXSpi_Nand_vXSpiDataType)vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProgramErrorBitMask( /* VCA_VXSPI_VALID_INSTANCE_ID */
      InstanceId);
  processedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_SELECT_DIE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->BusyCheckTimeoutCounter = /* VCA_VXSPI_VALID_INSTANCE_ID */
      vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceId);
  processedModifierInstance->TargetAddress = TargetAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->ErrorType = VMEM_30_VXSPI_NAND_P_FAIL; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->JobType = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_JOB; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->SourceAddressPtr = SourceAddressPtr; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->SourceAddressPtrLength = Length; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformWriteAccess */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType TargetAddress)
{
  vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType processedModifierInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobInfo[InstanceId];

  processedModifierInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->ResultBitMask = (vMem_30_vXSpi_Nand_vXSpiDataType)vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterEraseErrorBitMask( /* VCA_VXSPI_VALID_INSTANCE_ID */
      InstanceId);
  processedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_SELECT_DIE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->BusyCheckTimeoutCounter = /* VCA_VXSPI_VALID_INSTANCE_ID */
      vMem_30_vXSpi_Nand_LL_CfgInstance_GetBusyCheckTimeoutThresholdOfvMemInstance(InstanceId);
  processedModifierInstance->TargetAddress = TargetAddress; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->ErrorType = VMEM_30_VXSPI_NAND_E_FAIL; /* VCA_VXSPI_VALID_INSTANCE_ID */
  processedModifierInstance->JobType = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_ERASE_JOB; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceModifier_PerformEraseAccess */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing( /* PRQA S 6050 */ /* MD_MSR_STCAL */ /* vMem_30_vXSpi_Nand_LL_InstanceModifier_Processing */
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobPtrType processedModifierInstance =
      &vMem_30_vXSpi_Nand_LL_InstanceModifier_InstanceJobInfo[InstanceId];

  switch (processedModifierInstance->JobProgress)
  {
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_SELECT_DIE:
    {
      uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(processedModifierInstance->InstanceId, processedModifierInstance->TargetAddress);
      vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);

      if((vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(processedModifierInstance->InstanceId))
          && (vMem_30_vXSpi_Nand_ActiveDie[processedModifierInstance->InstanceId] != dieIndex))
      {
        vMem_30_vXSpi_Nand_LL_InstanceModifier_SelectDie(processedModifierInstance);
      }
      else
      {
        processedModifierInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_ENABLE;
        vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
      }
    }
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_WRITE_ENABLE:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_WriteEnable(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_LOAD_PROGRAM_DATA:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_LoadProgramData(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE_LOAD_PROGRAM_DATA:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_ExecuteProgram(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_INITIATE_ERASE:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_InitiateErase(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_EXECUTE:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_TriggerProgressCheck(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_PROGRESS:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckProgress(processedModifierInstance);
      break;
    case VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_CHECK_RESULT:
      vMem_30_vXSpi_Nand_LL_InstanceModifier_CheckOperationSuccess(processedModifierInstance);
      break;
    default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* VMEM_30_VXSPI_NAND_INSTANCEMODIFIER_IDLE */
      break;
  }
}

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceModifier.c
 *********************************************************************************************************************/
