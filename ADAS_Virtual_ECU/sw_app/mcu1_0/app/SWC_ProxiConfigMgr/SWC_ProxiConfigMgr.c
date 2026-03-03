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
 *             File:  SWC_ProxiConfigMgr.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_ProxiConfigMgr
 *  Generation Time:  2025-04-08 15:09:54
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_ProxiConfigMgr>
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
 * BSM_THA_Brk_Resp
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
 * Dcm_NegativeResponseCodeType
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
 * TotalOdometer
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
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
 *********************************************************************************************************************/

#include "Rte_SWC_ProxiConfigMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "vstdlib.h"
#include "Enums.h"
#include "ProxiMgrIpcDataTypes.h"
#include "ipc_manager.h"
#include "SSM_Slave.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "SSM_BSW_Interface.h"
/*Shift Bits Macro*/

#define MCU2_0_STATE                        0x01u
#define MCU2_1_STATE                        0x02u
#define MPU1_0_STATE                        0x04u
#define ALL_CORE_STATE                      (MCU2_0_STATE | MCU2_1_STATE | MPU1_0_STATE)

#define D_kDescNrcInvalidFormat                      0x13U
#define D_kDescNrcRequestOutOfRange                  0x31u
#define D_PROXI_BIT0_MASK                            0x01U
#define D_PROXI_BIT1_MASK                            0x02U
#define D_PROXI_BIT2_MASK                            0x04U
#define D_PROXI_BIT3_MASK                            0x08U
#define D_PROXI_BIT4_MASK                            0x10U
#define D_PROXI_BIT5_MASK                            0x20U
#define D_PROXI_BIT6_MASK                            0x40U
#define D_PROXI_BIT7_MASK                            0x80u
#define D_MINIMUM_PROXI_FILE_DATA_SIZE               214u
#define D_INITIAL_VALUE                              0x0000u
#define D_PROXI_ERROR_LOG_SIZE                       3u
#define D_TOTAL_PROXI_PARAM                          4u
#define D_TOTAL_VAR_STD_TYPE                         11u
#define D_TOTAL_VAR_NON_STD_TYPE                     10u

#define D_PROXI_BIT0_TO_1_MASK (D_PROXI_BIT0_MASK | D_PROXI_BIT1_MASK)
#define D_PROXI_BIT0_TO_7_MASK  0xFF
#define D_PROXI_BIT0_TO_2_MASK (D_PROXI_BIT0_MASK | D_PROXI_BIT1_MASK | D_PROXI_BIT2_MASK)
#define D_PROXI_BIT0_TO_3_MASK (D_PROXI_BIT0_MASK | D_PROXI_BIT1_MASK | D_PROXI_BIT2_MASK | D_PROXI_BIT3_MASK )
#define D_PROXI_BIT2_TO_4_MASK (D_PROXI_BIT2_MASK | D_PROXI_BIT3_MASK | D_PROXI_BIT4_MASK)
#define D_PROXI_BIT3_TO_4_MASK (D_PROXI_BIT3_MASK | D_PROXI_BIT4_MASK)
#define D_PROXI_BIT4_TO_5_MASK (D_PROXI_BIT4_MASK | D_PROXI_BIT5_MASK )
#define D_PROXI_BIT4_TO_7_MASK (D_PROXI_BIT4_MASK | D_PROXI_BIT5_MASK | D_PROXI_BIT6_MASK | D_PROXI_BIT7_MASK)
#define D_PROXI_BIT5_TO_7_MASK (D_PROXI_BIT5_MASK | D_PROXI_BIT6_MASK | D_PROXI_BIT7_MASK)

#define D_PROXI_BIT1_SHIFT 1U
#define D_PROXI_BIT2_SHIFT 2U
#define D_PROXI_BIT3_SHIFT 3U
#define D_PROXI_BIT4_SHIFT 4U
#define D_PROXI_BIT5_SHIFT 5U
#define D_PROXI_BIT6_SHIFT 6U
#define D_PROXI_BIT7_SHIFT 7U

#define D_ALL_SET 0xFFU
#define D_ASCII0  0x30U
#define D_ASCII9  0x39U
#define D_HEX_15  0X0FU
#define D_HEX_10  0x0AU
#define D_NEW_PROXICHANGE 0U

#define D_DRIVER_SIDE_MASK                             D_PROXI_BIT3_MASK
#define D_DRIVER_SIDE_SHIFT                            D_PROXI_BIT3_SHIFT

#define D_COUNTRY_CODE_MASK                            D_PROXI_BIT0_TO_7_MASK

#define D_VEHICLE_LINE_CONFIGURATION_MASK              D_PROXI_BIT0_TO_7_MASK

#define D_WHEELBASE_DEFINITION_MASK                    D_PROXI_BIT4_TO_7_MASK
#define D_WHEELBASE_DEFINITION_SHIFT                   D_PROXI_BIT4_SHIFT

#define D_SIDE_DISTANCE_WARNING_MASK                   D_PROXI_BIT7_MASK
#define D_SIDE_DISTANCE_WARNING_SHIFT                  D_PROXI_BIT7_SHIFT

#define D_STEERING_RATIO_RACK_TYPE_MASK                D_PROXI_BIT0_TO_1_MASK

#define D_GEAR_BOX_TYPE_MASK                           D_PROXI_BIT0_TO_2_MASK

#define D_PAM_CONFIGURATION_MASK                       D_PROXI_BIT4_TO_5_MASK
#define D_PAM_CONFIGURATION_SHIFT                      D_PROXI_BIT4_SHIFT

#define D_SURROUND_VIEW_CAMERA_MASK                    D_PROXI_BIT0_MASK

#define D_MIRRORS_TYPE_MASK                  	         D_PROXI_BIT3_TO_4_MASK
#define D_MIRRORS_TYPE_SHIFT                           D_PROXI_BIT3_SHIFT

#define D_CAN_NODE_14_TRSCM_MASK                       D_PROXI_BIT6_MASK
#define D_CAN_NODE_14_TRSCM_SHIFT                      D_PROXI_BIT6_SHIFT

#define D_CAN_NODE_27_ASM_MASK                         D_PROXI_BIT3_MASK
#define D_CAN_NODE_27_ASM_SHIFT                        D_PROXI_BIT3_SHIFT

#define D_CAN_NODE_63_TTM_MASK                         D_PROXI_BIT7_MASK
#define D_CAN_NODE_63_TTM_SHIFT                        D_PROXI_BIT7_SHIFT

#define D_CAN_NODE_67_DTCM_MASK                        D_PROXI_BIT3_MASK
#define D_CAN_NODE_67_DTCM_SHIFT                       D_PROXI_BIT3_SHIFT

#define D_CAN_NODE_95_ITCM_MASK                        D_PROXI_BIT7_MASK
#define D_CAN_NODE_95_ITCM_SHIFT                       D_PROXI_BIT7_SHIFT

#define D_REAR_VIEW_CAMERA_MASK                        D_PROXI_BIT0_MASK

#define D_STOP_AND_START_MASK                          D_PROXI_BIT0_MASK

#define D_PARK_WITH_STOP_MASK                          D_PROXI_BIT6_MASK
#define D_PARK_WITH_STOP_SHIFT                         D_PROXI_BIT6_SHIFT

#define D_DRIVE_TYPE_VARIANT_MASK                      D_PROXI_BIT5_TO_7_MASK
#define D_DRIVE_TYPE_VARIANT_SHIFT                     D_PROXI_BIT5_SHIFT

#define D_PAM_TUNING_SET_MASK                          D_PROXI_BIT0_TO_2_MASK

#define D_SEMI_AUTOMATIC_PARKING_MASK                  D_PROXI_BIT3_MASK
#define D_SEMI_AUTOMATIC_PARKING_SHIFT                 D_PROXI_BIT3_SHIFT

#define D_SRT_MASK                                     D_PROXI_BIT1_MASK
#define D_SRT_SHIFT                                    D_PROXI_BIT1_SHIFT

#define D_HYBRID_TYPE_MASK                             D_PROXI_BIT0_TO_3_MASK

#define D_PULL_OUT_CONTROL_MASK                        D_PROXI_BIT5_MASK
#define D_PULL_OUT_CONTROL_SHIFT                       D_PROXI_BIT5_SHIFT

#define D_FORWARD_FACING_CAMERA_MASK                   D_PROXI_BIT1_MASK
#define D_FORWARD_FACING_CAMERA_SHIFT                  D_PROXI_BIT1_SHIFT

#define D_AUTONOMY_LEVEL_MASK                          D_PROXI_BIT2_TO_4_MASK
#define D_AUTONOMY_LEVEL_SHIFT                         D_PROXI_BIT2_SHIFT

#define D_FULL_AUTOMATIC_PARKING_MASK                  D_PROXI_BIT5_MASK 
#define D_FULL_AUTOMATIC_PARKING_SHIFT                 D_PROXI_BIT5_SHIFT

