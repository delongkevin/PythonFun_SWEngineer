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
 *            Module: WrapNv
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101146_D09
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WrapNv_Cfg.h
 *   Generation Time: 2023-10-09 10:56:17
 *           Project: DemoUpdater - Version 1.0
 *          Delivery: CBD2101146_D09
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (WRAPNV_CFG_H)
# define WRAPNV_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "MemIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*******************************************************************************************
 *                                    NvMBlock              Offset              DESCRIPTION
 *   
 *   Memory Layout
 *   |
 *   +-- NvMConfigBlock               NvMConfigBlock        0x00000000          NvMConfigBlock
 *   |
 *   +-- ApplUpdate                   NvMBlockDescriptor_ApplUpdate 0x00000000  Application update flag
 *   |
 *   +-- ProgReqFlag                  SWC_SysMgrSysM_ProgReqFlag 0x00000000     Programming request flag
 *   |
 *   +-- SecAccessDelayFlag           NvMBlockDescriptor_SecAccessDelayFlag 0x00000000 Security Access Delay flag
 *   |
 *   +-- SecAccessInvalidCount        NvMBlockDescriptor_SecAccessInvalidCount 0x00000000 Security Access Invalid count
 *   |
 *   +-- ApplValidity                 NvMBlockDescriptor_ApplValidity 0x00000000 Application validity flag
 *   |
 *   +-- DcmDslRxTesterSourceAddr     NvMBlockDescriptor_DcmDslRxTesterSourceAddr 0x00000000 Connection for reset response
 *   |
 *   +-- ValidityFlags                NvMBlockDescriptor_ValidityFlags 0x00000000 Logical block validity flagss
 *   |
 *   +-- ExhaustRegulationTan         NvMBlockDescriptor_ExhaustRegulationTan 0x00000000 DID F196 - Exhaust Regulation or Type Approval Number
 *   |
 *   +-- ResetResponseFlag            NvMBlockDescriptor_ResetResponseFlag 0x00000000 Reset response flag
 *   |
 *   +-- DID_F180_Boot_SW_Ver_Info    SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info 0x00000000 DID_F180_Boot_SW_Ver_Info
 *   |
 *   +-- ProgrammingStatus            NvMBlockDescriptor_DID_2010_ProgrammingStatus 0x00000000 Programming Status Informationn
 *   |
 *   +-- 10 x Metadata                                                          Metadata information for each logical block
 *   |   |
 *   |   +-- Fingerprint              NvMBlockDescriptor_MetaData 0x00000000    Download fingerprint
 *   |   |
 *   |   +-- ProgCounter              NvMBlockDescriptor_MetaData 0x0000000D    Successful reprogramming attempts
 *   |   |
 *   |   +-- ProgAttempts             NvMBlockDescriptor_MetaData 0x0000000F    Reprogramming attempts
 *   |   |
 *   |   +-- CRCValue                 NvMBlockDescriptor_MetaData 0x00000011    CRC total of logical block
 *   |   |
 *   |   +-- CRCStart                 NvMBlockDescriptor_MetaData 0x00000012    Start address of CRC total
 *   |   |
 *   |   +-- CRCLength                NvMBlockDescriptor_MetaData 0x00000013    Length of CRC total
 *   |   |
 *   |   +-- SoftwareIdentification   NvMBlockDescriptor_MetaData 0x00000014    DID F181 or F182 - Application Software- or Application Data Identification
 *   |   |
 *   |   +-- SwEbomPartNumber         NvMBlockDescriptor_MetaData 0x00000021    DID F122 - S/W EBOM Part Number
 *   |   |
 *   |   +-- MemoryStatus             NvMBlockDescriptor_MetaData 0x0000002B    Memory status; erased, programmeds
 *   |   |
 *   |   +-- SegmentCount             NvMBlockDescriptor_MetaData 0x0000002C    Number of entries in segment list
 *   |   |
 *   |   +-- SegmentAddrList          NvMBlockDescriptor_MetaData 0x0000002D    List of segment start addresses
 *   |   |
 *   |   +-- SegmentLengthList        NvMBlockDescriptor_MetaData 0x00000055    List of segment lengths
 *   |   |
 *   |   +-- FlashStatus              NvMBlockDescriptor_MetaData 0x0000007D    Flash Status
 *   |
 *   +-- VehicleManufEcuSwNumber      SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num 0x00000000 DID F188 - Vehicle Manufacturer ECU Software Number
 *   |
 *   +-- EbomAssemblyPartNumber       SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum 0x00000000 EbomAssemblyPartNumber
 *   |
 *   +-- DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num 0x00000000 DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num
 *   |
 *   +-- DID_F18B_FCA_ESLM_ECU_SW_App_Num SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num 0x00000000 DID_F18B_FCA_ESLM_ECU_SW_App_Num
 *   |
 *   +-- CoDePEcuPartNumber           SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum 0x00000000 DID F187 - CoDeP ECU Part Number
 *   |
 *   +-- CodepAssemblyPartNumber      SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum 0x00000000 CodepAssemblyPartNumber
 *   |
 *   +-- EbomEcuPartNumber            SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum 0x00000000 DID F132 - EBOM ECU Part Number
 *   |
 *   +-- DID_F194_Supplier_Ecu_SW_PartNum SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum 0x00000000 DID_F194_Supplier_Ecu_SW_PartNum
 *   |
 *   +-- DID_F195_Supplier_Ecu_SW_VerNum SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum 0x00000000 DID_F195_Supplier_Ecu_SW_VerNum
 *   |
 *   +-- DiagnosticVersion            SWC_PartNumMgrDID_F110_Ecu_Diag_Info 0x00000000 Diagnostic Version of DID F110h
 *   |
 *   +-- DID_2002_OdoFlashing         SWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock 0x00000000 DID_2002_OdoFlashing
 *   |
 *   +-- 9 x fileHeader                                                         fileHeader information for each logical block
 *   |   |
 *   |   +-- FileHeaderInfo           NvMBlockDescriptor_FileHeader 0x00000000  TargetName field is a PrintableString that will equal the identifier for the intended ECU
 *   |   |
 *   |   +-- Uuid                     NvMBlockDescriptor_FileHeader 0x000000A0  The Uuid field represents a unique identifier of the signed block.
 *   |
 *   +-- 10 x CertAccessInfo                                                    FBL ADA  certificate serialNumber
 *       |
 *       +-- IssuerNme                NvMBlockDescriptor_CertAccessInfo 0x00000000 FBL ADA  certificate issuer name
 *       |
 *       +-- SerialNumber             NvMBlockDescriptor_CertAccessInfo 0x00000019 FBL ADA  certificate serialNumber
 ******************************************************************************************/

