/***********************************************************************************************************************
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
/*!        \file  vXSpi_Types.h
 *        \brief  vXSpi public types header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#if !defined (VXSPI_TYPES_H)
#define VXSPI_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef uint32 vXSpi_AddressType;
typedef uint32 vXSpi_DataLengthType;
typedef uint16 vXSpi_PageSizeType;
typedef uint8 vXSpi_DataType;
typedef uint8 vXSpi_DeviceIndexType;
typedef uint8 vXSpi_DeviceIdType;
typedef uint8 vXSpi_CommandType;
typedef uint8 vXSpi_BaudrateType;
typedef uint32 vXSpi_HardwareLoopCyclesType;
typedef uint8 vXSpi_ChipSelectIndexType;
typedef uint8 vXSpi_DummyCycleType;
typedef uint8 vXSpi_HwUnitIndexType;
typedef uint8 vXSpi_HwUnitIdType;
typedef uint32 vXSpi_MemorySizeType;
typedef uint8 vXSpi_BitShiftType;

typedef P2VAR(vXSpi_DataType, AUTOMATIC, VXSPI_APPL_VAR) vXSpi_DataPtrType;
typedef P2CONST(vXSpi_DataType, AUTOMATIC, VXSPI_APPL_VAR) vXSpi_ConstDataPtrType;

/*! Width of a register. */
typedef uint32 vXSpi_RegWidthType;

/*! Offset within the register space of the xSPI peripheral. */
typedef uint32 vXSpi_RegOffsetType;

/*! Register access type. */
typedef volatile vXSpi_RegWidthType vXSpi_RegAccessType;

/*! Pointer to a register. */
typedef P2VAR(vXSpi_RegAccessType, AUTOMATIC, MSR_REGSPACE) vXSpi_RegPtrType;
typedef P2CONST(vXSpi_RegAccessType, AUTOMATIC, MSR_REGSPACE) vXSpi_ConstRegPtrType;

typedef enum
{
  VXSPI_TRANSACTION_OK = 0u, /*!< Last transaction finished successfully. */
  VXSPI_TRANSACTION_PENDING, /*!< Transaction is currently pending, i.e. in processing, hardware pending. */
  VXSPI_TRANSACTION_FAILED   /*!< Last transaction failed. */
} vXSpi_TransactionResultType; /*!< Stores all known vXSpi transaction results. */

typedef enum
{
  VXSPI_ADDRESS_FORMAT_1_BYTE = 0u,
  VXSPI_ADDRESS_FORMAT_2_BYTE,
  VXSPI_ADDRESS_FORMAT_3_BYTE,
  VXSPI_ADDRESS_FORMAT_4_BYTE
} vXSpi_AddressFormatType;

typedef enum
{
  VXSPI_DATA_RATE_SDR = 0u, /*!< Single Data Rate */
  VXSPI_DATA_RATE_DDR       /*!< Double Data Rate */
} vXSpi_DataRateType;

typedef enum
{
  VXSPI_DATA_WIDTH_SINGLE = 0u,
  VXSPI_DATA_WIDTH_DUAL,
  VXSPI_DATA_WIDTH_QUAD,
  VXSPI_DATA_WIDTH_OCTAL
} vXSpi_DataWidthType;

typedef enum
{
  VXSPI_DLS_NO_DELAY_SEL,
  VXSPI_DLS_ONE_NEW_SEL_PER_TAP,
  VXSPI_DDLS_ONE_SEN_SEL_PER_TAP,
  VXSPI_DLS_TWO_SEN_SEL_PER_TAP,
  VXSPI_DLS_FOUR_SEN_SEL_PER_TAP
} vXSpi_DelayLineSelectType;

typedef struct
{
  vXSpi_AddressFormatType AddressFormat;  /*!< Enum with the address format (length of the address in bytes). */
  vXSpi_AddressType Address;              /*!< Address to transmit. */
} vXSpi_AddressAndFormatType;
typedef P2CONST(vXSpi_AddressAndFormatType, AUTOMATIC, VXSPI_APPL_VAR) vXSpi_AddressAndFormatPtrType;

typedef struct
{
  vXSpi_DataPtrType DataBuffer;    /*!< Pointer to buffer with data to be received. */
  vXSpi_DataLengthType DataLength; /*!< Length of data in bytes to be received. */
} vXSpi_DataAndLengthType;
typedef P2CONST(vXSpi_DataAndLengthType, AUTOMATIC, VXSPI_APPL_VAR) vXSpi_DataAndLengthPtrType;

typedef struct
{
  vXSpi_ConstDataPtrType DataBuffer; /*!< Pointer to buffer with data to be transmitted. */
  vXSpi_DataLengthType DataLength;   /*!< Length of data in bytes to be transmitted. */
} vXSpi_ConstDataAndLengthType;
typedef P2CONST(vXSpi_ConstDataAndLengthType, AUTOMATIC, VXSPI_APPL_VAR) vXSpi_ConstDataAndLengthPtrType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif  /* VXSPI_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: vXSpi_Types.h
 **********************************************************************************************************************/
