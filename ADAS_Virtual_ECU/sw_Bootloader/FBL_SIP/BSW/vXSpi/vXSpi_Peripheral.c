/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vXSpi_Peripheral.c
 *        \brief  Implementation file of the Peripheral abstraction of the vXSpi driver.
 *
 *      \details  Describe the Peripheral here in more detail.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
/*lint -e537 */ /* Suppress ID537 due to MD_MSR_MemMap */
/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vXSpi.h"
#include "vXSpi_Peripheral.h"
#include "vXSpi_CfgAccess_Int.h"
#include "vXSpi_Regs_Int.h"
#include "vXSpi_RegAccess_Int.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VXSPI_4BYTES_LENGTH                                   (4u)
#define VXSPI_4BYTES_FLOOR_MASK                      (0xFFFFFFFCu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define VXSPI_CEIL_2BYTES(num)          ((num + 1u) & 0xFFFFFFFEu)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VXSPI_PERIPHERAL_LOCAL) /* COV_VXSPI_COMPATIBILITY */
# define VXSPI_PERIPHERAL_LOCAL static
#endif

#if !defined (VXSPI_PERIPHERAL_LOCAL_INLINE) /* COV_VXSPI_COMPATIBILITY */
# define VXSPI_PERIPHERAL_LOCAL_INLINE LOCAL_INLINE
#endif

typedef struct
{
  vXSpi_ProtocolModeIdType  ProtocolModeId;  /*!< Stores last used spi protocol mode id */
  vXSpi_CommandType         ReadCmd;         /*!< Stores last used read command for INDAC mode */
  vXSpi_CommandType         WriteCmd;        /*!< Stores last used write command for INDAC mode */
  vXSpi_AddressFormatType   TxAddressFormat; /*!< Stores last used Tx address format */
  vXSpi_DeviceIdType        DeviceId;        /*!< Stores last used Device ID */
  vXSpi_DummyCycleType      DummyCycles;     /*!< Stores last used Number of dummy cycles */
} vXSpi_LastUsedConfigsType;                 /*!< Stores information about last used configs */


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VXSPI_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!< Stores information about last used INDAC mode values. */
VXSPI_PERIPHERAL_LOCAL VAR(vXSpi_LastUsedConfigsType, VXSPI_VAR_NOINIT) vXSpi_LastUsedConfigs[VXSPI_MAX_NUMBER_OF_HW_UNITS]; 

/*! Stores information about transaction results. */
VXSPI_PERIPHERAL_LOCAL VAR(vXSpi_TransactionResultType, VXSPI_VAR_NOINIT)
    vXSpi_TransactionResults[VXSPI_MAX_NUMBER_OF_DEVICES];

#define VXSPI_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VXSPI_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  vXSpi_DeserializeToUint32()
**********************************************************************************************************************/
/*! \brief       Deserialize 4 byte data and return it as Uint32 variable.
 *  \details     -
 *  \param[in]   DataBuffer            Pointer to buffer to write data from
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(uint32, VXSPI_CODE) vXSpi_DeserializeToUint32(
    vXSpi_ConstDataPtrType DataBuffer
);

/**********************************************************************************************************************
  vXSpi_SerializeFromUint32()
**********************************************************************************************************************/
/*! \brief       Serialize Uint32 variable and store it as 4 byte data in DataBuffer.
 *  \details     -
 *  \param[in]   Data                  Uint32 variable to write data from
 *  \param[in]   DataBuffer            Pointer to buffer to write data to
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_SerializeFromUint32(
    uint32 Data,
    vXSpi_DataPtrType DataBuffer
);

/**********************************************************************************************************************
  vXSpi_DisableDAC()
**********************************************************************************************************************/
/*! \brief       Disable the direct access controler (DAC).
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_DisableDAC(vXSpi_HwUnitIdType HwUnitId);

/**********************************************************************************************************************
 *  vXSpi_TriggerCmd()
 *********************************************************************************************************************/