#define D_RADIO_DISPLAY_MASK                           D_PROXI_BIT0_TO_3_MASK

#define D_AUXILIARY_CAMERA_MASK                        D_PROXI_BIT2_MASK
#define D_AUXILIARY_CAMERA_SHIFT                       D_PROXI_BIT2_SHIFT

#define D_TRAILER_REVERSE_GUIDENCE_MASK                D_PROXI_BIT3_MASK
#define D_TRAILER_REVERSE_GUIDENCE_SHIFT               D_PROXI_BIT3_SHIFT

#define D_TRAILER_SURROUND_MASK                        D_PROXI_BIT6_MASK
#define D_TRAILER_SURROUND_SHIFT                       D_PROXI_BIT6_SHIFT

#define D_TRAILER_REVERSE_STEERING_MASK                D_PROXI_BIT7_MASK
#define D_TRAILER_REVERSE_STEERING_SHIFT               D_PROXI_BIT7_SHIFT

#define D_TRAILER_HITCH_ASSIST_MASK                    D_PROXI_BIT1_MASK
#define D_TRAILER_HITCH_ASSIST_SHIFT                   D_PROXI_BIT1_SHIFT


/*Below variables shouldnt be included as safe*/
__attribute__ ((section("QMRAM"))) VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */


/*SaKa:-Move VIN DID and PIM to RID Manager/Configuration replace lock status s_variable_u8 with PIM*/
#if defined( BUILD_MCU1_0 )
#define SWC_ProxiConfigMgr_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_ProxiConfigMgr_MemMap.h"
#endif
volatile static uint8 V_u8IsDataAvailable_u8=FALSE;
static  boolean v_ProxiUpdateFlag_b = FALSE;


#if defined( BUILD_MCU1_0 )
#define SWC_ProxiConfigMgr_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_ProxiConfigMgr_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define SWC_ProxiConfigMgr_START_SEC_VAR_NOINIT_UNSPECIFIED/*PRQA S 0791*/
#include "SWC_ProxiConfigMgr_MemMap.h"
#endif
static uint8 V_PROXI_error_log_index_u8 ;

static uint8 V_ProxiError_Array_au8[e_ELEVEN];
static ME_Proxi_to_IpcSignals_t ProxiToIpc_s;
static uint8 v_RemoteCoreStatus_u8;
static ME_Proxi_MPU1_0_to_MCU1_0_t ME_Proxi_MPU1_0_to_MCU1_0_data;
#if defined( BUILD_MCU1_0 )
#define SWC_ProxiConfigMgr_STOP_SEC_VAR_NOINIT_UNSPECIFIED/*PRQA S 0791*/
#include "SWC_ProxiConfigMgr_MemMap.h"
#endif

/* Function declarations */
static void F_aProxiM_f_VehCfgPROXIErrorLogDataClear_v(void);
static void F_aProxiM_f_PROXIWriteErrorLog_v(uint8 i_error_found_u8, uint8 i_byte_with_error_u8, uint8 i_bit_info_mask_u8 );
static void F_aProxiM_f_CheckReceivedProxiDataIntgrity(uint8* Rxbuffer,uint16 i_length_u16);
static void F_aProxiM_f_incrementproxiwritecounter_v(void);
static void F_aProxiM_f_writeConfigurationValue_v(const uint8 data[]);
static uint16 F_aProxiM_f_GetCRCFromString_uint16(const uint8 data1[]);
static uint8 F_aProxiM_F_CRCPROXI(const uint8 PROXI_message[], uint32 i_nBytes_u32);
static void F_ProxiMgr_ErrorChk(void);
static void F_UpdateIpcStruct(void);
static void F_SendDataToRemoteCore(void);
void Update_Proxi_MirrorBlock(boolean Proxi_Erase_block);
uint8 F_camera_variant(void);

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
 * BSM_THA_Brk_Resp: Integer in interval [0...3]
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
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
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
 * IgnitionOnCounter: Integer in interval [0...65535]
 * LHF_FastPulseCounter: Integer in interval [0...255]
 * LHF_Spin: Integer in interval [0...3]
 * LHR_FastPulseCounter: Integer in interval [0...255]
 * LHR_Spin: Integer in interval [0...3]
 * NvM_RequestResultType: Integer in interval [0...255]
 * OperationalModeSts: Integer in interval [0...15]
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
 * RHF_FastPulseCounter: Integer in interval [0...255]
 * RHF_Spin: Integer in interval [0...3]
 * RHR_FastPulseCounter: Integer in interval [0...255]
 * RHR_Spin: Integer in interval [0...3]
 * RemStActvSts: Integer in interval [0...1]
 * Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1: Integer in interval [0...4294967295]
 * Rte_DT_StayActiveSource_FD02_PAM_0: Integer in interval [0...4]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * THA_EPB_Req: Integer in interval [0...3]
 * THA_STAT: Integer in interval [0...7]
 * THA_SpeedLimit_Req: Integer in interval [0...3]
 * THA_Speed_Limit: Integer in interval [0...31]
 * THA_SteeringTorqueReq: Integer in interval [0...3]
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
 * TotalOdometer: Integer in interval [0...1048575]
 * Trailer_Angle: Integer in interval [0...255]
 * Trailer_Angle_Sign: Integer in interval [0...3]
 * Trailer_Calibration: Integer in interval [0...2]
 * TrlrHitchLight_Cntrl: Integer in interval [0...3]
 * TurnIndicatorSts: Integer in interval [0...3]
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
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Array_04Byte: Array with 4 element(s) of type uint8
 * Array_10Byte: Array with 10 element(s) of type uint8
 * Array_11Byte: Array with 11 element(s) of type uint8
 * N_PDU: Array with 8 element(s) of type uint8
 * ProxiErrData_Arr: Array with 3 element(s) of type uint8
 * Proxi_255byte: Array with 255 element(s) of type uint8
 * SSM_MCU_1_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * StayActiveSource_FD02_PAM: Array with 8 element(s) of type Rte_DT_StayActiveSource_FD02_PAM_0
 *
 * Record Types:
 * =============
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
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
 * ME_Hydra2defs_S_PROXI_error_Data_t: Record with elements
 *   ErrorFound of type ProxiErrData_Arr
 *   ByteWithError of type ProxiErrData_Arr
 *   BitInformationMask of type ProxiErrData_Arr
 * ME_Proxi_MPU1_0_to_MCU1_0_t: Record with elements
 *   a72_cpu_load of type float32
 *   state of type Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1
 *   PRX_RadioDispTyp_u8 of type uint8
 *   PRX_variantID_u8 of type uint8
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
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   ME_Hydra2defs_S_CodingTableExt_t *Rte_Pim_ProxiConfigTable_MirrorBlock(void)
 *   ME_Hydra2defs_S_PROXI_error_Data_t *Rte_Pim_ProxiErrorData_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   ME_Hydra2defs_S_CodingTableExt_t *Rte_CData_ProxiConfigTable_DefaultValue(void)
 *   ME_Hydra2defs_S_PROXI_error_Data_t *Rte_CData_ProxiErrorData_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define SWC_ProxiConfigMgr_START_SEC_CODE
