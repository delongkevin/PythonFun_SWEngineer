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
 *             File:  CDD_IPCHandler.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_IPCHandler
 *  Generation Time:  2026-01-28 08:15:33
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_IPCHandler>
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
 * APARequestSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * AP_HMI_BottomBlackBanner_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * AP_HMI_Fullscreen_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * AP_HMI_TopBlackBanner_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * AP_HMI_TopRedBanner_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ASCM_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ASCM_SysFail
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Active_Park_Mode
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Active_Park_Prox_Chime
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Backup_Cam_Delay
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Brk_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CM_TCH_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CM_TCH_X_COORD
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * CM_TCH_Y_COORD
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * CalibrationState_DID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * CalibrationState_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * CameraDisplaySts2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CameraStatus_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * CanDebugMode_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * CmdIgnSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CplrDetStatus_e
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DLDCamSts_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DetectionFailInfo_DID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DetectionFailInfo_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DriverDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * DynamicGrid
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * ECM_THA_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ECM_TRSC_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EPS_SteeringTouchStat
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EPS_SteeringTouq_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EPS_THA_DriverTorqueOverride
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EPS_THA_SteeringTorqueResp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ESS_ENG_ST_W
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EngineSts_W
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ErrorMgr_ErrorField
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ErrorMgr_ErrorField
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Cntr_CVPAM_FD_Data
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Cntr_CVPAM_FD_Data2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_LHF_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LatAccelerationOffset_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LongAccelerationOffset_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LwsAngle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PPPA_MaxSpeed
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PdlPosActual
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_RHF_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_RHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Slope
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_THA_SteeringDamping
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_TRSC_SteeringDamping
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FL_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FR_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FT_PAMRequestSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Fwrd_Cam_Guidelines
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GearEngaged
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * GearEngagedForDisplay
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * HAS_Status_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * HU_TRSC_EnableBtn_Sts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * HitchDetStatus_e
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * IAllowedParkingDirection_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ITBM_TrlrStat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LHRDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LaneColor_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LaneDetHealth_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LaneTrackState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LaneType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LanguageSelection
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LwsAngleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
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
 * ME_Hydra3defs_E_CameraID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_EOLAlgoState_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_EOLErrorCode_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_NRCType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_OCAlgoState_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_OCErrorCode_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_RoutineType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ME_Hydra3defs_E_TestPatternType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * MRM_STATUS_C2
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
 * PAMRequestSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * PamChimeVolumeFront
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PamChimeVolumeRear
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ParkINStyle_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ParkOutStyle_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ParkingSlotID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ParkingSlotType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * PsngrDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RHRDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RHatchSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RL_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RR_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Rear_Brk_Asst
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RecognitionInfo_t
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
 * SVC_Guidelines
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * ShiftLeverPosition
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ShiftLeverPositionReq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Shifter_ADAS_Inhibit
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SlotSide_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * State_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TCASERANGESTATUS
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TGW_CAMERA_DISP_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * THA_SteeringTouchStat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRANS_ADAS_Inhibit
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TargetGear
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TeAP_e_Alert
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_AlgoState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_DispView2
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_FrntSnsrStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_GearShiftReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_GraphicFlshRate
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_HMIPopUp
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_InterfaceBSM
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMChimeRepnRate
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMChimeTyp
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMLedCtrlStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMOffStatus2BT
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMPopUpReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMSystemFault
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMVolSig
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMVolume
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_ParKMnvrActv
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_ParkAssistStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_RearSnsrStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_SPMActvStat
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_SPMLatCtrlReqSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAutoPark_e_AutoParkStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAutoPark_e_ChimeReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAutoPark_e_GearCmd
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAutoPark_e_ScanDir
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeEnv_e_NFCDState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeEnv_e_ObjClass
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_EPBReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_PamChimeRepRateSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_PamChimeTyp
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_PamVol
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_RearBrkSupprInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_ScreenRequest
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_THARmpUpDwnSpd
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_THASpdLimReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_THAState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_THAStateInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTHA_e_THASteerTrqReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_CamBlockSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_DispView2_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_GearShiftSts_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_GraphicOverlay_Sts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_SpdLmtReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TADState
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCAbortReason_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCLedSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCPopupDispInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCStat
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCStrTrqActvReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSCUnavailReas_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSKMBtnSts_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSKMCenBtnSts_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSKMSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TRSKMSts_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrCalInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrCalInfo_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrHitchLightCtrl
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrPrsntInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrPrsntInfo_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrRecogInfo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_TrlrRecogInfo_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_VehStpReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeTRSC_e_VehStpReq_DID
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeVBII_e_CenterBtnSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeVBII_e_DrverSecuBltAlrmSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeVBII_e_EnblBtnSts
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeVBII_e_GearEngagedForDsply
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TrailerAngleSign_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TrailerCalibrationFailInfo_DID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TrailerCalibrationFailInfo_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TrailerConnectionSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TrailerID_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TrailerPresentInfo_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TransmissionSailingSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TrlrCalInfo_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TurnAroundState_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * US_E_Zoneinfo_list_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * VIN_MSG
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * aSigConverter_E_DisplayView2_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * aSigConverter_E_THAScreenRequest_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * aZynqM_E_ModuleState_EOL_STM_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * aZynqM_E_ModuleState_OC_STM_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * aZynqM_E_ModuleState_SC_STM_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * bool_t
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * char_T
 *   sint8 represents integers with a minimum value of -128 and a maximum value of 127.
 *      The order-relation on sint8 is: x < y if y - x is positive.
 *      sint8 has a lexical representation consisting of an optional sign followed 
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is 
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, 12678, +10000.
 *
 * e_SensorSource
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * real32_T
 *   float32 corresponds to the IEEE single-precision 32-bit floating point type
 *      [IEEE 754-1985]. The basic value space of float32 consists of the values 
 *      m * 2^e, where m is an integer whose absolute value is less than 2^24, 
 *      and e is an integer between -149 and 104, inclusive. In addition to the basic
 *      value space described above, the value space of float32 also contains the 
 *      following special values: positive and negative zero, positive and negative 
 *      infinity and not-a-number. The order-relation on float32 is: 
 *      x < y if y - x is positive. Positive zero is greater than negative zero.
 *      Not-a-number equals itself and is greater than all float values including positive infinity. 
 *      
 *      float32 values have a lexical representation consisting of a mantissa followed, 
 *      optionally, by the character "E" or "e", followed by an exponent. The exponent
 *      must be an integer. The mantissa must be a decimal number. The representations
 *      for exponent and mantissa must follow the lexical rules for integer and decimal.
 *      If the "E" or "e" and the following exponent are omitted, an exponent value 
 *      of 0 is assumed. 
 *      
 *      The special values positive and negative zero, positive and negative infinity
 *      and not-a-number have lexical representations 0, -0, INF, -INF and NaN, 
 *      respectively. 
 *      
 *      For example, -1E4, 1267.43233E12, 12.78e-2, 12 and INF are all legal literals
 *      for float32.
 *
 * sint16_t
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 *********************************************************************************************************************/

#include "Rte_CDD_IPCHandler.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Enums.h"
#include "APDiagDataTypes.h"
#include "PduR_Cdd_UssLog.h"
#include "ipc_manager.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "Os_Lcfg.h"
#include "vstdlib.h"

#define MCU2_0_STATE                        0x01u
#define MCU2_1_STATE                        0x02u
#define ALL_CORE_STATE                      (MCU2_0_STATE | MCU2_1_STATE)
#define D_ZERO_VAL                          (0x00u)

