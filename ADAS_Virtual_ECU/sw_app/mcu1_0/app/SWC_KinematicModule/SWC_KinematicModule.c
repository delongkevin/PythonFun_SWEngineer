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
 *             File:  SWC_KinematicModule.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_KinematicModule
 *  Generation Time:  2024-12-03 16:36:46
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_KinematicModule>
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
 * CameraDisplaySts2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CmdIgnSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * FD14_ACC_Systemsts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_BSM_THA_Brk_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_BrkPdl_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Brk_Stat
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
 * FD14_ECM_THA_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ECM_TRSC_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_EPBSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_EPS_HandsOnRecognition
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_EPS_SteeringTouchStat
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_EPS_SteeringTouq_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_EPS_THA_DriverTorqueOverride
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_EPS_THA_SteeringTorqueResp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ESC_TRSC_Brk_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ESS_ENG_ST_W
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_EngineSts_W
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ExternalBrkRequestsDisabled
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_HAS_Status
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHF_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHF_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHF_WheelSensorFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_LHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHR_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LHR_WheelSensorFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_LatAccelerationFailSts_BSM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_LatAccelerationOffset_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_LongAccelerationFailSts_BSM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * FD14_LwsAngleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PAM_Brk_Rq_RspSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_MaxSpeed
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ParkingGearShiftReq_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_ParkingInterventionSts
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
 * FD14_RHF_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_RHF_WheelSensorFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_RHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_RHR_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_RHR_WheelSensorFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_SPM_Lat_Ctrl_ResponseSts
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
 * FD14_THA_SteeringTouchStat
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
 * FD14_VehicleStandStillSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_YawRateFailSts_BSM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * MRM_STATUS_C2
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
 * TeAP_e_ParkAssistStatus
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
 * TrailerConnectionSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TransmissionSailingSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * VIN_MSG
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Runnable Entities:
 * ==================
 * RE_KinematicModule_Init
 *   Periodic Runnable of Satellite
 *
 * RE_KinematicModule_Main
 *   Init Runnable
 *
 *********************************************************************************************************************/

#include "Rte_SWC_KinematicModule.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "JobKM.h"
#include "vstdlib.h"
#include "Enums.h"
#include "ipc_manager.h"
#include "ti/osal/TimerP.h"

