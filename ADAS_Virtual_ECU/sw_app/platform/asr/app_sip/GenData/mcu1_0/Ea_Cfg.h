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
 *            Module: Ea
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ea_Cfg.h
 *   Generation Time: 2024-12-05 16:58:36
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**** Protection against multiple inclusion **************************************************************************/
#ifndef EA_CFG_H_PUBLIC
#define EA_CFG_H_PUBLIC

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
#ifndef EA_USE_DUMMY_STATEMENT
#define EA_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EA_DUMMY_STATEMENT
#define EA_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EA_DUMMY_STATEMENT_CONST
#define EA_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef EA_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define EA_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef EA_ATOMIC_VARIABLE_ACCESS
#define EA_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef EA_PROCESSOR_TDA4VE88
#define EA_PROCESSOR_TDA4VE88
#endif
#ifndef EA_COMP_LLVMTEXASINSTRUMENTS
#define EA_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef EA_GEN_GENERATOR_MSR
#define EA_GEN_GENERATOR_MSR
#endif
#ifndef EA_CPUTYPE_BITORDER_LSB2MSB
#define EA_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef EA_CONFIGURATION_VARIANT_PRECOMPILE
#define EA_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef EA_CONFIGURATION_VARIANT_LINKTIME
#define EA_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef EA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define EA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef EA_CONFIGURATION_VARIANT
#define EA_CONFIGURATION_VARIANT EA_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef EA_POSTBUILD_VARIANT_SUPPORT
#define EA_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
#define EA_CFG_MAJOR_VERSION	(5u) 
#define EA_CFG_MINOR_VERSION	(3u) 

/**** Pre-compile switches for EA development error checks ***********************************************************/

#define EA_DEV_ERROR_DETECT              (STD_ON)

/* EA_DEV_ERROR_REPORT is always set to STD_OFF if DEV_ERROR_DETECT is disabled */
#define EA_DEV_ERROR_REPORT              (STD_ON)

/***** Optional API functions **************************************************************************************/

#define EA_VERSION_INFO_API              (STD_OFF)
#define EA_SETMODE_API                   (STD_ON)

/**** Symbolic block names **************************************************************************/
  
