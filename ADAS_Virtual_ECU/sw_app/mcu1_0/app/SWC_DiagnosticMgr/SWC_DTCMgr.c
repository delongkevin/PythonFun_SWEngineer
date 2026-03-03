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
 *             File:  SWC_DTCMgr.c
 *           Config:  C:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_DTCMgr
 *  Generation Time:  2025-09-11 12:39:02
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_DTCMgr>
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
 * BswM_DtcSettingClearFlagModeGrp
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
 * Camera_Status
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
 * Cntr_ADAS_FD_LANES_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Cntr_ADAS_FD_LANES_2
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
 * DLDCamSts_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DataPrimitiveType_uint16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * DataPrimitiveType_uint8
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
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_OperationCycleStateType
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
 * FD14_Brk_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Camera_Status
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Cntr_ADAS_FD_LANES_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Cntr_ADAS_FD_LANES_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_FOD_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Frame_Index_Lanes_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_Frame_Index_Lanes_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_HAS_Status
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Health_Front_Object_Detection
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_Health_Lane_Detection
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
 * FD14_Line_1_Type
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
 * FD14_Line_2_Type
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
 * FD14_Line_3_Type
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
 * FD14_Line_4_Type
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
 * FD14_ManoeuvrePhase
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FD14_PAM_Brk_Rq_RspSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * FD14_Reserved_for_functional_safety
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
 * FD14_Segment_1_ID
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
 * FD14_Segment_2_ID
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
 * FD14_Segment_3_ID
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
 * FD14_Segment_4_ID
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
 * FD14_Segment_5_ID
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
 * FD14_Segment_6_ID
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
 * FD14_Segment_7_ID
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
 * FD14_Segment_8_ID
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
 * FOD_Confidence
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
 * Frame_Index_Lanes_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Frame_Index_Lanes_2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * Health_Front_Object_Detection
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Health_Lane_Detection
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
 * ImageDefeatRQSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * Line_1_Type
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
 * Line_2_Type
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
 * Line_3_Type
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
 * Line_4_Type
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
 * MRM_STATUS_C2
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
 * Reserved_for_functional_safety
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * Segment_1_ID
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
 * Segment_2_ID
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
 * Segment_3_ID
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
 * Segment_4_ID
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
 * Segment_5_ID
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
 * Segment_6_ID
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
 * Segment_7_ID
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
 * Segment_8_ID
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
 * TeAP_e_FrntSnsrStatus
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
 * TeAP_e_PAMSystemFault
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
 *
 * Runnable Entities:
 * ==================
 * RE_DTCMgr_Init
 *   Init Runnable
 *
 * RE_DTCMgr_Main
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_SWC_DTCMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "vstdlib.h"
#include "Enums.h"
#include "ErrorManagerDef.h"
#include "ipc_manager.h"
#include "APDiagDataTypes.h"

#define D_VOLTAGE_SCALING_FACTOR   	10.0f
#define D_CRANK_DELAY_TIME              500U
#define D_VALID_VOL_LOW_RANGE           9.0f
#define D_VALID_VOL_HIGH_RANGE          16.0f
#define D_DTC_TEST_FAILED_STATUS_MASK   0x01u
#define D_ODOMETER_SCALING_FACTOR       16u
#define DEGMANAGER_GETPACKEDSIZE(x)  (uint32_t)(((uint32_t)(x)>>5u) + (((uint32_t)(x)&(uint32_t)0x1F)!=0?(uint32_t)1:(uint32_t)0))
#define SIZEOF_ERROR_B_DATA  	(4u * (uint16)DEGMANAGER_GETPACKEDSIZE(ldef_B_ErrorMgr_ErrorNum_Max))
#define SIZEOF_ERROR_QM_DATA  	(4u * (uint16)DEGMANAGER_GETPACKEDSIZE(ldef_QM_ErrorMgr_ErrorNum_Max))
#define AGING_COUNTER_ID        6080u
#define FREQUENCY_COUNTER_ID    6090u
#define CYCLE_SWITCH_OFF_WI_ID  6081u
#define D_FIVESEC_CNTR          500u
#define D_SPEED_CONV_FACTOR_INV (16u) /* 1/0.0625 = 16u */
#define DTC_ENABLE_SPPED_LIMIT  (11u * D_SPEED_CONV_FACTOR_INV)
#define DTCMGR_APAPROXY_PRESENT TRUE
#define CAMERA_BLOCKED          0u
#define CAMERA_CLEAR            1u
#define TRSC_ENABLED                 0u
#define NOT_ENABLED             1u
#define USS_STAT_EN             (1u<<6u)
#define SINGLE_CAM_VARIANT      0u

static boolean v_SensrTestFlag = FALSE;
static uint8 v_InPlantMode = FALSE;
typedef struct
 {
	  uint8 DTC_FAILED_B210C_16;
	  uint8 DTC_FAILED_B210C_17;
	  uint8 DTC_FAILED_U104E_0;
	  uint8 DTC_FAILED_U100B_0;
	  uint8 DTC_FAILED_U0140_0;
	  uint8 DTC_FAILED_U0184_0;
	  uint8 DTC_FAILED_B223B_0;
	  uint8 DTC_FAILED_U0129_0;
	  uint8 DTC_FAILED_U0131_0;
	  uint8 DTC_FAILED_U0418_0;
	  uint8 DTC_FAILED_U0420_0;
	  uint8 DTC_FAILED_U0422_0;
	  uint8 DTC_FAILED_U0485_0;
	  uint8 DTC_FAILED_B12B2_2A;
	  uint8 DTC_FAILED_B1285_2A;
	  uint8 DTC_FAILED_B128E_13;
	  uint8 DTC_FAILED_B128F_13;
	  uint8 DTC_FAILED_B1290_13;
	  uint8 DTC_FAILED_B1291_13;
	  uint8 DTC_FAILED_B1292_13;
	  uint8 DTC_FAILED_B1293_13;
	  uint8 DTC_FAILED_B1294_13;
	  uint8 DTC_FAILED_B1295_13;
	  uint8 DTC_FAILED_B1296_13;
	  uint8 DTC_FAILED_B1297_13;
	  uint8 DTC_FAILED_B1298_13;
	  uint8 DTC_FAILED_B1299_13;
	  uint8 DTC_FAILED_B128E_92;
	  uint8 DTC_FAILED_B128F_92;
	  uint8 DTC_FAILED_B1290_92;
	  uint8 DTC_FAILED_B1291_92;
	  uint8 DTC_FAILED_B1292_92;
	  uint8 DTC_FAILED_B1293_92;
	  uint8 DTC_FAILED_B1294_92;
	  uint8 DTC_FAILED_B1295_92;
	  uint8 DTC_FAILED_B1296_92;
	  uint8 DTC_FAILED_B1297_92;
	  uint8 DTC_FAILED_B1298_92;
	  uint8 DTC_FAILED_B1299_92;
	  uint8 DTC_FAILED_B212A_16;
	  uint8 DTC_FAILED_B212B_16;
	  uint8 DTC_FAILED_B23C6_92;
	  uint8 DTC_FAILED_U0267_0;
	  uint8 DTC_FAILED_B23C7_92;
	  uint8 DTC_FAILED_U0266_0;
	  uint8 DTC_FAILED_U0264_0;
	  uint8 DTC_FAILED_B217A_92;
	  uint8 DTC_FAILED_U0265_0;
	  uint8 DTC_FAILED_B23C5_92;
	  uint8 DTC_FAILED_B217A_1C;
	  uint8 DTC_FAILED_B23C5_1C;
	  uint8 DTC_FAILED_B23C6_1C;
	  uint8 DTC_FAILED_B23C7_1C;
	  uint8 DTC_FAILED_B2286_0;
	  uint8 DTC_FAILED_C2212_0;
	  uint8 DTC_FAILED_B212A_17;
	  uint8 DTC_FAILED_B212B_17;
	  uint8 DTC_FAILED_B212A_8;
	  uint8 DTC_FAILED_B212B_8;
	  uint8 DTC_FAILED_B22A9_0;
	  uint8 DTC_FAILED_U0100_0;
	  uint8 DTC_FAILED_U0401_0;
	  uint8 DTC_FAILED_U0151_0;
	  uint8 DTC_FAILED_U12B9_0;
	  uint8 DTC_FAILED_U14A0_0;
	  uint8 DTC_FAILED_U0455_0;
 }DTCSettingStatus_st;

extern DiagToParkAssist_t DiagToParkAssist_data;
static DTCSettingStatus_st DTC_Setting_Status;

