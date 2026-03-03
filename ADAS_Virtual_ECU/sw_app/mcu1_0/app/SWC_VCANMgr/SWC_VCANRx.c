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
 *             File:  SWC_VCANRx.c
 *           Config:  D:/git/L2H4060_Software_master/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_VCANRx
 *  Generation Time:  2025-08-20 17:38:09
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_VCANRx>
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
 * ExternalTemperature
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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

#include "Rte_SWC_VCANRx.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_VCANMgr.h"
#include "Enums.h"
#include "Os_Lcfg.h"

# define D_READ_SIGNAL_FROMCOM_FD14(Sig, Var) (void)Rte_Read_RpFromComFD14Rx_##Sig((Sig*)&(Var))
# define D_WRITE_SIGNAL_TOSWC_FD14(Sig, Var) (void)Rte_Write_PpToSwcFD14Rx_##Sig((Sig)(Var))

# define D_READ_SIGNAL_FROMCOM_FD02(Sig, Var) (void)Rte_Read_RpFromComFD02Rx_##Sig((Sig*)&(Var))
# define D_WRITE_SIGNAL_TOSWC_FD02(Sig, Var) (void)Rte_Write_PpToSwcFD02Rx_##Sig((Sig)(Var))

// For Array
# define D_READ_SIGNAL_FROMCOM_FD14_ARRAY(Sig, Var) (void)Rte_Read_RpFromComFD14Rx_##Sig(Var)
# define D_WRITE_SIGNAL_TOSWC_FD14_ARRAY(Sig, Var) (void)Rte_Write_PpToSwcFD14Rx_##Sig(Var)

# define D_READ_SIGNAL_FROMCOM_FD02_ARRAY(Sig, Var) (void)Rte_Read_RpFromComFD02Rx_##Sig(Var)
# define D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(Sig, Var) (void)Rte_Write_PpToSwcFD02Rx_##Sig(Var)

#define TRSC_FEATURE  			((((uint8)e_ONE ==TrailerConnectionSts_Data)||((uint8)e_ONE ==ITBM_TrlrStat_Data)) && (((uint8)e_ZERO == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_ONE == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_TWO == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts) || ((uint8)e_THREE == ME_VehOut_TRSC_Data.IeTRSC_e_TRSCSts))) /* Req. ID : 21185349 */

#define SBR1ROWDRIVERS_SEATSTS_SNA    3u
#define TRSC_CENTERBTN_STS_SNA        3u
#define TRSC_ENABLEBTN_STS_SNA        3u
#define TRSC_RAWKNOB_LOWRANGE       360u
#define TRSC_RAWKNOB_HIGHRANGE      511u            /* 511 = 0x1FF */


#define D_DLC_ORC_FD_1          (0x20u)
#define D_DLC_TRSKM_FD_1        (0x20u)

static uint8 v_Data_u8;
static uint16 v_Data_u16;
static boolean v_Failsafe_ProhibitFlag_b;

static ME_VehInp_to_IpcSignals_QM_t S_VCANtoIPC_QM;
static ME_VehOut_TRSC_t ME_VehOut_TRSC_Data;
static uint8 s_SBR1RowDriverSeatSts_MM_u8 = (uint8)e_ZERO;
static uint8 s_TRSC_CenterBtn_Sts_MM_u8 = (uint8)e_ZERO;
static ITBM_TrlrStat ITBM_TrlrStat_Data;
static TrailerConnectionSts TrailerConnectionSts_Data;

typedef void (*v_funcptr_v)(void);
typedef enum e_RX_VCAN_AllEventList_s
{
	E_RX_FROMCOM_TOSWC_Process10_mSecSignal= 0U,
	E_RX_FROMCOM_TOSWC_Process20_mSecSignal,
	E_RX_FROMCOM_TOSWC_Process40_mSecSignal,
	E_RX_FROMCOM_TOSWC_Process50_mSecSignal,
	E_RX_FROMCOM_TOSWC_Process1000_mSecSignal,
	E_RX_EVENT_RX_FROMCOM_TOSWC,
    E_RX_Last_EventIndex
}e_RX_VCAN_AllEventList_t;

typedef struct s_EventDataManage
{
	e_RX_VCAN_AllEventList_t EventID;
    boolean isTriggered_b;
    uint8  EventType_u8;
    uint32  CounterValue_u32;
    uint32 PeriodicityTypes_u32;
	v_funcptr_v FuncPtrWrite;
} EventDataManage_t;

static void RX_VCANProcess(void);
static void f_DTC_TRSKM_flag_set_TRSC_RawKnob(TRSC_RawKnob v_Data_u16);
static void f_DTC_TRSKM_flag_set_TRSC_CenterBtn_Sts(TRSC_CenterBtn_Sts v_Data_u8);
static void f_DTC_TRSKM_flag_set_TRSC_EnableBtn_Sts(TRSC_EnableBtn_Sts v_Data_u8);
static void f_DTC_Flag_ORC_FD_1_SBR1RowDriverSeatSts(SBR1RowDriverSeatSts v_Data_u8);

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
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * ExternalTemperature: Integer in interval [0...511]
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
 * Rte_DT_ME_VehOut_TRSC_t_10: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_11: Integer in interval [0...4294967295]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SPMControlSts: Integer in interval [0...3]
 * SPMFailSts: Integer in interval [0...1]
 * SPMSystemFault: Integer in interval [0...1]
 * SPM_LedControlSts: Integer in interval [0...3]
 * SPM_Screen_Rqst: Integer in interval [0...1]
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
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * real32_T: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
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
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
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
 *
 *********************************************************************************************************************/


#define SWC_VCANRx_START_SEC_CODE
#include "SWC_VCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VCANRx_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCANRx_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_VCANRx_CODE) RE_VCANRx_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCANRx_Init
 *********************************************************************************************************************/
 /* DD-ID:{AF861292-A582-4159-B1C3-A3D4CFC352DD}*/
