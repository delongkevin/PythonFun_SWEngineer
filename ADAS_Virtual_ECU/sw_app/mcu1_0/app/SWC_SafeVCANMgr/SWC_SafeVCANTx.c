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
 *             File:  SWC_SafeVCANTx.c
 *           Config:  D:/git/L2H4060_Software_master/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_SafeVCANTx
 *  Generation Time:  2025-08-20 17:38:09
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_SafeVCANTx>
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
 * AUXCamsRQSts
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
 * CameraStatus_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
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
 * DisplayView2
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
 * FD14_1_AliveCntr_MCU2_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_AliveCntr_MCU2_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_AliveCntr_MPU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_ErrFaultInfo_MCU2_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Err_FaultInfo_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Err_FaultInfo_MCU2_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Err_FaultInfo_MPU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Err_FaultNum_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Err_FaultNum_MCU2_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Err_FaultNum_MCU2_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Err_FaultNum_MPU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Hook_DtErr_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Hook_Error_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Hook_PresentPtr_MCU1_0
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_Hook_Reserved_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Hook_Service_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_Hook_Type_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Hook_actTsk_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Hook_fatalErr_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_OsRegMCU_ADFSR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_AIFSR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_DFAR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_DFSR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_IFAR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_IFSR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Link
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_SPSR
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack0
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack1
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack2
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack3
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack4
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack5
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack6
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack7
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack8
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_OsRegMCU_Stack9
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_Reserved_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Reserved_MCU2_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Reserved_MCU2_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_Reserved_MPU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SDL_Fault_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FD14_1_SSM_FltData10_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData11_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData12_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData13_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData14_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData15_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData16_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData17_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData18_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData1_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData2_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData3_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData4_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData5_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData6_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData7_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData8_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_FltData9_MCU1_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_SSM_SystemStateReq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FD14_1_TimeSincePowerON
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * FD14_1_WDG_Error_ID_MCU1_0
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * FD14_ManoeuvrePhase
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
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
 * FD14_ParkingGearShiftReq
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
 * FD14_TorqueOverlaySteeringReq_SPM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * FOD_Confidence
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * HMICode
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
 * ImageDefeatRQSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LaneDetHealth_t
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
 * MoreCamsRQSts
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
 * ParkingManeuverActive
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * Reserved_for_functional_safety
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
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
 * TRSC_LED_Stat
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

#include "Rte_SWC_SafeVCANTx.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Type.h"
#include "SWC_VCANMgr.h"
#include "Enums.h"
#include <ti/osal/TimerP.h>
#include "Os.h"

# define D_READ_SIGNAL_FROMSWC_FD14(Sig, Var) (void)Rte_Read_RpFromSwcSafeFD14Tx_##Sig((Sig*)&Var)
# define D_WRITE_SIGNAL_TOCOM_FD14(Sig, Var) (void)Rte_Write_PpToComSafeFD14Tx_##Sig((Sig)Var)
# define D_WRITE_SIGNAL_TOSWC_FD14(Sig, Var) (void)Rte_Write_PpToSwcSafeFD14Tx_##Sig((Sig)Var)

# define D_READ_SIGNAL_FROMSWC_FD02(Sig, Var) (void)Rte_Read_RpFromSwcSafeFD02Tx_##Sig((Sig*)&Var)
# define D_WRITE_SIGNAL_TOCOM_FD02(Sig, Var) (void)Rte_Write_PpToComSafeFD02Tx_##Sig((Sig)Var)
# define D_WRITE_SIGNAL_TOSWC_FD02(Sig, Var) (void)Rte_Write_PpToSwcSafeFD02Tx_##Sig((Sig)Var)
# define D_WRITE_SIGNAL_TOCOM_FD02(Sig, Var) (void)Rte_Write_PpToComSafeFD02Tx_##Sig((Sig)(Var))
# define D_WRITE_SIGNAL_TOSWC_FD02(Sig, Var) (void)Rte_Write_PpToSwcSafeFD02Tx_##Sig((Sig)(Var))

// For Array
 # define D_READ_SIGNAL_FROMSWC_FD14_ARRAY(Sig, Var) (void)Rte_Read_RpFromSwcSafeFD14Tx_##Sig(Var)
 # define D_WRITE_SIGNAL_TOCOM_FD14_ARRAY(Sig, Var) (void)Rte_Write_PpToComSafeFD14Tx_##Sig(Var)
// # define D_WRITE_SIGNAL_TOCOM_FD02_ARRAY(Sig, Var) (void)Rte_Write_PpToSwcFD14Rx_##Sig(Var)

# define D_READ_SIGNAL_FROMSWC_FD02_ARRAY(Sig, Var) (void)Rte_Read_RpFromSwcSafeFD02Tx_##Sig(Var)
# define D_WRITE_SIGNAL_TOCOM_FD02_ARRAY(Sig, Var) (void)Rte_Write_PpToComSafeFD02Tx_##Sig(Var)

#define D_LINE_HEADING_OFFSET                  (0.357f)
#define D_LINE_HEADING_FACTOR                  (0.0009765625f)
#define D_LMD_SEGMENT_X_FACTOR                 (0.03f)
#define D_LMD_SEGMENT_X_OFFSET                 (-21)
#define D_LMD_SEGMENT_Y_OFFSET                 (-5)
#define D_CURVATURE_OFFSET                     (0.032f)
#define D_CURVATURE_RATE_OFFSET                (0.000122f)
#define D_CURVATURE_FACTOR                     (0.000000977f)
#define D_CURVATURE_RATE_FACTOR                (0.00000000372529f)

#define SAFEVCANTX_US2MS_CONV_FACT 1000u

typedef void (*v_funcptr_v)(void);

typedef enum e_TX_SafeVCAN_AllEventList_s
{
	E_TX_SafeVcan_FROMSWC_TOCOM_Process10_mSecSignal = 0U,
	E_TX_SafeVcan_FROMSWC_TOCOM_Process40_mSecSignal,
	E_TX_SafeVcan_FROMSWC_TOCOM_Process250_mSecSignal,
	E_TX_SafeVcan_EVENT_TX_FROMSWC_TOCOM,
	E_TX_SafeVCAN_Last_EventIndex,
}e_TX_SafeVCAN_AllEventList_t;

typedef struct s_EventDataManage
{
	e_TX_SafeVCAN_AllEventList_t EventID; 
    uint8 isTriggered_b;
    uint8  EventType_u8;
    uint32  CounterValue_u32;
    uint32 PeriodicityTypes_u32;
	v_funcptr_v FuncPtrWrite;
} EventDataManage_t;

typedef struct ME_SystemDebugData
{
	uint32 FD14_1_Hook_PresentPtr_MCU1_0;
	uint16 FD14_1_Err_FaultInfo_MCU2_0;
	uint16 FD14_1_Err_FaultInfo_MCU2_1;
	uint16 FD14_1_Err_FaultInfo_MPU1_0;
	uint16 FD14_1_Err_FaultInfo_MCU1_0;
	uint16 FD14_1_WDG_Error_ID_MCU1_0;
	uint16 FD14_1_SDL_Fault_MCU1_0;
	uint16 FD14_1_Hook_Service_MCU1_0;
	uint16 FD14_1_Hook_DtErr_MCU1_0;
	uint16 FD14_1_Hook_Reserved_MCU1_0;
	uint8 FD14_1_Hook_fatalErr_MCU1_0;
	uint8 FD14_1_Hook_actTsk_MCU1_0;
	uint8 FD14_1_Hook_Error_MCU1_0;
	uint8 FD14_1_Hook_Type_MCU1_0;
	uint8 FD14_1_SSM_FltData1_MCU1_0;
	uint8 FD14_1_SSM_FltData2_MCU1_0;
	uint8 FD14_1_SSM_FltData3_MCU1_0;
	uint8 FD14_1_SSM_FltData4_MCU1_0;
	uint8 FD14_1_SSM_FltData5_MCU1_0;
	uint8 FD14_1_SSM_FltData6_MCU1_0;
	uint8 FD14_1_SSM_FltData7_MCU1_0;
	uint8 FD14_1_SSM_FltData8_MCU1_0;
	uint8 FD14_1_SSM_FltData9_MCU1_0;
	uint8 FD14_1_SSM_FltData10_MCU1_0;
	uint8 FD14_1_SSM_FltData11_MCU1_0;
	uint8 FD14_1_SSM_FltData12_MCU1_0;
	uint8 FD14_1_SSM_FltData13_MCU1_0;
	uint8 FD14_1_SSM_FltData14_MCU1_0;
	uint8 FD14_1_SSM_FltData15_MCU1_0;
	uint8 FD14_1_SSM_FltData16_MCU1_0;
	uint8 FD14_1_SSM_FltData17_MCU1_0;
	uint8 FD14_1_SSM_FltData18_MCU1_0;
	uint8 FD14_1_Err_FaultNum_MCU2_0;
	uint8 FD14_1_Err_FaultNum_MCU2_1;
	uint8 FD14_1_Err_FaultNum_MPU1_0;
	uint8 FD14_1_Err_FaultNum_MCU1_0;
	uint8 FD14_1_Reserved_MCU2_0;
	uint8 FD14_1_Reserved_MCU2_1;
	uint8 FD14_1_Reserved_MPU1_0;
  uint8 FD14_1_Reserved_MCU1_0;
}ME_SystemDebugData_t;

#if defined( BUILD_MCU1_0 )
#define SWC_SafeVCANTx_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_SafeVCANTx_MemMap.h"
#endif
static uint8 v_Data_u8;
static uint16 v_Data_u16;

static ME_SystemDebugData_t ME_SystemDebugData_1_CanTxData;
static TbAP_FPAWarnOut_t TbAP_FPAWarnOut_Data;
static TbAP_PAStateOut_t TbAP_PAStateOut_Data;
static TbAP_RPAWarnOut_t TbAP_RPAWarnOut_Data;
static TbAP_APSMPAOut_t TbAP_APSMPAOut_Data;
static TbFA_ArbiterOutput_t TbFA_ArbiterOutput_Data;
static SvsToVCAN_t SvsToVCAN_Data;
static TbAP_DriveAssistStatOut_t TbAP_DriveAssistStatOut_Data;
static ME_OsHookDebugData_t OsHookDebugData;
static boolean v_OsHook_bool;

#if defined( BUILD_MCU1_0 )
#define SWC_SafeVCANTx_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_SafeVCANTx_MemMap.h"
#endif

