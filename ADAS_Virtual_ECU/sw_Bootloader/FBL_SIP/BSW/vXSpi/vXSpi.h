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
/*!        \file  vXSpi.h
 *        \brief  vXSpi header file
 *      \details  vXSpi driver for the Jacinto7 platform
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2021-07-19  virepm  CTM-3247      Initial Implementation.
 *  01.00.01  2021-12-01  virzln  -             inc file updated.
 *  02.00.00  2022-03-17  virzln  CTM-4524      Adapt the vXSpi driver to the modifications of the vXSpi interface. 
 *********************************************************************************************************************/

#if !defined (VXSPI_H)
# define VXSPI_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vXSpi_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VXSPI_VENDOR_ID                           (30u)
# define VXSPI_MODULE_ID                           (0xFFu)

/* AUTOSAR Software specification version information */
# define VXSPI_AR_RELEASE_MAJOR_VERSION            (4u)
# define VXSPI_AR_RELEASE_MINOR_VERSION            (0u)
# define VXSPI_AR_RELEASE_REVISION_VERSION         (3u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VXSPI_SW_MAJOR_VERSION                    (2u)
# define VXSPI_SW_MINOR_VERSION                    (0u)
# define VXSPI_SW_PATCH_VERSION                    (0u)

# define VXSPI_INSTANCE_ID_DET                     (0x00u)

/* ----- API service IDs ----- */
# define VXSPI_SID_INIT                            (0x00u) /*!< Service ID: vXSpi_Init() */
# define VXSPI_SID_TX_CMD_ADDR_RX_DATA             (0x01u) /*!< Service ID: vXSpi_TxCmdAddrRxData() */
# define VXSPI_SID_TX_CMD_ADDR_TX_DATA             (0x02u) /*!< Service ID: vXSpi_TxCmdAddrTxData() */
# define VXSPI_SID_TX_CMD_RX_DATA                  (0x03u) /*!< Service ID: vXSpi_TxCmdRxData() */
# define VXSPI_SID_TX_CMD_TX_DATA                  (0x04u) /*!< Service ID: vXSpi_TxCmdTxData() */
# define VXSPI_SID_TX_CMD                          (0x05u) /*!< Service ID: vXSpi_TxCmd() */
# define VXSPI_SID_TX_CMD_ADDR                     (0x06u) /*!< Service ID: vXSpi_TxCmdAddr() */
# define VXSPI_SID_GET_VERSION_INFO                (0x07u) /*!< Service ID: vXSpi_GetVersionInfo() */
# define VXSPI_SID_GET_TRANSACTION_RESULT          (0x08u) /*!< Service ID: vXSpi_GetTransactionResult() */

/* ----- Error codes ----- */
# define VXSPI_E_NO_ERROR                          (0x00u) /*!< used to check if no error occurred - use a value unequal to any error code */
# define VXSPI_E_UNINIT                            (0x01u) /*!< Error code: API service used without module initialization */
# define VXSPI_E_ALREADY_INITIALIZED               (0x02u) /*!< Error code: The service vXSpi_Init() is called while the module is already initialized  */
# define VXSPI_E_INITIALIZATION_FAILED             (0x03u) /*!< Error code: Initialization failed  */
# define VXSPI_E_TRANSACTION_PENDING               (0x04u) /*!< Error code: Transaction for requested device is pending. */
# define VXSPI_E_PARAM_DEVICE_ID                   (0x05u) /*!< Error code: API Service used with invalid DeviceId parameter (exceeds number of devices) */
# define VXSPI_E_PARAM_PROTOCOL_MODE_ID            (0x06u) /*!< Error code: API Service used with invalid ProtocolModeId parameter (exceeds number of configured protocol modes) */
# define VXSPI_E_PARAM_ADDRESS_FORMAT              (0x07u) /*!< Error code: API Service used with invalid AddressFormat parameter (address format not known) */
# define VXSPI_E_PARAM_ADDRESS                     (0x08u) /*!< Error code: API Service used with invalid AddressFormat parameter (exceeds valid address of the external device) */
# define VXSPI_E_PARAM_DUMMY_CYCLES                (0x09u) /*!< Error code: API Service used with invalid DummyCycles parameter (exceeds number of dummy cycles supported by the xSPI peripheral) */
# define VXSPI_E_PARAM_POINTER                     (0x0Au) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define VXSPI_E_PARAM_DATA_LENGTH                 (0x0Bu) /*!< Error code: API service used with invalid DataLength parameter */
# define VXSPI_E_PARAM_DATA_BUFFER_ALIGNMENT       (0x0Cu) /*!< Error code: API service used with invalid alignment of data buffer pointer */

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
# define VXSPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vXSpi_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Initialization for *_INIT_*-variables
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VXSPI_CODE) vXSpi_InitMemory(void);

