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
 *            Module: NvM
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.c
 *   Generation Time: 2024-12-05 18:40:59
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */
    
/**********************************************************************************************************************
 *  MODULE SWITCH
 *********************************************************************************************************************/
/* this switch enables the header file(s) to hide some parts. */
#define NVM_CFG_SOURCE

/* multiple inclusion protection */
#define NVM_H_

/* Required for RTE ROM block definitions */
#define RTE_MICROSAR_PIM_EXPORT

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* This tag will only be replaced, if one or more callbacks via Service Ports had been configured */
#include "Rte_NvM.h"

/**********************************************************************************************************************
 *  MODULE HEADER INCLUDES
 *********************************************************************************************************************/
/* only includes the public part of config */
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

#include "BswM_NvM.h"

/**********************************************************************************************************************
 *  VERSION CHECKS
 *********************************************************************************************************************/
#if ((NVM_CFG_MAJOR_VERSION != (9u)) \
        || (NVM_CFG_MINOR_VERSION != (2u)))
# error "Version numbers of NvM_Cfg.c and NvM_Cfg.h are inconsistent!"
#endif

/* include list of the callback definitions */
#include "vRoE.h" 
#include "Eep_Public.h" 
#include "Dem_Cbk.h" 
#include "Dem.h" 
#include "NvMdef_User_Types.h" 


/* include configured file declaring or defining resource (un)locking service(s) */
#include "SchM_NvM.h"

/**********************************************************************************************************************
 *  PUBLIC CONSTANTS
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_16
#include "NvM_MemMap.h"

/* maximum number of bytes to be processed in one crc calculation step */
CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16 = 64u;

/* constant holding Crc queue size value */
CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16 = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

#define NVM_STOP_SEC_CONST_16
#include "NvM_MemMap.h"

/* 8Bit Data section containing the data integrity buffers */
#define NVM_START_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

static VAR(uint8, NVM_PRIVATE_DATA) NvMConfigBlock_RamBlock_au8[4u];

#if ((NVM_DATA_INTEGRITY_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SecAccessDelayFlag_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SecAccessInvalidCount_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_F110_Ecu_Diag_Info_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_2002_OdoFlashing_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_ADMIN_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_Aging_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY0_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY1_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY2_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY3_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY4_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY5_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY6_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY7_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY8_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_PRIMARY9_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvM_Dem_STATUS_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgr_vRoE_Activation_State_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_191D_PowerLatch_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_200A_IgOnCounter_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_200B_TimeSinceFirstDTC_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_200D_LastClearDTCOdo_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrECU_LifeTime_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_ProxiConfigMgrProxiConfigTable_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_ProxiConfigMgrProxiErrorData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_2002_ProgReqFlag_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD33_MagnaTesting_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrDID_FD31_EOLCodingState_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamCurrentCalibData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamEOLCalibData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamOCCalibData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamSCCalibData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_PartNumMgrUssSensorMarrData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD01_PrevCalibDataCopy_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD42_FailsafeDebug_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_RearBrakeEvent_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_SPMAbrtEvent_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_IPCHandlerFeatureAP_HMI_NvMData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD86_FunctionalSettings_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_IPCHandlerFPA_SlotData_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Safety_GuardSafeStat2_ResetReason_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderFrontCamSerialNumber_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderLeftCamSerialNumber_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderRearCamSerialNumber_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderRightCamSerialNumber_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SecondCounter_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SystemTimestamp_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_SafetyCDD_PMICLastResetReason_BISTStatus_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD74_BuffMarkCompErr_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DIDMgrDID_FD74_PHY_TuningErr_Crc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_DTCMgrDTC_APARequestSts_PAMRequestSts_Crc[2u]; 

