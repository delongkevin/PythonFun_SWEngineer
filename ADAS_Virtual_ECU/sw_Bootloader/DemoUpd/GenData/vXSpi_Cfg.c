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
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vXSpi_Cfg.c
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#define VXSPI_CFG_C_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "vXSpi_Cfg.h"
#include "vXSpi_Cfg_Int.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VXSPI_LOCAL)
# define VXSPI_LOCAL static
#endif

/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/
#define VXSPI_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
VXSPI_LOCAL CONST(vXSpi_DeviceType, VXSPI_CONST) vXSpi_Devices_HwConfig[1] =
{
  {
    0x50000000u /*  MemoryBaseAddress  */ , 
    0x08000000u /*  MemorySize  */ , 
    0x40400808u /*  Device Delay Register Value  */ , 
    0x00000001u /*  Read Data Capture Register Value  */ , 
    4095u /*  PageSize  */ , 
    1u /*  Baudrate Divider  */ , 
    0u /*  HwUnitId  */ , 
    0u /*  ChipSelectIndex  */ 
  } /*  vXSpiDevice DeviceId 0  */ 
} /*  HwConfig  */ ;


VXSPI_LOCAL CONST(vXSpi_ProtocolModeType, VXSPI_CONST) vXSpi_ProtocolModes_HwConfig[3] =
{
  {
    VXSPI_DATA_RATE_SDR /*  Command Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Command Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Address Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Address Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Data Data Rate  */ , 
    VXSPI_DATA_WIDTH_OCTAL /*  Data Data Width  */ 
  } /*  vXSpiProtocolMode_Read  */ , 
  {
    VXSPI_DATA_RATE_SDR /*  Command Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Command Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Address Data Rate  */ , 
    VXSPI_DATA_WIDTH_OCTAL /*  Address Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Data Data Rate  */ , 
    VXSPI_DATA_WIDTH_OCTAL /*  Data Data Width  */ 
  } /*  vXSpiProtocolMode_Write  */ , 
  {
    VXSPI_DATA_RATE_SDR /*  Command Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Command Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Address Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Address Data Width  */ , 
    VXSPI_DATA_RATE_SDR /*  Data Data Rate  */ , 
    VXSPI_DATA_WIDTH_SINGLE /*  Data Data Width  */ 
  } /*  vXSpiProtocolMode  */ 
} /*  HwConfig  */ ;


VXSPI_LOCAL CONST(vXSpi_HwUnitType, VXSPI_CONST) vXSpi_HwUnits_HwConfig[1] =
{
  {
    0x50000000u /*  MemoryBaseAddress  */ , 
    0x47040000u /*  RegisterBaseAddress  */ , 
    1u /*  NumberOfDevices  */ , 
    0u /*  HwUnitToDeviceMapStartIndex  */ 
  } /*  vXSpiHwUnit HwUnitId 0  */ 
} /*  HwConfig  */ ;


VXSPI_LOCAL CONST(vXSpi_DeviceIdType, VXSPI_CONST) vXSpi_HwUnitToDeviceMap_HwConfig[1] =
{
  0u /*  DeviceId 0 is mapped to HwUnitId 0  */ 
} /*  HwConfig  */ ;


CONST(vXSpi_HwConfigType, VXSPI_CONST) vXSpi_HwConfig =
{
  vXSpi_ProtocolModes_HwConfig /*  ProtocolModesConfig  */ , 
  vXSpi_HwUnits_HwConfig /*  HwUnitsConfig  */ , 
  vXSpi_Devices_HwConfig /*  DevicesConfig  */ , 
  vXSpi_HwUnitToDeviceMap_HwConfig /*  HwUnitToDeviceMap  */ , 
  1u /*  NumberOfHwUnits  */ , 
  1u /*  NumberOfDevices  */ 
} /*  HwConfig  */ ;


#define VXSPI_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
#define VXSPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(vXSpi_ConfigPtrType, VXSPI_CFG) vXSpi_ConfigPtr;

#define VXSPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*********************************************************************************************************************
 *  END OF FILE: vXSpi_Cfg.c
 *********************************************************************************************************************/

