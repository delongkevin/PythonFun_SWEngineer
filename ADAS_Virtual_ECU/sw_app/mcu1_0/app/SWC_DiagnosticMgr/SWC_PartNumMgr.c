/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PartNumMgr.c
 *           Config:  D:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_PartNumMgr
 *  Generation Time:  2023-10-12 15:37:11
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PartNumMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SSM_ApplicationStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_ApplicationStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_CoreSlaveCoreStateDef
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_CoreSlaveCoreStateDef
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_DegradedState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * SSM_SystemStateDef
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PartNumMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_PartNumMgr.h"
#include "vstdlib.h"
#include "Enums.h"
#include "ipc_manager.h"
#include "SSM_Slave.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "SSM_BSW_Interface.h"

static metaData_t s_MetaData_Arr_as[e_TEN];
static uint8 s_MetaArrayCounter_u8 = (uint8)e_ZERO;
static uint8 s_DID_22F122_SW_EBOM_PartNum_au8[D_DID_F122_DATA_LEN];             /* Buffer for F122 */
static uint8 s_DID_22F180_BootSWVerInfoDefaultValue_au8[D_DID_F180_DATA_LEN];   /* Buffer for F180 */
static uint8 s_DID_22F181_AppSWVersionInfo_au8[D_DID_F181_DATA_LEN];            /* Buffer for F181 */
static uint8 s_DID_22F182_AppDataSWVersionInfo_au8[D_DID_F182_DATA_LEN];        /* Buffer for F182 */
static uint8 s_DID_22F1B3_BOOT_SW_Fingerprint_au8[e_THIRTEEN];                  /* Buffer for F1B3 */
static uint8 s_DID_22F1B4_AppSW_Fingerprint_au8[e_SIXTY_FIVE];                  /* Buffer for F1B4 */
static uint8 s_DID_22F1B5_AppDataSW_Fingerprint_au8[e_THIRTY_NINE];             /* Buffer for F1B5 */
static uint8 s_DID_222003_BootSW_ProgAttmptCntr_au8[e_TWO];                     /* Buffer for 2003 */
static uint8 s_DID_22201A_AppSW_ProgAttmptCntr_au8[e_TEN];                      /* Buffer for 201A */
static uint8 s_DID_22201B_AppDataSW_ProgAttmptCntr_au8[e_SIX];                  /* Buffer for 201B */


static const uint8 s_Varify_EOL_Marker_Data_au8[e_FOUR] = {D_EOL_MARKER_DATA};
static const uint8 s_LogicalBlock_MaxDurance_au8[e_TWO] = {D_LOGICALBLOCK_MAXENDURANCE};


static boolean v_UssMarrDataFlag_b = FALSE;