static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1_Mac[16u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2_Mac[16u]; 

#endif


 /*  CRC buffers for CRCCompareMechanism  */ 
static VAR(uint8, NVM_PRIVATE_DATA) SWC_ProxiConfigMgrProxiConfigTable_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamCurrentCalibData_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamEOLCalibData_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamOCCalibData_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderSVSCamSCCalibData_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CDD_IPCHandlerFPA_SlotData_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderFrontCamSerialNumber_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderLeftCamSerialNumber_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderRearCamSerialNumber_CompCrc[2u]; 
static VAR(uint8, NVM_PRIVATE_DATA) CalDataProviderRightCamSerialNumber_CompCrc[2u]; 


#define NVM_STOP_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

/* Data section containing the internal buffers. If job forwarding from application to memory core is enabled the buffer must be placed in the shared memory. */
#define NVM_START_SEC_VAR_INTERNAL_BUFFER
#include "NvM_MemMap.h"

#if ((NVM_DATA_INTEGRITY_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON) \
    || (NVM_JOB_FORWARDING_TO_MEMORY_CORE == STD_ON) || (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
/* create the internal buffer of size NVM_INTERNAL_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[NVM_INTERNAL_BUFFER_LENGTH]; /* PRQA S 1533 */ /* MD_NvM_Cfg_8.9_InternalBuffer */
/* create the internal immediate prio buffer of size NVM_INTERNAL_IMMEDIATE_DATA_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalImmediateDataBuffer[NVM_INTERNAL_IMMEDIATE_DATA_BUFFER_LENGTH]; /* PRQA S 1533 */ /* MD_NvM_Cfg_8.9_InternalBuffer */
#endif


#define NVM_STOP_SEC_VAR_INTERNAL_BUFFER
#include "NvM_MemMap.h"

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t = {(uint16)NVM_COMPILED_CONFIG_ID}; /* PRQA S 0759 */ /* MD_MSR_Union */
 

CONST(NvM_CsmMacJobType, NVM_PRIVATE_CONST) NvM_CsmMacJobs[NVM_NR_OF_CSM_MAC_JOBS] = 
    {
      {
        4u /*  Generation job Id  */ , 
        5u /*  Verification job Id  */ 
      }
    };
 
/* block descriptor table that holds the static configuration parameters of the RAM, ROM and NVBlocks.
* This table has to be adjusted according to the configuration of the NVManager.
*/

CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS] =
    {
      { /*  MultiBlockRequest  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        { 0u } /*  Flags  */ , 
        0x0001u /*  NV block Base number (defined by FEE/EA)  */ , 
        0U /*  NvMNvBlockLength  */ , 
        0U /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        0u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        0u /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMConfigBlock  */ 
        (NvM_RamAddressType)NvMConfigBlock_RamBlock_au8 /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0010u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_ApplUpdate  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0250u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SecAccessDelayFlag  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SecAccessDelayFlag_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0220u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SecAccessInvalidCount  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SecAccessInvalidCount_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0230u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_ApplValidity  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0100u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_DcmDslRxTesterSourceAddr  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_ValidityFlags  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0240u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_ExhaustRegulationTan  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        6u /*  NvMNvBlockLength  */ , 
        6u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_ResetResponseFlag  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0210u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0170u /*  NV block Base number (defined by FEE/EA)  */ , 
        13u /*  NvMNvBlockLength  */ , 
        13u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_DID_2010_ProgrammingStatus  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0120u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_MetaData  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0200u /*  NV block Base number (defined by FEE/EA)  */ , 
        126u /*  NvMNvBlockLength  */ , 
        126u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        10u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_DATASET /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_FileHeader  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NvMBlockDescriptor_FileHeader_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0450u /*  NV block Base number (defined by FEE/EA)  */ , 
        176u /*  NvMNvBlockLength  */ , 
        176u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        9u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_DATASET /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMBlockDescriptor_CertAccessInfo  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NvMBlockDescriptor_CertAccessInfo_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0460u /*  NV block Base number (defined by FEE/EA)  */ , 
        46u /*  NvMNvBlockLength  */ , 
        46u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        10u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_DATASET /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0190u /*  NV block Base number (defined by FEE/EA)  */ , 
        11u /*  NvMNvBlockLength  */ , 
        11u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0150u /*  NV block Base number (defined by FEE/EA)  */ , 
        10u /*  NvMNvBlockLength  */ , 
        10u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        10u /*  NvMNvBlockLength  */ , 
        10u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        10u /*  NvMNvBlockLength  */ , 
        10u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0180u /*  NV block Base number (defined by FEE/EA)  */ , 
        11u /*  NvMNvBlockLength  */ , 
        11u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0160u /*  NV block Base number (defined by FEE/EA)  */ , 
        11u /*  NvMNvBlockLength  */ , 
        11u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0140u /*  NV block Base number (defined by FEE/EA)  */ , 
        10u /*  NvMNvBlockLength  */ , 
        10u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        11u /*  NvMNvBlockLength  */ , 
        11u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x01D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_F110_Ecu_Diag_Info  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_F110_Ecu_Diag_Info_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0130u /*  NV block Base number (defined by FEE/EA)  */ , 
        6u /*  NvMNvBlockLength  */ , 
        6u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_2002_OdoFlashing  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_2002_OdoFlashing_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0110u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_RIDMgrVIN_OriginalVal  */ 
        (NvM_RamAddressType)&Rte_SWC_RIDMgr_VIN_OriginalVal_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        17u /*  NvMNvBlockLength  */ , 
        17u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_ADMIN  */ 
        (NvM_RamAddressType)&Dem_Cfg_AdminData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitAdminData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_ADMIN_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0020u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_Aging  */ 
        (NvM_RamAddressType)&Dem_Cfg_AgingData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_Aging_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0030u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_AgingData) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_AgingData) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY0  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_0 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY0_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0050u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY1  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_1 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY1_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0060u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY2  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_2 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY2_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0070u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY3  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_3 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY3_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0080u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY4  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_4 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY4_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0090u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY5  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_5 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY5_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY6  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_6 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY6_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY7  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_7 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY7_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY8  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_8 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY8_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_PRIMARY9  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_9 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_PRIMARY9_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvM_Dem_STATUS  */ 
        (NvM_RamAddressType)&Dem_Cfg_StatusData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitStatusData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvM_Dem_STATUS_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_OFF, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0040u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_2939_WakeupReason  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_2939_WakeupReason_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0260u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FDF0_SleepProcess  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0270u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_RIDMgrDID_5201_PlantModeStatus  */ 
        (NvM_RamAddressType)&Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0290u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_RIDMgrVIN_CurrentVal  */ 
        (NvM_RamAddressType)&Rte_SWC_RIDMgr_VIN_CurrentVal_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        17u /*  NvMNvBlockLength  */ , 
        17u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_RIDMgrVIN_Lock  */ 
        (NvM_RamAddressType)&Rte_SWC_RIDMgr_VIN_Lock_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_RIDMgr_VIN_Lock_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0280u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_RIDMgrVIN_OdometerCnt  */ 
        (NvM_RamAddressType)&Rte_SWC_RIDMgr_VIN_OdometerCnt_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgr_vRoE_Activation_State  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgr_vRoE_Activation_State_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_191D_PowerLatch  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_191D_PowerLatch_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_200A_IgOnCounter  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_200A_IgOnCounter_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_200B_TimeSinceFirstDTC  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_200B_TimeSinceFirstDTC_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0300u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0310u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_200D_LastClearDTCOdo  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_200D_LastClearDTCOdo_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0320u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrECU_LifeTime  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrECU_LifeTime_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0340u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_ProxiConfigMgrProxiConfigTable  */ 
        (NvM_RamAddressType)&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_ProxiConfigMgrProxiConfigTable_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        SWC_ProxiConfigMgrProxiConfigTable_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0360u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_ProxiConfigMgrProxiErrorData  */ 
        (NvM_RamAddressType)&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_ProxiConfigMgrProxiErrorData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0370u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_2002_ProgReqFlag  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_2002_ProgReqFlag_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x02E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD33_MagnaTesting  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD33_MagnaTesting_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0330u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrDID_FD31_EOLCodingState  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrDID_FD31_EOLCodingState_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0350u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderSVSCamCurrentCalibData  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderSVSCamCurrentCalibData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderSVSCamCurrentCalibData_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0380u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderSVSCamEOLCalibData  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderSVSCamEOLCalibData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderSVSCamEOLCalibData_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0390u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderSVSCamOCCalibData  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderSVSCamOCCalibData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderSVSCamOCCalibData_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderSVSCamSCCalibData  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderSVSCamSCCalibData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderSVSCamSCCalibData_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_PartNumMgrUssSensorMarrData  */ 
        (NvM_RamAddressType)&Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_PartNumMgrUssSensorMarrData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD01_PrevCalibDataCopy  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD01_PrevCalibDataCopy_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD42_FailsafeDebug  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD42_FailsafeDebug_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_RearBrakeEvent  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_RearBrakeEvent_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x03F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_SPMAbrtEvent  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_SPMAbrtEvent_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0400u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_IPCHandlerFeatureAP_HMI_NvMData  */ 
        (NvM_RamAddressType)&Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_IPCHandlerFeatureAP_HMI_NvMData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0410u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_Mirror_Copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1_Mac /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0420u /*  NV block Base number (defined by FEE/EA)  */ , 
        488u /*  NvMNvBlockLength  */ , 
        488u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        16u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_MAC_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_Mirror_Copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2_Mac /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0430u /*  NV block Base number (defined by FEE/EA)  */ , 
        488u /*  NvMNvBlockLength  */ , 
        488u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        16u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_MAC_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD86_FunctionalSettings  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD86_FunctionalSettings_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0440u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_IPCHandlerFPA_SlotData  */ 
        (NvM_RamAddressType)&Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_IPCHandlerFPA_SlotData_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CDD_IPCHandlerFPA_SlotData_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0470u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Safety_GuardSafeStat2_ResetReason  */ 
        (NvM_RamAddressType)&Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Safety_GuardSafeStat2_ResetReason_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0480u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderFrontCamSerialNumber  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderFrontCamSerialNumber_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderFrontCamSerialNumber_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0490u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderLeftCamSerialNumber  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderLeftCamSerialNumber_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderLeftCamSerialNumber_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderRearCamSerialNumber  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_RearCamSerialNumber_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderRearCamSerialNumber_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderRearCamSerialNumber_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CalDataProviderRightCamSerialNumber  */ 
        (NvM_RamAddressType)&Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CalDataProvider_RightCamSerialNumber_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CalDataProviderRightCamSerialNumber_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        CalDataProviderRightCamSerialNumber_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_ON, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_ON, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SecondCounter  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SecondCounter_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        4u /*  NvMNvBlockLength  */ , 
        4u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_SystemTimestamp  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_SystemTimestamp_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        15u /*  NvMNvBlockLength  */ , 
        15u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_SafetyCDD_PMICLastResetReason_BISTStatus  */ 
        (NvM_RamAddressType)&Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_SafetyCDD_PMICLastResetReason_BISTStatus_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0500u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy) /*  NvMNvBlockLength  */ , 
        (uint16)sizeof(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy) /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        0u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired  */ 
        (NvM_RamAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x04F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD74_BuffMarkCompErr  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD74_BuffMarkCompErr_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0510u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DIDMgrDID_FD74_PHY_TuningErr  */ 
        (NvM_RamAddressType)&Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DIDMgrDID_FD74_PHY_TuningErr_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0520u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  SWC_DTCMgrDTC_APARequestSts_PAMRequestSts  */ 
        (NvM_RamAddressType)&Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SWC_DTCMgrDTC_APARequestSts_PAMRequestSts_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_PRE_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0530u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        1u /*  NvMacReference  */ , 
        1u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Ea /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }
    };