#define EaConf_EaBlockConfiguration_EaBlockConfiguration                                         16u 
#define EaConf_EaBlockConfiguration_EaBlockDem_AdminData                                         32u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Aging                                             48u 
#define EaConf_EaBlockConfiguration_EaBlockDem_EventStatus                                       64u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary0                                          80u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary1                                          96u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary2                                          112u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary3                                          128u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary4                                          144u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary5                                          160u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary6                                          176u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary7                                          192u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary8                                          208u 
#define EaConf_EaBlockConfiguration_EaBlockDem_Primary9                                          224u 
#define EaConf_EaBlockConfiguration_EaSWC_vRoE_Activation_State                                  240u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_ApplValidity                               256u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_2002_OdoFlashing                       272u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_2010_ProgrammingStatus                 288u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F110_Ecu_Diag_Id_FlashDefinitionNumber 304u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F132_EBOM_Ecu_PartNum                  320u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F133_EBOM_Asm_PartNum                  336u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F134_CODEP_Asm_PartNum                 352u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F180_Boot_SW_Ver_Info                  368u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F187_CODEP_Ecu_PartNum                 384u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F188_FCA_ESLM_Ecu_SW_Num               400u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num           416u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F18B_FCA_ESLM_ECU_SW_App_Num           432u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F194_Supplier_Ecu_SW_PartNum           448u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DID_F195_Supplier_Ecu_SW_VerNum            464u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_DcmDslRxTesterSourceAddr                   480u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_ExhaustRegulationTan                       496u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_MetaData                                   512u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_ResetResponseFlag                          528u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_SecAccessDelayFlag                         544u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_SecAccessInvalidCount                      560u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_ValidityFlags                              576u 
#define EaConf_EaBlockConfiguration_EaBlock_ApplUpdate                                           592u 
#define EaConf_EaBlockConfiguration_EaCDD_GenericBswDID_2939_WakeupReason                        608u 
#define EaConf_EaBlockConfiguration_EaCDD_GenericBswDID_FDF0_SleepProcess                        624u 
#define EaConf_EaBlockConfiguration_EaSWC_ConfigMgrDID_2013_VIN_Lock_Status                      640u 
#define EaConf_EaBlockConfiguration_EaSWC_ConfigMgrDID_5201_PlantMode                            656u 
#define EaConf_EaBlockConfiguration_EaSWC_ConfigMgrVIN_CurrentVal                                672u 
#define EaConf_EaBlockConfiguration_EaSWC_ConfigMgrVIN_OdometerCnt                               688u 
#define EaConf_EaBlockConfiguration_EaSWC_ConfigMgrVIN_OriginalVal                               704u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_191D_PowerLatch                              720u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_2002_ProgReqFlag                             736u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_200A_IgOnCounter                             752u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_200B_TimeSinceFirstDTC                       768u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_200C_TimeSinceIgnOnFirstDTC                  784u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_200D_LastClearDTCOdo                         800u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD33_MagnaTesting                            816u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrECU_LifeTime                                     832u 
#define EaConf_EaBlockConfiguration_EaSWC_PartNumMgrDID_FD31_EOLCodingState                      848u 
#define EaConf_EaBlockConfiguration_EaSWC_ProxiMgrProxiConfigTable                               864u 
#define EaConf_EaBlockConfiguration_EaSWC_ProxiMgrProxiErrorData                                 880u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderSVSCamCurrentCalibData                      896u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderSVSCamEOLCalibData                          912u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderSVSCamOCCalibData                           928u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderSVSCamSCCalibData                           944u 
#define EaConf_EaBlockConfiguration_EaSWC_PartNumMgrUssSensorMarrData                            960u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD01_PrevCalibDataCopy                       976u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD42_FailsafeDebug                           992u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_RearBrakeEvent                               1008u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_SPMAbrtEvent                                 1024u 
#define EaConf_EaBlockConfiguration_EaCDD_IPCHandlerFeatureAP_HMI_NvMData                        1040u 
#define EaConf_EaBlockConfiguration_EaBlockConfiguration_SecureLogGroup1                         1056u 
#define EaConf_EaBlockConfiguration_EaBlockConfiguration_SecureLogGroup2                         1072u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD86_FunctionalSettings                      1088u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_FileHeader                                 1104u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_SerialNumber                               1120u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_CDD_IPCHandlerFPA_SlotData                   1136u 
#define EaConf_EaBlockConfiguration_EaSafety_GuardSafeStat2_ResetReason                          1152u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderFrontCamSerialNumber                        1168u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderLeftCamSerialNumber                         1184u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderRearCamSerialNumber                         1200u 
#define EaConf_EaBlockConfiguration_EaCalDataProviderRightCamSerialNumber                        1216u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_SecondCounter                              1232u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_SystemTimestamp                            1248u 
#define EaConf_EaBlockConfiguration_EaBlockDescriptor_CertificateExpired                         1264u 
#define EaConf_EaBlockConfiguration_EaCDD_SafetyCDD_PMICLastResetReason_BISTStatus               1280u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD74_BuffMarkCompErr                         1296u 
#define EaConf_EaBlockConfiguration_EaSWC_DIDMgrDID_FD74_PHY_TuningErr                           1312u 
#define EaConf_EaBlockConfiguration_EaSWC_DTCMgrDTC_APARequestSts_PAMRequestSts                  1328u 


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef uint32 Ea_AddressType;
typedef P2VAR(uint8, AUTOMATIC, EA_APPL_DATA) Ea_DataBufferPtrType;
typedef P2CONST(uint8, AUTOMATIC, EA_APPL_DATA) Ea_ConstDataBufferPtrType;

/**********************************************************************************************************************
 *  MODULE RELEVANT CONFIGURATION
 *********************************************************************************************************************/
 
#ifdef EA_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define EA_LAYER_ONE_INDEX                                   (0x00U)
#define EA_LAYER_TWO_INDEX                                   (0x01U)
#define EA_LAYER_THREE_INDEX                                 (0x02U)

/****  EEP Configuration *********************************************************************************************/

#define EA_NUMBER_OF_EEP_DEVICES                             (1u)

/****  EA Configuration **********************************************************************************************/

#define EA_EEP_POLLING_MODE                                  (STD_ON)
#define EA_CORRECT_SINGLE_BIT_FLIPS                          (STD_ON)

