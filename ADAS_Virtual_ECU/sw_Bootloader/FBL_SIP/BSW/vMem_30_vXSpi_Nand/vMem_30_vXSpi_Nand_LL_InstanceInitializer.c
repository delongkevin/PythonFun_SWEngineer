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
/*!        \file  vMem_30_vXSpi_Nand_LL_InstanceInitializer.c
 *        \brief  Instance initializer source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_InstanceInitializer.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_LL_INSTANCEINITIALIZER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_LL_Types.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_InstanceInitializer.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"
#include "vMem_30_vXSpi_Nand_LL.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined(VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
#define VMEM_30_VXSPI_NAND_LOCAL static
#endif

/*! This enum specifies all possible states of the instance specific initialization. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCE_UNINIT = 0u,
  VMEM_30_VXSPI_NAND_INSTANCE_INIT
} vMem_30_vXSpi_Nand_InstanceInitResultType;

/*! Internal sub-"state machine" type to indicate the progress of the Hw initialization. */
typedef enum
{
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_IDLE = 0u,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_DIE_SELECTION,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_INITIATE_READ_STATUS_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_PROTECTION_STATUS_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_PROTECTION_STATUS_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_PROTECTION,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_READMODE_STATUS_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_READMODE_STATUS_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_READMODE,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_ENABLE,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_INPUT_OUTPUT_MODE_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_INPUT_OUTPUT_MODE_REGISTER,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_INPUT_OUTPUT_MODE,
  VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_INIT_HW_FINISH
} vMem_30_vXSpi_Nand_InstanceInitializer_ProgressType;

