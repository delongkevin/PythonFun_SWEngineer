/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vXSpi
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vXSpi_Cfg.h
 *   Generation Time: 2024-11-25 15:00:22
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined VXSPI_CFG_H_
# define VXSPI_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "vXSpi_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define VXSPI_CFG_MAJOR_VERSION                       2u
# define VXSPI_CFG_MINOR_VERSION                       0u
# define VXSPI_CFG_PATCH_VERSION                       0u

# define VXSPI_CFG_COMP_MAJOR_VERSION                  2u
# define VXSPI_CFG_COMP_MINOR_VERSION                  0u
# define VXSPI_CFG_COMP_PATCH_VERSION                  0u


# define VXSPI_HARDWARE_LOOP_CYCLES                    1000u
# define VXSPI_SYNCHRONOUS_PROCESSING_LOOP_CYCLES      100000000u

/*! Defines whether development error detection or reporting is enabled or disabled. */
# ifndef VXSPI_DEV_ERROR_DETECT
#  define VXSPI_DEV_ERROR_DETECT STD_ON
# endif
# ifndef VXSPI_DEV_ERROR_REPORT
#  define VXSPI_DEV_ERROR_REPORT STD_ON
# endif

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTS
 *********************************************************************************************************************/
typedef enum
{
  VXSPI_vXSpiProtocolMode_Read,
  VXSPI_vXSpiProtocolMode_Write,
  VXSPI_vXSpiProtocolMode,
  VXSPI_NUMBER_OF_PROTOCOL_MODES
} vXSpi_ProtocolModeIdType;

typedef P2CONST(vXSpi_DeviceIdType, AUTOMATIC, VXSPI_CFG) vXSpi_ConstDeviceIdPtrType;

typedef struct
{
  vXSpi_AddressType MemoryBaseAddress;
  vXSpi_MemorySizeType MemorySize;
  vXSpi_RegWidthType DevDelayReg; /* OSPI_DEV_DELAY_REG */
  vXSpi_RegWidthType RdDataCaptureReg; /* OSPI_RD_DATA_CAPTURE_REG */
  vXSpi_PageSizeType PageSize; /* BYTES_PER_DEVICE_PAGE_FLD */
  vXSpi_BaudrateType BaudrateDivider; /* MSTR_BAUD_DIV_FLD */
  vXSpi_HwUnitIdType HwUnitId;
  vXSpi_ChipSelectIndexType ChipSelectIndex;
} vXSpi_DeviceType;
typedef P2CONST(vXSpi_DeviceType, AUTOMATIC, VXSPI_CFG) vXSpi_ConstDevicePtrType;

typedef struct
{
  vXSpi_DataRateType CommandDataRate;
  vXSpi_DataWidthType CommandDataWidth;
  vXSpi_DataRateType AddressDataRate;
  vXSpi_DataWidthType AddressDataWidth;
  vXSpi_DataRateType DataDataRate;
  vXSpi_DataWidthType DataDataWidth;
  vXSpi_DummyCycleType NumOfDummyCycles;
} vXSpi_ProtocolModeType;
typedef P2CONST(vXSpi_ProtocolModeType, AUTOMATIC, VXSPI_CONST) vXSpi_ConstProtocolModePtrType;

typedef struct
{
  vXSpi_AddressType MemoryBaseAddress;
  vXSpi_AddressType RegisterBaseAddress;
  vXSpi_DeviceIndexType NumberOfDevices;
  uint8 HwUnitToDeviceMapStartIndex;
} vXSpi_HwUnitType;
typedef P2CONST(vXSpi_HwUnitType, AUTOMATIC, VXSPI_CFG) vXSpi_ConstHwUnitPtrType;

typedef struct
{
  vXSpi_ConstProtocolModePtrType ProtocolModes;
  vXSpi_ConstHwUnitPtrType HwUnits;
  vXSpi_ConstDevicePtrType Devices;
  vXSpi_ConstDeviceIdPtrType HwUnitToDeviceMap;
  vXSpi_HwUnitIndexType NumberOfHwUnits;
  vXSpi_DeviceIndexType NumberOfDevices;
} vXSpi_HwConfigType;
typedef P2CONST(vXSpi_HwConfigType, AUTOMATIC, VXSPI_CFG) vXSpi_ConstHwConfigPtrType;

typedef vXSpi_ConstHwConfigPtrType vXSpi_ConfigPtrType;
typedef vXSpi_HwConfigType vXSpi_ConfigType;

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define VXSPI_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(vXSpi_HwConfigType, VXSPI_CONST) vXSpi_HwConfig;

# define VXSPI_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* VXSPI_CFG_H_ */

/*********************************************************************************************************************
 *  END OF FILE: vXSpi_Cfg.h
 *********************************************************************************************************************/

