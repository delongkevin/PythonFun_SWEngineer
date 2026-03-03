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
 *    License Scope : The usage is restricted to CBD2101146_D13
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WrapNv_Cfg.c
 *   Generation Time: 2024-11-25 14:50:08
 *           Project: DemoBm - Version 1.0
 *          Delivery: CBD2101146_D13
 *      Tool Version: DaVinci Configurator Classic 5.25.40 SP3
 *
 *
 *********************************************************************************************************************/


#define WRAPNV_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "WrapNv_Cfg.h"
# include "Eep_30_XXi2c01.h"
# include "Ea.h"
# include "NvM.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define kEepSizeNvMBlockDescriptor_ApplUpdate 0x01u
#define kEepSizeNvMBlockDescriptor_ApplValidity 0x01u
#define kEepSizeNvMBlockDescriptor_CertAccessInfo 0x2Eu
#define kEepSizeNvMBlockDescriptor_CertificateExpired 0x01u
#define kEepSizeNvMBlockDescriptor_DID_2010_ProgrammingStatus 0x02u
#define kEepSizeNvMBlockDescriptor_DcmDslRxTesterSourceAddr 0x02u
#define kEepSizeNvMBlockDescriptor_ExhaustRegulationTan 0x06u
#define kEepSizeNvMBlockDescriptor_FileHeader 0xB0u
#define kEepSizeNvMBlockDescriptor_MetaData  0x7Eu
#define kEepSizeNvMBlockDescriptor_ResetResponseFlag 0x01u
#define kEepSizeNvMBlockDescriptor_SecAccessDelayFlag 0x01u
#define kEepSizeNvMBlockDescriptor_SecAccessInvalidCount 0x01u
#define kEepSizeNvMBlockDescriptor_SecondCounter 0x04u
#define kEepSizeNvMBlockDescriptor_SecureLogGroup1 0x01E8u
#define kEepSizeNvMBlockDescriptor_SecureLogGroup2 0x01E8u
#define kEepSizeNvMBlockDescriptor_SystemTimestamp 0x0Fu
#define kEepSizeNvMBlockDescriptor_ValidityFlags 0x02u
#define kEepSizeNvMConfigBlock               0x02u
#define kEepSizeSWC_ConfigMgrVIN_OriginalVal 0x11u
#define kEepSizeSWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock 0x02u
#define kEepSizeSWC_PartNumMgrDID_F110_Ecu_Diag_Info 0x06u
#define kEepSizeSWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum 0x0Au
#define kEepSizeSWC_PartNumMgrDID_F133_EBOM_Asm_PartNum 0x0Au
#define kEepSizeSWC_PartNumMgrDID_F134_CODEP_Asm_PartNum 0x0Bu
#define kEepSizeSWC_PartNumMgrDID_F180_Boot_SW_Ver_Info 0x0Du
#define kEepSizeSWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum 0x0Bu
#define kEepSizeSWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num 0x0Bu
#define kEepSizeSWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num 0x0Au
#define kEepSizeSWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num 0x0Au
#define kEepSizeSWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum 0x0Bu
#define kEepSizeSWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum 0x02u
#define kEepSizeSWC_SysMgrSysM_ProgReqFlag   0x01u

