/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vXSpi.c
 *        \brief  vXSpi source file
 *      \details  See vXSpi.h. 
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define VXSPI_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vXSpi.h"
#include "vXSpi_CfgAccess_Int.h"
#include "vXSpi_Peripheral.h"
 
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
# include "Platform_Types.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vXSpi header file */
#if (  (VXSPI_SW_MAJOR_VERSION != (2u)) \
    || (VXSPI_SW_MINOR_VERSION != (0u)) \
    || (VXSPI_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vXSpi.c and vXSpi.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VXSPI_CFG_MAJOR_VERSION != (2u)) \
    || (VXSPI_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of vXSpi.c and vXSpi_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (VXSPI_LOCAL)
# define VXSPI_LOCAL static
#endif

#if !defined (VXSPI_LOCAL_INLINE)
# define VXSPI_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VXSPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization status of the module */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
VXSPI_LOCAL VAR(vXSpi_StatusType, VXSPI_VAR_INIT) vXSpi_Status = VXSPI_UNINIT;
#endif

#define VXSPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VXSPI_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vXSpi_GetMaxAddressOfDevice()
 *********************************************************************************************************************/
/*! \brief      Calculates the maximum supported address of the given device.
 *  \details    This function retrieves the maximum address of the memory space of the device.
 *              The memory space is always the biggest address space of the device.
 *  \param[in]  DeviceId        Id of the external device.
 *  \return     Maximum address of the device.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetMaxAddressOfDevice
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_GetMaxAddressOfAddressFormat()
 *********************************************************************************************************************/
/*! \brief      Calculates the maximum address of the given address format.
 *  \details    -
 *  \param[in]  AddressFormat   Address format of the address.
 *  \return     Maximum address of address format.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetMaxAddressOfAddressFormat
(
    vXSpi_AddressFormatType AddressFormat
);

/**********************************************************************************************************************
 *  vXSpi_FitsAddressIntoDevice()
 *********************************************************************************************************************/
/*! \brief      Checks if address is smaller than the maximum address supported by the device.
 *  \details    -
 *  \param[in]  DeviceId        Id of the external device.
 *  \param[in]  Address         Address on the external memory device.
 *  \return     TRUE            The requested address is within the valid range.
 *  \return     FALSE           The requested address is not within the valid range.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_FitsAddressIntoDevice
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressType Address
);

/**********************************************************************************************************************
 *  vXSpi_FitsAddressIntoAddressFormat()
 *********************************************************************************************************************/
/*! \brief      Checks if the requested address fits into the given address format.
 *  \details    -
 *  \param[in]  AddressAndFormat  Pointer to struct with Address and AddressFormat.
 *  \return     TRUE              The requested address is within the valid range.
 *  \return     FALSE             The requested address is not within the valid range.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_FitsAddressIntoAddressFormat
(
    vXSpi_AddressAndFormatPtrType AddressAndFormat
);

/**********************************************************************************************************************
 *  vXSpi_DetCheckDataLength()
 *********************************************************************************************************************/
/*! \brief      Checks if the requested data length for the given device is within the valid range.
 *  \details    This function checks if the data length with respect to the address
 *              fits into the memory space of the device.
 *  \param[in]  DeviceId        Id of the external device.
 *  \param[in]  Address         Address on the external memory device.
 *  \param[in]  DataLength      Length of the data in bytes.
 *  \return     TRUE            Length is within the valid range.
 *  \return     FALSE           Length is without the valid range.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckDataLength
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressType Address,
    vXSpi_DataLengthType DataLength
);

/**********************************************************************************************************************
 *  vXSpi_DetCheckAddressFormat()
 *********************************************************************************************************************/
/*! \brief      Checks if the requested address format is within the valid range.
 *  \details    -
 *  \param[in]  AddressFormat   Address format of the address.
 *  \return     TRUE            The requested address format is within the valid range.
 *  \return     FALSE           The requested address format is not within the valid range.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckAddressFormat
(
    vXSpi_AddressFormatType AddressFormat
);

/**********************************************************************************************************************
 *  vXSpi_DetCheckAddress()
 *********************************************************************************************************************/
/*!
 * \brief      Checks if the requested address is within the valid range.
 * \details    -
 * \param[in]  DeviceId        Id of the external device.
 * \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 * \return     TRUE            The requested address is within the valid range.
 * \return     FALSE           The requested address is not within the valid range.
 * \pre        -
 * \context    TASK
 * \reentrant  TRUE
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckAddress
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressAndFormatPtrType AddressAndFormat
);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vXSpi_GetMaxAddressOfDevice()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetMaxAddressOfDevice
(
    vXSpi_DeviceIdType DeviceId
)
{
  /* To get the maximum supported address of the device we use the memory size of the device.
   * Usually all external xSPI devices have more than one address space (e. g. memory address space and
   * register address space. But the memory address space is always the biggest address space).
   * So we check only against the biggest address space. All other address spaces are not known by the
   * vXSpi driver. */
  vXSpi_MemorySizeType memorySize = vXSpi_Cfg_Device_GetMemorySize(DeviceId);
  
  return memorySize - 1u;
} /* vXSpi_GetMaxAddressOfDevice */