#define EA_MANAGEMENT_SIZE                                   (1U)
#define EA_NUMBER_OF_PARTITIONS                              (5u)
#define EA_NUMBER_OF_BLOCKS                                  (83u)
#define EA_MAX_WRITE_ALIGNMENT                               (1u)
#define EA_MAX_READ_ALIGNMENT                                (1u)

/****  NVM Interface **************************************************************************************************/

#define EA_NVM_POLLING_MODE                                  (STD_ON)




/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
  
/* Function pointer prototypes for EEP API services */

typedef P2FUNC(Std_ReturnType, EA_PRIVATE_CODE, Ea_ReadPtrType)(Ea_AddressType EepAddress, Ea_DataBufferPtrType TargetAddressPtr, uint16 Length);
typedef P2FUNC(Std_ReturnType, EA_PRIVATE_CODE, Ea_WritePtrType)(Ea_AddressType EepAddress, Ea_DataBufferPtrType SourceAddressPtr, uint16 Length);
typedef P2FUNC(Std_ReturnType, EA_PRIVATE_CODE, Ea_ComparePtrType)(Ea_AddressType EepAddress, Ea_DataBufferPtrType DataBufferPtr, uint16 Length);
typedef P2FUNC(Std_ReturnType, EA_PRIVATE_CODE, Ea_ErasePtrType)(Ea_AddressType EepAddress, uint16 Length);
typedef P2FUNC(void, EA_PRIVATE_CODE, Ea_CancelPtrType)(void);
typedef P2FUNC(MemIf_StatusType, EA_PRIVATE_CODE, Ea_GetStatusPtrType)(void);
typedef P2FUNC(MemIf_JobResultType, EA_PRIVATE_CODE, Ea_GetJobResultPtrType)(void);
typedef P2FUNC(void, EA_PRIVATE_CODE, Ea_SetModePtrType)(MemIf_ModeType Mode);

typedef struct
{
	Ea_ReadPtrType Read;
	Ea_WritePtrType Write;
	Ea_ComparePtrType Compare;
	Ea_ErasePtrType Erase;
	Ea_CancelPtrType Cancel;
	Ea_GetStatusPtrType GetStatus;
	Ea_GetJobResultPtrType GetJobResult;
	Ea_SetModePtrType SetMode;
} Ea_EepApiType;

typedef P2CONST(Ea_EepApiType, AUTOMATIC, EA_APPL_DATA) Ea_EepApiPtrType;
  
typedef struct
{
    Ea_AddressType PartitionStartAddress;
    uint16 PartitionAddressAlignment;
    uint16 PartitionWriteAlignment;
    uint16 PartitionReadAlignment;
    uint16 EepDeviceIndex;
    Ea_EepApiPtrType EepApiPtr;
    uint8 EepEraseValue;
} Ea_PartitionConfigType;

typedef struct
{
    Ea_AddressType BlockStartAddress;
    uint16 DataLength;
    uint16 PartitionIndex;
    uint8 NumberOfInstances;
    uint8 NumberOfDatasets;
    boolean IsImmediateData;
    boolean HasVerificationEnabled;
} Ea_BlockConfigType;


/* Function pointer prototypes NvM callback routines */

typedef P2FUNC(void, EA_NVM_CODE, Ea_CbkJobEndNotificationType)(void);
typedef P2FUNC(void, EA_NVM_CODE, Ea_CbkJobErrorNotificationType)(void);

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define EA_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, EA_PRIVATE_CONST) Ea_DatasetSelectionBits;

#define EA_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define EA_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */
  
extern CONST(Ea_PartitionConfigType, EA_PRIVATE_CONST) Ea_PartitionConfigList[EA_NUMBER_OF_PARTITIONS];
extern CONST(Ea_BlockConfigType, EA_PRIVATE_CONST) Ea_BlockConfigList[EA_NUMBER_OF_BLOCKS];
extern CONST(Ea_EepApiType, EA_PRIVATE_CONST) Ea_EepApi0; 


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Function pointers to the callback routines of the NvM. */
extern CONST(Ea_CbkJobEndNotificationType, EA_PRIVATE_CONST) Ea_CbkJobEndNotification;
extern CONST(Ea_CbkJobErrorNotificationType, EA_PRIVATE_CONST) Ea_CbkJobErrorNotification;

#define EA_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* #ifdef EA_IMPLEMENTATION_SOURCE */

#endif /* EA_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: Ea_Cfg.h
 *********************************************************************************************************************/
 
