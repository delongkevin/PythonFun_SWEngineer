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
 *             File:  SWC_SafeVCANRx.c
 *           Config:  D:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_SafeVCANRx
 *  Generation Time:  2025-11-04 13:24:59
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_SafeVCANRx>
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
 * AUXCamsRQSts
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
 * Alert_CHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Alert_CHR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Alert_LHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Alert_LHR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Alert_RHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Alert_RHR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Altitude_RMSE_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * Battery_Volt_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * CRC_ADAS_INFO_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_AGSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM10
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM12
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM27
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM29
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BCM9
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE2_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_BRAKE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_CVPAM_FD_Control
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_CVPAM_FD_Data
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_CVPAM_FD_Data2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_CVPAM_FD_Info
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_ENGINE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_ENGINE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_ENGINE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_EPS1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_EPS2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_GLOB_NAV_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_TRANSM1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_TRANSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_TRANSM4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_TRSCM1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_TRSKM_FD_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_Telematic11
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_Telematic14
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC_Telematic5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC__BRAKE3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CRC__DRIVETRAIN3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CameraDisplaySts2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ChimeActivation_LHF
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * ChimeActivation_LHR
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * ChimeActivation_RHF
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * ChimeActivation_RHR
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CmdIgnSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Cntr_CVPAM_FD_Data
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Cntr_CVPAM_FD_Data2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * CurrentCanNMState_FD02_PAM
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
 * CurrentFailSts_FD02_PAM
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
 * DES_FD02_PAM
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
 * DeltaTimestamp_IMUdata
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
 * Digit_01_PAM
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
 * Digit_02_PAM
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
 * Digit_03_PAM
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
 * Digit_04_PAM
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
 * Digit_05_PAM
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
 * Digit_06_PAM
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
 * Digit_07_PAM
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
 * Digit_08_PAM
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
 * Digit_09_PAM
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
 * Digit_10_PAM
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
 * Digit_11_PAM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DisplayView2
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
 * E2E_MEP_CheckStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * E2E_MEP_DataIDMode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * EOL_FD02_PAM
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
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ExternalTemperature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_ACC_Systemsts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Accel_Pedal_Override
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * FD14_BrkTrq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_BrkTrq_Driver
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Brk_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_ADAS_FD_INFO
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_BRAKE1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_BRAKE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_BRAKE4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_BRAKE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_BRAKE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_CVPAM_FD_Control
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_CVPAM_FD_Data
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_CVPAM_FD_Data2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_ENGINE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_ENGINE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_EPS1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC_EPS2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_CRC__BRAKE3
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
 * FD14_DriverReq_AxleTrq_Enabled_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * FD14_IeTRSC_M_TRSCStrTrq
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
 * FD14_IeTRSC_deg_FrntWhlAng
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
 * FD14_IeTRSC_deg_JackknifeThrAngle
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
 * FD14_IeTRSC_deg_TADAngle
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
 * FD14_IeTRSC_deg_TrlrAngKnob
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
 * FD14_IeTRSC_kph_VehSpeedVSOSig
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
 * FD14_IeTRSC_m_TrlrWhlBaseEff
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
 * FD14_IeTRSC_pct_TrlrDetConf
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
 * FD14_IeTRSC_pct_TrlrRecogConf
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
 * FD14_IeTRSC_pct_TrlrTrackConf
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
 * FD14_IeVBII_nfcd_MinDisToCollisionObj
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
 * FD14_JackknifeAngle
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
 * FD14_JackknifeThrAngle
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
 * FD14_LHFWheelSpeed
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
 * FD14_LHRWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_LMD_m_Line_1_End_Range
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
 * FD14_LMD_m_Line_1_Offset
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
 * FD14_LMD_m_Line_1_Start_Range
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
 * FD14_LMD_m_Line_2_End_Range
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
 * FD14_LMD_m_Line_2_Offset
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
 * FD14_LMD_m_Line_2_Start_Range
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
 * FD14_LMD_m_Line_3_End_Range
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
 * FD14_LMD_m_Line_3_Offset
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
 * FD14_LMD_m_Line_3_Start_Range
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
 * FD14_LMD_m_Line_4_End_Range
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
 * FD14_LMD_m_Line_4_Offset
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
 * FD14_LMD_m_Line_4_Start_Range
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
 * FD14_LMD_m_Segment_1_X1
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
 * FD14_LMD_m_Segment_1_X2
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
 * FD14_LMD_m_Segment_1_Y1
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
 * FD14_LMD_m_Segment_1_Y2
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
 * FD14_LMD_m_Segment_2_X1
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
 * FD14_LMD_m_Segment_2_X2
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
 * FD14_LMD_m_Segment_2_Y1
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
 * FD14_LMD_m_Segment_2_Y2
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
 * FD14_LMD_m_Segment_3_X1
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
 * FD14_LMD_m_Segment_3_X2
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
 * FD14_LMD_m_Segment_3_Y1
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
 * FD14_LMD_m_Segment_3_Y2
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
 * FD14_LMD_m_Segment_4_X1
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
 * FD14_LMD_m_Segment_4_X2
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
 * FD14_LMD_m_Segment_4_Y1
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
 * FD14_LMD_m_Segment_4_Y2
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
 * FD14_LMD_m_Segment_5_X1
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
 * FD14_LMD_m_Segment_5_X2
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
 * FD14_LMD_m_Segment_5_Y1
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
 * FD14_LMD_m_Segment_5_Y2
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
 * FD14_LMD_m_Segment_6_X1
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
 * FD14_LMD_m_Segment_6_X2
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
 * FD14_LMD_m_Segment_6_Y1
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
 * FD14_LMD_m_Segment_6_Y2
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
 * FD14_LMD_m_Segment_7_X1
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
 * FD14_LMD_m_Segment_7_X2
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
 * FD14_LMD_m_Segment_7_Y1
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
 * FD14_LMD_m_Segment_7_Y2
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
 * FD14_LMD_m_Segment_8_X1
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
 * FD14_LMD_m_Segment_8_X2
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
 * FD14_LMD_m_Segment_8_Y1
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
 * FD14_LMD_m_Segment_8_Y2
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
 * FD14_LMD_pct_Line_1_Confidence
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
 * FD14_LMD_pct_Line_2_Confidence
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
 * FD14_LMD_pct_Line_3_Confidence
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
 * FD14_LMD_pct_Line_4_Confidence
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
 * FD14_LMD_pct_Segment_1_Confidence
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
 * FD14_LMD_pct_Segment_2_Confidence
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
 * FD14_LMD_pct_Segment_3_Confidence
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
 * FD14_LMD_pct_Segment_4_Confidence
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
 * FD14_LMD_pct_Segment_5_Confidence
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
 * FD14_LMD_pct_Segment_6_Confidence
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
 * FD14_LMD_pct_Segment_7_Confidence
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
 * FD14_LMD_pct_Segment_8_Confidence
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
 * FD14_LMD_px_Line_1_Curvature
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
 * FD14_LMD_px_Line_2_Curvature
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
 * FD14_LMD_px_Line_3_Curvature
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
 * FD14_LMD_px_Line_4_Curvature
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
 * FD14_LMD_rad_Line_1_Heading
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
 * FD14_LMD_rad_Line_2_Heading
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
 * FD14_LMD_rad_Line_3_Heading
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
 * FD14_LMD_rad_Line_4_Heading
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
 * FD14_LatAcceleration_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_1_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_1_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_1_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_1_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_1_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_1_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_1_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_2_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_2_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_2_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_2_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_2_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_2_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_2_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_3_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_3_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_3_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_3_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_3_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_3_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_3_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_4_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_4_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_4_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_4_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Line_4_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_4_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Line_4_Start_Range
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
 * FD14_LongAcceleration_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_LwsSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_MaAP_m_ParkSpot1FrntStreetX
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
 * FD14_MaAP_m_ParkSpot1FrntStreetY
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
 * FD14_MaAP_m_ParkSpot2FrntBorderX
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
 * FD14_MaAP_m_ParkSpot2FrntBorderY
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
 * FD14_MaAP_m_ParkSpot3RearBorderX
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
 * FD14_MaAP_m_ParkSpot3RearBorderY
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
 * FD14_MaAP_m_ParkSpot4RearStreetX
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
 * FD14_MaAP_m_ParkSpot4RearStreetY
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
 * FD14_ManoeuvrePhase
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_MeTHA_deg_CplrAng
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
 * FD14_MeTHA_deg_RoadWhlAng
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
 * FD14_MeTRSC_M_SteeringTorqInfo
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
 * FD14_MeTRSC_deg_DetJackKnifeAngle
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
 * FD14_MeTRSC_deg_DetJackknifeThrAngle
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
 * FD14_MeTRSC_deg_JackKnifeAngle
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
 * FD14_MeTRSC_deg_JackknifeThrAngle
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
 * FD14_MeTRSC_deg_MaxAllowedTADAngle
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
 * FD14_MeTRSC_deg_TADAngle
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
 * FD14_MeTRSC_deg_TADAngleRate
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
 * FD14_MeTRSC_m_DetTrailerBeamLen
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
 * FD14_MeTRSC_m_HitchLength
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
 * FD14_MeTRSC_m_TrailerBeamLen
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
 * FD14_MessageCounter_ADAS_FD_INFO
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_BRAKE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_CVPAM_FD_Control
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_CVPAM_FD_Data
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_CVPAM_FD_Data2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_ENGINE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_ENGINE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_EPS1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_MessageCounter_EPS2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_NFCD_DistanceToClosestPoint_0_0
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
 * FD14_NFCD_DistanceToClosestPoint_0_1
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
 * FD14_NFCD_DistanceToClosestPoint_0_2
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
 * FD14_NFCD_DistanceToClosestPoint_0_3
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
 * FD14_NFCD_DistanceToClosestPoint_0_4
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
 * FD14_NFCD_DistanceToClosestPoint_0_5
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
 * FD14_NFCD_DistanceToClosestPoint_0_6
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
 * FD14_NFCD_DistanceToClosestPoint_0_7
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
 * FD14_NFCD_DistanceToClosestPoint_0_8
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
 * FD14_NFCD_DistanceToClosestPoint_0_9
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
 * FD14_NFCD_DistanceToClosestPoint_1_0
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
 * FD14_NFCD_DistanceToClosestPoint_1_1
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
 * FD14_NFCD_DistanceToClosestPoint_1_2
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
 * FD14_NFCD_DistanceToClosestPoint_1_3
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
 * FD14_NFCD_DistanceToClosestPoint_1_4
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
 * FD14_NFCD_DistanceToClosestPoint_1_5
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
 * FD14_NFCD_DistanceToClosestPoint_1_6
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
 * FD14_NFCD_DistanceToClosestPoint_1_7
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
 * FD14_NFCD_DistanceToClosestPoint_1_8
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
 * FD14_NFCD_DistanceToClosestPoint_1_9
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
 * FD14_PAM_Brk_Rq_RspSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Front_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Lane_Dection_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Left_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_LM_Color
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_LM_Distance
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Line_LM_Distance_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_LM_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Line_LM_Heading_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_LM_Style
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_RM_Color
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_RM_Distance
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Line_RM_Distance_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_RM_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Line_RM_Heading_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Line_RM_Style
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj1_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj1_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj1_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj1_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj1_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj1_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj2_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj2_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj2_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj2_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj2_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj2_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj3_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj3_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj3_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj3_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj3_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj3_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj4_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj4_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj4_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj4_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj4_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj4_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj5_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj5_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj5_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj5_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj5_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj5_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj6_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj6_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj6_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Obj6_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj6_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_Obj6_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_Right_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_SideSensor_FrontLeft_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_SideSensor_FrontLeft_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_SideSensor_FrontRight_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_SideSensor_FrontRight_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_SideSensor_RearLeft_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_SideSensor_RearLeft_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PA_SideSensor_RearRight_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PA_SideSensor_RearRight_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PPPA_AccelMax
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_AccelMin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_DecelMax
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_DecelMin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_Interface_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_JerkAccelMax
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_JerkAccelMin
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_JerkDecelMax
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_PPPA_JerkDecelMin
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
 * FD14_PPPA_StandstillRqst
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_PPPA_TargetDistance
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_PPPA_TrqEnblRq_Allowed
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_ParkingGearShiftReq
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
 * FD14_ParkingManeuverActive
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
 * FD14_REF_VEH_SPEED
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_RHFWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_RHRWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_RR_PAM_Brk_RqSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_RR_PAM_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_SPM_Lat_Ctrl_RequestSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_SPM_Lat_Ctrl_ResponseSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_1_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_1_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_1_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_1_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_1_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_2_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_2_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_2_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_2_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_2_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_3_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_3_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_3_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_3_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_3_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_4_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_4_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_4_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_4_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_4_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_5_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_5_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_5_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_5_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_5_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_6_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_6_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_6_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_6_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_6_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_7_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_7_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_7_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_7_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_7_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_8_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Segment_8_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_8_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_8_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Segment_8_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Slope
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Steering_Column_Torque
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_TADAngleRate
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
 * FD14_THA_EPB_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_THA_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_THA_SpeedLimit_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_THA_Speed_Limit
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
 * FD14_THA_SteeringTorqueInfo
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_THA_SteeringTorqueReq
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
 * FD14_TRSC_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_TRSC_SpeedLimit_Req
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
 * FD14_TRSC_SteeringTorqueInfo
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_TRSC_SteeringTorqueReq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_TRSC_VehicleStop_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_TorqueOverlaySteeringReq_SPM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FIL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FIL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FIR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FIR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FOL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FOL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FOR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FOR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FSL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FSL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FSR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_FSR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RIL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RIL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RIR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RIR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_ROL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_ROL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_ROR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_ROR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RSL_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RSL_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RSR_DrvFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Tstr_SD_RSR_RingFreq
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_VehicleSpeedVSOSig
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_VehicleSpeedVSOSig_B2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_YawRate_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_hitchLength
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
 * FD14_trailerAngle
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
 * FL_Lvl
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
 * FR_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FR_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FT_PAMRequestSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FT_PAM_LedControlSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FrontSensorSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * GenericFailSts_FD02_PAM
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
 * Graphic_CHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Graphic_CHR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Graphic_LHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Graphic_LHR
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Graphic_RHF
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Graphic_RHR
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
 * HMICode
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
 * Heading_Angle_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * ImageDefeatRQSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LHFWheelSpeed
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
 * LHRWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * LatAccelerationOffset_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LatAcceleration_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * LatAcceleration_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Latitude_RMSE_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_1_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_1_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_1_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_1_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_1_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_1_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_1_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_2_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_2_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_2_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_2_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_2_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_2_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_2_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_3_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_3_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_3_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_3_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_3_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_3_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_3_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_4_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_4_Curvature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_4_Curvature_Rate
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_4_End_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Line_4_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_4_Offset
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Line_4_Start_Range
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LongAccelerationOffset_BSM
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LongAcceleration_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * LongAcceleration_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Longitude_RMSE_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LwsAngle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * LwsAngleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * LwsSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * MRM_STATUS_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_ADAS_INFO_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_AGSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM10
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM12
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM27
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM29
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BCM9
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE2_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_BRAKE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_CVPAM_FD_Control
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_CVPAM_FD_Data
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_CVPAM_FD_Data2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_CVPAM_FD_Info
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_DRIVETRAIN3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_ENGINE2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_ENGINE5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_ENGINE7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_EPS1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_EPS2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_GLOB_NAV_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_TRANSM1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_TRANSM2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_TRANSM4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_TRSCM1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_TRSKM_FD_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_Telematic11
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_Telematic14
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MessageCounter_Telematic5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MoreCamsRQSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * PAMSystemFault
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_CHIME_REP_RATESts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_CHIME_TYPE
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_LedControlSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_Off_Status
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * PAM_Off_Status_2BT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_PopUpRqst
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PAM_Volume
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Front_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Lane_Dection_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Left_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_LM_Color
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_LM_Distance
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Line_LM_Distance_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_LM_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Line_LM_Heading_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_LM_Style
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_RM_Color
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_RM_Distance
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Line_RM_Distance_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_RM_Heading
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Line_RM_Heading_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Line_RM_Style
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj1_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj1_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj1_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj1_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj1_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj1_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj2_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj2_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj2_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj2_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj2_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj2_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj3_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj3_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj3_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj3_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj3_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj3_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj4_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj4_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj4_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj4_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj4_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj4_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj5_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj5_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj5_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj5_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj5_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj5_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj6_Angle
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj6_Angle_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj6_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Obj6_Range
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj6_Range_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_Obj6_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_Right_Sensor_Det_Health
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_SideSensor_FrontLeft_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_SideSensor_FrontLeft_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_SideSensor_FrontRight_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_SideSensor_FrontRight_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_SideSensor_RearLeft_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_SideSensor_RearLeft_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PA_SideSensor_RearRight_Conf
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PA_SideSensor_RearRight_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * PPPA_TurnIndicatorRqst
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * ParkingManeuverActive
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PdlPosActual
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PitchRate_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Pitch_RMSE_C2
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
 * PreviousCanNMState_FD02_PAM
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
 * REF_VEH_SPEED
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * RHFWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * RHRWheelSpeed
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * RL_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RL_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RR_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RR_Lvl_Adj
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RR_PAM_Brk_RqSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RR_PAM_Dist
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * RR_PAM_StopControlSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RearSensorSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rear_Brk_Asst
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RemStActvSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RollRate_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Roll_RMSE_C2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SBR1RowDriverSeatSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SPMControlSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SPMFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SPMSystemFault
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SPM_LedControlSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SPM_Screen_Rqst
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * SVC_Guidelines
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Segment_1_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_1_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_1_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_1_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_1_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_2_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_2_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_2_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_2_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_2_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_3_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_3_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_3_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_3_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_3_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_4_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_4_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_4_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_4_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_4_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_5_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_5_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_5_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_5_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_5_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_6_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_6_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_6_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_6_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_6_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_7_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_7_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_7_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_7_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_7_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_8_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Segment_8_X1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_8_X2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_8_Y1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Segment_8_Y2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * StaticGrid
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
 * THA_EPB_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * THA_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * THA_SpeedLimit_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * THA_SteeringDamping
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * THA_SteeringTorqueInfo
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * THA_SteeringTorqueReq
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
 * TRSCMoreCamRQSts
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
 * TRSC_LED_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_PopupDisp_Info
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
 * TRSC_STAT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_SpeedLimit_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_SteeringDamping
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_SteeringTorqueInfo
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * TRSC_SteeringTorqueReq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_VehicleStop_Req
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TargetGear
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * TeAutoPark_e_ScanDir
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
 * TeTRSC_e_SpdLmtReq
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
 * TeTRSC_e_TrlrHitchLightCtrl
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
 * TotalOdometer
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
 * Trailer_Angle
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Trailer_Angle_Sign
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Trailer_Calibration
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
 * TrlrHitchLight_Cntrl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * VehicleSpeedVSOSig
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * VehicleStandStillSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * VerticalAcceleration_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * WakeupSource_FD02_PAM
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
 * YawRate_BSM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * YawRate_C2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * YawRate_RMSE_C2
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
 *********************************************************************************************************************/

#include "Rte_SWC_SafeVCANRx.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Rte_Type.h"
#include "SWC_VCANMgr.h"
#include "Enums.h"
#include "Os_Lcfg.h"
#include "ipc_manager.h"
#include "vstdlib.h"
#include "APDiagDataTypes.h"
#include "SSM_Slave.h"
#include "SSM_BSW_Interface.h"

# define D_READ_SIGNAL_FROMCOM_FD14(Sig, Var) (void)Rte_Read_RpFromComSafeFD14Rx_##Sig((Sig*)&(Var))
# define D_WRITE_SIGNAL_TOSWC_FD14(Sig, Var) (void)Rte_Write_PpToSwcSafeFD14Rx_##Sig((Sig)(Var))

# define D_READ_SIGNAL_FROMCOM_FD02(Sig, Var) (void)Rte_Read_RpFromComSafeFD02Rx_##Sig((Sig*)&(Var))
# define D_WRITE_SIGNAL_TOSWC_FD02(Sig, Var) (void)Rte_Write_PpToSwcSafeFD02Rx_##Sig((Sig)(Var))

/* For Array */
# define D_READ_SIGNAL_FROMCOM_FD14_ARRAY(Sig, Var) (void)Rte_Read_RpFromComSafeFD14Rx_##Sig(Var)
# define D_WRITE_SIGNAL_TOSWC_FD14_ARRAY(Sig, Var) (void)Rte_Write_PpToSwcSafeFD14Rx_##Sig(Var)

# define D_READ_SIGNAL_FROMCOM_FD02_ARRAY(Sig, Var) (void)Rte_Read_RpFromComSafeFD02Rx_##Sig(Var)
# define D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(Sig, Var) (void)Rte_Write_PpToSwcSafeFD02Rx_##Sig(Var)

/*Remote core status Macro*/
#define MCU2_0_STATE                        (0x01u)
#define MCU2_1_STATE                        (0x02u)
#define MPU1_0_STATE                        (0x04u)
#define D_CRANKING_TIME                     500U   /* 5 sec counter for EC1 check */
#define ALL_CORE_STATE                      ((MCU2_0_STATE) | (MCU2_1_STATE) | (MPU1_0_STATE))

#define HEALTHY 3U
#define D_VEHICLE_SPEED_ZERO     0.00f

/*Feature Enable condition Macro*/
#define SVC360_FEATURE			(((uint8)e_ZERO != SvsToVCAN_Data.IeSVS_e_DispView2) && ((uint8)e_ONE == v_SurroundViewCam_u8))  /* Req. ID : 21190475 */
#define PARB_FEATURE  			(((uint8)e_ONE == TbAP_PAStateOut_Data.IeAP_b_PAMRearCtrlSts) && ((uint8)e_ONE == v_ParkWithStop_u8)) /* Req. ID : 21190456 */
#define PA_FEATURE 				((((uint8)e_ONE == TbAP_APSMPAOut_Data.IeAP_e_FrntRearParkSts) || ((uint8)e_TWO == TbAP_APSMPAOut_Data.IeAP_e_FrntRearParkSts) || ((uint8)e_THREE == TbAP_APSMPAOut_Data.IeAP_e_FrntRearParkSts)) && (((uint8)e_ZERO == v_PamConfiguration_u8) || ((uint8)e_ONE == v_PamConfiguration_u8))) /* Req. ID : 21190248 */
#define PARB_PA_FEATURE 		((PA_FEATURE) || (PARB_FEATURE))
#define TRSC_FEATURE  			((((uint8)e_ONE == S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts) || ((uint8)e_ONE == S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat)) && (((uint8)e_ZERO == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_ONE == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_TWO == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_THREE == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts)))  /* Req. ID : 21185349 */
#define FULL_PPPA_FEATURE  		((((uint8)e_ONE == TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv) || ((uint8)e_TWO == TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv) || ((uint8)e_THREE == TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv)) && ((uint8)e_ONE == v_FullAutoParkSystem_u8)) /* Req. ID : 21189404 */
#define THA_FEATURE   			((((uint8)e_ONE == TbTHASmVc_FeatureOutputs_Data.IeTHA_e_THAState) || ((uint8)e_TWO == TbTHASmVc_FeatureOutputs_Data.IeTHA_e_THAState) || ((uint8)e_THREE == TbTHASmVc_FeatureOutputs_Data.IeTHA_e_THAState) || ((uint8)e_FOUR == TbTHASmVc_FeatureOutputs_Data.IeTHA_e_THAState)) && ((uint8)e_ONE == v_Trailerhitchassist_u8)) /* Req. ID : 21190313 */
#define CMD_IGN_STATUS          ((uint8)TRUE == v_CmdIgnsts_u8)
#define FULL_PPPA_FEATURE_PPPA_STUCK_SWITCH  		(((e_ENABLE_SEEKING_STATE == TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv) || (e_ENABLE_ENGAGED_SEMI_STATE == TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv) ) && (FULL_AUTO_PARK_SYSTEM_ON == v_FullAutoParkSystem_u8)) /* Req. ID : 21245200  Defect:20944364*/
#define FOD_FEATURE				((uint32)HEALTHY == SafeVCANRx_CVPAMFDData_t.IeFOD_e_FODHealth)  /* Req. ID : 22533934 */
 
/*CAN Signal Invalid Data Macro*/
#define EXT_TEMP_SNA                        511u     /*511-0x1FF*/
#define CMD_IG_STATUS_SNA                   7u
#define TRLR_CONN_STS_NOTUSED               2u
#define TRLR_CONN_STS_SNA                   3u
#define TGW_CAMERA_DISP_STAT_SNA            15u
#define APAREQUEST_STS_PRESSESD             1u
#define PAMREQUEST_STS_PRESSESD             1u 
#define FT_PAMREQUEST_STS_PRESSESD          1u
#define REF_VEH_SPEED_SNA                   1023u    /* 1023 = 0x3FF */
#define VEH_STANDSTILL_STS_SNA              3u
#define LAT_ACC_BSM_SNA                     4095u    /* 4095 = 0xFFF */
#define CMD_IG_STATUS_INVALID_1             2u
#define CMD_IG_STATUS_INVALID_2             6u
#define LANGUAGE_SEL_INVALID_RANGE          21u
#define PAM_CHIME_VOL_FRONT_INVALID          3u
#define PAM_CHIME_VOL_REAR_INVALID           3u
#define LAT_ACC_BSM_FAIL                     1u
#define LONG_ACC_BSM_FAIL                    1u
#define LONG_ACC_BSM_SNA                    4095u     /* 4095 = 0xFFF */
#define VEHICLE_SPEEDVSO_SIG_SNA            8191u     /* 8191 = 0x1FFF */
#define YAWRATE_BSM_SNA                      4095u    /* 4095 = 0xFFF */
#define YAWRATE_BSM_FAIL                      1u
#define LAT_ACC_OFFSET_BSM_SNA                255u    /* 255 = 0xFF */
#define LONG_ACC_OFFSET_BSM_SNA               255u    /* 255 = 0xFF */
#define LHF_FASTPULSECOUNTER_SNA              255u    /* 255 = 0xFF */
#define LHF_SPIN_SNA                           3u
#define LHF_WHEEL_SNR_STS_FAIL                 1u
#define LHR_FASTPULSECOUNTER_SNA              255u    /* 255 = 0xFF */
#define LHR_SPIN_SNA                           3u
#define LHR_WHEEL_SNR_STS_FAIL                 1u
#define RHF_FASTPULSECOUNTER_SNA              255u    /* 255 = 0xFF */
#define RHF_SPIN_SNA                          3u
#define RHF_WHEEL_SNR_STS_FAIL                1u
#define RHR_FASTPULSECOUNTER_SNA              255u    /* 255 = 0xFF */
#define RHR_SPIN_SNA                          3u
#define RHR_WHEEL_SNR_STS_FAIL                 1u
#define LHF_WHEEL_SPEED_SNA                   8191u   /* 8191 = 0x1FFF */
#define LHR_WHEEL_SPEED_SNA                   8191u   /* 8191 = 0x1FFF */
#define RHF_WHEEL_SPEED_SNA                   8191u   /* 8191 = 0x1FFF */
#define RHR_WHEEL_SPEED_SNA                   8191u   /* 8191 = 0x1FFF */
#define LAT_CTRLSTS_PERM_NA                   1u
#define LAT_CTRLSTS_TEMP_NA                   2u
#define LWS_ANGLE_SNA                        65535    /*65535 =0xFFFF */
#define LWS_ANGLE_TYPE_SNA                    3u
#define LWS_SPEED_SNA                       4095u     /* 4095 = 0xFFF */
#define EPBSTS_SNA                           15u
#define PAM_BRK_RSPSTS_SNA                   3u
#define PAM_BRK_RSPSTS_FAULTED               2u
#define ESC_TRSC_BRK_RSP_SNA                 3u
#define ESC_TRSC_BRK_RSP_OVERHEATED          2u
#define BSM_THA_BRK_RSP_SNA                  3u
#define BSM_THA_BRK_RSP_OVERHEATED           2u
#define EXT_BRK_REQ_DIS_SNA                  3u
#define ADAS_INHIBIT_FAULTED                 0u
#define SHIFTLEVERPOS_NOSEL                  0u
#define SHIFTLEVERPOS_NOTUSED                10u
#define SHIFTLEVERPOS_SNA                    15u
#define ITBM_TRLRSTAT_SNA                    3u
#define VIN_MSG_SNA                          3u
#define FL_LVL_SNA                          255u         /* 255 = 0xFF */
#define FR_LVL_SNA                          255u         /* 255 = 0xFF */
#define RL_LVL_SNA                          255u         /* 255 = 0xFF */
#define RR_LVL_SNA                          255u         /* 255 = 0xFF */
#define ASCM_STAT_CLEARANCE2                13u
#define ASCM_STAT_INVALID                   14u
#define ASCM_STAT_SNA                       15u
#define ASCM_SYSFAIL_TRUE                   1u
#define CM_TCH_STAT_NOTUSED                 3u
#define CM_TCH_STAT_SNA                     7u
#define CAM_DISPLAYSTS2_VIEW4               4u
#define CAM_DISPLAYSTS2_VIEW10              10u
#define TRSC_ENABLE_BTN_STS_SNA             2u
#define THA_STERRING_TRQREP_TEMP_NA         0u
#define THA_STERRING_TRQREP_PERM_NA         1u
#define THA_STERRING_TRQREP_INVALID         4u
#define THA_STERRING_TRQREP_SNA             7u
#define EPS_STEERINGTOUQ_REP_SNA            3u
#define THA_STEERINGTOUCH_STAT_SNA          3u
#define THA_DRVTORQ_OVERRIDE_SNA            3u
#define DRIVETRAIN_SNA  					3u
#define TARGET_GEAR_UNSED1  				10u
#define TARGET_GEAR_UNSED2   				11u
#define TARGET_GEAR_UNSED3  				12u
#define TARGET_GEAR_SNA     				15u
#define ECM_THA_RESP_SNA    				3u
#define TRANS_ADAS_FAULTED 					0u
#define GEAR_ENG_UNSED1  					10u
#define GEAR_ENG_UNSED2   					11u
#define GEAR_ENG_UNSED3  					12u
#define GEAR_ENG_SNA     					15u
#define GEAR_ENAGED_DISPLAY_UNSED1 			10u
#define GEAR_ENAGED_DISPLAY_UNSED2 			11u
#define GEAR_ENAGED_DISPLAY_UNSED3 			16u
#define GEAR_ENAGED_DISPLAY_SNA 			31u
#define ENGINE_STS_SNA 						3u
#define ECM_TRSC_RESP_SNA 					3u
#define ENGINE_FD5_PDLPOSACT_SNA 			255u

/*CAN signal conversion Macro*/
#define D_BRAKE_FD_2_OFFSET                    (40.96f)
#define D_BSM_0_2_OFFSET                       (2.56f)
#define D_BSM_0_2_FACTOR                       (0.02f)
#define D_BSM_0_8_FACTOR                       (0.08f)
#define D_ENG_PDL_FACTOR                       (0.4f)
#define D_BSM_0_8_OFFSET                       (163.84f)
#define D_EPS_ANGLE_OFFSET                     (720u)
#define D_EPS_SPEED_OFFSET                     (2000u)

/*Maturation time Macro*/
#define MATURATION_CNT_TWO 2u
#define MATURATION_CNT_THREE 3u
#define MATURATION_CNT_FIVE 5u
#define MATURATION_CNT_TEN 10u
#define MATURATION_CNT_TWELVE 12u
#define MATURATION_CNT_FIFTEEN 15u
#define MATURATION_CNT_TWENTY_FIVE 25u
#define MATURATION_CNT_THIRTY 30u
#define MATURATION_CNT_FIFTY 50u
#define MATURATION_CNT_ONE_HUNDRED 100u
#define MATURATION_CNT_ONE_HUNDRED_FIFTY 150u
#define MATURATION_CNT_THREE_HUNDRED 300u

/*CAN DLC Macro*/
#define D_DLC_AGSM_FD_2         (0x20u)
#define D_DLC_BCM_FD_2          (0x20u)
#define D_DLC_BCM_FD_9          (0x20u)
#define D_DLC_BCM_FD_10         (0x20u)
#define D_DLC_BCM_FD_12         (0x20u)
#define D_DLC_BCM_FD_27         (0x20u)
#define D_DLC_BCM_FD_29         (0x20u)
#define D_DLC_IPC_VEHICLE_SETUP (0x30u)
#define D_DLC_IPC_FD_1          (0x20u)
#define D_DLC_ASCM_FD_1         (0x20u)
#define D_DLC_ASCM_FD_2         (0x20u)
#define D_DLC_VIN               (0x20u)
#define D_DLC_PT_SYSTEM_FD_1    (0x40u)
#define D_DLC_PT_TORQUE_FD_1    (0x30u)
#define D_DLC_TELEMATIC_FD_5    (0x20u)
#define D_DLC_TELEMATIC_FD_11   (0x20u)
#define D_DLC_TELEMATIC_FD_14   (0x20u)
#define D_DLC_BRAKE_FD_1        (0x20u)
#define D_DLC_BRAKE_FD_2        (0x40u)
#define D_DLC_BRAKE_FD_3        (0x20u)
#define D_DLC_BRAKE_FD_4        (0x20u)
#define D_DLC_BRAKE_FD_5        (0x20u)
#define D_DLC_BRAKE_FD_7        (0x20u)
#define D_DLC_EPS_FD_1          (0x20u)
#define D_DLC_EPS_FD_2          (0x20u)
#define D_DLC_DRIVETRAIN_FD_3   (0x20u)
#define D_DLC_ENGINE_FD_2       (0x40u)
#define D_DLC_ENGINE_FD_5       (0x20u)
#define D_DLC_ENGINE_FD_7       (0x20u)
#define D_DLC_TRANSM_FD_1       (0x40u)
#define D_DLC_TRANSM_FD_4       (0x20u)
#define D_DLC_TRANSM_FD_2       (0x20u)

extern TbNVM_ReadParam TbNVM_ReadParam_Data;

#if defined( BUILD_MCU1_0 )
#define SWC_SafeVCANRx_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_SafeVCANRx_MemMap.h"
#endif

static ME_VehInp_to_IpcSignals_t S_VCANtoIPC;
static uint8 v_SurroundViewCam_u8;
static uint8 v_Trailerhitchassist_u8;
static uint8 v_PamConfiguration_u8;
static uint8 v_ParkWithStop_u8;
static uint8 v_FullAutoParkSystem_u8;
static ME_Hydra2defs_S_CodingTableExt_t codingTableExt_s;
static boolean v_FailsafeFlag_b;
static ME_VehOut_TRSC_t ME_VehOut_TRSC_Data;
static TbAP_APSMPAOut_t TbAP_APSMPAOut_Data;
static SvsToVCAN_t SvsToVCAN_Data;
static TbAP_PAStateOut_t TbAP_PAStateOut_Data;
static TbAP_DriveAssistStatOut_t TbAP_DriveAssistStatOut_Data;
static TbTHASmVc_FeatureOutputs_t TbTHASmVc_FeatureOutputs_Data;
static uint8 v_CmdIgnsts_u8;
static uint8 v_CmdIgnsts_Init_u8 = (uint8)FALSE;
static IFOD_Outputs_CVPAMFDData_t SafeVCANRx_CVPAMFDData_t = {0};

static uint8 v_DTCB12852AIPCBlockWrite_u8 = 0u;
static uint8 v_Data_u8;
static uint16 v_Data_u16;

static uint8 v_RemoteCoreStatus_u8;
static uint8 s_IPC_VEHICLE_SETUP_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_10_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_7_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_1_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_4_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_3_MM_u8 = (uint8)e_ZERO;
static uint8 s_EPS_FD_1_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_12_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_9_MM_u8 = (uint8)e_ZERO;
static uint8 s_TRANSM_FD_4_MM_u8 = (uint8)e_ZERO;
static uint8 s_DRIVETRAIN_FD_3_MM_u8 = (uint8)e_ZERO;
static uint8 s_TELEMATIC_FD_14_MM_u8 = (uint8)e_ZERO;
static uint8 s_TRANSM_FD_1_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_27_MM_u8 = (uint8)e_ZERO;
static uint8 s_BRAKE_FD_5_MM_u8 = (uint8)e_ZERO;
static uint8 s_ASCM_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_TELEMATIC_FD_5_MM_u8 = (uint8)e_ZERO;
static uint8 s_ENGINE_FD_7_MM_u8 = (uint8)e_ZERO;
static uint8 s_ENGINE_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_ENGINE_FD_5_MM_u8 = (uint8)e_ZERO;
static uint8 s_EPS_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_ASCM_FD_1_MM_u8 = (uint8)e_ZERO;
static uint8 s_TRANSM_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_TELEMATIC_FD_11_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_29_MM_u8 = (uint8)e_ZERO;
static uint8 s_AGSM_FD_2_MM_u8 = (uint8)e_ZERO;
static uint8 s_IPC_FD_1_MM_u8 = (uint8)e_ZERO;
static uint8 s_VIN_MM_u8 = (uint8)e_ZERO;
static uint8 s_BCM_FD_2_MM_u8 = (uint8)e_ZERO;