/**********************************************************************************************************************
 *  vXSpi_GetMaxAddressOfAddressFormat()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_GetMaxAddressOfAddressFormat
(
    vXSpi_AddressFormatType AddressFormat
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  /* Array holds max address for all specified address formats. */
  const vXSpi_AddressType maxAddressOfAddressFormat[4u] =
  {
    VXSPI_ADDRESS_FORMAT_1_BYTE_MAX_VALUE,
    VXSPI_ADDRESS_FORMAT_2_BYTE_MAX_VALUE,
    VXSPI_ADDRESS_FORMAT_3_BYTE_MAX_VALUE,
    VXSPI_ADDRESS_FORMAT_4_BYTE_MAX_VALUE,
  };

  /* ----------- Implementation ------------------------------------------------------------------ */
  return maxAddressOfAddressFormat[AddressFormat];
} /* vXSpi_GetMaxAddressOfAddressFormat */

/**********************************************************************************************************************
 *  vXSpi_FitsAddressIntoDevice()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_FitsAddressIntoDevice
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressType Address
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  boolean retVal = FALSE;
  vXSpi_AddressType maxAddress;

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Get maximum supported address of the external device. */
  maxAddress = vXSpi_GetMaxAddressOfDevice(DeviceId);

  /* #20 Check if address is in valid range. */
  if(Address <= maxAddress)
  {
    retVal = TRUE;
  }

  return retVal;
} /* vXSpi_FitsAddressIntoDevice */

/**********************************************************************************************************************
 *  vXSpi_FitsAddressIntoAddressFormat()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_FitsAddressIntoAddressFormat
(
    vXSpi_AddressAndFormatPtrType AddressAndFormat
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  boolean retVal = FALSE;
  /* #10 Get maximum supported address of address format. */
  vXSpi_AddressType maxAddress = vXSpi_GetMaxAddressOfAddressFormat(AddressAndFormat->AddressFormat);

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #20 Check if address is in valid range. */
  if(AddressAndFormat->Address <= maxAddress)
  {
    retVal = TRUE;
  }

  return retVal;
} /* vXSpi_FitsAddressIntoAddressFormat */

/**********************************************************************************************************************
 *  vXSpi_DetCheckDataLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckDataLength
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressType Address,
    vXSpi_DataLengthType DataLength
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  boolean retVal = FALSE;
  vXSpi_DataLengthType maxDataLength;
  vXSpi_AddressType maxAddress;

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Get maximum supported address. */
  maxAddress = vXSpi_GetMaxAddressOfDevice(DeviceId);
  /* #20 Calculate the maximum supported data length with respect to the given address. */
  maxDataLength = maxAddress - Address;

  /* #30 Check if data length is in valid range. */
  if((DataLength > 0u) && (DataLength <= maxDataLength))
  {
    retVal = TRUE;
  }

  return retVal;
} /* vXSpi_DetCheckDataLength */

/**********************************************************************************************************************
 *  vXSpi_DetCheckAddressFormat()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckAddressFormat
(
    vXSpi_AddressFormatType AddressFormat
)
{
    /* ----------- Local variables ----------------------------------------------------------------- */
    boolean retVal = FALSE;
    
    /* ----------- Implementation ------------------------------------------------------------------ */
    if(AddressFormat <= VXSPI_ADDRESS_FORMAT_4_BYTE) /*lint !e685 */
    {
        retVal = TRUE;
    }

  return retVal;
} /* vXSpi_DetCheckAddressFormat */