/* Permanent RAM and ROM block length checks - compile time (only available for blocks with enabled length check */

/* PRQA S 3494, 3213, 1755 BlockLengthChecks */ /* MD_NvM_Cfg_14.3, MD_NvM_Cfg_2.4 */

/* How does it work:
 * data length = sizeof(ramBlock - CrcLength 
 *     - CRC internal buffer enabled: CRC length == 0, RAM blocks store only data, CRC is handles internally
 *     - CRC internal buffer disabled: CRC length is the number of CRC bytes, for blocks without CRC the length == 0
 *     - for ROM blocks the CRC does not matter
 * Data length has to be > or < or == to configured NvM block length, depending on configuration (see above). 
 * In case the lengths do not match a bitfield with length -1 will be created and shall cause a compiler error.
 * The compiler error shall mark the line with invalid bitfield (bitfield length == -1) - the line includes all required information:
 *     - Block_ + NvM block name
 *     - length error description
 *     - RAM block name, CRC length and configured NvM block length
 */

typedef unsigned int NvM_LengthCheck;
 
/* Block Length Check and Automatic Block Length enabled: error if sizeof RAM block is greater than the configured block length */
#define SizeOfRamBlockGreaterThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) > (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof RAM block does not match the configured block length */
#define SizeOfRamBlockDoesNotMatchConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled and Strict Length Check disabled: error if the sizeof RAM block is less than the configured block length */
#define SizeOfRamBlockLessThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* RAM block length checks */
struct PermanentRamBlockLengthChecks {
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_MirrorBlock, 0u, 13u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_MirrorBlock, 0u, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock, 0u, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock, 0u, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_MirrorBlock, 0u, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_MirrorBlock, 0u, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_MirrorBlock, 0u, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock, 0u, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock, 0u, 2u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F110_Ecu_Diag_Info : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_MirrorBlock, 0u, 6u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2002_OdoFlashing : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock, 0u, 2u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_OriginalVal : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_OriginalVal_MirrorBlock, 0u, 17u);
  NvM_LengthCheck Block_NvM_Dem_ADMIN : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_AdminData, 0u, 12u);
  NvM_LengthCheck Block_NvM_Dem_Aging : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_AgingData, 0u, 132u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY0 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_0, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY1 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_1, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY2 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_2, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY3 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_3, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY4 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_4, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY5 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_5, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY6 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_6, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY7 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_7, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY8 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_8, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY9 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_9, 0u, 84u);
  NvM_LengthCheck Block_NvM_Dem_STATUS : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_StatusData, 0u, 76u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2939_WakeupReason : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_DIDMgr_DID_2939_WakeupReason_MirrorBlock, 0u, 20u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FDF0_SleepProcess : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrDID_5201_PlantModeStatus : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_CurrentVal : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_CurrentVal_MirrorBlock, 0u, 17u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_Lock : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_Lock_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_OdometerCnt : SizeOfRamBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_OdometerCnt_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgr_vRoE_Activation_State : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_191D_PowerLatch : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200A_IgOnCounter : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock, 0u, 2u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200B_TimeSinceFirstDTC : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock, 0u, 4u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock, 0u, 2u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200D_LastClearDTCOdo : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock, 0u, 2u);
  NvM_LengthCheck Block_SWC_DIDMgrECU_LifeTime : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock, 0u, 4u);
  NvM_LengthCheck Block_SWC_ProxiConfigMgrProxiConfigTable : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy, 0u, 66u);
  NvM_LengthCheck Block_SWC_ProxiConfigMgrProxiErrorData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy, 0u, 9u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2002_ProgReqFlag : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD33_MagnaTesting : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock, 0u, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_FD31_EOLCodingState : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock, 0u, 4u);
  NvM_LengthCheck Block_CalDataProviderSVSCamCurrentCalibData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy, 0u, 200u);
  NvM_LengthCheck Block_CalDataProviderSVSCamEOLCalibData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy, 0u, 200u);
  NvM_LengthCheck Block_CalDataProviderSVSCamOCCalibData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy, 0u, 100u);
  NvM_LengthCheck Block_CalDataProviderSVSCamSCCalibData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy, 0u, 100u);
  NvM_LengthCheck Block_SWC_PartNumMgrUssSensorMarrData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock, 0u, 56u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD01_PrevCalibDataCopy : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock, 0u, 192u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD42_FailsafeDebug : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_RearBrakeEvent : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock, 0u, 44u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_SPMAbrtEvent : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock, 0u, 56u);
  NvM_LengthCheck Block_CDD_IPCHandlerFeatureAP_HMI_NvMData : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy, 0u, 1u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD86_FunctionalSettings : SizeOfRamBlockGreaterThanConfiguredLength(Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock, 0u, 8u);
  NvM_LengthCheck Block_CalDataProviderFrontCamSerialNumber : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy, 0u, 10u);
  NvM_LengthCheck Block_CalDataProviderLeftCamSerialNumber : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy, 0u, 10u);
  NvM_LengthCheck Block_CalDataProviderRearCamSerialNumber : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy, 0u, 10u);
  NvM_LengthCheck Block_CalDataProviderRightCamSerialNumber : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy, 0u, 10u);
  NvM_LengthCheck Block_CDD_SafetyCDD_PMICLastResetReason_BISTStatus : SizeOfRamBlockGreaterThanConfiguredLength(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy, 0u, 2u);
};