#include "SWC_ProxiConfigMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_DID2023_ProxiData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <Pp_2023_ProxiData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_DID2023_ProxiData(const uint8 *Data, uint16 Datalength, Dcm_NegativeResponseCodeType *Errorcode)
 *     Argument Data: uint8* is of type Proxi_255byte
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DID2023_ProxiData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_ProxiConfigMgr_CODE) RE_DID2023_ProxiData(P2CONST(uint8, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) Errorcode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DID2023_ProxiData
 *********************************************************************************************************************/
  /* DD-ID: {49E0F64A-7622-4cbe-AA23-A7C63682C544}*/

 /*Check if the data is valid*/
 if (NULL_PTR != Data)
 {
   /* Clear all the previously stored PROXI error data to restart check. */
   F_aProxiM_f_VehCfgPROXIErrorLogDataClear_v();
   /*check integrity of Proxi Data*/
   F_aProxiM_f_CheckReceivedProxiDataIntgrity((uint8*)Data,Datalength);
   (void)Rte_Write_PpProxiErrorData_Error(Rte_Pim_ProxiErrorData_MirrorBlock());
   
   /*check if data integrity passed*/
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
   if (V_PROXI_error_log_index_u8 != FALSE)
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
   {
     V_u8IsDataAvailable_u8 = FALSE;
     *Errorcode = Rte_Pim_ProxiErrorData_MirrorBlock()->ErrorFound[e_ZERO];
     //v_retval_u8 = RTE_E_DataServices_Data_2E2023_PROXI_Data_E_NOT_OK;
   }
   else
   {
     V_u8IsDataAvailable_u8 = TRUE;
     /* Write the Configuration parameters */
     F_aProxiM_f_writeConfigurationValue_v(&Data[e_ZERO]);
     /* Increment the PROXI write counter*/
     F_aProxiM_f_incrementproxiwritecounter_v();
     Rte_Pim_ProxiConfigTable_MirrorBlock()->Variant_ID = F_camera_variant();

     Update_Proxi_MirrorBlock(FALSE);
    // v_retval_u8 = RTE_E_OK;
   }
 }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_ProxiConfigMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiConfigMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiConfigMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiConfigMgr_Init
 *********************************************************************************************************************/
  /*GUID:-{CA4F8286-BAC5-44a5-9C7B-08050E09A8C6}*/
  /* DD-ID: {E83E4A85-7CD1-46ff-942D-9AD263360F86}*/

  /**************************************************ProxiConfigTable**********************************************************/
  VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock,
   &Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy, sizeof(ME_Hydra2defs_S_CodingTableExt_t));

  /**************************************************ProxiErrorData**********************************************************/
  VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock,
   &Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy, sizeof(ME_Hydra2defs_S_PROXI_error_Data_t));

  VStdLib_MemClr(V_ProxiError_Array_au8,sizeof(V_ProxiError_Array_au8));
  v_ProxiUpdateFlag_b = FALSE;
 (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_ProxiManager,SSM_APPSTATE_INIT);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_ProxiConfigMgr_Main
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
 *   Std_ReturnType Rte_Read_RpFromComFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpProxiConfigData_ProxiData(const ME_Hydra2defs_S_CodingTableExt_t *data)
 *   Std_ReturnType Rte_Write_PpProxiErrorData_Error(const ME_Hydra2defs_S_PROXI_error_Data_t *data)
 *   Std_ReturnType Rte_Write_PpProxiReset_ProxiDataflag_b(boolean data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_Fullautomaticparking(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_PAMConfig_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_PRX_CanNod27_b(boolean data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_Pamtuningset(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_Parkwithstop_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_SurroundViewCam_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_Trailerhitchassist_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpProxiToSWC_TyreSz_u16(uint16 data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_EOL_FD02_PAM(EOL_FD02_PAM data)
 *   Std_ReturnType Rte_Write_PpVariantData_Variant(uint8 data)
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
 *   Std_ReturnType Rte_Call_Rp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_ProxiErrorData_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiConfigMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiConfigMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiConfigMgr_Main
 *********************************************************************************************************************/
  /*GUID:-{9A39B841-073F-4bc7-9C45-0DDEFE5D427B}*/
  /* DD-ID: {9A39B841-073F-4bc7-9C45-0DDEFE5D427B}*/
  static boolean v_ProxiDataflag_b = FALSE;/*PRQA S 3516*/
  static uint32 v_ProxiResetCntr = (uint8)e_ZERO;
  SSM_SystemState SSMSystemState;
  static SSM_SystemStateDef previous_SSMMasterState = SSM_STATE_MAX;
  NvM_RequestResultType v_BlockErrorStatus;

  (void)Rte_Write_PpToComFD02Tx_EOL_FD02_PAM((uint8)e_ONE); //ToUpdate
  if(V_u8IsDataAvailable_u8 == TRUE)
  {
    V_u8IsDataAvailable_u8 = FALSE;  /*clear once update is done*/
    v_ProxiDataflag_b = TRUE;
    Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock.bValid = TRUE;
    (void)Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_GetErrorStatus(&v_BlockErrorStatus);
    if(NVM_REQ_PENDING != v_BlockErrorStatus)
    {
    	(void)Rte_Call_NvMService_AC3_SRBS_ProxiConfigTable_WriteBlock(Rte_Pim_ProxiConfigTable_MirrorBlock());
    }
    
     /*Send indication to swc did that Nvm writing has started*/
    (void)Rte_Call_Rp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation();
    (void)Rte_Write_PpProxiConfigData_ProxiData(Rte_Pim_ProxiConfigTable_MirrorBlock());
    (void)Rte_Write_PpProxiToSWC_TyreSz_u16(Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16);
    (void)Rte_Write_PpProxiToSWC_SurroundViewCam_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera);
    (void)Rte_Write_PpProxiToSWC_Fullautomaticparking(Rte_Pim_ProxiConfigTable_MirrorBlock()->Fullautomaticparking);
    (void)Rte_Write_PpProxiToSWC_Pamtuningset(Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset);
    (void)Rte_Write_PpProxiToSWC_PRX_CanNod27_b(Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode27Asm_uint8);
    (void)Rte_Write_PpProxiToSWC_PAMConfig_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->PAMConfig_uint8);
    (void)Rte_Write_PpProxiToSWC_Trailerhitchassist_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerhitchassist);
    (void)Rte_Write_PpProxiToSWC_Parkwithstop_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Parkwithstop);
    F_UpdateIpcStruct(); /*Update Proxi data only once every power cycle*/
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t, (uint16)sizeof(ME_ProxiToMPU1_0_Def_t));
    F_ProxiMgr_ErrorChk();    /*Check if data is updated*/
   }
  else
  {
    /*Do Nothing*/
  }
 
  if(v_ProxiUpdateFlag_b == FALSE)  
  {
    F_UpdateIpcStruct(); /*Update Proxi data only once every power cycle*/
    F_ProxiMgr_ErrorChk();  /*Perform Error check every power cycle*/
    v_ProxiUpdateFlag_b = TRUE;
    (void)Rte_Write_PpProxiConfigData_ProxiData(Rte_Pim_ProxiConfigTable_MirrorBlock());
    (void)Rte_Write_PpProxiToSWC_TyreSz_u16(Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16);
    (void)Rte_Write_PpProxiToSWC_SurroundViewCam_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera);
    (void)Rte_Write_PpProxiToSWC_Fullautomaticparking(Rte_Pim_ProxiConfigTable_MirrorBlock()->Fullautomaticparking);
    (void)Rte_Write_PpProxiToSWC_Pamtuningset(Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset);
    (void)Rte_Write_PpProxiToSWC_PRX_CanNod27_b(Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode27Asm_uint8);
    (void)Rte_Write_PpProxiToSWC_PAMConfig_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->PAMConfig_uint8);
    (void)Rte_Write_PpProxiToSWC_Trailerhitchassist_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerhitchassist);
    (void)Rte_Write_PpProxiToSWC_Parkwithstop_u8(Rte_Pim_ProxiConfigTable_MirrorBlock()->Parkwithstop);
  }
  else
  {
	  /*Do Nothing*/
  }
  if(v_RemoteCoreStatus_u8 != ALL_CORE_STATE)  /*Return function till Proxi data sent to all core*/
  {
    F_SendDataToRemoteCore();
  }
  else if(ME_Proxi_MPU1_0_to_MCU1_0_data.state != QNX_RUNNING_PROXI_WRITTEN_PASS_STATE)
  {
	  (void)Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(&ME_Proxi_MPU1_0_to_MCU1_0_data);
	  if(ME_Proxi_MPU1_0_to_MCU1_0_data.state == QNX_RESTART_REQ_STATE)
	  {
      v_ProxiDataflag_b = TRUE;
		  (void)Rte_Write_PpProxiReset_ProxiDataflag_b(v_ProxiDataflag_b);
	  }
	  else if(ME_Proxi_MPU1_0_to_MCU1_0_data.state == QNX_ETFS_NOT_READY_STATE)
	  {
      (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t, (uint16)sizeof(ME_ProxiToMPU1_0_Def_t));
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
  #if 0
  /*This is not clear, will confirm and update*/
  if(TRUE == v_ProxiDataflag_b)
  {
    if(e_TWO_HUNDRED == v_ProxiResetCntr)
    {
      (void)Rte_Write_PpProxiReset_ProxiDataflag_b(v_ProxiDataflag_b);
    }
    else
    {
      v_ProxiResetCntr++;
    }    
  }
  else
  {
    /*Do nothing*/
  }
  #endif


  // Read SSM master state and update the application accordingly
  (void)Rte_Read_R_SystemState_SystemState(&SSMSystemState);

  if(previous_SSMMasterState != SSMSystemState.SystemState)
  {
    switch(SSMSystemState.SystemState)
    {
      case SSM_STATE_BOOTING:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_ProxiManager, SSM_APPSTATE_INIT);
      break;
      case SSM_STATE_IPCREADY:
      case SSM_STATE_RUNNING:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_ProxiManager, SSM_APPSTATE_RUNNING);
      break;
      case SSM_STATE_DEGRADED:
      case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP:
      case SSM_STATE_SHUTTINGDOWN_REMOTECORES:
      case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE:
      case SSM_STATE_OFF:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_ProxiManager, SSM_APPSTATE_STOPPED);
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
 *
 * Runnable Entity Name: RE_ProxiMgr_ConfigDataRSP
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Digit_01> of PortPrototype <RpFromComFD02Rx>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_01_PAM(Digit_01_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_02_PAM(Digit_02_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_03_PAM(Digit_03_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_04_PAM(Digit_04_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_05_PAM(Digit_05_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_06_PAM(Digit_06_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_07_PAM(Digit_07_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_08_PAM(Digit_08_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_09_PAM(Digit_09_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_10_PAM(Digit_10_PAM data)
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_Digit_11_PAM(Digit_11_PAM data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiMgr_ConfigDataRSP_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_ProxiConfigMgr_CODE) RE_ProxiMgr_ConfigDataRSP(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ProxiMgr_ConfigDataRSP
 *********************************************************************************************************************/
/*ReqID:-16356500,15799972,16356485,15799992*/
/*GUID:-{2F766FE8-9E04-4c9b-9C32-2EFFC9F2E86C}*/
  /* DD-ID: {2F766FE8-9E04-4c9b-9C32-2EFFC9F2E86C}*/
static uint8 V_config_code_rsp_value_au8[e_ELEVEN];
uint8 v_u8incr_u8=FALSE;
if(Rte_Pim_ProxiConfigTable_MirrorBlock()->PROXIWriteCounter == (uint8)e_ZERO)
{
  VStdLib_MemSet(&V_config_code_rsp_value_au8[(uint8)e_ZERO],D_HEX_10,(uint8)e_ELEVEN); 
}
else
{
  for(v_u8incr_u8=(uint8)e_ZERO;v_u8incr_u8 < (uint8)e_ELEVEN;v_u8incr_u8++)
  {
    V_config_code_rsp_value_au8[(uint8)e_TEN-v_u8incr_u8] = (Rte_Pim_ProxiConfigTable_MirrorBlock()->ConfigCode[v_u8incr_u8] - D_ASCII0);
  }
}
  (void)Rte_Write_PpToComFD02Tx_Digit_01_PAM(V_config_code_rsp_value_au8[e_ZERO]); 
  (void)Rte_Write_PpToComFD02Tx_Digit_02_PAM(V_config_code_rsp_value_au8[e_ONE]);
  (void)Rte_Write_PpToComFD02Tx_Digit_03_PAM(V_config_code_rsp_value_au8[e_TWO]);
  (void)Rte_Write_PpToComFD02Tx_Digit_04_PAM(V_config_code_rsp_value_au8[e_THREE]);
  (void)Rte_Write_PpToComFD02Tx_Digit_05_PAM(V_config_code_rsp_value_au8[e_FOUR]);
  (void)Rte_Write_PpToComFD02Tx_Digit_06_PAM(V_config_code_rsp_value_au8[e_FIVE]);
  (void)Rte_Write_PpToComFD02Tx_Digit_07_PAM(V_config_code_rsp_value_au8[e_SIX]);
  (void)Rte_Write_PpToComFD02Tx_Digit_08_PAM(V_config_code_rsp_value_au8[e_SEVEN]);
  (void)Rte_Write_PpToComFD02Tx_Digit_09_PAM(V_config_code_rsp_value_au8[e_EIGHT]);
  (void)Rte_Write_PpToComFD02Tx_Digit_10_PAM(V_config_code_rsp_value_au8[e_NINE]);
  (void)Rte_Write_PpToComFD02Tx_Digit_11_PAM(V_config_code_rsp_value_au8[e_TEN]);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* ===========================================================================
*
*   Name:          F_aProxiM_f_GetCRCFromString_uint16
*
*   Function:      This function is called get the CRC stored in PROXI String
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(uint16, SWC_ProxiMgr_CODE)static F_aProxiM_f_GetCRCFromString_uint16(const uint8 data1[])
{
  /* DD-ID: {3CBF017C-EDB7-41c1-9222-957C4A35F34B}*/
	/*GUID:-{3CBF017C-EDB7-41c1-9222-957C4A35F34B}*/
  uint16 v_CRC_in_string_u16 = (uint8)e_ZERO;
  /*Check if the data is valid*/
  if (NULL_PTR != data1)
  {
    v_CRC_in_string_u16  = (uint16)(((uint16)(data1[e_ZERO])-D_ASCII0) *TEN_THOUSAND);
    v_CRC_in_string_u16 += (uint16)(((uint16)(data1[e_ONE])-D_ASCII0) *THOUSAND);
    v_CRC_in_string_u16 += (uint16)(((uint16)(data1[e_TWO])-D_ASCII0) *e_ONE_HUNDRED);
    v_CRC_in_string_u16 += (uint16)(((uint16)(data1[e_THREE])-D_ASCII0) *e_TEN);
    v_CRC_in_string_u16 += (uint16)(data1[e_FOUR])- D_ASCII0 ;
  }
  else
  {
    /* Do Nothing this condition should never be satisfied*/
  }
  return v_CRC_in_string_u16;
}
  /* ===========================================================================
*
*   Name:          F_aProxiM_f_PROXIWriteErrorLog_v
*
*   Function:      This function is called to Write PROXI error log 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(void, SWC_ProxiMgr_CODE)static F_aProxiM_f_PROXIWriteErrorLog_v(uint8 i_error_found_u8, uint8 i_byte_with_error_u8, uint8 i_bit_info_mask_u8)
{
  /* DD-ID: {FD5623B7-B292-4c5e-BC09-D41B1A9A8D17}*/
	/*GUID:-*/
  /* If the log is not filled, write the next entry.
  ** If it is filled , the Error should be ignored
  */
  if (V_PROXI_error_log_index_u8 < D_PROXI_ERROR_LOG_SIZE)
  {
    Rte_Pim_ProxiErrorData_MirrorBlock()->ErrorFound[V_PROXI_error_log_index_u8] = i_error_found_u8;
    Rte_Pim_ProxiErrorData_MirrorBlock()->ByteWithError[V_PROXI_error_log_index_u8] = i_byte_with_error_u8;
    Rte_Pim_ProxiErrorData_MirrorBlock()->BitInformationMask[V_PROXI_error_log_index_u8] = i_bit_info_mask_u8;
    V_PROXI_error_log_index_u8++;
   (void)Rte_Call_NvMService_AC3_SRBS_ProxiErrorData_SetRamBlockStatus(TRUE);
  }
}
/* ===========================================================================
*
*   Name:          F_aProxiM_f_VehCfgPROXIErrorLogDataClear_v
*
*   Function:      This function is called to clear the error log of PROXI 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(void, SWC_ProxiMgr_CODE)static F_aProxiM_f_VehCfgPROXIErrorLogDataClear_v(void)
{
  /* DD-ID: {A306D10D-7D7F-45ba-889A-9A6F4220DE31}*/
	/*GUID:-{A306D10D-7D7F-45ba-889A-9A6F4220DE31}*/

  uint8 v_u8incr_u8;
  for (v_u8incr_u8 = FALSE; v_u8incr_u8 < (uint8)e_THREE; v_u8incr_u8++)
  {
    Rte_Pim_ProxiErrorData_MirrorBlock()->ErrorFound[v_u8incr_u8] = FALSE;
    Rte_Pim_ProxiErrorData_MirrorBlock()->ByteWithError[v_u8incr_u8]= FALSE;
    Rte_Pim_ProxiErrorData_MirrorBlock()->BitInformationMask[v_u8incr_u8]= FALSE;
  }
  V_PROXI_error_log_index_u8 = FALSE;
  (void)Rte_Call_NvMService_AC3_SRBS_ProxiErrorData_SetRamBlockStatus(TRUE);

}


void Update_Proxi_MirrorBlock(boolean Proxi_Erase_block)
{
  /* DD-ID: {1D2AA440-96E7-4666-8AD7-4C5837778917}*/
	if(Proxi_Erase_block)
	{
		/**************************************************ProxiConfigTable**********************************************************/
		VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock,
			&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy, sizeof(ME_Hydra2defs_S_CodingTableExt_t));

		/**************************************************ProxiErrorData**********************************************************/
		VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock,
			&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy, sizeof(ME_Hydra2defs_S_PROXI_error_Data_t));
	}
	else
	{
		/**************************************************ProxiConfigTable**********************************************************/
		VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock_copy,
			&Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock, sizeof(ME_Hydra2defs_S_CodingTableExt_t));

		/**************************************************ProxiErrorData**********************************************************/
		VStdLib_MemCpy(&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock_copy,
			&Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock, sizeof(ME_Hydra2defs_S_PROXI_error_Data_t));
	}
}

/* ===========================================================================
*
*   Name:          F_aProxiM_f_writeConfigurationValue_v
*
*   Function:      This function is called to set values to NVM that we read from PROXI
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */

FUNC(void, SWC_ProxiMgr_CODE)static F_aProxiM_f_writeConfigurationValue_v(const uint8 data[])
{
  /* DD-ID: {BE45AFCC-9942-4b81-8BAC-9DEC08418DBC}*/
	/*GUID:-{BE45AFCC-9942-4b81-8BAC-9DEC08418DBC}*/
  uint8 v_inc_u8 = (uint8)e_ZERO;

  /*Check if the data is valid*/
  if (NULL_PTR != data)
  {
    /** Write configuration Code*/
    for (v_inc_u8 = (uint8)e_ZERO; v_inc_u8 < (uint8)e_ELEVEN; v_inc_u8++)
    {
      Rte_Pim_ProxiConfigTable_MirrorBlock()->ConfigCode[v_inc_u8] = data[v_inc_u8];
    }
    /*Write Tester Code*/
    for (v_inc_u8 = (uint8)e_ELEVEN; v_inc_u8 < (uint8)e_TWENTY_ONE; v_inc_u8++)
    {
      Rte_Pim_ProxiConfigTable_MirrorBlock()->TesterCode[v_inc_u8-(uint8)e_ELEVEN] = data[v_inc_u8];
    }
    /*Write Production Date Code*/
    for (v_inc_u8 = (uint8)e_TWENTY_ONE; v_inc_u8 < (uint8)e_TWENTY_FIVE; v_inc_u8++)
    {
      Rte_Pim_ProxiConfigTable_MirrorBlock()->ProductionDate[v_inc_u8 - (uint8)e_TWENTY_ONE] = data[v_inc_u8];
    }
    
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode14trscm_uint8 = (((data[e_TWENTY_SIX] &  D_CAN_NODE_14_TRSCM_MASK))) >> D_CAN_NODE_14_TRSCM_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode27Asm_uint8 = (data[e_TWENTY_EIGHT] & D_CAN_NODE_27_ASM_MASK) >> D_CAN_NODE_27_ASM_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode63ttm_uint8 = (data[e_THIRTY_TWO] & D_CAN_NODE_63_TTM_MASK) >> D_CAN_NODE_63_TTM_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode67dtcm_uint8 = (data[e_THIRTY_THREE] & D_CAN_NODE_67_DTCM_MASK) >> D_CAN_NODE_67_DTCM_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode95itcm_uint8 = (data[e_THIRTY_SIX] & D_CAN_NODE_95_ITCM_MASK) >> D_CAN_NODE_95_ITCM_SHIFT;
    /* write Driver_Side configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->StopandStart = (data[e_FIFTY_SEVEN] & D_STOP_AND_START_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->DriverSide = (data[e_FIFTY_SEVEN] & D_DRIVER_SIDE_MASK) >> D_DRIVER_SIDE_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16 = (uint16)(((data[e_SIXTY_THREE]<< (uint8)e_EIGHT) |data[e_SIXTY_FOUR]));
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Rearviewcamera = (data[e_EIGHTY_FIVE] & D_REAR_VIEW_CAMERA_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Parkwithstop = (data[e_EIGHTY_FIVE] & D_PARK_WITH_STOP_MASK) >> D_PARK_WITH_STOP_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->SideDistanceWarning = (data[e_EIGHTY_FIVE] & D_SIDE_DISTANCE_WARNING_MASK) >> D_SIDE_DISTANCE_WARNING_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Drivetypevariant = (data[e_NINETY] & D_DRIVE_TYPE_VARIANT_MASK) >> D_DRIVE_TYPE_VARIANT_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset = (data[e_ONE_THREE] & D_PAM_TUNING_SET_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Semiautopark = (data[e_ONE_THREE] & D_SEMI_AUTOMATIC_PARKING_MASK) >> D_SEMI_AUTOMATIC_PARKING_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Srt = (data[e_ONE_TEN] & D_SRT_MASK) >> D_SRT_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Hybridtype  = (data[e_ONE_FORTY] & D_HYBRID_TYPE_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Pulloutcontrol = (data[e_ONE_FORTY_NINE] & D_PULL_OUT_CONTROL_MASK) >> D_PULL_OUT_CONTROL_SHIFT;
    /* write WheelBase configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Wheelbase = (data[e_SEVENTY] & D_WHEELBASE_DEFINITION_MASK) >> D_WHEELBASE_DEFINITION_SHIFT;
    /* write SteeringRatio configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->SteeringRatio_uint8 = (data[e_EIGHTY_SEVEN] & D_STEERING_RATIO_RACK_TYPE_MASK);
    /* write GearBoxType configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Gearboxtype = (data[e_ONE_HUNDRED] & D_GEAR_BOX_TYPE_MASK);

    /* write VehicleLineConfig configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->VehicleLineConfiguration_uint8 = data[e_ONE_FOUR];
    /* write Country_Code configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->CountryCode_uint8 = data[e_ONE_SIX];
    /* write PAMConfig configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->PAMConfig_uint8 = (data[e_ONE_SEVENTEEN] & D_PAM_CONFIGURATION_MASK) >> D_PAM_CONFIGURATION_SHIFT;

    /* write ModelYear configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->ModelYear_uint8 = data[e_ONE_TWENTY_FOUR];
    /* write Surround_View_Camera configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera = (data[e_ONE_SEVENTY_SIX] & D_SURROUND_VIEW_CAMERA_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Forwardfacingcamera = (data[e_ONE_SEVENTY_SIX] & D_FORWARD_FACING_CAMERA_MASK) >> D_FORWARD_FACING_CAMERA_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Autonomylevel = (data[e_ONE_SEVENTY_SIX] & D_AUTONOMY_LEVEL_MASK) >> D_AUTONOMY_LEVEL_SHIFT;

    Rte_Pim_ProxiConfigTable_MirrorBlock()->Fullautomaticparking = (data[e_ONE_SEVENTY_SIX] & D_FULL_AUTOMATIC_PARKING_MASK) >> D_FULL_AUTOMATIC_PARKING_SHIFT;
    /* write Mirrors Type configuration to NVM */
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Mirrortype = (data[e_TWO_HUNDRED_TWO] & D_MIRRORS_TYPE_MASK) >> D_MIRRORS_TYPE_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Radiodisplay = (data[e_ONE_EIGHTY_FOUR] & D_RADIO_DISPLAY_MASK);
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Auxiliarycamera = (data[e_TWO_TEN] & D_AUXILIARY_CAMERA_MASK) >> D_AUXILIARY_CAMERA_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerreverseguide = (data[e_TWO_TEN] & D_TRAILER_REVERSE_GUIDENCE_MASK) >> D_TRAILER_REVERSE_GUIDENCE_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailersurround = (data[e_TWO_TEN] & D_TRAILER_SURROUND_MASK) >> D_TRAILER_SURROUND_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerreversesteering = (data[e_TWO_TEN] & D_TRAILER_REVERSE_STEERING_MASK) >> D_TRAILER_REVERSE_STEERING_SHIFT;
    Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerhitchassist = (data[e_TWO_TWELEVE] & D_TRAILER_HITCH_ASSIST_MASK) >> D_TRAILER_HITCH_ASSIST_SHIFT;



  }
  else
  {
    /* Do Nothing this condition should never be satisfied*/
  }
}
  /* ===========================================================================
*
*   Name:          F_aProxiM_f_incrementproxiwritecounter_v
*
*   Function:      This function is called after successful PROXI write operation
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(void, SWC_ProxiMgr_CODE)static F_aProxiM_f_incrementproxiwritecounter_v(void)
{
  /* DD-ID: {08F2F81E-5F85-44a1-B6BC-830B5EAE54A0}*/
	/*GUID:-{08F2F81E-5F85-44a1-B6BC-830B5EAE54A0}*/
  if (Rte_Pim_ProxiConfigTable_MirrorBlock()->PROXIWriteCounter < D_ALL_SET)
  {
    Rte_Pim_ProxiConfigTable_MirrorBlock()->PROXIWriteCounter++;
  }
  else
  {
    Rte_Pim_ProxiConfigTable_MirrorBlock()->PROXIWriteCounter= D_ALL_SET;
  }
}
/* ===========================================================================
*
*   Name:          F_aProxiM_f_CheckReceivedProxiDataIntgrity
*
*   Function:      This function is called to check integrity of Proxi Data 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(void, SWC_ProxiMgr_CODE)static F_aProxiM_f_CheckReceivedProxiDataIntgrity(uint8* Rxbuffer,uint16 i_length_u16)
{
  /* DD-ID: {53226376-2569-48e4-81E6-A9BA4D2B87A8}*/
  /*ReqID:- 15799991,15799971,15799978,15800045,15799958,15799946*/
  /*GUID:-{53226376-2569-48e4-81E6-A9BA4D2B87A8}*/
  uint8 v_u8incr_u8 = (uint8)e_ZERO;
  uint8 v_monthvalue_u8 = (uint8)e_ZERO;
  uint8 v_dayvalue_u8 = (uint8)e_ZERO;
  uint8 v_iSCRCMatch_u8 = (uint8)e_ZERO;
  /*
    ** Verify we have received at least the minimum number of expected bytes.
    ** The minimum number we need to get is defined as the largest index
    ** containing data that we store per the table in the PROXI sheet. If that
    ** is OK, then check rest of parameters and parameter validity.
    ** Currently largest index is 213 for Mirrors_Type (byte 203 in Proxi_sheet)
  */
  if (i_length_u16 < (uint16)D_MINIMUM_PROXI_FILE_DATA_SIZE)
  {
    F_aProxiM_f_PROXIWriteErrorLog_v(D_kDescNrcInvalidFormat, (D_MINIMUM_PROXI_FILE_DATA_SIZE + (uint8)e_ONE), D_ALL_SET);
  }
  else
  {
    /* Configuration Code Check characters supported in this string is from 30 to 39 Hex*/
    for (v_u8incr_u8 = (uint8)e_ZERO; v_u8incr_u8 < (uint8)e_ELEVEN; v_u8incr_u8++)
    {
      if ((Rxbuffer[v_u8incr_u8] >= D_ASCII0) && (D_ASCII9 >= Rxbuffer[v_u8incr_u8]))
      {
        /*Do Nothing*/
      }
      else
      {
        F_aProxiM_f_PROXIWriteErrorLog_v(D_kDescNrcInvalidFormat, (v_u8incr_u8 + (uint8)e_ONE), D_ALL_SET);
      }
    } 
    v_monthvalue_u8 = ((Rxbuffer[e_TWENTY_THREE] >> (uint8)e_FOUR) * (uint8)e_TEN) + (Rxbuffer[e_TWENTY_THREE] & D_HEX_15);
    v_dayvalue_u8 = ((Rxbuffer[e_TWENTY_FOUR] >> (uint8)e_FOUR)  * (uint8)e_TEN)+ (Rxbuffer[e_TWENTY_FOUR] & D_HEX_15);

    if ((v_monthvalue_u8 < (uint8)e_ONE) || (v_monthvalue_u8 > (uint8)e_TWELVE))
    {
      F_aProxiM_f_PROXIWriteErrorLog_v(D_kDescNrcInvalidFormat, (uint8)e_TWENTY_FOUR, D_ALL_SET);
    }
    if ((v_dayvalue_u8 < (uint8)e_ONE) || (v_dayvalue_u8 > (uint8)e_THIRTY_TWO))
    {
      F_aProxiM_f_PROXIWriteErrorLog_v(D_kDescNrcInvalidFormat, (uint8)e_TWENTY_FIVE, D_ALL_SET);
    }  
    /* CRC Check */
    v_iSCRCMatch_u8 = F_aProxiM_F_CRCPROXI(&Rxbuffer[e_ZERO], (uint32)(i_length_u16));
    if(v_iSCRCMatch_u8 == FALSE)
    {
      F_aProxiM_f_PROXIWriteErrorLog_v(D_kDescNrcRequestOutOfRange,(uint8)e_SEVEN, D_ALL_SET);
    }
  }
}
/* ===========================================================================
*
*   Name:         crc_proxi
*
*   Function:     This function computes the CRC for the PROXI data bytes
*                 provided.
*
*
*   Inputs:       uint8_t const PROXI_message[] - message
*                 uint32 nBytes - number of bytes in PROXI_message
*
*   Outputs:      uint16 - actual crc value
*
*   Side Effects: None
*
*   Remarks:      None
*
* ========================================================================= */
FUNC(uint8, SWC_ProxiMgr_CODE)static F_aProxiM_F_CRCPROXI(const uint8 PROXI_message[], uint32 i_nBytes_u32)
{
  /* DD-ID: {84216951-F393-45c0-B8D2-BCE2A79C4FBF}*/
	/*GUID:-{7BBC8963-A428-4336-A09A-162BBE16DE94}*/
  uint8 v_data_v_u8 = (uint8)e_ZERO;
  Std_ReturnType v_retvalue_u8 = TRUE;
  uint16 v_calculated_crc_u8 = D_INITIAL_VALUE;
  uint16 v_byte_index_u8 = (uint8)e_ZERO;
  uint16 v_PROXI_CRC_String_u8 = (uint8)e_ZERO;
   static uint16 V_Table_CRC_16_CCITT_au16[e_TWO_FIFTY_SIX] =                           
{
0x0000U, 0x1189U, 0x2312U, 0x329bU, 0x4624U, 0x57adU, 0x6536U, 0x74bfU,
0x8c48U, 0x9dc1U, 0xaf5aU, 0xbed3U, 0xca6cU, 0xdbe5U, 0xe97eU, 0xf8f7U,
0x1081U, 0x0108U, 0x3393U, 0x221aU, 0x56a5U, 0x472cU, 0x75b7U, 0x643eU,
0x9cc9U, 0x8d40U, 0xbfdbU, 0xae52U, 0xdaedU, 0xcb64U, 0xf9ffU, 0xe876U,
0x2102U, 0x308bU, 0x0210U, 0x1399U, 0x6726U, 0x76afU, 0x4434U, 0x55bdU,
0xad4aU, 0xbcc3U, 0x8e58U, 0x9fd1U, 0xeb6eU, 0xfae7U, 0xc87cU, 0xd9f5U,
0x3183U, 0x200aU, 0x1291U, 0x0318U, 0x77a7U, 0x662eU, 0x54b5U, 0x453cU,
0xbdcbU, 0xac42U, 0x9ed9U, 0x8f50U, 0xfbefU, 0xea66U, 0xd8fdU, 0xc974U,
0x4204U, 0x538dU, 0x6116U, 0x709fU, 0x0420U, 0x15a9U, 0x2732U, 0x36bbU,
0xce4cU, 0xdfc5U, 0xed5eU, 0xfcd7U, 0x8868U, 0x99e1U, 0xab7aU, 0xbaf3U,
0x5285U, 0x430cU, 0x7197U, 0x601eU, 0x14a1U, 0x0528U, 0x37b3U, 0x263aU,
0xdecdU, 0xcf44U, 0xfddfU, 0xec56U, 0x98e9U, 0x8960U, 0xbbfbU, 0xaa72U,
0x6306U, 0x728fU, 0x4014U, 0x519dU, 0x2522U, 0x34abU, 0x0630U, 0x17b9U,
0xef4eU, 0xfec7U, 0xcc5cU, 0xddd5U, 0xa96aU, 0xb8e3U, 0x8a78U, 0x9bf1U,
0x7387U, 0x620eU, 0x5095U, 0x411cU, 0x35a3U, 0x242aU, 0x16b1U, 0x0738U,
0xffcfU, 0xee46U, 0xdcddU, 0xcd54U, 0xb9ebU, 0xa862U, 0x9af9U, 0x8b70U,
0x8408U, 0x9581U, 0xa71aU, 0xb693U, 0xc22cU, 0xd3a5U, 0xe13eU, 0xf0b7U,
0x0840U, 0x19c9U, 0x2b52U, 0x3adbU, 0x4e64U, 0x5fedU, 0x6d76U, 0x7cffU,
0x9489U, 0x8500U, 0xb79bU, 0xa612U, 0xd2adU, 0xc324U, 0xf1bfU, 0xe036U,
0x18c1U, 0x0948U, 0x3bd3U, 0x2a5aU, 0x5ee5U, 0x4f6cU, 0x7df7U, 0x6c7eU,
0xa50aU, 0xb483U, 0x8618U, 0x9791U, 0xe32eU, 0xf2a7U, 0xc03cU, 0xd1b5U,
0x2942U, 0x38cbU, 0x0a50U, 0x1bd9U, 0x6f66U, 0x7eefU, 0x4c74U, 0x5dfdU,
0xb58bU, 0xa402U, 0x9699U, 0x8710U, 0xf3afU, 0xe226U, 0xd0bdU, 0xc134U,
0x39c3U, 0x284aU, 0x1ad1U, 0x0b58U, 0x7fe7U, 0x6e6eU, 0x5cf5U, 0x4d7cU,
0xc60cU, 0xd785U, 0xe51eU, 0xf497U, 0x8028U, 0x91a1U, 0xa33aU, 0xb2b3U,
0x4a44U, 0x5bcdU, 0x6956U, 0x78dfU, 0x0c60U, 0x1de9U, 0x2f72U, 0x3efbU,
0xd68dU, 0xc704U, 0xf59fU, 0xe416U, 0x90a9U, 0x8120U, 0xb3bbU, 0xa232U,
0x5ac5U, 0x4b4cU, 0x79d7U, 0x685eU, 0x1ce1U, 0x0d68U, 0x3ff3U, 0x2e7aU,
0xe70eU, 0xf687U, 0xc41cU, 0xd595U, 0xa12aU, 0xb0a3U, 0x8238U, 0x93b1U,
0x6b46U, 0x7acfU, 0x4854U, 0x59ddU, 0x2d62U, 0x3cebU, 0x0e70U, 0x1ff9U,
0xf78fU, 0xe606U, 0xd49dU, 0xc514U, 0xb1abU, 0xa022U, 0x92b9U, 0x8330U,
0x7bc7U, 0x6a4eU, 0x58d5U, 0x495cU, 0x3de3U, 0x2c6aU, 0x1ef1U, 0x0f78U
};
  /*
  ** Divide the PROXI_message by the polynomial, one byte at a time.
  */
  if (NULL_PTR != PROXI_message)
  {
    for (v_byte_index_u8 = (uint8)e_TWENTY_FIVE; v_byte_index_u8 < i_nBytes_u32; v_byte_index_u8++)
    {
      v_data_v_u8 = (uint8)(PROXI_message[v_byte_index_u8] ^ (v_calculated_crc_u8 & D_ALL_SET));
      v_calculated_crc_u8 = (V_Table_CRC_16_CCITT_au16[v_data_v_u8] ^ (v_calculated_crc_u8 >> (uint8)e_EIGHT));
    }
    v_PROXI_CRC_String_u8 = F_aProxiM_f_GetCRCFromString_uint16(&PROXI_message[(uint8)e_SIX]);
    /*  The final v_calculated_crc_u8 is the CRC.*/
    if (v_calculated_crc_u8 != v_PROXI_CRC_String_u8)
    {
      v_retvalue_u8 = FALSE;
    }
    else
    {
      v_retvalue_u8 = TRUE;
    }
  }
  else
  {
    /* Do Nothing this condition should never be satisfied*/
  }
  return v_retvalue_u8;
}
/* ===========================================================================
*
*   Name:          F_ProxiMgr_ErrorChk
*
*   Function:      This function is called to check the errors of PROXI if present any 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(void, SWC_ProxiMgr_CODE)static F_ProxiMgr_ErrorChk()
{
  /* DD-ID: {CB15EF77-2913-4e8d-BB8E-D8B9CF282E47}*/
/*GUID:-*/
  uint8 V_Error_value_u8 = (uint8)e_ZERO;
  V_Error_value_u8 = (Rte_Pim_ProxiConfigTable_MirrorBlock()->SteeringRatio_uint8 <= (uint8)e_TWO) ? ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_ZERO]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_Steering_RackPinion_Ratio_Incorr,(uint32)V_Error_value_u8,NULL_PTR);

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16 >= THOUSAND_FOUR_FOURTY) && (Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16 <= THREE_THOUSAND_FOURTY_SIX)) ? ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_ONE]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_Tyre_Size_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset > (uint8)e_ZERO) && (Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset <= (uint8)e_FIVE)) ? ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_TWO]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_PAM_TunSet_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = (Rte_Pim_ProxiConfigTable_MirrorBlock()->VehicleLineConfiguration_uint8 != (uint8)e_ONE_TWENTY_FOUR) ?  ErrorMgr_ErrorActive :ErrorMgr_ErrorInactive ;
  V_ProxiError_Array_au8[e_THREE]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_VehiLineConf_Incorr,(uint32)V_Error_value_u8,NULL_PTR);

  V_Error_value_u8 = (Rte_Pim_ProxiConfigTable_MirrorBlock()->Wheelbase <= (uint8)e_TWO) ?  ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_FOUR]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_WB_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Radiodisplay == (uint8)e_TWO) || (Rte_Pim_ProxiConfigTable_MirrorBlock()->Radiodisplay == (uint8)e_SEVEN)|| (Rte_Pim_ProxiConfigTable_MirrorBlock()->Radiodisplay == (uint8)e_NINE)) ?  ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_FIVE]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_Radio_Display_Type_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

 #if D_NEW_PROXICHANGE 
 /* Currently removed from requirement */
  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Autonomylevel >= (uint8)e_ZERO) && (Rte_Pim_ProxiConfigTable_MirrorBlock()->Autonomylevel < (uint8)e_THREE)) ? ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_SIX]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_PROXI_Autonomy_Level_Incorr,(uint32)V_Error_value_u8, NULL_PTR);
