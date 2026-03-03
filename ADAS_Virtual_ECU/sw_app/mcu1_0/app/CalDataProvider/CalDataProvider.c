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
 *             File:  CalDataProvider.c
 *           Config:  C:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  CalDataProvider
 *  Generation Time:  2025-07-18 11:32:22
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <CalDataProvider>
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
 * BswM_CalDataProSCCalStatus
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
 * TotalOdometer
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
 * char_T
 *   sint8 represents integers with a minimum value of -128 and a maximum value of 127.
 *      The order-relation on sint8 is: x < y if y - x is positive.
 *      sint8 has a lexical representation consisting of an optional sign followed 
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is 
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, 12678, +10000.
 *
 *
 * Runnable Entities:
 * ==================
 * RE_Periodic_CalDataProvider
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_CalDataProvider.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalDataProvider.h"
#include "vstdlib.h"
#include "NvM.h"
#include "SSM_BSW_Interface.h"
#include "Enums.h"
#include "ErrorManagerDef.h"
#include "Trusted_Func_Api.h"

#define D_ODOMETER_SCALING_FACTOR 16u
#define D_COUNTER_VAL 450U
#define D_COUNTER100ms_VAL 10U
#define D_NUM_OF_CAMERAS 4U
#define D_REAR_CAMERA_ID 2U
#define D_RETRY_NV_WRITING_CNT 3U
#define TIMER_5_SEC_COUNT  500U
#define ENFORCED_CALIBRATION_SC 1u
#define REAR_CAMERA_CALIBRATION_SC 5u

typedef struct
{
	FinalAssemblySerialNumber_t *NvMRamMirrorBlock_copy;
	FinalAssemblySerialNumber_t *NvMRamMirror;
	NvM_BlockIdType BlockId;
	ErrorMgr_enErrorNo ErrorEnum;
	uint8 retryCounter_u8;
	boolean CamIntrNvBlockTriggered_b;
	boolean CamIntrNvBlockProcessed_b;
	boolean PerformRetry_b;
} CalIntrinsicData_ConfigType;

typedef struct
{
	FinalAssemblySerialNumber_t CamSerialNumber;
	uint8 IsNvReadBlockTriggered;
	uint8 IsNvReadBlockProcessed;
	NvM_RequestResultType BlockStatus;
} CamReadNvBlock_t;

static void f_CamIntrinsicNumCheck_v(void);



/*Below variables shouldnt be included as safe*/
__attribute__ ((section("QMRAM"))) VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
__attribute__ ((section("QMRAM"))) VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */



#define CalDataProvider_START_SEC_VAR_INIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"

static boolean s_CalibDIDTriggered_b = FALSE;