/* Block Length Check and Automatic Block Length enabled: error if sizeof ROM block is less than sizeof RAM block */
#define SizeOfRomBlockLessThanSizeOfRamBlock(romBlock, ramBlock) ((sizeof(romBlock) < sizeof(ramBlock)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof ROM block does not match the configured block length */
#define SizeOfRomBlockDoesNotMatchConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled, Strict Length disabled: error if the sizeof ROM block is less than the configured block length */
#define SizeOfRomBlockLessThanConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* ROM block length checks */
struct PermRomBlockLengthCheck {
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue, 13u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue, 10u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue, 11u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue, 2u);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_F110_Ecu_Diag_Info : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue, 6u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2002_OdoFlashing : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue, Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_OriginalVal : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue, 17u);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY0 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_0);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY1 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_1);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY2 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_2);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY3 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_3);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY4 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_4);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY5 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_5);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY6 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_6);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY7 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_7);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY8 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_8);
  NvM_LengthCheck Block_NvM_Dem_PRIMARY9 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_9);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2939_WakeupReason : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue, 20u);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FDF0_SleepProcess : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrDID_5201_PlantModeStatus : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_CurrentVal : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue, 17u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_Lock : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_Lock_DefaultValue, 1u);
  NvM_LengthCheck Block_SWC_RIDMgrVIN_OdometerCnt : SizeOfRomBlockLessThanConfiguredLength(Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue, 1u);
  NvM_LengthCheck Block_SWC_DIDMgr_vRoE_Activation_State : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue, Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_191D_PowerLatch : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue, Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200A_IgOnCounter : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue, Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200B_TimeSinceFirstDTC : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue, Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue, Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_200D_LastClearDTCOdo : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue, Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrECU_LifeTime : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue, Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock);
  NvM_LengthCheck Block_SWC_ProxiConfigMgrProxiConfigTable : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue, Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy);
  NvM_LengthCheck Block_SWC_ProxiConfigMgrProxiErrorData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue, Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy);
  NvM_LengthCheck Block_SWC_DIDMgrDID_2002_ProgReqFlag : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue, Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD33_MagnaTesting : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue, Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock);
  NvM_LengthCheck Block_SWC_PartNumMgrDID_FD31_EOLCodingState : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue, Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock);
  NvM_LengthCheck Block_CalDataProviderSVSCamCurrentCalibData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue, Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderSVSCamEOLCalibData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue, Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderSVSCamOCCalibData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue, Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderSVSCamSCCalibData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue, Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy);
  NvM_LengthCheck Block_SWC_PartNumMgrUssSensorMarrData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue, Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD01_PrevCalibDataCopy : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue, Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD42_FailsafeDebug : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue, Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_RearBrakeEvent : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue, Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock);
  NvM_LengthCheck Block_SWC_DIDMgrDID_SPMAbrtEvent : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue, Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock);
  NvM_LengthCheck Block_CDD_IPCHandlerFeatureAP_HMI_NvMData : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue, Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy);
  NvM_LengthCheck Block_SWC_DIDMgrDID_FD86_FunctionalSettings : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue, Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock);
  NvM_LengthCheck Block_CalDataProviderFrontCamSerialNumber : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue, Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderLeftCamSerialNumber : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue, Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderRearCamSerialNumber : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_RearCamSerialNumber_DefaultValue, Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy);
  NvM_LengthCheck Block_CalDataProviderRightCamSerialNumber : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CalDataProvider_RightCamSerialNumber_DefaultValue, Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy);
  NvM_LengthCheck Block_CDD_SafetyCDD_PMICLastResetReason_BISTStatus : SizeOfRomBlockLessThanSizeOfRamBlock(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue, Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock_copy);
};