/** General defines *********************************************************** */
#define WRAPNV_USECASE_NVM
#define WRAPNV_MAINFUNCTION_POLLING          STD_ON
#define WRAPNV_DEV_ERROR_REPORT              STD_ON

/** ID defines **************************************************************** */
/** NvMConfigBlock */
#define WRAPNV_DATASET_NVMCONFIGBLOCK        0x01u
#define WRAPNV_RECORD_ID_NVMCONFIGBLOCK      0x00u

/** ApplUpdate */
#define WRAPNV_DATASET_APPLUPDATE            0x01u
#define WRAPNV_RECORD_ID_APPLUPDATE          0x01u

/** ProgReqFlag */
#define WRAPNV_DATASET_PROGREQFLAG           0x01u
#define WRAPNV_RECORD_ID_PROGREQFLAG         0x02u

/** SecAccessDelayFlag */
#define WRAPNV_DATASET_SECACCESSDELAYFLAG    0x01u
#define WRAPNV_RECORD_ID_SECACCESSDELAYFLAG  0x03u

/** SecAccessInvalidCount */
#define WRAPNV_DATASET_SECACCESSINVALIDCOUNT 0x01u
#define WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT 0x04u

/** ApplValidity */
#define WRAPNV_DATASET_APPLVALIDITY          0x01u
#define WRAPNV_RECORD_ID_APPLVALIDITY        0x05u

/** DcmDslRxTesterSourceAddr */
#define WRAPNV_DATASET_DCMDSLRXTESTERSOURCEADDR 0x01u
#define WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR 0x06u

/** ValidityFlags */
#define WRAPNV_DATASET_VALIDITYFLAGS         0x01u
#define WRAPNV_RECORD_ID_VALIDITYFLAGS       0x07u