/*! \brief       Trigger command execution.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_TriggerCmd(vXSpi_HwUnitIdType HwUnitId);

/**********************************************************************************************************************
  vXSpi_DisableAutomaticPolling()
**********************************************************************************************************************/
/*! \brief       Disable the automatic polling of the status register from the external device.
 *  \details     The Jacinto7 does as default, poll the status register of the external device after each write 
 *               instruction. This automatic polling is disabled by this function.
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_DisableAutomaticPolling(vXSpi_HwUnitIdType HwUnitId);

/**********************************************************************************************************************
  vXSpi_SetupFlsCmd()
**********************************************************************************************************************/
/*! \brief       Set up a flash command for the software triggered instruction generator (STIG).
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   Cmd                   Command to be used in next transmission
 *  \param[in]   RxData                VXSPI_REG_VAL_TRUE if data should be received, VXSPI_REG_VAL_FALSE if not
 *  \param[in]   TxAddress             VXSPI_REG_VAL_TRUE if an address should be transmitted, VXSPI_REG_VAL_FALSE if not
 *  \param[in]   TxAddressFormat       Tx address format
 *  \param[in]   TxData                VXSPI_REG_VAL_TRUE if data should be transmitted, VXSPI_REG_VAL_FALSE if not
 *  \param[in]   DataLength            Length in bytes of data to wirte or to be received
 *  \param[in]   DummyCycles           Number of dummy cycles to transmit between address and data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupFlsCmd(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_CommandType Cmd, 
  uint8 RxData, 
  uint8 TxAddress,
  vXSpi_AddressFormatType TxAddressFormat,
  uint8 TxData,
  vXSpi_DataLengthType DataLength, 
  vXSpi_DummyCycleType DummyCycles);

/**********************************************************************************************************************
  vXSpi_ReadSram()
**********************************************************************************************************************/
/*! \brief       Read data from the SRAM into the DataBuffer.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   DataAndLength         Pointer to buffer to write data to and length in bytes to be received
 *  \return      E_OK, if all Data was read from SRAM,
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_ReadSram(
  vXSpi_HwUnitIdType HwUnitId,  
  vXSpi_DataAndLengthPtrType DataAndLength);
  
/**********************************************************************************************************************
  vXSpi_WriteSram()
**********************************************************************************************************************/
/*! \brief       Write data from the DataBuffer to the SRAM.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   DataAndLength         Pointer to buffer to write data from and length in bytes to be written
 *  \return      E_OK if all Data was written to the SRAM,
 *               E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_WriteSram(
  vXSpi_DeviceIdType DeviceId,
  vXSpi_ConstDataAndLengthPtrType DataAndLength);
  
/**********************************************************************************************************************
  vXSpi_SetupIndacRead()
**********************************************************************************************************************/
/*! \brief       Modify all necessary registers for the indirect access controler (INDAc) mode to read data.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   ProtocolModeId        Protocol mode ID
 *  \param[in]   Address               Address to transmit
 *  \param[in]   DataLength            Length in bytes to be received
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupIndacRead(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_AddressType Address, 
  vXSpi_DataLengthType DataLength);
  
/**********************************************************************************************************************
  vXSpi_SetupIndacWrite()
**********************************************************************************************************************/
/*! \brief       Modify all necessary registers for the indirect access controler (INDAc) mode to write data.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   Address               Address to transmit
 *  \param[in]   DataLength            Length in bytes to be received
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupIndacWrite(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_AddressType Address, 
  vXSpi_DataLengthType DataLength);
  
/**********************************************************************************************************************
  vXSpi_PollStatus()
**********************************************************************************************************************/
/*! \brief       Poll the OSPI_IND_OPS_DONE_STATUS_FLD of the OSPI_INDIRECT_READ_XFER_CTRL_REG.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   RegAddress            Address of the Register to poll the status from
 *  \param[in]   CompareValue          0 if 0 equals status busy and 1 equals status done
 *                                     1 if 1 equals status busy and 0 equals status done
 *  \param[in]   BitShiftValue         BitShift Value of the Status Bit of the regarding register
 *  \return      E_OK if the INDAC operation is finished, 
 *               E_NOT_OK if the INDAC operation is not finished and the BusyCheckCycleThreshold was exceeded.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_PollStatus(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_AddressType RegAddress,
  vXSpi_RegWidthType CompareValue,
  vXSpi_BitShiftType BitShiftValue);
  

/**********************************************************************************************************************
  vXSpi_ProtocolChanged()
**********************************************************************************************************************/
/*! \brief       Check if the protocolmode or the read and write commands for the direct access controler have changed. 
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   ReadCmd               Read command for the INDAC
 *  \param[in]   WriteCmd              Wirte command for the INDAC
 *  \param[in]   ProtocolModeId        Protocol mode ID
 *  \param[in]   DummyCycles           Number of dummy cycles to transmit between address and data
 *  \return      TRUE Protocol or commands changed, FALSE Protocol and commands did not change
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_ProtocolChanged(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_CommandType ReadCmd, 
  vXSpi_CommandType WriteCmd, 
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_DummyCycleType DummyCycles);

/**********************************************************************************************************************
  vXSpi_SetupProtocolProperties()
**********************************************************************************************************************/
/*! \brief       Setup values for protocol configurations and write to the according registers.
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   ProtocolModeId        Protocol mode ID
 *  \param[in]   ReadCmd               Read command for the INDAC
 *  \param[in]   WriteCmd              Wirte command for the INDAC
 *  \param[in]   DummyCycles           Number of dummy cycles to transmit between address and data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_SetupProtocolProperties(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_CommandType ReadCmd,
  vXSpi_CommandType WriteCmd,
  vXSpi_DummyCycleType DummyCycles);

/**********************************************************************************************************************
  vXSpi_SetupProtocol()
**********************************************************************************************************************/
/*! \brief       Setup the spi protocol.
 *  \details     Check if the protocol changed, if so, trigger the setup.
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   ProtocolModeId        Protocol mode ID
 *  \param[in]   ReadCmd               Read command for the INDAC
 *  \param[in]   WriteCmd              Wirte command for the INDAC
 *  \param[in]   DummyCycles           Number of dummy cycles to transmit between address and data
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupProtocol(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_CommandType ReadCmd,
  vXSpi_CommandType WriteCmd,
  vXSpi_DummyCycleType DummyCycles);
  
/**********************************************************************************************************************
  vXSpi_SetupDeviceProperties()
**********************************************************************************************************************/
/*! \brief       Set up the OSPI_DEV_SIZE_CONFIG_REG register. 
 *  \details     -
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   DeviceId              Device ID
 *  \param[in]   TxAddressFormat       Tx address format
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupDeviceProperties(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_DeviceIdType DeviceId,
  vXSpi_AddressFormatType TxAddressFormat);
  
/**********************************************************************************************************************
  vXSpi_SetupDevice()
**********************************************************************************************************************/
/*! \brief       Setup configs for the external device.
 *  \details     Check if the device changed, if so, disable the INDAC and trigger the setup
 *  \param[in]   HwUnitId              Hardware unit ID
 *  \param[in]   DeviceId              Device ID
 *  \param[in]   TxAddressFormat       Tx address format
 *  \return      E_OK if setup was successful, E_NOT_OK if setup failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_SetupDevice(
  vXSpi_HwUnitIdType HwUnitId, 
  vXSpi_DeviceIdType DeviceId, 
  vXSpi_AddressFormatType TxAddressFormat);
  
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vXSpi_DeserializeToUint32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(uint32, VXSPI_CODE) vXSpi_DeserializeToUint32(
    vXSpi_ConstDataPtrType DataBuffer
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  uint32 value = 0u;

  /* ----------- Implementation ------------------------------------------------------------------ */
  value = ((uint32) DataBuffer[0u]); 
  value |= ((uint32) DataBuffer[1u]) << VXSPI_1_BYTE_SHIFT;
  value |= ((uint32) DataBuffer[2u]) << VXSPI_2_BYTE_SHIFT;
  value |= ((uint32) DataBuffer[3u]) << VXSPI_3_BYTE_SHIFT;

  return value;
}