/**********************************************************************************************************************
 *  vXSpi_DetCheckAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VXSPI_LOCAL_INLINE FUNC(boolean, VXSPI_CODE) vXSpi_DetCheckAddress
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_AddressAndFormatPtrType AddressAndFormat
)
{
  /* ----------- Local variables ----------------------------------------------------------------- */
  boolean retVal = FALSE;
  boolean retValCheckAddressIntoDevice = vXSpi_FitsAddressIntoDevice(DeviceId, AddressAndFormat->Address);
  boolean retValCheckAddressIntoAddressFormat = vXSpi_FitsAddressIntoAddressFormat(AddressAndFormat);

  /* ----------- Implementation ------------------------------------------------------------------ */
  /* #10 Check if address is smaller than the maximum address
   *     supported by the device and fits into address format. */
  if((retValCheckAddressIntoDevice == TRUE) && (retValCheckAddressIntoAddressFormat == TRUE))
  {
    retVal = TRUE;
  }

  return retVal;
} /* vXSpi_DetCheckAddress */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vXSpi_InitMemory()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VXSPI_CODE) vXSpi_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
    vXSpi_Status = VXSPI_UNINIT;
#endif
}

/**********************************************************************************************************************
 *  vXSpi_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VXSPI_CODE) vXSpi_Init(vXSpi_ConfigPtrType ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VXSPI_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_INIT)
  {
    errorId = VXSPI_E_ALREADY_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    vXSpi_ConfigPtr = ConfigPtr;
    
    /* #10 Forward request to Peripheral unit. */
    if(vXSpi_Peripheral_Init() == E_NOT_OK)
    {
      errorId = VXSPI_E_INITIALIZATION_FAILED;
    }
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
    else
    {
      vXSpi_Status = VXSPI_INIT;
    }