#endif

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Gearboxtype == (uint8)e_ONE)) ? ErrorMgr_ErrorActive : ErrorMgr_ErrorInactive;
  V_ProxiError_Array_au8[e_SIX]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_GearBox_Type_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = (Rte_Pim_ProxiConfigTable_MirrorBlock()->PAMConfig_uint8 != (uint8)e_ONE)? ErrorMgr_ErrorActive : ErrorMgr_ErrorInactive;
  V_ProxiError_Array_au8[e_SEVEN]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Fault_PAM_Config_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode95itcm_uint8 == (uint8)e_ONE) && (Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode63ttm_uint8 == (uint8)e_ONE))? ErrorMgr_ErrorActive : ErrorMgr_ErrorInactive;
  V_ProxiError_Array_au8[e_EIGHT]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_CAN_Node_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

 #if D_NEW_PROXICHANGE 
 /* Currently removed from requirement */
  V_Error_value_u8 = (Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera <= (uint8)e_ONE)? ErrorMgr_ErrorInactive : ErrorMgr_ErrorActive;
  V_ProxiError_Array_au8[e_ELEVEN]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM(ErrorMgr_Error_PROXI_SVS_NotPresent_Fault,(uint32)V_Error_value_u8, NULL_PTR);
#endif


  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->ModelYear_uint8 < (uint8)e_TWENTY_FIVE))? ErrorMgr_ErrorActive: ErrorMgr_ErrorInactive;
  V_ProxiError_Array_au8[e_NINE]=V_Error_value_u8;
  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_Model_Year_Incorr,(uint32)V_Error_value_u8, NULL_PTR);

  V_Error_value_u8 = ((Rte_Pim_ProxiConfigTable_MirrorBlock()->Fullautomaticparking == (uint8)e_ONE)&&(Rte_Pim_ProxiConfigTable_MirrorBlock()->Semiautopark == (uint8)e_ONE))?  ErrorMgr_ErrorActive : ErrorMgr_ErrorInactive;
  V_ProxiError_Array_au8[e_TEN]=V_Error_value_u8;

	  /* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
	if( (uint8)e_ONE == Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera)
	{
	  (void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_AutoPark_Sys_Incorr,(uint32)V_Error_value_u8, NULL_PTR);
	}
	else
	{
		(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_Error_PROXI_AutoPark_Sys_Incorr,(uint32)ErrorMgr_ErrorInactive, NULL_PTR);
	}
}
/* ===========================================================================
*
*   Name:          F_UpdateIpcStruct
*
*   Function:      This function is called to verify the IPC structure variables 
                    from Proxi 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
 FUNC(void, SWC_ProxiMgr_CODE)static F_UpdateIpcStruct(void)
{
  /* DD-ID: {944EB3A7-C71A-4a38-A739-74DD84BBAA43}*/
  uint8 v_varientID_u8;
  ProxiToIpc_s.PRX_bValid_b = TRUE; 
  ProxiToIpc_s.PRX_TrlrHitchAssPres_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerhitchassist;
  ProxiToIpc_s.PRX_CanNod63_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode63ttm_uint8;
  ProxiToIpc_s.PRX_CanNod67_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode67dtcm_uint8;
  ProxiToIpc_s.PRX_CanNod95_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode95itcm_uint8;  
  ProxiToIpc_s.PRX_CanNod14_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode14trscm_uint8;
  ProxiToIpc_s.PRX_CanNod27_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->CanNode27Asm_uint8;
  ProxiToIpc_s.PRX_SRT_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Srt;
  ProxiToIpc_s.PRX_TyreSz_u16 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16;
  ProxiToIpc_s.PRX_VehTyreSize_f32 = (float32)Rte_Pim_ProxiConfigTable_MirrorBlock()->Tyresize_uint16;
  ProxiToIpc_s.PRX_VehLineCfg_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->VehicleLineConfiguration_uint8;
  ProxiToIpc_s.PRX_Wheelbase_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Wheelbase;
  ProxiToIpc_s.PRX_RadioDispTyp_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Radiodisplay;
  ProxiToIpc_s.PRX_StopNStrt_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->StopandStart;
  ProxiToIpc_s.PRX_DrvSide_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->DriverSide;
  ProxiToIpc_s.PRX_ParkWithStop_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Parkwithstop;
  ProxiToIpc_s.PRX_FrwFacingCam_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Forwardfacingcamera;
  ProxiToIpc_s.PRX_AutonomyLvl_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Autonomylevel;
  ProxiToIpc_s.PRX_ModelYear_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->ModelYear_uint8;
  ProxiToIpc_s.PRX_HybTyp_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Hybridtype;
  ProxiToIpc_s.PRX_CountryCode_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->CountryCode_uint8;
  ProxiToIpc_s.PRX_PullOutCtrlPres_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Pulloutcontrol;
  ProxiToIpc_s.PRX_FullAutoPrkgSys_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Fullautomaticparking;
  ProxiToIpc_s.PRX_MirrorType_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Mirrortype;
  ProxiToIpc_s.PRX_SurroundViewCamera_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Surroundviewcamera;
  ProxiToIpc_s.PRX_RvcEnbl_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Rearviewcamera;
  ProxiToIpc_s.PRX_VehLineCfg_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->VehicleLineConfiguration_uint8;
  ProxiToIpc_s.PRX_AuxTrlrCam_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Auxiliarycamera;
  ProxiToIpc_s.PRX_DrvTypVrnt_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Drivetypevariant;
  ProxiToIpc_s.PRX_GbTyp_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Gearboxtype;
  ProxiToIpc_s.PRX_PAMTunSet_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset;
  ProxiToIpc_s.PRX_StrRatRckPinionTyp_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->SteeringRatio_uint8;
  ProxiToIpc_s.PRX_SemiAutoPrkgSys_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Semiautopark;
  ProxiToIpc_s.PRX_PAMCfg_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->PAMConfig_uint8;
  ProxiToIpc_s.PRX_TrlrSurroundPresence_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailersurround;
  ProxiToIpc_s.PRX_TRGPresence_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerreverseguide;
  ProxiToIpc_s.PRX_TRSCPresence_b = Rte_Pim_ProxiConfigTable_MirrorBlock()->Trailerreversesteering;
