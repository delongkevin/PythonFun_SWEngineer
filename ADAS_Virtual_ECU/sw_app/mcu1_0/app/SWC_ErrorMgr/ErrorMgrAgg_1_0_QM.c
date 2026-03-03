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
 *             File:  ErrorMgrAgg_1_0_QM.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  ErrorMgrAgg_1_0_QM
 *  Generation Time:  2024-02-08 15:53:28
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <ErrorMgrAgg_1_0_QM>
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
 * RE_Init_ErrorMgrAgg_1_0_QM
 *   Init Runnable
 *
 * RE_Periodic_ErrorMgrAgg_1_0_QM
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_ErrorMgrAgg_1_0_QM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "ErrorManagerTypes.h"
#include "ErrorManagerAggregator.h"
#include "ErrorManager_Rte.h"
#include "ErrorManager_RteOutStubs.h"

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
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Data1_0QM_arr: Array with 12 element(s) of type ErrorMgr_stAddData
 * Data2_0QM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * Data2_1QM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * DataQNXQM_arr: Array with 1 element(s) of type ErrorMgr_stAddData
 * Error1_0QM_arr: Array with 12 element(s) of type ErrorMgr_ErrorField
 * Error2_0QM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * Error2_1QM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * ErrorListArr_QM: Array with 1 element(s) of type uint32
 * ErrorQNXQM_arr: Array with 1 element(s) of type ErrorMgr_ErrorField
 * Padding2_0QM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * Padding2_1QM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * PaddingQNXQM_arr: Array with 3 element(s) of type ErrorMgr_ErrorField
 * SafeStateActive_arr: Array with 16 element(s) of type uint8
 *
 * Record Types:
 * =============
 * DtcAddData_QM: Record with elements
 *   u0151_0_0 of type AdditionalData_arr
 *   u12b9_0_0 of type AdditionalData_arr
 *   u14a0_0_0 of type AdditionalData_arr
 *   u0455_0_0 of type AdditionalData_arr
 * DtcStatus_QM: Record with elements
 *   u0151_0_0 of type uint8
 *   u12b9_0_0 of type uint8
 *   u14a0_0_0 of type uint8
 *   u0455_0_0 of type uint8
 * ErrorMgr_ErrorCommPack_1_0_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error1_0QM_arr
 *   Data of type Data1_0QM_arr
 * ErrorMgr_ErrorCommPack_2_0_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_0QM_arr
 *   Padding of type Padding2_0QM_arr
 *   Data of type Data2_0QM_arr
 * ErrorMgr_ErrorCommPack_2_1_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type Error2_1QM_arr
 *   Padding of type Padding2_1QM_arr
 *   Data of type Data2_1QM_arr
 * ErrorMgr_ErrorCommPack_QNX_QM: Record with elements
 *   RunningCounter of type uint32
 *   Checksum of type uint32
 *   Error of type ErrorQNXQM_arr
 *   Padding of type PaddingQNXQM_arr
 *   Data of type DataQNXQM_arr
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * SafeStateOpDef: Record with elements
 *   SafeStateActive of type SafeStateActive_arr
 *
 *********************************************************************************************************************/


#define ErrorMgrAgg_1_0_QM_START_SEC_CODE
#include "ErrorMgrAgg_1_0_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Init_ErrorMgrAgg_1_0_QM
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrAgg_1_0_QM_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrAgg_1_0_QM_CODE) RE_Init_ErrorMgrAgg_1_0_QM(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrAgg_1_0_QM
 *********************************************************************************************************************/
  /* DD-ID: {C988BC1E-23AB-41ba-94CD-E4F0318200F5}*/
  ErrorMgrAggregator_Init_QM();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_ErrorMgrAgg_1_0_QM
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
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM(ErrorMgr_ErrorCommPack_1_0_QM *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_QM(ErrorMgr_ErrorCommPack_2_0_QM *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_QM(ErrorMgr_ErrorCommPack_2_1_QM *data)
 *   Std_ReturnType Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_QM(ErrorMgr_ErrorCommPack_QNX_QM *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_DtcData_Data_DtcAddData_QM(const DtcAddData_QM *data)
 *   Std_ReturnType Rte_Write_P_DtcData_Data_DtcStatus_QM(const DtcStatus_QM *data)
 *   Std_ReturnType Rte_Write_P_Errors_QM_Errors_QM(const uint32 *data)
 *     Argument data: uint32* is of type ErrorListArr_QM
 *   Std_ReturnType Rte_Write_P_SafeState_SafeStateOp(const SafeStateOpDef *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrAgg_1_0_QM_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrAgg_1_0_QM_CODE) RE_Periodic_ErrorMgrAgg_1_0_QM(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrAgg_1_0_QM
 *********************************************************************************************************************/
  /* DD-ID: {A8A1EF57-1709-4496-85F6-08D53D49BD5D}*/
  ErrorMgrAggregator_QM_PeriodicFunction();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ErrorMgrAgg_1_0_QM_STOP_SEC_CODE
#include "ErrorMgrAgg_1_0_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