/*Below variables shouldnt be included as safe*/
__attribute__ ((section("QMRAM"))) VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy;
__attribute__ ((section("QMRAM"))) VAR(INVMSignalManager_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy;

#if defined( BUILD_MCU1_0 )
#define CDD_IPCHandler_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_IPCHandler_MemMap.h"
#endif
static uint8 S_RemoteCoreStatus_u8;
static uint8 S_SendNvmDataFlag;
TbNVM_ReadParam TbNVM_ReadParam_Data;
#if defined( BUILD_MCU1_0 )
#define CDD_IPCHandler_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CDD_IPCHandler_MemMap.h"
#endif
static void f_SendNvmDataToCore_v(void);
void f_FPA_NVMHandle_v(void);

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
 * APARequestSts: Integer in interval [0...1]
 * AP_HMI_BottomBlackBanner_t: Integer in interval [0...4294967295]
 * AP_HMI_Fullscreen_t: Integer in interval [0...4294967295]
 * AP_HMI_TopBlackBanner_t: Integer in interval [0...4294967295]
 * AP_HMI_TopRedBanner_t: Integer in interval [0...4294967295]
 * ASCM_Stat: Integer in interval [0...15]
 * ASCM_SysFail: Integer in interval [0...1]
 * Active_Park_Mode: Integer in interval [0...1]
 * Active_Park_Prox_Chime: Integer in interval [0...1]
 * Backup_Cam_Delay: Integer in interval [0...1]
 * Brk_Stat: Integer in interval [0...3]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CalibrationState_DID_t: Integer in interval [0...4294967295]
 * CalibrationState_t: Integer in interval [0...4294967295]
 * CameraDisplaySts2: Integer in interval [0...15]
 * CameraStatus_t: Integer in interval [0...4294967295]
 * CanDebugMode_t: Integer in interval [0...4294967295]
 * CmdIgnSts: Integer in interval [0...7]
 * CplrDetStatus_e: Integer in interval [0...4294967295]
 * DLDCamSts_t: Integer in interval [0...4294967295]
 * DetectionFailInfo_DID_t: Integer in interval [0...4294967295]
 * DetectionFailInfo_t: Integer in interval [0...4294967295]
 * DriverDoorSts: Integer in interval [0...1]
 * DynamicGrid: Integer in interval [0...1]
 * ECM_THA_Resp: Integer in interval [0...3]
 * ECM_TRSC_Resp: Integer in interval [0...3]
 * EPS_SteeringTouchStat: Integer in interval [0...1]
 * EPS_SteeringTouq_Resp: Integer in interval [0...3]
 * EPS_THA_DriverTorqueOverride: Integer in interval [0...3]
 * EPS_THA_SteeringTorqueResp: Integer in interval [0...7]
 * ESS_ENG_ST_W: Integer in interval [0...15]
 * EngineSts_W: Integer in interval [0...3]
 * ErrorMgr_ErrorField: Integer in interval [0...255]
 * ErrorMgr_ErrorField: Integer in interval [0...255]
 * FD14_Cntr_CVPAM_FD_Data: Integer in interval [0...65535]
 * FD14_Cntr_CVPAM_FD_Data2: Integer in interval [0...65535]
 * FD14_LHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_LatAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LongAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LwsAngle: Integer in interval [0...65535]
 * FD14_PPPA_MaxSpeed: Integer in interval [0...255]
 * FD14_PdlPosActual: Integer in interval [0...255]
 * FD14_RHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_Slope: Integer in interval [0...255]
 * FD14_THA_SteeringDamping: Integer in interval [0...255]
 * FD14_TRSC_SteeringDamping: Integer in interval [0...255]
 * FL_Lvl_Adj: Integer in interval [0...1]
 * FR_Lvl_Adj: Integer in interval [0...1]
 * FT_PAMRequestSts: Integer in interval [0...1]
 * Fwrd_Cam_Guidelines: Integer in interval [0...1]
 * GearEngaged: Integer in interval [0...15]
 * GearEngagedForDisplay: Integer in interval [0...31]
 * HAS_Status_C2: Integer in interval [0...3]
 * HU_TRSC_EnableBtn_Sts: Integer in interval [0...2]
 * HitchDetStatus_e: Integer in interval [0...4294967295]
 * IAllowedParkingDirection_t: Integer in interval [0...4294967295]
 * ITBM_TrlrStat: Integer in interval [0...3]
 * LHRDoorSts: Integer in interval [0...1]
 * LaneColor_t: Integer in interval [0...4294967295]
 * LaneDetHealth_t: Integer in interval [0...4294967295]
 * LaneTrackState: Integer in interval [0...4294967295]
 * LaneType_t: Integer in interval [0...4294967295]
 * LanguageSelection: Integer in interval [0...255]
 * LwsAngleType: Integer in interval [0...3]
 * ME_Hydra3defs_E_CalibStatus_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CalibrationID_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CameraID_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_EOLAlgoState_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_EOLErrorCode_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_NRCType_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_OCAlgoState_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_OCErrorCode_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_RoutineType_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_TestPatternType_t: Integer in interval [0...4294967295]
 * MRM_STATUS_C2: Integer in interval [0...7]
 * NvM_RequestResultType: Integer in interval [0...255]
 * PAMRequestSts: Integer in interval [0...1]
 * PamChimeVolumeFront: Integer in interval [0...3]
 * PamChimeVolumeRear: Integer in interval [0...3]
 * ParkINStyle_t: Integer in interval [0...4294967295]
 * ParkOutStyle_t: Integer in interval [0...4294967295]
 * ParkingSlotID_t: Integer in interval [0...4294967295]
 * ParkingSlotType_t: Integer in interval [0...4294967295]
 * PsngrDoorSts: Integer in interval [0...1]
 * RHRDoorSts: Integer in interval [0...1]
 * RHatchSts: Integer in interval [0...1]
 * RL_Lvl_Adj: Integer in interval [0...1]
 * RR_Lvl_Adj: Integer in interval [0...1]
 * Rear_Brk_Asst: Integer in interval [0...1]
 * RecognitionInfo_t: Integer in interval [0...4294967295]
 * Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_10: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_11: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_4: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_5: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_6: Integer in interval [0...4294967295]
 * Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SVC_Guidelines: Integer in interval [0...1]
 * ShiftLeverPosition: Integer in interval [0...15]
 * ShiftLeverPositionReq: Integer in interval [0...15]
 * Shifter_ADAS_Inhibit: Integer in interval [0...1]
 * SlotSide_t: Integer in interval [0...4294967295]
 * State_t: Integer in interval [0...4294967295]
 * TCASERANGESTATUS: Integer in interval [0...3]
 * TGW_CAMERA_DISP_STAT: Integer in interval [0...15]
 * THA_SteeringTouchStat: Integer in interval [0...3]
 * TRANS_ADAS_Inhibit: Integer in interval [0...1]
 * TargetGear: Integer in interval [0...15]
 * TeAP_e_Alert: Integer in interval [0...4294967295]
 * TeAP_e_AlgoState: Integer in interval [0...4294967295]
 * TeAP_e_DispView2: Integer in interval [0...4294967295]
 * TeAP_e_FrntSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_GearShiftReq: Integer in interval [0...4294967295]
 * TeAP_e_GraphicFlshRate: Integer in interval [0...4294967295]
 * TeAP_e_HMIPopUp: Integer in interval [0...4294967295]
 * TeAP_e_InterfaceBSM: Integer in interval [0...4294967295]
 * TeAP_e_PAMChimeRepnRate: Integer in interval [0...4294967295]
 * TeAP_e_PAMChimeTyp: Integer in interval [0...4294967295]
 * TeAP_e_PAMLedCtrlStatus: Integer in interval [0...4294967295]
 * TeAP_e_PAMOffStatus2BT: Integer in interval [0...4294967295]
 * TeAP_e_PAMPopUpReq: Integer in interval [0...4294967295]
 * TeAP_e_PAMSystemFault: Integer in interval [0...4294967295]
 * TeAP_e_PAMVolSig: Integer in interval [0...4294967295]
 * TeAP_e_PAMVolume: Integer in interval [0...4294967295]
 * TeAP_e_ParKMnvrActv: Integer in interval [0...4294967295]
 * TeAP_e_ParkAssistStatus: Integer in interval [0...4294967295]
 * TeAP_e_RearSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_SPMActvStat: Integer in interval [0...4294967295]
 * TeAP_e_SPMLatCtrlReqSts: Integer in interval [0...4294967295]
 * TeAutoPark_e_AutoParkStatus: Integer in interval [0...4294967295]
 * TeAutoPark_e_ChimeReq: Integer in interval [0...4294967295]
 * TeAutoPark_e_GearCmd: Integer in interval [0...4294967295]
 * TeAutoPark_e_ScanDir: Integer in interval [0...4294967295]
 * TeEnv_e_NFCDState: Integer in interval [0...4294967295]
 * TeEnv_e_ObjClass: Integer in interval [0...4294967295]
 * TeTHA_e_EPBReq: Integer in interval [0...4294967295]
 * TeTHA_e_PamChimeRepRateSts: Integer in interval [0...4294967295]
 * TeTHA_e_PamChimeTyp: Integer in interval [0...4294967295]
 * TeTHA_e_PamVol: Integer in interval [0...4294967295]
 * TeTHA_e_RearBrkSupprInfo: Integer in interval [0...4294967295]
 * TeTHA_e_ScreenRequest: Integer in interval [0...4294967295]
 * TeTHA_e_THARmpUpDwnSpd: Integer in interval [0...4294967295]
 * TeTHA_e_THASpdLimReq: Integer in interval [0...4294967295]
 * TeTHA_e_THAState: Integer in interval [0...4294967295]
 * TeTHA_e_THAStateInfo: Integer in interval [0...4294967295]
 * TeTHA_e_THASteerTrqReq: Integer in interval [0...4294967295]
 * TeTRSC_e_CamBlockSts: Integer in interval [0...4294967295]
 * TeTRSC_e_DispView2_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_GearShiftSts_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_GraphicOverlay_Sts: Integer in interval [0...4294967295]
 * TeTRSC_e_SpdLmtReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TADState: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCAbortReason_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCLedSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCPopupDispInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCStat: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCStrTrqActvReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCUnavailReas_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSKMBtnSts_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSKMCenBtnSts_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSKMSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSKMSts_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrCalInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrCalInfo_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrHitchLightCtrl: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrPrsntInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrPrsntInfo_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrRecogInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrRecogInfo_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq_DID: Integer in interval [0...4294967295]
 * TeVBII_e_CenterBtnSts: Integer in interval [0...4294967295]
 * TeVBII_e_DrverSecuBltAlrmSts: Integer in interval [0...4294967295]
 * TeVBII_e_EnblBtnSts: Integer in interval [0...4294967295]
 * TeVBII_e_GearEngagedForDsply: Integer in interval [0...4294967295]
 * TrailerAngleSign_t: Integer in interval [0...4294967295]
 * TrailerCalibrationFailInfo_DID_t: Integer in interval [0...4294967295]
 * TrailerCalibrationFailInfo_t: Integer in interval [0...4294967295]
 * TrailerConnectionSts: Integer in interval [0...3]
 * TrailerID_t: Integer in interval [0...4294967295]
 * TrailerPresentInfo_t: Integer in interval [0...4294967295]
 * TransmissionSailingSts: Integer in interval [0...15]
 * TrlrCalInfo_t: Integer in interval [0...4294967295]
 * TurnAroundState_t: Integer in interval [0...4294967295]
 * US_E_Zoneinfo_list_t: Integer in interval [0...4294967295]
 * VIN_MSG: Integer in interval [0...3]
 * aSigConverter_E_DisplayView2_t: Integer in interval [0...4294967295]
 * aSigConverter_E_THAScreenRequest_t: Integer in interval [0...4294967295]
 * aZynqM_E_ModuleState_EOL_STM_t: Integer in interval [0...4294967295]
 * aZynqM_E_ModuleState_OC_STM_t: Integer in interval [0...4294967295]
 * aZynqM_E_ModuleState_SC_STM_t: Integer in interval [0...4294967295]
 * bool_t: Boolean
 * boolean: Boolean (standard type)
 * char_T: Integer in interval [-128...127]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * e_SensorSource: Integer in interval [0...4294967295]
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * real32_T: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint16_t: Integer in interval [-32768...32767]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AP_HMI_ParkSlot_Array: Array with 6 element(s) of type AP_HMI_ParkSlot_t
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * BoundingBox_Real_Array: Array with 4 element(s) of type Float2
 * CameraEepromData_arr: Array with 4 element(s) of type CameraEepromData_t
 * Data1_0B_arr: Array with 400 element(s) of type ErrorMgr_stAddData
 * Data1_0QM_arr: Array with 12 element(s) of type ErrorMgr_stAddData
 * Data2_0B_arr: Array with 144 element(s) of type ErrorMgr_stAddData
 * Data2_0QM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * Data2_1B_arr: Array with 548 element(s) of type ErrorMgr_stAddData
 * Data2_1QM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * DataQNXB_arr: Array with 8 element(s) of type ErrorMgr_stAddData
 * DataQNXQM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * DistanceToClosestPoint_Array: Array with 2 element(s) of type float32
 * EOLIterationData_arr: Array with 5 element(s) of type uint8
 * Error1_0B_arr: Array with 400 element(s) of type ErrorMgr_ErrorField
 * Error1_0QM_arr: Array with 12 element(s) of type ErrorMgr_ErrorField
 * Error2_0B_arr: Array with 144 element(s) of type ErrorMgr_ErrorField
 * Error2_0QM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * Error2_1B_arr: Array with 548 element(s) of type ErrorMgr_ErrorField
 * Error2_1QM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * ErrorQNXB_arr: Array with 8 element(s) of type ErrorMgr_ErrorField
 * ErrorQNXQM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * Float2_Array: Array with 4 element(s) of type Float2
 * IAllowedParkingDirection_Array: Array with 6 element(s) of type IAllowedParkingDirection_t
 * IParkingSlotData_Array: Array with 6 element(s) of type IParkingSlotData_t
 * IobjectSignals_Arr: Array with 6 element(s) of type IobjectSignals_t
 * LeftObjectList_Array: Array with 4 element(s) of type IobjectEdge_t
 * Log_PackedDiagFlagData1_v_Array: Array with 64 element(s) of type uint8
 * Log_PackedDiagFlagData2_v_Array: Array with 64 element(s) of type uint8
 * Log_PackedNoiseMeasData_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData1_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData2_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData3_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData4_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData5_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData6_Array: Array with 64 element(s) of type uint8
 * Log_SnrMeasData7_Array: Array with 64 element(s) of type uint8
 * Log_SnrTemperature_Array: Array with 32 element(s) of type sint16
 * ME_Hydra3defs_E_CalibStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_E_CalibStatus_t
 * ME_Hydra3defs_S_EOLStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_S_EOLStatus_t
 * ME_Hydra3defs_S_OCStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_S_OCStatus_t
 * NFCD_EnvSignals_Array: Array with 10 element(s) of type IaNFCD_e_BlobList
 * ObjectDimensions_Array: Array with 2 element(s) of type float32
 * ObjectPos_Real_Array: Array with 4 element(s) of type Float2
 * Padding2_0QM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * Padding2_1QM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * PaddingQNXQM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * RLDFeatureCountInSubRois_Array: Array with 2 element(s) of type sint32
 * Reserved_arr: Array with 7 element(s) of type uint8
 * RightObjectList_Array: Array with 4 element(s) of type IobjectEdge_t
 * Rte_DT_RunTimeStats_MCU2_0_t_0: Array with 10 element(s) of type uint32
 * Rte_DT_RunTimeStats_MCU2_0_t_1: Array with 6 element(s) of type uint32
 * Rte_DT_RunTimeStats_MCU2_1_t_0: Array with 14 element(s) of type uint32
 * Rte_DT_RunTimeStats_MCU2_1_t_1: Array with 4 element(s) of type uint32
 * Rte_DT_RunTimeStats_MCU2_1_t_2: Array with 4 element(s) of type uint32
 * Rte_DT_StackUsage_MCU2_0_t_0: Array with 5 element(s) of type uint8
 * Rte_DT_StackUsage_MCU2_0_t_1: Array with 3 element(s) of type uint8
 * Rte_DT_StackUsage_MCU2_1_t_0: Array with 6 element(s) of type uint8
 * Rte_DT_StackUsage_MCU2_1_t_1: Array with 2 element(s) of type uint8
 * Rte_DT_StackUsage_MCU2_1_t_2: Array with 2 element(s) of type uint8
 * Rte_DT_laneCoef_2dArray_0: Array with 3 element(s) of type float32
 * Rte_DT_laneCoef_TVG_2dArray_0: Array with 3 element(s) of type float32
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * Sig_Debug_Signal_Arr: Array with 32 element(s) of type sint16
 * SubRois_Array: Array with 2 element(s) of type ColumnRowParams
 * US_E_Zoneinfo_list_Array: Array with 16 element(s) of type US_E_Zoneinfo_list_t
 * US_S_PointOutputBuff_Array: Array with 96 element(s) of type US_S_PointOutputBuff_t
 * Unsig_Debug_Signal_Arr: Array with 32 element(s) of type uint16
 * UssTunningDataOut_arr: Array with 3072 element(s) of type uint8
 * VIN_DATA: Array with 7 element(s) of type uint8
 * coef_img_Array: Array with 3 element(s) of type float32
 * constantStartSequence_ac: Array with 2 element(s) of type char_T
 * eepromMapRevision_au16: Array with 2 element(s) of type uint16
 * endpoints_Array: Array with 2 element(s) of type Float2
 * finalAssemblyDay_ac: Array with 3 element(s) of type char_T
 * finalAssemblyFocusAndAlign_ac: Array with 1 element(s) of type char_T
 * finalAssemblyPartNumber_ac: Array with 16 element(s) of type char_T
 * finalAssemblySerialNumber_ac: Array with 4 element(s) of type char_T
 * finalAssemblyYear_ac: Array with 2 element(s) of type char_T
 * firstReservedBytes_au8: Array with 56 element(s) of type uint8
 * intrinsicAlgoRevision_ac: Array with 16 element(s) of type char_T
 * lanTrack_s_Array: Array with 2 element(s) of type LaneTrackState
 * laneCoef_2dArray: Array with 2 element(s) of type Rte_DT_laneCoef_2dArray_0
 * laneCoef_TVG_2dArray: Array with 2 element(s) of type Rte_DT_laneCoef_TVG_2dArray_0
 * laneCoef_TVG_valid_Array: Array with 2 element(s) of type boolean
 * m_Parkable_Array: Array with 6 element(s) of type boolean
 * midDist_Array: Array with 12 element(s) of type uint16
 * minDist_Array: Array with 16 element(s) of type uint16
 * output_Array: Array with 2 element(s) of type OutLaneInfo
 * para_Array: Array with 10 element(s) of type float32
 * polyImage2World_af32: Array with 6 element(s) of type float32
 * polyWorld2Image_af32: Array with 6 element(s) of type float32
 * productionBoardSerialNumber_ac: Array with 2 element(s) of type char_T
 * productionDay_ac: Array with 3 element(s) of type char_T
 * productionLineNumber_ac: Array with 2 element(s) of type char_T
 * productionSerialNumber_ac: Array with 5 element(s) of type char_T
 * productionYear_ac: Array with 2 element(s) of type char_T
 * reservedBytesIntrinsic_au8: Array with 32 element(s) of type uint8
 * reservedBytes_au8: Array with 16 element(s) of type uint8
 * rev_arr: Array with 2 element(s) of type uint8
 * rsv_Array: Array with 3 element(s) of type uint8
 * secondReservedBytes_au8: Array with 4 element(s) of type uint8
 * stUSSParkingSlotData_Array: Array with 6 element(s) of type IParkingSlotData_t
 * stepArray_Array: Array with 60 element(s) of type LC_LnCup
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
 * AP_HMI_ParkSlot_t: Record with elements
 *   SlotID of type ParkingSlotID_t
 *   SlotType of type ParkingSlotType_t
 *   SlotSelected of type boolean
 *   SlotPixelCoordinate_X of type uint16
 *   SlotPixelCoordinate_Y of type uint16
 * CAM_CS_Curr_Monitor_t: Record with elements
 *   s_Front_CAM_CS_A of type uint8
 *   s_Right_CAM_CS_A of type uint8
 *   s_Left_CAM_CS_A of type uint8
 *   s_Rear_CAM_CS_A of type uint8
 *   s_FreshnessCounter of type uint8
 * CAM_select_info_t: Record with elements
 *   s_Cam_ChId of type uint8
 *   s_Cam_PwrEn_Sts of type uint8
 *   rsvd1 of type uint8
 *   rsvd2 of type uint8
 * CamEepromCrcData_t: Record with elements
 *   crc_u32 of type uint32
 *   firstReservedBytes of type firstReservedBytes_au8
 *   secondReservedBytes of type secondReservedBytes_au8
 * CamEepromIntrinsicData_t: Record with elements
 *   intrinsicAlgoRevision of type intrinsicAlgoRevision_ac
 *   imageWidth_u32 of type uint32
 *   imageHeight_u32 of type uint32
 *   ppx_f32 of type float32
 *   ppy_f32 of type float32
 *   polyImage2World of type polyImage2World_af32
 *   polyWorld2Image of type polyWorld2Image_af32
 *   pixelSizeX_f32 of type float32
 *   pixelSizeY_f32 of type float32
 *   fieldOfView_f32 of type float32
 *   effectiveFocalLength_f32 of type float32
 *   reservedBytes of type reservedBytesIntrinsic_au8
 * CamEepromProductionData_t: Record with elements
 *   constantStartSequence of type constantStartSequence_ac
 *   magnaSerialNumber_s of type MagnaSerialNumber_t
 *   finalAssemblySerialNumber_s of type FinalAssemblySerialNumber_t
 *   finalAssemblyPartNumber of type finalAssemblyPartNumber_ac
 *   eepromMapRevision of type eepromMapRevision_au16
 *   reservedBytes of type reservedBytes_au8
 * Cam_and_Ser_EN_Status_t: Record with elements
 *   Cam1_en_stat of type uint8
 *   Cam2_en_stat of type uint8
 *   Cam3_en_stat of type uint8
 *   Cam4_en_stat of type uint8
 *   SER_en_stat of type uint8
 * CameraEepromData_t: Record with elements
 *   camProductionData_s of type CamEepromProductionData_t
 *   camIntrinsicData_s of type CamEepromIntrinsicData_t
 *   camCrcData_s of type CamEepromCrcData_t
 * ColumnRowParams: Record with elements
 *   START_ROW of type sint32
 *   END_ROW of type sint32
 *   START_COL of type sint32
 *   END_COL of type sint32
 * CpuLoadMcu2_0_t: Record with elements
 *   CpluLoad_MCU2_0_u32 of type uint32
 * CpuLoadMcu2_1_t: Record with elements
 *   CpluLoad_MCU2_1_u32 of type uint32
 * CurveModel: Record with elements
 *   C0 of type float32
 *   C1 of type float32
 *   C2 of type float32
 * DebugDumpAlgo: Record with elements
 *   o_ProcessRoi of type Rois
 *   o_egoLaneModel of type LC_LnModel
 *   imgWidth of type uint32
 *   imgHeight of type uint32
 *   showLaneInfo of type boolean
 * Debug_HMI_Curr_Displayed_Overlays: Record with elements
 *   TopRearButtonSelect_b of type uint8
 *   TopRearButtonNoSelect_b of type uint8
 *   RearCrossButtonSelect_b of type uint8
 *   RearCrossButtonNoSelect_b of type uint8
 *   FrontCrossButtonSelect_b of type uint8
 *   FrontCrossButtonNoSelect_b of type uint8
 *   TopFrontButtonNoSelect_b of type uint8
 *   TopFrontButtonSelect_b of type uint8
 *   BackupRearCamButtonNoSelect_b of type uint8
 *   BackupRearCamButtonSelect_b of type uint8
 *   FrontFaceCamButtonNoSelect_b of type uint8
 *   FrontFaceCamButtonSelect_b of type uint8
 *   AuxCamButton1NoSelect_b of type uint8
 *   AuxCamButton1Select_b of type uint8
 *   AuxCamButton2NoSelect_b of type uint8
 *   AuxCamButton2Select_b of type uint8
 *   MoreCamsButton1NoSelect_b of type uint8
 *   MoreCamsButton1Select_b of type uint8
 *   MoreCamsButton2NoSelect_b of type uint8
 *   MoreCamsButton2Select_b of type uint8
 *   XIcon_b of type uint8
 *   Frameset1AndTopRearText_b of type uint8
 *   Frameset1AndTopFrontText_b of type uint8
 *   Frameset2AndRearCrossText_b of type uint8
 *   Frameset2AndFrontCrossText_b of type uint8
 *   ZoomPlus_Selectable_b of type uint8
 *   ZoomPlus_Not_Selectable_b of type uint8
 *   ZoomMinus_Selectable_b of type uint8
 *   ZoomMinus_Not_Selectable_b of type uint8
 *   MoreCamsIconFullScreenNoSelect_b of type uint8
 *   Auto_NoSelect_b of type uint8
 *   Auto_Select_b of type uint8
 *   TopViewFrontDynamics_b of type uint8
 *   FrontViewDynamics_b of type uint8
 *   TopViewRearDynamics_b of type uint8
 *   RearViewDynamics_b of type uint8
 *   FrontTireTracks_b of type uint8
 *   BackDoorClose_Icon_b of type uint8
 *   RightDoorRearClose_Icon_b of type uint8
 *   RightDoorFrontClose_Icon_b of type uint8
 *   LeftDoorRearClose_Icon_b of type uint8
 *   LeftDoorFrontClose_Icon_b of type uint8
 *   BackDoorOpen_Icon_b of type uint8
 *   RightDoorRearOpen_Icon_b of type uint8
 *   RightDoorFrontOpen_Icon_b of type uint8
 *   LeftDoorRearOpen_Icon_b of type uint8
 *   LeftDoorFrontOpen_Icon_b of type uint8
 *   TopViewBlack_b of type uint8
 *   RightCam_NA_b of type uint8
 *   BackCam_NA_b of type uint8
 *   LeftCam_NA_b of type uint8
 *   FrontCam_NA_b of type uint8
 *   DefaultEngLang_b of type uint8
 *   EnableStaticGuidelines_b of type uint8
 *   DoorSigFault_b of type uint8
 *   Reserved_15_b of type uint8
 *   TRSC_TrailerRed of type uint8
 *   TRSC_Enable of type uint8
 *   THA_Updated_b of type uint8
 *   THA_ProgressBar of type uint8
 *   THA_StartButton of type uint8
 *   THA_ConfirmButton of type uint8
 *   THA_ButtonSelectable of type uint8
 *   THA_ButtonGrey of type uint8
 *   THA_CouplerBulletIcon of type uint8
 *   THA_TriangleOverlay of type uint8
 *   PDC_RearLeft_Red_b of type uint8
 *   PDC_RearLeft_Yellow_b of type uint8
 *   PDC_RearRight_Red_b of type uint8
 *   PDC_RearRight_Yellow_b of type uint8
 *   PDC_RearCenter_Red_b of type uint8
 *   PDC_RearCenter_Yellow_b of type uint8
 *   PDC_FrontLeft_Red_b of type uint8
 *   PDC_FrontLeft_Yellow_b of type uint8
 *   PDC_FrontRight_Red_b of type uint8
 *   PDC_FrontRight_Yellow_b of type uint8
 *   PDC_FrontCenter_Red_b of type uint8
 *   PDC_FrontCenter_Yellow_b of type uint8
 *   AP_BackBtn of type uint8
 *   AP_ParkBtn_Selected of type uint8
 *   AP_ParkBtn_Not_Selected of type uint8
 *   AP_ExitBtn_Selected of type uint8
 *   AP_ExitBtn_Not_Selected of type uint8
 *   AP_Disclaimer_Core of type uint8
 *   AP_BG_Main of type uint8
 *   AP_Para_Exit_Core of type uint8
 *   AP_Forward_LeftBtn_Selected of type uint8
 *   AP_Forward_LeftBtn_Not_Selected of type uint8
 *   AP_Forward_RightBtn_Selected of type uint8
 *   AP_Forward_RightBtn_Not_Selected of type uint8
 *   AP_Perp_Right_Core of type uint8
 *   AP_Perp_Left_Core of type uint8
 *   AP_RearInBtn_Not_Selected of type uint8
 *   AP_RearInBtn_Selected of type uint8
 *   AP_FrontInBtn_Not_Selected of type uint8
 *   AP_FrontInBtn_Selected of type uint8
 *   AP_RearInBtn_Not_Avail of type uint8
 *   AP_FrontInBtn_Not_Avail of type uint8
 *   AP_Parkout_Done of type uint8
 *   AP_ParkIn_Done of type uint8
 *   AP_Scanning_Core of type uint8
 *   AP_Grey_Banner1 of type uint8
 *   AP_Grey_Banner2 of type uint8
 *   AP_Scan_Select_Space_Text of type uint8
 *   AP_Scan_Space_Found_Text of type uint8
 *   AP_Scan_STOP_Text of type uint8
 *   AP_Scan_Searching_Text of type uint8
 *   AP_Scan_Keep_Moving_Forward_Text of type uint8
 *   AP_Scan_Reduce_Speed_Text of type uint8
 *   AP_FullscreenText_Updated of type uint8
 *   AP_ParksenseUnavailable of type uint8
 *   AP_TopBlackBannerUpdated of type uint8
 *   AP_BottomBlackBannerUpdated of type uint8
 *   AP_RedBannerUpdated of type uint8
 *   AP_ParkSlots_Updated of type uint8
 *   SrvPrgBar999Per_b of type uint8
 *   SrvPrgBar100Per_b of type uint8
 *   SrvPrgBar75Per_b of type uint8
 *   SrvPrgBar50Per_b of type uint8
 *   SrvPrgBar25Per_b of type uint8
 *   SrvPrgBar0Per_b of type uint8
 *   SrvCamIndRiNone_b of type uint8
 *   SrvCamIndRiPend_b of type uint8
 *   SrvCamIndRiNok_b of type uint8
 *   SrvCamIndRiOk_b of type uint8
 *   SrvCamIndBaNone_b of type uint8
 *   SrvCamIndBaPend_b of type uint8
 *   SrvCamIndBaNok_b of type uint8
 *   SrvCamIndBaOk_b of type uint8
 *   SrvCamIndLeNone_b of type uint8
 *   SrvCamIndLePend_b of type uint8
 *   SrvCamIndLeNok_b of type uint8
 *   SrvCamIndLeOk_b of type uint8
 *   SrvCamIndFrNone_b of type uint8
 *   SrvCamIndFrPend_b of type uint8
 *   SrvCamIndFrNok_b of type uint8
 *   SrvCamIndFrOk_b of type uint8
 *   SrvChkIndCondNok_b of type uint8
 *   SrvChkIndNok_b of type uint8
 *   SrvChkIndOk_b of type uint8
 *   SrvChkIndRun_b of type uint8
 *   SrvSpOmIndNok_b of type uint8
 *   SrvSpOmIndOk_b of type uint8
 *   SrvStAngIndNok_b of type uint8
 *   SrvStAngIndOk_b of type uint8
 *   SrvLayout_b of type uint8
 *   Reserved_01_b of type uint8
 *   Reserved_02_b of type uint8
 *   Reserved_03_b of type uint8
 *   Reserved_04_b of type uint8
 *   Reserved_05_b of type uint8
 *   Reserved_06_b of type uint8
 *   Reserved_07_b of type uint8
 *   Reserved_08_b of type uint8
 *   Reserved_09_b of type uint8
 *   Reserved_10_b of type uint8
 *   Reserved_11_b of type uint8
 *   Reserved_12_b of type uint8
 *   Reserved_13_b of type uint8
 *   Reserved_14_b of type uint8
 *   OneCam_ZoomPlus_Selectable_b of type uint8
 *   OneCam_ZoomPlus_Not_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Not_Selectable_b of type uint8
 *   OneCam_AuxCamButtonSelect_b of type uint8
 *   OneCam_AuxCamButtonNoSelect_b of type uint8
 * Debug_HMI_Curr_Displayed_ProxiConfig: Record with elements
 *   MePRX_e_VariantID of type uint8
 *   MePRX_e_VehLineCfg of type uint8
 *   MePRX_e_Wheelbase of type uint8
 *   MePRX_e_SteerRatRackPinionType of type uint8
 *   MePRX_e_RadDispType of type uint8
 *   MePRX_e_MirrorType of type uint8
 *   MePRX_e_PAMTunSet of type uint8
 *   MePRX_e_AutonomyLvl of type uint8
 *   MePRX_b_SurroundViewCamera of type boolean
 *   MePRX_b_FrwFacingCam of type boolean
 *   MePRX_b_AuxTrlrCam of type boolean
 *   MePRX_b_CANNode95 of type boolean
 *   MePRX_b_CanNode27 of type boolean
 *   MePRX_b_TRGPresence of type boolean
 *   MePRX_b_TRSCPresence of type boolean
 * Debug_HMI_Curr_Requested_Overlays: Record with elements
 *   TopRearButtonSelect_b of type uint8
 *   TopRearButtonNoSelect_b of type uint8
 *   RearCrossButtonSelect_b of type uint8
 *   RearCrossButtonNoSelect_b of type uint8
 *   FrontCrossButtonSelect_b of type uint8
 *   FrontCrossButtonNoSelect_b of type uint8
 *   TopFrontButtonNoSelect_b of type uint8
 *   TopFrontButtonSelect_b of type uint8
 *   BackupRearCamButtonNoSelect_b of type uint8
 *   BackupRearCamButtonSelect_b of type uint8
 *   FrontFaceCamButtonNoSelect_b of type uint8
 *   FrontFaceCamButtonSelect_b of type uint8
 *   AuxCamButton1NoSelect_b of type uint8
 *   AuxCamButton1Select_b of type uint8
 *   AuxCamButton2NoSelect_b of type uint8
 *   AuxCamButton2Select_b of type uint8
 *   MoreCamsButton1NoSelect_b of type uint8
 *   MoreCamsButton1Select_b of type uint8
 *   MoreCamsButton2NoSelect_b of type uint8
 *   MoreCamsButton2Select_b of type uint8
 *   XIcon_b of type uint8
 *   Frameset1AndTopRearText_b of type uint8
 *   Frameset1AndTopFrontText_b of type uint8
 *   Frameset2AndRearCrossText_b of type uint8
 *   Frameset2AndFrontCrossText_b of type uint8
 *   ZoomPlus_Selectable_b of type uint8
 *   ZoomPlus_Not_Selectable_b of type uint8
 *   ZoomMinus_Selectable_b of type uint8
 *   ZoomMinus_Not_Selectable_b of type uint8
 *   MoreCamsIconFullScreenNoSelect_b of type uint8
 *   Auto_NoSelect_b of type uint8
 *   Auto_Select_b of type uint8
 *   TopViewFrontDynamics_b of type uint8
 *   FrontViewDynamics_b of type uint8
 *   TopViewRearDynamics_b of type uint8
 *   RearViewDynamics_b of type uint8
 *   FrontTireTracks_b of type uint8
 *   BackDoorClose_Icon_b of type uint8
 *   RightDoorRearClose_Icon_b of type uint8
 *   RightDoorFrontClose_Icon_b of type uint8
 *   LeftDoorRearClose_Icon_b of type uint8
 *   LeftDoorFrontClose_Icon_b of type uint8
 *   BackDoorOpen_Icon_b of type uint8
 *   RightDoorRearOpen_Icon_b of type uint8
 *   RightDoorFrontOpen_Icon_b of type uint8
 *   LeftDoorRearOpen_Icon_b of type uint8
 *   LeftDoorFrontOpen_Icon_b of type uint8
 *   TopViewBlack_b of type uint8
 *   RightCam_NA_b of type uint8
 *   BackCam_NA_b of type uint8
 *   LeftCam_NA_b of type uint8
 *   FrontCam_NA_b of type uint8
 *   DefaultEngLang_b of type uint8
 *   EnableStaticGuidelines_b of type uint8
 *   DoorSigFault_b of type uint8
 *   Reserved_15_b of type uint8
 *   TRSC_TrailerRed of type uint8
 *   TRSC_Enable of type uint8
 *   THA_Updated_b of type uint8
 *   THA_ProgressBar of type uint8
 *   THA_StartButton of type uint8
 *   THA_ConfirmButton of type uint8
 *   THA_ButtonSelectable of type uint8
 *   THA_ButtonGrey of type uint8
 *   THA_CouplerBulletIcon of type uint8
 *   THA_TriangleOverlay of type uint8
 *   PDC_RearLeft_Red_b of type uint8
 *   PDC_RearLeft_Yellow_b of type uint8
 *   PDC_RearRight_Red_b of type uint8
 *   PDC_RearRight_Yellow_b of type uint8
 *   PDC_RearCenter_Red_b of type uint8
 *   PDC_RearCenter_Yellow_b of type uint8
 *   PDC_FrontLeft_Red_b of type uint8
 *   PDC_FrontLeft_Yellow_b of type uint8
 *   PDC_FrontRight_Red_b of type uint8
 *   PDC_FrontRight_Yellow_b of type uint8
 *   PDC_FrontCenter_Red_b of type uint8
 *   PDC_FrontCenter_Yellow_b of type uint8
 *   AP_BackBtn of type uint8
 *   AP_ParkBtn_Selected of type uint8
 *   AP_ParkBtn_Not_Selected of type uint8
 *   AP_ExitBtn_Selected of type uint8
 *   AP_ExitBtn_Not_Selected of type uint8
 *   AP_Disclaimer_Core of type uint8
 *   AP_BG_Main of type uint8
 *   AP_Para_Exit_Core of type uint8
 *   AP_Forward_LeftBtn_Selected of type uint8
 *   AP_Forward_LeftBtn_Not_Selected of type uint8
 *   AP_Forward_RightBtn_Selected of type uint8
 *   AP_Forward_RightBtn_Not_Selected of type uint8
 *   AP_Perp_Right_Core of type uint8
 *   AP_Perp_Left_Core of type uint8
 *   AP_RearInBtn_Not_Selected of type uint8
 *   AP_RearInBtn_Selected of type uint8
 *   AP_FrontInBtn_Not_Selected of type uint8
 *   AP_FrontInBtn_Selected of type uint8
 *   AP_RearInBtn_Not_Avail of type uint8
 *   AP_FrontInBtn_Not_Avail of type uint8
 *   AP_Parkout_Done of type uint8
 *   AP_ParkIn_Done of type uint8
 *   AP_Scanning_Core of type uint8
 *   AP_Grey_Banner1 of type uint8
 *   AP_Grey_Banner2 of type uint8
 *   AP_Scan_Select_Space_Text of type uint8
 *   AP_Scan_Space_Found_Text of type uint8
 *   AP_Scan_STOP_Text of type uint8
 *   AP_Scan_Searching_Text of type uint8
 *   AP_Scan_Keep_Moving_Forward_Text of type uint8
 *   AP_Scan_Reduce_Speed_Text of type uint8
 *   AP_FullscreenText_Updated of type uint8
 *   AP_ParksenseUnavailable of type uint8
 *   AP_TopBlackBannerUpdated of type uint8
 *   AP_BottomBlackBannerUpdated of type uint8
 *   AP_RedBannerUpdated of type uint8
 *   AP_ParkSlots_Updated of type uint8
 *   SrvPrgBar999Per_b of type uint8
 *   SrvPrgBar100Per_b of type uint8
 *   SrvPrgBar75Per_b of type uint8
 *   SrvPrgBar50Per_b of type uint8
 *   SrvPrgBar25Per_b of type uint8
 *   SrvPrgBar0Per_b of type uint8
 *   SrvCamIndRiNone_b of type uint8
 *   SrvCamIndRiPend_b of type uint8
 *   SrvCamIndRiNok_b of type uint8
 *   SrvCamIndRiOk_b of type uint8
 *   SrvCamIndBaNone_b of type uint8
 *   SrvCamIndBaPend_b of type uint8
 *   SrvCamIndBaNok_b of type uint8
 *   SrvCamIndBaOk_b of type uint8
 *   SrvCamIndLeNone_b of type uint8
 *   SrvCamIndLePend_b of type uint8
 *   SrvCamIndLeNok_b of type uint8
 *   SrvCamIndLeOk_b of type uint8
 *   SrvCamIndFrNone_b of type uint8
 *   SrvCamIndFrPend_b of type uint8
 *   SrvCamIndFrNok_b of type uint8
 *   SrvCamIndFrOk_b of type uint8
 *   SrvChkIndCondNok_b of type uint8
 *   SrvChkIndNok_b of type uint8
 *   SrvChkIndOk_b of type uint8
 *   SrvChkIndRun_b of type uint8
 *   SrvSpOmIndNok_b of type uint8
 *   SrvSpOmIndOk_b of type uint8
 *   SrvStAngIndNok_b of type uint8
 *   SrvStAngIndOk_b of type uint8
 *   SrvLayout_b of type uint8
 *   Reserved_01_b of type uint8
 *   Reserved_02_b of type uint8
 *   Reserved_03_b of type uint8
 *   Reserved_04_b of type uint8
 *   Reserved_05_b of type uint8
 *   Reserved_06_b of type uint8
 *   Reserved_07_b of type uint8
 *   Reserved_08_b of type uint8
 *   Reserved_09_b of type uint8
 *   Reserved_10_b of type uint8
 *   Reserved_11_b of type uint8
 *   Reserved_12_b of type uint8
 *   Reserved_13_b of type uint8
 *   Reserved_14_b of type uint8
 *   OneCam_ZoomPlus_Selectable_b of type uint8
 *   OneCam_ZoomPlus_Not_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Not_Selectable_b of type uint8
 *   OneCam_AuxCamButtonSelect_b of type uint8
 *   OneCam_AuxCamButtonNoSelect_b of type uint8
 * Debug_HMI_Curr_Requested_ProxiConfig: Record with elements
 *   MePRX_e_VariantID of type uint8
 *   MePRX_e_VehLineCfg of type uint8
 *   MePRX_e_Wheelbase of type uint8
 *   MePRX_e_SteerRatRackPinionType of type uint8
 *   MePRX_e_RadDispType of type uint8
 *   MePRX_e_MirrorType of type uint8
 *   MePRX_e_PAMTunSet of type uint8
 *   MePRX_e_AutonomyLvl of type uint8
 *   MePRX_b_SurroundViewCamera of type boolean
 *   MePRX_b_FrwFacingCam of type boolean
 *   MePRX_b_AuxTrlrCam of type boolean
 *   MePRX_b_CANNode95 of type boolean
 *   MePRX_b_CanNode27 of type boolean
 *   MePRX_b_TRGPresence of type boolean
 *   MePRX_b_TRSCPresence of type boolean
 * Debug_HMI_Input_Data_t: Record with elements
 *   steeringWheelAngle_f32 of type float32
 *   vehicleSpeed_f32 of type float32
 *   lrwsST_e of type uint32
 *   revGear_e of type uint32
 *   trscStat_e of type uint32
 *   NetCfg_TRSCM_e of type uint32
 *   ignitionStatus_e of type uint32
 *   transEquipped_e of type uint32
 *   prndStatus_e of type uint32
 *   CameraDisplaySts2_e of type uint32
 *   tgwDispStatus_e of type uint32
 *   ImageDefeat_Error_e of type uint32
 *   SoftBtn_Error_e of type uint32
 *   DynOvl_Error_e of type uint32
 *   View_Error_e of type uint32
 *   tchScrnStatus_e of type uint32
 *   tchScrnCoordX_s of type uint16
 *   tchScrnCoordY_s of type uint16
 *   CAM_NA_Bitfield_u8 of type uint8
 *   vehicleLine_e of type uint8
 *   LanguageSelection_u8 of type uint8
 *   TopVideoBlanked_b of type boolean
 *   SVC_Dynamic_Gridlines_Feature_b of type boolean
 *   SVC_Static_Gridlines_Feature_b of type boolean
 *   SVC_FFCV_Gridlines_Feature_b of type boolean
 *   SVC_Delay_Feature_b of type boolean
 *   GW_C_I6_timeout_b of type boolean
 * Debug_HMI_Internal_Data_t: Record with elements
 *   M_BURV_Memory_e of type uint32
 *   M_FFClatch_e of type uint32
 *   Curr_SystemState_e of type uint32
 *   Prev_SystemState_e of type uint32
 *   Curr_RequestedViewByHmiM_e of type uint32
 *   Prev_RequestedViewByHmiM_e of type uint32
 *   Curr_DisplayedViewByAcore_e of type uint32
 *   Prev_DisplayedViewByAcore_e of type uint32
 *   LastViewBeforeTestPattern_e of type uint32
 *   ZoomFactor_u8 of type uint8
 *   IgnoreVehicleOffSpeed of type boolean
 *   X_BTN_PRESSED_b of type boolean
 *   MAGNIFIER_BTN_PRESSED_b of type boolean
 *   REAR_TOP_BTN_PRESSED_b of type boolean
 *   FRONT_TOP_BTN_PRESSED_b of type boolean
 *   REAR_CROSS_BTN_PRESSED_b of type boolean
 *   FRONT_CROSS_BTN_PRESSED_b of type boolean
 *   FFCV_BTN_PRESSED_b of type boolean
 *   RVCONLY_BTN_PRESSED_b of type boolean
 *   VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b of type boolean
 *   VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b of type boolean
 *   VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b of type boolean
 *   VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b of type boolean
 * Debug_HMI_ProxiConfig_t: Record with elements
 *   MePRX_e_VariantID of type uint8
 *   MePRX_e_VehLineCfg of type uint8
 *   MePRX_e_Wheelbase of type uint8
 *   MePRX_e_SteerRatRackPinionType of type uint8
 *   MePRX_e_RadDispType of type uint8
 *   MePRX_e_MirrorType of type uint8
 *   MePRX_e_PAMTunSet of type uint8
 *   MePRX_e_AutonomyLvl of type uint8
 *   MePRX_b_SurroundViewCamera of type boolean
 *   MePRX_b_FrwFacingCam of type boolean
 *   MePRX_b_AuxTrlrCam of type boolean
 *   MePRX_b_CANNode95 of type boolean
 *   MePRX_b_CanNode27 of type boolean
 *   MePRX_b_TRGPresence of type boolean
 *   MePRX_b_TRSCPresence of type boolean
 * Debug_HMI_Trailer_Views_Data_t: Record with elements
 *   TadAngle of type float32
 *   MaxTadAngle of type float32
 *   KnobAngle of type float32
 *   JackKnifeAngle of type float32
 *   TrscStatus of type uint32
 *   TrailerAngleSign of type uint32
 *   TrailerCalibrationStatus of type uint32
 *   Curr_TRG_Stat of type uint32
 *   Prev_TRG_Stat of type uint32
 *   M_CPLR_POS_X_u of type uint8
 *   M_CPLR_POS_Y_u of type uint8
 *   M_Cplr_Htch_Distance of type uint8
 *   M_Progress_Bar_Distance of type uint8
 *   M_Maneuver_Initial_Run of type uint8
 *   M_Progress_Bar_Percentage of type uint8
 *   M_Current_THA_State_On_Zync of type uint8
 *   M_Current_THA_State_On_Screen of type uint8
 *   M_Requested_THA_State of type uint8
 *   TrailerWheelBase of type uint8
 *   TrailerConnectionStatus of type uint8
 *   ItbmTrailerStatus of type uint8
 *   M_VIEW_ZOOM_STS_b of type boolean
 *   M_VIEW_SCRN_TCH_STS_b of type boolean
 *   M_CONFIRM_BTN_PRESSED_b of type boolean
 *   M_START_BTN_PRESSED_b of type boolean
 *   M_THA_SFT_BTN_PRESSED_b of type boolean
 *   aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b of type boolean
 *   aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b of type boolean
 *   aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b of type boolean
 * Detection_Inputs_from_TRSC_t: Record with elements
 *   MeTRSC_e_TRSCStat of type TeTRSC_e_TRSCStat
 *   MeTRSC_deg_JackKnifeAngle of type real32_T
 *   MeTRSC_m_TrailerBeamLen of type real32_T
 *   MeTRSC_e_TrlrPrsntInfoCAN of type TeTRSC_e_TrlrPrsntInfo
 *   MeTRSC_b_TRSCSwitchPressed of type boolean
 *   MeTRSC_b_OTBLReset of type boolean
 *   MeTRSC_b_TBLComputationDone of type boolean
 *   dummy of type boolean
 * ErrorMgr_ErrorCommPack_1_0_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error1_0B_arr
 *   Data of type Data1_0B_arr
 * ErrorMgr_ErrorCommPack_1_0_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error1_0QM_arr
 *   Data of type Data1_0QM_arr
 * ErrorMgr_ErrorCommPack_2_0_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_0B_arr
 *   Data of type Data2_0B_arr
 * ErrorMgr_ErrorCommPack_2_0_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_0QM_arr
 *   Padding of type Padding2_0QM_arr
 *   Data of type Data2_0QM_arr
 * ErrorMgr_ErrorCommPack_2_1_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_1B_arr
 *   Data of type Data2_1B_arr
 * ErrorMgr_ErrorCommPack_2_1_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_1QM_arr
 *   Padding of type Padding2_1QM_arr
 *   Data of type Data2_1QM_arr
 * ErrorMgr_ErrorCommPack_QNX_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type ErrorQNXB_arr
 *   Data of type DataQNXB_arr
 * ErrorMgr_ErrorCommPack_QNX_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type ErrorQNXQM_arr
 *   Padding of type PaddingQNXQM_arr
 *   Data of type DataQNXQM_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * Error_Fault_MCU2_0_t: Record with elements
 *   Err_FaultInfo_MCU2_0 of type uint16
 *   Err_FaultNum_MCU2_0 of type uint8
 *   Reserved of type uint8
 * Error_Fault_MCU2_1_t: Record with elements
 *   Err_FaultInfo_MCU2_1 of type uint16
 *   Err_FaultNum_MCU2_1 of type uint8
 *   Reserved of type uint8
 * Error_Fault_MPU1_0_t: Record with elements
 *   Err_FaultInfo_MPU1_0 of type uint16
 *   Err_FaultNum_MPU1_0 of type uint8
 *   Reserved of type uint8
 * FinalAssemblySerialNumber_t: Record with elements
 *   finalAssemblyYear of type finalAssemblyYear_ac
 *   finalAssemblyDay of type finalAssemblyDay_ac
 *   finalAssemblySerialNumber of type finalAssemblySerialNumber_ac
 *   finalAssemblyFocusAndAlign of type finalAssemblyFocusAndAlign_ac
 * Float2: Record with elements
 *   x of type float32
 *   y of type float32
 * IDebug_FODObject_t: Record with elements
 *   Debug_FODObjectInfo_s of type IobjectSignals_Arr
 *   IeVBII_nfcd_MinDistanceToCollisionObject of type float32
 *   latDistance_f32 of type float32
 *   longiDistance_f32 of type float32
 *   vehiclePosX1_f32 of type float32
 *   vehiclePosY1_f32 of type float32
 *   vehiclePosX2_f32 of type float32
 *   vehiclePosY2_f32 of type float32
 *   IeFOD_e_FODConfidence of type float32
 *   IeVBII_cnt_nfcd_currDetection of type uint8
 * IFOD_Outputs_Arbitration_t: Record with elements
 *   IeFOD_e_FODStatus of type uint8
 *   MeFOD_e_USSFiringMode of type uint8
 *   IeFOD_b_ResetKM of type boolean
 * IFOD_Outputs_CVPAMFDData_t: Record with elements
 *   IeFOD_e_FODHealth of type uint32
 *   IeFOD_e_FODConfidence of type uint32
 * IFPAInfoToHMI_t: Record with elements
 *   stFPAParkingSlotData of type IParkingSlotData_Array
 *   stFPALockedSlotData of type IParkingSlotData_t
 *   LockedSlotWidth of type float32
 *   LockedSlotDepth of type float32
 *   m_Parkable of type m_Parkable_Array
 *   m_ParkableInDIrection of type IAllowedParkingDirection_Array
 *   ParkOutEnableFlag of type boolean
 * IFPAInfoToPLD_t: Record with elements
 *   PLDSlotID of type ParkingSlotID_t
 * IFPAInfoToUSSOM_t: Record with elements
 *   USSOMSlotID of type ParkingSlotID_t
 *   ParkOutSlotData of type IParkingSlotData_t
 * IFPAInfoToVC_t: Record with elements
 *   stFPALockedSlotData of type IParkingSlotData_t
 *   LockedSlotWidth of type float32
 *   LockedSlotDepth of type float32
 *   parkOutStyle of type ParkOutStyle_t
 * IJobFPAOutput_t: Record with elements
 *   AutoParkInitializedStatus_b of type boolean
 *   m_FpaInfoToVC of type IFPAInfoToVC_t
 *   m_FPAInfoToPLD of type IFPAInfoToPLD_t
 *   m_FPAInfoToUSSOM of type IFPAInfoToUSSOM_t
 *   m_FPAInfoToHMI of type IFPAInfoToHMI_t
 *   m_FPAToNVM of type INVMSignalManager_t
 * IJobPLDOutput_t: Record with elements
 *   isPLDInitSuccess_b of type boolean
 *   stPLDParkingSlotData of type IParkingSlotData_Array
 *   stPLDLockedSlotData of type IParkingSlotData_t
 * IJobUSSObjectMapOutput_t: Record with elements
 *   isUSSOMInitSuccess_b of type boolean
 *   stUSSParkingSlotData of type stUSSParkingSlotData_Array
 *   numPointsL of type uint16
 *   numPointsR of type uint16
 *   LeftObjectList of type LeftObjectList_Array
 *   RightObjectList of type RightObjectList_Array
 *   stUSSLockedSlotData of type IParkingSlotData_t
 * ILMD_Outputs_ADASFDLANES1_t: Record with elements
 *   IeLMD_e_FrameIndexLanes1 of type uint64
 *   IeLMD_e_CntrAdasFdLanes1 of type uint64
 *   IeLMD_e_Line1Confidence of type float32
 *   IeLMD_e_Line2Confidence of type float32
 *   IeLMD_e_Line3Confidence of type float32
 *   IeLMD_e_Line4Confidence of type float32
 *   IeLMD_m_Line1Offset of type float32
 *   IeLMD_m_Line2Offset of type float32
 *   IeLMD_m_Line3Offset of type float32
 *   IeLMD_m_Line4Offset of type float32
 *   IeLMD_rad_Line1Heading of type float32
 *   IeLMD_rad_Line2Heading of type float32
 *   IeLMD_rad_Line3Heading of type float32
 *   IeLMD_rad_Line4Heading of type float32
 *   IeLMD_m_Line1StartRange of type float32
 *   IeLMD_m_Line2StartRange of type float32
 *   IeLMD_m_Line3StartRange of type float32
 *   IeLMD_m_Line4StartRange of type float32
 *   IeLMD_m_Line1EndRange of type float32
 *   IeLMD_m_Line2EndRange of type float32
 *   IeLMD_m_Line3EndRange of type float32
 *   IeLMD_m_Line4EndRange of type float32
 *   IeLMD_e_Line1Curvature of type float32
 *   IeLMD_e_Line2Curvature of type float32
 *   IeLMD_e_Line3Curvature of type float32
 *   IeLMD_e_Line4Curvature of type float32
 *   IeLMD_e_Line1CurvatureRate of type float32
 *   IeLMD_e_Line2CurvatureRate of type float32
 *   IeLMD_e_Line3CurvatureRate of type float32
 *   IeLMD_e_Line4CurvatureRate of type float32
 *   IeLMD_e_Line1Type of type LaneType_t
 *   IeLMD_e_Line2Type of type LaneType_t
 *   IeLMD_e_Line3Type of type LaneType_t
 *   IeLMD_e_Line4Type of type LaneType_t
 *   IeLMD_e_LaneDetectionHealth of type LaneDetHealth_t
 *   IeLMD_e_CameraStatus of type CameraStatus_t
 *   IeLMD_e_CrcAdasFdLanes1 of type uint16
 *   IeLMD_e_MsgCntrAdasFdLanes1 of type uint8
 *   IeLMD_e_MacAdasFdLanes1 of type uint8
 *   IeLMD_e_ReservedForFunctionalSafety1 of type uint8
 *   Dummy1_1_b of type uint8
 *   Dummy2_1_b of type uint8
 *   Dummy3_1_b of type uint8
 * ILMD_Outputs_ADASFDLANES2_t: Record with elements
 *   IeLMD_e_FrameIndexLanes2 of type uint64
 *   IeLMD_e_CntrAdasFdLanes2 of type uint64
 *   IeLMD_e_LineSeg1Conf of type float32
 *   IeLMD_e_LineSeg2Conf of type float32
 *   IeLMD_e_LineSeg3Conf of type float32
 *   IeLMD_e_LineSeg4Conf of type float32
 *   IeLMD_e_LineSeg5Conf of type float32
 *   IeLMD_e_LineSeg6Conf of type float32
 *   IeLMD_e_LineSeg7Conf of type float32
 *   IeLMD_e_LineSeg8Conf of type float32
 *   IeLMD_m_LineSeg1X1 of type float32
 *   IeLMD_m_LineSeg2X1 of type float32
 *   IeLMD_m_LineSeg3X1 of type float32
 *   IeLMD_m_LineSeg4X1 of type float32
 *   IeLMD_m_LineSeg5X1 of type float32
 *   IeLMD_m_LineSeg6X1 of type float32
 *   IeLMD_m_LineSeg7X1 of type float32
 *   IeLMD_m_LineSeg8X1 of type float32
 *   IeLMD_m_LineSeg1X2 of type float32
 *   IeLMD_m_LineSeg2X2 of type float32
 *   IeLMD_m_LineSeg3X2 of type float32
 *   IeLMD_m_LineSeg4X2 of type float32
 *   IeLMD_m_LineSeg5X2 of type float32
 *   IeLMD_m_LineSeg6X2 of type float32
 *   IeLMD_m_LineSeg7X2 of type float32
 *   IeLMD_m_LineSeg8X2 of type float32
 *   IeLMD_m_LineSeg1Y1 of type float32
 *   IeLMD_m_LineSeg2Y1 of type float32
 *   IeLMD_m_LineSeg3Y1 of type float32
 *   IeLMD_m_LineSeg4Y1 of type float32
 *   IeLMD_m_LineSeg5Y1 of type float32
 *   IeLMD_m_LineSeg6Y1 of type float32
 *   IeLMD_m_LineSeg7Y1 of type float32
 *   IeLMD_m_LineSeg8Y1 of type float32
 *   IeLMD_m_LineSeg1Y2 of type float32
 *   IeLMD_m_LineSeg2Y2 of type float32
 *   IeLMD_m_LineSeg3Y2 of type float32
 *   IeLMD_m_LineSeg4Y2 of type float32
 *   IeLMD_m_LineSeg5Y2 of type float32
 *   IeLMD_m_LineSeg6Y2 of type float32
 *   IeLMD_m_LineSeg7Y2 of type float32
 *   IeLMD_m_LineSeg8Y2 of type float32
 *   IeLMD_e_CrcAdasFdLanes2 of type uint16
 *   IeLMD_e_LineSeg1Id of type uint8
 *   IeLMD_e_LineSeg2Id of type uint8
 *   IeLMD_e_LineSeg3Id of type uint8
 *   IeLMD_e_LineSeg4Id of type uint8
 *   IeLMD_e_LineSeg5Id of type uint8
 *   IeLMD_e_LineSeg6Id of type uint8
 *   IeLMD_e_LineSeg7Id of type uint8
 *   IeLMD_e_LineSeg8Id of type uint8
 *   IeLMD_e_MsgCntrAdasFdLanes2 of type uint8
 *   IeLMD_e_MacAdasFdLanes2 of type uint8
 *   IeLMD_e_ReservedForFunctionalSafety2 of type uint8
 *   Dummy1_2_b of type uint8
 *   Dummy2_2_b of type uint8
 *   Dummy3_2_b of type uint8
 * INVMSignalManager_t: Record with elements
 *   m_ReadNVMParam_b of type boolean
 *   m_WriteNVMParam_b of type boolean
 *   m_ParkINStyle_e of type ParkINStyle_t
 *   m_ParkInSlotData of type IParkingSlotData_t
 * IParkingSlotData_t: Record with elements
 *   Vertices of type Float2_Array
 *   m_SlotType of type ParkingSlotType_t
 *   m_SlotSide of type SlotSide_t
 *   m_SlotID of type ParkingSlotID_t
 *   m_isSlotValid_b of type boolean
 * IaNFCD_e_BlobList: Record with elements
 *   ObjectID of type uint8
 *   DistanceToClosestPoint of type DistanceToClosestPoint_Array
 *   SensorSource of type e_SensorSource
 *   ObjectPos_Real of type ObjectPos_Real_Array
 *   BoundingBox_Real of type BoundingBox_Real_Array
 *   ObjectDimensions of type ObjectDimensions_Array
 *   ObjVelX of type float32
 *   ObjVelY of type float32
 *   ObjAge of type float32
 *   ObjValid of type boolean
 *   ObjClass of type TeEnv_e_ObjClass
 * IobjectEdge_t: Record with elements
 *   center of type Float2
 *   curvature of type float32
 *   endpoints of type endpoints_Array
 *   fit_err of type float32
 *   hitratio of type float32
 *   numPoint of type uint16
 *   isCurve of type boolean
 *   valid of type boolean
 * IobjectSignals_t: Record with elements
 *   objAge_f32 of type float32
 *   objDistance_f32 of type float32
 *   ObjDistToClosestPointX_f32 of type float32
 *   ObjDistToClosestPointY_f32 of type float32
 * JobDLDOutput_t: Record with elements
 *   IeDLD_e_FrCamSts of type DLDCamSts_t
 *   IeDLD_e_RrCamSts of type DLDCamSts_t
 *   IeDLD_e_RyCamSts of type DLDCamSts_t
 *   IeDLD_e_LyCamSts of type DLDCamSts_t
 *   IeDLD_p_FrCamOcclnPerc of type uint8
 *   IeDLD_p_FrCamLoLumPerc of type uint8
 *   IeDLD_p_RrCamOcclnPerc of type uint8
 *   IeDLD_p_RrCamLoLumPerc of type uint8
 *   IeDLD_p_LyCamOcclnPerc of type uint8
 *   IeDLD_p_LyCamLoLumPerc of type uint8
 *   IeDLD_p_RyCamOcclnPerc of type uint8
 *   IeDLD_p_RyCamLoLumPerc of type uint8
 *   IeDLD_b_FrCamOcclnSts of type boolean
 *   IeDLD_b_FrCamLoLumSts of type boolean
 *   IeDLD_b_RrCamOcclnSts of type boolean
 *   IeDLD_b_RrCamLoLumSts of type boolean
 *   IeDLD_b_LyCamOcclnSts of type boolean
 *   IeDLD_b_LyCamLoLumSts of type boolean
 *   IeDLD_b_RyCamOcclnSts of type boolean
 *   IeDLD_b_RyCamLoLumSts of type boolean
 * JobTHADetOutput_t: Record with elements
 *   HitchLoc_p3f of type Point3f_c
 *   HitchPix_p2d of type Point2i_c
 *   CplrLoc_p3f of type Point3f_c
 *   CplrPix_p2d of type Point2i_c
 *   CplrAng_f32 of type float32
 *   CplrDist_f32 of type float32
 *   HitchDetctStatus_e of type HitchDetStatus_e
 *   CplrDetctStatus_e of type CplrDetStatus_e
 *   HitchCplrPixDiffLongY_s32 of type sint32
 *   HitchCplrPixDiffLatX_s32 of type sint32
 *   CplrDetctConf_u8 of type uint8
 *   CplrTrackConf_u8 of type uint8
 *   StatusCplrZone_b of type boolean
 *   CplrAngFound_b of type boolean
 *   TrlrCplrStatus_b of type boolean
 * KeepAliveResponse_t: Record with elements
 *   FrameID_u32 of type uint32
 *   ResponseCode_u8 of type uint8
 * LC_LnCup: Record with elements
 *   width of type sint32
 *   height of type sint32
 *   startPositionX of type sint32
 *   startPositionY of type sint32
 *   leftPoint of type LC_LnPnt
 *   rightPoint of type LC_LnPnt
 * LC_LnModel: Record with elements
 *   stepArray of type stepArray_Array
 *   averageLaneWidth of type sint32
 *   countLaneStep of type sint32
 *   laneCoef of type laneCoef_2dArray
 *   laneCoef_TVG of type laneCoef_TVG_2dArray
 *   laneCoef_TVG_valid of type laneCoef_TVG_valid_Array
 *   lanTrack_s of type lanTrack_s_Array
 *   output of type output_Array
 * LC_LnPnt: Record with elements
 *   x of type sint32
 *   y of type sint32
 *   x_World_mm of type float32
 *   y_World_mm of type float32
 *   confidanceScore of type sint32
 *   valid of type boolean
 *   angle of type float32
 *   rho of type float32
 *   selectCurveFit of type boolean
 *   IsInnerPoint of type boolean
 * LMD_Lane_Outputs_s: Record with elements
 *   Lane_Outputs_Debug_s of type Lane_Outputs_Debug_t
 * LMD_Outputs_CVPAMFDData2_t: Record with elements
 *   LMD_Outputs_ADASFDLANES1_s of type ILMD_Outputs_ADASFDLANES1_t
 *   LMD_Outputs_ADASFDLANES2_s of type ILMD_Outputs_ADASFDLANES2_t
 * LaneLists_s: Record with elements
 *   m_LeftLane of type LaneParams_s
 *   m_RightLane of type LaneParams_s
 * LaneParams_s: Record with elements
 *   m_valid of type boolean
 *   m_LineID of type uint8
 *   m_DetectionPoint_Front_5m of type Point2f_c
 *   m_DetectionPoint_Front_12m of type Point2f_c
 *   m_DetectionPoint_Rear_5m of type Point2f_c
 *   m_DetectionPoint_Side_0m of type Point2f_c
 *   m_LaneConfidence of type sint32
 *   m_curveModel of type CurveModel
 *   m_radiusOfCurvature of type float32
 *   m_LaneType of type LaneType_t
 *   m_LaneTypeConfidance of type sint32
 *   m_LaneColor of type LaneColor_t
 *   m_LaneColorConfidance of type sint32
 *   m_LaneWidth of type float32
 *   m_LateralDistToLaneFront of type float32
 *   m_LateralDistToLaneRear of type float32
 *   m_LongitudinalDistToLane of type float32
 *   m_TimeToLaneCrossing of type float32
 * Lane_Outputs_Debug_t: Record with elements
 *   m_TotalLanes of type LaneLists_s
 *   m_DebugInfo of type DebugDumpAlgo
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
 * ME_Hydra3defs_S_EOLStatus_t: Record with elements
 *   deltaPitch_f32 of type float32
 *   deltaYaw_f32 of type float32
 *   deltaRoll_f32 of type float32
 *   deltaX_f32 of type float32
 *   deltaY_f32 of type float32
 *   deltaZ_f32 of type float32
 *   algoState_e of type ME_Hydra3defs_E_EOLAlgoState_t
 *   errorCode_e of type ME_Hydra3defs_E_EOLErrorCode_t
 *   targetData_s of type ME_Hydra3defs_S_EOLTargetData_t
 *   camID_e of type ME_Hydra3defs_E_CameraID_t
 * ME_Hydra3defs_S_EOLTargetData_t: Record with elements
 *   TargetInit_s8 of type sint8
 *   TargetLimitFront_s8 of type sint8
 *   TargetLimitRear_s8 of type sint8
 *   TargetDetectLeftFront_s8 of type sint8
 *   TargetDetectLeftRear_s8 of type sint8
 *   TargetDetectRightFront_s8 of type sint8
 *   TargetDetectRightRear_s8 of type sint8
 *   Reserved_s8 of type sint8
 * ME_Hydra3defs_S_OCStatus_t: Record with elements
 *   deltaPitch_f32 of type float32
 *   deltaYaw_f32 of type float32
 *   deltaRoll_f32 of type float32
 *   ValidFeatures_u32 of type uint32
 *   IgnoredFeatures_u32 of type uint32
 *   InvalidFeatures_u32 of type uint32
 *   algoState_e of type ME_Hydra3defs_E_OCAlgoState_t
 *   errorCode_e of type ME_Hydra3defs_E_OCErrorCode_t
 *   camID_e of type ME_Hydra3defs_E_CameraID_t
 * ME_Proxi_MPU1_0_to_MCU1_0_t: Record with elements
 *   a72_cpu_load of type float32
 *   state of type Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1
 *   PRX_RadioDispTyp_u8 of type uint8
 *   PRX_variantID_u8 of type uint8
 * ME_VehInpAdp_ACU_0x159: Record with elements
 *   ACU_Pass_OCS_St of type uint8
 *   ACU_AirBagSysAlrmLampSts of type uint8
 *   ACU_Pass_Airbag_LED of type uint8
 *   ACU_Drvr_Occpt_St of type uint8
 *   ACU_BucSwtStFrntDrvr of type uint8
 *   ACU_BucSwtStFrntPass of type uint8
 * ME_VehInpAdp_ACU_0x59: Record with elements
 *   ACU_FrntCrashOutpSts of type uint8
 *   ACU_RiSideCrashOutpSts of type uint8
 *   ACU_LeSideCrashOutpSts of type uint8
 *   ACU_RearCrashOutpSts of type uint8
 * ME_VehInpAdp_BCM_0x333: Record with elements
 *   BCM_IG1Sts of type uint8
 *   BCM_PwrMod of type uint8
 *   BCM_BrkSwtSts of type uint8
 *   BCM_IG2Sts of type uint8
 * ME_VehInpAdp_BCM_0x335: Record with elements
 *   BCM_ReWiprBackSwtSts of type uint8
 *   BCM_LeTrunLampOutpCmd of type uint8
 *   BCM_RiTrunLampOutpCmd of type uint8
 *   BCM_BrkLampSwtSts of type uint8
 *   BCM_HiBeamOutpCmd of type uint8
 *   BCM_LoBeamOutpCmd of type uint8
 *   BCM_PosnLampOutpCmd of type uint8
 *   BCM_FrntWiprSpd of type uint8
 *   BCM_VehAmbBri of type uint8
 * ME_VehInpAdp_BCM_0x343: Record with elements
 *   BCM_FrntHoodLidSts of type uint8
 *   BCM_FrntLeDoorLockSts of type uint8
 *   BCM_LockAllDoorCmd of type uint8
 *   BCM_LeFrntDoorSts of type uint8
 *   BCM_RiFrntDoorSts of type uint8
 *   BCM_RiReDoorSts of type uint8
 *   BCM_LeReDoorSts of type uint8
 *   BCM_SteerWhlVbrnAlrmAvl of type uint8
 * ME_VehInpAdp_CIM_0x310: Record with elements
 *   CIM_TurnLampSwtSts of type uint8
 *   CIM_HiBeamSwtSts of type uint8
 *   CIM_FrntWiprSwtSts of type uint8
 * ME_VehInpAdp_ECC_0x373: Record with elements
 *   ECC_OutdT of type float32
 * ME_VehInpAdp_EPS_0x1C2: Record with elements
 *   EPS_SteerWhlAgSig of type float32
 *   EPS_SteerWhlRotSpd of type float32
 *   EPS_MaxSftyTq of type float32
 * ME_VehInpAdp_EPS_0x1C4: Record with elements
 *   EPS_DrvrSteerTqDir of type uint8
 *   EPS_DrvrSteerTq of type float32
 *   EPS_EPSAvl of type uint8
 *   EPS_DrvrIntvSteerWhlDetd of type uint8
 *   EPS_DrvrIntvSteerWhlVld of type uint8
 *   EPS_SteerSnsrSts of type uint8
 *   EPS_SysAvlSts of type uint8
 *   EPS_LatMtnCtrlSts of type uint8
 *   EPS_MinSftyTq of type float32
 *   EPS_PinionAg of type float32
 * ME_VehInpAdp_EPS_0x475: Record with elements
 *   EPS_ModSts of type uint8
 * ME_VehInpAdp_ESP_0x120: Record with elements
 *   ESP_ActvSig_ABS of type uint8
 *   ESP_VmcVseYawRateAvlCpby of type uint8
 *   ESP_MstCylP of type float32
 *   ESP_MstCylPOffs of type float32
 *   ESP_TotBrkTqReq of type uint16
 * ME_VehInpAdp_ESP_0x122: Record with elements
 *   ESP_VmcVseAxOvrGrnd of type float32
 *   ESP_VmcVsevVeh of type float32
 * ME_VehInpAdp_ESP_0x125: Record with elements
 *   ESP_WhlOdoEdges_FL of type uint8
 *   ESP_WhlOdoEdges_FR of type uint8
 *   ESP_WhlOdoEdges_RL of type uint8
 *   ESP_WhlOdoEdges_RR of type uint8
 * ME_VehInpAdp_ESP_0x1B8: Record with elements
 *   ESP_VehStopSts of type uint8
 *   ESP_VehStandstillSts of type uint8
 *   ESP_VMC_PrefillActv of type uint8
 *   ESP_VLC_APCtrlSaturated of type uint8
 *   ESP_RoadSlopVld of type uint8
 *   ESP_AEBRdy of type uint8
 *   ESP_ParkRdy of type uint8
 *   ESP_ReAEBRdy of type uint8
 *   ESP_VlcApVehIsSecured of type uint8
 *   ESP_RoadSlop of type float32
 * ME_VehInpAdp_ESP_0x261: Record with elements
 *   ESP_ActvSig of type uint8
 *   ESP_ActvSig_TCS of type uint8
 *   ESP_WarningOn of type uint8
 *   ESP_ActvIndcn_AEB of type uint8
 *   ESP_FltIndcn_AEB of type uint8
 *   ESP_VehStandstillIndcn of type uint8
 *   ESP_BrkOverTIndcn of type uint8
 * ME_VehInpAdp_ESP_0x262: Record with elements
 *   ESP_ApaDrvOverrideFcn of type uint8
 * ME_VehInpAdp_ESP_0x268: Record with elements
 *   ESP_SysSts_EPB of type uint8
 *   ESP_EPBSwtichPosition of type uint8
 * ME_VehInpAdp_ESP_0x305: Record with elements
 *   ESP_WhlSpdVld_RF of type uint8
 *   ESP_WhlSpd_RF of type float32
 *   ESP_WhlMovgDir_RF of type uint8
 *   ESP_WhlMovgDir_LF of type uint8
 *   ESP_WhlSpdVld_LF of type uint8
 *   ESP_WhlSpd_LF of type float32
 * ME_VehInpAdp_ESP_0x306: Record with elements
 *   ESP_WhlSpdVld_RR of type uint8
 *   ESP_WhlSpd_RR of type float32
 *   ESP_WhlMovgDir_RR of type uint8
 *   ESP_WhlMovgDir_RL of type uint8
 *   ESP_WhlSpdVld_RL of type uint8
 *   ESP_WhlSpd_RL of type float32
 * ME_VehInpAdp_ESP_0x30A: Record with elements
 *   ESP_LgtOffs of type float32
 *   ESP_LatOffs of type float32
 *   ESP_YAWVOffs of type float32
 * ME_VehInpAdp_ESP_0x318: Record with elements
 *   ESP_BrkPedlSts of type uint8
 *   ESP_BrkPedlStsVld of type uint8
 *   ESP_VehSpdVld of type uint8
 *   ESP_SysActv of type uint8
 *   ESP_FltIndcn_ABS of type uint8
 *   ESP_VehSpd of type float32
 * ME_VehInpAdp_ICC_0x171: Record with elements
 *   ICC_Start_X_Coordinate of type sint16_t
 *   ICC_Start_Y_Coordinate of type sint16_t
 *   ICC_dX_Coordinate of type sint16_t
 *   ICC_dY_Coordinate of type sint16_t
 *   ADAS_DOW_Sts of type uint8
 *   ADAS_BSDSts of type uint8
 *   ADAS_DMSSts of type uint8
 *   ADAS_Sts_ACC_ICC of type uint8
 *   ADAS_ESAState of type uint8
 *   AEB_Sts of type uint8
 *   AEB_RCTB_Sts of type uint8
 *   AEB_ReAEB_Sts of type uint8
 *   ADAS_AHAB_Sts of type uint8
 *   ADAS_Sts_TLA of type uint8
 *   ADAS_TSRSts of type uint8
 *   ADAS_ISASts of type uint8
 *   ADAS_ThreatIDLeft of type uint8
 *   ADAS_ThreatIDRight of type uint8
 *   ADAS_DOW_Threat_Status of type uint8
 *   ADAS_DOWLeMirrWarnReq of type uint8
 *   ADAS_DOWRiMirrWarnReq of type uint8
 *   ADAS_ACCPrimTgtID of type uint8
 *   ADAS_ACCScndTgtID of type uint8
 *   ADAS_BSD_ObjDetnSts of type uint8
 *   ADAS_BSD_MirrWarnReq of type uint8
 *   ADAS_BSDLeMirrWarnReq of type uint8
 *   ADAS_BSDLeftThreatID of type uint8
 *   ADAS_BSDRightThreatID of type uint8
 *   ADAS_BSDWarnSetting of type uint8
 *   ADAS_BSDRiMirrWarnReq of type uint8
 *   ADAS_RAEB_ThreatID of type uint8
 *   ADAS_AEBThreatID of type uint8
 *   ADAS_RAEBAvl of type uint8
 *   ADAS_AEBWarnSts of type uint8
 *   ADAS_AEB_RCTA_WarnSide of type uint8
 *   ADAS_AEB_RAEB_WarnReq of type uint8
 *   ADAS_BrakeIntrvntnSt of type uint8
 *   ADAS_AEB_Typ of type uint8
 *   ADAS_LCA_TrajectoryX of type uint8
 *   ADAS_LCA_TrajectoryY of type uint8
 *   ADAS_LCA_TrajectoryHeadingAngle of type uint8
 *   ADAS_LaneCenteringHandsOnRew of type uint8
 *   ADAS_TLA_WarnReq of type uint8
 *   ADAS_TSRSignCondition of type uint8
 *   ADAS_SpeedLimitUnit of type uint8
 *   ADAS_TSRPassingCondition of type uint8
 *   ADAS_TSRSpeedLimitAddOn of type uint8
 *   ADAS_TSRSpeedLimit of type uint8
 *   ADAS_TSRSignName of type uint8
 *   ADAS_ISAOverSpeedWarning of type uint8
 * ME_VehInpAdp_ICC_0x250: Record with elements
 *   ICC_SegMsgType of type uint8
 *   ICC_SegOffset of type uint16
 *   ICC_SegPathIdx of type uint8
 *   ICC_SegCycCnt of type uint8
 *   ICC_SegUpdate of type uint8
 *   ICC_SegRetr of type uint8
 *   ICC_SegBuildUpArea of type uint8
 *   ICC_SegBridge of type uint8
 *   ICC_SegTunnel of type uint8
 *   ICC_SegFuncRoadClass of type uint8
 *   ICC_SegRelProbb of type uint8
 *   ICC_SegFormOfWay of type uint8
 *   ICC_SegCmplxInsct of type uint8
 *   ICC_SegPartOfCalcRoute of type uint8
 *   ICC_SegEffSpdLmtType of type uint8
 *   ICC_SegEffSpdLmt of type uint8
 *   ICC_SegNumOfLaneDrvDir of type uint8
 *   ICC_SegNumOfLaneOppDir of type uint8
 *   ICC_SegDividedRoad of type uint8
 * ME_VehInpAdp_ICC_0x251: Record with elements
 *   ICC_StubMsgType of type uint8
 *   ICC_StubOffset of type uint16
 *   ICC_StubPathIdx of type uint8
 *   ICC_StubCycCnt of type uint8
 *   ICC_StubUpdate of type uint8
 *   ICC_StubRetr of type uint8
 *   ICC_StubStubPathIdx of type uint8
 *   ICC_StubFuncRoadClass of type uint8
 *   ICC_StubRelProbb of type uint8
 *   ICC_StubFormOfWay of type uint8
 *   ICC_StubCmplxInsct of type uint8
 *   ICC_StubPartOfCalcRout of type uint8
 *   ICC_StubTurnAngl of type uint8
 *   ICC_StubNumOfLaneDrvDir of type uint8
 *   ICC_StubNumOfLaneOppDir of type uint8
 *   ICC_StubRtOfWay of type uint8
 *   ICC_StubLastStub of type uint8
 * ME_VehInpAdp_ICC_0x252: Record with elements
 *   ICC_ProfLongOffset of type uint16
 *   ICC_ProfLongMsgType of type uint8
 *   ICC_ProfLongPathIdx of type uint8
 *   ICC_ProfLongCycCnt of type uint8
 *   ICC_ProfLongUpdate of type uint8
 *   ICC_ProfLongRetr of type uint8
 *   ICC_ProfLongCtrlPoint of type uint8
 *   ICC_ProfLongProfType of type uint8
 *   ICC_ProfLongSignType of type uint8
 *   ICC_ProfLongSignValue of type uint8
 *   ICC_ProfLongSignTimeSpec of type uint8
 *   ICC_ProfLongSignVehSpec of type uint8
 *   ICC_ProfLongSignLane of type uint8
 *   ICC_0x252_Reserved of type uint8
 *   ICC_ProfLongSignLocation of type uint8
 *   ICC_ProfLongSignCondition of type uint8
 * ME_VehInpAdp_ICC_0x253: Record with elements
 *   ICC_0x253_ProfShortMsgType of type uint8
 *   ICC_0x253_ProfShortOffset of type uint8
 *   ICC_0x253_ProfShortPathIdx of type uint8
 *   ICC_0x253_ProfShortCycCnt of type uint8
 *   ICC_0x253_ProfShortUpdate of type uint8
 *   ICC_0x253_ProfShortRetr of type uint8
 *   ICC_0x253_ProfShortCtrlPoint of type uint8
 *   ICC_0x253_ProfShortProfType of type uint8
 *   ICC_0x253_ProfShortAccurClass of type uint8
 *   ICC_0x253_ProfShortDist1 of type uint8
 *   ICC_0x253_ProfShortValue0 of type uint8
 *   ICC_0x253_ProfShortValue1 of type uint8
 * ME_VehInpAdp_ICC_0x255: Record with elements
 *   ICC_ProfShortOffset of type uint16
 *   ICC_ProfShortMsgType of type uint8
 *   ICC_ProfShortPathIdx of type uint8
 *   ICC_ProfShortCycCnt of type uint8
 *   ICC_ProfShortUpdate of type uint8
 *   ICC_ProfShortRetr of type uint8
 *   ICC_ProfShortCtrlPoint of type uint8
 *   ICC_ProfShortProfType of type uint8
 *   ICC_ProfShortAccurClass of type uint8
 *   ICC_ProfShortDist1 of type uint16
 *   ICC_ProfShortValue0 of type uint16
 *   ICC_ProfShortValue1 of type uint16
 * ME_VehInpAdp_ICC_0x361: Record with elements
 *   ICC_PosnMsgTye of type uint8
 *   ICC_PosnOffset of type uint16
 *   ICC_PosnPathldx of type uint8
 *   ICC_PosnCycCnt of type uint8
 *   ICC_PosnPosProbb of type uint8
 *   ICC_PosnIdx of type uint8
 *   ICC_PosnAge of type uint16
 *   ICC_PosnCurLane of type uint8
 *   ICC_PosnPosConfdc of type uint8
 *   ICC_PosnSpd of type float32
 *   ICC_PosnRehead of type float32
 * ME_VehInpAdp_ICC_0x362: Record with elements
 *   ICC_MetaMapProvider of type uint8
 *   ICC_MetaMsgType of type uint8
 *   ICC_MetaCountryCode of type uint16
 *   ICC_MetaProtVerMinorSub of type uint8
 *   ICC_MetaProtVerMajor of type uint8
 *   ICC_MetaCycCnt of type uint8
 *   ICC_MetaHwVer of type uint16
 *   ICC_MetaDrvSide of type uint8
 *   ICC_MetaRegionCode of type uint16
 *   ICC_MetaMapVerYear of type uint8
 *   ICC_MetaMapVerQtr of type uint8
 *   ICC_MetaProtVerMinor of type uint8
 *   ICC_MetaSpdUnits of type uint8
 *   ICC_Reserved of type uint8
 * ME_VehInpAdp_ICC_0x52A: Record with elements
 *   ICC_ACCAutoSpdSts of type uint8
 *   ICC_ACCSpdStepSize of type uint8
 *   ICC_UsrProfTimeGapSet of type uint8
 *   ICC_ACCFuncTyp of type uint8
 *   ICC_AutomaticViewReq of type uint8
 *   ICC_OperationType of type uint8
 *   ICC_ZOOM_Start of type uint8
 *   ICC_ZOOM_End of type uint8
 *   ICC_ZOOM_ScalingFactor of type float32
 *   ICC_BSDSetting of type uint8
 *   ICC_ESA_Setting of type uint8
 *   ICC_ViewReq of type uint8
 *   ICC_AEB_WarningSetting of type uint8
 *   ICC_AEB_Sensitivity of type uint8
 *   ICC_BACM_Setting of type uint8
 *   ICC_BACM_WarningSetting of type uint8
 *   ICC_BACM_Sensitivity of type uint8
 *   ICC_LKA_Setting of type uint8
 *   ICC_ELKA_Setting of type uint8
 *   ICC_ELKASteeringInterventionSet of type uint8
 *   ICC_AHBA_Setting of type uint8
 *   ICC_TLR_Setting of type uint8
 *   ICC_TRS_Setting of type uint8
 *   ICC_ISASetting of type uint8
 *   ICC_ISASpeedOffset of type uint8
 *   ICC_AEB_Setting of type uint8
 *   ICC_DOW_Setting of type uint8
 *   ICC_LaneTrajectorySetting of type uint8
 * ME_VehInpAdp_ICC_0x530: Record with elements
 *   ICC_NavCtryCod of type uint8
 *   ICC_NavRoadTyp of type uint8
 *   ADAS_LgtCtrl_Sts of type uint8
 *   ADAS_LgtCtr_StsVld of type uint8
 *   ADAS_LgtCtrl_DrvrOvrdSts of type uint8
 *   ADAS_LgtCtrl_DrvrOvrdVld of type uint8
 *   ADAS_ParkStandstillReq of type uint8
 *   ADAS_ParkStandstillVld of type uint8
 *   ADAS_ParkGearReq of type uint8
 *   ADAS_ParkGearReqVld of type uint8
 *   ADAS_LgtCtrl_Typ of type uint8
 *   ADAS_LgtCtrl_AccelVld of type uint8
 *   ADAS_LgtCtrl_AccelReq of type float32
 *   ADAS_LatCtrl_Sts of type uint8
 *   ADAS_LatCtrl_StsVld of type uint8
 *   ADAS_LatCtrl_DrvrOvrd of type uint8
 *   ADAS_LatCtrl_DrvrOvrdVld of type uint8
 *   ADAS_LatCtrl_Typ of type uint8
 *   ADAS_LatCtrl_ReqVld of type uint8
 *   ADAS_LatCtrl_Req of type uint8
 *   ADAS_LatCtrl_SteerAnReq of type float32
 *   ADAS_LatCtrl_SteerTqReq of type float32
 *   ADAS_AEB_Ctrl_Sts of type uint8
 *   ADAS_AEB_Ctrl_Vld of type uint8
 *   ADAS_AEB_DrvrOvrdSts of type uint8
 *   ADAS_AEB_DrvrOvrdVld of type uint8
 *   ADAS_AEB_HBAReq of type uint8
 *   ADAS_AEB_HBAVld of type uint8
 *   ADAS_AEB_StandstillReq of type uint8
 *   ADAS_AEB_StandstillVld of type uint8
 *   ADAS_AEB_JerkReq of type uint8
 *   ADAS_AEB_JerkReqVld of type uint8
 *   ADAS_AEB_BrkPrefillReq of type uint8
 *   ADAS_AEB_BrkPrefillVld of type uint8
 *   ADAS_AEB_ActvTyp of type uint8
 *   ADAS_AEB_DecelVld of type uint8
 *   ADAS_AEB_DecelReq of type float32
 *   ADAS_CamSts of type uint8
 *   ADAS_ObjNr of type uint8
 *   ADAS_DispSpd_ACC of type uint8
 *   ADAS_DispSpdUnit_ACC of type uint8
 *   ADAS_TiGapSet_ACC of type uint8
 *   ADAS_LatCtrl_LeTurnLampReq of type uint8
 *   ADAS_LatCtrl_RiTurnLampReq of type uint8
 *   ADAS_LatCtrl_HapticReq of type uint8
 *   ADAS_Warn_TLA of type uint8
 * ME_VehInpAdp_ICC_0x531: Record with elements
 *   ICM_TotMilg_ODO of type float32
 *   ICM_DispVehSpd of type uint8
 *   ICM_DispVehSpdUnit of type uint8
 * ME_VehInpAdp_MCU_F_0x150: Record with elements
 *   MCU_F_CrtRotDir of type uint8
 *   MCU_F_CrtSpd of type uint16
 * ME_VehInpAdp_MFS_0x514: Record with elements
 *   MFS_LeBtnNorth of type uint8
 *   MFS_LeBtnSouth of type uint8
 *   MFS_LeBtnWest of type uint8
 *   MFS_LeBtnEast of type uint8
 *   MFS_LeRollUp of type uint8
 *   MFS_LeRollDwn of type uint8
 *   MFS_LeRollPress of type uint8
 *   MFS_RiBtnNorth of type uint8
 *   MFS_RiBtnSouth of type uint8
 *   MFS_RiBtnWest of type uint8
 *   MFS_RiBtnEast of type uint8
 *   MFS_RiRollUp of type uint8
 *   MFS_RiRollDwn of type uint8
 *   MFS_RiRollPress of type uint8
 * ME_VehInpAdp_PLGM_0x471: Record with elements
 *   PLGM_TrSts of type uint8
 * ME_VehInpAdp_TBOX_0x24B: Record with elements
 *   TBOX_XAcce of type float32
 *   TBOX_YAcce of type float32
 *   TBOX_ZAcce of type float32
 *   TBOX_XVelocity of type float32
 *   TBOX_YVelocity of type float32
 *   TBOX_ZVelocity of type float32
 *   TBOX_XAgrRate of type float32
 *   TBOX_YAgrRate of type float32
 *   TBOX_ZAgrRate of type float32
 *   TBOX_VehMovg of type float32
 *   TBOX_Roll of type float32
 *   TBOX_Pitch of type float32
 *   TBOX_Yaw of type float32
 * ME_VehInpAdp_TBOX_0x24C: Record with elements
 *   TBOX_SatellitesNr of type uint8
 *   TBOX_GNSSReckoningTi of type uint16
 *   TBOX_GPSNumSatellitesVld of type uint16
 *   TBOX_SysSts of type uint8
 * ME_VehInpAdp_TBOX_0x36: Record with elements
 *   TBOX_BusWakeupMsg of type uint8
 * ME_VehInpAdp_TBOX_0x525: Record with elements
 *   TBOX_GPSLongi of type float32
 *   TBOX_GPSLati of type float32
 * ME_VehInpAdp_TRM_0x348: Record with elements
 *   TRM_TrailerSts of type uint8
 *   TRM_IndcrLeSts of type uint8
 *   TRM_IndcrRiSts of type uint8
 *   TRM_RvsSts of type uint8
 *   TRM_HitchSts of type uint8
 * ME_VehInpAdp_VCU_0x1BA: Record with elements
 *   VCU_VehConfig of type uint8
 *   VCU_DrvrAPSPerc of type float32
 *   VCU_PrkgCmd of type uint8
 *   VCU_Decoup_Dyn of type uint8
 *   VCU_DrvrAPSGrdt of type uint8
 * ME_VehInpAdp_VCU_0x214: Record with elements
 *   VCU_StgyGearSig of type uint8
 *   VCU_GearSigVld of type uint8
 *   VCU_GearSig of type uint8
 *   VCU_ACCRdy of type uint8
 *   VCU_ParkRdy of type uint8
 *   VCU_APSPercVld of type uint8
 *   VCU_VehSt of type uint8
 *   VCU_APSPerc of type uint8
 *   VCU_BrkSig of type uint8
 * ME_VehInpAdp_VCU_0x225: Record with elements
 *   VCU_MotChkACCFltFbFlg of type uint8
 *   VCU_VehTqFltSts of type uint8
 * ME_VehInpAdp_YRS_0x242: Record with elements
 *   YRS_LatAcce of type float32
 *   YRS_YawRate of type float32
 * ME_VehInpAdp_YRS_0x246: Record with elements
 *   YRS_LgtAcce of type float32
 *   BCM_LightReqReason_RLS of type uint8
 * ME_VehInpAdp_iBooster_0x271: Record with elements
 *   iBooster_WarnOn of type uint8
 *   iBooster_BrkPedlAppld of type uint8
 * ME_VehOut_TRSC_t: Record with elements
 *   IeTRSC_e_SpdLmtReq of type TeTRSC_e_SpdLmtReq
 *   IeTRSC_e_VehStpReq of type TeTRSC_e_VehStpReq
 *   IeTRSC_e_TRSCLedSts of type TeTRSC_e_TRSCLedSts
 *   IeTRSC_e_TRSCPopupDispInfo of type TeTRSC_e_TRSCPopupDispInfo
 *   IeTRSC_e_TRSCSts of type TeTRSC_e_TRSCSts
 *   IeTRSC_e_TRSCStrTrqActvReq of type TeTRSC_e_TRSCStrTrqActvReq
 *   IeTRSC_e_TrlrHitchLightCtrl of type TeTRSC_e_TrlrHitchLightCtrl
 *   IeTRSC_M_TRSCStrTrq of type real32_T
 *   IeTRSC_pct_TRSCStrDmp of type real32_T
 *   IeTRSC_deg_TADAngAct of type uint8
 *   IeTRSC_e_TADAngActSign of type Rte_DT_ME_VehOut_TRSC_t_10
 *   IeTRSC_e_TrlrCalInfo of type Rte_DT_ME_VehOut_TRSC_t_11
 *   IeTRSC_b_MoreCamReqSts of type boolean
 *   IeTRSC_kph_SpdLmtReq_DID of type real32_T
 *   IeTRSC_e_VehStpReq_DID of type TeTRSC_e_VehStpReq_DID
 * MagnaSerialNumber_t: Record with elements
 *   initialCharacter_c of type char_T
 *   productionLineNumber of type productionLineNumber_ac
 *   productionYear of type productionYear_ac
 *   productionDay of type productionDay_ac
 *   productionSerialNumber of type productionSerialNumber_ac
 *   productionBoardSerialNumber of type productionBoardSerialNumber_ac
 *   zeroCharacter_c of type char_T
 * NFCD_Output: Record with elements
 *   NFCD_EnvSignals of type NFCD_EnvSignals_Array
 *   IeVBII_cnt_nfcd_currDetection of type uint8
 *   IeVBII_nfcd_DetectionTimestamp of type float32
 *   IeVBII_nfcd_MinDistanceToCollisionObject of type float32
 *   NFCDState of type TeEnv_e_NFCDState
 * NVMSignalManager_t: Record with elements
 *   m_ReadNVMParam_b of type boolean
 *   m_WriteNVMParam_b of type boolean
 *   m_ParkINStyle_e of type ParkINStyle_t
 *   m_ParkInSlotData of type IParkingSlotData_t
 * OutLaneInfo: Record with elements
 *   coef_img of type coef_img_Array
 *   laneType of type sint32
 *   laneType_conf of type sint32
 *   laneDetect_conf of type sint32
 *   laneColor of type sint32
 *   laneColor_conf of type sint32
 *   laneWidth of type float32
 *   distantToLane_pix of type Point2f_c
 *   distantToLaneFront of type float32
 *   distantToLaneRear of type float32
 *   radiusOfCurvature of type float32
 *   longituCrossCrossLanePoint_pix of type Point2f_c
 *   longituCrossLaneDist of type float32
 *   TTLC of type float32
 * OverlayBits_t: Record with elements
 *   TopRearButtonSelect_b of type uint8
 *   TopRearButtonNoSelect_b of type uint8
 *   RearCrossButtonSelect_b of type uint8
 *   RearCrossButtonNoSelect_b of type uint8
 *   FrontCrossButtonSelect_b of type uint8
 *   FrontCrossButtonNoSelect_b of type uint8
 *   TopFrontButtonNoSelect_b of type uint8
 *   TopFrontButtonSelect_b of type uint8
 *   BackupRearCamButtonNoSelect_b of type uint8
 *   BackupRearCamButtonSelect_b of type uint8
 *   FrontFaceCamButtonNoSelect_b of type uint8
 *   FrontFaceCamButtonSelect_b of type uint8
 *   AuxCamButton1NoSelect_b of type uint8
 *   AuxCamButton1Select_b of type uint8
 *   AuxCamButton2NoSelect_b of type uint8
 *   AuxCamButton2Select_b of type uint8
 *   MoreCamsButton1NoSelect_b of type uint8
 *   MoreCamsButton1Select_b of type uint8
 *   MoreCamsButton2NoSelect_b of type uint8
 *   MoreCamsButton2Select_b of type uint8
 *   XIcon_b of type uint8
 *   Frameset1AndTopRearText_b of type uint8
 *   Frameset1AndTopFrontText_b of type uint8
 *   Frameset2AndRearCrossText_b of type uint8
 *   Frameset2AndFrontCrossText_b of type uint8
 *   ZoomPlus_Selectable_b of type uint8
 *   ZoomPlus_Not_Selectable_b of type uint8
 *   ZoomMinus_Selectable_b of type uint8
 *   ZoomMinus_Not_Selectable_b of type uint8
 *   MoreCamsIconFullScreenNoSelect_b of type uint8
 *   Auto_NoSelect_b of type uint8
 *   Auto_Select_b of type uint8
 *   TopViewFrontDynamics_b of type uint8
 *   FrontViewDynamics_b of type uint8
 *   TopViewRearDynamics_b of type uint8
 *   RearViewDynamics_b of type uint8
 *   FrontTireTracks_b of type uint8
 *   BackDoorClose_Icon_b of type uint8
 *   RightDoorRearClose_Icon_b of type uint8
 *   RightDoorFrontClose_Icon_b of type uint8
 *   LeftDoorRearClose_Icon_b of type uint8
 *   LeftDoorFrontClose_Icon_b of type uint8
 *   BackDoorOpen_Icon_b of type uint8
 *   RightDoorRearOpen_Icon_b of type uint8
 *   RightDoorFrontOpen_Icon_b of type uint8
 *   LeftDoorRearOpen_Icon_b of type uint8
 *   LeftDoorFrontOpen_Icon_b of type uint8
 *   TopViewBlack_b of type uint8
 *   RightCam_NA_b of type uint8
 *   BackCam_NA_b of type uint8
 *   LeftCam_NA_b of type uint8
 *   FrontCam_NA_b of type uint8
 *   DefaultEngLang_b of type uint8
 *   EnableStaticGuidelines_b of type uint8
 *   DoorSigFault_b of type uint8
 *   Reserved_15_b of type uint8
 *   TRSC_TrailerRed of type uint8
 *   TRSC_Enable of type uint8
 *   THA_Updated_b of type uint8
 *   THA_ProgressBar of type uint8
 *   THA_StartButton of type uint8
 *   THA_ConfirmButton of type uint8
 *   THA_ButtonSelectable of type uint8
 *   THA_ButtonGrey of type uint8
 *   THA_CouplerBulletIcon of type uint8
 *   THA_TriangleOverlay of type uint8
 *   PDC_RearLeft_Red_b of type uint8
 *   PDC_RearLeft_Yellow_b of type uint8
 *   PDC_RearRight_Red_b of type uint8
 *   PDC_RearRight_Yellow_b of type uint8
 *   PDC_RearCenter_Red_b of type uint8
 *   PDC_RearCenter_Yellow_b of type uint8
 *   PDC_FrontLeft_Red_b of type uint8
 *   PDC_FrontLeft_Yellow_b of type uint8
 *   PDC_FrontRight_Red_b of type uint8
 *   PDC_FrontRight_Yellow_b of type uint8
 *   PDC_FrontCenter_Red_b of type uint8
 *   PDC_FrontCenter_Yellow_b of type uint8
 *   AP_BackBtn of type uint8
 *   AP_ParkBtn_Selected of type uint8
 *   AP_ParkBtn_Not_Selected of type uint8
 *   AP_ExitBtn_Selected of type uint8
 *   AP_ExitBtn_Not_Selected of type uint8
 *   AP_Disclaimer_Core of type uint8
 *   AP_BG_Main of type uint8
 *   AP_Para_Exit_Core of type uint8
 *   AP_Forward_LeftBtn_Selected of type uint8
 *   AP_Forward_LeftBtn_Not_Selected of type uint8
 *   AP_Forward_RightBtn_Selected of type uint8
 *   AP_Forward_RightBtn_Not_Selected of type uint8
 *   AP_Perp_Right_Core of type uint8
 *   AP_Perp_Left_Core of type uint8
 *   AP_RearInBtn_Not_Selected of type uint8
 *   AP_RearInBtn_Selected of type uint8
 *   AP_FrontInBtn_Not_Selected of type uint8
 *   AP_FrontInBtn_Selected of type uint8
 *   AP_RearInBtn_Not_Avail of type uint8
 *   AP_FrontInBtn_Not_Avail of type uint8
 *   AP_Parkout_Done of type uint8
 *   AP_ParkIn_Done of type uint8
 *   AP_Scanning_Core of type uint8
 *   AP_Grey_Banner1 of type uint8
 *   AP_Grey_Banner2 of type uint8
 *   AP_Scan_Select_Space_Text of type uint8
 *   AP_Scan_Space_Found_Text of type uint8
 *   AP_Scan_STOP_Text of type uint8
 *   AP_Scan_Searching_Text of type uint8
 *   AP_Scan_Keep_Moving_Forward_Text of type uint8
 *   AP_Scan_Reduce_Speed_Text of type uint8
 *   AP_FullscreenText_Updated of type uint8
 *   AP_ParksenseUnavailable of type uint8
 *   AP_TopBlackBannerUpdated of type uint8
 *   AP_BottomBlackBannerUpdated of type uint8
 *   AP_RedBannerUpdated of type uint8
 *   AP_ParkSlots_Updated of type uint8
 *   SrvPrgBar999Per_b of type uint8
 *   SrvPrgBar100Per_b of type uint8
 *   SrvPrgBar75Per_b of type uint8
 *   SrvPrgBar50Per_b of type uint8
 *   SrvPrgBar25Per_b of type uint8
 *   SrvPrgBar0Per_b of type uint8
 *   SrvCamIndRiNone_b of type uint8
 *   SrvCamIndRiPend_b of type uint8
 *   SrvCamIndRiNok_b of type uint8
 *   SrvCamIndRiOk_b of type uint8
 *   SrvCamIndBaNone_b of type uint8
 *   SrvCamIndBaPend_b of type uint8
 *   SrvCamIndBaNok_b of type uint8
 *   SrvCamIndBaOk_b of type uint8
 *   SrvCamIndLeNone_b of type uint8
 *   SrvCamIndLePend_b of type uint8
 *   SrvCamIndLeNok_b of type uint8
 *   SrvCamIndLeOk_b of type uint8
 *   SrvCamIndFrNone_b of type uint8
 *   SrvCamIndFrPend_b of type uint8
 *   SrvCamIndFrNok_b of type uint8
 *   SrvCamIndFrOk_b of type uint8
 *   SrvChkIndCondNok_b of type uint8
 *   SrvChkIndNok_b of type uint8
 *   SrvChkIndOk_b of type uint8
 *   SrvChkIndRun_b of type uint8
 *   SrvSpOmIndNok_b of type uint8
 *   SrvSpOmIndOk_b of type uint8
 *   SrvStAngIndNok_b of type uint8
 *   SrvStAngIndOk_b of type uint8
 *   SrvLayout_b of type uint8
 *   Reserved_01_b of type uint8
 *   Reserved_02_b of type uint8
 *   Reserved_03_b of type uint8
 *   Reserved_04_b of type uint8
 *   Reserved_05_b of type uint8
 *   Reserved_06_b of type uint8
 *   Reserved_07_b of type uint8
 *   Reserved_08_b of type uint8
 *   Reserved_09_b of type uint8
 *   Reserved_10_b of type uint8
 *   Reserved_11_b of type uint8
 *   Reserved_12_b of type uint8
 *   Reserved_13_b of type uint8
 *   Reserved_14_b of type uint8
 *   OneCam_ZoomPlus_Selectable_b of type uint8
 *   OneCam_ZoomPlus_Not_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Selectable_b of type uint8
 *   OneCam_ZoomMinus_Not_Selectable_b of type uint8
 *   OneCam_AuxCamButtonSelect_b of type uint8
 *   OneCam_AuxCamButtonNoSelect_b of type uint8
 * Point2f_c: Record with elements
 *   x of type float32
 *   y of type float32
 * Point2i_c: Record with elements
 *   x of type sint32
 *   y of type sint32
 * Point3f_c: Record with elements
 *   x of type float32
 *   y of type float32
 *   z of type float32
 * Rois: Record with elements
 *   ValidNum of type sint32
 *   SubRois of type SubRois_Array
 *   RLDFeatureCountInSubRois of type RLDFeatureCountInSubRois_Array
 *   para of type para_Array
 *   LDW_REG_DYNAMIC_ROI_MAX_OFFSET_BTW_ROI_AND_CENTRAL_LINE of type sint32
 *   LDW_REG_DYNAMIC_ROI_MAX_RLD_PIXEL_COUNT of type sint32
 *   isLeft2Right of type boolean
 *   isRight2Left of type boolean
 * RunTimeStats_MCU2_0_t: Record with elements
 *   en_Task_BSWTaskTime of type Rte_DT_RunTimeStats_MCU2_0_t_0
 *   en_Task_APPTaskTime of type Rte_DT_RunTimeStats_MCU2_0_t_1
 * RunTimeStats_MCU2_1_t: Record with elements
 *   en_Task_BSWTaskTime of type Rte_DT_RunTimeStats_MCU2_1_t_0
 *   en_Task_APPTaskTime of type Rte_DT_RunTimeStats_MCU2_1_t_1
 *   en_Task_SAFETYTaskTime of type Rte_DT_RunTimeStats_MCU2_1_t_2
 * RunTimeStats_MPU1_0_t: Record with elements
 *   APA_Runtime of type uint32
 *   CALSM_Runtime of type uint32
 *   CALSMThread_Runtime of type uint32
 *   DLDThread_Runtime of type uint32
 *   DLD_Runtime of type uint32
 *   PLDThread_Runtime of type uint32
 *   EOL_Runtime of type uint32
 *   EOLThread_Runtime of type uint32
 *   MOT_Runtime of type uint32
 *   OC_Runtime of type uint32
 *   OCThread_Runtime of type uint32
 *   OD_Runtime of type uint32
 *   ODThread_Runtime of type uint32
 *   OVL3D_Runtime of type uint32
 *   RenderThread_Runtime of type uint32
 *   TAD_Runtime of type uint32
 *   TADThread_Runtime of type uint32
 *   THA_Runtime of type uint32
 *   THAThread_Runtime of type uint32
 *   TIOVXThread_Runtime of type uint32
 *   TIOVX_Runtime of type uint32
 *   CameraCalib_Runtime of type uint32
 *   VideoInput_Runtime of type uint32
 *   AppM_Runtime of type uint32
 *   LogM_Runtime of type uint32
 *   KeepAlive_Runtime of type uint32
 *   ThreadMsgSndr_Runtime of type uint32
 *   SigM_Runtime of type uint32
 *   ThreadSigM_Runtime of type uint32
 *   Sys_Runtime of type uint32
 *   SysMon_Runtime of type uint32
 *   VarM_Runtime of type uint32
 *   AlgoViewThread_Runtime of type uint32
 * SSM_2_0_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_0_LocalAppStatus_Arr
 * SSM_2_1_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_1_LocalAppStatus_Arr
 * SSM_QNX_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_QNX_LocalAppStatus_Arr
 * SVSToDiag_t: Record with elements
 *   Routine_ID of type ME_Hydra3defs_E_RoutineType_t
 *   Camera_ID of type ME_Hydra3defs_E_CameraID_t
 *   TestPattern_ID of type ME_Hydra3defs_E_TestPatternType_t
 *   Response_Ack of type boolean
 *   NRC_ID of type ME_Hydra3defs_E_NRCType_t
 * SVS_NVMData_t: Record with elements
 *   IeSVS_b_isDynGridPrstFromNVM of type boolean
 *   IeSVS_b_isFwdCamGridPrstFromNVM of type boolean
 * SVStoTRSC_t: Record with elements
 *   MeSVS_e_DispView2Info of type aSigConverter_E_DisplayView2_t
 *   MeSVS_b_MoreCamReq of type bool_t
 * ScreenRequest_t: Record with elements
 *   MbSVS_bf_OverlayBitsReq of type OverlayBits_t
 *   AP_HMI_ParkSlot of type AP_HMI_ParkSlot_Array
 *   AP_HMI_SelectedSlot of type ParkingSlotID_t
 *   AP_HMI_Fullscreen of type AP_HMI_Fullscreen_t
 *   AP_HMI_TopBlackBanner of type AP_HMI_TopBlackBanner_t
 *   AP_HMI_TopRedBanner of type AP_HMI_TopRedBanner_t
 *   AP_HMI_BottomBlackBanner of type AP_HMI_BottomBlackBanner_t
 *   MeSVS_e_THAScreenRequesttoA72 of type aSigConverter_E_THAScreenRequest_t
 *   MeSVS_DesiredTrailerAngle of type sint8
 *   MeSVS_ActualTrailerAngle of type sint8
 *   MeSVS_Orage_Arc_StartAngle of type sint8
 *   MeSVS_Red_Arc_StartAngle of type sint8
 *   MeSVS_pct_ProgressBar of type uint16
 *   MeSVS_px_CplrPosX of type uint16
 *   MeSVS_px_CplrPosY of type uint16
 *   MeSVS_px_ScrnTchX of type uint16
 *   MeSVS_px_ScrnTchY of type uint16
 *   MeSVS_deg_StrWhlAng of type sint16
 *   MeSVS_e_CRCRReq of type uint16
 *   MeSVS_e_ViewEngReqCode of type uint8
 *   ZoomFactor_u8 of type uint8
 *   MeSVS_b_ZoomPressedReq of type boolean
 * ScreenResponse_t: Record with elements
 *   MbSVS_bf_OverlayBitsRes of type OverlayBits_t
 *   AP_HMI_ParkSlot of type AP_HMI_ParkSlot_Array
 *   AP_HMI_SelectedSlot of type ParkingSlotID_t
 *   AP_HMI_Fullscreen of type AP_HMI_Fullscreen_t
 *   AP_HMI_TopBlackBanner of type AP_HMI_TopBlackBanner_t
 *   AP_HMI_TopRedBanner of type AP_HMI_TopRedBanner_t
 *   AP_HMI_BottomBlackBanner of type AP_HMI_BottomBlackBanner_t
 *   Pixel_X_to_RealWord_X_cm of type float32
 *   Pixel_Y_to_RealWord_Y_cm of type float32
 *   MeSVS_e_THAScreenResponse of type aSigConverter_E_THAScreenRequest_t
 *   MeSVS_DesiredTrailerAngle of type sint8
 *   MeSVS_ActualTrailerAngle of type sint8
 *   MeSVS_Orage_Arc_StartAngle of type sint8
 *   MeSVS_Red_Arc_StartAngle of type sint8
 *   MeSVS_pct_ProgressBar of type uint16
 *   MeSVS_px_CplrPosX of type uint16
 *   MeSVS_px_CplrPosY of type uint16
 *   MeSVS_px_ScrnTchX of type uint16
 *   MeSVS_px_ScrnTchY of type uint16
 *   MeSVS_deg_StrWhlAng of type sint16
 *   MeSVS_e_CRCRReq of type uint16
 *   MeSVS_e_ViewEngResCode of type uint8
 *   ZoomFactor_u8 of type uint8
 *   RenderedRadioDispType of type uint8
 *   MeSVS_b_ZoomPressedRes of type uint8
 *   THAViewZoomResponse of type boolean
 * StackUsage_MCU2_0_t: Record with elements
 *   en_Task_BSWTaskTime of type Rte_DT_StackUsage_MCU2_0_t_0
 *   en_Task_APPTaskTime of type Rte_DT_StackUsage_MCU2_0_t_1
 * StackUsage_MCU2_1_t: Record with elements
 *   en_Task_BSWTaskTime of type Rte_DT_StackUsage_MCU2_1_t_0
 *   en_Task_APPTaskTime of type Rte_DT_StackUsage_MCU2_1_t_1
 *   en_Task_SAFETYTaskTime of type Rte_DT_StackUsage_MCU2_1_t_2
 * SvsToTHA_t: Record with elements
 *   MeSVS_e_THAScrResp of type aSigConverter_E_THAScreenRequest_t
 *   MeSVS_b_THASftBtnPrsdStsToTHA of type boolean
 *   MeSVS_b_IsConfirmBtnPrsd of type boolean
 *   MeSVS_b_ImgDefeatReqSts of type boolean
 *   MeSVS_b_ViewZoomSts of type boolean
 *   MeSVS_b_THAMnvrStartBtnPrsd of type boolean
 *   MeSVS_b_THAScrTchSts of type boolean
 *   MeSVS_b_THAAbortReq of type boolean
 * SvsToVCAN_t: Record with elements
 *   IeSVS_b_SPMScrnReq of type boolean
 *   IeSVS_b_ImgDefeatReqSts of type boolean
 *   IeSVS_b_MoreCamsReqSts of type boolean
 *   IeSVS_b_AUXCamReqSts of type boolean
 *   IeSVS_e_DispView2 of type aSigConverter_E_DisplayView2_t
 * Svs_CamEepromDataArray_t: Record with elements
 *   CameraEepromData of type CameraEepromData_arr
 * TRSCSMVCtoDebugCAN_t: Record with elements
 *   MeTRSC_deg_StrCMD of type real32_T
 *   ReservedTRSCSig1 of type real32_T
 *   ReservedTRSCSig2 of type real32_T
 *   MeTRSC_s_TRSCPeriodicity of type uint16
 *   MeTRSC_s_TRSCTimeTaken of type uint16
 *   MeTRSC_cnt_TRSCAliveCounter of type uint16
 *   MeTRSC_b_TrlrCalibPopInfo of type boolean
 * TRSCSMVCtoSVS_t: Record with elements
 *   MeTRSC_e_TRSCStat of type TeTRSC_e_TRSCStat
 *   MeTRSC_e_TrlrCalInfoSMVC of type TeTRSC_e_TrlrCalInfo
 *   MeTRSC_deg_JackKnifeAngle of type real32_T
 *   MeTRSC_deg_JackknifeThrAngle of type real32_T
 *   MeTRSC_deg_MaxAllowedTADAngle of type real32_T
 *   MeTRSC_deg_KnobAngle of type real32_T
 *   MeTRSC_M_SteeringTorqInfo of type real32_T
 *   MeTRSC_deg_TADAngleSMVC of type real32_T
 *   ReservedSignal1 of type real32_T
 *   ReservedSignal2 of type real32_T
 *   MeTRSC_b_MoreCamSoftButtEnbl of type boolean
 *   MeTRSC_b_TrlrRevSteeringStsInfo of type boolean
 * TRSC_Inputs_from_TrailerDetection_t: Record with elements
 *   m_leftCalibrationAngle of type float32
 *   m_rightCalibrationAngle of type float32
 *   m_hitchCalibrationAngle of type float32
 *   m_averageIllumination of type float32
 *   MeTRSC_deg_TADAngle of type float32
 *   MeTRSC_deg_TADAngleRate of type float32
 *   MeTRSC_m_DetTrailerBeamLen of type float32
 *   MeTRSC_m_HitchLength of type float32
 *   MeTRSC_deg_DetJackknifeThrAngle of type float32
 *   MeTRSC_deg_DetJackKnifeAngle of type float32
 *   MeTRSC_cnt_TrlrCalibFailCntInfo of type uint32
 *   MeTRSC_e_TrlrAngSign of type TrailerAngleSign_t
 *   MeTRSC_e_TrailerID of type TrailerID_t
 *   MeTRSC_e_TADState of type TeTRSC_e_TADState
 *   MeTRSC_e_TADCalibrationSubstate of type CalibrationState_t
 *   MeTRSC_e_TurnAroundSubState of type TurnAroundState_t
 *   MeTRSC_e_TrlrCalInfo of type TeTRSC_e_TrlrCalInfo
 *   MeTRSC_e_TrlrRecogInfo of type TeTRSC_e_TrlrRecogInfo
 *   MeTRSC_e_TrlrPrsntInfo of type TeTRSC_e_TrlrPrsntInfo
 *   MeTRSC_e_CalFail of type TrailerCalibrationFailInfo_t
 *   MeTRSC_b_OBTLRecalibrate of type boolean
 *   MeTRSC_b_TrlrCalibDelayInfo of type boolean
 * TRSCtoDiagMgr_t: Record with elements
 *   IeTRSC_e_TRSKMBtnSts of type TeVBII_e_EnblBtnSts
 *   IeTRSC_e_TRSKMBtnSts_DID of type TeTRSC_e_TRSKMBtnSts_DID
 *   IeTRSC_e_TRSKMCenBtnSts of type TeVBII_e_CenterBtnSts
 *   IeTRSC_e_TRSKMCenBtnSts_DID of type TeTRSC_e_TRSKMCenBtnSts_DID
 *   IeTRSC_e_TRSKMSts of type TeTRSC_e_TRSKMSts
 *   IeTRSC_e_TRSKMSts_DID of type TeTRSC_e_TRSKMSts_DID
 *   IeTRSC_e_GearShiftSts of type TeVBII_e_GearEngagedForDsply
 *   IeTRSC_e_GearShiftSts_DID of type TeTRSC_e_GearShiftSts_DID
 *   IeTRSC_e_TRSCUnavailReas of type uint32
 *   IeTRSC_e_TRSCUnavailReas_DID of type TeTRSC_e_TRSCUnavailReas_DID
 *   IeTRSC_e_TRSCAbortReas of type uint32
 *   IeTRSC_e_TRSCAbortReas_DID of type TeTRSC_e_TRSCAbortReason_DID
 *   IeTRSC_kph_VehSpeedVSOSig of type real32_T
 *   IeTRSC_m_TrlrWhlBaseEff of type real32_T
 *   IeTRSC_deg_FrntWhlAng of type real32_T
 *   IeTRSC_deg_TrlrAngKnob of type real32_T
 *   IeTRSC_deg_JackknifeThrAngle of type real32_T
 *   IeTRSC_M_TRSCStrTrq of type real32_T
 *   IeTRSC_cnt_KnobPos of type uint16
 *   MeSVS_e_DispView2Info_DID of type TeTRSC_e_DispView2_DID
 *   IeTRSC_e_GraphicOverlay_Sts of type TeTRSC_e_GraphicOverlay_Sts
 * TbAP_APSMPAOut_t: Record with elements
 *   IeAP_e_PAMFlt of type TeAP_e_PAMSystemFault
 *   IeAP_e_FrntRearParkSts of type TeAP_e_PAMOffStatus2BT
 *   IeAP_e_FrntSensorActvSts of type TeAP_e_FrntSnsrStatus
 *   IeAP_e_RearSnsrActvSts of type TeAP_e_RearSnsrStatus
 * TbAP_DebugOut: Record with elements
 *   MeAP_deg_StrCmd of type real32_T
 *   MeAP_a_BrkCmd of type real32_T
 *   MeAP_a_ThrtlCmd of type real32_T
 *   MeAP_cnt_StateDebugVar of type uint16
 *   MeAP_cnt_TransDebugVar of type uint16
 *   MeAP_cm_FrntCenterMinXDist of type sint16
 *   MeAP_cm_FrntLeftMinXDist of type sint16
 *   MeAP_cm_FrntRightMinXDist of type sint16
 *   MeAP_cm_RearCenterMinXDist of type sint16
 *   MeAP_cm_RearLeftMinXDist of type sint16
 *   MeAP_cm_RearRightMinXDist of type sint16
 *   MeAP_b_VCOpPaused of type boolean
 *   MeAP_b_BSMInterfaceTimeout of type boolean
 *   MeAP_b_EPSInterfaceTimeout of type boolean
 *   MeAP_b_GearShiftWaitTimeout of type boolean
 *   MeAP_b_CamHandshakeTimeout of type boolean
 *   MeAP_b_ObjInPathTimeout of type boolean
 *   MeAP_b_PausedPressBtnTimeout of type boolean
 *   MeAP_b_SeekSpdExceedTimeout of type boolean
 *   MeAP_b_APInitSts of type boolean
 *   MeAP_b_DriverOverride of type boolean
 *   MeAP_b_StandStill of type boolean
 *   MeAP_b_BSMHandshakeActv of type boolean
 *   MeAP_b_VehCndSts of type boolean
 *   MeAP_b_FeatureEnbl of type boolean
 *   MeAP_b_FPADisable of type boolean
 *   MeAP_b_RPADisable of type boolean
 *   MeAP_b_RPAActvTrlr of type boolean
 *   MeAP_b_PAVolDefMed of type boolean
 *   MeAP_b_FPAVolDefMed of type boolean
 *   MeAP_b_RPAVolDefMed of type boolean
 *   MeAP_b_PARBActvTrlr of type boolean
 *   MeAP_b_PARBActv4LOW of type boolean
 *   MeAP_b_PARBDiable of type boolean
 *   MeAP_b_PPPAActvTrlr of type boolean
 *   MeAP_b_PPPAActv4LOW of type boolean
 *   MeAP_b_PPPADefEng of type boolean
 *   MeAP_b_PPPADisable of type boolean
 * TbAP_DriveAssistStatOut_t: Record with elements
 *   MeAP_s_FaultWaitTime of type real32_T
 *   IeAutoPark_e_ChimeReq of type TeAutoPark_e_ChimeReq
 *   IeAP_e_ScanDir of type TeAutoPark_e_ScanDir
 *   IeAP_e_AutoParkStatus of type TeAutoPark_e_AutoParkStatus
 *   IeAP_e_AlgoState of type TeAP_e_AlgoState
 *   IeAP_e_ParKMnvrActv of type TeAP_e_ParKMnvrActv
 *   IeAP_e_InterfaceBSM of type TeAP_e_InterfaceBSM
 *   IeAP_e_SPMLatCtrlReqSts of type TeAP_e_SPMLatCtrlReqSts
 *   IeAP_e_SPMLedSts of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_SPMActvStat of type TeAP_e_SPMActvStat
 *   IeAP_e_DispView2 of type TeAP_e_DispView2
 *   IeAP_e_GearShiftReq of type TeAP_e_GearShiftReq
 *   MeAP_e_PAMVolSigSVM of type TeAP_e_PAMVolSig
 *   MeAP_e_PAMChimeTypSVM of type TeAP_e_PAMChimeTyp
 *   MeAP_e_PAMChimeRepnRateSVM of type TeAP_e_PAMChimeRepnRate
 *   IeAP_e_HMIDispReq of type uint8
 *   IeAP_b_WrngSpdExceed of type boolean
 *   IeAP_b_FaultStatus of type boolean
 *   IeAP_b_ParkInOutSuccess of type boolean
 *   IeAP_b_ParkInOutAbort of type boolean
 *   IeAP_b_FeatureAvl of type boolean
 *   IeAP_b_ParkOutAvailable of type boolean
 *   IeAP_b_ImgDefeatReqSts of type boolean
 *   IeAP_b_SPMScrnReq of type boolean
 *   IeAP_b_SPMFailSts of type boolean
 *   IeAP_b_SPMFaultSts of type boolean
 *   IeAP_b_VehMnvrDirSPM of type boolean
 *   IeAP_b_AutoParkOverride of type boolean
 *   MeAP_b_SensorFltSts of type boolean
 *   MeAP_b_ChimeActvReqLHFSVM of type boolean
 *   MeAP_b_ChimeActvReqLHRSVM of type boolean
 *   MeAP_b_ChimeActvReqRHFSVM of type boolean
 *   MeAP_b_ChimeActvReqRHRSVM of type boolean
 * TbAP_FPAWarnOut_t: Record with elements
 *   IeAP_e_DispArcCHF of type TeAP_e_Alert
 *   IeAP_e_DispArcLHF of type TeAP_e_Alert
 *   IeAP_e_DispArcRHF of type TeAP_e_Alert
 *   IeAP_e_ArcFlashRateLHF of type TeAP_e_GraphicFlshRate
 *   IeAP_e_ArcFlashRateRHF of type TeAP_e_GraphicFlshRate
 *   IeAP_e_ArcFlashRateCHF of type TeAP_e_GraphicFlshRate
 *   IeAP_b_ChimeActvReqLHF of type boolean
 *   IeAP_b_ChimeActvReqRHF of type boolean
 * TbAP_PAStateOut_t: Record with elements
 *   IeAP_e_PAMChimeRepnRate of type TeAP_e_PAMChimeRepnRate
 *   IeAP_e_PAMVolSig of type TeAP_e_PAMVolume
 *   IeAP_e_FrntParkLEDSts of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMLedCtrl of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMChimeTyp of type TeAP_e_PAMChimeTyp
 *   IeAP_e_ParkSensePopUpReq of type TeAP_e_PAMPopUpReq
 *   IeAP_b_PAMRearBrkReq of type boolean
 *   IeAP_b_PAMRearCtrlSts of type boolean
 * TbAP_RPAWarnOut_t: Record with elements
 *   IeAP_e_DispArcCHR of type TeAP_e_Alert
 *   IeAP_e_DispArcLHR of type TeAP_e_Alert
 *   IeAP_e_DispArcRHR of type TeAP_e_Alert
 *   IeAP_e_ArcFlashRateCHR of type TeAP_e_GraphicFlshRate
 *   IeAP_e_ArcFlashRateLHR of type TeAP_e_GraphicFlshRate
 *   IeAP_e_ArcFlashRateRHR of type TeAP_e_GraphicFlshRate
 *   IeAP_cm_RearDisttoNearObst of type uint16
 *   IeAP_b_ChimeActvReqLHR of type boolean
 *   IeAP_b_ChimeActvReqRHR of type boolean
 * TbAP_SMDAInternalOut_t: Record with elements
 *   MeAP_e_ParkAssistStatus of type TeAP_e_ParkAssistStatus
 *   MeAP_e_GearCmdToHMI of type TeAutoPark_e_GearCmd
 *   IeAP_e_MnvActvStat of type uint8
 *   IeAP_e_AbortCon of type uint8
 *   IeAP_e_SemiParkSysSts of type uint8
 *   IeAP_e_DIDHMICode of type uint8
 *   MeAP_b_AutoParkEnblSwtStuckStatus of type boolean
 *   MeAP_b_ScanSts of type boolean
 *   MeAP_b_ParkSlotDetctSts of type boolean
 *   MeAP_b_ResetKM of type boolean
 * TbAP_SMPAInternalOut_t: Record with elements
 *   MeAP_e_HMIPopUp of type TeAP_e_HMIPopUp
 *   MeAP_b_FPAStatus of type boolean
 *   MeAP_b_RPAStatus of type boolean
 *   MeAP_b_FPASwtStatus of type boolean
 *   MeAP_b_RPASwtStatus of type boolean
 *   MeAP_b_DisableDiag of type boolean
 *   MeAP_b_RPAwithBrkStatus of type boolean
 *   MeAP_b_SystemFail of type boolean
 *   MeAP_b_ExternalFail of type boolean
 *   MeAP_b_TempFail of type boolean
 *   MeAP_b_RPAwithBrkDisable of type boolean
 *   MeAP_b_RPADisable of type boolean
 *   MeAP_b_FPADisable of type boolean
 * TbAP_VCActuatorOut_t: Record with elements
 *   IeAP_nm_StrwTrqReq of type real32_T
 *   IeAP_a_DecelMax of type real32_T
 *   IeAP_a_DecelMin of type real32_T
 *   IeAP_a_JerkDecelMax of type real32_T
 *   IeAP_a_JerkDecelMin of type real32_T
 *   IeAP_a_AcclMin of type real32_T
 *   IeAP_a_AcclMax of type real32_T
 *   IeAP_da_JerkAcclMax of type real32_T
 *   IeAP_da_JerkAcclMin of type real32_T
 *   IeAP_cm_TrgtDist of type real32_T
 *   IeAP_kph_TrgtVehSpd of type real32_T
 *   IeAP_e_TurnIndicReq of type sint32
 *   IeAP_b_StandstillReq of type boolean
 * TbAP_VCStateOut_t: Record with elements
 *   MeAP_e_Park_state of type float32
 *   MeAP_e_PP_state of type sint8
 *   IeAP_cnt_CurrentVehSweep of type uint8
 *   MeAP_b_ManeuverAbort of type boolean
 *   MeAP_b_ManeuverSuccess of type boolean
 *   MeAP_b_PosMet of type boolean
 *   MeAP_b_SteerActionReq of type boolean
 *   IeAP_b_MnvPosOk of type boolean
 * TbFA_ArbiterOutput_t: Record with elements
 *   IeFA_b_ChimeActvLhf of type boolean
 *   IeFA_b_ChimeActvRhf of type boolean
 *   IeFA_b_ChimeActvLhr of type boolean
 *   IeFA_b_ChimeActvRhr of type boolean
 *   IeFA_e_PamChimeRepRateSts of type Rte_DT_TbFA_ArbiterOutput_t_4
 *   IeFA_e_PamChimeTyp of type Rte_DT_TbFA_ArbiterOutput_t_5
 *   IeFA_e_PamVol of type Rte_DT_TbFA_ArbiterOutput_t_6
 * TbFA_ResetKM_t: Record with elements
 *   MeFA_b_ResetKM of type boolean
 * TbSVS_S_SVSCamCurrentCalibDataToNVM_t: Record with elements
 *   bValid of type boolean
 *   FreshnessCount of type uint32
 *   CamCurrent of type TbSVS_S_SVSCamCurrentCalibData_t
 * TbSVS_S_SVSCamCurrentCalibData_t: Record with elements
 *   CamFrontCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamLeftCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRearCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRightCurrent of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 * TbSVS_S_SVSCamEOLCalibDataToNVM_t: Record with elements
 *   bValid of type boolean
 *   FreshnessCount of type uint32
 *   CamEOL of type TbSVS_S_SVSCamEOLCalibData_t
 * TbSVS_S_SVSCamEOLCalibData_t: Record with elements
 *   CamFrontEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamLeftEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRearEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 *   CamRightEOL of type ME_Hydra3defs_S_CamEOLCalibDataSTM_t
 * TbSVS_S_SVSCamOCCalibDataToNVM_t: Record with elements
 *   bValid of type boolean
 *   FreshnessCount of type uint32
 *   LastOCCurrentCam of type ME_Hydra3defs_E_CameraID_t
 *   CamOC of type TbSVS_S_SVSCamOCCalibData_t
 * TbSVS_S_SVSCamOCCalibData_t: Record with elements
 *   CamFrontOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamLeftOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRearOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRightOC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 * TbSVS_S_SVSCamSCCalibDataToNVM_t: Record with elements
 *   bValid of type boolean
 *   FreshnessCount of type uint32
 *   CamSC of type TbSVS_S_SVSCamSCCalibData_t
 * TbSVS_S_SVSCamSCCalibData_t: Record with elements
 *   CamFrontSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamLeftSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRearSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 *   CamRightSC of type ME_Hydra3defs_S_CamCalibDataSTM_t
 * TbSVS_e_CamCalibNVMBlockSM_t: Record with elements
 *   EOL_CamEOLCalibData_STM of type ME_Hydra3defs_S_CamEOLCalibData_t
 *   SC_CamCalibData_STM of type ME_Hydra3defs_S_CamCalibData_t
 *   OC_CamCalibData_STM of type ME_Hydra3defs_S_CamCalibData_t
 *   CamIDNVM_STM of type ME_Hydra3defs_E_CameraID_t
 *   CamCalibIDs_STM of type ME_Hydra3defs_E_CalibrationID_t
 * TbSVS_e_SVSOutputToDiagMgrCamCalib_t: Record with elements
 *   EOL_v_IsRequestedByDiag_b of type boolean
 *   SC_v_IsRequestedByDiag_b of type boolean
 *   EOLCompletedCurrentCycle of type boolean
 *   SCCompletedCurrentCycle of type boolean
 *   EOL_StartConditions_STM of type aZynqM_S_EOL_Conditions_t
 *   SC_StartConditions_STM of type aZynqM_S_SCConditions_t
 *   OC_StartConditions_STM of type aZynqM_S_OC_Conditions_t
 *   EOL_ModuleState_STM of type aZynqM_E_ModuleState_EOL_STM_t
 *   SC_ModuleState_STM of type aZynqM_E_ModuleState_SC_STM_t
 *   OC_ModuleState_STM of type aZynqM_E_ModuleState_OC_STM_t
 *   EOL_Status_STM of type ME_Hydra3defs_S_EOLStatus_arr
 *   SC_Status_STM of type ME_Hydra3defs_S_OCStatus_arr
 *   OC_Status_STM of type ME_Hydra3defs_S_OCStatus_arr
 *   EOL_CalibStatus_STM of type ME_Hydra3defs_E_CalibStatus_arr
 *   SC_CalibStatus_STM of type ME_Hydra3defs_E_CalibStatus_arr
 *   OC_CalibStatus_STM of type ME_Hydra3defs_E_CalibStatus_arr
 * TbSVS_e_SVSOutputToNVMCamCalibSM_t: Record with elements
 *   bValid of type boolean
 *   FreshnessCount of type uint32
 *   CamCalibNVMBlock_STM of type TbSVS_e_CamCalibNVMBlockSM_t
 * TbTHASmVc_DiagMgr_t: Record with elements
 *   MeTHA_px_HitchCplrPixDiffLongAtStrt of type sint32
 *   MeTHA_deg_RoadWhlAng of type real32_T
 *   MeTHA_e_THASpdLimReq of type TeTHA_e_THASpdLimReq
 *   MeTHA_e_THASteerTrqReq of type TeTHA_e_THASteerTrqReq
 *   MeTHA_e_THARmpUpDwnSpd of type TeTHA_e_THARmpUpDwnSpd
 *   MeTHA_e_EPBReq of type TeTHA_e_EPBReq
 *   MeTHA_e_THAStateInfo of type TeTHA_e_THAStateInfo
 *   MeTHA_b_UsrCplrSelCnfm of type boolean
 *   MeTHA_b_TrlrCplrStatus of type boolean
 *   MeTHA_b_THAAbortStatus of type boolean
 *   MeTHA_b_UsrInputTimeOut of type boolean
 *   MeTHA_b_ViewZoomSts of type boolean
 *   MeTHA_b_CamOccluLoLi of type boolean
 * TbTHASmVc_FeatureOutputs_t: Record with elements
 *   IeTHA_M_THASteerTrqInfo of type real32_T
 *   IeTHA_pct_THAStrDamp of type real32_T
 *   MeTHA_deg_RoadWhlAng of type real32_T
 *   IeTHA_e_THAState of type TeTHA_e_THAState
 *   IeTHA_e_THASpdLimReq of type TeTHA_e_THASpdLimReq
 *   IeTHA_e_PamVol of type TeTHA_e_PamVol
 *   IeTHA_e_PamChimeTyp of type TeTHA_e_PamChimeTyp
 *   IeTHA_e_PamChimeRepRateSts of type TeTHA_e_PamChimeRepRateSts
 *   IeTHA_e_THASteerTrqReq of type TeTHA_e_THASteerTrqReq
 *   IeTHA_e_THARmpUpDwnSpd of type TeTHA_e_THARmpUpDwnSpd
 *   IeTHA_e_EPBReq of type TeTHA_e_EPBReq
 *   MeTHA_e_THAStateInfo of type TeTHA_e_THAStateInfo
 *   MeTHA_e_ScreenRequest of type TeTHA_e_ScreenRequest
 *   MeTHA_e_RearBrkSupprInfo of type TeTHA_e_RearBrkSupprInfo
 *   IeTHA_b_ChimeActvLhf of type boolean
 *   IeTHA_b_ChimeActvRhf of type boolean
 *   IeTHA_b_ChimeActvLhr of type boolean
 *   IeTHA_b_ChimeActvRhr of type boolean
 *   MeTHA_b_EnblRearParkAsstTrg of type boolean
 *   MeTHA_b_UsrHitchCnfm of type boolean
 *   MeTHA_b_UsrCplrSelCnfm of type boolean
 *   MeTHA_b_TrlrCplrStatus of type boolean
 *   MeTHA_b_THAAbortStatus of type boolean
 * TeTRSC_e_TrailerCalibMemClearResponse_t: Record with elements
 *   CalibMemClearResponse of type Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0
 *   bValid of type boolean
 * TrailerDetection_Output_DID_t: Record with elements
 *   Trailer_tracking_confidence of type float32
 *   Trailer_Recognition_Confidence of type float32
 *   Trailer_Calibration_Status of type TrlrCalInfo_t
 *   Trailer_Calibration_maneuver_State of type State_t
 *   Trailer_Calibration_Fail_Count of type uint32
 *   Trailer_Calibration_Fail_Reason of type TrailerCalibrationFailInfo_t
 *   Trailer_Calibration_Pass_Count of type uint32
 *   Trailer_Presence_detection of type TrailerPresentInfo_t
 *   Trailer_Recognition_ID of type TrailerID_t
 *   Trailer_known_or_Unknown of type RecognitionInfo_t
 *   trailerDetectionFailReason of type DetectionFailInfo_t
 *   Trailer_Angle_current of type float32
 *   IeTRSC_e_CamBlockSts of type TeTRSC_e_CamBlockSts
 *   IeTRSC_e_TrailerCalibMemClearResponse_t of type TeTRSC_e_TrailerCalibMemClearResponse_t
 *   Trailer_Calibration_maneuver_State_DID of type CalibrationState_DID_t
 *   Trailer_Calibration_Status_DID of type TeTRSC_e_TrlrCalInfo_DID
 *   Trailer_Calibration_Fail_Count_Current_key_cycle of type uint32
 *   Trailer_Calibration_Fail_Reason_DID of type TrailerCalibrationFailInfo_DID_t
 *   Trailer_Calibration_Pass_Count_Current_key_cycle of type uint32
 *   Trailer_Presence_detection_DID of type TeTRSC_e_TrlrPrsntInfo_DID
 *   trailerDetectionFailReason_DID of type DetectionFailInfo_DID_t
 *   Trailer_known_or_Unknown_DID of type TeTRSC_e_TrlrRecogInfo_DID
 *   Trailer_detection_Confidence of type float32
 * US_ME_FiringSensorsOutputBuff_t: Record with elements
 *   timestamp of type uint32
 *   firingSensors of type uint16
 *   rsv of type uint16
 * US_ME_SensorFiringModeOutputBuff_t: Record with elements
 *   timestamp of type uint32
 *   sensorFiringMode of type uint8
 *   rsv of type rsv_Array
 * US_ME_SnsDat_FrontPSM_Echoes_t: Record with elements
 *   Sig_SnsDat_FSL_Timestamp_us of type uint16
 *   Sig_SnsDat_FSL_DirEcho1_cm of type uint16
 *   Sig_SnsDat_FSL_DirEcho2_cm of type uint16
 *   Sig_SnsDat_FSR_Timestamp_us of type sint16_t
 *   Sig_SnsDat_FSR_DirEcho1_cm of type uint16
 *   Sig_SnsDat_FSR_DirEcho2_cm of type uint16
 * US_ME_SnsDat_Front_Direct_2_t: Record with elements
 *   Sig_SnrDat_FSR_Dir2_cm of type uint16
 *   Sig_SnrDat_FOR_Dir2_cm of type uint16
 *   Sig_SnrDat_FIR_Dir2_cm of type uint16
 *   Sig_SnrDat_FIL_Dir2_cm of type uint16
 *   Sig_SnrDat_FOL_Dir2_cm of type uint16
 *   Sig_SnrDat_FSL_Dir2_cm of type uint16
 * US_ME_SnsDat_Front_Direct_t: Record with elements
 *   Sig_SnrDat_FSR_Dir1_cm of type uint16
 *   Sig_SnrDat_FOR_Dir1_cm of type uint16
 *   Sig_SnrDat_FIR_Dir1_cm of type uint16
 *   Sig_SnrDat_FIL_Dir1_cm of type uint16
 *   Sig_SnrDat_FOL_Dir1_cm of type uint16
 *   Sig_SnrDat_FSL_Dir1_cm of type uint16
 * US_ME_SnsDat_RearSide_Echoes_t: Record with elements
 *   Sig_SnsDat_RSL_Timestamp_us of type uint16
 *   Sig_SnsDat_RSL_DirEcho1_cm of type uint16
 *   Sig_SnsDat_RSL_DirEcho2_cm of type uint16
 *   Sig_SnsDat_RSR_Timestamp_us of type uint16
 *   Sig_SnsDat_RSR_DirEcho1_cm of type uint16
 *   Sig_SnsDat_RSR_DirEcho2_cm of type uint16
 * US_ME_SnsDat_Rear_Direct_2_t: Record with elements
 *   Sig_SnrDat_RSR_Dir2_cm of type uint16
 *   Sig_SnrDat_ROR_Dir2_cm of type uint16
 *   Sig_SnrDat_RIR_Dir2_cm of type uint16
 *   Sig_SnrDat_RIL_Dir2_cm of type uint16
 *   Sig_SnrDat_ROL_Dir2_cm of type uint16
 *   Sig_SnrDat_RSL_Dir2_cm of type uint16
 * US_ME_SnsDat_Rear_Direct_t: Record with elements
 *   Sig_SnrDat_RSR_Dir1_cm of type uint16
 *   Sig_SnrDat_ROR_Dir1_cm of type uint16
 *   Sig_SnrDat_RIR_Dir1_cm of type uint16
 *   Sig_SnrDat_RIL_Dir1_cm of type uint16
 *   Sig_SnrDat_ROL_Dir1_cm of type uint16
 *   Sig_SnrDat_RSL_Dir1_cm of type uint16
 * US_S_BlockageBit_t: Record with elements
 *   timestamp of type uint32
 *   blockageFlagBits of type uint16
 *   Rsv of type uint16
 * US_S_CsmStateChangeReason_Type: Record with elements
 *   CsmStateCurrent of type uint8
 *   CsmStatePreviuos of type uint8
 *   CsmLocalModuleId of type uint8
 *   CsmLocalModuleInstanceId of type uint8
 *   CsmLocalErrOrEventId of type uint8
 *   CsmLocalErrOrEventState of type uint8
 * US_S_DebugMsg_t: Record with elements
 *   Sig_Debug_Signal of type Sig_Debug_Signal_Arr
 *   Unsig_Debug_Signal of type Unsig_Debug_Signal_Arr
 * US_S_DiagnosticsOutputBuff_t: Record with elements
 *   timestamp of type uint32
 *   overTempFault of type uint16
 *   commFault of type uint16
 *   commUnknown of type uint16
 *   hardwareFault of type uint16
 * US_S_DrivingFrequency_t: Record with elements
 *   uDrvFreq_FSR of type uint16
 *   uDrvFreq_FOR of type uint16
 *   uDrvFreq_FIR of type uint16
 *   uDrvFreq_FIL of type uint16
 *   uDrvFreq_FOL of type uint16
 *   uDrvFreq_FSL of type uint16
 *   uDrvFreq_RSR of type uint16
 *   uDrvFreq_ROR of type uint16
 *   uDrvFreq_RIR of type uint16
 *   uDrvFreq_RIL of type uint16
 *   uDrvFreq_ROL of type uint16
 *   uDrvFreq_RSL of type uint16
 * US_S_Firing_Sequence_t: Record with elements
 *   Sig_Current_Firing_Sequence of type uint8
 *   rsv of type rsv_Array
 * US_S_MarriageSensorIDs_t: Record with elements
 *   bValid of type boolean
 *   uMarriageStatus of type uint32
 *   uSavedSensorIDs of type uSavedSensorIDs_au32
 * US_S_PointDistOutputBuff_t: Record with elements
 *   timestamp of type uint32
 *   minDist of type minDist_Array
 *   midDist of type midDist_Array
 * US_S_PointMapGroup_t: Record with elements
 *   FiringSensors of type US_ME_FiringSensorsOutputBuff_t
 *   FiringMode of type US_ME_SensorFiringModeOutputBuff_t
 *   PointMap of type US_S_PointMapOutputBuff_t
 *   FiringSequence of type US_S_Firing_Sequence_t
 * US_S_PointMapOutputBuff_t: Record with elements
 *   timestamp of type uint32
 *   pointMap of type US_S_PointOutputBuff_Array
 * US_S_PointOutputBuff_t: Record with elements
 *   x of type sint16
 *   y of type sint16
 *   height of type uint8
 *   Cruising_Age of type uint8
 *   confidence of type uint8
 *   age of type uint8
 * US_S_RigningFrequency_t: Record with elements
 *   uRingFreq_FSR of type uint16
 *   uRingFreq_FOR of type uint16
 *   uRingFreq_FIR of type uint16
 *   uRingFreq_FIL of type uint16
 *   uRingFreq_FOL of type uint16
 *   uRingFreq_FSL of type uint16
 *   uRingFreq_RSR of type uint16
 *   uRingFreq_ROR of type uint16
 *   uRingFreq_RIR of type uint16
 *   uRingFreq_RIL of type uint16
 *   uRingFreq_ROL of type uint16
 *   uRingFreq_RSL of type uint16
 * US_S_RigningTime_t: Record with elements
 *   uRingTime_FSR of type uint16
 *   uRingTime_FOR of type uint16
 *   uRingTime_FIR of type uint16
 *   uRingTime_FIL of type uint16
 *   uRingTime_FOL of type uint16
 *   uRingTime_FSL of type uint16
 *   uRingTime_RSR of type uint16
 *   uRingTime_ROR of type uint16
 *   uRingTime_RIR of type uint16
 *   uRingTime_RIL of type uint16
 *   uRingTime_ROL of type uint16
 *   uRingTime_RSL of type uint16
 * US_S_SensorTemp_t: Record with elements
 *   sSensorTemp_FSR of type sint16_t
 *   sSensorTemp_FOR of type sint16_t
 *   sSensorTemp_FIR of type sint16_t
 *   sSensorTemp_FIL of type sint16_t
 *   sSensorTemp_FOL of type sint16_t
 *   sSensorTemp_FSL of type sint16_t
 *   sSensorTemp_RSR of type sint16_t
 *   sSensorTemp_ROR of type sint16_t
 *   sSensorTemp_RIR of type sint16_t
 *   sSensorTemp_RIL of type sint16_t
 *   sSensorTemp_ROL of type sint16_t
 *   sSensorTemp_RSL of type sint16_t
 * US_S_SnrDirEcho_t: Record with elements
 *   FrontSnrDirEcho1 of type US_ME_SnsDat_Front_Direct_t
 *   FrontSnrDirEcho2 of type US_ME_SnsDat_Front_Direct_2_t
 *   FrontPSMEcho of type US_ME_SnsDat_FrontPSM_Echoes_t
 *   RearSnrDirEcho1 of type US_ME_SnsDat_Rear_Direct_t
 *   RearSnrDirEcho2 of type US_ME_SnsDat_Rear_Direct_2_t
 *   RearSideEcho of type US_ME_SnsDat_RearSide_Echoes_t
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
 * US_S_SnrPowerSupply_t: Record with elements
 *   uUSSPowerAMonVtg of type uint16
 *   uUSSPowerBMonVtg of type uint16
 *   uUSSPowerCMonVtg of type uint16
 *   uUSSPowerIS1Current of type uint16
 *   uUSSPowerIS2Current of type uint16
 *   Reserved of type uint16
 * US_S_USSConstantData_t: Record with elements
 *   SensorPartNum of type US_S_USSPartNumberData_t
 *   SensorIMESerialNum of type US_S_SnrIMESerialNum_t
 *   SensorMurataSerialNum of type US_S_SnrMurataSerialNum_t
 *   USS_Ver of type US_S_USSVersion_t
 * US_S_USSDataCollectionData_t: Record with elements
 *   Log_SnrMeasData_01 of type Log_SnrMeasData1_Array
 *   Log_SnrMeasData_02 of type Log_SnrMeasData2_Array
 *   Log_SnrMeasData_03 of type Log_SnrMeasData3_Array
 *   Log_SnrMeasData_04 of type Log_SnrMeasData4_Array
 *   Log_SnrMeasData_05 of type Log_SnrMeasData5_Array
 *   Log_SnrMeasData_06 of type Log_SnrMeasData6_Array
 *   Log_SnrMeasData_07 of type Log_SnrMeasData7_Array
 *   Log_SnrTemperature of type Log_SnrTemperature_Array
 *   Log_PackedNoiseMeasData of type Log_PackedNoiseMeasData_Array
 *   Log_PackedDiagFlagData1_v of type Log_PackedDiagFlagData1_v_Array
 *   Log_PackedDiagFlagData2_v of type Log_PackedDiagFlagData2_v_Array
 * US_S_USSErrorDiagData_t: Record with elements
 *   ErrorMsg of type US_S_DiagnosticsOutputBuff_t
 *   live_detection of type uint16
 *   rsv_u16 of type uint16
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
 * US_S_USSPeriodDiagData_t: Record with elements
 *   SnrDrvFreq of type US_S_DrivingFrequency_t
 *   SnrRingFreq of type US_S_RigningFrequency_t
 *   SnrRingTime of type US_S_RigningTime_t
 *   SnrTemperature of type US_S_SensorTemp_t
 *   SnrPwr of type US_S_SnrPowerSupply_t
 *   BlockageSetCnt of type US_S_uBlockageSetCnt_t
 *   BlockageClrCnt of type US_S_uBlockageClrCnt_t
 * US_S_USSVersion_t: Record with elements
 *   US_CalVer of type uint32
 *   US_SnrVer of type uint16
 *   US_ModuleVer_YEAR of type uint8
 *   US_ModuleVer_WEEK of type uint8
 *   US_ModuleVer_DAY of type uint8
 *   US_ModuleVer_BUILD of type uint8
 *   Rsv of type rev_arr
 * US_S_ZoneInfo_t: Record with elements
 *   timestamp of type uint32
 *   zoneInfo of type US_E_Zoneinfo_list_Array
 * US_S_uBlockageClrCnt_t: Record with elements
 *   uBlockageClrCnt_FSR of type uint16
 *   uBlockageClrCnt_FOR of type uint16
 *   uBlockageClrCnt_FIR of type uint16
 *   uBlockageClrCnt_FIL of type uint16
 *   uBlockageClrCnt_FOL of type uint16
 *   uBlockageClrCnt_FSL of type uint16
 *   uBlockageClrCnt_RSR of type uint16
 *   uBlockageClrCnt_ROR of type uint16
 *   uBlockageClrCnt_RIR of type uint16
 *   uBlockageClrCnt_RIL of type uint16
 *   uBlockageClrCnt_ROL of type uint16
 *   uBlockageClrCnt_RSL of type uint16
 * US_S_uBlockageSetCnt_t: Record with elements
 *   uBlockageSetCnt_FSR of type uint16
 *   uBlockageSetCnt_FOR of type uint16
 *   uBlockageSetCnt_FIR of type uint16
 *   uBlockageSetCnt_FIL of type uint16
 *   uBlockageSetCnt_FOL of type uint16
 *   uBlockageSetCnt_FSL of type uint16
 *   uBlockageSetCnt_RSR of type uint16
 *   uBlockageSetCnt_ROR of type uint16
 *   uBlockageSetCnt_RIR of type uint16
 *   uBlockageSetCnt_RIL of type uint16
 *   uBlockageSetCnt_ROL of type uint16
 *   uBlockageSetCnt_RSL of type uint16
 * UssTunningData_mcu2_1_t: Record with elements
 *   UssTunningDataOut of type UssTunningDataOut_arr
 * VehInpAdapter_opVehSignals: Record with elements
 *   dt_ESP_0x318 of type ME_VehInpAdp_ESP_0x318
 *   dt_ESP_0x261 of type ME_VehInpAdp_ESP_0x261
 *   dt_ESP_0x305 of type ME_VehInpAdp_ESP_0x305
 *   dt_ESP_0x306 of type ME_VehInpAdp_ESP_0x306
 *   dt_ESP_0x268 of type ME_VehInpAdp_ESP_0x268
 *   dt_ESP_0x120 of type ME_VehInpAdp_ESP_0x120
 *   dt_ESP_0x122 of type ME_VehInpAdp_ESP_0x122
 *   dt_iBooster_0x271 of type ME_VehInpAdp_iBooster_0x271
 *   dt_EPS_0x1C2 of type ME_VehInpAdp_EPS_0x1C2
 *   dt_EPS_0x1C4 of type ME_VehInpAdp_EPS_0x1C4
 *   dt_EPS_0x475 of type ME_VehInpAdp_EPS_0x475
 *   dt_ACU_0x59 of type ME_VehInpAdp_ACU_0x59
 *   dt_ACU_0x159 of type ME_VehInpAdp_ACU_0x159
 *   dt_ESP_0x30A of type ME_VehInpAdp_ESP_0x30A
 *   dt_BCM_0x335 of type ME_VehInpAdp_BCM_0x335
 *   dt_BCM_0x343 of type ME_VehInpAdp_BCM_0x343
 *   dt_ECC_0x373 of type ME_VehInpAdp_ECC_0x373
 *   dt_PLGM_0x471 of type ME_VehInpAdp_PLGM_0x471
 *   dt_CIM_0x310 of type ME_VehInpAdp_CIM_0x310
 *   dt_VCU_0x225 of type ME_VehInpAdp_VCU_0x225
 *   dt_VCU_0x214 of type ME_VehInpAdp_VCU_0x214
 *   dt_ICC_0x531 of type ME_VehInpAdp_ICC_0x531
 *   dt_ICC_0x530 of type ME_VehInpAdp_ICC_0x530
 *   dt_BCM_0x333 of type ME_VehInpAdp_BCM_0x333
 *   dt_MCU_F_0x150 of type ME_VehInpAdp_MCU_F_0x150
 *   dt_ESP_0x125 of type ME_VehInpAdp_ESP_0x125
 *   dt_MFS_0x514 of type ME_VehInpAdp_MFS_0x514
 *   dt_ICC_0x361 of type ME_VehInpAdp_ICC_0x361
 *   dt_ICC_0x250 of type ME_VehInpAdp_ICC_0x250
 *   dt_ICC_0x251 of type ME_VehInpAdp_ICC_0x251
 *   dt_ICC_0x362 of type ME_VehInpAdp_ICC_0x362
 *   dt_ICC_0x252 of type ME_VehInpAdp_ICC_0x252
 *   dt_ICC_0x253 of type ME_VehInpAdp_ICC_0x253
 *   dt_ICC_0x255 of type ME_VehInpAdp_ICC_0x255
 *   dt_VCU_0x1BA of type ME_VehInpAdp_VCU_0x1BA
 *   dt_ESP_0x1B8 of type ME_VehInpAdp_ESP_0x1B8
 *   dt_ESP_0x262 of type ME_VehInpAdp_ESP_0x262
 *   dt_TRM_0x348 of type ME_VehInpAdp_TRM_0x348
 *   dt_TBOX_0x525 of type ME_VehInpAdp_TBOX_0x525
 *   dt_TBOX_0x24B of type ME_VehInpAdp_TBOX_0x24B
 *   dt_TBOX_0x24C of type ME_VehInpAdp_TBOX_0x24C
 *   dt_TBOX_0x36 of type ME_VehInpAdp_TBOX_0x36
 *   dt_YRS_0x242 of type ME_VehInpAdp_YRS_0x242
 *   dt_YRS_0x246 of type ME_VehInpAdp_YRS_0x246
 *   dt_ICC_0x52A of type ME_VehInpAdp_ICC_0x52A
 *   dt_ICC_0x171 of type ME_VehInpAdp_ICC_0x171
 * WdgCheckpointStatus_t: Record with elements
 *   timeoutCntr_u16 of type uint16
 *   seid_s of type uint16
 *   wdgDataLiveCntr_u32 of type uint32
 * aZynqM_S_EOL_Conditions_t: Record with elements
 *   LeftFrontDoor_b of type boolean
 *   RightFrontDoor_b of type boolean
 *   LeftRearDoor_b of type boolean
 *   RightRearDoor_b of type boolean
 *   Hood_b of type boolean
 *   Tailgate_b of type boolean
 *   InnerTailgate_b of type boolean
 *   LeftMirror_b of type boolean
 *   RightMirror_b of type boolean
 *   VehicleLevel_b of type boolean
 *   ZynqModuleState_b of type boolean
 * aZynqM_S_OC_Conditions_t: Record with elements
 *   Configuration_b of type boolean
 *   ApprovedByApplication_b of type boolean
 *   EOLSCCalibration_b of type boolean
 *   DrivingForward of type boolean
 *   SpeedValid_b of type boolean
 *   IgnitionState_b of type boolean
 * aZynqM_S_SCConditions_t: Record with elements
 *   LeftFrontDoor_b of type boolean
 *   RightFrontDoor_b of type boolean
 *   LeftRearDoor_b of type boolean
 *   RightRearDoor_b of type boolean
 *   Hood_b of type boolean
 *   Tailgate_b of type boolean
 *   DrivingForward of type boolean
 *   SpeedValid_b of type boolean
 *   LeftMirror_b of type boolean
 *   RightMirror_b of type boolean
 *   VehicleLevel_b of type boolean
 *   SteeringAngle_b of type boolean
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   INVMSignalManager_t *Rte_Pim_FPA_Slot_Data_MirrorBlock(void)
 *   uint8 *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 Rte_CData_FeatureAP_HMI_NvMData_DefaultValue(void)
 *   INVMSignalManager_t *Rte_CData_FPA_Slot_Data_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define CDD_IPCHandler_START_SEC_CODE
#include "CDD_IPCHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CddIpcHandler_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CddIpcHandler_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_IPCHandler_CODE) CddIpcHandler_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CddIpcHandler_Init
 *********************************************************************************************************************/
  /* DD-ID: {47862008-D463-46ad-81F3-2DBF5BC0AC42}*/
uint32_t v_errorRet_u32 = D_IPC_NO_ERROR;
S_SendNvmDataFlag = FALSE;
v_errorRet_u32 = IPC_F_ManagerInit_u32();
if(v_errorRet_u32 != D_IPC_NO_ERROR)
{
  /* IPC Not Initialized Error MSG */
}
Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock = Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy;
Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock = Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CddIpcHandler_Main
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
 *   Std_ReturnType Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(TbAP_APSMPAOut_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Read_RpCan14DbgRoutineState_Can14DbgRoutine(CanDebugMode_t *data)
 *   Std_ReturnType Rte_Read_RpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(Debug_HMI_Curr_Requested_Overlays *data)
 *   Std_ReturnType Rte_Read_RpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(Debug_HMI_Curr_Displayed_Overlays *data)
 *   Std_ReturnType Rte_Read_RpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(Debug_HMI_Curr_Displayed_ProxiConfig *data)
 *   Std_ReturnType Rte_Read_RpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(Debug_HMI_Curr_Requested_ProxiConfig *data)
 *   Std_ReturnType Rte_Read_RpDebHmiInput_Debug_HMI_Input_Data_t(Debug_HMI_Input_Data_t *data)
 *   Std_ReturnType Rte_Read_RpDebHmiInternal_Debug_HMI_Internal_Data_t(Debug_HMI_Internal_Data_t *data)
 *   Std_ReturnType Rte_Read_RpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(Debug_HMI_Trailer_Views_Data_t *data)
 *   Std_ReturnType Rte_Read_RpDetInpTrsc_Detection_Inputs_from_TRSC_t(Detection_Inputs_from_TRSC_t *data)
 *   Std_ReturnType Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(TbAP_DriveAssistStatOut_t *data)
 *   Std_ReturnType Rte_Read_RpFPAWarnOut_TbAP_FPAWarnOut_t(TbAP_FPAWarnOut_t *data)
 *   Std_ReturnType Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(TbTHASmVc_FeatureOutputs_t *data)
 *   Std_ReturnType Rte_Read_RpIDebugFODObject_IDebug_FODObject_t(IDebug_FODObject_t *data)
 *   Std_ReturnType Rte_Read_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t(IFOD_Outputs_Arbitration_t *data)
 *   Std_ReturnType Rte_Read_RpIJobUSSObjOp_IJobUSSObjectMapOutput_t(IJobUSSObjectMapOutput_t *data)
 *   Std_ReturnType Rte_Read_RpJobFPAData_IJobFPAOutput_t(IJobFPAOutput_t *data)
 *   Std_ReturnType Rte_Read_RpJobPLDData_IJobPLDOutput_t(IJobPLDOutput_t *data)
 *   Std_ReturnType Rte_Read_RpJobTHADetOutput_JobTHADetOutput_t(JobTHADetOutput_t *data)
 *   Std_ReturnType Rte_Read_RpLMDLaneOp_LMD_Lane_Outputs_s(LMD_Lane_Outputs_s *data)
 *   Std_ReturnType Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
 *   Std_ReturnType Rte_Read_RpNFCDOutput_NFCD_Output(NFCD_Output *data)
 *   Std_ReturnType Rte_Read_RpNVMSignMgr_NVMSignalManager_t(NVMSignalManager_t *data)
 *   Std_ReturnType Rte_Read_RpPAStateOut_TbAP_PAStateOut_t(TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Read_RpPointDistOpBuff_US_S_PointDistOutputBuff_t(US_S_PointDistOutputBuff_t *data)
 *   Std_ReturnType Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t(TbAP_RPAWarnOut_t *data)
 *   Std_ReturnType Rte_Read_RpSMDAInternal_TbAP_SMDAInternalOut_t(TbAP_SMDAInternalOut_t *data)
 *   Std_ReturnType Rte_Read_RpSR_State_MCU2_State_2_0(SSM_2_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_RpSR_State_MCU2_State_2_1(SSM_2_1_CoreStatus *data)
 *   Std_ReturnType Rte_Read_RpSVSNVMData_SVS_NVMData_t(SVS_NVMData_t *data)
 *   Std_ReturnType Rte_Read_RpSVStoTRSC_SVStoTRSC_t(SVStoTRSC_t *data)
 *   Std_ReturnType Rte_Read_RpScreenRequest_ScreenRequest_t(ScreenRequest_t *data)
 *   Std_ReturnType Rte_Read_RpSvsToTHA_SvsToTHA_t(SvsToTHA_t *data)
 *   Std_ReturnType Rte_Read_RpSvsToVCAN_SvsToVCAN_t(SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Read_RpTRSC_ME_VehOut_TRSC_t(ME_VehOut_TRSC_t *data)
 *   Std_ReturnType Rte_Read_RpTbAPDebugOut_TbAP_DebugOut(TbAP_DebugOut *data)
 *   Std_ReturnType Rte_Read_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(TbAP_SMPAInternalOut_t *data)
 *   Std_ReturnType Rte_Read_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(TbFA_ArbiterOutput_t *data)
 *   Std_ReturnType Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t(TbFA_ResetKM_t *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(CmdIgnSts *data)
 *   Std_ReturnType Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t(TrailerDetection_Output_DID_t *data)
 *   Std_ReturnType Rte_Read_RpTrscSmvctoSvs_TRSCSMVCtoSVS_t(TRSCSMVCtoSVS_t *data)
 *   Std_ReturnType Rte_Read_RpTrscToDiag_TRSCtoDiagMgr_t(TRSCtoDiagMgr_t *data)
 *   Std_ReturnType Rte_Read_RpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(TRSC_Inputs_from_TrailerDetection_t *data)
 *   Std_ReturnType Rte_Read_RpUSSBlockageBit_US_S_BlockageBit_t(US_S_BlockageBit_t *data)
 *   Std_ReturnType Rte_Read_RpUSSErrorDiagData_US_S_USSErrorDiagData_t(US_S_USSErrorDiagData_t *data)
 *   Std_ReturnType Rte_Read_RpUssDataCollection_US_S_USSDataCollectionData_t(US_S_USSDataCollectionData_t *data)
 *   Std_ReturnType Rte_Read_RpUssPointMapGrp_US_S_PointMapGroup_t(US_S_PointMapGroup_t *data)
 *   Std_ReturnType Rte_Read_RpUssZoneInfo_US_S_ZoneInfo_t(US_S_ZoneInfo_t *data)
 *   Std_ReturnType Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t(TbAP_VCActuatorOut_t *data)
 *   Std_ReturnType Rte_Read_RpVCState_TbAP_VCStateOut_t(TbAP_VCStateOut_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpAPSMPAOut_TbAP_APSMPAOut_t(const TbAP_APSMPAOut_t *data)
 *   Std_ReturnType Rte_Write_PpCAMSelInfo_CAM_select_info_t(const CAM_select_info_t *data)
 *   Std_ReturnType Rte_Write_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(const IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Write_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(const LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Write_PpCamCsData_CAM_CS_Curr_Monitor_t(const CAM_CS_Curr_Monitor_t *data)
 *   Std_ReturnType Rte_Write_PpCamEepromData_Svs_CamEepromDataArray_t(const Svs_CamEepromDataArray_t *data)
 *   Std_ReturnType Rte_Write_PpCamSerENStat_Cam_and_Ser_EN_Status_t(const Cam_and_Ser_EN_Status_t *data)
 *   Std_ReturnType Rte_Write_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(const CpuLoadMcu2_0_t *data)
 *   Std_ReturnType Rte_Write_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(const CpuLoadMcu2_1_t *data)
 *   Std_ReturnType Rte_Write_PpDLDOutput_JobDLDOutput_t(const JobDLDOutput_t *data)
 *   Std_ReturnType Rte_Write_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(const Debug_HMI_Curr_Requested_Overlays *data)
 *   Std_ReturnType Rte_Write_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(const Debug_HMI_Curr_Displayed_Overlays *data)
 *   Std_ReturnType Rte_Write_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(const Debug_HMI_Curr_Displayed_ProxiConfig *data)
 *   Std_ReturnType Rte_Write_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(const Debug_HMI_Curr_Requested_ProxiConfig *data)
 *   Std_ReturnType Rte_Write_PpDebHmiInput_Debug_HMI_Input_Data_t(const Debug_HMI_Input_Data_t *data)
 *   Std_ReturnType Rte_Write_PpDebHmiInternal_Debug_HMI_Internal_Data_t(const Debug_HMI_Internal_Data_t *data)
 *   Std_ReturnType Rte_Write_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(const Debug_HMI_Trailer_Views_Data_t *data)
 *   Std_ReturnType Rte_Write_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(const Detection_Inputs_from_TRSC_t *data)
 *   Std_ReturnType Rte_Write_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(const TbAP_DriveAssistStatOut_t *data)
 *   Std_ReturnType Rte_Write_PpDrverSecuBltAlrmSts_TeVBII_e_DrverSecuBltAlrmSts(TeVBII_e_DrverSecuBltAlrmSts data)
 *   Std_ReturnType Rte_Write_PpEPS_VehInpAdapter_opVehSignals(const VehInpAdapter_opVehSignals *data)
 *   Std_ReturnType Rte_Write_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(const Error_Fault_MCU2_0_t *data)
 *   Std_ReturnType Rte_Write_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(const Error_Fault_MCU2_1_t *data)
 *   Std_ReturnType Rte_Write_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(const Error_Fault_MPU1_0_t *data)
 *   Std_ReturnType Rte_Write_PpFPAWarnOut_TbAP_FPAWarnOut_t(const TbAP_FPAWarnOut_t *data)
 *   Std_ReturnType Rte_Write_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(const TbTHASmVc_FeatureOutputs_t *data)
 *   Std_ReturnType Rte_Write_PpIDebugFODObject_IDebug_FODObject_t(const IDebug_FODObject_t *data)
 *   Std_ReturnType Rte_Write_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(const IFOD_Outputs_Arbitration_t *data)
 *   Std_ReturnType Rte_Write_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(const IJobUSSObjectMapOutput_t *data)
 *   Std_ReturnType Rte_Write_PpJobFPAData_IJobFPAOutput_t(const IJobFPAOutput_t *data)
 *   Std_ReturnType Rte_Write_PpJobPLDData_IJobPLDOutput_t(const IJobPLDOutput_t *data)
 *   Std_ReturnType Rte_Write_PpJobTHADetOutput_JobTHADetOutput_t(const JobTHADetOutput_t *data)
 *   Std_ReturnType Rte_Write_PpKeepAliveResponse_KeepAliveResponse_t(const KeepAliveResponse_t *data)
 *   Std_ReturnType Rte_Write_PpLMDLaneOp_LMD_Lane_Outputs_s(const LMD_Lane_Outputs_s *data)
 *   Std_ReturnType Rte_Write_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(const ME_Proxi_MPU1_0_to_MCU1_0_t *data)
 *   Std_ReturnType Rte_Write_PpNFCDOutput_NFCD_Output(const NFCD_Output *data)
 *   Std_ReturnType Rte_Write_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t(const TbSVS_e_SVSOutputToNVMCamCalibSM_t *data)
 *   Std_ReturnType Rte_Write_PpNVMSignMgr_NVMSignalManager_t(const NVMSignalManager_t *data)
 *   Std_ReturnType Rte_Write_PpPAM2BTIpcTxStatus_IpcTxDone(boolean data)
 *   Std_ReturnType Rte_Write_PpPAStateOut_TbAP_PAStateOut_t(const TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Write_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(const US_S_PointDistOutputBuff_t *data)
 *   Std_ReturnType Rte_Write_PpRPAWarnOut_TbAP_RPAWarnOut_t(const TbAP_RPAWarnOut_t *data)
 *   Std_ReturnType Rte_Write_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(const RunTimeStats_MCU2_0_t *data)
 *   Std_ReturnType Rte_Write_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(const RunTimeStats_MCU2_1_t *data)
 *   Std_ReturnType Rte_Write_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(const RunTimeStats_MPU1_0_t *data)
 *   Std_ReturnType Rte_Write_PpSMDAInternal_TbAP_SMDAInternalOut_t(const TbAP_SMDAInternalOut_t *data)
 *   Std_ReturnType Rte_Write_PpSR_State_MCU2_State_2_0(const SSM_2_0_CoreStatus *data)
 *   Std_ReturnType Rte_Write_PpSR_State_MCU2_State_2_1(const SSM_2_1_CoreStatus *data)
 *   Std_ReturnType Rte_Write_PpSR_State_QNX_State_QNX(const SSM_QNX_CoreStatus *data)
 *   Std_ReturnType Rte_Write_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Write_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(const TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Write_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(const TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Write_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(const TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Write_PpSVSNVMData_SVS_NVMData_t(const SVS_NVMData_t *data)
 *   Std_ReturnType Rte_Write_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(const TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
 *   Std_ReturnType Rte_Write_PpSVSToDiag_SVSToDiag_t(const SVSToDiag_t *data)
 *   Std_ReturnType Rte_Write_PpSVStoTRSC_SVStoTRSC_t(const SVStoTRSC_t *data)
 *   Std_ReturnType Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_1_0_B(const ErrorMgr_ErrorCommPack_1_0_B *data)
 *   Std_ReturnType Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(const ErrorMgr_ErrorCommPack_2_0_B *data)
 *   Std_ReturnType Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(const ErrorMgr_ErrorCommPack_2_1_B *data)
 *   Std_ReturnType Rte_Write_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(const ErrorMgr_ErrorCommPack_QNX_B *data)
 *   Std_ReturnType Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_1_0_QM(const ErrorMgr_ErrorCommPack_1_0_QM *data)
 *   Std_ReturnType Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(const ErrorMgr_ErrorCommPack_2_0_QM *data)
 *   Std_ReturnType Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(const ErrorMgr_ErrorCommPack_2_1_QM *data)
 *   Std_ReturnType Rte_Write_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(const ErrorMgr_ErrorCommPack_QNX_QM *data)
 *   Std_ReturnType Rte_Write_PpScreenRequest_ScreenRequest_t(const ScreenRequest_t *data)
 *   Std_ReturnType Rte_Write_PpScreenResponse_ScreenResponse_t(const ScreenResponse_t *data)
 *   Std_ReturnType Rte_Write_PpSnrDirEcho_US_S_SnrDirEcho_t(const US_S_SnrDirEcho_t *data)
 *   Std_ReturnType Rte_Write_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(const StackUsage_MCU2_0_t *data)
 *   Std_ReturnType Rte_Write_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(const StackUsage_MCU2_1_t *data)
 *   Std_ReturnType Rte_Write_PpSvsToTHA_SvsToTHA_t(const SvsToTHA_t *data)
 *   Std_ReturnType Rte_Write_PpSvsToVCAN_SvsToVCAN_t(const SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Write_PpTRSC_ME_VehOut_TRSC_t(const ME_VehOut_TRSC_t *data)
 *   Std_ReturnType Rte_Write_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(const TRSCSMVCtoDebugCAN_t *data)
 *   Std_ReturnType Rte_Write_PpTbAPDebugOut_TbAP_DebugOut(const TbAP_DebugOut *data)
 *   Std_ReturnType Rte_Write_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(const TbAP_SMPAInternalOut_t *data)
 *   Std_ReturnType Rte_Write_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(const TbFA_ArbiterOutput_t *data)
 *   Std_ReturnType Rte_Write_PpTbFAResetKM_TbFA_ResetKM_t(const TbFA_ResetKM_t *data)
 *   Std_ReturnType Rte_Write_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(const TbTHASmVc_DiagMgr_t *data)
 *   Std_ReturnType Rte_Write_PpTrailerDetectOP_TrailerDetection_Output_DID_t(const TrailerDetection_Output_DID_t *data)
 *   Std_ReturnType Rte_Write_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(const TRSCSMVCtoSVS_t *data)
 *   Std_ReturnType Rte_Write_PpTrscToDiag_TRSCtoDiagMgr_t(const TRSCtoDiagMgr_t *data)
 *   Std_ReturnType Rte_Write_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(const TRSC_Inputs_from_TrailerDetection_t *data)
 *   Std_ReturnType Rte_Write_PpUSSBlockageBit_US_S_BlockageBit_t(const US_S_BlockageBit_t *data)
 *   Std_ReturnType Rte_Write_PpUSSConstantData_US_S_USSConstantData_t(const US_S_USSConstantData_t *data)
 *   Std_ReturnType Rte_Write_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(const US_S_USSErrorDiagData_t *data)
 *   Std_ReturnType Rte_Write_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(const US_S_USSPeriodDiagData_t *data)
 *   Std_ReturnType Rte_Write_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(const US_S_CsmStateChangeReason_Type *data)
 *   Std_ReturnType Rte_Write_PpUssDataCollection_US_S_USSDataCollectionData_t(const US_S_USSDataCollectionData_t *data)
 *   Std_ReturnType Rte_Write_PpUssDebugMsg_US_S_DebugMsg_t(const US_S_DebugMsg_t *data)
 *   Std_ReturnType Rte_Write_PpUssMrrgData_US_S_MarriageSensorIDs_t(const US_S_MarriageSensorIDs_t *data)
 *   Std_ReturnType Rte_Write_PpUssPointMapGrp_US_S_PointMapGroup_t(const US_S_PointMapGroup_t *data)
 *   Std_ReturnType Rte_Write_PpUssTunData_UssTunningData_mcu2_1_t(const UssTunningData_mcu2_1_t *data)
 *   Std_ReturnType Rte_Write_PpUssZoneInfo_US_S_ZoneInfo_t(const US_S_ZoneInfo_t *data)
 *   Std_ReturnType Rte_Write_PpVCActuatorOut_TbAP_VCActuatorOut_t(const TbAP_VCActuatorOut_t *data)
 *   Std_ReturnType Rte_Write_PpVCState_TbAP_VCStateOut_t(const TbAP_VCStateOut_t *data)
 *   Std_ReturnType Rte_Write_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(const WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Write_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(const WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Write_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(const WdgCheckpointStatus_t *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FeatureAP_HMI_NvMData_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CddIpcHandler_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_IPCHandler_CODE) CddIpcHandler_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CddIpcHandler_Main
 *********************************************************************************************************************/
  /* DD-ID: {51144F8D-31D7-4188-8962-3AA37A5CB4E9}*/

IPC_F_IpcManager_v();
//Run IPC Manager

#if defined DEBUG_IPC
IPC_f_SenderFxn_v();
#endif

/*Send Autopark and HMI NVM data*/
f_SendNvmDataToCore_v();

f_FPA_NVMHandle_v();

if(S_RemoteCoreStatus_u8 == ALL_CORE_STATE) /*Return function till NVM data sent to all core*/
{
  S_SendNvmDataFlag = TRUE;
}
else
{
    /*Do Nothing*/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IpcTxData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IPC_Write_v> of PortPrototype <PpIpcTxData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IpcTxData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_IPCHandler_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IpcTxData
 *********************************************************************************************************************/
  /* DD-ID: {1A744298-65B9-4004-8F50-5789113DA22C}*/
     IPCMessage_Params_t ipcParams_s;
     ipcParams_s.IpcMsgID_u16 = i_IpcMsgId_u16;
     ipcParams_s.IpcMsgSize_u16 = i_IpcMsgSize_u16;
     ipcParams_s.IpcMsgData_v = (uint8_t*)b_TxData_pv;
     uint32_t v_errorRet_u32 = D_IPC_NO_ERROR;
	
     v_errorRet_u32 =  IPC_F_WrapperSend_u32(&ipcParams_s);

	   if(v_errorRet_u32 != D_IPC_NO_ERROR)
	   {

	   }
     else
     {

     }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}





/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static void f_SendNvmDataToCore_v(void)
{
  /* DD-ID: {13AEEE66-8A4F-432a-8E8C-2FBC5AEBFEED}*/
  SSM_2_0_CoreStatus SSM_2_0_data;
  SSM_2_1_CoreStatus SSM_2_1_data;
  SVS_NVMData_t SVS_NVMData_Data;
  /* TbNVM_ReadParam TbNVM_ReadParam_Data;  This variable  declared as global,As feature team requested for third parameter-DTC status update from SafeVCAN */
  TbAP_DriveAssistStatOut_t TbAP_DriveAssistStatOut_Data;
  TbAP_PAStateOut_t TbAP_PAStateOut_Data;
  CmdIgnSts v_IGN_status_u8; 
  static uint8 S_ApSvsNvmData_u8;
  
  if (TRUE == S_SendNvmDataFlag)
  {
      (void)Rte_Read_RpSVSNVMData_SVS_NVMData_t(&SVS_NVMData_Data);
      (void)Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(&TbAP_DriveAssistStatOut_Data);
      (void)Rte_Read_RpPAStateOut_TbAP_PAStateOut_t(&TbAP_PAStateOut_Data);
      (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&v_IGN_status_u8);
      S_ApSvsNvmData_u8 = (uint8)TbAP_DriveAssistStatOut_Data.IeAP_e_ScanDir;
      S_ApSvsNvmData_u8 |= LEFTSHIFT_BIT(TbAP_PAStateOut_Data.IeAP_b_PAMRearCtrlSts, BIT_SHIFT_TWO_BIT);
      S_ApSvsNvmData_u8 |= LEFTSHIFT_BIT(SVS_NVMData_Data.IeSVS_b_isDynGridPrstFromNVM, BIT_SHIFT_FOUR_BIT);
      S_ApSvsNvmData_u8 |= LEFTSHIFT_BIT(SVS_NVMData_Data.IeSVS_b_isFwdCamGridPrstFromNVM, BIT_SHIFT_FIVE_BIT);
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if ((S_ApSvsNvmData_u8 != *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock()) && (Cx4_RUN == v_IGN_status_u8))
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
        *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock() = S_ApSvsNvmData_u8;
        Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy = *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock();
        (void)Rte_Call_NvMService_AC3_SRBS_FeatureAP_HMI_NvMData_SetRamBlockStatus(TRUE);
      }
      else
      {
        /* Do nothing */
      }
  }
  else
  {
      /*Read MCU 2_0 status*/
      (void)Rte_Read_RpSR_State_MCU2_State_2_0(&SSM_2_0_data);
      if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_0_data.CoreStatus) && ((S_RemoteCoreStatus_u8 & MCU2_0_STATE) == FALSE))
      {
            S_ApSvsNvmData_u8 = *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock();
            SVS_NVMData_Data.IeSVS_b_isDynGridPrstFromNVM =((uint8)CHECK_BIT(S_ApSvsNvmData_u8, BIT_MASK_FIFTH_BIT)!= (uint8)e_ZERO)?TRUE:FALSE;
            SVS_NVMData_Data.IeSVS_b_isFwdCamGridPrstFromNVM =((uint8)CHECK_BIT(S_ApSvsNvmData_u8,BIT_MASK_SIXTH_BIT) !=(uint8)e_ZERO)?TRUE:FALSE;
            (void)RE_IpcTxData((dtRef_VOID)&SVS_NVMData_Data, (uint16)e_IpcMsgId_Data_SVS_NVMData_t, (uint16)sizeof(SVS_NVMData_t));
            S_RemoteCoreStatus_u8 |= MCU2_0_STATE; /*Update core Status Flag once data is transmited*/
      }
      else
      {
        /* Do nothing */
      }

      /*Read MCU 2_1 status*/
      (void)Rte_Read_RpSR_State_MCU2_State_2_1(&SSM_2_1_data);
      if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_1_data.CoreStatus) && ((S_RemoteCoreStatus_u8 & MCU2_1_STATE) == FALSE))
      {
            S_ApSvsNvmData_u8 = *Rte_Pim_FeatureAP_HMI_NvMData_MirrorBlock();
            TbNVM_ReadParam_Data.IeNVM_e_FrntRearParkSts = (uint32)CHECK_BIT((uint32)S_ApSvsNvmData_u8,(uint32)BIT_MASK_TWO_BIT);
            TbNVM_ReadParam_Data.IeNVM_b_PAMRearCtrlSts = CHECK_BIT(S_ApSvsNvmData_u8,BIT_SHIFT_FOUR_BIT)?TRUE:FALSE;
            (void)RE_IpcTxData((dtRef_VOID)&TbNVM_ReadParam_Data, (uint16)e_IpcMsgId_Data_TbNVM_ReadParam, (uint16)sizeof(TbNVM_ReadParam));
            S_RemoteCoreStatus_u8 |= MCU2_1_STATE; /*Update core Status Flag once data is transmited*/
            (void)Rte_Write_PpPAM2BTIpcTxStatus_IpcTxDone((boolean)TRUE);
            #ifdef Enable_Printf
            appLogPrintf("\n MCU1_0 Autosar Sent Park Status IeNVM_e_FrntRearParkSts ##=%d and IeNVM_b_PAMRearCtrlSts ##=%d to Autopark Module",TbNVM_ReadParam_Data.IeNVM_e_FrntRearParkSts,TbNVM_ReadParam_Data.IeNVM_b_PAMRearCtrlSts);
            #endif
            (void)RE_IpcTxData((dtRef_VOID)&Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy, (uint16)e_IpcMsgId_Data_INVMSignalManager_t, (uint16)sizeof(INVMSignalManager_t));
      }
      else
      {
        /* Do nothing */
      }
  }
}

void f_FPA_NVMHandle_v(void)
{
  /* DD-ID: {3905EB30-E890-4fb3-A81C-6D509B838C61}*/
  sint8 v_RetVal_s8;
  IJobFPAOutput_t v_FPA_OutData;
  static INVMSignalManager_t S_FPA_NVM_Data;
  NvM_RequestResultType v_BlockErrorStatus;
  (void)Rte_Read_RpJobFPAData_IJobFPAOutput_t(&v_FPA_OutData);

  v_RetVal_s8 = VStdLib_MemCmpLarge(&v_FPA_OutData.m_FPAToNVM, &S_FPA_NVM_Data, sizeof(INVMSignalManager_t));
  if ((sint8)D_ZERO_VAL != v_RetVal_s8)
  {
    VStdLib_MemCpy(&S_FPA_NVM_Data, &v_FPA_OutData.m_FPAToNVM, sizeof(INVMSignalManager_t));
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (TRUE == S_FPA_NVM_Data.m_WriteNVMParam_b)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
          Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock = S_FPA_NVM_Data;
          Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy = Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock;
          (void)Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_GetErrorStatus(&v_BlockErrorStatus);
          if(NVM_REQ_PENDING != v_BlockErrorStatus)
          {
        	  (void)Rte_Call_NvMService_AC3_SRBS_FPA_Slot_Data_WriteBlock(&Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy);
          }
            #ifdef Enable_Printf
            appLogPrintf("\n MCU1_0 Autosar WriteBlock Park Assist#####");
            #endif          
    }
    else
    {
          /*Do Nothing*/
    }
  }
  else
  {
      /*Do Nothing*/
  }
}

void Update_CDD_IPCHandler_MirrorBlock(boolean CDD_IPCHandler_Erase_block)
{
  /* DD-ID: {69E8E60A-06F9-4225-886D-0BC01032167F}*/
  if(TRUE == CDD_IPCHandler_Erase_block)
  {
    Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock = Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy;
    Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock = Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy;
  }
  else
  {
    Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock_copy = Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock;
    Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock_copy = Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock;
  }
}

FUNC(void, CDD_IPCHandler_CODE) RE_CddIpcHandler_Init(void)
{
  /* DD-ID: {47862008-D463-46ad-81F3-2DBF5BC0AC42}*/
  /* DD-ID:{6B5E99AA-94EA-4dfe-946F-AC38F7D53D88}*/
	(void)Os_Call_CddIpcHandler_Init();
}

FUNC(void, CDD_IPCHandler_CODE) RE_CddIpcHandler_Main(void)
{
  /* DD-ID: {51144F8D-31D7-4188-8962-3AA37A5CB4E9}*/
  /* DD-ID:{A7599B9F-3600-4955-B3BC-04CD22960C6D}*/
	 (void)Os_Call_CddIpcHandler_Main();
}

#if defined DEBUG_IPC
void IPC_f_SenderFxn_v()
{
  /* DD-ID: {6703774A-2D82-46c6-987F-E613DF283009}*/
	   IPCMessage_Params_t ipcParams_s, ipcParams_s_2;
     ipcParams_s.IpcMsgID_u16 = 0x0001U;
     ipcParams_s.IpcMsgSize_u16 = sizeof(IPC_test_small_data_t);
	   uint8_t v_tx_msgData_u8[32] = {0xAAU, 0xBBU, 0xCCU, 0xDDU};
     ipcParams_s.IpcMsgData_v = &v_tx_msgData_u8[0];
     uint32_t status_e = D_IPC_NO_ERROR;
	
     status_e =  IPC_F_WrapperSend_u32(&ipcParams_s);

	   if(D_IPC_NO_ERROR != status_e)
	   {

	   }
     else
     {

     }


     ipcParams_s_2.IpcMsgID_u16 = 0x0002U;
     ipcParams_s_2.IpcMsgSize_u16 = sizeof(IPC_test_large_data_t);
     ipcParams_s_2.IpcMsgData_v = &v_tx_msgData_u8[0];
	
     status_e =  IPC_F_WrapperSend_u32(&ipcParams_s_2);

	   if(D_IPC_NO_ERROR != status_e)
	   {

	   }
     else
     {

     }

}
#endif

#define CDD_IPCHandler_STOP_SEC_CODE
#include "CDD_IPCHandler_MemMap.h"

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