static void TX_SafeVCANProcess(void);
static void f_SendSystemDebugData_v(void);
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
 * AUXCamsRQSts: Integer in interval [0...1]
 * Alert_CHF: Integer in interval [0...7]
 * Alert_CHR: Integer in interval [0...7]
 * Alert_LHF: Integer in interval [0...7]
 * Alert_LHR: Integer in interval [0...7]
 * Alert_RHF: Integer in interval [0...7]
 * Alert_RHR: Integer in interval [0...7]
 * CameraStatus_t: Integer in interval [0...4294967295]
 * Camera_Status: Integer in interval [0...15]
 * ChimeActivation_LHF: Integer in interval [0...1]
 * ChimeActivation_LHR: Integer in interval [0...1]
 * ChimeActivation_RHF: Integer in interval [0...1]
 * ChimeActivation_RHR: Integer in interval [0...1]
 * Cntr_ADAS_FD_LANES_1: Integer in interval [0...65535]
 * Cntr_ADAS_FD_LANES_2: Integer in interval [0...65535]
 * DisplayView2: Integer in interval [0...15]
 * E2E_MEP_DataIDMode: Integer in interval [0...255]
 * FD14_1_AliveCntr_MCU2_0: Integer in interval [0...255]
 * FD14_1_AliveCntr_MCU2_1: Integer in interval [0...255]
 * FD14_1_AliveCntr_MPU1_0: Integer in interval [0...255]
 * FD14_1_ErrFaultInfo_MCU2_0: Integer in interval [0...65535]
 * FD14_1_Err_FaultInfo_MCU1_0: Integer in interval [0...65535]
 * FD14_1_Err_FaultInfo_MCU2_1: Integer in interval [0...65535]
 * FD14_1_Err_FaultInfo_MPU1_0: Integer in interval [0...65535]
 * FD14_1_Err_FaultNum_MCU1_0: Integer in interval [0...255]
 * FD14_1_Err_FaultNum_MCU2_0: Integer in interval [0...255]
 * FD14_1_Err_FaultNum_MCU2_1: Integer in interval [0...255]
 * FD14_1_Err_FaultNum_MPU1_0: Integer in interval [0...255]
 * FD14_1_Hook_DtErr_MCU1_0: Integer in interval [0...65535]
 * FD14_1_Hook_Error_MCU1_0: Integer in interval [0...255]
 * FD14_1_Hook_PresentPtr_MCU1_0: Integer in interval [0...4294967295]
 * FD14_1_Hook_Reserved_MCU1_0: Integer in interval [0...65535]
 * FD14_1_Hook_Service_MCU1_0: Integer in interval [0...65535]
 * FD14_1_Hook_Type_MCU1_0: Integer in interval [0...255]
 * FD14_1_Hook_actTsk_MCU1_0: Integer in interval [0...255]
 * FD14_1_Hook_fatalErr_MCU1_0: Integer in interval [0...255]
 * FD14_1_OsRegMCU_ADFSR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_AIFSR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_DFAR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_DFSR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_IFAR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_IFSR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Link: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_SPSR: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack0: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack1: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack2: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack3: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack4: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack5: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack6: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack7: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack8: Integer in interval [0...4294967295]
 * FD14_1_OsRegMCU_Stack9: Integer in interval [0...4294967295]
 * FD14_1_Reserved_MCU1_0: Integer in interval [0...255]
 * FD14_1_Reserved_MCU2_0: Integer in interval [0...255]
 * FD14_1_Reserved_MCU2_1: Integer in interval [0...255]
 * FD14_1_Reserved_MPU1_0: Integer in interval [0...255]
 * FD14_1_SDL_Fault_MCU1_0: Integer in interval [0...65535]
 * FD14_1_SSM_FltData10_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData11_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData12_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData13_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData14_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData15_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData16_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData17_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData18_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData1_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData2_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData3_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData4_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData5_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData6_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData7_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData8_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_FltData9_MCU1_0: Integer in interval [0...255]
 * FD14_1_SSM_SystemStateReq: Integer in interval [0...255]
 * FD14_1_TimeSincePowerON: Integer in interval [0...4294967295]
 * FD14_1_WDG_Error_ID_MCU1_0: Integer in interval [0...65535]
 * FD14_Camera_Status: Integer in interval [0...15]
 * FD14_Cntr_ADAS_FD_LANES_1: Integer in interval [0...65535]
 * FD14_Cntr_ADAS_FD_LANES_2: Integer in interval [0...65535]
 * FD14_FOD_Confidence: Integer in interval [0...3]
 * FD14_Frame_Index_Lanes_1: Integer in interval [0...65535]
 * FD14_Frame_Index_Lanes_2: Integer in interval [0...65535]
 * FD14_Health_Front_Object_Detection: Integer in interval [0...3]
 * FD14_Health_Lane_Detection: Integer in interval [0...3]
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
 * FD14_ManoeuvrePhase: Integer in interval [0...1]
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
 * FD14_ParkingGearShiftReq: Integer in interval [0...7]
 * FD14_ParkingManeuverActive: Integer in interval [0...7]
 * FD14_RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * FD14_RR_PAM_Dist: Integer in interval [0...1023]
 * FD14_Reserved_for_functional_safety: Integer in interval [0...4095]
 * FD14_SPM_Lat_Ctrl_RequestSts: Integer in interval [0...3]
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
 * FD14_TorqueOverlaySteeringReq_SPM: Integer in interval [0...2047]
 * FOD_Confidence: Integer in interval [0...3]
 * FT_PAM_LedControlSts: Integer in interval [0...3]
 * Frame_Index_Lanes_1: Integer in interval [0...65535]
 * Frame_Index_Lanes_2: Integer in interval [0...65535]
 * FrontSensorSts: Integer in interval [0...3]
 * Graphic_CHF: Integer in interval [0...3]
 * Graphic_CHR: Integer in interval [0...3]
 * Graphic_LHF: Integer in interval [0...3]
 * Graphic_LHR: Integer in interval [0...3]
 * Graphic_RHF: Integer in interval [0...3]
 * Graphic_RHR: Integer in interval [0...3]
 * HMICode: Integer in interval [0...255]
 * Health_Front_Object_Detection: Integer in interval [0...3]
 * Health_Lane_Detection: Integer in interval [0...3]
 * ImageDefeatRQSts: Integer in interval [0...1]
 * LaneDetHealth_t: Integer in interval [0...4294967295]
 * LaneType_t: Integer in interval [0...4294967295]
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
 * MoreCamsRQSts: Integer in interval [0...1]
 * PAMSystemFault: Integer in interval [0...3]
 * PAM_CHIME_REP_RATESts: Integer in interval [0...15]
 * PAM_CHIME_TYPE: Integer in interval [0...15]
 * PAM_LedControlSts: Integer in interval [0...3]
 * PAM_Off_Status: Integer in interval [0...1]
 * PAM_Off_Status_2BT: Integer in interval [0...3]
 * PAM_PopUpRqst: Integer in interval [0...255]
 * PAM_Volume: Integer in interval [0...3]
 * PPPA_TurnIndicatorRqst: Integer in interval [0...3]
 * ParkingManeuverActive: Integer in interval [0...7]
 * RR_PAM_Brk_RqSts: Integer in interval [0...1]
 * RR_PAM_Dist: Integer in interval [0...1023]
 * RR_PAM_StopControlSts: Integer in interval [0...1]
 * RearSensorSts: Integer in interval [0...3]
 * Reserved_for_functional_safety: Integer in interval [0...4095]
 * Rte_DT_ME_VehOut_TRSC_t_10: Integer in interval [0...4294967295]
 * Rte_DT_ME_VehOut_TRSC_t_11: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_4: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_5: Integer in interval [0...4294967295]
 * Rte_DT_TbFA_ArbiterOutput_t_6: Integer in interval [0...4294967295]
 * SPMControlSts: Integer in interval [0...3]
 * SPMFailSts: Integer in interval [0...1]
 * SPMSystemFault: Integer in interval [0...1]
 * SPM_LedControlSts: Integer in interval [0...3]
 * SPM_Screen_Rqst: Integer in interval [0...1]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
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
 * TRSC_LED_Stat: Integer in interval [0...3]
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
 * TeAP_e_RearSnsrStatus: Integer in interval [0...4294967295]
 * TeAP_e_SPMActvStat: Integer in interval [0...4294967295]
 * TeAP_e_SPMLatCtrlReqSts: Integer in interval [0...4294967295]
 * TeAutoPark_e_AutoParkStatus: Integer in interval [0...4294967295]
 * TeAutoPark_e_ChimeReq: Integer in interval [0...4294967295]
 * TeAutoPark_e_ScanDir: Integer in interval [0...4294967295]
 * TeTRSC_e_SpdLmtReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCLedSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCPopupDispInfo: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCStrTrqActvReq: Integer in interval [0...4294967295]
 * TeTRSC_e_TRSCSts: Integer in interval [0...4294967295]
 * TeTRSC_e_TrlrHitchLightCtrl: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq: Integer in interval [0...4294967295]
 * TeTRSC_e_VehStpReq_DID: Integer in interval [0...4294967295]
 * aSigConverter_E_DisplayView2_t: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * real32_T: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * FD14_MAC_ADAS_FD_LANES_1: Array with 6 element(s) of type uint8
 * FD14_MAC_ADAS_FD_LANES_2: Array with 6 element(s) of type uint8
 * MAC_ADAS_FD_LANES_1: Array with 6 element(s) of type uint8
 * MAC_ADAS_FD_LANES_2: Array with 6 element(s) of type uint8
 *
 * Record Types:
 * =============
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
 * E2E_MEP_ProtectStateType: Record with elements
 *   Counter of type uint8
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
 * IFOD_Outputs_CVPAMFDData_t: Record with elements
 *   IeFOD_e_FODHealth of type uint32
 *   IeFOD_e_FODConfidence of type uint32
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
 * KeepAliveResponse_t: Record with elements
 *   FrameID_u32 of type uint32
 *   ResponseCode_u8 of type uint8
 * LMD_Outputs_CVPAMFDData2_t: Record with elements
 *   LMD_Outputs_ADASFDLANES1_s of type ILMD_Outputs_ADASFDLANES1_t
 *   LMD_Outputs_ADASFDLANES2_s of type ILMD_Outputs_ADASFDLANES2_t
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
 * TbFA_ArbiterOutput_t: Record with elements
 *   IeFA_b_ChimeActvLhf of type boolean
 *   IeFA_b_ChimeActvRhf of type boolean
 *   IeFA_b_ChimeActvLhr of type boolean
 *   IeFA_b_ChimeActvRhr of type boolean
 *   IeFA_e_PamChimeRepRateSts of type Rte_DT_TbFA_ArbiterOutput_t_4
 *   IeFA_e_PamChimeTyp of type Rte_DT_TbFA_ArbiterOutput_t_5
 *   IeFA_e_PamVol of type Rte_DT_TbFA_ArbiterOutput_t_6
 * WdgCheckpointStatus_t: Record with elements
 *   timeoutCntr_u16 of type uint16
 *   seid_s of type uint16
 *   wdgDataLiveCntr_u32 of type uint32
 *
 *********************************************************************************************************************/


#define SWC_SafeVCANTx_START_SEC_CODE
#include "SWC_SafeVCANTx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SafeVCANTx_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANTx_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_SafeVCANTx_CODE) RE_SafeVCANTx_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANTx_Init
 *********************************************************************************************************************/
  /* DD-ID: {76003906-EB15-4e8a-B8F5-0D9E4378D39D}*/
