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
 *             File:  ErrorMgrSat_1_0_B.c
 *           Config:  D:/CVADAS/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  ErrorMgrSat_1_0_B
 *  Generation Time:  2026-01-27 19:54:35
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <ErrorMgrSat_1_0_B>
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
 *
 * Runnable Entities:
 * ==================
 * RE_Init_ErrorMgrSat_1_0_B
 *   Init Runnable
 *
 * RE_Periodic_ErrorMgrSat_1_0_B
 *   Periodic Runnable of Satellite
 *
 * RE_ReportErrorStatus1_0_B
 *   Server Runnable for handling the error reporting
 *
 *********************************************************************************************************************/

#include "Rte_ErrorMgrSat_1_0_B.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "ErrorManager_Rte.h"
#include "ErrorManagerSatellite.h"



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
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Data1_0B_arr: Array with 400 element(s) of type ErrorMgr_stAddData
 * Data2_0B_arr: Array with 144 element(s) of type ErrorMgr_stAddData
 * Data2_1B_arr: Array with 548 element(s) of type ErrorMgr_stAddData
 * DataQNXB_arr: Array with 8 element(s) of type ErrorMgr_stAddData
 * Error1_0B_arr: Array with 400 element(s) of type ErrorMgr_ErrorField
 * Error2_0B_arr: Array with 144 element(s) of type ErrorMgr_ErrorField
 * Error2_1B_arr: Array with 548 element(s) of type ErrorMgr_ErrorField
 * ErrorQNXB_arr: Array with 8 element(s) of type ErrorMgr_ErrorField
 *
 * Record Types:
 * =============
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
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 *
 *********************************************************************************************************************/


#define ErrorMgrSat_1_0_B_START_SEC_CODE
#include "ErrorMgrSat_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Init_ErrorMgrSat_1_0_B
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrSat_1_0_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrSat_1_0_B_CODE) RE_Init_ErrorMgrSat_1_0_B(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Init_ErrorMgrSat_1_0_B
 *********************************************************************************************************************/
  /* DD-ID: {897642E6-6440-47a5-8DC2-DC1C4C1C8EE5}*/
  ErrorMgrSatellite_Init_B();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_ErrorMgrSat_1_0_B
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(const ErrorMgr_ErrorCommPack_1_0_B *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrSat_1_0_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, ErrorMgrSat_1_0_B_CODE) RE_Periodic_ErrorMgrSat_1_0_B(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_ErrorMgrSat_1_0_B
 *********************************************************************************************************************/
  /* DD-ID: {70C9751D-301F-42cb-B1A8-2E31DD43E262}*/
  ErrorMgrSatellite_PeriodicFunction_B();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_ReportErrorStatus1_0_B
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReportErrorStatus1_0_B> of PortPrototype <P_Error>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_P_Error_CS_E_NOK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ReportErrorStatus1_0_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, ErrorMgrSat_1_0_B_CODE) RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_ERRORMGRSAT_1_0_B_APPL_DATA) addData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_ReportErrorStatus1_0_B (returns application error)
 *********************************************************************************************************************/
  /*@GUID:-{C020CDB1-A367-4bc2-A3C3-2E9366602B34}*/
  /* DD-ID: {C020CDB1-A367-4bc2-A3C3-2E9366602B34}*/
  bool_t bRet;
  Std_ReturnType sRet;
  bRet=ErrorMgrSatellite_ReportErrorStatus((ldef_ErrorMgr_enErrorNo)err,(ldef_ErrorMgr_enErrorStatus)errStatus,(const ldef_ErrorMgr_stAddData*)addData);
  if(bRet == (bool_t)TRUE)
  {
    sRet=RTE_E_OK;
  }
  else 
  {
    sRet = E_NOT_OK;
  }
  
  return sRet;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ErrorMgrSat_1_0_B_STOP_SEC_CODE
#include "ErrorMgrSat_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
