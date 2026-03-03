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
 *             File:  CDD_GenericBswM.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CDD_GenericBswM
 *  Generation Time:  2025-04-08 15:09:51
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CDD_GenericBswM>
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
 * BswM_BswM_PreviousNMState
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * BswM_ESH_RunRequest
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
 * ComM_ModeType
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
 * Dcm_SesCtrlType
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
 * Dem_EventIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * MRM_STATUS_C2
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
 * THA_Speed_Limit
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * TRSC_PopupDisp_Info
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TRSC_PopupDisp_Info2
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
 * VehicleStandStillSts
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
 * udtBatteryVoltageStatus
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CDD_GenericBswM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Can_30_Mcan.h"
#include  "NM_Callout_Stubs.h"
#include "Os.h"
#include "vstdlib.h"
#include "CanIf.h"
#include "vstdlib.h"
#include "Dem_Dcm.h"
#include "Enums.h"
//#include "CDD_PMIC.h"

#include "ErrorManagerAggregatorDef.h"
#include "NvM.h"

#include <ti/csl/cslr.h>
#include <ti/csl/soc.h>
#include <ti/csl/src/ip/vtm/V1/csl_vtm.h>
#include "app_log.h"
#include "app_log_Boot.h"


#define NUM_TEMP_SENSORS            5U
#define TEMPERATUREOFFSET           40U

#define DEVICEID_EXTWDG             0x0
#define WD_MODE_REG                 0x406
#define WD_MODE_RETURN_LON_WINDOW   0x01

#define IGN_SIGNAL_MSG_ID          (0x40000481U)

#define NM_MSG_LOWER_ID            (0x1E384000)
#define NM_MSG_HIGHER_ID           (0x1E3840FF)

#define VCAN_FD2_CONTROLLER		   (0x0U)
#define ODOMETER_SCALING_FACTOR    (uint16)16u
#define CMD_INGNITION_DATABYTE     (0x11u)
#define MAX_STACK_SIZE              0xFFFFU
#define HIGHER_NIBBLE_MASK          0xFF00U
#define LOWER_NIBBLE_MASK           0x00FFU


#define D_NMSTATE_UNINIT        			(0x00u)
#define D_NMSTATE_BUS_SLEEP     			(0x01u)
#define D_NMSTATE_PREPARE_BUS_SLEEP     	(0x02u)
#define D_NMSTATE_READY_SLEEP               (0x03u)
#define D_NMSTATE_NORMAL_OPERATION          (0x04u)
#define D_NMSTATE_REPEAT_MESSAGE            (0x05u)
#define D_NMSTATE_SYNCHRONIZE               (0x06u)
#define D_NMSTATE_OFFLINE                   (0x07u)
#define D_NMSTATE_CHECK_WAKEUP              (0x08u)
#define D_NMSTATE_WAIT_STARTUP              (0x09u)

#define D_WAKEUP_REASON                     (0x82u)

#define D_STAYACTIVE_REASON_ARRAY_SIZE      (0x08U)
#define D_SWC_BASE_BLOCKID                  (0x0DU)

static void f_SysMgr_MonitorExternalRequest(void);
static void f_UpdateMessage_PDC_INFO_FD_PAM(void);

#define NUM_OFSOCDIEID 4u
/*DET is to be disabled for SW Test Team Release*/
//# define  DET_ENDLESSLOOP_ENABLED  
/* Max number of Det errors can be captured  */
#define DETERROR_STORE_CNT  5U
#define ONE_HUNDRED_FOURTY_MS   14u

typedef enum 
{
    e_CmdIgnition_Initialization = 0u,
    e_CmdIgnition_IGN_LK = 1,
    e_CmdIgnition_ACC = 3,
    e_CmdIgnition_RUN = 4,
    e_CmdIgnition_START = 5,
	e_CmdIgnition_SNA = 7,
}IgnitionSignalEnum;

/*If defined then it will store last 5 DET, if not defined then code will go into endless loop*/
typedef struct aDet_s_DetErrorCount_s
{
    uint8 u8InstanceId;
    uint8 u8ApiId;
    uint8 u8ErrorId;
    uint16 u16ModuleId;
} aDet_s_DetErrorCount_t;


volatile boolean V_canWUp_Val_validWakeup_b = FALSE;
volatile boolean V_canWUp_Val_enableWakeupValidation_b = FALSE;

/* Get SOC DIE Ids */
static uint8 V_System_State_u8 = FALSE;
static CurrentCanNMState_FD02_PAM  V_NMState_u8  = FALSE;