/** ExhaustRegulationTan */
#define WRAPNV_DATASET_EXHAUSTREGULATIONTAN  0x01u
#define WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN 0x08u

/** ResetResponseFlag */
#define WRAPNV_DATASET_RESETRESPONSEFLAG     0x01u
#define WRAPNV_RECORD_ID_RESETRESPONSEFLAG   0x09u

/** DID_F180_Boot_SW_Ver_Info */
#define WRAPNV_DATASET_DID_F180_BOOT_SW_VER_INFO 0x01u
#define WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO 0x0Au

/** ProgrammingStatus */
#define WRAPNV_DATASET_PROGRAMMINGSTATUS     0x01u
#define WRAPNV_RECORD_ID_PROGRAMMINGSTATUS   0x0Bu

/** Metadata */
#define WRAPNV_DATASET_METADATA              0x0Au
#define WRAPNV_RECORD_ID_FINGERPRINT         0x0Cu
#define WRAPNV_RECORD_ID_PROGCOUNTER         0x0Du
#define WRAPNV_RECORD_ID_PROGATTEMPTS        0x0Eu
#define WRAPNV_RECORD_ID_CRCVALUE            0x0Fu
#define WRAPNV_RECORD_ID_CRCSTART            0x10u
#define WRAPNV_RECORD_ID_CRCLENGTH           0x11u
#define WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION 0x12u
#define WRAPNV_RECORD_ID_SWEBOMPARTNUMBER    0x13u
#define WRAPNV_RECORD_ID_MEMORYSTATUS        0x14u
#define WRAPNV_RECORD_ID_SEGMENTCOUNT        0x15u
#define WRAPNV_RECORD_ID_SEGMENTADDRLIST     0x16u
#define WRAPNV_RECORD_ID_SEGMENTLENGTHLIST   0x17u
#define WRAPNV_RECORD_ID_FLASHSTATUS         0x18u

/** VehicleManufEcuSwNumber */
#define WRAPNV_DATASET_VEHICLEMANUFECUSWNUMBER 0x01u
#define WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER 0x19u

/** EbomAssemblyPartNumber */
#define WRAPNV_DATASET_EBOMASSEMBLYPARTNUMBER 0x01u
#define WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER 0x1Au

/** DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */
#define WRAPNV_DATASET_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM 0x01u
#define WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM 0x1Bu

/** DID_F18B_FCA_ESLM_ECU_SW_App_Num */
#define WRAPNV_DATASET_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM 0x01u
#define WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM 0x1Cu

/** CoDePEcuPartNumber */
#define WRAPNV_DATASET_CODEPECUPARTNUMBER    0x01u
#define WRAPNV_RECORD_ID_CODEPECUPARTNUMBER  0x1Du

/** CodepAssemblyPartNumber */
#define WRAPNV_DATASET_CODEPASSEMBLYPARTNUMBER 0x01u
#define WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER 0x1Eu

/** EbomEcuPartNumber */
#define WRAPNV_DATASET_EBOMECUPARTNUMBER     0x01u
#define WRAPNV_RECORD_ID_EBOMECUPARTNUMBER   0x1Fu

/** DID_F194_Supplier_Ecu_SW_PartNum */
#define WRAPNV_DATASET_DID_F194_SUPPLIER_ECU_SW_PARTNUM 0x01u
#define WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM 0x20u

/** DID_F195_Supplier_Ecu_SW_VerNum */
#define WRAPNV_DATASET_DID_F195_SUPPLIER_ECU_SW_VERNUM 0x01u
#define WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM 0x21u

/** DiagnosticVersion */
#define WRAPNV_DATASET_DIAGNOSTICVERSION     0x01u
#define WRAPNV_RECORD_ID_DIAGNOSTICVERSION   0x22u

/** DID_2002_OdoFlashing */
#define WRAPNV_DATASET_DID_2002_ODOFLASHING  0x01u
#define WRAPNV_RECORD_ID_DID_2002_ODOFLASHING 0x23u

/** fileHeader */
#define WRAPNV_DATASET_FILEHEADER            0x09u
#define WRAPNV_RECORD_ID_FILEHEADERINFO      0x24u
#define WRAPNV_RECORD_ID_UUID                0x25u

/** CertAccessInfo */
#define WRAPNV_DATASET_CERTACCESSINFO        0x0Au
#define WRAPNV_RECORD_ID_ISSUERNME           0x26u
#define WRAPNV_RECORD_ID_SERIALNUMBER        0x27u

