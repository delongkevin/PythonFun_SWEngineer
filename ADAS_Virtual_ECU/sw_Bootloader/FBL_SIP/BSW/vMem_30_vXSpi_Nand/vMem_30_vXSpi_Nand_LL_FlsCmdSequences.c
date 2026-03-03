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
/*!        \file  vMem_30_vXSpi_Nand_LL_FlsCmdSequences.c
 *        \brief  Flash command sequence builder source file
 *
 *      \details  See vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define  VMEM_30_VXSPI_NAND_LL_FLSCMDSEQUENCES_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_IntShared.h"
#include "vMem_30_vXSpi_Nand_LL_FlsCmdSequences.h"
#include "vMem_30_vXSpi_Nand_LL_Cbk_Int.h"

#if (VMEM_30_VXSPI_NAND_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Number of bytes of all addresses of the device  */
#define VMEM_30_VXSPI_NAND_ADDRESS_NUMBER_OF_BYTES          3u

/*! Size of the address buffer for each instance. */
#define VMEM_30_VXSPI_NAND_DATA_BUFFER_SIZE                 4u

/*! Bit shift macros */
#define  VMEM_30_VXSPI_16BIT_SHIFT                          16u
#define  VMEM_30_VXSPI_8BIT_SHIFT                           8u

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LOCAL) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define  VMEM_30_VXSPI_NAND_LOCAL static
#endif

#if !defined (VMEM_30_VXSPI_NAND_LOCAL_INLINE) /* COV_VMEM_30_VXSPI_NAND_COMPATIBILITY */
# define  VMEM_30_VXSPI_NAND_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define  VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_VXSPI_NAND_LOCAL VAR(vMem_30_vXSpi_Nand_vXSpiDataType, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_DataBuffer[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()][VMEM_30_VXSPI_NAND_DATA_BUFFER_SIZE];

VMEM_30_VXSPI_NAND_LOCAL VAR(boolean, VMEM_30_VXSPI_NAND_VAR)
    vMem_30_vXSpi_Nand_IsJobActive[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];

#define  VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define  VMEM_30_VXSPI_NAND_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat()
 *********************************************************************************************************************/
/*! \brief       Converts the address format to the vXSpi address format.
 *  \details     The function converts the vMem address format to the vXSpi address format.
 *  \param[in]   AddressFormat       vMem address format of the command.
 *  \return      vXSpi address format.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiAddressFormatType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(
    vMem_30_vXSpi_Nand_AddressFormatType AddressFormat);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress()
 *********************************************************************************************************************/
/*! \brief       Calculates the column address from the given absolute address.
 *  \details     The function calculates the column address from the given absolute address with the value of the 
 *               given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   Address             The address that shall be converted to the column address.
 *  return       Column address for the external device.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer()
 *********************************************************************************************************************/
/*! \brief       Fills the address buffer for the given instance.
 *  \details     The function fills the address buffer of the given instance with the value of the given instance.
 *  \param[in]   InstanceId          ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   Address             The address that shall be written into the address buffer.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorAddressBuffer()
 *********************************************************************************************************************/
/*! \brief       Fills the replacing address buffer for the given instance.
 *  \details     The function fills the replacing address buffer of the given instance with the value of the given
 *               instance.
 *  \param[in]   InstanceId               ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   TargetSectorAddress      The target sector address that shall be written into the data buffer.
 *  \param[in]   ReplacingSectorAddress   The replacing sector address that shall be written into the data buffer.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorDataBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetSectorAddress,
    vMem_30_vXSpi_Nand_AddressType ReplacingSectorAddress);

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer()
 *********************************************************************************************************************/
