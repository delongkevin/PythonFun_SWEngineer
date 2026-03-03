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
 *             File:  ErrorMgrAgg_1_0_B.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  ErrorMgrAgg_1_0_B
 *  Generation Time:  2026-01-27 19:54:35
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <ErrorMgrAgg_1_0_B>
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
 * ErrorMgr_ErrorField
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
 * RE_Init_ErrorMgrAgg_1_0_B
 *   Init Runnable
 *
 * RE_Periodic_ErrorMgrAgg_1_0_B
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_ErrorMgrAgg_1_0_B.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManager_Rte.h"
#include "ErrorManager_RteOutStubs.h"

#define SIXTY_MS   6u
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
 * ErrorMgr_ErrorField: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Data1_0B_arr: Array with 400 element(s) of type ErrorMgr_stAddData
 * Data2_0B_arr: Array with 144 element(s) of type ErrorMgr_stAddData
 * Data2_1B_arr: Array with 548 element(s) of type ErrorMgr_stAddData
 * DataQNXB_arr: Array with 8 element(s) of type ErrorMgr_stAddData
 * Error1_0B_arr: Array with 400 element(s) of type ErrorMgr_ErrorField
 * Error2_0B_arr: Array with 144 element(s) of type ErrorMgr_ErrorField
 * Error2_1B_arr: Array with 548 element(s) of type ErrorMgr_ErrorField
 * ErrorListArr_B: Array with 35 element(s) of type uint32
 * ErrorQNXB_arr: Array with 8 element(s) of type ErrorMgr_ErrorField
 * SafeStateActive_arr: Array with 16 element(s) of type uint8
 *
 * Record Types:
 * =============
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
 * ErrorMgr_ErrorCommPack_1_0_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error1_0B_arr
 *   Data of type Data1_0B_arr
 * ErrorMgr_ErrorCommPack_2_0_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_0B_arr
 *   Data of type Data2_0B_arr
 * ErrorMgr_ErrorCommPack_2_1_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_1B_arr
 *   Data of type Data2_1B_arr
 * ErrorMgr_ErrorCommPack_QNX_B: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type ErrorQNXB_arr
 *   Data of type DataQNXB_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * SafeStateOpDef: Record with elements
 *   SafeStateActive of type SafeStateActive_arr
 *
 *********************************************************************************************************************/


#define ErrorMgrAgg_1_0_B_START_SEC_CODE
#include "ErrorMgrAgg_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Init_ErrorMgrAgg_1_0_B
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrAgg_1_0_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrAgg_1_0_B_CODE) RE_Init_ErrorMgrAgg_1_0_B(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrAgg_1_0_B
 *********************************************************************************************************************/
  /* DD-ID: {A988A37D-40A7-4d56-B5C6-30FBE7AFEC03}*/
  ErrorMgrAggregator_Init_B();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_ErrorMgrAgg_1_0_B
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
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(ErrorMgr_ErrorCommPack_1_0_B *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B(ErrorMgr_ErrorCommPack_2_0_B *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B(ErrorMgr_ErrorCommPack_2_1_B *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B(ErrorMgr_ErrorCommPack_QNX_B *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_DtcData_Data_DtcAddData_B(const DtcAddData_B *data)
 *   Std_ReturnType Rte_Write_P_DtcData_Data_DtcStatus_B(const DtcStatus_B *data)
 *   Std_ReturnType Rte_Write_P_Errors_B_Errors_B(const uint32 *data)
 *     Argument data: uint32* is of type ErrorListArr_B
 *   Std_ReturnType Rte_Write_P_SafeState_SafeStateOp(const SafeStateOpDef *data)
 *   Std_ReturnType Rte_Write_P_SafeState2Reason_FaultEnum_u16(uint16 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrAgg_1_0_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrAgg_1_0_B_CODE) RE_Periodic_ErrorMgrAgg_1_0_B(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrAgg_1_0_B
 *********************************************************************************************************************/
  /* DD-ID: {19390AB1-549B-49d1-8593-5474D86D0C3F}*/
  static boolean ErrorMgrAgg_1_0_B_Start_Periodic = FALSE;
  static uint8 ErrorMgrAgg_1_0_B_Counter = 0u;

  if(ErrorMgrAgg_1_0_B_Start_Periodic == TRUE)
  {
    ErrorMgrAggregator_B_PeriodicFunction();
  }
  else{
    ErrorMgrAgg_1_0_B_Counter++; /* PRQA 3383 *//* No functional impact. Does not increment beyond 6. */

    if(ErrorMgrAgg_1_0_B_Counter == SIXTY_MS)
    {
      ErrorMgrAgg_1_0_B_Start_Periodic = TRUE;
    }
    else{

    }

  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ErrorMgrAgg_1_0_B_STOP_SEC_CODE
#include "ErrorMgrAgg_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