/** Maximum ID of a DataElement */
#define WRAPNV_RECORD_ID_MAX                 0x27u

/** Maximum NvM Block size */
#define WRAPNV_MAX_BLOCK_LENGTH              0xB0u

/** Size defines ************************************************************** */
#define kEepSizeNvMConfigBlock               0x02u
#define kEepSizeApplUpdate                   0x01u
#define kEepSizeProgReqFlag                  0x01u
#define kEepSizeSecAccessDelayFlag           0x01u
#define kEepSizeSecAccessInvalidCount        0x01u
#define kEepSizeApplValidity                 0x01u
#define kEepSizeDcmDslRxTesterSourceAddr     0x02u
#define kEepSizeValidityFlags                0x02u
#define kEepSizeExhaustRegulationTan         0x06u
#define kEepSizeResetResponseFlag            0x01u
#define kEepSizeDID_F180_Boot_SW_Ver_Info    0x0Du
#define kEepSizeProgrammingStatus            0x02u
#define kEepSizeFingerprint                  0x0Du
#define kEepSizeProgCounter                  0x02u
#define kEepSizeProgAttempts                 0x02u
#define kEepSizeCRCValue                     0x01u
#define kEepSizeCRCStart                     0x01u
#define kEepSizeCRCLength                    0x01u
#define kEepSizeSoftwareIdentification       0x0Du
#define kEepSizeSwEbomPartNumber             0x0Au
#define kEepSizeMemoryStatus                 0x01u
#define kEepSizeSegmentCount                 0x01u
#define kEepSizeSegmentAddrList              0x28u
#define kEepSizeSegmentLengthList            0x28u
#define kEepSizeFlashStatus                  0x01u
#define kEepSizeVehicleManufEcuSwNumber      0x0Bu
#define kEepSizeEbomAssemblyPartNumber       0x0Au
#define kEepSizeDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num 0x0Au
#define kEepSizeDID_F18B_FCA_ESLM_ECU_SW_App_Num 0x0Au
#define kEepSizeCoDePEcuPartNumber           0x0Bu
#define kEepSizeCodepAssemblyPartNumber      0x0Bu
#define kEepSizeEbomEcuPartNumber            0x0Au
#define kEepSizeDID_F194_Supplier_Ecu_SW_PartNum 0x0Bu
#define kEepSizeDID_F195_Supplier_Ecu_SW_VerNum 0x02u
#define kEepSizeDiagnosticVersion            0x06u
#define kEepSizeDID_2002_OdoFlashing         0x02u
#define kEepSizeFileHeaderInfo               0xA0u
#define kEepSizeUuid                         0x10u
#define kEepSizeIssuerNme                    0x19u
#define kEepSizeSerialNumber                 0x14u

#define kWrapNvNrOfBlock                     0x1Au
#define kWrapNvNrOfRecord                    0x28u

/** Access macros ************************************************************* */

/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */

#define ApplFblNvReadNvMConfigBlock(buf)     WrapNv_ReadSync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf))
#define ApplFblNvReadPartialNvMConfigBlock(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf), (offset), (length))
#define ApplFblNvWriteNvMConfigBlock(buf)    WrapNv_WriteSync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf))
#define ApplFblNvReadAsyncNvMConfigBlock(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncNvMConfigBlock(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncNvMConfigBlock(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_NVMCONFIGBLOCK, 0u, (buf), (op))

#define ApplFblNvReadApplUpdate(buf)         WrapNv_ReadSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf))
#define ApplFblNvReadPartialApplUpdate(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf), (offset), (length))
#define ApplFblNvWriteApplUpdate(buf)        WrapNv_WriteSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf))
#define ApplFblNvReadAsyncApplUpdate(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncApplUpdate(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncApplUpdate(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf), (op))

#define ApplFblNvReadProgReqFlag(buf)        WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf))
#define ApplFblNvReadPartialProgReqFlag(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf), (offset), (length))
#define ApplFblNvWriteProgReqFlag(buf)       WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf))
#define ApplFblNvReadAsyncProgReqFlag(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncProgReqFlag(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncProgReqFlag(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf), (op))