#if defined( BUILD_MCU1_0 )
#define SWC_SafeVCANRx_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_SafeVCANRx_MemMap.h"
#endif

typedef void (*v_funcptr_v)(void);
typedef enum e_RX_SafeVCAN_AllEventList_s
{
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process10_mSecSignal = 0U,
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process20_mSecSignal,
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process100_mSecSignal,
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process200_mSecSignal,
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process250_mSecSignal,
	E_RX_SafeVCAN_FROMCOM_TOSWC_Process1000_mSecSignal,
	E_RX_SafeVCAN_EVENT_RX_FROMCOM_TOSWC,
	E_RX_SafeVCNA_Last_EventIndex,
}e_RX_SafeVCAN_AllEventList_t;

typedef struct s_EventDataManage
{
    e_RX_SafeVCAN_AllEventList_t EventID;
    uint8 isTriggered_b;
    uint8 EventType_u8;
    uint32 CounterValue_u32;
    uint32 PeriodicityTypes_u32;
    v_funcptr_v FuncPtrWrite;
} EventDataManage_t;

static void RX_SafeVCANProcess(void);
static void F_SendCanDataToRemoteCore(void);

static void f_DTC_Flag_BCM_FD_9_ExternalTemperature(ExternalTemperature v_fData_u16);
static void f_DTC_Flag_BCM_FD_10_CmdIgnSts(CmdIgnSts v_fData_u8);
static void f_DTC_Flag_BCM_FD_12_APARequestSts(APARequestSts v_fData_u8);
static void f_DTC_Flag_BCM_FD_12_PAMRequestSts(PAMRequestSts v_fData_u8);
static void f_DTC_Flag_BCM_FD_12_FT_PAMRequests(FT_PAMRequestSts v_fData_u8);
static void f_DTC_Flag_BCM_FD_27_TrailerConnectionSts(TrailerConnectionSts v_fData_u8);
static void f_DTC_Flag_DRIVETRAIN_FD_3_TCASERANGESTATUS(TCASERANGESTATUS v_fData_u8);
static void f_DTC_Flag_IPC_VEHICLE_SETUP_LanguageSelection(LanguageSelection v_fData_u8);
static void f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeFront(PamChimeVolumeFront v_fData_u8);
static void f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeRear(PamChimeVolumeRear v_fData_u8);
static void f_DTC_Flag_TRANSM_FD_1_TargetGear(TargetGear v_fData_u8);
static void f_DTC_Flag_TRANSM_FD_1_TRANS_ADAS_Inhibit(TRANS_ADAS_Inhibit v_fData_u8);
static void f_DTC_Flag_TRANSM_FD_4_GearEngaged(GearEngaged v_fData_u8);
static void f_DTC_Flag_TRANSM_FD_4_ShiftLeverPosition(ShiftLeverPosition v_fData_u8);
static void f_DTC_Flag_TELEMATIC_FD_14_TGW_CAMERA_DISP_STAT(TGW_CAMERA_DISP_STAT v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_1_FD14_REF_VEH_SPEED(FD14_REF_VEH_SPEED v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_1_FD14_VehicleStandStillSts(FD14_VehicleStandStillSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_2_FD14_LatAcceleration_BSM(FD14_LatAcceleration_BSM v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_2_FD14_LatAccelerationFailSts_BSM(FD14_LatAccelerationFailSts_BSM v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_2_FD14_LongAcceleration_BSM(FD14_LongAcceleration_BSM v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_2_FD14_LongAccelerationFailSts_BSM(FD14_LongAccelerationFailSts_BSM v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_2_FD14_VehicleSpeedVSOSig(FD14_VehicleSpeedVSOSig v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_2_FD14_YawRate_BSM(FD14_YawRate_BSM v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_2_FD14_YawRateFailSts_BSM(FD14_YawRateFailSts_BSM v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LatAccelerationOffset_BSM(FD14_LatAccelerationOffset_BSM v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LongAccelerationOffset_BSM(FD14_LongAccelerationOffset_BSM v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_FastPulseCounter(FD14_LHF_FastPulseCounter v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_Spin(FD14_LHF_Spin v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_WheelSensorFailSts(FD14_LHF_WheelSensorFailSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_FastPulseCounter(FD14_LHR_FastPulseCounter v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_Spin(FD14_LHR_Spin v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_WheelSensorFailSts(FD14_LHR_WheelSensorFailSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_FastPulseCounter(FD14_RHF_FastPulseCounter v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_Spin(FD14_RHF_Spin v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_WheelSensorFailSts(FD14_RHF_WheelSensorFailSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_FastPulseCounter(FD14_RHR_FastPulseCounter v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_Spin(FD14_RHR_Spin v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_WheelSensorFailSts(FD14_RHR_WheelSensorFailSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHFWheelSpeed(FD14_LHFWheelSpeed v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_3_FD14_LHRWheelSpeed(FD14_LHRWheelSpeed v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHFWheelSpeed(FD14_RHFWheelSpeed v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_3_FD14_RHRWheelSpeed(FD14_RHRWheelSpeed v_fData_u16);
static void f_DTC_Flag_EPS_FD_1_FD14_SPM_Lat_Ctrl_ResponseSts(FD14_SPM_Lat_Ctrl_ResponseSts v_fData_u8);
static void f_DTC_Flag_EPS_FD_1_FD14_LwsAngle(FD14_LwsAngle v_fData_u16);
static void f_DTC_Flag_EPS_FD_1_FD14_LwsAngleType(FD14_LwsAngleType v_fData_u8);
static void f_DTC_Flag_EPS_FD_1_FD14_LwsSpeed(FD14_LwsSpeed v_fData_u16);
static void f_DTC_Flag_BRAKE_FD_4_FD14_EPBSts(FD14_EPBSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_7_FD14_PAM_Brk_Rq_RspSts(FD14_PAM_Brk_Rq_RspSts v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_5_FD14_ESC_TRSC_Brk_Resp(FD14_ESC_TRSC_Brk_Resp v_fData_u8);
static void f_DTC_Flag_Brake_FD_5_FD14_BSM_THA_Brk_Resp(FD14_BSM_THA_Brk_Resp v_fData_u8);
static void f_DTC_Flag_BRAKE_FD_1_FD14_ExternalBrkRequestsDisabled(FD14_ExternalBrkRequestsDisabled v_fData_u8);
static void f_DTC_Flag_ASCM_FD1_FL_Lvl(FL_Lvl v_fData_u8);
static void f_DTC_Flag_ASCM_FD1_FR_Lvl(FR_Lvl v_fData_u8);
static void f_DTC_Flag_ASCM_FD1_RL_Lvl(RL_Lvl v_fData_u8);
static void f_DTC_Flag_ASCM_FD1_RR_Lvl(RR_Lvl v_fData_u8);
static void f_DTC_Flag_ASCM_FD2_ASCM_Stat(ASCM_Stat v_fData_u8);
static void f_DTC_Flag_ASCM_FD2_ASCM_SysFail(ASCM_SysFail v_fData_u8);
static void f_DTC_Flag_TRANSM_FD_2_GearEngagedForDisplay(GearEngagedForDisplay v_fData_u8);
static void f_DTC_Flag_VIN(VIN_MSG v_fData_u8);
static void f_DTC_Flag_ENGINE_FD_2_FD14_EngineSts_W(FD14_EngineSts_W v_fData_u8);
static void f_DTC_Flag_ENGINE_FD_7_FD14_ECM_THA_Resp(FD14_ECM_THA_Resp v_fData_u8);
static void f_DTC_Flag_ENGINE_FD_7_FD14_ECM_TRSC_Resp(FD14_ECM_TRSC_Resp v_fData_u8);
static void f_DTC_Flag_TELEMATIC_FD_11_HU_TRSC_EnableBtn_Sts(HU_TRSC_EnableBtn_Sts v_fData_u8);
static void f_DTC_Flag_ENGINE_FD_5_FD14_PdlPosActual(FD14_PdlPosActual v_fData_u8);
static void f_DTC_Flag_AGSM_FD_2_Shifter_ADAS_Inhibit(Shifter_ADAS_Inhibit v_fData_u8);
static void f_DTC_Flag_AGSM_FD_2_ShiftLeverPositionReq(ShiftLeverPositionReq v_fData_u8);
static void f_DTC_Flag_BCM_FD_29_ITBM_TrlrStat(ITBM_TrlrStat v_fData_u8);
static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_STAT(CM_TCH_STAT v_fData_u8);
static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_X_COORD(CM_TCH_X_COORD v_fData_u16);
static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_Y_COORD(CM_TCH_Y_COORD v_fData_u16);
static void f_DTC_Flag_TELEMATIC_FD_5_CameraDisplaySts2(CameraDisplaySts2 v_fData_u8);
static void f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_DriverTorqueOverride(FD14_EPS_THA_DriverTorqueOverride v_fData_u8);
static void f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_SteeringTorqueResp(FD14_EPS_THA_SteeringTorqueResp v_fData_u8);
static void f_DTC_Flag_EPS_FD_2_FD14_EPS_SteeringTouq_Resp(FD14_EPS_SteeringTouq_Resp v_fData_u8);
static void f_DTC_Flag_EPS_FD_2_FD14_THA_SteeringTouchStat(FD14_THA_SteeringTouchStat v_fData_u8);

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
 * AUXCamsRQSts: Integer in interval [0...1]
 * Active_Park_Mode: Integer in interval [0...1]
 * Active_Park_Prox_Chime: Integer in interval [0...1]
 * Alert_CHF: Integer in interval [0...7]
 * Alert_CHR: Integer in interval [0...7]
 * Alert_LHF: Integer in interval [0...7]
 * Alert_LHR: Integer in interval [0...7]
 * Alert_RHF: Integer in interval [0...7]
 * Alert_RHR: Integer in interval [0...7]
 * Altitude_RMSE_C2: Integer in interval [0...255]
 * BSM_THA_Brk_Resp: Integer in interval [0...3]
 * Backup_Cam_Delay: Integer in interval [0...1]
 * Battery_Volt_1: Integer in interval [0...511]
 * Brk_Stat: Integer in interval [0...3]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CRC_ADAS_INFO_C2: Integer in interval [0...255]
 * CRC_AGSM2: Integer in interval [0...255]
 * CRC_BCM10: Integer in interval [0...255]
 * CRC_BCM12: Integer in interval [0...255]
 * CRC_BCM2: Integer in interval [0...255]
 * CRC_BCM27: Integer in interval [0...255]
 * CRC_BCM29: Integer in interval [0...255]
 * CRC_BCM9: Integer in interval [0...255]
 * CRC_BRAKE1: Integer in interval [0...255]
 * CRC_BRAKE2: Integer in interval [0...255]
 * CRC_BRAKE2_1: Integer in interval [0...255]
 * CRC_BRAKE4: Integer in interval [0...255]
 * CRC_BRAKE5: Integer in interval [0...255]
 * CRC_BRAKE7: Integer in interval [0...255]
 * CRC_CVPAM_FD_Control: Integer in interval [0...255]
 * CRC_CVPAM_FD_Data: Integer in interval [0...255]
 * CRC_CVPAM_FD_Data2: Integer in interval [0...255]
 * CRC_CVPAM_FD_Info: Integer in interval [0...255]
 * CRC_ENGINE2: Integer in interval [0...255]
 * CRC_ENGINE5: Integer in interval [0...255]
 * CRC_ENGINE7: Integer in interval [0...255]
 * CRC_EPS1: Integer in interval [0...255]
 * CRC_EPS2: Integer in interval [0...255]
 * CRC_GLOB_NAV_C2: Integer in interval [0...255]
 * CRC_TRANSM1: Integer in interval [0...255]
 * CRC_TRANSM2: Integer in interval [0...255]
 * CRC_TRANSM4: Integer in interval [0...255]
 * CRC_TRSCM1: Integer in interval [0...255]
 * CRC_TRSKM_FD_1: Integer in interval [0...255]
 * CRC_Telematic11: Integer in interval [0...255]
 * CRC_Telematic14: Integer in interval [0...255]
 * CRC_Telematic5: Integer in interval [0...255]
 * CRC__BRAKE3: Integer in interval [0...255]
 * CRC__DRIVETRAIN3: Integer in interval [0...255]
 * CameraDisplaySts2: Integer in interval [0...15]
 * ChimeActivation_LHF: Integer in interval [0...1]
 * ChimeActivation_LHR: Integer in interval [0...1]
 * ChimeActivation_RHF: Integer in interval [0...1]
 * ChimeActivation_RHR: Integer in interval [0...1]
 * CmdIgnSts: Integer in interval [0...7]
 * Cntr_CVPAM_FD_Data: Integer in interval [0...65535]
 * Cntr_CVPAM_FD_Data2: Integer in interval [0...65535]
 * CurrentCanNMState_FD01_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD01_SGW: Integer in interval [0...15]
 * CurrentCanNMState_FD02_BCM: Integer in interval [0...15]
 * CurrentCanNMState_FD02_BSM2: Integer in interval [0...15]
 * CurrentCanNMState_FD02_CADM2: Integer in interval [0...15]
 * CurrentCanNMState_FD02_EPS: Integer in interval [0...15]
 * CurrentCanNMState_FD02_ORC: Integer in interval [0...15]
 * CurrentCanNMState_FD02_PAM: Integer in interval [0...15]
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
 * CurrentFailSts_FD02_PAM: Integer in interval [0...1]
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
 * DES_FD02_PAM: Integer in interval [0...3]
 * DES_FD02_SGW: Integer in interval [0...3]
 * DES_FD02_TRLR_REV: Integer in interval [0...3]
 * DES_FD03_BCM: Integer in interval [0...3]
 * DES_FD03_SGW: Integer in interval [0...3]
 * DES_FD04_BCM: Integer in interval [0...3]
 * DES_FD08_SGW: Integer in interval [0...3]
 * DES_FD11_SGW: Integer in interval [0...3]
 * DeltaTimestamp_IMUdata: Integer in interval [0...255]
 * Digit_01: Integer in interval [0...15]
 * Digit_01_PAM: Integer in interval [0...15]
 * Digit_02: Integer in interval [0...15]
 * Digit_02_PAM: Integer in interval [0...15]
 * Digit_03: Integer in interval [0...15]
 * Digit_03_PAM: Integer in interval [0...15]
 * Digit_04: Integer in interval [0...15]
 * Digit_04_PAM: Integer in interval [0...15]
 * Digit_05: Integer in interval [0...15]
 * Digit_05_PAM: Integer in interval [0...15]
 * Digit_06: Integer in interval [0...15]
 * Digit_06_PAM: Integer in interval [0...15]
 * Digit_07: Integer in interval [0...15]
 * Digit_07_PAM: Integer in interval [0...15]
 * Digit_08: Integer in interval [0...15]
 * Digit_08_PAM: Integer in interval [0...15]
 * Digit_09: Integer in interval [0...15]
 * Digit_09_PAM: Integer in interval [0...15]
 * Digit_10: Integer in interval [0...15]
 * Digit_10_PAM: Integer in interval [0...15]
 * Digit_11: Integer in interval [0...15]
 * Digit_11_PAM: Integer in interval [0...15]
 * DisplayView2: Integer in interval [0...15]
 * DriverDoorSts: Integer in interval [0...1]
 * DynamicGrid: Integer in interval [0...1]
 * E2E_MEP_CheckStatusType: Integer in interval [0...255]
 * E2E_MEP_DataIDMode: Integer in interval [0...255]
 * ECM_THA_Resp: Integer in interval [0...3]
 * ECM_TRSC_Resp: Integer in interval [0...3]
 * EOL_FD01_BCM: Integer in interval [0...1]
 * EOL_FD01_SGW: Integer in interval [0...1]
 * EOL_FD02_BCM: Integer in interval [0...1]
 * EOL_FD02_BSM2: Integer in interval [0...1]
 * EOL_FD02_CADM2: Integer in interval [0...1]
 * EOL_FD02_EPS: Integer in interval [0...1]
 * EOL_FD02_ORC: Integer in interval [0...1]
 * EOL_FD02_PAM: Integer in interval [0...1]
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
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * ExternalTemperature: Integer in interval [0...511]
 * FD14_ACC_Systemsts: Integer in interval [0...15]
 * FD14_Accel_Pedal_Override: Integer in interval [0...1]
 * FD14_BSM_THA_Brk_Resp: Integer in interval [0...3]
 * FD14_BrkPdl_Stat: Integer in interval [0...3]
 * FD14_BrkTrq: Integer in interval [0...32767]
 * FD14_BrkTrq_Driver: Integer in interval [0...32767]
 * FD14_Brk_Stat: Integer in interval [0...3]
 * FD14_CRC_ADAS_FD_INFO: Integer in interval [0...255]
 * FD14_CRC_BRAKE1: Integer in interval [0...255]
 * FD14_CRC_BRAKE2: Integer in interval [0...255]
 * FD14_CRC_BRAKE4: Integer in interval [0...255]
 * FD14_CRC_BRAKE5: Integer in interval [0...255]
 * FD14_CRC_BRAKE7: Integer in interval [0...255]
 * FD14_CRC_CVPAM_FD_Control: Integer in interval [0...255]
 * FD14_CRC_CVPAM_FD_Data: Integer in interval [0...255]
 * FD14_CRC_CVPAM_FD_Data2: Integer in interval [0...255]
 * FD14_CRC_ENGINE2: Integer in interval [0...255]
 * FD14_CRC_ENGINE7: Integer in interval [0...255]
 * FD14_CRC_EPS1: Integer in interval [0...255]
 * FD14_CRC_EPS2: Integer in interval [0...255]
 * FD14_CRC__BRAKE3: Integer in interval [0...255]
 * FD14_Cntr_CVPAM_FD_Data: Integer in interval [0...65535]
 * FD14_Cntr_CVPAM_FD_Data2: Integer in interval [0...65535]
 * FD14_DriverReq_AxleTrq_Enabled_BSM: Integer in interval [0...15]
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
 * FD14_IeTRSC_M_TRSCStrTrq: Real in interval [-9000...9000] with single precision
 * FD14_IeTRSC_deg_FrntWhlAng: Real in interval [-400...400] with single precision
 * FD14_IeTRSC_deg_JackknifeThrAngle: Real in interval [-9000...9000] with single precision
 * FD14_IeTRSC_deg_TADAngle: Real in interval [-9000...9000] with single precision
 * FD14_IeTRSC_deg_TrlrAngKnob: Real in interval [-9000...9000] with single precision
 * FD14_IeTRSC_kph_VehSpeedVSOSig: Real in interval [-9000...9000] with single precision
 * FD14_IeTRSC_m_TrlrWhlBaseEff: Real in interval [0...1500000] with single precision
 * FD14_IeTRSC_pct_TrlrDetConf: Real in interval [0...1000] with single precision
 * FD14_IeTRSC_pct_TrlrRecogConf: Real in interval [0...1000] with single precision
 * FD14_IeTRSC_pct_TrlrTrackConf: Real in interval [0...1000] with single precision
 * FD14_IeVBII_nfcd_MinDisToCollisionObj: Real in interval [-150000...150000] with single precision
 * FD14_JackknifeAngle: Real in interval [-11000...11000] with single precision
 * FD14_JackknifeThrAngle: Real in interval [-11000...11000] with single precision
 * FD14_LHFWheelSpeed: Integer in interval [0...8191]
 * FD14_LHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHF_Spin: Integer in interval [0...3]
 * FD14_LHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LHRWheelSpeed: Integer in interval [0...8191]
 * FD14_LHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHR_Spin: Integer in interval [0...3]
 * FD14_LHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LMD_m_Line_1_End_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_1_Offset: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Line_1_Start_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_2_End_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_2_Offset: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Line_2_Start_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_3_End_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_3_Offset: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Line_3_Start_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_4_End_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Line_4_Offset: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Line_4_Start_Range: Real in interval [-50...77] with single precision
 * FD14_LMD_m_Segment_1_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_1_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_1_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_1_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_2_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_2_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_2_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_2_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_3_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_3_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_3_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_3_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_4_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_4_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_4_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_4_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_5_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_5_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_5_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_5_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_6_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_6_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_6_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_6_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_7_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_7_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_7_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_7_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_8_X1: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_8_X2: Real in interval [-700...1347] with single precision
 * FD14_LMD_m_Segment_8_Y1: Real in interval [-500...523] with single precision
 * FD14_LMD_m_Segment_8_Y2: Real in interval [-500...523] with single precision
 * FD14_LMD_pct_Line_1_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Line_2_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Line_3_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Line_4_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_1_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_2_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_3_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_4_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_5_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_6_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_7_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_pct_Segment_8_Confidence: Real in interval [0...15] with single precision
 * FD14_LMD_px_Line_1_Curvature: Real in interval [-32753...32782] with single precision
 * FD14_LMD_px_Line_2_Curvature: Real in interval [-32753...32782] with single precision
 * FD14_LMD_px_Line_3_Curvature: Real in interval [-32753...32782] with single precision
 * FD14_LMD_px_Line_4_Curvature: Real in interval [-32753...32782] with single precision
 * FD14_LMD_rad_Line_1_Heading: Real in interval [-366...657] with single precision
 * FD14_LMD_rad_Line_2_Heading: Real in interval [-366...657] with single precision
 * FD14_LMD_rad_Line_3_Heading: Real in interval [-366...657] with single precision
 * FD14_LMD_rad_Line_4_Heading: Real in interval [-366...657] with single precision
 * FD14_LatAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LatAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LatAcceleration_BSM: Integer in interval [0...4095]
 * FD14_Line_1_Confidence: Integer in interval [0...15]
 * FD14_Line_1_Curvature: Integer in interval [0...65535]
 * FD14_Line_1_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_1_End_Range: Integer in interval [0...127]
 * FD14_Line_1_Heading: Integer in interval [0...1023]
 * FD14_Line_1_Offset: Integer in interval [0...1023]
 * FD14_Line_1_Start_Range: Integer in interval [0...127]
 * FD14_Line_2_Confidence: Integer in interval [0...15]
 * FD14_Line_2_Curvature: Integer in interval [0...65535]
 * FD14_Line_2_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_2_End_Range: Integer in interval [0...127]
 * FD14_Line_2_Heading: Integer in interval [0...1023]
 * FD14_Line_2_Offset: Integer in interval [0...1023]
 * FD14_Line_2_Start_Range: Integer in interval [0...127]
 * FD14_Line_3_Confidence: Integer in interval [0...15]
 * FD14_Line_3_Curvature: Integer in interval [0...65535]
 * FD14_Line_3_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_3_End_Range: Integer in interval [0...127]
 * FD14_Line_3_Heading: Integer in interval [0...1023]
 * FD14_Line_3_Offset: Integer in interval [0...1023]
 * FD14_Line_3_Start_Range: Integer in interval [0...127]
 * FD14_Line_4_Confidence: Integer in interval [0...15]
 * FD14_Line_4_Curvature: Integer in interval [0...65535]
 * FD14_Line_4_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_4_End_Range: Integer in interval [0...127]
 * FD14_Line_4_Heading: Integer in interval [0...1023]
 * FD14_Line_4_Offset: Integer in interval [0...1023]
 * FD14_Line_4_Start_Range: Integer in interval [0...127]
 * FD14_LongAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LongAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LongAcceleration_BSM: Integer in interval [0...4095]
 * FD14_LwsAngle: Integer in interval [0...65535]
 * FD14_LwsAngleType: Integer in interval [0...3]
 * FD14_LwsSpeed: Integer in interval [0...4095]
 * FD14_MaAP_m_ParkSpot1FrntStreetX: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot1FrntStreetY: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot2FrntBorderX: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot2FrntBorderY: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot3RearBorderX: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot3RearBorderY: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot4RearStreetX: Real in interval [-150000...150000] with single precision
 * FD14_MaAP_m_ParkSpot4RearStreetY: Real in interval [-150000...150000] with single precision
 * FD14_ManoeuvrePhase: Integer in interval [0...1]
 * FD14_MeTHA_deg_CplrAng: Real in interval [0...360] with single precision
 * FD14_MeTHA_deg_RoadWhlAng: Real in interval [-180000...180000] with single precision
 * FD14_MeTRSC_M_SteeringTorqInfo: Real in interval [-80...7912] with single precision
 * FD14_MeTRSC_deg_DetJackKnifeAngle: Real in interval [-11000...11000] with single precision
 * FD14_MeTRSC_deg_DetJackknifeThrAngle: Real in interval [-11000...11000] with single precision
 * FD14_MeTRSC_deg_JackKnifeAngle: Real in interval [-11000...11000] with single precision
 * FD14_MeTRSC_deg_JackknifeThrAngle: Real in interval [-1100...1100] with single precision
 * FD14_MeTRSC_deg_MaxAllowedTADAngle: Real in interval [-1100...1100] with single precision
 * FD14_MeTRSC_deg_TADAngle: Real in interval [-11000...11000] with single precision
 * FD14_MeTRSC_deg_TADAngleRate: Real in interval [-1100...1100] with single precision
 * FD14_MeTRSC_m_DetTrailerBeamLen: Real in interval [100...2000] with single precision
 * FD14_MeTRSC_m_HitchLength: Real in interval [100000...250000] with single precision
 * FD14_MeTRSC_m_TrailerBeamLen: Real in interval [100...2000] with single precision
 * FD14_MessageCounter_ADAS_FD_INFO: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE1: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE2: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE3: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE4: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE5: Integer in interval [0...15]
 * FD14_MessageCounter_BRAKE7: Integer in interval [0...15]
 * FD14_MessageCounter_CVPAM_FD_Control: Integer in interval [0...15]
 * FD14_MessageCounter_CVPAM_FD_Data: Integer in interval [0...15]
 * FD14_MessageCounter_CVPAM_FD_Data2: Integer in interval [0...15]
 * FD14_MessageCounter_ENGINE2: Integer in interval [0...15]
 * FD14_MessageCounter_ENGINE7: Integer in interval [0...15]
 * FD14_MessageCounter_EPS1: Integer in interval [0...15]
 * FD14_MessageCounter_EPS2: Integer in interval [0...15]
 * FD14_NFCD_DistanceToClosestPoint_0_0: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_1: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_2: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_3: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_4: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_5: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_6: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_7: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_8: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_0_9: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_0: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_1: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_2: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_3: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_4: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_5: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_6: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_7: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_8: Real in interval [-150000...150000] with single precision
 * FD14_NFCD_DistanceToClosestPoint_1_9: Real in interval [-150000...150000] with single precision
 * FD14_PAM_Brk_Rq_RspSts: Integer in interval [0...3]
 * FD14_PA_Front_Sensor_Det_Health: Integer in interval [0...3]
 * FD14_PA_Lane_Dection_Health: Integer in interval [0...3]
 * FD14_PA_Left_Sensor_Det_Health: Integer in interval [0...3]
 * FD14_PA_Line_LM_Color: Integer in interval [0...7]
 * FD14_PA_Line_LM_Distance: Integer in interval [0...511]
 * FD14_PA_Line_LM_Distance_Conf: Integer in interval [0...15]
 * FD14_PA_Line_LM_Heading: Integer in interval [0...511]
 * FD14_PA_Line_LM_Heading_Conf: Integer in interval [0...15]
 * FD14_PA_Line_LM_Style: Integer in interval [0...15]
 * FD14_PA_Line_RM_Color: Integer in interval [0...7]
 * FD14_PA_Line_RM_Distance: Integer in interval [0...511]
 * FD14_PA_Line_RM_Distance_Conf: Integer in interval [0...15]
 * FD14_PA_Line_RM_Heading: Integer in interval [0...511]
 * FD14_PA_Line_RM_Heading_Conf: Integer in interval [0...15]
 * FD14_PA_Line_RM_Style: Integer in interval [0...15]
 * FD14_PA_Obj1_Angle: Integer in interval [0...511]
 * FD14_PA_Obj1_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj1_Conf: Integer in interval [0...3]
 * FD14_PA_Obj1_Range: Integer in interval [0...1023]
 * FD14_PA_Obj1_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj1_Type: Integer in interval [0...7]
 * FD14_PA_Obj2_Angle: Integer in interval [0...511]
 * FD14_PA_Obj2_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj2_Conf: Integer in interval [0...3]
 * FD14_PA_Obj2_Range: Integer in interval [0...1023]
 * FD14_PA_Obj2_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj2_Type: Integer in interval [0...7]
 * FD14_PA_Obj3_Angle: Integer in interval [0...511]
 * FD14_PA_Obj3_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj3_Conf: Integer in interval [0...3]
 * FD14_PA_Obj3_Range: Integer in interval [0...1023]
 * FD14_PA_Obj3_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj3_Type: Integer in interval [0...7]
 * FD14_PA_Obj4_Angle: Integer in interval [0...511]
 * FD14_PA_Obj4_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj4_Conf: Integer in interval [0...3]
 * FD14_PA_Obj4_Range: Integer in interval [0...1023]
 * FD14_PA_Obj4_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj4_Type: Integer in interval [0...7]
 * FD14_PA_Obj5_Angle: Integer in interval [0...511]
 * FD14_PA_Obj5_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj5_Conf: Integer in interval [0...3]
 * FD14_PA_Obj5_Range: Integer in interval [0...1023]
 * FD14_PA_Obj5_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj5_Type: Integer in interval [0...7]
 * FD14_PA_Obj6_Angle: Integer in interval [0...511]
 * FD14_PA_Obj6_Angle_2: Integer in interval [0...511]
 * FD14_PA_Obj6_Conf: Integer in interval [0...3]
 * FD14_PA_Obj6_Range: Integer in interval [0...1023]
 * FD14_PA_Obj6_Range_2: Integer in interval [0...1023]
 * FD14_PA_Obj6_Type: Integer in interval [0...7]
 * FD14_PA_Right_Sensor_Det_Health: Integer in interval [0...3]
 * FD14_PA_SideSensor_FrontLeft_Conf: Integer in interval [0...3]
 * FD14_PA_SideSensor_FrontLeft_Dist: Integer in interval [0...1023]
 * FD14_PA_SideSensor_FrontRight_Conf: Integer in interval [0...3]
 * FD14_PA_SideSensor_FrontRight_Dist: Integer in interval [0...1023]
 * FD14_PA_SideSensor_RearLeft_Conf: Integer in interval [0...3]
 * FD14_PA_SideSensor_RearLeft_Dist: Integer in interval [0...1023]
 * FD14_PA_SideSensor_RearRight_Conf: Integer in interval [0...3]
 * FD14_PA_SideSensor_RearRight_Dist: Integer in interval [0...1023]
 * FD14_PPPA_AccelMax: Integer in interval [0...31]
 * FD14_PPPA_AccelMin: Integer in interval [0...31]
 * FD14_PPPA_DecelMax: Integer in interval [0...31]
 * FD14_PPPA_DecelMin: Integer in interval [0...31]
 * FD14_PPPA_Interface_BSM: Integer in interval [0...3]
 * FD14_PPPA_JerkAccelMax: Integer in interval [0...63]
 * FD14_PPPA_JerkAccelMin: Integer in interval [0...63]
 * FD14_PPPA_JerkDecelMax: Integer in interval [0...63]
 * FD14_PPPA_JerkDecelMin: Integer in interval [0...63]
 * FD14_PPPA_MaxSpeed: Integer in interval [0...255]
 * FD14_PPPA_StandstillRqst: Integer in interval [0...1]
 * FD14_PPPA_TargetDistance: Integer in interval [0...1023]
 * FD14_PPPA_TrqEnblRq_Allowed: Integer in interval [0...1]
 * FD14_ParkingGearShiftReq: Integer in interval [0...7]
 * FD14_ParkingGearShiftReq_BSM: Integer in interval [0...7]
 * FD14_ParkingInterventionSts: Integer in interval [0...3]
 * FD14_ParkingManeuverActive: Integer in interval [0...7]
 * FD14_PdlPosActual: Integer in interval [0...255]
 * FD14_REF_VEH_SPEED: Integer in interval [0...1023]
 * FD14_RHFWheelSpeed: Integer in interval [0...8191]
 * FD14_RHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHF_Spin: Integer in interval [0...3]
 * FD14_RHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_RHRWheelSpeed: Integer in interval [0...8191]
 * FD14_RHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHR_Spin: Integer in interval [0...3]
 * FD14_RHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * FD14_RR_PAM_Dist: Integer in interval [0...1023]
 * FD14_SPM_Lat_Ctrl_RequestSts: Integer in interval [0...3]
 * FD14_SPM_Lat_Ctrl_ResponseSts: Integer in interval [0...3]
 * FD14_Segment_1_Confidence: Integer in interval [0...15]
 * FD14_Segment_1_X1: Integer in interval [0...2047]
 * FD14_Segment_1_X2: Integer in interval [0...2047]
 * FD14_Segment_1_Y1: Integer in interval [0...1023]
 * FD14_Segment_1_Y2: Integer in interval [0...1023]
 * FD14_Segment_2_Confidence: Integer in interval [0...15]
 * FD14_Segment_2_X1: Integer in interval [0...2047]
 * FD14_Segment_2_X2: Integer in interval [0...2047]
 * FD14_Segment_2_Y1: Integer in interval [0...1023]
 * FD14_Segment_2_Y2: Integer in interval [0...1023]
 * FD14_Segment_3_Confidence: Integer in interval [0...15]
 * FD14_Segment_3_X1: Integer in interval [0...2047]
 * FD14_Segment_3_X2: Integer in interval [0...2047]
 * FD14_Segment_3_Y1: Integer in interval [0...1023]
 * FD14_Segment_3_Y2: Integer in interval [0...1023]
 * FD14_Segment_4_Confidence: Integer in interval [0...15]
 * FD14_Segment_4_X1: Integer in interval [0...2047]
 * FD14_Segment_4_X2: Integer in interval [0...2047]
 * FD14_Segment_4_Y1: Integer in interval [0...1023]
 * FD14_Segment_4_Y2: Integer in interval [0...1023]
 * FD14_Segment_5_Confidence: Integer in interval [0...15]
 * FD14_Segment_5_X1: Integer in interval [0...2047]
 * FD14_Segment_5_X2: Integer in interval [0...2047]
 * FD14_Segment_5_Y1: Integer in interval [0...1023]
 * FD14_Segment_5_Y2: Integer in interval [0...1023]
 * FD14_Segment_6_Confidence: Integer in interval [0...15]
 * FD14_Segment_6_X1: Integer in interval [0...2047]
 * FD14_Segment_6_X2: Integer in interval [0...2047]
 * FD14_Segment_6_Y1: Integer in interval [0...1023]
 * FD14_Segment_6_Y2: Integer in interval [0...1023]
 * FD14_Segment_7_Confidence: Integer in interval [0...15]
 * FD14_Segment_7_X1: Integer in interval [0...2047]
 * FD14_Segment_7_X2: Integer in interval [0...2047]
 * FD14_Segment_7_Y1: Integer in interval [0...1023]
 * FD14_Segment_7_Y2: Integer in interval [0...1023]
 * FD14_Segment_8_Confidence: Integer in interval [0...15]
 * FD14_Segment_8_X1: Integer in interval [0...2047]
 * FD14_Segment_8_X2: Integer in interval [0...2047]
 * FD14_Segment_8_Y1: Integer in interval [0...1023]
 * FD14_Segment_8_Y2: Integer in interval [0...1023]
 * FD14_Slope: Integer in interval [0...255]
 * FD14_Steering_Column_Torque: Integer in interval [0...2047]
 * FD14_TADAngleRate: Real in interval [-11000...11000] with single precision
 * FD14_THA_EPB_Req: Integer in interval [0...3]
 * FD14_THA_STAT: Integer in interval [0...7]
 * FD14_THA_SpeedLimit_Req: Integer in interval [0...3]
 * FD14_THA_Speed_Limit: Integer in interval [0...31]
 * FD14_THA_SteeringDamping: Integer in interval [0...255]
 * FD14_THA_SteeringTorqueInfo: Integer in interval [0...2047]
 * FD14_THA_SteeringTorqueReq: Integer in interval [0...3]
 * FD14_THA_SteeringTouchStat: Integer in interval [0...3]
 * FD14_TRSC_STAT: Integer in interval [0...7]
 * FD14_TRSC_SpeedLimit_Req: Integer in interval [0...15]
 * FD14_TRSC_SteeringDamping: Integer in interval [0...255]
 * FD14_TRSC_SteeringTorqueInfo: Integer in interval [0...2047]
 * FD14_TRSC_SteeringTorqueReq: Integer in interval [0...3]
 * FD14_TRSC_VehicleStop_Req: Integer in interval [0...3]
 * FD14_TorqueOverlaySteeringReq_SPM: Integer in interval [0...2047]
 * FD14_Tstr_SD_FIL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FIL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FIR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FIR_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FOL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FOL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FOR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FOR_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FSL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FSL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FSR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_FSR_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RIL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RIL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RIR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RIR_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_ROL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_ROL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_ROR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_ROR_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RSL_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RSL_RingFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RSR_DrvFreq: Integer in interval [0...255]
 * FD14_Tstr_SD_RSR_RingFreq: Integer in interval [0...255]
 * FD14_VehicleSpeedVSOSig: Integer in interval [0...8191]
 * FD14_VehicleSpeedVSOSig_B2: Integer in interval [0...8191]
 * FD14_VehicleStandStillSts: Integer in interval [0...3]
 * FD14_YawRateFailSts_BSM: Integer in interval [0...1]
 * FD14_YawRate_BSM: Integer in interval [0...4095]
 * FD14_hitchLength: Real in interval [100000...250000] with single precision
 * FD14_trailerAngle: Real in interval [-11000...11000] with single precision
 * FL_Lvl: Integer in interval [0...255]
 * FL_Lvl_Adj: Integer in interval [0...1]
 * FR_Lvl: Integer in interval [0...255]
 * FR_Lvl_Adj: Integer in interval [0...1]
 * FT_PAMRequestSts: Integer in interval [0...1]
 * FT_PAM_LedControlSts: Integer in interval [0...3]
 * FrontSensorSts: Integer in interval [0...3]
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
 * GenericFailSts_FD02_PAM: Integer in interval [0...1]
 * GenericFailSts_FD02_SGW: Integer in interval [0...1]
 * GenericFailSts_FD02_TRLR_REV: Integer in interval [0...1]
 * GenericFailSts_FD03_BCM: Integer in interval [0...1]
 * GenericFailSts_FD03_SGW: Integer in interval [0...1]
 * GenericFailSts_FD04_BCM: Integer in interval [0...1]
 * GenericFailSts_FD08_SGW: Integer in interval [0...1]
 * GenericFailSts_FD11_SGW: Integer in interval [0...1]
 * Graphic_CHF: Integer in interval [0...3]
 * Graphic_CHR: Integer in interval [0...3]
 * Graphic_LHF: Integer in interval [0...3]
 * Graphic_LHR: Integer in interval [0...3]
 * Graphic_RHF: Integer in interval [0...3]
 * Graphic_RHR: Integer in interval [0...3]
 * HAS_Status_C2: Integer in interval [0...3]
 * HMICode: Integer in interval [0...255]
 * HU_TRSC_EnableBtn_Sts: Integer in interval [0...2]
 * Heading_Angle_C2: Integer in interval [0...65535]
 * ITBM_TrlrStat: Integer in interval [0...3]
 * IgnitionOnCounter: Integer in interval [0...65535]
 * ImageDefeatRQSts: Integer in interval [0...1]
 * LHFWheelSpeed: Integer in interval [0...8191]
 * LHF_FastPulseCounter: Integer in interval [0...255]
 * LHF_Spin: Integer in interval [0...3]
 * LHRDoorSts: Integer in interval [0...1]
 * LHRWheelSpeed: Integer in interval [0...8191]
 * LHR_FastPulseCounter: Integer in interval [0...255]
 * LHR_Spin: Integer in interval [0...3]
 * LanguageSelection: Integer in interval [0...255]
 * LatAccelerationOffset_BSM: Integer in interval [0...255]
 * LatAcceleration_BSM: Integer in interval [0...4095]
 * LatAcceleration_C2: Integer in interval [0...4095]
 * Latitude_RMSE_C2: Integer in interval [0...255]
 * Line_1_Confidence: Integer in interval [0...15]
 * Line_1_Curvature: Integer in interval [0...65535]
 * Line_1_Curvature_Rate: Integer in interval [0...65535]
 * Line_1_End_Range: Integer in interval [0...127]
 * Line_1_Heading: Integer in interval [0...1023]
 * Line_1_Offset: Integer in interval [0...1023]
 * Line_1_Start_Range: Integer in interval [0...127]
 * Line_2_Confidence: Integer in interval [0...15]
 * Line_2_Curvature: Integer in interval [0...65535]
 * Line_2_Curvature_Rate: Integer in interval [0...65535]
 * Line_2_End_Range: Integer in interval [0...127]
 * Line_2_Heading: Integer in interval [0...1023]
 * Line_2_Offset: Integer in interval [0...1023]
 * Line_2_Start_Range: Integer in interval [0...127]
 * Line_3_Confidence: Integer in interval [0...15]
 * Line_3_Curvature: Integer in interval [0...65535]
 * Line_3_Curvature_Rate: Integer in interval [0...65535]
 * Line_3_End_Range: Integer in interval [0...127]
 * Line_3_Heading: Integer in interval [0...1023]
 * Line_3_Offset: Integer in interval [0...1023]
 * Line_3_Start_Range: Integer in interval [0...127]
 * Line_4_Confidence: Integer in interval [0...15]
 * Line_4_Curvature: Integer in interval [0...65535]
 * Line_4_Curvature_Rate: Integer in interval [0...65535]
 * Line_4_End_Range: Integer in interval [0...127]
 * Line_4_Heading: Integer in interval [0...1023]
 * Line_4_Offset: Integer in interval [0...1023]
 * Line_4_Start_Range: Integer in interval [0...127]
 * LongAccelerationOffset_BSM: Integer in interval [0...255]
 * LongAcceleration_BSM: Integer in interval [0...4095]
 * LongAcceleration_C2: Integer in interval [0...4095]
 * Longitude_RMSE_C2: Integer in interval [0...255]
 * LwsAngle: Integer in interval [0...65535]
 * LwsAngleType: Integer in interval [0...3]
 * LwsSpeed: Integer in interval [0...4095]
 * MRM_STATUS_C2: Integer in interval [0...7]
 * MessageCounter_ADAS_INFO_C2: Integer in interval [0...15]
 * MessageCounter_AGSM2: Integer in interval [0...15]
 * MessageCounter_BCM10: Integer in interval [0...15]
 * MessageCounter_BCM12: Integer in interval [0...15]
 * MessageCounter_BCM2: Integer in interval [0...15]
 * MessageCounter_BCM27: Integer in interval [0...15]
 * MessageCounter_BCM29: Integer in interval [0...15]
 * MessageCounter_BCM9: Integer in interval [0...15]
 * MessageCounter_BRAKE1: Integer in interval [0...15]
 * MessageCounter_BRAKE2: Integer in interval [0...15]
 * MessageCounter_BRAKE2_1: Integer in interval [0...15]
 * MessageCounter_BRAKE3: Integer in interval [0...15]
 * MessageCounter_BRAKE4: Integer in interval [0...15]
 * MessageCounter_BRAKE5: Integer in interval [0...15]
 * MessageCounter_BRAKE7: Integer in interval [0...15]
 * MessageCounter_CVPAM_FD_Control: Integer in interval [0...15]
 * MessageCounter_CVPAM_FD_Data: Integer in interval [0...15]
 * MessageCounter_CVPAM_FD_Data2: Integer in interval [0...15]
 * MessageCounter_CVPAM_FD_Info: Integer in interval [0...15]
 * MessageCounter_DRIVETRAIN3: Integer in interval [0...15]
 * MessageCounter_ENGINE2: Integer in interval [0...15]
 * MessageCounter_ENGINE5: Integer in interval [0...15]
 * MessageCounter_ENGINE7: Integer in interval [0...15]
 * MessageCounter_EPS1: Integer in interval [0...15]
 * MessageCounter_EPS2: Integer in interval [0...15]
 * MessageCounter_GLOB_NAV_C2: Integer in interval [0...15]
 * MessageCounter_TRANSM1: Integer in interval [0...15]
 * MessageCounter_TRANSM2: Integer in interval [0...15]
 * MessageCounter_TRANSM4: Integer in interval [0...15]
 * MessageCounter_TRSCM1: Integer in interval [0...15]
 * MessageCounter_TRSKM_FD_1: Integer in interval [0...15]
 * MessageCounter_Telematic11: Integer in interval [0...15]
 * MessageCounter_Telematic14: Integer in interval [0...15]
 * MessageCounter_Telematic5: Integer in interval [0...15]
 * MoreCamsRQSts: Integer in interval [0...1]
 * OperationalModeSts: Integer in interval [0...15]
 * PAMRequestSts: Integer in interval [0...1]
 * PAMSystemFault: Integer in interval [0...3]
 * PAM_CHIME_REP_RATESts: Integer in interval [0...15]
 * PAM_CHIME_TYPE: Integer in interval [0...15]
 * PAM_LedControlSts: Integer in interval [0...3]
 * PAM_Off_Status: Integer in interval [0...1]
 * PAM_Off_Status_2BT: Integer in interval [0...3]
 * PAM_PopUpRqst: Integer in interval [0...255]
 * PAM_Volume: Integer in interval [0...3]
 * PA_Front_Sensor_Det_Health: Integer in interval [0...3]
 * PA_Lane_Dection_Health: Integer in interval [0...3]
 * PA_Left_Sensor_Det_Health: Integer in interval [0...3]
 * PA_Line_LM_Color: Integer in interval [0...4]
 * PA_Line_LM_Distance: Integer in interval [0...511]
 * PA_Line_LM_Distance_Conf: Integer in interval [0...15]
 * PA_Line_LM_Heading: Integer in interval [0...511]
 * PA_Line_LM_Heading_Conf: Integer in interval [0...15]
 * PA_Line_LM_Style: Integer in interval [0...7]
 * PA_Line_RM_Color: Integer in interval [0...4]
 * PA_Line_RM_Distance: Integer in interval [0...511]
 * PA_Line_RM_Distance_Conf: Integer in interval [0...15]
 * PA_Line_RM_Heading: Integer in interval [0...511]
 * PA_Line_RM_Heading_Conf: Integer in interval [0...15]
 * PA_Line_RM_Style: Integer in interval [0...7]
 * PA_Obj1_Angle: Integer in interval [0...511]
 * PA_Obj1_Angle_2: Integer in interval [0...511]
 * PA_Obj1_Conf: Integer in interval [0...3]
 * PA_Obj1_Range: Integer in interval [0...1023]
 * PA_Obj1_Range_2: Integer in interval [0...1023]
 * PA_Obj1_Type: Integer in interval [0...7]
 * PA_Obj2_Angle: Integer in interval [0...511]
 * PA_Obj2_Angle_2: Integer in interval [0...511]
 * PA_Obj2_Conf: Integer in interval [0...3]
 * PA_Obj2_Range: Integer in interval [0...1023]
 * PA_Obj2_Range_2: Integer in interval [0...1023]
 * PA_Obj2_Type: Integer in interval [0...7]
 * PA_Obj3_Angle: Integer in interval [0...511]
 * PA_Obj3_Angle_2: Integer in interval [0...511]
 * PA_Obj3_Conf: Integer in interval [0...3]
 * PA_Obj3_Range: Integer in interval [0...1023]
 * PA_Obj3_Range_2: Integer in interval [0...1023]
 * PA_Obj3_Type: Integer in interval [0...7]
 * PA_Obj4_Angle: Integer in interval [0...511]
 * PA_Obj4_Angle_2: Integer in interval [0...511]
 * PA_Obj4_Conf: Integer in interval [0...3]
 * PA_Obj4_Range: Integer in interval [0...1023]
 * PA_Obj4_Range_2: Integer in interval [0...1023]
 * PA_Obj4_Type: Integer in interval [0...7]
 * PA_Obj5_Angle: Integer in interval [0...511]
 * PA_Obj5_Angle_2: Integer in interval [0...511]
 * PA_Obj5_Conf: Integer in interval [0...3]
 * PA_Obj5_Range: Integer in interval [0...1023]
 * PA_Obj5_Range_2: Integer in interval [0...1023]
 * PA_Obj5_Type: Integer in interval [0...7]
 * PA_Obj6_Angle: Integer in interval [0...511]
 * PA_Obj6_Angle_2: Integer in interval [0...511]
 * PA_Obj6_Conf: Integer in interval [0...3]
 * PA_Obj6_Range: Integer in interval [0...1023]
 * PA_Obj6_Range_2: Integer in interval [0...1023]
 * PA_Obj6_Type: Integer in interval [0...7]
 * PA_Right_Sensor_Det_Health: Integer in interval [0...3]
 * PA_SideSensor_FrontLeft_Conf: Integer in interval [0...3]
 * PA_SideSensor_FrontLeft_Dist: Integer in interval [0...1023]
 * PA_SideSensor_FrontRight_Conf: Integer in interval [0...3]
 * PA_SideSensor_FrontRight_Dist: Integer in interval [0...1023]
 * PA_SideSensor_RearLeft_Conf: Integer in interval [0...3]
 * PA_SideSensor_RearLeft_Dist: Integer in interval [0...1023]
 * PA_SideSensor_RearRight_Conf: Integer in interval [0...3]
 * PA_SideSensor_RearRight_Dist: Integer in interval [0...1023]
 * PPPA_TurnIndicatorRqst: Integer in interval [0...3]
 * PamChimeVolumeFront: Integer in interval [0...3]
 * PamChimeVolumeRear: Integer in interval [0...3]
 * ParkingManeuverActive: Integer in interval [0...7]
 * PdlPosActual: Integer in interval [0...255]
 * PitchRate_C2: Integer in interval [0...4095]
 * Pitch_RMSE_C2: Integer in interval [0...255]
 * PreviousCanNMState_FD01_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD01_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD02_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD02_BSM2: Integer in interval [0...15]
 * PreviousCanNMState_FD02_CADM2: Integer in interval [0...15]
 * PreviousCanNMState_FD02_EPS: Integer in interval [0...15]
 * PreviousCanNMState_FD02_ORC: Integer in interval [0...15]
 * PreviousCanNMState_FD02_PAM: Integer in interval [0...15]
 * PreviousCanNMState_FD02_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD02_TRLR_REV: Integer in interval [0...15]
 * PreviousCanNMState_FD03_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD03_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD04_BCM: Integer in interval [0...15]
 * PreviousCanNMState_FD08_SGW: Integer in interval [0...15]
 * PreviousCanNMState_FD11_SGW: Integer in interval [0...15]
 * PsngrDoorSts: Integer in interval [0...1]
 * REF_VEH_SPEED: Integer in interval [0...1023]
 * RHFWheelSpeed: Integer in interval [0...8191]
 * RHF_FastPulseCounter: Integer in interval [0...255]
 * RHF_Spin: Integer in interval [0...3]
 * RHRDoorSts: Integer in interval [0...1]
 * RHRWheelSpeed: Integer in interval [0...8191]
 * RHR_FastPulseCounter: Integer in interval [0...255]
 * RHR_Spin: Integer in interval [0...3]
 * RHatchSts: Integer in interval [0...1]
 * RL_Lvl: Integer in interval [0...255]
 * RL_Lvl_Adj: Integer in interval [0...1]
 * RR_Lvl: Integer in interval [0...255]
 * RR_Lvl_Adj: Integer in interval [0...1]
 * RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * RR_PAM_Dist: Integer in interval [0...1023]
 * RR_PAM_StopControlSts: Integer in interval [0...1]
 * RearSensorSts: Integer in interval [0...3]
 * Rear_Brk_Asst: Integer in interval [0...1]
 * RemStActvSts: Integer in interval [0...1]
 * RollRate_C2: Integer in interval [0...4095]
 * Roll_RMSE_C2: Integer in interval [0...255]
 * Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_10: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_11: Integer in interval [0...4294967295]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SPMControlSts: Integer in interval [0...3]
 * SPMFailSts: Integer in interval [0...1]
 * SPMSystemFault: Integer in interval [0...1]
 * SPM_LedControlSts: Integer in interval [0...3]
 * SPM_Screen_Rqst: Integer in interval [0...1]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * SVC_Guidelines: Integer in interval [0...1]
 * Segment_1_Confidence: Integer in interval [0...15]
 * Segment_1_X1: Integer in interval [0...2047]
 * Segment_1_X2: Integer in interval [0...2047]
 * Segment_1_Y1: Integer in interval [0...1023]
 * Segment_1_Y2: Integer in interval [0...1023]
 * Segment_2_Confidence: Integer in interval [0...15]
 * Segment_2_X1: Integer in interval [0...2047]
 * Segment_2_X2: Integer in interval [0...2047]
 * Segment_2_Y1: Integer in interval [0...1023]
 * Segment_2_Y2: Integer in interval [0...1023]
 * Segment_3_Confidence: Integer in interval [0...15]
 * Segment_3_X1: Integer in interval [0...2047]
 * Segment_3_X2: Integer in interval [0...2047]
 * Segment_3_Y1: Integer in interval [0...1023]
 * Segment_3_Y2: Integer in interval [0...1023]
 * Segment_4_Confidence: Integer in interval [0...15]
 * Segment_4_X1: Integer in interval [0...2047]
 * Segment_4_X2: Integer in interval [0...2047]
 * Segment_4_Y1: Integer in interval [0...1023]
 * Segment_4_Y2: Integer in interval [0...1023]
 * Segment_5_Confidence: Integer in interval [0...15]
 * Segment_5_X1: Integer in interval [0...2047]
 * Segment_5_X2: Integer in interval [0...2047]
 * Segment_5_Y1: Integer in interval [0...1023]
 * Segment_5_Y2: Integer in interval [0...1023]
 * Segment_6_Confidence: Integer in interval [0...15]
 * Segment_6_X1: Integer in interval [0...2047]
 * Segment_6_X2: Integer in interval [0...2047]
 * Segment_6_Y1: Integer in interval [0...1023]
 * Segment_6_Y2: Integer in interval [0...1023]
 * Segment_7_Confidence: Integer in interval [0...15]
 * Segment_7_X1: Integer in interval [0...2047]
 * Segment_7_X2: Integer in interval [0...2047]
 * Segment_7_Y1: Integer in interval [0...1023]
 * Segment_7_Y2: Integer in interval [0...1023]
 * Segment_8_Confidence: Integer in interval [0...15]
 * Segment_8_X1: Integer in interval [0...2047]
 * Segment_8_X2: Integer in interval [0...2047]
 * Segment_8_Y1: Integer in interval [0...1023]
 * Segment_8_Y2: Integer in interval [0...1023]
 * ShiftLeverPosition: Integer in interval [0...15]
 * ShiftLeverPositionReq: Integer in interval [0...15]
 * Shifter_ADAS_Inhibit: Integer in interval [0...1]
 * StaticGrid: Integer in interval [0...1]
 * TCASERANGESTATUS: Integer in interval [0...3]
 * TGW_CAMERA_DISP_STAT: Integer in interval [0...15]
 * THA_EPB_Req: Integer in interval [0...3]
 * THA_STAT: Integer in interval [0...7]
 * THA_SpeedLimit_Req: Integer in interval [0...3]
 * THA_SteeringDamping: Integer in interval [0...255]
 * THA_SteeringTorqueInfo: Integer in interval [0...2047]
 * THA_SteeringTorqueReq: Integer in interval [0...3]
 * THA_SteeringTouchStat: Integer in interval [0...3]
 * TRANS_ADAS_Inhibit: Integer in interval [0...1]
 * TRSCMoreCamRQSts: Integer in interval [0...1]
 * TRSC_CenterBtn_Sts: Integer in interval [0...3]
 * TRSC_EnableBtn_Sts: Integer in interval [0...3]
 * TRSC_LED_Stat: Integer in interval [0...3]
 * TRSC_PopupDisp_Info: Integer in interval [0...15]
 * TRSC_RawKnob: Integer in interval [0...511]
 * TRSC_STAT: Integer in interval [0...7]
 * TRSC_SpeedLimit_Req: Integer in interval [0...15]
 * TRSC_SteeringDamping: Integer in interval [0...255]
 * TRSC_SteeringTorqueInfo: Integer in interval [0...1023]
 * TRSC_SteeringTorqueReq: Integer in interval [0...3]
 * TRSC_VehicleStop_Req: Integer in interval [0...3]
 * TargetGear: Integer in interval [0...15]
 * TeAP_e_AlgoState: Integer in interval [0...4294967295]
 * TeAP_e_DispView2: Integer in interval [0...4294967295]
 * TeAP_e_FrntSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_GearShiftReq: Integer in interval [0...4294967295]
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
 * TeAP_e_RearSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_SPMActvStat: Integer in interval [0...4294967295]
 * TeAP_e_SPMLatCtrlReqSts: Integer in interval [0...4294967295]
 * TeAutoPark_e_AutoParkStatus: Integer in interval [0...4294967295]
 * TeAutoPark_e_ChimeReq: Integer in interval [0...4294967295]
 * TeAutoPark_e_ScanDir: Integer in interval [0...4294967295]
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
 * TeTRSC_e_SpdLmtReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCLedSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCPopupDispInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCStrTrqActvReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrHitchLightCtrl: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq_DID: Integer in interval [0...4294967295]
 * TotalOdometer: Integer in interval [0...1048575]
 * TrailerConnectionSts: Integer in interval [0...3]
 * Trailer_Angle: Integer in interval [0...255]
 * Trailer_Angle_Sign: Integer in interval [0...3]
 * Trailer_Calibration: Integer in interval [0...2]
 * TransmissionSailingSts: Integer in interval [0...15]
 * TrlrHitchLight_Cntrl: Integer in interval [0...3]
 * TurnIndicatorSts: Integer in interval [0...3]
 * VIN_MSG: Integer in interval [0...3]
 * VehicleSpeedVSOSig: Integer in interval [0...8191]
 * VehicleStandStillSts: Integer in interval [0...3]
 * VerticalAcceleration_C2: Integer in interval [0...4095]
 * WakeupSource_FD01_ADCM: Integer in interval [0...255]
 * WakeupSource_FD01_BCM: Integer in interval [0...255]
 * WakeupSource_FD01_SGW: Integer in interval [0...255]
 * WakeupSource_FD02_BCM: Integer in interval [0...255]
 * WakeupSource_FD02_BSM2: Integer in interval [0...255]
 * WakeupSource_FD02_CADM2: Integer in interval [0...255]
 * WakeupSource_FD02_EPS: Integer in interval [0...255]
 * WakeupSource_FD02_ORC: Integer in interval [0...255]
 * WakeupSource_FD02_PAM: Integer in interval [0...255]
 * WakeupSource_FD02_SGW: Integer in interval [0...255]
 * WakeupSource_FD02_TRLR_REV: Integer in interval [0...255]
 * WakeupSource_FD03_BCM: Integer in interval [0...255]
 * WakeupSource_FD03_SGW: Integer in interval [0...255]
 * WakeupSource_FD04_BCM: Integer in interval [0...255]
 * WakeupSource_FD08_SGW: Integer in interval [0...255]
 * WakeupSource_FD11_SGW: Integer in interval [0...255]
 * YawRate_BSM: Integer in interval [0...4095]
 * YawRate_C2: Integer in interval [0...4095]
 * YawRate_RMSE_C2: Integer in interval [0...255]
 * aSigConverter_E_DisplayView2_t: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * real32_T: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Array_04Byte: Array with 4 element(s) of type uint8
 * Array_10Byte: Array with 10 element(s) of type uint8
 * Array_11Byte: Array with 11 element(s) of type uint8
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * VIN_DATA: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * E2E_MEP_CheckStateType: Record with elements
 *   LastValidCounter of type uint8
 *   MaxDeltaCounter of type uint8
 *   WaitForFirstData of type boolean
 *   NewDataAvailable of type boolean
 *   LostData of type uint8
 *   Status of type E2E_MEP_CheckStatusType
 *   SyncCounter of type uint8
 *   NoNewOrRepeatedDataCounter of type uint8
 * E2E_MEP_ConfigType: Record with elements
 *   CounterOffset of type uint16
 *   CRCOffset of type uint16
 *   DataID of type uint16
 *   DataIDNibbleOffset of type uint16
 *   DataIDMode of type E2E_MEP_DataIDMode
 *   DataLength of type uint16
 *   MaxDeltaCounterInit of type uint8
 *   MaxNoNewOrRepeatedData of type uint8
 *   SyncCounterInit of type uint8
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * IFOD_Outputs_CVPAMFDData_t: Record with elements
 *   IeFOD_e_FODHealth of type uint32
 *   IeFOD_e_FODConfidence of type uint32
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
 * ME_Proxi_MPU1_0_to_MCU1_0_t: Record with elements
 *   a72_cpu_load of type float32
 *   state of type Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1
 *   PRX_RadioDispTyp_u8 of type uint8
 *   PRX_variantID_u8 of type uint8
 * ME_VehInp_BCM_FD_21_QM: Record with elements
 *   Snow_Plow_Presence of type uint8
 * ME_VehInp_BCM_FD_2_QM: Record with elements
 *   RemStActvSts of type uint8
 *   TurnIndicatorSts of type uint8
 * ME_VehInp_FD14_BRAKE_FD_6_QM: Record with elements
 *   FD14_DriverReq_AxleTrq_Enabled_BSM of type uint8
 * ME_VehInp_FD14_PT_TORQUE_FD_1_QM: Record with elements
 *   FD14_Accel_Pedal_Override of type boolean
 *   FD14_PPPA_TrqEnblRq_Allowed of type uint8
 * ME_VehInp_ORC_FD_1_QM: Record with elements
 *   SBR1RowDriverSeatSts of type uint8
 * ME_VehInp_TRSKM_FD_1_QM: Record with elements
 *   TRSC_CenterBtn_Sts of type uint8
 *   TRSC_EnableBtn_Sts of type uint8
 *   TRSC_RawKnob of type uint16
 * ME_VehInp_to_IpcSignals_QM_t: Record with elements
 *   DataInp_BCM_FD_2 of type ME_VehInp_BCM_FD_2_QM
 *   DataInp_BCM_FD_21 of type ME_VehInp_BCM_FD_21_QM
 *   DataInp_TRSKM_FD_1 of type ME_VehInp_TRSKM_FD_1_QM
 *   DataInp_FD14_BRAKE_FD_6 of type ME_VehInp_FD14_BRAKE_FD_6_QM
 *   DataInp_ORC_FD_1 of type ME_VehInp_ORC_FD_1_QM
 *   DataInp_FD14_PT_TORQUE_FD_1 of type ME_VehInp_FD14_PT_TORQUE_FD_1_QM
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
 * SvsToVCAN_t: Record with elements
 *   IeSVS_b_SPMScrnReq of type boolean
 *   IeSVS_b_ImgDefeatReqSts of type boolean
 *   IeSVS_b_MoreCamsReqSts of type boolean
 *   IeSVS_b_AUXCamReqSts of type boolean
 *   IeSVS_e_DispView2 of type aSigConverter_E_DisplayView2_t
 * TbAP_APSMPAOut_t: Record with elements
 *   IeAP_e_PAMFlt of type TeAP_e_PAMSystemFault
 *   IeAP_e_FrntRearParkSts of type TeAP_e_PAMOffStatus2BT
 *   IeAP_e_FrntSensorActvSts of type TeAP_e_FrntSnsrStatus
 *   IeAP_e_RearSnsrActvSts of type TeAP_e_RearSnsrStatus
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
 * TbAP_PAStateOut_t: Record with elements
 *   IeAP_e_PAMChimeRepnRate of type TeAP_e_PAMChimeRepnRate
 *   IeAP_e_PAMVolSig of type TeAP_e_PAMVolume
 *   IeAP_e_FrntParkLEDSts of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMLedCtrl of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMChimeTyp of type TeAP_e_PAMChimeTyp
 *   IeAP_e_ParkSensePopUpReq of type TeAP_e_PAMPopUpReq
 *   IeAP_b_PAMRearBrkReq of type boolean
 *   IeAP_b_PAMRearCtrlSts of type boolean
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
 *
 *********************************************************************************************************************/


#define SWC_SafeVCANRx_START_SEC_CODE
#include "SWC_SafeVCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SafeVCANRx_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANRx_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_SafeVCANRx_CODE) RE_SafeVCANRx_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANRx_Init
 *********************************************************************************************************************/
  /* DD-ID: {BB9321F1-2B78-496e-BA12-079E44846D92}*/
  static uint8 incr; /*PRQA S 3516*/

    for (incr = 0u; incr < (uint8)LAST_MESSAGE_ID; incr++)
    {
        s_E2E_State_Read[incr].WaitForFirstData = TRUE;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SafeVCANRx_Main
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
 *   Std_ReturnType Rte_Read_R_SSM_QNXState_State_QNX(SSM_QNX_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SystemState_SystemState(SSM_SystemState *data)
 *   Std_ReturnType Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(TbAP_APSMPAOut_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(TbAP_DriveAssistStatOut_t *data)
 *   Std_ReturnType Rte_Read_RpDtcB12852AData_v_DtcData_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpFailSafeReaction_State(boolean *data)
 *   Std_ReturnType Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(TbTHASmVc_FeatureOutputs_t *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_APARequestSts(APARequestSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ASCM_Stat(ASCM_Stat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ASCM_SysFail(ASCM_SysFail *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Active_Park_Mode(Active_Park_Mode *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Active_Park_Prox_Chime(Active_Park_Prox_Chime *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Backup_Cam_Delay(Backup_Cam_Delay *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Brk_Stat(Brk_Stat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_CM_TCH_STAT(CM_TCH_STAT *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_CM_TCH_X_COORD(CM_TCH_X_COORD *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_CM_TCH_Y_COORD(CM_TCH_Y_COORD *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_CameraDisplaySts2(CameraDisplaySts2 *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_CmdIgnSts(CmdIgnSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_DriverDoorSts(DriverDoorSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_DynamicGrid(DynamicGrid *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ECM_THA_Resp(ECM_THA_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ECM_TRSC_Resp(ECM_TRSC_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_EPS_SteeringTouchStat(EPS_SteeringTouchStat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_EPS_SteeringTouq_Resp(EPS_SteeringTouq_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_EPS_THA_DriverTorqueOverride(EPS_THA_DriverTorqueOverride *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_EPS_THA_SteeringTorqueResp(EPS_THA_SteeringTorqueResp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ESS_ENG_ST_W(ESS_ENG_ST_W *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_EngineSts_W(EngineSts_W *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ExternalTemperature(ExternalTemperature *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_FL_Lvl(FL_Lvl *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_FL_Lvl_Adj(FL_Lvl_Adj *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_FR_Lvl(FR_Lvl *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_FR_Lvl_Adj(FR_Lvl_Adj *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_FT_PAMRequestSts(FT_PAMRequestSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines(Fwrd_Cam_Guidelines *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_GearEngaged(GearEngaged *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_GearEngagedForDisplay(GearEngagedForDisplay *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_HAS_Status_C2(HAS_Status_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts(HU_TRSC_EnableBtn_Sts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ITBM_TrlrStat(ITBM_TrlrStat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LHRDoorSts(LHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LanguageSelection(LanguageSelection *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LatAcceleration_BSM(LatAcceleration_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LongAcceleration_BSM(LongAcceleration_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LwsAngle(LwsAngle *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LwsAngleType(LwsAngleType *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_LwsSpeed(LwsSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_MRM_STATUS_C2(MRM_STATUS_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_PAMRequestSts(PAMRequestSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_PamChimeVolumeFront(PamChimeVolumeFront *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_PamChimeVolumeRear(PamChimeVolumeRear *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_PdlPosActual(PdlPosActual *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_PsngrDoorSts(PsngrDoorSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RHRDoorSts(RHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RHatchSts(RHatchSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RL_Lvl(RL_Lvl *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RL_Lvl_Adj(RL_Lvl_Adj *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RR_Lvl(RR_Lvl *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_RR_Lvl_Adj(RR_Lvl_Adj *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Rear_Brk_Asst(Rear_Brk_Asst *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_SVC_Guidelines(SVC_Guidelines *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ShiftLeverPosition(ShiftLeverPosition *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_ShiftLeverPositionReq(ShiftLeverPositionReq *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_Shifter_ADAS_Inhibit(Shifter_ADAS_Inhibit *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TCASERANGESTATUS(TCASERANGESTATUS *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT(TGW_CAMERA_DISP_STAT *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_THA_SteeringTouchStat(THA_SteeringTouchStat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TRANS_ADAS_Inhibit(TRANS_ADAS_Inhibit *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TargetGear(TargetGear *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TrailerConnectionSts(TrailerConnectionSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_TransmissionSailingSts(TransmissionSailingSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_VIN_DATA(uint8 *data)
 *     Argument data: uint8* is of type VIN_DATA
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_VIN_MSG(VIN_MSG *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_VehicleSpeedVSOSig(VehicleSpeedVSOSig *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD02Rx_YawRate_BSM(YawRate_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ACC_Systemsts(FD14_ACC_Systemsts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp(FD14_BSM_THA_Brk_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_BrkPdl_Stat(FD14_BrkPdl_Stat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_BrkTrq(FD14_BrkTrq *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_BrkTrq_Driver(FD14_BrkTrq_Driver *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_Brk_Stat(FD14_Brk_Stat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp(FD14_ECM_THA_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp(FD14_ECM_TRSC_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPBSts(FD14_EPBSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_HandsOnRecognition(FD14_EPS_HandsOnRecognition *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouchStat(FD14_EPS_SteeringTouchStat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_SteeringTouq_Resp(FD14_EPS_SteeringTouq_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride(FD14_EPS_THA_DriverTorqueOverride *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp(FD14_EPS_THA_SteeringTorqueResp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(FD14_ESC_TRSC_Brk_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W(FD14_ESS_ENG_ST_W *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_EngineSts_W(FD14_EngineSts_W *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ExternalBrkRequestsDisabled(FD14_ExternalBrkRequestsDisabled *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_HAS_Status(FD14_HAS_Status *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHFWheelSpeed(FD14_LHFWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_FastPulseCounter(FD14_LHF_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_Spin(FD14_LHF_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHF_WheelSensorFailSts(FD14_LHF_WheelSensorFailSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHRWheelSpeed(FD14_LHRWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_FastPulseCounter(FD14_LHR_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_Spin(FD14_LHR_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LHR_WheelSensorFailSts(FD14_LHR_WheelSensorFailSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LatAccelerationFailSts_BSM(FD14_LatAccelerationFailSts_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LatAccelerationOffset_BSM(FD14_LatAccelerationOffset_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LatAcceleration_BSM(FD14_LatAcceleration_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LongAccelerationFailSts_BSM(FD14_LongAccelerationFailSts_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LongAccelerationOffset_BSM(FD14_LongAccelerationOffset_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LongAcceleration_BSM(FD14_LongAcceleration_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LwsAngle(FD14_LwsAngle *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LwsAngleType(FD14_LwsAngleType *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_LwsSpeed(FD14_LwsSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts(FD14_PAM_Brk_Rq_RspSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ParkingGearShiftReq_BSM(FD14_ParkingGearShiftReq_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_ParkingInterventionSts(FD14_ParkingInterventionSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_PdlPosActual(FD14_PdlPosActual *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_REF_VEH_SPEED(FD14_REF_VEH_SPEED *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHFWheelSpeed(FD14_RHFWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_FastPulseCounter(FD14_RHF_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_Spin(FD14_RHF_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHF_WheelSensorFailSts(FD14_RHF_WheelSensorFailSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHRWheelSpeed(FD14_RHRWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_FastPulseCounter(FD14_RHR_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_Spin(FD14_RHR_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_RHR_WheelSensorFailSts(FD14_RHR_WheelSensorFailSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts(FD14_SPM_Lat_Ctrl_ResponseSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_Slope(FD14_Slope *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_Steering_Column_Torque(FD14_Steering_Column_Torque *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_THA_SteeringTouchStat(FD14_THA_SteeringTouchStat *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig(FD14_VehicleSpeedVSOSig *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2(FD14_VehicleSpeedVSOSig_B2 *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleStandStillSts(FD14_VehicleStandStillSts *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_YawRateFailSts_BSM(FD14_YawRateFailSts_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComSafeFD14Rx_FD14_YawRate_BSM(FD14_YawRate_BSM *data)
 *   Std_ReturnType Rte_Read_RpGearPosition_GearValue(uint8 *data)
 *   Std_ReturnType Rte_Read_RpGearPosition_ShortTermAdjActiveFlag_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
 *   Std_ReturnType Rte_Read_RpNmStateInfo_v_IsNmStateNormal_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpPAM2BTIpcTxStatus_IpcTxDone(boolean *data)
 *   Std_ReturnType Rte_Read_RpPlantMode_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiConfigData_ProxiData(ME_Hydra2defs_S_CodingTableExt_t *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_Fullautomaticparking(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_PAMConfig_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_Parkwithstop_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_SurroundViewCam_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_Trailerhitchassist_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_TyreSz_u16(uint16 *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t(SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Read_RpTRSC_ME_VehOut_TRSC_t(ME_VehOut_TRSC_t *data)
 *   Std_ReturnType Rte_Read_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(ME_VehInp_to_IpcSignals_QM_t *data)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_APARequestSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_Stat(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_SysFail(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Mode(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Prox_Chime(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_Backup_Cam_Delay(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_STAT(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_X_COORD(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_Y_COORD(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_CameraDisplaySts2(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_CmdIgnSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_DriverDoorSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ECM_THA_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ECM_TRSC_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_FT_PAMRequestSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_GearEngaged(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ITBM_TrlrStat(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_LHRDoorSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_LanguageSelection(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_PAMRequestSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeFront(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeRear(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_PsngrDoorSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_RHRDoorSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_RHatchSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_Rear_Brk_Asst(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_SVC_Guidelines(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPosition(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPositionReq(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_TCASERANGESTATUS(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_EPBSts(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_APARequestSts(APARequestSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ASCM_Stat(ASCM_Stat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ASCM_SysFail(ASCM_SysFail data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Active_Park_Mode(Active_Park_Mode data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Active_Park_Prox_Chime(Active_Park_Prox_Chime data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Backup_Cam_Delay(Backup_Cam_Delay data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Brk_Stat(Brk_Stat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_STAT(CM_TCH_STAT data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_X_COORD(CM_TCH_X_COORD data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD(CM_TCH_Y_COORD data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_CameraDisplaySts2(CameraDisplaySts2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_CmdIgnSts(CmdIgnSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_DriverDoorSts(DriverDoorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_DynamicGrid(DynamicGrid data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ECM_THA_Resp(ECM_THA_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ECM_TRSC_Resp(ECM_TRSC_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_EPS_SteeringTouchStat(EPS_SteeringTouchStat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_EPS_SteeringTouq_Resp(EPS_SteeringTouq_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_EPS_THA_DriverTorqueOverride(EPS_THA_DriverTorqueOverride data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_EPS_THA_SteeringTorqueResp(EPS_THA_SteeringTorqueResp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ESS_ENG_ST_W(ESS_ENG_ST_W data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_EngineSts_W(EngineSts_W data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ExternalTemperature(ExternalTemperature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_FL_Lvl(FL_Lvl data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_FL_Lvl_Adj(FL_Lvl_Adj data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_FR_Lvl(FR_Lvl data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_FR_Lvl_Adj(FR_Lvl_Adj data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_FT_PAMRequestSts(FT_PAMRequestSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(Fwrd_Cam_Guidelines data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_GearEngaged(GearEngaged data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_GearEngagedForDisplay(GearEngagedForDisplay data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_HAS_Status_C2(HAS_Status_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_HU_TRSC_EnableBtn_Sts(HU_TRSC_EnableBtn_Sts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ITBM_TrlrStat(ITBM_TrlrStat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LHRDoorSts(LHRDoorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LanguageSelection(LanguageSelection data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LatAcceleration_BSM(LatAcceleration_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LongAcceleration_BSM(LongAcceleration_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LwsAngle(LwsAngle data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LwsAngleType(LwsAngleType data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_LwsSpeed(LwsSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_MRM_STATUS_C2(MRM_STATUS_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_PAMRequestSts(PAMRequestSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_PamChimeVolumeFront(PamChimeVolumeFront data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_PamChimeVolumeRear(PamChimeVolumeRear data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_PdlPosActual(PdlPosActual data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_PsngrDoorSts(PsngrDoorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RHRDoorSts(RHRDoorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RHatchSts(RHatchSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RL_Lvl(RL_Lvl data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RL_Lvl_Adj(RL_Lvl_Adj data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RR_Lvl(RR_Lvl data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_RR_Lvl_Adj(RR_Lvl_Adj data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Rear_Brk_Asst(Rear_Brk_Asst data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_SVC_Guidelines(SVC_Guidelines data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ShiftLeverPosition(ShiftLeverPosition data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_ShiftLeverPositionReq(ShiftLeverPositionReq data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_Shifter_ADAS_Inhibit(Shifter_ADAS_Inhibit data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TCASERANGESTATUS(TCASERANGESTATUS data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(TGW_CAMERA_DISP_STAT data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_THA_SteeringTouchStat(THA_SteeringTouchStat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit(TRANS_ADAS_Inhibit data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TargetGear(TargetGear data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TrailerConnectionSts(TrailerConnectionSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_TransmissionSailingSts(TransmissionSailingSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_VIN_DATA(const uint8 *data)
 *     Argument data: uint8* is of type VIN_DATA
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_VIN_MSG(VIN_MSG data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig(VehicleSpeedVSOSig data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Rx_YawRate_BSM(YawRate_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ACC_Systemsts(FD14_ACC_Systemsts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp(FD14_BSM_THA_Brk_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkPdl_Stat(FD14_BrkPdl_Stat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkTrq(FD14_BrkTrq data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_BrkTrq_Driver(FD14_BrkTrq_Driver data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_Brk_Stat(FD14_Brk_Stat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ECM_THA_Resp(FD14_ECM_THA_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ECM_TRSC_Resp(FD14_ECM_TRSC_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPBSts(FD14_EPBSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition(FD14_EPS_HandsOnRecognition data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouchStat(FD14_EPS_SteeringTouchStat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_SteeringTouq_Resp(FD14_EPS_SteeringTouq_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_THA_DriverTorqueOverride(FD14_EPS_THA_DriverTorqueOverride data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EPS_THA_SteeringTorqueResp(FD14_EPS_THA_SteeringTorqueResp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(FD14_ESC_TRSC_Brk_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(FD14_ESS_ENG_ST_W data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_EngineSts_W(FD14_EngineSts_W data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled(FD14_ExternalBrkRequestsDisabled data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_HAS_Status(FD14_HAS_Status data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed(FD14_LHFWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter(FD14_LHF_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_Spin(FD14_LHF_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts(FD14_LHF_WheelSensorFailSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(FD14_LHRWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(FD14_LHR_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_Spin(FD14_LHR_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts(FD14_LHR_WheelSensorFailSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM(FD14_LatAccelerationFailSts_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM(FD14_LatAccelerationOffset_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM(FD14_LatAcceleration_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM(FD14_LongAccelerationFailSts_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM(FD14_LongAccelerationOffset_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM(FD14_LongAcceleration_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsAngle(FD14_LwsAngle data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsAngleType(FD14_LwsAngleType data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_LwsSpeed(FD14_LwsSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts(FD14_PAM_Brk_Rq_RspSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM(FD14_ParkingGearShiftReq_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_ParkingInterventionSts(FD14_ParkingInterventionSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_PdlPosActual(FD14_PdlPosActual data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED(FD14_REF_VEH_SPEED data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed(FD14_RHFWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter(FD14_RHF_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_Spin(FD14_RHF_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts(FD14_RHF_WheelSensorFailSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(FD14_RHRWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(FD14_RHR_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_Spin(FD14_RHR_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts(FD14_RHR_WheelSensorFailSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts(FD14_SPM_Lat_Ctrl_ResponseSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_Slope(FD14_Slope data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque(FD14_Steering_Column_Torque data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_THA_SteeringTouchStat(FD14_THA_SteeringTouchStat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(FD14_VehicleSpeedVSOSig data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2(FD14_VehicleSpeedVSOSig_B2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts(FD14_VehicleStandStillSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM(FD14_YawRateFailSts_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Rx_FD14_YawRate_BSM(FD14_YawRate_BSM data)
 *   Std_ReturnType Rte_Write_PpVIN_MessageFault_VIN_InvalidValueFlag(boolean data)
 *   Std_ReturnType Rte_Write_PpVIN_MessageFault_VIN_MissingMessageFlag(boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PpMode_VehicleSpeedCheck_Mode(uint8 mode)
 *   Modes of Rte_ModeType_VehicleSpeedCheck:
 *   - RTE_MODE_VehicleSpeedCheck_VehicleSpeedNonZero
 *   - RTE_MODE_VehicleSpeedCheck_VehicleSpeedZero
 *   - RTE_TRANSITION_VehicleSpeedCheck
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpE2EServices_ME_E2E_Check(E2E_MEP_ConfigType *ConfigPtr, E2E_MEP_CheckStateType *StatePtr, uint8 *DataPtr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG, RTE_E_IF_E2EServices_ME_E2E_E_INTERR, RTE_E_IF_E2EServices_ME_E2E_E_INTERR, RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE, RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *   Std_ReturnType Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANRx_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_SafeVCANRx_CODE) RE_SafeVCANRx_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANRx_Main
 *********************************************************************************************************************/
  /* DD-ID: {713D419F-2B01-4a0b-AC21-2EC08802133F}*/
FD14_VehicleSpeedVSOSig v_VehicleSpd_u16;
boolean v_ShortTermAdjActiveFlag_b;
sint8 v_RetVal_s8;
ME_VehInp_to_IpcSignals_QM_t S_VCANtoIPC_QM;
SSM_SystemState SSMSystemState;
static SSM_SystemStateDef previous_SSMMasterState = SSM_STATE_MAX;
static uint16 v_Crank_Delay_Counter_u16 = (uint16)e_ZERO;
static ME_VehInp_to_IpcSignals_t S_VCANtoIPC_Update;
/*Variable to read current Gear Value for IO Control */
static uint8 s_GearPosForced_u8;

/* VCAN Signal Rx-Tx process : On Cyclic Time*/
D_READ_SIGNAL_FROMCOM_FD02(CmdIgnSts,v_Data_u8);  // General: FD2 Not Common READ
D_WRITE_SIGNAL_TOSWC_FD02(CmdIgnSts,v_Data_u8);
f_DTC_Flag_BCM_FD_10_CmdIgnSts(v_Data_u8);
S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts = v_Data_u8;
    
    /*EC1 condition implemented at fault level*/
	if(v_Data_u8 == (uint8)Cx4_RUN)
	{
	  if(v_Crank_Delay_Counter_u16 >= ((uint16)D_CRANKING_TIME))
		  {
			v_CmdIgnsts_u8 = (uint8)TRUE;
			v_CmdIgnsts_Init_u8 = (uint8)TRUE;
		  }
		  else
		  {
			v_CmdIgnsts_u8 = (uint8)FALSE;
			v_Crank_Delay_Counter_u16 = (v_Crank_Delay_Counter_u16 + (uint8)e_ONE);
		  }
	}
	else
	{
	  v_Crank_Delay_Counter_u16 = (uint8)e_ZERO;
	  v_CmdIgnsts_u8 = (uint8)FALSE;
	}

	/*VIN Missing Message : LIMP-IN Action*/
	if((uint8)e_ONE == s_VIN_MM_u8)
	{
		s_VIN_MM_u8 = (uint8)e_ZERO;
		(void) Rte_Write_PpVIN_MessageFault_VIN_MissingMessageFlag(TRUE);
	}

/*Feature Enable Condition Data Read*/
(void)Rte_Read_RpTRSC_ME_VehOut_TRSC_t(&ME_VehOut_TRSC_Data);
(void)Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(&TbAP_APSMPAOut_Data);
(void)Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(&TbAP_DriveAssistStatOut_Data);
(void)Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(&TbTHASmVc_FeatureOutputs_Data);
(void)Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t(&SvsToVCAN_Data);
(void)Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(&TbAP_PAStateOut_Data);
(void)Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(&SafeVCANRx_CVPAMFDData_t);

RX_SafeVCANProcess();

(void)Rte_Read_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(&S_VCANtoIPC_QM);

VStdLib_MemCpy(&S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_2, &S_VCANtoIPC_QM.DataInp_BCM_FD_2, sizeof(ME_VehInp_BCM_FD_2_QM));
VStdLib_MemCpy(&S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_21, &S_VCANtoIPC_QM.DataInp_BCM_FD_21, sizeof(ME_VehInp_BCM_FD_21_QM));
VStdLib_MemCpy(&S_VCANtoIPC.CAN2_to_IPC.DataInp_TRSKM_FD_1, &S_VCANtoIPC_QM.DataInp_TRSKM_FD_1, sizeof(ME_VehInp_TRSKM_FD_1_QM));
VStdLib_MemCpy(&S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_6, &S_VCANtoIPC_QM.DataInp_FD14_BRAKE_FD_6, sizeof(ME_VehInp_FD14_BRAKE_FD_6_QM));
VStdLib_MemCpy(&S_VCANtoIPC.CAN2_to_IPC.DataInp_ORC_FD_1, &S_VCANtoIPC_QM.DataInp_ORC_FD_1, sizeof(ME_VehInp_ORC_FD_1_QM));
VStdLib_MemCpy(&S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_PT_TORQUE_FD_1, &S_VCANtoIPC_QM.DataInp_FD14_PT_TORQUE_FD_1, sizeof(ME_VehInp_FD14_PT_TORQUE_FD_1_QM));

    if (v_RemoteCoreStatus_u8 != ALL_CORE_STATE) /* Return function till CAN data sent to all core once */
{
	F_SendCanDataToRemoteCore();
}
else
{
	/*Check if received CAN data is updated*/
	v_RetVal_s8 = VStdLib_MemCmpLarge(&S_VCANtoIPC, &S_VCANtoIPC_Update, sizeof(ME_VehInp_to_IpcSignals_t));
	if ((sint8)D_ZERO_VAL != v_RetVal_s8)
	{
		/* Send Updated CAN Signal Data to other cores */
		(void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&S_VCANtoIPC, (uint16)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f, (uint16)sizeof(ME_VehInp_to_IpcSignals_t));
		VStdLib_MemCpy(&S_VCANtoIPC_Update, &S_VCANtoIPC, sizeof(ME_VehInp_to_IpcSignals_t));
	}
	else
	{
		/* CAN signal data is not Updated */
	}
}

    (void)Rte_Read_RpFailSafeReaction_State(&v_FailsafeFlag_b);
(void)Rte_Read_RpFromComSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehicleSpd_u16);
if (v_VehicleSpd_u16 > (uint16)D_VEHICLE_SPEED_ZERO)
{
    /*SRS req. 15252854 & 15212114 */
    /*Write mode port of VehicleSpeedCheck_Mode as VehicleSpeedNonZero
     so DCM will send NRC 0x22 for SID 14 or 85*/
    (void)Rte_Switch_PpMode_VehicleSpeedCheck_Mode(RTE_MODE_VehicleSpeedCheck_VehicleSpeedNonZero);
}
else
{
    /*Write mode port of VehicleSpeedCheck_Mode as VehicleSpeedZero
     so DCM will process the request and send postive response for SID 14 or 85*/
    (void)Rte_Switch_PpMode_VehicleSpeedCheck_Mode(RTE_MODE_VehicleSpeedCheck_VehicleSpeedZero);
}

(void)Rte_Read_RpGearPosition_ShortTermAdjActiveFlag_b(&v_ShortTermAdjActiveFlag_b);
if(v_ShortTermAdjActiveFlag_b == FALSE)
{
	/* Send Gear Position from CAN*/
    (void)Rte_Read_RpFromComSafeFD02Rx_ShiftLeverPosition(&s_GearPosForced_u8);
}
else
{
    /*Send forced Gear Position*/
    (void)Rte_Read_RpGearPosition_GearValue(&s_GearPosForced_u8);
}
(void)Rte_Write_PpToSwcSafeFD02Rx_ShiftLeverPosition(s_GearPosForced_u8);

f_DTC_Flag_TRANSM_FD_4_ShiftLeverPosition(s_GearPosForced_u8);

(void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_SurroundViewCam_u8);       /* Reading Single or four camera */
(void)Rte_Read_RpProxiToSWC_Fullautomaticparking(&v_FullAutoParkSystem_u8);  /* Reading PPPA Feature enable condition proxi parameter */
(void)Rte_Read_RpProxiToSWC_PAMConfig_u8(&v_PamConfiguration_u8);            /* Reading RPA/FPA Feature enable condition proxi parameter */
(void)Rte_Read_RpProxiToSWC_Parkwithstop_u8(&v_ParkWithStop_u8);             /* Reading PARB Feature enable condition proxi parameter */
(void)Rte_Read_RpProxiToSWC_Trailerhitchassist_u8(&v_Trailerhitchassist_u8); /* Reading THA Feature enable condition proxi parameter */
(void)Rte_Read_RpProxiConfigData_ProxiData(&codingTableExt_s);

    /* Read SSM master state and update the application accordingly */
    (void)Rte_Read_R_SystemState_SystemState(&SSMSystemState);

    if (previous_SSMMasterState != SSMSystemState.SystemState)
    {
        switch (SSMSystemState.SystemState)
        {
        case SSM_STATE_BOOTING:
            (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_SafeVcanRx, SSM_APPSTATE_INIT);
            break;
        case SSM_STATE_IPCREADY:
        case SSM_STATE_RUNNING:
            (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_SafeVcanRx, SSM_APPSTATE_RUNNING);
            break;
        case SSM_STATE_DEGRADED:
        case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP:
        case SSM_STATE_SHUTTINGDOWN_REMOTECORES:
        case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE:
        case SSM_STATE_OFF:
            (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_SafeVcanRx, SSM_APPSTATE_STOPPED);
            break;
        default:
        	/* Do Nothing */
            break;
        }
        previous_SSMMasterState = SSMSystemState.SystemState;
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void RX_SafeVcan_FROMCOM_TOSWC_Process10_mSecSignal(void)
{
  /* DD-ID: {913ED7FC-7B9E-4b9c-A1F9-889F96F07003}*/
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EngineSts_W,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EngineSts_W,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_ENGINE_FD_2_FD14_EngineSts_W(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_ACC_Systemsts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ACC_Systemsts,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ADAS_FD_INFO.FD14_ACC_Systemsts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_Brk_Stat,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_Brk_Stat,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_Brk_Stat = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EPS_HandsOnRecognition,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPS_HandsOnRecognition,v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_EPS_HandsOnRecognition = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_HAS_Status,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_HAS_Status,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ADAS_FD_INFO.FD14_HAS_Status = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LatAcceleration_BSM,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LatAcceleration_BSM = FD14_LatAcceleration_BSM *  D_FCT_FD14_LatAcceleration_BSM +  D_OFST_FD14_LatAcceleration_BSM ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LatAcceleration_BSM,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_2_FD14_LatAcceleration_BSM(v_Data_u16);
    S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM = (((float32)v_Data_u16 * D_BSM_0_2_FACTOR) - D_BRAKE_FD_2_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LatAccelerationFailSts_BSM,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LatAccelerationFailSts_BSM,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_2_FD14_LatAccelerationFailSts_BSM(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LatAccelerationFailSts_BSM = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LatAccelerationOffset_BSM,v_Data_u8); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LatAccelerationOffset_BSM = FD14_LatAccelerationOffset_BSM *  D_FCT_FD14_LatAccelerationOffset_BSM +  D_OFST_FD14_LatAccelerationOffset_BSM ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LatAccelerationOffset_BSM,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_BRAKE_FD_3_FD14_LatAccelerationOffset_BSM(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LatAccelerationOffset_BSM = (((float32)v_Data_u8 * D_BSM_0_2_FACTOR) - D_BSM_0_2_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHF_FastPulseCounter,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHF_FastPulseCounter,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHF_FastPulseCounter(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHF_Spin,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHF_Spin,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHF_Spin(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHF_WheelSensorFailSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHF_WheelSensorFailSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHF_WheelSensorFailSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_WheelSensorFailSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHFWheelSpeed,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LHFWheelSpeed = FD14_LHFWheelSpeed *  D_FCT_FD14_LHFWheelSpeed +  D_OFST_FD14_LHFWheelSpeed ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHFWheelSpeed,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHFWheelSpeed(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHR_FastPulseCounter,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHR_FastPulseCounter,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHR_FastPulseCounter(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHR_Spin,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHR_Spin,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_BRAKE_FD_3_FD14_LHR_Spin(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_Spin = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHR_WheelSensorFailSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHR_WheelSensorFailSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHR_WheelSensorFailSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_WheelSensorFailSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LHRWheelSpeed,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LHRWheelSpeed = FD14_LHRWheelSpeed *  D_FCT_FD14_LHRWheelSpeed +  D_OFST_FD14_LHRWheelSpeed ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LHRWheelSpeed,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_3_FD14_LHRWheelSpeed(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LongAcceleration_BSM,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LongAcceleration_BSM = FD14_LongAcceleration_BSM *  D_FCT_FD14_LongAcceleration_BSM +  D_OFST_FD14_LongAcceleration_BSM ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LongAcceleration_BSM,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_2_FD14_LongAcceleration_BSM(v_Data_u16);
    S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM = (((float32)v_Data_u16 * D_BSM_0_2_FACTOR) - D_BRAKE_FD_2_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LongAccelerationFailSts_BSM,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LongAccelerationFailSts_BSM,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_2_FD14_LongAccelerationFailSts_BSM(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LongAccelerationFailSts_BSM = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LongAccelerationOffset_BSM,v_Data_u8); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LongAccelerationOffset_BSM = FD14_LongAccelerationOffset_BSM *  D_FCT_FD14_LongAccelerationOffset_BSM +  D_OFST_FD14_LongAccelerationOffset_BSM ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LongAccelerationOffset_BSM,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_BRAKE_FD_3_FD14_LongAccelerationOffset_BSM(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LongAccelerationOffset_BSM = (((float32)v_Data_u8 * D_BSM_0_2_FACTOR)- D_BSM_0_2_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LwsAngle,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LwsAngle = FD14_LwsAngle *  D_FCT_FD14_LwsAngle +  D_OFST_FD14_LwsAngle ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LwsAngle,v_Data_u16);
   f_DTC_Flag_EPS_FD_1_FD14_LwsAngle(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle = (((float32)v_Data_u16 * D_CAN_0_1_FACTOR) - (float32)D_EPS_ANGLE_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LwsAngleType,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LwsAngleType,v_Data_u8);
   f_DTC_Flag_EPS_FD_1_FD14_LwsAngleType(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngleType = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_LwsSpeed,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_LwsSpeed = FD14_LwsSpeed *  D_FCT_FD14_LwsSpeed +  D_OFST_FD14_LwsSpeed ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_LwsSpeed,v_Data_u16);
   f_DTC_Flag_EPS_FD_1_FD14_LwsSpeed(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsSpeed = ((sint16)v_Data_u16 - (sint16)D_EPS_SPEED_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_ParkingGearShiftReq_BSM,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ParkingGearShiftReq_BSM,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_ParkingGearShiftReq_BSM = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_ParkingInterventionSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ParkingInterventionSts,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_ParkingInterventionSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHF_FastPulseCounter,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHF_FastPulseCounter,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHF_FastPulseCounter(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHF_Spin,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHF_Spin,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHF_Spin(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHF_WheelSensorFailSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHF_WheelSensorFailSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHF_WheelSensorFailSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_WheelSensorFailSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHFWheelSpeed,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_RHFWheelSpeed = FD14_RHFWheelSpeed *  D_FCT_FD14_RHFWheelSpeed +  D_OFST_FD14_RHFWheelSpeed ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHFWheelSpeed,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHFWheelSpeed(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHR_FastPulseCounter,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHR_FastPulseCounter,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHR_FastPulseCounter(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHR_Spin,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHR_Spin,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_BRAKE_FD_3_FD14_RHR_Spin(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_Spin = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHR_WheelSensorFailSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHR_WheelSensorFailSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHR_WheelSensorFailSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_WheelSensorFailSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_RHRWheelSpeed,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_RHRWheelSpeed = FD14_RHRWheelSpeed *  D_FCT_FD14_RHRWheelSpeed +  D_OFST_FD14_RHRWheelSpeed ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RHRWheelSpeed,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_3_FD14_RHRWheelSpeed(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_Slope,v_Data_u8); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_Slope = FD14_Slope *  D_FCT_FD14_Slope +  D_OFST_FD14_Slope ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_Slope,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_Slope = ((sint8)v_Data_u8 - (sint8)e_ONE_HUNDRED);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_SPM_Lat_Ctrl_ResponseSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_SPM_Lat_Ctrl_ResponseSts,v_Data_u8);
   f_DTC_Flag_EPS_FD_1_FD14_SPM_Lat_Ctrl_ResponseSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_Steering_Column_Torque,v_Data_u16); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_Steering_Column_Torque = FD14_Steering_Column_Torque *  D_FCT_FD14_Steering_Column_Torque +  D_OFST_FD14_Steering_Column_Torque ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_Steering_Column_Torque,v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque = (((float32)v_Data_u16 * D_TRQ_FACTOR) - (float32)e_EIGHT);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_VehicleSpeedVSOSig,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_VehicleSpeedVSOSig = FD14_VehicleSpeedVSOSig *  D_FCT_FD14_VehicleSpeedVSOSig +  D_OFST_FD14_VehicleSpeedVSOSig ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_VehicleSpeedVSOSig,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_2_FD14_VehicleSpeedVSOSig(v_Data_u16);
    S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_VehicleSpeedVSOSig_B2,v_Data_u16); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_VehicleSpeedVSOSig_B2 = FD14_VehicleSpeedVSOSig_B2 *  D_FCT_FD14_VehicleSpeedVSOSig_B2 +  D_OFST_FD14_VehicleSpeedVSOSig_B2 ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_VehicleSpeedVSOSig_B2,v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE2_FD_1.FD14_VehicleSpeedVSOSig_B2 = ((float32)v_Data_u16 * D_SPEED_CONV_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_YawRate_BSM,v_Data_u16); // ASIL: FD14 Common READ
   // VT: FACT+OFFST :  FD14_YawRate_BSM = FD14_YawRate_BSM *  D_FCT_FD14_YawRate_BSM +  D_OFST_FD14_YawRate_BSM ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_YawRate_BSM,v_Data_u16);
   f_DTC_Flag_BRAKE_FD_2_FD14_YawRate_BSM(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM = (((float32)v_Data_u16 * D_BSM_0_8_FACTOR) - D_BSM_0_8_OFFSET);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_YawRateFailSts_BSM,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_YawRateFailSts_BSM,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_2_FD14_YawRateFailSts_BSM(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_YawRateFailSts_BSM = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(HAS_Status_C2,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(HAS_Status_C2,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ADAS_FD_INFO_C2.HAS_Status_C2 = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(MRM_STATUS_C2,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(MRM_STATUS_C2,v_Data_u8); /*PRQA S 3119*/
   D_READ_SIGNAL_FROMCOM_FD02(TargetGear,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TargetGear,v_Data_u8);
   f_DTC_Flag_TRANSM_FD_1_TargetGear(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_1.TargetGear = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(TRANS_ADAS_Inhibit,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TRANS_ADAS_Inhibit,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_TRANSM_FD_1_TRANS_ADAS_Inhibit(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_1.TRANS_ADAS_Inhibit = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(TransmissionSailingSts,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TransmissionSailingSts,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_1.TransmissionSailingSts = v_Data_u8;
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_ABSActive =(sint8)e_ZERO;
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_3.FD14_Override = (uint8)e_ZERO;
}
static void RX_SafeVcan_FROMCOM_TOSWC_Process20_mSecSignal(void)
{
  /* DD-ID: {B4CBF466-2337-4bff-9712-6F9F5B5E51E7}*/
   D_READ_SIGNAL_FROMCOM_FD14(FD14_PdlPosActual,v_Data_u8); // General: FD14 Common READ
   // VT: FACT+OFFST :  FD14_PdlPosActual = FD14_PdlPosActual *  D_FCT_FD14_PdlPosActual +  D_OFST_FD14_PdlPosActual ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PdlPosActual,v_Data_u8);
   f_DTC_Flag_ENGINE_FD_5_FD14_PdlPosActual(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_5.FD14_PdlPosActual = ((float32)v_Data_u8 * D_ENG_PDL_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD02(GearEngagedForDisplay,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GearEngagedForDisplay,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_TRANSM_FD_2_GearEngagedForDisplay(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_2.GearEngagedForDisplay = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_BrkPdl_Stat,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_BrkPdl_Stat,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_7.FD14_BrkPdl_Stat = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_BrkTrq,v_Data_u16); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_BrkTrq = FD14_BrkTrq *  D_FCT_FD14_BrkTrq +  D_OFST_FD14_BrkTrq ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_BrkTrq,v_Data_u16); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_BrkTrq = (uint16)(v_Data_u16 * (uint8)e_THREE);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_BrkTrq_Driver,v_Data_u16); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_BrkTrq_Driver = FD14_BrkTrq_Driver *  D_FCT_FD14_BrkTrq_Driver +  D_OFST_FD14_BrkTrq_Driver ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_BrkTrq_Driver,v_Data_u16); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_BrkTrq_Driver = (uint16)(v_Data_u16 * (uint8)e_THREE);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_ExternalBrkRequestsDisabled,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ExternalBrkRequestsDisabled,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_ExternalBrkRequestsDisabled = v_Data_u8;
   f_DTC_Flag_BRAKE_FD_1_FD14_ExternalBrkRequestsDisabled(v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD14(FD14_PAM_Brk_Rq_RspSts,v_Data_u8);  // ASIL: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PAM_Brk_Rq_RspSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_7_FD14_PAM_Brk_Rq_RspSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_7.FD14_PAM_Brk_Rq_RspSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_VehicleStandStillSts,v_Data_u8); // ASIL: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_VehicleStandStillSts,v_Data_u8);
   f_DTC_Flag_BRAKE_FD_1_FD14_VehicleStandStillSts(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_VehicleStandStillSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_REF_VEH_SPEED,v_Data_u16); // ASIL: FD14 Not Common READ
   // VT: FACT+OFFST :  FD14_REF_VEH_SPEED = FD14_REF_VEH_SPEED *  D_FCT_FD14_REF_VEH_SPEED +  D_OFST_FD14_REF_VEH_SPEED ;
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_REF_VEH_SPEED,v_Data_u16); /*PRQA S 3119*/
   f_DTC_Flag_BRAKE_FD_1_FD14_REF_VEH_SPEED(v_Data_u16);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_REF_VEH_SPEED = ((float32)v_Data_u16 * D_CAN_0_5_FACTOR);
   D_READ_SIGNAL_FROMCOM_FD02(Shifter_ADAS_Inhibit,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(Shifter_ADAS_Inhibit,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_AGSM_FD_2_Shifter_ADAS_Inhibit(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_AGSM_FD_2.Shifter_ADAS_Inhibit = v_Data_u8;
}
static void RX_SafeVcan_FROMCOM_TOSWC_Process100_mSecSignal(void)
{
   static uint8 v_Data_a7_au8[e_SEVEN];

  /* DD-ID: {3C4C9D4E-B079-4626-A055-45BAEAF9F952}*/
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EPS_SteeringTouchStat,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPS_SteeringTouchStat,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouchStat = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EPS_SteeringTouq_Resp,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPS_SteeringTouq_Resp,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_EPS_FD_2_FD14_EPS_SteeringTouq_Resp(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_SteeringTouq_Resp = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EPS_THA_DriverTorqueOverride,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPS_THA_DriverTorqueOverride,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_DriverTorqueOverride(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_THA_DriverTorqueOverride = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_EPS_THA_SteeringTorqueResp,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPS_THA_SteeringTorqueResp,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_SteeringTorqueResp(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_EPS_THA_SteeringTorqueResp = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_THA_SteeringTouchStat,v_Data_u8); // General: FD14 Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_THA_SteeringTouchStat,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_EPS_FD_2_FD14_THA_SteeringTouchStat(v_Data_u8);
   S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_EPS_FD_2.FD14_THA_SteeringTouchStat = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(VIN_DATA,v_Data_a7_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(VIN_DATA,v_Data_a7_au8);
   D_READ_SIGNAL_FROMCOM_FD02(VIN_MSG,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(VIN_MSG,v_Data_u8);
   f_DTC_Flag_VIN(v_Data_u8);
}

static void RX_SafeVCAN_FROMCOM_TOSWC_Process200_mSecSignal(void)
{
  /* DD-ID: {2F16543F-06D2-478b-8D7F-CEA552C66313}*/
   D_READ_SIGNAL_FROMCOM_FD02(FL_Lvl,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  FL_Lvl = FL_Lvl *  D_FCT_FL_Lvl +  D_OFST_FL_Lvl ;
   D_WRITE_SIGNAL_TOSWC_FD02(FL_Lvl,v_Data_u8); /*PRQA S 3119*/
   f_DTC_Flag_ASCM_FD1_FL_Lvl(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.FL_Lvl = ((sint16)v_Data_u8 - (sint16)e_ONE_HUNDRED);
   D_READ_SIGNAL_FROMCOM_FD02(FL_Lvl_Adj,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(FL_Lvl_Adj,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.FL_Lvl_Adj = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(FR_Lvl,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  FR_Lvl = FR_Lvl *  D_FCT_FR_Lvl +  D_OFST_FR_Lvl ;
   f_DTC_Flag_ASCM_FD1_FR_Lvl(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.FR_Lvl = ((sint16)v_Data_u8 - (sint16)e_ONE_HUNDRED);
   D_WRITE_SIGNAL_TOSWC_FD02(FR_Lvl,v_Data_u8); /*PRQA S 3119*/
   D_READ_SIGNAL_FROMCOM_FD02(FR_Lvl_Adj,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(FR_Lvl_Adj,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.FR_Lvl_Adj = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(RL_Lvl,v_Data_u8);  // General: FD2 Not Common READ
   f_DTC_Flag_ASCM_FD1_RL_Lvl(v_Data_u8);
   // VT: FACT+OFFST :  RL_Lvl = RL_Lvl *  D_FCT_RL_Lvl +  D_OFST_RL_Lvl ;
   D_WRITE_SIGNAL_TOSWC_FD02(RL_Lvl,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.RL_Lvl = ((sint16)v_Data_u8 - (sint16)e_ONE_HUNDRED);
   D_READ_SIGNAL_FROMCOM_FD02(RL_Lvl_Adj,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(RL_Lvl_Adj,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.RL_Lvl_Adj = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(RR_Lvl,v_Data_u8);  // General: FD2 Not Common READ
   f_DTC_Flag_ASCM_FD1_RR_Lvl(v_Data_u8);
   // VT: FACT+OFFST :  RR_Lvl = RR_Lvl *  D_FCT_RR_Lvl +  D_OFST_RR_Lvl ;
   D_WRITE_SIGNAL_TOSWC_FD02(RR_Lvl,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.RR_Lvl = ((sint16)v_Data_u8 - (sint16)e_ONE_HUNDRED);
   D_READ_SIGNAL_FROMCOM_FD02(RR_Lvl_Adj,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(RR_Lvl_Adj,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_1.RR_Lvl_Adj = v_Data_u8;
}

static void RX_SafeVcan_FROMCOM_TOSWC_Process250_mSecSignal(void)
{
  /* DD-ID: {23BD25E0-1003-4793-B229-B069361E3A47}*/
   D_READ_SIGNAL_FROMCOM_FD02(ExternalTemperature,v_Data_u16);  // ASIL: FD2 Not Common READ
   // VT: FACT+OFFST :  ExternalTemperature = ExternalTemperature *  D_FCT_ExternalTemperature +  D_OFST_ExternalTemperature ;
   D_WRITE_SIGNAL_TOSWC_FD02(ExternalTemperature,v_Data_u16);
   f_DTC_Flag_BCM_FD_9_ExternalTemperature(v_Data_u16);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.ExternalTemperature = (((float32)v_Data_u16 * D_CAN_0_5_FACTOR) - (float32)e_EIGHTY_FIVE);
}

static void RX_SafeVcan_FROMCOM_TOSWC_Process1000_mSecSignal(void)
{
  /* DD-ID: {B1FFC695-B948-4401-9352-421D11E8EE33}*/
   D_READ_SIGNAL_FROMCOM_FD02(Backup_Cam_Delay,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(Backup_Cam_Delay,v_Data_u8); /*PRQA S 3119*/
   D_READ_SIGNAL_FROMCOM_FD02(DynamicGrid,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DynamicGrid,v_Data_u8); /*PRQA S 3119*/
   S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.DynamicGrid = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(TrailerConnectionSts,v_Data_u8);  // ASIL: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TrailerConnectionSts,v_Data_u8);
   f_DTC_Flag_BCM_FD_27_TrailerConnectionSts(v_Data_u8);
   S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts = v_Data_u8;
}

static void RX_SafeVcan_EVENT_RX_FROMCOM_TOSWC(void)
{
  /* DD-ID: {68493473-C2D8-48f0-8435-F36E3B42CDFB}*/
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_SVC_Guidelines())
   {
      D_READ_SIGNAL_FROMCOM_FD02(SVC_Guidelines,v_Data_u8);  // ASIL: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(SVC_Guidelines,v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.SVC_Guidelines = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_STAT())
   {
      D_READ_SIGNAL_FROMCOM_FD02(CM_TCH_STAT,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(CM_TCH_STAT,v_Data_u8);
      f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_STAT(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_STAT = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_X_COORD())
   {
      D_READ_SIGNAL_FROMCOM_FD02(CM_TCH_X_COORD,v_Data_u16);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(CM_TCH_X_COORD,v_Data_u16);
      f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_X_COORD(v_Data_u16);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD = v_Data_u16;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_CM_TCH_Y_COORD())
   {
      D_READ_SIGNAL_FROMCOM_FD02(CM_TCH_Y_COORD,v_Data_u16);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(CM_TCH_Y_COORD,v_Data_u16);
      f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_Y_COORD(v_Data_u16);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD = v_Data_u16;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_CameraDisplaySts2())
   {
      D_READ_SIGNAL_FROMCOM_FD02(CameraDisplaySts2,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(CameraDisplaySts2,v_Data_u8);
      f_DTC_Flag_TELEMATIC_FD_5_CameraDisplaySts2(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CameraDisplaySts2 = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_ITBM_TrlrStat())
   {
      D_READ_SIGNAL_FROMCOM_FD02(ITBM_TrlrStat,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(ITBM_TrlrStat,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_BCM_FD_29_ITBM_TrlrStat(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_GearEngaged())
   {
      D_READ_SIGNAL_FROMCOM_FD02(GearEngaged,v_Data_u8);  // ASIL: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(GearEngaged,v_Data_u8);
      f_DTC_Flag_TRANSM_FD_4_GearEngaged(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_4.GearEngaged = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPositionReq())
   {
      D_READ_SIGNAL_FROMCOM_FD02(ShiftLeverPositionReq,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(ShiftLeverPositionReq,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_AGSM_FD_2_ShiftLeverPositionReq(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_AGSM_FD_2.ShiftLeverPositionReq = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_APARequestSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(APARequestSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(APARequestSts, v_Data_u8);
	f_DTC_Flag_BCM_FD_12_APARequestSts(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_12.APARequestSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Mode())
   {
	D_READ_SIGNAL_FROMCOM_FD02(Active_Park_Mode, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(Active_Park_Mode, v_Data_u8); /*PRQA S 3119*/
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Active_Park_Mode = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_Active_Park_Prox_Chime())
   {
	D_READ_SIGNAL_FROMCOM_FD02(Active_Park_Prox_Chime, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(Active_Park_Prox_Chime, v_Data_u8); /*PRQA S 3119*/
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Active_Park_Prox_Chime = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_DriverDoorSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(DriverDoorSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(DriverDoorSts, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_FT_PAMRequestSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(FT_PAMRequestSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(FT_PAMRequestSts, v_Data_u8); /*PRQA S 3119*/
	f_DTC_Flag_BCM_FD_12_FT_PAMRequests(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_12.FT_PAMRequestSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines())
   {
	D_READ_SIGNAL_FROMCOM_FD02(Fwrd_Cam_Guidelines, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(Fwrd_Cam_Guidelines, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Fwrd_Cam_Guidelines = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_LHRDoorSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(LHRDoorSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(LHRDoorSts, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.LHRDoorSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_LanguageSelection())
   {
	D_READ_SIGNAL_FROMCOM_FD02(LanguageSelection, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(LanguageSelection, v_Data_u8);
	f_DTC_Flag_IPC_VEHICLE_SETUP_LanguageSelection(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_PAMRequestSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(PAMRequestSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(PAMRequestSts, v_Data_u8);
	f_DTC_Flag_BCM_FD_12_PAMRequestSts(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_12.PAMRequestSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeFront())
   {
	D_READ_SIGNAL_FROMCOM_FD02(PamChimeVolumeFront, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(PamChimeVolumeFront, v_Data_u8);
	f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeFront(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.PamChimeVolumeFront = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_PamChimeVolumeRear())
   {
	D_READ_SIGNAL_FROMCOM_FD02(PamChimeVolumeRear, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(PamChimeVolumeRear, v_Data_u8);
	f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeRear(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.PamChimeVolumeRear = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_PsngrDoorSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(PsngrDoorSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(PsngrDoorSts, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.PsngrDoorSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_RHRDoorSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(RHRDoorSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(RHRDoorSts, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.RHRDoorSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_RHatchSts())
   {
	D_READ_SIGNAL_FROMCOM_FD02(RHatchSts, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(RHatchSts, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_Rear_Brk_Asst())
   {
	D_READ_SIGNAL_FROMCOM_FD02(Rear_Brk_Asst, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(Rear_Brk_Asst, v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Rear_Brk_Asst = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_ShiftLeverPosition())
   {
	D_READ_SIGNAL_FROMCOM_FD02(ShiftLeverPosition, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(ShiftLeverPosition, v_Data_u8);
	/* f_DTC_Flag_TRANSM_FD_4_ShiftLeverPosition(v_Data_u8);  Defect - 21278854 Fix */
	S_VCANtoIPC.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_TCASERANGESTATUS())
   {
	D_READ_SIGNAL_FROMCOM_FD02(TCASERANGESTATUS, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(TCASERANGESTATUS, v_Data_u8);
	f_DTC_Flag_DRIVETRAIN_FD_3_TCASERANGESTATUS(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_DRIVETRAIN_FD_3.TCASERANGESTATUS = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT())
   {
	D_READ_SIGNAL_FROMCOM_FD02(TGW_CAMERA_DISP_STAT, v_Data_u8); // ASIL: FD2 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD02(TGW_CAMERA_DISP_STAT, v_Data_u8);
	f_DTC_Flag_TELEMATIC_FD_14_TGW_CAMERA_DISP_STAT(v_Data_u8);
	S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp())
   {
	D_READ_SIGNAL_FROMCOM_FD14(FD14_BSM_THA_Brk_Resp, v_Data_u8); // ASIL: FD14 Common READ
	D_WRITE_SIGNAL_TOSWC_FD14(FD14_BSM_THA_Brk_Resp, v_Data_u8); /*PRQA S 3119*/
	f_DTC_Flag_Brake_FD_5_FD14_BSM_THA_Brk_Resp(v_Data_u8);
	S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_5.FD14_BSM_THA_Brk_Resp = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_EPBSts())
   {
	D_READ_SIGNAL_FROMCOM_FD14(FD14_EPBSts, v_Data_u8); // ASIL: FD14 Common READ
	D_WRITE_SIGNAL_TOSWC_FD14(FD14_EPBSts, v_Data_u8); /*PRQA S 3119*/
	f_DTC_Flag_BRAKE_FD_4_FD14_EPBSts(v_Data_u8);
	S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_4.FD14_EPBSts = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }
   if (Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp())
   {
	D_READ_SIGNAL_FROMCOM_FD14(FD14_ESC_TRSC_Brk_Resp, v_Data_u8); // ASIL: FD14 Not Common READ
	D_WRITE_SIGNAL_TOSWC_FD14(FD14_ESC_TRSC_Brk_Resp, v_Data_u8); /*PRQA S 3119*/
	f_DTC_Flag_BRAKE_FD_5_FD14_ESC_TRSC_Brk_Resp(v_Data_u8);
	S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_5.FD14_ESC_TRSC_Brk_Resp = v_Data_u8;
   }
   else
   {
	/*Do nothing*/
   }

   if(Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_Stat())
   {
      D_READ_SIGNAL_FROMCOM_FD02(ASCM_Stat,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(ASCM_Stat,v_Data_u8);
      f_DTC_Flag_ASCM_FD2_ASCM_Stat(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_2.ASCM_Stat = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }

   if(Rte_IsUpdated_RpFromComSafeFD02Rx_ASCM_SysFail())
   {
      D_READ_SIGNAL_FROMCOM_FD02(ASCM_SysFail,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(ASCM_SysFail,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_ASCM_FD2_ASCM_SysFail(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_ASCM_FD_2.ASCM_SysFail = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }

   if(Rte_IsUpdated_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts())
   {
      D_READ_SIGNAL_FROMCOM_FD02(HU_TRSC_EnableBtn_Sts,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(HU_TRSC_EnableBtn_Sts,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_TELEMATIC_FD_11_HU_TRSC_EnableBtn_Sts(v_Data_u8);
      S_VCANtoIPC.CAN2_to_IPC.DataInp_TELEMATIC_FD_11.HU_TRSC_EnableBtn_Sts = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }

   if(Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp())
   {
      D_READ_SIGNAL_FROMCOM_FD14(FD14_ECM_THA_Resp,v_Data_u8); // General: FD14 Common READ
      D_WRITE_SIGNAL_TOSWC_FD14(FD14_ECM_THA_Resp,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_ENGINE_FD_7_FD14_ECM_THA_Resp(v_Data_u8);
      S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_7.FD14_ECM_THA_Resp = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }

    if(Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp())
   {
      D_READ_SIGNAL_FROMCOM_FD14(FD14_ECM_TRSC_Resp,v_Data_u8); // General: FD14 Common READ
      D_WRITE_SIGNAL_TOSWC_FD14(FD14_ECM_TRSC_Resp,v_Data_u8); /*PRQA S 3119*/
      f_DTC_Flag_ENGINE_FD_7_FD14_ECM_TRSC_Resp(v_Data_u8);
      S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_7.FD14_ECM_TRSC_Resp = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }

   if(Rte_IsUpdated_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W())
   {
      D_READ_SIGNAL_FROMCOM_FD14(FD14_ESS_ENG_ST_W,v_Data_u8); // General: FD14 Common READ
      D_WRITE_SIGNAL_TOSWC_FD14(FD14_ESS_ENG_ST_W,v_Data_u8);
      S_VCANtoIPC.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_ESS_ENG_ST_W = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
}

static void RX_SafeVCANProcess(void)
{
  /* DD-ID: {D5E93445-6756-4e94-B71B-82EBE247A000}*/
  uint8 reqItemIndex;
 static EventDataManage_t RX_SafeVCAN_EventDataManage[E_RX_SafeVCNA_Last_EventIndex] =
{
    /*EventID		                               isTriggered_b		EventType_u8		               CounterValue_u32		  PeriodicityTypes_u32		FuncPtrWrite*/
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process10_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  10,                     &RX_SafeVcan_FROMCOM_TOSWC_Process10_mSecSignal },
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process20_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  20,                     &RX_SafeVcan_FROMCOM_TOSWC_Process20_mSecSignal },
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process100_mSecSignal,   0U,              D_TIME_TRIGGERED_EVENT,       0U,                  100,                    &RX_SafeVcan_FROMCOM_TOSWC_Process100_mSecSignal },
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process200_mSecSignal,   0U,              D_TIME_TRIGGERED_EVENT,       0U,                  200,                    &RX_SafeVCAN_FROMCOM_TOSWC_Process200_mSecSignal },
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process250_mSecSignal,   0U,              D_TIME_TRIGGERED_EVENT,       0U,                  250,                    &RX_SafeVcan_FROMCOM_TOSWC_Process250_mSecSignal },
  { E_RX_SafeVCAN_FROMCOM_TOSWC_Process1000_mSecSignal,  0U,              D_TIME_TRIGGERED_EVENT,       0U,                  1000,                   &RX_SafeVcan_FROMCOM_TOSWC_Process1000_mSecSignal },
  { E_RX_SafeVCAN_EVENT_RX_FROMCOM_TOSWC,                   0U,           D_EXTERNAL_TRIGGERED_EVENT,   0U,                  0U,                     &RX_SafeVcan_EVENT_RX_FROMCOM_TOSWC },

};
    for (reqItemIndex = (uint8)E_RX_SafeVCAN_FROMCOM_TOSWC_Process10_mSecSignal; reqItemIndex < (uint8)E_RX_SafeVCNA_Last_EventIndex; reqItemIndex++)
  {
    if(RX_SafeVCAN_EventDataManage[reqItemIndex].EventType_u8 == D_TIME_TRIGGERED_EVENT)
    {
          RX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32+=TASKREPRATE;
          if(RX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32 >= RX_SafeVCAN_EventDataManage[reqItemIndex].PeriodicityTypes_u32)
          {
              RX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32 = TASKREPRATE;
              RX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ONE;
          }
    }
    else if(RX_SafeVCAN_EventDataManage[reqItemIndex].EventType_u8 == D_EXTERNAL_TRIGGERED_EVENT)
    {
      RX_SafeVCAN_EventDataManage[reqItemIndex].FuncPtrWrite();
    }
	else
	{
		/*Do Nothing*/
	}
  }

    for (reqItemIndex = 0; reqItemIndex < (uint8)E_RX_SafeVCNA_Last_EventIndex; reqItemIndex++)
  {
        if(RX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b == (uint8)e_ONE)
      {
          RX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ZERO;
          RX_SafeVCAN_EventDataManage[reqItemIndex].FuncPtrWrite();

      }
  }
}


/**********************************************************************************************************************
                                  * Signal Timeout Call Start
 *********************************************************************************************************************/

static void f_DTC_Flag_BCM_FD_9_ExternalTemperature(ExternalTemperature v_fData_u16)
{
  /* DD-ID: {B06D1436-9C3D-43c1-8622-11E4A8F07DA0}*/
    static uint8 v_Set_ExternalTemperature_u8 = (uint8)e_ZERO;
    static uint8 s_flag_ExternalTemperature_u8 = (uint8)e_ZERO;

    if(EXT_TEMP_SNA == v_fData_u16) 
    {
        if(((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_TWELVE <= v_Set_ExternalTemperature_u8)
            {
                if ((uint8)e_ONE != s_flag_ExternalTemperature_u8)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM9_Ext_Temp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_ExternalTemperature_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_ExternalTemperature_u8++;
            }
        }
        else
        {
            v_Set_ExternalTemperature_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_ExternalTemperature_u8 = (uint8)e_ZERO;
        if ((uint8)e_TWO != s_flag_ExternalTemperature_u8)
        {
          (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM9_Ext_Temp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
          s_flag_ExternalTemperature_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BCM_FD_10_CmdIgnSts(CmdIgnSts v_fData_u8)
{
  /* DD-ID: {E248463E-186C-45fc-8468-4A91B2F865BE}*/
    static uint16 v_Set_CmdIgnSts_u16 = (uint16)e_ZERO;
    static uint8 s_flag_CmdIgnSts_u8 = (uint8)e_ZERO;

    if(((uint8)CMD_IG_STATUS_INVALID_1 == v_fData_u8) || ((uint8)CMD_IG_STATUS_INVALID_2 == v_fData_u8) || ((uint8)CMD_IG_STATUS_SNA == v_fData_u8))
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (v_CmdIgnsts_Init_u8 == TRUE))
        {
            if (MATURATION_CNT_THREE_HUNDRED <= v_Set_CmdIgnSts_u16)
            {
                if (s_flag_CmdIgnSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM10_CmdIgnSt_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_CmdIgnSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_CmdIgnSts_u16++;
            }
        }
        else
        {
            v_Set_CmdIgnSts_u16 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_CmdIgnSts_u16 = (uint8)e_ZERO;
        if(s_flag_CmdIgnSts_u8 != (uint8)e_TWO)
        {
          (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM10_CmdIgnSt_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
          s_flag_CmdIgnSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BCM_FD_27_TrailerConnectionSts(TrailerConnectionSts v_fData_u8)
{
  /* DD-ID: {9A1403F2-1A4C-4c8c-B150-86D04F92F1CC}*/
    static uint8 v_Set_TrailerConnectionSts_u8 = (uint8)e_ZERO;
    static uint8 s_flag_TrailerConnectionSts_u8 = (uint8)e_ZERO;

    if(((uint8)TRLR_CONN_STS_NOTUSED == v_fData_u8) || ((uint8)TRLR_CONN_STS_SNA == v_fData_u8))
    {
        if(((FULL_PPPA_FEATURE) ||(TRSC_FEATURE)|| (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE <= v_Set_TrailerConnectionSts_u8)
            {
                if (s_flag_TrailerConnectionSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM27_TrailrConnSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_TrailerConnectionSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TrailerConnectionSts_u8++;
            }
        }
        else
        {
            v_Set_TrailerConnectionSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TrailerConnectionSts_u8 = (uint8)e_ZERO;
        if(s_flag_TrailerConnectionSts_u8 != (uint8)e_TWO)
        {       
          (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM27_TrailrConnSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
          s_flag_TrailerConnectionSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_DRIVETRAIN_FD_3_TCASERANGESTATUS(TCASERANGESTATUS v_fData_u8)
{
  /* DD-ID: {6E34E2D6-A12D-4cd9-865C-0791ADE54C26}*/
    static uint16 v_Set_TCASERANGESts_u16 = (uint16)e_ZERO;
    static uint8 s_flag_TCASERANGESts_u8 = (uint8)e_ZERO;

    if((uint8)DRIVETRAIN_SNA == v_fData_u8)
    {
        if((codingTableExt_s.CanNode67dtcm_uint8 == TRUE) && ((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THIRTY <= v_Set_TCASERANGESts_u16)
            {
                if (s_flag_TCASERANGESts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_DRIVETRAIN3_TCASERANGESts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_TCASERANGESts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TCASERANGESts_u16++;
            }
        }
        else
        {
            v_Set_TCASERANGESts_u16 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TCASERANGESts_u16 = (uint8)e_ZERO;
        if (s_flag_TCASERANGESts_u8 != (uint8)e_TWO)
        {       
          (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_DRIVETRAIN3_TCASERANGESts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
          s_flag_TCASERANGESts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_IPC_VEHICLE_SETUP_LanguageSelection(LanguageSelection v_fData_u8)
{
  /* DD-ID: {DA1E480D-21F5-4b87-8FC1-3AEC4D16D4A4}*/
    static uint8 v_Set_LanguageSelection_u8 = (uint8)e_ZERO;
    static uint8 s_flag_LanguageSelection_u8 = (uint8)e_ZERO;
    /*Language selection range is upto 0x15 which is equal to 21 in decimal REQ 16645960 , 16645962 */
    if((uint8)LANGUAGE_SEL_INVALID_RANGE < v_fData_u8)
    {
        if(((FULL_PPPA_FEATURE) ||(THA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE <= v_Set_LanguageSelection_u8)
            {
                if (s_flag_LanguageSelection_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_LangSel_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_LanguageSelection_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_LanguageSelection_u8++;

            }
        }
        else
        {
            v_Set_LanguageSelection_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_LanguageSelection_u8 = (uint8)e_ZERO;
        if (s_flag_LanguageSelection_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_LangSel_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_LanguageSelection_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeFront(PamChimeVolumeFront v_fData_u8)
{
  /* DD-ID: {29A2E218-E1D7-4639-B393-D75FF37AFB3F}*/
  static uint8 v_Set_PamChimeVolumeFront_u8 = (uint8)e_ZERO;
  static uint8 s_flag_PamChimeVolumeFront_u8 = (uint8)e_ZERO;

    if ((uint8)PAM_CHIME_VOL_FRONT_INVALID == v_fData_u8)
    {
        if((PA_FEATURE) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE <= v_Set_PamChimeVolumeFront_u8)
            {
                if (s_flag_PamChimeVolumeFront_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_F_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_PamChimeVolumeFront_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_PamChimeVolumeFront_u8++;
            }
        }
        else
        {
            v_Set_PamChimeVolumeFront_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_PamChimeVolumeFront_u8 = (uint8)e_ZERO;
        if (s_flag_PamChimeVolumeFront_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_F_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_PamChimeVolumeFront_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_IPC_VEHICLE_SETUP_PamChimeVolumeRear(PamChimeVolumeRear v_fData_u8)
{
  /* DD-ID: {D0047960-AB3F-4837-A66C-2F8727AA9868}*/
  static uint8 v_Set_PamChimeVolumeRear_u8 = (uint8)e_ZERO;
  static uint8 s_flag_PamChimeVolumeRear_u8 = (uint8)e_ZERO;

    if ((uint8)PAM_CHIME_VOL_REAR_INVALID == v_fData_u8) 
    {
        if((PA_FEATURE) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE <= v_Set_PamChimeVolumeRear_u8)
            {
                if (s_flag_PamChimeVolumeRear_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_R_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_PamChimeVolumeRear_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_PamChimeVolumeRear_u8++;
            }
        }
		else
		{
			v_Set_PamChimeVolumeRear_u8 = (uint8)e_ZERO;
		}
    }
    else
    {
        v_Set_PamChimeVolumeRear_u8 = (uint8)e_ZERO;
        if (s_flag_PamChimeVolumeRear_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_R_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_PamChimeVolumeRear_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TRANSM_FD_1_TargetGear(TargetGear v_fData_u8)
{
  /* DD-ID: {C9276F20-7003-4683-9AF4-05E8FFB72450}*/
  static uint8 v_Set_TargetGear_u8 = (uint8)e_ZERO;
  static uint8 s_flag_TargetGear_u8 = (uint8)e_ZERO;

    if (((uint8)TARGET_GEAR_UNSED1 == v_fData_u8) || ((uint8)TARGET_GEAR_UNSED2 == v_fData_u8) || ((uint8)TARGET_GEAR_UNSED3 == v_fData_u8) || ((uint8)TARGET_GEAR_SNA == v_fData_u8))
    {
        if (((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
        {       
            if (MATURATION_CNT_ONE_HUNDRED <= v_Set_TargetGear_u8)
            {
                if (s_flag_TargetGear_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM1_TargetGear_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_TargetGear_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TargetGear_u8++;
            }
        }
        else
        {
            v_Set_TargetGear_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TargetGear_u8 = (uint8)e_ZERO;
        if(s_flag_TargetGear_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM1_TargetGear_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_TargetGear_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TRANSM_FD_1_TRANS_ADAS_Inhibit(TRANS_ADAS_Inhibit v_fData_u8)
{
  /* DD-ID: {00B40EC3-935A-4d06-B752-BC4220A3D768}*/
  static uint8 v_Set_TRANS_ADAS_Inhibit_u8 = (uint8)e_ZERO;
  static uint8 s_flag_TRANS_ADAS_Inhibit_u8 = (uint8)e_ZERO;

    /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    if((uint8)TRANS_ADAS_FAULTED == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) && (CMD_IGN_STATUS) && ((uint8)e_ONE == v_SurroundViewCam_u8))
        {
            if (MATURATION_CNT_ONE_HUNDRED <= v_Set_TRANS_ADAS_Inhibit_u8)
            {
                if (s_flag_TRANS_ADAS_Inhibit_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM1_ADAS_Inhibit_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_TRANS_ADAS_Inhibit_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TRANS_ADAS_Inhibit_u8++;
            }
        }
        else
        {
            v_Set_TRANS_ADAS_Inhibit_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TRANS_ADAS_Inhibit_u8 = (uint8)e_ZERO;
        if(s_flag_TRANS_ADAS_Inhibit_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM1_ADAS_Inhibit_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_TRANS_ADAS_Inhibit_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TRANSM_FD_4_GearEngaged(GearEngaged v_fData_u8)
{
  /* DD-ID: {9418B250-895A-45d9-A7A9-BDB09AF11F7D}*/
  static uint8 v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
  static uint8 s_flag_GearEngaged_u8 = (uint8)e_ZERO;

    if(((uint8)GEAR_ENG_UNSED1 == v_fData_u8) || ((uint8)GEAR_ENG_UNSED2 == v_fData_u8) || ((uint8)GEAR_ENG_UNSED3 == v_fData_u8) || ((uint8)GEAR_ENG_SNA == v_fData_u8)) 
    {
        if(((FULL_PPPA_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE <= v_Set_ITBM_TrlrStat_u8)
            {
                if (s_flag_GearEngaged_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM4_GearEngd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_GearEngaged_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_ITBM_TrlrStat_u8++;
            }
        }
        else
        {
            v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
        if(s_flag_GearEngaged_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM4_GearEngd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_GearEngaged_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TRANSM_FD_4_ShiftLeverPosition(ShiftLeverPosition v_fData_u8)
{
  /* DD-ID: {3DAB0044-1708-4591-999B-39A28A44DDBB}*/
  static uint16 v_Set_ShiftLeverPosition_u16 = (uint8)e_ZERO;   
  static uint8 s_flag_ShiftLeverPosition_u8 = (uint8)e_ZERO;

    if(((uint8)SHIFTLEVERPOS_NOTUSED <= v_fData_u8) && (v_fData_u8 <= (uint8)SHIFTLEVERPOS_SNA))
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (MATURATION_CNT_THREE_HUNDRED <= v_Set_ShiftLeverPosition_u16)  
            {
                if (s_flag_ShiftLeverPosition_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM4_ShiftLvrPos_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_ShiftLeverPosition_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_ShiftLeverPosition_u16++;
            }
        }
        else
        {
           v_Set_ShiftLeverPosition_u16 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_ShiftLeverPosition_u16 = (uint8)e_ZERO;
        if(s_flag_ShiftLeverPosition_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM4_ShiftLvrPos_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_ShiftLeverPosition_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TELEMATIC_FD_14_TGW_CAMERA_DISP_STAT(TGW_CAMERA_DISP_STAT v_fData_u8)
{
  /* DD-ID: {00D328B9-4C63-4ff0-8FA6-DDEAB3E6A9DE}*/
  static uint8 v_Set_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_ZERO;
  static uint8 s_flag_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_ZERO;

    if((uint8)TGW_CAMERA_DISP_STAT_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            if (MATURATION_CNT_THREE <= v_Set_TGW_CAMERA_DISP_STAT_u8)
            {
                if (s_flag_TGW_CAMERA_DISP_STAT_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT14_TGW_Cam_Disp_St_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TGW_CAMERA_DISP_STAT_u8++;
            }
        }
        else
        {
            v_Set_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_ZERO;
        if(s_flag_TGW_CAMERA_DISP_STAT_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT14_TGW_Cam_Disp_St_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_TGW_CAMERA_DISP_STAT_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BCM_FD_12_APARequestSts(APARequestSts v_fData_u8)
{
  /* DD-ID: {430CDBE0-8B86-4175-8082-969DDCA9EF52}*/
    static uint8 s_flag_APARequestSts_u8 = (uint8)e_ZERO;
	uint8 v_PlantMode_u8;

    (void)Rte_Read_RpPlantMode_Status(&v_PlantMode_u8);


    /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    /* Req. ID : 21245200  Defect:20944364*/
    if((uint8)APAREQUEST_STS_PRESSESD == v_fData_u8) 
    {
        if((((uint8)e_ONE == v_SurroundViewCam_u8) && (FULL_PPPA_FEATURE_PPPA_STUCK_SWITCH)) || (v_PlantMode_u8 == TRUE))
        {
            if ((uint8)e_ONE != s_flag_APARequestSts_u8)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_APAReqSts_Stuck_Fault, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_APARequestSts_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if (s_flag_APARequestSts_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_APAReqSts_Stuck_Fault, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_APARequestSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BCM_FD_12_PAMRequestSts(PAMRequestSts v_fData_u8)
{
  /* DD-ID: {8B50FFE6-BCD5-444a-A789-2B14F97E8EAC}*/
    static uint8 s_flag_PAMRequestSts_u8 = (uint8)e_ZERO;
    uint8 v_DtcB12852AStatus;
	uint8 v_PlantMode_u8;
    boolean v_PAM2BTIpcTxDone;

    (void)Rte_Read_RpPlantMode_Status(&v_PlantMode_u8);
    (void)Rte_Read_RpPAM2BTIpcTxStatus_IpcTxDone(&v_PAM2BTIpcTxDone);

    if ((uint8)PAMREQUEST_STS_PRESSESD == v_fData_u8) 
    {
        if((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE) || (v_PlantMode_u8 == TRUE))
        {
            if (((uint8)e_ONE != s_flag_PAMRequestSts_u8) && ((boolean)FALSE != v_PAM2BTIpcTxDone))
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_PAMReqSts_Stuck_Fault, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_PAMRequestSts_u8 = (uint8)e_ONE;
                (void)Rte_Read_RpDtcB12852AData_v_DtcData_u8(&v_DtcB12852AStatus);              /* Read DTC B1285-2A set */
                if(v_DtcB12852AStatus == TRUE)
                {
                    SET_BIT(v_DTCB12852AIPCBlockWrite_u8,0u);                                     /* Set First Bit */
                    TbNVM_ReadParam_Data.Dtc_B12852A_Status = v_DTCB12852AIPCBlockWrite_u8;
                    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TbNVM_ReadParam_Data,(uint16)e_IpcMsgId_Data_TbNVM_ReadParam,(uint16)sizeof(TbNVM_ReadParam));     /* Update Status on IPC */
                }
                else
                {
					/*Do nothing*/
                }
            }
            else
            {
				/*Do nothing*/
            }
        }
        else
        {
			/*Do nothing*/
        }
    }
    else 
    {
        if (((uint8)e_TWO != s_flag_PAMRequestSts_u8) && ((boolean)FALSE != v_PAM2BTIpcTxDone))
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_PAMReqSts_Stuck_Fault, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_PAMRequestSts_u8 = (uint8)e_TWO;
            CLR_BIT(v_DTCB12852AIPCBlockWrite_u8,0u);                                                                          /* Clear First Bit */
            TbNVM_ReadParam_Data.Dtc_B12852A_Status = v_DTCB12852AIPCBlockWrite_u8;
            /* IPC Block Write */
            (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TbNVM_ReadParam_Data,(uint16)e_IpcMsgId_Data_TbNVM_ReadParam,(uint16)sizeof(TbNVM_ReadParam));                   /* Update Status on IPC */
        }
        else
        {
			/*Do nothing*/
        }
    }
}

static void f_DTC_Flag_BCM_FD_12_FT_PAMRequests(FT_PAMRequestSts v_fData_u8)
{
  /* DD-ID: {879A3E10-8CD2-4479-A02F-6DE345644452}*/
	static uint8 s_flag_FT_PAMRequestSts_u8 = (uint8)e_ZERO;
	uint8 v_DtcB12852AStatus;
	uint8 v_PlantMode_u8;
    boolean v_PAM2BTIpcTxDone;

    (void)Rte_Read_RpPlantMode_Status(&v_PlantMode_u8);
    (void)Rte_Read_RpPAM2BTIpcTxStatus_IpcTxDone(&v_PAM2BTIpcTxDone);

    if((uint8)FT_PAMREQUEST_STS_PRESSESD == v_fData_u8) 
    {
        if((PA_FEATURE) || (FULL_PPPA_FEATURE) || (v_PlantMode_u8 == TRUE))
        {
            if (((uint8)e_ONE != s_flag_FT_PAMRequestSts_u8) && ((boolean)FALSE != v_PAM2BTIpcTxDone))
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_FTPAMReqSts_Stuck_Fault, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FT_PAMRequestSts_u8 = (uint8)e_ONE;
                (void)Rte_Read_RpDtcB12852AData_v_DtcData_u8(&v_DtcB12852AStatus);               /* Read DTC B1285-2A set */
                if(v_DtcB12852AStatus == TRUE)
                {
                    SET_BIT(v_DTCB12852AIPCBlockWrite_u8,1u);                                      /* Set second Bit */
                    TbNVM_ReadParam_Data.Dtc_B12852A_Status = v_DTCB12852AIPCBlockWrite_u8;
                    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TbNVM_ReadParam_Data,(uint16)e_IpcMsgId_Data_TbNVM_ReadParam,(uint16)sizeof(TbNVM_ReadParam));      /* Update Status on IPC */
                }
                else
                {
					/*Do nothing*/
                }
            }
            else
            {
				/*Do nothing*/
            }
        }
        else
        {
			/*Do nothing*/
        }
    }
    else
    {
        if (((uint8)e_TWO != s_flag_FT_PAMRequestSts_u8) && ((boolean)FALSE != v_PAM2BTIpcTxDone))
        {
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM12_FTPAMReqSts_Stuck_Fault, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_FT_PAMRequestSts_u8 = (uint8)e_TWO;
            CLR_BIT(v_DTCB12852AIPCBlockWrite_u8,1u);                                          /* Clear second Bit */
            TbNVM_ReadParam_Data.Dtc_B12852A_Status = v_DTCB12852AIPCBlockWrite_u8;
            /* IPC Block Write */
            (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&TbNVM_ReadParam_Data,(uint16)e_IpcMsgId_Data_TbNVM_ReadParam,(uint16)sizeof(TbNVM_ReadParam));           /* Update Status In IPC */
        }
        else
        {
			/*Do nothing*/
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_1_FD14_REF_VEH_SPEED(FD14_REF_VEH_SPEED v_fData_u16)
{
  /* DD-ID: {A9FFE62C-F311-4d26-94F7-3C3725AA7D2C}*/
  static uint8 v_Set_FD14_REF_VEH_SPEED_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_REF_VEH_SPEED_u8 = (uint8)e_ZERO;

    if ((uint16)REF_VEH_SPEED_SNA == v_fData_u16)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE))
        { 
            if (v_Set_FD14_REF_VEH_SPEED_u8 >= (uint8)MATURATION_CNT_TWENTY_FIVE)
            {
                if (s_flag_FD14_REF_VEH_SPEED_u8 != (uint8)e_ONE)
                {
                   (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE1_REF_VEH_SPD_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_REF_VEH_SPEED_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_REF_VEH_SPEED_u8++;
            }
        }
        else
        {
         v_Set_FD14_REF_VEH_SPEED_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_REF_VEH_SPEED_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_REF_VEH_SPEED_u8 != (uint8)e_TWO)
        {       
         (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE1_REF_VEH_SPD_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
         s_flag_FD14_REF_VEH_SPEED_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_1_FD14_VehicleStandStillSts(FD14_VehicleStandStillSts v_fData_u8)
{
  /* DD-ID: {EF0BB909-6B4E-42b9-87AB-BA46773E7C85}*/
  static uint8 v_Set_FD14_VehicleStandStillSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_VehicleStandStillSts_u8 = (uint8)e_ZERO;

    if((uint8)VEH_STANDSTILL_STS_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_FD14_VehicleStandStillSts_u8 >= (uint8)MATURATION_CNT_TWENTY_FIVE)
            {
                if (s_flag_FD14_VehicleStandStillSts_u8 != (uint8)e_ONE)
                {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE1_VehStandStillSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_VehicleStandStillSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_VehicleStandStillSts_u8++;
            }
        }
        else
        {
            v_Set_FD14_VehicleStandStillSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_VehicleStandStillSts_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_VehicleStandStillSts_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE1_VehStandStillSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_VehicleStandStillSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_LatAcceleration_BSM(FD14_LatAcceleration_BSM v_fData_u16)
{
  /* DD-ID: {EE711BDF-163B-4168-B0B1-753029484BB9}*/
  static uint8 v_Set_LatAcceleration_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LatAcceleration_BSM_u8 = (uint8)e_ZERO;

    if((uint16)LAT_ACC_BSM_SNA == v_fData_u16) 
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_LatAcceleration_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LatAcceleration_BSM_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LatAcc_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LatAcceleration_BSM_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_LatAcceleration_BSM_u8++;
            }
        }
        else
        {
            v_Set_LatAcceleration_BSM_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_LatAcceleration_BSM_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LatAcceleration_BSM_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LatAcc_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LatAcceleration_BSM_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_LatAccelerationFailSts_BSM(FD14_LatAccelerationFailSts_BSM v_fData_u8)
{
  /* DD-ID: {92D3F10A-EDFC-4ae0-9CA6-EA1619FE33F2}*/
  static uint8 v_Set_LatAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LatAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;

    if((uint8)LAT_ACC_BSM_FAIL == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_LatAccelerationFailSts_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LatAccelerationFailSts_BSM_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LatAcc_FailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LatAccelerationFailSts_BSM_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_LatAccelerationFailSts_BSM_u8++;
            }
        }
        else
        {
            v_Set_LatAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_LatAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LatAccelerationFailSts_BSM_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LatAcc_FailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LatAccelerationFailSts_BSM_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_LongAccelerationFailSts_BSM(FD14_LongAccelerationFailSts_BSM v_fData_u8)
{
  /* DD-ID: {24844433-6480-47aa-A107-2DF3A6AD7071}*/
  static uint8 v_Set_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;

    if((uint8)LONG_ACC_BSM_FAIL == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_FD14_LongAccelerationFailSts_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LongAccelerationFailSts_BSM_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LongAcc_FailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_LongAccelerationFailSts_BSM_u8++;
            }
        }
        else
        {
            v_Set_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;  
        }
    }
    else
    {
        v_Set_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LongAccelerationFailSts_BSM_u8 != (uint8)e_TWO)
        {       
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LongAcc_FailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_FD14_LongAccelerationFailSts_BSM_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_LongAcceleration_BSM(FD14_LongAcceleration_BSM v_fData_u16)
{
  /* DD-ID: {CC2AFC12-5F7A-48e8-87CB-1BB80C4FA77B}*/
  static uint8 v_Set_LongAccleration_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LongAcceleration_BSM_u8 = (uint8)e_ZERO;

    if((uint16)LONG_ACC_BSM_SNA == v_fData_u16) 
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_LongAccleration_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LongAcceleration_BSM_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LongAcc_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LongAcceleration_BSM_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_LongAccleration_BSM_u8++;
            }
        }
        else
        {
            v_Set_LongAccleration_BSM_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_LongAccleration_BSM_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LongAcceleration_BSM_u8 != (uint8)e_TWO)
        {       
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_LongAcc_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_FD14_LongAcceleration_BSM_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_VehicleSpeedVSOSig(FD14_VehicleSpeedVSOSig v_fData_u16)
{
  /* DD-ID: {42C2E264-7853-412f-BC59-EE79E6347345}*/
  static uint8 v_Set_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_ZERO;

  if((uint16)VEHICLE_SPEEDVSO_SIG_SNA == v_fData_u16)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (FOD_FEATURE) || (SVC360_FEATURE)) 
    {
        if (v_Set_FD14_VehicleSpeedVSOSig_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_VehicleSpeedVSOSig_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_VehSpd_VSO_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_FD14_VehicleSpeedVSOSig_u8++;
        }
    }
    else
    {
        v_Set_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_VehicleSpeedVSOSig_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_VehSpd_VSO_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_VehicleSpeedVSOSig_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_YawRate_BSM(FD14_YawRate_BSM v_fData_u16)
{
  /* DD-ID: {F47BF14E-D4B5-4671-8372-57BBED2A9CE4}*/
  static uint8 v_Set_FD14_YawRate_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_YawRate_BSM_u8 = (uint8)e_ZERO;

  if ((uint16)YAWRATE_BSM_SNA == v_fData_u16)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
    {
        if (v_Set_FD14_YawRate_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_YawRate_BSM_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_YawRate_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_YawRate_BSM_u8 = (uint8)e_ONE;
            }
        }
        else
        {
        v_Set_FD14_YawRate_BSM_u8++;
        }
    }
    else
    {
        v_Set_FD14_YawRate_BSM_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_YawRate_BSM_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_YawRate_BSM_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_YawRate_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_YawRate_BSM_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_2_FD14_YawRateFailSts_BSM(FD14_YawRateFailSts_BSM v_fData_u8)
{
  /* DD-ID: {906CF9EA-6F62-4e27-AC02-B622B8E437F9}*/
  static uint8 v_Set_YawRateFailSts_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_YawRateFailSts_BSM_u8 = (uint8)e_ZERO;

    if((uint8)YAWRATE_BSM_FAIL == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
        {
            if (v_Set_YawRateFailSts_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_YawRateFailSts_BSM_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_YawRate_FailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_YawRateFailSts_BSM_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_YawRateFailSts_BSM_u8++;
            }
        }
        else
        {
            v_Set_YawRateFailSts_BSM_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_YawRateFailSts_BSM_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_YawRateFailSts_BSM_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE2_YawRate_FailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_YawRateFailSts_BSM_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LatAccelerationOffset_BSM(FD14_LatAccelerationOffset_BSM v_fData_u8)
{
  /* DD-ID: {AA53F942-205D-44ef-847F-C9EED71A9590}*/
  static uint8 v_Set_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_ZERO;

  if((uint8)LAT_ACC_OFFSET_BSM_SNA == v_fData_u8)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE))
    {
        if (v_Set_FD14_LatAccelerationOffset_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_FD14_LatAccelerationOffset_BSM_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LatAcc_Offset_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_FD14_LatAccelerationOffset_BSM_u8++;
        }
    }
    else
    {
       v_Set_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_FD14_LatAccelerationOffset_BSM_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LatAcc_Offset_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_FD14_LatAccelerationOffset_BSM_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LongAccelerationOffset_BSM(FD14_LongAccelerationOffset_BSM v_fData_u8)
{
  /* DD-ID: {CF1303D7-5F0D-4a10-8849-6376A056A6E6}*/
  static uint8 v_Set_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_ZERO;

  if((uint8)LONG_ACC_OFFSET_BSM_SNA == v_fData_u8) 
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
    {
        if (v_Set_FD14_LongAccelerationOffset_BSM_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_LongAccelerationOffset_BSM_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LongAcc_Offset_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_ONE;
            }
        }
        else
        {
           v_Set_FD14_LongAccelerationOffset_BSM_u8++;
        }
    }
    else
    {
        v_Set_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_LongAccelerationOffset_BSM_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LongAcc_Offset_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_LongAccelerationOffset_BSM_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_FastPulseCounter(FD14_LHF_FastPulseCounter v_fData_u8)
{
  /* DD-ID: {0DC07B16-5BB0-4129-8DD2-E44127569819}*/
  static uint8 v_Set_FD14_LHF_FastPulseCounter_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHF_FastPulseCounter_u8 = (uint8)e_ZERO;

  if((uint8)LHF_FASTPULSECOUNTER_SNA == v_fData_u8)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
    {
        if (v_Set_FD14_LHF_FastPulseCounter_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_LHF_FastPulseCounter_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_FastPulseCntr_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_LHF_FastPulseCounter_u8 = (uint8)e_ONE;
            }
        }
        else
        {
         v_Set_FD14_LHF_FastPulseCounter_u8++;
        }
    }
    else
    {
        v_Set_FD14_LHF_FastPulseCounter_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_LHF_FastPulseCounter_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_LHF_FastPulseCounter_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_FastPulseCntr_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_LHF_FastPulseCounter_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_Spin(FD14_LHF_Spin v_fData_u8)
{
  /* DD-ID: {BB312E53-D1F0-4a78-AC8D-FAB590837016}*/
  static uint8 v_Set_FD14_LHF_Spin_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHF_Spin_u8 = (uint8)e_ZERO;

    if ((uint8)LHF_SPIN_SNA == v_fData_u8)
    {
        if ((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))  
        {
            if (v_Set_FD14_LHF_Spin_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LHF_Spin_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_Spin_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LHF_Spin_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_LHF_Spin_u8++;
            }
        }
        else
        {
        v_Set_FD14_LHF_Spin_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_LHF_Spin_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LHF_Spin_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_Spin_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LHF_Spin_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHF_WheelSensorFailSts(FD14_LHF_WheelSensorFailSts v_fData_u8)
{
  /* DD-ID: {40C8F4F1-58EA-4951-8C94-7A1F48EF785D}*/
  static uint8 v_Set_LHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;

  if((uint8)LHF_WHEEL_SNR_STS_FAIL == v_fData_u8) 
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
    {
        if (v_Set_LHF_WheelSensorFailSts_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_LHF_WheelSensorFailSts_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_WhlSenFailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_LHF_WheelSensorFailSts_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_LHF_WheelSensorFailSts_u8++;
        }
    }
    else
    {
        v_Set_LHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_LHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_LHF_WheelSensorFailSts_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_WhlSenFailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_LHF_WheelSensorFailSts_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_FastPulseCounter(FD14_LHR_FastPulseCounter v_fData_u8)
{
  /* DD-ID: {9EED2251-B4BF-4d59-8925-16F30D6DCBCC}*/
  static uint8 v_Set_FD14_LHR_FastPulseCounter_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHR_FastPulseCounter_u8 = (uint8)e_ZERO;

    if((uint8)LHR_FASTPULSECOUNTER_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_FD14_LHR_FastPulseCounter_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LHR_FastPulseCounter_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_FastPulseCntr_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LHR_FastPulseCounter_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_LHR_FastPulseCounter_u8++;       
            }
        }
        else
        {
            v_Set_FD14_LHR_FastPulseCounter_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_LHR_FastPulseCounter_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LHR_FastPulseCounter_u8 != (uint8)e_TWO)
        {       
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_FastPulseCntr_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_FD14_LHR_FastPulseCounter_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_Spin(FD14_LHR_Spin v_fData_u8)
{
  /* DD-ID: {0E2B8EA6-0176-45f4-B770-8E5C63005E96}*/
  static uint8 v_Set_FD14_LHR_Spin_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHR_Spin_u8 = (uint8)e_ZERO;

    if((uint8)LHR_SPIN_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_FD14_LHR_Spin_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LHR_Spin_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_Spin_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LHR_Spin_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_LHR_Spin_u8++;
            }
        }
        else
        {
            v_Set_FD14_LHR_Spin_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_LHR_Spin_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LHR_Spin_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_Spin_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LHR_Spin_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHR_WheelSensorFailSts(FD14_LHR_WheelSensorFailSts v_fData_u8)
{
  /* DD-ID: {5D785C49-50DA-4497-A281-E9DCA9EC007B}*/
  static uint8 v_Set_LHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHR_Spin_u8 = (uint8)e_ZERO;

    if((uint8)LHR_WHEEL_SNR_STS_FAIL == v_fData_u8) 
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_LHR_WheelSensorFailSts_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LHR_Spin_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_WhlSenFailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LHR_Spin_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_LHR_WheelSensorFailSts_u8++;
            }
        }
        else
        {
            v_Set_LHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_LHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LHR_Spin_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_WhlSenFailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LHR_Spin_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_FastPulseCounter(FD14_RHF_FastPulseCounter v_fData_u8)
{
  /* DD-ID: {B861C1E1-22A1-4483-94DE-F304DC4282B5}*/
  static uint8 v_Set_FD14_RHF_FastPulseCounter_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHF_FastPulseCounter_u8 = (uint8)e_ZERO;

    if ((uint8)RHF_FASTPULSECOUNTER_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_FD14_RHF_FastPulseCounter_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHF_FastPulseCounter_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_FastPulseCntr_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHF_FastPulseCounter_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_RHF_FastPulseCounter_u8++;
            }
        }
        else
        {
        v_Set_FD14_RHF_FastPulseCounter_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_RHF_FastPulseCounter_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHF_FastPulseCounter_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_FastPulseCntr_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_RHF_FastPulseCounter_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_Spin(FD14_RHF_Spin v_fData_u8)
{
  /* DD-ID: {BA70600F-5D6F-4ef4-B887-5CB43398F470}*/
  static uint8 v_Set_FD14_RHF_Spin_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHF_Spin_u8 = (uint8)e_ZERO;

    if ((uint8)RHF_SPIN_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_FD14_RHF_Spin_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHF_Spin_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_Spin_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHF_Spin_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_RHF_Spin_u8++;
            }
        }
        else
        {
            v_Set_FD14_RHF_Spin_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_RHF_Spin_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHF_Spin_u8 != (uint8)e_TWO)
        {       
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_Spin_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_FD14_RHF_Spin_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHF_WheelSensorFailSts(FD14_RHF_WheelSensorFailSts v_fData_u8)
{
  /* DD-ID: {CD0C4B36-2AAA-4510-89F4-187D193A8A5A}*/
  static uint8 v_Set_RHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;

    if((uint8)RHF_WHEEL_SNR_STS_FAIL == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
        {
            if (v_Set_RHF_WheelSensorFailSts_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHF_WheelSensorFailSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_WhlSenFailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHF_WheelSensorFailSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
             v_Set_RHF_WheelSensorFailSts_u8++;
            }
        }
        else
        {
            v_Set_RHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        }
    }  
    else
    {
        v_Set_RHF_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHF_WheelSensorFailSts_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_WhlSenFailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_RHF_WheelSensorFailSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_FastPulseCounter(FD14_RHR_FastPulseCounter v_fData_u8)
{
  /* DD-ID: {30718CBC-C190-47d7-B17C-69D191F64CE2}*/
  static uint8 v_Set_FD14_RHR_FastPulseCounter_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHR_FastPulseCounter_u8 = (uint8)e_ZERO;

    if((uint8)RHR_FASTPULSECOUNTER_SNA == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
        {
            if (v_Set_FD14_RHR_FastPulseCounter_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHR_FastPulseCounter_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_FastPulseCntr_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHR_FastPulseCounter_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_RHR_FastPulseCounter_u8++;
            }
        }
        else
        {
            v_Set_FD14_RHR_FastPulseCounter_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_RHR_FastPulseCounter_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHR_FastPulseCounter_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_FastPulseCntr_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_RHR_FastPulseCounter_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_Spin(FD14_RHR_Spin v_fData_u8)
{
  /* DD-ID: {484821EB-E407-4126-94C3-FDE7EEDC7F79}*/
  static uint8 v_Set_FD14_RHR_Spin_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHR_Spin_u8 = (uint8)e_ZERO;

  if((uint8)RHR_SPIN_SNA == v_fData_u8)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) 
    {

        if (v_Set_FD14_RHR_Spin_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_RHR_Spin_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_Spin_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_RHR_Spin_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_FD14_RHR_Spin_u8++;
        }
    }
    else
    {
        v_Set_FD14_RHR_Spin_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_RHR_Spin_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_RHR_Spin_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_Spin_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_RHR_Spin_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHR_WheelSensorFailSts(FD14_RHR_WheelSensorFailSts v_fData_u8)
{
  /* DD-ID: {1C2E2DAB-104F-4cc3-8146-E429B2FF0E7F}*/
  static uint8 v_Set_RHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;

    if((uint8)RHR_WHEEL_SNR_STS_FAIL == v_fData_u8)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
        {  
            if (v_Set_RHR_WheelSensorFailSts_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHR_WheelSensorFailSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_WhlSenFailSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHR_WheelSensorFailSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_RHR_WheelSensorFailSts_u8++;
            }
        }
        else
        {
            v_Set_RHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_RHR_WheelSensorFailSts_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHR_WheelSensorFailSts_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_WhlSenFailSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_RHR_WheelSensorFailSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHFWheelSpeed(FD14_LHFWheelSpeed v_fData_u16)
{
  /* DD-ID: {56ABA84B-0CAD-4ef3-B4C0-12E6997D67AC}*/
  static uint8 v_Set_FD14_LHFWheelSpeed_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHFWheelSpeed_u8 = (uint8)e_ZERO;

    if((uint16)LHF_WHEEL_SPEED_SNA == v_fData_u16)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))  
        {
            if (v_Set_FD14_LHFWheelSpeed_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LHFWheelSpeed_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_WhlSpd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LHFWheelSpeed_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_LHFWheelSpeed_u8++;
            }
        }
        else
        {
        v_Set_FD14_LHFWheelSpeed_u8 = (uint8)e_ZERO;    
        }
    }
    else
    {
        v_Set_FD14_LHFWheelSpeed_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LHFWheelSpeed_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHF_WhlSpd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LHFWheelSpeed_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_LHRWheelSpeed(FD14_LHRWheelSpeed v_fData_u16)
{
  /* DD-ID: {CDA6F98A-ECCE-45f0-92DC-A94ABEEA09EF}*/
  static uint8 v_Set_FD14_LHRWheelSpeed_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LHRWheelSpeed_u8 = (uint8)e_ZERO;

  if((uint16)LHR_WHEEL_SPEED_SNA == v_fData_u16)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))  
    {
        if (v_Set_FD14_LHRWheelSpeed_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_LHRWheelSpeed_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_WhlSpd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_LHRWheelSpeed_u8 = (uint8)e_ONE;
            }
        }
        else
        {
          v_Set_FD14_LHRWheelSpeed_u8++;
        }
    }
    else
    {
        v_Set_FD14_LHRWheelSpeed_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_LHRWheelSpeed_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_LHRWheelSpeed_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_LHR_WhlSpd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_LHRWheelSpeed_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHFWheelSpeed(FD14_RHFWheelSpeed v_fData_u16)
{
  /* DD-ID: {0AA88339-AA86-4c20-852A-A413C6892445}*/
  static uint8 v_Set_FD14_RHFWheelSpeed_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHFWheelSpeed_u8 = (uint8)e_ZERO;

    if((uint16)RHF_WHEEL_SPEED_SNA == v_fData_u16)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))  
        {
            if (v_Set_FD14_RHFWheelSpeed_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_RHFWheelSpeed_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_WhlSpd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_RHFWheelSpeed_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_RHFWheelSpeed_u8++;
            }
        }
        else
        {
            v_Set_FD14_RHFWheelSpeed_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_RHFWheelSpeed_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_RHFWheelSpeed_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHF_WhlSpd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_RHFWheelSpeed_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_3_FD14_RHRWheelSpeed(FD14_RHRWheelSpeed v_fData_u16)
{
  /* DD-ID: {EB6D8915-E39A-49b5-B323-19E3324392FE}*/
  static uint8 v_Set_FD14_RHRWheelSpeed_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_RHRWheelSpeed_u8 = (uint8)e_ZERO;

  if((uint16)RHR_WHEEL_SPEED_SNA == v_fData_u16)
  {
    if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))  
    {
        if (v_Set_FD14_RHRWheelSpeed_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_RHRWheelSpeed_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_WhlSpd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_RHRWheelSpeed_u8 = (uint8)e_ONE;
            }
        }
        else
        {
          v_Set_FD14_RHRWheelSpeed_u8++;
        }
    }
    else
    {
        v_Set_FD14_RHRWheelSpeed_u8 = (uint8)e_ZERO;    
    }
  }
  else
  {
    v_Set_FD14_RHRWheelSpeed_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_RHRWheelSpeed_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE3_RHR_WhlSpd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_RHRWheelSpeed_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_EPS_FD_1_FD14_SPM_Lat_Ctrl_ResponseSts(FD14_SPM_Lat_Ctrl_ResponseSts  v_fData_u8)
{
  /* DD-ID: {4E74940B-1623-48b5-9053-575955F84290}*/
  static uint8 v_Set_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_ZERO;

  
    if(((uint8)LAT_CTRLSTS_PERM_NA == v_fData_u8)|| ((uint8)LAT_CTRLSTS_TEMP_NA == v_fData_u8))
    {
        /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
        if(((uint8)e_ONE == v_SurroundViewCam_u8) && (FULL_PPPA_FEATURE))
        {
            if (v_Set_FD14_SPM_Lat_Ctrl_ResponseSts_u8 >= (uint8)MATURATION_CNT_TEN)
            {
                if (s_flag_FD14_SPM_Lat_Ctrl_ResponseSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_SPM_LAT_Ctrl_Resp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_SPM_Lat_Ctrl_ResponseSts_u8++;
            }
        }
        else
        {
            v_Set_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_SPM_Lat_Ctrl_ResponseSts_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_SPM_LAT_Ctrl_Resp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_SPM_Lat_Ctrl_ResponseSts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_EPS_FD_1_FD14_LwsAngle(FD14_LwsAngle v_fData_u16)
{
  /* DD-ID: {FF0AD509-ADDE-412f-8DA3-465639B8BF2B}*/
  static uint8 v_Set_FD14_LwsAngle_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LwsAngle_u8 = (uint8)e_ZERO;

  if((uint16)LWS_ANGLE_SNA == v_fData_u16) 
  {
    if((PARB_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FULL_PPPA_FEATURE) || (SVC360_FEATURE))
    {
        if (v_Set_FD14_LwsAngle_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_LwsAngle_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Angle_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_LwsAngle_u8 = (uint8)e_ONE;
            }
        }
        else
        {
          v_Set_FD14_LwsAngle_u8++;
        }
    }
    else
    {
        v_Set_FD14_LwsAngle_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_FD14_LwsAngle_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_LwsAngle_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Angle_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_LwsAngle_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_EPS_FD_1_FD14_LwsAngleType(FD14_LwsAngleType  v_fData_u8)
{
  /* DD-ID:{506AC4A9-7AC5-4140-8EBA-C0616024701B}*/
  static uint8 v_Set_FD14_LwsAngleType_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LwsAngleType_u8 = (uint8)e_ZERO;

    if((uint8)LWS_ANGLE_TYPE_SNA == v_fData_u8)
    {
        if((THA_FEATURE) || (TRSC_FEATURE) || (FULL_PPPA_FEATURE)) 
        {
            if (v_Set_FD14_LwsAngleType_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LwsAngleType_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Angle_Typ_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LwsAngleType_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_LwsAngleType_u8++;
            }
        }
        else
        {
            v_Set_FD14_LwsAngleType_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_LwsAngleType_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LwsAngleType_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Angle_Typ_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LwsAngleType_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_EPS_FD_1_FD14_LwsSpeed(FD14_LwsSpeed v_fData_u16)
{
  /* DD-ID: {7A966AED-223C-4efa-9466-F03D0E70A158}*/
  static uint8 v_Set_FD14_LwsSpeed_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_LwsSpeed_u8 = (uint8)e_ZERO;

    if((uint16)LWS_SPEED_SNA == v_fData_u16)
    {
        if((PARB_FEATURE) || (FULL_PPPA_FEATURE)) 
        {
            if (v_Set_FD14_LwsSpeed_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_FD14_LwsSpeed_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Spd_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_LwsSpeed_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_LwsSpeed_u8++;
            }
        }
        else
        {
            v_Set_FD14_LwsSpeed_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_LwsSpeed_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_LwsSpeed_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS1_LWS_Spd_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_LwsSpeed_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_BRAKE_FD_4_FD14_EPBSts(FD14_EPBSts v_fData_u8)
{
  /* DD-ID: {E56D1DC1-E5AB-4dc8-B768-86FDCB0CC8FD}*/
  static uint8 v_Set_EPBSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_EPBSts_u8 = (uint8)e_ZERO;

  if((uint8)EPBSTS_SNA == v_fData_u8)
    {
       if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE)) 
       {
            if (v_Set_EPBSts_u8 >= (uint8)MATURATION_CNT_FIVE)
            {
                if (s_flag_FD14_EPBSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE4_EPBSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_EPBSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
               v_Set_EPBSts_u8++;
            }
       }
       else
       {
        v_Set_EPBSts_u8 = (uint8)e_ZERO;
       }
  }
  else
  {
    v_Set_EPBSts_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_EPBSts_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE4_EPBSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_EPBSts_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_7_FD14_PAM_Brk_Rq_RspSts(FD14_PAM_Brk_Rq_RspSts v_fData_u8)
{
  /* DD-ID: {EFC37690-6F87-4652-9185-2ECA9DE846EC}*/
  static uint8 v_Set_PAM_Brk_Rq_RspSts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_PAM_Brk_Rq_RspSts_u8 = (uint8)e_ZERO;

  if(((uint8)PAM_BRK_RSPSTS_FAULTED == v_fData_u8) || (v_fData_u8 == (uint8)PAM_BRK_RSPSTS_SNA))
  {
    if((PARB_FEATURE) || (FULL_PPPA_FEATURE))
    {
        if (v_Set_PAM_Brk_Rq_RspSts_u8 >= (uint8)MATURATION_CNT_FIFTY)
        {
            if (s_flag_FD14_PAM_Brk_Rq_RspSts_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE7_PAM_BrkRqRspSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_PAM_Brk_Rq_RspSts_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_PAM_Brk_Rq_RspSts_u8++;
        }
    }
    else
    {
        v_Set_PAM_Brk_Rq_RspSts_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_PAM_Brk_Rq_RspSts_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_PAM_Brk_Rq_RspSts_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE7_PAM_BrkRqRspSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_PAM_Brk_Rq_RspSts_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_5_FD14_ESC_TRSC_Brk_Resp(FD14_ESC_TRSC_Brk_Resp v_fData_u8)
{
  /* DD-ID: {4ED942B5-ADA2-4c6f-8F3B-87C99C7B03C2}*/
  static uint8 v_Set_ESC_TRSC_Brk_Resp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_ESC_TRSC_Brk_Resp_u8 = (uint8)e_ZERO;

  if(((uint8)ESC_TRSC_BRK_RSP_OVERHEATED == v_fData_u8) || (v_fData_u8 == (uint8)ESC_TRSC_BRK_RSP_SNA))
    {
        if(TRSC_FEATURE) 
        {
            if (v_Set_ESC_TRSC_Brk_Resp_u8 >= (uint8)MATURATION_CNT_TWO)
            {
                if (s_flag_FD14_ESC_TRSC_Brk_Resp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE5_ESC_TRSCBrkResp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_ESC_TRSC_Brk_Resp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
               v_Set_ESC_TRSC_Brk_Resp_u8++;
            }
        }
        else
        {
            v_Set_ESC_TRSC_Brk_Resp_u8 = (uint8)e_ZERO;
        }
  }
  else
  {
    v_Set_ESC_TRSC_Brk_Resp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_ESC_TRSC_Brk_Resp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE5_ESC_TRSCBrkResp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_ESC_TRSC_Brk_Resp_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_Brake_FD_5_FD14_BSM_THA_Brk_Resp(FD14_BSM_THA_Brk_Resp v_fData_u8)
{
  /* DD-ID: {F3D19CF1-EB01-42a2-8488-D3216C8B267D}*/
  static uint8 v_Set_BSM_THA_Brk_Resp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_BSM_THA_Brk_Resp_u8 = (uint8)e_ZERO;

  if(((uint8)BSM_THA_BRK_RSP_OVERHEATED == v_fData_u8) || (v_fData_u8 == (uint8)BSM_THA_BRK_RSP_SNA))
    {
        if(THA_FEATURE) 
        {
            if (v_Set_BSM_THA_Brk_Resp_u8 >= (uint8)MATURATION_CNT_TWO)
            {
                if (s_flag_FD14_BSM_THA_Brk_Resp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE5_BSM_THABrkResp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_BSM_THA_Brk_Resp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_BSM_THA_Brk_Resp_u8++;
            }
        }
        else
        {
            v_Set_BSM_THA_Brk_Resp_u8 = (uint8)e_ZERO;
        }
   }
  else
  {
    v_Set_BSM_THA_Brk_Resp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_BSM_THA_Brk_Resp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKE5_BSM_THABrkResp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_BSM_THA_Brk_Resp_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BRAKE_FD_1_FD14_ExternalBrkRequestsDisabled(FD14_ExternalBrkRequestsDisabled v_fData_u8)
{
  /* DD-ID: {45017DC9-040E-4312-AFE3-77E07C1956A2}*/
  static uint8 v_Set_ExternalBrkRequestsDisabled = (uint8)e_ZERO;
  static uint8 s_flag_FD14_ExternalBrkRequestsDisabled_u8 = (uint8)e_ZERO;

  if((uint8)EXT_BRK_REQ_DIS_SNA == v_fData_u8)
  {
    if(FULL_PPPA_FEATURE) 
    {
        if (v_Set_ExternalBrkRequestsDisabled >= (uint8)MATURATION_CNT_TWENTY_FIVE)
        {
            if (s_flag_FD14_ExternalBrkRequestsDisabled_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKEFD1_ExternalBrkRequestsDisabled, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_ExternalBrkRequestsDisabled_u8 = (uint8)e_ONE;
            }
        }
        else
        {
           v_Set_ExternalBrkRequestsDisabled++;
        }
    }
    else
    {
        v_Set_ExternalBrkRequestsDisabled = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_ExternalBrkRequestsDisabled = (uint8)e_ZERO;
    if(s_flag_FD14_ExternalBrkRequestsDisabled_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BRAKEFD1_ExternalBrkRequestsDisabled, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_ExternalBrkRequestsDisabled_u8 = (uint8)e_TWO;
    }
  }
}


static void f_DTC_Flag_AGSM_FD_2_Shifter_ADAS_Inhibit(Shifter_ADAS_Inhibit v_fData_u8)
{
    /* DD-ID: {27EBA834-CB8C-4aaf-8455-7639BE89B72D}*/
  static uint8 v_Set_Shifter_ADAS_Inhibit_u8 = (uint8)e_ZERO;
  static uint8 s_flag_Shifter_ADAS_Inhibit_u8 = (uint8)e_ZERO;

  /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
  if((uint8)ADAS_INHIBIT_FAULTED == v_fData_u8)
  {
    if(((uint8)e_ONE == v_SurroundViewCam_u8) && (FULL_PPPA_FEATURE) && (CMD_IGN_STATUS))
    {
        if (v_Set_Shifter_ADAS_Inhibit_u8 >= (uint8)MATURATION_CNT_ONE_HUNDRED_FIFTY)
        {
            if (s_flag_Shifter_ADAS_Inhibit_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_AGSM2_Shiftr_ADAS_Inhbt_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_Shifter_ADAS_Inhibit_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_Shifter_ADAS_Inhibit_u8++;
        }
    }
    else
    {
        v_Set_Shifter_ADAS_Inhibit_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_Shifter_ADAS_Inhibit_u8 = (uint8)e_ZERO;
    if(s_flag_Shifter_ADAS_Inhibit_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_AGSM2_Shiftr_ADAS_Inhbt_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_Shifter_ADAS_Inhibit_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_AGSM_FD_2_ShiftLeverPositionReq(ShiftLeverPositionReq v_fData_u8)
{
    /* DD-ID: {FBC14A72-21DD-4b2e-9C07-9825DE85C2F5}*/
  static uint8 v_Set_ShiftLeverPositionReq_u8 = (uint8)e_ZERO;
  static uint8 s_flag_ShiftLeverPositionReq_u8 = (uint8)e_ZERO;
  /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
  if(((uint8)SHIFTLEVERPOS_NOSEL == v_fData_u8) || (((uint8)SHIFTLEVERPOS_NOTUSED <= v_fData_u8) && (v_fData_u8 <= (uint8)SHIFTLEVERPOS_SNA)))
  {
    if(((uint8)e_ONE == v_SurroundViewCam_u8) && (FULL_PPPA_FEATURE) && (CMD_IGN_STATUS))
    {
        if (v_Set_ShiftLeverPositionReq_u8 >= (uint8)MATURATION_CNT_ONE_HUNDRED_FIFTY)
        {
            if (s_flag_ShiftLeverPositionReq_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_AGSMD_ShifrLevrPosReq_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_ShiftLeverPositionReq_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_ShiftLeverPositionReq_u8++;
        }
    }
    else
    {
        v_Set_ShiftLeverPositionReq_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_ShiftLeverPositionReq_u8 = (uint8)e_ZERO;
    if(s_flag_ShiftLeverPositionReq_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_AGSMD_ShifrLevrPosReq_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_ShiftLeverPositionReq_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_BCM_FD_29_ITBM_TrlrStat(ITBM_TrlrStat v_fData_u8)
{
    /* DD-ID: {30E58D68-8B80-48fc-8FD3-74FB62E05F08}*/
  static uint8 v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
  static uint8 s_flag_ITBM_TrlrStat_u8 = (uint8)e_ZERO;

  if((uint8)ITBM_TRLRSTAT_SNA == v_fData_u8)
  {
    if((codingTableExt_s.CanNode95itcm_uint8 == TRUE) && ((FULL_PPPA_FEATURE) ||(TRSC_FEATURE)  || (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if (v_Set_ITBM_TrlrStat_u8 >= (uint8)MATURATION_CNT_THREE)
        {
            if (s_flag_ITBM_TrlrStat_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM29_ITBM_TrailrStat_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_ITBM_TrlrStat_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_ITBM_TrlrStat_u8++;
        }
    }
    else
    {
        v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_ITBM_TrlrStat_u8 = (uint8)e_ZERO;
    if(s_flag_ITBM_TrlrStat_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_BCM29_ITBM_TrailrStat_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_ITBM_TrlrStat_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_VIN(VIN_MSG v_fData_u8)
{
    /* DD-ID: {A620E79E-DCFB-4eb1-ABF3-86CDE7F74B33}*/
  static uint8 v_Set_VIN_Msg_u8 = (uint8)e_ZERO;
  static uint8 s_flag_VIN_MSG_u8 = (uint8)e_ZERO;

  if((uint8)VIN_MSG_SNA == v_fData_u8)
  {

    if(CMD_IGN_STATUS)
    {
        if(v_Set_VIN_Msg_u8 >= (uint8)MATURATION_CNT_THIRTY)
        {
            if (s_flag_VIN_MSG_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_VIN_Msg_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_VIN_MSG_u8 = (uint8)e_ONE;
                (void)Rte_Write_PpVIN_MessageFault_VIN_InvalidValueFlag(TRUE);
            }
        }
        else
        {
           v_Set_VIN_Msg_u8++;
        }
    }
    else
    {
        v_Set_VIN_Msg_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_VIN_Msg_u8 = (uint8)e_ZERO;
    if(s_flag_VIN_MSG_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_VIN_Msg_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_VIN_MSG_u8 = (uint8)e_TWO;
      (void)Rte_Write_PpVIN_MessageFault_VIN_InvalidValueFlag(FALSE);
	  
    }
  }
}

static void f_DTC_Flag_ASCM_FD1_FL_Lvl(FL_Lvl v_fData_u8)
{
    /* DD-ID: {B00DA8AC-E37C-47eb-AF33-A09C40A638C3}*/
  static uint8 v_Set_FL_Lvl_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FL_Lvl_u8 = (uint8)e_ZERO;

  if((uint8)FL_LVL_SNA == v_fData_u8) 
  {
    if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if (v_Set_FL_Lvl_u8 >= (uint8)MATURATION_CNT_FIFTEEN)
        {
            if (s_flag_FL_Lvl_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_FL_Lvl_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FL_Lvl_u8 = (uint8)e_ONE;
            }
        }
        else
        {
        v_Set_FL_Lvl_u8++;
        }
    }
    else
    {
      v_Set_FL_Lvl_u8 = (uint8)e_ZERO;  
    }
  }
  else
  {
    v_Set_FL_Lvl_u8 = (uint8)e_ZERO;
    if(s_flag_FL_Lvl_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_FL_Lvl_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FL_Lvl_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_ASCM_FD1_FR_Lvl(FR_Lvl v_fData_u8)
{
    /* DD-ID: {5BC69948-1F0F-4428-8AC5-F82F9335C6C1}*/
  static uint16 v_Set_v_FR_Lvl_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FR_Lvl_u8 = (uint8)e_ZERO;

  if((uint8)FR_LVL_SNA == v_fData_u8)
  {
    if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if (v_Set_v_FR_Lvl_u8 >= (uint8)MATURATION_CNT_FIFTEEN)
        {
            if (s_flag_FR_Lvl_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_FR_Lvl_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FR_Lvl_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_v_FR_Lvl_u8++;
        }
    }
    else
    {
       v_Set_v_FR_Lvl_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_v_FR_Lvl_u8 = (uint8)e_ZERO;
    if(s_flag_FR_Lvl_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_FR_Lvl_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FR_Lvl_u8 = (uint8)e_TWO;
    }
  }
}


static void f_DTC_Flag_ASCM_FD1_RL_Lvl(RL_Lvl v_fData_u8)
{
    /* DD-ID: {E471411B-01B7-4b0a-B043-71CC19B31F1E}*/
  static uint16 v_Set_v_RL_Lvl_u8 = (uint8)e_ZERO;
  static uint8 s_flag_RL_Lvl_u8 = (uint8)e_ZERO;

    if((uint8)RL_LVL_SNA == v_fData_u8)
    {
        if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (v_Set_v_RL_Lvl_u8 >= (uint8)MATURATION_CNT_FIFTEEN)
            {
                if (s_flag_RL_Lvl_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_RL_Lvl_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_RL_Lvl_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_v_RL_Lvl_u8++;
            }
        }
        else
        {
            v_Set_v_RL_Lvl_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_v_RL_Lvl_u8 = (uint8)e_ZERO;
        if(s_flag_RL_Lvl_u8 != (uint8)e_TWO)
        {       
            (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_RL_Lvl_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_RL_Lvl_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_ASCM_FD1_RR_Lvl(RR_Lvl v_fData_u8)
{
    /* DD-ID: {452DD7C7-6D16-4479-A55D-3C4FAFC1B1C6}*/
  static uint16 v_Set_v_RR_Lvl_u8 = (uint8)e_ZERO;
  static uint8 s_flag_RR_Lvl_u8 = (uint8)e_ZERO;

    if((uint8)RR_LVL_SNA == v_fData_u8)
    {
        if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (v_Set_v_RR_Lvl_u8 >= (uint8)MATURATION_CNT_FIFTEEN)
            {
                if (s_flag_RR_Lvl_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_RR_Lvl_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_RR_Lvl_u8 = (uint8)e_ONE;
                }
            }
            else
            {
               v_Set_v_RR_Lvl_u8++;
            }
        }
        else
        {
            v_Set_v_RR_Lvl_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_v_RR_Lvl_u8 = (uint8)e_ZERO;
        if(s_flag_RR_Lvl_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM1_RR_Lvl_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_RR_Lvl_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_ASCM_FD2_ASCM_Stat(ASCM_Stat v_fData_u8)
{
  /* DD-ID: {71558309-5032-4bbf-9D8F-C3B66CBE8FFF}*/
  static uint16 v_Set_ASCM_Stat_u8 = (uint8)e_ZERO;
  static uint8 s_flag_ASCM_Stat_u8 = (uint8)e_ZERO;

    if(((uint8)ASCM_STAT_CLEARANCE2 == v_fData_u8) || (uint8)(ASCM_STAT_INVALID == v_fData_u8) ||(uint8)(ASCM_STAT_SNA == v_fData_u8))
    {
        if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (v_Set_ASCM_Stat_u8 >= (uint8)MATURATION_CNT_THREE)
            {
                if (s_flag_ASCM_Stat_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM2_Stat_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_ASCM_Stat_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_ASCM_Stat_u8++;
            }
        }
        else
        {
            v_Set_ASCM_Stat_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_ASCM_Stat_u8 = (uint8)e_ZERO;
        if(s_flag_ASCM_Stat_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM2_Stat_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_ASCM_Stat_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_ASCM_FD2_ASCM_SysFail(ASCM_SysFail v_fData_u8)
{
    /* DD-ID: {5DFAB0CE-865D-4e7e-B6D5-C24D9449AF31}*/
  static uint8 v_Set_ASCM_SysFail_u8 = (uint8)e_ZERO;
  static uint8 s_flag_ASCM_SysFail_u8 = (uint8)e_ZERO;

  if((uint8)ASCM_SYSFAIL_TRUE == v_fData_u8) 
  {
    if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if (v_Set_ASCM_SysFail_u8 >= (uint8)MATURATION_CNT_THREE)
        {
            if (s_flag_ASCM_SysFail_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM2_SysFail_Fault, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_ASCM_SysFail_u8 = (uint8)e_ONE;
            }
        }
        else
        {
          v_Set_ASCM_SysFail_u8++;
        }
    }
    else
    {
       v_Set_ASCM_SysFail_u8 = (uint8)e_ZERO;   
    }
  }
  else
  {
    v_Set_ASCM_SysFail_u8 = (uint8)e_ZERO;
    if(s_flag_ASCM_SysFail_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_ASCM2_SysFail_Fault, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_ASCM_SysFail_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_TRANSM_FD_2_GearEngagedForDisplay(GearEngagedForDisplay v_fData_u8)
{
    /* DD-ID: {7B6C31DC-672D-47cd-AB5F-D8E2DA572ABD}*/
  static uint8 v_GearEngagedForDisplay_u8 = (uint8)e_ZERO;
  static uint8 s_flag_GearEngagedForDisplay_u8 = (uint8)e_ZERO;

    if(((uint8)GEAR_ENAGED_DISPLAY_UNSED1 == v_fData_u8) || ((uint8)GEAR_ENAGED_DISPLAY_UNSED2 == v_fData_u8)  || (((uint8)GEAR_ENAGED_DISPLAY_UNSED3 <= v_fData_u8) && (v_fData_u8 <= (uint8)GEAR_ENAGED_DISPLAY_SNA))) 
    {
        if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if (v_GearEngagedForDisplay_u8 >= (uint8)MATURATION_CNT_FIFTY)
            {
                if (s_flag_GearEngagedForDisplay_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM2_GearEngdForDisp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_GearEngagedForDisplay_u8 = (uint8)e_ONE;
                }
            }
            else
            {
              v_GearEngagedForDisplay_u8++;
            }
        }
        else
        {
            v_GearEngagedForDisplay_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_GearEngagedForDisplay_u8 = (uint8)e_ZERO;
        if(s_flag_GearEngagedForDisplay_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TRANSM2_GearEngdForDisp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_GearEngagedForDisplay_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_STAT(CM_TCH_STAT v_fData_u8)
{
    /* DD-ID: {A033AB4B-0775-4fa7-9C40-AC6DABB749F9}*/
  static uint8 v_Set_CM_TCH_STAT_u8 = (uint8)e_ZERO;
  static uint8 s_flag_CM_TCH_STAT_u8 = (uint8)e_ZERO;

  if(((uint8)CM_TCH_STAT_NOTUSED == v_fData_u8) || ((uint8)CM_TCH_STAT_SNA == v_fData_u8))
  {
    if((FULL_PPPA_FEATURE) || (THA_FEATURE) || (TRSC_FEATURE) || (SVC360_FEATURE)) 
    {
        if (v_Set_CM_TCH_STAT_u8 >= (uint8)MATURATION_CNT_THREE)
        {
            if (s_flag_CM_TCH_STAT_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_STAT_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_CM_TCH_STAT_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_CM_TCH_STAT_u8++;
        }
    }
    else
    {
        v_Set_CM_TCH_STAT_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_CM_TCH_STAT_u8 = (uint8)e_ZERO;
    if(s_flag_CM_TCH_STAT_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_STAT_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_CM_TCH_STAT_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_X_COORD(CM_TCH_X_COORD v_fData_u16)
{
    /* DD-ID: {375D9EA9-613B-4741-B0D0-D721623C0C5A}*/
  static uint8 v_Set_CM_TCH_X_COORD_u8 = (uint8)e_ZERO;
  static uint8 s_flag_CM_TCH_X_COORD_u8 = (uint8)e_ZERO;

 if(((v_fData_u16 > (uint16)ONE_THOUSAND_TWENTY_FOUR) && (((uint8)e_TWO == codingTableExt_s.Radiodisplay) || ((uint8)e_NINE == codingTableExt_s.Radiodisplay))) ||
   ((v_fData_u16 > (uint16)TWELVE_THOUSAND) && ((uint8)e_SEVEN == codingTableExt_s.Radiodisplay)))
   {
       if ((FULL_PPPA_FEATURE) || (THA_FEATURE) || (TRSC_FEATURE) || (SVC360_FEATURE))
       {
            if ((uint8)MATURATION_CNT_FIVE <= v_Set_CM_TCH_X_COORD_u8)
            {
                if (s_flag_CM_TCH_X_COORD_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_X_COORD_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_CM_TCH_X_COORD_u8 = (uint8)e_ONE;
                }
            }
            else
            {
              v_Set_CM_TCH_X_COORD_u8++;
            }
       }
       else
        {
            v_Set_CM_TCH_X_COORD_u8 = (uint8)e_ZERO;
        }
  }
  else
  {
    v_Set_CM_TCH_X_COORD_u8 = (uint8)e_ZERO;
    if(s_flag_CM_TCH_X_COORD_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_X_COORD_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_CM_TCH_X_COORD_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_TELEMATIC_FD_5_CM_TCH_Y_COORD(CM_TCH_Y_COORD v_fData_u16)
{
    /* DD-ID: {D0CFA4A1-4447-4843-A3D7-F57BFDF9A88C}*/
  static uint8 v_Set_CM_TCH_Y_COORD_u8 = (uint8)e_ZERO;
  static uint8 s_flag_CM_TCH_Y_COORD_u8 = (uint8)e_ZERO;

  if(((v_fData_u16 > (uint16)SEVEN_HUNDRED_SIXTY_EIGHT) && ((uint8)e_TWO == codingTableExt_s.Radiodisplay)) ||
    ((v_fData_u16 > (uint16)NINETEEN_HUNDRED_TEWNTY) && (((uint8)e_SEVEN == codingTableExt_s.Radiodisplay) || ((uint8)e_NINE == codingTableExt_s.Radiodisplay))))
   {
       if ((FULL_PPPA_FEATURE) || (THA_FEATURE) || (TRSC_FEATURE) || (SVC360_FEATURE))
       {
            if ((uint8)MATURATION_CNT_FIVE <= v_Set_CM_TCH_Y_COORD_u8)
            {
                if (s_flag_CM_TCH_Y_COORD_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_Y_COORD_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_CM_TCH_Y_COORD_u8 = (uint8)e_ONE;
                }
            }
            else
            {
               v_Set_CM_TCH_Y_COORD_u8++;
            }
       }
       else
       {
          v_Set_CM_TCH_Y_COORD_u8 = (uint8)e_ZERO;
       }
  }
  else
  {
    v_Set_CM_TCH_Y_COORD_u8 = (uint8)e_ZERO;
    if(s_flag_CM_TCH_Y_COORD_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMATIC5_CM_TCH_Y_COORD_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_CM_TCH_Y_COORD_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_TELEMATIC_FD_5_CameraDisplaySts2(CameraDisplaySts2 v_fData_u8)
{
    /* DD-ID: {0F247B63-78EA-4758-B29B-5DD9BA077E91}*/
  static uint8 v_Set_CameraDisplaySts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_CameraDisplaySts2_u8 = (uint8)e_ZERO;

  if(((uint8)CAM_DISPLAYSTS2_VIEW4 == v_fData_u8) || ((uint8)CAM_DISPLAYSTS2_VIEW10 == v_fData_u8))
  {
    if((THA_FEATURE) || (TRSC_FEATURE) || (SVC360_FEATURE))
    {
        if (v_Set_CameraDisplaySts_u8 >= (uint8)MATURATION_CNT_THREE)
        {
            if (s_flag_CameraDisplaySts2_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT5_CamDispSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_CameraDisplaySts2_u8 = (uint8)e_ONE;
            }
        }
        else
        {
          v_Set_CameraDisplaySts_u8++;
        }
    }
    else
    {
      v_Set_CameraDisplaySts_u8 = (uint8)e_ZERO;    
    }
  }
  else
  {
    v_Set_CameraDisplaySts_u8 = (uint8)e_ZERO;
    if(s_flag_CameraDisplaySts2_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT5_CamDispSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_CameraDisplaySts2_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_TELEMATIC_FD_11_HU_TRSC_EnableBtn_Sts(HU_TRSC_EnableBtn_Sts v_fData_u8)
{
    /* DD-ID: {5ACD851E-B117-441a-9BB9-8DF41862BC90}*/
  static uint8 v_Set_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
  static uint8 s_flag_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;

  if((uint8)TRSC_ENABLE_BTN_STS_SNA == v_fData_u8)
  {
    if((TRSC_FEATURE) || (THA_FEATURE) || (FULL_PPPA_FEATURE) || (SVC360_FEATURE)) 
    {
        if (v_Set_HU_TRSC_EnableBtn_Sts_u8 >= (uint8)MATURATION_CNT_THIRTY)
        {
            if (s_flag_HU_TRSC_EnableBtn_Sts_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT11_HU_TRSC_EnBtnSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_ONE;
            }
        }
        else
        {
           v_Set_HU_TRSC_EnableBtn_Sts_u8++;
        }
    }
    else
    {
        v_Set_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
    if(s_flag_HU_TRSC_EnableBtn_Sts_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_TELEMT11_HU_TRSC_EnBtnSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_HU_TRSC_EnableBtn_Sts_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_ENGINE_FD_2_FD14_EngineSts_W(FD14_EngineSts_W v_fData_u8)
{
  /* DD-ID: {23143475-FE2F-4fe1-B35D-E34214BAC59A}*/
  static uint8 v_Set_EngineSts_W_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_EngineSts_W_u8 = (uint8)e_ZERO;

  if((uint8)ENGINE_STS_SNA == v_fData_u8)
  {
    if((TRSC_FEATURE) || (THA_FEATURE)) 
    {
        if (v_Set_EngineSts_W_u8 >= (uint8)MATURATION_CNT_ONE_HUNDRED)
        {
            if (s_flag_FD14_EngineSts_W_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine2_EngineSts_W_ECM_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_EngineSts_W_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_EngineSts_W_u8++;
        }
    }
    else
    {
        v_Set_EngineSts_W_u8 = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_EngineSts_W_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_EngineSts_W_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine2_EngineSts_W_ECM_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_EngineSts_W_u8 = (uint8)e_TWO;
    }
  }
}


static void f_DTC_Flag_ENGINE_FD_7_FD14_ECM_TRSC_Resp(FD14_ECM_TRSC_Resp v_fData_u8)
{
    /* DD-ID: {0D9B3536-29AC-43aa-BC6F-3FB53DFD53B3}*/
  static uint8 v_Set_ECM_TRSC_Resp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_ECM_TRSC_Resp_u8 = (uint8)e_ZERO;

  if((uint8)ECM_TRSC_RESP_SNA == v_fData_u8) 
    {
        if(TRSC_FEATURE) 
        {
            if (v_Set_ECM_TRSC_Resp_u8 >= (uint8)MATURATION_CNT_THREE)
            {
                if (s_flag_FD14_ECM_TRSC_Resp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_7_ECM_TRSC_Resp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_ECM_TRSC_Resp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_ECM_TRSC_Resp_u8++;
            }
        }
        else
        {
            v_Set_ECM_TRSC_Resp_u8 = (uint8)e_ZERO;
        }
  }
  else
  {
    v_Set_ECM_TRSC_Resp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_ECM_TRSC_Resp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_7_ECM_TRSC_Resp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_ECM_TRSC_Resp_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_ENGINE_FD_7_FD14_ECM_THA_Resp(FD14_ECM_THA_Resp v_fData_u8)
{
    /* DD-ID: {C4F1FFDC-A9E5-401c-BC31-C94126F73F2B}*/
  static uint8 v_Set_ECM_THA_Resp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_ECM_THA_Resp_u8 = (uint8)e_ZERO;

  if((uint8)ECM_THA_RESP_SNA == v_fData_u8)
    {
        if(THA_FEATURE) 
        {
            if (v_Set_ECM_THA_Resp_u8 >= (uint8)MATURATION_CNT_THREE)
            {
                if (s_flag_FD14_ECM_THA_Resp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_7_ECM_THA_Resp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_ECM_THA_Resp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
              v_Set_ECM_THA_Resp_u8++;
            }
        }
        else
        {
            v_Set_ECM_THA_Resp_u8 = (uint8)e_ZERO;
        }
    }
   else
   {
    v_Set_ECM_THA_Resp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_ECM_THA_Resp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_7_ECM_THA_Resp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_ECM_THA_Resp_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_DriverTorqueOverride(FD14_EPS_THA_DriverTorqueOverride v_fData_u8)
{
     /* DD-ID: {FE07BAE7-A0F3-4f24-BF6D-793342FCCEAE}*/
  static uint8 v_Set_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_ZERO;

  if((uint8)THA_DRVTORQ_OVERRIDE_SNA == v_fData_u8)
    {
        if(THA_FEATURE) 
        {
            if (v_Set_FD14_EPS_THA_DriverTorqueOverride_u8 >= (uint8)MATURATION_CNT_TEN)
            {
                if (s_flag_FD14_EPS_THA_DriverTorqueOverride_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_DrivrTqOvrride_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_ONE;
                }
            }
            else
            {
              v_Set_FD14_EPS_THA_DriverTorqueOverride_u8++;
            }
        }
        else
        {
            v_Set_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_ZERO;
        if(s_flag_FD14_EPS_THA_DriverTorqueOverride_u8 != (uint8)e_TWO)
        {       
        (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_DrivrTqOvrride_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
        s_flag_FD14_EPS_THA_DriverTorqueOverride_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_EPS_FD_2_FD14_EPS_THA_SteeringTorqueResp(FD14_EPS_THA_SteeringTorqueResp v_fData_u8)
{
    /* DD-ID: {47BFF9CC-3359-4034-A9C5-A3E85200CD0E}*/
  static uint8 v_Set_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_ZERO;

  if(((uint8)THA_STERRING_TRQREP_TEMP_NA == v_fData_u8) || ((uint8)THA_STERRING_TRQREP_PERM_NA == v_fData_u8) || 
     (((uint8)THA_STERRING_TRQREP_INVALID <= v_fData_u8)&&( v_fData_u8 <= (uint8)THA_STERRING_TRQREP_SNA)))
    {
        if(THA_FEATURE)
        { 
            if (v_Set_FD14_EPS_THA_SteeringTorqueResp_u8 >= (uint8)MATURATION_CNT_TEN)
            {
                if (s_flag_FD14_EPS_THA_SteeringTorqueResp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_SteeringTqResp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_EPS_THA_SteeringTorqueResp_u8++;
            }
        }
        else
        {
            v_Set_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_ZERO;
        }
   }
   else
   {
    v_Set_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_EPS_THA_SteeringTorqueResp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_SteeringTqResp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_EPS_THA_SteeringTorqueResp_u8 = (uint8)e_TWO;
    }
  }
}

static void f_DTC_Flag_EPS_FD_2_FD14_EPS_SteeringTouq_Resp(FD14_EPS_SteeringTouq_Resp v_fData_u8)
{
    /* DD-ID: {C3757194-8A11-4caa-801C-3EDE5304377A}*/
  static uint8 v_Set_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_ZERO;

  if((uint8)EPS_STEERINGTOUQ_REP_SNA == v_fData_u8) 
    {
        if(TRSC_FEATURE) 
        {
            if (v_Set_FD14_THA_SteeringTouq_Resp_u8 >= (uint8)MATURATION_CNT_TEN)
            {
                if (s_flag_FD14_THA_SteeringTouq_Resp_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_EPS_SteeringTqResp_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_FD14_THA_SteeringTouq_Resp_u8++;
            }
        }
        else
        {
			v_Set_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_ZERO;  
        }
  }
  else
  {
    v_Set_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_THA_SteeringTouq_Resp_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_EPS_SteeringTqResp_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_THA_SteeringTouq_Resp_u8 = (uint8)e_TWO;
    }
  }
}
static void f_DTC_Flag_EPS_FD_2_FD14_THA_SteeringTouchStat(FD14_THA_SteeringTouchStat v_fData_u8)
{
  /* DD-ID: {BAC85A57-098C-4a7a-8D59-DA529C18EB64}*/
  static uint8 v_Set_FD14_THA_SteeringTouchStat_u8 = (uint8)e_ZERO;
  static uint8 s_flag_FD14_THA_SteeringTouchStat_u8 = (uint8)e_ZERO;

  if((uint8)THA_STEERINGTOUCH_STAT_SNA == v_fData_u8)
    {
        if(THA_FEATURE) 
        {
            if (v_Set_FD14_THA_SteeringTouchStat_u8 >= (uint8)MATURATION_CNT_TEN)
            {
                if (s_flag_FD14_THA_SteeringTouchStat_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_SteerTouchStat_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_FD14_THA_SteeringTouchStat_u8 = (uint8)e_ONE;
                }
            }
            else
            {
            v_Set_FD14_THA_SteeringTouchStat_u8++;
            }
        }
        else
        {
           v_Set_FD14_THA_SteeringTouchStat_u8 = (uint8)e_ZERO;
        }
  }
  else
  {
    v_Set_FD14_THA_SteeringTouchStat_u8 = (uint8)e_ZERO;
    if(s_flag_FD14_THA_SteeringTouchStat_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_EPS2_THA_SteerTouchStat_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_THA_SteeringTouchStat_u8 = (uint8)e_TWO;
    }
  }
}

static void  f_DTC_Flag_ENGINE_FD_5_FD14_PdlPosActual(FD14_PdlPosActual v_fData_u8)
{
    /* DD-ID: {E64054E3-8BE9-46b5-8A27-F180CF234EA8}*/
  static uint8 v_Set_PdlPosActual = (uint8)e_ZERO;
  static uint8 s_flag_FD14_PdlPosActual_u8 = (uint8)e_ZERO;

  if((uint8)ENGINE_FD5_PDLPOSACT_SNA == v_fData_u8)
  {
    if(FULL_PPPA_FEATURE) 
    {
        if (v_Set_PdlPosActual >= (uint8)MATURATION_CNT_ONE_HUNDRED_FIFTY)
        {
            if (s_flag_FD14_PdlPosActual_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_5_ECM_PdlPosActual, ErrorMgr_ErrorActive, NULL_PTR);
                s_flag_FD14_PdlPosActual_u8 = (uint8)e_ONE;
            }
        }
        else
        {
            v_Set_PdlPosActual++;
        }
    }
    else
    {
        v_Set_PdlPosActual = (uint8)e_ZERO;
    }
  }
  else
  {
    v_Set_PdlPosActual = (uint8)e_ZERO;
    if(s_flag_FD14_PdlPosActual_u8 != (uint8)e_TWO)
    {       
      (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_Engine_FD_5_ECM_PdlPosActual, ErrorMgr_ErrorInactive, NULL_PTR);
      s_flag_FD14_PdlPosActual_u8 = (uint8)e_TWO;
    }
  }
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_INFO_C2_oFDCAN2_f97a3a77_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {30B7C471-A9F0-4b56-A56C-7940B6AD755F}*/
    return TRUE;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_5_oFDCAN2_a4a3db9e_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {A2EFADAC-5F70-4bb2-86B0-5A5CD4D24FC5}*/
    static E2E_MEP_CheckStateType ls_E2E_State_Read;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;
	(void)PduInfoPtr;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    ls_E2E_State_Read.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &ls_E2E_State_Read, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == ls_E2E_State_Read.Status) || (E2E_MEP_STATUS_OKSOMELOST == ls_E2E_State_Read.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == ls_E2E_State_Read.Status)
    {

        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGSEQUENCE == ls_E2E_State_Read.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        /*DO Nothing*/
    }

    return v_retVal_b;

}
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_3_oFDCAN2_7bf2eeed_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {6FC21E83-6593-4d5e-B124-560644A97AC8}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_BRAKE_FD_3;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_BRAKE_FD_3.NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_BRAKE_FD_3, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_BRAKE_FD_3.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_BRAKE_FD_3.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_BRAKE_FD_3.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_BRAKE_FD_3.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
       /*DO Nothing*/
    }

     return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_5_oFDCAN2_08e89767_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {76E0A3F9-EBBE-4238-B526-774F8BCDE110}*/
	/*GUID:-{17087EE4-D053-4a4d-BC30-8C2172FD4F3E}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_BRAKE_FD_5;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_BRAKE_FD_5.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_BRAKE_FD_5, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_BRAKE_FD_5.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_BRAKE_FD_5.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_BRAKE_FD_5.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_BRAKE_FD_5.Status)
    {

        v_retVal_b = TRUE;
    }
    else
    {
       /*DO Nothing*/
    }

     return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_2_oFDCAN2_c0c2b657_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {05F02AD4-73E6-480f-A3B8-B519B26B3A41}*/
	/*GUID:-{26516282-73C9-46e7-AFA7-CF34E95FDB28}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_ENGINE_FD_2;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_ENGINE_FD_2.NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_ENGINE_FD_2, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_ENGINE_FD_2.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_ENGINE_FD_2.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_ENGINE_FD_2.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_ENGINE_FD_2.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        /*DO Nothing*/
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_7_oFDCAN2_8a55f318_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {6FB1911A-0CCD-4e8a-A865-6558ACCF6AB8}*/
	/*GUID:-{361D1CB1-DF34-4461-8BAC-6833C5E7DB45}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_ENGINE_FD_7;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read_FD2_ENGINE_FD_7.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_ENGINE_FD_7, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_ENGINE_FD_7.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_ENGINE_FD_7.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_ENGINE_FD_7.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_ENGINE_FD_7.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
       /*DO Nothing*/
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_2_oFDCAN2_f615aeb5_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {4BBC9B8E-C06B-4b30-A2C9-B6572FF347F1}*/

    static E2E_MEP_CheckStateType ls_E2E_State_Read;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    ls_E2E_State_Read.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &ls_E2E_State_Read, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == ls_E2E_State_Read.Status) || (E2E_MEP_STATUS_OKSOMELOST == ls_E2E_State_Read.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == ls_E2E_State_Read.Status)
    {

        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGSEQUENCE == ls_E2E_State_Read.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
       /*DO Nothing*/
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_2_oFDCAN2_6c89faae_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {207EF369-7548-4f8e-80D5-84BBF1F23E5C}*/
/*GUID:-{207EF369-7548-4f8e-80D5-84BBF1F23E5C}*/

     static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_BRAKE_FD_2;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;
	(void)PduInfoPtr;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_BRAKE_FD_2.NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_BRAKE_FD_2, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_BRAKE_FD_2.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_BRAKE_FD_2.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_BRAKE_FD_2.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_BRAKE_FD_2.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_10_oFDCAN2_8d7683ae_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {FF870B6A-82F5-4369-9F1D-589B0C345095}*/
	/*GUID:-{9159539C-B1F1-42d1-B9B6-05E8BFCCF12C}*/
  Std_ReturnType v_checkRetVal_u8;
  boolean v_retVal_b= FALSE;
  static uint8 s_BCM_FD_10_DLC_u8 = (uint8)e_ZERO;
 (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BCM_FD_10_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD10, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_10_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_BCM_FD_10) 
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_10_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD10, ErrorMgr_ErrorActive, NULL_PTR);
                s_BCM_FD_10_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BCM_FD_10_DLC_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD10, ErrorMgr_ErrorInactive, NULL_PTR);
            s_BCM_FD_10_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_BCM_FD_10_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_10_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_10_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_10_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM10,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM10,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_10_ID].Status)
    {
       if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
       {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM10,ErrorMgr_ErrorActive,NULL_PTR);
       }
       v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_10_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_10_ID].Status))
    {
       if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
       {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM10,ErrorMgr_ErrorActive,NULL_PTR);
       }
        v_retVal_b = TRUE;
    }
    else
    {
        /*DO Nothing*/
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_12_oFDCAN2_a380ab28_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {69AFCE18-A2C4-41f6-BD15-B08CA9F87C54}*/
	/*GUID:-{69AFCE18-A2C4-41f6-BD15-B08CA9F87C54}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b= FALSE;
    static uint8 s_BCM_FD_12_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;
 
    if ((uint8)e_TWO != s_BCM_FD_12_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD12, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_12_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength < D_DLC_BCM_FD_12)
    {
        if(((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_12_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD12, ErrorMgr_ErrorActive, NULL_PTR);
                s_BCM_FD_12_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else  
    {
        if((uint8)e_TWO != s_BCM_FD_12_DLC_u8) 
        {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD12, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_12_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_BCM_FD_12_ID].NewDataAvailable = TRUE;


    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_12_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_12_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_12_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM12,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM12,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_12_ID].Status)
    {
      /* CR: 21034004
       * Task: 21215973
       * Description: PARB and PA feature condition added for CRC_BCM12
       */
      if(((FULL_PPPA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM12,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_12_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_12_ID].Status))
    {
      if(((FULL_PPPA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM12,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
     /*DO Nothing*/
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_27_oFDCAN2_02205564_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {29CBDF49-84E1-49b8-BE18-340D23D29F86}*/
	/*GUID:-{29CBDF49-84E1-49b8-BE18-340D23D29F86}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BCM_FD_27_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BCM_FD_27_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD27, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_27_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_BCM_FD_27)
    {
        if(((FULL_PPPA_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) ||(TRSC_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_27_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD27, ErrorMgr_ErrorActive, NULL_PTR);
                s_BCM_FD_27_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_BCM_FD_27_DLC_u8) 
        {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD27, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_27_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_BCM_FD_27_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_27_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_27_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_27_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM27,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM27,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_27_ID].Status)
    {
      if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS) )
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM27,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if(( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_27_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_27_ID].Status))
    {
      if(((FULL_PPPA_FEATURE) ||  (THA_FEATURE) || (PARB_PA_FEATURE) || (TRSC_FEATURE)) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM27,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      /*DO Nothing*/
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_9_oFDCAN2_718f54c7_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {B322DAA7-74A0-45e2-BF48-A6D89997C477}*/
	/*GUID:-{B322DAA7-74A0-45e2-BF48-A6D89997C477}*/
   Std_ReturnType v_checkRetVal_u8;
   boolean v_retVal_b = FALSE;
   static uint8 s_BCM_FD_9_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BCM_FD_9_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD9, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_9_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_BCM_FD_9)
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_9_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD9, ErrorMgr_ErrorActive, NULL_PTR);
                s_BCM_FD_9_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BCM_FD_9_DLC_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD9, ErrorMgr_ErrorInactive, NULL_PTR);
            s_BCM_FD_9_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_BCM_FD_9_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_9_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_9_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_9_ID].Status)))
    {
          (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM9,ErrorMgr_ErrorInactive,NULL_PTR);
          (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM9,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_9_ID].Status)
    {
      if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
      {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM9,ErrorMgr_ErrorActive,NULL_PTR);
      }
          v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_9_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_9_ID].Status))
    {
      if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM9,ErrorMgr_ErrorActive,NULL_PTR);
      }
        v_retVal_b = TRUE;
    }
    else
    {
      /*DO Nothing*/
    }

     return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_DRIVETRAIN_FD_3_oFDCAN2_8dcee934_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {34391437-250E-419c-B80A-2F511075B9E5}*/
	/*GUID:-{34391437-250E-419c-B80A-2F511075B9E5}*/
  Std_ReturnType v_checkRetVal_u8;
  boolean v_retVal_b = FALSE;
  static uint8 s_DRIVETRAIN_FD_3_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;
  (void)PduInfoPtr;
    if ((uint8)e_TWO != s_DRIVETRAIN_FD_3_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_DRIVETRAIN_FD3, ErrorMgr_ErrorInactive, NULL_PTR);
        s_DRIVETRAIN_FD_3_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_DRIVETRAIN_FD_3)
    {
        if((codingTableExt_s.CanNode67dtcm_uint8 == TRUE)  && ((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_DRIVETRAIN_FD_3_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_DRIVETRAIN_FD3, ErrorMgr_ErrorActive, NULL_PTR);
                s_DRIVETRAIN_FD_3_DLC_u8 = (uint8)e_ONE;    
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_DRIVETRAIN_FD_3_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_DRIVETRAIN_FD3, ErrorMgr_ErrorInactive, NULL_PTR);
            s_DRIVETRAIN_FD_3_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].Status)))
    {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_DRIVETRAIN3,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_DRIVETRAIN3,ErrorMgr_ErrorInactive,NULL_PTR);
     v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].Status)
    {
      if(((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_DRIVETRAIN3,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].Status))
    {
       if(((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_DRIVETRAIN3,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
     /*DO Nothing*/
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_1_oFDCAN2_cf989270_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {FC13DC20-3E2F-4f4b-8B92-FB97535491E3}*/
	/*GUID:-{FC13DC20-3E2F-4f4b-8B92-FB97535491E3}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_EPS_FD_1;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;
	(void)PduInfoPtr;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_EPS_FD_1.NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_EPS_FD_1, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_EPS_FD_1.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_EPS_FD_1.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read_FD2_EPS_FD_1.Status)
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read_FD2_EPS_FD_1.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_1_oFDCAN2_de4da8da_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {F6655213-15C9-48f5-8BF1-A7295792FCE2}*/
	/*GUID:-{F6655213-15C9-48f5-8BF1-A7295792FCE2}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TRANSM_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;
    if ((uint8)e_TWO != s_TRANSM_FD_1_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_TRANSM_FD_1_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_TRANSM_FD_1)
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_TRANSM_FD_1_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD1, ErrorMgr_ErrorActive, NULL_PTR);
                s_TRANSM_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else   
    {
        if((uint8)e_TWO != s_TRANSM_FD_1_DLC_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
            s_TRANSM_FD_1_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_TRANSM_FD_1_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TRANSM_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TRANSM_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TRANSM_FD_1_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM1,ErrorMgr_ErrorInactive,NULL_PTR);
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM1,ErrorMgr_ErrorInactive,NULL_PTR);
          v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TRANSM_FD_1_ID].Status)
    {
      if(((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM1,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TRANSM_FD_1_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TRANSM_FD_1_ID].Status))
    {
      if(((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM1,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      /*DO Nothing*/
    }
    return v_retVal_b;
}


FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_2_oFDCAN14_e9994fee_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {F999A851-4473-47af-ADB9-41589C5FBFD4}*/
	/*GUID:-{F999A851-4473-47af-ADB9-41589C5FBFD4}*/
   Std_ReturnType v_checkRetVal_u8;
   boolean v_retVal_b  = FALSE;
   static uint8 s_BRAKE_FD_2_DLC_u8 = (uint8)e_ZERO;
   (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BRAKE_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_2, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BRAKE_FD_2_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_BRAKE_FD_2)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_2_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_2, ErrorMgr_ErrorActive, NULL_PTR);
                s_BRAKE_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BRAKE_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_2, ErrorMgr_ErrorInactive, NULL_PTR);
            s_BRAKE_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD14_BRAKE_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_2_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE2,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE2,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_2_ID].Status)
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE2,ErrorMgr_ErrorActive,NULL_PTR);
      }
        v_retVal_b = TRUE;
    }
      else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_2_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_2_ID].Status))
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE2,ErrorMgr_ErrorActive,NULL_PTR);
      }
        v_retVal_b = TRUE;
    }
      else
    {
      /*DO Nothing*/
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_INFO_oFDCAN14_fa8dfd08_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {36D35783-DA84-4700-B066-D4B9C57F41E3}*/
	(void)PduId;
	(void)PduInfoPtr;
    return TRUE;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_3_oFDCAN14_065b24d0_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {2F2065AE-58F9-4c16-8D81-A99F92C03C07}*/
	/*GUID:-{2F2065AE-58F9-4c16-8D81-A99F92C03C07}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BRAKE_FD_3_DLC_u8 = (uint8)e_ZERO;
   (void)PduId;
	(void)PduInfoPtr;
 
    if ((uint8)e_TWO != s_BRAKE_FD_3_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_3, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BRAKE_FD_3_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength < D_DLC_BRAKE_FD_3)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_3_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_3, ErrorMgr_ErrorActive, NULL_PTR);
                s_BRAKE_FD_3_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BRAKE_FD_3_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_3, ErrorMgr_ErrorInactive, NULL_PTR);
            s_BRAKE_FD_3_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD14_BRAKE_FD_3_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_3_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_3_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_3_ID].Status)))
    {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE3,ErrorMgr_ErrorInactive,NULL_PTR);
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE3,ErrorMgr_ErrorInactive,NULL_PTR);
       v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_3_ID].Status)
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE3,ErrorMgr_ErrorActive,NULL_PTR);
      }
       v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_3_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_3_ID].Status))
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE3,ErrorMgr_ErrorActive,NULL_PTR);
      }
        v_retVal_b = TRUE;
    }
     else
    {
       /*Do Nothing*/
    }

     return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_5_oFDCAN14_0b455497_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {9C9A530D-2BB5-4682-9211-7770E1EE173D}*/
	/*GUID:-{9C9A530D-2BB5-4682-9211-7770E1EE173D}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BRAKE_FD_5_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BRAKE_FD_5_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_5, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BRAKE_FD_5_MM_u8 = (uint8)e_TWO;
    }  
    if(PduInfoPtr->SduLength < D_DLC_BRAKE_FD_5)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_5_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_5, ErrorMgr_ErrorActive, NULL_PTR);
                s_BRAKE_FD_5_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_BRAKE_FD_5_DLC_u8) 
        {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_5, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BRAKE_FD_5_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD14_BRAKE_FD_5_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_5_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_5_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_5_ID].Status)))
    {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE5,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE5,ErrorMgr_ErrorInactive,NULL_PTR);
     v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_5_ID].Status)
    {
      if( (TRSC_FEATURE) || (THA_FEATURE) )
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE5,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_5_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_5_ID].Status))
    {
      if((TRSC_FEATURE) || (THA_FEATURE) )
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE5,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      /*DO Nothing*/
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_1_oFDCAN14_8851a155_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {4FBDCC34-8966-49d9-919A-64C16AD0D6CA}*/
	/*GUID:-{4FBDCC34-8966-49d9-919A-64C16AD0D6CA}*/
     Std_ReturnType v_checkRetVal_u8;
     boolean v_retVal_b = FALSE;
    static uint8 s_EPS_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_EPS_FD_1_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_EPS_FD_1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_EPS_FD_1_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength < D_DLC_EPS_FD_1) 
    {
        if((PARB_FEATURE) || (FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            if((uint8)e_ONE != s_EPS_FD_1_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_EPS_FD_1, ErrorMgr_ErrorActive, NULL_PTR);
                s_EPS_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_EPS_FD_1_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_EPS_FD_1, ErrorMgr_ErrorInactive, NULL_PTR);
            s_EPS_FD_1_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD14_EPS_FD_1_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_EPS_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_EPS_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_EPS_FD_1_ID].Status)))
    {
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_EPS1,ErrorMgr_ErrorInactive,NULL_PTR);
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_EPS1,ErrorMgr_ErrorInactive,NULL_PTR);
     v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_EPS_FD_1_ID].Status)
    {
      if((PARB_FEATURE) || (FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_EPS1,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_EPS_FD_1_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_EPS_FD_1_ID].Status))
    {
      if((PARB_FEATURE) || (FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_EPS1,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      /*DO Nothing*/
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_1_oFDCAN2_5504c66b_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {64D2664D-8B1E-43d6-83B0-E83FA8584E0A}*/
    static E2E_MEP_CheckStateType ls_E2E_State_Read;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
   (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    ls_E2E_State_Read.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &ls_E2E_State_Read, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == ls_E2E_State_Read.Status) || (E2E_MEP_STATUS_OKSOMELOST == ls_E2E_State_Read.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == ls_E2E_State_Read.Status)
    {

        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == ls_E2E_State_Read.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_4_oFDCAN2_1f938324_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {94DDB33B-0018-4e7c-9035-C4F2A343992A}*/
    static E2E_MEP_CheckStateType ls_E2E_State_Read;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
     (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    ls_E2E_State_Read.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &ls_E2E_State_Read, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == ls_E2E_State_Read.Status) || (E2E_MEP_STATUS_OKSOMELOST == ls_E2E_State_Read.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == ls_E2E_State_Read.Status)
    {

        v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGSEQUENCE == ls_E2E_State_Read.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_7_oFDCAN2_261ebfe1_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr) /*PRQA S 0794, 0795*/
{
  /* DD-ID: {53006AF9-3726-4d19-9A2C-3CAB1C628D74}*/
    static E2E_MEP_CheckStateType ls_E2E_State_Read;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
     (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    ls_E2E_State_Read.NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &ls_E2E_State_Read, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == ls_E2E_State_Read.Status) || (E2E_MEP_STATUS_OKSOMELOST == ls_E2E_State_Read.Status)))
    {
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == ls_E2E_State_Read.Status)
    {

        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGSEQUENCE == ls_E2E_State_Read.Status)
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }
   return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_14_oFDCAN2_f082faaa_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {584AC09F-A1C6-4651-AFCD-9028B9C236AA}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TELEMATIC_FD_14_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;

    if ((uint8)e_TWO != s_TELEMATIC_FD_14_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD14,ErrorMgr_ErrorInactive,NULL_PTR);
        s_TELEMATIC_FD_14_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength<D_DLC_TELEMATIC_FD_14) 
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            if((uint8)e_ONE != s_TELEMATIC_FD_14_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD14,ErrorMgr_ErrorActive,NULL_PTR);
                s_TELEMATIC_FD_14_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_TELEMATIC_FD_14_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD14,ErrorMgr_ErrorInactive,NULL_PTR);
            s_TELEMATIC_FD_14_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT14,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT14,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].Status)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT14,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].Status) || (E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].Status))
    {
        if((TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT14,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else
    {
       /*Do nothing*/
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_4_oFDCAN2_94daed95_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {8DC92E57-BED1-49a6-B70B-F8955A80198A}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TRANSM_FD_4_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;

    if ((uint8)e_TWO != s_TRANSM_FD_4_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD4,ErrorMgr_ErrorInactive,NULL_PTR);
        s_TRANSM_FD_4_MM_u8 = (uint8)e_TWO;
    }

    if(PduInfoPtr->SduLength<D_DLC_TRANSM_FD_4)
    {
        if(((THA_FEATURE) || (FULL_PPPA_FEATURE) || (SVC360_FEATURE) ) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_TRANSM_FD_4_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD4,ErrorMgr_ErrorActive,NULL_PTR);
                s_TRANSM_FD_4_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_TRANSM_FD_4_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD4,ErrorMgr_ErrorInactive,NULL_PTR);
            s_TRANSM_FD_4_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_TRANSM_FD_4_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TRANSM_FD_4_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TRANSM_FD_4_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TRANSM_FD_4_ID].Status)))
    {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM4,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM4,ErrorMgr_ErrorInactive,NULL_PTR);
       v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TRANSM_FD_4_ID].Status)
    {
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)|| (SVC360_FEATURE)) && (CMD_IGN_STATUS) )
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM4,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TRANSM_FD_4_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TRANSM_FD_4_ID].Status))
    {
      /* CR: 21034004
       * Task: 21215973
       * Description:Surrounding view feature condition added for MC_TRANSM_FD4
       */
        if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM4,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else
    {
     /*Do Nothing*/
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_1_oFDCAN14_02aef4ed_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {02469204-CE36-4baa-8A31-CEF66D426B74}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BRAKE_FD_1_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;
	(void)PduInfoPtr;

    if ((uint8)e_TWO != s_BRAKE_FD_1_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_1,ErrorMgr_ErrorInactive,NULL_PTR);
        s_BRAKE_FD_1_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength<D_DLC_BRAKE_FD_1)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_1_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_1,ErrorMgr_ErrorActive,NULL_PTR);
                s_BRAKE_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BRAKE_FD_1_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_1,ErrorMgr_ErrorInactive,NULL_PTR);
            s_BRAKE_FD_1_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD14_BRAKE_FD_1_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_1_ID].Status)))
    {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE1,ErrorMgr_ErrorInactive,NULL_PTR);
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE1,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_1_ID].Status)
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE))
       {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE1,ErrorMgr_ErrorActive,NULL_PTR);
       }
       v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_1_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_1_ID].Status))
    {
       if ((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE) )
       {
           (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE1,ErrorMgr_ErrorActive,NULL_PTR);
       }
       v_retVal_b = TRUE;
    }
    else
    {
      /* Nothing */
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_4_oFDCAN14_e4873fa9_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {FF9D06B4-2D82-4dd3-9D15-CDEEF9C30B93}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BRAKE_FD_4_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;

    if ((uint8)e_TWO != s_BRAKE_FD_4_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_4,ErrorMgr_ErrorInactive,NULL_PTR);
        s_BRAKE_FD_4_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength<D_DLC_BRAKE_FD_4)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_4_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_4,ErrorMgr_ErrorActive,NULL_PTR);
                s_BRAKE_FD_4_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else  
    {
        if((uint8)e_TWO != s_BRAKE_FD_4_DLC_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_4,ErrorMgr_ErrorInactive,NULL_PTR);
            s_BRAKE_FD_4_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD14_BRAKE_FD_4_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_4_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_4_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_4_ID].Status)))
    {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE4,ErrorMgr_ErrorInactive,NULL_PTR);
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE4,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_4_ID].Status)
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE))
       {
          (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE4,ErrorMgr_ErrorActive,NULL_PTR);
       }
       v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_4_ID].Status)|| (E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_4_ID].Status))
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE))
       {
          (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE4,ErrorMgr_ErrorActive,NULL_PTR);
       }
       v_retVal_b = TRUE;
    }
    else
    {
      //QAC
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_7_oFDCAN14_0fb084aa_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {030F8C5D-DD21-4d85-8046-19AEA0CDC22A}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BRAKE_FD_7_DLC_u8 = (uint8)e_ZERO;
     (void)PduId;

    if ((uint8)e_TWO != s_BRAKE_FD_7_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_7,ErrorMgr_ErrorInactive,NULL_PTR);
        s_BRAKE_FD_7_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength<D_DLC_BRAKE_FD_7)
    {
        if((PARB_FEATURE) || (FULL_PPPA_FEATURE))
        {
            if((uint8)e_ONE != s_BRAKE_FD_7_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_7,ErrorMgr_ErrorActive,NULL_PTR);
                s_BRAKE_FD_7_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BRAKE_FD_7_DLC_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BRAKE_FD_7,ErrorMgr_ErrorInactive,NULL_PTR);
            s_BRAKE_FD_7_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD14_BRAKE_FD_7_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_BRAKE_FD_7_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_BRAKE_FD_7_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_BRAKE_FD_7_ID].Status)))
    {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE7,ErrorMgr_ErrorInactive,NULL_PTR);
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE7,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_BRAKE_FD_7_ID].Status)
    {
      if((PARB_FEATURE) || (FULL_PPPA_FEATURE))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BRAKE7,ErrorMgr_ErrorActive,NULL_PTR);
      }
       v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_BRAKE_FD_7_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_BRAKE_FD_7_ID].Status))
    {
      if((PARB_FEATURE) || (FULL_PPPA_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BRAKE7,ErrorMgr_ErrorActive,NULL_PTR);
      }
        v_retVal_b = TRUE;
    }
    else
    {
      //QAC
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_IPC_VEHICLE_SETUP_oFDCAN2_ddb2e91d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {15FEE8F1-BDF7-4c93-9D5E-19F440EE16FF}*/
    static uint8 s_IPC_VEHICLE_SETUP_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_IPC_VEHICLE_SETUP_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_IPC_VEHICLE_SETUP,ErrorMgr_ErrorInactive,NULL_PTR);
        s_IPC_VEHICLE_SETUP_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength<D_DLC_IPC_VEHICLE_SETUP)
    {
        if(((FULL_PPPA_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_IPC_VEHICLE_SETUP_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_IPC_VEHICLE_SETUP,ErrorMgr_ErrorActive,NULL_PTR);
                s_IPC_VEHICLE_SETUP_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_IPC_VEHICLE_SETUP_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_IPC_VEHICLE_SETUP,ErrorMgr_ErrorInactive,NULL_PTR);
            s_IPC_VEHICLE_SETUP_DLC_u8 = (uint8)e_TWO;
        }
    }
return TRUE;
}


FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_2_oFDCAN2_f3daca1a_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {0AB54B3F-6F0A-49e1-967A-17D9868E98E2}*/
	/*GUID:-{7CE8668D-C04E-40d8-8071-D63536C9CACA}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BCM_FD_2_DLC_u8 = (uint8)e_ZERO;
   (void)PduId;

    if ((uint8)e_TWO != s_BCM_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
        s_BCM_FD_2_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength < D_DLC_BCM_FD_2)
    {
        if((FULL_PPPA_FEATURE) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_2_DLC_u8 )
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
                s_BCM_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BCM_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
            s_BCM_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_BCM_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_2_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM2,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM2,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_2_ID].Status)
    {
      if((FULL_PPPA_FEATURE) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_2_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_2_ID].Status))
    {
      if((FULL_PPPA_FEATURE) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      //QAC
    }
     return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_5_oFDCAN2_e0161ca6_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {777B97C6-B21F-4eb5-99B6-AF4389FE4964}*/
	/*GUID:-{E4A5CC20-38D4-40bd-9808-A5484758D3CA}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TELEMATIC_FD_5_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_TELEMATIC_FD_5_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD5, ErrorMgr_ErrorInactive, NULL_PTR);
        s_TELEMATIC_FD_5_MM_u8 = (uint8)e_TWO;
    }

    if(PduInfoPtr->SduLength < D_DLC_TELEMATIC_FD_5)
    {
        if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
        {
            if((uint8)e_ONE != s_TELEMATIC_FD_5_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD5, ErrorMgr_ErrorActive, NULL_PTR);
                s_TELEMATIC_FD_5_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_TELEMATIC_FD_5_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD5, ErrorMgr_ErrorInactive, NULL_PTR);
            s_TELEMATIC_FD_5_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].Status)))
    {
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT5,ErrorMgr_ErrorInactive,NULL_PTR);
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT5,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].Status)
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT5,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].Status))
    {
      if((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT5,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
      //qac
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_2_oFDCAN2_e7c0941f_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {F5D09A5C-5CC9-4cfa-BEF0-A72A21277A40}*/
	/*GUID:-{49B234EB-86B1-4a7b-8AA3-9E8044EB9782}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TRANSM_FD_2_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;

    if ((uint8)e_TWO != s_TRANSM_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
        s_TRANSM_FD_2_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_TRANSM_FD_2)
    {
        if(((THA_FEATURE) || (TRSC_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_TRANSM_FD_2_DLC_u8 )
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
                s_TRANSM_FD_2_DLC_u8 = (uint8)e_ONE;
            }   
        }   
    }
    else
    {
        if((uint8)e_TWO != s_TRANSM_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TRANSM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
            s_TRANSM_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD2_TRANSM_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TRANSM_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TRANSM_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TRANSM_FD_2_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM2,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM2,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TRANSM_FD_2_ID].Status)
    {
      if(((TRSC_FEATURE) || (THA_FEATURE)) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TRANSM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
     v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TRANSM_FD_2_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TRANSM_FD_2_ID].Status))
    {
      if(((THA_FEATURE) || (TRSC_FEATURE)) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TRANSM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
     v_retVal_b = TRUE;
    }
    else
    {
      //QAC
    }
     return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_2_oFDCAN14_2d544e1a_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {10A182AA-96B0-409c-A433-5D03ED70DF69}*/
	/*GUID:-{04857263-4B41-4a56-80F8-CA5FA2CF05F7}*/

    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_ENGINE_FD_2_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;
    if ((uint8)e_TWO != s_ENGINE_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ENGINE_FD_2_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_ENGINE_FD_2)
    {
        if((TRSC_FEATURE) || (THA_FEATURE)) 
        {
            if((uint8)e_ONE != s_ENGINE_FD_2_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD2, ErrorMgr_ErrorActive, NULL_PTR);
                s_ENGINE_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_ENGINE_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
            s_ENGINE_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read[FD14_ENGINE_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_ENGINE_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_ENGINE_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_ENGINE_FD_2_ID].Status)))
    {
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_CRC_Fault_ENGINE2,ErrorMgr_ErrorInactive,NULL_PTR);
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_MC_Fault_ENGINE2,ErrorMgr_ErrorInactive,NULL_PTR);
     v_retVal_b = TRUE;
    }
    else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_ENGINE_FD_2_ID].Status)
    {
      if((TRSC_FEATURE) || (THA_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_CRC_Fault_ENGINE2,ErrorMgr_ErrorActive,NULL_PTR);
      }
     v_retVal_b = TRUE;
    }
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_ENGINE_FD_2_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_ENGINE_FD_2_ID].Status))
    {
      if((TRSC_FEATURE) || (THA_FEATURE))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_MC_Fault_ENGINE2,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
	else
	{
       /*Do nothing*/
	}
     return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_AGSM_FD_2_oFDCAN2_97b68631_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {5E01C506-DAD0-4cb7-BC0A-7DA12F536078}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_AGSM_FD_2_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_AGSM_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_AGSM_FD2,ErrorMgr_ErrorInactive,NULL_PTR);
        s_AGSM_FD_2_MM_u8 = (uint8)e_TWO;
    }
      /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    if(PduInfoPtr->SduLength<D_DLC_AGSM_FD_2)
    {
        if(((FULL_PPPA_FEATURE) && ((uint8)e_ONE == v_SurroundViewCam_u8)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_AGSM_FD_2_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_AGSM_FD2,ErrorMgr_ErrorActive,NULL_PTR);
                s_AGSM_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_AGSM_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_AGSM_FD2,ErrorMgr_ErrorInactive,NULL_PTR);
            s_AGSM_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_AGSM_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_AGSM_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_AGSM_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_AGSM_FD_2_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_AGSM2,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_AGSM2,ErrorMgr_ErrorInactive,NULL_PTR);
       v_retVal_b = TRUE;
    }
    /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    else if(E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_AGSM_FD_2_ID].Status)
    {
     if((FULL_PPPA_FEATURE) && ((uint8)e_ONE == v_SurroundViewCam_u8) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_AGSM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
       v_retVal_b = TRUE;
    }
    /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_AGSM_FD_2_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_AGSM_FD_2_ID].Status))
    {
      if ((FULL_PPPA_FEATURE) && ((uint8)e_ONE == v_SurroundViewCam_u8) && (CMD_IGN_STATUS))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_AGSM2,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
       //qac
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_29_oFDCAN2_cae28ef6_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {09566469-B30C-4e8e-AC64-C71F1E7D8947}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_BCM_FD_29_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_BCM_FD_29_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD29,ErrorMgr_ErrorInactive,NULL_PTR);
        s_BCM_FD_29_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength<D_DLC_BCM_FD_29)
    {
        if((codingTableExt_s.CanNode95itcm_uint8 == TRUE) && ( (FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
        {
            if((uint8)e_ONE != s_BCM_FD_29_DLC_u8 )
            {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD29,ErrorMgr_ErrorActive,NULL_PTR);
            s_BCM_FD_29_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_BCM_FD_29_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_BCM_FD29,ErrorMgr_ErrorInactive,NULL_PTR);
            s_BCM_FD_29_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_BCM_FD_29_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_BCM_FD_29_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_BCM_FD_29_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_BCM_FD_29_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM29,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM29,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
      else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_BCM_FD_29_ID].Status)
    {
      if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_BCM29,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
      else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_BCM_FD_29_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_BCM_FD_29_ID].Status))
    {
      if(( (FULL_PPPA_FEATURE) || (TRSC_FEATURE)|| (THA_FEATURE) || (PARB_PA_FEATURE) ) && (CMD_IGN_STATUS))
      {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_BCM29,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
        /* QAC */
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_11_oFDCAN2_ba15bfe5_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {EB3B7566-AD33-4c48-A6D0-6DE29FACB67A}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TELEMATIC_FD_11_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_TELEMATIC_FD_11_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD11,ErrorMgr_ErrorInactive,NULL_PTR);
        s_TELEMATIC_FD_11_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength<D_DLC_TELEMATIC_FD_11)
    {
        if(((uint8)e_NINE == codingTableExt_s.Radiodisplay) && ((TRSC_FEATURE) || (FULL_PPPA_FEATURE)))
        {
            if((uint8)e_ONE != s_TELEMATIC_FD_11_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD11,ErrorMgr_ErrorActive,NULL_PTR);
                s_TELEMATIC_FD_11_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_TELEMATIC_FD_11_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_TELEMATIC_FD11,ErrorMgr_ErrorInactive,NULL_PTR);
            s_TELEMATIC_FD_11_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].Status)))
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT11,ErrorMgr_ErrorInactive,NULL_PTR);
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT11,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].Status)
    {
        if(TRSC_FEATURE)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_TELEMT11,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].Status))
    {
        if(TRSC_FEATURE)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_TELEMT11,ErrorMgr_ErrorActive,NULL_PTR);
        }
      v_retVal_b = TRUE;
    }
    else
    {
     //QAC
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_7_oFDCAN14_cb7d855e_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {7AECE277-6897-4d85-B96B-275F9C6C182C}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_ENGINE_FD_7_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;
    if ((uint8)e_TWO != s_ENGINE_FD_7_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD7, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ENGINE_FD_7_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_ENGINE_FD_7)
    {
        if((TRSC_FEATURE) || (THA_FEATURE)) 
        {
            if((uint8)e_ONE != s_ENGINE_FD_7_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD7, ErrorMgr_ErrorActive, NULL_PTR);
                s_ENGINE_FD_7_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else
    {
        if((uint8)e_TWO != s_ENGINE_FD_7_DLC_u8) 
        {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD7, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ENGINE_FD_7_DLC_u8 = (uint8)e_TWO;
        }
    }
 
    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD14_ENGINE_FD_7_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_ENGINE_FD_7_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_ENGINE_FD_7_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_ENGINE_FD_7_ID].Status)))
    {
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_CRC_Fault_ENGINE7,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_MC_Fault_ENGINE7,ErrorMgr_ErrorInactive,NULL_PTR);
         v_retVal_b = TRUE;
    }
      else if( E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_ENGINE_FD_7_ID].Status)
    {
      if((TRSC_FEATURE) || (THA_FEATURE))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_CRC_Fault_ENGINE7,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
      else if((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_ENGINE_FD_7_ID].Status)||( E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_ENGINE_FD_7_ID].Status))
    {
      if((TRSC_FEATURE) || (THA_FEATURE))
      {
      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_ECM_MC_Fault_ENGINE7,ErrorMgr_ErrorActive,NULL_PTR);
      }
      v_retVal_b = TRUE;
    }
    else
    {
       //QAC
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_2_oFDCAN14_63661a56_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {1A230DE2-6316-4e48-BA97-9A070C415C19}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_EPS_FD_2_DLC_u8 = (uint8)e_ZERO;
  (void)PduId;

    if ((uint8)e_TWO != s_EPS_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_EPS_FD_2,ErrorMgr_ErrorInactive,NULL_PTR);
        s_EPS_FD_2_MM_u8 = (uint8)e_TWO;
    }
   
    if(PduInfoPtr->SduLength<D_DLC_EPS_FD_2) 
    {
        if((THA_FEATURE) || (TRSC_FEATURE)) 
        {
            if((uint8)e_ONE != s_EPS_FD_2_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_EPS_FD_2,ErrorMgr_ErrorActive,NULL_PTR);
                s_EPS_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_EPS_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_EPS_FD_2,ErrorMgr_ErrorInactive,NULL_PTR);
            s_EPS_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD14_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD14_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
 
    s_E2E_State_Read[FD14_EPS_FD_2_ID].NewDataAvailable = TRUE;
 
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD14_Read, &s_E2E_State_Read[FD14_EPS_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD14_EPS_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD14_EPS_FD_2_ID].Status)))
    {
     (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_EPS2,ErrorMgr_ErrorInactive,NULL_PTR);
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_EPS2,ErrorMgr_ErrorInactive,NULL_PTR);
      v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD14_EPS_FD_2_ID].Status)
    {
      if((THA_FEATURE) || (TRSC_FEATURE))
      {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_Fault_EPS2,ErrorMgr_ErrorActive,NULL_PTR);
      }
       v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD14_EPS_FD_2_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD14_EPS_FD_2_ID].Status))
    {
      if((THA_FEATURE) || (TRSC_FEATURE))
      {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_EPS2,ErrorMgr_ErrorActive,NULL_PTR);
      }
       v_retVal_b = TRUE;
    }
    else
    {
      /* QAC */
    }
 
    return v_retVal_b;
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx(void)
{
  /* DD-ID: {854EA150-81D6-40e9-8297-2D931B224286}*/
    if (((FULL_PPPA_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_IPC_VEHICLE_SETUP_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_IPC_VEHICLE_SETUP, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_IPC_VEHICLE_SETUP_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx(void)
{
	boolean v_NmNormalStatFlg_b = FALSE;
	(void)Rte_Read_RpNmStateInfo_v_IsNmStateNormal_b(&v_NmNormalStatFlg_b);
  /* DD-ID: {AFD41651-4923-4f20-B0F5-C3B4C3FA8020}*/

    if(((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (v_CmdIgnsts_Init_u8 == TRUE) && (v_NmNormalStatFlg_b == TRUE) )
    {
        if((uint8)e_ONE != s_BCM_FD_10_MM_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD10, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_10_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_10_ID].WaitForFirstData, (uint8)TRUE);

}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx(void)
{
  /* DD-ID: {30095E2B-2667-4479-BD5D-E4AA2998BD8C}*/
    if (((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_7_MM_u8)
         {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_7, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_BRAKE_FD_7_MM_u8, (uint8)e_ONE);
         }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_7_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx(void)
{
  /* DD-ID: {548C49F0-48EE-43eb-86AD-19E7036101FB}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_1_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_1, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BRAKE_FD_1_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_1_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx(void)
{
  /* DD-ID: {5119C296-5EC3-42a3-85AF-DAB1DFCF72DE}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE) || (FOD_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_2_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_2, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BRAKE_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx(void)
{
  /* DD-ID: {AF01F34B-3B82-4039-B2A3-ED4D7EDE1B1A}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (FOD_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_4_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_4, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_BRAKE_FD_4_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_4_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx(void)
{
  /* DD-ID: {D8B3D0A0-942C-4a9d-AD07-9C8202BD8188}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_3_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_3, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_BRAKE_FD_3_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_3_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx(void)
{
  /* DD-ID: {D0F5F09A-82FD-4bb3-8218-4BBFC8B41026}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_EPS_FD_1_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_EPS_FD_1, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_EPS_FD_1_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_EPS_FD_1_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx(void)
{
  /* DD-ID: {F5E7F673-FBE6-4c22-9030-71E036175442}*/
    if (((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_BCM_FD_12_MM_u8) 
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD12, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_12_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_12_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx(void)
{
  /* DD-ID: {7C292838-68D3-4dc0-BA91-A8506E86B220}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_BCM_FD_9_MM_u8) 
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD9, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_9_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_9_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx(void)
{
  /* DD-ID: {B69C19F7-86EB-4a7e-A4C4-F49DADFAB801}*/
    if (((THA_FEATURE) || (FULL_PPPA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_TRANSM_FD_4_MM_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD4, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_TRANSM_FD_4_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TRANSM_FD_4_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx(void)
{
  /* DD-ID: {3CE30714-87E6-4f77-A04D-7F5385AB3C36}*/
    if ((codingTableExt_s.CanNode67dtcm_uint8 == TRUE) && (v_FailsafeFlag_b == FALSE) && ((PARB_FEATURE) || (FULL_PPPA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_DRIVETRAIN_FD_3_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_DRIVETRAIN_FD3, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_DRIVETRAIN_FD_3_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_DRIVETRAIN_FD_3_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx(void)
{
  /* DD-ID: {9CB48DF9-B6DE-4ec8-92F1-B32D841F9A2A}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_TELEMATIC_FD_14_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD14, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_TELEMATIC_FD_14_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TELEMATIC_FD_14_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx(void)
{
  /* DD-ID: {90718783-BBC5-47e0-8B56-0731115A0AED}*/
    if (((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_TRANSM_FD_1_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD1, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_TRANSM_FD_1_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TRANSM_FD_1_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx(void)
{
  /* DD-ID: {5ED3FE4A-D334-480f-A949-09DFBB69D944}*/
    if ((v_FailsafeFlag_b == FALSE) && ((PARB_PA_FEATURE) || (FULL_PPPA_FEATURE) || (THA_FEATURE) || (TRSC_FEATURE)) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_BCM_FD_27_MM_u8) 
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD27, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_27_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_27_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE)ComNotification_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void)
{
  /* DD-ID: {0145BE3E-0FE7-45ff-BE15-1C2F61ADDE1B}*/
}
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void)
{
  /* DD-ID: {BB9383EC-C795-417b-95C4-EB4D24660761}*/
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx(void)
{
  /* DD-ID: {4352A971-05CC-41fa-A65E-412F61C2D542}*/
    if (((TRSC_FEATURE) || (THA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_BRAKE_FD_5_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BRAKE_FD_5, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_BRAKE_FD_5_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_BRAKE_FD_5_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_ASCM_FD_1_oFDCAN2_d84f57a2_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {A73A6796-BAC1-4276-A5F0-825F5D967805}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_ASCM_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;

    if ((uint8)e_TWO != s_ASCM_FD_1_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ASCM_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ASCM_FD_1_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_ASCM_FD_1)  
    {
        if((codingTableExt_s.CanNode27Asm_uint8 == TRUE) && (THA_FEATURE) && (CMD_IGN_STATUS))
        {
            if( (uint8)e_ONE != s_ASCM_FD_1_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ASCM_FD1, ErrorMgr_ErrorActive, NULL_PTR);
                s_ASCM_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if ((uint8)e_TWO != s_ASCM_FD_1_DLC_u8) 
        {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ASCM_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ASCM_FD_1_DLC_u8 = (uint8)e_TWO;
        }
    }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_ASCM_FD_1_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_ASCM_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_ASCM_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_ASCM_FD_1_ID].Status)))
    {
        // Removed in ErrM1.116      (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_ASCM_FD_1,ErrorMgr_ErrorInactive,NULL_PTR);
        // Removed in ErrM1.116   (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_ASCM_FD_1,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_ASCM_FD_1_ID].Status)
    {
        /* Workaround for 6.00 release */
        //(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_ASCM_FD_1,ErrorMgr_ErrorActive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_ASCM_FD_1_ID].Status) || (E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_ASCM_FD_1_ID].Status))
    {

        //(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_ASCM_FD_1,ErrorMgr_ErrorActive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else
    {
        // QAC
    }
    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_ASCM_FD_2_oFDCAN2_e1c26b67_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {10830862-C222-454a-8EA6-4B5B4D7BB877}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_ASCM_FD_2_DLC_u8 = (uint8)e_ZERO;
   (void)PduId;

    if ((uint8)e_TWO != s_ASCM_FD_2_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ASCM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ASCM_FD_2_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_ASCM_FD_2) 
    {
        if((codingTableExt_s.CanNode27Asm_uint8 == TRUE) && (THA_FEATURE) && (CMD_IGN_STATUS)) 
        {
            if((uint8)e_ONE != s_ASCM_FD_2_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ASCM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
                s_ASCM_FD_2_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_ASCM_FD_2_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ASCM_FD2, ErrorMgr_ErrorInactive, NULL_PTR);
            s_ASCM_FD_2_DLC_u8 = (uint8)e_TWO;
        }
    }


    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_ASCM_FD_2_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_ASCM_FD_2_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_ASCM_FD_2_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_ASCM_FD_2_ID].Status)))
    {
        // Removed in ErrM1.116  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_ASCM_FD_2,ErrorMgr_ErrorInactive,NULL_PTR);
        // Removed in ErrM1.116 (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_ASCM_FD_2,ErrorMgr_ErrorInactive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_ASCM_FD_2_ID].Status)
    {
        /* Workaround for 6.00 release */
        //(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_CRC_ASCM_FD_2,ErrorMgr_ErrorActive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_ASCM_FD_2_ID].Status) || (E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_ASCM_FD_2_ID].Status))
    {
        //(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MC_Fault_ASCM_FD_2,ErrorMgr_ErrorActive,NULL_PTR);
        v_retVal_b = TRUE;
    }
    else
    {
        // QAC
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_IPC_FD_1_oFDCAN2_0e087dd4_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {3ADAB830-5632-42ec-AF23-F8407F253157}*/
    static uint8 s_IPC_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;

    if ((uint8)e_TWO != s_IPC_FD_1_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_IPC_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_IPC_FD_1_MM_u8 = (uint8)e_TWO;
    }

    if(PduInfoPtr->SduLength < D_DLC_IPC_FD_1)
    {
        if(CMD_IGN_STATUS)
        {
            if((uint8)e_ONE != s_IPC_FD_1_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_IPC_FD1, ErrorMgr_ErrorActive, NULL_PTR);
                s_IPC_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_IPC_FD_1_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_IPC_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
            s_IPC_FD_1_DLC_u8 = (uint8)e_TWO;
        }
    }
    return TRUE;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_VIN_oFDCAN2_e2480108_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {E2FF0C48-0314-428a-A127-3E31357832C2}*/
    static uint8 s_VIN_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;


    if ((uint8)e_TWO != s_VIN_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_VIN, ErrorMgr_ErrorInactive, NULL_PTR);
        s_VIN_MM_u8 = (uint8)e_TWO;
        (void)Rte_Write_PpVIN_MessageFault_VIN_MissingMessageFlag(FALSE);
    }
    if(PduInfoPtr->SduLength < D_DLC_VIN)
    {
        if(CMD_IGN_STATUS)
        {
            if((uint8)e_ONE != s_VIN_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_VIN, ErrorMgr_ErrorActive, NULL_PTR);
                s_VIN_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_VIN_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_VIN, ErrorMgr_ErrorInactive, NULL_PTR);
            s_VIN_DLC_u8 = (uint8)e_TWO;
        }
    }
    return TRUE;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_BRAKE_FD_6_oFDCAN14_e072ef94_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    /* DD-ID:{9D3BA217-0246-4d7d-BE51-A420831DFA3B}*/
	(void)PduId;
	(void)PduInfoPtr;
    return TRUE;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_ENGINE_FD_5_oFDCAN14_cf885563_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {5DB0B548-6530-48f2-93B4-177BDEC94204}*/
    static uint8 s_ENGINE_FD_5_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;
	(void)PduInfoPtr;
    if ((uint8)e_TWO != s_ENGINE_FD_5_MM_u8)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD5, ErrorMgr_ErrorInactive, NULL_PTR);
        s_ENGINE_FD_5_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_ENGINE_FD_5)
    {
        if((TRSC_FEATURE) || (THA_FEATURE)) 
        {
            if((uint8)e_ONE != s_ENGINE_FD_5_DLC_u8)
            {
                (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD5, ErrorMgr_ErrorActive, NULL_PTR);
                s_ENGINE_FD_5_DLC_u8 = (uint8)e_ONE;
            }
        }
    }
    else 
    {
        if((uint8)e_TWO != s_ENGINE_FD_5_DLC_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD5, ErrorMgr_ErrorInactive, NULL_PTR);
            s_ENGINE_FD_5_DLC_u8 = (uint8)e_TWO;
        }
    }

    return TRUE;
}

FUNC(boolean, COM_APPL_CODE)ComIPduCallout_PT_TORQUE_FD_1_oFDCAN14_c23d259d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr) 
{ 
    /* DD-ID: {ECF207B8-ED1E-4f25-95E4-B619A667D977}*/
    return TRUE; 
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx(void)
{
  /* DD-ID: {36E1E579-5240-4856-9001-A62A1B15A81C}*/
    if ((THA_FEATURE) && (codingTableExt_s.CanNode27Asm_uint8 == TRUE) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_ASCM_FD_2_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ASCM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_ASCM_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_ASCM_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx(void)
{
  /* DD-ID: {D7F38DA7-4DA8-4ea1-B56D-72FCD7DC91CC}*/
    if (((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (SVC360_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_TELEMATIC_FD_5_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD5, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_TELEMATIC_FD_5_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TELEMATIC_FD_5_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx(void) 
{
    /* DD-ID: {AF4EC5BB-39C1-450c-A8B0-9378B9CB08EC}*/
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx(void)
{
  /* DD-ID: {BFEA394A-A1AC-434c-8A0C-E653D500B16B}*/
    if (((TRSC_FEATURE) || (THA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_ENGINE_FD_7_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD7, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_ENGINE_FD_7_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_ENGINE_FD_7_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx(void)
 {
    /* DD-ID: {BABA6C9D-E446-472d-9CEF-3AE7DB543409}*/
 }

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx(void)
{
  /* DD-ID: {7003DC84-6D33-4e5f-B340-DFB463CE0875}*/
    if (((TRSC_FEATURE) || (THA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_ENGINE_FD_2_MM_u8)
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD2, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_ENGINE_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_ENGINE_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx(void)
{
  /* DD-ID: {43FC7CEF-CFD8-4f94-B7C4-246E00BBC475}*/
    if (((TRSC_FEATURE) || (THA_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_ENGINE_FD_5_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD5, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_ENGINE_FD_5_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx(void)
{
  /* DD-ID: {09EFE18C-5C7F-4d7a-B5BF-50354C7B90E5}*/
    if (((THA_FEATURE) || (TRSC_FEATURE)) && (v_FailsafeFlag_b == FALSE))
    {
        if((uint8)e_ONE != s_EPS_FD_2_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_EPS_FD_2, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_EPS_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD14_EPS_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx(void)
{
  /* DD-ID: {CFF6D769-E084-48af-9A1B-F7A484E49825}*/
    if ((THA_FEATURE) && (codingTableExt_s.CanNode27Asm_uint8 == TRUE) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_ASCM_FD_1_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_ASCM_FD1, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_ASCM_FD_1_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_ASCM_FD_1_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx(void)
{
  /* DD-ID: {D66DF523-FBB5-4eb2-A1B6-FD99C8502CFD}*/
    if (((THA_FEATURE) || (TRSC_FEATURE)) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_TRANSM_FD_2_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TRANSM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_TRANSM_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TRANSM_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx(void)
{
  /* DD-ID: {A60176CF-BCF0-49a2-B528-DF45D852EFBA}*/
    if ((codingTableExt_s.Radiodisplay == (uint8)e_NINE) && (v_FailsafeFlag_b == FALSE) && ((TRSC_FEATURE) || (FOD_FEATURE)))
    {
        if((uint8)e_ONE != s_TELEMATIC_FD_11_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_TELEMATIC_FD11, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_TELEMATIC_FD_11_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_TELEMATIC_FD_11_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx(void)
{
  /* DD-ID: {58E605E7-78D7-4d8a-B85D-3715DA78DCC8}*/
    if ((codingTableExt_s.CanNode95itcm_uint8 == TRUE) && (v_FailsafeFlag_b == FALSE) && ((FULL_PPPA_FEATURE) || (TRSC_FEATURE) || (THA_FEATURE) || (PARB_PA_FEATURE)) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_BCM_FD_29_MM_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD29, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_29_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_29_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx(void)
{
  /* DD-ID: {8B4918EA-0AF5-45f2-8216-7562123D6353}*/
    /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
    if (((uint8)e_ONE == v_SurroundViewCam_u8) && (FULL_PPPA_FEATURE) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_AGSM_FD_2_MM_u8) 
        {
            (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_AGSM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
            Os_Call_Update_ComCallout_FlagStatus(&s_AGSM_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_AGSM_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx(void)
{
  /* DD-ID: {A2559580-3B49-48d1-BEAA-D85B884A88C0}*/
    if ((v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_IPC_FD_1_MM_u8) 
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_IPC_FD1, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_IPC_FD_1_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx(void)
{
  /* DD-ID: {AF7A49D6-EC30-4ecc-8B75-13B1DAD51B58}*/
    if ((FULL_PPPA_FEATURE) && (v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_BCM_FD_2_MM_u8)
        {
        	(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_BCM_FD2, ErrorMgr_ErrorActive, NULL_PTR);
        	Os_Call_Update_ComCallout_FlagStatus(&s_BCM_FD_2_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }
    Os_Call_Update_ComCallout_FlagStatus((uint8 *)&s_E2E_State_Read[FD2_BCM_FD_2_ID].WaitForFirstData, (uint8)TRUE);
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx(void)
{
  /* DD-ID: {FEEBB669-BD8D-4603-8CFF-C9F2087FAF13}*/
    if ((v_FailsafeFlag_b == FALSE) && (CMD_IGN_STATUS))
    {
        if((uint8)e_ONE != s_VIN_MM_u8)
        {
           (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_MissingMessage_VIN, ErrorMgr_ErrorActive, NULL_PTR);
           Os_Call_Update_ComCallout_FlagStatus(&s_VIN_MM_u8, (uint8)e_ONE);
        }
    }
    else
    {
        /*Do Nothing*/
    }

}

static void F_SendCanDataToRemoteCore(void)
{
    /* DD-ID: {50AB4CCE-168E-4e8c-928C-7EA21E3F68CE}*/
  SSM_2_0_CoreStatus SSM_2_0_data;
  SSM_2_1_CoreStatus SSM_2_1_data;
  SSM_QNX_CoreStatus SSM_QNX_data;
  ME_Proxi_MPU1_0_to_MCU1_0_t ME_Proxi_MPU1_0_to_MCU1_0_data;

  /*Read MCU 2_0 status*/
  (void)Rte_Read_R_SSM_2_State_State_2_0(&SSM_2_0_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_0_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MCU2_0_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&S_VCANtoIPC, (uint16)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f, (uint16)sizeof(ME_VehInp_to_IpcSignals_t));
    v_RemoteCoreStatus_u8 |= MCU2_0_STATE;   /*Update core Status Flag once data is transmited*/
    #ifdef Enable_Printf
    appLogPrintf("\n Sent CAN Data to MCU2_0 core");
    #endif
  }

  /*Read MCU 2_1 status*/
  (void)Rte_Read_R_SSM_2_State_State_2_1(&SSM_2_1_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_1_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MCU2_1_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&S_VCANtoIPC, (uint16)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f, (uint16)sizeof(ME_VehInp_to_IpcSignals_t));
    v_RemoteCoreStatus_u8 |= MCU2_1_STATE;   /*Update core Status Flag once data is transmited*/
   #ifdef Enable_Printf
    appLogPrintf("\n Sent CAN Data to MCU2_1 core");
   #endif
  }

  /*Read Qnx status*/
  (void)Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(&ME_Proxi_MPU1_0_to_MCU1_0_data);
  if ((ME_Proxi_MPU1_0_to_MCU1_0_data.state == QNX_BOOTUP_STATE) && ((v_RemoteCoreStatus_u8 & MPU1_0_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&S_VCANtoIPC, (uint16)e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f, (uint16)sizeof(ME_VehInp_to_IpcSignals_t));
    v_RemoteCoreStatus_u8 |= MPU1_0_STATE;   /*Update core Status Flag once data is transmited*/
    #ifdef Enable_Printf
    appLogPrintf("\n Sent CAN Data to MPU1_0 core");
    #endif
  }

}

void Update_ComCallout_FlagStatus(uint8* const flagPtrU8, const uint8 data)
{
	/*DD-ID:{03C97C7C-F651-4290-AC8E-ACEF4BC0611C}*/
	if(NULL_PTR != (void *)flagPtrU8)
	{
		*flagPtrU8 = data;
	}
}

#define SWC_SafeVCANRx_STOP_SEC_CODE
#include "SWC_SafeVCANRx_MemMap.h"

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
