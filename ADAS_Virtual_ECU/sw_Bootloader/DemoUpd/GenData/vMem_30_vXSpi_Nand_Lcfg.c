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
 *            Module: vMem_30_vXSpi_Nand
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_vXSpi_Nand_Lcfg.c
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define VMEM_30_VXSPI_NAND_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_vXSpi_Nand_Cfg.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK tagId>
 *********************************************************************************************************************/
/* defaultContent */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

/* Add hw specific data */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId
  \brief  Mapping between Instance Id and vXSpi Device Id
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceIdType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_InstanceIdTovXSpiDeviceId[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InstanceIdTovXSpiDeviceId      Referable Keys */
  /*     0 */                         0u   /* [/ActiveEcuC/vMem_30_vXSpi_Nand/vMemInstance_ExtFlash[0:vMemvXSpiDeviceRef]] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element              Description
  EraseBurstSize       Burst size for erase jobs, if configured. Otherwise sector size
  SectorSize           Size of this sector in bytes.
  NrOfSectors          Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  PageSize             Size of one page of this sector in bytes.
  WriteBurstSize       Burst size for write jobs, if configured. Otherwise page size
  ReplacementSector    Specifies whether the MemSector consists of replacement sectors.
  RamAlignment         In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
  StartAddress         Physical start address of the first sector.
  vMemDieIdx           the index of the 1:1 relation pointing to vMem_30_vXSpi_Nand_vMemDie
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_MemSectorType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_MemSector[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseBurstSize  SectorSize  NrOfSectors  PageSize  WriteBurstSize  ReplacementSector  RamAlignment  StartAddress  vMemDieIdx        Referable Keys */
  { /*     0 */        262144u,    262144u,        512u,    4096u,          4096u,             FALSE,           1u,        0x00u,         0u }   /* [/ActiveEcuC/vMem_30_vXSpi_Nand/vMemInstance_ExtFlash] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemDeviceConfig
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemDeviceConfig
  \details
  Element                                          Description
  InputOutputModeRegisterExisting                  Is input output mode register existing
  EraseValue                                       Erase value.
  InputOutputModeRegisterAddress                   Address of input output mode register
  InputOutputModeRegisterValue                     Value of input output mode register
  LutAddressLength                                 Length of one address within the Lookup table
  LutDataBufferLength                              Length of Lookup table data buffer
  LutEntryLength                                   Length of one Lookup table entry
  LutMaxEntries                                    Maximal number of Lookup table entries
  StatusRegister1Address                           Address of status register 1
  StatusRegister2Address                           Address of status register 2
  StatusRegister3Address                           Address of status register 3
  StatusRegisterBufferReadModeBitMask              Status register buffer read mode bitmask.
  StatusRegisterBusyFlagBitMask                    Status register busy flag bitmask.
  StatusRegisterDataBufferLength                   Length of status register data buffer
  StatusRegisterEcc0BitMask                        Status register ECC0 bitmask.
  StatusRegisterEcc1BitMask                        Status register ECC1 bitmask.
  StatusRegisterEraseErrorBitMask                  Status register erase error bitmask.
  StatusRegisterLutFBitMask                        Status register Lookup table full bitmask.
  StatusRegisterProgramErrorBitMask                Status register program error bitmask.
  StatusRegisterProtectionBitMask                  Status register Protection bitmask.
  VolatileConfigurationRegisterDataBufferLength    Length of volatile configuration register data buffer
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemDeviceConfigType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDeviceConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InputOutputModeRegisterExisting  EraseValue  InputOutputModeRegisterAddress  InputOutputModeRegisterValue  LutAddressLength  LutDataBufferLength  LutEntryLength  LutMaxEntries  StatusRegister1Address  StatusRegister2Address  StatusRegister3Address  StatusRegisterBufferReadModeBitMask  StatusRegisterBusyFlagBitMask  StatusRegisterDataBufferLength  StatusRegisterEcc0BitMask  StatusRegisterEcc1BitMask  StatusRegisterEraseErrorBitMask  StatusRegisterLutFBitMask  StatusRegisterProgramErrorBitMask  StatusRegisterProtectionBitMask  VolatileConfigurationRegisterDataBufferLength        Referable Keys */
  { /*     0 */                            TRUE,      0xFFu,                          0x00u,                        0xDFu,            0x02u,               0x28u,          0x04u,         0x0Au,                  0xA0u,                  0xB0u,                  0xC0u,                               0x08u,                         0x01u,                          0x01u,                     0x10u,                     0x20u,                           0x04u,                     0x40u,                             0x08u,                           0xFFu,                                         0x01u }   /* [/ActiveEcuC/vMem_30_vXSpi_Nand/Winbond_W35N01JW_01] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemDie
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemDie
  \brief  Configuration description of a flash memory die.
  \details
  Element            Description
  DieSize            Size of the die.
  DieStartAddress    Memory start address of the die.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemDieType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemDie[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DieSize     DieStartAddress        Referable Keys */
  { /*     0 */ 134217728u,              0u }   /* [/ActiveEcuC/vMem_30_vXSpi_Nand/Winbond_W35N01JW_01/vMemDieList/Die0, /ActiveEcuC/vMem_30_vXSpi_Nand/vMemInstance_ExtFlash] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdAddressFormatValue[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseCmd                                  PageDataReadCmd                           ProgramDataLoadCmd                        ProgramExecuteCmd                         ReadBbmLutCmd                             ReadCmd                                   ReadStatusRegisterCmd                     ReadVolatileConfigurationRegisterCmd      ReplaceLogicalBlocksCmd                   SoftwareDieSelectCmd                      WriteEnableCmd                            WriteStatusRegisterCmd                    WriteVolatileConfigurationRegisterCmd           Comment                                                Referable Keys */
  { /*     0 */ VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_2_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_1_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_2_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_1_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_3_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_0_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_1_BYTE, VMEM_30_VXSPI_NAND_ADDRESS_FORMAT_3_BYTE }   /* [Contains device-specific flash commands.] */  /* [/ActiveEcuC/vMem_30_vXSpi_Nand/Winbond_W35N01JW_01] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdDummyCycleValue[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseCmd  PageDataReadCmd  ProgramDataLoadCmd  ProgramExecuteCmd  ReadBbmLutCmd  ReadCmd  ReadStatusRegisterCmd  ReadVolatileConfigurationRegisterCmd  ReplaceLogicalBlocksCmd  SoftwareDieSelectCmd  WriteEnableCmd  WriteStatusRegisterCmd  WriteVolatileConfigurationRegisterCmd        Comment                                                Referable Keys */
  { /*     0 */       0u,              0u,                 0u,                0u,            0u,      8u,                    0u,                                   8u,                      0u,                   0u,             0u,                     0u,                                    0u }   /* [Contains device-specific flash commands.] */  /* [/ActiveEcuC/vMem_30_vXSpi_Nand/Winbond_W35N01JW_01] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemFlsCmdValue
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemFlsCmdValue
  \details
  Element                                  Description
  EraseCmd                                 Erase command.
  PageDataReadCmd                          Page data read command.
  ProgramDataLoadCmd                       Program data load command.
  ProgramExecuteCmd                        Program execute command.
  ReadBbmLutCmd                            Read BBM LUT command.
  ReadCmd                                  Read command.
  ReadStatusRegisterCmd                    Read status register command.
  ReadVolatileConfigurationRegisterCmd     Read volatile configuration register command.
  ReplaceLogicalBlocksCmd                  Replace logical sector command.
  SoftwareDieSelectCmd                     Software die select command.
  WriteEnableCmd                           Write enable command.
  WriteStatusRegisterCmd                   Write status register command.
  WriteVolatileConfigurationRegisterCmd    Write volatile configuration register command.
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemFlsCmdValueType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemFlsCmdValue[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EraseCmd  PageDataReadCmd  ProgramDataLoadCmd  ProgramExecuteCmd  ReadBbmLutCmd  ReadCmd  ReadStatusRegisterCmd  ReadVolatileConfigurationRegisterCmd  ReplaceLogicalBlocksCmd  SoftwareDieSelectCmd  WriteEnableCmd  WriteStatusRegisterCmd  WriteVolatileConfigurationRegisterCmd        Comment                                                Referable Keys */
  { /*     0 */    0xD8u,           0x13u,              0xC4u,             0x10u,         0xA5u,   0x8Bu,                 0x05u,                                0x85u,                   0xA1u,                0x00u,          0x06u,                  0x01u,                                 0x81u }   /* [Contains device-specific flash commands.] */  /* [/ActiveEcuC/vMem_30_vXSpi_Nand/Winbond_W35N01JW_01] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element                                     Description
  BlankCheckBufferArrayOne2SortedNEndIdx      the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BlankCheckBufferArrayOne2SortedNLength      the number of relations pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BlankCheckBufferArrayOne2SortedNStartIdx    the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_BlankCheckBufferArray
  BusyCheckTimeoutThreshold                   Specifies the maximum number of busy checks before the active job fails.
  SoftwareDieSelectCommandUsed                Specifies if software die select command is used.
  Id                                          Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx                             the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector
  MemSectorLength                             the number of relations pointing to vMem_30_vXSpi_Nand_MemSector
  MemSectorStartIdx                           the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_MemSector
  vMemDieEndIdx                               the end index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie
  vMemDieLength                               the number of relations pointing to vMem_30_vXSpi_Nand_vMemDie
  vMemDieStartIdx                             the start index of the 1:n relation pointing to vMem_30_vXSpi_Nand_vMemDie
  GenericProtocolModeId                       Specifies the protocol mode used for all commands except reading and writing data
  ReadDataProtocolModeId                      Specifies the protocol mode used reading data
  WriteDataProtocolModeId                     Specifies the protocol mode used writing data
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMem_30_vXSpi_Nand_vMemInstanceType, VMEM_30_VXSPI_NAND_CONST) vMem_30_vXSpi_Nand_vMemInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BlankCheckBufferArrayOne2SortedNEndIdx  BlankCheckBufferArrayOne2SortedNLength  BlankCheckBufferArrayOne2SortedNStartIdx  BusyCheckTimeoutThreshold  SoftwareDieSelectCommandUsed  Id  MemSectorEndIdx  MemSectorLength  MemSectorStartIdx  vMemDieEndIdx  vMemDieLength  vMemDieStartIdx  GenericProtocolModeId    ReadDataProtocolModeId        WriteDataProtocolModeId              Referable Keys */
  { /*     0 */                                  4096u,                                  4096u,                                       0u,                     2000u,                        FALSE, 0u,              1u,              1u,                0u,            1u,            1u,              0u, VXSPI_vXSpiProtocolMode, VXSPI_vXSpiProtocolMode_Read, VXSPI_vXSpiProtocolMode_Write }   /* [/ActiveEcuC/vMem_30_vXSpi_Nand/vMemInstance_ExtFlash] */
};
#define VMEM_30_VXSPI_NAND_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_vXSpi_Nand_BlankCheckBufferArray
**********************************************************************************************************************/
/** 
  \var    vMem_30_vXSpi_Nand_BlankCheckBufferArray
  \brief  BlankCheckBufferArray
*/ 
#define VMEM_30_VXSPI_NAND_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(vMem_30_vXSpi_Nand_BlankCheckBufferArrayUType, VMEM_30_VXSPI_NAND_VAR_NOINIT) vMem_30_vXSpi_Nand_BlankCheckBufferArray;  /* PRQA S 0759, 1514, 1533, 0612 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [vMemInstance_ExtFlash] */
  /*   ... */  /* [vMemInstance_ExtFlash] */
  /*  4095 */  /* [vMemInstance_ExtFlash] */

#define VMEM_30_VXSPI_NAND_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