/* _GB_ : Not available at mcu1_0 Proxi, Set with Zero vaules*/
  ProxiToIpc_s.PRX_ParksensePres_b = FALSE;
  ProxiToIpc_s.PRX_ParkSenseCamView_b = FALSE;
  ProxiToIpc_s.PRX_CvadasEthernet_b = FALSE;
  ProxiToIpc_s.PRX_CanNode29_b = FALSE;
  ProxiToIpc_s.PRX_TcaseType_u8 = (uint8)e_ZERO;
  ProxiToIpc_s.PRX_SpecialPckgVP_u8 = (uint8)e_ZERO;
  ProxiToIpc_s.PRX_variantID_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Variant_ID;
  v_varientID_u8 = Rte_Pim_ProxiConfigTable_MirrorBlock()->Variant_ID;
  (void)Rte_Write_PpVariantData_Variant(v_varientID_u8);
}
/* ===========================================================================
*
*   Name:          F_camera_variant
*
*   Function:      This function is called to check Vehicle camera variant 
*
*   Inputs:        None
*
*   Outputs:       None
*
*   Side Effects:  None
*
*   Remarks:       None
*
* ========================================================================= */
FUNC(uint8, SWC_ProxiMgr_CODE)F_camera_variant(void)
{
  /* DD-ID: {172884F6-EF7D-4782-A3B1-8C64DA68F45A}*/
  uint8 incr = (uint8)e_ZERO;
  uint8 jump = (uint8)e_ZERO;
  uint8 ret_value = D_ALL_SET;
  
  uint8 Array_StdType_Var[D_TOTAL_VAR_STD_TYPE][D_TOTAL_PROXI_PARAM] = {
    /*Steering Rack Ratio, Wheelbase, Pamtuningset, Vehicle Variant */
                                     {0x1u,0x0u,0x5u,1u},            
                                     {0x1u,0x1u,0x5u,2u},
                                     {0x2u,0x2u,0x5u,3u},
                                     {0x0u,0x1u,0x2u,4u},
                                     {0x1u,0x1u,0x1u,6u},
                                     {0x2u,0x2u,0x1u,7u},
                                     {0x2u,0x1u,0x3u,10u},
                                     {0x1u,0x0u,0x1u,12u},
                                     {0x1u,0x1u,0x4u,14u},
                                     {0x0u,0x1u,0x1u,19u},
                                     {0x1u,0x1u,0x2u,20u}           /*Buzz model variant*/
                                    };
  uint8 Array_NonStdType_Var[D_TOTAL_VAR_NON_STD_TYPE][D_TOTAL_PROXI_PARAM] = {
    /*Steering Rack Ratio, Wheelbase, Pamtuningset, Vehicle Variant */
                                    {0x0u,0x1u,0x2u,5u},           
                                    {0x1u,0x1u,0x1u,8u},
                                    {0x2u,0x2u,0x1u,9u},
                                    {0x2u,0x1u,0x3u,11u},
                                    {0x1u,0x0u,0x1u,13u},
                                    {0x1u,0x1u,0x4u,15u},
                                    {0x1u,0x0u,0x5u,16u},
                                    {0x1u,0x1u,0x5u,17u},
                                    {0x2u,0x2u,0x5u,18u},
                                    {0x0u,0x1u,0x1u,19u}
                                   };

  if(Rte_Pim_ProxiConfigTable_MirrorBlock()->Mirrortype < 3u)
  {
    for(incr = (uint8)e_ZERO;incr < (uint8)D_TOTAL_VAR_STD_TYPE;incr++)
    {
      jump=(uint8)e_ZERO;
      if((Array_StdType_Var[incr][jump] == Rte_Pim_ProxiConfigTable_MirrorBlock()->SteeringRatio_uint8)&&(Array_StdType_Var[incr][e_ONE] == Rte_Pim_ProxiConfigTable_MirrorBlock()->Wheelbase)&&(Array_StdType_Var[incr][e_TWO] == Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset))
      {
        ret_value = Array_StdType_Var[incr][e_THREE];
      }
    }
  }
  else
  {
    for(incr = (uint8)e_ZERO;incr < (uint8)D_TOTAL_VAR_NON_STD_TYPE;incr++)
    {
      jump=(uint8)e_ZERO;
      if((Array_NonStdType_Var[incr][jump] == Rte_Pim_ProxiConfigTable_MirrorBlock()->SteeringRatio_uint8)&&(Array_NonStdType_Var[incr][e_ONE] == Rte_Pim_ProxiConfigTable_MirrorBlock()->Wheelbase)&&(Array_NonStdType_Var[incr][e_TWO] == Rte_Pim_ProxiConfigTable_MirrorBlock()->Pamtuningset))
      {
        ret_value = Array_NonStdType_Var[incr][e_THREE];
      }
    }
  }
  return ret_value;
}

