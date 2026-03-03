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
/*!        \file  vXSpi_Peripheral.h
 *        \brief  Header file of the Peripheral abstraction of the vXSpi driver.
 *
 *      \details  Describe the Peripheral here in more detail.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VXSPI_PERIPHERAL_H)
# define VXSPI_PERIPHERAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (VXSPI_PERIPHERAL_INLINE) /* COV_VXSPI_COMPATIBILITY */
#  define VXSPI_PERIPHERAL_INLINE static INLINE
# endif /* VXSPI_PERIPHERAL_INLINE */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct
{
  vXSpi_DeviceIdType DeviceId; /*!< Id of the external device. */
  vXSpi_ProtocolModeIdType ProtocolModeId; /*!< Enum with xSPI protocol configurations. */
  vXSpi_CommandType Command; /*!< xSPI command to receive data. */
  vXSpi_AddressAndFormatPtrType AddressAndFormat; /*!< Pointer to struct with Address and AddressFormat. */
} vXSpi_CmdAddrInfoType;
typedef P2CONST(vXSpi_CmdAddrInfoType, AUTOMATIC, VXSPI_VAR) vXSpi_CmdAddrInfoPtrType;

typedef struct
{
  vXSpi_DeviceIdType DeviceId; /*!< Id of the external device. */
  vXSpi_ProtocolModeIdType ProtocolModeId; /*!< Enum with xSPI protocol configurations. */
  vXSpi_CommandType Command; /*!< xSPI command to receive data. */
} vXSpi_CmdInfoType;
typedef P2CONST(vXSpi_CmdInfoType, AUTOMATIC, VXSPI_VAR) vXSpi_CmdInfoPtrType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VXSPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * vXSpi_Peripheral_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the peripheral module of vXSpi.
 *  \return      E_NOT_OK - Initialization failed.
 *  \return      E_OK - Intitalization successful.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE

 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_Init(void);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdAddrRxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command, address and receiving data.
 *  \details     -
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to receive data.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between address and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddrRxData
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdAddrTxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command, address and data.
 *  \details     -
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between address and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddrTxData
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdRxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and receiving data.
 *  \details     -
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to receive data.
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between command and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdRxData
(
    vXSpi_CmdInfoPtrType CmdInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_DataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmdTxData()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and data.
 *  \details     -
 *  \param[in]   TxCmd                   Pointer to struct with .
 *  \param[in]   DummyCycles             Number of dummy cycles to transmit between command and data.
 *  \param[in]   DataAndLength           Pointer to struct with pointer to data buffer and data length.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdTxData
(
    vXSpi_CmdInfoPtrType CmdInfo,
    vXSpi_DummyCycleType DummyCycles,
    vXSpi_ConstDataAndLengthPtrType DataAndLength
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCmd()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command.
 *  \details     -
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmd
(
    vXSpi_DeviceIdType DeviceId,
    vXSpi_ProtocolModeIdType ProtocolModeId,
    vXSpi_CommandType Command
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_TxCommandAddr()
 *********************************************************************************************************************/
/*! \brief       Asynchronous service to start a xSPI transaction by transmitting command and address.
 *  \details     -
 *  \param[in]   DeviceId                Id of the external device.
 *  \param[in]   ProtocolModeId          Enum with xSPI protocol configurations.
 *  \param[in]   Command                 xSPI command to transmit.
 *  \param[in]   AddressAndFormat        Pointer to struct with Address and AddressFormat.
 *  \return      E_NOT_OK -
 *  \return      E_OK -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VXSPI_CODE) vXSpi_Peripheral_TxCmdAddr
(
    vXSpi_CmdAddrInfoPtrType CmdAddrInfo
);

/**********************************************************************************************************************
 *  vXSpi_Peripheral_GetTransactionResult()
 *********************************************************************************************************************/
/*! \brief       Returns the result of the last transaction for the requested device.
 *  \details     Returns the result of the last accepted transaction, as long as no new transaction was accepted.
 *  \param[in]   DeviceId                Id of the external device.
 *  \return      vXSpi_Peripheral_TRANSACTION_OK - The transaction finished successfully.
 *  \return      vXSpi_Peripheral_TRANSACTION_OK_FAILED - The transaction failed.
 *  \return      vXSpi_Peripheral_TRANSACTION_OK_PENDING - The transaction has not yet been finished.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(vXSpi_TransactionResultType, VXSPI_CODE) vXSpi_Peripheral_GetTransactionResult
(
    vXSpi_DeviceIdType DeviceId
);

# define VXSPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* VXSPI_PERIPHERAL_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi_Peripheral.h
 *********************************************************************************************************************/
