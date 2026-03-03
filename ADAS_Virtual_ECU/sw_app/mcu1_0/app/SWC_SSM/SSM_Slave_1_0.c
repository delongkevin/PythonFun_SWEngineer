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
 *             File:  SSM_Slave_1_0.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SSM_Slave_1_0
 *  Generation Time:  2024-12-03 16:36:45
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SSM_Slave_1_0>
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
 * ME_Hydra3defs_E_CalibStatus_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_CalibrationID_t
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
 *
 * Runnable Entities:
 * ==================
 * RE_Periodic_SSM_Slave
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_SSM_Slave_1_0.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SSM_Slave.h"


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
 * ME_Hydra3defs_E_CalibStatus_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CalibrationID_t: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Array_04Byte: Array with 4 element(s) of type uint8
 * Array_10Byte: Array with 10 element(s) of type uint8
 * Array_11Byte: Array with 11 element(s) of type uint8
 * EOLIterationData_arr: Array with 5 element(s) of type uint8
 * Reserved_arr: Array with 7 element(s) of type uint8
 * SSM_MCU_1_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 *
 * Record Types:
 * =============
 * CalDataProvider_MCU_1_0_Def: Record with elements
 *   CalData_SVSCamCurrentCalibData of type TbSVS_S_SVSCamCurrentCalibData_t
 *   CalData_SVSCamEOLCalibData of type TbSVS_S_SVSCamEOLCalibData_t
 *   CalData_SVSCamOCCalibData of type TbSVS_S_SVSCamOCCalibData_t
 *   CalData_SVSCamSCCalibData of type TbSVS_S_SVSCamSCCalibData_t
 *   FreshnessCount of type uint32
 *   CalData_PlantOdoValue of type uint16
 *   CalData_PrevOdoValue of type uint16
 *   bValid of type boolean
 * ME_Hydra2defs_S_CodingTableExt_t: Record with elements
 *   bValid of type boolean
 *   ConfigCode of type Array_11Byte
 *   TesterCode of type Array_10Byte
 *   ProductionDate of type Array_04Byte
 *   CanNode14trscm_uint8 of type uint8
 *   Variant_ID of type uint8
 *   CanNode27Asm_uint8 of type uint8
 *   CanNode63ttm_uint8 of type uint8
 *   CanNode67dtcm_uint8 of type uint8
 *   CanNode95itcm_uint8 of type uint8
 *   StopandStart of type uint8
 *   DriverSide of type uint8
 *   Tyresize_uint16 of type uint16
 *   Wheelbase of type uint8
 *   Rearviewcamera of type uint8
 *   Parkwithstop of type uint8
 *   SteeringRatio_uint8 of type uint8
 *   Gearboxtype of type uint8
 *   Drivetypevariant of type uint8
 *   Pamtuningset of type uint8
 *   Semiautopark of type uint8
 *   VehicleLineConfiguration_uint8 of type uint8
 *   CountryCode_uint8 of type uint8
 *   Srt of type uint8
 *   PAMConfig_uint8 of type uint8
 *   ModelYear_uint8 of type uint8
 *   Hybridtype of type uint8
 *   Pulloutcontrol of type uint8
 *   Surroundviewcamera of type uint8
 *   Forwardfacingcamera of type uint8
 *   Autonomylevel of type uint8
 *   Fullautomaticparking of type uint8
 *   Radiodisplay of type uint8
 *   Mirrortype of type uint8
 *   Auxiliarycamera of type uint8
 *   Trailerreverseguide of type uint8
 *   Trailersurround of type uint8
 *   Trailerreversesteering of type uint8
 *   Trailerhitchassist of type uint8
 *   CVPAM_Presence_uint8 of type uint8
 *   SideDistanceWarning of type uint8
 *   PROXIWriteCounter of type uint8
 * ME_Hydra3defs_S_CamCalibDataSTM_t: Record with elements
 *   CamCalibData_STM of type ME_Hydra3defs_S_CamCalibData_t
 *   CamCalibIDs_STM of type ME_Hydra3defs_E_CalibrationID_t
 * ME_Hydra3defs_S_CamCalibData_t: Record with elements
 *   Pitch_f32 of type float32
 *   Yaw_f32 of type float32
 *   Roll_f32 of type float32
 *   CalibStatus_e of type ME_Hydra3defs_E_CalibStatus_t
 *   NewValueAvailable_b of type boolean
 *   OverwriteStatus_b of type boolean
 * ME_Hydra3defs_S_CamEOLCalibDataSTM_t: Record with elements
 *   CamCalibData_STM of type ME_Hydra3defs_S_CamEOLCalibData_t
 *   CamCalibIDs_STM of type ME_Hydra3defs_E_CalibrationID_t
 * ME_Hydra3defs_S_CamEOLCalibData_t: Record with elements
 *   calibdata of type ME_Hydra3defs_S_CamCalibData_t
 *   X_f32 of type float32
 *   Y_f32 of type float32
 *   Z_f32 of type float32
 *   EOLIterationData_au8 of type EOLIterationData_arr
 *   Reserved_au8 of type Reserved_arr
 * SSM_1_0_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_1_0_LocalAppStatus_Arr
 * SSM_SystemState: Record with elements
 *   SystemState of type SSM_SystemStateDef
 *   DegradedState of type SSM_DegradedState
 * TbSVS_S_SVSCamCurrentCalibData_t: Record with elements
 *   CamFrontCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamLeftCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRearCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRightCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 * TbSVS_S_SVSCamEOLCalibData_t: Record with elements
 *   CamFrontEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamLeftEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRearEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRightEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 * TbSVS_S_SVSCamOCCalibData_t: Record with elements
 *   CamFrontOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamLeftOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRearOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRightOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 * TbSVS_S_SVSCamSCCalibData_t: Record with elements
 *   CamFrontSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamLeftSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRearSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRightSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *
 *********************************************************************************************************************/


#define SSM_Slave_1_0_START_SEC_CODE
#include "SSM_Slave_1_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_SSM_Slave
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
 *   Std_ReturnType Rte_Read_R_SystemState_SystemState(SSM_SystemState *data)
 *   Std_ReturnType Rte_Read_SSM_Slave_1_0_R_SWC_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0(CalDataProvider_MCU_1_0_Def *data)
 *   Std_ReturnType Rte_Read_SSM_Slave_1_0_R_SWC_ProxiM_MCU1_0_EEPROM_Data_ProxiData(ME_Hydra2defs_S_CodingTableExt_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_SSM_1_0_State_State_1_0(const SSM_1_0_CoreStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_R_IPC_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_SSM_Slave_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SSM_Slave_1_0_CODE) RE_Periodic_SSM_Slave(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_SSM_Slave
 *********************************************************************************************************************/
  /* DD-ID: {2C5C4024-A8BE-4770-BB8D-1B2DB6152257}*/
	SSM_Slave_MainTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SSM_Slave_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SSM_Slave_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SSM_Slave_1_0_CODE) RE_SSM_Slave_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SSM_Slave_Init
 *********************************************************************************************************************/
  /* DD-ID: {5B32FDE3-0717-488d-A5D0-BB9C49EF2EEA}*/
	SSM_Slave_Init();

  //Set the SSM State to BSP init Done
  (void)SSM_Slave_RequestState(SSM_SlaveCore_State_BSP_Init_Done);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SSM_Slave_1_0_STOP_SEC_CODE
#include "SSM_Slave_1_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