#define ApplFblNvReadSecAccessDelayFlag(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))
#define ApplFblNvReadPartialSecAccessDelayFlag(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (offset), (length))
#define ApplFblNvWriteSecAccessDelayFlag(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))
#define ApplFblNvReadAsyncSecAccessDelayFlag(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncSecAccessDelayFlag(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSecAccessDelayFlag(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (op))

#define ApplFblNvReadSecAccessInvalidCount(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf))
#define ApplFblNvReadPartialSecAccessInvalidCount(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf), (offset), (length))
#define ApplFblNvWriteSecAccessInvalidCount(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf))
#define ApplFblNvReadAsyncSecAccessInvalidCount(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncSecAccessInvalidCount(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSecAccessInvalidCount(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf), (op))

#define ApplFblNvReadApplValidity(buf)       WrapNv_ReadSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf))
#define ApplFblNvReadPartialApplValidity(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf), (offset), (length))
#define ApplFblNvWriteApplValidity(buf)      WrapNv_WriteSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf))
#define ApplFblNvReadAsyncApplValidity(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncApplValidity(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncApplValidity(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf), (op))

#define ApplFblNvReadDcmDslRxTesterSourceAddr(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf))
#define ApplFblNvReadPartialDcmDslRxTesterSourceAddr(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDcmDslRxTesterSourceAddr(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf))
#define ApplFblNvReadAsyncDcmDslRxTesterSourceAddr(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDcmDslRxTesterSourceAddr(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDcmDslRxTesterSourceAddr(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf), (op))

#define ApplFblNvReadValidityFlags(buf)      WrapNv_ReadSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf))
#define ApplFblNvReadPartialValidityFlags(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf), (offset), (length))
#define ApplFblNvWriteValidityFlags(buf)     WrapNv_WriteSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf))
#define ApplFblNvReadAsyncValidityFlags(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncValidityFlags(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncValidityFlags(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf), (op))

#define ApplFblNvReadExhaustRegulationTan(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf))
#define ApplFblNvReadPartialExhaustRegulationTan(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf), (offset), (length))
#define ApplFblNvWriteExhaustRegulationTan(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf))
#define ApplFblNvReadAsyncExhaustRegulationTan(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncExhaustRegulationTan(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncExhaustRegulationTan(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf), (op))

#define ApplFblNvReadResetResponseFlag(buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf))
#define ApplFblNvReadPartialResetResponseFlag(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf), (offset), (length))
#define ApplFblNvWriteResetResponseFlag(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf))
#define ApplFblNvReadAsyncResetResponseFlag(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncResetResponseFlag(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncResetResponseFlag(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf), (op))

#define ApplFblNvReadDID_F180_Boot_SW_Ver_Info(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf))
#define ApplFblNvReadPartialDID_F180_Boot_SW_Ver_Info(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_F180_Boot_SW_Ver_Info(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf))
#define ApplFblNvReadAsyncDID_F180_Boot_SW_Ver_Info(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_F180_Boot_SW_Ver_Info(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_F180_Boot_SW_Ver_Info(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_F180_BOOT_SW_VER_INFO, 0u, (buf), (op))

#define ApplFblNvReadProgrammingStatus(buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf))
#define ApplFblNvReadPartialProgrammingStatus(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf), (offset), (length))
#define ApplFblNvWriteProgrammingStatus(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf))
#define ApplFblNvReadAsyncProgrammingStatus(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncProgrammingStatus(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncProgrammingStatus(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf), (op))

#define ApplFblNvReadFingerprint(idx, buf)   WrapNv_ReadSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf))
#define ApplFblNvReadPartialFingerprint(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteFingerprint(idx, buf)  WrapNv_WriteSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncFingerprint(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncFingerprint(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncFingerprint(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (op))

#define ApplFblNvReadProgCounter(idx, buf)   WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf))
#define ApplFblNvReadPartialProgCounter(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteProgCounter(idx, buf)  WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncProgCounter(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncProgCounter(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncProgCounter(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGCOUNTER, (uint16)(idx), (buf), (op))

