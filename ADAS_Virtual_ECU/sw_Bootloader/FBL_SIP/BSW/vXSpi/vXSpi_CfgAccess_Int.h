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
/*!        \file  vXSpi_CfgAccess_Int.h
 *        \brief  Configuration access header file
 *
 *      \details  Provides inline functions to access the configuration in an abstracted way.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VXSPI_CFGACCESS_INT_H)
# define VXSPI_CFGACCESS_INT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vXSpi_Cfg_Int.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if !defined (VXSPI_CFG_ACCESS_INLINE) /* COV_VXSPI_COMPATIBILITY */
#  define VXSPI_CFG_ACCESS_INLINE static INLINE
# endif /* VXSPI_CFG_ACCESS_INLINE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
 *  vXSpi_Cfg_Device_GetMemorySize()
 *********************************************************************************************************************/
/*! \brief        Retrieves the memory size in bytes of the given device.
 *  \details      -
 *  \param[in]    deviceId      Id of the external device.
 *  \return       Device memory size in bytes.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_MemorySizeType, VXSPI_CODE) vXSpi_Cfg_Device_GetMemorySize
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetMemoryBaseAddress()
 *********************************************************************************************************************/
/*! \brief        Retrieves the device memory base address of the given device.
 *  \details      -
 *  \param[in]    deviceId      Id of the external device.
 *  \return       Device memory base address.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_MemorySizeType, VXSPI_CODE) vXSpi_Cfg_Device_GetMemoryBaseAddress
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetHwUnitId()
 *********************************************************************************************************************/
/*! \brief        Retrieves the hardware unit Id of the given device.
 *  \details      -
 *  \param[in]    deviceId      Id of the external device.
 *  \return       Id of the hardware unit.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_HwUnitIdType, VXSPI_CODE) vXSpi_Cfg_Device_GetHwUnitId
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetChipSelectIndex()
 *********************************************************************************************************************/
/*! \brief        Retrieves the chip select index of the given device.
 *  \details      -
 *  \param[in]    deviceId      Id of the external device.
 *  \return       Index of the chip select.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_ChipSelectIndexType, VXSPI_CODE) vXSpi_Cfg_Device_GetChipSelectIndex
(
    vXSpi_DeviceIdType DeviceId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetDeviceId()
 *********************************************************************************************************************/
/*! \brief        Retrieves the device id for the selected device of the given hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \param[in]    deviceIndex   Index of the external device.
 *  \return       Id of the hardware unit.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DeviceIdType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetDeviceId
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_DeviceIndexType DeviceIndex
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetNumberOfDevices()
 *********************************************************************************************************************/
/*! \brief        Retrieves the number of configured devices for the given hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \return       Number of devices.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DeviceIndexType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetNumberOfDevices
(
    vXSpi_HwUnitIdType HwUnitId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetRegisterBaseAddress()
 *********************************************************************************************************************/
/*! \brief        Retrieves the register base address of the given hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \return       Register base address.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetRegisterBaseAddress
(
    vXSpi_HwUnitIdType HwUnitId
);


/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetMemoryBaseAddress()
 *********************************************************************************************************************/
/*! \brief        Retrieves the memory base address of the given hardware unit.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \return       Memory base address.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetMemoryBaseAddress
(
    vXSpi_HwUnitIdType HwUnitId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeCommandDataRate()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured command data rate of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data rate of the command
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeCommandDataRate
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeCommandDataWidth()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured command data width of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data width of the command
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeCommandDataWidth
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeAddressDataRate()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured address data rate of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data rate of the address
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeAddressDataRate
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeAddressDataWidth()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured address data width of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data width of the address
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeAddressDataWidth
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeDataDataRate()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured data data rate of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data rate of data
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeDataDataRate
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeDataDataWidth()
 *********************************************************************************************************************/
/*! \brief        Retrieves the configured data data width of the given protocol mode.
 *  \details      -
 *  \param[in]    ProtocolModeId      Id of the protocol mode.
 *  \return       Data width of data
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeDataDataWidth
(
    vXSpi_ProtocolModeIdType ProtocolModeId
);

#if(VXSPI_USE_PERIPHERAL_ACCESS_API == STD_ON)
/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetPeripheralId()
 *********************************************************************************************************************/