/*Store CAN Overrun counter per controller*/
volatile static uint8 s_CANOverrunCnt_a8[e_TWO];

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
 * BswM_BswM_PreviousNMState: Integer in interval [0...255]
 * BswM_ESH_RunRequest: Integer in interval [0...255]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CameraDisplaySts2: Integer in interval [0...15]
 * ChangeSYSState_t: Integer in interval [0...65535]
 * CmdIgnSts: Integer in interval [0...7]
 * ComM_ModeType: Integer in interval [0...3]
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
 * Dcm_SesCtrlType: Integer in interval [0...3]
 * DeltaTimestamp_IMUdata: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_UdsStatusByteType: Integer in interval [0...255]
 * DeviceAddress: Integer in interval [0...255]
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
 * MRM_STATUS_C2: Integer in interval [0...7]
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
 * PreviousCanNMState_FD02_PAM: Integer in interval [0...15]
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
 * RemStActvSts: Integer in interval [0...1]
 * Rte_DT_StayActiveSource_FD02_PAM_0: Integer in interval [0...4]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SVC_Guidelines: Integer in interval [0...1]
 * ShiftLeverPosition: Integer in interval [0...15]
 * ShiftLeverPositionReq: Integer in interval [0...15]
 * Shifter_ADAS_Inhibit: Integer in interval [0...1]
 * SystemState: Integer in interval [0...255]
 * TCASERANGESTATUS: Integer in interval [0...3]
 * TGW_CAMERA_DISP_STAT: Integer in interval [0...15]
 * THA_EPB_Req: Integer in interval [0...3]
 * THA_STAT: Integer in interval [0...7]
 * THA_SpeedLimit_Req: Integer in interval [0...3]
 * THA_Speed_Limit: Integer in interval [0...31]
 * THA_SteeringTorqueReq: Integer in interval [0...3]
 * THA_SteeringTouchStat: Integer in interval [0...3]
 * TRANS_ADAS_Inhibit: Integer in interval [0...1]
 * TRSCMoreCamRQSts: Integer in interval [0...1]
 * TRSC_CenterBtn_Sts: Integer in interval [0...3]
 * TRSC_EnableBtn_Sts: Integer in interval [0...3]
 * TRSC_PopupDisp_Info: Integer in interval [0...15]
 * TRSC_PopupDisp_Info2: Integer in interval [0...63]
 * TRSC_RawKnob: Integer in interval [0...511]
 * TRSC_STAT: Integer in interval [0...7]
 * TRSC_SpeedLimit_Req: Integer in interval [0...15]
 * TRSC_SteeringTorqueReq: Integer in interval [0...3]
 * TRSC_VehicleStop_Req: Integer in interval [0...3]
 * TargetGear: Integer in interval [0...15]
 * TotalOdometer: Integer in interval [0...1048575]
 * TrailerConnectionSts: Integer in interval [0...3]
 * Trailer_Angle: Integer in interval [0...255]
 * Trailer_Angle_Sign: Integer in interval [0...3]
 * Trailer_Calibration: Integer in interval [0...2]
 * TransmissionSailingSts: Integer in interval [0...15]
 * TrlrHitchLight_Cntrl: Integer in interval [0...3]
 * TurnIndicatorSts: Integer in interval [0...3]
 * VIN_MSG: Integer in interval [0...3]
 * VehicleStandStillSts: Integer in interval [0...3]
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
 * boolean: Boolean (standard type)
 * udtBatteryVoltageStatus: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * N_PDU: Array with 8 element(s) of type uint8
 * StayActiveSource_FD02_PAM: Array with 8 element(s) of type Rte_DT_StayActiveSource_FD02_PAM_0
 * VIN_DATA: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 *
 *********************************************************************************************************************/