#define D_FACTOR 0.0174532924F
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
 * ASCM_Stat: Integer in interval [0...15]
 * ASCM_SysFail: Integer in interval [0...1]
 * Active_Park_Mode: Integer in interval [0...1]
 * Active_Park_Prox_Chime: Integer in interval [0...1]
 * Backup_Cam_Delay: Integer in interval [0...1]
 * Brk_Stat: Integer in interval [0...3]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CameraDisplaySts2: Integer in interval [0...15]
 * CmdIgnSts: Integer in interval [0...7]
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
 * FD14_ACC_Systemsts: Integer in interval [0...15]
 * FD14_BSM_THA_Brk_Resp: Integer in interval [0...3]
 * FD14_BrkPdl_Stat: Integer in interval [0...3]
 * FD14_Brk_Stat: Integer in interval [0...3]
 * FD14_Cntr_CVPAM_FD_Data: Integer in interval [0...65535]
 * FD14_Cntr_CVPAM_FD_Data2: Integer in interval [0...65535]
 * FD14_ECM_THA_Resp: Integer in interval [0...3]
 * FD14_ECM_TRSC_Resp: Integer in interval [0...3]
 * FD14_EPBSts: Integer in interval [0...15]
 * FD14_EPS_HandsOnRecognition: Integer in interval [0...1]
 * FD14_EPS_SteeringTouchStat: Integer in interval [0...1]
 * FD14_EPS_SteeringTouq_Resp: Integer in interval [0...3]
 * FD14_EPS_THA_DriverTorqueOverride: Integer in interval [0...3]
 * FD14_EPS_THA_SteeringTorqueResp: Integer in interval [0...7]
 * FD14_ESC_TRSC_Brk_Resp: Integer in interval [0...3]
 * FD14_ESS_ENG_ST_W: Integer in interval [0...15]
 * FD14_EngineSts_W: Integer in interval [0...3]
 * FD14_ExternalBrkRequestsDisabled: Integer in interval [0...3]
 * FD14_HAS_Status: Integer in interval [0...3]
 * FD14_LHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHF_Spin: Integer in interval [0...3]
 * FD14_LHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHR_Spin: Integer in interval [0...3]
 * FD14_LHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LatAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LatAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LongAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LongAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LwsAngle: Integer in interval [0...65535]
 * FD14_LwsAngleType: Integer in interval [0...3]
 * FD14_PAM_Brk_Rq_RspSts: Integer in interval [0...3]
 * FD14_PPPA_MaxSpeed: Integer in interval [0...255]
 * FD14_ParkingGearShiftReq_BSM: Integer in interval [0...7]
 * FD14_ParkingInterventionSts: Integer in interval [0...3]
 * FD14_PdlPosActual: Integer in interval [0...255]
 * FD14_RHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHF_Spin: Integer in interval [0...3]
 * FD14_RHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_RHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHR_Spin: Integer in interval [0...3]
 * FD14_RHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_SPM_Lat_Ctrl_ResponseSts: Integer in interval [0...3]
 * FD14_Slope: Integer in interval [0...255]
 * FD14_THA_SteeringDamping: Integer in interval [0...255]
 * FD14_THA_SteeringTouchStat: Integer in interval [0...3]
 * FD14_TRSC_SteeringDamping: Integer in interval [0...255]
 * FD14_VehicleStandStillSts: Integer in interval [0...3]
 * FD14_YawRateFailSts_BSM: Integer in interval [0...1]
 * FL_Lvl_Adj: Integer in interval [0...1]
 * FR_Lvl_Adj: Integer in interval [0...1]
 * FT_PAMRequestSts: Integer in interval [0...1]
 * Fwrd_Cam_Guidelines: Integer in interval [0...1]
 * GearEngaged: Integer in interval [0...15]
 * GearEngagedForDisplay: Integer in interval [0...31]
 * HAS_Status_C2: Integer in interval [0...3]
 * HU_TRSC_EnableBtn_Sts: Integer in interval [0...2]
 * ITBM_TrlrStat: Integer in interval [0...3]
 * LHRDoorSts: Integer in interval [0...1]
 * LanguageSelection: Integer in interval [0...255]
 * LwsAngleType: Integer in interval [0...3]
 * MRM_STATUS_C2: Integer in interval [0...7]
 * PAMRequestSts: Integer in interval [0...1]
 * PamChimeVolumeFront: Integer in interval [0...3]
 * PamChimeVolumeRear: Integer in interval [0...3]
 * PsngrDoorSts: Integer in interval [0...1]
 * RHRDoorSts: Integer in interval [0...1]
 * RHatchSts: Integer in interval [0...1]
 * RL_Lvl_Adj: Integer in interval [0...1]
 * RR_Lvl_Adj: Integer in interval [0...1]
 * Rear_Brk_Asst: Integer in interval [0...1]
 * SVC_Guidelines: Integer in interval [0...1]
 * ShiftLeverPosition: Integer in interval [0...15]
 * ShiftLeverPositionReq: Integer in interval [0...15]
 * Shifter_ADAS_Inhibit: Integer in interval [0...1]
 * TCASERANGESTATUS: Integer in interval [0...3]
 * TGW_CAMERA_DISP_STAT: Integer in interval [0...15]
 * THA_SteeringTouchStat: Integer in interval [0...3]
 * TRANS_ADAS_Inhibit: Integer in interval [0...1]
 * TargetGear: Integer in interval [0...15]
 * TeAP_e_ParkAssistStatus: Integer in interval [0...4294967295]
 * TeAutoPark_e_GearCmd: Integer in interval [0...4294967295]
 * TrailerConnectionSts: Integer in interval [0...3]
 * TransmissionSailingSts: Integer in interval [0...15]
 * VIN_MSG: Integer in interval [0...3]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * Array_04Byte: Array with 4 element(s) of type uint8
 * Array_10Byte: Array with 10 element(s) of type uint8
 * Array_11Byte: Array with 11 element(s) of type uint8
 * K_Overlap_Thrsld_RAEB_Array: Array with 5 element(s) of type float32
 * Obj_DistTable_Array: Array with 5 element(s) of type float32
 * VIN_DATA: Array with 7 element(s) of type uint8
 * keVehParam_e_StrWhlRatioBrkPnts_Array: Array with 19 element(s) of type float32
 * keVehParam_e_VehSteerRatioTable_Array: Array with 19 element(s) of type float32
 *
 * Record Types:
 * =============
 * IFOD_Outputs_Arbitration_t: Record with elements
 *   IeFOD_e_FODStatus of type uint8
 *   MeFOD_e_USSFiringMode of type uint8
 *   IeFOD_b_ResetKM of type boolean
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
 * TbAP_VrntTunParam_t: Record with elements
 *   KeAP_degC_OperatingTempThd of type float32
 *   KeAP_kph_EnblHysThd of type float32
 *   KeAP_kph_FrntWarnMaxSpdThd of type float32
 *   KeAP_kph_ParkMnvThd of type float32
 *   KeAP_kph_PSDOffThd of type float32
 *   KeAP_kph_PSDOnThd of type float32
 *   KeAP_kph_RearWarnMaxSpdThd of type float32
 *   KeAP_kph_USSActiveSpdThd of type float32
 *   K_e_RAEB_VehicleWidth of type float32
 *   K_Overlap_Thrsld_RAEB of type K_Overlap_Thrsld_RAEB_Array
 *   KeTOS_s_InTurnDbncTm of type float32
 *   KeTOS_s_StrDrvDbncTm of type float32
 *   KeTOS_s_TurnExitDbncTm of type float32
 *   KeTOS_x_InTurnThd of type float32
 *   KeTOS_x_TurnExitThd of type float32
 *   keVehParam_m_DistWhlBse of type float32
 *   Obj_DistTable of type Obj_DistTable_Array
 *   Overlap_Thrsld_Switch of type float32
 *   RAEB_Envelope_Offset of type float32
 *   RAEB_Lateral_Distance_Notification of type float32
 *   RAEB_Minimum_Object_Heigh of type float32
 *   sampling_time of type float32
 *   keVehParam_e_VehSteerRatioTable of type keVehParam_e_VehSteerRatioTable_Array
 *   keVehParam_e_StrWhlRatioBrkPnts of type keVehParam_e_StrWhlRatioBrkPnts_Array
 *   keInpAdptr_e_StWhOffset of type float32
 *   Straight_Driving_Thresold_rads2 of type float32
 *   Steering_Angle_DeadZone_Start of type float32
 *   Steering_Angle_DeadZone_End of type float32
 *   KeAP_k_PathSepaMinSpd of type float32
 *   KeAP_k_PathSepaSpdRampGrd of type float32
 *   KeAP_k_DetWP_PreviewTime of type float32
 *   KeAP_k_LatPathDevPGain of type float32
 *   KeAP_k_LatPathDevIGain of type float32
 *   KeAP_k_LatPathDevDGain of type float32
 *   KeAP_k_LatHeadDevPGain of type float32
 *   KeAP_k_LatHeadDevIGain of type float32
 *   KeAP_k_LatHeadDevDGain of type float32
 *   KeAP_k_SteerUpperLimit of type float32
 *   KeAP_k_SteerLowerLimit of type float32
 *   KeAP_k_CtrlOutCollDetActivate of type float32
 *   KeAP_k_CtrlOutRemainDistNA of type float32
 *   KeAP_k_CtrlOutCollDetCollDistLimit of type float32
 *   KeAP_k_CtrlOutCollDetRedStopVal of type float32
 *   KeAP_k_CtrlOutVehSpdMaxSpotStrTime of type float32
 *   KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd of type float32
 *   KeAP_k_CtrlOutVehSpdMaxSpotSteer of type float32
 *   KeAP_k_BrakePGain of type float32
 *   KeAP_k_BrakeIGain of type float32
 *   KeAP_k_BrakeUpperLimit of type float32
 *   KeAP_k_BrakeLowerLimit of type float32
 *   KeAP_k_CtrlOutGearDrive of type float32
 *   KeAP_k_CtrlOutGearReverse of type float32
 *   KeAP_k_CtrlOutGearPark of type float32
 *   KeAP_k_WhlCircum of type float32
 *   KeAP_cnt_ChimeVolChgAlert of type uint16
 *   KeAP_cnt_FrntChimeDisTimeThd of type uint16
 *   KeAP_cnt_HalfSecChimeAlert of type uint16
 *   KeAP_cnt_LEDBlinkTimeThd of type uint16
 *   KeAP_cnt_VehKeyOnTimeThd of type uint16
 *   KeAP_Cnt_GearFiltTimeThd of type uint16
 *   KeAP_cnt_TimeStep of type uint16
 *   KeAP_cm_ObjPrestFCDistThd of type uint16
 *   KeAP_cm_ObjPrestRCDistThd of type uint16
 *   KeAP_cm_VehicleWidth of type uint16
 *   KeAP_Cnt_GearOverrideTimeThd of type uint16
 *   KeAP_cnt_SwtStuckTimeThd of type uint16
 *   KeAP_s_BSMInterfaceCntTimeout of type uint16
 *   KeAP_s_CamHandshakeDur of type uint16
 *   KeAP_s_EPSInterfaceCntTimeout of type uint16
 *   KeAP_s_GearShiftWaitCntTimeout of type uint16
 *   KeAP_s_MaxStandstillTimeThd of type uint16
 *   KeAP_s_ObjInPathTimeoutDur of type uint16
 *   KeAP_s_PausedPressBtnTimeoutDur of type uint16
 *   KeAP_s_SeekPhaseTimeoutDur of type uint16
 *   KeAP_s_SpdExceedDur of type uint16
 *   KeAP_cnt_SPMBlinkLEDDur of type uint16
 *   KeAP_cm_VehContour_FSL_x of type sint16
 *   KeAP_cm_VehContour_FOL_x of type sint16
 *   KeAP_cm_VehContour_FIL_x of type sint16
 *   KeAP_cm_VehContour_FIR_x of type sint16
 *   KeAP_cm_VehContour_FOR_x of type sint16
 *   KeAP_cm_VehContour_FSR_x of type sint16
 *   KeAP_cm_VehContour_FSL_y of type sint16
 *   KeAP_cm_VehContour_FOL_y of type sint16
 *   KeAP_cm_VehContour_FIL_y of type sint16
 *   KeAP_cm_VehContour_FIR_y of type sint16
 *   KeAP_cm_VehContour_FOR_y of type sint16
 *   KeAP_cm_VehContour_FSR_y of type sint16
 *   KeAP_cm_VehContour_RSR_x of type sint16
 *   KeAP_cm_VehContour_ROR_x of type sint16
 *   KeAP_cm_VehContour_RIR_x of type sint16
 *   KeAP_cm_VehContour_RIL_x of type sint16
 *   KeAP_cm_VehContour_ROL_x of type sint16
 *   KeAP_cm_VehContour_RSL_x of type sint16
 *   KeAP_cm_VehContour_RSR_y of type sint16
 *   KeAP_cm_VehContour_ROR_y of type sint16
 *   KeAP_cm_VehContour_RIR_y of type sint16
 *   KeAP_cm_VehContour_RIL_y of type sint16
 *   KeAP_cm_VehContour_ROL_y of type sint16
 *   KeAP_cm_VehContour_RSL_y of type sint16
 *   KeAP_cm_DistZone1 of type sint16
 *   KeAP_cm_DistZone2 of type sint16
 *   KeAP_cm_DistZone3 of type sint16
 *   KeAP_cm_DistZone4 of type sint16
 *   KeAP_cm_DistZone5 of type sint16
 *   KeAP_cm_DistZone6 of type sint16
 *   KeAP_cnt_DebounceTimeThd of type sint16
 *   KeAP_cm_FrntLongDistAdj of type sint16
 *   KeAP_cm_HalfVehicleWidth of type sint16
 *   KeAP_cm_HookDistOffset of type sint16
 *   KeAP_cm_MaxNoObjDetctDist of type sint16
 *   KeAP_cm_RearLongDistAdj of type sint16
 *   KeAP_cm_WarnOffset of type sint16
 *   KeAP_e_GbTypAT of type uint8
 *   KeAP_pct_ObjConfidenceThd of type uint8
 *   Reverse_Gr_num of type uint8
 *   KeAP_b_AutoParkEn of type uint8
 *   KeAP_b_FPAEn of type uint8
 *   KeAP_b_FullAutoPark of type uint8
 *   KeAP_b_HookConnected of type uint8
 *   KeAP_b_RPAwithBrk of type uint8
 *   KeAP_b_RPAwithSurroundView of type uint8
 *   KeAP_b_SteerOnlyAutoPark of type uint8
 *   KeCMbB_b_EnblOncObjDbnc of type uint8
 *   dummy of type uint8
 *   dummy1 of type uint8
 *   dummy2 of type uint8
 * TbFA_ResetKM_t: Record with elements
 *   MeFA_b_ResetKM of type boolean
 *
 *********************************************************************************************************************/