/*! \brief        Retrieves the Os Peripheral Id.
 *  \details      -
 *  \param[in]    hwUnitId      Id of the hardware unit.
 *  \return       OsPeripheralRegionId.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 */
VXSPI_CFG_ACCESS_INLINE FUNC(Os_PeripheralIdType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetPeripheralId
(
    vXSpi_HwUnitIdType HwUnitId
);
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetPageSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_PageSizeType, VXSPI_CODE) vXSpi_Cfg_Device_GetPageSize /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].PageSize;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetBaudRateDivider()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_BaudrateType, VXSPI_CODE) vXSpi_Cfg_Device_GetBaudRateDivider /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].BaudrateDivider;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetDevDelayReg()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Cfg_Device_GetDevDelayReg /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].DevDelayReg;
}


/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetRdDataCaptureReg()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_RegWidthType, VXSPI_CODE) vXSpi_Cfg_Device_GetRdDataCaptureReg /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].RdDataCaptureReg;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetMemorySize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_MemorySizeType, VXSPI_CODE) vXSpi_Cfg_Device_GetMemorySize /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].MemorySize;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetMemoryBaseAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_MemorySizeType, VXSPI_CODE) vXSpi_Cfg_Device_GetMemoryBaseAddress /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].MemoryBaseAddress;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetHwUnitId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_HwUnitIdType, VXSPI_CODE) vXSpi_Cfg_Device_GetHwUnitId /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].HwUnitId;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_Device_GetChipSelectIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_ChipSelectIndexType, VXSPI_CODE) vXSpi_Cfg_Device_GetChipSelectIndex /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_DeviceIdType DeviceId
)
{
  return vXSpi_ConfigPtr->Devices[DeviceId].ChipSelectIndex;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetDeviceId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DeviceIdType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetDeviceId /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId,
    vXSpi_DeviceIndexType DeviceIndex
)
{
  uint8 hwUnitToDeviceMapStartIndex = vXSpi_ConfigPtr->HwUnits[HwUnitId].HwUnitToDeviceMapStartIndex;

  return (vXSpi_DeviceIdType) (vXSpi_ConfigPtr->HwUnitToDeviceMap[hwUnitToDeviceMapStartIndex] + DeviceIndex);
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetNumberOfDevices()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DeviceIndexType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetNumberOfDevices /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId
)
{
  return vXSpi_ConfigPtr->HwUnits[HwUnitId].NumberOfDevices;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetRegisterBaseAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetRegisterBaseAddress /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId
)
{
  return vXSpi_ConfigPtr->HwUnits[HwUnitId].RegisterBaseAddress;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetMemoryBaseAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_AddressType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetMemoryBaseAddress /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId
)
{
  return vXSpi_ConfigPtr->HwUnits[HwUnitId].MemoryBaseAddress;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeCommandDataRate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeCommandDataRate /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].CommandDataRate;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeCommandDataWidth()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeCommandDataWidth /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].CommandDataWidth;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeAddressDataRate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeAddressDataRate /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].AddressDataRate;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeAddressDataWidth()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeAddressDataWidth /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].AddressDataWidth;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeDataDataRate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataRateType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeDataDataRate /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].DataDataRate;
}

/**********************************************************************************************************************
 *  vXSpi_Cfg_GetProtocolModeDataDataWidth()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(vXSpi_DataWidthType, VXSPI_CODE) vXSpi_Cfg_GetProtocolModeDataDataWidth /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_ProtocolModeIdType ProtocolModeId
)
{
  return vXSpi_ConfigPtr->ProtocolModes[ProtocolModeId].DataDataWidth;
}

#if(VXSPI_USE_PERIPHERAL_ACCESS_API == STD_ON)
/**********************************************************************************************************************
 *  vXSpi_Cfg_HwUnit_GetPeripheralId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VXSPI_CFG_ACCESS_INLINE FUNC(Os_PeripheralIdType, VXSPI_CODE) vXSpi_Cfg_HwUnit_GetPeripheralId /* PRQA S 3219 */ /* MD_vXSpi_3219 */
(
    vXSpi_HwUnitIdType HwUnitId
)
{
  return vXSpi_ConfigPtr->HwUnits[HwUnitId].OsPeripheralRegionId;
}
#endif

# define VXSPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* VXSPI_CFGACCESS_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: vXSpi_CfgAccess_Int.h
 *********************************************************************************************************************/