/*! \brief       Fills the die select buffer for the given instance.
 *  \details     The function fills the die select buffer of the given instance with the value of the given
 *               instance.
 *  \param[in]   InstanceId               ID and index of the related vMem_30_vXSpi_Nand instance.
 *  \param[in]   DieIndex                 Index of die to solect of the related vMem_30_vXSpi_Nand instance.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DieIndexType DieIndex);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiAddressFormatType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(
    vMem_30_vXSpi_Nand_AddressFormatType AddressFormat)
{
  /* Array holds vXSpi address formats for all specified vMem address formats. */
  const vMem_30_vXSpi_Nand_vXSpiAddressFormatType vXSpiAddressFormatMap[5u] =
  {
    VXSPI_ADDRESS_FORMAT_1_BYTE,
    VXSPI_ADDRESS_FORMAT_1_BYTE,
    VXSPI_ADDRESS_FORMAT_2_BYTE,
    VXSPI_ADDRESS_FORMAT_3_BYTE,
    VXSPI_ADDRESS_FORMAT_4_BYTE
  };

  return vXSpiAddressFormatMap[AddressFormat];
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address)
{
  vMem_30_vXSpi_Nand_vXSpiDataPtrType buffer = vMem_30_vXSpi_Nand_DataBuffer[InstanceId];
  vMem_30_vXSpi_Nand_AddressType convertedAddress = Address;

  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(InstanceId, Address);

  /* This is only needed for hybrid devices with explicit die select command. Like Winbond_W25M02GV */
  if(vMem_30_vXSpi_Nand_LL_CfgInstance_IsSoftwareDieSelectUsed(InstanceId))
  {
    uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, Address);
    vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);
    /* Convert the user Address to the corresponding address in the physical address mapping. */
    convertedAddress = Address - vMem_30_vXSpi_Nand_LL_CfgDie_GetDieStartAddressOfvMemDie(dieIndex);
  }

  /* The MSB is transmitted first according to the Spi protocol. */
  buffer[0] = (vMem_30_vXSpi_Nand_vXSpiDataType) (convertedAddress >> (columnAddressLength + VMEM_30_VXSPI_16BIT_SHIFT)); /* VCA_VXSPI_VALID_INSTANCE_ID */
  buffer[1] = (vMem_30_vXSpi_Nand_vXSpiDataType) (convertedAddress >> (columnAddressLength + VMEM_30_VXSPI_8BIT_SHIFT)); /* VCA_VXSPI_VALID_INSTANCE_ID */
  buffer[2] = (vMem_30_vXSpi_Nand_vXSpiDataType) (convertedAddress >> columnAddressLength); /* VCA_VXSPI_VALID_INSTANCE_ID */

  return buffer;
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorDataBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorDataBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetSectorAddress,
    vMem_30_vXSpi_Nand_AddressType ReplacingSectorAddress)
{
  vMem_30_vXSpi_Nand_vXSpiDataPtrType buffer = vMem_30_vXSpi_Nand_DataBuffer[InstanceId];

  /* The same columnAddressLength can be used for source and target.
     The taret and source sector are on the same chip, so they have the same page size, otherwise the complete replaceing sector logc is not working. */
  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(InstanceId, TargetSectorAddress);

  /* The MSB is transmitted first according to the Spi protocol. */
  buffer[0] = (vMem_30_vXSpi_Nand_vXSpiDataType) (TargetSectorAddress >> (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH + VMEM_30_VXSPI_8BIT_SHIFT)); /* VCA_VXSPI_VALID_INSTANCE_ID */
  buffer[1] = (vMem_30_vXSpi_Nand_vXSpiDataType) (TargetSectorAddress >> (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH)); /* VCA_VXSPI_VALID_INSTANCE_ID */
  buffer[2] = (vMem_30_vXSpi_Nand_vXSpiDataType) (ReplacingSectorAddress >> (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH + VMEM_30_VXSPI_8BIT_SHIFT)); /* VCA_VXSPI_VALID_INSTANCE_ID */
  buffer[3] = (vMem_30_vXSpi_Nand_vXSpiDataType) (ReplacingSectorAddress >> (columnAddressLength + VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH)); /* VCA_VXSPI_VALID_INSTANCE_ID */

  return buffer;
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorDataBuffer */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_vXSpiDataPtrType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DieIndexType DieIndex)
{
  vMem_30_vXSpi_Nand_vXSpiDataPtrType buffer = vMem_30_vXSpi_Nand_DataBuffer[InstanceId];

  /* The MSB is transmitted first according to the Spi protocol. */
  buffer[0] = (vMem_30_vXSpi_Nand_vXSpiDataType) DieIndex; /* VCA_VXSPI_VALID_INSTANCE_ID */

  return buffer;
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_VXSPI_NAND_LOCAL FUNC(vMem_30_vXSpi_Nand_AddressType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType Address)
{
  uint32 sectorIndex = vMem_30_vXSpi_Nand_GetSectorIndex(InstanceId, Address);
  vMem_30_vXSpi_Nand_DieIndexType dieIndex = vMem_30_vXSpi_Nand_LL_CfgSector_GetvMemDieIdxOfMemSector(sectorIndex);
  uint8 columnAddressLength = vMem_30_vXSpi_Nand_GetColumnAddressLength(InstanceId, Address);

  /* Convert the user address to the corresponding address in the physical address mapping. */
  vMem_30_vXSpi_Nand_AddressType convertedAddress = Address - vMem_30_vXSpi_Nand_LL_CfgDie_GetDieStartAddressOfvMemDie(dieIndex);

  return (convertedAddress & VMEM_30_VXSPI_NAND_COLUMN_ADDRESS_BITMASK(columnAddressLength));
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId, vMem_30_vXSpi_Nand_AddressType TargetAddress)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].EraseCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].EraseCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;

  /* TargetAddress does not comply to address phase of vXSpi. Erase sequence requires dummy cycles before address
   * is transmitted. This is not compatible to xSPI. So TargetAddress complies to xSPI data phase. */
  dataAndLength.DataLength = VMEM_30_VXSPI_NAND_ADDRESS_NUMBER_OF_BYTES;
  dataAndLength.DataBuffer = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer(InstanceId, TargetAddress);

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdTxData(deviceId, genericProtocolModeId, command, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteEraseSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].PageDataReadCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].PageDataReadCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;

  /* TargetAddress does not comply to address phase of vXSpi. Erase sequence requires dummy cycles before address
   * is transmitted. This is not compatible to xSPI. So TargetAddress complies to xSPI data phase. */
  dataAndLength.DataLength = VMEM_30_VXSPI_NAND_ADDRESS_NUMBER_OF_BYTES;
  dataAndLength.DataBuffer = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer(InstanceId, SourceAddress);

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdTxData(deviceId, genericProtocolModeId, command, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecutePageDataReadSequence() */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType readDataProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].ReadDataProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ReadCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].ReadCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ReadCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_DataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress(InstanceId, SourceAddress);
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = TargetAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrRxData(deviceId, readDataProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType writeDataProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].WriteDataProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ProgramDataLoadCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].ProgramDataLoadCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ProgramDataLoadCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetColumnAddress(InstanceId, TargetAddress);
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = SourceAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrTxData(deviceId, writeDataProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramDataLoadSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ProgramExecuteCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ProgramExecuteCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;

  /* TargetAddress does not comply to address phase of vXSpi. Erase sequence requires dummy cycles before address
   * is transmitted. This is not compatible to xSPI. So TargetAddress complies to xSPI data phase. */
  dataAndLength.DataLength = VMEM_30_VXSPI_NAND_ADDRESS_NUMBER_OF_BYTES;
  dataAndLength.DataBuffer = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetPageAddressBuffer(InstanceId, TargetAddress);

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdTxData(deviceId, genericProtocolModeId, command, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteProgramExecuteSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ReadBbmLutCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].ReadBbmLutCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ReadBbmLutCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_DataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = TargetAddress;
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = TargetAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrRxData(deviceId, genericProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadBbmLutSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ReadStatusRegisterCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].ReadStatusRegisterCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ReadStatusRegisterCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_DataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = SourceAddress;
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = TargetAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrRxData(deviceId, genericProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadStatusRegisterSequence */


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType SourceAddress,
    vMem_30_vXSpi_Nand_vXSpiDataPtrType TargetAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ReadVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_DataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = SourceAddress;
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = TargetAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrRxData(deviceId, genericProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_RX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReadVolatileConfigurationRegisterSequence */


/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].WriteStatusRegisterCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].WriteStatusRegisterCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].WriteStatusRegisterCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = TargetAddress;
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = SourceAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrTxData(deviceId, genericProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteStatusRegisterSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetAddress,
    vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType SourceAddressPtr,
    vMem_30_vXSpi_Nand_vXSpiDataLengthType Length)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_AddressFormatType addressFormat =
      vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[InstanceId].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdAddressFormatValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].WriteVolatileConfigurationRegisterCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;
  vXSpi_AddressAndFormatType addressAndFormat;

  addressAndFormat.Address = TargetAddress;
  addressAndFormat.AddressFormat = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ConvertAddressFormatTovXSpiAddressFormat(addressFormat);

  dataAndLength.DataLength = Length;
  dataAndLength.DataBuffer = SourceAddressPtr;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdAddrTxData(deviceId, genericProtocolModeId, command, &addressAndFormat, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteVolatileConfigurationRegisterSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_AddressType TargetSectorAddress,
    vMem_30_vXSpi_Nand_AddressType ReplacingSectorAddress)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].ReplaceLogicalBlocksCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].ReplaceLogicalBlocksCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;

  dataAndLength.DataLength = 4u;
  dataAndLength.DataBuffer = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetReplacingSectorDataBuffer(
      InstanceId, TargetSectorAddress, ReplacingSectorAddress);

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdTxData(deviceId, genericProtocolModeId, command, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteReplaceSectorSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId,
    vMem_30_vXSpi_Nand_DieIndexType DieIndex)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].SoftwareDieSelectCmdOfvMemFlsCmdValue;
  vMem_30_vXSpi_Nand_vXSpiDummyCycleType dummyCycles =
      vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[InstanceId].SoftwareDieSelectCmdOfvMemFlsCmdDummyCycleValue;
  vXSpi_ConstDataAndLengthType dataAndLength;

  dataAndLength.DataLength = 1u;
  dataAndLength.DataBuffer = vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetDieSelectDataBuffer(InstanceId, DieIndex);

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmdTxData(deviceId, genericProtocolModeId, command, dummyCycles, &dataAndLength); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */ /* VCA_VMEM_VXSPI_NAND_DATA_BUFFER_AND_LENGTH_TX */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteDieSelectSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_vXSpiDeviceIdType deviceId = vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[InstanceId];
  vMem_30_vXSpi_Nand_vXSpiProtocolModeIdType genericProtocolModeId =
      vMem_30_vXSpi_Nand_vMemInstance[InstanceId].GenericProtocolModeIdOfvMemInstance;
  vMem_30_vXSpi_Nand_vXSpiCommandType command = vMem_30_vXSpi_Nand_vMemFlsCmdValue[InstanceId].WriteEnableCmdOfvMemFlsCmdValue;

  vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = TRUE; /* VCA_VXSPI_VALID_INSTANCE_ID */
  return vXSpi_TxCmd(deviceId, genericProtocolModeId, command); /* VCA_VMEM_VXSPI_NAND_CALL_EXTERNAL_VXSPI_FUNCTION */
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_ExecuteWriteEnableSequence */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMem_30_vXSpi_Nand_FlsCmdSequenceResultType, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  vMem_30_vXSpi_Nand_FlsCmdSequenceResultType retVal;
  uint8 deviceId = vMem_30_vXSpi_Nand_LL_CfgInstance_GetInstanceIdTovXSpiDeviceId(InstanceId);

  if(vXSpi_GetTransactionResult(deviceId) == VXSPI_TRANSACTION_OK)
  {
    retVal = VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_OK;
  }
  else if(vXSpi_GetTransactionResult(deviceId) == VXSPI_TRANSACTION_PENDING)
  {
    retVal = VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_PENDING;
  }
  else /* vXSpi_GetTransactionResult(deviceId) == VXSPI_TRANSACTION_FAILED */
  {
    retVal = VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_FAILED;
  }

  return retVal;
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult */

/**********************************************************************************************************************
 *  vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_VXSPI_NAND_CODE) vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing(
    vMem_30_vXSpi_Nand_InstanceIdType InstanceId)
{
  if((vMem_30_vXSpi_Nand_LL_FlsCmdSequences_GetResult(InstanceId) != VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_PENDING)
      && (vMem_30_vXSpi_Nand_IsJobActive[InstanceId] == TRUE))
  {
    vMem_30_vXSpi_Nand_IsJobActive[InstanceId] = FALSE;
    vMem_30_vXSpi_Nand_LL_Cbk_SequenceEndNotification(InstanceId);
  }
} /* vMem_30_vXSpi_Nand_LL_FlsCmdSequences_Processing */

#define  VMEM_30_VXSPI_NAND_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* START_COVERAGE_JUSTIFICATION

 Variant coverage:

 \ID COV_VMEM_30_VXSPI_NAND_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

 END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_FlsCmdSequences.c
 *********************************************************************************************************************/