TX_SafeVCANProcess();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SafeVCANTx_Main
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
 *   Std_ReturnType Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(TbAP_APSMPAOut_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(TbAP_DriveAssistStatOut_t *data)
 *   Std_ReturnType Rte_Read_RpErrFltMcu2_0_Error_Fault_MCU2_0_t(Error_Fault_MCU2_0_t *data)
 *   Std_ReturnType Rte_Read_RpErrFltMcu2_1_Error_Fault_MCU2_1_t(Error_Fault_MCU2_1_t *data)
 *   Std_ReturnType Rte_Read_RpErrFltMpu1_0_Error_Fault_MPU1_0_t(Error_Fault_MPU1_0_t *data)
 *   Std_ReturnType Rte_Read_RpFPAWarnOut_TbAP_FPAWarnOut_t(TbAP_FPAWarnOut_t *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_AUXCamsRQSts(AUXCamsRQSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_CHF(Alert_CHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_CHR(Alert_CHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_LHF(Alert_LHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_LHR(Alert_LHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_RHF(Alert_RHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Alert_RHR(Alert_RHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Camera_Status(Camera_Status *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_LHF(ChimeActivation_LHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_LHR(ChimeActivation_LHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_RHF(ChimeActivation_RHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_RHR(ChimeActivation_RHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1(Cntr_ADAS_FD_LANES_1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2(Cntr_ADAS_FD_LANES_2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_DisplayView2(DisplayView2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_FOD_Confidence(FOD_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_FT_PAM_LedControlSts(FT_PAM_LedControlSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_1(Frame_Index_Lanes_1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_2(Frame_Index_Lanes_2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_FrontSensorSts(FrontSensorSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_CHF(Graphic_CHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_CHR(Graphic_CHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_LHF(Graphic_LHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_LHR(Graphic_LHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_RHF(Graphic_RHF *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Graphic_RHR(Graphic_RHR *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_HMICode(HMICode *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Health_Front_Object_Detection(Health_Front_Object_Detection *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Health_Lane_Detection(Health_Lane_Detection *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ImageDefeatRQSts(ImageDefeatRQSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Confidence(Line_1_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Curvature(Line_1_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Curvature_Rate(Line_1_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_End_Range(Line_1_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Heading(Line_1_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Offset(Line_1_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Start_Range(Line_1_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Type(Line_1_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Confidence(Line_2_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Curvature(Line_2_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Curvature_Rate(Line_2_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_End_Range(Line_2_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Heading(Line_2_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Offset(Line_2_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Start_Range(Line_2_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Type(Line_2_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Confidence(Line_3_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Curvature(Line_3_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Curvature_Rate(Line_3_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_End_Range(Line_3_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Heading(Line_3_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Offset(Line_3_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Start_Range(Line_3_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Type(Line_3_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Confidence(Line_4_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Curvature(Line_4_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Curvature_Rate(Line_4_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_End_Range(Line_4_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Heading(Line_4_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Offset(Line_4_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Start_Range(Line_4_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Type(Line_4_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1(uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2(uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_MoreCamsRQSts(MoreCamsRQSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAMSystemFault(PAMSystemFault *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_CHIME_REP_RATESts(PAM_CHIME_REP_RATESts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_CHIME_TYPE(PAM_CHIME_TYPE *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_LedControlSts(PAM_LedControlSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_Off_Status(PAM_Off_Status *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_Off_Status_2BT(PAM_Off_Status_2BT *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_PopUpRqst(PAM_PopUpRqst *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PAM_Volume(PAM_Volume *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_PPPA_TurnIndicatorRqst(PPPA_TurnIndicatorRqst *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_Brk_RqSts(RR_PAM_Brk_RqSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_Dist(RR_PAM_Dist *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_StopControlSts(RR_PAM_StopControlSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_RearSensorSts(RearSensorSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Reserved_for_functional_safety(Reserved_for_functional_safety *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_SPMControlSts(SPMControlSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_SPMFailSts(SPMFailSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_SPMSystemFault(SPMSystemFault *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_SPM_LedControlSts(SPM_LedControlSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_SPM_Screen_Rqst(SPM_Screen_Rqst *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Confidence(Segment_1_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_ID(Segment_1_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_X1(Segment_1_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_X2(Segment_1_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Y1(Segment_1_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Y2(Segment_1_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Confidence(Segment_2_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_ID(Segment_2_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_X1(Segment_2_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_X2(Segment_2_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Y1(Segment_2_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Y2(Segment_2_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Confidence(Segment_3_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_ID(Segment_3_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_X1(Segment_3_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_X2(Segment_3_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Y1(Segment_3_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Y2(Segment_3_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Confidence(Segment_4_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_ID(Segment_4_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_X1(Segment_4_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_X2(Segment_4_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Y1(Segment_4_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Y2(Segment_4_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Confidence(Segment_5_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_ID(Segment_5_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_X1(Segment_5_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_X2(Segment_5_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Y1(Segment_5_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Y2(Segment_5_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Confidence(Segment_6_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_ID(Segment_6_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_X1(Segment_6_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_X2(Segment_6_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Y1(Segment_6_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Y2(Segment_6_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Confidence(Segment_7_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_ID(Segment_7_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_X1(Segment_7_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_X2(Segment_7_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Y1(Segment_7_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Y2(Segment_7_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Confidence(Segment_8_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_ID(Segment_8_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_X1(Segment_8_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_X2(Segment_8_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Y1(Segment_8_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Y2(Segment_8_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD02Tx_TRSC_LED_Stat(TRSC_LED_Stat *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Camera_Status(FD14_Camera_Status *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(FD14_Cntr_ADAS_FD_LANES_1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(FD14_Cntr_ADAS_FD_LANES_2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_FOD_Confidence(FD14_FOD_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1(FD14_Frame_Index_Lanes_1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2(FD14_Frame_Index_Lanes_2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Health_Front_Object_Detection(FD14_Health_Front_Object_Detection *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Health_Lane_Detection(FD14_Health_Lane_Detection *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Confidence(FD14_Line_1_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature(FD14_Line_1_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate(FD14_Line_1_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_End_Range(FD14_Line_1_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Heading(FD14_Line_1_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Offset(FD14_Line_1_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Start_Range(FD14_Line_1_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Type(FD14_Line_1_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Confidence(FD14_Line_2_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature(FD14_Line_2_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate(FD14_Line_2_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_End_Range(FD14_Line_2_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Heading(FD14_Line_2_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Offset(FD14_Line_2_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Start_Range(FD14_Line_2_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Type(FD14_Line_2_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Confidence(FD14_Line_3_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature(FD14_Line_3_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate(FD14_Line_3_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_End_Range(FD14_Line_3_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Heading(FD14_Line_3_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Offset(FD14_Line_3_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Start_Range(FD14_Line_3_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Type(FD14_Line_3_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Confidence(FD14_Line_4_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature(FD14_Line_4_Curvature *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate(FD14_Line_4_Curvature_Rate *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_End_Range(FD14_Line_4_End_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Heading(FD14_Line_4_Heading *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Offset(FD14_Line_4_Offset *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Start_Range(FD14_Line_4_Start_Range *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Type(FD14_Line_4_Type *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_ManoeuvrePhase(FD14_ManoeuvrePhase *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMax(FD14_PPPA_AccelMax *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMin(FD14_PPPA_AccelMin *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMax(FD14_PPPA_DecelMax *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMin(FD14_PPPA_DecelMin *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_Interface_BSM(FD14_PPPA_Interface_BSM *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax(FD14_PPPA_JerkAccelMax *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin(FD14_PPPA_JerkAccelMin *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax(FD14_PPPA_JerkDecelMax *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin(FD14_PPPA_JerkDecelMin *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_MaxSpeed(FD14_PPPA_MaxSpeed *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_StandstillRqst(FD14_PPPA_StandstillRqst *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_TargetDistance(FD14_PPPA_TargetDistance *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_ParkingGearShiftReq(FD14_ParkingGearShiftReq *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_ParkingManeuverActive(FD14_ParkingManeuverActive *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(FD14_RR_PAM_Brk_RqSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Dist(FD14_RR_PAM_Dist *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Reserved_for_functional_safety(FD14_Reserved_for_functional_safety *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(FD14_SPM_Lat_Ctrl_RequestSts *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Confidence(FD14_Segment_1_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_ID(FD14_Segment_1_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_X1(FD14_Segment_1_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_X2(FD14_Segment_1_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y1(FD14_Segment_1_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y2(FD14_Segment_1_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Confidence(FD14_Segment_2_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_ID(FD14_Segment_2_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_X1(FD14_Segment_2_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_X2(FD14_Segment_2_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y1(FD14_Segment_2_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y2(FD14_Segment_2_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Confidence(FD14_Segment_3_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_ID(FD14_Segment_3_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_X1(FD14_Segment_3_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_X2(FD14_Segment_3_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y1(FD14_Segment_3_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y2(FD14_Segment_3_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Confidence(FD14_Segment_4_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_ID(FD14_Segment_4_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_X1(FD14_Segment_4_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_X2(FD14_Segment_4_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y1(FD14_Segment_4_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y2(FD14_Segment_4_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Confidence(FD14_Segment_5_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_ID(FD14_Segment_5_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_X1(FD14_Segment_5_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_X2(FD14_Segment_5_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y1(FD14_Segment_5_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y2(FD14_Segment_5_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Confidence(FD14_Segment_6_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_ID(FD14_Segment_6_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_X1(FD14_Segment_6_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_X2(FD14_Segment_6_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y1(FD14_Segment_6_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y2(FD14_Segment_6_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Confidence(FD14_Segment_7_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_ID(FD14_Segment_7_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_X1(FD14_Segment_7_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_X2(FD14_Segment_7_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y1(FD14_Segment_7_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y2(FD14_Segment_7_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Confidence(FD14_Segment_8_Confidence *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_ID(FD14_Segment_8_ID *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_X1(FD14_Segment_8_X1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_X2(FD14_Segment_8_X2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y1(FD14_Segment_8_Y1 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y2(FD14_Segment_8_Y2 *data)
 *   Std_ReturnType Rte_Read_RpFromSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(FD14_TorqueOverlaySteeringReq_SPM *data)
 *   Std_ReturnType Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t(KeepAliveResponse_t *data)
 *   Std_ReturnType Rte_Read_RpPAStateOut_TbAP_PAStateOut_t(TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t(TbAP_RPAWarnOut_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t(SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Read_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(TbAP_VCActuatorOut_t *data)
 *   Std_ReturnType Rte_Read_RpSvsToVCAN_SvsToVCAN_t(SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Read_RpTRSC_ME_VehOut_TRSC_t(ME_VehOut_TRSC_t *data)
 *   Std_ReturnType Rte_Read_RpTbAPDebugOut_TbAP_DebugOut(TbAP_DebugOut *data)
 *   Std_ReturnType Rte_Read_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(TbAP_SMPAInternalOut_t *data)
 *   Std_ReturnType Rte_Read_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(TbFA_ArbiterOutput_t *data)
 *   Std_ReturnType Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t(TbAP_VCActuatorOut_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *   Std_ReturnType Rte_Read_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(WdgCheckpointStatus_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0(FD14_1_AliveCntr_MCU2_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1(FD14_1_AliveCntr_MCU2_1 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0(FD14_1_AliveCntr_MPU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0(FD14_1_ErrFaultInfo_MCU2_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0(FD14_1_Err_FaultInfo_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1(FD14_1_Err_FaultInfo_MCU2_1 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0(FD14_1_Err_FaultInfo_MPU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0(FD14_1_Err_FaultNum_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0(FD14_1_Err_FaultNum_MCU2_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1(FD14_1_Err_FaultNum_MCU2_1 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0(FD14_1_Err_FaultNum_MPU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0(FD14_1_Hook_DtErr_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0(FD14_1_Hook_Error_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0(FD14_1_Hook_PresentPtr_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0(FD14_1_Hook_Reserved_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0(FD14_1_Hook_Service_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0(FD14_1_Hook_Type_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0(FD14_1_Hook_actTsk_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0(FD14_1_Hook_fatalErr_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR(FD14_1_OsRegMCU_ADFSR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR(FD14_1_OsRegMCU_AIFSR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR(FD14_1_OsRegMCU_DFAR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR(FD14_1_OsRegMCU_DFSR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR(FD14_1_OsRegMCU_IFAR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR(FD14_1_OsRegMCU_IFSR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link(FD14_1_OsRegMCU_Link data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR(FD14_1_OsRegMCU_SPSR data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0(FD14_1_OsRegMCU_Stack0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1(FD14_1_OsRegMCU_Stack1 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2(FD14_1_OsRegMCU_Stack2 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3(FD14_1_OsRegMCU_Stack3 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4(FD14_1_OsRegMCU_Stack4 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5(FD14_1_OsRegMCU_Stack5 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6(FD14_1_OsRegMCU_Stack6 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7(FD14_1_OsRegMCU_Stack7 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8(FD14_1_OsRegMCU_Stack8 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9(FD14_1_OsRegMCU_Stack9 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0(FD14_1_Reserved_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0(FD14_1_Reserved_MCU2_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1(FD14_1_Reserved_MCU2_1 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0(FD14_1_Reserved_MPU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0(FD14_1_SDL_Fault_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0(FD14_1_SSM_FltData10_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0(FD14_1_SSM_FltData11_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0(FD14_1_SSM_FltData12_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0(FD14_1_SSM_FltData13_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0(FD14_1_SSM_FltData14_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0(FD14_1_SSM_FltData15_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0(FD14_1_SSM_FltData16_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0(FD14_1_SSM_FltData17_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0(FD14_1_SSM_FltData18_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0(FD14_1_SSM_FltData1_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0(FD14_1_SSM_FltData2_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0(FD14_1_SSM_FltData3_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0(FD14_1_SSM_FltData4_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0(FD14_1_SSM_FltData5_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0(FD14_1_SSM_FltData6_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0(FD14_1_SSM_FltData7_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0(FD14_1_SSM_FltData8_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0(FD14_1_SSM_FltData9_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq(FD14_1_SSM_SystemStateReq data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON(FD14_1_TimeSincePowerON data)
 *   Std_ReturnType Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0(FD14_1_WDG_Error_ID_MCU1_0 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_AUXCamsRQSts(AUXCamsRQSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_CHF(Alert_CHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_CHR(Alert_CHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_LHF(Alert_LHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_LHR(Alert_LHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_RHF(Alert_RHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Alert_RHR(Alert_RHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Camera_Status(Camera_Status data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ChimeActivation_LHF(ChimeActivation_LHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ChimeActivation_LHR(ChimeActivation_LHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ChimeActivation_RHF(ChimeActivation_RHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ChimeActivation_RHR(ChimeActivation_RHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1(Cntr_ADAS_FD_LANES_1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2(Cntr_ADAS_FD_LANES_2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_DisplayView2(DisplayView2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_FOD_Confidence(FOD_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_FT_PAM_LedControlSts(FT_PAM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Frame_Index_Lanes_1(Frame_Index_Lanes_1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Frame_Index_Lanes_2(Frame_Index_Lanes_2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_FrontSensorSts(FrontSensorSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_CHF(Graphic_CHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_CHR(Graphic_CHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_LHF(Graphic_LHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_LHR(Graphic_LHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_RHF(Graphic_RHF data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Graphic_RHR(Graphic_RHR data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_HMICode(HMICode data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Health_Front_Object_Detection(Health_Front_Object_Detection data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Health_Lane_Detection(Health_Lane_Detection data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ImageDefeatRQSts(ImageDefeatRQSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Confidence(Line_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Curvature(Line_1_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Curvature_Rate(Line_1_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_End_Range(Line_1_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Heading(Line_1_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Offset(Line_1_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Start_Range(Line_1_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_1_Type(Line_1_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Confidence(Line_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Curvature(Line_2_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Curvature_Rate(Line_2_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_End_Range(Line_2_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Heading(Line_2_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Offset(Line_2_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Start_Range(Line_2_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_2_Type(Line_2_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Confidence(Line_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Curvature(Line_3_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Curvature_Rate(Line_3_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_End_Range(Line_3_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Heading(Line_3_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Offset(Line_3_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Start_Range(Line_3_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_3_Type(Line_3_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Confidence(Line_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Curvature(Line_4_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Curvature_Rate(Line_4_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_End_Range(Line_4_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Heading(Line_4_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Offset(Line_4_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Start_Range(Line_4_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Line_4_Type(Line_4_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1(const uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2(const uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_MoreCamsRQSts(MoreCamsRQSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAMSystemFault(PAMSystemFault data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts(PAM_CHIME_REP_RATESts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_CHIME_TYPE(PAM_CHIME_TYPE data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_LedControlSts(PAM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_Off_Status(PAM_Off_Status data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_Off_Status_2BT(PAM_Off_Status_2BT data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_PopUpRqst(PAM_PopUpRqst data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PAM_Volume(PAM_Volume data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst(PPPA_TurnIndicatorRqst data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts(RR_PAM_Brk_RqSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_RR_PAM_Dist(RR_PAM_Dist data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_RR_PAM_StopControlSts(RR_PAM_StopControlSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_RearSensorSts(RearSensorSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Reserved_for_functional_safety(Reserved_for_functional_safety data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_SPMControlSts(SPMControlSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_SPMFailSts(SPMFailSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_SPMSystemFault(SPMSystemFault data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_SPM_LedControlSts(SPM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_SPM_Screen_Rqst(SPM_Screen_Rqst data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_Confidence(Segment_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_ID(Segment_1_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_X1(Segment_1_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_X2(Segment_1_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_Y1(Segment_1_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_1_Y2(Segment_1_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_Confidence(Segment_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_ID(Segment_2_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_X1(Segment_2_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_X2(Segment_2_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_Y1(Segment_2_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_2_Y2(Segment_2_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_Confidence(Segment_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_ID(Segment_3_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_X1(Segment_3_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_X2(Segment_3_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_Y1(Segment_3_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_3_Y2(Segment_3_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_Confidence(Segment_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_ID(Segment_4_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_X1(Segment_4_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_X2(Segment_4_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_Y1(Segment_4_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_4_Y2(Segment_4_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_Confidence(Segment_5_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_ID(Segment_5_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_X1(Segment_5_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_X2(Segment_5_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_Y1(Segment_5_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_5_Y2(Segment_5_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_Confidence(Segment_6_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_ID(Segment_6_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_X1(Segment_6_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_X2(Segment_6_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_Y1(Segment_6_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_6_Y2(Segment_6_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_Confidence(Segment_7_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_ID(Segment_7_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_X1(Segment_7_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_X2(Segment_7_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_Y1(Segment_7_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_7_Y2(Segment_7_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_Confidence(Segment_8_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_ID(Segment_8_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_X1(Segment_8_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_X2(Segment_8_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_Y1(Segment_8_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_Segment_8_Y2(Segment_8_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD02Tx_TRSC_LED_Stat(TRSC_LED_Stat data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Camera_Status(FD14_Camera_Status data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(FD14_Cntr_ADAS_FD_LANES_1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(FD14_Cntr_ADAS_FD_LANES_2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_FOD_Confidence(FD14_FOD_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1(FD14_Frame_Index_Lanes_1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2(FD14_Frame_Index_Lanes_2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection(FD14_Health_Front_Object_Detection data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Health_Lane_Detection(FD14_Health_Lane_Detection data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Confidence(FD14_Line_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Curvature(FD14_Line_1_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate(FD14_Line_1_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_End_Range(FD14_Line_1_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Heading(FD14_Line_1_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Offset(FD14_Line_1_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Start_Range(FD14_Line_1_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Type(FD14_Line_1_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Confidence(FD14_Line_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Curvature(FD14_Line_2_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate(FD14_Line_2_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_End_Range(FD14_Line_2_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Heading(FD14_Line_2_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Offset(FD14_Line_2_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Start_Range(FD14_Line_2_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Type(FD14_Line_2_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Confidence(FD14_Line_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Curvature(FD14_Line_3_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate(FD14_Line_3_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_End_Range(FD14_Line_3_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Heading(FD14_Line_3_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Offset(FD14_Line_3_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Start_Range(FD14_Line_3_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Type(FD14_Line_3_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Confidence(FD14_Line_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Curvature(FD14_Line_4_Curvature data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate(FD14_Line_4_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_End_Range(FD14_Line_4_End_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Heading(FD14_Line_4_Heading data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Offset(FD14_Line_4_Offset data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Start_Range(FD14_Line_4_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Type(FD14_Line_4_Type data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(const uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(const uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_ManoeuvrePhase(FD14_ManoeuvrePhase data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_AccelMax(FD14_PPPA_AccelMax data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_AccelMin(FD14_PPPA_AccelMin data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_DecelMax(FD14_PPPA_DecelMax data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_DecelMin(FD14_PPPA_DecelMin data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM(FD14_PPPA_Interface_BSM data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax(FD14_PPPA_JerkAccelMax data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin(FD14_PPPA_JerkAccelMin data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax(FD14_PPPA_JerkDecelMax data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin(FD14_PPPA_JerkDecelMin data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed(FD14_PPPA_MaxSpeed data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst(FD14_PPPA_StandstillRqst data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance(FD14_PPPA_TargetDistance data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq(FD14_ParkingGearShiftReq data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_ParkingManeuverActive(FD14_ParkingManeuverActive data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(FD14_RR_PAM_Brk_RqSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_RR_PAM_Dist(FD14_RR_PAM_Dist data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety(FD14_Reserved_for_functional_safety data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(FD14_SPM_Lat_Ctrl_RequestSts data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Confidence(FD14_Segment_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_ID(FD14_Segment_1_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_X1(FD14_Segment_1_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_X2(FD14_Segment_1_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Y1(FD14_Segment_1_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Y2(FD14_Segment_1_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Confidence(FD14_Segment_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_ID(FD14_Segment_2_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_X1(FD14_Segment_2_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_X2(FD14_Segment_2_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Y1(FD14_Segment_2_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Y2(FD14_Segment_2_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Confidence(FD14_Segment_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_ID(FD14_Segment_3_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_X1(FD14_Segment_3_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_X2(FD14_Segment_3_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Y1(FD14_Segment_3_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Y2(FD14_Segment_3_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Confidence(FD14_Segment_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_ID(FD14_Segment_4_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_X1(FD14_Segment_4_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_X2(FD14_Segment_4_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Y1(FD14_Segment_4_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Y2(FD14_Segment_4_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Confidence(FD14_Segment_5_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_ID(FD14_Segment_5_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_X1(FD14_Segment_5_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_X2(FD14_Segment_5_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Y1(FD14_Segment_5_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Y2(FD14_Segment_5_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Confidence(FD14_Segment_6_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_ID(FD14_Segment_6_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_X1(FD14_Segment_6_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_X2(FD14_Segment_6_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Y1(FD14_Segment_6_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Y2(FD14_Segment_6_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Confidence(FD14_Segment_7_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_ID(FD14_Segment_7_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_X1(FD14_Segment_7_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_X2(FD14_Segment_7_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Y1(FD14_Segment_7_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Y2(FD14_Segment_7_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Confidence(FD14_Segment_8_Confidence data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_ID(FD14_Segment_8_ID data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_X1(FD14_Segment_8_X1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_X2(FD14_Segment_8_X2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Y1(FD14_Segment_8_Y1 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Y2(FD14_Segment_8_Y2 data)
 *   Std_ReturnType Rte_Write_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(FD14_TorqueOverlaySteeringReq_SPM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_AUXCamsRQSts(AUXCamsRQSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_CHF(Alert_CHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_CHR(Alert_CHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_LHF(Alert_LHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_LHR(Alert_LHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_RHF(Alert_RHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Alert_RHR(Alert_RHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Camera_Status(Camera_Status data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_LHF(ChimeActivation_LHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_LHR(ChimeActivation_LHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_RHF(ChimeActivation_RHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_RHR(ChimeActivation_RHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1(Cntr_ADAS_FD_LANES_1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2(Cntr_ADAS_FD_LANES_2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_DisplayView2(DisplayView2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_FOD_Confidence(FOD_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_FT_PAM_LedControlSts(FT_PAM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Frame_Index_Lanes_1(Frame_Index_Lanes_1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Frame_Index_Lanes_2(Frame_Index_Lanes_2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_FrontSensorSts(FrontSensorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_CHF(Graphic_CHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_CHR(Graphic_CHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_LHF(Graphic_LHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_LHR(Graphic_LHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_RHF(Graphic_RHF data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Graphic_RHR(Graphic_RHR data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_HMICode(HMICode data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Health_Front_Object_Detection(Health_Front_Object_Detection data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Health_Lane_Detection(Health_Lane_Detection data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ImageDefeatRQSts(ImageDefeatRQSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Confidence(Line_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Curvature(Line_1_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Curvature_Rate(Line_1_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_End_Range(Line_1_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Heading(Line_1_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Offset(Line_1_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Start_Range(Line_1_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_1_Type(Line_1_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Confidence(Line_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Curvature(Line_2_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Curvature_Rate(Line_2_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_End_Range(Line_2_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Heading(Line_2_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Offset(Line_2_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Start_Range(Line_2_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_2_Type(Line_2_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Confidence(Line_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Curvature(Line_3_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Curvature_Rate(Line_3_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_End_Range(Line_3_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Heading(Line_3_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Offset(Line_3_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Start_Range(Line_3_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_3_Type(Line_3_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Confidence(Line_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Curvature(Line_4_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Curvature_Rate(Line_4_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_End_Range(Line_4_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Heading(Line_4_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Offset(Line_4_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Start_Range(Line_4_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Line_4_Type(Line_4_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1(const uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2(const uint8 *data)
 *     Argument data: uint8* is of type MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_MoreCamsRQSts(MoreCamsRQSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAMSystemFault(PAMSystemFault data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts(PAM_CHIME_REP_RATESts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE(PAM_CHIME_TYPE data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_LedControlSts(PAM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_Off_Status(PAM_Off_Status data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_Off_Status_2BT(PAM_Off_Status_2BT data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_PopUpRqst(PAM_PopUpRqst data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PAM_Volume(PAM_Volume data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_PPPA_TurnIndicatorRqst(PPPA_TurnIndicatorRqst data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts(RR_PAM_Brk_RqSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_Dist(RR_PAM_Dist data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts(RR_PAM_StopControlSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_RearSensorSts(RearSensorSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Reserved_for_functional_safety(Reserved_for_functional_safety data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_SPMControlSts(SPMControlSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_SPMFailSts(SPMFailSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_SPMSystemFault(SPMSystemFault data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_SPM_LedControlSts(SPM_LedControlSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_SPM_Screen_Rqst(SPM_Screen_Rqst data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Confidence(Segment_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_ID(Segment_1_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_X1(Segment_1_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_X2(Segment_1_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Y1(Segment_1_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Y2(Segment_1_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Confidence(Segment_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_ID(Segment_2_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_X1(Segment_2_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_X2(Segment_2_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Y1(Segment_2_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Y2(Segment_2_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Confidence(Segment_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_ID(Segment_3_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_X1(Segment_3_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_X2(Segment_3_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Y1(Segment_3_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Y2(Segment_3_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Confidence(Segment_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_ID(Segment_4_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_X1(Segment_4_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_X2(Segment_4_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Y1(Segment_4_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Y2(Segment_4_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Confidence(Segment_5_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_ID(Segment_5_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_X1(Segment_5_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_X2(Segment_5_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Y1(Segment_5_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Y2(Segment_5_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Confidence(Segment_6_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_ID(Segment_6_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_X1(Segment_6_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_X2(Segment_6_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Y1(Segment_6_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Y2(Segment_6_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Confidence(Segment_7_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_ID(Segment_7_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_X1(Segment_7_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_X2(Segment_7_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Y1(Segment_7_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Y2(Segment_7_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Confidence(Segment_8_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_ID(Segment_8_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_X1(Segment_8_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_X2(Segment_8_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Y1(Segment_8_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Y2(Segment_8_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD02Tx_TRSC_LED_Stat(TRSC_LED_Stat data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Camera_Status(FD14_Camera_Status data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(FD14_Cntr_ADAS_FD_LANES_1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(FD14_Cntr_ADAS_FD_LANES_2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_FOD_Confidence(FD14_FOD_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1(FD14_Frame_Index_Lanes_1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2(FD14_Frame_Index_Lanes_2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Health_Front_Object_Detection(FD14_Health_Front_Object_Detection data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Health_Lane_Detection(FD14_Health_Lane_Detection data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Confidence(FD14_Line_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature(FD14_Line_1_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate(FD14_Line_1_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_End_Range(FD14_Line_1_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Heading(FD14_Line_1_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Offset(FD14_Line_1_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Start_Range(FD14_Line_1_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Type(FD14_Line_1_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Confidence(FD14_Line_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature(FD14_Line_2_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate(FD14_Line_2_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_End_Range(FD14_Line_2_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Heading(FD14_Line_2_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Offset(FD14_Line_2_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Start_Range(FD14_Line_2_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Type(FD14_Line_2_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Confidence(FD14_Line_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature(FD14_Line_3_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate(FD14_Line_3_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_End_Range(FD14_Line_3_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Heading(FD14_Line_3_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Offset(FD14_Line_3_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Start_Range(FD14_Line_3_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Type(FD14_Line_3_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Confidence(FD14_Line_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature(FD14_Line_4_Curvature data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate(FD14_Line_4_Curvature_Rate data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_End_Range(FD14_Line_4_End_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Heading(FD14_Line_4_Heading data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Offset(FD14_Line_4_Offset data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Start_Range(FD14_Line_4_Start_Range data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Type(FD14_Line_4_Type data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(const uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_1
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(const uint8 *data)
 *     Argument data: uint8* is of type FD14_MAC_ADAS_FD_LANES_2
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase(FD14_ManoeuvrePhase data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMax(FD14_PPPA_AccelMax data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMin(FD14_PPPA_AccelMin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMax(FD14_PPPA_DecelMax data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMin(FD14_PPPA_DecelMin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_Interface_BSM(FD14_PPPA_Interface_BSM data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax(FD14_PPPA_JerkAccelMax data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin(FD14_PPPA_JerkAccelMin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax(FD14_PPPA_JerkDecelMax data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin(FD14_PPPA_JerkDecelMin data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_MaxSpeed(FD14_PPPA_MaxSpeed data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_StandstillRqst(FD14_PPPA_StandstillRqst data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_TargetDistance(FD14_PPPA_TargetDistance data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_ParkingGearShiftReq(FD14_ParkingGearShiftReq data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_ParkingManeuverActive(FD14_ParkingManeuverActive data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(FD14_RR_PAM_Brk_RqSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist(FD14_RR_PAM_Dist data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Reserved_for_functional_safety(FD14_Reserved_for_functional_safety data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(FD14_SPM_Lat_Ctrl_RequestSts data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Confidence(FD14_Segment_1_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_ID(FD14_Segment_1_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_X1(FD14_Segment_1_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_X2(FD14_Segment_1_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Y1(FD14_Segment_1_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Y2(FD14_Segment_1_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Confidence(FD14_Segment_2_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_ID(FD14_Segment_2_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_X1(FD14_Segment_2_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_X2(FD14_Segment_2_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Y1(FD14_Segment_2_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Y2(FD14_Segment_2_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Confidence(FD14_Segment_3_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_ID(FD14_Segment_3_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_X1(FD14_Segment_3_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_X2(FD14_Segment_3_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Y1(FD14_Segment_3_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Y2(FD14_Segment_3_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Confidence(FD14_Segment_4_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_ID(FD14_Segment_4_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_X1(FD14_Segment_4_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_X2(FD14_Segment_4_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Y1(FD14_Segment_4_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Y2(FD14_Segment_4_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Confidence(FD14_Segment_5_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_ID(FD14_Segment_5_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_X1(FD14_Segment_5_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_X2(FD14_Segment_5_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Y1(FD14_Segment_5_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Y2(FD14_Segment_5_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Confidence(FD14_Segment_6_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_ID(FD14_Segment_6_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_X1(FD14_Segment_6_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_X2(FD14_Segment_6_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Y1(FD14_Segment_6_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Y2(FD14_Segment_6_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Confidence(FD14_Segment_7_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_ID(FD14_Segment_7_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_X1(FD14_Segment_7_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_X2(FD14_Segment_7_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Y1(FD14_Segment_7_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Y2(FD14_Segment_7_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Confidence(FD14_Segment_8_Confidence data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_ID(FD14_Segment_8_ID data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_X1(FD14_Segment_8_X1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_X2(FD14_Segment_8_X2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Y1(FD14_Segment_8_Y1 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Y2(FD14_Segment_8_Y2 data)
 *   Std_ReturnType Rte_Write_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(FD14_TorqueOverlaySteeringReq_SPM data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpE2EServices_ME_E2E_Protect(E2E_MEP_ConfigType *ConfigPtr, E2E_MEP_ProtectStateType *StatePtr, uint8 *DataPtr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG, RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG, RTE_E_IF_E2EServices_ME_E2E_E_INTERR, RTE_E_IF_E2EServices_ME_E2E_E_INTERR, RTE_E_IF_E2EServices_ME_E2E_E_INTERR, RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE, RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE, RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANTx_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_SafeVCANTx_CODE) RE_SafeVCANTx_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SafeVCANTx_Main
 *********************************************************************************************************************/
  /* DD-ID: {8ADCFE58-7571-434a-AFC0-B633FAD6AC82}*/
  f_SendSystemDebugData_v();
  TX_SafeVCANProcess();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void f_SendSystemDebugData_v(void)
{
  /* DD-ID: {DF87E49F-6404-41a1-AB71-00D76CD655C8}*/
  SSM_SystemState SSMSystemState = {0};
  WdgCheckpointStatus_t v_WdgCheckpointStatus_MCU2_0 = {0};
  WdgCheckpointStatus_t v_WdgCheckpointStatus_MCU2_1 = {0};
  KeepAliveResponse_t v_KeepAliveResponse_MPU1_0 = {0u};
  uint32 tiEcuPowerOn;  

  tiEcuPowerOn = (uint32)(TimerP_getTimeInUsecs()/((uint64)SAFEVCANTX_US2MS_CONV_FACT)); /* convert system time to 0.001 Sec resolution */

  (void)Rte_Read_R_SystemState_SystemState(&SSMSystemState); /* Read SSM Master State */
  (void)Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(&v_WdgCheckpointStatus_MCU2_0);
  (void)Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(&v_WdgCheckpointStatus_MCU2_1);
  (void)Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t(&v_KeepAliveResponse_MPU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0((uint8)(v_WdgCheckpointStatus_MCU2_0.wdgDataLiveCntr_u32));
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1((uint8)(v_WdgCheckpointStatus_MCU2_1.wdgDataLiveCntr_u32));
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0((uint8)(v_KeepAliveResponse_MPU1_0.FrameID_u32));
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq((uint8)SSMSystemState.SystemState);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON(tiEcuPowerOn);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultInfo_MCU2_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_PresentPtr_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Service_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_DtErr_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_fatalErr_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_actTsk_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultInfo_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultInfo_MCU2_1);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultInfo_MPU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultNum_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultNum_MCU2_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultNum_MCU2_1);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultNum_MPU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Error_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Type_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Reserved_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0(ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MCU2_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1(ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MCU2_1);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MPU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SDL_Fault_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData10_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData11_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData12_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData13_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData14_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData15_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData16_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData17_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData18_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData1_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData2_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData3_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData4_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData5_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData6_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData7_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData8_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData9_MCU1_0);
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_WDG_Error_ID_MCU1_0);
   /* This Reserved_MCU1_0 is using to check  NVM WriteAll Sucess or not?If NVM WriteAll fails it send value as 1 */
  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0(ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MCU1_0);

  if(TRUE == v_OsHook_bool)
  {
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_ADFSR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_AIFSR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_DFAR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_DFSR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_IFAR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_IFSR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Link);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_SPSR);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[0]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[1]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[2]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[3]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[4]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[5]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[6]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[7]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[8]);
	  (void)Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9(OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[9]);
  }
}

void f_Send_Dbg_MCU1_0_Faultnum_CanTx(uint8 FaultNum)
{
  /* DD-ID: {A6A0BBB4-C434-4df2-8540-1256C42A38FA}*/
  /* update the reported value to the Global CAN Tx Debug structure*/
  ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultNum_MCU1_0=FaultNum;

}

void f_Send_Dbg_MCU1_0_FaultInfo_CanTx(uint16 FaultInfo)
{
  /* DD-ID: {C433F57E-49E6-4766-8FE4-1DFE38CAB14E}*/

 /* update the reported value to the Global CAN Tx Debug structure*/
  ME_SystemDebugData_1_CanTxData.FD14_1_Err_FaultInfo_MCU1_0=FaultInfo;

}

void f_Send_Dbg_Os_hook_CanTx(ME_OsHookDebugData_t s_ME_OsHookDebugData_RPRAM_as)
{
  /* DD-ID: {0B775B34-BD7F-48f3-87A1-451323795347}*/
    /* update the reported data to the Global CAN Tx Debug structure*/
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Service_MCU1_0         = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Service_MCU1_0 ;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_DtErr_MCU1_0           = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_DtErr_MCU1_0;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_fatalErr_MCU1_0        = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_fatalErr_MCU1_0;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_actTsk_MCU1_0          = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_actTsk_MCU1_0;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Error_MCU1_0           = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Error_MCU1_0;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_Type_MCU1_0            = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_Type_MCU1_0;
    ME_SystemDebugData_1_CanTxData.FD14_1_Hook_PresentPtr_MCU1_0      = s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0;
    /* Publish Exception debug Data */
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_ADFSR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_ADFSR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_AIFSR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_AIFSR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_DFAR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_DFAR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_DFSR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_DFSR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_IFAR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_IFAR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_IFSR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_IFSR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Link = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Link;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_SPSR = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_SPSR;
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[0] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[0];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[1] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[1];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[2] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[2];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[3] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[3];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[4] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[4];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[5] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[5];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[6] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[6];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[7] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[7];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[8] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[8];
    OsHookDebugData.OsExceptionHandler.FD14_1_OsRegMCU_Stack[9] = s_ME_OsHookDebugData_RPRAM_as.OsExceptionHandler.FD14_1_OsRegMCU_Stack[9];
    v_OsHook_bool = TRUE;
	 ME_SystemDebugData_1_CanTxData.FD14_1_Reserved_MCU1_0 			  = s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Fail_Status;
}

void f_Send_Dbg_WdgErr_CanTx(uint16 WdgError)
{
  /* DD-ID: {00EF36D9-598B-4d74-BB8B-43A99BF61D6A}*/
  /* Update the reported value to the Global CAN Tx Debug structure*/
  ME_SystemDebugData_1_CanTxData.FD14_1_WDG_Error_ID_MCU1_0=WdgError;
}

void f_Send_Dbg_SDLFault_CanTx(uint16 SDLFault)
{
  /* DD-ID: {839AF1B2-05DF-4f6c-B241-B86C97180CE8}*/

   /* Update the reported value to the Global CAN Tx Debug structure*/
  ME_SystemDebugData_1_CanTxData.FD14_1_SDL_Fault_MCU1_0=SDLFault;

}

void f_Send_Dbg_SSMFault_CanTx(uint8*  SSMFault)
{
  /* DD-ID: {20EF77EE-EDBE-49ef-A54E-71AF4EC8D9CE}*/
  /* Update the reported value to the Global CAN Tx Debug structure*/
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData1_MCU1_0=SSMFault[e_ZERO];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData2_MCU1_0=SSMFault[e_ONE];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData3_MCU1_0=SSMFault[e_TWO];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData4_MCU1_0=SSMFault[e_THREE];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData5_MCU1_0=SSMFault[e_FOUR];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData6_MCU1_0=SSMFault[e_FIVE];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData7_MCU1_0=SSMFault[e_SIX];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData8_MCU1_0=SSMFault[e_SEVEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData9_MCU1_0=SSMFault[e_EIGHT];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData10_MCU1_0=SSMFault[e_NINE];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData11_MCU1_0=SSMFault[e_TEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData12_MCU1_0=SSMFault[e_ELEVEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData13_MCU1_0=SSMFault[e_TWELVE];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData14_MCU1_0=SSMFault[e_THIRTEEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData15_MCU1_0=SSMFault[e_FOURTEEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData16_MCU1_0=SSMFault[e_FIFTEEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData17_MCU1_0=SSMFault[e_SIXTEEN];
  ME_SystemDebugData_1_CanTxData.FD14_1_SSM_FltData18_MCU1_0=SSMFault[e_SEVENTEEN];
}

static void TX_SafeVcan_FROMSWC_TOCOM_Process10_mSecSignal(void)
{
  /* DD-ID: {AFC92040-0061-406c-9C20-D6E0D3C17006}*/
   static TbAP_VCActuatorOut_t TbAP_VCActuatorOut_Data;
  (void)Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(&TbAP_DriveAssistStatOut_Data);
  (void)Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t(&TbAP_RPAWarnOut_Data);
  (void)Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(&TbAP_PAStateOut_Data);
  (void)Rte_Read_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(&TbAP_VCActuatorOut_Data);
  (void)Rte_Read_RpFPAWarnOut_TbAP_FPAWarnOut_t(&TbAP_FPAWarnOut_Data);
  (void)Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t(&SvsToVCAN_Data);
  (void)Rte_Read_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(&TbFA_ArbiterOutput_Data);
  (void)Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t(&TbAP_APSMPAOut_Data);
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_ManoeuvrePhase,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_ManoeuvrePhase,TbAP_DriveAssistStatOut_Data.IeAP_b_VehMnvrDirSPM); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ManoeuvrePhase,TbAP_DriveAssistStatOut_Data.IeAP_b_VehMnvrDirSPM); // ASIL: FD14 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_ParkingGearShiftReq,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_ParkingGearShiftReq,TbAP_DriveAssistStatOut_Data.IeAP_e_GearShiftReq); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_ParkingGearShiftReq,TbAP_DriveAssistStatOut_Data.IeAP_e_GearShiftReq); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_AccelMax,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_AccelMax = (FD14_PPPA_AccelMax -  D_OFST_FD14_PPPA_AccelMax)/ D_FCT_FD14_PPPA_AccelMax;
   v_Data_u8 = (uint8)(TbAP_VCActuatorOut_Data.IeAP_a_AcclMax/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_AccelMax,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_AccelMax,v_Data_u8);/*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_AccelMin,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_AccelMin = (FD14_PPPA_AccelMin -  D_OFST_FD14_PPPA_AccelMin)/ D_FCT_FD14_PPPA_AccelMin;
   v_Data_u8 =(uint8) (TbAP_VCActuatorOut_Data.IeAP_a_AcclMin/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_AccelMin,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_AccelMin,v_Data_u8);/*PRQA S 3119*/ // ASIL: FD14 Not Common Write  
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_DecelMax,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_DecelMax = (FD14_PPPA_DecelMax -  D_OFST_FD14_PPPA_DecelMax)/ D_FCT_FD14_PPPA_DecelMax;
   v_Data_u8 =(uint8) (TbAP_VCActuatorOut_Data.IeAP_a_DecelMax/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_DecelMax,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_DecelMax,v_Data_u8);/*PRQA S 3119*/ // ASIL: FD14 Not Common Write  
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_DecelMin,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_DecelMin = (FD14_PPPA_DecelMin -  D_OFST_FD14_PPPA_DecelMin)/ D_FCT_FD14_PPPA_DecelMin;
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_Interface_BSM,v_Data_u8);
   v_Data_u8 =(uint8) (TbAP_VCActuatorOut_Data.IeAP_a_DecelMin/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_DecelMin,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_DecelMin,v_Data_u8);  /*PRQA S 3119*/ // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_Interface_BSM,TbAP_DriveAssistStatOut_Data.IeAP_e_InterfaceBSM); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_Interface_BSM,TbAP_DriveAssistStatOut_Data.IeAP_e_InterfaceBSM); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_JerkAccelMax,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_JerkAccelMax = (FD14_PPPA_JerkAccelMax -  D_OFST_FD14_PPPA_JerkAccelMax)/ D_FCT_FD14_PPPA_JerkAccelMax;
   v_Data_u8 = (uint8)(TbAP_VCActuatorOut_Data.IeAP_da_JerkAcclMax/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_JerkAccelMax,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_JerkAccelMax,v_Data_u8); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_JerkAccelMin,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_JerkAccelMin = (FD14_PPPA_JerkAccelMin -  D_OFST_FD14_PPPA_JerkAccelMin)/ D_FCT_FD14_PPPA_JerkAccelMin;
   v_Data_u8 =(uint8) (TbAP_VCActuatorOut_Data.IeAP_da_JerkAcclMin/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_JerkAccelMin,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_JerkAccelMin,v_Data_u8);/*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_JerkDecelMax,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_JerkDecelMax = (FD14_PPPA_JerkDecelMax -  D_OFST_FD14_PPPA_JerkDecelMax)/ D_FCT_FD14_PPPA_JerkDecelMax;
   v_Data_u8 = (uint8)(TbAP_VCActuatorOut_Data.IeAP_a_JerkDecelMax/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_JerkDecelMax,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_JerkDecelMax,v_Data_u8); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_JerkDecelMin,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_JerkDecelMin = (FD14_PPPA_JerkDecelMin -  D_OFST_FD14_PPPA_JerkDecelMin)/ D_FCT_FD14_PPPA_JerkDecelMin;
   v_Data_u8 = (uint8)(TbAP_VCActuatorOut_Data.IeAP_a_JerkDecelMin/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_JerkDecelMin,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_JerkDecelMin,v_Data_u8); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_MaxSpeed,v_Data_u8);
   // VT: FACT+OFFST :  FD14_PPPA_MaxSpeed = (FD14_PPPA_MaxSpeed -  D_OFST_FD14_PPPA_MaxSpeed)/ D_FCT_FD14_PPPA_MaxSpeed;
   v_Data_u8 = (uint8)(TbAP_VCActuatorOut_Data.IeAP_kph_TrgtVehSpd/D_SPEED_CONV_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_MaxSpeed,v_Data_u8); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_MaxSpeed,v_Data_u8); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
  // D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_StandstillRqst,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_StandstillRqst,TbAP_VCActuatorOut_Data.IeAP_b_StandstillReq); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_StandstillRqst,TbAP_VCActuatorOut_Data.IeAP_b_StandstillReq);/*PRQA S 3119*/  // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_PPPA_TargetDistance,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_PPPA_TargetDistance,TbAP_VCActuatorOut_Data.IeAP_cm_TrgtDist); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_PPPA_TargetDistance,TbAP_VCActuatorOut_Data.IeAP_cm_TrgtDist); /*PRQA S 3119*/ // ASIL: FD14 Not Common Write 
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_RR_PAM_Brk_RqSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_RR_PAM_Brk_RqSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearBrkReq); // ASIL: FD14 Common WRITE
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RR_PAM_Brk_RqSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearBrkReq); // ASIL: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(RR_PAM_Brk_RqSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearBrkReq); // ASIL: FD02 Common WRITE
   D_WRITE_SIGNAL_TOSWC_FD02(RR_PAM_Brk_RqSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearBrkReq);
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_RR_PAM_Dist,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_RR_PAM_Dist,TbAP_RPAWarnOut_Data.IeAP_cm_RearDisttoNearObst); // ASIL: FD14 Common WRITE
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_RR_PAM_Dist,TbAP_RPAWarnOut_Data.IeAP_cm_RearDisttoNearObst); // ASIL: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(RR_PAM_Dist,TbAP_RPAWarnOut_Data.IeAP_cm_RearDisttoNearObst); // ASIL: FD02 Common WRITE
   D_WRITE_SIGNAL_TOSWC_FD02(RR_PAM_Dist,TbAP_RPAWarnOut_Data.IeAP_cm_RearDisttoNearObst);
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_SPM_Lat_Ctrl_RequestSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_SPM_Lat_Ctrl_RequestSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMLatCtrlReqSts); // ASIL: FD14 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_SPM_Lat_Ctrl_RequestSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMLatCtrlReqSts); // ASIL: FD14 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02(PPPA_TurnIndicatorRqst,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PPPA_TurnIndicatorRqst,TbAP_VCActuatorOut_Data.IeAP_e_TurnIndicReq); // ASIL: FD2 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02(RR_PAM_StopControlSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(RR_PAM_StopControlSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearCtrlSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(RR_PAM_StopControlSts,TbAP_PAStateOut_Data.IeAP_b_PAMRearCtrlSts);
   v_Data_u16 = (uint16)((TbAP_VCActuatorOut_Data.IeAP_nm_StrwTrqReq + (uint8)e_EIGHT)/D_TRQ_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_TorqueOverlaySteeringReq_SPM,v_Data_u16); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD14(FD14_TorqueOverlaySteeringReq_SPM,v_Data_u16); // ASIL: FD2 Not Common Write
}

static void TX_SafeVcan_FROMSWC_TOCOM_Process40_mSecSignal(void)
{
  /* DD-ID: {40596EBF-C474-4ca6-A6BB-352EE9F1FBE3}*/
   LMD_Outputs_CVPAMFDData2_t LMD_Outputs_CVPAMFDData2_Data;
   IFOD_Outputs_CVPAMFDData_t FOD_Outputs_CVPAMFDData_Data;
   static uint8 v_Data_a6_au8[e_SIX];
   (void)Rte_Read_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(&LMD_Outputs_CVPAMFDData2_Data);
   (void)Rte_Read_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(&FOD_Outputs_CVPAMFDData_Data);
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Camera_Status,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Camera_Status,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_CameraStatus); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Camera_Status,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_CameraStatus); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Cntr_ADAS_FD_LANES_1,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Cntr_ADAS_FD_LANES_1,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_CntrAdasFdLanes1); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Cntr_ADAS_FD_LANES_1,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_CntrAdasFdLanes1); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Cntr_ADAS_FD_LANES_2,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Cntr_ADAS_FD_LANES_2,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_CntrAdasFdLanes2); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Cntr_ADAS_FD_LANES_2,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_CntrAdasFdLanes2); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_FOD_Confidence,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_FOD_Confidence,FOD_Outputs_CVPAMFDData_Data.IeFOD_e_FODConfidence); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(FOD_Confidence,FOD_Outputs_CVPAMFDData_Data.IeFOD_e_FODConfidence); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Frame_Index_Lanes_1,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Frame_Index_Lanes_1,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_FrameIndexLanes1); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Frame_Index_Lanes_1,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_FrameIndexLanes1); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Frame_Index_Lanes_2,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Frame_Index_Lanes_2,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_FrameIndexLanes2); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Frame_Index_Lanes_2,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_FrameIndexLanes2); // General: FD02 Common WRITE   
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Health_Front_Object_Detection,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Health_Front_Object_Detection,FOD_Outputs_CVPAMFDData_Data.IeFOD_e_FODHealth); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Health_Front_Object_Detection,FOD_Outputs_CVPAMFDData_Data.IeFOD_e_FODHealth); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Health_Lane_Detection,v_Data_u8);
   LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_LaneDetectionHealth = Lane_Unknown; // Temporary workaround, need to remove once LMD feature is enabled
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Health_Lane_Detection,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_LaneDetectionHealth); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Health_Lane_Detection,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_LaneDetectionHealth); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Confidence,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_1_Confidence = (FD14_Line_1_Confidence -  D_OFST_FD14_Line_1_Confidence)/ D_FCT_FD14_Line_1_Confidence;
   v_Data_u16 = (uint16)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Confidence/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Confidence,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Confidence,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Curvature,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_1_Curvature = (FD14_Line_1_Curvature -  D_OFST_FD14_Line_1_Curvature)/ D_FCT_FD14_Line_1_Curvature;
   v_Data_u16 =(uint16) ((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Curvature + D_CURVATURE_OFFSET)/D_CURVATURE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Curvature,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Curvature,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Curvature_Rate,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_1_Curvature_Rate = (FD14_Line_1_Curvature_Rate -  D_OFST_FD14_Line_1_Curvature_Rate)/ D_FCT_FD14_Line_1_Curvature_Rate;
   v_Data_u16 =(uint16) ((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1CurvatureRate + D_CURVATURE_RATE_OFFSET)/D_CURVATURE_RATE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Curvature_Rate,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Curvature_Rate,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_End_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_1_End_Range = (FD14_Line_1_End_Range -  D_OFST_FD14_Line_1_End_Range)/ D_FCT_FD14_Line_1_End_Range;
   v_Data_u8 =(uint8) ((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1EndRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_End_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_End_Range,v_Data_u8); // General: FD02 Common WRITE
   // VT: FACT+OFFST :  FD14_Line_1_Heading = (FD14_Line_1_Heading -  D_OFST_FD14_Line_1_Heading)/ D_FCT_FD14_Line_1_Heading;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line1Heading + D_LINE_HEADING_OFFSET)/D_LINE_HEADING_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Heading,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Heading,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Offset,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_1_Offset = (FD14_Line_1_Offset -  D_OFST_FD14_Line_1_Offset)/ D_FCT_FD14_Line_1_Offset;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1Offset + (uint8)e_FIVE)/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Offset,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Offset,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Start_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_1_Start_Range = (FD14_Line_1_Start_Range -  D_OFST_FD14_Line_1_Start_Range)/ D_FCT_FD14_Line_1_Start_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1StartRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Start_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Start_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_1_Type,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_1_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Type); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_1_Type,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_2_Confidence = (FD14_Line_2_Confidence -  D_OFST_FD14_Line_2_Confidence)/ D_FCT_FD14_Line_2_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Confidence/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Curvature,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_2_Curvature = (FD14_Line_2_Curvature -  D_OFST_FD14_Line_2_Curvature)/ D_FCT_FD14_Line_2_Curvature;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Curvature + D_CURVATURE_OFFSET)/D_CURVATURE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Curvature,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Curvature,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Curvature_Rate,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_2_Curvature_Rate = (FD14_Line_2_Curvature_Rate -  D_OFST_FD14_Line_2_Curvature_Rate)/ D_FCT_FD14_Line_2_Curvature_Rate;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2CurvatureRate + D_CURVATURE_RATE_OFFSET)/D_CURVATURE_RATE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Curvature_Rate,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Curvature_Rate,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_End_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_2_End_Range = (FD14_Line_2_End_Range -  D_OFST_FD14_Line_2_End_Range)/ D_FCT_FD14_Line_2_End_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2EndRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_End_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_End_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Heading,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_2_Heading = (FD14_Line_2_Heading -  D_OFST_FD14_Line_2_Heading)/ D_FCT_FD14_Line_2_Heading;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line2Heading + D_LINE_HEADING_OFFSET)/D_LINE_HEADING_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Heading,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Heading,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Offset,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_2_Offset = (FD14_Line_2_Offset -  D_OFST_FD14_Line_2_Offset)/ D_FCT_FD14_Line_2_Offset;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2Offset + (uint8)e_FIVE)/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Offset,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Offset,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Start_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_2_Start_Range = (FD14_Line_2_Start_Range -  D_OFST_FD14_Line_2_Start_Range)/ D_FCT_FD14_Line_2_Start_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2StartRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Start_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Start_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_2_Type,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_2_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Type); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_2_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Type); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_3_Confidence = (FD14_Line_3_Confidence -  D_OFST_FD14_Line_3_Confidence)/ D_FCT_FD14_Line_3_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Confidence/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Curvature,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_3_Curvature = (FD14_Line_3_Curvature -  D_OFST_FD14_Line_3_Curvature)/ D_FCT_FD14_Line_3_Curvature;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Curvature + D_CURVATURE_OFFSET)/D_CURVATURE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Curvature,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Curvature,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Curvature_Rate,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_3_Curvature_Rate = (FD14_Line_3_Curvature_Rate -  D_OFST_FD14_Line_3_Curvature_Rate)/ D_FCT_FD14_Line_3_Curvature_Rate;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3CurvatureRate + D_CURVATURE_RATE_OFFSET)/D_CURVATURE_RATE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Curvature_Rate,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Curvature_Rate,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_End_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_3_End_Range = (FD14_Line_3_End_Range -  D_OFST_FD14_Line_3_End_Range)/ D_FCT_FD14_Line_3_End_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3EndRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_End_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_End_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Heading,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_3_Heading = (FD14_Line_3_Heading -  D_OFST_FD14_Line_3_Heading)/ D_FCT_FD14_Line_3_Heading;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line3Heading + D_LINE_HEADING_OFFSET)/D_LINE_HEADING_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Heading,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Heading,v_Data_u16); // General: FD02 Common WRITE
   D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Offset,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_3_Offset = (FD14_Line_3_Offset -  D_OFST_FD14_Line_3_Offset)/ D_FCT_FD14_Line_3_Offset;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3Offset + (uint8)e_FIVE)/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Offset,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Offset,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Start_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_3_Start_Range = (FD14_Line_3_Start_Range -  D_OFST_FD14_Line_3_Start_Range)/ D_FCT_FD14_Line_3_Start_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3StartRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Start_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Start_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_3_Type,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_3_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Type); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_3_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Type); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_4_Confidence = (FD14_Line_4_Confidence -  D_OFST_FD14_Line_4_Confidence)/ D_FCT_FD14_Line_4_Confidence;
   v_Data_u8 =(uint8) (LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Confidence/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Curvature,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_4_Curvature = (FD14_Line_4_Curvature -  D_OFST_FD14_Line_4_Curvature)/ D_FCT_FD14_Line_4_Curvature;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Curvature + D_CURVATURE_OFFSET)/D_CURVATURE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Curvature,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Curvature,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Curvature_Rate,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_4_Curvature_Rate = (FD14_Line_4_Curvature_Rate -  D_OFST_FD14_Line_4_Curvature_Rate)/ D_FCT_FD14_Line_4_Curvature_Rate;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4CurvatureRate + D_CURVATURE_RATE_OFFSET)/D_CURVATURE_RATE_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Curvature_Rate,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Curvature_Rate,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_End_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_4_End_Range = (FD14_Line_4_End_Range -  D_OFST_FD14_Line_4_End_Range)/ D_FCT_FD14_Line_4_End_Range;
   v_Data_u8 = (uint8)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4EndRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_End_Range,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_End_Range,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Heading,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_4_Heading = (FD14_Line_4_Heading -  D_OFST_FD14_Line_4_Heading)/ D_FCT_FD14_Line_4_Heading;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line4Heading + D_LINE_HEADING_OFFSET)/D_LINE_HEADING_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Heading,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Heading,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Offset,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Line_4_Offset = (FD14_Line_4_Offset -  D_OFST_FD14_Line_4_Offset)/ D_FCT_FD14_Line_4_Offset;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4Offset + (uint8)e_FIVE)/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Offset,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Offset,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Start_Range,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Line_4_Start_Range = (FD14_Line_4_Start_Range -  D_OFST_FD14_Line_4_Start_Range)/ D_FCT_FD14_Line_4_Start_Range;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4StartRange + (uint8)e_TWENTY_FIVE)/D_CAN_0_5_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Start_Range,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Start_Range,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Line_4_Type,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Line_4_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Type); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Line_4_Type,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Type); // General: FD02 Common WRITE
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_1,v_Data_a8_au8); // General: FD14 Not Common Write
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_2,v_Data_a8_au8); // General: FD14 Not Common Write
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_3,v_Data_a8_au8); // General: FD14 Not Common Write
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_4,v_Data_a8_au8); // General: FD14 Not Common Write
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_5,v_Data_a8_au8); // General: FD14 Not Common Write
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_Log_SnrMeasData_6,v_Data_a8_au8); // General: FD14 Not Common Write
   D_READ_SIGNAL_FROMSWC_FD14_ARRAY(FD14_MAC_ADAS_FD_LANES_1,v_Data_a6_au8);
   D_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_MAC_ADAS_FD_LANES_1,v_Data_a6_au8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02_ARRAY(MAC_ADAS_FD_LANES_1,v_Data_a6_au8); // General: FD02 Common WRITE
   D_READ_SIGNAL_FROMSWC_FD14_ARRAY(FD14_MAC_ADAS_FD_LANES_2,v_Data_a6_au8);
   D_WRITE_SIGNAL_TOCOM_FD14_ARRAY(FD14_MAC_ADAS_FD_LANES_2,v_Data_a6_au8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02_ARRAY(MAC_ADAS_FD_LANES_2,v_Data_a6_au8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Reserved_for_functional_safety,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Reserved_for_functional_safety,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_ReservedForFunctionalSafety1); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Reserved_for_functional_safety,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_ReservedForFunctionalSafety1); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Reserved_for_functional_safety,v_Data_u16);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Reserved_for_functional_safety,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_ReservedForFunctionalSafety2); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Reserved_for_functional_safety,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_ReservedForFunctionalSafety2); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_1_Confidence = (FD14_Segment_1_Confidence -  D_OFST_FD14_Segment_1_Confidence)/ D_FCT_FD14_Segment_1_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg1Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_1_X1 = (FD14_Segment_1_X1 -  D_OFST_FD14_Segment_1_X1)/ D_FCT_FD14_Segment_1_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_1_X2 = (FD14_Segment_1_X2 -  D_OFST_FD14_Segment_1_X2)/ D_FCT_FD14_Segment_1_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_1_Y2 = (FD14_Segment_1_Y2 -  D_OFST_FD14_Segment_1_Y2)/ D_FCT_FD14_Segment_1_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_2_Confidence = (FD14_Segment_2_Confidence -  D_OFST_FD14_Segment_2_Confidence)/ D_FCT_FD14_Segment_2_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg2Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_2_X1 = (FD14_Segment_2_X1 -  D_OFST_FD14_Segment_2_X1)/ D_FCT_FD14_Segment_2_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_2_X2 = (FD14_Segment_2_X2 -  D_OFST_FD14_Segment_2_X2)/ D_FCT_FD14_Segment_2_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_2_Y1 = (FD14_Segment_2_Y1 -  D_OFST_FD14_Segment_2_Y1)/ D_FCT_FD14_Segment_2_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_2_Y2 = (FD14_Segment_2_Y2 -  D_OFST_FD14_Segment_2_Y2)/ D_FCT_FD14_Segment_2_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_3_Confidence = (FD14_Segment_3_Confidence -  D_OFST_FD14_Segment_3_Confidence)/ D_FCT_FD14_Segment_3_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg3Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg3Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg3Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_3_X1 = (FD14_Segment_3_X1 -  D_OFST_FD14_Segment_3_X1)/ D_FCT_FD14_Segment_3_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_3_X2 = (FD14_Segment_3_X2 -  D_OFST_FD14_Segment_3_X2)/ D_FCT_FD14_Segment_3_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_3_Y2 = (FD14_Segment_3_Y2 -  D_OFST_FD14_Segment_3_Y2)/ D_FCT_FD14_Segment_3_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_4_Confidence = (FD14_Segment_4_Confidence -  D_OFST_FD14_Segment_4_Confidence)/ D_FCT_FD14_Segment_4_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg4Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_4_X1 = (FD14_Segment_4_X1 -  D_OFST_FD14_Segment_4_X1)/ D_FCT_FD14_Segment_4_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_4_Y1 = (FD14_Segment_4_Y1 -  D_OFST_FD14_Segment_4_Y1)/ D_FCT_FD14_Segment_4_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_4_Y2 = (FD14_Segment_4_Y2 -  D_OFST_FD14_Segment_4_Y2)/ D_FCT_FD14_Segment_4_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_5_Confidence = (FD14_Segment_5_Confidence -  D_OFST_FD14_Segment_5_Confidence)/ D_FCT_FD14_Segment_5_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg5Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg5Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg5Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_5_X1 = (FD14_Segment_5_X1 -  D_OFST_FD14_Segment_5_X1)/ D_FCT_FD14_Segment_5_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_5_X2 = (FD14_Segment_5_X2 -  D_OFST_FD14_Segment_5_X2)/ D_FCT_FD14_Segment_5_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_5_Y1 = (FD14_Segment_5_Y1 -  D_OFST_FD14_Segment_5_Y1)/ D_FCT_FD14_Segment_5_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_5_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_5_Y2 = (FD14_Segment_5_Y2 -  D_OFST_FD14_Segment_5_Y2)/ D_FCT_FD14_Segment_5_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_5_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_5_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_6_Confidence = (FD14_Segment_6_Confidence -  D_OFST_FD14_Segment_6_Confidence)/ D_FCT_FD14_Segment_6_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg6Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg6Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg6Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_6_X1 = (FD14_Segment_6_X1 -  D_OFST_FD14_Segment_6_X1)/ D_FCT_FD14_Segment_6_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_6_X2 = (FD14_Segment_6_X2 -  D_OFST_FD14_Segment_6_X2)/ D_FCT_FD14_Segment_6_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_6_Y1 = (FD14_Segment_6_Y1 -  D_OFST_FD14_Segment_6_Y1)/ D_FCT_FD14_Segment_6_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_6_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_6_Y2 = (FD14_Segment_6_Y2 -  D_OFST_FD14_Segment_6_Y2)/ D_FCT_FD14_Segment_6_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_6_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_6_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_7_Confidence = (FD14_Segment_7_Confidence -  D_OFST_FD14_Segment_7_Confidence)/ D_FCT_FD14_Segment_7_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg7Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg7Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg7Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_7_X1 = (FD14_Segment_7_X1 -  D_OFST_FD14_Segment_7_X1)/ D_FCT_FD14_Segment_7_X1;
   v_Data_u16 =(uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_7_X2 = (FD14_Segment_7_X2 -  D_OFST_FD14_Segment_7_X2)/ D_FCT_FD14_Segment_7_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_7_Y1 = (FD14_Segment_7_Y1 -  D_OFST_FD14_Segment_7_Y1)/ D_FCT_FD14_Segment_7_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_7_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_7_Y2 = (FD14_Segment_7_Y2 -  D_OFST_FD14_Segment_7_Y2)/ D_FCT_FD14_Segment_7_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_7_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_7_Y2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_Confidence,v_Data_u8);
   // VT: FACT+OFFST :  FD14_Segment_8_Confidence = (FD14_Segment_8_Confidence -  D_OFST_FD14_Segment_8_Confidence)/ D_FCT_FD14_Segment_8_Confidence;
   v_Data_u8 = (uint8)(LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg8Conf/D_CAN_0_1_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_Confidence,v_Data_u8); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_Confidence,v_Data_u8); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg8Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg8Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_X1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_8_X1 = (FD14_Segment_8_X1 -  D_OFST_FD14_Segment_8_X1)/ D_FCT_FD14_Segment_8_X1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8X1-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_X1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_X1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_8_X2 = (FD14_Segment_8_X2 -  D_OFST_FD14_Segment_8_X2)/ D_FCT_FD14_Segment_8_X2;
   v_Data_u16 =(uint16) ((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_X2,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_8_Y1 = (FD14_Segment_8_Y1 -  D_OFST_FD14_Segment_8_Y1)/ D_FCT_FD14_Segment_8_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_8_Y2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_8_Y2 = (FD14_Segment_8_Y2 -  D_OFST_FD14_Segment_8_Y2)/ D_FCT_FD14_Segment_8_Y2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8Y2-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_8_Y2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_8_Y2,v_Data_u16); // General: FD02 Common WRITE
   
   //D_DEBUG_WRITE_SIGNAL_TOCOM_FD14(FD14_SnrMeasDataChecksum,v_Data_u32); // General: FD14 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg1Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg1Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_1_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_1_Y1 = (FD14_Segment_1_Y1 -  D_OFST_FD14_Segment_1_Y1)/ D_FCT_FD14_Segment_1_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_1_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_1_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_2_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_2_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg2Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_2_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg2Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_3_Y1,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_3_Y1 = (FD14_Segment_3_Y1 -  D_OFST_FD14_Segment_3_Y1)/ D_FCT_FD14_Segment_3_Y1;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3Y1-(D_LMD_SEGMENT_Y_OFFSET))/D_LMD_SEGMENT_Y_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_3_Y1,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_3_Y1,v_Data_u16); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_ID,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg4Id); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_ID,LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg4Id); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD14(FD14_Segment_4_X2,v_Data_u16);
   // VT: FACT+OFFST :  FD14_Segment_4_X2 = (FD14_Segment_4_X2 -  D_OFST_FD14_Segment_4_X2)/ D_FCT_FD14_Segment_4_X2;
   v_Data_u16 = (uint16)((LMD_Outputs_CVPAMFDData2_Data.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4X2-(D_LMD_SEGMENT_X_OFFSET))/D_LMD_SEGMENT_X_FACTOR);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_Segment_4_X2,v_Data_u16); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(Segment_4_X2,v_Data_u16); // General: FD02 Common WRITE
}

static void TX_SafeVcan_FROMSWC_TOCOM_Process250_mSecSignal(void)
{
  /* DD-ID: {D2E49C34-A8BF-4688-9073-976B4F7A21F6}*/
   ME_VehOut_TRSC_t ME_VehOut_TRSC_Data;
   (void)Rte_Read_RpTRSC_ME_VehOut_TRSC_t(&ME_VehOut_TRSC_Data);
  //D_READ_SIGNAL_FROMSWC_FD14(FD14_ParkingManeuverActive,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD14(FD14_ParkingManeuverActive,TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv); // General: FD14 Common WRITE
   D_WRITE_SIGNAL_TOCOM_FD02(ParkingManeuverActive,TbAP_DriveAssistStatOut_Data.IeAP_e_ParKMnvrActv); // General: FD02 Common WRITE
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_CHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_CHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcCHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_CHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcCHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_CHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_CHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcCHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_CHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcCHR);
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_LHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_LHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcLHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_LHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcLHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_LHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_LHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcLHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_LHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcLHR);
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_RHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_RHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcRHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_RHF,TbAP_FPAWarnOut_Data.IeAP_e_DispArcRHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Alert_RHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Alert_RHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcRHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Alert_RHR,TbAP_RPAWarnOut_Data.IeAP_e_DispArcRHR);
   //D_READ_SIGNAL_FROMSWC_FD02(AUXCamsRQSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(AUXCamsRQSts,SvsToVCAN_Data.IeSVS_b_AUXCamReqSts); // ASIL: FD2 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02(ChimeActivation_LHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(ChimeActivation_LHF,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvLhf); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(ChimeActivation_LHF,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvLhf);
   //D_READ_SIGNAL_FROMSWC_FD02(ChimeActivation_LHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(ChimeActivation_LHR,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvLhr); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(ChimeActivation_LHR,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvLhr);
   //D_READ_SIGNAL_FROMSWC_FD02(ChimeActivation_RHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(ChimeActivation_RHF,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvRhf); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(ChimeActivation_RHF,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvRhf);
   //D_READ_SIGNAL_FROMSWC_FD02(ChimeActivation_RHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(ChimeActivation_RHR,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvRhr); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(ChimeActivation_RHR,TbFA_ArbiterOutput_Data.IeFA_b_ChimeActvRhr);
   //D_READ_SIGNAL_FROMSWC_FD02(DisplayView2,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(DisplayView2,SvsToVCAN_Data.IeSVS_e_DispView2); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(DisplayView2,SvsToVCAN_Data.IeSVS_e_DispView2); 
   //D_READ_SIGNAL_FROMSWC_FD02(FrontSensorSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(FrontSensorSts,TbAP_APSMPAOut_Data.IeAP_e_FrntSensorActvSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(FrontSensorSts,TbAP_APSMPAOut_Data.IeAP_e_FrntSensorActvSts);
   //D_READ_SIGNAL_FROMSWC_FD02(FT_PAM_LedControlSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(FT_PAM_LedControlSts,TbAP_PAStateOut_Data.IeAP_e_FrntParkLEDSts); // ASIL: FD2 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_CHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_CHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateCHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_CHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateCHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_CHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_CHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateCHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_CHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateCHR);
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_LHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_LHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateLHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_LHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateLHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_LHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_LHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateLHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_LHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateLHR);
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_RHF,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_RHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateRHF); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_RHF,TbAP_FPAWarnOut_Data.IeAP_e_ArcFlashRateRHF);
   //D_READ_SIGNAL_FROMSWC_FD02(Graphic_RHR,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(Graphic_RHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateRHR); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(Graphic_RHR,TbAP_RPAWarnOut_Data.IeAP_e_ArcFlashRateRHR);
   //D_READ_SIGNAL_FROMSWC_FD02HMICode,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(HMICode,TbAP_DriveAssistStatOut_Data.IeAP_e_HMIDispReq); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(HMICode,TbAP_DriveAssistStatOut_Data.IeAP_e_HMIDispReq);
   //D_READ_SIGNAL_FROMSWC_FD02(ImageDefeatRQSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(ImageDefeatRQSts,SvsToVCAN_Data.IeSVS_b_ImgDefeatReqSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(ImageDefeatRQSts,SvsToVCAN_Data.IeSVS_b_ImgDefeatReqSts);
   //D_READ_SIGNAL_FROMSWC_FD02(MoreCamsRQSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(MoreCamsRQSts,SvsToVCAN_Data.IeSVS_b_MoreCamsReqSts); // ASIL: FD2 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02(PAM_CHIME_REP_RATESts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_CHIME_REP_RATESts,TbFA_ArbiterOutput_Data.IeFA_e_PamChimeRepRateSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_CHIME_REP_RATESts,TbFA_ArbiterOutput_Data.IeFA_e_PamChimeRepRateSts);
   //D_READ_SIGNAL_FROMSWC_FD02(PAM_CHIME_TYPE,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_CHIME_TYPE,TbFA_ArbiterOutput_Data.IeFA_e_PamChimeTyp); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_CHIME_TYPE,TbFA_ArbiterOutput_Data.IeFA_e_PamChimeTyp);
   //D_READ_SIGNAL_FROMSWC_FD02(PAM_LedControlSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_LedControlSts,TbAP_PAStateOut_Data.IeAP_e_PAMLedCtrl); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_LedControlSts,TbAP_PAStateOut_Data.IeAP_e_PAMLedCtrl);
   D_READ_SIGNAL_FROMSWC_FD02(PAM_Off_Status,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_Off_Status,v_Data_u8); // ASIL: FD2 Not Common Write   /* Signal not availed in cdd_ipchandler*/
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_Off_Status,v_Data_u8);
   //D_READ_SIGNAL_FROMSWC_FD02(PAM_Off_Status_2BT,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_Off_Status_2BT,TbAP_APSMPAOut_Data.IeAP_e_FrntRearParkSts); // ASIL: FD2 Not Common Write
   //D_READ_SIGNAL_FROMSWC_FD02PAM_PopUpRqst,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_PopUpRqst,TbAP_PAStateOut_Data.IeAP_e_ParkSensePopUpReq); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_PopUpRqst,TbAP_PAStateOut_Data.IeAP_e_ParkSensePopUpReq);
   //D_READ_SIGNAL_FROMSWC_FD02(PAM_Volume,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAM_Volume,TbFA_ArbiterOutput_Data.IeFA_e_PamVol); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAM_Volume,TbFA_ArbiterOutput_Data.IeFA_e_PamVol);
   //D_READ_SIGNAL_FROMSWC_FD02(PAMSystemFault,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(PAMSystemFault,TbAP_APSMPAOut_Data.IeAP_e_PAMFlt); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(PAMSystemFault,TbAP_APSMPAOut_Data.IeAP_e_PAMFlt);
   //D_READ_SIGNAL_FROMSWC_FD02(RearSensorSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(RearSensorSts,TbAP_APSMPAOut_Data.IeAP_e_RearSnsrActvSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(RearSensorSts,TbAP_APSMPAOut_Data.IeAP_e_RearSnsrActvSts);
   //D_READ_SIGNAL_FROMSWC_FD02(SPM_LedControlSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(SPM_LedControlSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMLedSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(SPM_LedControlSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMLedSts);
   //D_READ_SIGNAL_FROMSWC_FD02(SPM_Screen_Rqst,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(SPM_Screen_Rqst,SvsToVCAN_Data.IeSVS_b_SPMScrnReq); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(SPM_Screen_Rqst,SvsToVCAN_Data.IeSVS_b_SPMScrnReq);
   //D_READ_SIGNAL_FROMSWC_FD02(SPMControlSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(SPMControlSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMActvStat); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(SPMControlSts,TbAP_DriveAssistStatOut_Data.IeAP_e_SPMActvStat);
   //D_READ_SIGNAL_FROMSWC_FD02S(PMFailSts,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(SPMFailSts,TbAP_DriveAssistStatOut_Data.IeAP_b_SPMFailSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(SPMFailSts,TbAP_DriveAssistStatOut_Data.IeAP_b_SPMFailSts);
   //D_READ_SIGNAL_FROMSWC_FD02(SPMSystemFault,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(SPMSystemFault,TbAP_DriveAssistStatOut_Data.IeAP_b_SPMFaultSts); // ASIL: FD2 Not Common Write
   D_WRITE_SIGNAL_TOSWC_FD02(SPMSystemFault,TbAP_DriveAssistStatOut_Data.IeAP_b_SPMFaultSts);
   //D_READ_SIGNAL_FROMSWC_FD02(TRSC_LED_Stat,v_Data_u8);
   D_WRITE_SIGNAL_TOCOM_FD02(TRSC_LED_Stat,ME_VehOut_TRSC_Data.IeTRSC_e_TRSCLedSts); // ASIL: FD2 Not Common Write
}

static void TX_SafeVcan_EVENT_RX_FROMCOM_TOSWC(void)
{
  /* DD-ID: {AB4795F4-1654-4519-8903-9A61074C52A7}*/
   sint8 v_cmpsts_s8;
   boolean v_CvPamflag_b = (boolean)FALSE;
   static TbAP_DriveAssistStatOut_t TbAP_DriveAssistStatOut_temp;
   static TbAP_APSMPAOut_t TbAP_APSMPAOut_temp;
   static TbAP_PAStateOut_t TbAP_PAStateOut_temp;
   static SvsToVCAN_t SvsToVCAN_temp;
   static TbAP_RPAWarnOut_t TbAP_RPAWarnOut_temp;
   static TbAP_FPAWarnOut_t TbAP_FPAWarnOut_temp;
   static TbFA_ArbiterOutput_t TbFA_ArbiterOutput_temp;
   v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbAP_DriveAssistStatOut_temp, &TbAP_DriveAssistStatOut_Data, sizeof(TbAP_DriveAssistStatOut_t));
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
   if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
   {
    TbAP_DriveAssistStatOut_temp = TbAP_DriveAssistStatOut_Data;
    v_CvPamflag_b = (boolean)TRUE;
   }
   else
   {
    v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbAP_APSMPAOut_temp, &TbAP_APSMPAOut_Data, sizeof(TbAP_APSMPAOut_t));
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
    if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
   /* VCAST Jenkins requirement - do not modify */
   /* VCAST Jenkins requirement - do not modify */
    {
      TbAP_APSMPAOut_temp = TbAP_APSMPAOut_Data;
      v_CvPamflag_b = (boolean)TRUE;
    }
    else
    {
      v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbAP_PAStateOut_temp, &TbAP_PAStateOut_Data, sizeof(TbAP_PAStateOut_t));
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
      /* VCAST Jenkins requirement - do not modify */
      /* VCAST Jenkins requirement - do not modify */
      {
          TbAP_PAStateOut_temp = TbAP_PAStateOut_Data;
          v_CvPamflag_b = (boolean)TRUE;
      }
      else
      {
          v_cmpsts_s8 = VStdLib_MemCmpLarge(&SvsToVCAN_temp, &SvsToVCAN_Data, sizeof(SvsToVCAN_t));
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
          if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
          /* VCAST Jenkins requirement - do not modify */
          /* VCAST Jenkins requirement - do not modify */
          {
              SvsToVCAN_temp = SvsToVCAN_Data;
              v_CvPamflag_b = (boolean)TRUE;
          }
          else
          {
              v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbAP_RPAWarnOut_temp, &TbAP_RPAWarnOut_Data, sizeof(TbAP_RPAWarnOut_t));
              /* VCAST Jenkins requirement - do not modify */
              /* VCAST Jenkins requirement - do not modify */
              if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
              /* VCAST Jenkins requirement - do not modify */
              /* VCAST Jenkins requirement - do not modify */
              {
                  TbAP_RPAWarnOut_temp = TbAP_RPAWarnOut_Data;
                  v_CvPamflag_b = (boolean)TRUE;
              }
              else
              {
                  v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbAP_FPAWarnOut_temp, &TbAP_FPAWarnOut_Data, sizeof(TbAP_FPAWarnOut_t));
                  /* VCAST Jenkins requirement - do not modify */
                  /* VCAST Jenkins requirement - do not modify */
                  if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
                  /* VCAST Jenkins requirement - do not modify */
                  /* VCAST Jenkins requirement - do not modify */                  {
                      TbAP_FPAWarnOut_temp = TbAP_FPAWarnOut_Data;
                      v_CvPamflag_b = (boolean)TRUE;
                  }
                  else
                  {
                      v_cmpsts_s8 = VStdLib_MemCmpLarge(&TbFA_ArbiterOutput_temp, &TbFA_ArbiterOutput_Data, sizeof(TbFA_ArbiterOutput_t));
                      /* VCAST Jenkins requirement - do not modify */
                      /* VCAST Jenkins requirement - do not modify */
                      if ((sint8)D_ZERO_VAL != v_cmpsts_s8)
                      /* VCAST Jenkins requirement - do not modify */
                      /* VCAST Jenkins requirement - do not modify */
                      {
                          TbFA_ArbiterOutput_temp = TbFA_ArbiterOutput_Data;
                          v_CvPamflag_b = (boolean)TRUE;
                      }
                      else
                      {
                        /*Do nothing*/
                      }
                  }
              }
          }
      }
    }
   }
   if ((boolean)TRUE == v_CvPamflag_b)
   {
    TX_SafeVcan_FROMSWC_TOCOM_Process250_mSecSignal();
   }
   else
   {
    /*Do Nothing*/
   }
}


static void TX_SafeVCANProcess(void)
{
  /* DD-ID: {D85AFB03-E7DE-42d8-B8B2-1B47E450F51C}*/
  uint8 reqItemIndex;
  static EventDataManage_t TX_SafeVCAN_EventDataManage[E_TX_SafeVCAN_Last_EventIndex] =
  {
      /*EventID		                                         isTriggered_b		       EventType_u8		       CounterValue_u32	  	PeriodicityTypes_u32	     	FuncPtrWrite*/
    { E_TX_SafeVcan_FROMSWC_TOCOM_Process10_mSecSignal,       0U,              D_TIME_TRIGGERED_EVENT,       0U,                  10u,                     &TX_SafeVcan_FROMSWC_TOCOM_Process10_mSecSignal },
    { E_TX_SafeVcan_FROMSWC_TOCOM_Process40_mSecSignal,       0U,              D_TIME_TRIGGERED_EVENT,       0U,                  40u,                     &TX_SafeVcan_FROMSWC_TOCOM_Process40_mSecSignal },
    { E_TX_SafeVcan_FROMSWC_TOCOM_Process250_mSecSignal,      0U,              D_TIME_TRIGGERED_EVENT,       0U,                  250u,                    &TX_SafeVcan_FROMSWC_TOCOM_Process250_mSecSignal },
    { E_TX_SafeVcan_EVENT_TX_FROMSWC_TOCOM,                   0U,              D_EXTERNAL_TRIGGERED_EVENT,   0U,                  0U,                      &TX_SafeVcan_EVENT_RX_FROMCOM_TOSWC },

  };

  for(reqItemIndex = (uint8)E_TX_SafeVcan_FROMSWC_TOCOM_Process10_mSecSignal; reqItemIndex < (uint8)E_TX_SafeVCAN_Last_EventIndex; reqItemIndex++)
  {
    if(TX_SafeVCAN_EventDataManage[reqItemIndex].EventType_u8 == (uint8)D_TIME_TRIGGERED_EVENT)
    {
          TX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32+=(uint32)TASKREPRATE;
          if(TX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32 >= TX_SafeVCAN_EventDataManage[reqItemIndex].PeriodicityTypes_u32)
          {
              TX_SafeVCAN_EventDataManage[reqItemIndex].CounterValue_u32 =(uint32)TASKREPRATE;
              TX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ONE;
          }
          else
          {
		     /*Do Nothing*/
          }
    }
    else if(TX_SafeVCAN_EventDataManage[reqItemIndex].EventType_u8 == (uint8)D_EXTERNAL_TRIGGERED_EVENT)
    {
      TX_SafeVCAN_EventDataManage[reqItemIndex].FuncPtrWrite();
    }
    else
    {
      /* Do Nothing */
    }
  }
  
  for(reqItemIndex = (uint8)e_ZERO; reqItemIndex < (uint8)E_TX_SafeVCAN_Last_EventIndex; reqItemIndex++)
  {
      if(TX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b == (uint8)e_ONE)
      {
          TX_SafeVCAN_EventDataManage[reqItemIndex].isTriggered_b = (uint8)e_ZERO;
          TX_SafeVCAN_EventDataManage[reqItemIndex].FuncPtrWrite();  
      }
     else
     {
	    /*Do Nothing*/
     }
  }
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {12BF7889-C47C-4ace-B389-3C715C8E13A6}*/
	Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx(PduId, PduInfoPtr);
	return TRUE;
}

FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /*DD-ID:{2A90B15B-AA85-4246-845C-EB2090A927FF}*/
	static E2E_MEP_ProtectStateType s_CheckStateType_FD2_CVPAM_FD_Control;
	(void)PduId;

	S_ConfigType_FD2_Write.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD2_Write.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD2_Write.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

	(void)Rte_Call_RpE2EServices_ME_E2E_Protect(&S_ConfigType_FD2_Write, &s_CheckStateType_FD2_CVPAM_FD_Control, PduInfoPtr->SduDataPtr);
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {889BE285-B51C-4d4e-B416-1303A8D1DF77}*/
	Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx(PduId, PduInfoPtr);
	return TRUE;
}

FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /*DD-ID:{427024E1-B9AB-40a6-996C-96FF307CA1B9}*/
	static E2E_MEP_ProtectStateType s_CheckStateType_FD2_CVPAM_FD_Info;
	(void)PduId;

	S_ConfigType_FD2_Write.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD2_Write.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD2_Write.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

	(void)Rte_Call_RpE2EServices_ME_E2E_Protect(&S_ConfigType_FD2_Write, &s_CheckStateType_FD2_CVPAM_FD_Info, PduInfoPtr->SduDataPtr);
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {886E6DBA-A974-4cb1-B145-29BFDADF5B48}*/
	Os_Call_SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx(PduId, PduInfoPtr);
	return TRUE;
}

FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {886E6DBA-A974-4cb1-B145-29BFDADF5B48}*/
  static E2E_MEP_ProtectStateType s_CheckStateType_FD14_CVPAM_FD_Control;
  (void)PduId;

  S_ConfigType_FD14_Write.DataLength = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;
  S_ConfigType_FD14_Write.CounterOffset = D_E2E_COUNTER_OFFSET_22 * D_CONVERT_BYTE_TO_BIT;
  S_ConfigType_FD14_Write.CRCOffset = D_E2E_CRC_OFFSET_23 * D_CONVERT_BYTE_TO_BIT;

  (void)Rte_Call_RpE2EServices_ME_E2E_Protect(&S_ConfigType_FD14_Write, &s_CheckStateType_FD14_CVPAM_FD_Control, PduInfoPtr->SduDataPtr);
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {6E2EF416-F291-4b3e-9772-59238C581776}*/
	Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx(PduId, PduInfoPtr);
	return TRUE;
}

FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {6E2EF416-F291-4b3e-9772-59238C581776}*/
	static E2E_MEP_ProtectStateType s_CheckStateType_FD14_ADAS_FD_LANES_1;
	(void)PduId;

	S_ConfigType_FD14_Write.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD14_Write.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD14_Write.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;

	(void)Rte_Call_RpE2EServices_ME_E2E_Protect(&S_ConfigType_FD14_Write, &s_CheckStateType_FD14_ADAS_FD_LANES_1, PduInfoPtr->SduDataPtr);
}

FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {199E3192-B28E-4d58-99EF-0DAD5F442C74}*/
	Os_Call_SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx(PduId, PduInfoPtr);
	return TRUE;
}

FUNC(void, COM_APPL_CODE) SafeVCANTx_ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  /* DD-ID: {199E3192-B28E-4d58-99EF-0DAD5F442C74}*/
	static E2E_MEP_ProtectStateType s_CheckStateType_FD14_ADAS_FD_LANES_2;
    (void)PduId;

	S_ConfigType_FD14_Write.DataLength = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD14_Write.CounterOffset = D_E2E_COUNTER_OFFSET_54 * D_CONVERT_BYTE_TO_BIT;
	S_ConfigType_FD14_Write.CRCOffset = D_E2E_CRC_OFFSET_55 * D_CONVERT_BYTE_TO_BIT;

	(void)Rte_Call_RpE2EServices_ME_E2E_Protect(&S_ConfigType_FD14_Write, &s_CheckStateType_FD14_ADAS_FD_LANES_2, PduInfoPtr->SduDataPtr);
}


#define SWC_SafeVCANTx_STOP_SEC_CODE
#include "SWC_SafeVCANTx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