/**********************************************************************************************************************
 *  vXSpi_SerializeFromUint32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_SerializeFromUint32(
    uint32 Data,
    vXSpi_DataPtrType DataBuffer
)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  DataBuffer[0u] = (uint8)(Data & VXSPI_BYTE_MASK);
  DataBuffer[1u] = (uint8)((Data >> VXSPI_1_BYTE_SHIFT) & VXSPI_BYTE_MASK);
  DataBuffer[2u] = (uint8)((Data >> VXSPI_2_BYTE_SHIFT) & VXSPI_BYTE_MASK);
  DataBuffer[3u] = (uint8)(Data >> VXSPI_3_BYTE_SHIFT);
}
  
/**********************************************************************************************************************
 *  vXSpi_DisableDAC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_DisableDAC(vXSpi_HwUnitIdType HwUnitId)
{
  /* Dissable the direct access controler (DAC) */
  vXSpi_RegWidthType regVal = (vXSpi_Reg_Read(HwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET) & (~(VXSPI_REG_VAL_TRUE << VXSPI_ENB_DIR_ACC_CTLR_FLD)));
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET, regVal);
}
  
/**********************************************************************************************************************
 *  vXSpi_TriggerCmd()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_TriggerCmd(vXSpi_HwUnitIdType HwUnitId)
{
  vXSpi_RegWidthType regVal = (vXSpi_Reg_Read(HwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET) | (VXSPI_REG_VAL_TRUE << VXSPI_CMD_EXEC_FLD));
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, regVal);
}

/**********************************************************************************************************************
 *  vXSpi_DisableAutomaticPolling()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_DisableAutomaticPolling(vXSpi_HwUnitIdType HwUnitId)
{
  vXSpi_RegWidthType regVal = ((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE << VXSPI_DISABLE_POLLING_FLD);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_WRITE_COMPLETION_CTRL_REG_OFFSET, regVal);
}

/**********************************************************************************************************************
 *  vXSpi_SetupFlsCmd()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupFlsCmd(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_CommandType Cmd, 
  uint8 RxData, 
  uint8 TxAddress,
  vXSpi_AddressFormatType TxAddressFormat,
  uint8 TxData,
  vXSpi_DataLengthType DataLength, 
  vXSpi_DummyCycleType DummyCycles)
{
  vXSpi_DataLengthType dataLengthRegVal;
  vXSpi_RegWidthType regVal;

  /* DataLength in register is always one less than real number of bytes with preventing underflow. */
  if(DataLength > 0u)
  {
    dataLengthRegVal = (DataLength - 1u);
  }
  else
  {
    dataLengthRegVal = DataLength;
  }

  /* Setup the register value for the OSPI_FLASH_CMD_CTRL_REG */
  regVal = 
    (((vXSpi_RegWidthType) Cmd               << VXSPI_CMD_OPCODE_FLD)
    |((vXSpi_RegWidthType) RxData            << VXSPI_ENB_READ_DATA_FLD)
    |(DataLength                             << VXSPI_NUM_RD_DATA_BYTES_FLD)
    |((vXSpi_RegWidthType) TxAddress         << VXSPI_ENB_COMD_ADDR_FLD)
    |((vXSpi_RegWidthType) TxAddressFormat   << VXSPI_NUM_ADDR_BYTES_FLD)
    |((vXSpi_RegWidthType) TxData            << VXSPI_ENB_WRITE_DATA_FLD)
    |(dataLengthRegVal                       << VXSPI_NUM_WR_DATA_BYTES_FLD)
    |((vXSpi_RegWidthType) DummyCycles       << VXSPI_NUM_DUMMY_CYCLES_FLD));

  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, regVal);
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  vXSpi_ReadSram()
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
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_ReadSram(
  vXSpi_HwUnitIdType HwUnitId,  
  vXSpi_DataAndLengthPtrType DataAndLength)
{
  uint32 clcByteCnt = 0u;
  uint32 clcByteCntEnd;
  uint32 dataLenFloored = DataAndLength->DataLength & (VXSPI_4BYTES_FLOOR_MASK);
  uint32 bytesFilled = 0u;
  uint32 busyCheckCounter = 0;
  uint32 tmpData;
  vXSpi_AddressType ospiFssMemRegionAddr = vXSpi_Cfg_HwUnit_GetMemoryBaseAddress(HwUnitId);
  Std_ReturnType retVal = E_NOT_OK;
  uint8 tmpDataCurrByteIndex;

  while((bytesFilled < dataLenFloored) && (busyCheckCounter < VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES))
  {
    busyCheckCounter++;
    
    clcByteCntEnd = bytesFilled + ((vXSpi_Reg_Read(HwUnitId, VXSPI_OSPI_SRAM_FILL_REG_OFFSET) & VXSPI_SRAM_FILL_INDAC_READ_FLD_MASK) * VXSPI_4BYTES_LENGTH);
    if(clcByteCntEnd > dataLenFloored)
    {
      clcByteCntEnd = dataLenFloored;
    }
    
    while(clcByteCnt < clcByteCntEnd)
    {
      /* PRQA S 0303 1 */ /* MD_vXSpi_MemoryMappedAccess */
      tmpData = *((vXSpi_RegPtrType) ospiFssMemRegionAddr);
      
      vXSpi_SerializeFromUint32(tmpData, &DataAndLength->DataBuffer[clcByteCnt]);
      clcByteCnt += VXSPI_4BYTES_LENGTH;
    }
    
    bytesFilled = clcByteCntEnd;
  }
  
  while((bytesFilled < DataAndLength->DataLength) && (busyCheckCounter < VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES))
  {
    busyCheckCounter++;
    if((vXSpi_Reg_Read(HwUnitId, VXSPI_OSPI_SRAM_FILL_REG_OFFSET) & VXSPI_SRAM_FILL_INDAC_READ_FLD_MASK) != 0u)
    {
      /* PRQA S 0303 1 */ /* MD_vXSpi_MemoryMappedAccess */
      tmpData = *((vXSpi_RegPtrType) ospiFssMemRegionAddr);
      tmpDataCurrByteIndex = 0;
      do
      {
        DataAndLength->DataBuffer[bytesFilled] = ((uint8*)&tmpData)[tmpDataCurrByteIndex];
        bytesFilled++;
        tmpDataCurrByteIndex++;
      }while(bytesFilled < DataAndLength->DataLength);
    }
  }
  
  if(bytesFilled == DataAndLength->DataLength)
  {
    retVal = E_OK;
  }
  
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_WriteSram()
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
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_WriteSram(
  vXSpi_DeviceIdType DeviceId,
  vXSpi_ConstDataAndLengthPtrType DataAndLength)
{
  uint32 clcByteCnt = 0u;
  uint32 clcByteCntEnd;
  uint32 dataLenFloored = DataAndLength->DataLength & (VXSPI_4BYTES_FLOOR_MASK);
  uint32 tmpData;
  uint32 bytesFilled = 0u;
  uint32 busyCheckCounter = 0u;
  vXSpi_RegWidthType availableSramBytesSize;
  vXSpi_AddressType ospiFssMemRegionAddr;
  vXSpi_PageSizeType pageSize = vXSpi_Cfg_Device_GetPageSize(DeviceId);
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(DeviceId);
  Std_ReturnType retVal = E_NOT_OK;
  uint8 tmpDataCurrByteIndex;
  
  ospiFssMemRegionAddr = vXSpi_Cfg_HwUnit_GetMemoryBaseAddress(hwUnitId);

  while((bytesFilled <  dataLenFloored) && (busyCheckCounter < VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES))
  {
    busyCheckCounter++;
    
    availableSramBytesSize = pageSize - ((vXSpi_Reg_Read(hwUnitId, VXSPI_OSPI_SRAM_FILL_REG_OFFSET) >> VXSPI_SRAM_FILL_INDAC_WRITE_FLD) * VXSPI_4BYTES_LENGTH);
    
    clcByteCntEnd = bytesFilled + availableSramBytesSize;
    if(clcByteCntEnd > dataLenFloored)
    {
      clcByteCntEnd = dataLenFloored;
    }
    
    while(clcByteCnt < clcByteCntEnd)
    {
      tmpData = vXSpi_DeserializeToUint32(&DataAndLength->DataBuffer[clcByteCnt]);
      /* PRQA S 0303 1 */ /* MD_vXSpi_MemoryMappedAccess */
      *((vXSpi_RegPtrType) ospiFssMemRegionAddr) = tmpData;
      clcByteCnt += VXSPI_4BYTES_LENGTH;
    }
    
    bytesFilled = clcByteCntEnd;
  }
  
  while((bytesFilled < DataAndLength->DataLength) && (busyCheckCounter < VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES))
  {
    busyCheckCounter++;
    
    availableSramBytesSize = pageSize 
      - ((vXSpi_Reg_Read(hwUnitId, VXSPI_OSPI_SRAM_FILL_REG_OFFSET) >> VXSPI_SRAM_FILL_INDAC_WRITE_FLD) * VXSPI_4BYTES_LENGTH);
      
    if(availableSramBytesSize >= (DataAndLength->DataLength - bytesFilled))
    {
      tmpData = 0u;
      tmpDataCurrByteIndex = 0u;
      do
      {
        ((uint8*)&tmpData)[tmpDataCurrByteIndex] = DataAndLength->DataBuffer[bytesFilled];
        tmpDataCurrByteIndex++;
        bytesFilled++;
      }while(bytesFilled < DataAndLength->DataLength);
      
      /* PRQA S 0303 1 */ /* MD_vXSpi_MemoryMappedAccess */
      *((vXSpi_RegPtrType) ospiFssMemRegionAddr) = tmpData;
    }
  }
  
  if(bytesFilled == DataAndLength->DataLength)
  {
    retVal = E_OK;
  }
  
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_SetupIndacRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupIndacRead(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_AddressType Address, 
  vXSpi_DataLengthType DataLength)
{
  vXSpi_DataRateType drt = vXSpi_Cfg_GetProtocolModeDataDataRate(ProtocolModeId);
  vXSpi_DataWidthType dwt = vXSpi_Cfg_GetProtocolModeDataDataWidth(ProtocolModeId);
  vXSpi_DataLengthType correctedDataLength = DataLength;
  
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_IND_AHB_ADDR_TRIGGER_REG_OFFSET, VXSPI_INDIRECT_TRIGGER_BASE_ADDRESS);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_TRIGGER_ADDR_RANGE_REG_OFFSET, VXSPI_TRIGGER_ADDR_RANGE);

  /* In Protocol which has octal data width and DDR as data rate it is needed to read even number of data bytes
  to complete the clock cycle (rising and falling edge of the SCK line). Since the data is later read with 32bit access to the 
  peripheral SRAM and then only necessary number of bytes is copied to the DataBuffer, the change in DataLength at this
  place has no influence on further read behavior. */
  
  if((drt == VXSPI_DATA_RATE_DDR) && (dwt == VXSPI_DATA_WIDTH_OCTAL))
  {
    correctedDataLength = VXSPI_CEIL_2BYTES(DataLength);
  }
  
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_NUM_BYTES_REG_OFFSET, correctedDataLength);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_START_REG_OFFSET, Address);

  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE);   
}