#define CDD_GenericBswM_START_SEC_CODE
#include "CDD_GenericBswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_GenBswSysMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   ChangeSYSState_t Rte_IrvRead_RE_GenBswSysMgr_Init_Irv_ChangeSYSStateReq(void)
 *   uint16 Rte_IrvRead_RE_GenBswSysMgr_Init_Irv_PreviousNMState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_RE_GenBswSysMgr_Init_Irv_ChangeSYSStateReq(ChangeSYSState_t data)
 *   void Rte_IrvWrite_RE_GenBswSysMgr_Init_Irv_PreviousNMState(uint16 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenBswSysMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_GenericBswM_CODE) RE_GenBswSysMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenBswSysMgr_Init
 *********************************************************************************************************************/
 /*GUID: DD-ID: {7EC8D56B-4B7B-4cd5-AC0B-49B0433FDF91}*/
   (void)Rte_Write_PpBSWM_PostRunRequest_0_requestedMode(REQUESTED);
   (void)Rte_Write_PpBSWM_PostRunRequest_1_requestedMode(REQUESTED);
   (void)Rte_Write_PpBSWM_RunRequest_0_requestedMode(REQUESTED);
   (void)Rte_Write_PpBSWM_RunRequest_1_requestedMode(REQUESTED);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_GenBswSysMgr_Main
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
 *   Std_ReturnType Rte_Read_RpProxiReset_ProxiDataflag_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpSleepProcessState_status(uint8 *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(CmdIgnSts *data)
 *   Std_ReturnType Rte_Read_RpVoltageChannelStatus_BatteryVoltageStatus(udtBatteryVoltageStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpBSWM_PostRunRequest_0_requestedMode(BswM_ESH_RunRequest data)
 *   Std_ReturnType Rte_Write_PpBSWM_PostRunRequest_1_requestedMode(BswM_ESH_RunRequest data)
 *   Std_ReturnType Rte_Write_PpBSWM_RunRequest_0_requestedMode(BswM_ESH_RunRequest data)
 *   Std_ReturnType Rte_Write_PpBSWM_RunRequest_1_requestedMode(BswM_ESH_RunRequest data)
 *   Std_ReturnType Rte_Write_PpBswM_PreviousNMState_requestedMode(BswM_BswM_PreviousNMState data)
 *   Std_ReturnType Rte_Write_PpGetFirstDTCStatus_DeFirstDTCStatus(boolean data)
 *   Std_ReturnType Rte_Write_PpNmStateInfo_v_IsNmStateNormal_b(boolean data)
 *   Std_ReturnType Rte_Write_PpSystemStateManager_SysM_State(SystemState data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_CurrentCanNMState_FD02_PAM(CurrentCanNMState_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_CurrentFailSts_FD02_PAM(CurrentFailSts_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_DES_FD02_PAM(DES_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_GenericFailSts_FD02_PAM(GenericFailSts_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_PreviousCanNMState_FD02_PAM(PreviousCanNMState_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_StayActiveSource_FD02_PAM(const Rte_DT_StayActiveSource_FD02_PAM_0 *data)
 *     Argument data: Rte_DT_StayActiveSource_FD02_PAM_0* is of type StayActiveSource_FD02_PAM
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_WakeupSource_FD02_PAM(WakeupSource_FD02_PAM data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_PpDiagRequestNtfy_SYSModeRequestType(uint8 mode)
 *   Modes of Rte_ModeType_SYSModeRequestType:
 *   - RTE_MODE_SYSModeRequestType_SYS_REQ_HARDRESET
 *   - RTE_MODE_SYSModeRequestType_SYS_REQ_INIT
 *   - RTE_MODE_SYSModeRequestType_SYS_REQ_INVALID
 *   - RTE_MODE_SYSModeRequestType_SYS_REQ_JUMPTOBOOT
 *   - RTE_TRANSITION_SYSModeRequestType
 *   uint8 Rte_Mode_RpNM_State_Mode(void)
 *   Modes of Rte_ModeType_NM_State:
 *   - RTE_MODE_NM_State_NM_STATE_BUS_SLEEP
 *   - RTE_MODE_NM_State_NM_STATE_NORMAL
 *   - RTE_MODE_NM_State_NM_STATE_PREPARE_SLEEP
 *   - RTE_MODE_NM_State_NM_STATE_READY_SLEEP
 *   - RTE_MODE_NM_State_NM_STATE_REPEAT
 *   - RTE_MODE_NM_State_NM_UINIT
 *   - RTE_TRANSITION_NM_State
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   ChangeSYSState_t Rte_IrvRead_RE_GenBswSysMgr_Main_Irv_ChangeSYSStateReq(void)
 *   uint16 Rte_IrvRead_RE_GenBswSysMgr_Main_Irv_PreviousNMState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_RE_GenBswSysMgr_Main_Irv_ChangeSYSStateReq(ChangeSYSState_t data)
 *   void Rte_IrvWrite_RE_GenBswSysMgr_Main_Irv_PreviousNMState(uint16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpError_CS_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceRegData(DeviceAddress DeviceAdd, uint16 *RegAddress)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpMCUDeviceRegReadWrite_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK, RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus(Dem_EventIdType EventId, Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpComM_UserRequest_FDCAN14_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpComM_UserRequest_FDCAN2_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpDCMServices_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenBswSysMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_GenericBswM_CODE) RE_GenBswSysMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenBswSysMgr_Main
 *********************************************************************************************************************/
 /*ReqID:- 16305628, 16305647,16305656,16303358,16303361,16303363,16303355 
    DD-ID: {4BEEAE74-7607-478c-96CD-A015D2780B31}*/

    uint32 v_udsDTC_u32;
    Dem_UdsStatusByteType v_DTCStatus_u8;
    static uint8_t s_EventId_u8 = 1;  /*PRQA S 3516*/
    Std_ReturnType v_status_u8;
    static uint8_t s_counter_u8 = 0;
    static SystemState s_CurrentSysM_State_u8;
    static uint8 s_CurrentExternalReq_u8;
    static uint8 Previous_NMState_u8;

    static boolean RE_GenBswSysMgr_Main_Start_Periodic = FALSE;
    static uint8 RE_GenBswSysMgr_Main_Counter = 0u;

    if(RE_GenBswSysMgr_Main_Start_Periodic)
    {
      f_SysMgr_MonitorExternalRequest(); /* Call to External Montior Function Request */
      f_UpdateMessage_PDC_INFO_FD_PAM(); /* Call to f_UpdateMessage_PDC_INFO_FD_PAM function */
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if (s_CurrentExternalReq_u8 != V_System_State_u8)
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
        switch (V_System_State_u8)
        {
        case CHANGESYSSTATE_UVVOLT_REQ:
        {
        }
        break;

        case CHANGESYSSTATE_OVVOLT_REQ:
        {
        }
        break;

        case CHANGESYSSTATE_IGNON_REQ:
        {
           (void)Rte_Write_PpBSWM_PostRunRequest_0_requestedMode(REQUESTED);
           (void)Rte_Write_PpBSWM_PostRunRequest_1_requestedMode(REQUESTED);
           (void)Rte_Write_PpBSWM_RunRequest_0_requestedMode(REQUESTED);
           (void)Rte_Write_PpBSWM_RunRequest_1_requestedMode(REQUESTED);
           (void)Rte_Call_RpComM_UserRequest_FDCAN2_RequestComMode(COMM_FULL_COMMUNICATION);
           (void)Rte_Call_RpComM_UserRequest_FDCAN14_RequestComMode(COMM_FULL_COMMUNICATION);
           (void)Rte_Write_PpSystemStateManager_SysM_State(NORMAL);
           s_CurrentSysM_State_u8 = NORMAL;
           #ifdef Enable_Printf
           appLogPrintf("\n MCU1_0 Autosar Entered in FULL_COMM Mode");
           #endif
        }
        break;

        case CHANGESYSSTATE_IGNOFF_REQ: 
        {
            #ifdef Enable_Printf
            appLogPrintf("\n MCU1_0 Autosar  Entered in PREPARE_SLEEP Mode");
            #endif
           (void)Rte_Write_PpBSWM_PostRunRequest_0_requestedMode(RELEASED);
           (void)Rte_Write_PpBSWM_PostRunRequest_1_requestedMode(RELEASED);
           (void)Rte_Write_PpBSWM_RunRequest_0_requestedMode(RELEASED);
           (void)Rte_Write_PpBSWM_RunRequest_1_requestedMode(RELEASED);
           (void)Rte_Call_RpComM_UserRequest_FDCAN2_RequestComMode(COMM_NO_COMMUNICATION);
           (void)Rte_Call_RpComM_UserRequest_FDCAN14_RequestComMode(COMM_NO_COMMUNICATION);
           (void)Rte_Write_PpSystemStateManager_SysM_State(PREPARE);
            s_CurrentSysM_State_u8 = PREPARE;
            
        }
        break;

        case CHANGESYSSTATE_BOOT_REQ:
        {
           /* Send Ack to BSWM*/
           (void)Rte_Switch_PpDiagRequestNtfy_SYSModeRequestType(RTE_MODE_SYSModeRequestType_SYS_REQ_JUMPTOBOOT);
        }
        break;

        case CHANGESYSSTATE_HARD_REQ:
        {
		   #ifdef Enable_Printf
           appLogPrintf("\n MCU1_0 Autosar  CHANGESYSSTATE_HARD_REQ Requested");
           #endif
           /* Send Ack to BSWM*/
           (void)Rte_Switch_PpDiagRequestNtfy_SYSModeRequestType(RTE_MODE_SYSModeRequestType_SYS_REQ_HARDRESET);
           #ifdef Enable_Printf
           appLogPrintf("\n MCU1_0 Autosar  Hard Reset Requested");
           #endif
        }
        break;

        case CHANGESYSSTATE_NO_REQ:
           break;

        default:
        	/* Do Nothing */
           break;
        }
        s_CurrentExternalReq_u8 = V_System_State_u8; /* Assiging System State to Current External Request*/
       }

       if (s_CurrentSysM_State_u8 == NORMAL)
       {
        /*Check first DTC is set */
        v_status_u8 = Dem_GetDTCByOccurrenceTime(0, DEM_FIRST_FAILED_DTC, &v_udsDTC_u32);
        (void)v_udsDTC_u32; /*PRQA S 3119*/

        if (RTE_E_OK == v_status_u8)
        {
           (void)Rte_Write_PpGetFirstDTCStatus_DeFirstDTCStatus(TRUE);
        }
        else
        {
           (void)Rte_Write_PpGetFirstDTCStatus_DeFirstDTCStatus(FALSE);
        }

        /*Check current fail status*/
        v_status_u8 = Dem_GetDTCByOccurrenceTime(0, DEM_MOST_RECENT_FAILED_DTC, &v_udsDTC_u32);
        if (RTE_E_OK == v_status_u8)
        {
           for (s_EventId_u8 = 1; s_EventId_u8 <= 64; s_EventId_u8++)
           {
                   (void)Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus(s_EventId_u8, &v_DTCStatus_u8);
                    /* VCAST Jenkins requirement - do not modify */
                    /* VCAST Jenkins requirement - do not modify */
                    if (v_DTCStatus_u8 & 0x01)
                    /* VCAST Jenkins requirement - do not modify */
                    /* VCAST Jenkins requirement - do not modify */
                   {
                       (void)Rte_Write_PpToComFD02Tx_CurrentFailSts_FD02_PAM(TRUE);
                       break;
                   }
                   else
                   {
                       if (s_counter_u8 >= 64)
                       {
                           (void)Rte_Write_PpToComFD02Tx_CurrentFailSts_FD02_PAM(FALSE);
                           s_EventId_u8 = 1;
                       }
                   }
                   s_counter_u8++;
           }
        }
        else
        {
            (void)Rte_Write_PpToComFD02Tx_CurrentFailSts_FD02_PAM(FALSE);
        }

        /*Check Generic fail status*/
        v_status_u8 = Dem_GetDTCByOccurrenceTime(0, DEM_MOST_REC_DET_CONFIRMED_DTC, &v_udsDTC_u32);
        (void)v_udsDTC_u32;  /*PRQA S 3119*/

        if (RTE_E_OK == v_status_u8)
        {
           (void)Rte_Write_PpToComFD02Tx_GenericFailSts_FD02_PAM(TRUE);
        }
        else
        {
           (void)Rte_Write_PpToComFD02Tx_GenericFailSts_FD02_PAM(FALSE);
        }
       }
    }
    else{
      RE_GenBswSysMgr_Main_Counter++;

      if(RE_GenBswSysMgr_Main_Counter == ONE_HUNDRED_FOURTY_MS)
      {
        RE_GenBswSysMgr_Main_Start_Periodic = TRUE;
      }
      else{

      }
    }
    Previous_NMState_u8 = (uint8)(Rte_IrvRead_RE_UpdateNMState_Irv_PreviousNMState());
    (void)Rte_Write_PpBswM_PreviousNMState_requestedMode(Previous_NMState_u8);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_GenericBswM_HARDResetReq
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <HARD> and entering of Mode <EXECUTE> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <RpDcmEcuReset>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   ChangeSYSState_t Rte_IrvRead_RE_GenericBswM_HARDResetReq_Irv_ChangeSYSStateReq(void)
 *   uint16 Rte_IrvRead_RE_GenericBswM_HARDResetReq_Irv_PreviousNMState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_RE_GenericBswM_HARDResetReq_Irv_ChangeSYSStateReq(ChangeSYSState_t data)
 *   void Rte_IrvWrite_RE_GenericBswM_HARDResetReq_Irv_PreviousNMState(uint16 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenericBswM_HARDResetReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_GenericBswM_CODE) RE_GenericBswM_HARDResetReq(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenericBswM_HARDResetReq
 *********************************************************************************************************************/
  /* DD-ID: {DE8C3972-C7CF-4938-93BE-0D4243574FF6}*/
    #ifdef Enable_Printf
           appLogPrintf("\n if (RE_GenericBswM_HARDResetReq)");
           #endif
    Rte_IrvWrite_RE_GenericBswM_HARDResetReq_Irv_ChangeSYSStateReq(CHANGESYSSTATE_HARD_REQ);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_GenericBswM_JumpToBootReq
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <JUMPTOBOOTLOADER> and entering of Mode <EXECUTE> of ModeDeclarationGroupPrototype <DcmEcuReset> of PortPrototype <RpDcmEcuReset>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   ChangeSYSState_t Rte_IrvRead_RE_GenericBswM_JumpToBootReq_Irv_ChangeSYSStateReq(void)
 *   uint16 Rte_IrvRead_RE_GenericBswM_JumpToBootReq_Irv_PreviousNMState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_RE_GenericBswM_JumpToBootReq_Irv_ChangeSYSStateReq(ChangeSYSState_t data)
 *   void Rte_IrvWrite_RE_GenericBswM_JumpToBootReq_Irv_PreviousNMState(uint16 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenericBswM_JumpToBootReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_GenericBswM_CODE) RE_GenericBswM_JumpToBootReq(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GenericBswM_JumpToBootReq
 *********************************************************************************************************************/
  /* DD-ID: {B33767EF-A058-4b7c-A0E4-715C88F268FA}*/
    #ifdef Enable_Printf
           appLogPrintf("\n if (RE_GenericBswM_JumpToBootReq)");
    #endif
    Os_Call_PMIC_EnterLongWindow_DisableWdg();
	Rte_IrvWrite_RE_GenericBswM_JumpToBootReq_Irv_ChangeSYSStateReq(CHANGESYSSTATE_BOOT_REQ);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_UpdateNMState
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <NM_STATE_BUS_SLEEP> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_BUSSLEEP)
 *   - triggered on entering of Mode <NM_STATE_NORMAL> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_NORMAL)
 *   - triggered on entering of Mode <NM_STATE_PREPARE_SLEEP> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_PREPARESLEEP)
 *   - triggered on entering of Mode <NM_STATE_READY_SLEEP> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_READYSLEEP)
 *   - triggered on entering of Mode <NM_STATE_REPEAT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_REPEATMSG)
 *   - triggered on entering of Mode <NM_UINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <RpNM_State> (Activation Reason: Rte_ActivatingEvent_RE_UpdateNMState_ActReason_UNINIT)
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   ChangeSYSState_t Rte_IrvRead_RE_UpdateNMState_Irv_ChangeSYSStateReq(void)
 *   uint16 Rte_IrvRead_RE_UpdateNMState_Irv_PreviousNMState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_RE_UpdateNMState_Irv_ChangeSYSStateReq(ChangeSYSState_t data)
 *   void Rte_IrvWrite_RE_UpdateNMState_Irv_PreviousNMState(uint16 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_UpdateNMState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CDD_GenericBswM_CODE) RE_UpdateNMState(Rte_ActivatingEvent_RE_UpdateNMState activationVector) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_UpdateNMState
 *********************************************************************************************************************/
 /*ReqID:- */
    /* DD-ID: {D5E3E5FE-253F-4b0e-B118-D91C39338891}*/
	boolean v_NmNormalStateNtfy_b = FALSE;
    V_NMState_u8 = (uint8)(Rte_IrvRead_RE_UpdateNMState_Irv_PreviousNMState());  /*Reading Previous NM State*/
    (void)Rte_Write_PpToComFD02Tx_PreviousCanNMState_FD02_PAM(V_NMState_u8); /*Passing  Previous NM State to CAN Signal*/
    switch (activationVector)
    {
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_REPEATMSG:
    V_NMState_u8 = D_NMSTATE_REPEAT_MESSAGE;
    break;
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_NORMAL:
    V_NMState_u8 = D_NMSTATE_NORMAL_OPERATION;
	v_NmNormalStateNtfy_b = TRUE;
    break;
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_READYSLEEP:
    V_NMState_u8 = D_NMSTATE_READY_SLEEP;
	v_NmNormalStateNtfy_b = FALSE;
    break;
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_BUSSLEEP:
    #ifdef Enable_Printf
           appLogPrintf("\n if (Rte_ActivatingEvent_RE_UpdateNMState_ActReason_BUSSLEEP)");
           #endif
    V_NMState_u8 = D_NMSTATE_BUS_SLEEP;
    break;
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_PREPARESLEEP:
    (void)Rte_Write_PpSystemStateManager_SysM_State(SHUTDOWN);
    V_NMState_u8 = D_NMSTATE_PREPARE_BUS_SLEEP;
    break;
    case Rte_ActivatingEvent_RE_UpdateNMState_ActReason_UNINIT:
    V_NMState_u8 = D_NMSTATE_UNINIT;
    break;
    default:
    V_NMState_u8 = D_NMSTATE_UNINIT;
    break;
    }
    /*Updating new NM State*/
    (void)Rte_IrvWrite_RE_UpdateNMState_Irv_PreviousNMState(V_NMState_u8);
    /*Passing  Current  NM State to CAN Signal*/
    (void)Rte_Write_PpToComFD02Tx_CurrentCanNMState_FD02_PAM(V_NMState_u8);
	/*Notify NM Normal state status to Fault reporting SWC*/
    (void)Rte_Write_PpNmStateInfo_v_IsNmStateNormal_b(v_NmNormalStateNtfy_b);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*********************************************************************************************************************/
/**
    \brief         Application callback function which informs about all incoming RX messages including the contained data
    \param[in]     Controller  Controller which received the message
    \param[in]     ID          ID of the received message. \n
                               In case of extended or mixed ID systems the highest bit (bit 31) is set to mark an extended ID. \n
                               FD-bit will not be set at all.
    \param[in]     DataLength  Data length of the received message.
    \param[in]     pData       Pointer to the data of the received message.
    \return        CAN_OK      if the indication of the message should be called afterwards (notification to higher layer), \n
                   CAN_NOT_OK  in case of stopping furthermore reception.
    \context       Called within CAN message reception context (Polling or Interrupt).
    \note          Called by CAN driver.
    \pre           "pData" is read only and must not be accessed for further write operations. \n
    \reentrancy    Non-Reentrant
    \synchron      Synchronous
    \availability  "CanGenericPrecopy" is activated ("CAN_GENERIC_PRECOPY == STD_ON").
    \warning       None AUTOSAR API
**********************************************************************************************************************/

V_DEF_30_MCAN_FUNC(V_NONE, void, APPL_CODE) Appl_30_McanCanTimerStart( CAN_30_MCAN_CHANNEL_CANTYPE_FIRST uint8 source )
{
  /* DD-ID: {A4BE75AE-DA46-4b3d-AAE5-D3F00907EF12}*/
   /*ReqID:-*/
    
}
/* ===========================================================================
 *
 *   Name: Appl_30_McanCanTimerLoop
 *
 *   Function: 
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
V_DEF_30_MCAN_FUNC(V_NONE, Can_ReturnType, APPL_CODE) Appl_30_McanCanTimerLoop( CAN_30_MCAN_CHANNEL_CANTYPE_FIRST uint8 source )
{
  /* DD-ID: {BF3D4250-E0A4-4d4a-9579-E8897889BB85}*/
   /*ReqID:-*/
   return CAN_OK; 
}
/* ===========================================================================
 *
 *   Name: Appl_30_McanCanTimerEnd
 *
 *   Function:  
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
V_DEF_30_MCAN_FUNC(V_NONE, void, APPL_CODE) Appl_30_McanCanTimerEnd( CAN_30_MCAN_CHANNEL_CANTYPE_FIRST uint8 source )
{
  /* DD-ID: {63FBAA32-C7A8-4c73-BFD4-5578F98A4B02}*/
   /*ReqID:-*/
}
/* ===========================================================================
 *
 *   Name: Appl_30_Mcan_CanCorruptMailbox
 *
 *   Function:  
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

V_DEF_30_MCAN_FUNC(extern, void, APPL_CODE) Appl_30_Mcan_CanCorruptMailbox(uint8 Controller, Can_HwHandleType hwObjHandle)
{
  /* DD-ID: {623D0A81-C4E0-4161-ABB6-EDC35ED1D800}*/
   /*ReqID:-*/
}
/* ===========================================================================
 *
 *   Name: Appl_30_Mcan_CanRamCheckFailed
 *
 *   Function:  
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
V_DEF_30_MCAN_FUNC(extern, uint8, APPL_CODE) Appl_30_Mcan_CanRamCheckFailed(uint8 Controller)
{
  /* DD-ID: {6D4D37B2-8C5E-4dd6-8A6B-A10D40C288CB}*/
   /*ReqID:-*/
   /*GUID:-*/
    (void) Controller;  /*PRQA S 3119*/
    return (uint8)CAN_OK;

}
/* ===========================================================================
 *
 *   Name: Appl_30_Mcan_GenericPrecopy
 *
 *   Function:  
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
 FUNC(Can_ReturnType, CDD_GenericBsw_CODE) Appl_30_Mcan_GenericPrecopy( uint8 Controller, Can_IdType ID, uint8 DataLength, Can_30_Mcan_DataPtrType DataPtr )
{
  /* DD-ID: {0D9C9975-D4DE-444b-86E3-7E13C129A879}*/
   /*ReqID:-*/
      uint8 v_dataByte_u8 = FALSE;
    Can_ReturnType v_retStatus_e = CAN_NOT_OK;
    /*#10 Check if ID and CAN Controller */
    if ((ID == IGN_SIGNAL_MSG_ID) && (Controller == VCAN_FD2_CONTROLLER))
    {
        if(DataPtr != NULL_PTR)
        {
            /*Validating whether IGN signal is received or not*/
            if (((DataPtr[CMD_INGNITION_DATABYTE] & e_SEVEN) == (uint8)e_CmdIgnition_RUN) ||
                ((DataPtr[CMD_INGNITION_DATABYTE] & e_SEVEN) == (uint8)e_CmdIgnition_START))
            {
                if (V_canWUp_Val_enableWakeupValidation_b == TRUE)
                {
                    V_canWUp_Val_validWakeup_b = TRUE;
                }

            }
    
        }

    }
    return CAN_OK;
}
/* ===========================================================================
 *
 *   Name: CanWUp_Val_CheckPN
 *
 *   Function:  To be called by EcuM_CheckValidation in ECUM_Callout_Stub.c
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
 FUNC(void, CDD_GenericBsw_CODE) CanWUp_Val_CheckPN(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* DD-ID: {766FEC8A-51C9-4201-9781-FF01FABD833D}*/
   /*ReqID:-*/
   /*GUID:-*/
    if(V_canWUp_Val_validWakeup_b == TRUE)
    {
        EcuM_ValidateWakeupEvent(WakeupSource);
        /* Stop validation */
        V_canWUp_Val_enableWakeupValidation_b = FALSE;
        /* Clear validWakeup flag for next wakeup */
        V_canWUp_Val_validWakeup_b = FALSE;
    }
    else
    {
        /* Do Nothing */
    }
}
/* ===========================================================================
 *
 *   Name: CanWUp_Val_StartWakeUpValidation
 *
 *   Function:  Start wakeup validation
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
 FUNC(void, CDD_GenericBsw_CODE)CanWUp_Val_StartWakeUpValidation(void)
{
  /* DD-ID: {52CF1AD2-6B8B-41eb-8AED-1C048AE8D568}*/
   /*ReqID:-*/
   /*GUID:-*/
    V_canWUp_Val_enableWakeupValidation_b = TRUE;
    V_canWUp_Val_validWakeup_b = FALSE;
}
/* ===========================================================================
 *
 *   Name: CanWUp_Val_StopWakeUpValidation
 *
 *   Function:
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
 FUNC(void, CDD_GenericBsw_CODE)CanWUp_Val_StopWakeUpValidation(void)
{
  /* DD-ID: {362457B6-9C88-42b1-849B-AF9866A0A548}*/
   /*ReqID:-*/
   /*GUID:-*/
   
   V_canWUp_Val_enableWakeupValidation_b = FALSE;
}
/* ===========================================================================
 *
 *   Name: Det_UserReportError
 *
 *   Function: All code of of Det_UserReportError() currently added in Task.c since
 *             "GenericBSWServices" file is not yet created considering all BSW callouts.
 *              Once "GenericBSWServices" is added Det_UserReportError() code should be moved to that file
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

FUNC(Std_ReturnType, DET_CODE) Det_UserReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
{
  /* DD-ID: {16645CE9-AACC-42cb-B3CF-561E0217E86A}*/
  /*Index to store DET*/  
  volatile static uint8 s_DeterrorIndex_u8;
  /*Global counter to tell how many times DET occured*/
  static uint8 s_TotalErrorinIgCycle_u8;
  /*Last 5 det storages*/
  volatile static aDet_s_DetErrorCount_t s_StoreDetErrorId_as[DETERROR_STORE_CNT];
   /*ReqID:-*/
      /*increment counter every time Det reports error*/
    s_TotalErrorinIgCycle_u8++;

    if(s_DeterrorIndex_u8 >= (uint8)DETERROR_STORE_CNT)
    {   
        s_DeterrorIndex_u8 = e_ZERO;
    }
    else
    {
        /*do nothing*/
    }

    /*store last 5 set of errors*/
    s_StoreDetErrorId_as[s_DeterrorIndex_u8].u16ModuleId = ModuleId;
    s_StoreDetErrorId_as[s_DeterrorIndex_u8].u8InstanceId = InstanceId;
    s_StoreDetErrorId_as[s_DeterrorIndex_u8].u8ApiId = ApiId;
    s_StoreDetErrorId_as[s_DeterrorIndex_u8].u8ErrorId = ErrorId;

    /* increment Index to store 5 DET */
    s_DeterrorIndex_u8 += e_ONE;

