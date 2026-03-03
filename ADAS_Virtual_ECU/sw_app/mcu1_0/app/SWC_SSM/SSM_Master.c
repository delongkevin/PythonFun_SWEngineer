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
 *             File:  SSM_Master.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SSM_Master
 *  Generation Time:  2023-11-08 19:04:08
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SSM_Master>
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
 *
 * Runnable Entities:
 * ==================
 * RE_Periodic_SSM_Master
 *   Periodic Runnable of Satellite
 *
 *********************************************************************************************************************/

#include "Rte_SSM_Master.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SSM_Master.h"

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
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_ApplicationStatus: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_CoreSlaveCoreStateDef: Integer in interval [0...4294967295]
 * SSM_DegradedState: Integer in interval [0...4294967295]
 * SSM_SystemStateDef: Integer in interval [0...4294967295]
 * dtRef_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * SSM_MCU_1_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_0_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_2_1_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 * SSM_MCU_QNX_LocalAppStatus_Arr: Array with 20 element(s) of type SSM_ApplicationStatus
 *
 * Record Types:
 * =============
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


#define SSM_Master_START_SEC_CODE
#include "SSM_Master_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Periodic_SSM_Master
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
 *   Std_ReturnType Rte_Read_RpFailsafeDebug_Debugflag(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_SystemState_SystemState(const SSM_SystemState *data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_P_SSM_BSW_SystemState_Mode(uint8 mode)
 *   Modes of Rte_ModeType_SSM_SystemState_Mode:
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOTING
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_BOOT_ERROR
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_DEGRADED
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_IPCREADY
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_MAX
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_OFF
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_RUNNING
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SHUTTINGDOWN_REMOTECORES
 *   - RTE_MODE_SSM_SystemState_Mode_SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
 *   - RTE_TRANSITION_SSM_SystemState_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_R_IPC_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_SSM_Master_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SSM_Master_CODE) RE_Periodic_SSM_Master(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Periodic_SSM_Master
 *********************************************************************************************************************/
/*GUID:-*/
  /* DD-ID: {913FFE75-35EE-4366-AF5C-A2C3CBD31901}*/
SSM_Master_PeriodicRunnable();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SSM_Master_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SSM_Master_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SSM_Master_CODE) RE_SSM_Master_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SSM_Master_Init
 *********************************************************************************************************************/
	/*GUID:-*/
  /* DD-ID: {AAB40C99-DD05-44c6-9B43-CA969D1F09E6}*/
	(void)SSM_Master_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SSM_Master_STOP_SEC_CODE
#include "SSM_Master_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
