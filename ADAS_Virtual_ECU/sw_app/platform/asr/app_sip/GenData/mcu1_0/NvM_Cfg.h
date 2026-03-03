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
 *              File: NvM_Cfg.h
 *   Generation Time: 2024-12-05 17:00:18
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (9u)
#define NVM_CFG_MINOR_VERSION    (2u)
#define NVM_CFG_PATCH_VERSION    (0u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID (see CompiledConfigurationId in NvM.h). */
/* Compiled Config Id Type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_Union */
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_OFF)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_OFF)

#define NVM_API_CONFIG_CLASS_1                (1u)
#define NVM_API_CONFIG_CLASS_2                (3u)
#define NVM_API_CONFIG_CLASS_3                (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (5u)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for data integrity handling */
#define NVM_DATA_INTEGRITY_INT_BUFFER         (STD_ON)

/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS         (84u)

/* internal buffer size */
#define NVM_INTERNAL_BUFFER_LENGTH            504u

/* internal immediate data buffer size */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER_LENGTH  68u

/* version info api switch */
#define NVM_VERSION_INFO_API                  (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API          (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_ON)

/* switch to enable the pre readall api to be able to split the readall into two phases */
#define NVM_PRE_READALL_API                   (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS            (4u)

/* switch for enabling the job forwading from the application to the memory core */
#define  NVM_JOB_FORWARDING_TO_MEMORY_CORE    (STD_OFF) 

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET                  0x8000u

/* Enabled if at least one block used NvMCalcRamblockCrc and ExplicitSync mechanisms */
#define NVM_CRC_USE_INTERNAL_EXPLICIT_SYNC_BUFFER (STD_OFF)


/* Enabled if at least one block used immediate data */
#define NVM_INTERNAL_IMMEDIATE_DATA_BUFFER  (STD_ON)

/* returns corresponding DCM BlockId of an original NVRAM Block */
#define NvM_GetDcmBlockId(MyApplBlockId)      ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptorTable_at
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf___MultiBlockRequest (0u) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ApplUpdate (2u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecAccessDelayFlag (3u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecAccessInvalidCount (4u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ApplValidity (5u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DcmDslRxTesterSourceAddr (6u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ValidityFlags (7u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ExhaustRegulationTan (8u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_ResetResponseFlag (9u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F180_Boot_SW_Ver_Info (10u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_2010_ProgrammingStatus (11u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_MetaData (12u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_FileHeader (13u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_CertAccessInfo (14u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F188_FCA_ESLM_Ecu_SW_Num (15u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F133_EBOM_Asm_PartNum (16u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F18A_FCA_ESLM_Ecu_SW_Cal_Num (17u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F18B_FCA_ESLM_ECU_SW_App_Num (18u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F187_CODEP_Ecu_PartNum (19u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F134_CODEP_Asm_PartNum (20u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F132_EBOM_Ecu_PartNum (21u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F194_Supplier_Ecu_SW_PartNum (22u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F195_Supplier_Ecu_SW_VerNum (23u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_F110_Ecu_Diag_Info (24u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_2002_OdoFlashing (25u) 
#define NvMConf_NvMBlockDescriptor_SWC_RIDMgrVIN_OriginalVal (26u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_ADMIN (27u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_Aging (28u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY0 (29u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY1 (30u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY2 (31u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY3 (32u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY4 (33u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY5 (34u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY6 (35u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY7 (36u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY8 (37u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_PRIMARY9 (38u) 
#define NvMConf_NvMBlockDescriptor_NvM_Dem_STATUS (39u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_2939_WakeupReason (40u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FDF0_SleepProcess (41u) 
#define NvMConf_NvMBlockDescriptor_SWC_RIDMgrDID_5201_PlantModeStatus (42u) 
#define NvMConf_NvMBlockDescriptor_SWC_RIDMgrVIN_CurrentVal (43u) 
#define NvMConf_NvMBlockDescriptor_SWC_RIDMgrVIN_Lock (44u) 
#define NvMConf_NvMBlockDescriptor_SWC_RIDMgrVIN_OdometerCnt (45u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgr_vRoE_Activation_State (46u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_191D_PowerLatch (47u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_200A_IgOnCounter (48u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_200B_TimeSinceFirstDTC (49u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC (50u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_200D_LastClearDTCOdo (51u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrECU_LifeTime (52u) 
#define NvMConf_NvMBlockDescriptor_SWC_ProxiConfigMgrProxiConfigTable (53u) 
#define NvMConf_NvMBlockDescriptor_SWC_ProxiConfigMgrProxiErrorData (54u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_2002_ProgReqFlag (55u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD33_MagnaTesting (56u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrDID_FD31_EOLCodingState (57u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamCurrentCalibData (58u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamEOLCalibData (59u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamOCCalibData (60u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamSCCalibData (61u) 
#define NvMConf_NvMBlockDescriptor_SWC_PartNumMgrUssSensorMarrData (62u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD01_PrevCalibDataCopy (63u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD42_FailsafeDebug (64u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_RearBrakeEvent (65u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_SPMAbrtEvent (66u) 
#define NvMConf_NvMBlockDescriptor_CDD_IPCHandlerFeatureAP_HMI_NvMData (67u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup1 (68u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecureLogGroup2 (69u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD86_FunctionalSettings (70u) 
#define NvMConf_NvMBlockDescriptor_CDD_IPCHandlerFPA_SlotData (71u) 
#define NvMConf_NvMBlockDescriptor_Safety_GuardSafeStat2_ResetReason (72u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderFrontCamSerialNumber (73u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderLeftCamSerialNumber (74u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderRearCamSerialNumber (75u) 
#define NvMConf_NvMBlockDescriptor_CalDataProviderRightCamSerialNumber (76u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SecondCounter (77u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_SystemTimestamp (78u) 
#define NvMConf_NvMBlockDescriptor_CDD_SafetyCDD_PMICLastResetReason_BISTStatus (79u) 
#define NvMConf_NvMBlockDescriptor_CDD_CryptoMgrNvMBlockDescriptor_CertificateExpired (80u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD74_BuffMarkCompErr (81u) 
#define NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD74_PHY_TuningErr (82u) 
#define NvMConf_NvMBlockDescriptor_SWC_DTCMgrDTC_APARequestSts_PAMRequestSts (83u) 


/* CONST_DESCRIPTOR_TABLE contains all block relevant data, including the compiled config ID
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t; /* PRQA S 0759 */ /* MD_MSR_Union */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_TDA4VE88
#define NVM_PROCESSOR_TDA4VE88
#endif
#ifndef NVM_COMP_LLVMTEXASINSTRUMENTS
#define NVM_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/* PRQA L:MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.h
 *********************************************************************************************************************/