static void F_SendDataToRemoteCore(void)
{
  /* DD-ID: {ABE32F1A-5ECD-4180-B513-12272A9C9348}*/
  SSM_2_0_CoreStatus SSM_2_0_data;
  SSM_2_1_CoreStatus SSM_2_1_data;
  SSM_QNX_CoreStatus SSM_QNX_data;

  /*Read MCU 2_0 status*/
  (void)Rte_Read_R_SSM_2_State_State_2_0(&SSM_2_0_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_0_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MCU2_0_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t, (uint16)sizeof(ME_ProxiToMCU2_0_Def_t));
    v_RemoteCoreStatus_u8 |= MCU2_0_STATE;   /*Update core Status Flag once data is transmited*/
    #ifdef Enable_Printf
    appLogPrintf("\n Sent Proxi Data to MCU2_0 core");
    #endif
  }

  /*Read MCU 2_1 status*/
  (void)Rte_Read_R_SSM_2_State_State_2_1(&SSM_2_1_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_2_1_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MCU2_1_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t, (uint16)sizeof(ME_ProxiToMCU2_1_Def_t));
    v_RemoteCoreStatus_u8 |= MCU2_1_STATE;   /*Update core Status Flag once data is transmited*/
   #ifdef Enable_Printf
    appLogPrintf("\n Sent Proxi Data to MCU2_1 core");
   #endif
  }