#define CalDataProvider_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CalDataProvider_MemMap.h"

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
 * BswM_CalDataProSCCalStatus: Integer in interval [0...255]
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
 * DeltaTimestamp_IMUdata: Integer in interval [0...255]
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
 * ME_Hydra3defs_E_CalibStatus_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CalibrationID_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CameraID_t: Integer in interval [0...4294967295]
 * NvM_RequestResultType: Integer in interval [0...255]
 * OperationalModeSts: Integer in interval [0...15]
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
 * RHF_FastPulseCounter: Integer in interval [0...255]
 * RHF_Spin: Integer in interval [0...3]
 * RHR_FastPulseCounter: Integer in interval [0...255]
 * RHR_Spin: Integer in interval [0...3]
 * RemStActvSts: Integer in interval [0...1]
 * Rte_DT_CamNvmReadSts_0: Integer in interval [0...255]
 * Rte_DT_CamNvmReadSts_1: Integer in interval [0...255]
 * Rte_DT_CamNvmReadSts_2: Integer in interval [0...255]
 * Rte_DT_CamNvmReadSts_3: Integer in interval [0...255]
 * Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1: Integer in interval [0...4294967295]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * TRSC_CenterBtn_Sts: Integer in interval [0...3]
 * TRSC_EnableBtn_Sts: Integer in interval [0...3]
 * TRSC_RawKnob: Integer in interval [0...511]
 * TotalOdometer: Integer in interval [0...1048575]
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
 * WakeupSource_FD02_SGW: Integer in interval [0...255]
 * WakeupSource_FD02_TRLR_REV: Integer in interval [0...255]
 * WakeupSource_FD03_BCM: Integer in interval [0...255]
 * WakeupSource_FD03_SGW: Integer in interval [0...255]
 * WakeupSource_FD04_BCM: Integer in interval [0...255]
 * WakeupSource_FD08_SGW: Integer in interval [0...255]
 * WakeupSource_FD11_SGW: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * char_T: Integer in interval [-128...127]
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
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
 * CameraEepromData_arr: Array with 4 element(s) of type CameraEepromData_t
 * EOLIterationData_arr: Array with 5 element(s) of type uint8
 * K_Overlap_Thrsld_RAEB_Array: Array with 5 element(s) of type float32
 * Obj_DistTable_Array: Array with 5 element(s) of type float32
 * Reserved_arr: Array with 7 element(s) of type uint8
 * SSM_MCU_1_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * constantStartSequence_ac: Array with 2 element(s) of type char_T
 * eepromMapRevision_au16: Array with 2 element(s) of type uint16
 * finalAssemblyDay_ac: Array with 3 element(s) of type char_T
 * finalAssemblyFocusAndAlign_ac: Array with 1 element(s) of type char_T
 * finalAssemblyPartNumber_ac: Array with 16 element(s) of type char_T
 * finalAssemblySerialNumber_ac: Array with 4 element(s) of type char_T
 * finalAssemblyYear_ac: Array with 2 element(s) of type char_T
 * firstReservedBytes_au8: Array with 56 element(s) of type uint8
 * intrinsicAlgoRevision_ac: Array with 16 element(s) of type char_T
 * keVehParam_e_StrWhlRatioBrkPnts_Array: Array with 19 element(s) of type float32
 * keVehParam_e_VehSteerRatioTable_Array: Array with 19 element(s) of type float32
 * polyImage2World_af32: Array with 6 element(s) of type float32
 * polyWorld2Image_af32: Array with 6 element(s) of type float32
 * productionBoardSerialNumber_ac: Array with 2 element(s) of type char_T
 * productionDay_ac: Array with 3 element(s) of type char_T
 * productionLineNumber_ac: Array with 2 element(s) of type char_T
 * productionSerialNumber_ac: Array with 5 element(s) of type char_T
 * productionYear_ac: Array with 2 element(s) of type char_T
 * reservedBytesIntrinsic_au8: Array with 32 element(s) of type uint8
 * reservedBytes_au8: Array with 16 element(s) of type uint8
 * secondReservedBytes_au8: Array with 4 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CDP_TbSVS_S_SVSCamCurrentCalibData_t: Record with elements
 *   calibrated of type uint8
 *   data of type TbSVS_S_SVSCamCurrentCalibData_t
 *   PrevOdoValue of type uint16
 * CDP_TbSVS_S_SVSCamEOLCalibData_t: Record with elements
 *   calibrated of type uint8
 *   data of type TbSVS_S_SVSCamEOLCalibData_t
 *   PlantOdoValue of type uint16
 * CDP_TbSVS_S_SVSCamOCCalibData_t: Record with elements
 *   calibrated of type uint8
 *   data of type TbSVS_S_SVSCamOCCalibData_t
 * CDP_TbSVS_S_SVSCamSCCalibData_t: Record with elements
 *   calibrated of type uint8
 *   data of type TbSVS_S_SVSCamSCCalibData_t
 * CalDataProvider_MCU_1_0_Def: Record with elements
 *   CalData_SVSCamCurrentCalibData of type TbSVS_S_SVSCamCurrentCalibData_t
 *   CalData_SVSCamEOLCalibData of type TbSVS_S_SVSCamEOLCalibData_t
 *   CalData_SVSCamOCCalibData of type TbSVS_S_SVSCamOCCalibData_t
 *   CalData_SVSCamSCCalibData of type TbSVS_S_SVSCamSCCalibData_t
 *   FreshnessCount of type uint32
 *   CalData_PlantOdoValue of type uint16
 *   CalData_PrevOdoValue of type uint16
 *   bValid of type boolean
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
 * CamNvmReadSts: Record with elements
 *   FrontCameraNVMStatus of type Rte_DT_CamNvmReadSts_0
 *   LeftCameraNVMStatus of type Rte_DT_CamNvmReadSts_1
 *   RearCameraNVMStatus of type Rte_DT_CamNvmReadSts_2
 *   RightCameraNVMStatus of type Rte_DT_CamNvmReadSts_3
 * CameraEepromData_t: Record with elements
 *   camProductionData_s of type CamEepromProductionData_t
 *   camIntrinsicData_s of type CamEepromIntrinsicData_t
 *   camCrcData_s of type CamEepromCrcData_t
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * FinalAssemblySerialNumber_t: Record with elements
 *   finalAssemblyYear of type finalAssemblyYear_ac
 *   finalAssemblyDay of type finalAssemblyDay_ac
 *   finalAssemblySerialNumber of type finalAssemblySerialNumber_ac
 *   finalAssemblyFocusAndAlign of type finalAssemblyFocusAndAlign_ac
 * IntrinsicCamID: Record with elements
 *   FrontCamera of type FinalAssemblySerialNumber_t
 *   LeftCamera of type FinalAssemblySerialNumber_t
 *   RearCamera of type FinalAssemblySerialNumber_t
 *   RightCamera of type FinalAssemblySerialNumber_t
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
 * ME_Proxi_MPU1_0_to_MCU1_0_t: Record with elements
 *   a72_cpu_load of type float32
 *   state of type Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1
 *   PRX_RadioDispTyp_u8 of type uint8
 *   PRX_variantID_u8 of type uint8
 * MagnaSerialNumber_t: Record with elements
 *   initialCharacter_c of type char_T
 *   productionLineNumber of type productionLineNumber_ac
 *   productionYear of type productionYear_ac
 *   productionDay of type productionDay_ac
 *   productionSerialNumber of type productionSerialNumber_ac
 *   productionBoardSerialNumber of type productionBoardSerialNumber_ac
 *   zeroCharacter_c of type char_T
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
 * Svs_CamEepromDataArray_t: Record with elements
 *   CameraEepromData of type CameraEepromData_arr
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
 * TbSVS_S_SVSCamCalibReset_t: Record with elements
 *   CalibrationID of type ME_Hydra3defs_E_CalibrationID_t
 *   CameraID of type ME_Hydra3defs_E_CameraID_t
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
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   FinalAssemblySerialNumber_t *Rte_Pim_FrontCamSerialNumber_MirrorBlock(void)
 *   FinalAssemblySerialNumber_t *Rte_Pim_LeftCamSerialNumber_MirrorBlock(void)
 *   FinalAssemblySerialNumber_t *Rte_Pim_RearCamSerialNumber_MirrorBlock(void)
 *   FinalAssemblySerialNumber_t *Rte_Pim_RightCamSerialNumber_MirrorBlock(void)
 *   CDP_TbSVS_S_SVSCamCurrentCalibData_t *Rte_Pim_SVSCamCurrentCalibData_MirrorBlock(void)
 *   CDP_TbSVS_S_SVSCamEOLCalibData_t *Rte_Pim_SVSCamEOLCalibData_MirrorBlock(void)
 *   CDP_TbSVS_S_SVSCamOCCalibData_t *Rte_Pim_SVSCamOCCalibData_MirrorBlock(void)
 *   CDP_TbSVS_S_SVSCamSCCalibData_t *Rte_Pim_SVSCamSCCalibData_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   FinalAssemblySerialNumber_t *Rte_CData_FrontCamSerialNumber_DefaultValue(void)
 *   FinalAssemblySerialNumber_t *Rte_CData_LeftCamSerialNumber_DefaultValue(void)
 *   FinalAssemblySerialNumber_t *Rte_CData_RearCamSerialNumber_DefaultValue(void)
 *   FinalAssemblySerialNumber_t *Rte_CData_RightCamSerialNumber_DefaultValue(void)
 *   CDP_TbSVS_S_SVSCamCurrentCalibData_t *Rte_CData_SVSCamCurrentCalibData_DefaultValue(void)
 *   CDP_TbSVS_S_SVSCamEOLCalibData_t *Rte_CData_SVSCamEOLCalibData_DefaultValue(void)
 *   CDP_TbSVS_S_SVSCamOCCalibData_t *Rte_CData_SVSCamOCCalibData_DefaultValue(void)
 *   CDP_TbSVS_S_SVSCamSCCalibData_t *Rte_CData_SVSCamSCCalibData_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define CalDataProvider_START_SEC_CODE