static FUNC(void, SWC_DTCMgr_CODE) F_DTC_Check_Enable_Condition(void);
static FUNC(uint8, SWC_DTCMgr_CODE) F_PPPAEnable_Status_Check(void);

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
 * BSM_THA_Brk_Resp: Integer in interval [0...3]
 * Backup_Cam_Delay: Integer in interval [0...1]
 * Brk_Stat: Integer in interval [0...3]
 * BswM_DtcSettingClearFlagModeGrp: Integer in interval [0...255]
 * CM_TCH_STAT: Integer in interval [0...7]
 * CM_TCH_X_COORD: Integer in interval [0...65535]
 * CM_TCH_Y_COORD: Integer in interval [0...65535]
 * CameraDisplaySts2: Integer in interval [0...15]
 * Camera_Status: Integer in interval [0...15]
 * ChimeActivation_LHF: Integer in interval [0...1]
 * ChimeActivation_LHR: Integer in interval [0...1]
 * ChimeActivation_RHF: Integer in interval [0...1]
 * ChimeActivation_RHR: Integer in interval [0...1]
 * CmdIgnSts: Integer in interval [0...7]
 * Cntr_ADAS_FD_LANES_1: Integer in interval [0...65535]
 * Cntr_ADAS_FD_LANES_2: Integer in interval [0...65535]
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
 * DLDCamSts_t: Integer in interval [0...4294967295]
 * DataPrimitiveType_uint16: Integer in interval [0...65535]
 * DataPrimitiveType_uint8: Integer in interval [0...255]
 * DeltaTimestamp_IMUdata: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_EventStatusType: Integer in interval [0...255]
 * Dem_OperationCycleStateType: Integer in interval [0...1]
 * Dem_UdsStatusByteType: Integer in interval [0...255]
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
 * FD14_Brk_Stat: Integer in interval [0...3]
 * FD14_Camera_Status: Integer in interval [0...15]
 * FD14_Cntr_ADAS_FD_LANES_1: Integer in interval [0...65535]
 * FD14_Cntr_ADAS_FD_LANES_2: Integer in interval [0...65535]
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
 * FD14_FOD_Confidence: Integer in interval [0...3]
 * FD14_Frame_Index_Lanes_1: Integer in interval [0...65535]
 * FD14_Frame_Index_Lanes_2: Integer in interval [0...65535]
 * FD14_HAS_Status: Integer in interval [0...3]
 * FD14_Health_Front_Object_Detection: Integer in interval [0...3]
 * FD14_Health_Lane_Detection: Integer in interval [0...3]
 * FD14_LHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHF_Spin: Integer in interval [0...3]
 * FD14_LHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_LHR_Spin: Integer in interval [0...3]
 * FD14_LHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_LatAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LatAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_Line_1_Confidence: Integer in interval [0...15]
 * FD14_Line_1_Curvature: Integer in interval [0...65535]
 * FD14_Line_1_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_1_End_Range: Integer in interval [0...127]
 * FD14_Line_1_Heading: Integer in interval [0...1023]
 * FD14_Line_1_Offset: Integer in interval [0...1023]
 * FD14_Line_1_Start_Range: Integer in interval [0...127]
 * FD14_Line_1_Type: Integer in interval [0...15]
 * FD14_Line_2_Confidence: Integer in interval [0...15]
 * FD14_Line_2_Curvature: Integer in interval [0...65535]
 * FD14_Line_2_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_2_End_Range: Integer in interval [0...127]
 * FD14_Line_2_Heading: Integer in interval [0...1023]
 * FD14_Line_2_Offset: Integer in interval [0...1023]
 * FD14_Line_2_Start_Range: Integer in interval [0...127]
 * FD14_Line_2_Type: Integer in interval [0...15]
 * FD14_Line_3_Confidence: Integer in interval [0...15]
 * FD14_Line_3_Curvature: Integer in interval [0...65535]
 * FD14_Line_3_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_3_End_Range: Integer in interval [0...127]
 * FD14_Line_3_Heading: Integer in interval [0...1023]
 * FD14_Line_3_Offset: Integer in interval [0...1023]
 * FD14_Line_3_Start_Range: Integer in interval [0...127]
 * FD14_Line_3_Type: Integer in interval [0...15]
 * FD14_Line_4_Confidence: Integer in interval [0...15]
 * FD14_Line_4_Curvature: Integer in interval [0...65535]
 * FD14_Line_4_Curvature_Rate: Integer in interval [0...65535]
 * FD14_Line_4_End_Range: Integer in interval [0...127]
 * FD14_Line_4_Heading: Integer in interval [0...1023]
 * FD14_Line_4_Offset: Integer in interval [0...1023]
 * FD14_Line_4_Start_Range: Integer in interval [0...127]
 * FD14_Line_4_Type: Integer in interval [0...15]
 * FD14_LongAccelerationFailSts_BSM: Integer in interval [0...1]
 * FD14_LongAccelerationOffset_BSM: Integer in interval [0...255]
 * FD14_LwsAngle: Integer in interval [0...65535]
 * FD14_LwsAngleType: Integer in interval [0...3]
 * FD14_ManoeuvrePhase: Integer in interval [0...1]
 * FD14_PAM_Brk_Rq_RspSts: Integer in interval [0...3]
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
 * FD14_RHF_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHF_Spin: Integer in interval [0...3]
 * FD14_RHF_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_RHR_FastPulseCounter: Integer in interval [0...255]
 * FD14_RHR_Spin: Integer in interval [0...3]
 * FD14_RHR_WheelSensorFailSts: Integer in interval [0...1]
 * FD14_RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * FD14_RR_PAM_Dist: Integer in interval [0...1023]
 * FD14_Reserved_for_functional_safety: Integer in interval [0...4095]
 * FD14_SPM_Lat_Ctrl_RequestSts: Integer in interval [0...3]
 * FD14_SPM_Lat_Ctrl_ResponseSts: Integer in interval [0...3]
 * FD14_Segment_1_Confidence: Integer in interval [0...15]
 * FD14_Segment_1_ID: Integer in interval [0...15]
 * FD14_Segment_1_X1: Integer in interval [0...2047]
 * FD14_Segment_1_X2: Integer in interval [0...2047]
 * FD14_Segment_1_Y1: Integer in interval [0...1023]
 * FD14_Segment_1_Y2: Integer in interval [0...1023]
 * FD14_Segment_2_Confidence: Integer in interval [0...15]
 * FD14_Segment_2_ID: Integer in interval [0...15]
 * FD14_Segment_2_X1: Integer in interval [0...2047]
 * FD14_Segment_2_X2: Integer in interval [0...2047]
 * FD14_Segment_2_Y1: Integer in interval [0...1023]
 * FD14_Segment_2_Y2: Integer in interval [0...1023]
 * FD14_Segment_3_Confidence: Integer in interval [0...15]
 * FD14_Segment_3_ID: Integer in interval [0...15]
 * FD14_Segment_3_X1: Integer in interval [0...2047]
 * FD14_Segment_3_X2: Integer in interval [0...2047]
 * FD14_Segment_3_Y1: Integer in interval [0...1023]
 * FD14_Segment_3_Y2: Integer in interval [0...1023]
 * FD14_Segment_4_Confidence: Integer in interval [0...15]
 * FD14_Segment_4_ID: Integer in interval [0...15]
 * FD14_Segment_4_X1: Integer in interval [0...2047]
 * FD14_Segment_4_X2: Integer in interval [0...2047]
 * FD14_Segment_4_Y1: Integer in interval [0...1023]
 * FD14_Segment_4_Y2: Integer in interval [0...1023]
 * FD14_Segment_5_Confidence: Integer in interval [0...15]
 * FD14_Segment_5_ID: Integer in interval [0...15]
 * FD14_Segment_5_X1: Integer in interval [0...2047]
 * FD14_Segment_5_X2: Integer in interval [0...2047]
 * FD14_Segment_5_Y1: Integer in interval [0...1023]
 * FD14_Segment_5_Y2: Integer in interval [0...1023]
 * FD14_Segment_6_Confidence: Integer in interval [0...15]
 * FD14_Segment_6_ID: Integer in interval [0...15]
 * FD14_Segment_6_X1: Integer in interval [0...2047]
 * FD14_Segment_6_X2: Integer in interval [0...2047]
 * FD14_Segment_6_Y1: Integer in interval [0...1023]
 * FD14_Segment_6_Y2: Integer in interval [0...1023]
 * FD14_Segment_7_Confidence: Integer in interval [0...15]
 * FD14_Segment_7_ID: Integer in interval [0...15]
 * FD14_Segment_7_X1: Integer in interval [0...2047]
 * FD14_Segment_7_X2: Integer in interval [0...2047]
 * FD14_Segment_7_Y1: Integer in interval [0...1023]
 * FD14_Segment_7_Y2: Integer in interval [0...1023]
 * FD14_Segment_8_Confidence: Integer in interval [0...15]
 * FD14_Segment_8_ID: Integer in interval [0...15]
 * FD14_Segment_8_X1: Integer in interval [0...2047]
 * FD14_Segment_8_X2: Integer in interval [0...2047]
 * FD14_Segment_8_Y1: Integer in interval [0...1023]
 * FD14_Segment_8_Y2: Integer in interval [0...1023]
 * FD14_Slope: Integer in interval [0...255]
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
 * FD14_VehicleStandStillSts: Integer in interval [0...3]
 * FD14_YawRateFailSts_BSM: Integer in interval [0...1]
 * FL_Lvl_Adj: Integer in interval [0...1]
 * FOD_Confidence: Integer in interval [0...3]
 * FR_Lvl_Adj: Integer in interval [0...1]
 * FT_PAMRequestSts: Integer in interval [0...1]
 * FT_PAM_LedControlSts: Integer in interval [0...3]
 * Frame_Index_Lanes_1: Integer in interval [0...65535]
 * Frame_Index_Lanes_2: Integer in interval [0...65535]
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
 * Health_Front_Object_Detection: Integer in interval [0...3]
 * Health_Lane_Detection: Integer in interval [0...3]
 * ITBM_TrlrStat: Integer in interval [0...3]
 * IgnitionOnCounter: Integer in interval [0...65535]
 * ImageDefeatRQSts: Integer in interval [0...1]
 * LHF_FastPulseCounter: Integer in interval [0...255]
 * LHF_Spin: Integer in interval [0...3]
 * LHRDoorSts: Integer in interval [0...1]
 * LHR_FastPulseCounter: Integer in interval [0...255]
 * LHR_Spin: Integer in interval [0...3]
 * LanguageSelection: Integer in interval [0...255]
 * Line_1_Confidence: Integer in interval [0...15]
 * Line_1_Curvature: Integer in interval [0...65535]
 * Line_1_Curvature_Rate: Integer in interval [0...65535]
 * Line_1_End_Range: Integer in interval [0...127]
 * Line_1_Heading: Integer in interval [0...1023]
 * Line_1_Offset: Integer in interval [0...1023]
 * Line_1_Start_Range: Integer in interval [0...127]
 * Line_1_Type: Integer in interval [0...15]
 * Line_2_Confidence: Integer in interval [0...15]
 * Line_2_Curvature: Integer in interval [0...65535]
 * Line_2_Curvature_Rate: Integer in interval [0...65535]
 * Line_2_End_Range: Integer in interval [0...127]
 * Line_2_Heading: Integer in interval [0...1023]
 * Line_2_Offset: Integer in interval [0...1023]
 * Line_2_Start_Range: Integer in interval [0...127]
 * Line_2_Type: Integer in interval [0...15]
 * Line_3_Confidence: Integer in interval [0...15]
 * Line_3_Curvature: Integer in interval [0...65535]
 * Line_3_Curvature_Rate: Integer in interval [0...65535]
 * Line_3_End_Range: Integer in interval [0...127]
 * Line_3_Heading: Integer in interval [0...1023]
 * Line_3_Offset: Integer in interval [0...1023]
 * Line_3_Start_Range: Integer in interval [0...127]
 * Line_3_Type: Integer in interval [0...15]
 * Line_4_Confidence: Integer in interval [0...15]
 * Line_4_Curvature: Integer in interval [0...65535]
 * Line_4_Curvature_Rate: Integer in interval [0...65535]
 * Line_4_End_Range: Integer in interval [0...127]
 * Line_4_Heading: Integer in interval [0...1023]
 * Line_4_Offset: Integer in interval [0...1023]
 * Line_4_Start_Range: Integer in interval [0...127]
 * Line_4_Type: Integer in interval [0...15]
 * LwsAngleType: Integer in interval [0...3]
 * ME_Hydra3defs_E_CalibStatus_t: Integer in interval [0...4294967295]
 * ME_Hydra3defs_E_CalibrationID_t: Integer in interval [0...4294967295]
 * MRM_STATUS_C2: Integer in interval [0...7]
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
 * PPPA_TurnIndicatorRqst: Integer in interval [0...3]
 * PamChimeVolumeFront: Integer in interval [0...3]
 * PamChimeVolumeRear: Integer in interval [0...3]
 * ParkingManeuverActive: Integer in interval [0...7]
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
 * RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * RR_PAM_Dist: Integer in interval [0...1023]
 * RR_PAM_StopControlSts: Integer in interval [0...1]
 * RearSensorSts: Integer in interval [0...3]
 * Rear_Brk_Asst: Integer in interval [0...1]
 * RemStActvSts: Integer in interval [0...1]
 * Reserved_for_functional_safety: Integer in interval [0...4095]
 * Rte_DT_StayActiveSource_FD02_PAM_0: Integer in interval [0...4]
 * SBR1RowDriverSeatSts: Integer in interval [0...3]
 * SPMControlSts: Integer in interval [0...3]
 * SPMFailSts: Integer in interval [0...1]
 * SPMSystemFault: Integer in interval [0...1]
 * SPM_LedControlSts: Integer in interval [0...3]
 * SPM_Screen_Rqst: Integer in interval [0...1]
 * SVC_Guidelines: Integer in interval [0...1]
 * Segment_1_Confidence: Integer in interval [0...15]
 * Segment_1_ID: Integer in interval [0...15]
 * Segment_1_X1: Integer in interval [0...2047]
 * Segment_1_X2: Integer in interval [0...2047]
 * Segment_1_Y1: Integer in interval [0...1023]
 * Segment_1_Y2: Integer in interval [0...1023]
 * Segment_2_Confidence: Integer in interval [0...15]
 * Segment_2_ID: Integer in interval [0...15]
 * Segment_2_X1: Integer in interval [0...2047]
 * Segment_2_X2: Integer in interval [0...2047]
 * Segment_2_Y1: Integer in interval [0...1023]
 * Segment_2_Y2: Integer in interval [0...1023]
 * Segment_3_Confidence: Integer in interval [0...15]
 * Segment_3_ID: Integer in interval [0...15]
 * Segment_3_X1: Integer in interval [0...2047]
 * Segment_3_X2: Integer in interval [0...2047]
 * Segment_3_Y1: Integer in interval [0...1023]
 * Segment_3_Y2: Integer in interval [0...1023]
 * Segment_4_Confidence: Integer in interval [0...15]
 * Segment_4_ID: Integer in interval [0...15]
 * Segment_4_X1: Integer in interval [0...2047]
 * Segment_4_X2: Integer in interval [0...2047]
 * Segment_4_Y1: Integer in interval [0...1023]
 * Segment_4_Y2: Integer in interval [0...1023]
 * Segment_5_Confidence: Integer in interval [0...15]
 * Segment_5_ID: Integer in interval [0...15]
 * Segment_5_X1: Integer in interval [0...2047]
 * Segment_5_X2: Integer in interval [0...2047]
 * Segment_5_Y1: Integer in interval [0...1023]
 * Segment_5_Y2: Integer in interval [0...1023]
 * Segment_6_Confidence: Integer in interval [0...15]
 * Segment_6_ID: Integer in interval [0...15]
 * Segment_6_X1: Integer in interval [0...2047]
 * Segment_6_X2: Integer in interval [0...2047]
 * Segment_6_Y1: Integer in interval [0...1023]
 * Segment_6_Y2: Integer in interval [0...1023]
 * Segment_7_Confidence: Integer in interval [0...15]
 * Segment_7_ID: Integer in interval [0...15]
 * Segment_7_X1: Integer in interval [0...2047]
 * Segment_7_X2: Integer in interval [0...2047]
 * Segment_7_Y1: Integer in interval [0...1023]
 * Segment_7_Y2: Integer in interval [0...1023]
 * Segment_8_Confidence: Integer in interval [0...15]
 * Segment_8_ID: Integer in interval [0...15]
 * Segment_8_X1: Integer in interval [0...2047]
 * Segment_8_X2: Integer in interval [0...2047]
 * Segment_8_Y1: Integer in interval [0...1023]
 * Segment_8_Y2: Integer in interval [0...1023]
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
 * TRSC_LED_Stat: Integer in interval [0...3]
 * TRSC_PopupDisp_Info: Integer in interval [0...15]
 * TRSC_PopupDisp_Info2: Integer in interval [0...63]
 * TRSC_RawKnob: Integer in interval [0...511]
 * TRSC_STAT: Integer in interval [0...7]
 * TRSC_SpeedLimit_Req: Integer in interval [0...15]
 * TRSC_SteeringTorqueReq: Integer in interval [0...3]
 * TRSC_VehicleStop_Req: Integer in interval [0...3]
 * TargetGear: Integer in interval [0...15]
 * TeAP_e_FrntSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_PAMOffStatus2BT: Integer in interval [0...4294967295]
 * TeAP_e_PAMSystemFault: Integer in interval [0...4294967295]
 * TeAP_e_RearSnsrStatus: Integer in interval [0...4294967295]
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
 * VoltMgr_Enum_VoltageMON: Integer in interval [0...255]
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
 * DataArrayType_uint8_1: Array with 1 element(s) of type uint8
 * DataArrayType_uint8_2: Array with 2 element(s) of type uint8
 * DataArrayType_uint8_3: Array with 3 element(s) of type uint8
 * DataArrayType_uint8_9: Array with 9 element(s) of type uint8
 * EOLIterationData_arr: Array with 5 element(s) of type uint8
 * ErrorListArr_B: Array with 35 element(s) of type uint32
 * ErrorListArr_QM: Array with 1 element(s) of type uint32
 * FD14_MAC_ADAS_FD_LANES_1: Array with 6 element(s) of type uint8
 * FD14_MAC_ADAS_FD_LANES_2: Array with 6 element(s) of type uint8
 * MAC_ADAS_FD_LANES_1: Array with 6 element(s) of type uint8
 * MAC_ADAS_FD_LANES_2: Array with 6 element(s) of type uint8
 * N_PDU: Array with 8 element(s) of type uint8
 * Reserved_arr: Array with 7 element(s) of type uint8
 * StayActiveSource_FD02_PAM: Array with 8 element(s) of type Rte_DT_StayActiveSource_FD02_PAM_0
 * VIN_DATA: Array with 7 element(s) of type uint8
 * vRoE_MessageType: Array with 8 element(s) of type uint8
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
 * DtcAddData_B: Record with elements
 *   b210c_16_0 of type AdditionalData_arr
 *   b210c_17_0 of type AdditionalData_arr
 *   u104e_0_0 of type AdditionalData_arr
 *   u100b_0_0 of type AdditionalData_arr
 *   u0140_0_0 of type AdditionalData_arr
 *   u0184_0_0 of type AdditionalData_arr
 *   b223b_0_0 of type AdditionalData_arr
 *   u0129_0_0 of type AdditionalData_arr
 *   u0131_0_0 of type AdditionalData_arr
 *   u0418_0_0 of type AdditionalData_arr
 *   u0420_0_0 of type AdditionalData_arr
 *   u0422_0_0 of type AdditionalData_arr
 *   u0485_0_0 of type AdditionalData_arr
 *   b12b2_2a_0 of type AdditionalData_arr
 *   b1285_2a_0 of type AdditionalData_arr
 *   b128e_13_0 of type AdditionalData_arr
 *   b128f_13_0 of type AdditionalData_arr
 *   b1290_13_0 of type AdditionalData_arr
 *   b1291_13_0 of type AdditionalData_arr
 *   b1292_13_0 of type AdditionalData_arr
 *   b1293_13_0 of type AdditionalData_arr
 *   b1294_13_0 of type AdditionalData_arr
 *   b1295_13_0 of type AdditionalData_arr
 *   b1296_13_0 of type AdditionalData_arr
 *   b1297_13_0 of type AdditionalData_arr
 *   b1298_13_0 of type AdditionalData_arr
 *   b1299_13_0 of type AdditionalData_arr
 *   b128e_92_0 of type AdditionalData_arr
 *   b128f_92_0 of type AdditionalData_arr
 *   b1290_92_0 of type AdditionalData_arr
 *   b1291_92_0 of type AdditionalData_arr
 *   b1292_92_0 of type AdditionalData_arr
 *   b1293_92_0 of type AdditionalData_arr
 *   b1294_92_0 of type AdditionalData_arr
 *   b1295_92_0 of type AdditionalData_arr
 *   b1296_92_0 of type AdditionalData_arr
 *   b1297_92_0 of type AdditionalData_arr
 *   b1298_92_0 of type AdditionalData_arr
 *   b1299_92_0 of type AdditionalData_arr
 *   b212a_16_0 of type AdditionalData_arr
 *   b212b_16_0 of type AdditionalData_arr
 *   b22a9_0_0 of type AdditionalData_arr
 *   b23c6_92_0 of type AdditionalData_arr
 *   u0267_0_0 of type AdditionalData_arr
 *   b23c7_92_0 of type AdditionalData_arr
 *   u0266_0_0 of type AdditionalData_arr
 *   u0264_0_0 of type AdditionalData_arr
 *   b217a_92_0 of type AdditionalData_arr
 *   u0265_0_0 of type AdditionalData_arr
 *   b23c5_92_0 of type AdditionalData_arr
 *   b217a_1c_0 of type AdditionalData_arr
 *   b23c5_1c_0 of type AdditionalData_arr
 *   b23c6_1c_0 of type AdditionalData_arr
 *   b23c7_1c_0 of type AdditionalData_arr
 *   b2286_0_0 of type AdditionalData_arr
 *   c2212_0_0 of type AdditionalData_arr
 *   b212a_17_0 of type AdditionalData_arr
 *   b212b_17_0 of type AdditionalData_arr
 *   u0100_0_0 of type AdditionalData_arr
 *   u0401_0_0 of type AdditionalData_arr
 *   b212a_8_0 of type AdditionalData_arr
 *   b212b_8_0 of type AdditionalData_arr
 * DtcAddData_QM: Record with elements
 *   u0151_0_0 of type AdditionalData_arr
 *   u12b9_0_0 of type AdditionalData_arr
 *   u14a0_0_0 of type AdditionalData_arr
 *   u0455_0_0 of type AdditionalData_arr
 * DtcStatus_B: Record with elements
 *   b210c_16_0 of type uint8
 *   b210c_17_0 of type uint8
 *   u104e_0_0 of type uint8
 *   u100b_0_0 of type uint8
 *   u0140_0_0 of type uint8
 *   u0184_0_0 of type uint8
 *   b223b_0_0 of type uint8
 *   u0129_0_0 of type uint8
 *   u0131_0_0 of type uint8
 *   u0418_0_0 of type uint8
 *   u0420_0_0 of type uint8
 *   u0422_0_0 of type uint8
 *   u0485_0_0 of type uint8
 *   b12b2_2a_0 of type uint8
 *   b1285_2a_0 of type uint8
 *   b128e_13_0 of type uint8
 *   b128f_13_0 of type uint8
 *   b1290_13_0 of type uint8
 *   b1291_13_0 of type uint8
 *   b1292_13_0 of type uint8
 *   b1293_13_0 of type uint8
 *   b1294_13_0 of type uint8
 *   b1295_13_0 of type uint8
 *   b1296_13_0 of type uint8
 *   b1297_13_0 of type uint8
 *   b1298_13_0 of type uint8
 *   b1299_13_0 of type uint8
 *   b128e_92_0 of type uint8
 *   b128f_92_0 of type uint8
 *   b1290_92_0 of type uint8
 *   b1291_92_0 of type uint8
 *   b1292_92_0 of type uint8
 *   b1293_92_0 of type uint8
 *   b1294_92_0 of type uint8
 *   b1295_92_0 of type uint8
 *   b1296_92_0 of type uint8
 *   b1297_92_0 of type uint8
 *   b1298_92_0 of type uint8
 *   b1299_92_0 of type uint8
 *   b212a_16_0 of type uint8
 *   b212b_16_0 of type uint8
 *   b22a9_0_0 of type uint8
 *   b23c6_92_0 of type uint8
 *   u0267_0_0 of type uint8
 *   b23c7_92_0 of type uint8
 *   u0266_0_0 of type uint8
 *   u0264_0_0 of type uint8
 *   b217a_92_0 of type uint8
 *   u0265_0_0 of type uint8
 *   b23c5_92_0 of type uint8
 *   b217a_1c_0 of type uint8
 *   b23c5_1c_0 of type uint8
 *   b23c6_1c_0 of type uint8
 *   b23c7_1c_0 of type uint8
 *   b2286_0_0 of type uint8
 *   c2212_0_0 of type uint8
 *   b212a_17_0 of type uint8
 *   b212b_17_0 of type uint8
 *   u0100_0_0 of type uint8
 *   u0401_0_0 of type uint8
 *   b212a_8_0 of type uint8
 *   b212b_8_0 of type uint8
 * DtcStatus_QM: Record with elements
 *   u0151_0_0 of type uint8
 *   u12b9_0_0 of type uint8
 *   u14a0_0_0 of type uint8
 *   u0455_0_0 of type uint8
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
 * TbAP_APSMPAOut_t: Record with elements
 *   IeAP_e_PAMFlt of type TeAP_e_PAMSystemFault
 *   IeAP_e_FrntRearParkSts of type TeAP_e_PAMOffStatus2BT
 *   IeAP_e_FrntSensorActvSts of type TeAP_e_FrntSnsrStatus
 *   IeAP_e_RearSnsrActvSts of type TeAP_e_RearSnsrStatus
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_DTC_APARequestSts_PAMRequestSts_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 Rte_CData_DTC_APARequestSts_PAMRequestSts_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define SWC_DTCMgr_START_SEC_CODE
#include "SWC_DTCMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x1002_Vehicle_Speed_24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData (returns application error)
 *********************************************************************************************************************/
   /*ReqID:-16323767*/
   /*GUID:-{5A5E7D9B-ECF0-4c87-8A42-A4A20386C2B0}*/
  /* DD-ID: {5A5E7D9B-ECF0-4c87-8A42-A4A20386C2B0}*/
    VehicleSpeedVSOSig v_vehicleSpd_u16;

    /*Get Vehicle Speed*/
    (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_vehicleSpd_u16);

    /*Send Vehicle Speed Response Data*/
    v_vehicleSpd_u16 = (uint16)((float32)v_vehicleSpd_u16 * D_SPEED_CONV_FACTOR);
    Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_vehicleSpd_u16,BIT_SHIFT_EIGHT_BIT);
    Data[e_ONE]  = (uint8)v_vehicleSpd_u16;
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x1004_Battery_Voltage_24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x1004_Battery_Voltage_24_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:-16323767*/
  /*GUID:-{9E8EA79F-381E-4701-A3ED-B4C2F7DB2FAE}*/
  /* DD-ID: {9E8EA79F-381E-4701-A3ED-B4C2F7DB2FAE}*/
  float32 v_BatteryVoltageValue_f32;
  uint8 v_BatteryVoltageScaledValue_u8;

  /*Get Battery Voltage*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVoltageValue_f32);

  /* Scailing Voltage*/
  v_BatteryVoltageScaledValue_u8 = (uint8)(v_BatteryVoltageValue_f32 * (uint8)D_VOLTAGE_SCALING_FACTOR);

  /*Send Response Data*/
  VStdLib_MemCpy(Data, &v_BatteryVoltageScaledValue_u8, sizeof(v_BatteryVoltageScaledValue_u8));

  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x1008_ECU_Life_Time_24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:-16323767*/
  /*GUID:-{72A20C70-8656-4d81-AA23-9E4129FFB368}*/
  /* DD-ID: {72A20C70-8656-4d81-AA23-9E4129FFB368}*/
  uint32 v_EcuLifeTime_u32;

 (void)Rte_Read_RpECUTimeStamp_ECUTimeStamp(&v_EcuLifeTime_u32);

  Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_EcuLifeTime_u32,BIT_SHIFT_SIXTEEN_BIT);
  Data[e_ONE] = (uint8)RIGHTSHIFT_BIT(v_EcuLifeTime_u32,BIT_SHIFT_EIGHT_BIT);
  Data[e_TWO] = (uint8)(v_EcuLifeTime_u32);

 return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData (returns application error)
 *********************************************************************************************************************/
  /*ReqID:-16323767*/
  /*GUID:-{87007F3D-F0FD-48b5-B79A-1BF36A59A954}*/
  /* DD-ID: {87007F3D-F0FD-48b5-B79A-1BF36A59A954}*/
  uint32 v_EcuTime_u32;

  (void)Rte_Read_RpECUTimeSinceIGON_ECUTimeStamp_IGON(&v_EcuTime_u32);

  Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_EcuTime_u32, BIT_SHIFT_EIGHT_BIT);
  Data[e_ONE] = (uint8)(v_EcuTime_u32);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x1921_CombinedSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_9
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x1921_CombinedSignal_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData (returns application error)
 *********************************************************************************************************************/
    /*ReqID:-16323767*/
	/*GUID:-{419F4536-F657-4621-BCD6-9678163E2C6A}*/
  /* DD-ID: {419F4536-F657-4621-BCD6-9678163E2C6A}*/
  Std_ReturnType v_retVal_u8;
  CmdIgnSts v_IGStatus_u8;
  uint8 v_StatusData0_u8=(uint8)e_ZERO;
  uint8 v_StatusData1_u8=(uint8)e_ZERO;
  OperationalModeSts v_OpModeStatus_u8;

  (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&v_IGStatus_u8);
  (void)Rte_Read_RpToSwcFD02Rx_OperationalModeSts(&v_OpModeStatus_u8);
 
 if (NULL_PTR != Data)
  {
    VStdLib_MemClr(Data,DID_1921_DATA_LEN);

    v_StatusData0_u8 = (v_OpModeStatus_u8 == SECOND_BIT)? TRUE : FALSE;  /*Ignition Off- 0x2*/
    Data[e_ZERO] = v_StatusData0_u8;
    v_StatusData0_u8 = (v_OpModeStatus_u8  == THIRD_BIT)? TRUE : FALSE;  /*Ignition Acc-0x3*/
    Data[e_ZERO] |=  (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_ONE_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8  == FOURTH_BIT)? TRUE : FALSE;  /*Ignition On-0x4*/
    Data[e_ZERO] |=  (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_TWO_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8  == FIFTH_BIT)? TRUE : FALSE;  /*Ignition Pre Start-0x5*/
    Data[e_ZERO] |=  (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_THREE_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8  == SIXTH_BIT)? TRUE : FALSE;  /*Ignition Start-0x6*/
    Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_FOUR_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8  == SEVENTH_BIT)? TRUE : FALSE;  /* Ignition Cranking- 0x7*/
    Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_FIVE_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8 == EIGHTH_BIT)? TRUE : FALSE;  /*Ignition On Eng On -0x8*/
    Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_SIX_BIT);
    v_StatusData0_u8 = (v_OpModeStatus_u8  == TENTH_BIT)? TRUE : FALSE;  /*Ignition Pre Off-0xA*/
    Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(v_StatusData0_u8,BIT_SHIFT_SEVEN_BIT);

    v_StatusData0_u8 = (v_OpModeStatus_u8  == NINTH_BIT)? TRUE : FALSE;  /* Ignition Pre Acc-0x9  */
    Data[e_ONE] = v_StatusData0_u8;

    v_StatusData1_u8 = (v_IGStatus_u8 == FIRST_BIT)? TRUE : FALSE;    /* IGN LK (STOP)-0x1  */
    Data[e_SEVEN]   = v_StatusData1_u8;
    v_StatusData1_u8 = (v_IGStatus_u8 == THIRD_BIT)? TRUE : FALSE;    /*ACC-0x3  */
    Data[e_SEVEN] |=  (uint8)LEFTSHIFT_BIT(v_StatusData1_u8,BIT_SHIFT_ONE_BIT);
    v_StatusData1_u8 = (v_IGStatus_u8  == FOURTH_BIT)? TRUE : FALSE;     /*RUN (MAR)-0x4  */
    Data[e_SEVEN] |= (uint8)LEFTSHIFT_BIT(v_StatusData1_u8, BIT_SHIFT_TWO_BIT);
    v_StatusData1_u8 = (v_IGStatus_u8 == FIFTH_BIT)? TRUE : FALSE;    /*START-0x5 */
    Data[e_SEVEN] |= (uint8)LEFTSHIFT_BIT(v_StatusData1_u8,BIT_SHIFT_THREE_BIT);
    v_StatusData1_u8 = (v_IGStatus_u8 == ZEROTH_BIT)? TRUE : FALSE;    /*INITIALIZATION-0x0*/
    Data[e_SEVEN] |= (uint8)LEFTSHIFT_BIT(v_StatusData1_u8,BIT_SHIFT_FOUR_BIT);
    v_StatusData1_u8 = (v_IGStatus_u8 == SEVENTH_BIT)? TRUE : FALSE;     /*SNA (Signal Not Available)-0x7 */
    Data[e_SEVEN] |= (uint8)LEFTSHIFT_BIT(v_StatusData1_u8, BIT_SHIFT_SEVEN_BIT);

   v_retVal_u8 = RTE_E_OK;
 
  }
  else
  {
    v_retVal_u8 = RTE_E_INVALID;
  }
 
  return v_retVal_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x2001_Odometer_24_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x2001_Odometer_24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x2001_Odometer_24_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x2001_Odometer_24_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x2001_Odometer_24_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x2001_Odometer_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x2001_Odometer_24_ReadData (returns application error)
 *********************************************************************************************************************/
 /*ReqID:-16323767*/
 /*GUID:-{FBEB4B61-7873-4944-A53F-35D64E458431}*/
  /* DD-ID: {FBEB4B61-7873-4944-A53F-35D64E458431}*/
    uint32 v_TotalOdometerValue_u32;
    uint16 v_TotalOdometerScaledValue_u16;

    /* Read Total Odometer Value */
   (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&v_TotalOdometerValue_u32);

    /* Scale Odometer Value Before Sending */
    v_TotalOdometerScaledValue_u16 = ((uint16)(v_TotalOdometerValue_u32 / (uint32)D_ODOMETER_SCALING_FACTOR));

    Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_TotalOdometerScaledValue_u16,BIT_SHIFT_EIGHT_BIT);
    Data[e_ONE] = (uint8)(v_TotalOdometerScaledValue_u16);
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData (returns application error)
 *********************************************************************************************************************/
   /*ReqID:-16323767*/
   /*GUID:-{538DE106-B855-4440-93D7-2BDFF42596B7}*/
  /* DD-ID: {538DE106-B855-4440-93D7-2BDFF42596B7}*/
  uint16 v_IgCounter_u16;
  (void)Rte_Read_RpIgOnCounter_IGCounter(&v_IgCounter_u16);

  Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_IgCounter_u16,BIT_SHIFT_EIGHT_BIT);
  Data[e_ONE] = (uint8)v_IgCounter_u16;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {30DF092B-4D27-4cfb-9AB1-8C9EEEA60F9D}*/
  Data[0] = AGING_COUNTER_ID;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {4B744363-CE6F-40ad-8B96-0FF4FB60E2EC}*/
  uint8 v_Front_u8;
  uint8 v_Left_u8;
  uint8 v_Rear_u8;
  uint8 v_Right_u8;
  
  CalDataProvider_MCU_1_0_Def CalDataProvider_NvmCalibData;
  (void)Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(&CalDataProvider_NvmCalibData);
    
  /*Front Camera calibration status*/
  v_Front_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Left Camera calibration status*/
  v_Left_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Rear Camera calibration status*/
  v_Rear_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Right Camera calibration status*/
  v_Right_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  
  if((v_Front_u8 == ME_Hydra3defs_E_CalibCompletedSuccessful) && (v_Left_u8 == ME_Hydra3defs_E_CalibCompletedSuccessful) && (v_Rear_u8 == ME_Hydra3defs_E_CalibCompletedSuccessful) && (v_Right_u8 == ME_Hydra3defs_E_CalibCompletedSuccessful))
  {
        Data[e_ZERO] = 0x00u;
  }
  else
  {
        Data[e_ZERO] = 0x01u;
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {5D5BF320-7587-445e-A1D0-855A484F3677}*/
  uint8 v_Front_u8;
  uint8 v_Left_u8;
  uint8 v_Rear_u8;
  uint8 v_Right_u8;
  
  CalDataProvider_MCU_1_0_Def CalDataProvider_NvmCalibData;
  (void)Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(&CalDataProvider_NvmCalibData);
    
  /*Front Camera calibration status*/
  v_Front_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Left Camera calibration status*/
  v_Left_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Rear Camera calibration status*/
  v_Rear_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Right Camera calibration status*/
  v_Right_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  
  if((v_Front_u8 == ME_Hydra3defs_E_CalibAbortedFailed) || (v_Left_u8 == ME_Hydra3defs_E_CalibAbortedFailed) || (v_Rear_u8 == ME_Hydra3defs_E_CalibAbortedFailed) || (v_Right_u8 == ME_Hydra3defs_E_CalibAbortedFailed))
  {
        Data[e_ZERO] = 0x00u;
  }
  else
  {
        Data[e_ZERO] = 0x01u;
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {64F4D59B-A9C9-4d5a-B051-E9193E8C98F4}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Calibration_Pending>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Pending_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {0F493113-F0E5-4197-BCD6-1EF35E593E6F}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Calibration_Running>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Running_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {DDA25832-BDAC-4b13-BDDC-0ACFFFB99483}*/
  uint8 v_Front_u8;
  uint8 v_Left_u8;
  uint8 v_Rear_u8;
  uint8 v_Right_u8;
  
  CalDataProvider_MCU_1_0_Def CalDataProvider_NvmCalibData;
  (void)Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(&CalDataProvider_NvmCalibData);
    
  /*Front Camera calibration status*/
  v_Front_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamFrontCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Left Camera calibration status*/
  v_Left_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamLeftCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Rear Camera calibration status*/
  v_Rear_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRearCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  /*Right Camera calibration status*/
  v_Right_u8 = (uint8)(CalDataProvider_NvmCalibData.CalData_SVSCamCurrentCalibData.CamRightCurrent.CamCalibData_STM.calibdata.CalibStatus_e);
  
  if((v_Front_u8 == ME_Hydra3defs_E_CalibRunning) || (v_Left_u8 == ME_Hydra3defs_E_CalibRunning) || (v_Rear_u8 == ME_Hydra3defs_E_CalibRunning) || (v_Right_u8 == ME_Hydra3defs_E_CalibRunning))
  {
      Data[e_ZERO] = 0x00u;
  }
  else
  {
      Data[e_ZERO] = 0x01u;
  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Camera_Occlusion>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {804DD514-9ED5-4903-A5B4-465F53C11034}*/
  JobDLDOutput_t CamOcclusion;
  (void)Rte_Read_RpDLDOutput_JobDLDOutput_t(&CamOcclusion);
  if(DLD_Blockage == (uint8)CamOcclusion.IeDLD_e_RrCamSts)
  {
        Data[e_ZERO] = CAMERA_BLOCKED;
  }
  else if(DLD_Normal == (uint8)CamOcclusion.IeDLD_e_RrCamSts)
  {
        Data[e_ZERO] = CAMERA_CLEAR;
  }
  else
  {
        Data[e_ZERO] = (uint8)CamOcclusion.IeDLD_e_RrCamSts;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Current_Gear>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Current_Gear_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {643849E0-24C6-48da-809C-4BD573FE70F7}*/
  GearEngaged GearStatus;
  (void)Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(&GearStatus);
  Data[e_ZERO] = GearStatus;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {F4A24025-E20B-4918-96F1-8359F7470187}*/
  Data[e_ZERO] = CYCLE_SWITCH_OFF_WI_ID;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_DisplayStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_DisplayStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {A821E2D2-0A62-4899-BE42-0DCB8F2157EE}*/
  CameraDisplaySts2 CamDisplaySts;
  DisplayView2 DisplayView;
  uint8 Convertdata;

  (void)Rte_Read_RpToSwcSafeFD02Rx_CameraDisplaySts2(&CamDisplaySts);
  (void)Rte_Read_RpToSwcSafeFD02Tx_DisplayView2(&DisplayView);

  Data[e_ZERO] = (uint8)CHECK_BIT(CamDisplaySts,BIT_MASK_FOUR_BIT);
  Convertdata =  CHECK_BIT(DisplayView,BIT_MASK_FOUR_BIT);
  Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(Convertdata,BIT_SHIFT_FOUR_BIT);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Door_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Door_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {F401759E-3479-4e08-BAEC-F977035CB703}*/
  LHRDoorSts LHRDoorStatus;
  PsngrDoorSts PsngrDoorStatus;
  RHRDoorSts RHRDoorStatus;
  DriverDoorSts DriverDoorStatus;
  ShiftLeverPosition ShiftLeverPos;
  uint8 convertdata;

  (void)Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts(&LHRDoorStatus);
  (void)Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts(&PsngrDoorStatus);
  (void)Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts(&RHRDoorStatus);
  (void)Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts(&DriverDoorStatus);
  (void)Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(&ShiftLeverPos);

  convertdata = (uint8)CHECK_BIT(DriverDoorStatus, BIT_MASK_ONE_BIT);
  Data[e_ZERO] = (uint8)LEFTSHIFT_BIT(convertdata,BIT_SHIFT_ZERO_BIT);
  convertdata = (uint8)CHECK_BIT(LHRDoorStatus, BIT_MASK_ONE_BIT);
  Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(convertdata, BIT_SHIFT_ONE_BIT);
  convertdata =(uint8)CHECK_BIT(PsngrDoorStatus, BIT_MASK_ONE_BIT);
  Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(convertdata ,BIT_SHIFT_TWO_BIT);
  convertdata = (uint8)CHECK_BIT(RHRDoorStatus,BIT_MASK_ONE_BIT);
  Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(convertdata , BIT_SHIFT_THREE_BIT);
  convertdata = (uint8)CHECK_BIT(ShiftLeverPos, BIT_MASK_FOUR_BIT);
  Data[e_ZERO] |= (uint8)LEFTSHIFT_BIT(convertdata , BIT_SHIFT_FOUR_BIT);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_ECU_Voltage>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_ECU_Voltage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {57C5B891-686D-4422-B959-4D4BAF9F54EE}*/
  float32 v_BatteryVoltageValue_f32;
  uint8 v_BatteryVoltageScaledValue_u8;

  /*Get Battery Voltage*/
  (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVoltageValue_f32);

  /* Scailing Voltage*/
  v_BatteryVoltageScaledValue_u8 = (uint8)(v_BatteryVoltageValue_f32 * (uint8)D_VOLTAGE_SCALING_FACTOR);
  
  /*Send Response Data*/
  VStdLib_MemCpy(Data, &v_BatteryVoltageScaledValue_u8, sizeof(v_BatteryVoltageScaledValue_u8));
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_External_Temperature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_External_Temperature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {43366978-0505-4ecd-B9FE-068B3474A25B}*/
  uint16 v_ExtTemp_u16;
  (void)Rte_Read_RpToSwcSafeFD02Rx_ExternalTemperature(&v_ExtTemp_u16);

  Data[e_ZERO] = v_ExtTemp_u16;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {2092FB19-BE75-45f6-A127-85F315DDD1A2}*/
 Data[0] = FREQUENCY_COUNTER_ID;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_LiftgateAjar>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_LiftgateAjar_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData (returns application error)
 *********************************************************************************************************************/
   /* DD-ID: {C6B8202F-43C8-4aff-BE91-141C86FAC1CD} */
   RHatchSts Liftgateajar;

  VStdLib_MemClr(Data,(uint8)e_ONE);
  (void)Rte_Read_RpToSwcSafeFD02Rx_RHatchSts(&Liftgateajar);
  Data[e_ZERO] = Liftgateajar;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_New_Bit_Field>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_New_Bit_Field_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {25AD9835-F21F-40c1-9223-6D4AA691880A}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Odometer_Value>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Odometer_Value_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {B4962EB0-E1DA-4a32-9778-739561808EB8}*/
    uint32 v_TotalOdometerValue_u32;

    /* Read Total Odometer Value */
   (void)Rte_Read_RpToSwcFD02Rx_TotalOdometer(&v_TotalOdometerValue_u32);

    Data[e_ZERO] = (uint8)RIGHTSHIFT_BIT(v_TotalOdometerValue_u32,(uint8)e_SIXTEEN);
    Data[e_ONE] = (uint8)RIGHTSHIFT_BIT(v_TotalOdometerValue_u32,(uint8)e_EIGHT);
    Data[e_TWO] = (uint8)(v_TotalOdometerValue_u32);
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Radio_Display_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {BFED8390-D9E6-41ba-BB5E-0B077819FB7E}*/
  TGW_CAMERA_DISP_STAT RedioDisplayType;

  VStdLib_MemClr(Data,(uint8)e_ONE);
  (void)Rte_Read_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(&RedioDisplayType);
  Data[e_ZERO] = (uint8)CHECK_BIT(RedioDisplayType, BIT_MASK_FOUR_BIT);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Reserved_1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_1_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {A5030B27-A5E9-42da-8CD1-64EA5C81D979}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Reserved_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {6F1D1067-8461-486c-8FA4-887DA6F145E0}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Reserved_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Reserved>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Reserved_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Reserved_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {C0A5346B-EF01-4bf9-8571-765E14C5A6C7}*/
  Data[e_ZERO] = 0x00u;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {EE257E4E-62C7-438c-A81D-B3A676DECD6A}*/
  FD14_LwsAngle v_fLwsAngle_u16;
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(&v_fLwsAngle_u16);
  Data[e_ZERO]  = v_fLwsAngle_u16;

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_9
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {B782B62C-7F8F-43a0-9FAA-4DF0B11BFA10}*/
   uint32 ErrorListArr_B[SIZEOF_ERROR_B_DATA] = {0u};
   uint32 ErrorListArr_QM[SIZEOF_ERROR_QM_DATA] = {0u};
   static uint32  ErrorListArr_B_OR_VALUE[SIZEOF_ERROR_B_DATA] = {0u};
   static uint32  ErrorListArr_QM_OR_VALUE[SIZEOF_ERROR_QM_DATA] = {0u};

  (void)Rte_Read_RpErrors_B_Errors_B((uint32*)&ErrorListArr_B[0]);
  (void)Rte_Read_RpErrors_QM_Errors_QM((uint32*)&ErrorListArr_QM[0]);

  VStdLib_MemCpy(&ErrorListArr_B_OR_VALUE[0],&ErrorListArr_B[0],SIZEOF_ERROR_B_DATA);
  VStdLib_MemCpy(&ErrorListArr_QM_OR_VALUE[0],&ErrorListArr_QM[0],SIZEOF_ERROR_QM_DATA);
  VStdLib_MemClr(Data,(uint8)e_NINE);

  switch(EventId)
  { 
    case 1u: /*B210C17*/
    Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000002u));   /*Battery_OverVoltage*/
    break;

    case 2u: /*B210C16*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000001u));   /*Battery_UnderVoltage*/
        break;  

    case 3u: /*B228600*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x20000000u) >> 29u);    /*SVC_Cam_Calibration_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00010000u) >> 15u);    /*SVC_Rear_Incorrect_Device_ID_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00020000u) >> 15u);    /*SVC_Front_Incorrect_Device_ID_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00040000u) >> 15u);    /*SVC_Left_Incorrect_Device_ID_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00080000u) >> 15u);    /*SVC_Right_Incorrect_Device_ID_Fault*/
        break;  

    case 4u: /*C221200*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x40000000u) >> 30u);    /*ECU_In_Plant_Mode_Fault*/
        break;  

    case 5u: /*B22A900*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00200000u) >> 21u);    /*SysIntFlt_MCU_ADC_uncorrectable_ECC*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x04000000u) >> 25u);    /*SysIntFlt_Main_UDMA_Uncorrectable_ECC_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00000002u) << 1u);    /*SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00000008u));   /*SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00000010u));   /*SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00000200u) >> 4u);    /*SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_Slave*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00002000u) >> 7u);    /*SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_HERA*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00010000u) >> 9u);    /*SysIntFlt_Main_DDRSS0_Two_BIT_and_multibit_ECC_Failure_in_DDR_data*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00100000u) >> 20u);    /*SysIntFlt_Main_CBASS_Parity_failure_of_override_registers*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x00800000u) >> 22u);    /*SysIntFlt_Main_Domain_clock_reference_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[7u] & 0x40000000u) >> 28u);    /*SysIntFlt_Main_PWR_Supply_Internal_POK_monitoring_VDD_CPU*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[8u] & 0x00000200u) >> 6u);    /*SysIntFlt_MCU_Reset_Reset_Configuration_registers_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[8u] & 0x00004000u) >> 10u);    /*SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[9u] & 0x00000200u) >> 4u);    /*SysIntFlt_Main_VTM_OverTemp_Interrupt*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[9u] & 0x00000400u) >> 4u);    /*SysIntFlt_Main_VTM_Registers_Mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[10u] & 0x00000010u) << 3u);    /*SysIntFlt_MCU_NAVSS_NAVSS_IA_Mem_ECC_Err*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[10u] & 0x00000040u) >> 6u);    /*SysIntFlt_MCU_NAVSS_PBIST_Check_Fail*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[10u] & 0x00001000u) >> 11u);    /*SysIntFlt_Main_NAVSSMailbox_1Bit_ParityCheck_Err*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[10u] & 0x00008000u) >> 13u);    /*SysIntFlt_MCU_Timer_2TimerSyncCheck*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[11u] & 0x00000040u) >> 3u);    /*SysIntFlt_MCU_GIC_ECC_Failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x10000000u) >> 24u);    /*USS_Cal_Data_Fault*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x02000000u) >> 20u);    /*SysIntFault_MCU_USS_MASTER_internal_failure_RAM_BIST_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x04000000u) >> 20u);    /*SysIntFault_MCU_USS_MASTER_internal_failure_FSM_RESET*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x08000000u) >> 20u);    /*SysIntFault_MCU_USS_MASTER_internal_failure_VDSIUV*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x10000000u) >> 28u);    /*SysIntFault_MCU_USS_MASTER_internal_failure_VCCUV*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x20000000u) >> 28u);    /*SysIntFault_MCU_USS_MASTER_ECU_COMM_ERR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x40000000u) >> 28u);    /*SysIntFault_MCU_USS_MASTER_INTB_pin_low_CLKREF_failure*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x80000000u) >> 28u);    /*SysIntFault_MCU_USS_MASTER_DSI_Overtemperature_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000001u) << 4u);    /*SysIntFault_MCU_USS_MASTER_DSI3_Safety_critical_registers_mismatch*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000002u) << 4u);    /*SysIntFault_MCU_USS_MASTER_DSI_IRQ_STAT_CRC_ERR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000004u) << 4u);    /*SysIntFault_MCU_USS_MASTER_ECU_SPI_DMA_ERR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000010u) << 3u);    /*SysIntFault_MCU_USS_MASTER_ECU_GPIO_INT_INITIAL_ERR*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000020u) >> 5u);    /*SysIntFault_MCU_USS_MASTER_ECU_PIN_INITIAL_ERR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000040u) >> 5u);    /*SysIntFault_MCU_USS_MASTER_ECU_DSI_CLOCK_INITIAL_ERR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000080u) >> 5u);    /*SysIntFault_MCU_USS_MASTER_ECU_SPI_INITIAL_ERR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000100u) >> 5u);    /*SysIntFault_MCU_USS_MASTER_ECU_USS_POWER_ON_ERR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000200u) >> 5u);    /*SysIntFault_MCU_USS_MASTER_ECU_DSI_RFC_ERR*/
        break;  

    case 6u: /*B23C51C*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00800000u) >> 20u);    /*V_Meas_FrontCam_ADC_Ctrl_OORL*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x01000000u) >> 20u);    /*V_Meas_FrontCam_ADC_Ctrl_OORH*/
        break;  

    case 7u: /*B23C592*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x01000000u) >> 24u);    /*DS90UB962_RX3_CSI_RX_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x08000000u) >> 26u);    /*DS90UB962_CSI_TX0_DETECT_B23C5*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000040u) >> 4u);    /*Front_Cam_I2C_back_channel_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000400u) >> 5u);    /*SVC_Front_self_test_fail_SCCB_Register_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000800u) >> 5u);    /*SVC_Front_online_pixel_test_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00001000u) >> 5u);    /*SVC_Front_analog_test_pattern_error*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00002000u) >> 13u);    /*SVC_Front_row_column_id_checker_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00004000u) >> 13u);    /*SVC_Front_analog_digital_sync_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00008000u) >> 13u);    /*SVC_Front_digital_test_pattern_row_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00010000u) >> 13u);    /*SVC_Front_blc_check_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00020000u) >> 13u);    /*SVC_Front_PLL_Clock_Monitor_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00040000u) >> 13u);    /*SVC_Front_PLL_Lock_State_Monitoring_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00080000u) >> 13u);    /*SVC_Front_SCCB_CRC_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00100000u) >> 13u);    /*SVC_Front_SCCB_embedded_CRC_mismatch*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00200000u) >> 21u);    /*SVC_Front_SI_Default_Register_Check_error*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00400000u) >> 21u);    /*SVC_Front_MIPI_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00800000u) >> 21u);    /*SVC_Front_MIPI_ECC_2_bit_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x01000000u) >> 21u);    /*SVC_Front_FIFO_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x02000000u) >> 21u);    /*SVC_Front_ROM_CRC_Check_Fail*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x04000000u) >> 21u);    /*SVC_Front_OTP_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x08000000u) >> 21u);    /*SVC_Front_SRAM_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x10000000u) >> 21u);    /*SVC_Front_Temp_OOR*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x20000000u) >> 29u);    /*SVC_Front_Temp_Snsr_Integrity_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x40000000u) >> 29u);    /*SVC_Front_Temp_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x80000000u) >> 29u);    /*SVC_Front_Cam_Pwr_Supply_OOR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000001u) << 3u);    /*SVC_Front_VoltageMonitor_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000002u) << 3u);    /*SVC_Front_Frame_Cntr_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000004u) << 3u);    /*SVC_Front_Cam_EEPROM_CRCMismatch_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000008u) << 3u);    /*Front_Cam_Intrinsic_Zero*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x10000000u) >> 21u);    /*SVC_Front_Cam_I2C_NACK_error*/
        break;  

    case 8u: /*B212A08*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000400u) >> 6u);    /*SysIntFault_MCU_USS_MASTER_Front_OC_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000800u) >> 6u);    /*SysIntFault_MCU_USS_MASTER_Front_DSI_Undervoltage_error*/
        break;  

    case 9u: /*B212A17*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00200000u) >> 19u);    /*USS_M_F_Short_to_Bat*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00400000u) >> 19u);    /*USS_M_F_voltage_OOR_High*/
        break;  

    case 10u: /*B212A16*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x01000000u) >> 24u);    /*USS_M_F_short_to_GND*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x02000000u) >> 24u);    /*USS_M_F_voltage_OOR_Low*/
        break;  

    case 11u: /*U104E00*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000004u) >> 2u);    /*Vehicle_CanBusoff_CAN2*/
        break;  

    case 12u: /*U100B00*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000008u) >> 3u);    /*Vehicle_CanBusoff_CAN14*/
        break;  

    case 13u: /*U041800*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000008u) >> 3u);    /*BRAKE1_REF_VEH_SPD_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000010u) >> 3u);    /*BRAKE1_VehStandStillSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000020u) >> 3u);    /*BRAKEFD1_ExternalBrkRequestsDisabled*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000040u) >> 3u);    /*BRAKE2_LatAcc_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000080u) >> 3u);    /*BRAKE2_LatAcc_FailSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000100u) >> 3u);    /*BRAKE2_LongAcc_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000200u) >> 3u);    /*BRAKE2_LongAcc_FailSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000400u) >> 3u);    /*BRAKE2_VehSpd_VSO_Invld*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000800u) >> 11u);    /*BRAKE2_YawRate_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00001000u) >> 11u);    /*BRAKE2_YawRate_FailSts_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00002000u) >> 11u);    /*BRAKE3_LatAcc_Offset_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00004000u) >> 11u);    /*BRAKE3_LongAcc_Offset_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00008000u) >> 11u);    /*BRAKE3_LHF_FastPulseCntr_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00010000u) >> 11u);    /*BRAKE3_LHF_Spin_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00020000u) >> 11u);    /*BRAKE3_LHF_WhlSenFailSts_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00040000u) >> 11u);    /*BRAKE3_LHR_FastPulseCntr_Invld*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00080000u) >> 19u);    /*BRAKE3_LHR_Spin_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00100000u) >> 19u);    /*BRAKE3_LHR_WhlSenFailSts_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00200000u) >> 19u);    /*BRAKE3_RHF_FastPulseCntr_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00400000u) >> 19u);    /*BRAKE3_RHF_Spin_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00800000u) >> 19u);    /*BRAKE3_RHF_WhlSenFailSts_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x01000000u) >> 19u);    /*BRAKE3_RHR_FastPulseCntr_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x02000000u) >> 19u);    /*BRAKE3_RHR_Spin_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x04000000u) >> 19u);    /*BRAKE3_RHR_WhlSenFailSts_Invld*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x08000000u) >> 27u);    /*BRAKE3_LHF_WhlSpd_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x10000000u) >> 27u);    /*BRAKE3_LHR_WhlSpd_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x20000000u) >> 27u);    /*BRAKE3_RHF_WhlSpd_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x40000000u) >> 27u);    /*BRAKE3_RHR_WhlSpd_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x80000000u) >> 27u);    /*BRAKE4_EPBSts_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000001u) << 5u);    /*BRAKE5_BSM_THABrkResp_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000008u) << 3u);    /*BRAKE5_ESC_TRSCBrkResp_Invld*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000010u) << 3u);    /*CRC_Fault_BRAKE5*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000020u) >> 5u);    /*MC_Fault_BRAKE5*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000040u) >> 5u);    /*CRC_Fault_BRAKE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000080u) >> 5u);    /*CRC_Fault_BRAKE3*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000100u) >> 5u);    /*CRC_Fault_BRAKE1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000200u) >> 5u);    /*CRC_Fault_BRAKE4*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000400u) >> 5u);    /*MC_Fault_BRAKE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000800u) >> 5u);    /*MC_Fault_BRAKE3*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00001000u) >> 5u);    /*MC_Fault_BRAKE1*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00002000u) >> 13u);    /*MC_Fault_BRAKE4*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00010000u) >> 15u);    /*BRAKE7_PAM_BrkRqRspSts_Invld*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00020000u) >> 15u);    /*CRC_Fault_BRAKE7*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00040000u) >> 15u);    /*MC_Fault_BRAKE7*/
        break;  

    case 14u: /*U042200*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00800000u) >> 23u);    /*AGSMD_ShifrLevrPosReq_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x01000000u) >> 23u);    /*BCM9_Ext_Temp_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x02000000u) >> 23u);    /*BCM10_CmdIgnSt_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x04000000u) >> 23u);    /*BCM27_TrailrConnSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x08000000u) >> 23u);    /*BCM29_ITBM_TrailrStat_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x10000000u) >> 23u);    /*DRIVETRAIN3_TCASERANGESts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x20000000u) >> 23u);    /*IPC_VEH_SETUP_LangSel_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x40000000u) >> 23u);    /*IPC_VEH_SETUP_PAMChmVol_F_Invld*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x80000000u) >> 31u);    /*IPC_VEH_SETUP_PAMChmVol_R_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000001u) << 1u);    /*TRANSM1_TargetGear_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000002u) << 1u);    /*TRANSM1_ADAS_Inhibit_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000004u) << 1u);    /*TRANSM4_GearEngd_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000008u) << 1u);    /*TRANSM4_ShiftLvrPos_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000010u) << 1u);    /*VIN_Msg_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000020u) << 1u);    /*ASCM1_FL_Lvl_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000040u) << 1u);    /*ASCM1_FR_Lvl_Invld*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000080u) >> 7u);    /*ASCM1_RL_Lvl_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000100u) >> 7u);    /*ASCM1_RR_Lvl_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000200u) >> 7u);    /*ASCM2_Stat_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000400u) >> 7u);    /*ASCM2_SysFail_Fault*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00000800u) >> 7u);    /*TRANSM2_GearEngdForDisp_Invld*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00001000u) >> 7u);    /*CRC_Fault_BCM9*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00002000u) >> 7u);    /*CRC_Fault_BCM10*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00004000u) >> 7u);    /*CRC_Fault_BCM12*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00008000u) >> 15u);    /*CRC_Fault_DRIVETRAIN3*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00010000u) >> 15u);    /*CRC_Fault_TRANSM1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00020000u) >> 15u);    /*CRC_Fault_TRANSM2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00040000u) >> 15u);    /*CRC_Fault_TRANSM4*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00080000u) >> 15u);    /*CRC_Fault_BCM27*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00100000u) >> 15u);    /*CRC_Fault_BCM29*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00200000u) >> 15u);    /*CRC_Fault_AGSM2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00400000u) >> 15u);    /*MC_Fault_BCM2*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x00800000u) >> 23u);    /*MC_Fault_BCM9*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x01000000u) >> 23u);    /*MC_Fault_BCM10*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x02000000u) >> 23u);    /*MC_Fault_BCM12*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x04000000u) >> 23u);    /*MC_Fault_BCM27*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x08000000u) >> 23u);    /*MC_Fault_BCM29*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x10000000u) >> 23u);    /*MC_Fault_DRIVETRAIN3*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x20000000u) >> 23u);    /*MC_Fault_TRANSM1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x40000000u) >> 23u);    /*MC_Fault_TRANSM2*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[4u] & 0x80000000u) >> 31u);    /*MC_Fault_TRANSM4*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000001u) << 1u);    /*MC_Fault_AGSM2*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00100000u) >> 18u);    /*CRC_Fault_BCM2*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000002u) << 2u);    /*AGSM2_Shiftr_ADAS_Inhbt_Invld*/
        break;  

    case 15u: /*U048500*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000002u) >> 1u);    /*TELEMATIC5_CM_TCH_STAT_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000004u) >> 1u);    /*TELEMATIC5_CM_TCH_X_COORD_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000008u) >> 1u);    /*TELEMATIC5_CM_TCH_Y_COORD_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000010u) >> 1u);    /*TELEMT11_HU_TRSC_EnBtnSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000020u) >> 1u);    /*TELEMT14_TGW_Cam_Disp_St_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000040u) >> 1u);    /*TELEMT5_CamDispSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000080u) >> 1u);    /*CRC_Fault_TELEMT14*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000100u) >> 1u);    /*MC_Fault_TELEMT14*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000200u) >> 9u);    /*CRC_Fault_TELEMT11*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000400u) >> 9u);    /*MC_Fault_TELEMT11*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00000800u) >> 9u);    /*CRC_Fault_TELEMT5*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00001000u) >> 9u);    /*MC_Fault_TELEMT5*/
        break;  

    case 16u: /*U045500*/
        Data[0u] = (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000100u) >> 8u);    /*SBR1RowDriverSeatSts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000200u) >> 8u);    /*CRC_Fault_ORC*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000400u) >> 8u);    /*MC_Fault_ORC*/
        break;  

    case 17u: /*U14A000*/
        Data[0u] = (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000010u) >> 4u);    /*TRSC_EnableBtn_Sts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000020u) >> 4u);    /*TRSC_CenterBtn_Sts_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000040u) >> 4u);    /*CRC_Fault_TRSKM*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000080u) >> 4u);    /*MC_Fault_TRSKM*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000800u) >> 7u);    /*TRSC_RawKnob_OOR_Fault*/
        break;  

    case 18u: /*U040100*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000100u) >> 8u);    /*Engine2_EngineSts_W_ECM_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000200u) >> 8u);    /*Engine_FD_5_ECM_PdlPosActual*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000400u) >> 8u);    /*Engine_FD_7_ECM_TRSC_Resp_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000800u) >> 8u);    /*Engine_FD_7_ECM_THA_Resp_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00001000u) >> 8u);    /*ECM_CRC_Fault_ENGINE2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00002000u) >> 8u);    /*ECM_MC_Fault_ENGINE2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00004000u) >> 8u);    /*ECM_CRC_Fault_ENGINE7*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00008000u) >> 8u);    /*ECM_MC_Fault_ENGINE7*/
        break;  

    case 19u: /*U042000*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00004000u) >> 14u);    /*EPS2_THA_DrivrTqOvrride_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00008000u) >> 14u);    /*EPS2_THA_SteeringTqResp_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00010000u) >> 14u);    /*EPS1_SPM_LAT_Ctrl_Resp_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00020000u) >> 14u);    /*EPS1_LWS_Angle_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00040000u) >> 14u);    /*EPS1_LWS_Spd_Invld*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00080000u) >> 14u);    /*CRC_Fault_EPS2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00100000u) >> 14u);    /*MC_Fault_EPS2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00200000u) >> 14u);    /*CRC_Fault_EPS1*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00400000u) >> 22u);    /*MC_Fault_EPS1*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00080000u) >> 18u);    /*EPS1_LWS_Angle_Typ_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x80000000u) >> 29u);    /*EPS2_EPS_SteeringTqResp_Invld*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000001u) << 3u);    /*EPS2_THA_SteerTouchStat_Invld*/
        break;  

    case 20u: /*B23C61C*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x02000000u) >> 22u);    /*V_Meas_LeftCam_ADC_Ctrl_OORL*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x04000000u) >> 22u);    /*V_Meas_LeftCam_ADC_Ctrl_OORH*/
        break;  

    case 21u: /*B23C692*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00010000u) >> 16u);    /*Left_Cam_I2C_back_channel_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00100000u) >> 19u);    /*DS90UB962_RX1_CSI_RX_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x04000000u) >> 24u);    /*DS90UB962_CSI_TX0_DETECT_B23C6*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000010u) << 1u);    /*SVC_Left_self_test_fail_SCCB_Register_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000020u) << 1u);    /*SVC_Left_online_pixel_test_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000040u) << 1u);    /*SVC_Left_analog_test_pattern_error*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000080u) >> 7u);    /*SVC_Left_row_column_id_checker_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000100u) >> 7u);    /*SVC_Left_analog_digital_sync_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000200u) >> 7u);    /*SVC_Left_digital_test_pattern_row_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000400u) >> 7u);    /*SVC_Left_blc_check_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00000800u) >> 7u);    /*SVC_Left_PLL_Clock_Monitor_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00001000u) >> 7u);    /*SVC_Left_PLL_Lock_State_Monitoring_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00002000u) >> 7u);    /*SVC_Left_SCCB_CRC_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00004000u) >> 7u);    /*SVC_Left_SCCB_embedded_CRC_mismatch*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00008000u) >> 15u);    /*SVC_Left_SI_Default_Register_Check_error*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00010000u) >> 15u);    /*SVC_Left_MIPI_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00020000u) >> 15u);    /*SVC_Left_MIPI_ECC_2_bit_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00040000u) >> 15u);    /*SVC_Left_FIFO_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00080000u) >> 15u);    /*SVC_Left_ROM_CRC_Check_Fail*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00100000u) >> 15u);    /*SVC_Left_OTP_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00200000u) >> 15u);    /*SVC_Left_SRAM_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00400000u) >> 15u);    /*SVC_Left_Temp_OOR*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x00800000u) >> 23u);    /*SVC_Left_Temp_Snsr_Integrity_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x01000000u) >> 23u);    /*SVC_Left_Temp_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x02000000u) >> 23u);    /*SVC_Left_Cam_Pwr_Supply_OOR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x04000000u) >> 23u);    /*SVC_Left_VoltageMonitor_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x08000000u) >> 23u);    /*SVC_Left_Frame_Cntr_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x10000000u) >> 23u);    /*SVC_Left_Cam_EEPROM_CRCMismatch_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x20000000u) >> 23u);    /*Left_Cam_Intrinsic_Zero*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x04000000u) >> 19u);    /*SVC_Left_Cam_I2C_NACK_error*/
        break;  

    case 22u: /*U12B900*/
        Data[0u] = (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000004u) >> 2u);    /*MissingMessage_TRSKM_FD_1*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000008u) >> 2u);    /*DLC_Fault_TRSKM_FD_1*/
        break;  

    case 23u: /*U010000*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000004u) >> 2u);    /*MissingMessage_ECM_ENGINE_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000008u) >> 2u);    /*MissingMessage_ECM_ENGINE_FD5*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000010u) >> 2u);    /*MissingMessage_ECM_ENGINE_FD7*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000020u) >> 2u);    /*DLC_Fault_ECM_ENGINE_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000040u) >> 2u);    /*DLC_Fault_ECM_ENGINE_FD5*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[6u] & 0x00000080u) >> 2u);    /*DLC_Fault_ECM_ENGINE_FD7*/
        break;  

    case 24u: /*U014000*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000010u) >> 4u);    /*MissingMessage_AGSM_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000020u) >> 4u);    /*DLC_Fault_AGSM_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000040u) >> 4u);    /*MissingMessage_BCM_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000080u) >> 4u);    /*DLC_Fault_BCM_FD2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000100u) >> 4u);    /*MissingMessage_BCM_FD9*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000200u) >> 4u);    /*DLC_Fault_BCM_FD9*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000400u) >> 4u);    /*MissingMessage_BCM_FD10*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00000800u) >> 4u);    /*DLC_Fault_BCM_FD10*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00001000u) >> 12u);    /*MissingMessage_BCM_FD12*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00002000u) >> 12u);    /*DLC_Fault_BCM_FD12*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00004000u) >> 12u);    /*MissingMessage_BCM_FD27*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00008000u) >> 12u);    /*DLC_Fault_BCM_FD27*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00010000u) >> 12u);    /*MissingMessage_BCM_FD29*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00020000u) >> 12u);    /*DLC_Fault_BCM_FD29*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00040000u) >> 12u);    /*MissingMessage_DRIVETRAIN_FD3*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00080000u) >> 12u);    /*DLC_Fault_DRIVETRAIN_FD3*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00100000u) >> 20u);    /*MissingMessage_IPC_VEHICLE_SETUP*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00200000u) >> 20u);    /*DLC_Fault_IPC_VEHICLE_SETUP*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00400000u) >> 20u);    /*MissingMessage_IPC_FD1*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x00800000u) >> 20u);    /*DLC_Fault_IPC_FD1*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x01000000u) >> 20u);    /*MissingMessage_TRANSM_FD1*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x02000000u) >> 20u);    /*DLC_Fault_TRANSM_FD1*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x04000000u) >> 20u);    /*MissingMessage_TRANSM_FD2*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x08000000u) >> 20u);    /*DLC_Fault_TRANSM_FD2*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x10000000u) >> 28u);    /*MissingMessage_TRANSM_FD4*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x20000000u) >> 28u);    /*DLC_Fault_TRANSM_FD4*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x40000000u) >> 28u);    /*MissingMessage_ASCM_FD1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[0u] & 0x80000000u) >> 28u);    /*DLC_Fault_ASCM_FD1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000001u) << 4u);    /*MissingMessage_ASCM_FD2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000002u) << 4u);    /*DLC_Fault_ASCM_FD2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000004u) << 4u);    /*MissingMessage_VIN*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000008u) << 4u);    /*DLC_Fault_VIN*/
        break;  

    case 25u: /*U012900*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00200000u) >> 21u);    /*MissingMessage_BRAKE_FD_1*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00400000u) >> 21u);    /*DLC_Fault_BRAKE_FD_1*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00800000u) >> 21u);    /*MissingMessage_BRAKE_FD_2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x01000000u) >> 21u);    /*DLC_Fault_BRAKE_FD_2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x02000000u) >> 21u);    /*MissingMessage_BRAKE_FD_3*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x04000000u) >> 21u);    /*DLC_Fault_BRAKE_FD_3*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x08000000u) >> 21u);    /*MissingMessage_BRAKE_FD_4*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x10000000u) >> 21u);    /*DLC_Fault_BRAKE_FD_4*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x20000000u) >> 29u);    /*MissingMessage_BRAKE_FD_7*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x40000000u) >> 29u);    /*DLC_Fault_BRAKE_FD_7*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000002u) << 1u);    /*MissingMessage_BRAKE_FD_5*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[3u] & 0x00000004u) << 1u);    /*DLC_Fault_BRAKE_FD_5*/
        break;  

    case 26u: /*U013100*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x80000000u) >> 31u);    /*MissingMessage_EPS_FD_2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000001u) << 1u);    /*DLC_Fault_EPS_FD_2*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000002u) << 1u);    /*MissingMessage_EPS_FD_1*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[2u] & 0x00000004u) << 1u);    /*DLC_Fault_EPS_FD_1*/
        break;  

    case 27u: /*U018400*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000010u) >> 4u);    /*MissingMessage_TELEMATIC_FD5*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000020u) >> 4u);    /*DLC_Fault_TELEMATIC_FD5*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000040u) >> 4u);    /*MissingMessage_TELEMATIC_FD14*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000080u) >> 4u);    /*DLC_Fault_TELEMATIC_FD14*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000100u) >> 4u);    /*MissingMessage_TELEMATIC_FD11*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000200u) >> 4u);    /*DLC_Fault_TELEMATIC_FD11*/
        break;  

    case 28u: /*U026500*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00800000u) >> 23u);    /*DS90UB962_RX3_LOCK_STS*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000004u) >> 1u);    /*FrontCamFailure_STG*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000008u) >> 1u);    /*FrontCamFailure_STB*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000010u) >> 1u);    /*LOC_SVC_Front_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000020u) >> 1u);    /*Front_Cam_LOC_Incorrect_PMIC_DeviceID*/
        break;  

    case 29u: /*U026600*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00080000u) >> 19u);    /*DS90UB962_RX1_LOCK_STS*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000080u) >> 6u);    /*LeftCamFailure_STG*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000100u) >> 6u);    /*LeftCamFailure_STB*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000200u) >> 6u);    /*LOC_SVC_Left_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000400u) >> 6u);    /*Left_Cam_LOC_Incorrect_PMIC_DeviceID*/
        break;  

    case 30u: /*U015100*/
        Data[0u] = (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000001u));   /*MissingMessage_ORC_FD1*/
        Data[0u] |= (uint8)((ErrorListArr_QM_OR_VALUE[0u] & 0x00000002u));   /*DLC_Fault_ORC_FD1*/
        break;  

    case 31u: /*U026400*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00200000u) >> 21u);    /*DS90UB962_RX2_LOCK_STS*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x20000000u) >> 28u);    /*RearCamFailure_STG*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x40000000u) >> 28u);    /*RearCamFailure_STB*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x80000000u) >> 28u);    /*LOC_SVC_Rear_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000001u) << 4u);    /*Rear_Cam_LOC_Incorrect_PMIC_DeviceID*/
        break;  

    case 32u: /*U026700*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00020000u) >> 17u);    /*DS90UB962_RX0_LOCK_STS*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000800u) >> 10u);    /*RightCamFailure_STG*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00001000u) >> 10u);    /*RightCamFailure_STB*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00002000u) >> 10u);    /*LOC_SVC_Right_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00004000u) >> 10u);    /*Right_Cam_LOC_Incorrect_PMIC_DeviceID*/
        break;  

    case 33u: /*B12B22A*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00002000u) >> 13u);    /*BCM12_APAReqSts_Stuck_Fault*/
        break;  

    case 34u: /*B128E13*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000001u) << 2u);    /*SENSOR1_OpenCkt_Fault*/
        break;  

    case 35u: /*B128E92*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00001000u) >> 9u);    /*SENSOR1_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x20000000u) >> 25u);    /*SENSOR1_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00004000u) >> 9u);    /*SysIntFault_USS_SENSOR1_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00008000u) >> 9u);    /*SysIntFault_USS_SENSOR1_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00010000u) >> 9u);    /*SysIntFault_USS_SENSOR1_VREF_OTP_out_of_range*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00020000u) >> 17u);    /*SysIntFault_USS_SENSOR1_VDDD_out_of_range*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00040000u) >> 17u);    /*SysIntFault_USS_SENSOR1_DRV1_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00080000u) >> 17u);    /*SysIntFault_USS_SENSOR1_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00100000u) >> 17u);    /*SysIntFault_USS_SENSOR1_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00200000u) >> 17u);    /*SysIntFault_USS_SENSOR1_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00400000u) >> 17u);    /*SysIntFault_USS_SENSOR1_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00800000u) >> 17u);    /*SysIntFault_USS_SENSOR1_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x01000000u) >> 17u);    /*SysIntFault_USS_SENSOR1_RECEIVED_COMMAND_INVALID*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x02000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_WD_COUNTER_DESYNC*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x04000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_WD_CLOCK_FAIL*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x08000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x10000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x20000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x40000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x80000000u) >> 25u);    /*SysIntFault_USS_SENSOR1_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000001u) << 7u);    /*SysIntFault_USS_SENSOR1_VTANK_OVERVOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000002u) >> 1u);    /*SysIntFault_USS_SENSOR1_VTANK_UNDERVOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000004u) >> 1u);    /*SysIntFault_USS_SENSOR1_VSUP_OVER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000008u) >> 1u);    /*SysIntFault_USS_SENSOR1_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000010u) >> 1u);    /*SysIntFault_USS_SENSOR1_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000020u) >> 1u);    /*SysIntFault_USS_SENSOR1_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000040u) >> 1u);    /*SysIntFault_USS_SENSOR1_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000080u) >> 1u);    /*SysIntFault_USS_SENSOR1_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000100u) >> 1u);    /*SysIntFault_USS_SENSOR1_CRC_BLOCK_MFG1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000200u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_BLOCK_MFG2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000400u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_OP_MODE1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00000800u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00001000u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00002000u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00004000u) >> 9u);    /*SysIntFault_USS_SENSOR1_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00010000u) >> 10u);    /*SysIntFault_USS_SENSOR1_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00020000u) >> 10u);    /*SysIntFault_USS_SENSOR1_SNR_SETUP_SENSOR_FAIL*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00040000u) >> 18u);    /*SysIntFault_USS_SENSOR1_GET_RING_FREQUENCY_FAILURE*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00080000u) >> 18u);    /*SysIntFault_USS_SENSOR1_ADA_MEASURE_TIMEOUT*/
        Data[5u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00100000u) >> 18u);    /*SysIntFault_USS_SENSOR1_PROGRAM_EEPROM*/
        break;  

    case 36u: /*B128F13*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000002u) >> 1u);    /*SENSOR2_OpenCkt_Fault*/
        break;  

    case 37u: /*B128F92*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00002000u) >> 12u);    /*SENSOR2_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x40000000u) >> 28u);    /*SENSOR2_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00200000u) >> 18u);    /*SysIntFault_USS_SENSOR2_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00400000u) >> 18u);    /*SysIntFault_USS_SENSOR2_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x00800000u) >> 18u);    /*SysIntFault_USS_SENSOR2_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x01000000u) >> 18u);    /*SysIntFault_USS_SENSOR2_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x02000000u) >> 18u);    /*SysIntFault_USS_SENSOR2_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x04000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x08000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x10000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x20000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x40000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[20u] & 0x80000000u) >> 26u);    /*SysIntFault_USS_SENSOR2_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000001u) << 6u);    /*SysIntFault_USS_SENSOR2_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000002u) << 6u);    /*SysIntFault_USS_SENSOR2_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000004u) >> 2u);    /*SysIntFault_USS_SENSOR2_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000008u) >> 2u);    /*SysIntFault_USS_SENSOR2_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000010u) >> 2u);    /*SysIntFault_USS_SENSOR2_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000020u) >> 2u);    /*SysIntFault_USS_SENSOR2_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000040u) >> 2u);    /*SysIntFault_USS_SENSOR2_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000080u) >> 2u);    /*SysIntFault_USS_SENSOR2_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000100u) >> 2u);    /*SysIntFault_USS_SENSOR2_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000200u) >> 2u);    /*SysIntFault_USS_SENSOR2_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000400u) >> 10u);    /*SysIntFault_USS_SENSOR2_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00000800u) >> 10u);    /*SysIntFault_USS_SENSOR2_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00001000u) >> 10u);    /*SysIntFault_USS_SENSOR2_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00002000u) >> 10u);    /*SysIntFault_USS_SENSOR2_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00004000u) >> 10u);    /*SysIntFault_USS_SENSOR2_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00008000u) >> 10u);    /*SysIntFault_USS_SENSOR2_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00010000u) >> 10u);    /*SysIntFault_USS_SENSOR2_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00020000u) >> 10u);    /*SysIntFault_USS_SENSOR2_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00040000u) >> 18u);    /*SysIntFault_USS_SENSOR2_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00080000u) >> 18u);    /*SysIntFault_USS_SENSOR2_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00100000u) >> 18u);    /*SysIntFault_USS_SENSOR2_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00200000u) >> 18u);    /*SysIntFault_USS_SENSOR2_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x00800000u) >> 19u);    /*SysIntFault_USS_SENSOR2_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x01000000u) >> 19u);    /*SysIntFault_USS_SENSOR2_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x02000000u) >> 19u);    /*SysIntFault_USS_SENSOR2_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x04000000u) >> 19u);    /*SysIntFault_USS_SENSOR2_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x08000000u) >> 27u);    /*SysIntFault_USS_SENSOR2_PROGRAM_EEPROM*/
        break;  

    case 38u: /*B129013*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000004u) >> 2u);    /*SENSOR3_OpenCkt_Fault*/
        break;  

    case 39u: /*B129092*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00004000u) >> 13u);    /*SENSOR3_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x80000000u) >> 29u);    /*SENSOR3_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x10000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x20000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x40000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[21u] & 0x80000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000001u) << 7u);    /*SysIntFault_USS_SENSOR3_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000002u) >> 1u);    /*SysIntFault_USS_SENSOR3_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000004u) >> 1u);    /*SysIntFault_USS_SENSOR3_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000008u) >> 1u);    /*SysIntFault_USS_SENSOR3_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000010u) >> 1u);    /*SysIntFault_USS_SENSOR3_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000020u) >> 1u);    /*SysIntFault_USS_SENSOR3_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000040u) >> 1u);    /*SysIntFault_USS_SENSOR3_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000080u) >> 1u);    /*SysIntFault_USS_SENSOR3_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000100u) >> 1u);    /*SysIntFault_USS_SENSOR3_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000200u) >> 9u);    /*SysIntFault_USS_SENSOR3_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000400u) >> 9u);    /*SysIntFault_USS_SENSOR3_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00000800u) >> 9u);    /*SysIntFault_USS_SENSOR3_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00001000u) >> 9u);    /*SysIntFault_USS_SENSOR3_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00002000u) >> 9u);    /*SysIntFault_USS_SENSOR3_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00004000u) >> 9u);    /*SysIntFault_USS_SENSOR3_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00008000u) >> 9u);    /*SysIntFault_USS_SENSOR3_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00010000u) >> 9u);    /*SysIntFault_USS_SENSOR3_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00020000u) >> 17u);    /*SysIntFault_USS_SENSOR3_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00040000u) >> 17u);    /*SysIntFault_USS_SENSOR3_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00080000u) >> 17u);    /*SysIntFault_USS_SENSOR3_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00100000u) >> 17u);    /*SysIntFault_USS_SENSOR3_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00200000u) >> 17u);    /*SysIntFault_USS_SENSOR3_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00400000u) >> 17u);    /*SysIntFault_USS_SENSOR3_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x00800000u) >> 17u);    /*SysIntFault_USS_SENSOR3_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x01000000u) >> 17u);    /*SysIntFault_USS_SENSOR3_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x02000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x04000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x08000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x10000000u) >> 25u);    /*SysIntFault_USS_SENSOR3_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x40000000u) >> 26u);    /*SysIntFault_USS_SENSOR3_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[22u] & 0x80000000u) >> 26u);    /*SysIntFault_USS_SENSOR3_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000001u) << 6u);    /*SysIntFault_USS_SENSOR3_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000002u) << 6u);    /*SysIntFault_USS_SENSOR3_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000004u) >> 2u);    /*SysIntFault_USS_SENSOR3_PROGRAM_EEPROM*/
        break;  

    case 40u: /*B129113*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000008u) >> 3u);    /*SENSOR4_OpenCkt_Fault*/
        break;  

    case 41u: /*B129192*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00008000u) >> 14u);    /*SENSOR4_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000001u) << 2u);    /*SENSOR4_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000008u));          /*SysIntFault_USS_SENSOR4_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000010u));          /*SysIntFault_USS_SENSOR4_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000020u));          /*SysIntFault_USS_SENSOR4_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000040u));          /*SysIntFault_USS_SENSOR4_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000080u));          /*SysIntFault_USS_SENSOR4_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000100u) >> 8u);    /*SysIntFault_USS_SENSOR4_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000200u) >> 8u);    /*SysIntFault_USS_SENSOR4_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000400u) >> 8u);    /*SysIntFault_USS_SENSOR4_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00000800u) >> 8u);    /*SysIntFault_USS_SENSOR4_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00001000u) >> 8u);    /*SysIntFault_USS_SENSOR4_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00002000u) >> 8u);    /*SysIntFault_USS_SENSOR4_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00004000u) >> 8u);    /*SysIntFault_USS_SENSOR4_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00008000u) >> 8u);    /*SysIntFault_USS_SENSOR4_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00010000u) >> 16u);    /*SysIntFault_USS_SENSOR4_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00020000u) >> 16u);    /*SysIntFault_USS_SENSOR4_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00040000u) >> 16u);    /*SysIntFault_USS_SENSOR4_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00080000u) >> 16u);    /*SysIntFault_USS_SENSOR4_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00100000u) >> 16u);    /*SysIntFault_USS_SENSOR4_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00200000u) >> 16u);    /*SysIntFault_USS_SENSOR4_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00400000u) >> 16u);    /*SysIntFault_USS_SENSOR4_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x00800000u) >> 16u);    /*SysIntFault_USS_SENSOR4_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x01000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x02000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x04000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x08000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x10000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x20000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x40000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[23u] & 0x80000000u) >> 24u);    /*SysIntFault_USS_SENSOR4_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000001u));           /*SysIntFault_USS_SENSOR4_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000002u));           /*SysIntFault_USS_SENSOR4_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000004u));           /*SysIntFault_USS_SENSOR4_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000008u));           /*SysIntFault_USS_SENSOR4_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000020u) >> 1u);    /*SysIntFault_USS_SENSOR4_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000040u) >> 1u);    /*SysIntFault_USS_SENSOR4_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000080u) >> 1u);    /*SysIntFault_USS_SENSOR4_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000100u) >> 1u);    /*SysIntFault_USS_SENSOR4_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000200u) >> 9u);    /*SysIntFault_USS_SENSOR4_PROGRAM_EEPROM*/
        break;  

    case 42u: /*B129213*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000010u) >> 4u);    /*SENSOR5_OpenCkt_Fault*/
        break;  

    case 43u: /*B129292*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00010000u) >> 15u);    /*SENSOR5_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000002u) << 1u);    /*SENSOR5_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000400u) >> 7u);    /*SysIntFault_USS_SENSOR5_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00000800u) >> 7u);    /*SysIntFault_USS_SENSOR5_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00001000u) >> 7u);    /*SysIntFault_USS_SENSOR5_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00002000u) >> 7u);    /*SysIntFault_USS_SENSOR5_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00004000u) >> 7u);    /*SysIntFault_USS_SENSOR5_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00008000u) >> 15u);    /*SysIntFault_USS_SENSOR5_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00010000u) >> 15u);    /*SysIntFault_USS_SENSOR5_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00020000u) >> 15u);    /*SysIntFault_USS_SENSOR5_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00040000u) >> 15u);    /*SysIntFault_USS_SENSOR5_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00080000u) >> 15u);    /*SysIntFault_USS_SENSOR5_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00100000u) >> 15u);    /*SysIntFault_USS_SENSOR5_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00200000u) >> 15u);    /*SysIntFault_USS_SENSOR5_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00400000u) >> 15u);    /*SysIntFault_USS_SENSOR5_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x00800000u) >> 23u);    /*SysIntFault_USS_SENSOR5_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x01000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x02000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x04000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x08000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x10000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x20000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x40000000u) >> 23u);    /*SysIntFault_USS_SENSOR5_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[24u] & 0x80000000u) >> 31u);    /*SysIntFault_USS_SENSOR5_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000001u) << 1u);    /*SysIntFault_USS_SENSOR5_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000002u) << 1u);    /*SysIntFault_USS_SENSOR5_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000004u) << 1u);    /*SysIntFault_USS_SENSOR5_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000008u) << 1u);    /*SysIntFault_USS_SENSOR5_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000010u) << 1u);    /*SysIntFault_USS_SENSOR5_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000020u) << 1u);    /*SysIntFault_USS_SENSOR5_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000040u) << 1u);    /*SysIntFault_USS_SENSOR5_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000080u) >> 7u);    /*SysIntFault_USS_SENSOR5_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000100u) >> 7u);    /*SysIntFault_USS_SENSOR5_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000200u) >> 7u);    /*SysIntFault_USS_SENSOR5_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00000400u) >> 7u);    /*SysIntFault_USS_SENSOR5_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00001000u) >> 8u);    /*SysIntFault_USS_SENSOR5_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00002000u) >> 8u);    /*SysIntFault_USS_SENSOR5_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00004000u) >> 8u);    /*SysIntFault_USS_SENSOR5_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00008000u) >> 8u);    /*SysIntFault_USS_SENSOR5_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00010000u) >> 16u);    /*SysIntFault_USS_SENSOR5_PROGRAM_EEPROM*/
        break;  

    case 44u: /*B129313*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000020u) >> 5u);    /*SENSOR6_OpenCkt_Fault*/
        break;  

    case 45u: /*B129413*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000040u) >> 6u);    /*SENSOR7_OpenCkt_Fault*/
        break;  

    case 46u: /*B129492*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00040000u) >> 17u);    /*SENSOR7_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000008u) >> 1u);    /*SENSOR7_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x01000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x02000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x04000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x08000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x10000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x20000000u) >> 29u);    /*SysIntFault_USS_SENSOR7_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x40000000u) >> 29u);    /*SysIntFault_USS_SENSOR7_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x80000000u) >> 29u);    /*SysIntFault_USS_SENSOR7_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000001u) << 3u);    /*SysIntFault_USS_SENSOR7_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000002u) << 3u);    /*SysIntFault_USS_SENSOR7_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000004u) << 3u);    /*SysIntFault_USS_SENSOR7_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000008u) << 3u);    /*SysIntFault_USS_SENSOR7_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000010u) << 3u);    /*SysIntFault_USS_SENSOR7_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000020u) >> 5u);    /*SysIntFault_USS_SENSOR7_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000040u) >> 5u);    /*SysIntFault_USS_SENSOR7_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000080u) >> 5u);    /*SysIntFault_USS_SENSOR7_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000100u) >> 5u);    /*SysIntFault_USS_SENSOR7_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000200u) >> 5u);    /*SysIntFault_USS_SENSOR7_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000400u) >> 5u);    /*SysIntFault_USS_SENSOR7_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00000800u) >> 5u);    /*SysIntFault_USS_SENSOR7_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00001000u) >> 5u);    /*SysIntFault_USS_SENSOR7_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00002000u) >> 13u);    /*SysIntFault_USS_SENSOR7_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00004000u) >> 13u);    /*SysIntFault_USS_SENSOR7_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00008000u) >> 13u);    /*SysIntFault_USS_SENSOR7_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00010000u) >> 13u);    /*SysIntFault_USS_SENSOR7_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00020000u) >> 13u);    /*SysIntFault_USS_SENSOR7_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00040000u) >> 13u);    /*SysIntFault_USS_SENSOR7_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00080000u) >> 13u);    /*SysIntFault_USS_SENSOR7_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00100000u) >> 13u);    /*SysIntFault_USS_SENSOR7_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00200000u) >> 21u);    /*SysIntFault_USS_SENSOR7_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00400000u) >> 21u);    /*SysIntFault_USS_SENSOR7_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x00800000u) >> 21u);    /*SysIntFault_USS_SENSOR7_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x01000000u) >> 21u);    /*SysIntFault_USS_SENSOR7_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x04000000u) >> 22u);    /*SysIntFault_USS_SENSOR7_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x08000000u) >> 22u);    /*SysIntFault_USS_SENSOR7_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x10000000u) >> 22u);    /*SysIntFault_USS_SENSOR7_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x20000000u) >> 22u);    /*SysIntFault_USS_SENSOR7_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x40000000u) >> 30u);    /*SysIntFault_USS_SENSOR7_PROGRAM_EEPROM*/
        break;  

    case 47u: /*B129513*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000080u) >> 7u);    /*SENSOR8_OpenCkt_Fault*/
        break;  

    case 48u: /*B129592*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00080000u) >> 18u);    /*SENSOR8_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000010u) >> 2u);    /*SENSOR8_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[27u] & 0x80000000u) >> 28u);    /*SysIntFault_USS_SENSOR8_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000001u) << 4u);    /*SysIntFault_USS_SENSOR8_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000002u) << 4u);    /*SysIntFault_USS_SENSOR8_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000004u) << 4u);    /*SysIntFault_USS_SENSOR8_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000008u) << 4u);    /*SysIntFault_USS_SENSOR8_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000010u) >> 4u);    /*SysIntFault_USS_SENSOR8_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000020u) >> 4u);    /*SysIntFault_USS_SENSOR8_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000040u) >> 4u);    /*SysIntFault_USS_SENSOR8_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000080u) >> 4u);    /*SysIntFault_USS_SENSOR8_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000100u) >> 4u);    /*SysIntFault_USS_SENSOR8_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000200u) >> 4u);    /*SysIntFault_USS_SENSOR8_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000400u) >> 4u);    /*SysIntFault_USS_SENSOR8_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00000800u) >> 4u);    /*SysIntFault_USS_SENSOR8_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00001000u) >> 12u);    /*SysIntFault_USS_SENSOR8_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00002000u) >> 12u);    /*SysIntFault_USS_SENSOR8_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00004000u) >> 12u);    /*SysIntFault_USS_SENSOR8_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00008000u) >> 12u);    /*SysIntFault_USS_SENSOR8_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00010000u) >> 12u);    /*SysIntFault_USS_SENSOR8_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00020000u) >> 12u);    /*SysIntFault_USS_SENSOR8_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00040000u) >> 12u);    /*SysIntFault_USS_SENSOR8_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00080000u) >> 12u);    /*SysIntFault_USS_SENSOR8_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00100000u) >> 20u);    /*SysIntFault_USS_SENSOR8_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00200000u) >> 20u);    /*SysIntFault_USS_SENSOR8_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00400000u) >> 20u);    /*SysIntFault_USS_SENSOR8_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x00800000u) >> 20u);    /*SysIntFault_USS_SENSOR8_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x01000000u) >> 20u);    /*SysIntFault_USS_SENSOR8_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x02000000u) >> 20u);    /*SysIntFault_USS_SENSOR8_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x04000000u) >> 20u);    /*SysIntFault_USS_SENSOR8_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x08000000u) >> 20u);    /*SysIntFault_USS_SENSOR8_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x10000000u) >> 28u);    /*SysIntFault_USS_SENSOR8_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x20000000u) >> 28u);    /*SysIntFault_USS_SENSOR8_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x40000000u) >> 28u);    /*SysIntFault_USS_SENSOR8_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[28u] & 0x80000000u) >> 28u);    /*SysIntFault_USS_SENSOR8_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000002u) << 3u);    /*SysIntFault_USS_SENSOR8_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000004u) << 3u);    /*SysIntFault_USS_SENSOR8_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000008u) << 3u);    /*SysIntFault_USS_SENSOR8_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000010u) << 3u);    /*SysIntFault_USS_SENSOR8_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000020u) >> 5u);    /*SysIntFault_USS_SENSOR8_PROGRAM_EEPROM*/
        break;  

    case 49u: /*B129613*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000100u) >> 8u);    /*SENSOR9_OpenCkt_Fault*/
        break;  

    case 50u: /*B129692*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00100000u) >> 19u);    /*SENSOR9_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000020u) >> 3u);    /*SENSOR9_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000040u) >> 3u);    /*SysIntFault_USS_SENSOR9_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000080u) >> 3u);    /*SysIntFault_USS_SENSOR9_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000100u) >> 3u);    /*SysIntFault_USS_SENSOR9_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000200u) >> 3u);    /*SysIntFault_USS_SENSOR9_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000400u) >> 3u);    /*SysIntFault_USS_SENSOR9_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00000800u) >> 11u);    /*SysIntFault_USS_SENSOR9_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00001000u) >> 11u);    /*SysIntFault_USS_SENSOR9_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00002000u) >> 11u);    /*SysIntFault_USS_SENSOR9_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00004000u) >> 11u);    /*SysIntFault_USS_SENSOR9_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00008000u) >> 11u);    /*SysIntFault_USS_SENSOR9_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00010000u) >> 11u);    /*SysIntFault_USS_SENSOR9_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00020000u) >> 11u);    /*SysIntFault_USS_SENSOR9_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00040000u) >> 11u);    /*SysIntFault_USS_SENSOR9_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00080000u) >> 19u);    /*SysIntFault_USS_SENSOR9_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00100000u) >> 19u);    /*SysIntFault_USS_SENSOR9_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00200000u) >> 19u);    /*SysIntFault_USS_SENSOR9_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00400000u) >> 19u);    /*SysIntFault_USS_SENSOR9_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x00800000u) >> 19u);    /*SysIntFault_USS_SENSOR9_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x01000000u) >> 19u);    /*SysIntFault_USS_SENSOR9_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x02000000u) >> 19u);    /*SysIntFault_USS_SENSOR9_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x04000000u) >> 19u);    /*SysIntFault_USS_SENSOR9_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x08000000u) >> 27u);    /*SysIntFault_USS_SENSOR9_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x10000000u) >> 27u);    /*SysIntFault_USS_SENSOR9_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x20000000u) >> 27u);    /*SysIntFault_USS_SENSOR9_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x40000000u) >> 27u);    /*SysIntFault_USS_SENSOR9_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[29u] & 0x80000000u) >> 27u);    /*SysIntFault_USS_SENSOR9_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000001u) << 5u);    /*SysIntFault_USS_SENSOR9_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000002u) << 5u);    /*SysIntFault_USS_SENSOR9_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000004u) << 5u);    /*SysIntFault_USS_SENSOR9_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000008u) >> 3u);    /*SysIntFault_USS_SENSOR9_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000010u) >> 3u);    /*SysIntFault_USS_SENSOR9_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000020u) >> 3u);    /*SysIntFault_USS_SENSOR9_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000040u) >> 3u);    /*SysIntFault_USS_SENSOR9_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000100u) >> 4u);    /*SysIntFault_USS_SENSOR9_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000200u) >> 4u);    /*SysIntFault_USS_SENSOR9_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000400u) >> 4u);    /*SysIntFault_USS_SENSOR9_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00000800u) >> 4u);    /*SysIntFault_USS_SENSOR9_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00001000u) >> 12u);    /*SysIntFault_USS_SENSOR9_PROGRAM_EEPROM*/
        break;  

    case 51u: /*B129713*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000200u) >> 9u);    /*SENSOR10_OpenCkt_Fault*/
        break;  

    case 52u: /*B129792*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00200000u) >> 20u);    /*SENSOR10_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000040u) >> 4u);    /*SENSOR10_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00002000u) >> 10u);    /*SysIntFault_USS_SENSOR10_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00004000u) >> 10u);    /*SysIntFault_USS_SENSOR10_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00008000u) >> 10u);    /*SysIntFault_USS_SENSOR10_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00010000u) >> 10u);    /*SysIntFault_USS_SENSOR10_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00020000u) >> 10u);    /*SysIntFault_USS_SENSOR10_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00040000u) >> 18u);    /*SysIntFault_USS_SENSOR10_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00080000u) >> 18u);    /*SysIntFault_USS_SENSOR10_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00100000u) >> 18u);    /*SysIntFault_USS_SENSOR10_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00200000u) >> 18u);    /*SysIntFault_USS_SENSOR10_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00400000u) >> 18u);    /*SysIntFault_USS_SENSOR10_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x00800000u) >> 18u);    /*SysIntFault_USS_SENSOR10_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x01000000u) >> 18u);    /*SysIntFault_USS_SENSOR10_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x02000000u) >> 18u);    /*SysIntFault_USS_SENSOR10_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x04000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x08000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x10000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x20000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x40000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[30u] & 0x80000000u) >> 26u);    /*SysIntFault_USS_SENSOR10_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000001u) << 6u);    /*SysIntFault_USS_SENSOR10_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000002u) << 6u);    /*SysIntFault_USS_SENSOR10_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000004u) >> 2u);    /*SysIntFault_USS_SENSOR10_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000008u) >> 2u);    /*SysIntFault_USS_SENSOR10_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000010u) >> 2u);    /*SysIntFault_USS_SENSOR10_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000020u) >> 2u);    /*SysIntFault_USS_SENSOR10_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000040u) >> 2u);    /*SysIntFault_USS_SENSOR10_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000080u) >> 2u);    /*SysIntFault_USS_SENSOR10_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000100u) >> 2u);    /*SysIntFault_USS_SENSOR10_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000200u) >> 2u);    /*SysIntFault_USS_SENSOR10_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000400u) >> 10u);    /*SysIntFault_USS_SENSOR10_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00000800u) >> 10u);    /*SysIntFault_USS_SENSOR10_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00001000u) >> 10u);    /*SysIntFault_USS_SENSOR10_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00002000u) >> 10u);    /*SysIntFault_USS_SENSOR10_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00008000u) >> 11u);    /*SysIntFault_USS_SENSOR10_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00010000u) >> 11u);    /*SysIntFault_USS_SENSOR10_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00020000u) >> 11u);    /*SysIntFault_USS_SENSOR10_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00040000u) >> 11u);    /*SysIntFault_USS_SENSOR10_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00080000u) >> 19u);    /*SysIntFault_USS_SENSOR10_PROGRAM_EEPROM*/
        break;  

    case 53u: /*B129813*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000400u) >> 10u);    /*SENSOR11_OpenCkt_Fault*/
        break;  

    case 54u: /*B129892*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00400000u) >> 21u);    /*SENSOR11_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000080u) >> 5u);    /*SENSOR11_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00100000u) >> 17u);    /*SysIntFault_USS_SENSOR11_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00200000u) >> 17u);    /*SysIntFault_USS_SENSOR11_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00400000u) >> 17u);    /*SysIntFault_USS_SENSOR11_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x00800000u) >> 17u);    /*SysIntFault_USS_SENSOR11_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x01000000u) >> 17u);    /*SysIntFault_USS_SENSOR11_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x02000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x04000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x08000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x10000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x20000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x40000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[31u] & 0x80000000u) >> 25u);    /*SysIntFault_USS_SENSOR11_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000001u) << 7u);    /*SysIntFault_USS_SENSOR11_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000002u) >> 1u);    /*SysIntFault_USS_SENSOR11_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000004u) >> 1u);    /*SysIntFault_USS_SENSOR11_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000008u) >> 1u);    /*SysIntFault_USS_SENSOR11_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000010u) >> 1u);    /*SysIntFault_USS_SENSOR11_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000020u) >> 1u);    /*SysIntFault_USS_SENSOR11_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000040u) >> 1u);    /*SysIntFault_USS_SENSOR11_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000080u) >> 1u);    /*SysIntFault_USS_SENSOR11_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000100u) >> 1u);    /*SysIntFault_USS_SENSOR11_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000200u) >> 9u);    /*SysIntFault_USS_SENSOR11_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000400u) >> 9u);    /*SysIntFault_USS_SENSOR11_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00000800u) >> 9u);    /*SysIntFault_USS_SENSOR11_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00001000u) >> 9u);    /*SysIntFault_USS_SENSOR11_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00002000u) >> 9u);    /*SysIntFault_USS_SENSOR11_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00004000u) >> 9u);    /*SysIntFault_USS_SENSOR11_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00008000u) >> 9u);    /*SysIntFault_USS_SENSOR11_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00010000u) >> 9u);    /*SysIntFault_USS_SENSOR11_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00020000u) >> 17u);    /*SysIntFault_USS_SENSOR11_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00040000u) >> 17u);    /*SysIntFault_USS_SENSOR11_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00080000u) >> 17u);    /*SysIntFault_USS_SENSOR11_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00100000u) >> 17u);    /*SysIntFault_USS_SENSOR11_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00400000u) >> 18u);    /*SysIntFault_USS_SENSOR11_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x00800000u) >> 18u);    /*SysIntFault_USS_SENSOR11_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x01000000u) >> 18u);    /*SysIntFault_USS_SENSOR11_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x02000000u) >> 18u);    /*SysIntFault_USS_SENSOR11_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x04000000u) >> 26u);    /*SysIntFault_USS_SENSOR11_PROGRAM_EEPROM*/
        break;  

    case 55u: /*B129913*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00000800u) >> 11u);    /*SENSOR12_OpenCkt_Fault*/
        break;  

    case 56u: /*B129992*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00800000u) >> 22u);    /*SENSOR12_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000100u) >> 6u);    /*SENSOR12_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x08000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x10000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x20000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x40000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[32u] & 0x80000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000001u));   /*SysIntFault_USS_SENSOR12_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000002u));   /*SysIntFault_USS_SENSOR12_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000004u));   /*SysIntFault_USS_SENSOR12_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000008u));   /*SysIntFault_USS_SENSOR12_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000010u));   /*SysIntFault_USS_SENSOR12_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000020u));   /*SysIntFault_USS_SENSOR12_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000040u));   /*SysIntFault_USS_SENSOR12_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000080u));   /*SysIntFault_USS_SENSOR12_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000100u) >> 8u);    /*SysIntFault_USS_SENSOR12_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000200u) >> 8u);    /*SysIntFault_USS_SENSOR12_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000400u) >> 8u);    /*SysIntFault_USS_SENSOR12_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00000800u) >> 8u);    /*SysIntFault_USS_SENSOR12_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00001000u) >> 8u);    /*SysIntFault_USS_SENSOR12_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00002000u) >> 8u);    /*SysIntFault_USS_SENSOR12_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00004000u) >> 8u);    /*SysIntFault_USS_SENSOR12_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00008000u) >> 8u);    /*SysIntFault_USS_SENSOR12_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00010000u) >> 16u);    /*SysIntFault_USS_SENSOR12_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00020000u) >> 16u);    /*SysIntFault_USS_SENSOR12_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00040000u) >> 16u);    /*SysIntFault_USS_SENSOR12_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00080000u) >> 16u);    /*SysIntFault_USS_SENSOR12_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00100000u) >> 16u);    /*SysIntFault_USS_SENSOR12_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00200000u) >> 16u);    /*SysIntFault_USS_SENSOR12_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00400000u) >> 16u);    /*SysIntFault_USS_SENSOR12_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x00800000u) >> 16u);    /*SysIntFault_USS_SENSOR12_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x01000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x02000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x04000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x08000000u) >> 24u);    /*SysIntFault_USS_SENSOR12_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x20000000u) >> 25u);    /*SysIntFault_USS_SENSOR12_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x40000000u) >> 25u);    /*SysIntFault_USS_SENSOR12_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[33u] & 0x80000000u) >> 25u);    /*SysIntFault_USS_SENSOR12_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[34u] & 0x00000001u) << 7u);    /*SysIntFault_USS_SENSOR12_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[34u] & 0x00000002u) >> 1u);    /*SysIntFault_USS_SENSOR12_PROGRAM_EEPROM*/
        break;  

    case 57u: /*B12852A*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00004000u) >> 14u);    /*BCM12_PAMReqSts_Stuck_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00008000u) >> 14u);    /*BCM12_FTPAMReqSts_Stuck_Fault*/
        break;  

    case 58u: /*B217A1C*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00200000u) >> 18u);    /*V_Meas_RearCam_ADC_Ctrl_OORL*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x00400000u) >> 18u);    /*V_Meas_RearCam_ADC_Ctrl_OORH*/
        break;  

    case 59u: /*B217A92*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00400000u) >> 22u);    /*DS90UB962_RX2_CSI_RX_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x10000000u) >> 27u);    /*DS90UB962_CSI_TX0_DETECT_B217A*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00000002u) << 1u);    /*Rear_Cam_I2C_back_channel_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00010000u) >> 11u);    /*SVC_Rear_self_test_fail_SCCB_Register_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00020000u) >> 11u);    /*SVC_Rear_online_pixel_test_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00040000u) >> 11u);    /*SVC_Rear_analog_test_pattern_error*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00080000u) >> 19u);    /*SVC_Rear_row_column_id_checker_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00100000u) >> 19u);    /*SVC_Rear_analog_digital_sync_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00200000u) >> 19u);    /*SVC_Rear_digital_test_pattern_row_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00400000u) >> 19u);    /*SVC_Rear_blc_check_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00800000u) >> 19u);    /*SVC_Rear_PLL_Clock_Monitor_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x01000000u) >> 19u);    /*SVC_Rear_PLL_Lock_State_Monitoring_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x02000000u) >> 19u);    /*SVC_Rear_SCCB_CRC_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x04000000u) >> 19u);    /*SVC_Rear_SCCB_embedded_CRC_mismatch*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x08000000u) >> 27u);    /*SVC_Rear_SI_Default_Register_Check_error*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x10000000u) >> 27u);    /*SVC_Rear_MIPI_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x20000000u) >> 27u);    /*SVC_Rear_MIPI_ECC_2_bit_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x40000000u) >> 27u);    /*SVC_Rear_FIFO_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x80000000u) >> 27u);    /*SVC_Rear_ROM_CRC_Check_Fail*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000001u) << 5u);    /*SVC_Rear_OTP_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000002u) << 5u);    /*SVC_Rear_SRAM_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000004u) << 5u);    /*SVC_Rear_Temp_OOR*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000008u) >> 3u);     /*SVC_Rear_Temp_Snsr_Integrity_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000010u) >> 3u);    /*SVC_Rear_Temp_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000020u) >> 3u);    /*SVC_Rear_Cam_Pwr_Supply_OOR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000040u) >> 3u);    /*SVC_Rear_VoltageMonitor_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000080u) >> 3u);    /*SVC_Rear_Frame_Cntr_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000100u) >> 3u);    /*SVC_Rear_Cam_EEPROM_CRCMismatch_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[14u] & 0x00000200u) >> 3u);    /*Rear_Cam_Intrinsic_Zero*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x08000000u) >> 20u);    /*SVC_Rear_Cam_I2C_NACK_error*/
        break;  

    case 60u: /*B212B08*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00001000u) >> 8u);    /*SysIntFault_MCU_USS_MASTER_Rear_OC_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00002000u) >> 8u);    /*SysIntFault_MCU_USS_MASTER_Rear_DSI_Undervoltage_error*/
        break;  

    case 61u: /*B212B17*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00800000u) >> 21u);    /*USS_M_R_Short_to_Bat*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x01000000u) >> 21u);    /*USS_M_R_voltage_OOR_High*/
        break;  

    case 62u: /*B212B16*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x04000000u) >> 26u);    /*USS_M_R_short_to_GND*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x08000000u) >> 26u);    /*USS_M_R_voltage_OOR_Low*/
        break;  

    case 63u: /*B23C71C*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x08000000u) >> 24u);    /*V_Meas_RightCam_ADC_Ctrl_OORL*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[5u] & 0x10000000u) >> 24u);    /*V_Meas_RightCam_ADC_Ctrl_OORH*/
        break;  

    case 64u: /*B23C792*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x00040000u) >> 18u);    /*DS90UB962_RX0_CSI_RX_ERR*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[12u] & 0x02000000u) >> 24u);    /*DS90UB962_CSI_TX0_DETECT_B23C7*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[13u] & 0x00008000u) >> 13u);    /*Right_Cam_I2C_back_channel_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x40000000u) >> 25u);    /*SVC_Right_self_test_fail_SCCB_Register_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[15u] & 0x80000000u) >> 25u);    /*SVC_Right_online_pixel_test_error*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000001u) << 7u);    /*SVC_Right_analog_test_pattern_error*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000002u) >> 1u);     /*SVC_Right_row_column_id_checker_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000004u) >> 1u);    /*SVC_Right_analog_digital_sync_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000008u) >> 1u);    /*SVC_Right_digital_test_pattern_row_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000010u) >> 1u);    /*SVC_Right_blc_check_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000020u) >> 1u);    /*SVC_Right_PLL_Clock_Monitor_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000040u) >> 1u);    /*SVC_Right_PLL_Lock_State_Monitoring_error*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000080u) >> 1u);    /*SVC_Right_SCCB_CRC_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000100u) >> 1u);    /*SVC_Right_SCCB_embedded_CRC_mismatch*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000200u) >> 9u);     /*SVC_Right_SI_Default_Register_Check_error*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000400u) >> 9u);    /*SVC_Right_MIPI_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00000800u) >> 9u);    /*SVC_Right_MIPI_ECC_2_bit_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00001000u) >> 9u);    /*SVC_Right_FIFO_CRC_mismatch*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00002000u) >> 9u);    /*SVC_Right_ROM_CRC_Check_Fail*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00004000u) >> 9u);    /*SVC_Right_OTP_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00008000u) >> 9u);    /*SVC_Right_SRAM_CRC_MISMATCH*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00010000u) >> 9u);    /*SVC_Right_Temp_OOR*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00020000u) >> 17u);    /*SVC_Right_Temp_Snsr_Integrity_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00040000u) >> 17u);    /*SVC_Right_Temp_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00080000u) >> 17u);    /*SVC_Right_Cam_Pwr_Supply_OOR*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00100000u) >> 17u);    /*SVC_Right_VoltageMonitor_Self_Test_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00200000u) >> 17u);    /*SVC_Right_Frame_Cntr_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00400000u) >> 17u);    /*SVC_Right_Cam_EEPROM_CRCMismatch_Fault*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x00800000u) >> 17u);    /*Right_Cam_Intrinsic_Zero*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[16u] & 0x20000000u) >> 22u);    /*SVC_Right_Cam_I2C_NACK_error*/
        break;  

    case 65u: /*B223B00*/
        Data[0u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000400u) >> 10u);     /*PROXI_Fault_Steering_RackPinion_Ratio_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00000800u) >> 10u);    /*PROXI_Fault_Tyre_Size_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00001000u) >> 10u);    /*PROXI_Fault_PAM_TunSet_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00002000u) >> 10u);    /*PROXI_Fault_VehiLineConf_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00004000u) >> 10u);    /*PROXI_Fault_WB_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00008000u) >> 10u);    /*PROXI_Fault_PAM_Config_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00010000u) >> 10u);    /*PROXI_Fault_Radio_Display_Type_Incorr*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00020000u) >> 10u);    /*PROXI_CAN_Node_Incorr*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00040000u) >> 18u);     /*PROXI_GearBox_Type_Incorr*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00080000u) >> 18u);    /*PROXI_Model_Year_Incorr*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[1u] & 0x00100000u) >> 18u);    /*PROXI_AutoPark_Sys_Incorr*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[19u] & 0x00000008u));          /*SysIntFault_MCU_USS_MASTER_ECU_CFG_SENSOR_ERR*/
        break;  

    case 66u: /*B129392*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[17u] & 0x00020000u) >> 16u);    /*SENSOR6_USS_Power_Lost_Fault*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[18u] & 0x00000004u));           /*SENSOR6_USS_SWFirmWr_MisMatch*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00020000u) >> 14u);    /*SysIntFault_USS_SENSOR6_FLG_SIGNAL_PATH_FAILURE*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00040000u) >> 14u);    /*SysIntFault_USS_SENSOR6_Vref_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00080000u) >> 14u);    /*SysIntFault_USS_SENSOR6_VREF_OTP_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00100000u) >> 14u);    /*SysIntFault_USS_SENSOR6_VDDD_out_of_range*/
        Data[0u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00200000u) >> 14u);    /*SysIntFault_USS_SENSOR6_DRV1_FAILURE_DURING_BURST*/
        Data[1u] = (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00400000u) >> 22u);     /*SysIntFault_USS_SENSOR6_DRV2_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x00800000u) >> 22u);    /*SysIntFault_USS_SENSOR6_DRVS_FAILURE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x01000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_NOISE_DURING_BURST*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x02000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_DSP_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x04000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_CPU_Config_register_mismatch*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x08000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_RECEIVED_COMMAND_INVALID*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x10000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_WD_COUNTER_DESYNC*/
        Data[1u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x20000000u) >> 22u);    /*SysIntFault_USS_SENSOR6_WD_CLOCK_FAIL*/
        Data[2u] = (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x40000000u) >> 30u);    /*SysIntFault_USS_SENSOR6_SYNCHRONISATION_COUNTER_ERROR_DETECTED*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[25u] & 0x80000000u) >> 30u);    /*SysIntFault_USS_SENSOR6_GET_DRV_FREQUENCY_FAILURE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000001u) << 2u);    /*SysIntFault_USS_SENSOR6_RING_COMPARATOR_ZERO*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000002u) << 2u);    /*SysIntFault_USS_SENSOR6_VTANK_overvoltage_burst_status_failure*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000004u) << 2u);    /*SysIntFault_USS_SENSOR6_BURST_ABORT_DURING_BURST*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000008u) << 2u);    /*SysIntFault_USS_SENSOR6_VTANK_OVERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000010u) << 2u);    /*SysIntFault_USS_SENSOR6_VTANK_UNDERVOLTAGE*/
        Data[2u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000020u) << 2u);    /*SysIntFault_USS_SENSOR6_VSUP_OVER_VOLTAGE*/
        Data[3u] = (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000040u) >> 6u);    /*SysIntFault_USS_SENSOR6_VSUP_UNDER_VOLTAGE*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000080u) >> 6u);    /*SysIntFault_USS_SENSOR6_Temparature_out_of_range_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000100u) >> 6u);    /*SysIntFault_USS_SENSOR6_SRAM_Parity_error*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000200u) >> 6u);    /*SysIntFault_USS_SENSOR6_CRC_BLOCK_CFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000400u) >> 6u);    /*SysIntFault_USS_SENSOR6_CRC_BLOCK_CFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00000800u) >> 6u);    /*SysIntFault_USS_SENSOR6_CRC_BLOCK_MFG1*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00001000u) >> 6u);    /*SysIntFault_USS_SENSOR6_CRC_BLOCK_MFG2*/
        Data[3u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00002000u) >> 6u);    /*SysIntFault_USS_SENSOR6_CRC_OP_MODE1*/
        Data[4u] = (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00004000u) >> 14u);    /*SysIntFault_USS_SENSOR6_CRC_OP_MODE2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00008000u) >> 14u);    /*SysIntFault_USS_SENSOR6_CRC_MISMATCH_IN_OTP*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00010000u) >> 14u);    /*SysIntFault_USS_SENSOR6_CRC_MISTMATCH_IN_EEPROM_A1*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00020000u) >> 14u);    /*SysIntFault_USS_SENSOR6_CRC_MISTMATCH_IN_EEPROM_A2*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00080000u) >> 15u);    /*SysIntFault_USS_SENSOR6_SNR_OPMODE_ERROR*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00100000u) >> 15u);    /*SysIntFault_USS_SENSOR6_SNR_SETUP_SENSOR_FAIL*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00200000u) >> 15u);    /*SysIntFault_USS_SENSOR6_GET_RING_FREQUENCY_FAILURE*/
        Data[4u] |= (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00400000u) >> 15u);    /*SysIntFault_USS_SENSOR6_ADA_MEASURE_TIMEOUT*/
        Data[5u] = (uint8)((ErrorListArr_B_OR_VALUE[26u] & 0x00800000u) >> 23u);    /*SysIntFault_USS_SENSOR6_PROGRAM_EEPROM*/
        break;
               
    default:
    	/* Do Nothing */
    break;

  }
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_THA_state_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_THA_state>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_THA_state_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_THA_state_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_THA_state_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_THA_state_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_THA_state_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {9F722557-1E5F-4085-8111-669659542EAD}*/
  THA_STAT THAStatus;
  (void)Rte_Read_RpToSwcFD02Tx_THA_STAT(&THAStatus);

  VStdLib_MemClr(Data, (uint8)e_ONE);
  Data[e_ZERO] = THAStatus ;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_TRSC_Stat>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_TRSC_Stat_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {3D84A199-EBFF-4806-A26B-5A757FB37DBE}*/
  TRSC_STAT TRSCStatus;
  (void)Rte_Read_RpToSwcFD02Tx_TRSC_STAT(&TRSCStatus);
  VStdLib_MemClr(Data, (uint8)e_ONE);

  Data[e_ZERO] = TRSCStatus;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpProxiToSWC_Pamtuningset(uint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {3715EA4E-BDEF-4179-9912-9080D56C6AB9}*/
  TRSC_EnableBtn_Sts v_TRSCEnablebtnSts_u8;
  uint8 FullautomaticparkingStatus;
  uint8 Pamtuningset;
  
  (void)Rte_Read_RpToSwcFD02Rx_TRSC_EnableBtn_Sts(&v_TRSCEnablebtnSts_u8);
  (void)Rte_Read_RpProxiToSWC_Fullautomaticparking(&FullautomaticparkingStatus);
  (void)Rte_Read_RpProxiToSWC_Pamtuningset(&Pamtuningset);
  
  VStdLib_MemClr(Data, (uint8)e_ONE);
  
  if(Cx0_Not_Pressed == (uint8)v_TRSCEnablebtnSts_u8)
  {
        Data[e_ZERO] = (uint8)NOT_ENABLED;
  }
  else if(Cx1_Pressed == (uint8)v_TRSCEnablebtnSts_u8)
  {
        Data[e_ZERO] = (uint8)TRSC_ENABLED;
  }
  else
  {
       Data[e_ZERO] = v_TRSCEnablebtnSts_u8;
  }

  if(((uint8)e_ZERO == FullautomaticparkingStatus) && ((uint8)e_FOUR != Pamtuningset))
  {
	Data[e_ZERO] |= USS_STAT_EN;   /* Update 6th bit with USS status */
  }
  else
  {
       /*Do Nothing*/ 
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_TireLines_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_TireLines>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_TireLines_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_TireLines_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TireLines_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TireLines_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_TireLines_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {5A628ED1-EB2B-452b-A7D2-566309630C13}*/
  Fwrd_Cam_Guidelines FFTTireLines;
  uint8 ConvertData;
  (void)Rte_Read_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(&FFTTireLines);

  VStdLib_MemClr(Data, (uint8)e_ONE);
  ConvertData = CHECK_BIT(FFTTireLines,BIT_MASK_ONE_BIT);
  Data[e_ZERO] = (uint8)LEFTSHIFT_BIT(ConvertData ,BIT_SHIFT_SIX_BIT);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {1F929E8C-ACCF-44a2-913F-511CEB4058CC}*/
  CM_TCH_STAT TCHStatus;
  (void)Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_STAT(&TCHStatus);
  Data[e_ZERO] = TCHStatus;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {1590EBA4-AB28-49c8-8015-4F5F47D4D5D4}*/
  CM_TCH_X_COORD v_TCH_XCoordinate_16;
  (void)Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_X_COORD(&v_TCH_XCoordinate_16);
  /* Get TCH_X_COORD info */
  Data[e_ZERO] = v_TCH_XCoordinate_16;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {DCFBA4C2-9054-4387-AD45-8196E82217DC}*/
  CM_TCH_Y_COORD v_TCH_YCoordinate_u16;
  (void)Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD(&v_TCH_YCoordinate_u16);
  /* Get TCH_Y_COORD info */
  Data[e_ZERO] = v_TCH_YCoordinate_u16;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_Data_OccurrenceCounter_Vehicle_Speed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData (returns application error)
 *********************************************************************************************************************/
  /* DD-ID: {BD7CBB8D-12C3-427d-9459-0535E3BF4B0F}*/
    VehicleSpeedVSOSig v_vehicleSpd_u16;
    /*Get Vehicle Speed*/
    (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_vehicleSpd_u16);
    /*Send Vehicle Speed Response Data*/
    Data[e_ZERO] = v_vehicleSpd_u16;
 
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_ClearDTCSettingStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearDTCSettingStatus> of PortPrototype <PpClearDTCSettingStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_ClearDTCSettingStatus(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ClearDTCSettingStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_DTCMgr_CODE) RE_ClearDTCSettingStatus(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ClearDTCSettingStatus
 *********************************************************************************************************************/
  /* DD-ID: {7FEBC3BB-A40A-4796-B6D7-E5CB8A47AD2F}*/
	VStdLib_MemSet(&DTC_Setting_Status,0x00,sizeof(DTC_Setting_Status));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_DTCMgr_EtROEMessage
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Data> of PortPrototype <RoEMessageSRI>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RoEMessageSRI_Data(uint8 *data)
 *     Argument data: uint8* is of type vRoE_MessageType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpToComFD02Tx_N_PDU(const uint8 *data)
 *     Argument data: uint8* is of type N_PDU
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_EtROEMessage_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_EtROEMessage(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_EtROEMessage
 *********************************************************************************************************************/
 /*ReqID:-16142558,16142563*/
  /*GUID:-{E0C37421-397B-483e-93DA-1AFD683FBFF6}*/
  /* DD-ID: {E0C37421-397B-483e-93DA-1AFD683FBFF6}*/
  uint8 v_ROE_Meassage_au8[e_EIGHT];

   /* Initialise Array with zero value*/
  VStdLib_MemClr(v_ROE_Meassage_au8,(uint8)e_EIGHT);

 (void)Rte_Read_RoEMessageSRI_Data(v_ROE_Meassage_au8);
 (void)Rte_Write_PpToComFD02Tx_N_PDU(v_ROE_Meassage_au8);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_DTCMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_Init
 *********************************************************************************************************************/
  /*ReqID:-*/
  /*GUID:-{FB986904-B67E-4bb8-9CAD-65B451459F00}*/
  /* DD-ID: {FB986904-B67E-4bb8-9CAD-65B451459F00}*/
 (void)Rte_Call_Dem_OperationCycle_SetOperationCycleState(DEM_CYCLE_STATE_START);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_DTCMgr_Main
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
 *   Std_ReturnType Rte_Read_PRpDtcSettingClearFlagModeGrp_requestedMode(BswM_DtcSettingClearFlagModeGrp *data)
 *   Std_ReturnType Rte_Read_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(boolean *data)
 *   Std_ReturnType Rte_Read_R_DtcData_B_Data_DtcAddData_B(DtcAddData_B *data)
 *   Std_ReturnType Rte_Read_R_DtcData_B_Data_DtcStatus_B(DtcStatus_B *data)
 *   Std_ReturnType Rte_Read_R_DtcData_QM_Data_DtcAddData_QM(DtcAddData_QM *data)
 *   Std_ReturnType Rte_Read_R_DtcData_QM_Data_DtcStatus_QM(DtcStatus_QM *data)
 *   Std_ReturnType Rte_Read_RoEMessageSRI_Data(uint8 *data)
 *     Argument data: uint8* is of type vRoE_MessageType
 *   Std_ReturnType Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(TbAP_APSMPAOut_t *data)
 *   Std_ReturnType Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0(CalDataProvider_MCU_1_0_Def *data)
 *   Std_ReturnType Rte_Read_RpDLDOutput_JobDLDOutput_t(JobDLDOutput_t *data)
 *   Std_ReturnType Rte_Read_RpECUTimeSinceIGON_ECUTimeStamp_IGON(uint32 *data)
 *   Std_ReturnType Rte_Read_RpECUTimeStamp_ECUTimeStamp(uint32 *data)
 *   Std_ReturnType Rte_Read_RpErrors_B_Errors_B(uint32 *data)
 *     Argument data: uint32* is of type ErrorListArr_B
 *   Std_ReturnType Rte_Read_RpErrors_QM_Errors_QM(uint32 *data)
 *     Argument data: uint32* is of type ErrorListArr_QM
 *   Std_ReturnType Rte_Read_RpIgOnCounter_IGCounter(uint32 *data)
 *   Std_ReturnType Rte_Read_RpPlantMode_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_Fullautomaticparking(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_SurroundViewCam_u8(uint8 *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_TyreSz_u16(uint16 *data)
 *   Std_ReturnType Rte_Read_RpSystemStateManager_SysM_State(SystemState *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_Battery_Volt_1(uint16 *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_OperationalModeSts(OperationalModeSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_TRSC_EnableBtn_Sts(TRSC_EnableBtn_Sts *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Rx_TotalOdometer(TotalOdometer *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Tx_THA_STAT(THA_STAT *data)
 *   Std_ReturnType Rte_Read_RpToSwcFD02Tx_TRSC_STAT(TRSC_STAT *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_APARequestSts(APARequestSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_STAT(CM_TCH_STAT *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_X_COORD(CM_TCH_X_COORD *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD(CM_TCH_Y_COORD *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CameraDisplaySts2(CameraDisplaySts2 *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(CmdIgnSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts(DriverDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_ExternalTemperature(uint16 *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(Fwrd_Cam_Guidelines *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(GearEngaged *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts(LHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts(PsngrDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts(RHRDoorSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_RHatchSts(RHatchSts *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition(ShiftLeverPosition *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(TGW_CAMERA_DISP_STAT *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Tx_DisplayView2(DisplayView2 *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(FD14_ESS_ENG_ST_W *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle(FD14_LwsAngle *data)
 *   Std_ReturnType Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(uint16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PRpDtcSettingClearFlagModeGrp_requestedMode(BswM_DtcSettingClearFlagModeGrp data)
 *   Std_ReturnType Rte_Write_PpDtcB12852AData_v_DtcData_u8(uint8 data)
 *   Std_ReturnType Rte_Write_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(boolean data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_RpReadVoltInfo_GetVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, float32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Dem_EnableCondition1_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition10_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition1_4_8_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition1_8_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition2_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition4_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition5_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition7_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_EnableCondition9_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_Dem_OperationCycle_GetOperationCycleState(Dem_OperationCycleStateType *CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *   Std_ReturnType Rte_Call_Dem_OperationCycle_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_DTC_APARequestSts_PAMRequestSts_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B12852A_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B128E13_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B128E92_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B128F13_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B128F92_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129013_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129092_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129113_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129192_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129213_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129292_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129313_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129392_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129413_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129492_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129513_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129592_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129613_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129692_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129713_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129792_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129813_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129892_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129913_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B129992_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B12B22A_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B210C16_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B210C17_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212A08_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212A16_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212A17_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212B08_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212B16_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B212B17_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B217A1C_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B217A92_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B223B00_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B228600_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B22A900_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C51C_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C592_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C61C_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C692_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C71C_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_B23C792_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_C221200_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_P060200_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U010000_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U012900_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U013100_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U014000_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U015100_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U018400_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026400_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026500_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026600_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U026700_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U040100_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U041800_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U042000_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U042200_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U045500_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U048500_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U100B00_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U104E00_GetEventStatus(Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U104E00_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U12B900_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_RpEventDTC_U14A000_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_DTCMgr_Main
 *********************************************************************************************************************/
   /*ReqID:-*/
   /*GUID:-{7A3736C4-E06C-42c9-8448-4E57D16EAF72}*/
  /* DD-ID: {7A3736C4-E06C-42c9-8448-4E57D16EAF72}*/
  TbAP_APSMPAOut_t st_APSMPAOutData;
  VehicleSpeedVSOSig v_VehSpd;
  GearEngaged v_GearEngaged;
  uint8 st_PPPAFeatureEnbl;
  uint8 st_FPAFeatureEnbl = FALSE;
  uint8 st_RPAFeatureEnbl = FALSE;

  BswM_DtcSettingClearFlagModeGrp v_ClearDTCStatusFlag_u8;
  static DtcStatus_B Dtc_flag_status_B;
  static DtcAddData_B Dtc_Additionaldata_B;
  static DtcStatus_QM Dtc_flag_status_QM;
  static DtcAddData_QM Dtc_Additionaldata_QM;

   (void)Rte_Write_PpDtcB12852AData_v_DtcData_u8(Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock);    /* Status of DTC B1285-2A set or not Sending to SafeVCAN */
  (void)Rte_Read_R_DtcData_B_Data_DtcAddData_B(&Dtc_Additionaldata_B);
  (void)Rte_Read_R_DtcData_B_Data_DtcStatus_B(&Dtc_flag_status_B);

  (void)Rte_Read_R_DtcData_QM_Data_DtcAddData_QM(&Dtc_Additionaldata_QM);
  (void)Rte_Read_R_DtcData_QM_Data_DtcStatus_QM(&Dtc_flag_status_QM);

  (void)Rte_Read_PRpDtcSettingClearFlagModeGrp_requestedMode(&v_ClearDTCStatusFlag_u8);

  if (v_ClearDTCStatusFlag_u8 == (uint8)TRUE)
  {
	/* when there is change in dem operation cycle then clear structure DTC_SEETING_FLAG */
	(void)RE_ClearDTCSettingStatus();
	v_ClearDTCStatusFlag_u8 = (uint8)FALSE;
	(void)Rte_Write_PRpDtcSettingClearFlagModeGrp_requestedMode(v_ClearDTCStatusFlag_u8);
  }
  else
  {
   /*Do Nothing*/
  }
  (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(&v_VehSpd); /* Read vehicle speed */
  (void)Rte_Read_SWC_DTCMgr_RpAPSMPAOut_TbAP_APSMPAOut_t(&st_APSMPAOutData); /* Read PA Feature Enable Status */
  (void)Rte_Read_RpToSwcSafeFD02Rx_GearEngaged(&v_GearEngaged);
  st_PPPAFeatureEnbl = F_PPPAEnable_Status_Check(); /* Evaluate PPPA Feature Enable status */
  F_DTC_Check_Enable_Condition();
  
  /* Evaluate Front Park Assist Feature Enable status */
  if(((((uint8)TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF == (uint8)st_APSMPAOutData.IeAP_e_FrntRearParkSts)
			||( (uint8)TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON == (uint8)st_APSMPAOutData.IeAP_e_FrntRearParkSts))
		&&(DTC_ENABLE_SPPED_LIMIT >= v_VehSpd)
		&&(((Cx1_ForwardGear_1 <= (uint8)v_GearEngaged)&&(Cx9_ForwardGear_9 >= (uint8)v_GearEngaged)) || (CxE_ReverseGear == (uint8)v_GearEngaged)))
	|| (v_InPlantMode == (uint8) TRUE)
	|| (v_SensrTestFlag == (uint8) TRUE)
	 )
  {
      st_FPAFeatureEnbl = TRUE;
  }
  else{/*Do Nothing*/}

  /* Evaluate Rear Park Assist Feature Enable status */
  /* VCAST Jenkins requirement - do not modify */
  /* VCAST Jenkins requirement - do not modify */
  if(((((uint8)TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON == (uint8)st_APSMPAOutData.IeAP_e_FrntRearParkSts)
			||( (uint8)TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON == (uint8)st_APSMPAOutData.IeAP_e_FrntRearParkSts))
		&&(DTC_ENABLE_SPPED_LIMIT >= v_VehSpd)
		&&(((Cx1_ForwardGear_1 <= (uint8)v_GearEngaged)&&(Cx9_ForwardGear_9 >= (uint8)v_GearEngaged)) || (CxE_ReverseGear == (uint8)v_GearEngaged)))
	|| (v_InPlantMode == (uint8) TRUE)
	|| (v_SensrTestFlag == (uint8) TRUE)
	 )
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
  {
      st_RPAFeatureEnbl = TRUE;
  }
  else{/*Do Nothing*/}


  

  /* DTC Implementation */

  /*DTC B1285_2A*/
  	if( Dtc_flag_status_B.b1285_2a_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1285_2A !=(uint8)e_ONE)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B12852A_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1285_2A =(uint8)e_ONE;

  				Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock = TRUE;                               /* Update Mirror Variable */
  				(void)Rte_Call_NvMService_AC3_SRBS_DTC_APARequestSts_PAMRequestSts_SetRamBlockStatus(TRUE);      /* Inform to DEM write while shutdown,Sleep */

  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1285_2A !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B12852A_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1285_2A =(uint8)e_TWO;

  				Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock = FALSE;							  /* Update Mirror Variable */
  				(void)Rte_Call_NvMService_AC3_SRBS_DTC_APARequestSts_PAMRequestSts_SetRamBlockStatus(TRUE);   /* Inform to DEM write while shutdown,Sleep */
  			}
  		}

  	}

  	/*DTC B128E_13*/
  	if( Dtc_flag_status_B.b128e_13_0==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B128E_13 !=(uint8)e_ONE) 
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128E13_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B128E_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B128E_13 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128E13_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128E_13 =(uint8)e_TWO;
  			}
  		}

  	}

  	/*DTC B128E_92*/
  	if( Dtc_flag_status_B.b128e_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B128E_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128E92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128E_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B128E_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128E92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128E_92 =(uint8)e_TWO;
  			}

  		}

  	}

  	/*DTC B128F_13*/
  	if( Dtc_flag_status_B.b128f_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B128F_13 !=(uint8)e_ONE)
                  && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO ==Rte_Call_RpEventDTC_B128F13_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128F_13 =(uint8)e_ONE;
  			}

  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B128F_13 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128F13_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128F_13 =(uint8)e_TWO;
  			}

  		}
  	}

  	/*DTC B128F_92*/
  	if( Dtc_flag_status_B.b128f_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B128F_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128F92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128F_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B128F_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B128F92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B128F_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1290_13*/
  	if( Dtc_flag_status_B.b1290_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1290_13 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129013_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1290_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1290_13 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129013_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1290_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1290_92*/
  	if( Dtc_flag_status_B.b1290_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1290_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129092_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1290_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1290_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO ==Rte_Call_RpEventDTC_B129092_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1290_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1291_13*/
  	if( Dtc_flag_status_B.b1291_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1291_13 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129113_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1291_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1291_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129113_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1291_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1291_92*/
  	if( Dtc_flag_status_B.b1291_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1291_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129192_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1291_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1291_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129192_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1291_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1292_13*/
  	if( Dtc_flag_status_B.b1292_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1292_13 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129213_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1292_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1292_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129213_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1292_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1292_92*/
  	if( Dtc_flag_status_B.b1292_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1292_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129292_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1292_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1292_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129292_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1292_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1293_13*/
  	if( Dtc_flag_status_B.b1293_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1293_13 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if ( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129313_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1293_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1293_13 !=(uint8)e_TWO)
  		{
  			if ( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129313_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1293_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1293_92*/
  	if( Dtc_flag_status_B.b1293_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1293_92 !=(uint8)e_ONE)
                   && ((TRUE == st_FPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129392_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1293_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1293_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129392_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1293_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1294_13*/
  	if( Dtc_flag_status_B.b1294_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1294_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO ==Rte_Call_RpEventDTC_B129413_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_B1294_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1294_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO ==Rte_Call_RpEventDTC_B129413_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_B1294_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1294_92*/
  	if( Dtc_flag_status_B.b1294_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1294_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129492_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1294_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1294_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129492_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1294_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1295_13*/
  	if( Dtc_flag_status_B.b1295_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1295_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129513_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1295_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1295_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129513_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1295_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1295_92*/
  	if( Dtc_flag_status_B.b1295_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1295_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129592_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1295_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1295_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO ==  Rte_Call_RpEventDTC_B129592_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1295_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1296_13 */
  	if( Dtc_flag_status_B.b1296_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1296_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129613_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1296_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1296_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129613_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1296_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1296_92 */
  	if( Dtc_flag_status_B.b1296_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1296_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129692_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1296_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1296_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129692_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1296_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/*DTC B1297_13 */
  	if( Dtc_flag_status_B.b1297_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1297_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129713_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1297_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1297_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129713_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1297_13 =(uint8)e_TWO;
  			}
  		}

  	}

  	/* DTC B1297_92 */
  	if( Dtc_flag_status_B.b1297_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1297_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129792_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_B1297_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1297_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B129792_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_B1297_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B1298_13 */
  	if( Dtc_flag_status_B.b1298_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1298_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129813_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1298_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1298_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129813_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1298_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B1298_92 */
  	if( Dtc_flag_status_B.b1298_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1298_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129892_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B1298_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1298_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129892_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B1298_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B1299_13 */
  	if( Dtc_flag_status_B.b1299_13_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1299_13 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129913_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1299_13 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1299_13 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129913_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1299_13 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B1299_92 */
  	if( Dtc_flag_status_B.b1299_92_0 ==(uint8)e_ONE )
  	{
  		if((DTC_Setting_Status.DTC_FAILED_B1299_92 !=(uint8)e_ONE)
                   && ((TRUE == st_RPAFeatureEnbl) || (TRUE == st_PPPAFeatureEnbl)))
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129992_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1299_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B1299_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B129992_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B1299_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B12B2_2A */
  	if( Dtc_flag_status_B.b12b2_2a_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B12B2_2A !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B12B22A_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B12B2_2A =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B12B2_2A !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B12B22A_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B12B2_2A =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B210C_16 */
  	if( Dtc_flag_status_B.b210c_16_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B210C_16 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B210C16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B210C_16 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B210C_16 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B210C16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B210C_16 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B210C_17 */
  	if( Dtc_flag_status_B.b210c_17_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B210C_17 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B210C17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B210C_17 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B210C_17 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B210C17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B210C_17 =(uint8)e_TWO;
  			}
  		}
  	}


  	if( Dtc_flag_status_B.b212a_8_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_8!=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A08_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_8=(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_8!=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A08_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_8=(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B212A_16 */
  	if( Dtc_flag_status_B.b212a_16_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_16 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_16 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_16 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_16 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B212A_17 */
  	if( Dtc_flag_status_B.b212a_17_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_17 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_17 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212A_17 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212A17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212A_17 =(uint8)e_TWO;
  			}
  		}
  	}


  	 if( Dtc_flag_status_B.b212b_8_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_8 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B08_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B212B_8 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_8 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B08_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B212B_8 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B212B_16 */
  	if( Dtc_flag_status_B.b212b_16_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_16 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212B_16 =(uint8)e_ONE;
  			}

  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_16 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B16_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212B_16 =(uint8)e_TWO;
  			}

  		}
  	}

  	/* DTC B212B_17 */
  	if( Dtc_flag_status_B.b212b_17_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_17 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212B_17 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B212B_17 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B212B17_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B212B_17 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B217A_1C */
  	if( Dtc_flag_status_B.b217a_1c_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B217A_1C !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B217A1C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B217A_1C =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B217A_1C !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B217A1C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B217A_1C =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B217A_92 */
  	if( Dtc_flag_status_B.b217a_92_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B217A_92 !=(uint8)e_ONE)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B217A92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B217A_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B217A_92 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B217A92_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B217A_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B223B_00 */
  	if( Dtc_flag_status_B.b223b_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B223B_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B223B00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B223B_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B223B_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B223B00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B223B_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B2286_00 */
  	if( Dtc_flag_status_B.b2286_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B2286_0 !=(uint8)e_ONE)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B228600_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B2286_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B2286_0 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_B228600_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B2286_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B22A9_00 */
  	if( Dtc_flag_status_B.b22a9_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B22A9_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B22A900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B22A9_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B22A9_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B22A900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B22A9_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C5_1C */
  	if( Dtc_flag_status_B.b23c5_1c_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C5_1C !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C51C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B23C5_1C =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C5_1C !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C51C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_B23C5_1C =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C5_92 */
  	if( Dtc_flag_status_B.b23c5_92_0  ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C5_92 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C592_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C5_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C5_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C592_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C5_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C6_1C */
  	if( Dtc_flag_status_B.b23c6_1c_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C6_1C !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C61C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C6_1C =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C6_1C !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C61C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C6_1C =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C6_92 */
  	if( Dtc_flag_status_B.b23c6_92_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C6_92 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C692_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C6_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C6_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C692_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C6_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C7_1C */
  	if( Dtc_flag_status_B.b23c7_1c_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C7_1C !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C71C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C7_1C =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C7_1C !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C71C_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C7_1C =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC B23C7_92 */
  	if( Dtc_flag_status_B.b23c7_92_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C7_92 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C792_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C7_92 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_B23C7_92 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_B23C792_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_B23C7_92 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC C2212_00 */
  	if( Dtc_flag_status_B.c2212_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_C2212_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_C221200_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_C2212_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_C2212_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_C221200_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_C2212_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0100_00 */
  	if( Dtc_flag_status_B.u0100_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0100_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U010000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0100_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0100_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U010000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0100_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0129_00 */
  	if( Dtc_flag_status_B.u0129_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0129_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U012900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0129_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0129_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U012900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0129_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0131_00 */
  	if( Dtc_flag_status_B.u0131_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0131_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U013100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_U0131_0 =(uint8)e_ONE;
  			}
  		}


  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0131_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U013100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED) )
  			{
  				DTC_Setting_Status.DTC_FAILED_U0131_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0140_00 */
  	if( Dtc_flag_status_B.u0140_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0140_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U014000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0140_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0140_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U014000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0140_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0151_00 */
  	if( Dtc_flag_status_QM.u0151_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0151_0 !=(uint8)e_ONE)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_U015100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0151_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0151_0 !=(uint8)e_TWO)
  		{
  			if((uint8)e_ZERO == Rte_Call_RpEventDTC_U015100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0151_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0184_00 */
  	if( Dtc_flag_status_B.u0184_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0184_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U018400_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0184_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0184_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U018400_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0184_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0264_00 */
  	if( Dtc_flag_status_B.u0264_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0264_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026400_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0264_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0264_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026400_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0264_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0265_00 */
  	if( Dtc_flag_status_B.u0265_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0265_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0265_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0265_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0265_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0266_00 */
  	if( Dtc_flag_status_B.u0266_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0266_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026600_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0266_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0266_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026600_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0266_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0267_00 */
  	if( Dtc_flag_status_B.u0267_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0267_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026700_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0267_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0267_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U026700_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0267_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0401_00 */
  	if( Dtc_flag_status_B.u0401_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0401_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U040100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0401_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0401_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U040100_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0401_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0418_00 */
  	if( Dtc_flag_status_B.u0418_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0418_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U041800_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0418_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0418_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U041800_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0418_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0420_00 */
  	if( Dtc_flag_status_B.u0420_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0420_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U042000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0420_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0420_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U042000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0420_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0422_00 */
  	if( Dtc_flag_status_B.u0422_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0422_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U042200_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_U0422_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0422_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U042200_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				 DTC_Setting_Status.DTC_FAILED_U0422_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0455_00 */
  	if( Dtc_flag_status_QM.u0455_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0455_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U045500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0455_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0455_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U045500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0455_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U0485_00 */
  	if( Dtc_flag_status_B.u0485_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0485_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U048500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0485_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U0485_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U048500_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U0485_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U100B_00 */
  	if( Dtc_flag_status_B.u100b_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U100B_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U100B00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U100B_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U100B_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U100B00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U100B_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U104E_00 */
  	if( Dtc_flag_status_B.u104e_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U104E_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U104E00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U104E_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U104E_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U104E00_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U104E_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U12B9_00 */
  	if( Dtc_flag_status_QM.u12b9_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U12B9_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U12B900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U12B9_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U12B9_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U12B900_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U12B9_0 =(uint8)e_TWO;
  			}
  		}
  	}

  	/* DTC U14A0_00 */
  	if( Dtc_flag_status_QM.u14a0_0_0 ==(uint8)e_ONE )
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U14A0_0 !=(uint8)e_ONE)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U14A000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_FAILED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U14A0_0 =(uint8)e_ONE;
  			}
  		}

  	}
  	else
  	{
  		if( DTC_Setting_Status.DTC_FAILED_U14A0_0 !=(uint8)e_TWO)
  		{
  			if( (uint8)e_ZERO == Rte_Call_RpEventDTC_U14A000_SetEventStatus((Dem_EventStatusType) DEM_EVENT_STATUS_PASSED))
  			{
  				DTC_Setting_Status.DTC_FAILED_U14A0_0 =(uint8)e_TWO;
  			}
  		}
  	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_DTCMgr_STOP_SEC_CODE
#include "SWC_DTCMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* ===========================================================================
 *
 *   Name: F_DTC_Check_Enable_Condition
 *
 *   Function: Check all DTCs Enable condition
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
 static FUNC(void, SWC_DTCMgr_CODE) F_DTC_Check_Enable_Condition(void)
  {
   /*ReqID:-115059262,15224821,15238558,15238688,15460786,15460709,15460729,15460797,15460821,15460721,
	        15460731,15460798,15460794,15460830, 15460661,15460744,15738236,15460818,15460809,15739200,
          15460758,15460743,15739524,15460734,15460780,15739559,15460775,15460768, 15739578,15460712,
          15460736,15460727,15460657,15460819,15460762,15460703,15460660,15460689,15460687,15460711,
          15460799,15460792,15460803,15460690,15460801,15460827,15460820,15460752,15460747,15460774,
          15460767,15460720,15460672,15460658,15460742,15460756, 15738240,15460699,15460802,15460688,15460806*/
   /* DD-ID: {4D086F79-7EC5-40b1-88A9-23D20A2C26D5}*/

    CmdIgnSts v_IgnitionStatus;
    FD14_ESS_ENG_ST_W v_StrtStpWarmCrank;
    float32 v_BatteryVoltageValue_f32;
    Dem_UdsStatusByteType v_DTCStatusByte;
    uint8 v_ConditionFaultFlag_au8[e_SEVEN];
    boolean v_DTCFaultFlag_b;
    static uint16 v_Crank_Delay_Counter_u16 = (uint8)e_ZERO;
    uint16 v_sysVolatge;
    static uint16 FiveSecDelay = (uint8)e_ZERO;
    uint8 v_PlantMode_u8;
    ParkingManeuverActive v_Parkingstatus;
    uint8 v_CameraVariant_u8;
      /* Initialise Array with zero value*/
    VStdLib_MemClr(v_ConditionFaultFlag_au8,(uint8)e_SEVEN);

      /*Get Ignition Status*/
    (void)Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts(&v_IgnitionStatus);
    /*Get Start Stop Warm Crank Value*/
    (void)Rte_Read_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(&v_StrtStpWarmCrank);
    /*Get Battery Voltage*/
    (void)Rte_Call_RpReadVoltInfo_GetVoltageInfo(Vol_VBAT_MON, &v_BatteryVoltageValue_f32);
    /*Get DTC U104E00 Status*/
    (void)Rte_Call_RpEventDTC_U104E00_GetEventStatus(&v_DTCStatusByte);
    /*Get System Voltage */
     (void)Rte_Read_RpToSwcFD02Rx_Battery_Volt_1(&v_sysVolatge);
      /*Read RID5101 sensor functiona test flag*/
     (void)Rte_Read_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(&v_SensrTestFlag);
      /*Read status of plant mode*/
     (void)Rte_Read_RpPlantMode_Status(&v_PlantMode_u8);
      /*Read status of ParkingManeuverActive*/
     (void)Rte_Read_RpToSwcSafeFD02Tx_ParkingManeuverActive(&v_Parkingstatus);
     /*Read status of Surround view system proxy parameter*/
     (void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_CameraVariant_u8);

        /**********************************************************************************************************************
        * EnableCondition1
        * Ignition Run  and 5 second crank delay timer expired: BCM_FD_10.CmdIgnsts = RUN for 5Sec
        *********************************************************************************************************************/
		if(v_IgnitionStatus == Cx4_RUN)
		{
		  if(v_Crank_Delay_Counter_u16 >= ((uint16)D_CRANK_DELAY_TIME))
		  {
			v_ConditionFaultFlag_au8[e_ZERO] = TRUE;
		  }
		  else
		  {
			v_ConditionFaultFlag_au8[e_ZERO] = FALSE;
			v_Crank_Delay_Counter_u16++;
		  }
		  /*Send Condition1 fulfilled Status*/
		  (void)Rte_Call_Dem_EnableCondition1_SetEnableCondition(v_ConditionFaultFlag_au8[e_ZERO]);
		}
		else
		{
		  v_Crank_Delay_Counter_u16 =(uint8)e_ZERO;
		  (void)Rte_Call_Dem_EnableCondition1_SetEnableCondition(FALSE);
		}

	/**********************************************************************************************************************
	* EnableCondition2
	* Battery Voltage / ECU Voltage : 9.0V to 16.0 V
	*********************************************************************************************************************/

		if((v_BatteryVoltageValue_f32 > (float32)D_VALID_VOL_LOW_RANGE) && (v_BatteryVoltageValue_f32 < (float32)D_VALID_VOL_HIGH_RANGE))
		{
		  v_ConditionFaultFlag_au8[e_ONE] = TRUE;
		}
		else
		{
		  v_ConditionFaultFlag_au8[e_ONE] = FALSE;
		}
		/*Send Condition2 fulfilled Status*/
		(void)Rte_Call_Dem_EnableCondition2_SetEnableCondition(v_ConditionFaultFlag_au8[e_ONE] );

	/**********************************************************************************************************************
	* EnableCondition4
	* Start Stop Warm Crank is not in progress
	*********************************************************************************************************************/

		if(((v_StrtStpWarmCrank != Cx2_ENS_Request_Start_ENS_RQ_ST) && (v_StrtStpWarmCrank != Cx9_ENS_Starting_ENS_Starting)) && (v_IgnitionStatus == Cx4_RUN)) /*Updated as per Req ID:19310320 & 16297734*//*PRQA S 2995*/
		{
		  v_ConditionFaultFlag_au8[e_THREE] = TRUE;
		}
		else
		{
		  v_ConditionFaultFlag_au8[e_THREE] = FALSE;
		}
		/*Send Condition4 fulfilled Status*/
		(void)Rte_Call_Dem_EnableCondition4_SetEnableCondition(v_ConditionFaultFlag_au8[e_THREE]);


	/**********************************************************************************************************************
	* EnableCondition5
	* U104E_DTC_Not Active
	*********************************************************************************************************************/

		v_DTCFaultFlag_b = ((v_DTCStatusByte) & (D_DTC_TEST_FAILED_STATUS_MASK));
		if(v_DTCFaultFlag_b == FALSE)
		{
		  v_ConditionFaultFlag_au8[e_FOUR] = TRUE;
		}
		else
		{
		  v_ConditionFaultFlag_au8[e_FOUR] = FALSE;
		}
		/*Send Condition5 fulfilled Status*/
		(void)Rte_Call_Dem_EnableCondition5_SetEnableCondition(v_ConditionFaultFlag_au8[e_FOUR]);

        /**********************************************************************************************************************
     	* EnableCondition7
     	* check EnableCondition7 = CVPAM_FD_Control.ParkingManeuverActive != Engaged_Full
	*********************************************************************************************************************/
	
                if (v_Parkingstatus != Cx3_Engaged_Full)
                {
		  v_ConditionFaultFlag_au8[e_SIX] = TRUE;    
                }
                else
		{
		  v_ConditionFaultFlag_au8[e_SIX] = FALSE;
		}
      		(void)Rte_Call_Dem_EnableCondition7_SetEnableCondition(v_ConditionFaultFlag_au8[e_SIX] );
        /**********************************************************************************************************************
     	* EnableCondition8
     	* RID5101 trigger to start sensor functional test
	*********************************************************************************************************************/

                /* VCAST Jenkins requirement - do not modify */
                /* VCAST Jenkins requirement - do not modify */
                if((uint8)v_SensrTestFlag == (uint8)TRUE)  /*this flag is set when we trigger rid 5101 sensor functional test */
                /* VCAST Jenkins requirement - do not modify */
                /* VCAST Jenkins requirement - do not modify */
                {
                   if(FiveSecDelay <= (uint16)D_FIVESEC_CNTR)
	            {           
                      FiveSecDelay = FiveSecDelay + 1u;
                    }
                    else
                   {
                      FiveSecDelay = (uint8)e_ZERO;
                      v_SensrTestFlag = (boolean)FALSE;
                      (void)Rte_Write_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(FALSE);

                        /*sending MbDiag_SensorTestMode data FALSE to IPC */
                        DiagToParkAssist_data.MbDiag_SensorTestMode = FALSE;
                        (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&DiagToParkAssist_data, (uint16)e_IpcMsgId_Data_DiagToParkAssist_t, (uint16)sizeof(DiagToParkAssist_t));
                    }
                }

                /*((EnableCondition1 ANDing  EnableCondition4) ORing(EnableCondition8))*/
                if (((v_ConditionFaultFlag_au8[e_ZERO] == TRUE) && (v_ConditionFaultFlag_au8[e_THREE] == TRUE)) || (v_SensrTestFlag == TRUE))
                {
                (void)Rte_Call_Dem_EnableCondition1_4_8_SetEnableCondition(TRUE);
                }
                else
                {
                (void)Rte_Call_Dem_EnableCondition1_4_8_SetEnableCondition(FALSE);
                }

                /*(EnableCondition1 ORing EnableCondition8)*/
                /* VCAST Jenkins requirement - do not modify */
                /* VCAST Jenkins requirement - do not modify */

                if((v_ConditionFaultFlag_au8[e_ZERO] == TRUE) || (v_SensrTestFlag == TRUE))
                /* VCAST Jenkins requirement - do not modify */
                /* VCAST Jenkins requirement - do not modify */
                {
                (void)Rte_Call_Dem_EnableCondition1_8_SetEnableCondition(TRUE);
                }
                else
                {
                (void)Rte_Call_Dem_EnableCondition1_8_SetEnableCondition(FALSE);
                }
 /**********************************************************************************************************************
     	 * EnableCondition9
     	 * check ECU is not in Plant mode
	*********************************************************************************************************************/
  if(v_PlantMode_u8 == FALSE)
  {
    (void)Rte_Call_Dem_EnableCondition9_SetEnableCondition(TRUE);
    v_InPlantMode = FALSE;
  }
  else
  {
     (void)Rte_Call_Dem_EnableCondition9_SetEnableCondition(FALSE);
     v_InPlantMode = TRUE;
  }
 /**********************************************************************************************************************
     	 * EnableCondition10
     	 * check Proxi parameter Singal camera varient 
 *********************************************************************************************************************/
      /*Set enable condition for SVS/ Four camera variant */  
        if(v_CameraVariant_u8 != SINGLE_CAM_VARIANT)
        {
        (void)Rte_Call_Dem_EnableCondition10_SetEnableCondition(TRUE);
        }
        else
        {
        (void)Rte_Call_Dem_EnableCondition10_SetEnableCondition(FALSE);
        }
}
/* ===========================================================================
 *   Name: F_PPPAEnable_Status_Check
 *   Function: Check PPPA Feature Enable status
 *   Inputs: None
 *   Outputs: st_DTCMgrAPAEnable
 *   Side Effects: None
 *   Remarks: None
 * ========================================================================= */
static FUNC(uint8, SWC_DTCMgr_CODE) F_PPPAEnable_Status_Check(void)
{
  /* DD-ID: {C27B3201-9FB3-4e36-8E79-657024EB4D78}*/
    static uint8 st_DTCMgrAPAEnable = FALSE;
    static APARequestSts st_DTCMgrAPAReqStOld = 0;
    APARequestSts st_DTCMgrAPAReqSt;
    uint8 st_FullAutoParkProxy;

    (void)Rte_Read_RpProxiToSWC_Fullautomaticparking(&st_FullAutoParkProxy); /* Read Full Auto Park Proxy Setting */
    (void)Rte_Read_RpToSwcSafeFD02Rx_APARequestSts(&st_DTCMgrAPAReqSt);      /* Read Auto Park Request Status */

    /* Enable APA only when Proxy is Present */
    if (DTCMGR_APAPROXY_PRESENT == st_FullAutoParkProxy)
    {
        /* Toggle APA Enable status when Push button is Pressed and Released */
        if ((st_DTCMgrAPAReqStOld != st_DTCMgrAPAReqSt) && (Cx0_Not_Pressed == st_DTCMgrAPAReqSt))
        {
            if (TRUE == st_DTCMgrAPAEnable)
            {
                st_DTCMgrAPAEnable = FALSE;
            }
            else
            {
                st_DTCMgrAPAEnable = TRUE;
            }
        }
        else{/*Do Nothing*/}

        st_DTCMgrAPAReqStOld = st_DTCMgrAPAReqSt;
    }
    else
    {
        st_DTCMgrAPAEnable = FALSE;
    }

    return st_DTCMgrAPAEnable;
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