static SSM_SystemStateDef previous_SystemState = SSM_STATE_MAX;
static void f_Send_USSData_mcu2_1_v(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * NvM_RequestResultType: Integer in interval [0...8]
 * NvM_ServiceIdType: Integer in interval [6...12]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * DID_F110_Pin_Arr: Array with 6 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data11ByteType: Array with 11 element(s) of type uint8
 * Dcm_Data12ByteType: Array with 12 element(s) of type uint8
 * Dcm_Data13ByteType: Array with 13 element(s) of type uint8
 * Dcm_Data14ByteType: Array with 14 element(s) of type uint8
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data16ByteType: Array with 16 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data32ByteType: Array with 32 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data40ByteType: Array with 40 element(s) of type uint8
 * Dcm_Data43ByteType: Array with 43 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data64ByteType: Array with 64 element(s) of type uint8
 * Dcm_Data66ByteType: Array with 66 element(s) of type uint8
 * Dcm_Data71ByteType: Array with 71 element(s) of type uint8
 * Dcm_Data90ByteType: Array with 90 element(s) of type uint8
 * SSM_MCU_1_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * VINlData_Arr: Array with 17 element(s) of type uint8
 * rev_arr: Array with 2 element(s) of type uint8
 * uSavedSensorIDs_au32: Array with 12 element(s) of type uint32
 * uUSSPartNumPDC_FIL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_FIR_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_FOL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_FOR_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_RIL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_RIR_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_ROL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_ROR_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_RSL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPDC_RSR_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPSM_FSL_arr: Array with 13 element(s) of type uint8
 * uUSSPartNumPSM_FSR_arr: Array with 13 element(s) of type uint8
 *
 * Record Types:
 * =============
 * SSM_1_0_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_1_0_LocalAppStatus_Arr
 * SSM_2_0_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_0_LocalAppStatus_Arr
 * SSM_2_1_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_1_LocalAppStatus_Arr
 * SSM_QNX_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_QNX_LocalAppStatus_Arr
 * SSM_SystemState: Record with elements
 *   SystemState of type SSM_SystemStateDef
 *   DegradedState of type SSM_DegradedState
 * US_S_MarriageSensorIDs_t: Record with elements
 *   bValid of type boolean
 *   uMarriageStatus of type uint32
 *   uSavedSensorIDs of type uSavedSensorIDs_au32
 * US_S_SnrIMESerialNum_t: Record with elements
 *   uSnrIMESerialNum_FSR of type uint32
 *   uSnrIMESerialNum_FOR of type uint32
 *   uSnrIMESerialNum_FIR of type uint32
 *   uSnrIMESerialNum_FIL of type uint32
 *   uSnrIMESerialNum_FOL of type uint32
 *   uSnrIMESerialNum_FSL of type uint32
 *   uSnrIMESerialNum_RSR of type uint32
 *   uSnrIMESerialNum_ROR of type uint32
 *   uSnrIMESerialNum_RIR of type uint32
 *   uSnrIMESerialNum_RIL of type uint32
 *   uSnrIMESerialNum_ROL of type uint32
 *   uSnrIMESerialNum_RSL of type uint32
 * US_S_SnrMurataSerialNum_t: Record with elements
 *   uSnrMurataSerialNum_FSR of type uint64
 *   uSnrMurataSerialNum_FOR of type uint64
 *   uSnrMurataSerialNum_FIR of type uint64
 *   uSnrMurataSerialNum_FIL of type uint64
 *   uSnrMurataSerialNum_FOL of type uint64
 *   uSnrMurataSerialNum_FSL of type uint64
 *   uSnrMurataSerialNum_RSR of type uint64
 *   uSnrMurataSerialNum_ROR of type uint64
 *   uSnrMurataSerialNum_RIR of type uint64
 *   uSnrMurataSerialNum_RIL of type uint64
 *   uSnrMurataSerialNum_ROL of type uint64
 *   uSnrMurataSerialNum_RSL of type uint64
 * US_S_USSConstantData_t: Record with elements
 *   SensorPartNum of type US_S_USSPartNumberData_t
 *   SensorIMESerialNum of type US_S_SnrIMESerialNum_t
 *   SensorMurataSerialNum of type US_S_SnrMurataSerialNum_t
 *   USS_Ver of type US_S_USSVersion_t
 * US_S_USSPartNumberData_t: Record with elements
 *   uUSSPartNum_FSR of type uUSSPartNumPSM_FSR_arr
 *   uUSSPartNum_FOR of type uUSSPartNumPDC_FOR_arr
 *   uUSSPartNum_FIR of type uUSSPartNumPDC_FIR_arr
 *   uUSSPartNum_FIL of type uUSSPartNumPDC_FIL_arr
 *   uUSSPartNum_FOL of type uUSSPartNumPDC_FOL_arr
 *   uUSSPartNum_FSL of type uUSSPartNumPSM_FSL_arr
 *   uUSSPartNum_RSR of type uUSSPartNumPDC_RSR_arr
 *   uUSSPartNum_ROR of type uUSSPartNumPDC_ROR_arr
 *   uUSSPartNum_RIR of type uUSSPartNumPDC_RIR_arr
 *   uUSSPartNum_RIL of type uUSSPartNumPDC_RIL_arr
 *   uUSSPartNum_ROL of type uUSSPartNumPDC_ROL_arr
 *   uUSSPartNum_RSL of type uUSSPartNumPDC_RSL_arr
 * US_S_USSVersion_t: Record with elements
 *   US_CalVer of type uint32
 *   US_SnrVer of type uint16
 *   US_ModuleVer_YEAR of type uint8
 *   US_ModuleVer_WEEK of type uint8
 *   US_ModuleVer_DAY of type uint8
 *   US_ModuleVer_BUILD of type uint8
 *   Rsv of type rev_arr
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_DID_F110_Ecu_Diag_Info_MirrorBlock(void)
 *     Returnvalue: uint8* is of type DID_F110_Pin_Arr
 *   uint8 *Rte_Pim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_Pim_DID_F133_EBOM_Asm_PartNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_Pim_DID_F134_CODEP_Asm_PartNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_Pim_DID_F180_Boot_SW_Ver_Info_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data13ByteType
 *   uint8 *Rte_Pim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_Pim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_Pim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_Pim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_Pim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_Pim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data2ByteType
 *   uint8 *Rte_Pim_DID_FD31_EOLCodingState_MirrorBlock(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   US_S_MarriageSensorIDs_t *Rte_Pim_UssSensorMarrData_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_DID_F110_Ecu_Diag_Info_DefaultValue(void)
 *     Returnvalue: uint8* is of type DID_F110_Pin_Arr
 *   uint8 *Rte_CData_DID_F132_EBOM_Ecu_PartNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_CData_DID_F133_EBOM_Asm_PartNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_CData_DID_F134_CODEP_Asm_PartNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_CData_DID_F180_Boot_SW_Ver_Info_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data13ByteType
 *   uint8 *Rte_CData_DID_F187_CODEP_Ecu_PartNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_CData_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_CData_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_CData_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data10ByteType
 *   uint8 *Rte_CData_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data11ByteType
 *   uint8 *Rte_CData_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data2ByteType
 *   uint8 *Rte_CData_DID_FD31_EOLCodingState_DefaultValue(void)
 *     Returnvalue: uint8* is of type Dcm_Data4ByteType
 *   US_S_MarriageSensorIDs_t *Rte_CData_UssSensorMarrData_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define SWC_PartNumMgr_START_SEC_CODE
#include "SWC_PartNumMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_DCM_E_PENDING
 *   RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16970362, 16970318, 16970381, 16970394*/
 /*GUID:-*/
  /* DD-ID: {14E01B8F-3C70-498e-B79D-AE899BD143E5}*/
  Std_ReturnType v_retVal_u8;
  uint16 v_tempCount_u16;

  if (NULL_PTR != Data)
  {
     /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_2003_DATA_LEN);

    v_tempCount_u16 = s_DID_222003_BootSW_ProgAttmptCntr_au8[e_ZERO];
    v_tempCount_u16 |= (uint16)s_DID_222003_BootSW_ProgAttmptCntr_au8[e_ONE] << (uint8)e_EIGHT;
    v_tempCount_u16 = D_Invert16Bit(v_tempCount_u16);
    /*logical block 0:- No of prog attempt counter */
    VStdLib_MemCpy(&Data[e_ZERO],&v_tempCount_u16,(uint8) e_TWO);
    /* Send max no of programming attempts for logical block 0*/
    VStdLib_MemCpy(&Data[e_TWO],&s_LogicalBlock_MaxDurance_au8,(uint8) e_TWO);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_222003_Boot_Software_Programming_Attempt_Counter_E_NOT_OK;
  }
  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16303311,16303289,16303325,16303339,16303346 */
  /*GUID:-*/
  /* DD-ID: {95B1B55E-17DC-428c-9D9B-F3820F84F41F}*/
  Std_ReturnType v_retVal_u8; 
  uint16 v_tempCount_u16;
  uint8 v_iCount_u8;
  static uint8 s_iBlockCount_u8  = (uint8)e_ZERO;

 /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, DID_201A_SIZE_LEN);

    for(v_iCount_u8=(uint8)e_ZERO;v_iCount_u8<(uint8)e_TEN;v_iCount_u8+=(uint8)e_TWO)
    {
      v_tempCount_u16 = s_DID_22201A_AppSW_ProgAttmptCntr_au8[v_iCount_u8];
      v_tempCount_u16 |= (uint16)s_DID_22201A_AppSW_ProgAttmptCntr_au8[v_iCount_u8 + (uint8)e_ONE] << (uint8)e_EIGHT;
      v_tempCount_u16 = D_Invert16Bit(v_tempCount_u16);   
      VStdLib_MemCpy(&Data[s_iBlockCount_u8],&v_tempCount_u16,(uint8)e_TWO);  
      VStdLib_MemCpy(&Data[s_iBlockCount_u8 + (uint8)e_TWO],&s_LogicalBlock_MaxDurance_au8,(uint8) e_TWO);
      s_iBlockCount_u8 += (uint8)e_FOUR;
    }
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_E_NOT_OK;
  }
  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data12ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22201B_Application_Data_Software_Programming_Attempt_Counter_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16970172,16970334,16970207,16970246*/
  /*GUID:*/
  /* DD-ID: {46F796B6-F677-486e-B886-D390E657C37A}*/
  Std_ReturnType v_retVal_u8; 
  uint16 v_tempCount_u16;
  uint8 v_iCount_u8;
  static uint8 s_iBlockCount_u8  = (uint8)e_ZERO;

 /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
     /* flush Data pointer */
    VStdLib_MemClr(Data, DID_201B_SIZE_LEN);

    for(v_iCount_u8=(uint8)e_ZERO;v_iCount_u8<(uint8)e_SIX;v_iCount_u8+=(uint8)e_TWO)
    {
      v_tempCount_u16 = s_DID_22201B_AppDataSW_ProgAttmptCntr_au8[v_iCount_u8];
      v_tempCount_u16 |= (uint16)s_DID_22201B_AppDataSW_ProgAttmptCntr_au8[v_iCount_u8 + (uint8)e_ONE] << (uint8)e_EIGHT;
      v_tempCount_u16 = D_Invert16Bit(v_tempCount_u16);   
      VStdLib_MemCpy(&Data[s_iBlockCount_u8],&v_tempCount_u16,(uint8)e_TWO);  
      VStdLib_MemCpy(&Data[s_iBlockCount_u8 + (uint8)e_TWO],&s_LogicalBlock_MaxDurance_au8,(uint8) e_TWO);
      s_iBlockCount_u8 += (uint8)e_FOUR;
    }
    
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22201A_Application_Software_Programming_Attempt_Counter_E_NOT_OK;
  }
  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F10D_Diagnostic_Specification_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F10D_Diagnostic_Specification_Information_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 15338018,15212997,15213989,15214039 */

  /* DD-ID: {77E9168D-9EB6-4132-933E-443338BC60A9}*/
  Std_ReturnType v_retValue_u8;
 const uint8 v_diagnosticSpecInfo_au8[D_DID_F10D_DATA_LEN]={D_F10D_DIAGSPEC_INFO};

  if(NULL_PTR != Data)
  {
    /* Send Diagnostic Specification Information */
    VStdLib_MemCpy(Data,v_diagnosticSpecInfo_au8,D_DID_F10D_DATA_LEN);
    v_retValue_u8 = RTE_E_OK;
  }
  else
  {
    v_retValue_u8 = RTE_E_DataServices_Data_22F10D_Diagnostic_Specification_Information_E_NOT_OK;
  }
  return v_retValue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F110_ECU_Diagnostic_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F110_ECU_Diagnostic_Identification_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {8903F2F0-15BE-4bb1-AFF6-899B1C9667D7}*/
  /* ReqID:- 15215749,15215752,15229654 */
  Std_ReturnType v_retVal_u8;
  const uint8 v_ecuDiagVar_au8[e_TWO]={D_F110_ECU_DIAG_VAR};
  const uint8 v_ecuSupplierID_au8[e_TWO]={D_F110_SUPPLIER_ID_MAGNA};

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Set ECU Diagnostic Variant */
    VStdLib_MemCpy(&Data[e_ZERO],v_ecuDiagVar_au8,(uint8)e_TWO);
    /* Send ECU Diagnostic Identification */
    VStdLib_MemCpy(&Data[e_TWO], Rte_Pim_DID_F110_Ecu_Diag_Info_MirrorBlock(), D_DID_F110_DATA_LEN);
    /* Set ECU Supplier ID */
    VStdLib_MemCpy(&Data[e_EIGHT],v_ecuSupplierID_au8,(uint8)e_TWO);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F110_ECU_Diagnostic_Identification_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F112_PTESLM_Hardware_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F112_PTESLM_Hardware_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F112_PTESLM_Hardware_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F112_PTESLM_Hardware_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {8CC507C3-5128-4152-9963-0A3302CC61C8}*/
  /* ReqID:- 16081823,16081820,16081826 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8,(uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send PT ESLM Hardware Number Data */
    VStdLib_MemCpy(Data, D_PT_ESLM_HARDWARE_NUMBER_ADDRESS, D_DID_F112_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F112_PTESLM_Hardware_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F122_Software_EBOM_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data90ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F122_Software_EBOM_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F122_Software_EBOM_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F122_Software_EBOM_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {DF6695FF-C56F-456f-B2CC-A2A34660CA32}*/
  /* ReqID:- 15342844,15227366,15224836,15229691 */
   Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send Software EBOM Part Number */
    VStdLib_MemCpy(&Data[e_ZERO], &s_DID_22F122_SW_EBOM_PartNum_au8[e_ZERO], (uint8)e_TEN);

    VStdLib_MemCpy(&Data[e_TEN], &s_DID_22F122_SW_EBOM_PartNum_au8[e_FORTY], (uint8)e_FIFTY);

    VStdLib_MemCpy(&Data[e_SIXTY], &s_DID_22F122_SW_EBOM_PartNum_au8[e_TEN], (uint8)e_THIRTY);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F122_Software_EBOM_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F132_EBOM_ECU_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F132_EBOM_ECU_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F132_EBOM_ECU_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F132_EBOM_ECU_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 15342853,15227370,15225541,1522969*/
/*GUID:-*/
  /* DD-ID: {1178675D-88DD-49dd-8882-938FCE2A1383}*/
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send EBOM ECU Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock(), D_DID_F132_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F132_EBOM_ECU_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F133_EBOM_Assembly_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F133_EBOM_Assembly_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F133_EBOM_Assembly_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F133_EBOM_Assembly_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {043479E6-5B6D-4255-A779-C911DCE86A2D}*/
  /* ReqID:- 16071600,16071608,16071609,16071706 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send EBOM Assembly Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F133_EBOM_Asm_PartNum_MirrorBlock(), D_DID_F133_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F133_EBOM_Assembly_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F134_CODEP_assembly_part_number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F134_CODEP_assembly_part_number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F134_CODEP_assembly_part_number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F134_CODEP_assembly_part_number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F134_CODEP_assembly_part_number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F134_CODEP_assembly_part_number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F134_CODEP_assembly_part_number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {746D10C7-8D09-4714-994F-B23F64CE25AF}*/
  /* ReqID:- 16071776,16071933,16071931,16071929 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send CODEP Assembly Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F134_CODEP_Asm_PartNum_MirrorBlock(), D_DID_F134_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F134_CODEP_assembly_part_number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F154_Hardware_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F154_Hardware_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F154_Hardware_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F154_Hardware_Supplier_Identification_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {7AA4F7C1-87EC-4d61-A874-F57A8C91C155}*/
  /* ReqID:- 15342984,15229526,15229530,15229703 */
/*GUID:-*/
  Std_ReturnType v_retVal_u8;
  const uint8 v_hwSupplierID_au8[D_DID_F154_DATA_LEN]={D_F154_HARDWARE_SUPPLIER_ID};

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send the Hardware Supplier Identification Number */
    VStdLib_MemCpy(Data,v_hwSupplierID_au8,D_DID_F154_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F154_Hardware_Supplier_Identification_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F155_Software_Supplier_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F155_Software_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F155_Software_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F155_Software_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F155_Software_Supplier_Identification_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F155_Software_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F155_Software_Supplier_Identification_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {A62235E6-1B75-460c-893A-7F264ACE1382}*/
  /* ReqID:- 15342997,15232548,15232630,15253028 */
  Std_ReturnType v_retVal_u8;
  const uint8 v_swSupplierID_au8[D_DID_F155_DATA_LEN]={D_F155_SOFTWARE_SUPPLIER_ID};

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send the Software Supplier Identification Number */
    VStdLib_MemCpy(Data,v_swSupplierID_au8, D_DID_F155_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F155_Software_Supplier_Identification_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F180_Boot_Software_Version_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F180_Boot_Software_Version_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data14ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F180_Boot_Software_Version_Information_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F180_Boot_Software_Version_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F180_Boot_Software_Version_Information_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F180_Boot_Software_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F180_Boot_Software_Version_Information_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {093E269F-D7E8-4d7c-B8F0-EF9DE9695E4B}*/
  /* ReqID:- 15343041,15252016,15252018,15253032 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_F180_DATA_LEN);
    /* Send Number of Boot Software Logical Block */
    Data[e_ZERO] = D_BOOT_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Boot Software Version Information */
    VStdLib_MemCpy(&Data[e_ONE],s_DID_22F180_BootSWVerInfoDefaultValue_au8, D_DID_F180_DATA_LEN);
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F180_Boot_Software_Version_Information_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F181_Application_Software_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F181_Application_Software_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data66ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F181_Application_Software_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F181_Application_Software_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F181_Application_Software_Identification_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F181_Application_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F181_Application_Software_Identification_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {A49300F3-61E8-4d20-989A-B86CA969A8FF}*/
  /* ReqID:- 15343061,15253036,15253022,15253038,15253729 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send Number of Application Software Logical Block size */
    Data[e_ZERO] = D_APP_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Application Software Identification Information */
    VStdLib_MemCpy(&Data[e_ONE],s_DID_22F181_AppSWVersionInfo_au8, D_DID_F181_DATA_LEN);
   
    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F181_Application_Software_Identification_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F182_Application_Data_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F182_Application_Data_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data40ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F182_Application_Data_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F182_Application_Data_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F182_Application_Data_Identification_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F182_Application_Data_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F182_Application_Data_Identification_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {F1A00024-9788-418c-961C-244DF281F6A1}*/
  /* ReqID:- 15253772,15253893,15253921 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send Number of Application Data Logical Block size */
    Data[e_ZERO] = D_APP_DATA_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Application Software Data Identification Information */
    VStdLib_MemCpy(&Data[e_ONE],s_DID_22F182_AppDataSWVersionInfo_au8, D_DID_F182_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F182_Application_Data_Identification_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F187_CODEP_ECU_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F187_CODEP_ECU_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F187_CODEP_ECU_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F187_CODEP_ECU_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {C3F1DCCD-98F8-47c6-A062-4A89BBDA38F6}*/
  /* ReqID:- 15254373,15254365,15254379 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send CODEP ECU Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock(), D_DID_F187_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F187_CODEP_ECU_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {964ADFCE-D784-4b9f-80C3-7AD533B1AE65}*/
  /* ReqID:- 16151199,16151205,16151203,16151202 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send FCA ESLM ECU Software Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock(), D_DID_F188_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F188_FCA_ESLM_ECU_Software_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {6A7978A3-C9F9-41a4-8356-47E00FD98E6F}*/
  /* ReqID:- 16151025,16151064,16151088,16151108 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send FCA ESLM ECU Software Calibration Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock(), D_DID_F18A_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F18A_FCA_ESLM_ECU_Software_Calibration_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {C4FCB462-88DE-45d4-84AC-48017037A467}*/
  /* ReqID:- 16148388,16148436,16148438,16148487 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send FCA ESLM ECU Software Application Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock(), D_DID_F18B_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F18B_FCA_ESLM_ECU_Software_Application_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F18C_ECU_Serial_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F18C_ECU_Serial_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F18C_ECU_Serial_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F18C_ECU_Serial_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18C_ECU_Serial_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F18C_ECU_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F18C_ECU_Serial_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {90BAE9F1-0205-4d8b-8A25-AF38E012A5E6}*/
  /* ReqID:- 16150880,16151030,16151516,16151549 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send ECU Serial Number */
    VStdLib_MemCpy(Data, D_ECU_SERIAL_NUMBER_ADDRESS, D_DID_F18C_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F18C_ECU_Serial_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {1949AF3E-2C5A-4a0b-A202-59E51B34D77B}*/
 /* ReqID:- 16150834,16150819,16150839,16150845 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 =(uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8,(uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send FCA ESLM ECU Hardware Number */
    VStdLib_MemCpy(Data, D_FCA_ESLM_ECU_HARDWARE_NUMBER_ADDRESS, D_DID_F191_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F191_FCA_ESLM_ECU_Hardware_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {DEAE96CF-50C0-4171-B7BB-29305C8AAAF7}*/
 /* ReqID:- 16075009,16075816,16075818,16077470 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 =(uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send Supplier ECU Hardware Part Number */
    VStdLib_MemCpy(Data, D_SUPPLIER_ECU_HARDWARE_PART_NUMBER_ADDRESS, D_DID_F192_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F192_Supplier_ECU_Hardware_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {59E6D283-E5F2-46c7-8E74-0EC21DA8C0B2}*/
 /* ReqID:- 16079787,16078200,16078339,16078513 */

  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send Supplier ECU Hardware Version Number */
    VStdLib_MemCpy(Data, D_SUPPLIER_ECU_HARDWARE_VERSION_NUMBER_ADDRESS, D_DID_F193_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F193_Supplier_ECU_Hardware_Version_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F194_Supplier_ECU_Software_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data11ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {9CDC66FE-BDB6-45de-BED9-57213F1ADA61}*/
  /* ReqID:- 16080712,16080239,16080310,16080638 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send Supplier ECU Software Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock(), D_DID_F194_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F194_Supplier_ECU_Software_Part_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F195_Supplier_ECU_Software_Version_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {B8C1653C-2F8D-4559-9840-9EBA4B953A98}*/
  /* ReqID:- 16081161,16081528,16081526,16081530 */
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send Supplier ECU Software Part Number */
    VStdLib_MemCpy(Data, Rte_Pim_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock(), D_DID_F195_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F195_Supplier_ECU_Software_Version_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F1A0_System_Identification_Data_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F1A0_System_Identification_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data90ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F1A0_System_Identification_Data_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F1A0_System_Identification_Data_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1A0_System_Identification_Data_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A0_System_Identification_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1A0_System_Identification_Data_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {4EF1B5B3-D250-45d9-A4B4-891EBADF4CD8}*/
  /* ReqID:- 15353759,15353752,15353765,15353939 */
  Std_ReturnType v_retVal_u8;
  uint8 v_vinCurrent_au8[D_VIN_ORIGINAL_BYTE_SIZE];
  const uint8 v_ecuDiagVar_au8[e_TWO]={D_F110_ECU_DIAG_VAR};
  const uint8 v_ecuSupplierID_au8[e_TWO]={D_F110_SUPPLIER_ID_MAGNA};

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_F1A0_DATA_LEN);

    /* Send CODEP ECU Part Number */
    VStdLib_MemCpy(&Data[e_ZERO], Rte_Pim_DID_F187_CODEP_Ecu_PartNum_MirrorBlock(), D_DID_F187_DATA_LEN);
    /* Send EBOM ECU Part Number */
    VStdLib_MemCpy(&Data[e_ELEVEN], Rte_Pim_DID_F132_EBOM_Ecu_PartNum_MirrorBlock(), D_DID_F132_DATA_LEN);
    /* Send ESLM_ECUHardwareNumber ECU Part Number */
    VStdLib_MemCpy(&Data[e_TWENTY_ONE], D_FCA_ESLM_ECU_HARDWARE_NUMBER_ADDRESS, D_DID_F191_DATA_LEN);
    /* Send FCA ESLM ECU Software Number */
    VStdLib_MemCpy(&Data[e_THIRTY_TWO], Rte_Pim_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock(), D_DID_F188_DATA_LEN);
    /* Send FCA ESLM ECU Software Application Number */
    VStdLib_MemCpy(&Data[e_FORTY_THREE], Rte_Pim_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock(), D_DID_F18B_DATA_LEN);
    /* Send FCA ESLM ECU Software Calibration Number */
    VStdLib_MemCpy(&Data[e_FIFTY_THREE], Rte_Pim_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock(), D_DID_F18A_DATA_LEN);
    
    /* Get VIN Current Message Information */
    (void)Rte_Read_RpVINData_VINCurrentData(&v_vinCurrent_au8[e_ZERO]);
    /* Send VIN Current Response Data */
    VStdLib_MemCpy(&Data[e_SIXTY_THREE], &v_vinCurrent_au8, sizeof(v_vinCurrent_au8));

    /* Set ECU Diagnostic Variant */
    VStdLib_MemCpy(&Data[e_EIGHTY],v_ecuDiagVar_au8,(uint8)e_TWO);
    /* Send ECU Diagnostic Identification */
    VStdLib_MemCpy(&Data[e_EIGHTY_TWO], Rte_Pim_DID_F110_Ecu_Diag_Info_MirrorBlock(), D_DID_F110_DATA_LEN);
    /* Set ECU Supplier ID */
    VStdLib_MemCpy(&Data[e_EIGHTY_EIGHT],v_ecuSupplierID_au8,(uint8)e_TWO);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F1A0_System_Identification_Data_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F1A2_Vector_Delivery_ID>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1A2_Vector_Delivery_ID_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {4CC9328A-D4A1-415a-A282-41DA5FBE11FB}*/
  /* ReqID:- 15344407,15255420,15255426,15255456 */
  Std_ReturnType v_retVal_u8;
  const uint8 v_vectorDeliveryID_au8[D_DID_F1A2_DATA_LEN]={D_F1A2_VECTOR_DELIVERY_ID};

  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemCpy(Data,v_vectorDeliveryID_au8,D_DID_F1A2_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F1A2_Vector_Delivery_ID_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16158708,16158712,16158729,16159115*/
  /*GUID:-*/
  /* DD-ID: {CF37A589-3578-4016-80E0-A0D02548F82A}*/
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_F1B3_DATA_LEN);
    /* Send Number of Boot Software fingerprint reading no of Logical Block */
    Data[e_ZERO] = D_BOOT_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Number of Boot Software fingerprint Logical Block 0*/
    Data[e_ONE] = D_LOGICAL_BLOCK_0;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_TWO],s_DID_22F1B3_BOOT_SW_Fingerprint_au8, (uint8)e_THIRTEEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F1B3_Boot_Software_Fingerprint_Reading_Information_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data71ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16159375,16159370,16159373,16159372*/
  /*GUID:-*/
  /* DD-ID: {9FB34561-6CE1-41e5-8455-B1B7BA328CE7}*/
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_F1B4_DATA_LEN);
    /* Send Number of Boot Software fingerprint reading no of Logical Block */
    Data[e_ZERO] = D_APP_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Number of Boot Software fingerprint Logical Block 1*/
    Data[e_ONE] = D_LOGICAL_BLOCK_1;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_TWO],&s_DID_22F1B4_AppSW_Fingerprint_au8[e_ZERO], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 2*/
    Data[e_FIFTEEN] = D_LOGICAL_BLOCK_2;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_SIXTEEN],&s_DID_22F1B4_AppSW_Fingerprint_au8[e_THIRTEEN], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 3*/
    Data[e_TWENTY_NINE] = D_LOGICAL_BLOCK_3;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_THIRTY],&s_DID_22F1B4_AppSW_Fingerprint_au8[e_TWENTY_SIX], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 4*/
    Data[e_FORTY_THREE] = D_LOGICAL_BLOCK_4;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_FORTY_FOUR],&s_DID_22F1B4_AppSW_Fingerprint_au8[e_THIRTY_NINE], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 5*/
    Data[e_FIFTY_SEVEN] = D_LOGICAL_BLOCK_5;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_FIFTY_EIGHT],&s_DID_22F1B4_AppSW_Fingerprint_au8[e_FIFTY_TWO], (uint8)e_THIRTEEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F1B4_Application_Software_Fingerprint_Reading_Information_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data43ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 16159375,16159374,16159370,16159373,16159372*/
  /*GUID:-*/
  /* DD-ID: {AD2BA9AA-4C47-4e72-B941-5C0D1C18577C}*/
  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_F1B5_DATA_LEN);
    /* Send Number of Boot Software fingerprint reading no of Logical Block */
    Data[e_ZERO] = D_APP_DATA_SOFTWARE_LOGICAL_BLOCKS;
    /* Send Number of Boot Software fingerprint Logical Block 6*/
    Data[e_ONE] = D_LOGICAL_BLOCK_6;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_TWO],&s_DID_22F1B5_AppDataSW_Fingerprint_au8[e_ZERO], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 7*/
    Data[e_FIFTEEN] = D_LOGICAL_BLOCK_7;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_SIXTEEN],&s_DID_22F1B5_AppDataSW_Fingerprint_au8[e_THIRTEEN], (uint8)e_THIRTEEN);
    /* Send Number of Boot Software fingerprint Logical Block 8*/
    Data[e_TWENTY_NINE] = D_LOGICAL_BLOCK_8;
    /* Send Boot Software fingerprint Information */
    VStdLib_MemCpy(&Data[e_THIRTY],&s_DID_22F1B5_AppDataSW_Fingerprint_au8[e_TWENTY_SIX], (uint8)e_THIRTEEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22F1B5_Application_Data_Software_Fingerprint_Reading_Information_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD13_Magna_Software_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD13_Magna_Software_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD13_Magna_Software_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD13_Magna_Software_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD13_Magna_Software_Version_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD13_Magna_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD13_Magna_Software_Version_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {08FFBFA5-39D6-4d78-8E75-2AF665471006}*/
  /* ReqID:- 15345601,15255732,15255736,15283926 */
  /*GUID:-*/
  Std_ReturnType v_retVal_u8;
  uint8 v_index = (uint8)e_EIGHTEEN;
  uint8 inc = (uint8)e_ZERO;

  static uint8 s_MagnaSoftwareVersion_au8[D_DID_FD13_DATA_LEN];                   /* Buffer for FD13 */
  static uint8 v_USS_Firmware_Version_au8[e_TWO];
  const uint8 v_Appl_SW_au8[(uint8)e_FOUR]={D_FD13_APPLICATION};
  const uint8 v_Boot_SW_au8[(uint8)e_FOUR]={D_FD13_BOOT};
  const uint8 v_HSM_SW_au8[(uint8)e_FOUR]={D_FD13_HSM};
  const uint8 v_FD13_FCAAppSoftwareBlockVersion_au8[D_FD13_APP_PRG_VERSION_LENGTH] = D_FD13_APP_PRG_VERSION_STRING; /* Emulate information from appl. version */
  US_S_USSConstantData_t uss_VersionInfo_s;

  if (NULL_PTR != Data)
  {
    /* flush Data pointer */
    VStdLib_MemClr(Data, D_DID_FD13_DATA_LEN);

    /* Fill Application SW Information */
    VStdLib_MemCpy(&s_MagnaSoftwareVersion_au8[e_ZERO], &v_Appl_SW_au8, (uint8)e_FOUR); 

    /* Fill Boot SW Information */
    VStdLib_MemCpy(&s_MagnaSoftwareVersion_au8[e_FOUR], &v_Boot_SW_au8, (uint8)e_FOUR);

    /* Fill HSM SW Information */
    VStdLib_MemCpy(&s_MagnaSoftwareVersion_au8[e_EIGHT], &v_HSM_SW_au8, (uint8)e_FOUR);

    /* Fill Uss Firmware Version Information */
    (void)Rte_Read_RpUSSConstantData_US_S_USSConstantData_t(&uss_VersionInfo_s); //Read USS version info
    VStdLib_MemCpy(&v_USS_Firmware_Version_au8, &uss_VersionInfo_s.USS_Ver.US_SnrVer, (uint8)e_TWO);  
    VStdLib_MemCpy(&s_MagnaSoftwareVersion_au8[e_TWELVE], &v_USS_Firmware_Version_au8[e_ONE], (uint8)e_ONE);  
    VStdLib_MemCpy(&s_MagnaSoftwareVersion_au8[e_THIRTEEN], &v_USS_Firmware_Version_au8[e_ZERO], (uint8)e_ONE);  
    s_MagnaSoftwareVersion_au8[e_FOURTEEN]= (uint8)uss_VersionInfo_s.USS_Ver.US_ModuleVer_YEAR;
    s_MagnaSoftwareVersion_au8[e_FIFTEEN] = (uint8)uss_VersionInfo_s.USS_Ver.US_ModuleVer_WEEK;
    s_MagnaSoftwareVersion_au8[e_SIXTEEN] = (uint8)uss_VersionInfo_s.USS_Ver.US_ModuleVer_DAY;
    s_MagnaSoftwareVersion_au8[e_SEVENTEEN] = (uint8)uss_VersionInfo_s.USS_Ver.US_ModuleVer_BUILD; 

    /* Fill Planned Release Version Information */
    for(inc = 0u; inc < 8u; inc++)
    {
      s_MagnaSoftwareVersion_au8[v_index] = v_FD13_FCAAppSoftwareBlockVersion_au8[inc];
      v_index++;
    }

    /* Fill Reserved Byte */
    VStdLib_MemSet(&s_MagnaSoftwareVersion_au8[e_TWENTY_SIX], D_BUILD_NUMBER, (uint8)e_SIX);

    /* Send s_MagnaSoftwareVersion_au8 Number Data */
    VStdLib_MemCpy(Data, &s_MagnaSoftwareVersion_au8, D_DID_FD13_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD13_Magna_Software_Version_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD14_FD14_Magna_Production_Date_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {CBCB0C4E-BBAC-468b-87AA-BEE56CF7AE1C}*/
  /* ReqID:- 16646098, 16646101, 16646103, 16646133, 16646033, 16646131, 16646140 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 =(uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send MAGNA Production Date */
    VStdLib_MemCpy(Data, D_MAGNA_PRODUCTION_DATE, D_DID_FD14_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD14_FD14_Magna_Production_Date_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD15_Magna_Production_HW_Number_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data13ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD15_Magna_Production_HW_Number_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {54BAF31B-28AB-4a13-A544-962CD24EA121}*/
  /* ReqID:- 17695823, 17695828, 17695847, 17695851 */
  /*GUID:-*/

  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send MAGNA Production HW Number */
    VStdLib_MemCpy(Data, D_MAGNA_PRODUCTION_HARDWARE_NUMBER, D_DID_FD15_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD15_Magna_Production_HW_Number_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD16_Magna_Production_ICT_Data_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {5ADE7893-569C-46df-A07E-DEC8104E8AE1}*/
  /* ReqID:- 17695869, 17695903, 17695906, 17695908 */
  /*GUID:-*/

  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send MAGNA Production ICT Data */
    VStdLib_MemCpy(Data, D_MAGNA_PRODUCTION_ICT_DATA, D_DID_FD16_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD16_Magna_Production_ICT_Data_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {B3C4FFEE-19B9-4429-AB4D-13527CB8A590}*/
  /* ReqID:- 17695925, 17695930, 17695932, 17695941 */
  /*GUID:-*/

  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send MAGNA Production HW Version Info  */
    VStdLib_MemCpy(Data, D_MAGNA_PRODUCTION_HARDWARE_VERSION_INFO, D_DID_FD17_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD17_Magna_Production_HW_Version_information_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD1D_PCB_Serial_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD1D_PCB_Serial_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data14ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD1D_PCB_Serial_Number_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD1D_PCB_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD1D_PCB_Serial_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {9E372955-38F5-4027-A2AC-A243F95160C9}*/
  /* ReqID:- 15345000,15255562,15255629,15283912 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8, (uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send PCB Serial Number */
    VStdLib_MemCpy(Data, D_PCB_SERIAL_NUMBER_ADDRESS, D_DID_FD1D_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD1D_PCB_Serial_Number_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD31_Magna_EOL_Coding_State_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {108344DA-06F7-47fd-9566-2354384DE969}*/
  /* ReqID:- 17727147, 17729102, 17729104, 17729247 */
  /*GUID:-*/

  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send MAGNA EOL Coding State */
    VStdLib_MemCpy(Data, Rte_Pim_DID_FD31_EOLCodingState_MirrorBlock(), D_DID_FD31_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Data_22FD31_Magna_EOL_Coding_State_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_WriteData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {EFFDDDBE-6AA6-4d6a-A85E-C20A33EC7A5A}*/
  /* ReqID:- 17727182, 17727832, 17729094, 17729214 */
  /*GUID:-*/

  Std_ReturnType v_retVal_u8;

  /* Check if destination address is not empty */
  if (NULL_PTR != Data)
  {
    /* Send MAGNA EOL Coding State */
    if((Data[e_ZERO] < (uint8)e_FOUR) && (Data[e_ONE] < (uint8)e_FOUR) && (Data[e_TWO] < (uint8)e_FOUR) && (Data[e_THREE] < (uint8)e_FOUR))
    {
      VStdLib_MemCpy(Rte_Pim_DID_FD31_EOLCodingState_MirrorBlock(), Data, D_DID_FD31_DATA_LEN);
      (void)Rte_Call_NvMService_AC3_SRBS_DID_FD31_EOLCodingState_SetRamBlockStatus(TRUE);
      v_retVal_u8 = RTE_E_OK;
    }
    else
    {
      *ErrorCode =  DCM_E_REQUESTOUTOFRANGE;
      v_retVal_u8 = RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK;
    }
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD31_Magna_EOL_Coding_State_Read_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Data_22FD38_Programmed_Assembly_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Data_22FD38_Programmed_Assembly>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Data_22FD38_Programmed_Assembly_DCM_E_PENDING
 *   RTE_E_DataServices_Data_22FD38_Programmed_Assembly_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD38_Programmed_Assembly_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PartNumMgr_CODE) DataServices_Data_22FD38_Programmed_Assembly_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_PARTNUMMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Data_22FD38_Programmed_Assembly_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {F4F286D5-BE2A-4b58-B538-D9359B5A32CD}*/
  /* ReqID:- 15346206,15255768,15255786,15283953 */
  Std_ReturnType v_retVal_u8;
  uint8 v_return_Val_u8;
  uint8 v_EOL_ActualMarkerData_au8[e_FOUR];

  VStdLib_MemCpy(v_EOL_ActualMarkerData_au8, D_EOL_MARKER_DATA_ADDRESS, (uint8)e_FOUR);
  v_return_Val_u8 = (uint8)VStdLib_MemCmpLarge(s_Varify_EOL_Marker_Data_au8,v_EOL_ActualMarkerData_au8,(uint8)e_FOUR);

  /* Check if destination address is not empty */
  if ((NULL_PTR != Data) && (v_return_Val_u8 == (uint8)e_ZERO))
  {
    /* Send Programmed Assembly Data */
    VStdLib_MemCpy(Data, D_PROGRAMMED_ASSEMBLY_ADDRESS, D_DID_FD38_DATA_LEN);

    v_retVal_u8 = RTE_E_OK;
  }
  else
  {
    v_retVal_u8 = RTE_E_DataServices_Data_22FD38_Programmed_Assembly_E_NOT_OK;
  }

  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PartNumMgr_CODE) RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_NvM_RpNotifyJobEnd_NvMBlockDescriptor_MetaData_JobFinished
 *********************************************************************************************************************/
/*GUID:-*/
  /* DD-ID: {C31A7169-CA8E-4c62-B51D-71C9D1BF131F}*/
  static uint8 s_F122_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_F181_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_F182_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_F1B4_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_F1B5_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_201A_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_201B_metaCounter_u8 = (uint8)e_ZERO;
  static uint8 s_SWVerInfoDataLength_u8 = (uint8)e_THIRTEEN;
  static uint8 s_EBOMPartDataLength_u8 = (uint8)e_TEN;
  static uint8 s_SWFigrPrintDataLength_u8 = (uint8)e_THIRTEEN;
  static uint8 s_ProgAtmptCntrDataLength_u8 = (uint8)e_TWO;
  static uint8 s_DID_22201F_FlashStatus_au8[e_TEN];                               /* Buffer for 201B */
 
  uint8 v_LoopIdx_MetaData_u8 ;

  if ((ServiceId == NVM_READ_BLOCK)  && (JobResult == NVM_REQ_OK))
  {
    INCREMENT_VALUE_BYONE(s_MetaArrayCounter_u8);
    if(s_MetaArrayCounter_u8 < (uint8)e_NINE)
    {
      (void)Rte_Call_NvMService_AC3_SRBS_DS_MetaData_SetDataIndex(s_MetaArrayCounter_u8);
      (void)Rte_Call_NvMService_AC3_SRBS_DS_MetaData_ReadBlock(&s_MetaData_Arr_as[s_MetaArrayCounter_u8]);
    }
    else
    {
      /* Send Meta block data into DID */
      for (v_LoopIdx_MetaData_u8= (uint8)e_ZERO ; v_LoopIdx_MetaData_u8 < (uint8)e_NINE; v_LoopIdx_MetaData_u8++)
      {
        if (v_LoopIdx_MetaData_u8 ==(uint8) e_ZERO)
        {  
          /*F122*/
          VStdLib_MemCpy(&s_DID_22F122_SW_EBOM_PartNum_au8[s_F122_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SwEbomPartNumber_au8, (uint32)s_EBOMPartDataLength_u8);
          s_F122_metaCounter_u8 = s_F122_metaCounter_u8 + s_EBOMPartDataLength_u8;
          /*F180*/
          VStdLib_MemCpy(&s_DID_22F180_BootSWVerInfoDefaultValue_au8[e_ZERO], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SoftwareIdentification_au8, (uint32)s_SWVerInfoDataLength_u8);
          /*F1B3*/
          VStdLib_MemCpy(&s_DID_22F1B3_BOOT_SW_Fingerprint_au8[e_ZERO],s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].Fingerprint_au8, (uint32)s_SWFigrPrintDataLength_u8);
          /*2003*/
          VStdLib_MemCpy(&s_DID_222003_BootSW_ProgAttmptCntr_au8[e_ZERO],s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].ProgAttempts_au8, (uint32)s_ProgAtmptCntrDataLength_u8);
          /*201F*/
          VStdLib_MemCpy(&s_DID_22201F_FlashStatus_au8[e_ZERO],&s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].FlashStatus_u8, (uint8)e_ONE);
        }
        else if ( v_LoopIdx_MetaData_u8 <= ((uint8)e_THREE))
        {  
          /*F122*/
          VStdLib_MemCpy(&s_DID_22F122_SW_EBOM_PartNum_au8[s_F122_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SwEbomPartNumber_au8, (uint32)s_EBOMPartDataLength_u8);
          s_F122_metaCounter_u8 = s_F122_metaCounter_u8 + s_EBOMPartDataLength_u8;
          /*F182*/
          VStdLib_MemCpy(&s_DID_22F182_AppDataSWVersionInfo_au8[s_F182_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SoftwareIdentification_au8, (uint32)s_SWVerInfoDataLength_u8);
          s_F182_metaCounter_u8 = s_F182_metaCounter_u8 + s_SWVerInfoDataLength_u8;  
          /*F1B5*/
          VStdLib_MemCpy(&s_DID_22F1B5_AppDataSW_Fingerprint_au8[s_F1B5_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].Fingerprint_au8, (uint32)s_SWFigrPrintDataLength_u8);
          s_F1B5_metaCounter_u8 = s_F1B5_metaCounter_u8 + s_SWFigrPrintDataLength_u8; 
          /*201B*/
          VStdLib_MemCpy(&s_DID_22201B_AppDataSW_ProgAttmptCntr_au8[s_201B_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].ProgAttempts_au8, (uint32)s_ProgAtmptCntrDataLength_u8);
          s_201B_metaCounter_u8 = s_201B_metaCounter_u8 + s_ProgAtmptCntrDataLength_u8;
          /*201F*/
          VStdLib_MemCpy(&s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8+(uint8)e_FIVE],&s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].FlashStatus_u8, (uint8)e_ONE);
          
        }
        else
        {     
          /*F122*/
          VStdLib_MemCpy(&s_DID_22F122_SW_EBOM_PartNum_au8[s_F122_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SwEbomPartNumber_au8, (uint32)s_EBOMPartDataLength_u8);
          s_F122_metaCounter_u8 = s_F122_metaCounter_u8 + s_EBOMPartDataLength_u8;
          /*F181*/
          VStdLib_MemCpy(&s_DID_22F181_AppSWVersionInfo_au8[s_F181_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].SoftwareIdentification_au8, (uint32)s_SWVerInfoDataLength_u8);
          s_F181_metaCounter_u8 = s_F181_metaCounter_u8 + s_SWVerInfoDataLength_u8;
          /*F1B4*/
          VStdLib_MemCpy(&s_DID_22F1B4_AppSW_Fingerprint_au8[s_F1B4_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].Fingerprint_au8, (uint32)s_SWFigrPrintDataLength_u8);
          s_F1B4_metaCounter_u8 = s_F1B4_metaCounter_u8 + s_SWFigrPrintDataLength_u8;
          /*201A*/
          VStdLib_MemCpy(&s_DID_22201A_AppSW_ProgAttmptCntr_au8[s_201A_metaCounter_u8], s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].ProgAttempts_au8, (uint32)s_ProgAtmptCntrDataLength_u8);
          s_201A_metaCounter_u8 = s_201A_metaCounter_u8 + s_ProgAtmptCntrDataLength_u8; 
          /*201F*/
          VStdLib_MemCpy(&s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8-(uint8)e_THREE],&s_MetaData_Arr_as[v_LoopIdx_MetaData_u8].FlashStatus_u8, (uint8)e_ONE);
        }
      }
      uint16 v_varTempContainer_u16=0x00u;
      uint16 v_varTemp_u16=0x00u;

      for ( v_LoopIdx_MetaData_u8 = (uint8)e_ZERO; v_LoopIdx_MetaData_u8 < (uint8)e_NINE ; v_LoopIdx_MetaData_u8++)
      {
        if (v_LoopIdx_MetaData_u8==(uint8)e_EIGHT)
        {
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
          if (s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8] == (uint8)e_ONE)
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
          {
            v_varTempContainer_u16 |= (uint16)(((uint16)s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8] << v_LoopIdx_MetaData_u8) & D_ALL_BIT_STATUS);
            v_varTemp_u16 |= (uint16)v_varTempContainer_u16;
            (void)Rte_Write_PpFlashSts_v_FlashSts_u16(v_varTemp_u16);
          }
          else
          {
            (void)Rte_Write_PpFlashSts_v_FlashSts_u16(v_varTemp_u16);
          }
        }

        else
        {
          if (s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8] == (uint8)e_ONE)
          {
            v_varTempContainer_u16 |= (uint16)(((uint16)s_DID_22201F_FlashStatus_au8[v_LoopIdx_MetaData_u8] << v_LoopIdx_MetaData_u8) & D_ALL_BIT_STATUS);
            v_varTemp_u16 |=(uint16)v_varTempContainer_u16;             
          }
          v_varTempContainer_u16=0x00;
        }
      }

      

    }
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PartNumMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_MetaData_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DS_MetaData_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_DS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PartNumMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PartNumMgr_CODE) RE_PartNumMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PartNumMgr_Init
 *********************************************************************************************************************/
/*GUID:-{EE07784D-5FB2-4612-BF68-F463FFE3FCBF}*/
  /* DD-ID: {EE07784D-5FB2-4612-BF68-F463FFE3FCBF}*/
  /* Set Index to Read Meta Data */
  (void)Rte_Call_NvMService_AC3_SRBS_DS_MetaData_SetDataIndex(s_MetaArrayCounter_u8);
  (void)Rte_Call_NvMService_AC3_SRBS_DS_MetaData_ReadBlock(&s_MetaData_Arr_as[s_MetaArrayCounter_u8]);
  v_UssMarrDataFlag_b = FALSE;
  (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_PartNumManager,SSM_APPSTATE_INIT);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PartNumMgr_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_SSM_1_0_State_State_1_0(SSM_1_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_0(SSM_2_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_1(SSM_2_1_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_QNXState_State_QNX(SSM_QNX_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SystemState_SystemState(SSM_SystemState *data)
 *   Std_ReturnType Rte_Read_RpUSSConstantData_US_S_USSConstantData_t(US_S_USSConstantData_t *data)
 *   Std_ReturnType Rte_Read_RpUssMrrgData_US_S_MarriageSensorIDs_t(US_S_MarriageSensorIDs_t *data)
 *   Std_ReturnType Rte_Read_RpVINData_VINCurrentData(uint8 *data)
 *     Argument data: uint8* is of type VINlData_Arr
 *   Std_ReturnType Rte_Read_RpVINData_VINLockStatus(uint8 *data)
 *   Std_ReturnType Rte_Read_RpVINData_VINOdoCounter(uint8 *data)
 *   Std_ReturnType Rte_Read_RpVINData_VINOriginalData(uint8 *data)
 *     Argument data: uint8* is of type VINlData_Arr
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpFlashSts_v_FlashSts_u16(uint16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DID_FD31_EOLCodingState_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_UssSensorMarrData_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_UssSensorMarrData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PartNumMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PartNumMgr_CODE) RE_PartNumMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PartNumMgr_Main
 *********************************************************************************************************************/
  /* DD-ID: {DA0D6492-F464-4f08-8D5B-AC1A83501DAC}*/
	SSM_SystemState SSMSystemState;
	static SSM_SystemStateDef previous_SSMMasterState = SSM_STATE_MAX;
  
  f_Send_USSData_mcu2_1_v();  /*Update USS sensor data */

  /* Read SSM master state and update the application accordingly */
  (void)Rte_Read_R_SystemState_SystemState(&SSMSystemState);

  if(previous_SSMMasterState != SSMSystemState.SystemState)
  {
    switch(SSMSystemState.SystemState)
    {
      case SSM_STATE_BOOTING:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_PartNumManager, SSM_APPSTATE_INIT);
      break;
      case SSM_STATE_IPCREADY:
      case SSM_STATE_RUNNING:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_PartNumManager, SSM_APPSTATE_RUNNING);
      break;
      case SSM_STATE_DEGRADED:
      case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP:
      case SSM_STATE_SHUTTINGDOWN_REMOTECORES:
      case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE:
      case SSM_STATE_OFF:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_PartNumManager, SSM_APPSTATE_STOPPED);
      break;
      default:/*QAC fixes*/
      break;
    }
    previous_SSMMasterState = SSMSystemState.SystemState;
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_PartNumMgr_STOP_SEC_CODE
#include "SWC_PartNumMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, SWC_PartNumMgr_CODE)static f_Send_USSData_mcu2_1_v(void)
{
  /* DD-ID: {B60F50A7-D5AB-4074-88FF-20CAD0459C1B}*/
  sint8 v_RetVal;
  SSM_2_1_CoreStatus data;
  static US_S_MarriageSensorIDs_t s_US_S_MarriageSensorIDs_Data;

  if (TRUE == v_UssMarrDataFlag_b) /* Check if Uss sensor marriage data stored in Nvm is sent to Uss core after power up */
  {
    (void)Rte_Read_RpUssMrrgData_US_S_MarriageSensorIDs_t(&s_US_S_MarriageSensorIDs_Data);
    if (TRUE == s_US_S_MarriageSensorIDs_Data.bValid)   /* Check if valid Uss sensor Marriage data is received to store in Nvm */
    {
      v_RetVal = VStdLib_MemCmpLarge(&s_US_S_MarriageSensorIDs_Data, Rte_Pim_UssSensorMarrData_MirrorBlock(), sizeof(US_S_MarriageSensorIDs_t));
      if ((sint8)0 != v_RetVal) /* Check if received valid Uss sensor marriage data is different than the data stored in NVM */
      {
        VStdLib_MemCpy(Rte_Pim_UssSensorMarrData_MirrorBlock(), &s_US_S_MarriageSensorIDs_Data, sizeof(US_S_MarriageSensorIDs_t));
        (void)Rte_Call_NvMService_AC3_SRBS_UssSensorMarrData_SetRamBlockStatus(TRUE);
      }
      else
      {
        /* Do Nothing */
      }
    }
    else
    {
      /* Do Nothing */
    }
  }
  else
  {
    /*Read MCU 2_1 status*/
    (void)Rte_Read_R_SSM_2_State_State_2_1(&data);
    if (SSM_SlaveCore_State_BSP_Init_Done <= data.CoreStatus)
    {
      VStdLib_MemCpy(&s_US_S_MarriageSensorIDs_Data,Rte_Pim_UssSensorMarrData_MirrorBlock(), sizeof(US_S_MarriageSensorIDs_t));
      s_US_S_MarriageSensorIDs_Data.bValid = TRUE;
      /* Send Uss sensor marriage data stored in Nvm to Uss core */
      (void)Rte_Call_RpIpcTxData_IPC_Write_v(&s_US_S_MarriageSensorIDs_Data, (uint16)e_IpcMsgId_Data_US_S_MarriageSensorIDs_t, sizeof(US_S_MarriageSensorIDs_t));
      v_UssMarrDataFlag_b = TRUE; /* Update core Status Flag once data is transmited */
#ifdef Enable_Printf
      appLogPrintf("\n MCU1_0 Autosar  Sent USS Marriage Data to MCU2_1");
      #endif
    }
    else
    {
      /*Do nothing*/
    }
  }
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