#define ApplFblNvReadProgAttempts(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf))
#define ApplFblNvReadPartialProgAttempts(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteProgAttempts(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncProgAttempts(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncProgAttempts(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncProgAttempts(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCRCValue(idx, buf)      WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCRCValue(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCRCValue(idx, buf)     WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCRCValue(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCRCValue(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCRCValue(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CRCVALUE, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCRCStart(idx, buf)      WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCRCStart(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCRCStart(idx, buf)     WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCRCStart(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCRCStart(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCRCStart(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CRCSTART, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCRCLength(idx, buf)     WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCRCLength(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCRCLength(idx, buf)    WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCRCLength(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCRCLength(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCRCLength(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CRCLENGTH, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSoftwareIdentification(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSoftwareIdentification(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSoftwareIdentification(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSoftwareIdentification(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSoftwareIdentification(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSoftwareIdentification(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSwEbomPartNumber(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSwEbomPartNumber(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSwEbomPartNumber(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSwEbomPartNumber(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSwEbomPartNumber(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSwEbomPartNumber(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (uint16)(idx), (buf), (op))

#define ApplFblNvReadMemoryStatus(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf))
#define ApplFblNvReadPartialMemoryStatus(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteMemoryStatus(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncMemoryStatus(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncMemoryStatus(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncMemoryStatus(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_MEMORYSTATUS, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentCount(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentCount(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentCount(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentCount(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentCount(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentCount(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentAddrList(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentAddrList(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentAddrList(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentAddrList(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentAddrList(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentAddrList(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentLengthList(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentLengthList(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentLengthList(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentLengthList(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentLengthList(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentLengthList(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (op))

#define ApplFblNvReadFlashStatus(idx, buf)   WrapNv_ReadSync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf))
#define ApplFblNvReadPartialFlashStatus(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteFlashStatus(idx, buf)  WrapNv_WriteSync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncFlashStatus(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncFlashStatus(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncFlashStatus(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_FLASHSTATUS, (uint16)(idx), (buf), (op))

#define ApplFblNvReadVehicleManufEcuSwNumber(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf))
#define ApplFblNvReadPartialVehicleManufEcuSwNumber(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteVehicleManufEcuSwNumber(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncVehicleManufEcuSwNumber(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncVehicleManufEcuSwNumber(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncVehicleManufEcuSwNumber(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf), (op))

#define ApplFblNvReadEbomAssemblyPartNumber(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf))
#define ApplFblNvReadPartialEbomAssemblyPartNumber(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteEbomAssemblyPartNumber(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncEbomAssemblyPartNumber(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncEbomAssemblyPartNumber(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncEbomAssemblyPartNumber(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_EBOMASSEMBLYPARTNUMBER, 0u, (buf), (op))

#define ApplFblNvReadDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf))
#define ApplFblNvReadPartialDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf))
#define ApplFblNvReadAsyncDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM, 0u, (buf), (op))

#define ApplFblNvReadDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf))
#define ApplFblNvReadPartialDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf))
#define ApplFblNvReadAsyncDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_F18B_FCA_ESLM_ECU_SW_App_Num(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM, 0u, (buf), (op))

#define ApplFblNvReadCoDePEcuPartNumber(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf))
#define ApplFblNvReadPartialCoDePEcuPartNumber(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteCoDePEcuPartNumber(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncCoDePEcuPartNumber(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncCoDePEcuPartNumber(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCoDePEcuPartNumber(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf), (op))

#define ApplFblNvReadCodepAssemblyPartNumber(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf))
#define ApplFblNvReadPartialCodepAssemblyPartNumber(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteCodepAssemblyPartNumber(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncCodepAssemblyPartNumber(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncCodepAssemblyPartNumber(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCodepAssemblyPartNumber(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CODEPASSEMBLYPARTNUMBER, 0u, (buf), (op))

#define ApplFblNvReadEbomEcuPartNumber(buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf))
#define ApplFblNvReadPartialEbomEcuPartNumber(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteEbomEcuPartNumber(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncEbomEcuPartNumber(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncEbomEcuPartNumber(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncEbomEcuPartNumber(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf), (op))

#define ApplFblNvReadDID_F194_Supplier_Ecu_SW_PartNum(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf))
#define ApplFblNvReadPartialDID_F194_Supplier_Ecu_SW_PartNum(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_F194_Supplier_Ecu_SW_PartNum(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf))
#define ApplFblNvReadAsyncDID_F194_Supplier_Ecu_SW_PartNum(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_F194_Supplier_Ecu_SW_PartNum(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_F194_Supplier_Ecu_SW_PartNum(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_F194_SUPPLIER_ECU_SW_PARTNUM, 0u, (buf), (op))