#define SWC_KinematicModule_START_SEC_CODE
#include "SWC_KinematicModule_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_KinematicModule_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_KinematicModule_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_KinematicModule_CODE) RE_KinematicModule_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_KinematicModule_Init
 *********************************************************************************************************************/
  /* DD-ID: {E08E547E-97BA-4513-A82C-F392AD6AE0C2}*/
  
  KM_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_KinematicModule_Main
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
 *   Std_ReturnType Rte_Read_RpAPVarTunParam_TbAP_VrntTunParam_t(TbAP_VrntTunParam_t *data)
 *   Std_ReturnType Rte_Read_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t(IFOD_Outputs_Arbitration_t *data)
 *   Std_ReturnType Rte_Read_RpProxiConfigData_ProxiData(ME_Hydra2defs_S_CodingTableExt_t *data)
 *   Std_ReturnType Rte_Read_RpSMDAInternal_TbAP_SMDAInternalOut_t(TbAP_SMDAInternalOut_t *data)
 *   Std_ReturnType Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t(TbFA_ResetKM_t *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(GearEngaged *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(FD14_LHR_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(FD14_LwsAngle *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(FD14_RHR_FastPulseCounter *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_KinematicModule_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_KinematicModule_CODE) RE_KinematicModule_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_KinematicModule_Main
 *********************************************************************************************************************/
/*GUID:-*/
  /* DD-ID: {CEFA8776-A991-4b47-94BC-593604208408}*/
  KM_onRun();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_KinematicModule_STOP_SEC_CODE
#include "SWC_KinematicModule_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void KM_GetData(KmFeatureComdata *data)
{
  /* DD-ID: {F024539F-1C47-4e76-A908-94A4FB8684AC}*/
  uint16 v_temp_var_u16 = 0U;
  static TbFA_ResetKM_t FAResetKMdata = {0};
  static ME_Hydra2defs_S_CodingTableExt_t FAProxyKMdata = {0};
  static TbAP_VrntTunParam_t FATunParamKMdata = {0};
  (void)Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(&data->GearEngagedData);
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(&v_temp_var_u16);
  data->LwsAngleData=(float32)v_temp_var_u16;
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(&v_temp_var_u16);
  data->LHR_FastPulseCounterData=(float32)v_temp_var_u16;
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(&v_temp_var_u16);
  data->RHR_FastPulseCounterData=(float32)v_temp_var_u16;
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(&v_temp_var_u16);
  data->RHRWheelSpeedData=(float32)v_temp_var_u16;
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(&v_temp_var_u16);
  data->LHRWheelSpeedData=(float32)v_temp_var_u16;
  (void)Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t(&FAResetKMdata);
  (void)Rte_Read_RpProxiConfigData_ProxiData(&FAProxyKMdata);
  (void)Rte_Read_RpAPVarTunParam_TbAP_VrntTunParam_t(&FATunParamKMdata);
  data->potMap_reset_KM = FAResetKMdata.MeFA_b_ResetKM;
  data->IePRX_e_VehWhlBase = FAProxyKMdata.Wheelbase;
  data->IePRX_mm_TyreSize = FAProxyKMdata.Tyresize_uint16;
  data->IePRX_e_StrRatRckPinionTyp = FAProxyKMdata.SteeringRatio_uint8;
}

void KM_SetData(ExtY_Kinematic_T* KinematicModel_Y)
{
  /* DD-ID: {561D5FE6-7313-43ed-8894-AAA83A6B8479}*/
  static float32_t KMTimer_Offset;
  IKinematicData_t km_output_sigm;
	ExtY_Kinematic_T km_out_old_format;

/*Send to IPC*/
	km_output_sigm.m_Global_dx = KinematicModel_Y->m_Global_x;
	km_output_sigm.m_Global_dy = KinematicModel_Y->m_Global_y;
	km_output_sigm.m_Global_dyaw_rad = KinematicModel_Y->m_Global_yaw_deg * D_FACTOR;
	km_output_sigm.dx_m = KinematicModel_Y->dx_mps;
	km_output_sigm.dy_m = KinematicModel_Y->dy_mps;
	km_output_sigm.dyaw_rad = KinematicModel_Y->dyaw_degps * D_FACTOR;
  TbFA_ResetKM_t FAResetKMdata = {0};
  

  (void)Rte_Read_RpTbFAResetKM_TbFA_ResetKM_t(&FAResetKMdata);
  if (FAResetKMdata.MeFA_b_ResetKM == (boolean)1)
  {
    km_output_sigm.timestamp_s = 0.0f;
    KMTimer_Offset = (float32_t)((float32)TimerP_getTimeInUsecs() / 1E6);
  }
  else
  {
    km_output_sigm.timestamp_s = (float32)(((float64)TimerP_getTimeInUsecs() / 1E6) -(float64) KMTimer_Offset);
  }

	VStdLib_MemCpy((void*)&km_out_old_format, (void*)&KinematicModel_Y, sizeof(km_out_old_format));

(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&km_output_sigm, (uint16)e_IpcMsgId_Data_IKinematicData_t, (uint16)sizeof(km_output_sigm));
(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&km_out_old_format, (uint16)e_IpcMsgId_Data_ExtY_Kinematic_T, (uint16)sizeof(km_out_old_format));
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
