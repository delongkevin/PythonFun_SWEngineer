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
 *             File:  SWC_RIDMgr.c
 *           Config:  D:/git/L2H4060_Software_master/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_RIDMgr
 *  Generation Time:  2025-08-20 17:38:08
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_RIDMgr>
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
 * BSM_THA_Brk_Resp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * CameraDisplaySts2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * CurrentCanNMState_FD01_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD01_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_BSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_CADM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_EPS
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_ORC
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD02_TRLR_REV
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD03_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD03_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD04_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD08_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentCanNMState_FD11_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CurrentFailSts_FD01_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD01_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_BSM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_CADM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_EPS
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_ORC
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD02_TRLR_REV
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD03_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD03_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD04_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD08_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CurrentFailSts_FD11_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * DES_FD01_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD01_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_BSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_CADM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_EPS
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_ORC
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD02_TRLR_REV
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD03_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD03_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD04_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD08_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DES_FD11_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
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
 * Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DeltaTimestamp_IMUdata
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * DeviceAddress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_01
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_02
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_03
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_04
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_05
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_06
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_07
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_08
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_09
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_10
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Digit_11
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
 * EOL_FD01_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD01_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_BSM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_CADM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_EPS
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_ORC
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD02_TRLR_REV
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD03_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD03_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD04_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD08_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EOL_FD11_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EPBSts
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
 * ErrorMgr_enErrorNo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorNo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD01_BCM_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD01_SGW_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_BCM_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_BSM2_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_CADM2_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_EPS_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_ORC_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_SGW_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD02_TRLR_REV_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD03_BCM_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD03_SGW_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD04_BCM_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD08_SGW_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD11_SGW_64
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
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
 * GenericFailSts_FD01_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD01_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_BSM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_CADM2
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_EPS
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_ORC
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD02_TRLR_REV
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD03_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD03_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD04_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD08_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * GenericFailSts_FD11_SGW
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * IgnitionOnCounter
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * LHF_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LHF_Spin
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
 * LHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LHR_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * OperationalModeSts
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
 * PreviousCanNMState_FD01_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD01_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_BSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_CADM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_EPS
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_ORC
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD02_TRLR_REV
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD03_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD03_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD04_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD08_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PreviousCanNMState_FD11_SGW
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
 * RHF_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RHF_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RHRDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RHR_FastPulseCounter
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RHR_Spin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * RemStActvSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SBR1RowDriverSeatSts
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
 * TRSC_CenterBtn_Sts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_EnableBtn_Sts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_RawKnob
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * TargetGear
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TeTRSC_e_CamBlockSts
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
 * TeTRSC_e_TrlrPrsntInfo_DID
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
 * TotalOdometer
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
 * TurnIndicatorSts
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
 * VehicleStandStillSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * VoltMgr_Enum_VoltageMON
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD01_ADCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD01_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD01_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_BSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_CADM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_EPS
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_ORC
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD02_TRLR_REV
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD03_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD03_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD04_BCM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD08_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WakeupSource_FD11_SGW
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 *
 * Runnable Entities:
 * ==================
 * RE_RIDMgrr_Init
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_SWC_RIDMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <string.h>
#include "vstdlib.h"
#include "Enums.h"
#include "ipc_manager.h"
#include "InterfaceSignalForTestPatternRoutine.h"
#include "APDiagDataTypes.h"
#include "CalibIpcDataTypes.h"
#include "APDiagDataTypes.h"
#include "ErrorManagerAggregatorDef.h"
#include "Os_Lcfg.h"
#include "Xcp.h"


/* Define for response routine information */
#define D_RID_MAX_WAITCOUNT        (20U)
#define D_VEHICLE_SPEED_THRESHOLD             0.00f
#define D_HIGH_VOL_THRESHOLD                  16.00f
#define D_LOW_VOL_THRESHOLD                   9.00f
#define D_HIGH_TEMP_THRESHOLD                 85.00f
#define D_LOW_TEMP_THRESHOLD                  -40.00f
#define D_VEHICLE_SPEED_FAULT_CODE            0x05
#define D_HIGH_BAT_FAULT_CODE                 0x0D
#define D_LOW_BAT_FAULT_CODE                  0x0A
#define D_HIGH_TEMP_FAULT_CODE                0x0B
#define D_LOW_TEMP_FAULT_CODE                 0x0C
#define D_GEAR_CON_FAULT_CODE                 0xC2
#define D_ALL_CON_PASSED_DATA_LEN             0x01
#define D_DTC_TF_STATUS_MASK                  0x01u
#define ALL_CAMERA                            0xFFu
#define D_VIN_MSG_SIZE                        17u
#define D_VIN_MSG_LEN                         7u
#define D_VIN_MSG_LEN_HIGH                    3u
#define D_VIN_MILEAGE_LOCK                    5u /*5Km*/
#define D_FINAL_SEQUENCE_COUNTER              2u
#define D_ASCIIA                              0X41U
#define D_ASCIIZ                              0x5AU
#define D_ASCII_0                              0x30U
#define D_ASCII_9                              0x39U
#define R_1000_MODE_MAX                        9u
#define SINGLE_CAM_VARIANT      0u
#define D_INDEX_0 0
#define D_INDEX_1 1
#define D_STOP_TESTPATTERN 0 
#define D_ROUTINE_START 1
#define D_ROUTINE_STOP 0
#define D_EOL_OK 0x00u
#define D_NO_ERROR 0x05u

#define D_ASCM_Stat_NVL 0x4u
#define D_ASCM_PRESENT 0x1u
#define D_LWSANGLE_OFFSET     720u
#define D_LWSANGLE_FACTOR      0.1f
#define D_VOL_LOW_RANGE           9.0f
#define D_VOL_HIGH_RANGE          16.0f
#define D_LWSANGLE_HIGH_THR 10.0F
#define D_LWSANGLE_LOW_THR  (-10.0F)
#define MCU2_1_STATE 0x02u

#define ENFORCED_CALIBRATION 1u
#define REAR_CAMERA_CALIBRATION 5u

typedef enum 
{
  NO_ERROR = 0X00u,
  IN_PROCESS = 0x01,
  TARGET_NOT_FOUND_INIT =0x02,
  TARGET_NOT_FOUND_LEFT =0x03,
  NOT_CALIBRATED = 0x04,
  TARGET_NOT_FOUND_RIGHT = 0x05,
  TARGET_IDENT_ERROR_LEFT=0x06,
  TARGET_IDENT_ERROR_RIGHT=0x07,
  EXCEED_QUALITY_LIMIT=0x08,
  ABORTED = 0x09,
  PRECONDITION_NOT_CORRECT = 0x0A
}SystemCalibStatus_t;
typedef enum 
{
  CAM_TARGET_NOT_FOUND =0x00,
  CAM_NOT_CALIBRATED = 0x01,
  CAM_ABORTED = 0x02,
  CAM_NO_ERROR = 0x03,
  CAM_TARGET_IDENT_ERROR = 0x04,
  CAM_EOL_EXCEED_QUALITY_LIMIT=0x05,
}CameraCalibStatus_t;
typedef enum 
{
  ROUTINE_COMPLETED = 0x00u,
  ROUTINE_ABORTED = 0x01u,
  ROUTINE_ACTIVE = 0x02
}RoutineStatus_t;

typedef enum 
{
  ABNORMALLY_FINISHED =1u,
  ACTIVE,
  FORCED,
  IDLE
}RIDM_RoutineStatus_t;

enum VINLock_e
{
  VIN_NOT_LOCKED=(uint8)FALSE,
  LOCK_BY_EXTERNAL_TOOL,
  LOCK_BY_ODOMETER_VALUE,
};
enum VINState_e
{
  CURR_VIN_LEARN = (uint8)e_ZERO,
  CURR_VIN_UPDATE,
  CHCK_VIN_LOCKSTATE,
  WAIT_FOR_VINLOCK,
  VIN_STATE_LASTINDEX
};

static boolean s_Failsafe_ProhibitFlag_D001_b = FALSE;


static RIDM_RoutineStatus_t RIDM_RoutineStatus_5400_e = IDLE;
static RIDM_RoutineStatus_t RIDM_RoutineStatus_5401_e = IDLE;
static RIDM_RoutineStatus_t RIDM_RoutineStatus_5502_e = IDLE;
static RIDM_RoutineStatus_t RIDM_RoutineStatus_FE0E_e = IDLE;
static RoutineStatus_t RESULT_5400_e = ROUTINE_COMPLETED;
static RoutineStatus_t RESULT_5401_e = ROUTINE_COMPLETED;


static boolean v_SC_calibRoutine_activeFlag = (boolean)FALSE;
static boolean v_EOL_calibRoutine_activeFlag = (boolean)FALSE;

static uint8 v_EOL_calibRoutine_RearStarted =  (uint8)e_ZERO;
static uint8 v_SC_calibRoutine_RearStarted =  (uint8)e_ZERO;