#define ApplFblNvReadDID_F195_Supplier_Ecu_SW_VerNum(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf))
#define ApplFblNvReadPartialDID_F195_Supplier_Ecu_SW_VerNum(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_F195_Supplier_Ecu_SW_VerNum(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf))
#define ApplFblNvReadAsyncDID_F195_Supplier_Ecu_SW_VerNum(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_F195_Supplier_Ecu_SW_VerNum(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_F195_Supplier_Ecu_SW_VerNum(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_F195_SUPPLIER_ECU_SW_VERNUM, 0u, (buf), (op))

#define ApplFblNvReadDiagnosticVersion(buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf))
#define ApplFblNvReadPartialDiagnosticVersion(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDiagnosticVersion(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf))
#define ApplFblNvReadAsyncDiagnosticVersion(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDiagnosticVersion(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDiagnosticVersion(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf), (op))

#define ApplFblNvReadDID_2002_OdoFlashing(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf))
#define ApplFblNvReadPartialDID_2002_OdoFlashing(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf), (offset), (length))
#define ApplFblNvWriteDID_2002_OdoFlashing(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf))
#define ApplFblNvReadAsyncDID_2002_OdoFlashing(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncDID_2002_OdoFlashing(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncDID_2002_OdoFlashing(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_DID_2002_ODOFLASHING, 0u, (buf), (op))

#define ApplFblNvReadFileHeaderInfo(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf))
#define ApplFblNvReadPartialFileHeaderInfo(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteFileHeaderInfo(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncFileHeaderInfo(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncFileHeaderInfo(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncFileHeaderInfo(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_FILEHEADERINFO, (uint16)(idx), (buf), (op))

#define ApplFblNvReadUuid(idx, buf)          WrapNv_ReadSync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf))
#define ApplFblNvReadPartialUuid(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteUuid(idx, buf)         WrapNv_WriteSync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncUuid(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncUuid(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncUuid(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_UUID, (uint16)(idx), (buf), (op))

#define ApplFblNvReadIssuerNme(idx, buf)     WrapNv_ReadSync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf))
#define ApplFblNvReadPartialIssuerNme(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteIssuerNme(idx, buf)    WrapNv_WriteSync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncIssuerNme(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncIssuerNme(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncIssuerNme(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_ISSUERNME, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSerialNumber(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSerialNumber(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSerialNumber(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSerialNumber(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSerialNumber(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSerialNumber(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SERIALNUMBER, (uint16)(idx), (buf), (op))

/* PRQA L:FctLikeMacroLabel */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** Specifies how the NV block is configured */
typedef enum
{
   WRAPNV_RECORDACCESS_STRUCTURED = 0u,  /**< NV block consists of several elements */
   WRAPNV_RECORDACCESS_SINGLE            /**< NV block consists of a single element */
} tWrapNvRecordAccess;

/** NV block configuration structure */
typedef struct
{
   tWrapNvRecordAccess blockDataAccess;                        /**< Access variant to the NV block */
   uint16 blockNumber;                                         /**< Number of NV block */
   uint16 blockLength;                                         /**< Length of NV block */
   uint16 blockMaxDatasets;                                    /**< Maximum datasets alloweed for the NV block */
   P2CONST(uint8, AUTOMATIC, WRAPNV_CONST) blockDefaultValue;  /**< Default value for NV block */
} tWrapNvBlockTbl;

/** NV record configuration structure */
typedef struct
{
   uint16 recordDataOffset;                                           /**< Offset in NV block to the data */
   uint16 recordDataLength;                                           /**< Length of data inside the NV block */
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) recordBlockPtr;  /**< Pointer to the NV block */
} tWrapNvRecordTbl;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[kWrapNvNrOfRecord];

# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, WRAPNV_CODE) WrapNv_InitConfig( void );

FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalIdle( void );
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalTimer( void );

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  USER CONFIG FILE
 *********************************************************************************************************************/



#endif  /* WRAPNV_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: WrapNv_Cfg.h
 *********************************************************************************************************************/