asm("nop");  /* Added for Debug */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VCANRx_Main
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
 *   Std_ReturnType Rte_Read_RpFailSafeReaction_State(boolean *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Altitude_RMSE_C2(Altitude_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_BSM_THA_Brk_Resp(BSM_THA_Brk_Resp *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Battery_Volt_1(Battery_Volt_1 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM(CurrentCanNMState_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW(CurrentCanNMState_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM(CurrentCanNMState_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2(CurrentCanNMState_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2(CurrentCanNMState_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS(CurrentCanNMState_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC(CurrentCanNMState_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW(CurrentCanNMState_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV(CurrentCanNMState_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM(CurrentCanNMState_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW(CurrentCanNMState_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM(CurrentCanNMState_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW(CurrentCanNMState_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW(CurrentCanNMState_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD01_BCM(CurrentFailSts_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD01_SGW(CurrentFailSts_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_BCM(CurrentFailSts_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2(CurrentFailSts_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2(CurrentFailSts_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_EPS(CurrentFailSts_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_ORC(CurrentFailSts_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_SGW(CurrentFailSts_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV(CurrentFailSts_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD03_BCM(CurrentFailSts_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD03_SGW(CurrentFailSts_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD04_BCM(CurrentFailSts_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD08_SGW(CurrentFailSts_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD11_SGW(CurrentFailSts_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD01_BCM(DES_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD01_SGW(DES_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_BCM(DES_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_BSM2(DES_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_CADM2(DES_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_EPS(DES_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_ORC(DES_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_SGW(DES_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD02_TRLR_REV(DES_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD03_BCM(DES_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD03_SGW(DES_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD04_BCM(DES_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD08_SGW(DES_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DES_FD11_SGW(DES_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_DeltaTimestamp_IMUdata(DeltaTimestamp_IMUdata *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_01(Digit_01 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_02(Digit_02 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_03(Digit_03 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_04(Digit_04 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_05(Digit_05 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_06(Digit_06 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_07(Digit_07 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_08(Digit_08 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_09(Digit_09 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_10(Digit_10 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Digit_11(Digit_11 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD01_BCM(EOL_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD01_SGW(EOL_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_BCM(EOL_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_BSM2(EOL_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_CADM2(EOL_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_EPS(EOL_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_ORC(EOL_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_SGW(EOL_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD02_TRLR_REV(EOL_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD03_BCM(EOL_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD03_SGW(EOL_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD04_BCM(EOL_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD08_SGW(EOL_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EOL_FD11_SGW(EOL_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_EPBSts(EPBSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD01_BCM(GenericFailSts_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD01_SGW(GenericFailSts_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_BCM(GenericFailSts_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_BSM2(GenericFailSts_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_CADM2(GenericFailSts_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_EPS(GenericFailSts_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_ORC(GenericFailSts_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_SGW(GenericFailSts_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV(GenericFailSts_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD03_BCM(GenericFailSts_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD03_SGW(GenericFailSts_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD04_BCM(GenericFailSts_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD08_SGW(GenericFailSts_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_GenericFailSts_FD11_SGW(GenericFailSts_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Heading_Angle_C2(Heading_Angle_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_IgnitionOnCounter(IgnitionOnCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHFWheelSpeed(LHFWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHF_FastPulseCounter(LHF_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHF_Spin(LHF_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHRWheelSpeed(LHRWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHR_FastPulseCounter(LHR_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LHR_Spin(LHR_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LatAccelerationOffset_BSM(LatAccelerationOffset_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LatAcceleration_C2(LatAcceleration_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Latitude_RMSE_C2(Latitude_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LongAccelerationOffset_BSM(LongAccelerationOffset_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_LongAcceleration_C2(LongAcceleration_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Longitude_RMSE_C2(Longitude_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_OperationalModeSts(OperationalModeSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PitchRate_C2(PitchRate_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Pitch_RMSE_C2(Pitch_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM(PreviousCanNMState_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW(PreviousCanNMState_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM(PreviousCanNMState_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2(PreviousCanNMState_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2(PreviousCanNMState_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS(PreviousCanNMState_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC(PreviousCanNMState_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW(PreviousCanNMState_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV(PreviousCanNMState_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM(PreviousCanNMState_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW(PreviousCanNMState_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM(PreviousCanNMState_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW(PreviousCanNMState_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW(PreviousCanNMState_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_REF_VEH_SPEED(REF_VEH_SPEED *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHFWheelSpeed(RHFWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHF_FastPulseCounter(RHF_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHF_Spin(RHF_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHRWheelSpeed(RHRWheelSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHR_FastPulseCounter(RHR_FastPulseCounter *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RHR_Spin(RHR_Spin *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RemStActvSts(RemStActvSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_RollRate_C2(RollRate_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_Roll_RMSE_C2(Roll_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_SBR1RowDriverSeatSts(SBR1RowDriverSeatSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD01_BCM(FD01_BCM_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD01_SGW(FD01_SGW_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_BCM(FD02_BCM_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_BSM2(FD02_BSM2_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_CADM2(FD02_CADM2_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_EPS(FD02_EPS_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_ORC(FD02_ORC_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_SGW(FD02_SGW_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV(FD02_TRLR_REV_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD03_BCM(FD03_BCM_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD03_SGW(FD03_SGW_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD04_BCM(FD04_BCM_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD08_SGW(FD08_SGW_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_StayActiveSource_FD11_SGW(FD11_SGW_64 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TRSC_CenterBtn_Sts(TRSC_CenterBtn_Sts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TRSC_EnableBtn_Sts(TRSC_EnableBtn_Sts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TRSC_RawKnob(TRSC_RawKnob *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TurnIndicatorSts(TurnIndicatorSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_VehicleStandStillSts(VehicleStandStillSts *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_VerticalAcceleration_C2(VerticalAcceleration_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_ADCM(WakeupSource_FD01_ADCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_BCM(WakeupSource_FD01_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_SGW(WakeupSource_FD01_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_BCM(WakeupSource_FD02_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_BSM2(WakeupSource_FD02_BSM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_CADM2(WakeupSource_FD02_CADM2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_EPS(WakeupSource_FD02_EPS *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_ORC(WakeupSource_FD02_ORC *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_SGW(WakeupSource_FD02_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV(WakeupSource_FD02_TRLR_REV *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD03_BCM(WakeupSource_FD03_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD03_SGW(WakeupSource_FD03_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD04_BCM(WakeupSource_FD04_BCM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD08_SGW(WakeupSource_FD08_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_WakeupSource_FD11_SGW(WakeupSource_FD11_SGW *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_YawRate_C2(YawRate_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_YawRate_RMSE_C2(YawRate_RMSE_C2 *data)
 *   Std_ReturnType Rte_Read_RpFromComFD14Rx_FD14_Accel_Pedal_Override(FD14_Accel_Pedal_Override *data)
 *   Std_ReturnType Rte_Read_RpFromComFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM(FD14_DriverReq_AxleTrq_Enabled_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromComFD14Rx_FD14_PPPA_TrqEnblRq_Allowed(FD14_PPPA_TrqEnblRq_Allowed *data)
 *   Std_ReturnType Rte_Read_RpGearPosition_GearValue(uint8 *data)
 *   Std_ReturnType Rte_Read_RpGearPosition_ShortTermAdjActiveFlag_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpTRSC_ME_VehOut_TRSC_t(ME_VehOut_TRSC_t *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_ITBM_TrlrStat(ITBM_TrlrStat *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_TrailerConnectionSts(TrailerConnectionSts *data)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_BSM_THA_Brk_Resp(void)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_EPBSts(void)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_SBR1RowDriverSeatSts(void)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_TRSC_CenterBtn_Sts(void)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_TRSC_EnableBtn_Sts(void)
 *   boolean Rte_IsUpdated_RpFromComFD02Rx_TRSC_RawKnob(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpBusOffIndication_V_BusOffIndicationFlagRte_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Altitude_RMSE_C2(Altitude_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_BSM_THA_Brk_Resp(BSM_THA_Brk_Resp data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Battery_Volt_1(Battery_Volt_1 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD01_BCM(CurrentCanNMState_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD01_SGW(CurrentCanNMState_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_BCM(CurrentCanNMState_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2(CurrentCanNMState_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2(CurrentCanNMState_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_EPS(CurrentCanNMState_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_ORC(CurrentCanNMState_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_SGW(CurrentCanNMState_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV(CurrentCanNMState_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD03_BCM(CurrentCanNMState_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD03_SGW(CurrentCanNMState_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD04_BCM(CurrentCanNMState_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD08_SGW(CurrentCanNMState_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD11_SGW(CurrentCanNMState_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD01_BCM(CurrentFailSts_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD01_SGW(CurrentFailSts_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_BCM(CurrentFailSts_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_BSM2(CurrentFailSts_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_CADM2(CurrentFailSts_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_EPS(CurrentFailSts_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_ORC(CurrentFailSts_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_SGW(CurrentFailSts_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV(CurrentFailSts_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD03_BCM(CurrentFailSts_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD03_SGW(CurrentFailSts_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD04_BCM(CurrentFailSts_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD08_SGW(CurrentFailSts_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD11_SGW(CurrentFailSts_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD01_BCM(DES_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD01_SGW(DES_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_BCM(DES_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_BSM2(DES_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_CADM2(DES_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_EPS(DES_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_ORC(DES_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_SGW(DES_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD02_TRLR_REV(DES_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD03_BCM(DES_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD03_SGW(DES_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD04_BCM(DES_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD08_SGW(DES_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DES_FD11_SGW(DES_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_DeltaTimestamp_IMUdata(DeltaTimestamp_IMUdata data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_01(Digit_01 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_02(Digit_02 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_03(Digit_03 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_04(Digit_04 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_05(Digit_05 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_06(Digit_06 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_07(Digit_07 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_08(Digit_08 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_09(Digit_09 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_10(Digit_10 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Digit_11(Digit_11 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD01_BCM(EOL_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD01_SGW(EOL_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_BCM(EOL_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_BSM2(EOL_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_CADM2(EOL_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_EPS(EOL_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_ORC(EOL_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_SGW(EOL_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD02_TRLR_REV(EOL_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD03_BCM(EOL_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD03_SGW(EOL_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD04_BCM(EOL_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD08_SGW(EOL_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EOL_FD11_SGW(EOL_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_EPBSts(EPBSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD01_BCM(GenericFailSts_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD01_SGW(GenericFailSts_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_BCM(GenericFailSts_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_BSM2(GenericFailSts_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_CADM2(GenericFailSts_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_EPS(GenericFailSts_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_ORC(GenericFailSts_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_SGW(GenericFailSts_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV(GenericFailSts_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD03_BCM(GenericFailSts_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD03_SGW(GenericFailSts_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD04_BCM(GenericFailSts_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD08_SGW(GenericFailSts_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD11_SGW(GenericFailSts_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Heading_Angle_C2(Heading_Angle_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_IgnitionOnCounter(IgnitionOnCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHFWheelSpeed(LHFWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHF_FastPulseCounter(LHF_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHF_Spin(LHF_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHRWheelSpeed(LHRWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHR_FastPulseCounter(LHR_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LHR_Spin(LHR_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LatAccelerationOffset_BSM(LatAccelerationOffset_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LatAcceleration_C2(LatAcceleration_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Latitude_RMSE_C2(Latitude_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LongAccelerationOffset_BSM(LongAccelerationOffset_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_LongAcceleration_C2(LongAcceleration_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Longitude_RMSE_C2(Longitude_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_OperationalModeSts(OperationalModeSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PitchRate_C2(PitchRate_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Pitch_RMSE_C2(Pitch_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD01_BCM(PreviousCanNMState_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD01_SGW(PreviousCanNMState_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_BCM(PreviousCanNMState_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2(PreviousCanNMState_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2(PreviousCanNMState_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_EPS(PreviousCanNMState_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_ORC(PreviousCanNMState_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_SGW(PreviousCanNMState_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV(PreviousCanNMState_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD03_BCM(PreviousCanNMState_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD03_SGW(PreviousCanNMState_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD04_BCM(PreviousCanNMState_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD08_SGW(PreviousCanNMState_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD11_SGW(PreviousCanNMState_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_REF_VEH_SPEED(REF_VEH_SPEED data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHFWheelSpeed(RHFWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHF_FastPulseCounter(RHF_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHF_Spin(RHF_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHRWheelSpeed(RHRWheelSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHR_FastPulseCounter(RHR_FastPulseCounter data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RHR_Spin(RHR_Spin data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RemStActvSts(RemStActvSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_RollRate_C2(RollRate_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_Roll_RMSE_C2(Roll_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_SBR1RowDriverSeatSts(SBR1RowDriverSeatSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD01_BCM(FD01_BCM_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD01_SGW(FD01_SGW_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_BCM(FD02_BCM_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_BSM2(FD02_BSM2_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_CADM2(FD02_CADM2_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_EPS(FD02_EPS_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_ORC(FD02_ORC_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_SGW(FD02_SGW_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV(FD02_TRLR_REV_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD03_BCM(FD03_BCM_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD03_SGW(FD03_SGW_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD04_BCM(FD04_BCM_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD08_SGW(FD08_SGW_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD11_SGW(FD11_SGW_64 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_TRSC_CenterBtn_Sts(TRSC_CenterBtn_Sts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_TRSC_EnableBtn_Sts(TRSC_EnableBtn_Sts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_TRSC_RawKnob(TRSC_RawKnob data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_TotalOdometer(TotalOdometer data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_TurnIndicatorSts(TurnIndicatorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_VehicleStandStillSts(VehicleStandStillSts data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_VerticalAcceleration_C2(VerticalAcceleration_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_ADCM(WakeupSource_FD01_ADCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_BCM(WakeupSource_FD01_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_SGW(WakeupSource_FD01_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_BCM(WakeupSource_FD02_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_BSM2(WakeupSource_FD02_BSM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_CADM2(WakeupSource_FD02_CADM2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_EPS(WakeupSource_FD02_EPS data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_ORC(WakeupSource_FD02_ORC data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_SGW(WakeupSource_FD02_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV(WakeupSource_FD02_TRLR_REV data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD03_BCM(WakeupSource_FD03_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD03_SGW(WakeupSource_FD03_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD04_BCM(WakeupSource_FD04_BCM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD08_SGW(WakeupSource_FD08_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_WakeupSource_FD11_SGW(WakeupSource_FD11_SGW data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_YawRate_C2(YawRate_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD02Rx_YawRate_RMSE_C2(YawRate_RMSE_C2 data)
 *   Std_ReturnType Rte_Write_PpToSwcFD14Rx_FD14_Accel_Pedal_Override(FD14_Accel_Pedal_Override data)
 *   Std_ReturnType Rte_Write_PpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM(FD14_DriverReq_AxleTrq_Enabled_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed(FD14_PPPA_TrqEnblRq_Allowed data)
 *   Std_ReturnType Rte_Write_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(const ME_VehInp_to_IpcSignals_QM_t *data)
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
 *   Std_ReturnType Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCANRx_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_VCANRx_CODE) RE_VCANRx_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VCANRx_Main
 *********************************************************************************************************************/
  /* DD-ID: {F06967C3-8860-4115-9A8C-09B2C9B49E51}*/
RX_VCANProcess();
/*Feature Enable Condition Data Read*/
(void)Rte_Read_RpTRSC_ME_VehOut_TRSC_t(&ME_VehOut_TRSC_Data);

(void)Rte_Write_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(&S_VCANtoIPC_QM);
(void)Rte_Read_RpFailSafeReaction_State(&v_Failsafe_ProhibitFlag_b);

/* TRSC feature below data capture*/
(void)Rte_Read_RpToSwcSafeFD02Rx_ITBM_TrlrStat(&ITBM_TrlrStat_Data);
(void)Rte_Read_RpToSwcSafeFD02Rx_TrailerConnectionSts(&TrailerConnectionSts_Data);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_VCANRx_STOP_SEC_CODE
#include "SWC_VCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static void RX_FROMCOM_TOSWC_Process10_mSecSignal(void)
{
  /* DD-ID: {7AD561BD-0155-415b-98E3-74C907303725}*/
   D_READ_SIGNAL_FROMCOM_FD14(FD14_Accel_Pedal_Override,v_Data_u8);  // General: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_Accel_Pedal_Override,v_Data_u8);
   S_VCANtoIPC_QM.DataInp_FD14_PT_TORQUE_FD_1.FD14_Accel_Pedal_Override = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_DriverReq_AxleTrq_Enabled_BSM,v_Data_u8);  // General: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_DriverReq_AxleTrq_Enabled_BSM,v_Data_u8);
   S_VCANtoIPC_QM.DataInp_FD14_BRAKE_FD_6.FD14_DriverReq_AxleTrq_Enabled_BSM = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD14(FD14_PPPA_TrqEnblRq_Allowed,v_Data_u8);  // General: FD14 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_TrqEnblRq_Allowed,v_Data_u8);
   S_VCANtoIPC_QM.DataInp_FD14_PT_TORQUE_FD_1.FD14_PPPA_TrqEnblRq_Allowed = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(OperationalModeSts,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(OperationalModeSts,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(RemStActvSts,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(RemStActvSts,v_Data_u8);
   S_VCANtoIPC_QM.DataInp_BCM_FD_2.RemStActvSts = v_Data_u8;
   D_READ_SIGNAL_FROMCOM_FD02(TurnIndicatorSts,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TurnIndicatorSts,v_Data_u8);
   S_VCANtoIPC_QM.DataInp_BCM_FD_2.TurnIndicatorSts = v_Data_u8;
   S_VCANtoIPC_QM.DataInp_BCM_FD_21.Snow_Plow_Presence = e_ZERO;
}
static void RX_FROMCOM_TOSWC_Process20_mSecSignal(void)
{
  /* DD-ID: {AF6859E5-0C11-4704-9302-BC53E89699EF}*/
   D_READ_SIGNAL_FROMCOM_FD02(Altitude_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Altitude_RMSE_C2 = Altitude_RMSE_C2 *  D_FCT_Altitude_RMSE_C2 +  D_OFST_Altitude_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Altitude_RMSE_C2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DeltaTimestamp_IMUdata,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DeltaTimestamp_IMUdata,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(Heading_Angle_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Heading_Angle_C2 = Heading_Angle_C2 *  D_FCT_Heading_Angle_C2 +  D_OFST_Heading_Angle_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Heading_Angle_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(LatAcceleration_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  LatAcceleration_C2 = LatAcceleration_C2 *  D_FCT_LatAcceleration_C2 +  D_OFST_LatAcceleration_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(LatAcceleration_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(Latitude_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Latitude_RMSE_C2 = Latitude_RMSE_C2 *  D_FCT_Latitude_RMSE_C2 +  D_OFST_Latitude_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Latitude_RMSE_C2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(LongAcceleration_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  LongAcceleration_C2 = LongAcceleration_C2 *  D_FCT_LongAcceleration_C2 +  D_OFST_LongAcceleration_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(LongAcceleration_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(Longitude_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Longitude_RMSE_C2 = Longitude_RMSE_C2 *  D_FCT_Longitude_RMSE_C2 +  D_OFST_Longitude_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Longitude_RMSE_C2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(Pitch_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Pitch_RMSE_C2 = Pitch_RMSE_C2 *  D_FCT_Pitch_RMSE_C2 +  D_OFST_Pitch_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Pitch_RMSE_C2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PitchRate_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  PitchRate_C2 = PitchRate_C2 *  D_FCT_PitchRate_C2 +  D_OFST_PitchRate_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(PitchRate_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(Roll_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Roll_RMSE_C2 = Roll_RMSE_C2 *  D_FCT_Roll_RMSE_C2 +  D_OFST_Roll_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Roll_RMSE_C2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(RollRate_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  RollRate_C2 = RollRate_C2 *  D_FCT_RollRate_C2 +  D_OFST_RollRate_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(RollRate_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(VerticalAcceleration_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  VerticalAcceleration_C2 = VerticalAcceleration_C2 *  D_FCT_VerticalAcceleration_C2 +  D_OFST_VerticalAcceleration_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(VerticalAcceleration_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(YawRate_C2,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  YawRate_C2 = YawRate_C2 *  D_FCT_YawRate_C2 +  D_OFST_YawRate_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(YawRate_C2,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(YawRate_RMSE_C2,v_Data_u8);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  YawRate_RMSE_C2 = YawRate_RMSE_C2 *  D_FCT_YawRate_RMSE_C2 +  D_OFST_YawRate_RMSE_C2 ;
   D_WRITE_SIGNAL_TOSWC_FD02(YawRate_RMSE_C2,v_Data_u8);
}
static void RX_FROMCOM_TOSWC_Process40_mSecSignal(void)
{
	/* DD-ID:{4F6EBB9E-B08D-4492-AE3C-B4C41FFACDD5}*/
   // VT: D_READ_SIGNAL_FROMCOM_FD14_ARRAY(FD14_RawPntDebugSignal,v_Data_a8_au8);  // General: FD14 Not Common READ
   // VT: D_WRITE_SIGNAL_TOSWC_FD14_ARRAY(FD14_RawPntDebugSignal,v_Data_a8_au8);
   // VT: D_READ_SIGNAL_FROMCOM_FD14(FD14_UssParkingModeSignal,v_Data_u8);  // General: FD14 Not Common READ
   // VT: D_WRITE_SIGNAL_TOSWC_FD14(FD14_UssParkingModeSignal,v_Data_u8);
}
static void RX_FROMCOM_TOSWC_Process50_mSecSignal(void)
{
  /* DD-ID: {8F506135-C0BF-418f-BF9D-F48EC682ACD5}*/
   D_READ_SIGNAL_FROMCOM_FD02(Battery_Volt_1,v_Data_u16);  // General: FD2 Not Common READ
   // VT: FACT+OFFST :  Battery_Volt_1 = Battery_Volt_1 *  D_FCT_Battery_Volt_1 +  D_OFST_Battery_Volt_1 ;
   D_WRITE_SIGNAL_TOSWC_FD02(Battery_Volt_1,v_Data_u16);
}
static void RX_FROMCOM_TOSWC_Process1000_mSecSignal(void)
{
  /* DD-ID: {D7EC1F84-73DA-45a4-BB47-7A1ABF78F4F4}*/
   static uint32 v_Data_u32;
   static uint8 v_Data_a8_au8[e_EIGHT];
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentCanNMState_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentCanNMState_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(CurrentFailSts_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(CurrentFailSts_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(DES_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(DES_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(EOL_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(EOL_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(GenericFailSts_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(GenericFailSts_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(IgnitionOnCounter,v_Data_u16);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(IgnitionOnCounter,v_Data_u16);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(PreviousCanNMState_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(PreviousCanNMState_FD11_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD01_BCM,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD01_BCM,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD01_SGW,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD01_SGW,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_BCM,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_BCM,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_BSM2,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_BSM2,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_CADM2,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_CADM2,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_EPS,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_EPS,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_ORC,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_ORC,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_SGW,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_SGW,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD02_TRLR_REV,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD02_TRLR_REV,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD03_BCM,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD03_BCM,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD03_SGW,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD03_SGW,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD04_BCM,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD04_BCM,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD08_SGW,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD08_SGW,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02_ARRAY(StayActiveSource_FD11_SGW,v_Data_a8_au8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02_ARRAY(StayActiveSource_FD11_SGW,v_Data_a8_au8);
   D_READ_SIGNAL_FROMCOM_FD02(TotalOdometer,v_Data_u32);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(TotalOdometer,v_Data_u32);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD01_ADCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD01_ADCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD01_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD01_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD01_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD01_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_BSM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_BSM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_CADM2,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_CADM2,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_EPS,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_EPS,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_ORC,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_ORC,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD02_TRLR_REV,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD02_TRLR_REV,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD03_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD03_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD03_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD03_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD04_BCM,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD04_BCM,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD08_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD08_SGW,v_Data_u8);
   D_READ_SIGNAL_FROMCOM_FD02(WakeupSource_FD11_SGW,v_Data_u8);  // General: FD2 Not Common READ
   D_WRITE_SIGNAL_TOSWC_FD02(WakeupSource_FD11_SGW,v_Data_u8);
}

static void RX_VCAN_EVENT_RX_FROMCOM_TOSWC(void)
{
  /* DD-ID: {A623E5AD-D17C-4ef1-8DF7-E2A2F1630362}*/
   if(Rte_IsUpdated_RpFromComFD02Rx_SBR1RowDriverSeatSts())
   {
      D_READ_SIGNAL_FROMCOM_FD02(SBR1RowDriverSeatSts,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(SBR1RowDriverSeatSts,v_Data_u8);
      f_DTC_Flag_ORC_FD_1_SBR1RowDriverSeatSts(v_Data_u8);
      S_VCANtoIPC_QM.DataInp_ORC_FD_1.SBR1RowDriverSeatSts = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComFD02Rx_TRSC_CenterBtn_Sts())
   {
      D_READ_SIGNAL_FROMCOM_FD02(TRSC_CenterBtn_Sts,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(TRSC_CenterBtn_Sts,v_Data_u8);
      f_DTC_TRSKM_flag_set_TRSC_CenterBtn_Sts(v_Data_u8);
      S_VCANtoIPC_QM.DataInp_TRSKM_FD_1.TRSC_CenterBtn_Sts = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComFD02Rx_TRSC_EnableBtn_Sts())
   {
      D_READ_SIGNAL_FROMCOM_FD02(TRSC_EnableBtn_Sts,v_Data_u8);  // General: FD2 Not Common READ
      D_WRITE_SIGNAL_TOSWC_FD02(TRSC_EnableBtn_Sts,v_Data_u8);
      f_DTC_TRSKM_flag_set_TRSC_EnableBtn_Sts(v_Data_u8);
      S_VCANtoIPC_QM.DataInp_TRSKM_FD_1.TRSC_EnableBtn_Sts = v_Data_u8;
   }
   else
   {
      /*Do nothing*/
   }
   if(Rte_IsUpdated_RpFromComFD02Rx_TRSC_RawKnob())
   {
      D_READ_SIGNAL_FROMCOM_FD02(TRSC_RawKnob,v_Data_u16);  /* General: FD2 Not Common READ */
      D_WRITE_SIGNAL_TOSWC_FD02(TRSC_RawKnob,v_Data_u16);
      f_DTC_TRSKM_flag_set_TRSC_RawKnob(v_Data_u16);
      S_VCANtoIPC_QM.DataInp_TRSKM_FD_1.TRSC_RawKnob = v_Data_u16;
   }
   else
   {
      /*Do nothing*/
   }
}

static void RX_VCANProcess(void)
{
static EventDataManage_t RX_VCAN_EventDataManage[E_RX_Last_EventIndex] =
{
    /*EventID		                               isTriggered_b		EventType_u8		               CounterValue_u32		  PeriodicityTypes_u32		FuncPtrWrite*/
  { E_RX_FROMCOM_TOSWC_Process10_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  10,                     &RX_FROMCOM_TOSWC_Process10_mSecSignal },
  { E_RX_FROMCOM_TOSWC_Process20_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  20,                     &RX_FROMCOM_TOSWC_Process20_mSecSignal },
  { E_RX_FROMCOM_TOSWC_Process40_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  40,                     &RX_FROMCOM_TOSWC_Process40_mSecSignal },
  { E_RX_FROMCOM_TOSWC_Process50_mSecSignal,    0U,              D_TIME_TRIGGERED_EVENT,       0U,                  50,                     &RX_FROMCOM_TOSWC_Process50_mSecSignal },
  { E_RX_FROMCOM_TOSWC_Process1000_mSecSignal,  0U,              D_TIME_TRIGGERED_EVENT,       0U,                  1000,                   &RX_FROMCOM_TOSWC_Process1000_mSecSignal },
  { E_RX_EVENT_RX_FROMCOM_TOSWC,                   0U,              D_EXTERNAL_TRIGGERED_EVENT,   0U,                  0U,                     &RX_VCAN_EVENT_RX_FROMCOM_TOSWC },

};

  /* DD-ID: {D88E831F-04B0-4df4-A392-360DD144555F}*/
  uint8 reqItemIndex;
  for (reqItemIndex = (uint8)E_RX_FROMCOM_TOSWC_Process10_mSecSignal; reqItemIndex < (uint8)E_RX_Last_EventIndex; reqItemIndex++)
  {
    if(RX_VCAN_EventDataManage[reqItemIndex].EventType_u8 == D_TIME_TRIGGERED_EVENT)
    {
          RX_VCAN_EventDataManage[reqItemIndex].CounterValue_u32+=TASKREPRATE;
          if(RX_VCAN_EventDataManage[reqItemIndex].CounterValue_u32 >= RX_VCAN_EventDataManage[reqItemIndex].PeriodicityTypes_u32)
          {
              RX_VCAN_EventDataManage[reqItemIndex].CounterValue_u32 = TASKREPRATE;
              RX_VCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ONE;
          }
    }
    else if(RX_VCAN_EventDataManage[reqItemIndex].EventType_u8 == D_EXTERNAL_TRIGGERED_EVENT)
    {
      RX_VCAN_EventDataManage[reqItemIndex].FuncPtrWrite();
    }
    else
    {
        /*Do Nothing*/
    }
  }

    for (reqItemIndex = 0; reqItemIndex < (uint8)E_RX_Last_EventIndex; reqItemIndex++)
  {
        if(RX_VCAN_EventDataManage[reqItemIndex].isTriggered_b == (uint8)e_ONE)
      {
          RX_VCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ZERO;
          RX_VCAN_EventDataManage[reqItemIndex].FuncPtrWrite();

      }
  }
}

FUNC(void, CANSM_APPL_CODE)Appl_BusOffBegin(NetworkHandleType NetworkHandle, P2VAR(uint8, AUTOMATIC, CANSM_APPL_VAR) OnlineDelayCyclesPtr)
{
/* DD-ID:{6EADE82D-2981-453f-A99D-21B9C25631BC}*/
    (void)OnlineDelayCyclesPtr;
	if(NetworkHandle == (uint8)e_ZERO)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Vehicle_CanBusoff_CAN14, ErrorMgr_ErrorActive, NULL_PTR);
    }
    else if(NetworkHandle == (uint8)e_ONE)
    {
        (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Vehicle_CanBusoff_CAN2, ErrorMgr_ErrorActive, NULL_PTR);
    }
    else
    {
        /*do nothing*/
    }
}

FUNC(void, CANSM_APPL_CODE)Appl_BusOffEnd(NetworkHandleType NetworkHandle)
{

	/* DD-ID:{4A3E48CC-B8D1-402a-A4B9-A1596E365568}*/
	 static uint8 V_BusOffIndicationFlag_u8;

    /*GUID:-*/
    if(NetworkHandle == (uint8)e_ZERO)
    {
       (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Vehicle_CanBusoff_CAN14, ErrorMgr_ErrorInactive, NULL_PTR);
    }
    else if(NetworkHandle == (uint8)e_ONE)
    {
         (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Vehicle_CanBusoff_CAN2, ErrorMgr_ErrorInactive, NULL_PTR);
         V_BusOffIndicationFlag_u8  = TRUE;
         (void)Rte_Write_PpBusOffIndication_V_BusOffIndicationFlagRte_u8(V_BusOffIndicationFlag_u8);
    }
    else
    {
        /*do nothing*/
    }
}

static void f_DTC_TRSKM_flag_set_TRSC_RawKnob(TRSC_RawKnob lv_Data_u16)
{
  /* DD-ID: {8B93DE29-693E-488a-8C41-C8EB11ACA6AD}*/
    static uint8 v_Set_TRSC_RawKnob_u8 = (uint8)e_ZERO;
    static uint8 s_flag_set_TRSC_RawKnob_u8 = (uint8)e_ZERO;
    
    if ((TRSC_RAWKNOB_LOWRANGE <= lv_Data_u16) && (lv_Data_u16 <= TRSC_RAWKNOB_HIGHRANGE))
    {
        if (TRSC_FEATURE)
        {
            if (v_Set_TRSC_RawKnob_u8 >= (uint8_t)e_THREE)
            {
                if(s_flag_set_TRSC_RawKnob_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_RawKnob_OOR_Fault, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_set_TRSC_RawKnob_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TRSC_RawKnob_u8++;
            }
        }
        else
        {
            v_Set_TRSC_RawKnob_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TRSC_RawKnob_u8 = (uint8)e_ZERO;
        if(s_flag_set_TRSC_RawKnob_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_RawKnob_OOR_Fault, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_set_TRSC_RawKnob_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_TRSKM_flag_set_TRSC_EnableBtn_Sts(TRSC_EnableBtn_Sts lv_Data_u8)
{
  /* DD-ID: {AC535226-9BB7-427c-A31E-E6DD721F7747}*/
    static uint8 v_Set_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
    static uint8 s_flag_set_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
    if((uint8)TRSC_ENABLEBTN_STS_SNA == lv_Data_u8)
    {
        if(TRSC_FEATURE)
        {
            if (v_Set_TRSC_EnableBtn_Sts_u8 >= (uint8_t)e_THREE)
            {
                if(s_flag_set_TRSC_EnableBtn_Sts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_EnableBtn_Sts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_set_TRSC_EnableBtn_Sts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TRSC_EnableBtn_Sts_u8++;
            }
        }
        else
        {
            v_Set_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TRSC_EnableBtn_Sts_u8 = (uint8)e_ZERO;
        if(s_flag_set_TRSC_EnableBtn_Sts_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_EnableBtn_Sts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_set_TRSC_EnableBtn_Sts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_TRSKM_flag_set_TRSC_CenterBtn_Sts(TRSC_CenterBtn_Sts lv_Data_u8)
{
  /* DD-ID: {1DC80ABA-20A2-4103-9C99-55D7F27E1C3C}*/
    static uint8 v_Set_TRSC_CenterBtn_Sts_u8 = (uint8)e_ZERO;
    static uint8 s_flag_set_TRSC_CenterBtn_Sts_u8 = (uint8)e_ZERO;

    if((uint8)TRSC_CENTERBTN_STS_SNA == lv_Data_u8)
    {
        if(TRSC_FEATURE)
        {
            if (v_Set_TRSC_CenterBtn_Sts_u8 >= (uint8_t)e_THREE)
            {
                if(s_flag_set_TRSC_CenterBtn_Sts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_CenterBtn_Sts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_set_TRSC_CenterBtn_Sts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_TRSC_CenterBtn_Sts_u8++;
            }
        }
        else
        {
            v_Set_TRSC_CenterBtn_Sts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_TRSC_CenterBtn_Sts_u8 = (uint8)e_ZERO;
        if(s_flag_set_TRSC_CenterBtn_Sts_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_TRSC_CenterBtn_Sts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_set_TRSC_CenterBtn_Sts_u8 = (uint8)e_TWO;
        }
    }
}

static void f_DTC_Flag_ORC_FD_1_SBR1RowDriverSeatSts(SBR1RowDriverSeatSts lv_Data_u8)
{
  /* DD-ID: {5F2F8778-0A2F-4dd9-997E-9AAE103EE754}*/
    static uint8 v_Set_SBR1RowDriverSeatSts_u8 = (uint8)e_ZERO;
    static uint8 s_flag_ORC_FD_1_SBR1RowDriverSeatSts_u8 = (uint8)e_ZERO;

    if((uint8)SBR1ROWDRIVERS_SEATSTS_SNA == lv_Data_u8)
    {
        if(TRSC_FEATURE)
        {
            if (v_Set_SBR1RowDriverSeatSts_u8 >= (uint8_t)e_TEN)
            {
                if(s_flag_ORC_FD_1_SBR1RowDriverSeatSts_u8 != (uint8)e_ONE)
                {
                    (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_SBR1RowDriverSeatSts_Invld, ErrorMgr_ErrorActive, NULL_PTR);
                    s_flag_ORC_FD_1_SBR1RowDriverSeatSts_u8 = (uint8)e_ONE;
                }
            }
            else
            {
                v_Set_SBR1RowDriverSeatSts_u8++;
            }
        }
        else
        {
            v_Set_SBR1RowDriverSeatSts_u8 = (uint8)e_ZERO;
        }
    }
    else
    {
        v_Set_SBR1RowDriverSeatSts_u8 = (uint8)e_ZERO;
        if(s_flag_ORC_FD_1_SBR1RowDriverSeatSts_u8 != (uint8)e_TWO)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_SBR1RowDriverSeatSts_Invld, ErrorMgr_ErrorInactive, NULL_PTR);
            s_flag_ORC_FD_1_SBR1RowDriverSeatSts_u8 = (uint8)e_TWO;
        }
    }
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_GLOB_NAV_FD_C2_oFDCAN2_098ddc16_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    /* DD-ID: {2109B902-6F88-4ef6-8F1C-E7B38EC99879}*/

    static E2E_MEP_CheckStateType s_E2E_State_Read_FD2_GLOB_NAV_FD;
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    (void)PduId;

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    s_E2E_State_Read_FD2_GLOB_NAV_FD.NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read_FD2_GLOB_NAV_FD, PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read_FD2_GLOB_NAV_FD.Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read_FD2_GLOB_NAV_FD.Status)))
    {
        v_retVal_b = TRUE;
    }
    else
    {
        v_retVal_b = TRUE;
    }

    return v_retVal_b;

}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRSKM_FD_1_oFDCAN2_2705233d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    /* DD-ID: {6E6675EE-FC78-4463-9AAA-0646722FBD0F}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_TRSKM_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;

    if (s_TRSC_CenterBtn_Sts_MM_u8 != (uint8)e_TWO)
    {
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MissingMessage_TRSKM_FD_1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_TRSC_CenterBtn_Sts_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength < D_DLC_TRSKM_FD_1) 
    {
        if(TRSC_FEATURE)
        {
            if(s_TRSKM_FD_1_DLC_u8 != e_ONE)
            {
                (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_DLC_Fault_TRSKM_FD_1, ErrorMgr_ErrorActive, NULL_PTR);
                s_TRSKM_FD_1_DLC_u8 = e_ONE;
            }
        }
    }
    else 
    {
		if((uint8)e_TWO != s_TRSKM_FD_1_DLC_u8)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_DLC_Fault_TRSKM_FD_1, ErrorMgr_ErrorInactive, NULL_PTR);
            s_TRSKM_FD_1_DLC_u8 = e_TWO;
        }
    }
   

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_TRSKM_FD_1_ID].NewDataAvailable = TRUE;

    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_TRSKM_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_TRSKM_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_TRSKM_FD_1_ID].Status)))
    {
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_CRC_Fault_TRSKM, ErrorMgr_ErrorInactive, NULL_PTR);
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MC_Fault_TRSKM, ErrorMgr_ErrorInactive, NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_TRSKM_FD_1_ID].Status)
    {
        if (TRSC_FEATURE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_CRC_Fault_TRSKM, ErrorMgr_ErrorActive, NULL_PTR);
        }
        v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_TRSKM_FD_1_ID].Status) || (E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_TRSKM_FD_1_ID].Status))
    {
        if (TRSC_FEATURE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MC_Fault_TRSKM, ErrorMgr_ErrorActive, NULL_PTR);
        }
        v_retVal_b = TRUE;
    }
    else
    {
        /*DO Nothing*/
    }

    return v_retVal_b;
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ORC_FD_1_oFDCAN2_f51fa5a1_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    /* DD-ID:{B95FC398-06BD-4d0e-A4C0-8C46E213B056}*/
    Std_ReturnType v_checkRetVal_u8;
    boolean v_retVal_b = FALSE;
    static uint8 s_ORC_FD_1_DLC_u8 = (uint8)e_ZERO;
    (void)PduId;

    if (s_SBR1RowDriverSeatSts_MM_u8 != (uint8)e_TWO)
    {
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MissingMessage_ORC_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
        s_SBR1RowDriverSeatSts_MM_u8 = (uint8)e_TWO;
    }
    if(PduInfoPtr->SduLength<D_DLC_ORC_FD_1) 
      {
        if(TRSC_FEATURE)
        {
            if(s_ORC_FD_1_DLC_u8 != (uint8)e_ONE)
            {
                (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_DLC_Fault_ORC_FD1, ErrorMgr_ErrorActive, NULL_PTR);
                s_ORC_FD_1_DLC_u8 = (uint8)e_ONE;
            }
        }
      }
      else 
      {
    	if((uint8)e_TWO != s_ORC_FD_1_DLC_u8)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_DLC_Fault_ORC_FD1, ErrorMgr_ErrorInactive, NULL_PTR);
            s_ORC_FD_1_DLC_u8 = (uint8)e_TWO;
        }
      }

    S_ConfigType_FD2_Read.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
    S_ConfigType_FD2_Read.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

    s_E2E_State_Read[FD2_ORC_FD_1_ID].NewDataAvailable = TRUE;
    v_checkRetVal_u8 = Rte_Call_RpE2EServices_ME_E2E_Check(&S_ConfigType_FD2_Read, &s_E2E_State_Read[FD2_ORC_FD_1_ID], PduInfoPtr->SduDataPtr);
    if ((E_OK == v_checkRetVal_u8) && ((E2E_MEP_STATUS_OK == s_E2E_State_Read[FD2_ORC_FD_1_ID].Status) || (E2E_MEP_STATUS_OKSOMELOST == s_E2E_State_Read[FD2_ORC_FD_1_ID].Status)))
    {
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_CRC_Fault_ORC, ErrorMgr_ErrorInactive, NULL_PTR);
        (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MC_Fault_ORC, ErrorMgr_ErrorInactive, NULL_PTR);
        v_retVal_b = TRUE;
    }
    else if (E2E_MEP_STATUS_WRONGCRC == s_E2E_State_Read[FD2_ORC_FD_1_ID].Status)
    {
        if (TRSC_FEATURE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_CRC_Fault_ORC, ErrorMgr_ErrorActive, NULL_PTR);
        }
        v_retVal_b = TRUE;
    }
    else if ((E2E_MEP_STATUS_WRONGSEQUENCE == s_E2E_State_Read[FD2_ORC_FD_1_ID].Status)||(E2E_MEP_STATUS_REPEATED == s_E2E_State_Read[FD2_ORC_FD_1_ID].Status))
    {
        if (TRSC_FEATURE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MC_Fault_ORC, ErrorMgr_ErrorActive, NULL_PTR);
        }
        v_retVal_b = TRUE;
    }
    else
    {
        /*DO Nothing*/
    }

    return v_retVal_b;
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx(void)
{
    /* DD-ID:{C12C6375-F590-49cf-9262-9CC2D6C8F1D6}*/
    if ((TRSC_FEATURE) && (v_Failsafe_ProhibitFlag_b == FALSE))
    {
        if(s_SBR1RowDriverSeatSts_MM_u8 != (uint8)e_ONE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MissingMessage_ORC_FD1, ErrorMgr_ErrorActive, NULL_PTR);
        s_SBR1RowDriverSeatSts_MM_u8 = (uint8)e_ONE;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    s_E2E_State_Read[FD2_ORC_FD_1_ID].WaitForFirstData = TRUE;
}

FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx(void)
{
    /* DD-ID:{421DFCB9-81CE-43c0-9BE4-648550F0ECBD}*/
    if ((TRSC_FEATURE) && (v_Failsafe_ProhibitFlag_b == FALSE))
    {
        if(s_TRSC_CenterBtn_Sts_MM_u8 != (uint8)e_ONE)
        {
            (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_MissingMessage_TRSKM_FD_1, ErrorMgr_ErrorActive, NULL_PTR);
        s_TRSC_CenterBtn_Sts_MM_u8 = (uint8)e_ONE;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    s_E2E_State_Read[FD2_TRSKM_FD_1_ID].WaitForFirstData = TRUE;
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