/**********************************************************************************************************************
 *  vXSpi_SetupIndacWrite()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupIndacWrite(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_AddressType Address, 
  vXSpi_DataLengthType DataLength)
{
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_IND_AHB_ADDR_TRIGGER_REG_OFFSET, VXSPI_INDIRECT_TRIGGER_BASE_ADDRESS);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_TRIGGER_ADDR_RANGE_REG_OFFSET, VXSPI_TRIGGER_ADDR_RANGE); 

  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_NUM_BYTES_REG_OFFSET, DataLength);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_START_REG_OFFSET, Address);
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE);
}

/**********************************************************************************************************************
 *  vXSpi_PollStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_PollStatus(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_AddressType RegAddress,
  vXSpi_RegWidthType CompareValue,
  vXSpi_BitShiftType BitShiftValue)
{
  Std_ReturnType retVal = E_OK;
  uint32 busyCheckCounter = 0u;
  vXSpi_RegWidthType status;
  do
  {
    status = vXSpi_Reg_Read(HwUnitId, RegAddress);
    busyCheckCounter++;
  }while((busyCheckCounter <= VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES) 
     && ((status & (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << BitShiftValue)) == (CompareValue << BitShiftValue)));

  if((status & (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << BitShiftValue)) == (CompareValue << BitShiftValue))
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_ProtocolChanged()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_ProtocolChanged(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_CommandType ReadCmd, 
  vXSpi_CommandType WriteCmd, 
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_DummyCycleType DummyCycles)
{
  boolean ProtocolChanged;

  if(ReadCmd != vXSpi_LastUsedConfigs[HwUnitId].ReadCmd)
  {
    ProtocolChanged = TRUE;
  }
  else if(WriteCmd != vXSpi_LastUsedConfigs[HwUnitId].WriteCmd)
  {
    ProtocolChanged = TRUE;
  }
  else if(ProtocolModeId != vXSpi_LastUsedConfigs[HwUnitId].ProtocolModeId)
  {
    ProtocolChanged = TRUE;
  }
  else if(DummyCycles != vXSpi_LastUsedConfigs[HwUnitId].DummyCycles)
  {
    ProtocolChanged = TRUE;
  }
  else
  {
    ProtocolChanged = FALSE;
  }

  return ProtocolChanged;
}

/**********************************************************************************************************************
 *  vXSpi_SetupProtocolProperties()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL_INLINE FUNC(void, VXSPI_CODE) vXSpi_SetupProtocolProperties(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_CommandType ReadCmd,
  vXSpi_CommandType WriteCmd,
  vXSpi_DummyCycleType DummyCycles)
{
  /* Setup the register value for the OSPI_DEV_INSTR_RD_CONFIG_REG */
  vXSpi_RegWidthType regVal = 
    ((((vXSpi_RegWidthType) DummyCycles) << VXSPI_DUMMY_RD_CLK_CYCLES_FLD)
    |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeCommandDataWidth(ProtocolModeId)) << VXSPI_INSTR_TYPE_FLD)
    |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeAddressDataWidth(ProtocolModeId)) << VXSPI_ADDR_XFER_TYPE_STD_MODE_FLD)
    |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeDataDataWidth(ProtocolModeId))    << VXSPI_DATA_XFER_TYPE_EXT_MODE_FLD)
    |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeDataDataRate(ProtocolModeId))     << VXSPI_DDR_EN_FLD)
    |((vXSpi_RegWidthType) ReadCmd                                                     << VXSPI_RD_OPCODE_NON_XIP_FLD));            /* PRQA S 2985 */ /* MD_vXSpi_ZeroShift */

  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_DEV_INSTR_RD_CONFIG_REG_OFFSET, regVal);

  /* Setup the register value for the OSPI_DEV_INSTR_WR_CONFIG_REG */
  regVal = (((vXSpi_RegWidthType) DummyCycles)                                                << VXSPI_DUMMY_WR_CLK_CYCLES_FLD)
           |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeAddressDataWidth(ProtocolModeId)) << VXSPI_ADDR_XFER_TYPE_STD_MODE_FLD) 
           |(((vXSpi_RegWidthType) vXSpi_Cfg_GetProtocolModeDataDataWidth(ProtocolModeId))    << VXSPI_DATA_XFER_TYPE_EXT_MODE_FLD)
           |((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE                                          << VXSPI_WEL_DIS_FLD)
           |((vXSpi_RegWidthType) WriteCmd                                                    << VXSPI_WR_OPCODE_FLD);             /* PRQA S 2985 */ /* MD_vXSpi_ZeroShift */

  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_DEV_INSTR_WR_CONFIG_REG_OFFSET, regVal);
}