/* PRQA L:BlockLengthChecks */

/* Permanent RAM and ROM block length checks - END */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* Job Queue used for normal and immediate prio jobs */
VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**********************************************************************************************************************
*  NvM_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 enter SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void)
{
  /* do what ever was defined to do for locking the resources */
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
*  NvM_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 exit SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void)
{
  /* do what ever was defined to do for unlocking the resources */
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiBlockMode(serv, res) BswM_NvM_CurrentJobMode((serv),(res)) /*  if NvMBswMMultiBlockJobStatusInformation is TRUE  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiCbk(serv, res)   /*  if Multi Block Callback is configured  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeDetectedLossOfRedundancyCallback(blockId) NvM_LossOfRedundancyCbk((blockId))

/**********************************************************************************************************************
*  NvM_MultiBlockCbk
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 invoke the BSWM notification if any is configured
 *  - #20 in case the given job result isn't set to pending, invoke the multi block job end notification
 * \endinternal
 */
/* PRQA S 3206 1 */ /* MD_NvM_Cfg_2.7 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockCbk(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  /* The complete function body is designed to be optimized away by the compiler, if it is not needed    *
   * If the used macro is empty, the compiler may decide to remove code because it would contain         *
   * empty execution blocks (it does not matter whether conditions were TRUE or FALSE                    */
  NvM_invokeMultiBlockMode(ServiceId, JobResult);

  if(JobResult != NVM_REQ_PENDING)
  {
    NvM_invokeMultiCbk(ServiceId, JobResult);
  }   
}