#endif    
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_INIT, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 * vXSpi_TxCmdAddrRxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddrRxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_CmdAddrInfoType cmdAddrInfo;

  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  /* Check parameter 'AddressAndFormat' is null pointer */
  else if(AddressAndFormat == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'AddressFormat' */
  else if (vXSpi_DetCheckAddressFormat(AddressAndFormat->AddressFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS_FORMAT;
  }
  /* Check parameter 'Address' */
  else if (vXSpi_DetCheckAddress(DeviceId, AddressAndFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS;
  }
  /* Check parameter 'DummyCycles' */
  else if (DummyCycles > VXSPI_DUMMY_CYCLES_MAX)
  {
    errorId = VXSPI_E_PARAM_DUMMY_CYCLES;
  }
  /* Check parameter 'DataAndLength' is null pointer */
  else if (DataAndLength == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataBuffer' is null pointer */
  else if (DataAndLength->DataBuffer == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataLength' */
  else if (vXSpi_DetCheckDataLength(DeviceId, AddressAndFormat->Address, DataAndLength->DataLength) == FALSE)
  {
    errorId = VXSPI_E_PARAM_DATA_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    cmdAddrInfo.DeviceId = DeviceId;
    cmdAddrInfo.ProtocolModeId = ProtocolModeId;
    cmdAddrInfo.Command = Command;
    cmdAddrInfo.AddressAndFormat = AddressAndFormat;

    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmdAddrRxData(&cmdAddrInfo, DummyCycles, DataAndLength);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD_ADDR_RX_DATA, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
}/* PRQA S 6080, 6060, 6030 */ /* MD_MSR_STMIF, MD_MSR_STPAR, MD_MSR_STCYC */

/**********************************************************************************************************************
 * vXSpi_TxCmdAddrTxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddrTxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_CmdAddrInfoType cmdAddrInfo;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  /* Check parameter 'AddressAndFormat' is null pointer */
  else if(AddressAndFormat == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'AddressFormat' */
  else if (vXSpi_DetCheckAddressFormat(AddressAndFormat->AddressFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS_FORMAT;
  }
  /* Check parameter 'Address' */
  else if (vXSpi_DetCheckAddress(DeviceId, AddressAndFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS;
  }
  /* Check parameter 'DummyCycles' */
  else if (DummyCycles > VXSPI_DUMMY_CYCLES_MAX)
  {
    errorId = VXSPI_E_PARAM_DUMMY_CYCLES;
  }
  /* Check parameter 'DataAndLength' is null pointer */
  else if (DataAndLength == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataBuffer' is null pointer */
  else if (DataAndLength->DataBuffer == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataLength' */
  else if (vXSpi_DetCheckDataLength(DeviceId, AddressAndFormat->Address, DataAndLength->DataLength) == FALSE)
  {
    errorId = VXSPI_E_PARAM_DATA_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    cmdAddrInfo.DeviceId = DeviceId;
    cmdAddrInfo.ProtocolModeId = ProtocolModeId;
    cmdAddrInfo.Command = Command;
    cmdAddrInfo.AddressAndFormat = AddressAndFormat;

    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmdAddrTxData(&cmdAddrInfo, DummyCycles, DataAndLength);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD_ADDR_TX_DATA, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080, 6060, 6030 */ /* MD_MSR_STMIF, MD_MSR_STPAR, MD_MSR_STCYC */

/**********************************************************************************************************************
 * vXSpi_TxCmdRxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdRxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_CmdInfoType cmdInfo;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  /* Check parameter 'DummyCycles' */
  else if (DummyCycles > VXSPI_DUMMY_CYCLES_MAX)
  {
    errorId = VXSPI_E_PARAM_DUMMY_CYCLES;
  }
  /* Check parameter 'DataAndLength' is null pointer */
  else if (DataAndLength == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataBuffer' is null pointer */
  else if (DataAndLength->DataBuffer == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataLength', the maximum data length can not be checked because we have no address. */
  else if ((DataAndLength->DataLength == 0u) || (DataAndLength->DataLength > VXSPI_CMD_DATA_LENGTH_MAX))
  {
    errorId = VXSPI_E_PARAM_DATA_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    cmdInfo.DeviceId = DeviceId;
    cmdInfo.ProtocolModeId = ProtocolModeId;
    cmdInfo.Command = Command;

    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmdRxData(&cmdInfo, DummyCycles, DataAndLength);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD_RX_DATA, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */

/**********************************************************************************************************************
 * vXSpi_TxCmdTxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdTxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_CmdInfoType cmdInfo;

  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  /* Check parameter 'DummyCycles' */
  else if (DummyCycles > VXSPI_DUMMY_CYCLES_MAX)
  {
    errorId = VXSPI_E_PARAM_DUMMY_CYCLES;
  }
  /* Check parameter 'DataAndLength' is null pointer */
  else if (DataAndLength == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataBuffer' is null pointer */
  else if (DataAndLength->DataBuffer == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'DataLength', the maximum data length can not be checked because we have no address. */
  else if ((DataAndLength->DataLength == 0u) || (DataAndLength->DataLength > VXSPI_CMD_DATA_LENGTH_MAX))
  {
    errorId = VXSPI_E_PARAM_DATA_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    cmdInfo.DeviceId = DeviceId;
    cmdInfo.ProtocolModeId = ProtocolModeId;
    cmdInfo.Command = Command;
    
    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmdTxData(&cmdInfo, DummyCycles, DataAndLength);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD_TX_DATA, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */

/**********************************************************************************************************************
 * vXSpi_TxCmd()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmd
(
  vXSpi_DeviceIdType DeviceId, 
  vXSpi_ProtocolModeIdType ProtocolModeId,
  vXSpi_CommandType Command
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmd(DeviceId, ProtocolModeId, Command);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 * vXSpi_TxCmdAddr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddr
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_CmdAddrInfoType cmdAddrInfo;

  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  /* Check for pending transaction of requested device */
  else if (vXSpi_GetTransactionResult(DeviceId) == VXSPI_TRANSACTION_PENDING)
  {
    errorId = VXSPI_E_TRANSACTION_PENDING;
  }
  /* Check parameter 'ProtocolModeId' */
  else if (ProtocolModeId >= VXSPI_NUMBER_OF_PROTOCOL_MODES)
  {
    errorId = VXSPI_E_PARAM_PROTOCOL_MODE_ID;
  }
  /* Check parameter 'AddressAndFormat' is null pointer */
  else if(AddressAndFormat == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  /* Check parameter 'AddressFormat' */
  else if (vXSpi_DetCheckAddressFormat(AddressAndFormat->AddressFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS_FORMAT;
  }
  /* Check parameter 'Address' */
  else if (vXSpi_DetCheckAddress(DeviceId, AddressAndFormat) == FALSE)
  {
    errorId = VXSPI_E_PARAM_ADDRESS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    cmdAddrInfo.DeviceId = DeviceId;
    cmdAddrInfo.ProtocolModeId = ProtocolModeId;
    cmdAddrInfo.Command = Command;
    cmdAddrInfo.AddressAndFormat = AddressAndFormat;

    /* #10 Forward request to Peripheral unit. */
    retVal = vXSpi_Peripheral_TxCmdAddr(&cmdAddrInfo);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_TX_CMD_ADDR, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vXSpi_GetTransactionResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(vXSpi_TransactionResultType, VXSPI_CODE) vXSpi_GetTransactionResult(vXSpi_DeviceIdType DeviceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VXSPI_E_NO_ERROR;
  vXSpi_TransactionResultType transactionResult;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  transactionResult = VXSPI_TRANSACTION_FAILED;

  /* Check initialization state of the component */
  if (vXSpi_Status == VXSPI_UNINIT)
  {
    errorId = VXSPI_E_UNINIT;
  }
  /* Check parameter 'DeviceId' */
  else if (DeviceId >= vXSpi_ConfigPtr->NumberOfDevices)
  {
    errorId = VXSPI_E_PARAM_DEVICE_ID;
  }
  else
#endif
  {
    transactionResult = vXSpi_Peripheral_GetTransactionResult(DeviceId);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_GET_TRANSACTION_RESULT, errorId);
  }
#else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
#endif

  return transactionResult;
}

/**********************************************************************************************************************
 *  vXSpi_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VXSPI_CODE) vXSpi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VXSPI_APPL_VAR) Versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VXSPI_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (VXSPI_DEV_ERROR_DETECT == STD_ON)
  if (Versioninfo == NULL_PTR)
  {
    errorId = VXSPI_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    Versioninfo->vendorID = (VXSPI_VENDOR_ID);
    Versioninfo->moduleID = (VXSPI_MODULE_ID);
    Versioninfo->sw_major_version = (VXSPI_SW_MAJOR_VERSION);
    Versioninfo->sw_minor_version = (VXSPI_SW_MINOR_VERSION);
    Versioninfo->sw_patch_version = (VXSPI_SW_PATCH_VERSION);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VXSPI_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VXSPI_E_NO_ERROR)
  {
    (void)Det_ReportError(VXSPI_MODULE_ID, VXSPI_INSTANCE_ID_DET, VXSPI_SID_GET_VERSION_INFO, errorId);
  }
# else
  VXSPI_DUMMY_STATEMENT(errorId); /*lint !e438 */
# endif
}

#define VXSPI_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:

  MD_vXSpi_MemoryMappedAccess: rule 11.3, 3.1, 11.4
    Reason:     vXSpi executes memory accesses memory mapped. This involves a cast between a pointer to a volatile object 
                and an integral type.
    Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
    Prevention: No prevention.

  MD_vXSpi_ZeroShift: Rule 21.1, 2.2
    Reason:     Value 0 gets shifted or value gets shifted by 0. This is practically redundant. However,
                this shift makes the code more readable and comprehensible and makes reviews easier.
                The register bit values can easier be compared to the datasheet values.
    Risk:       No risk.
    Prevention: No prevention.

  MD_vXSpi_3219: Rule11.4
    Reason:     This function is inlined and therefore it has to be implemented here. The function is not used
                by all implementation files which include this header file.
    Risk:       A static non-used function within this unit.
    Prevention: This function is used and shared by several other units. No prevention required.

  MD_vXSpi_0303: Rule11.4
    Reason:     Hardware register accesses need a cast from integral type to a pointer to volatile object.
    Risk:       There is no risk as the register is mapped to the respective memory address.
    Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: vXSpi.c
 *********************************************************************************************************************/