/**********************************************************************************************************************
 *  vXSpi_SetupProtocol()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupProtocol(
  vXSpi_HwUnitIdType HwUnitId,
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_CommandType ReadCmd,
  vXSpi_CommandType WriteCmd,
  vXSpi_DummyCycleType DummyCycles)
{
  if(vXSpi_ProtocolChanged(HwUnitId, ReadCmd, WriteCmd, ProtocolModeId, DummyCycles) == TRUE)
  {   
    vXSpi_LastUsedConfigs[HwUnitId].ReadCmd = ReadCmd;
    vXSpi_LastUsedConfigs[HwUnitId].WriteCmd = WriteCmd;
    vXSpi_LastUsedConfigs[HwUnitId].ProtocolModeId = ProtocolModeId;
    vXSpi_LastUsedConfigs[HwUnitId].DummyCycles = DummyCycles;
    vXSpi_SetupProtocolProperties(HwUnitId, ProtocolModeId, ReadCmd, WriteCmd, DummyCycles);
  }
}

/**********************************************************************************************************************
 *  vXSpi_SetupDeviceProperties()
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
VXSPI_PERIPHERAL_LOCAL FUNC(void, VXSPI_CODE) vXSpi_SetupDeviceProperties(vXSpi_HwUnitIdType HwUnitId,
  vXSpi_DeviceIdType DeviceId, vXSpi_AddressFormatType TxAddressFormat)
{
  vXSpi_RegWidthType chipSelectMask;

  /* Setup the register value for the OSPI_DEV_SIZE_CONFIG_REG. */ 
  vXSpi_RegWidthType regVal =
    (((vXSpi_RegWidthType) vXSpi_Cfg_Device_GetPageSize(DeviceId))        << VXSPI_BYTES_PER_DEVICE_PAGE_FLD)
    | (((vXSpi_RegWidthType)TxAddressFormat) << VXSPI_NUM_DEV_ADDR_BYTES_FLD);     /* PRQA S 2985 */ /* MD_vXSpi_ZeroShift */
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_DEV_SIZE_CONFIG_REG_OFFSET, regVal); 

  chipSelectMask = ((((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << vXSpi_Cfg_Device_GetChipSelectIndex(DeviceId)) ^ VXSPI_PERIPH_CS_LINES_BIT_MASK);

  /* Setup the register value for the OSPI_CONFIG_REG. */  
  regVal = ((vXSpi_Reg_Read(HwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET)                                             /* Read Register Value. */
         & (~(((vXSpi_RegWidthType) VXSPI_PERIPH_CS_LINES_BIT_MASK)              << VXSPI_PERIPH_CS_LINES_FLD)) /* Clear PERIPH_CS_LINES_FLD. */
         & (~(((vXSpi_RegWidthType) VXSPI_MSTR_BAUD_DIV_BIT_MASK)                << VXSPI_MSTR_BAUD_DIV_FLD)))  /* Clear MSTR_BAUD_DIV_FLD. */
         | (chipSelectMask                                                       << VXSPI_PERIPH_CS_LINES_FLD)  /* Set PERIPH_CS_LINES_FLD. */
         | (((vXSpi_RegWidthType) vXSpi_Cfg_Device_GetBaudRateDivider(DeviceId)) << VXSPI_MSTR_BAUD_DIV_FLD));  /* Set MSTR_BAUD_DIV_FLD. */ 
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET, regVal);

  /* Modify the OSPI_DEV_DELAY_REG. */
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_DEV_DELAY_REG_OFFSET, vXSpi_Cfg_Device_GetDevDelayReg(DeviceId));
  
  /* Modify the OSPI_RD_DATA_CAPTURE_REG. */
  vXSpi_Reg_Write(HwUnitId, VXSPI_OSPI_RD_DATA_CAPTURE_REG, vXSpi_Cfg_Device_GetRdDataCaptureReg(DeviceId));
}