#ifdef DET_ENDLESSLOOP_ENABLED 
    return E_OK;
#else
    return E_NOT_OK;
#endif 

}

/* ===========================================================================
*
*   Name      : SysMgr_MonitorExternalRequest
*
*   Function  : Check system state requested
*
*   Inputs    : 
*
*   Outputs   : 
*
*   Side Effects  :
*
*   Remarks   :
*
* ========================================================================= */
static void  f_SysMgr_MonitorExternalRequest(void)
{
  /* DD-ID: {AA1FA701-4F3F-4c3e-87F3-EF2D2F94E50D}*/
    /*ReqID:- */
	    CmdIgnSts v_IG_status_u8;
    ChangeSYSState_t v_ExternalReq_u16;
    udtBatteryVoltageStatus v_VoltageStatus_u8;
    uint8 v_SleepProcessState_u8;
    boolean v_ProxiDataflag_b;

    v_ExternalReq_u16 = Rte_IrvRead_RE_GenBswSysMgr_Main_Irv_ChangeSYSStateReq();          /* Read SystemState IRV Value*/
    (void)Rte_Read_RpVoltageChannelStatus_BatteryVoltageStatus(&v_VoltageStatus_u8); /* Reading the Votlage value*/
    (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&v_IG_status_u8);                     /*Reading the Ignition command status*/
    (void)Rte_Read_RpProxiReset_ProxiDataflag_b(&v_ProxiDataflag_b);
    if (v_VoltageStatus_u8 == OVER_M_VOLTAGE) /*check battery voltage*/
    {
        V_System_State_u8 = CHANGESYSSTATE_OVVOLT_REQ;
    }
    else if (v_VoltageStatus_u8 == UNDER_M_VOLTAGE)
    {
        V_System_State_u8 = CHANGESYSSTATE_UVVOLT_REQ;
    }
    else
    {
        // Do Nothing
    }
    if ((v_IG_status_u8 == Cx4_RUN) ||
        (v_IG_status_u8 == Cx5_START))
    {
        V_System_State_u8 = CHANGESYSSTATE_IGNON_REQ;
    }
    else
    {
        Rte_Read_RpSleepProcessState_status(&v_SleepProcessState_u8);  /*PRQA S 3426*/
        if (v_SleepProcessState_u8 == ENUM_CLEAR_VALUE)
        {
            V_System_State_u8 = CHANGESYSSTATE_IGNOFF_REQ;
        }
        else
        {
            /* Do nothing */
        }
    }

    /*Check Hard reset*/
    if (v_ExternalReq_u16 == CHANGESYSSTATE_HARD_REQ) /*Check Hard reset*/
    {
        V_System_State_u8 = CHANGESYSSTATE_HARD_REQ;
    }
    else
    {
        // code
    }

    /*Check Jump to Bootloader*/
    if (v_ExternalReq_u16 == CHANGESYSSTATE_BOOT_REQ) /*Check Jump to Bootloader*/
    {
        V_System_State_u8 = CHANGESYSSTATE_BOOT_REQ;
    }
    else
    {
        // code
    }

    /*Check Proxi reset*/
    if (v_ProxiDataflag_b == TRUE) /*Check Hard reset*/
    {
        V_System_State_u8 = CHANGESYSSTATE_HARD_REQ;
    }
    else
    {
        // code
    }
}
/* ===========================================================================
*
*   Name      : UpdateMessage_PDC_INFO_FD_PAM
*
*   Function  : Updates PDC_INFO_FD_PAM Messages
*
*   Inputs    : 
*
*   Outputs   : 
*
*   Side Effects  :
*
*   Remarks   :
*
* ========================================================================= */
void f_UpdateMessage_PDC_INFO_FD_PAM(void)
{
  /* DD-ID: {D16ED34B-64AB-47c9-9C05-A9FAF0ADD47C}*/
    /*ReqID:-15450229 15450224 15450258 15450254 */
	/*GUID:-*/
    CmdIgnSts v_IG_status_u8;                                                                                    /*Value for Command Igition Status*/
    StayActiveSource_FD02_PAM v_StayActiveReason_au8; /* Array Variable for StayActive Reason*/
    Dcm_SesCtrlType v_SesCtrlType_u8;  
    
    
                                                                              /* Variable for Session Ctrl Type*/
    VStdLib_MemSet(v_StayActiveReason_au8, FALSE, D_STAYACTIVE_REASON_ARRAY_SIZE);


    (void)Rte_Write_PpToComFD02Tx_WakeupSource_FD02_PAM(D_WAKEUP_REASON);   /**Write the Wakeup Reason **/
    (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&v_IG_status_u8);              /**Read the CmdIgnition Status**/
    (void)Rte_Call_RpDCMServices_GetSesCtrlType(&v_SesCtrlType_u8); /** Reading the current diagnostic sessiob **/

    if ((V_NMState_u8 == Cx5_Repeat_Message_State) /**Checking Igntion Staus and current NM STate**/
        && ((v_IG_status_u8 == Cx3_ACC) ||
            (v_IG_status_u8 == Cx1_IGN_LK) ||
            (v_IG_status_u8 == Cx0_Initialization)))
    {
        v_StayActiveReason_au8[e_SEVEN] = (uint8)e_FOUR;
    }
    else if (V_NMState_u8 == Cx4_Normal_Operation_State)
    {
        if (((v_IG_status_u8 == Cx0_Initialization) ||
             (v_IG_status_u8 == Cx1_IGN_LK) ||
             (v_IG_status_u8 == Cx3_ACC)))
        {
            if ((DCM_EXTENDED_DIAGNOSTIC_SESSION == v_SesCtrlType_u8))
            {
                v_StayActiveReason_au8[e_SEVEN] = (uint8)e_TWO;
            }
            else
            {
                v_StayActiveReason_au8[e_SEVEN] = (uint8)e_FOUR;
            }
        }
        else
        {
            v_StayActiveReason_au8[e_SEVEN] = (uint8)e_ONE;
        }
    }
    else if (V_NMState_u8 == Cx3_Ready_Sleep_State)
    {

        v_StayActiveReason_au8[e_SEVEN] = (uint8)e_ZERO;
    }
    else
    {
        // Do Nothing
    }

    (void)(Rte_Write_PpToComFD02Tx_StayActiveSource_FD02_PAM(v_StayActiveReason_au8)); /** Write the StayActiveSource signal with StayActiveReason **/
}

#define CDD_GenericBswM_STOP_SEC_CODE
#include "CDD_GenericBswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