#include "CalDataProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CalDataProvider_CODE) RE_CalDataProvider_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Init
 *********************************************************************************************************************/
  /* DD-ID: {AE0A2E2A-E425-47f7-ACBA-BD34959193B3}*/

  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamEOLCalibData_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamSCCalibData_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamOCCalibData_t));
  
  VStdLib_MemCpy(&Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy,  sizeof(FinalAssemblySerialNumber_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy,  sizeof(FinalAssemblySerialNumber_t));
  VStdLib_MemCpy(&Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));

   CDP_Cal_DataProvider_Init_v();
    (void) SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_CalDataProvider,SSM_APPSTATE_INIT);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Nvm_SVSCamCalibReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <P_CalDataProvider_Nvm_SVSCamCalibReset>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_CalDataProvider_Nvm_SVSCamCalibReset(const TbSVS_S_SVSCamCalibReset_t *v_SVSCamCalibReset)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_SVSCamCalibReset_E_NOT_OK
 *   RTE_E_IF_SVSCamCalibReset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamCalibReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamCalibReset(P2CONST(TbSVS_S_SVSCamCalibReset_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamCalibReset) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamCalibReset (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {2E38D995-CF1D-4b36-A1C7-8F3F8B71C5AC}*/
  switch(v_SVSCamCalibReset->CalibrationID)
  {
    case CalibrationID_EOL:
    switch(v_SVSCamCalibReset->CameraID)
    {
        case CameraID_Front:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data.CamFrontEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamFrontEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.data.CamFrontEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamFrontEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Left:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data.CamLeftEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamLeftEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.data.CamLeftEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamLeftEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Rear:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data.CamRearEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamRearEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.data.CamRearEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamRearEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Right:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data.CamRightEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamRightEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.data.CamRightEOL, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data.CamRightEOL, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_All:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamEOLCalibData_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.data, 
            &Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamEOLCalibData_t));
        break;
        default:
        /* Do nothing */
        break;
    }
    if((v_SVSCamCalibReset->CameraID > ((ME_Hydra3defs_E_CameraID_t)CameraID_None)) && (v_SVSCamCalibReset->CameraID < ((ME_Hydra3defs_E_CameraID_t)CameraID_Invalid)))
    {
        Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.calibrated = FALSE;
        Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy.calibrated = FALSE;
        (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamEOLCalibData, TRUE);
        CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
        CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    }
    else
    {
      /*do nothing*/
    }
    break;
    case CalibrationID_SC:
    switch(v_SVSCamCalibReset->CameraID)
    {
        case CameraID_Front:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data.CamFrontSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamFrontSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.data.CamFrontSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamFrontSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Left:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data.CamLeftSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamLeftSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.data.CamLeftSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamLeftSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Rear:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data.CamRearSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamRearSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.data.CamRearSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamRearSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Right:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data.CamRightSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamRightSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.data.CamRightSC, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data.CamRightSC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_All:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data,
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamSCCalibData_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.data, 
            &Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamSCCalibData_t));
        break;
        default:
        /* Do nothing */
        break;
    }

    if((v_SVSCamCalibReset->CameraID > ((ME_Hydra3defs_E_CameraID_t) CameraID_None)) && (v_SVSCamCalibReset->CameraID < ((ME_Hydra3defs_E_CameraID_t)CameraID_Invalid)))
    {
        Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.calibrated = FALSE;
        Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy.calibrated = FALSE;
        (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamSCCalibData, TRUE);
        CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
        CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    }
    else
    {
      /*Do nothing*/
    }
    break;
    case CalibrationID_OC:
    switch(v_SVSCamCalibReset->CameraID)
    {
        case CameraID_Front:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data.CamFrontOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamFrontOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.data.CamFrontOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamFrontOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Left:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data.CamLeftOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamLeftOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.data.CamLeftOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamLeftOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Rear:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data.CamRearOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamRearOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.data.CamRearOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamRearOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_Right:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data.CamRightOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamRightOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.data.CamRightOC, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data.CamRightOC, sizeof(ME_Hydra3defs_S_CamCalibDataSTM_t));
        break;
        case CameraID_All:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamOCCalibData_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.data, 
            &Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamOCCalibData_t));
        break;
        default:
        /* Do nothing */
        break;
    }
    if((v_SVSCamCalibReset->CameraID > ((ME_Hydra3defs_E_CameraID_t)CameraID_None)) && (v_SVSCamCalibReset->CameraID <((ME_Hydra3defs_E_CameraID_t) CameraID_Invalid)))
    {
        Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.calibrated = FALSE;
        Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy.calibrated = FALSE;
        (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamOCCalibData, TRUE);
        CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
        CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    }
    else
    {
      /*Do nothing*/
    }
    break;
    case CalibrationID_Current:
    switch(v_SVSCamCalibReset->CameraID)
    {
        case CameraID_Front:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data.CamFrontCurrent, 
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamFrontCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.data.CamFrontCurrent,
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamFrontCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Left:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data.CamLeftCurrent, 
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamLeftCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.data.CamLeftCurrent,
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamLeftCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Rear:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data.CamRearCurrent, 
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamRearCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.data.CamRearCurrent,
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamRearCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_Right:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data.CamRightCurrent, 
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamRightCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.data.CamRightCurrent,
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data.CamRightCurrent, sizeof(ME_Hydra3defs_S_CamEOLCalibDataSTM_t));
        break;
        case CameraID_All:
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data, 
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamCurrentCalibData_t));
        VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.data,
            &Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue.data, sizeof(TbSVS_S_SVSCamCurrentCalibData_t));
        break;
        default:
        /* Do nothing */
        break;
    }
    if((v_SVSCamCalibReset->CameraID > ((ME_Hydra3defs_E_CameraID_t)CameraID_None)) && (v_SVSCamCalibReset->CameraID < ((ME_Hydra3defs_E_CameraID_t)CameraID_Invalid)))
    {
        Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.calibrated = FALSE;
        Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy.calibrated = FALSE;
        (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamCurrentCalibData, TRUE);
        CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
        CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    }
    else
    {
      /*Do nothing*/
    }
    break;
    default:
    /* Do nothing */
    break;
  }

  /* Pim, CData and Prm accesses skipped as they can be done by any runnable in the SWC */
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <P_CalDataProvider_Nvm_SVSCamCurrentCalibData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock(const TbSVS_S_SVSCamCurrentCalibDataToNVM_t *v_SVSCamCurrentCalibData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_SWC_CalDataProvider_SVSCamCurrentCalibData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamCurrentCalibData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {9D80496F-030E-4637-AB93-D1DABE1FD5C8}*/
  Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data = v_SVSCamCurrentCalibData->CamCurrent;
  Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.calibrated = TRUE;
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
  (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamCurrentCalibData, TRUE);
  CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
  CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
  /* Pim, CData and Prm accesses skipped as they can be done by any runnable in the SWC */
  return RTE_E_OK;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <P_CalDataProvider_Nvm_SVSCamEOLCalibData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock(const TbSVS_S_SVSCamEOLCalibDataToNVM_t *v_SVSCamEOLCalibData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_SWC_CalDataProvider_SVSCamEOLCalibData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamEOLCalibData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {839F2A5C-7CFA-4e1f-BAD6-0975EB987F87}*/

  uint16 v_PlantOdoValue_u16;
  (void)Rte_Read_Rp_PlantOdoData_PlantOdoData(&v_PlantOdoValue_u16);
  
  Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data = v_SVSCamEOLCalibData->CamEOL;
  Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.PlantOdoValue = v_PlantOdoValue_u16;
  Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.calibrated = TRUE;
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamEOLCalibData_t));
  (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamEOLCalibData, TRUE);
  CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
  CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
  /* Pim  CData and Prm accesses skipped as they can be done by any runnable in the SWC */
  s_CalibDIDTriggered_b = TRUE;
  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <P_CalDataProvider_Nvm_SVSCamOCCalibData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock(const TbSVS_S_SVSCamOCCalibDataToNVM_t *v_SVSCamOCCalibData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_SWC_CalDataProvider_SVSCamOCCalibData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamOCCalibData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {63EAAAF1-7C20-4ec2-89BA-4976A4AE77D9}*/

  Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data = v_SVSCamOCCalibData->CamOC;
  Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.calibrated = TRUE;
  VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamOCCalibData_t));
  (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamOCCalibData, TRUE);
  CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
  CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
  /* Pim, CData and Prm accesses skipped as they can be done by any runnable in the SWC */
  s_CalibDIDTriggered_b = TRUE;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <P_CalDataProvider_Nvm_SVSCamSCCalibData>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock(const TbSVS_S_SVSCamSCCalibDataToNVM_t *v_SVSCamSCCalibData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_SWC_CalDataProvider_SVSCamSCCalibData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) v_SVSCamSCCalibData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {EA4BE02B-3C2A-4331-8EA2-8B94BD8D2A07}*/

  Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data = v_SVSCamSCCalibData->CamSC;
  Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.calibrated = TRUE;
  (void)VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamSCCalibData_t));
  (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamSCCalibData, TRUE);
  CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
  CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
  /* Pim, CData and Prm accesses skipped as they can be done by any runnable in the SWC */
  s_CalibDIDTriggered_b = TRUE;
  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_IntrinsicCameraSN_Readblock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Readblock> of PortPrototype <PpIntrinsicCameraSN>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_IntrinsicCameraSN_Readblock(IntrinsicCamID *CamNvmData, CamNvmReadSts *NvmCamSts)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IF_IntrinsicCameraSN_E_NOT_OK
 *   RTE_E_IF_IntrinsicCameraSN_E_NOT_OK
 *   RTE_E_IF_IntrinsicCameraSN_E_OK
 *   RTE_E_IF_IntrinsicCameraSN_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IntrinsicCameraSN_Readblock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CalDataProvider_CODE) RE_IntrinsicCameraSN_Readblock(P2VAR(IntrinsicCamID, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) CamNvmData, P2VAR(CamNvmReadSts, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) NvmCamSts) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_IntrinsicCameraSN_Readblock (returns application error)
 *********************************************************************************************************************/
  /*DD-ID:{D564E80C-4EB2-49fa-AA95-0E81338D6C8B}*/
	NvM_RequestResultType BlockErrorStatus;
	Std_ReturnType Retval = E_NOT_OK;
	uint8 CameraNum =0;
	uint8 IsNvReadProcessingOngoing = FALSE;
  const uint8 CamNvBlockId [D_NUM_OF_CAMERAS]=
  {
      NvMConf_NvMBlockDescriptor_CalDataProviderFrontCamSerialNumber,
      NvMConf_NvMBlockDescriptor_CalDataProviderLeftCamSerialNumber,
      NvMConf_NvMBlockDescriptor_CalDataProviderRearCamSerialNumber,
      NvMConf_NvMBlockDescriptor_CalDataProviderRightCamSerialNumber
  };