/**********************************************************************************************************************
 *  vXSpi_SetupDevice()
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
VXSPI_PERIPHERAL_LOCAL FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_SetupDevice(vXSpi_HwUnitIdType HwUnitId, 
  vXSpi_DeviceIdType DeviceId, vXSpi_AddressFormatType TxAddressFormat)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(vXSpi_PollStatus(HwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET, VXSPI_REG_VAL_FALSE, VXSPI_IDLE_FLD) == E_OK)
  {
    /* Check if device changed */
    if((vXSpi_LastUsedConfigs[HwUnitId].DeviceId != DeviceId) 
      || (vXSpi_LastUsedConfigs[HwUnitId].TxAddressFormat != TxAddressFormat))
    {
      vXSpi_LastUsedConfigs[HwUnitId].DeviceId = DeviceId;
      vXSpi_LastUsedConfigs[HwUnitId].TxAddressFormat = TxAddressFormat;
      vXSpi_SetupDeviceProperties(HwUnitId, DeviceId, TxAddressFormat);
    }
    retVal = E_OK;
  }
  
  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vXSpi_Peripheral_Init()
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
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  vXSpi_HwUnitIdType hwUnitId;
  vXSpi_DeviceIdType deviceId;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  for(deviceId = 0; deviceId < vXSpi_ConfigPtr->NumberOfDevices; deviceId++)
  {
    hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(deviceId);
    
    vXSpi_LastUsedConfigs[hwUnitId].ReadCmd = VXSPI_READ_CMD_INIT_VALUE;
    vXSpi_LastUsedConfigs[hwUnitId].WriteCmd = VXSPI_WRITE_CMD_INIT_VALUE;
    vXSpi_LastUsedConfigs[hwUnitId].ProtocolModeId = VXSPI_NUMBER_OF_PROTOCOL_MODES;
    vXSpi_LastUsedConfigs[hwUnitId].DeviceId = vXSpi_ConfigPtr->NumberOfDevices;
    /* Device ID is set to invalid value which triggers execution of vXSpi_SetupDeviceProperties().
       Setting  TxAddressFormat to a valid value will have no influence on 
      first time triggering the vXSpi_SetupDeviceProperties(). */
    vXSpi_LastUsedConfigs[hwUnitId].TxAddressFormat = VXSPI_ADDRESS_FORMAT_1_BYTE;
    
    if(vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_CONFIG_REG_OFFSET, VXSPI_REG_VAL_FALSE, VXSPI_IDLE_FLD) == E_OK)
    {
      vXSpi_DisableDAC(hwUnitId);
      vXSpi_DisableAutomaticPolling(hwUnitId);
    }
    else
    {
      retVal = E_NOT_OK;
      break;
    }
    
    vXSpi_TransactionResults[deviceId] = VXSPI_TRANSACTION_OK;
  }
  
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdAddrRxData()
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
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddrRxData
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(CmdAddrInfo->DeviceId);

  /* ----------- Implementation ------------------------------------------------------------------ */
  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = VXSPI_TRANSACTION_PENDING;
  
  if(vXSpi_SetupDevice(hwUnitId, CmdAddrInfo->DeviceId, CmdAddrInfo->AddressAndFormat->AddressFormat) == E_OK)
  {
    vXSpi_SetupProtocol(hwUnitId, CmdAddrInfo->ProtocolModeId, CmdAddrInfo->Command, 
                    vXSpi_LastUsedConfigs[hwUnitId].WriteCmd, DummyCycles);
                    
    vXSpi_SetupIndacRead(hwUnitId, CmdAddrInfo->ProtocolModeId, CmdAddrInfo->AddressAndFormat->Address, DataAndLength->DataLength);
    
    if(vXSpi_ReadSram(hwUnitId, DataAndLength) == E_OK)
    {
      retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_CTRL_REG_OFFSET, VXSPI_REG_VAL_FALSE, VXSPI_IND_OPS_DONE_STATUS_FLD);
    }
    
    if(retVal != E_OK)
    {
      /* trigger CANCEL_FLD */
      vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_CTRL_REG_OFFSET, 
        (vXSpi_RegWidthType) (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << VXSPI_CANCEL_FLD)); 
    }
    
    /* clear IND_OPS_DONE_STATUS_FLD */
    vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_INDIRECT_READ_XFER_CTRL_REG_OFFSET, 
      (vXSpi_RegWidthType) (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << VXSPI_IND_OPS_DONE_STATUS_FLD)); 
  }

  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdAddrTxData()
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
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddrTxData
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(CmdAddrInfo->DeviceId);

  /* ----------- Implementation ------------------------------------------------------------------ */
  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = VXSPI_TRANSACTION_PENDING;
  
  
  if(vXSpi_SetupDevice(hwUnitId, CmdAddrInfo->DeviceId, CmdAddrInfo->AddressAndFormat->AddressFormat) == E_OK)
  {
    vXSpi_SetupProtocol(hwUnitId, CmdAddrInfo->ProtocolModeId, vXSpi_LastUsedConfigs[hwUnitId].ReadCmd, 
                        CmdAddrInfo->Command, DummyCycles);
                        
    vXSpi_SetupIndacWrite(hwUnitId, CmdAddrInfo->AddressAndFormat->Address, DataAndLength->DataLength);

    if(vXSpi_WriteSram(CmdAddrInfo->DeviceId, DataAndLength) == E_OK) 
    {
      retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_CTRL_REG_OFFSET, VXSPI_REG_VAL_FALSE, VXSPI_IND_OPS_DONE_STATUS_FLD);
    }

    if(retVal != E_OK)
    {
      /* Trigger CANCEL_FLD. */
      vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_CTRL_REG_OFFSET, 
        (vXSpi_RegWidthType) (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << VXSPI_CANCEL_FLD)); 
    }
    
    /* Clear IND_OPS_DONE_STATUS_FLD. */
    vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_INDIRECT_WRITE_XFER_CTRL_REG_OFFSET, 
      (vXSpi_RegWidthType) (((vXSpi_RegWidthType) VXSPI_REG_VAL_TRUE) << VXSPI_IND_OPS_DONE_STATUS_FLD));
  }

  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdRxData()
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
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdRxData
(
    vXSpi_CmdInfoPtrType CmdInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vXSpi_RegWidthType regVal;
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(CmdInfo->DeviceId);

  /* ----------- Implementation ------------------------------------------------------------------ */
  vXSpi_TransactionResults[CmdInfo->DeviceId] = VXSPI_TRANSACTION_PENDING;
  if(vXSpi_SetupDevice(hwUnitId, CmdInfo->DeviceId, VXSPI_ADDRESS_FORMAT_1_BYTE) == E_OK)
  {
    vXSpi_SetupFlsCmd(CmdInfo->DeviceId, CmdInfo->Command, VXSPI_REG_VAL_TRUE, VXSPI_REG_VAL_FALSE, 
                      VXSPI_ADDRESS_FORMAT_1_BYTE, VXSPI_REG_VAL_FALSE, DataAndLength->DataLength, DummyCycles); 
    vXSpi_TriggerCmd(hwUnitId);
    retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE, VXSPI_CMD_EXEC_STATUS_FLD);
    
    if(retVal == E_OK)
    {
      regVal = vXSpi_Reg_Read(hwUnitId, VXSPI_OSPI_FLASH_RD_DATA_LOWER_REG_OFFSET);
      VStdLib_MemCpy(DataAndLength->DataBuffer, &regVal, DataAndLength->DataLength); /* PRQA S 0314, 0315 */ /* MD_MSR_VStdLibCopy */
    }
  }
  vXSpi_TransactionResults[CmdInfo->DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdTxData()
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
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdTxData
(
    vXSpi_CmdInfoPtrType CmdInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  vXSpi_RegWidthType regVal = 0;
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(CmdInfo->DeviceId);
  
  /* ----------- Implementation ------------------------------------------------------------------ */
  vXSpi_TransactionResults[CmdInfo->DeviceId] = VXSPI_TRANSACTION_PENDING;
  if(vXSpi_SetupDevice(hwUnitId, CmdInfo->DeviceId, VXSPI_ADDRESS_FORMAT_1_BYTE) == E_OK)
  {
    vXSpi_SetupFlsCmd(CmdInfo->DeviceId, CmdInfo->Command, VXSPI_REG_VAL_FALSE, VXSPI_REG_VAL_FALSE, 
                      VXSPI_ADDRESS_FORMAT_1_BYTE, VXSPI_REG_VAL_TRUE, DataAndLength->DataLength, DummyCycles); 
    
    VStdLib_MemCpy(&regVal, DataAndLength->DataBuffer, DataAndLength->DataLength); /* PRQA S 0314, 0315 */ /* MD_MSR_VStdLibCopy */
    vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_FLASH_WR_DATA_LOWER_REG_OFFSET, regVal);
        
    vXSpi_TriggerCmd(hwUnitId);
    retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE, VXSPI_CMD_EXEC_STATUS_FLD);
  }
  vXSpi_TransactionResults[CmdInfo->DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmd()
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
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmd
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(DeviceId);

  /* ----------- Implementation ------------------------------------------------------------------ */
  vXSpi_TransactionResults[DeviceId] = VXSPI_TRANSACTION_PENDING;
  if(vXSpi_SetupDevice(hwUnitId, DeviceId, VXSPI_ADDRESS_FORMAT_1_BYTE) == E_OK)
  {
    vXSpi_SetupFlsCmd(DeviceId, Command, VXSPI_REG_VAL_FALSE, VXSPI_REG_VAL_FALSE, VXSPI_ADDRESS_FORMAT_1_BYTE, 
                      VXSPI_REG_VAL_FALSE, 0u, 0u);            
    vXSpi_TriggerCmd(hwUnitId);
    retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE, VXSPI_CMD_EXEC_STATUS_FLD);
  }
  
  vXSpi_TransactionResults[DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  VXSPI_DUMMY_STATEMENT_CONST(ProtocolModeId); /*lint !e438 */
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdAddr()
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
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddr
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  vXSpi_HwUnitIdType hwUnitId = vXSpi_Cfg_Device_GetHwUnitId(CmdAddrInfo->DeviceId);

  /* ----- Implementation ----------------------------------------------- */
  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = VXSPI_TRANSACTION_PENDING;
  if(vXSpi_SetupDevice(hwUnitId, CmdAddrInfo->DeviceId, CmdAddrInfo->AddressAndFormat->AddressFormat) == E_OK)
  {
    vXSpi_SetupFlsCmd(CmdAddrInfo->DeviceId, CmdAddrInfo->Command, VXSPI_REG_VAL_FALSE, VXSPI_REG_VAL_TRUE,
                      CmdAddrInfo->AddressAndFormat->AddressFormat, VXSPI_REG_VAL_FALSE, 0u, 0u);
                      
    vXSpi_Reg_Write(hwUnitId, VXSPI_OSPI_FLASH_CMD_ADDR_REG_OFFSET, CmdAddrInfo->AddressAndFormat->Address);               
    vXSpi_TriggerCmd(hwUnitId);
    retVal = vXSpi_PollStatus(hwUnitId, VXSPI_OSPI_FLASH_CMD_CTRL_REG_OFFSET, VXSPI_REG_VAL_TRUE, VXSPI_CMD_EXEC_STATUS_FLD);
  }
  
  vXSpi_TransactionResults[CmdAddrInfo->DeviceId] = (retVal == E_OK) ? VXSPI_TRANSACTION_OK : VXSPI_TRANSACTION_FAILED;
  return retVal;
}

/**********************************************************************************************************************
 *  vXSpi_Peripheral_GetTransactionResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vXSpi_TransactionResultType, VXSPI_CODE) vXSpi_Peripheral_GetTransactionResult
(
    vXSpi_DeviceIdType DeviceId
)
{
  /* ----------- Implementation ------------------------------------------------------------------ */
  return vXSpi_TransactionResults[DeviceId];
}

#define VXSPI_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 **********************************************************************************************************************/

/* START_COVERAGE_JUSTIFICATION

 \ID COV_VXSPI_COMPATIBILITY
   \ACCEPT TX
   \REASON [COV_MSR_COMPATIBILITY]

 END_COVERAGE_JUSTIFICATION
 */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi_Peripheral.c
 *********************************************************************************************************************/