DiagToParkAssist_t DiagToParkAssist_data; /*This varible extern in SWC_DTCMgr.c, hence don't do it static*/
static FUNC(void, SWC_RIDMgr_CODE) F_ProgrammingPreconditionCheck(void);
static FUNC(void, SWC_RIDMgr_CODE) F_ConfigMgr_VINProcess(void);
static FUNC(Std_ReturnType, SWC_RIDMgr_CODE) F_EOL_CalibrationPreconditionCheck(void);
static FUNC(Std_ReturnType, SWC_RIDMgr_CODE) F_SC_CalibrationPreconditionCheck(void);
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
 * BSM_THA_Brk_Resp: Integer in interval [0...3]
 * Backup_Cam_Delay: Integer in interval [0...1]
 * Brk_Stat: Integer in interval [0...3]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CalibrationState_DID_t: Integer in interval [0...4294967295]
 * CameraDisplaySts2: Integer in interval [0...15]
 * CanDebugMode_t: Integer in interval [0...4294967295]
 * CmdIgnSts: Integer in interval [0...7]
 * CurrentCanNMState_FD01_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD01_SGW: Integer in interval [0...15]
 * CurrentCanNMState_FD02_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD02_BSM2: Integer in interval [0...15]
 * CurrentCanNMState_FD02_CADM2: Integer in interval [0...15]
 * CurrentCanNMState_FD02_EPS: Integer in interval [0...15]
 * CurrentCanNMState_FD02_ORC: Integer in interval [0...15]
 * CurrentCanNMState_FD02_SGW: Integer in interval [0...15]
 * CurrentCanNMState_FD02_TRLR_REV: Integer in interval [0...15]
 * CurrentCanNMState_FD03_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD03_SGW: Integer in interval [0...15]
 * CurrentCanNMState_FD04_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD08_SGW: Integer in interval [0...15]
 * CurrentCanNMState_FD11_SGW: Integer in interval [0...15]
 * CurrentFailSts_FD01_BCM: Integer in interval [0...1]
 * CurrentFailSts_FD01_SGW: Integer in interval [0...1]
 * CurrentFailSts_FD02_BCM: Integer in interval [0...1]
 * CurrentFailSts_FD02_BSM2: Integer in interval [0...1]
 * CurrentFailSts_FD02_CADM2: Integer in interval [0...1]
 * CurrentFailSts_FD02_EPS: Integer in interval [0...1]
 * CurrentFailSts_FD02_ORC: Integer in interval [0...1]
 * CurrentFailSts_FD02_SGW: Integer in interval [0...1]
 * CurrentFailSts_FD02_TRLR_REV: Integer in interval [0...1]
 * CurrentFailSts_FD03_BCM: Integer in interval [0...1]
 * CurrentFailSts_FD03_SGW: Integer in interval [0...1]
 * CurrentFailSts_FD04_BCM: Integer in interval [0...1]
 * CurrentFailSts_FD08_SGW: Integer in interval [0...1]
 * CurrentFailSts_FD11_SGW: Integer in interval [0...1]
 * DES_FD01_BCM: Integer in interval [0...3]
 * DES_FD01_SGW: Integer in interval [0...3]
 * DES_FD02_BCM: Integer in interval [0...3]
 * DES_FD02_BSM2: Integer in interval [0...3]
 * DES_FD02_CADM2: Integer in interval [0...3]
 * DES_FD02_EPS: Integer in interval [0...3]
 * DES_FD02_ORC: Integer in interval [0...3]
 * DES_FD02_SGW: Integer in interval [0...3]
 * DES_FD02_TRLR_REV: Integer in interval [0...3]
 * DES_FD03_BCM: Integer in interval [0...3]
 * DES_FD03_SGW: Integer in interval [0...3]
 * DES_FD04_BCM: Integer in interval [0...3]
 * DES_FD08_SGW: Integer in interval [0...3]
 * DES_FD11_SGW: Integer in interval [0...3]
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType: Integer in interval [0...255]
 * DeltaTimestamp_IMUdata: Integer in interval [0...255]
 * Dem_UdsStatusByteType: Integer in interval [0...255]
 * DetectionFailInfo_DID_t: Integer in interval [0...4294967295]
 * DetectionFailInfo_t: Integer in interval [0...4294967295]
 * DeviceAddress: Integer in interval [0...255]
 * Digit_01: Integer in interval [0...15]
 * Digit_02: Integer in interval [0...15]
 * Digit_03: Integer in interval [0...15]
 * Digit_04: Integer in interval [0...15]
 * Digit_05: Integer in interval [0...15]
 * Digit_06: Integer in interval [0...15]
 * Digit_07: Integer in interval [0...15]
 * Digit_08: Integer in interval [0...15]
 * Digit_09: Integer in interval [0...15]
 * Digit_10: Integer in interval [0...15]
 * Digit_11: Integer in interval [0...15]
 * DriverDoorSts: Integer in interval [0...1]
 * DynamicGrid: Integer in interval [0...1]
 * ECM_THA_Resp: Integer in interval [0...3]
 * ECM_TRSC_Resp: Integer in interval [0...3]
 * EOL_FD01_BCM: Integer in interval [0...1]
 * EOL_FD01_SGW: Integer in interval [0...1]
 * EOL_FD02_BCM: Integer in interval [0...1]
 * EOL_FD02_BSM2: Integer in interval [0...1]
 * EOL_FD02_CADM2: Integer in interval [0...1]
 * EOL_FD02_EPS: Integer in interval [0...1]
 * EOL_FD02_ORC: Integer in interval [0...1]
 * EOL_FD02_SGW: Integer in interval [0...1]
 * EOL_FD02_TRLR_REV: Integer in interval [0...1]
 * EOL_FD03_BCM: Integer in interval [0...1]
 * EOL_FD03_SGW: Integer in interval [0...1]
 * EOL_FD04_BCM: Integer in interval [0...1]
 * EOL_FD08_SGW: Integer in interval [0...1]
 * EOL_FD11_SGW: Integer in interval [0...1]
 * EPBSts: Integer in interval [0...15]
 * EPS_SteeringTouchStat: Integer in interval [0...1]
 * EPS_SteeringTouq_Resp: Integer in interval [0...3]
 * EPS_THA_DriverTorqueOverride: Integer in interval [0...3]
 * EPS_THA_SteeringTorqueResp: Integer in interval [0...7]
 * ESS_ENG_ST_W: Integer in interval [0...15]
 * EngineSts_W: Integer in interval [0...3]
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * FD01_BCM_64: Integer in interval [0...18446744073709551615]
 * FD01_SGW_64: Integer in interval [0...18446744073709551615]
 * FD02_BCM_64: Integer in interval [0...18446744073709551615]
 * FD02_BSM2_64: Integer in interval [0...18446744073709551615]
 * FD02_CADM2_64: Integer in interval [0...18446744073709551615]
 * FD02_EPS_64: Integer in interval [0...18446744073709551615]
 * FD02_ORC_64: Integer in interval [0...18446744073709551615]
 * FD02_SGW_64: Integer in interval [0...18446744073709551615]
 * FD02_TRLR_REV_64: Integer in interval [0...18446744073709551615]
 * FD03_BCM_64: Integer in interval [0...18446744073709551615]
 * FD03_SGW_64: Integer in interval [0...18446744073709551615]
 * FD04_BCM_64: Integer in interval [0...18446744073709551615]
 * FD08_SGW_64: Integer in interval [0...18446744073709551615]
 * FD11_SGW_64: Integer in interval [0...18446744073709551615]
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
 * GenericFailSts_FD01_BCM: Integer in interval [0...1]
 * GenericFailSts_FD01_SGW: Integer in interval [0...1]
 * GenericFailSts_FD02_BCM: Integer in interval [0...1]
 * GenericFailSts_FD02_BSM2: Integer in interval [0...1]
 * GenericFailSts_FD02_CADM2: Integer in interval [0...1]
 * GenericFailSts_FD02_EPS: Integer in interval [0...1]
 * GenericFailSts_FD02_ORC: Integer in interval [0...1]
 * GenericFailSts_FD02_SGW: Integer in interval [0...1]
 * GenericFailSts_FD02_TRLR_REV: Integer in interval [0...1]
 * GenericFailSts_FD03_BCM: Integer in interval [0...1]
 * GenericFailSts_FD03_SGW: Integer in interval [0...1]
 * GenericFailSts_FD04_BCM: Integer in interval [0...1]
 * GenericFailSts_FD08_SGW: Integer in interval [0...1]
 * GenericFailSts_FD11_SGW: Integer in interval [0...1]
 * HAS_Status_C2: Integer in interval [0...3]
 * HU_TRSC_EnableBtn_Sts: Integer in interval [0...2]
 * ITBM_TrlrStat: Integer in interval [0...3]
 * IgnitionOnCounter: Integer in interval [0...65535]
 * LHF_FastPulseCounter: Integer in interval [0...255]
 * LHF_Spin: Integer in interval [0...3]
 * LHRDoorSts: Integer in interval [0...1]
 * LHR_FastPulseCounter: Integer in interval [0...255]
 * LHR_Spin: Integer in interval [0...3]
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
 * OperationalModeSts: Integer in interval [0...15]
 * PAMRequestSts: Integer in interval [0...1]
 * PamChimeVolumeFront: Integer in interval [0...3]
 * PamChimeVolumeRear: Integer in interval [0...3]
 * PreviousCanNMState_FD01_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD01_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD02_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD02_BSM2: Integer in interval [0...15]
 * PreviousCanNMState_FD02_CADM2: Integer in interval [0...15]
 * PreviousCanNMState_FD02_EPS: Integer in interval [0...15]
 * PreviousCanNMState_FD02_ORC: Integer in interval [0...15]
 * PreviousCanNMState_FD02_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD02_TRLR_REV: Integer in interval [0...15]
 * PreviousCanNMState_FD03_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD03_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD04_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD08_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD11_SGW: Integer in interval [0...15]
 * PsngrDoorSts: Integer in interval [0...1]
 * RHF_FastPulseCounter: Integer in interval [0...255]
 * RHF_Spin: Integer in interval [0...3]
 * RHRDoorSts: Integer in interval [0...1]
 * RHR_FastPulseCounter: Integer in interval [0...255]
 * RHR_Spin: Integer in interval [0...3]
 * RHatchSts: Integer in interval [0...1]
 * RL_Lvl_Adj: Integer in interval [0...1]
 * RR_Lvl_Adj: Integer in interval [0...1]
 * Rear_Brk_Asst: Integer in interval [0...1]
 * RecognitionInfo_t: Integer in interval [0...4294967295]
 * RemStActvSts: Integer in interval [0...1]
 * Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0: Integer in interval [0...4294967295]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SVC_Guidelines: Integer in interval [0...1]
 * ShiftLeverPosition: Integer in interval [0...15]
 * ShiftLeverPositionReq: Integer in interval [0...15]
 * Shifter_ADAS_Inhibit: Integer in interval [0...1]
 * State_t: Integer in interval [0...4294967295]
 * TCASERANGESTATUS: Integer in interval [0...3]
 * TGW_CAMERA_DISP_STAT: Integer in interval [0...15]
 * THA_SteeringTouchStat: Integer in interval [0...3]
 * TRANS_ADAS_Inhibit: Integer in interval [0...1]
 * TRSC_CenterBtn_Sts: Integer in interval [0...3]
 * TRSC_EnableBtn_Sts: Integer in interval [0...3]
 * TRSC_RawKnob: Integer in interval [0...511]
 * TargetGear: Integer in interval [0...15]
 * TeTRSC_e_CamBlockSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrCalInfo_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrPrsntInfo_DID: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrRecogInfo_DID: Integer in interval [0...4294967295]
 * TotalOdometer: Integer in interval [0...1048575]
 * TrailerCalibrationFailInfo_DID_t: Integer in interval [0...4294967295]
 * TrailerCalibrationFailInfo_t: Integer in interval [0...4294967295]
 * TrailerConnectionSts: Integer in interval [0...3]
 * TrailerID_t: Integer in interval [0...4294967295]
 * TrailerPresentInfo_t: Integer in interval [0...4294967295]
 * TransmissionSailingSts: Integer in interval [0...15]
 * TrlrCalInfo_t: Integer in interval [0...4294967295]
 * TurnIndicatorSts: Integer in interval [0...3]
 * VIN_MSG: Integer in interval [0...3]
 * VehicleStandStillSts: Integer in interval [0...3]
 * VoltMgr_Enum_VoltageMON: Integer in interval [0...255]
 * WakeupSource_FD01_ADCM: Integer in interval [0...255]
 * WakeupSource_FD01_BCM: Integer in interval [0...255]
 * WakeupSource_FD01_SGW: Integer in interval [0...255]
 * WakeupSource_FD02_BCM: Integer in interval [0...255]
 * WakeupSource_FD02_BSM2: Integer in interval [0...255]
 * WakeupSource_FD02_CADM2: Integer in interval [0...255]
 * WakeupSource_FD02_EPS: Integer in interval [0...255]
 * WakeupSource_FD02_ORC: Integer in interval [0...255]
 * WakeupSource_FD02_SGW: Integer in interval [0...255]
 * WakeupSource_FD02_TRLR_REV: Integer in interval [0...255]
 * WakeupSource_FD03_BCM: Integer in interval [0...255]
 * WakeupSource_FD03_SGW: Integer in interval [0...255]
 * WakeupSource_FD04_BCM: Integer in interval [0...255]
 * WakeupSource_FD08_SGW: Integer in interval [0...255]
 * WakeupSource_FD11_SGW: Integer in interval [0...255]
 * aZynqM_E_ModuleState_EOL_STM_t: Integer in interval [0...4294967295]
 * aZynqM_E_ModuleState_OC_STM_t: Integer in interval [0...4294967295]
 * aZynqM_E_ModuleState_SC_STM_t: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType
 * Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType: Array with 8 element(s) of type Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
 * Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType: Array with 9 element(s) of type Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
 * Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType: Array with 2 element(s) of type Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
 * Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType: Array with 1 element(s) of type Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType: Array with 2 element(s) of type Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType: Array with 5 element(s) of type Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType: Array with 2 element(s) of type Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType
 * Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType: Array with 3 element(s) of type Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType
 * Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType: Array with 1 element(s) of type Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType: Array with 2 element(s) of type Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType: Array with 2 element(s) of type Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType
 * Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType: Array with 2 element(s) of type Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType
 * Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType: Array with 256 element(s) of type uint8
 * EOLIterationData_arr: Array with 5 element(s) of type uint8
 * ME_Hydra3defs_E_CalibStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_E_CalibStatus_t
 * ME_Hydra3defs_S_EOLStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_S_EOLStatus_t
 * ME_Hydra3defs_S_OCStatus_arr: Array with 4 element(s) of type ME_Hydra3defs_S_OCStatus_t
 * Reserved_arr: Array with 7 element(s) of type uint8
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * VIN_DATA: Array with 7 element(s) of type uint8
 * VINlData_Arr: Array with 17 element(s) of type uint8
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
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
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
 * SSM_2_0_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_0_LocalAppStatus_Arr
 * SSM_2_1_CoreStatus: Record with elements
 *   CoreStatus of type SSM_CoreSlaveCoreStateDef
 *   LocalAppStatus of type SSM_MCU_2_1_LocalAppStatus_Arr
 * SVSToDiag_t: Record with elements
 *   Routine_ID of type ME_Hydra3defs_E_RoutineType_t
 *   Camera_ID of type ME_Hydra3defs_E_CameraID_t
 *   TestPattern_ID of type ME_Hydra3defs_E_TestPatternType_t
 *   Response_Ack of type boolean
 *   NRC_ID of type ME_Hydra3defs_E_NRCType_t
 * TbSVS_S_SVSCamCalibReset_t: Record with elements
 *   CalibrationID of type ME_Hydra3defs_E_CalibrationID_t
 *   CameraID of type ME_Hydra3defs_E_CameraID_t
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
 *   uint8 *Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock(void)
 *   uint8 *Rte_Pim_VIN_Lock_MirrorBlock(void)
 *   uint8 *Rte_Pim_VIN_OdometerCnt_MirrorBlock(void)
 *   uint8 *Rte_Pim_VIN_CurrentVal_MirrorBlock(void)
 *     Returnvalue: uint8* is of type VINlData_Arr
 *   uint8 *Rte_Pim_VIN_OriginalVal_MirrorBlock(void)
 *     Returnvalue: uint8* is of type VINlData_Arr
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 Rte_CData_DID_5201_PlantModeStatus_DefaultValue(void)
 *   uint8 Rte_CData_VIN_Lock_DefaultValue(void)
 *   uint8 Rte_CData_VIN_OdometerCnt_DefaultValue(void)
 *   uint8 *Rte_CData_VIN_CurrentVal_DefaultValue(void)
 *     Returnvalue: uint8* is of type VINlData_Arr
 *   uint8 *Rte_CData_VIN_OriginalVal_DefaultValue(void)
 *     Returnvalue: uint8* is of type VINlData_Arr
 *
 *********************************************************************************************************************/