/**********************************************************************************************************************
 * vXSpi_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function.
 *  \details     Service to initialize the module vXSpi. It initializes the xSPI peripheral, all variables and 
                 sets the module state to initialized.
 *  \param[in]   ConfigPtr               Pointer to the configuration data.
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         vXSpi_InitMemory has been called unless vXSpi_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, VXSPI_CODE) vXSpi_Init(vXSpi_ConfigPtrType ConfigPtr);

/**********************************************************************************************************************
 *  vXSpi_TxCmdAddrRxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command, address and receiving data.
 *  \details     Is used to read data from the external device.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to receive data.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *                                       AddressFormat: Enum with the address format (length of the address in bytes).
                                         Address: Address to transmit.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between address and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *                                       DataBuffer: Pointer to buffer with data to be received.
 *                                       DataLength: Length of data in bytes to be received.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        DataBuffer pointer must stay valid until transaction is complete.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddrRxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_TxCmdAddrTxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command, address and data.
 *  \details     Is used to write data to the external device.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *                                       AddressFormat: Enum with the address format (length of the address in bytes).
                                         Address: Address to transmit.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between address and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *                                       DataBuffer: Pointer to buffer with data to be transmitted.
 *                                       DataLength: Length of data in bytes to be transmitted.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        DataBuffer pointer must stay valid until transaction is complete.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddrTxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_TxCmdRxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and receiving data.
 *  \details     Is used to receive data from the external device. 
 *               Usually used to read from a register.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to receive data.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between command and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *                                       DataBuffer: Pointer to buffer with data to be received.
 *                                       DataLength: Length of data in bytes to be received.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function does not check the maximum supported data length supported by the device.
 *               If the data length is too long for the command, the driver continuous reading. The most
 *               devices start repeating the data.
 *               DataBuffer pointer must stay valid until transaction is complete.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdRxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_TxCmdTxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and data.
 *  \details     Is used to transmit data to the external device. 
 *               Usually used to write to a register.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit data.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between command and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *                                       DataBuffer: Pointer to buffer with data to be transmitted.
 *                                       DataLength: Length of data in bytes to be transmitted.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This function does not check the maximum supported data length supported by the device.
 *               If the data length is too long for the command, the driver continuous writing. Depends
 *               on the device what happens. Normally the too much data is discarded.
 *               DataBuffer pointer must stay valid until transaction is complete.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdTxData
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_TxCmd()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command.
 *  \details     Is used to transmit a command to the external device without data or address. 
 *               Usually used for commands like write enable.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmd
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command
);

/**********************************************************************************************************************
 *  vXSpi_TxCommandAddr()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and address.
 *  \details     Is used to transmit a command and address to the external device without data. 
 *               Usually used for commands like sector erase.
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *                                       AddressFormat: Enum with the address format (length of the address in bytes).
                                         Address: Address to transmit.
 *  \return      E_NOT_OK - Function has been called with invalid parameters or transaction is ongoing.
 *                          If the mentioned does not apply, unspecified hardware error occurred.
 *  \return      E_OK - Transaction could be started successfully.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_TxCmdAddr
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command,
    vXSpi_AddressAndFormatPtrType AddressAndFormat
);

/**********************************************************************************************************************
 *  vXSpi_GetTransactionResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the last transaction for the requested device.
 *  \details     Returns the result of the last accepted transaction, as long as no new transaction was accepted.
 *  \param[in]   DeviceId                Id of the external device.
 *  \return      VXSPI_TRANSACTION_OK - The transaction finished successfully.
 *  \return      VXSPI_TRANSACTION_OK_FAILED - The transaction failed.
 *  \return      VXSPI_TRANSACTION_OK_PENDING - The transaction has not yet been finished.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(vXSpi_TransactionResultType, VXSPI_CODE) vXSpi_GetTransactionResult
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     This function returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VXSPI_CODE) vXSpi_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, VXSPI_APPL_VAR) Versioninfo
);

# define VXSPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VXSPI_H */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi.h
 *********************************************************************************************************************/