/*! This struct merges all instance specific parameters regarding their initialization status. */
typedef struct
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;
  vMem_30_vXSpi_Nand_InstanceInitResultType InitStatus;
  vMem_30_vXSpi_Nand_InstanceInitializer_ProgressType JobProgress;
} vMem_30_vXSpi_Nand_InstanceInitStateType;
typedef P2VAR(vMem_30_vXSpi_Nand_InstanceInitStateType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType;
typedef P2CONST(vMem_30_vXSpi_Nand_InstanceInitStateType, AUTOMATIC, VMEM_30_VXSPI_NAND_CONST)
    vMem_30_vXSpi_Nand_ConstInstanceInitStatePtrType;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Defines a buffer for each configured flash device to store the content of read device registers. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_REGISTER_DATA_BUFFER_LENGTH];

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vMemDieIdxOfMemSectorType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_NextDieToBeInitialized;

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Indicates the initialization status of each instance. */
VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_InstanceInitStateType, VMEM_30_VXSPI_NAND_VAR)
  vMem_30_vXSpi_Nand_InstanceInitState[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence()
 *********************************************************************************************************************/
/*! \brief        Reads the flash device's status register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \param[in]    RegisterAddress                    Address of the status register to read.
 *  \return       E_OK       - The flash command sequence was successfully triggered.
 *  \return       E_NOT_OK   - The underlying bus driver didn't accept the transmission request.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(
    vMem_30_vXSpi_Nand_ConstInstanceInitStatePtrType ProcessedInitializerInstance,
    vMem_30_vXSpi_Nand_AddressType RegisterAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*! \brief        Reads the flash device's volatile configuration register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \param[in]    RegisterAddress                    Address of the volatile configuration register to read.
 *  \return       E_OK       - The flash command sequence was successfully triggered.
 *  \return       E_NOT_OK   - The underlying bus driver didn't accept the transmission request.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_ConstInstanceInitStatePtrType ProcessedInitializerInstance,
    vMem_30_vXSpi_Nand_AddressType RegisterAddress);
    

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection()
 *********************************************************************************************************************/
/*! \brief        Disables the protection by writing the corresponding status register of the flash device.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection()
 *********************************************************************************************************************/
/*! \brief        Checks the protection bits in the status register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode()
 *********************************************************************************************************************/
/*! \brief        Writes the flash device's status register with the buffer read mode.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode()
 *********************************************************************************************************************/
/*! \brief        Writes the flash device's input output mode register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode()
 *********************************************************************************************************************/
/*! \brief        Checks the Buffer Read Mode bit in the status register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode()
 *********************************************************************************************************************/
/*! \brief        Checks the value of Input Output Mode register.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish()
 *********************************************************************************************************************/
/*! \brief        Resets the InstanceInitializer's state machine and sets the instance's init result to OK.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed()
 *********************************************************************************************************************/
/*! \brief        Resets the InstanceInitializer's state machine and sets the instance's init result to FAILED.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi Select Die sequence.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister()
 *********************************************************************************************************************/
/*! \brief        Executes the Spi sequence to read the status register and set the next initialization progress state.
 *  \details      -
 *  \param[in]    ProcessedInitializerInstance       Pointer to the currently processed instance.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType processedInitializerInstance);

/*********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(
    vMem_30_vXSpi_Nand_ConstInstanceInitStatePtrType ProcessedInitializerInstance, vMem_30_vXSpi_Nand_AddressType RegisterAddress)
{
  /* Execute read status register sequence transmission. */
  return vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
      ProcessedInitializerInstance->InstanceId,
      RegisterAddress,
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[ProcessedInitializerInstance->InstanceId],
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedInitializerInstance->InstanceId));

} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_ConstInstanceInitStatePtrType ProcessedInitializerInstance, vMem_30_vXSpi_Nand_AddressType RegisterAddress)
{
  /* Execute read status register sequence transmission. */
  return vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence(
      ProcessedInitializerInstance->InstanceId,
      RegisterAddress,
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[ProcessedInitializerInstance->InstanceId],
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedInitializerInstance->InstanceId));

} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;
  Std_ReturnType sequenceResult;

  /* Set protection bits to 0 in the status register content. */
  vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId][0u] = /* VCA_VXSPI_VALID_INSTANCE_ID */
      *vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId] 
      & (~(vMem_30_vXSpi_Nand_vXSpiDataType)(vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProtectionBitMask(instanceId)));

  /* Execute write status register sequence. */
  sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence(
      instanceId, 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister1Address(ProcessedInitializerInstance->InstanceId), 
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[ProcessedInitializerInstance->InstanceId], 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedInitializerInstance->InstanceId));


  if (sequenceResult == E_OK)
  {
    ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_PROTECTION_STATUS_REGISTER;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;

  if(((*vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId])
      & (vMem_30_vXSpi_Nand_vXSpiDataType)(vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterProtectionBitMask(instanceId))) == 0x00u)
  {
    if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(ProcessedInitializerInstance, 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister2Address(ProcessedInitializerInstance->InstanceId)) == E_OK)
    {
      ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_READMODE_STATUS_REGISTER;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
    }
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
  
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;
  Std_ReturnType sequenceResult;

  /* Set buffer read mode in the status register content. */
  vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId][0u] = /* VCA_VXSPI_VALID_INSTANCE_ID */
      ((*vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId]) 
      | (vMem_30_vXSpi_Nand_vXSpiDataType)(vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBufferReadModeBitMask(instanceId)));

  /* Execute write status register sequence. */
  sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence(
      instanceId, 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister2Address(ProcessedInitializerInstance->InstanceId), 
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[ProcessedInitializerInstance->InstanceId], 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterDataBufferLength(ProcessedInitializerInstance->InstanceId));

  if (sequenceResult == E_OK)
  {
    ProcessedInitializerInstance->JobProgress =
        VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_READMODE_STATUS_REGISTER;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;
  Std_ReturnType sequenceResult;

  /* Set input output mode in the input output mode register content. */
  vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId][0u] = vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterValue(instanceId); /* VCA_VXSPI_VALID_INSTANCE_ID */

  /* Execute write volatile configuration register sequence. */
  sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence(
      instanceId, 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterAddress(ProcessedInitializerInstance->InstanceId), 
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[ProcessedInitializerInstance->InstanceId], 
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetVolatileConfigurationRegisterDataBufferLength(ProcessedInitializerInstance->InstanceId));

  if (sequenceResult == E_OK)
  {
    ProcessedInitializerInstance->JobProgress =
        VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_INPUT_OUTPUT_MODE_REGISTER;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;

  /* Execute select die sequence. */
  Std_ReturnType sequenceResult = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
      instanceId, vMem_30_vXSpi_Nand_NextDieToBeInitialized);

  if (sequenceResult == E_OK)
  {
    ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_INITIATE_READ_STATUS_REGISTER;
    vMem_30_vXSpi_Nand_ActiveDie[ProcessedInitializerInstance->InstanceId] = vMem_30_vXSpi_Nand_NextDieToBeInitialized; /* VCA_VXSPI_VALID_INSTANCE_ID */
    vMem_30_vXSpi_Nand_NextDieToBeInitialized++;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;

  if((((*vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId]))
      & (vMem_30_vXSpi_Nand_vXSpiDataType)((vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegisterBufferReadModeBitMask(instanceId)))) != 0x00u)
  {
    if(vMem_30_vXSpi_Nand_LL_CfgDevice_IsInputOutputModeRegisterExisting(instanceId))
    {
      ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_ENABLE;
    }
    else
    {
      ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_INIT_HW_FINISH;
    }
    vMem_30_vXSpi_Nand_LL_SetProcessFlag(instanceId);
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  vMem_30_vXSpi_Nand_InstanceIdType instanceId = ProcessedInitializerInstance->InstanceId;

  if((*vMem_30_vXSpi_Nand_LL_InstanceInitializer_RegisterDataBuffers[instanceId]) == vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterValue(instanceId))
  {
    ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_INIT_HW_FINISH;
    vMem_30_vXSpi_Nand_LL_SetProcessFlag(instanceId);
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(ProcessedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  ProcessedInitializerInstance->InitStatus = VMEM_30_VXSPI_NAND_INSTANCE_INIT;
  ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_IDLE;
  vMem_30_vXSpi_Nand_NextDieToBeInitialized = vMem_30_vXSpi_Nand_LL_CfgInstance_GetvMemDieStartIdxOfvMemInstance(
      ProcessedInitializerInstance->InstanceId);

  vMem_30_vXSpi_Nand_LL_Cbk_InitSucceeded(ProcessedInitializerInstance->InstanceId);
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(
    vMem_30_vXSpi_Nand_InstanceInitStatePtrType ProcessedInitializerInstance)
{
  ProcessedInitializerInstance->InitStatus = VMEM_30_VXSPI_NAND_INSTANCE_UNINIT;
  ProcessedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_IDLE;
  vMem_30_vXSpi_Nand_NextDieToBeInitialized = vMem_30_vXSpi_Nand_LL_CfgInstance_GetvMemDieStartIdxOfvMemInstance(
      ProcessedInitializerInstance->InstanceId);

  vMem_30_vXSpi_Nand_LL_Cbk_JobFinished(ProcessedInitializerInstance->InstanceId, VMEM_JOB_FAILED, VMEM_30_VXSPI_NAND_OTHER_FAIL);
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister(vMem_30_vXSpi_Nand_InstanceInitStatePtrType processedInitializerInstance)
{
  if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(processedInitializerInstance,
      vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister1Address(processedInitializerInstance->InstanceId)) == E_OK)
  {
    processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_PROTECTION_STATUS_REGISTER;
  }
  else
  {
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(processedInitializerInstance);
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister */

/*********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  return (vMem_30_vXSpi_Nand_InstanceInitState[InstanceId].InitStatus == VMEM_30_VXSPI_NAND_INSTANCE_INIT) ? TRUE : FALSE;
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_IsInstanceInitialized */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init(void)
{
  vMem_30_vXSpi_Nand_InstanceIdType InstanceId;

  for (InstanceId = 0; InstanceId < vMem_30_vXSpi_Nand_GetSizeOfvMemInstance(); InstanceId++)
  {
    vMem_30_vXSpi_Nand_InstanceInitState[InstanceId].JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_IDLE;
    vMem_30_vXSpi_Nand_InstanceInitState[InstanceId].InitStatus = VMEM_30_VXSPI_NAND_INSTANCE_UNINIT;
  }
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_Init */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_InstanceInitStatePtrType processedInitializerInstance = &vMem_30_vXSpi_Nand_InstanceInitState[InstanceId];
  processedInitializerInstance->InstanceId = InstanceId; /* VCA_VXSPI_VALID_INSTANCE_ID */

  processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_DIE_SELECTION; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return E_OK;
} /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitInstance */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing( /* vMem_30_vXSpi_Nand_LL_InstanceInitializer_Processing */ /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_InstanceInitStatePtrType processedInitializerInstance = &vMem_30_vXSpi_Nand_InstanceInitState[InstanceId];

  switch (processedInitializerInstance->JobProgress)
  {
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_DIE_SELECTION:
    if(vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(processedInitializerInstance->InstanceId))
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie(processedInitializerInstance);
    }
    else
    {
      processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_INITIATE_READ_STATUS_REGISTER;
      vMem_30_vXSpi_Nand_LL_SetProcessFlag(InstanceId);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_INITIATE_READ_STATUS_REGISTER:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitiateReadStatusRegister(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_PROTECTION_STATUS_REGISTER:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_DisableProtection(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_PROTECTION_STATUS_REGISTER:
    if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(processedInitializerInstance,
        vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister1Address(processedInitializerInstance->InstanceId)) == E_OK)
    {
      processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_PROTECTION;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(processedInitializerInstance);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_PROTECTION:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckProtection(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_READMODE_STATUS_REGISTER:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetBufferReadMode(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_READMODE_STATUS_REGISTER:
    if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadStatusRegisterSequence(processedInitializerInstance, 
        vMem_30_vXSpi_Nand_LL_CfgDevice_GetStatusRegister2Address(processedInitializerInstance->InstanceId)) == E_OK)
    {
      processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_READMODE;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(processedInitializerInstance);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_READMODE:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckBufferReadMode(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_ENABLE:
    if(vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(processedInitializerInstance->InstanceId) == E_OK)
    {
      processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_INPUT_OUTPUT_MODE_REGISTER;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(processedInitializerInstance);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_WRITE_INPUT_OUTPUT_MODE_REGISTER:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_SetInputOutputMode(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_EXECUTE_READ_INPUT_OUTPUT_MODE_REGISTER:
    if (vMem_30_vXSpi_Nand_LL_InstanceInitializer_ReadVolatileConfigurationRegisterSequence(processedInitializerInstance, 
        vMem_30_vXSpi_Nand_LL_CfgDevice_GetInputOutputModeRegisterAddress(processedInitializerInstance->InstanceId)) == E_OK)
    {
      processedInitializerInstance->JobProgress = VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_INPUT_OUTPUT_MODE;
    }
    else
    {
      vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFailed(processedInitializerInstance);
    }
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_RESULT_INPUT_OUTPUT_MODE:
    vMem_30_vXSpi_Nand_LL_InstanceInitializer_CheckInputOutputMode(processedInitializerInstance);
    break;
  case VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_CHECK_INIT_HW_FINISH:
      if((vMem_30_vXSpi_Nand_NextDieToBeInitialized < vMem_30_vXSpi_Nand_LL_CfgInstance_GetNumberOfDiesOfvMemInstance(InstanceId))
          && (vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(InstanceId)))
      {
        vMem_30_vXSpi_Nand_LL_InstanceInitializer_SelectDie(processedInitializerInstance);
      }
      else
      {
        vMem_30_vXSpi_Nand_LL_InstanceInitializer_InitHwFinish(processedInitializerInstance);
      }
    break;
  
  default: /* VMEM_30_VXSPI_NAND_INSTANCEINITIALIZER_IDLE */
    /* Nothing to do. */
    break;
  }
}

#define VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_InstanceInitializer.c
 *********************************************************************************************************************/