#define SWC_RIDMgr_START_SEC_CODE
#include "SWC_RIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_RIDMgr_Main
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
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_0(SSM_2_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_1(SSM_2_1_CoreStatus *data)
 *   Std_ReturnType Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(CalDataProvider_MCU_1_0_Def *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_PRX_CanNod27_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_SurroundViewCam_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(TbSVS_e_SVSOutputToDiagMgrCamCalib_t *data)
 *   Std_ReturnType Rte_Read_RpSVSToDiag_SVSToDiag_t(SVSToDiag_t *data)
 *   Std_ReturnType Rte_Read_RpTemperatureVal_GetTemperatureVal(uint8 *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_ASCM_Stat(ASCM_Stat *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(CmdIgnSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts(DriverDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(GearEngaged *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts(LHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts(PsngrDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts(RHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_RHatchSts(RHatchSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(ShiftLeverPosition *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_VIN_DATA(uint8 *data)
 *     Argument data: uint8* is of type VIN_DATA
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_VIN_MSG(VIN_MSG *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(FD14_LwsAngle *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(uint16 *data)
 *   Std_ReturnType Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t(TrailerDetection_Output_DID_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpCalibRoutineTrigger_routine_b(boolean data)
 *   Std_ReturnType Rte_Write_PpCalibRoutineType_value(uint8 data)
 *   Std_ReturnType Rte_Write_PpCan14DbgRoutineState_Can14DbgRoutine(CanDebugMode_t data)
 *   Std_ReturnType Rte_Write_PpFailSafeReaction_State(boolean data)
 *   Std_ReturnType Rte_Write_PpPlantMode_Status(uint8 data)
 *   Std_ReturnType Rte_Write_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(boolean data)
 *   Std_ReturnType Rte_Write_PpVINData_VINCurrentData(const uint8 *data)
 *     Argument data: uint8* is of type VINlData_Arr
 *   Std_ReturnType Rte_Write_PpVINData_VINLockStatus(uint8 data)
 *   Std_ReturnType Rte_Write_PpVINData_VINOdoCounter(uint8 data)
 *   Std_ReturnType Rte_Write_PpVINData_VINOriginalData(const uint8 *data)
 *     Argument data: uint8* is of type VINlData_Arr
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PpModeProgPreconditionCheck_ModeProgPreconditionCheck(uint8 mode)
 *   Modes of Rte_ModeType_ProgPreconditionState:
 *   - RTE_MODE_ProgPreconditionState_StateNotOK
 *   - RTE_MODE_ProgPreconditionState_StateOK
 *   - RTE_TRANSITION_ProgPreconditionState
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrit_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrit_MCUReadDeviceRegData(DeviceAddress DeviceAdd, uint16 *RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrit_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpReadVoltInfo_GetVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, float32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RpSVSCamCalibReset_WriteBlock(const TbSVS_S_SVSCamCalibReset_t *v_SVSCamCalibReset)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_SVSCamCalibReset_E_NOT_OK, RTE_E_IF_SVSCamCalibReset_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_Lock_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_Lock_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_OdometerCnt_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_OdometerCnt_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B217A1C_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B217A92_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C51C_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C592_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C61C_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C692_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C71C_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C792_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026400_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026500_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026600_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026700_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RIDMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_RIDMgr_CODE) RE_RIDMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RIDMgr_Main
 *********************************************************************************************************************/
  /*ReqID:-*/
/*GUID:-{7D5FE2DD-0217-4785-A6DF-BDF775380717}*/
  /* DD-ID: {7D5FE2DD-0217-4785-A6DF-BDF775380717}*/
uint8 v_VINlockStatus_u8;
uint8 v_VINOdoConter_u8;
uint8 v_Plantmodestatus_u8;
NvM_RequestResultType v_BlockErrorStatus;
static uint8 s_nvm_PlantModeSts_u8 = (uint8)e_ZERO;
SSM_2_1_CoreStatus SSM_2_1_data;
static uint8 v_RemoteCoreStatus_u8;

   F_ConfigMgr_VINProcess();
   F_ProgrammingPreconditionCheck();

   v_VINlockStatus_u8 = *Rte_Pim_VIN_Lock_MirrorBlock();
   v_VINOdoConter_u8  = *Rte_Pim_VIN_OdometerCnt_MirrorBlock();
   (void)Rte_Write_PpVINData_VINLockStatus(v_VINlockStatus_u8);
   (void)Rte_Write_PpVINData_VINCurrentData(Rte_Pim_VIN_CurrentVal_MirrorBlock());   
   (void)Rte_Write_PpVINData_VINOriginalData(Rte_Pim_VIN_OriginalVal_MirrorBlock());
   (void)Rte_Write_PpVINData_VINOdoCounter(v_VINOdoConter_u8);
   
  if(*Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock() != s_nvm_PlantModeSts_u8)
  {
      VStdMemCpy( &s_nvm_PlantModeSts_u8,Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock(),sizeof(uint8));
      (void)Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_GetErrorStatus(&v_BlockErrorStatus);
      if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
      {
          (void)Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_WriteBlock(Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock());
      }
      else
      {
          /*Do Nothing*/
      }
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECU_In_Plant_Mode_Fault,s_nvm_PlantModeSts_u8+(uint32)ErrorMgr_ErrorInactive,NULL_PTR);
  }
  else
  {
    /*Do Nothing*/
  }
 v_Plantmodestatus_u8 =*Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock();
  (void)Rte_Write_PpPlantMode_Status(v_Plantmodestatus_u8);

 /*Read MCU 2_1 status*/
  (void)Rte_Read_R_SSM_2_State_State_2_1(&SSM_2_1_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_1_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MCU2_1_STATE) == FALSE))
  {
    /*once other core initialised then send this value */
     DiagToParkAssist_data.MbDiag_PlantModeOn =  (boolean)*Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock();
     (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&DiagToParkAssist_data, (uint16)e_IpcMsgId_Data_DiagToParkAssist_t, (uint16)sizeof(DiagToParkAssist_t));
    v_RemoteCoreStatus_u8 |= MCU2_1_STATE;   /*Update core Status Flag once data is transmited to avoid repetitive calls*/

  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_RIDMgrr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RIDMgrr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_RIDMgr_CODE) RE_RIDMgrr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RIDMgrr_Init
 *********************************************************************************************************************/
  /* DD-ID: {3627F8EA-FC60-4270-8092-9D5ACCA4DD49}*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(const Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 18407343, 18407355, 18407385, 18407363, 18407394, 18407399, 18407414 */
  /*GUID:-*/
  /* DD-ID: {5CCD84A3-3299-4851-89FC-CBC73EED73B2}*/
  CanDebugMode_t CanDebugMode_data;
  VehicleSpeedVSOSig v_VehicleSpd_u8;
  Std_ReturnType retvalue = RTE_E_INVALID;
  (void)OpStatus;
  (void)Out_ResData;
  /*Get Vehicle Speed*/
 (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);

  if(v_VehicleSpd_u8 > (VehicleSpeedVSOSig)D_VEHICLE_SPEED_THRESHOLD)
  {
	   *ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;
	   retvalue =  RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_E_NOT_OK;
  }
  else
  {
		  if((*In_ReqData < R_1000_MODE_MAX ) && (NULL != ErrorCode))
		  {
			CanDebugMode_data = *In_ReqData;
			(void)Rte_Write_PpCan14DbgRoutineState_Can14DbgRoutine(CanDebugMode_data);
			(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&CanDebugMode_data, (uint16)e_IpcMsgId_Data_ME_CanDebugRIDStatus_t, (uint16)sizeof(CanDebugMode_t));
			retvalue = RTE_E_OK;
		  }
		  else
		  {
			   *ErrorCode =  DCM_E_REQUESTOUTOFRANGE;
			   retvalue =  RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_E_NOT_OK;
		  }
  }
  return retvalue;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31012000_Original_VIN_Lock_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31012000_Original_VIN_Lock>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31012000_Original_VIN_Lock_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31012000_Original_VIN_Lock_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31012000_Original_VIN_Lock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31012000_Original_VIN_Lock_Start (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-   16323769,15253893,16558242,16560185,17347152,17347226,17378712,16239554,15754705*/
  /*GUID:-{2657991E-729D-4581-B27D-5FA429C68789}*/
  /* DD-ID: {1F7A69D1-1D0A-48ab-BC6A-B33544E66B57}*/
  Std_ReturnType v_retvalue_u8 = RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_PENDING;
  (void)OpStatus;
  NvM_RequestResultType v_BlockErrorStatus;

  if((*Rte_Pim_VIN_Lock_MirrorBlock() == (uint8)LOCK_BY_ODOMETER_VALUE)|| (*Rte_Pim_VIN_Lock_MirrorBlock() == (uint8)LOCK_BY_EXTERNAL_TOOL))
  {
   *ErrorCode =  DCM_E_CONDITIONSNOTCORRECT; 
   v_retvalue_u8 =  RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_E_NOT_OK;   
  }
  else
  {
   /* Lock VIN */
   *Rte_Pim_VIN_Lock_MirrorBlock()= (uint8)LOCK_BY_EXTERNAL_TOOL;  /* Write NVM Pim with TRUE value */
   (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_GetErrorStatus(&v_BlockErrorStatus);
   if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
   {
	   (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_WriteBlock(Rte_Pim_VIN_Lock_MirrorBlock());
	   v_retvalue_u8 =  RTE_E_OK;
   }
  else{/*do nothing*/}
  }
  
  return v_retvalue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31012001_Original_VIN_Unlock_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31012001_Original_VIN_Unlock>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31012001_Original_VIN_Unlock_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31012001_Original_VIN_Unlock_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31012001_Original_VIN_Unlock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31012001_Original_VIN_Unlock_Start (returns application error)
 *********************************************************************************************************************/
/*ReqID:-16240781,16240782,16240969,16240973,16240971,16241067,16240972,16240970*/
  /*GUID:-{9D0566AA-2B1F-4e61-AFE9-EAE335688D41}*/
  /* DD-ID: {EB3E79DA-78DF-4e27-854C-178B6062036C}*/
  Std_ReturnType v_retvalue_u8 = RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_PENDING;
  (void)OpStatus;
  NvM_RequestResultType v_BlockErrorStatus;
  if(*Rte_Pim_VIN_Lock_MirrorBlock() == (uint8)VIN_NOT_LOCKED)   /* Read Current VIN Lock value*/
  {
    *ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;  
    v_retvalue_u8 =  RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_E_NOT_OK; 
  }
  else
  {
    /* Unlock VIN */
    *Rte_Pim_VIN_Lock_MirrorBlock() = (uint8)VIN_NOT_LOCKED;
    (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_GetErrorStatus(&v_BlockErrorStatus);
    if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
    {
 	   (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_WriteBlock(Rte_Pim_VIN_Lock_MirrorBlock());
 	   v_retvalue_u8 =  RTE_E_OK;
    }
else
{
  /*Do Nothing*/
}
  }

  return v_retvalue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31013000_XCP_Enable_Disable_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(const Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {75ECA31A-6957-4020-92D5-355983D2AD42}*/
Std_ReturnType retVal;
VehicleSpeedVSOSig v_VehicleSpd_u8;
(void)OpStatus;
(void)Out_ResData;
/*Get Vehicle Speed*/
(void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);

/*Check Vehicle Speed*/
if(v_VehicleSpd_u8 > (VehicleSpeedVSOSig)D_VEHICLE_SPEED_THRESHOLD)
{
	   *ErrorCode =  DCM_E_CONDITIONSNOTCORRECT;
	   retVal =  RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_E_NOT_OK;
}
else
{
		switch(*In_ReqData)
		{
			case 0x01u: XCP_ACTIVATE();
					   retVal = RTE_E_OK;
			break;

    case 0x00u: Xcp_Disconnect(XCP_CHANNEL_IDX);
               XCP_DEACTIVATE();
               retVal = RTE_E_OK;
    break;

    default:
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    retVal = RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_E_NOT_OK;
    break;

		}
}
Out_ResData[e_ZERO] = In_ReqData[e_ZERO];
return (retVal);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(const Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 17771044, 17771130, 17771160, 17771165, 17771147, 17771146, 17771987 */
  /*GUID:-{D04467F1-982F-40a6-A293-5C4C8C923B21}*/
  /* DD-ID: {D04467F1-982F-40a6-A293-5C4C8C923B21}*/
  Std_ReturnType v_retvalue_u8 = RTE_E_INVALID;
  (void)OpStatus;
  if((NULL != In_ReqData) && (NULL != ErrorCode))
  {
    
    if((uint8)e_ZERO == In_ReqData[e_ZERO])
    {
      DiagToParkAssist_data.IeDiag_b_ParkAssistSts = (uint8)e_ONE;
      v_retvalue_u8 = RTE_E_OK;
    }
    
    else if ((uint8)e_ONE == In_ReqData[e_ZERO])
    {
      DiagToParkAssist_data.IeDiag_b_ParkAssistSts = (uint8)e_ZERO;
      v_retvalue_u8 = RTE_E_OK;
    }
    
    else
    {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      v_retvalue_u8 = RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_E_NOT_OK;
      DiagToParkAssist_data.IeDiag_b_ParkAssistSts = (uint8)e_ZERO;
    }

    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&DiagToParkAssist_data, (uint16)e_IpcMsgId_Data_DiagToParkAssist_t, (uint16)sizeof(DiagToParkAssist_t));
  }
else
{
/*Do nothing*/
}
  return v_retvalue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015101_Sensor_Functional_Test_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start (returns application error)
 *********************************************************************************************************************/
    /*ReqID:-*/
    /*GUID:-{58CBAF03-E822-4294-911F-7DAB33F2F87E}*/
	  (void)OpStatus;
	  (void)ErrorCode;
  /* DD-ID: {58CBAF03-E822-4294-911F-7DAB33F2F87E}*/
    
   (void)Rte_Write_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(TRUE);
   
   /*sending MbDiag_SensorTestMode data true to IPC */ 
    DiagToParkAssist_data.MbDiag_SensorTestMode = TRUE;
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&DiagToParkAssist_data, (uint16)e_IpcMsgId_Data_DiagToParkAssist_t, (uint16)sizeof(DiagToParkAssist_t));
   
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Routine_31015200_Plant_Mode_Routine_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType* is of type Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-   17061051*/
  /*GUID:-{C8F0FC31-6695-4c3a-B4E2-A5E69A8449ED}*/
  /* DD-ID: {55B61736-084B-452e-9108-DAD10A0CDEE9}*/
 /*return plant mode status in gloable s_variable_u8*/
 Std_ReturnType v_retval_u8;
 static uint8 s_PlantModeSts_u8;
 (void)OpStatus;
 (void)Out_ResData;
 VStdMemCpy(&s_PlantModeSts_u8,Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock(), sizeof(uint8));

 if((uint8)RID_STATUS_NOTCOMPLETE != s_PlantModeSts_u8)
 {
 	if(s_PlantModeSts_u8 == (uint8)e_ZERO)
 	{
 		Out_ResData[e_ZERO]= (uint8)e_ONE;
 		v_retval_u8 = RTE_E_OK;
 	}
 	else if(s_PlantModeSts_u8 == (uint8)e_ONE)
 	{
 		Out_ResData[e_ZERO]= (uint8)e_TWO;
 		v_retval_u8 = RTE_E_OK;
 	}
 	else
 	{
 		 *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
 		 v_retval_u8 =  RTE_E_INVALID;
 	}
 }
 else
 {
	 *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	 v_retval_u8 =  RTE_E_INVALID;
 }
	
 return v_retval_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015200_Plant_Mode_Routine_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(const Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start (returns application error)
 *********************************************************************************************************************/
/*ReqID:-   17086055,17086123,17058466*/
 /*GUID:-{049CB19E-EF07-4126-8731-81D10378A95A}*/
  /* DD-ID: {E80B1BE9-D5F4-437f-ACC9-084A38E8086A}*/
  /*read and store plant mode status in gloable s_variable_u8 s_nvm_PlantModeSts_u8*/
  Std_ReturnType v_retval_u8;
  (void)OpStatus;
  if(In_ReqData[e_ZERO] == (uint8)e_ZERO)
  {
    /* In plant Mode */
    *Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock() = (uint8)e_ONE;
    /*enter in Plant mode  */
    DiagToParkAssist_data.MbDiag_PlantModeOn = (boolean)e_ONE;
    v_retval_u8 = RTE_E_OK;
  }
  else if(In_ReqData[e_ZERO] == (uint8)e_ONE)
  {
    /* not in plant mode  */
    *Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock() = (uint8)e_ZERO;
    /*Plant mode exit */
    DiagToParkAssist_data.MbDiag_PlantModeOn = (boolean)e_ZERO;
    v_retval_u8 = RTE_E_OK;
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    /*adding default value as Plant mode exit */
    DiagToParkAssist_data.MbDiag_PlantModeOn = (boolean)e_ZERO;
    v_retval_u8 = RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_E_NOT_OK; 
  }
  

  (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&DiagToParkAssist_data, (uint16)e_IpcMsgId_Data_DiagToParkAssist_t, (uint16)sizeof(DiagToParkAssist_t));

  return v_retval_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType* is of type Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 17370168,17371583, 173715835,17371589,17372189,17372205,17372213,17372228,15754690*/
  /*GUID:-*/
  /* DD-ID: {9465A498-7997-441b-89EA-EE52DA06AC1F}*/

  Std_ReturnType retvalue = RTE_E_INVALID;
  TbSVS_e_SVSOutputToDiagMgrCamCalib_t EOL_CalibState;
  SystemCalibStatus_t SystemCalibStatus;
  CameraCalibStatus_t Front_CameraCalibStatus ;
  CameraCalibStatus_t Left_CameraCalibStatus;
  CameraCalibStatus_t Right_CameraCalibStatus ;
  CameraCalibStatus_t Rear_CameraCalibStatus;
  CalDataProvider_MCU_1_0_Def EOL_CalibStatus;
  (void)OpStatus;
  (void)Out_ResData;
  (void)Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(&EOL_CalibStatus);
  
    if ( (NULL_PTR != Out_ResData) && ( NULL_PTR != ErrorCode ))
    {
      if(RIDM_RoutineStatus_5400_e == ACTIVE)
      {
        (void)Rte_Read_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(&EOL_CalibState);
		
		/*when all camera variants selected then check status till last camera that is right */
        if(((EOL_CalibStatus.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibCompletedSuccessful) ||
          (EOL_CalibStatus.CalData_SVSCamEOLCalibData.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibAbortedFailed))
		  && (v_EOL_calibRoutine_RearStarted == (uint8)e_ONE))
          {
            RESULT_5400_e = ROUTINE_COMPLETED;
            v_EOL_calibRoutine_activeFlag = (boolean)FALSE;
          }
		  /*when single camera variant selected then check status of rear camera */
          else if(((EOL_CalibStatus.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibCompletedSuccessful) ||
          (EOL_CalibStatus.CalData_SVSCamEOLCalibData.CamRearEOL.CamCalibData_STM.calibdata.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibAbortedFailed))
		  && (v_EOL_calibRoutine_RearStarted == (uint8)e_FIVE))
          {
            RESULT_5400_e = ROUTINE_COMPLETED;
            v_EOL_calibRoutine_activeFlag = (boolean)FALSE;
          }
		  else
		  {
			RESULT_5400_e = ROUTINE_ACTIVE;
		  }			  
		 
      
        Out_ResData[e_ZERO] = (uint8)RESULT_5400_e;
        Out_ResData[e_ONE] = D_EOL_OK;
        Out_ResData[e_TWO] = D_NO_ERROR;

        if(v_EOL_calibRoutine_RearStarted == (uint8)e_FIVE)
        {
            /*System calibration status only depend on rear camera */
          if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
            {
              SystemCalibStatus = NO_ERROR;
            }
          else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_IN_PROCESS) 
            {
              SystemCalibStatus = IN_PROCESS;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT)
            {
              SystemCalibStatus = TARGET_NOT_FOUND_INIT ;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT)
            {
              SystemCalibStatus = TARGET_NOT_FOUND_LEFT;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_NOT_CALIBRATED)
            {
              SystemCalibStatus = NOT_CALIBRATED  ;
            }

            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT)
            {
              SystemCalibStatus = TARGET_NOT_FOUND_RIGHT ;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT)
            {
              SystemCalibStatus = TARGET_IDENT_ERROR_LEFT ;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT)
            {
              SystemCalibStatus = TARGET_IDENT_ERROR_RIGHT;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
            {
              SystemCalibStatus = EXCEED_QUALITY_LIMIT  ;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_ABORTED)
            {
              SystemCalibStatus = ABORTED;
            }
            else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_PRECONDITION_NOT_CORRECT)
            {
              SystemCalibStatus = PRECONDITION_NOT_CORRECT ;
            }
            else
            {
			/*Set as default value*/
               SystemCalibStatus = NOT_CALIBRATED  ;
            }
            Out_ResData[e_THREE] = (uint8)SystemCalibStatus;
    
            /* front camera status as no error because only single rear camera calibration is triggered */
            Out_ResData[e_FOUR]=(uint8) CAM_NO_ERROR  ;
           
           /* left  camera status as no error because only single rear camera calibration is triggered */
            Out_ResData[e_FIVE]=(uint8) CAM_NO_ERROR  ;
         

          /*Rear camera calibration status*/
          if((EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) || 
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) ||
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT))
          {
            Rear_CameraCalibStatus = CAM_TARGET_NOT_FOUND;
          }
          else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_NOT_CALIBRATED) 
          {
            Rear_CameraCalibStatus = CAM_NOT_CALIBRATED;
          }
          else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_ABORTED) 
          {
            Rear_CameraCalibStatus = CAM_ABORTED ;
          }
          else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
          {
            Rear_CameraCalibStatus = CAM_NO_ERROR  ;
          }
          else if((EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
                (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
          {
            Rear_CameraCalibStatus = CAM_TARGET_IDENT_ERROR;
          }
          else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
          {
            Rear_CameraCalibStatus = CAM_EOL_EXCEED_QUALITY_LIMIT  ;
          }
          else
          {

            Rear_CameraCalibStatus = CAM_NOT_CALIBRATED;
          }
          Out_ResData[e_SIX] =(uint8)Rear_CameraCalibStatus;
          /* right camera status as no error because only single rear camera calibration is triggered */
          Out_ResData[e_SEVEN]= (uint8)CAM_NO_ERROR  ;
        
        }
        else
        {

          /*System calibration status*/
          if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) &&
            (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS)  &&
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS)  &&
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS))
            {
              SystemCalibStatus = NO_ERROR;
            }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_CALIBRATION_IN_PROCESS) ||
            (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_CALIBRATION_IN_PROCESS)  ||
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_IN_PROCESS)  ||
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_CALIBRATION_IN_PROCESS))
            {
              SystemCalibStatus = IN_PROCESS;
            }
            else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) &&
            (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT)  &&
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT)  &&
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT))
            {
              SystemCalibStatus = TARGET_NOT_FOUND_INIT ;
            }
            else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) &&
            (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT)  &&
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT))
            {
              SystemCalibStatus = TARGET_NOT_FOUND_LEFT;
            }
            else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_NOT_CALIBRATED) ||
            (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_NOT_CALIBRATED)  ||
            (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_NOT_CALIBRATED)  ||
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_NOT_CALIBRATED))
            {
              SystemCalibStatus = NOT_CALIBRATED  ;
            }

          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT) &&
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT)  &&
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT))
          {
            SystemCalibStatus = TARGET_NOT_FOUND_RIGHT ;
          }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT)  ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT)  ||
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT))
          {
            SystemCalibStatus = TARGET_IDENT_ERROR_LEFT ;
          }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT)  ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT)  ||
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
          {
            SystemCalibStatus = TARGET_IDENT_ERROR_RIGHT;
          }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT)  ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT)  ||
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT))
          {
            SystemCalibStatus = EXCEED_QUALITY_LIMIT  ;
          }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_ABORTED) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_ABORTED)  ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_ABORTED)  ||
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_ABORTED))
          {
            SystemCalibStatus = ABORTED;
          }
          else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_PRECONDITION_NOT_CORRECT) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_PRECONDITION_NOT_CORRECT)  ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_PRECONDITION_NOT_CORRECT)  ||
          (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_PRECONDITION_NOT_CORRECT))
          {
            SystemCalibStatus = PRECONDITION_NOT_CORRECT ;
          }
          else
          {
		     /*Set as Defualt value*/
             SystemCalibStatus = NOT_CALIBRATED  ;
          }
          Out_ResData[e_THREE] = (uint8)SystemCalibStatus;
          
        /*Front camera calibration status*/
        if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) || 
          (EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) ||
          (EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT))
        {
          Front_CameraCalibStatus =CAM_TARGET_NOT_FOUND;
        }
        else if(EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_NOT_CALIBRATED) 
        {
          Front_CameraCalibStatus = CAM_NOT_CALIBRATED;
        }
        else if(EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_ABORTED) 
        {
          Front_CameraCalibStatus =CAM_ABORTED;
        }
        else if(EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
        {
          Front_CameraCalibStatus = CAM_NO_ERROR;
        }
        else if((EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
              (EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
        {
          Front_CameraCalibStatus =CAM_TARGET_IDENT_ERROR;
        }
        else if(EOL_CalibState.EOL_Status_STM[frontCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
        {
          Front_CameraCalibStatus= CAM_EOL_EXCEED_QUALITY_LIMIT;
        }
        else
        {
          Front_CameraCalibStatus= CAM_NOT_CALIBRATED;
        }
        Out_ResData[e_FOUR]= (uint8)Front_CameraCalibStatus;

        /*Left camera calibration status*/
        if((EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) || 
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) ||
          (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT))
        {
          Left_CameraCalibStatus = CAM_TARGET_NOT_FOUND;
        }
        else if(EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_NOT_CALIBRATED) 
        {
          Left_CameraCalibStatus =CAM_NOT_CALIBRATED;
        }
        else if(EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_ABORTED) 
        {
          Left_CameraCalibStatus = CAM_ABORTED ;
        }
        else if(EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
        {
          Left_CameraCalibStatus =CAM_NO_ERROR  ;
        }
        else if((EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
              (EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
        {
          Left_CameraCalibStatus = CAM_TARGET_IDENT_ERROR;
        }
        else if(EOL_CalibState.EOL_Status_STM[leftCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
        {
          Left_CameraCalibStatus = CAM_EOL_EXCEED_QUALITY_LIMIT;
        }
        else
        {
           Left_CameraCalibStatus = CAM_NOT_CALIBRATED;
        }
        Out_ResData[e_FIVE]= (uint8)Left_CameraCalibStatus;

        /*Rear camera calibration status*/
        if((EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) || 
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) ||
          (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT))
        {
          Rear_CameraCalibStatus =CAM_TARGET_NOT_FOUND;
        }
        else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_NOT_CALIBRATED) 
        {
          Rear_CameraCalibStatus =CAM_NOT_CALIBRATED;
        }
        else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_ABORTED) 
        {
          Rear_CameraCalibStatus = CAM_ABORTED ;
        }
        else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
        {
          Rear_CameraCalibStatus = CAM_NO_ERROR  ;
        }
        else if((EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
              (EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
        {
          Rear_CameraCalibStatus = CAM_TARGET_IDENT_ERROR;
        }
        else if(EOL_CalibState.EOL_Status_STM[rearCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
        {
          Rear_CameraCalibStatus =CAM_EOL_EXCEED_QUALITY_LIMIT;
        }
        else
        {
          Rear_CameraCalibStatus= CAM_NOT_CALIBRATED;
        }
          Out_ResData[e_SIX]= (uint8)Rear_CameraCalibStatus;

          /*Right camera calibration status*/
            if((EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_INIT) || 
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_LEFT) ||
            (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_NOT_FOUND_RIGHT))
          {
            Right_CameraCalibStatus = CAM_TARGET_NOT_FOUND;
          }
          else if(EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_NOT_CALIBRATED) 
          {
            Right_CameraCalibStatus = CAM_NOT_CALIBRATED;
          }
          else if(EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_ABORTED) 
          {
            Right_CameraCalibStatus = CAM_ABORTED ;
          }
          else if(EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_CALIBRATION_SUCCESS) 
          {
            Right_CameraCalibStatus =CAM_NO_ERROR  ;
          }
          else if((EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT) ||
                (EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT))
          {
            Right_CameraCalibStatus = CAM_TARGET_IDENT_ERROR;
          }
          else if(EOL_CalibState.EOL_Status_STM[rightCam].errorCode_e == e_EOL_RESULT_EXCEED_QUALITY_LIMIT) 
          {
            Right_CameraCalibStatus = CAM_EOL_EXCEED_QUALITY_LIMIT  ;
          }
          else
          {
            Right_CameraCalibStatus = CAM_NOT_CALIBRATED;
          }
           Out_ResData[e_SEVEN]= (uint8)Right_CameraCalibStatus;
        }
        retvalue = RTE_E_OK;
      }
      else
      {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        retvalue = RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK;
      }
    }
    else
    {
      /* do nothing */
    }
  
  return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(const Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start (returns application error)
 *********************************************************************************************************************/
 /*ReqID:- 17370168,17371583, 173715835,17371589,17372189,17372205,17372213,17372228,15754690*/
 /*GUID:-*/
  /* DD-ID: {14D1CBF4-F100-464a-A1AF-7BC19C4E2EBD}*/
	Std_ReturnType retvalue = RTE_E_INVALID;
  Std_ReturnType PreconditionStatus;
	TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t l_DiagMgrOutputToSVSCamCalib;
  boolean v_CalibRoutineTriggered_b = FALSE;
  (void)OpStatus;
  (void)Out_ResData;
  PreconditionStatus = F_EOL_CalibrationPreconditionCheck();
  /*Check if Routine is already active then throw NRC 24*/
  if(RESULT_5400_e != ROUTINE_ACTIVE)
  {
    if((PreconditionStatus == E_OK) && (v_SC_calibRoutine_activeFlag == FALSE))
    {
      if((NULL_PTR != ErrorCode) && ( NULL_PTR != Out_ResData ))
      {		
        /*routine input for all cameras*/
     if(In_ReqData[e_ZERO] == (uint8)e_ONE)
          {
		    v_EOL_calibRoutine_RearStarted = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camFront = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camLeft = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camRear = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camRight = (uint8)e_ONE;
          
            l_DiagMgrOutputToSVSCamCalib.isRoutineRequested = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.calibType = CalibrationID2_EOL;
            /*EOL request send to A72 with calibration type , camera mask */
            (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&l_DiagMgrOutputToSVSCamCalib,(uint16)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t,sizeof(l_DiagMgrOutputToSVSCamCalib));
            RIDM_RoutineStatus_5400_e = ACTIVE;
            RESULT_5400_e = ROUTINE_ACTIVE;
        v_EOL_calibRoutine_activeFlag = (boolean)TRUE;
            
       *Out_ResData = (uint8)RESULT_5400_e;	
            *ErrorCode = DCM_E_POSITIVERESPONSE;
            retvalue = RTE_E_OK;
            v_CalibRoutineTriggered_b = TRUE;
            (void)Rte_Write_PpCalibRoutineTrigger_routine_b(v_CalibRoutineTriggered_b);
          }
      else if(In_ReqData[e_ZERO] == (uint8)e_FIVE)  /*routine for rear camera */
          {
        v_EOL_calibRoutine_RearStarted = (uint8)e_FIVE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camFront = (uint8)e_ZERO;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camLeft = (uint8)e_ZERO;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camRear = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.cameraMask.camRight = (uint8)e_ZERO;
          
            l_DiagMgrOutputToSVSCamCalib.isRoutineRequested = (uint8)e_ONE;
            l_DiagMgrOutputToSVSCamCalib.calibType = CalibrationID2_EOL;
            /*EOL request send to A72 with calibration type , camera mask */
            (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&l_DiagMgrOutputToSVSCamCalib,(uint16)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t,sizeof(l_DiagMgrOutputToSVSCamCalib));
            RIDM_RoutineStatus_5400_e = ACTIVE;
          
            RESULT_5400_e = ROUTINE_ACTIVE;
        v_EOL_calibRoutine_activeFlag = (boolean)TRUE;
       *Out_ResData = (uint8)RESULT_5400_e;	
            *ErrorCode = DCM_E_POSITIVERESPONSE;
            retvalue = RTE_E_OK;
            v_CalibRoutineTriggered_b = TRUE;
            (void)Rte_Write_PpCalibRoutineTrigger_routine_b(v_CalibRoutineTriggered_b);
          }
          else
          {
              RESULT_5400_e = ROUTINE_ABORTED;
          *Out_ResData =(uint8) RESULT_5400_e;	
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            retvalue = RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK;
          }      
      }		
      else
      {
        /* do nothing */
      }
    }
        else
        {
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          retvalue = RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK;
        }
}
else
{
  *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    retvalue = RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK;
}

  return retvalue;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Routine_31015401_Camera_Service_Calibration_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType* is of type Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
 /*ReqID:- 15232630, 17378477,17379275,17379276,17379277,17379272,17379273,17379278,17379279,15754705*/
 /*GUID:-*/
  /* DD-ID: {6645166C-22EE-476d-950F-5C67C24EB09C}*/
  Std_ReturnType retvalue = RTE_E_INVALID;
  CalDataProvider_MCU_1_0_Def CalDataProvider_MCU_1_0_NvmData;
  TbSVS_e_SVSOutputToDiagMgrCamCalib_t SCCalibStatus;
  (void)OpStatus;
  (void)Out_ResData;
  if ( (NULL_PTR != Out_ResData ) && ( NULL_PTR != ErrorCode ))
	  {
      if(RIDM_RoutineStatus_5401_e == ACTIVE)
      {
        (void)Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(&CalDataProvider_MCU_1_0_NvmData);
        (void)Rte_Read_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(&SCCalibStatus);
        
        if(((CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibCompletedSuccessful) ||
          (CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibAbortedFailed))
		  &&(v_SC_calibRoutine_RearStarted == (uint8)e_ONE))
          {
            RESULT_5401_e = ROUTINE_COMPLETED;
            v_SC_calibRoutine_activeFlag = (boolean)FALSE;
          }
		 else if(((CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibCompletedSuccessful) ||
          (CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.CalibStatus_e == (uint32)ME_Hydra3defs_E_CalibAbortedFailed))
		  &&(v_SC_calibRoutine_RearStarted == (uint8)e_FIVE))
          {
            RESULT_5401_e = ROUTINE_COMPLETED;
            v_SC_calibRoutine_activeFlag = (boolean)FALSE;
          }
          else
          {
            RESULT_5401_e = ROUTINE_ACTIVE;
          }
        Out_ResData[e_ZERO] =(uint8) RESULT_5401_e;
       if(v_SC_calibRoutine_RearStarted ==(uint8)e_FIVE)
        {
           /*Front Camera*/
          Out_ResData[e_ONE] = (uint8)CAM_NO_ERROR;
          /*left Camera*/
          Out_ResData[e_TWO] = (uint8)CAM_NO_ERROR;
          /*Rear Camera*/
          Out_ResData[e_THREE] = (uint8)CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.CalibStatus_e;
          /*Right Camera*/
          Out_ResData[e_FOUR] = (uint8)CAM_NO_ERROR;

          /*Front Camera*/
          Out_ResData[e_FIVE] = (uint8)NO_ERROR;
          /*left Camera*/
          Out_ResData[e_SIX] = (uint8)NO_ERROR;
          /*Rear Camera*/
          Out_ResData[e_SEVEN] =(uint8) SCCalibStatus.SC_Status_STM[rearCam].errorCode_e;
          /*Right Camera*/
          Out_ResData[e_EIGHT] = (uint8)NO_ERROR;


        }
        else
        {
           /*Front Camera*/
          Out_ResData[e_ONE] = (uint8)CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamFrontSC.CamCalibData_STM.CalibStatus_e;
          /*left Camera*/
          Out_ResData[e_TWO] = (uint8)CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamLeftSC.CamCalibData_STM.CalibStatus_e;
          /*Rear Camera*/
          Out_ResData[e_THREE] = (uint8)CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRearSC.CamCalibData_STM.CalibStatus_e;
          /*Right Camera*/
          Out_ResData[e_FOUR] = (uint8)CalDataProvider_MCU_1_0_NvmData.CalData_SVSCamSCCalibData.CamRightSC.CamCalibData_STM.CalibStatus_e;

          /*Front Camera*/
          Out_ResData[e_FIVE] = (uint8)SCCalibStatus.SC_Status_STM[frontCam].errorCode_e;
          /*left Camera*/
          Out_ResData[e_SIX] = (uint8)SCCalibStatus.SC_Status_STM[leftCam].errorCode_e;
          /*Rear Camera*/
          Out_ResData[e_SEVEN] =(uint8) SCCalibStatus.SC_Status_STM[rearCam].errorCode_e;
          /*Right Camera*/
          Out_ResData[e_EIGHT] = (uint8)SCCalibStatus.SC_Status_STM[rightCam].errorCode_e;
        }
       
        retvalue = RTE_E_OK;
      }
      else
      {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        retvalue = RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK;
      }
    }
	  else
	  {
		  /* do nothing */
	  }
  
  return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015401_Camera_Service_Calibration_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(const Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start (returns application error)
 *********************************************************************************************************************/
  /*ReqID:- 17378477,17379275,17379276,17379277,17379272,17379273,17379278,17379279,15754705*/
  /*GUID:-*/
  /* DD-ID: {8A773BB6-6FC3-4223-A7EF-8FE4DDDE766A}*/
 	(void) OpStatus; /*PRQA S 3119*/
	Std_ReturnType retvalue = RTE_E_INVALID;
  Std_ReturnType PreconditionStatus;
	TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t l_DiagMgrOutputToSVSCamCalib;
  boolean v_CalibRoutineTriggered_b = FALSE;
  static uint8 v_SC_CalibRoutineType_u8;
  (void)OpStatus;
  (void)Out_ResData;
  PreconditionStatus = F_SC_CalibrationPreconditionCheck();

  /*Check if Routine is already active then throw NRC 24*/
  if(RESULT_5401_e != ROUTINE_ACTIVE)
 {
  if((PreconditionStatus == (uint8)E_OK) && (v_EOL_calibRoutine_activeFlag == (boolean)FALSE))
    {
      if((NULL_PTR != ErrorCode) && ( NULL_PTR != Out_ResData ))
      {
      if(In_ReqData[0]==(uint8)e_ONE)
        {
        v_SC_calibRoutine_RearStarted = (uint8)e_ONE;
        v_SC_CalibRoutineType_u8=ENFORCED_CALIBRATION;
        l_DiagMgrOutputToSVSCamCalib.cameraMask.camFront = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camLeft = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camRear = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camRight = (uint8)e_ONE;

          l_DiagMgrOutputToSVSCamCalib.isRoutineRequested = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.calibType = CalibrationID2_SC;

          (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&l_DiagMgrOutputToSVSCamCalib, (uint16)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t, sizeof(l_DiagMgrOutputToSVSCamCalib));
          RIDM_RoutineStatus_5401_e = ACTIVE;
          /*SC calibration is running*/
        v_SC_calibRoutine_activeFlag =(boolean)TRUE ;
          
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          retvalue = RTE_E_OK;
          RESULT_5401_e = ROUTINE_ACTIVE;
        *Out_ResData = (uint8)RESULT_5401_e;
          v_CalibRoutineTriggered_b = TRUE;
          (void)Rte_Write_PpCalibRoutineTrigger_routine_b(v_CalibRoutineTriggered_b);
        }
        
      else if(In_ReqData[0]==(uint8)e_FIVE)   /*for rear camera*/
        {
        v_SC_calibRoutine_RearStarted = (uint8)e_FIVE;
        v_SC_CalibRoutineType_u8 =REAR_CAMERA_CALIBRATION;
        l_DiagMgrOutputToSVSCamCalib.cameraMask.camFront = (uint8)e_ZERO;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camLeft = (uint8)e_ZERO;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camRear = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.cameraMask.camRight = (uint8)e_ZERO;

          l_DiagMgrOutputToSVSCamCalib.isRoutineRequested = (uint8)e_ONE;
          l_DiagMgrOutputToSVSCamCalib.calibType = CalibrationID2_SC;

          (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&l_DiagMgrOutputToSVSCamCalib,(uint16) e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t, sizeof(l_DiagMgrOutputToSVSCamCalib));
          RIDM_RoutineStatus_5401_e = ACTIVE;
          /*SC calibration is running*/
        v_SC_calibRoutine_activeFlag = (boolean)TRUE ;
          
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          retvalue = RTE_E_OK;
          RESULT_5401_e = ROUTINE_ACTIVE;
        *Out_ResData = (uint8)RESULT_5401_e;
          v_CalibRoutineTriggered_b = TRUE;
          (void)Rte_Write_PpCalibRoutineTrigger_routine_b(v_CalibRoutineTriggered_b);
        }
        else
        {
          *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
          retvalue = RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK;
          RESULT_5401_e = ROUTINE_ABORTED;
        *Out_ResData = (uint8)RESULT_5401_e;
        }
          /*sending calibtype to caldataprovider*/
    (void)Rte_Write_PpCalibRoutineType_value(v_SC_CalibRoutineType_u8);
    }
      else
      {
        /* do nothing */
      }
    }
      else
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retvalue = RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK;
      }
  }
  else
  {
     *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      retvalue = RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK;
  }

  return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType* is of type Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
 /* DD-ID:{0A9DE013-2943-4c41-B3CA-970BC25A4970}*/
	Std_ReturnType retvalue;
	static boolean Request_Result_Read = (boolean)FALSE;
	TRSC_CalibrationClear_t TRSC_CalibrationClear_Data;
	TrailerDetection_Output_DID_t TrailerDetection_Output_RID_Data;
	(void)OpStatus;
	if ( (NULL_PTR != Out_ResData) && ( NULL_PTR != ErrorCode ))
	{
		if(RIDM_RoutineStatus_5502_e == ACTIVE)
		{
			(void)Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t(&TrailerDetection_Output_RID_Data);
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
			if((TrailerDetection_Output_RID_Data.IeTRSC_e_TrailerCalibMemClearResponse_t.bValid == (boolean)TRUE) || (Request_Result_Read == (boolean)TRUE) )
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
			{
				if(TrailerDetection_Output_RID_Data.IeTRSC_e_TrailerCalibMemClearResponse_t.CalibMemClearResponse ==(uint32) TeTRSC_e_Completed)
			{
        RIDM_RoutineStatus_5502_e = IDLE;
				Out_ResData[e_ZERO] = (uint8)ROUTINE_COMPLETED;
				Out_ResData[e_ONE] = 0x01u; /* TRSC memory Clear successful*/
			}
				else if(TrailerDetection_Output_RID_Data.IeTRSC_e_TrailerCalibMemClearResponse_t.CalibMemClearResponse == (uint32)TeTRSC_e_Abort)
			{
         RIDM_RoutineStatus_5502_e = IDLE;
				Out_ResData[e_ZERO] = (uint8)ROUTINE_ABORTED;
				Out_ResData[e_ONE] = 0x00u; /* TRSC memory Clear unsuccessful*/
			}
			else
			{     
				Out_ResData[e_ZERO] =(uint8) ROUTINE_ACTIVE;
				Out_ResData[e_ONE] = 0x00u; /* TRSC memory Clear still in progress*/
			}

				TRSC_CalibrationClear_Data.TRSC_Calib_Clear_Req = TeTRSC_e_Unknown;
				(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TRSC_CalibrationClear_Data, (uint16)e_IpcMsgId_Data_TRSC_CalibrationClear_t, (uint16)sizeof(TRSC_CalibrationClear_t));
				Request_Result_Read = (boolean)TRUE;
			}
			else
			{
				Out_ResData[e_ZERO] =(uint8) ROUTINE_ACTIVE;
				Out_ResData[e_ONE] = 0x00u; /* TRSC memory Clear still in progress*/
			}
			retvalue = RTE_E_OK;
		}
		else
		{
			*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
			retvalue = RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK;
		}
	}
	else
	{
		retvalue = RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK;
	}

	return retvalue;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start (returns application error)
 *********************************************************************************************************************/
  /* DD-ID:{4C75035A-9B55-43a4-8064-0D25C7C9776B}*/
	Std_ReturnType retvalue;
	TRSC_CalibrationClear_t TRSC_CalibrationClear_Data;
	(void)OpStatus;
	if(RIDM_RoutineStatus_5502_e != ACTIVE)
	{
		retvalue = RTE_E_OK;
    Out_ResData[e_ZERO] = (uint8)ROUTINE_ACTIVE;
		RIDM_RoutineStatus_5502_e = ACTIVE;
		TRSC_CalibrationClear_Data.TRSC_Calib_Clear_Req = TeTRSC_e_Clear;
		(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TRSC_CalibrationClear_Data, (uint16)e_IpcMsgId_Data_TRSC_CalibrationClear_t, (uint16)sizeof(TRSC_CalibrationClear_t));
	}
	else
	{
		retvalue = RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK;
	}
	return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start (returns application error)
 *********************************************************************************************************************/
	/*ReqID:-*/
	/*GUID:-{DCFEFE14-20DE-40b6-92A5-62DF9B2CE8A2}*/
  /* DD-ID: {CB05D9A1-BB45-439e-8D0A-BFE5790AF63E}*/
  Std_ReturnType v_retvalue_u8;
  (void)OpStatus;
	if((boolean)FALSE == s_Failsafe_ProhibitFlag_D001_b)
	{
		s_Failsafe_ProhibitFlag_D001_b = (boolean)TRUE;
    (void)Rte_Write_PpFailSafeReaction_State(s_Failsafe_ProhibitFlag_D001_b);
		v_retvalue_u8 = RTE_E_OK;
	}
	else
	{
	    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	    v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK;

	}
 
  return v_retvalue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-*/
 /*GUID:-{DCFEFE14-20DE-40b6-92A5-62DF9B2CE8A2}*/
  /* DD-ID: {DCFEFE14-20DE-40b6-92A5-62DF9B2CE8A2}*/
  Std_ReturnType v_retvalue_u8;
  (void)OpStatus;
  if (TRUE == s_Failsafe_ProhibitFlag_D001_b)
  {

		s_Failsafe_ProhibitFlag_D001_b = FALSE;
    (void)Rte_Write_PpFailSafeReaction_State(s_Failsafe_ProhibitFlag_D001_b);
		v_retvalue_u8 = RTE_E_OK;
  }
  else
  {
	    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	    v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK;
  }

  return v_retvalue_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, uint8 *Out_ResData, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Out_ResData: uint8* is of type Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(uint16, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start (returns application error)
 *********************************************************************************************************************/
/*ReqID:- 15266616,15306014,15382425,15267617,15266583,15266614,15267653,15267655,152676537651
              15267657,15267659,15267661,15267663,15267665,15267667,15267671,15461101*/
  /* DD-ID: {8C71F424-E9C9-465e-999D-C21B8816FFBF}*/
			  /*GUID:-*/
   Std_ReturnType v_RetVal_u8;
   ShiftLeverPosition v_GearPosition_u8;
   VehicleSpeedVSOSig v_VehicleSpd_u8;
   uint8  s_ProgCondIndex_u8 = (uint8)e_ZERO;
   uint8 v_Failed_PreCond_au8[e_SEVEN];
   uint8 v_ResponseBytesSize_u8;
   float32 v_BatteryVolage_f32;
   float32 v_Temp1Mon_f32;
   float32 v_Temp2Mon_f32;
  (void)OpStatus;
  (void)Out_ResData;
  (void)ErrorCode;
   
   /*Get Gear Position*/
  (void)Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(&v_GearPosition_u8);
   /*Get Vehicle Speed*/
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);
  /*Get Battery Value*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVolage_f32);
  /*Check ECU Temperature*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_TEMP1_MON, &v_Temp1Mon_f32);
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_TEMP2_MON, &v_Temp2Mon_f32);
/*If CAN signal is not available on BUS send positive response to pass programming preconditions*/ 
 
  if(NULL_PTR != Out_ResData)
  { 
    /*Check Vehicle Speed*/  
      if(v_VehicleSpd_u8 > (VehicleSpeedVSOSig)D_VEHICLE_SPEED_THRESHOLD)
      {
      s_ProgCondIndex_u8++; 
      v_Failed_PreCond_au8[s_ProgCondIndex_u8] = (uint8)D_VEHICLE_SPEED_FAULT_CODE;
      }
      else
      {
      /* Do Nothing */
      }
	  
      /*Check Low Battery Voltage */
      if(v_BatteryVolage_f32 < ((float32)D_LOW_VOL_THRESHOLD))
      {
      s_ProgCondIndex_u8++; 
      v_Failed_PreCond_au8[s_ProgCondIndex_u8] = (uint8)D_LOW_BAT_FAULT_CODE;
      }
      else
      {
      /* Do Nothing */
      }
	  
    	   /*Check High Battery Voltage */
      if(v_BatteryVolage_f32 > (float32)D_HIGH_VOL_THRESHOLD)
      {
      s_ProgCondIndex_u8++; 
      v_Failed_PreCond_au8[s_ProgCondIndex_u8] = (uint8)D_HIGH_BAT_FAULT_CODE;
      }
      else
      {
      /* Do Nothing */
      }
	 
      /*Check High ECU Temperature*/  
      if((v_Temp1Mon_f32 > (float32) D_HIGH_TEMP_THRESHOLD) || (v_Temp2Mon_f32 > (float32) D_HIGH_TEMP_THRESHOLD) )
      {
      s_ProgCondIndex_u8++; 
      v_Failed_PreCond_au8[s_ProgCondIndex_u8] = (uint8)D_HIGH_TEMP_FAULT_CODE;
      }
      else
      {
      /* Do Nothing */
      }
	  
	    /*Check Low ECU Temperature*/  
      if((v_Temp1Mon_f32 < (float32) D_LOW_TEMP_THRESHOLD) || (v_Temp2Mon_f32 < (float32) D_LOW_TEMP_THRESHOLD))
      {
      s_ProgCondIndex_u8++; 
      v_Failed_PreCond_au8[s_ProgCondIndex_u8] =(uint8)D_LOW_TEMP_FAULT_CODE;
      }
      else
      {
      /* Do Nothing */
      }
	  
	  /*Check Gear Position*/  
	   if((v_GearPosition_u8 != (uint8)e_ONE) && (v_GearPosition_u8 != (uint8)e_THREE))
	  {
		s_ProgCondIndex_u8++; 
		v_Failed_PreCond_au8[s_ProgCondIndex_u8] =(uint8)D_GEAR_CON_FAULT_CODE;
	  }
	  else
	  {
		/* Do Nothing */
	  }
	  
				if(s_ProgCondIndex_u8 == (uint8)e_ZERO)
				{
				  /*Send Programing Precondition Failed count */ 
				  v_Failed_PreCond_au8[e_ZERO] = s_ProgCondIndex_u8;
				  Out_ResData[e_ZERO] = v_Failed_PreCond_au8[e_ZERO];
				  *DataLength = D_ALL_CON_PASSED_DATA_LEN;
          v_RetVal_u8 = RTE_E_OK;
				}
				else
				{
				  v_Failed_PreCond_au8[e_ZERO] = s_ProgCondIndex_u8;
				  v_ResponseBytesSize_u8 = (uint8)(s_ProgCondIndex_u8 + (uint8)e_ONE);
				  /*Return Data Length */ 
				  *DataLength = v_ResponseBytesSize_u8;
				   /* Send Number of Programing Precondition Failed Error Codes */ 
				  Out_ResData[e_ZERO] = v_Failed_PreCond_au8[e_ZERO];
				  VStdLib_MemCpy(&Out_ResData[e_ONE], &v_Failed_PreCond_au8[e_ONE], sizeof(v_Failed_PreCond_au8));
          v_RetVal_u8 = RTE_E_OK;
				}
  }
  else
  {
    v_RetVal_u8 = RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_E_NOT_OK;
  }
   return v_RetVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(const Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-*/
  /*GUID:-*/
  /* DD-ID: {2144EED8-EC9C-443a-A504-1687AE385C93}*/

  Std_ReturnType retvalue = RTE_E_INVALID;

	VAR(TbSVS_S_SVSCamCalibReset_t,RTE_INIT)SVSCamCalibReset_t;
  TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t l_DiagMgrOutputToSVSCamCalib;
  (void)OpStatus;
  (void)Out_ResData;
  (void)memset((TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t *)&l_DiagMgrOutputToSVSCamCalib,0,sizeof(l_DiagMgrOutputToSVSCamCalib));

	if((NULL_PTR != ErrorCode))
	{
		switch(In_ReqData[e_ZERO])
			{
			case (uint8)e_ZERO:
			{
				SVSCamCalibReset_t.CalibrationID = CalibrationID_EOL; /*EOL calibration*/
			}
			break;
			case (uint8)e_ONE:
			{
				SVSCamCalibReset_t.CalibrationID = CalibrationID_SC; /* SC calibration*/
			}
			break;
			case (uint8)e_TWO:
			{
				SVSCamCalibReset_t.CalibrationID = CalibrationID_OC; /* OC calibration*/
			}
			break;
			case (uint8)e_THREE:
			{
				SVSCamCalibReset_t.CalibrationID = CalibrationID_Current; /*current camera calebration*/
			}
			break;
			default:
			{
				SVSCamCalibReset_t.CalibrationID = CalibrationID_EOL; /*EOL calibration*/
			}
			break;
			}

			if(In_ReqData[e_ONE] == ALL_CAMERA)
			{
				SVSCamCalibReset_t.CameraID = CameraID_All; /* All camera*/
			}
			else
			{
				SVSCamCalibReset_t.CameraID = In_ReqData[e_ONE];
			}

     l_DiagMgrOutputToSVSCamCalib.EraseCalibNVMData.EraseCalibType= SVSCamCalibReset_t.CalibrationID ;
     VStdLib_MemCpy(&l_DiagMgrOutputToSVSCamCalib.EraseCalibNVMData.EraseCamId,&In_ReqData[e_ONE],sizeof(uint8));
     l_DiagMgrOutputToSVSCamCalib.EraseCalibNVMData.isCalibResetRoutineEraseRequested= TRUE;

     (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&l_DiagMgrOutputToSVSCamCalib,(uint16)e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t,sizeof(l_DiagMgrOutputToSVSCamCalib));


			(void)Os_Call_RE_CalDataProvider_Nvm_SVSCamCalibReset(&SVSCamCalibReset_t);
  
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			retvalue = RTE_E_OK;
	}
	else
	{
		/* do nothing */
	}
	return retvalue;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(const Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-*/
 /*GUID:-*/
  /* DD-ID: {82A22920-22A4-4d12-92C4-FF701025C803}*/

 uint8 v_InData_au8[e_FIVE];
  DeviceAddress s_DeviceID_u8;
  uint16 v_RegAddress_u16;
  uint16 v_RegData_u16;
  Std_ReturnType v_retvalue_u8=RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK;
  uint8 v_retstatus_u8;
  (void)OpStatus;
  if((NULL_PTR != In_ReqData)) 
  {   
      VStdLib_MemCpy(v_InData_au8, In_ReqData, (uint32)e_FIVE); 
      s_DeviceID_u8 = v_InData_au8[e_ZERO];
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if (s_DeviceID_u8 <= (uint8)e_THREE) /*DeviceType = SBC/PMIC/COREPS*/
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
        v_RegAddress_u16 = (uint16)((uint16)((uint16)v_InData_au8[e_ONE] << (uint16)e_EIGHT) | (uint16)(v_InData_au8[e_TWO]));
        v_RegData_u16 = (uint16)((uint16)((uint16)v_InData_au8[e_THREE] << (uint16)e_EIGHT) | (uint16)(v_InData_au8[e_FOUR]));
        /* Return with routine completed */
        v_retstatus_u8 = Os_Call_RE_MCUWriteDeviceReg(s_DeviceID_u8, v_RegAddress_u16, v_RegData_u16);
        if (RTE_E_OK == v_retstatus_u8)
        {
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          v_retvalue_u8 = RTE_E_OK;
        }
        else
        {
          *ErrorCode = DCM_E_GENERALREJECT;
          v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK;
        }
      }      
      else
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK;
      }      
  }
  else
  {
    /* check NULL pointer */
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if(NULL_PTR == In_ReqData) /*PRQA S 2995, 2991*/
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
       *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
       *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK;
  }
  return v_retvalue_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(const Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start (returns application error)
 *********************************************************************************************************************/
 /*GUID:-*/
  /* DD-ID: {A189247F-C26E-4a6e-BC9C-59DC16FD5E59}*/
Std_ReturnType retvalue = RTE_E_INVALID;

DiagToSVS_t RID_Testpattern;
  (void)OpStatus;
  (void)Out_ResData;
/*Fill Request Structure with Values coming from External Tool */
RID_Testpattern.Camera_ID = In_ReqData[D_INDEX_0];
RID_Testpattern.TestPattern_ID = In_ReqData[D_INDEX_1];

/* Set Routine status to 1*/
RID_Testpattern.Routine_ID = D_ROUTINE_START;
RID_Testpattern.isRoutineStarted = D_ROUTINE_START;

if (((RID_Testpattern.Camera_ID > 0u) && (RID_Testpattern.Camera_ID <=5u)) && ((RID_Testpattern.TestPattern_ID >= 0u)  && (RID_Testpattern.TestPattern_ID <= 0x2u))) /*PRQA S 2995*/
{
	/* Send above information to other Core over IPC */
	(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&RID_Testpattern,(uint16) e_IpcMsgId_Data_DiagToSVS_t, sizeof(RID_Testpattern));
	if ((NULL_PTR != ErrorCode) && (NULL_PTR != Out_ResData))
	{
     RIDM_RoutineStatus_FE0E_e = ACTIVE;
	  *ErrorCode = DCM_E_POSITIVERESPONSE;
	  retvalue = RTE_E_OK;
	  Out_ResData[D_INDEX_0] = (uint8)RID_Testpattern.Camera_ID;
	  Out_ResData[D_INDEX_1] = (uint8)RID_Testpattern.TestPattern_ID;
	}
	else
	{
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      retvalue = RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK;
	}
}
else
{
	*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
	retvalue = RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK;
}

return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop (returns application error)
 *********************************************************************************************************************/
/*GUID:-*/
  /* DD-ID: {4F183828-A443-4a1b-B628-A960135314A9}*/
Std_ReturnType retvalue = RTE_E_INVALID;
DiagToSVS_t RID_Testpattern;

  /*Fill Test Pattern with value zero for Stopping the Routine */
  RID_Testpattern.TestPattern_ID = (uint32)D_STOP_TESTPATTERN;

  /* Set Routine status to 0*/
  RID_Testpattern.isRoutineStarted = (boolean)D_ROUTINE_STOP;

/* Send above information to other Core over IPC */
(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&RID_Testpattern, (uint16)e_IpcMsgId_Data_DiagToSVS_t, sizeof(RID_Testpattern));

if (NULL_PTR != ErrorCode)
{

  if (ACTIVE == RIDM_RoutineStatus_FE0E_e)
  {
    RIDM_RoutineStatus_FE0E_e = FORCED;
    retvalue = RTE_E_OK; /*After implement the Start RID function, it should be removed, it only used to keep return positive response */
  }
  else
  {
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
  }

  if (RTE_E_INVALID == retvalue)
  {
    /*excute Abnormally or Forced*/
    RIDM_RoutineStatus_FE0E_e = ABNORMALLY_FINISHED;
  }
  else
  {
    /* do nothing */
  }
}
else
{
  /* do nothing */
}
return retvalue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(const Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType *In_ReqData, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType* is of type Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType
 *     Argument Out_ResData: Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType* is of type Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-*/
 /*GUID:-*/
  /* DD-ID: {420FE9DA-2506-4775-9FAA-9682DEA1E1A5}*/

  uint8 v_InData_au8[e_THREE];
  uint8 v_OutData_au8[e_THREE];
  static uint8 s_FE01ReadPendingCounter_u8 = FALSE;
  static DeviceAddress s_DeviceID_u8 = (uint8)e_ZERO;
  uint16 v_RegAddress_u16;  
  uint16 v_RegData_u16;
  Std_ReturnType v_retvalue_u8=RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK;
  uint8 v_retstatus_u8;
  (void)OpStatus;
  (void)Out_ResData;
    
  /* Check precondition IG ON or Crank to accept request */
  if((NULL_PTR != In_ReqData)) 
  {
    if (FALSE == s_FE01ReadPendingCounter_u8)
    {
      VStdLib_MemCpy(v_InData_au8, In_ReqData, (uint32)e_THREE); 
      s_DeviceID_u8 = v_InData_au8[e_ZERO];
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if ((uint8)e_THREE >= s_DeviceID_u8) /*DeviceType = SBC/PMIC/COREPS*/
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
        v_RegAddress_u16 = (uint16)((uint16)((uint16)v_InData_au8[e_ONE] << (uint16)e_EIGHT) | (uint16)(v_InData_au8[e_TWO]));
        (void)Os_Call_RE_MCUReadDeviceReg(s_DeviceID_u8, v_RegAddress_u16);
        v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_PENDING;
        s_FE01ReadPendingCounter_u8 = TRUE;
      }      
      else
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK;
      }
    }
    else
    {      
        v_retstatus_u8 = Os_Call_RE_MCUReadDeviceRegData(s_DeviceID_u8, &v_RegData_u16);
        if (RTE_E_OK == v_retstatus_u8)
        {
          v_OutData_au8[e_ZERO] = (uint8)(RIGHTSHIFT_BIT((uint16)v_RegData_u16,(uint16)e_EIGHT));
          v_OutData_au8[e_ONE] = (uint8)CHECK_BIT(v_RegData_u16 , BIT_MASK);
          s_FE01ReadPendingCounter_u8 = FALSE;
          s_DeviceID_u8 = (uint8)e_ZERO;
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          VStdLib_MemCpy(Out_ResData, v_OutData_au8, (uint32)e_THREE);
          v_retvalue_u8 = RTE_E_OK;
        }
        else
        {
          if((uint8)D_RID_MAX_WAITCOUNT > s_FE01ReadPendingCounter_u8)
          {
            s_FE01ReadPendingCounter_u8++;
            v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK;
          }
          else
          {
            s_DeviceID_u8 = BIT_MASK;
            s_FE01ReadPendingCounter_u8 = FALSE;
            *ErrorCode = DCM_E_GENERALREJECT;
            v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK;
          }
        }           
    }
   }
   else
   {
     /* Check NULL pointer */
     /* VCAST Jenkins requirement - do not modify */
     /* VCAST Jenkins requirement - do not modify */
     if(NULL_PTR == In_ReqData) /*PRQA S 2995, 2991*/
     /* VCAST Jenkins requirement - do not modify */
     /* VCAST Jenkins requirement - do not modify */
     {
       *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
     }
     else
     {
       *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
     
     v_retvalue_u8 = RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK;
    }
   }
   return v_retvalue_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_RIDMgr_STOP_SEC_CODE
#include "SWC_RIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* ===========================================================================
 *
 *   Name: F_ConfigMgr_VINProcess
 *
 *   Function: VIN process checks of config manager
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */
static FUNC(void, SWC_ConfigMgr_CODE) F_ConfigMgr_VINProcess(void)
{
  /* DD-ID: {23D2189D-4C9F-40b5-82EB-AF9AAB172EDE}*/
  /*GUID:-{57A671D8-C0FD-42ef-AD11-E308DDEBE94E}*/
  uint8 v_u8LoopCntr_u8;
  uint8 v_LoopCntrLength_u8 = D_VIN_MSG_LEN;
  sint8 v_s8CompareStatus_s8 = (sint8)e_ZERO;
  uint8 v_u8VINMsgValue_u8 = FALSE;
  static uint8 s_VinSeqCnt_u8 = FALSE;
  static uint8 s_u8prevVINMsgValue_u8 = (uint8)e_TWO;
  NvM_RequestResultType v_BlockErrorStatus;
  static uint8 V_u8VINState_u8 = (uint8)CURR_VIN_LEARN;
  static uint8 V_a8VINCANData_au8[e_THREE][D_VIN_MSG_LEN] = {FALSE};
  static uint32 s_CurrentOdoValue_u32 = FALSE;
  static uint32 s_prevOdoValue_u32 = FALSE;

  switch (V_u8VINState_u8)
  {
    case (uint8)CURR_VIN_LEARN:
   
      /* acquire VIN value and check VIN data check */
      (void)Rte_Read_RpToSwcSafeFD02Rx_VIN_MSG(&v_u8VINMsgValue_u8);
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if(s_VinSeqCnt_u8 == (uint8)e_THREE)  /*check if all VIN data received in sequence*/
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
        s_VinSeqCnt_u8 = FALSE;          /*reset flag for new operation*/
        V_u8VINState_u8 = (uint8)CURR_VIN_UPDATE;     /*jump to next state*/
      }
      else if(v_u8VINMsgValue_u8 != s_u8prevVINMsgValue_u8) 
      {
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if((s_VinSeqCnt_u8 == v_u8VINMsgValue_u8) && (v_u8VINMsgValue_u8 <= D_FINAL_SEQUENCE_COUNTER))
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
          if(v_u8VINMsgValue_u8 == D_FINAL_SEQUENCE_COUNTER)
          {
            v_LoopCntrLength_u8 = D_VIN_MSG_LEN_HIGH;
          }
          (void)Rte_Read_RpToSwcSafeFD02Rx_VIN_DATA(&V_a8VINCANData_au8[v_u8VINMsgValue_u8][e_ZERO]);
          for(v_u8LoopCntr_u8 = FALSE; v_u8LoopCntr_u8<v_LoopCntrLength_u8; v_u8LoopCntr_u8++)
          {
            if(((V_a8VINCANData_au8[v_u8VINMsgValue_u8][v_u8LoopCntr_u8] >= D_ASCII_0) && (V_a8VINCANData_au8[v_u8VINMsgValue_u8][v_u8LoopCntr_u8] <= D_ASCII_9)) ||
            ((V_a8VINCANData_au8[v_u8VINMsgValue_u8][v_u8LoopCntr_u8] >= D_ASCIIA) && (V_a8VINCANData_au8[v_u8VINMsgValue_u8][v_u8LoopCntr_u8] <= D_ASCIIZ)))
            {
              s_VinSeqCnt_u8 = (uint8)(v_u8VINMsgValue_u8 + (uint8)e_ONE);
              s_u8prevVINMsgValue_u8 = (uint8)v_u8VINMsgValue_u8;
            }
            else
            {
              s_VinSeqCnt_u8 = FALSE;
              break;
            }
          }
        }
        else
        {
          s_VinSeqCnt_u8 = FALSE;
        }
      }
      else
      {
        /*Do nothing*/
      }
      break;
    case (uint8)CURR_VIN_UPDATE:
        /* compare currently Learn VIN and Stored learn are matches */
        v_s8CompareStatus_s8 = VStdLib_MemCmpLarge(Rte_Pim_VIN_CurrentVal_MirrorBlock(),&V_a8VINCANData_au8[e_ZERO][e_ZERO],D_VIN_MSG_SIZE);
        if(v_s8CompareStatus_s8 != (sint8)e_ZERO)
        {
          VStdMemCpy(Rte_Pim_VIN_CurrentVal_MirrorBlock(),&V_a8VINCANData_au8[e_ZERO][e_ZERO],D_VIN_MSG_SIZE);
          (void)Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_GetErrorStatus(&v_BlockErrorStatus);
          if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
          {
        	  (void)Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_WriteBlock(Rte_Pim_VIN_CurrentVal_MirrorBlock()); /* change PIM type to Immediate */
          }
        }
        else
        {
          /*Do nothing*/
        }
        V_u8VINState_u8 = (uint8)CHCK_VIN_LOCKSTATE;

      break;
    case (uint8)CHCK_VIN_LOCKSTATE:
      /* check if VIN already locked otherwise update Orignal VIN procedure */
      if (*Rte_Pim_VIN_Lock_MirrorBlock() == (uint8)VIN_NOT_LOCKED)
      {
        VStdMemCpy(Rte_Pim_VIN_OriginalVal_MirrorBlock(),Rte_Pim_VIN_CurrentVal_MirrorBlock(),D_VIN_MSG_SIZE);
        (void)Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_GetErrorStatus(&v_BlockErrorStatus);
        if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
        {
        	(void)Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_WriteBlock(Rte_Pim_VIN_OriginalVal_MirrorBlock());
        }
        V_u8VINState_u8 = (uint8)WAIT_FOR_VINLOCK;
        *Rte_Pim_VIN_OdometerCnt_MirrorBlock() = FALSE;  /* clear store odometer value to start from zero */
        (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&s_CurrentOdoValue_u32); /* Read current Odometer value */
        s_prevOdoValue_u32 = s_CurrentOdoValue_u32; /* reset to start odometer value counting from Zero */
      }
      else
      {
        V_u8VINState_u8 = (uint8)VIN_STATE_LASTINDEX;
      }
      break;
    case (uint8)WAIT_FOR_VINLOCK:
      if(*Rte_Pim_VIN_Lock_MirrorBlock()== (uint8)LOCK_BY_EXTERNAL_TOOL)
      {
        V_u8VINState_u8 = (uint8)VIN_STATE_LASTINDEX; /* Update VIN original by currently learn VIN */
      }
      else if(*Rte_Pim_VIN_OdometerCnt_MirrorBlock() >= D_VIN_MILEAGE_LOCK)
      {
        V_u8VINState_u8 = (uint8)VIN_STATE_LASTINDEX; /* Update VIN original by currently learn VIN */
        *Rte_Pim_VIN_Lock_MirrorBlock()= (uint8)LOCK_BY_ODOMETER_VALUE;
        (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_GetErrorStatus(&v_BlockErrorStatus);
        if((NvM_RequestResultType)NVM_REQ_PENDING != v_BlockErrorStatus)
        {
            (void)Rte_Call_NvMService_AC3_SRBS_VIN_Lock_WriteBlock(Rte_Pim_VIN_Lock_MirrorBlock());
        }
      }
      else 
      {
        (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&s_CurrentOdoValue_u32); /* Read current Odometer value */
        if(s_prevOdoValue_u32 < s_CurrentOdoValue_u32)  /* check if Odo value is greated than previous value */
        {
          *Rte_Pim_VIN_OdometerCnt_MirrorBlock() += (uint8)(s_CurrentOdoValue_u32-s_prevOdoValue_u32);
        } 
        s_prevOdoValue_u32 = s_CurrentOdoValue_u32;
        (void)Rte_Call_NvMService_AC3_SRBS_VIN_OdometerCnt_SetRamBlockStatus(TRUE);
      }
      break;
    case (uint8)VIN_STATE_LASTINDEX:
      /*Do Nothing*/
      break;
    default:
      /*Do Nothing*/
      break;
  }
}
/* ===========================================================================
 *
 *   Name: F_EOL_CalibrationPreconditionCheck
 *
 *   Function:EOL_CalibrationPreconditionCheck
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */

static FUNC(Std_ReturnType, SWC_RIDMgr_CODE) F_EOL_CalibrationPreconditionCheck(void)
{
  /* DD-ID: {E2DCF721-57B7-4cd8-B126-79DF389BB688}*/
  Dem_UdsStatusByteType v_DTCStatus;
  Std_ReturnType v_retval;
  uint8 v_DTCFault_u8[e_EIGHT] = {0u};
  uint8 v_idx_u8 = (uint8)e_ZERO;

  CmdIgnSts CmdIgnStatus;
  DriverDoorSts DriverDoorStatus;
  LHRDoorSts LHRDoorStatus;
  PsngrDoorSts PsngrDoorStatus;
  RHRDoorSts RHRDoorStatus;
  RHatchSts RHatchStatus;
  ShiftLeverPosition ShiftLeverPos;
  boolean CalibPrecondition1;
  boolean CalibPrecondition2;
  boolean CalibPrecondition3;
  boolean CalibPrecondition4;
  boolean CalibPrecondition5;
  boolean CalibPrecondition6;
  boolean CalibPrecondition7;
  boolean CalibPrecondition8;
  FD14_LwsAngle LwsAngle1;
  float32 ConLwsAngle;
  VehicleSpeedVSOSig v_VehicleSpd_u8;
  ASCM_Stat v_ASCM_Stat_u8;
  boolean v_CanNod27_b;
  float32 v_BatteryVoltageValue_f32;
  uint8 v_CameraVariant_u8;

   (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&CmdIgnStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts(&DriverDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts(&LHRDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts(&PsngrDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts(&RHRDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_RHatchSts(&RHatchStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(&ShiftLeverPos);
   (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(&LwsAngle1);
   (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);
   (void)Rte_Read_RpToSwcSafeFD02Rx_ASCM_Stat(&v_ASCM_Stat_u8);
   (void)Rte_Read_RpProxiToSWC_PRX_CanNod27_b(&v_CanNod27_b);
   (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVoltageValue_f32);
   (void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_CameraVariant_u8);

  /*Check LwsAngle signale of EPS_FD_1 message*/
  /*conversion formula for 10 degree (LwsAngle= ((10+720)/0.1)= 730/0.1 = 7300)*/

   ConLwsAngle= (((float32)LwsAngle1 * D_LWSANGLE_FACTOR) - (float32)D_LWSANGLE_OFFSET);
  
   if((ConLwsAngle > D_LWSANGLE_HIGH_THR) || (ConLwsAngle < D_LWSANGLE_LOW_THR))
   {
     CalibPrecondition1 = TRUE;
   }
   else
   {
    CalibPrecondition1 = FALSE;
   }

   /*Check doors status of BCM_FD_9 message*/
   if((DriverDoorStatus ==(uint8)e_ONE) || (PsngrDoorStatus == (uint8)e_ONE) || (LHRDoorStatus == (uint8)e_ONE) || (RHRDoorStatus == (uint8)e_ONE) || (RHatchStatus == (uint8)e_ONE))
   {
     CalibPrecondition2 = TRUE;
   }
   else
   {
     CalibPrecondition2 = FALSE;
   }

   /*Check command ingition status for BCM_FD_10 message*/
   if((CmdIgnStatus != Cx4_RUN) && (CmdIgnStatus != Cx5_START))
   {
     CalibPrecondition3 = TRUE;
   }
   else
    {
      CalibPrecondition3 = FALSE;
    }
     /*Check DTCs status*/
     if(v_CameraVariant_u8 != SINGLE_CAM_VARIANT)
     {
        (void)Rte_Call_RpEventDTC_U026500_GetEventStatus(&v_DTCStatus); //Lost Communication with Front Camera
        v_DTCFault_u8[e_ONE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_U026600_GetEventStatus(&v_DTCStatus); //Lost Communication with Left Camera
        v_DTCFault_u8[e_TWO] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_U026700_GetEventStatus(&v_DTCStatus); //Lost Communication with Right Camera
        v_DTCFault_u8[e_THREE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C592_GetEventStatus(&v_DTCStatus); //Front Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_FIVE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C692_GetEventStatus(&v_DTCStatus); //Left Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_SIX] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C792_GetEventStatus(&v_DTCStatus); //Right Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_SEVEN] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
     }
     else
     {
        /*Front, Left Right camera DTCs status are zero*/
     }
        (void)Rte_Call_RpEventDTC_U026400_GetEventStatus(&v_DTCStatus);  //Lost Communication with Rear Camera 
        v_DTCFault_u8[e_ZERO] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B217A92_GetEventStatus(&v_DTCStatus);  //Rear Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_FOUR] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK)); 
  
  
  for(v_idx_u8 = (uint8)e_ZERO;v_idx_u8 < (uint8)e_EIGHT;v_idx_u8++)
  {
    if(v_DTCFault_u8[v_idx_u8] == D_DTC_TF_STATUS_MASK)
    {
     CalibPrecondition4 = TRUE;   
	   break;  
    }
    else
    {
      CalibPrecondition4 = FALSE;     
    }
  }

  /*check shiftleverPosition from TRANSM_FD_4 message*/
  if(ShiftLeverPos != (uint8)e_ONE)
  {
    CalibPrecondition5 = TRUE;
  }
  else
  {
    CalibPrecondition5 = FALSE;
  }

  /*Vehicle speed*/
  if(v_VehicleSpd_u8 >(uint8)e_ZERO)
  {
    CalibPrecondition6 = TRUE;
  }
  else
  {
    CalibPrecondition6 = FALSE;
  }
  
  /*ASCM condition*/
  if(D_ASCM_PRESENT == v_CanNod27_b)
  {
    /* Defect-21207628:
    * New Requirement 
    * The pre-condition should be ASCM_Stat=NVL/default.
    * If ASCM_Stat != NVL, conditions are not correct to start service calibration on vehicles equipped with air suspension (i.e. CAN Node 27 (ASM/ASCM) = Present)
    */ 
    if(D_ASCM_Stat_NVL == v_ASCM_Stat_u8)
    {
      CalibPrecondition7 = FALSE;
    }
    else
    {
      CalibPrecondition7 = TRUE;
    }
  }
  else
  {
    CalibPrecondition7 = FALSE;
  }

  /*battery voltage */
  if((v_BatteryVoltageValue_f32 < 9.0f) || (v_BatteryVoltageValue_f32 > 16.0f))
  {
    CalibPrecondition8 = TRUE;    
  }
  else
  {
    CalibPrecondition8 = FALSE;
  }

  if((CalibPrecondition1 == TRUE) || (CalibPrecondition2 == TRUE) || (CalibPrecondition3 == TRUE) || (CalibPrecondition4 == TRUE) || (CalibPrecondition5 == TRUE) || (CalibPrecondition6 == TRUE) || (CalibPrecondition7 == TRUE) || (CalibPrecondition8 == TRUE))
  {
    v_retval = E_NOT_OK;
  }
  else
  {
    v_retval = E_OK;
  }
  return v_retval;
}

/* ===========================================================================
 *
 *   Name: F_SC_CalibrationPreconditionCheck
 *
 *   Function: SC_CalibrationPreconditionCheck
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */

static FUNC(Std_ReturnType, SWC_ConfigMgr_CODE) F_SC_CalibrationPreconditionCheck(void)
{
  /* DD-ID: {BFD13152-07C2-4ec8-959B-ABBEE5ECF2FD}*/
  Dem_UdsStatusByteType v_DTCStatus;
  Std_ReturnType v_retval;
  uint8 v_DTCFault_u8[e_EIGHT] = {0u};
  uint8 v_idx_u8 = (uint8)e_ZERO;

  CmdIgnSts CmdIgnStatus;
  DriverDoorSts DriverDoorStatus;
  LHRDoorSts LHRDoorStatus;
  PsngrDoorSts PsngrDoorStatus;
  RHRDoorSts RHRDoorStatus;
  RHatchSts RHatchStatus;
  boolean CalibPrecondition1;
  boolean CalibPrecondition2;
  boolean CalibPrecondition3;
  boolean CalibPrecondition4;
  boolean CalibPrecondition5;
  boolean CalibPrecondition6;
  boolean CalibPrecondition7;
  boolean CalibPrecondition8;
  boolean v_CanNod27_b;
  ASCM_Stat v_ASCM_Stat_u8;
  FD14_LwsAngle LwsAngle1;
  float32 ConLwsAngle;
  GearEngaged v_GearEngaged_u8;
  float32 v_BatteryVoltageValue_f32;
  VehicleSpeedVSOSig v_VehicleSpd_u8;
  uint8 v_CameraVariant_u8;
  
   (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&CmdIgnStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts(&DriverDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts(&LHRDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts(&PsngrDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts(&RHRDoorStatus);
   (void)Rte_Read_RpToSwcSafeFD02Rx_RHatchSts(&RHatchStatus);
   (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(&LwsAngle1);
   (void)Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(&v_GearEngaged_u8);
   (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVoltageValue_f32);
   (void)Rte_Read_RpToSwcSafeFD02Rx_ASCM_Stat(&v_ASCM_Stat_u8);
   (void)Rte_Read_RpProxiToSWC_PRX_CanNod27_b(&v_CanNod27_b);
   (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);
   (void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_CameraVariant_u8);
   
  /*Check LwsAngle signale of EPS_FD_1 message*/
  /*conversion formula for 10 degree (LwsAngle= ((10+720)/0.1)= 730/0.1 = 7300)*/
    ConLwsAngle= (((float32)LwsAngle1 * D_LWSANGLE_FACTOR) - (float32)D_LWSANGLE_OFFSET);
  
   if((ConLwsAngle > D_LWSANGLE_HIGH_THR) || (ConLwsAngle < D_LWSANGLE_LOW_THR))
   {
     CalibPrecondition1 = TRUE;
   }
   else
   {
    CalibPrecondition1 = FALSE;
   }

   /*Check doors status of BMC_FD_9 message*/
   if((DriverDoorStatus ==(uint8)e_ONE) || (PsngrDoorStatus == (uint8)e_ONE) || (LHRDoorStatus == (uint8)e_ONE) || (RHRDoorStatus == (uint8)e_ONE) || (RHatchStatus == (uint8)e_ONE))
   {
     CalibPrecondition2 = TRUE;
   }
   else
   {
     CalibPrecondition2 = FALSE;
   }

   /*Check command ingition status for BCM_FD_10 message*/
   if((CmdIgnStatus != Cx4_RUN) && (CmdIgnStatus != Cx5_START))
   {
     CalibPrecondition3 = TRUE;
   }
   else
    {
      CalibPrecondition3 = FALSE;
    }
     /*Check DTCs status*/
     if(v_CameraVariant_u8 != SINGLE_CAM_VARIANT)
     {
        (void)Rte_Call_RpEventDTC_U026500_GetEventStatus(&v_DTCStatus); //Lost Communication with Front Camera
        v_DTCFault_u8[e_ONE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_U026600_GetEventStatus(&v_DTCStatus); //Lost Communication with Left Camera
        v_DTCFault_u8[e_TWO] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_U026700_GetEventStatus(&v_DTCStatus); //Lost Communication with Right Camera
        v_DTCFault_u8[e_THREE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C592_GetEventStatus(&v_DTCStatus); //Front Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_FIVE] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C692_GetEventStatus(&v_DTCStatus); //Left Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_SIX] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B23C792_GetEventStatus(&v_DTCStatus); //Right Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_SEVEN] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
     }
     else
     {
        /*Front, Left Right camera DTCs status are zero*/
     }
        (void)Rte_Call_RpEventDTC_U026400_GetEventStatus(&v_DTCStatus);  //Lost Communication with Rear Camera 
        v_DTCFault_u8[e_ZERO] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
        (void)Rte_Call_RpEventDTC_B217A92_GetEventStatus(&v_DTCStatus);  //Rear Camera - Performance or Incorrect Operation
        v_DTCFault_u8[e_FOUR] = ((v_DTCStatus) & (D_DTC_TF_STATUS_MASK));
  
  
  for(v_idx_u8 = (uint8)e_ZERO;v_idx_u8 < (uint8)e_EIGHT;v_idx_u8++)
  {
    if(v_DTCFault_u8[v_idx_u8] == D_DTC_TF_STATUS_MASK)
    {
     CalibPrecondition4 = TRUE;   
	   break;  
    }
    else
    {
      CalibPrecondition4 = FALSE;     
    }
  }

  /*transm_fd_4::IF Gear position is in reverse and signal is not valid that is 0xf*/
  if(v_GearEngaged_u8 >=(uint8)0x0E)
  {
    CalibPrecondition5 = TRUE;  
  }
  else
  {
    CalibPrecondition5 = FALSE;
  }
  
  /*battery voltage */
  if((v_BatteryVoltageValue_f32 < D_VOL_LOW_RANGE) || (v_BatteryVoltageValue_f32 > D_VOL_HIGH_RANGE))
  {
    CalibPrecondition6 = TRUE;    
  }
  else
  {
    CalibPrecondition6 = FALSE;
  }

  /*ASCM condition*/
  if(D_ASCM_PRESENT == v_CanNod27_b)
  {
    /* Defect-21207628:
    * New Requirement 
    * The pre-condition should be ASCM_Stat=NVL/default.
    * If ASCM_Stat != NVL, conditions are not correct to start service calibration on vehicles equipped with air suspension (i.e. CAN Node 27 (ASM/ASCM) = Present)
    */ 
    if(D_ASCM_Stat_NVL == v_ASCM_Stat_u8)
    {
      CalibPrecondition7 = FALSE;
    }
    else
    {
      CalibPrecondition7 = TRUE;
    }
  }
  else
  {
    CalibPrecondition7 = FALSE;
  }

  /*Vehical speed*/
  if(v_VehicleSpd_u8 >(uint8)e_ZERO)
  {
    CalibPrecondition8 = TRUE;
  }
  else
  {
    CalibPrecondition8 = FALSE;
  }
  /* VCAST Jenkins requirement - do not modify */
  /* VCAST Jenkins requirement - do not modify */
  if((CalibPrecondition1 == TRUE) || (CalibPrecondition2 == TRUE) || (CalibPrecondition3 == TRUE) || (CalibPrecondition4 == TRUE) || (CalibPrecondition5 == TRUE) || (CalibPrecondition6 == TRUE) || (CalibPrecondition7 == TRUE) || (CalibPrecondition8 == TRUE))
  /* VCAST Jenkins requirement - do not modify */
  /* VCAST Jenkins requirement - do not modify */
  {
    v_retval = E_NOT_OK;
  }
  else
  {
    v_retval = E_OK;
  }
  return v_retval;
}

/* ===========================================================================
 *
 *   Name: F_ProgrammingPreconditionCheck
 *
 *   Function:  This function is to verify the preconditions to jump in programming session 10 02 
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: Requirement: 22873258
 *
 * ========================================================================= */

static FUNC(void, SWC_RIDMgr_CODE) F_ProgrammingPreconditionCheck(void)
{
  /*DD-ID:{134E0AC6-83E7-401d-A474-000DEEF06E45}*/
  ShiftLeverPosition v_GearPosition_u8;
  VehicleSpeedVSOSig v_VehicleSpd_u8;
  float32 v_BatteryVolage_f32;
  float32 v_Temp1Mon_f32;
  float32 v_Temp2Mon_f32;

  /*Get Gear Position*/
  (void)Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(&v_GearPosition_u8);
  /*Get Vehicle Speed*/
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u8);
  /*Get Battery Value*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVolage_f32);
  /*Check ECU Temperature*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_TEMP1_MON, &v_Temp1Mon_f32);
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_TEMP2_MON, &v_Temp2Mon_f32);

  if (((VehicleSpeedVSOSig)D_VEHICLE_SPEED_THRESHOLD < v_VehicleSpd_u8) ||
      (((float32)D_LOW_VOL_THRESHOLD) > v_BatteryVolage_f32) ||
      ((float32)D_HIGH_VOL_THRESHOLD < v_BatteryVolage_f32) ||
      (((float32)D_HIGH_TEMP_THRESHOLD < v_Temp1Mon_f32) || ((float32)D_HIGH_TEMP_THRESHOLD < v_Temp2Mon_f32)) ||
      (((float32)D_LOW_TEMP_THRESHOLD > v_Temp1Mon_f32) || ((float32)D_LOW_TEMP_THRESHOLD > v_Temp2Mon_f32)) ||
      (((uint8)e_ONE != v_GearPosition_u8) && ((uint8)e_THREE != v_GearPosition_u8))) 
      {
        /*Write mode port of ProgPreconditionCheck as ProgPreconditionState_StateNotOK so DCM will send NRC 0x22 for SID 10 02*/
        (void)Rte_Switch_PpModeProgPreconditionCheck_ModeProgPreconditionCheck(RTE_MODE_ProgPreconditionState_StateNotOK);
      } 
      else 
      {
        /*Write mode port of ProgPreconditionCheck as ProgPreconditionState_StateOK*/
        (void)Rte_Switch_PpModeProgPreconditionCheck_ModeProgPreconditionCheck(RTE_MODE_ProgPreconditionState_StateOK);
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