/** Default value arrays ****************************************************** */
static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_ApplUpdate[kEepSizeNvMBlockDescriptor_ApplUpdate] =
         {
             /* ApplUpdate */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_ApplValidity[kEepSizeNvMBlockDescriptor_ApplValidity] =
         {
             /* ApplValidity */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_CertAccessInfo[kEepSizeNvMBlockDescriptor_CertAccessInfo] =
         {
             /* IssuerName */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* SerialNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_CertificateExpired[kEepSizeNvMBlockDescriptor_CertificateExpired] =
         {
             /* CertificateExpired */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_DID_2010_ProgrammingStatus[kEepSizeNvMBlockDescriptor_DID_2010_ProgrammingStatus] =
         {
             /* ProgrammingStatus */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_DcmDslRxTesterSourceAddr[kEepSizeNvMBlockDescriptor_DcmDslRxTesterSourceAddr] =
         {
             /* DcmDslRxTesterSourceAddr */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_ExhaustRegulationTan[kEepSizeNvMBlockDescriptor_ExhaustRegulationTan] =
         {
             /* ExhaustRegulationTan */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_FileHeader[kEepSizeNvMBlockDescriptor_FileHeader] =
         {
             /* FileHeaderInfo */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* Uuid */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_MetaData[kEepSizeNvMBlockDescriptor_MetaData] =
         {
             /* Fingerprint */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* ProgCounter */ 0xFF, 0xFF,
             /* ProgAttempts */ 0xFF, 0xFF,
             /* CRCValue */ 0xFF,
             /* CRCStart */ 0xFF,
             /* CRCLength */ 0xFF,
             /* SoftwareIdentification */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* SwEbomPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* MemoryStatus */ 0xFF,
             /* SegmentCount */ 0xFF,
             /* SegmentAddrList */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* SegmentLengthList */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* FlashStatus */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_ResetResponseFlag[kEepSizeNvMBlockDescriptor_ResetResponseFlag] =
         {
             /* ResetResponseFlag */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessDelayFlag[kEepSizeNvMBlockDescriptor_SecAccessDelayFlag] =
         {
             /* SecAccessDelayFlag */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessInvalidCount[kEepSizeNvMBlockDescriptor_SecAccessInvalidCount] =
         {
             /* SecAccessInvalidCount */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecondCounter[kEepSizeNvMBlockDescriptor_SecondCounter] =
         {
             /* SecondCounter */ 0x00, 0x00, 0x00, 0x00
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecureLogGroup1[kEepSizeNvMBlockDescriptor_SecureLogGroup1] =
         {
             /* SecureLogGroupOne */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecureLogGroup2[kEepSizeNvMBlockDescriptor_SecureLogGroup2] =
         {
             /* SecureLogGroupTwo */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SystemTimestamp[kEepSizeNvMBlockDescriptor_SystemTimestamp] =
         {
             /* SystemTimestamp */ 0x32, 0x30, 0x32, 0x33, 0x30, 0x39, 0x32, 0x36, 0x31, 0x34, 0x34, 0x35, 0x34, 0x32, 0x5a
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_ValidityFlags[kEepSizeNvMBlockDescriptor_ValidityFlags] =
         {
             /* ValidityFlags */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMConfigBlock[kEepSizeNvMConfigBlock] =
         {
             /* NvMConfigBlock */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_ConfigMgrVIN_OriginalVal[kEepSizeSWC_ConfigMgrVIN_OriginalVal] =
         {
             /* SWC_ConfigMgrVIN_OriginalVal */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock[kEepSizeSWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock] =
         {
             /* DID_2002_OdoFlashing */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F110_Ecu_Diag_Info[kEepSizeSWC_PartNumMgrDID_F110_Ecu_Diag_Info] =
         {
             /* DiagnosticVersion */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum[kEepSizeSWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum] =
         {
             /* EbomEcuPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum[kEepSizeSWC_PartNumMgrDID_F133_EBOM_Asm_PartNum] =
         {
             /* EbomAssemblyPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum[kEepSizeSWC_PartNumMgrDID_F134_CODEP_Asm_PartNum] =
         {
             /* CodepAssemblyPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info[kEepSizeSWC_PartNumMgrDID_F180_Boot_SW_Ver_Info] =
         {
             /* DID_F180_Boot_SW_Ver_Info */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum[kEepSizeSWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum] =
         {
             /* CoDePEcuPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num[kEepSizeSWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num] =
         {
             /* VehicleManufEcuSwNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num[kEepSizeSWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num] =
         {
             /* DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num[kEepSizeSWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num] =
         {
             /* DID_F18B_FCA_ESLM_ECU_SW_App_Num */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum[kEepSizeSWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum] =
         {
             /* DID_F194_Supplier_Ecu_SW_PartNum */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum[kEepSizeSWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum] =
         {
             /* DID_F195_Supplier_Ecu_SW_VerNum */ 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_SWC_SysMgrSysM_ProgReqFlag[kEepSizeSWC_SysMgrSysM_ProgReqFlag] =
         {
             /* ProgReqFlag */ 0xFF
         };


/** Block table *************************************************************** */
static CONST(tWrapNvBlockTbl, WRAPNV_CONST) kWrapNvBlockTbl[kWrapNvNrOfBlock] =
{
   /** NvMBlockDescriptor_ApplUpdate */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ApplUpdate,
      kEepSizeNvMBlockDescriptor_ApplUpdate,
      WRAPNV_DATASET_APPLUPDATE,
      kWrapNvDefaultValue_NvMBlockDescriptor_ApplUpdate
   },

   /** NvMBlockDescriptor_ApplValidity */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ApplValidity,
      kEepSizeNvMBlockDescriptor_ApplValidity,
      WRAPNV_DATASET_APPLVALIDITY,
      kWrapNvDefaultValue_NvMBlockDescriptor_ApplValidity
   },

   /** NvMBlockDescriptor_CertAccessInfo */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_CertAccessInfo,
      kEepSizeNvMBlockDescriptor_CertAccessInfo,
      WRAPNV_DATASET_CERTACCESSINFO,
      kWrapNvDefaultValue_NvMBlockDescriptor_CertAccessInfo
   },

   /** NvMBlockDescriptor_CertificateExpired */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_CertificateExpired,
      kEepSizeNvMBlockDescriptor_CertificateExpired,
      WRAPNV_DATASET_CERTIFICATEEXPIRED,
      kWrapNvDefaultValue_NvMBlockDescriptor_CertificateExpired
   },

   /** NvMBlockDescriptor_DID_2010_ProgrammingStatus */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_2010_ProgrammingStatus,
      kEepSizeNvMBlockDescriptor_DID_2010_ProgrammingStatus,
      WRAPNV_DATASET_PROGRAMMINGSTATUS,
      kWrapNvDefaultValue_NvMBlockDescriptor_DID_2010_ProgrammingStatus
   },

   /** NvMBlockDescriptor_DcmDslRxTesterSourceAddr */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DcmDslRxTesterSourceAddr,
      kEepSizeNvMBlockDescriptor_DcmDslRxTesterSourceAddr,
      WRAPNV_DATASET_DCMDSLRXTESTERSOURCEADDR,
      kWrapNvDefaultValue_NvMBlockDescriptor_DcmDslRxTesterSourceAddr
   },

   /** NvMBlockDescriptor_ExhaustRegulationTan */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ExhaustRegulationTan,
      kEepSizeNvMBlockDescriptor_ExhaustRegulationTan,
      WRAPNV_DATASET_EXHAUSTREGULATIONTAN,
      kWrapNvDefaultValue_NvMBlockDescriptor_ExhaustRegulationTan
   },

   /** NvMBlockDescriptor_FileHeader */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_FileHeader,
      kEepSizeNvMBlockDescriptor_FileHeader,
      WRAPNV_DATASET_FILEHEADER,
      kWrapNvDefaultValue_NvMBlockDescriptor_FileHeader
   },

   /** NvMBlockDescriptor_MetaData */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_MetaData,
      kEepSizeNvMBlockDescriptor_MetaData,
      WRAPNV_DATASET_METADATA,
      kWrapNvDefaultValue_NvMBlockDescriptor_MetaData
   },

   /** NvMBlockDescriptor_ResetResponseFlag */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ResetResponseFlag,
      kEepSizeNvMBlockDescriptor_ResetResponseFlag,
      WRAPNV_DATASET_RESETRESPONSEFLAG,
      kWrapNvDefaultValue_NvMBlockDescriptor_ResetResponseFlag
   },

   /** NvMBlockDescriptor_SecAccessDelayFlag */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecAccessDelayFlag,
      kEepSizeNvMBlockDescriptor_SecAccessDelayFlag,
      WRAPNV_DATASET_SECACCESSDELAYFLAG,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessDelayFlag
   },

   /** NvMBlockDescriptor_SecAccessInvalidCount */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecAccessInvalidCount,
      kEepSizeNvMBlockDescriptor_SecAccessInvalidCount,
      WRAPNV_DATASET_SECACCESSINVALIDCOUNT,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessInvalidCount
   },

   /** NvMBlockDescriptor_SecondCounter */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecondCounter,
      kEepSizeNvMBlockDescriptor_SecondCounter,
      WRAPNV_DATASET_SECONDCOUNTER,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecondCounter
   },

   /** NvMBlockDescriptor_SecureLogGroup1 */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecureLogGroup1,
      kEepSizeNvMBlockDescriptor_SecureLogGroup1,
      WRAPNV_DATASET_SECURELOGGROUP1,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecureLogGroup1
   },

   /** NvMBlockDescriptor_SecureLogGroup2 */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SecureLogGroup2,
      kEepSizeNvMBlockDescriptor_SecureLogGroup2,
      WRAPNV_DATASET_SECURELOGGROUP2,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecureLogGroup2
   },

   /** NvMBlockDescriptor_SystemTimestamp */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_SystemTimestamp,
      kEepSizeNvMBlockDescriptor_SystemTimestamp,
      WRAPNV_DATASET_SYSTEMTIMESTAMP,
      kWrapNvDefaultValue_NvMBlockDescriptor_SystemTimestamp
   },

   /** NvMBlockDescriptor_ValidityFlags */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ValidityFlags,
      kEepSizeNvMBlockDescriptor_ValidityFlags,
      WRAPNV_DATASET_VALIDITYFLAGS,
      kWrapNvDefaultValue_NvMBlockDescriptor_ValidityFlags
   },

   /** NvMConfigBlock */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_NvMConfigBlock,
      kEepSizeNvMConfigBlock,
      WRAPNV_DATASET_NVMCONFIGBLOCK,
      kWrapNvDefaultValue_NvMConfigBlock
   },

   /** SWC_ConfigMgrVIN_OriginalVal */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_ConfigMgrVIN_OriginalVal,
      kEepSizeSWC_ConfigMgrVIN_OriginalVal,
      WRAPNV_DATASET_SWC_CONFIGMGRVIN_ORIGINALVAL,
      kWrapNvDefaultValue_SWC_ConfigMgrVIN_OriginalVal
   },

   /** SWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock,
      kEepSizeSWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock,
      WRAPNV_DATASET_DID_2002_ODOFLASHING,
      kWrapNvDefaultValue_SWC_DIDMgrDID_2002_OdoFlashing_MirrorBlock
   },

   /** SWC_PartNumMgrDID_F110_Ecu_Diag_Info */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F110_Ecu_Diag_Info,
      kEepSizeSWC_PartNumMgrDID_F110_Ecu_Diag_Info,
      WRAPNV_DATASET_DIAGNOSTICVERSION,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F110_Ecu_Diag_Info
   },

   /** SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum,
      kEepSizeSWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum,
      WRAPNV_DATASET_EBOMECUPARTNUMBER,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum
   },

   /** SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum,
      kEepSizeSWC_PartNumMgrDID_F133_EBOM_Asm_PartNum,
      WRAPNV_DATASET_EBOMASSEMBLYPARTNUMBER,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum
   },

   /** SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum,
      kEepSizeSWC_PartNumMgrDID_F134_CODEP_Asm_PartNum,
      WRAPNV_DATASET_CODEPASSEMBLYPARTNUMBER,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum
   },

   /** SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info,
      kEepSizeSWC_PartNumMgrDID_F180_Boot_SW_Ver_Info,
      WRAPNV_DATASET_DID_F180_BOOT_SW_VER_INFO,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info
   },

   /** SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum,
      kEepSizeSWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum,
      WRAPNV_DATASET_CODEPECUPARTNUMBER,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum
   },

   /** SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num,
      kEepSizeSWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num,
      WRAPNV_DATASET_VEHICLEMANUFECUSWNUMBER,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num
   },

   /** SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num,
      kEepSizeSWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num,
      WRAPNV_DATASET_DID_F18A_FCA_ESLM_ECU_SW_CAL_NUM,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num
   },

   /** SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num,
      kEepSizeSWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num,
      WRAPNV_DATASET_DID_F18B_FCA_ESLM_ECU_SW_APP_NUM,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num
   },

   /** SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum,
      kEepSizeSWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum,
      WRAPNV_DATASET_DID_F194_SUPPLIER_ECU_SW_PARTNUM,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum
   },

   /** SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum,
      kEepSizeSWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum,
      WRAPNV_DATASET_DID_F195_SUPPLIER_ECU_SW_VERNUM,
      kWrapNvDefaultValue_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum
   },

   /** SWC_SysMgrSysM_ProgReqFlag */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      NvMConf_NvMBlockDescriptor_SWC_SysMgrSysM_ProgReqFlag,
      kEepSizeSWC_SysMgrSysM_ProgReqFlag,
      WRAPNV_DATASET_PROGREQFLAG,
      kWrapNvDefaultValue_SWC_SysMgrSysM_ProgReqFlag
   }
};

/** Record table ************************************************************** */
CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[kWrapNvNrOfRecord] =
{


   /** CertificateExpired */

   /** CertificateExpired */
   {  /* Store certificate Expiry due to session second counter(not used in BM) */
      0x00u,
      kEepSizeCertificateExpired,
      &kWrapNvBlockTbl[3]
   },

   /** NvMConfigBlock */

   /** NvMConfigBlock */
   {  /* NvMConfigBlock */
      0x00u,
      kEepSizeNvMConfigBlock,
      &kWrapNvBlockTbl[17]
   },

   /** ApplUpdate */

   /** ApplUpdate */
   {  /* Application update flag */
      0x00u,
      kEepSizeApplUpdate,
      &kWrapNvBlockTbl[0]
   },

   /** ProgReqFlag */

   /** ProgReqFlag */
   {  /* Programming request flag */
      0x00u,
      kEepSizeProgReqFlag,
      &kWrapNvBlockTbl[31]
   },

   /** SecAccessDelayFlag */

   /** SecAccessDelayFlag */
   {  /* Security Access Delay flag */
      0x00u,
      kEepSizeSecAccessDelayFlag,
      &kWrapNvBlockTbl[10]
   },

   /** SecAccessInvalidCount */

   /** SecAccessInvalidCount */
   {  /* Security Access Invalid count */
      0x00u,
      kEepSizeSecAccessInvalidCount,
      &kWrapNvBlockTbl[11]
   },

   /** ApplValidity */

   /** ApplValidity */
   {  /* Application validity flag */
      0x00u,
      kEepSizeApplValidity,
      &kWrapNvBlockTbl[1]
   },

   /** DcmDslRxTesterSourceAddr */

   /** DcmDslRxTesterSourceAddr */
   {  /* Connection for reset response */
      0x00u,
      kEepSizeDcmDslRxTesterSourceAddr,
      &kWrapNvBlockTbl[5]
   },

   /** ValidityFlags */

   /** ValidityFlags */
   {  /* Logical block validity flagss */
      0x00u,
      kEepSizeValidityFlags,
      &kWrapNvBlockTbl[16]
   },

   /** ExhaustRegulationTan */

   /** ExhaustRegulationTan */
   {  /* DID F196 - Exhaust Regulation or Type Approval Number */
      0x00u,
      kEepSizeExhaustRegulationTan,
      &kWrapNvBlockTbl[6]
   },

   /** ResetResponseFlag */

   /** ResetResponseFlag */
   {  /* Reset response flag */
      0x00u,
      kEepSizeResetResponseFlag,
      &kWrapNvBlockTbl[9]
   },

   /** DID_F180_Boot_SW_Ver_Info */

   /** DID_F180_Boot_SW_Ver_Info */
   {  /* DID_F180_Boot_SW_Ver_Info */
      0x00u,
      kEepSizeDID_F180_Boot_SW_Ver_Info,
      &kWrapNvBlockTbl[24]
   },

   /** ProgrammingStatus */

   /** ProgrammingStatus */
   {  /* Programming Status Informationn */
      0x00u,
      kEepSizeProgrammingStatus,
      &kWrapNvBlockTbl[4]
   },

   /** Metadata */

   /** Fingerprint */
   {  /* Download fingerprint */
      0x00u,
      kEepSizeFingerprint,
      &kWrapNvBlockTbl[8]
   },

   /** ProgCounter */
   {  /* Successful reprogramming attempts */
      0x0Du,
      kEepSizeProgCounter,
      &kWrapNvBlockTbl[8]
   },

   /** ProgAttempts */
   {  /* Reprogramming attempts */
      0x0Fu,
      kEepSizeProgAttempts,
      &kWrapNvBlockTbl[8]
   },

   /** CRCValue */
   {  /* CRC total of logical block */
      0x11u,
      kEepSizeCRCValue,
      &kWrapNvBlockTbl[8]
   },

   /** CRCStart */
   {  /* Start address of CRC total */
      0x12u,
      kEepSizeCRCStart,
      &kWrapNvBlockTbl[8]
   },

   /** CRCLength */
   {  /* Length of CRC total */
      0x13u,
      kEepSizeCRCLength,
      &kWrapNvBlockTbl[8]
   },

   /** SoftwareIdentification */
   {  /* DID F181 or F182 - Application Software- or Application Data Identification */
      0x14u,
      kEepSizeSoftwareIdentification,
      &kWrapNvBlockTbl[8]
   },

   /** SwEbomPartNumber */
   {  /* DID F122 - S/W EBOM Part Number */
      0x21u,
      kEepSizeSwEbomPartNumber,
      &kWrapNvBlockTbl[8]
   },

   /** MemoryStatus */
   {  /* Memory status; erased, programmeds */
      0x2Bu,
      kEepSizeMemoryStatus,
      &kWrapNvBlockTbl[8]
   },

   /** SegmentCount */
   {  /* Number of entries in segment list */
      0x2Cu,
      kEepSizeSegmentCount,
      &kWrapNvBlockTbl[8]
   },

   /** SegmentAddrList */
   {  /* List of segment start addresses */
      0x2Du,
      kEepSizeSegmentAddrList,
      &kWrapNvBlockTbl[8]
   },

   /** SegmentLengthList */
   {  /* List of segment lengths */
      0x55u,
      kEepSizeSegmentLengthList,
      &kWrapNvBlockTbl[8]
   },

   /** FlashStatus */
   {  /* Flash Status */
      0x7Du,
      kEepSizeFlashStatus,
      &kWrapNvBlockTbl[8]
   },

   /** VehicleManufEcuSwNumber */

   /** VehicleManufEcuSwNumber */
   {  /* DID F188 - Vehicle Manufacturer ECU Software Number */
      0x00u,
      kEepSizeVehicleManufEcuSwNumber,
      &kWrapNvBlockTbl[26]
   },

   /** EbomAssemblyPartNumber */

   /** EbomAssemblyPartNumber */
   {  /* EbomAssemblyPartNumber */
      0x00u,
      kEepSizeEbomAssemblyPartNumber,
      &kWrapNvBlockTbl[22]
   },

   /** DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */

   /** DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */
   {  /* DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num */
      0x00u,
      kEepSizeDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num,
      &kWrapNvBlockTbl[27]
   },

   /** DID_F18B_FCA_ESLM_ECU_SW_App_Num */

   /** DID_F18B_FCA_ESLM_ECU_SW_App_Num */
   {  /* DID_F18B_FCA_ESLM_ECU_SW_App_Num */
      0x00u,
      kEepSizeDID_F18B_FCA_ESLM_ECU_SW_App_Num,
      &kWrapNvBlockTbl[28]
   },

   /** CoDePEcuPartNumber */

   /** CoDePEcuPartNumber */
   {  /* DID F187 - CoDeP ECU Part Number */
      0x00u,
      kEepSizeCoDePEcuPartNumber,
      &kWrapNvBlockTbl[25]
   },

   /** CodepAssemblyPartNumber */

   /** CodepAssemblyPartNumber */
   {  /* CodepAssemblyPartNumber */
      0x00u,
      kEepSizeCodepAssemblyPartNumber,
      &kWrapNvBlockTbl[23]
   },

   /** EbomEcuPartNumber */

   /** EbomEcuPartNumber */
   {  /* DID F132 - EBOM ECU Part Number */
      0x00u,
      kEepSizeEbomEcuPartNumber,
      &kWrapNvBlockTbl[21]
   },

   /** DID_F194_Supplier_Ecu_SW_PartNum */

   /** DID_F194_Supplier_Ecu_SW_PartNum */
   {  /* DID_F194_Supplier_Ecu_SW_PartNum */
      0x00u,
      kEepSizeDID_F194_Supplier_Ecu_SW_PartNum,
      &kWrapNvBlockTbl[29]
   },

   /** DID_F195_Supplier_Ecu_SW_VerNum */

   /** DID_F195_Supplier_Ecu_SW_VerNum */
   {  /* DID_F195_Supplier_Ecu_SW_VerNum */
      0x00u,
      kEepSizeDID_F195_Supplier_Ecu_SW_VerNum,
      &kWrapNvBlockTbl[30]
   },

   /** DiagnosticVersion */

   /** DiagnosticVersion */
   {  /* Diagnostic Version of DID F110h */
      0x00u,
      kEepSizeDiagnosticVersion,
      &kWrapNvBlockTbl[20]
   },

   /** DID_2002_OdoFlashing */

   /** DID_2002_OdoFlashing */
   {  /* DID_2002_OdoFlashing */
      0x00u,
      kEepSizeDID_2002_OdoFlashing,
      &kWrapNvBlockTbl[19]
   },

   /** SWC_ConfigMgrVIN_OriginalVal */

   /** SWC_ConfigMgrVIN_OriginalVal */
   {  /* SWC_ConfigMgrVIN_OriginalVal */
      0x00u,
      kEepSizeSWC_ConfigMgrVIN_OriginalVal,
      &kWrapNvBlockTbl[18]
   },

   /** fileHeader */

   /** FileHeaderInfo */
   {  /* TargetName field is a PrintableString that will equal the identifier for the intended ECU */
      0x00u,
      kEepSizeFileHeaderInfo,
      &kWrapNvBlockTbl[7]
   },

   /** Uuid */
   {  /* The Uuid field represents a unique identifier of the signed block. */
      0xA0u,
      kEepSizeUuid,
      &kWrapNvBlockTbl[7]
   },

   /** CertAccessInfo */

   /** IssuerName */
   {  /* FBL ADA  certificate issuer name */
      0x00u,
      kEepSizeIssuerName,
      &kWrapNvBlockTbl[2]
   },

   /** SerialNumber */
   {  /* FBL ADA  certificate serialNumber */
      0x1Au,
      kEepSizeSerialNumber,
      &kWrapNvBlockTbl[2]
   },

   /** SecureLogGroup1 */

   /** SecureLogGroupOne */
   {  /*  */
      0x00u,
      kEepSizeSecureLogGroupOne,
      &kWrapNvBlockTbl[13]
   },

   /** SecureLogGroup2 */

   /** SecureLogGroupTwo */
   {  /*  */
      0x00u,
      kEepSizeSecureLogGroupTwo,
      &kWrapNvBlockTbl[14]
   },

   /** SecondCounter */

   /** SecondCounter */
   {  /* Second Counter */
      0x00u,
      kEepSizeSecondCounter,
      &kWrapNvBlockTbl[12]
   },

   /** SystemTimestamp */

   /** SystemTimestamp */
   {  /* System Timestamp(NotBefore time from received certificate) */
      0x00u,
      kEepSizeSystemTimestamp,
      &kWrapNvBlockTbl[15]
   }
};


# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Internal MainFunction polling idle function ******************************* */
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalIdle( void ) {

   Eep_30_XXi2c01_MainFunction();
   NvM_MainFunction();
   Ea_MainFunction();

}

/** Internal MainFunction polling timer function ****************************** */
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalTimer( void ) {

   /** Increment call counter */

   /** Call resp. MainFunctions if counter expired */

}

/** Init config function ****************************************************** */
FUNC(void, WRAPNV_CODE) WrapNv_InitConfig( void ) {

   /** Initialize call counter for polling main functions */

   /** Empty method stub */
}

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
  END OF FILE: WrapNv_Cfg.c
**********************************************************************************************************************/


