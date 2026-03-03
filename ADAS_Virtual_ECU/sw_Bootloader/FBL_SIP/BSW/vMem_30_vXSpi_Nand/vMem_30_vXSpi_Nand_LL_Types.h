/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_vXSpi_Nand_LL_Types.h
 *        \brief  vMem_30_vXSpi_Nand_LL types header file
 *
 *      \details  Defines vMem_30_vXSpi_Nand_LL types and symbols used in the low level implementation of the vMem driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_VXSPI_NAND_LL_TYPES_H)
# define VMEM_30_VXSPI_NAND_LL_TYPES_H

# include "Std_Types.h"
# include "vMem_30_vXSpi_Nand_Types.h"
# include "vMem_30_vXSpi_Nand_Cfg.h"
# include "vMem_30_vXSpi_Nand_Extended_Func.h"
# include "vXSpi.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define VMEM_30_VXSPI_NAND_PAGE_ADDRESS_LENGTH (6u)

/*! Bit masks. */
# define VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_1_BITMASK (0x8000u)
# define VMEM_30_VXSPI_NAND_LUT_STATUS_FLAG_2_BITMASK (0x4000u)
# define VMEM_30_VXSPI_NAND_LUT_STATUS_BITMASK (0x3FFFu)
# define VMEM_30_VXSPI_NAND_COLUMN_ADDRESS_BITMASK(coulmnAddresLength) (((uint32)1u << (coulmnAddresLength)) - 1u)
# define VMEM_30_VXSPI_NAND_SECTOR_ADDRESS_BITMASK (0xFFC0u)


#define VMEM_30_VXSPI_NAND_BYTE_MASK                               0xFFu
#define VMEM_30_VXSPI_NAND_BITS_PER_BYTE                              8u
#define VMEM_30_VXSPI_NAND_1_BYTE_SHIFT                               8u
#define VMEM_30_VXSPI_NAND_2_BYTE_SHIFT                              16u
#define VMEM_30_VXSPI_NAND_3_BYTE_SHIFT                              24u
#define VMEM_30_VXSPI_NAND_4_BYTE_SHIFT                              32u

/*! Predefines the maximum amount of flash command items for a flash command sequence. */
# define vMem_30_vXSpi_Nand_LL_MaximumChannels 4u

/* ----- Error codes ----- */
# define VMEM_30_VXSPI_NAND_RUNTIME_E_INITIALIZATION_FAILED       (0x20u)    /*!< used to check if no error occurred - use a value unequal to any error code. */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef vXSpi_DeviceIdType vMem_30_vXSpi_Nand_vXSpiDeviceIdType;
typedef vXSpi_CommandType vMem_30_vXSpi_Nand_vXSpiCommandType;
typedef vXSpi_AddressFormatType vMem_30_vXSpi_Nand_vXSpiAddressFormatType;
typedef vXSpi_AddressType vMem_30_vXSpi_Nand_vXSpiAddressType;
typedef vXSpi_DummyCycleType vMem_30_vXSpi_Nand_vXSpiDummyCycleType;
typedef vXSpi_TransactionResultType vMem_30_vXSpi_Nand_vXSpi_TransactionResultType;
typedef vXSpi_DataType vMem_30_vXSpi_Nand_vXSpiDataType;
typedef vXSpi_DataLengthType vMem_30_vXSpi_Nand_vXSpiDataLengthType;
typedef vXSpi_DataPtrType vMem_30_vXSpi_Nand_vXSpiDataPtrType;
typedef vXSpi_ConstDataPtrType vMem_30_vXSpi_Nand_ConstvXSpiDataPtrType;

typedef P2VAR(vMem_30_vXSpi_Nand_AddressType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) vMem_30_vXSpi_Nand_AddressPtrType;

typedef uint16 vMem_30_vXSpi_Nand_FlsAddressType;
typedef P2VAR(vMem_30_vXSpi_Nand_FlsAddressType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) vMem_30_vXSpi_Nand_FlsAddressPtrType;

typedef uint8 vMem_30_vXSpi_Nand_DieIndexType;

/*! Represents a converted address. */
typedef struct
{
  vMem_30_vXSpi_Nand_FlsAddressType PageAddress;
  vMem_30_vXSpi_Nand_FlsAddressType ColumnAddress;
  vMem_30_vXSpi_Nand_FlsAddressType SectorStartAddress;
} vMem_30_vXSpi_Nand_ConvertedAddressType;
typedef P2VAR(vMem_30_vXSpi_Nand_ConvertedAddressType, AUTOMATIC, VMEM_30_VXSPI_NAND_APPL_VAR) vMem_30_vXSpi_Nand_ConvertedAddressPtrType;

/*! This enum defines the possible ECC Error outcomes. */
typedef enum
{
  VMEM_30_VXSPI_NAND_NO_ECC_ERROR = 0,
  VMEM_30_VXSPI_NAND_CORRECTED_ECC_ERROR,
  VMEM_30_VXSPI_NAND_UNCORRECTABLE_ECC_ERROR
} vMem_30_vXSpi_Nand_LL_EccErrorType;

/*! Job parameters for backup purposes. */
typedef struct
{
  vMem_30_vXSpi_Nand_AddressType Address;
  vMem_30_vXSpi_Nand_ConstDataPtrType SourceAddressPtr;
  vMem_30_vXSpi_Nand_DataPtrType TargetAddressPtr;
  vMem_30_vXSpi_Nand_LengthType Length;
  vMem_30_vXSpi_Nand_AccessType AccessType;
  vMem_30_vXSpi_Nand_JobErrorType ErrorType;
  vMem_30_vXSpi_Nand_ReplaceSectorPtrType ReplaceSectorInfo;
  vMem_30_vXSpi_Nand_RecoverDataPtrType RecoverDataInfo;
} vMem_30_vXSpi_Nand_JobParamBackupType;
typedef P2VAR(vMem_30_vXSpi_Nand_JobParamBackupType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_JobParamBackupPtrType;
typedef P2CONST(vMem_30_vXSpi_Nand_JobParamBackupType, AUTOMATIC, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_ConstJobParamBackupPtrType;

/*! Automated Bad Block Info. */
typedef struct
{
  vMem_30_vXSpi_Nand_ReplaceSectorType ReplaceSectorInfo;
} vMem_30_vXSpi_Nand_AutomatedBadBlockInfoType;
typedef P2VAR(vMem_30_vXSpi_Nand_AutomatedBadBlockInfoType, AUTOMATIC, VMEM_30_VXSPI_NAND_VAR) vMem_30_vXSpi_Nand_AutomatedBadBlockInfoPtrType;

/*! Defines the possible transmission direction for a flash command item. */
typedef enum
{
  VMEM_30_VXSPI_NAND_CMD_SEND,
  VMEM_30_VXSPI_NAND_CMD_RECEIVE
} vMem_30_vXSpi_Nand_FlsCmdTransDirectionType;

/*! Defines the possible result values of a sequence. */
typedef enum
{
  VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_OK,
  VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_PENDING,
  VMEM_30_VXSPI_NAND_SEQUENCE_RESULT_FAILED
} vMem_30_vXSpi_Nand_FlsCmdSequenceResultType;


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/*! Holds the die index of the currently active die for every vMemInstance. */
extern vMem_30_vXSpi_Nand_DieIndexType vMem_30_vXSpi_Nand_ActiveDie[vMem_30_vXSpi_Nand_GetSizeOfvMemInstance()];


#endif /* VMEM_30_VXSPI_NAND_LL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_vXSpi_Nand_LL_Types.h
 *********************************************************************************************************************/