__attribute__ ((section("QMRAM"))) static CamReadNvBlock_t CamIntrinSicData [D_NUM_OF_CAMERAS] =
{
		/* Front Cam */
		{
				.CamSerialNumber={0},
				.IsNvReadBlockTriggered=FALSE,
				.IsNvReadBlockProcessed=FALSE,
				.BlockStatus = NVM_REQ_OK
		},
		/* Left Cam */
		{
				.CamSerialNumber={0},
				.IsNvReadBlockTriggered=FALSE,
				.IsNvReadBlockProcessed=FALSE,
				.BlockStatus = NVM_REQ_OK
		},
		/* Rear Cam */
		{
				.CamSerialNumber={0},
				.IsNvReadBlockTriggered=FALSE,
				.IsNvReadBlockProcessed=FALSE,
				.BlockStatus = NVM_REQ_OK
		},
		/* Right Cam */
		{
				.CamSerialNumber={0},
				.IsNvReadBlockTriggered=FALSE,
				.IsNvReadBlockProcessed=FALSE,
				.BlockStatus = NVM_REQ_OK
		}
};


	for(CameraNum= 0;CameraNum<D_NUM_OF_CAMERAS;CameraNum++)
	{
		/*Camera Serial number from NVM*/
		if(CamIntrinSicData[CameraNum].IsNvReadBlockProcessed == (uint8)FALSE)
		{
			(void)NvM_GetErrorStatus(CamNvBlockId[CameraNum],&BlockErrorStatus);
			if((NvM_RequestResultType)NVM_REQ_PENDING !=BlockErrorStatus)
			{
				if(CamIntrinSicData[CameraNum].IsNvReadBlockTriggered != (uint8)TRUE)
				{
          CamIntrinSicData[CameraNum].BlockStatus = NVM_REQ_NOT_OK;
					(void)NvM_ReadBlock(CamNvBlockId[CameraNum],&CamIntrinSicData[CameraNum].CamSerialNumber);
					CamIntrinSicData[CameraNum].IsNvReadBlockTriggered = (uint8)TRUE;
				}
				else
				{
					if((NvM_RequestResultType)NVM_REQ_OK != BlockErrorStatus)
					{						
						VStdLib_MemClr(&CamIntrinSicData[CameraNum].CamSerialNumber,sizeof(FinalAssemblySerialNumber_t));
					}
          CamIntrinSicData[CameraNum].BlockStatus=BlockErrorStatus;
					CamIntrinSicData[CameraNum].IsNvReadBlockProcessed = (uint8)TRUE;
					CamIntrinSicData[CameraNum].IsNvReadBlockTriggered = (uint8)FALSE;
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
		else
		{
			/* Do nothing */
		}
		if(CamIntrinSicData[CameraNum].IsNvReadBlockTriggered == TRUE)
		{
			IsNvReadProcessingOngoing =  TRUE;
		}

	}
	if(IsNvReadProcessingOngoing == TRUE)
	{
		Retval = RTE_E_IF_IntrinsicCameraSN_E_NOT_OK;
	}
	else
	{
		/* If Read Block is successful Copy the processed data and block status*/
		CamNvmData->FrontCamera=CamIntrinSicData[0].CamSerialNumber;
		NvmCamSts->FrontCameraNVMStatus = CamIntrinSicData[0].BlockStatus;

		CamNvmData->LeftCamera=CamIntrinSicData[1].CamSerialNumber;
		NvmCamSts->LeftCameraNVMStatus = CamIntrinSicData[1].BlockStatus;

		CamNvmData->RearCamera=CamIntrinSicData[2].CamSerialNumber;
		NvmCamSts->RearCameraNVMStatus = CamIntrinSicData[2].BlockStatus;

		CamNvmData->RightCamera=CamIntrinSicData[3].CamSerialNumber;
		NvmCamSts->RightCameraNVMStatus = CamIntrinSicData[3].BlockStatus;

		/* Clear Block processing Status */
		CamIntrinSicData[0].IsNvReadBlockProcessed = (uint8)FALSE;
		CamIntrinSicData[1].IsNvReadBlockProcessed = (uint8)FALSE;
		CamIntrinSicData[2].IsNvReadBlockProcessed = (uint8)FALSE;
		CamIntrinSicData[3].IsNvReadBlockProcessed = (uint8)FALSE;

		Retval = RTE_E_IF_IntrinsicCameraSN_E_OK;
	}
	return Retval ;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_CalDataProvider
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
 *   Std_ReturnType Rte_Read_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(TbSVS_S_SVSCamCurrentCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Read_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t(TbSVS_S_SVSCamEOLCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Read_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t(TbSVS_S_SVSCamOCCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Read_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t(TbSVS_S_SVSCamSCCalibDataToNVM_t *data)
 *   Std_ReturnType Rte_Read_R_SSM_1_0_State_State_1_0(SSM_1_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_0(SSM_2_0_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_2_State_State_2_1(SSM_2_1_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SSM_QNXState_State_QNX(SSM_QNX_CoreStatus *data)
 *   Std_ReturnType Rte_Read_R_SystemState_SystemState(SSM_SystemState *data)
 *   Std_ReturnType Rte_Read_RpCalibRoutineTrigger_routine_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpCalibRoutineType_value(uint8 *data)
 *   Std_ReturnType Rte_Read_RpCamEepromData_Svs_CamEepromDataArray_t(Svs_CamEepromDataArray_t *data)
 *   Std_ReturnType Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(ME_Proxi_MPU1_0_to_MCU1_0_t *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_SurroundViewCam_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpResetNvmFlag_V_ResetNvmFlag_b(boolean *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpVariantData_Variant(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_PlantOdoData_PlantOdoData(uint16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0(const CalDataProvider_MCU_1_0_Def *data)
 *   Std_ReturnType Rte_Write_P_Request_BswM_ScCalStatus_requestedMode(BswM_CalDataProSCCalStatus data)
 *   Std_ReturnType Rte_Write_PpAPVarTunParam_TbAP_VrntTunParam_t(const TbAP_VrntTunParam_t *data)
 *   Std_ReturnType Rte_Write_PpPreviousCamData_Data(const CDP_TbSVS_S_SVSCamCurrentCalibData_t *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_R_CalDataProvider_ErrorMgrSat_1_0_QM_Error_CS_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_R_IPC_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamCurrentCalibData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamCurrentCalibData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamEOLCalibData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamEOLCalibData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamOCCalibData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamOCCalibData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamSCCalibData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SVSCamSCCalibData_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_CalDataProvider_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CalDataProvider_CODE) RE_Periodic_CalDataProvider(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_CalDataProvider
 *********************************************************************************************************************/
  /* DD-ID: {57573965-7605-42d9-A1D7-7B615B6639F6}*/

  static uint32 prev_SVSCamCurrentCalibDataFreshnessCount;
  static uint32 prev_SVSCamEOLCalibDataFreshnessCount;
  static uint32 prev_SVSCamOCCalibDataFreshnessCount;
  static uint32 prev_SVSCamSCCalibDataFreshnessCount;
  uint32 v_TotalOdometerValue_u32;

  static boolean v_SVSCalibCompletionStatus_b = FALSE;
  static uint8 v_SC_calibRoutineType_u8 = 0u;
  static uint16 v_HardResetCounter_u16 = 0;

 
  SSM_SystemState SSMSystemState;
  static SSM_SystemStateDef previous_SSMMasterState = SSM_STATE_MAX;
  static uint16 v_IntrinsicCounter_u16;
  static uint16 v_Intrinsic100msCounter_u16;
  TbSVS_S_SVSCamCurrentCalibDataToNVM_t read_SVSCamCurrentCalibData;
  TbSVS_S_SVSCamEOLCalibDataToNVM_t read_SVSCamEOLCalibData;
  TbSVS_S_SVSCamOCCalibDataToNVM_t read_SVSCamOCCalibData;
  TbSVS_S_SVSCamSCCalibDataToNVM_t read_SVSCamSCCalibData;
  CDP_TbSVS_S_SVSCamCurrentCalibData_t PreviousCameraData;
  static uint8 v_Counter_u8 = 0u;
  boolean v_CalibRoutineTriggered_b;

  if((uint16)D_COUNTER_VAL <= v_IntrinsicCounter_u16)
  {
    if ((uint16)D_COUNTER100ms_VAL <= v_Intrinsic100msCounter_u16)
    {
      v_Intrinsic100msCounter_u16 = (uint16)0;
      f_CamIntrinsicNumCheck_v();
    }
    else
    {
      v_Intrinsic100msCounter_u16++;
    }
  }
  else
  {
    v_IntrinsicCounter_u16++;
  }

  (void)Rte_Read_RpCalibRoutineTrigger_routine_b(&v_CalibRoutineTriggered_b);
  (void)Rte_Read_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(&read_SVSCamCurrentCalibData);
  (void)  Rte_Read_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t(&read_SVSCamEOLCalibData);
  (void)Rte_Read_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t(&read_SVSCamOCCalibData);
 (void) Rte_Read_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t(&read_SVSCamSCCalibData);
 
 
  if((read_SVSCamCurrentCalibData.bValid == (boolean)TRUE )&& (read_SVSCamCurrentCalibData.FreshnessCount > prev_SVSCamCurrentCalibDataFreshnessCount))
  {
    /*value of v_Counter_u8 is one when any routine is trigger & is updated after hard reset also*/
    v_Counter_u8++;
    if((v_Counter_u8 == (uint8)e_ONE) && (v_CalibRoutineTriggered_b == TRUE))
    {
     /*Update Previous camera calibrationdata with old current camera calibration data*/
     VStdLib_MemCpy(&PreviousCameraData, &Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
     (void)Rte_Write_PpPreviousCamData_Data(&PreviousCameraData);
    }
    Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.data = read_SVSCamCurrentCalibData.CamCurrent;
    Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.calibrated = TRUE;
    /* Read Total Odometer Value */
    (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&v_TotalOdometerValue_u32);  
    /* Scale Odometer Value Before Sending */
    Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock.PrevOdoValue = (uint16)(v_TotalOdometerValue_u32/(uint32)D_ODOMETER_SCALING_FACTOR);
    /*store updated current camera calibration data in memory*/
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
    (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamCurrentCalibData, TRUE);
	
	CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
    CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    prev_SVSCamCurrentCalibDataFreshnessCount = read_SVSCamCurrentCalibData.FreshnessCount;


  }
  else
  {
    /*Do nothing*/
  }

  if((read_SVSCamEOLCalibData.bValid == (boolean)TRUE) && (read_SVSCamEOLCalibData.FreshnessCount > prev_SVSCamEOLCalibDataFreshnessCount))
  {


    Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.data = read_SVSCamEOLCalibData.CamEOL;
    Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.calibrated = TRUE;
    /* Read Total Odometer Value */
    (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&v_TotalOdometerValue_u32);  
    /* Scale Odometer Value Before Sending */
    Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock.PlantOdoValue = (uint16)(v_TotalOdometerValue_u32/(uint32)D_ODOMETER_SCALING_FACTOR);
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamEOLCalibData_t));
    (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamEOLCalibData, TRUE);

    CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
    CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    prev_SVSCamEOLCalibDataFreshnessCount = read_SVSCamEOLCalibData.FreshnessCount;
  }
  else
  {
    /*Do nothing*/
  }

  if((read_SVSCamOCCalibData.bValid == (boolean)TRUE) && (read_SVSCamOCCalibData.FreshnessCount > prev_SVSCamOCCalibDataFreshnessCount))
  {
    
    Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.data = read_SVSCamOCCalibData.CamOC;
    Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock.calibrated = TRUE;
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamOCCalibData_t));
    (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamOCCalibData, TRUE);

    CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
    CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    prev_SVSCamOCCalibDataFreshnessCount = read_SVSCamOCCalibData.FreshnessCount;
  }
  else
  {
    /*Do nothing*/
  }

  if((read_SVSCamSCCalibData.bValid == (boolean)TRUE) && (read_SVSCamSCCalibData.FreshnessCount > prev_SVSCamSCCalibDataFreshnessCount))
  {

    Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.data = read_SVSCamSCCalibData.CamSC;
    Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock.calibrated = TRUE;
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy,&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamSCCalibData_t));
    (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_CalDataProviderSVSCamSCCalibData, TRUE);

    CDP_F_CalData_update_to_core_v(SSM_CORE_QNX);
    CDP_F_CalData_update_to_core_v(SSM_CORE_1_0);
    prev_SVSCamSCCalibDataFreshnessCount = read_SVSCamSCCalibData.FreshnessCount;

        /* Check which SC calib routine has triggered from RID software component */
    (void)Rte_Read_RpCalibRoutineType_value(&v_SC_calibRoutineType_u8);


    /* Check calibration status based on the routine type */
    if (v_SC_calibRoutineType_u8 == (uint8)ENFORCED_CALIBRATION_SC) {
        /* Check right camera calibration status */
        if ((read_SVSCamSCCalibData.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e == ME_Hydra3defs_E_CalibCompletedSuccessful) ||
                 (read_SVSCamSCCalibData.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e == ME_Hydra3defs_E_CalibAbortedFailed)) {

            v_SVSCalibCompletionStatus_b = TRUE;
        } else {
            /* Do nothing */
        }
    } else if (v_SC_calibRoutineType_u8 == (uint8)REAR_CAMERA_CALIBRATION_SC) {
        /* Check rear camera calibration status */
        if ((read_SVSCamSCCalibData.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e == ME_Hydra3defs_E_CalibCompletedSuccessful) ||
                  (read_SVSCamSCCalibData.CamSC.CamRearSC.CamCalibData_STM.CalibStatus_e == ME_Hydra3defs_E_CalibAbortedFailed)) {

            v_SVSCalibCompletionStatus_b = TRUE;
        } else {
            /* Do nothing */
        }
    } else {
        /* Do nothing */
    }
  }
  else
  {
    /*Do nothing*/
  }

  CalDataProvider_Run_v();

  /* Read SSM master state and update the application accordingly */
  (void)Rte_Read_R_SystemState_SystemState(&SSMSystemState);

  if(previous_SSMMasterState != SSMSystemState.SystemState)
  {
    switch(SSMSystemState.SystemState)
    {
      case SSM_STATE_BOOTING:
      (void) SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_CalDataProvider, SSM_APPSTATE_INIT);
      break;
      case SSM_STATE_IPCREADY:
      case SSM_STATE_RUNNING:
        (void)SSM_Slave_SetApplicationStatus(SSM_MCU_1_0_Application_CalDataProvider, SSM_APPSTATE_RUNNING);
      break;
      case SSM_STATE_DEGRADED:
      case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP:
      case SSM_STATE_SHUTTINGDOWN_REMOTECORES:
      case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE:
      case SSM_STATE_OFF:
      break;
      default:/*QAC fixes*/
      break;
    }
    previous_SSMMasterState = SSMSystemState.SystemState;
  }
  else
  {
    /*do nothing*/
  }

  /* logic to perform automatic hard reset when service calibration (svs) is completed  */
  if(v_SVSCalibCompletionStatus_b == TRUE)
  {
    /* Delay for 5 sec*/
      if (v_HardResetCounter_u16 >= TIMER_5_SEC_COUNT)
      {      
        v_SVSCalibCompletionStatus_b = FALSE ;
        (void)Rte_Write_P_Request_BswM_ScCalStatus_requestedMode(SC_CAL_FINISHED);
      }
      else
      {
        v_HardResetCounter_u16++;
      }
  }
  else
  {
    /*do nothing*/
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void Update_CalDataProvider_MirrorBlock(boolean CalDataProvider_Erase_block)
{
  /* DD-ID: {9EF909EC-65E7-4d9f-8378-CFCDFF8B60F4}*/
  if( ( boolean) TRUE == CalDataProvider_Erase_block)
  {
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamEOLCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamSCCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock, &Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy, sizeof(CDP_TbSVS_S_SVSCamOCCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy,  sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy,  sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock, &Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));

  }
  else
  {
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock_copy, &Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamCurrentCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock_copy, &Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamEOLCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock_copy, &Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamSCCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock_copy, &Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock, sizeof(CDP_TbSVS_S_SVSCamOCCalibData_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy, &Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock,  sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy, &Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock, sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy, &Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock,  sizeof(FinalAssemblySerialNumber_t));
    VStdLib_MemCpy(&Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy, &Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock, sizeof(FinalAssemblySerialNumber_t));

  }
}

static void f_CamIntrinsicNumCheck_v(void)
{
	/* DD-ID: {29517E5F-FCE7-4328-A748-21452BE229AA}*/
	sint8 v_ComparePimVal_s8;
	sint8 v_CompareAcoreVal_s8;
	sint8 v_CompareAcoreAndPimVal_s8;
	uint8 v_view_u8;
	Std_ReturnType NvCallRetVal=FALSE;
	boolean v_CalibRoutineTriggered_b;
	boolean v_ResetNvmFlag_b = FALSE;
	uint8 CameraId=0u;
	Svs_CamEepromDataArray_t v_SvsCamEepromDataArray_data_s = {0u};
	ME_Proxi_MPU1_0_to_MCU1_0_t v_ME_Proxi_MPU1_0_to_MCU1_0_data_s;
	FinalAssemblySerialNumber_t FinalAssemblySerialNumber_data = {0u};
	NvM_RequestResultType BlockErrorStatus = NVM_REQ_NOT_OK;
	boolean v_CamIntrBlockProcPending_b = FALSE;
	static boolean v_CamIntrNvMWRProcessed_b = FALSE;
	/* Added structure in function so as to avoid MISRA Warning */
	static CalIntrinsicData_ConfigType CamIntrinsicData[D_NUM_OF_CAMERAS] = {
			/* Front Camera */
			{
					.NvMRamMirrorBlock_copy = &Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock_copy,
					.NvMRamMirror = &Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock,
					.BlockId = NvMConf_NvMBlockDescriptor_CalDataProviderFrontCamSerialNumber,
					.ErrorEnum=ErrorMgr_Error_SVC_Front_Incorrect_Device_ID_Fault,
					.retryCounter_u8=0u,
					.CamIntrNvBlockTriggered_b =(boolean) FALSE,
					.CamIntrNvBlockProcessed_b=(boolean)FALSE,
					.PerformRetry_b=(boolean)FALSE
			},
			/* Left Camera */
			{
					.NvMRamMirrorBlock_copy = &Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock_copy,
					.NvMRamMirror = &Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock,
					.BlockId = NvMConf_NvMBlockDescriptor_CalDataProviderLeftCamSerialNumber,
					.ErrorEnum=ErrorMgr_Error_SVC_Left_Incorrect_Device_ID_Fault,
					.retryCounter_u8=(uint8)0U,
					.CamIntrNvBlockTriggered_b =(boolean) FALSE,
					.CamIntrNvBlockProcessed_b=(boolean)FALSE,
					.PerformRetry_b=(boolean)FALSE

			},
			/* Rear Camera */
			{
					.NvMRamMirrorBlock_copy = &Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock_copy,
					.NvMRamMirror = &Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock,
					.BlockId = NvMConf_NvMBlockDescriptor_CalDataProviderRearCamSerialNumber,
					.ErrorEnum=ErrorMgr_Error_SVC_Rear_Incorrect_Device_ID_Fault,
					.retryCounter_u8=0u,
					.CamIntrNvBlockTriggered_b =(boolean) FALSE,
					.CamIntrNvBlockProcessed_b=(boolean)FALSE,
					.PerformRetry_b=(boolean)FALSE
			},
			/* Right Camera */
			{
					.NvMRamMirrorBlock_copy = &Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock_copy,
					.NvMRamMirror = &Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock,
					.BlockId = NvMConf_NvMBlockDescriptor_CalDataProviderRightCamSerialNumber,
					.ErrorEnum=ErrorMgr_Error_SVC_Right_Incorrect_Device_ID_Fault,
					.retryCounter_u8=0u,
					.CamIntrNvBlockTriggered_b =(boolean) FALSE,
					.CamIntrNvBlockProcessed_b=(boolean)FALSE,
					.PerformRetry_b=(boolean)FALSE
			}

	};

	(void)Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(&v_ME_Proxi_MPU1_0_to_MCU1_0_data_s);
	/* Check if camera intrinsic data is already stored because of calibration routine or Forced did trigger */
	if((boolean) FALSE == v_CamIntrNvMWRProcessed_b)
	{
		/* Read calibration routine trigger status */
		(void)Rte_Read_RpCalibRoutineTrigger_routine_b(&v_CalibRoutineTriggered_b);
	}
	else
	{
		/* Clear the calibration routine flag and DID trigger flag */
		v_CalibRoutineTriggered_b = FALSE;
		s_CalibDIDTriggered_b = FALSE;
	}
	/* Check if A-Core is up and running */
	if ((v_ME_Proxi_MPU1_0_to_MCU1_0_data_s.state == (uint32)QNX_BOOTUP_STATE) ||
			(v_ME_Proxi_MPU1_0_to_MCU1_0_data_s.state == (uint32)QNX_RUNNING_STATE) ||
			(v_ME_Proxi_MPU1_0_to_MCU1_0_data_s.state == (uint32)QNX_RUNNING_PROXI_WRITTEN_PASS_STATE) ||
			(v_ME_Proxi_MPU1_0_to_MCU1_0_data_s.state == (uint32)QNX_RUNNING_PROXI_WRITTEN_FAILED_STATE) ||
			(v_ME_Proxi_MPU1_0_to_MCU1_0_data_s.state == (uint32)QNX_RUNNING_PROXI_WRITTEN_SKIPPED_STATE))
	{
		/* Read Reset NvM Flag */
		(void)Rte_Read_RpResetNvmFlag_V_ResetNvmFlag_b(&v_ResetNvmFlag_b);
		/* Read SurroundViewCamera flag from proxi*/
		(void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_view_u8);
		/* Read Camera EEPROM Intrinsic Data from A-Core */
		(void)Rte_Read_RpCamEepromData_Svs_CamEepromDataArray_t(&v_SvsCamEepromDataArray_data_s);

		if((uint8)e_ONE != v_view_u8)
		{
			/* Single Camera variant Proxi selected */
			/* Update Camera ID to Rear Camera so that only that camera will be processed */
			CameraId = D_REAR_CAMERA_ID;
		}
		else
		{
			/* Process all cameras*/
			/* CameraId is already initialized and set to 0*/
		}
		/* Iterate for the cameras */
		/* While loop instead of for loop is used to avoid MISRA Warning */
		while(CameraId<D_NUM_OF_CAMERAS)
		{
			/* Compare PIM and A-Core received value with zero values */
			v_ComparePimVal_s8 = VStdLib_MemCmp(&FinalAssemblySerialNumber_data, CamIntrinsicData[CameraId].NvMRamMirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));
			v_CompareAcoreVal_s8 = VStdLib_MemCmp(&FinalAssemblySerialNumber_data, &v_SvsCamEepromDataArray_data_s.CameraEepromData[CameraId].camProductionData_s.finalAssemblySerialNumber_s, sizeof(FinalAssemblySerialNumber_t));
			/*
			 * Check if EEPROM Data is loaded with default values or Calibration routine / Forced calibration DID is triggered or Retry needs to be done for any Camera Nv Writing and
			 * A-Core received value is non Zero and NvM Reset is not ongoing
			 *
			 */
			/* Intentional cast of v_ComparePimVal_s8, v_CompareAcoreVal_s8 variables to avoid implicit promotion (MISRA Rule 10.6) */
			if ((((sint32_t)v_ComparePimVal_s8 == 0) || ((boolean)TRUE == v_CalibRoutineTriggered_b) || ((boolean)TRUE == s_CalibDIDTriggered_b)||((boolean)TRUE == CamIntrinsicData[CameraId].PerformRetry_b)) && ((sint32_t)v_CompareAcoreVal_s8!=0) && ((boolean)FALSE == v_ResetNvmFlag_b))
			{
				/* Check if retry counter is in range i.e < 3 */
				if(CamIntrinsicData[CameraId].retryCounter_u8 < D_RETRY_NV_WRITING_CNT)
				{
					/* Get Nv Block Error Status */
					(void)NvM_GetErrorStatus(CamIntrinsicData[CameraId].BlockId,&BlockErrorStatus);
					if(NVM_REQ_PENDING != BlockErrorStatus)
					{
						/* Compare previously stored NvM Value with A-Core received value */
						v_CompareAcoreAndPimVal_s8 = VStdLib_MemCmp(&v_SvsCamEepromDataArray_data_s.CameraEepromData[CameraId].camProductionData_s.finalAssemblySerialNumber_s, CamIntrinsicData[CameraId].NvMRamMirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));
						/* Check if A-Core received value and PIM Stored values are different and Nv block write is not triggered */
						/* Intentional cast of v_ComparePimVal_s8, variable to avoid implicit promotion (MISRA Rule 10.6) */
						if((sint32_t)v_CompareAcoreAndPimVal_s8!=0)
						{
							if((FALSE == CamIntrinsicData[CameraId].CamIntrNvBlockTriggered_b))
							{
								/*Copy data in RAM Mirror to Write Data in NvM */
								VStdLib_MemCpy(CamIntrinsicData[CameraId].NvMRamMirror, &v_SvsCamEepromDataArray_data_s.CameraEepromData[CameraId].camProductionData_s.finalAssemblySerialNumber_s, sizeof(FinalAssemblySerialNumber_t));
								/* Trigger for Nv Writing */
								NvCallRetVal=NvM_WriteBlock(CamIntrinsicData[CameraId].BlockId,CamIntrinsicData[CameraId].NvMRamMirror);
								/* Check if Write block is successful */
								if(E_OK == NvCallRetVal)
								{
									/* Set Nv triggered flag as TRUE */
									CamIntrinsicData[CameraId].CamIntrNvBlockTriggered_b= TRUE;
								}
								else
								{
									/* Increment the retry counter */
									CamIntrinsicData[CameraId].retryCounter_u8+=1u;
									/* Set retry flag as TRUE */
									CamIntrinsicData[CameraId].PerformRetry_b = TRUE;
									/* Set Nv Triggered flag as FALSE so as to process it again*/
									CamIntrinsicData[CameraId].CamIntrNvBlockTriggered_b = (boolean)FALSE;
								}
								/* Set Camera Intrinsic data Nv Block processing as pending so that */
								v_CamIntrBlockProcPending_b = TRUE;
							}
							else
							{
								/* Check for block error status */
								if(NVM_REQ_OK == BlockErrorStatus)
								{
									/* Block error status is OK and written in NvM */
									/* Clear the fault as Camera intrinsic data is written in NvM */
									(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(CamIntrinsicData[CameraId].ErrorEnum, ErrorMgr_ErrorInactive, NULL_PTR);
									/* Copy the Written data in RAM Mirror */
									CamIntrinsicData[CameraId].NvMRamMirrorBlock_copy = CamIntrinsicData[CameraId].NvMRamMirror;
									/* Clear the flag and counter values */
									CamIntrinsicData[CameraId].CamIntrNvBlockProcessed_b = (boolean)TRUE;
									CamIntrinsicData[CameraId].PerformRetry_b = (boolean)FALSE;
									CamIntrinsicData[CameraId].retryCounter_u8 = (uint8)e_ZERO;
								}
								else
								{
									/* Perform Retry */
									/* Increment the retry counter */
									if(CamIntrinsicData[CameraId].retryCounter_u8 < D_RETRY_NV_WRITING_CNT)
									{
										CamIntrinsicData[CameraId].retryCounter_u8+=1u;
									}
									else
									{
										/* Do Nothing */
									}
									/* Set retry flag as TRUE */
									CamIntrinsicData[CameraId].PerformRetry_b = TRUE;
								}
								/* Set Nv Triggered flag as FALSE so as to process it again*/
								CamIntrinsicData[CameraId].CamIntrNvBlockTriggered_b = (boolean)FALSE;
							}
						}
						else
						{
							/* Clear the fault as Camera intrinsic data is already written in NvM */
							(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(CamIntrinsicData[CameraId].ErrorEnum, ErrorMgr_ErrorInactive, NULL_PTR);
						}
					}
					else
					{
						/* Set Camera Intrinsic data Nv Block processing as pending */
						v_CamIntrBlockProcPending_b = TRUE;
					}
				}
				else
				{
					/* Clear perform retry flag and CamIntrNvblock Processing flag */
					CamIntrinsicData[CameraId].PerformRetry_b = FALSE;
					CamIntrinsicData[CameraId].CamIntrNvBlockProcessed_b = (boolean)FALSE;
				}

			}
			else if ((sint32_t)v_CompareAcoreVal_s8==0) /* Intentional cast to avoid implicit promotion (MISRA Rule 10.6) */

			{
				/* A-Core received value is zero set camera intrinsic data fault */
				(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(CamIntrinsicData[CameraId].ErrorEnum, ErrorMgr_ErrorActive, NULL_PTR);
			}
			else
			{
				/* Compare PIM and A-Core Received value */
				v_ComparePimVal_s8 = VStdLib_MemCmp(&v_SvsCamEepromDataArray_data_s.CameraEepromData[CameraId].camProductionData_s.finalAssemblySerialNumber_s, CamIntrinsicData[CameraId].NvMRamMirrorBlock_copy, sizeof(FinalAssemblySerialNumber_t));
				if ((sint32_t)v_ComparePimVal_s8!=0)
				{
					/* Camera intrinsic data mismatch , set fault */
					(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(CamIntrinsicData[CameraId].ErrorEnum, ErrorMgr_ErrorActive, NULL_PTR);
				}
				else
				{
					/* Camera intrinsic data match , Clear fault */
					(void)Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(CamIntrinsicData[CameraId].ErrorEnum, ErrorMgr_ErrorInactive, NULL_PTR);
				}
			}

			if((uint8)e_ONE != v_view_u8)
			{
				/* Single Camera variant Proxi selected */
				/* Rear Camera already processed break while loop */
				break;
			}
			/* Increment camera Id so as to process next camera */
			CameraId++;
		};

		/* Check if Calibration routine or Forced calibration DID was triggered and all Nv Blocks are processed */
		if ((FALSE == v_CamIntrBlockProcPending_b) && (((boolean)TRUE == v_CalibRoutineTriggered_b) || ((boolean)TRUE == s_CalibDIDTriggered_b)))
		{
			/* Set Nv Writing flag as TRUE so that no intrinsic data Nv Blocks will be written*/
			v_CamIntrNvMWRProcessed_b = TRUE;
			/* perform Hard Reset after EOL Calibration*/
		}
		else
		{
			/* Do /Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}

}

#define CalDataProvider_STOP_SEC_CODE
#include "CalDataProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
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