/**********************************************************************************************************************
*  NvM_NotifyLossOfRedundancy
**********************************************************************************************************************/
/*!
 * \internal
 *  - invoke the notification callback if any is configured
 * \endinternal
 */
/* PRQA S 3206 1 */ /* MD_NvM_Cfg_2.7 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NotifyLossOfRedundancy(NvM_BlockIdType BlockId)
{
  NvM_invokeDetectedLossOfRedundancyCallback(BlockId);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* PRQA L:MemMap */

/* Justification for module specific MISRA deviations:

MD_NvM_Cfg_2.4
Reason: NvM provides compile time block length checks via structures with bitfields with positive or negative length -
        the negative length lead to compiler errors. It is possible to use == or even >= check, if only one is used,
        the other one will never be used. The macros are always available. The created structures will never be used by NvM.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_2.7:
Reason: The function NvM_MultiBlockCbk gets all needed parameters to invoke the BSWM and multi block job end callback.
        If both are disabled, the function is empty and does nothing - the passed parameters remain unused.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.9_InternalBuffer:
Reason: NvM uses an internal buffer for explicit synchronization, in internal CRC buffer use case and for repair redundant blocks.
        Depending on configuration all, one or even none of the uses is enabled - therefore sometimes the internal buffer is
        used only once.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.11:
Reason: Array of unknown size is used in order to reduce dependencies.
Risk: In case the array size shall be determined it would be incorrect.
Prevention: No prevention.

MD_NvM_Cfg_14.3:
Reason: NvM provides compile time block length checks via bitfields with positive or negative length - the negative length
        lead to compiler errors. With valid configuration (all block length are configured correctly), all checks are false.
Risk: No risk.
Prevention: No prevention. If needed the compile time checks can be disabled via configuration.

 */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.c
 *********************************************************************************************************************/