#if ToEnableSSM
  /*Read Qnx status*/
  (void)Rte_Read_R_SSM_QNXState_State_QNX(&SSM_QNX_data);
  if ((SSM_SlaveCore_State_BSP_Init_Done <= SSM_QNX_data.CoreStatus) && ((v_RemoteCoreStatus_u8 & MPU1_0_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t, (uint16)sizeof(ME_ProxiToMPU1_0_Def_t));
    v_RemoteCoreStatus_u8 |= MPU1_0_STATE;   /*Update core Status Flag once data is transmited*/
  }
#endif
  /*Read Qnx status*/
  (void)Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(&ME_Proxi_MPU1_0_to_MCU1_0_data);
  if (((ME_Proxi_MPU1_0_to_MCU1_0_data.state == QNX_BOOTUP_STATE) || (ME_Proxi_MPU1_0_to_MCU1_0_data.state == QNX_ETFS_NOT_READY_STATE)) && ((v_RemoteCoreStatus_u8 & MPU1_0_STATE) == FALSE))
  {
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&ProxiToIpc_s, (uint16)e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t, (uint16)sizeof(ME_ProxiToMPU1_0_Def_t));
    v_RemoteCoreStatus_u8 |= MPU1_0_STATE;   /*Update core Status Flag once data is transmited*/
    #ifdef Enable_Printf
    appLogPrintf("\n Welcome to AUTOSAR!! Sent Proxi.. ");
    #endif
  }

}

#define SWC_ProxiConfigMgr_STOP_SEC_CODE
#include "SWC_ProxiConfigMgr_MemMap.h" 

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
