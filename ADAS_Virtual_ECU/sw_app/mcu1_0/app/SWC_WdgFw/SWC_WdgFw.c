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
 *             File:  SWC_WdgFw.c
 *           Config:  D:/Git/DT_WS_1/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_WdgFw
 *  Generation Time:  2025-01-23 18:05:51
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_WdgFw>
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
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_WdgFw.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Wdg.h"
#include "pmic.h"
#include "WdgSlave.h"

static void WdgM_f_CpReached_v(UINT32 *b_prevCntr_u32, UINT32 i_taskFreq_u32, UINT32 i_taskId_u32);

/* Task ID */
#define D_Safety_Task_00_10_ID              (0)
#define D_Safety_Task_01_10_ID              (1)
#define D_Safety_Com_Task_01_10_ID          (3)
#define D_Safety_Task_200_ID                (4)

/* #define D_TASK_ASILB_SAFESIGHNDLR_10MS_ID    (2) */
/* #define D_TASK_ASILB_TX_ID                   (3) */

/* Task call frequency */
#define D_WDGM_TASK_FREQ                     (10U)  /* WdgM_MainFunction() */
#define D_Safety_Task_00_10_FREQ             (10)
#define D_Safety_Task_01_10_FREQ             (10)
#define D_Safety_Com_Task_10_FREQ            (10)
#define D_Safety_Task_200_FREQ               (200)

/* #define D_TASK_ASILB_SAFESIGHNDLR_10MS_FREQ  (10) */
/* #define D_TASK_ASILB_TX_FREQ                 (10) */
#define INCREMENT_BY_ONE                     (1u)

#define SWC_WdgFw_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WdgFw_MemMap.h" 
/* WdgM_MainFunction() function call counter */
static UINT32 V_WdgmMainFuncCallCntr_u32 = 0u;
#define SWC_WdgFw_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WdgFw_MemMap.h" 



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
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 *
 *********************************************************************************************************************/


#define SWC_WdgFw_START_SEC_CODE
#include "SWC_WdgFw_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgFw_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_R_WdgM_AliveSupervision_Safety_Com_Task_10ms_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_R_WdgM_AliveSupervision_Safety_Task_00_10ms_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_R_WdgM_AliveSupervision_Safety_Task_01_10ms_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *   Std_ReturnType Rte_Call_R_WdgM_AliveSupervision_Safety_Task_200ms_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgFw_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_10ms
 *********************************************************************************************************************/
  /* DD-ID: {3FA1933E-EB7E-4a4a-AD65-E16AC5E65357}*/


    /* WDG scheduled function */   
    Wdg_Trigger(); 
    Pmic_F_MainTask_v();
        /* WDG Slave scheduled function */
    WdgSlave_F_MainFunc_v();  

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgFw_Safety_Task_00_10ms_CP_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_00_10ms_CP_10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_00_10ms_CP_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_00_10ms_CP_10ms
 *********************************************************************************************************************/
  /* DD-ID: {878EB0BB-DE6D-4eca-96A7-961EE6ED623E}*/

    static UINT32 V_WdgmMainFuncCallCntrPrev_u32 = 0u;

    /* Call Checkpoint Reached function -> This will decide how many time need to mark checkpoint reached */
   WdgM_f_CpReached_v(&V_WdgmMainFuncCallCntrPrev_u32, (UINT32)D_Safety_Task_00_10_FREQ, (UINT32)D_Safety_Task_00_10_ID);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgFw_Safety_Task_01_10ms_CP_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_01_10ms_CP_10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_01_10ms_CP_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_01_10ms_CP_10ms
 *********************************************************************************************************************/
  /* DD-ID: {56F12C76-08A7-4dde-964B-07026C3815D8}*/

    static UINT32 V_WdgmMainFuncCallCntrPrev_u32 = 0u;
    /* Call Checkpoint Reached function -> This will decide how many time need to mark checkpoint reached */
    WdgM_f_CpReached_v(&V_WdgmMainFuncCallCntrPrev_u32, (UINT32)D_Safety_Task_01_10_FREQ, (UINT32)D_Safety_Task_01_10_ID); 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgFw_Safety_Task_200ms_CP_200ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 200ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_200ms_CP_200ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_200ms_CP_200ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_200ms_CP_200ms
 *********************************************************************************************************************/
   /* DD-ID: {A17C0DA1-3C18-409d-9AC9-7D9502ECA225}*/
    static UINT32 V_WdgmMainFuncCallCntrPrev_u32 = 0u;
    /* Call Checkpoint Reached function -> This will decide how many time need to mark checkpoint reached */
    WdgM_f_CpReached_v(&V_WdgmMainFuncCallCntrPrev_u32, (UINT32)D_Safety_Task_200_FREQ, (UINT32)D_Safety_Task_200_ID); 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgFw_Safety_Task_Com_10ms_CP_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_Com_10ms_CP_10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_Com_10ms_CP_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgFw_Safety_Task_Com_10ms_CP_10ms
 *********************************************************************************************************************/
  /* DD-ID: {A2A901AE-3F74-4221-B69F-0AF9789A1F07}*/
    static UINT32 V_WdgmMainFuncCallCntrPrev_u32 = 0u;
    /* Call Checkpoint Reached function -> This will decide how many time need to mark checkpoint reached */
    WdgM_f_CpReached_v(&V_WdgmMainFuncCallCntrPrev_u32, (UINT32)D_Safety_Com_Task_10_FREQ, (UINT32)D_Safety_Com_Task_01_10_ID); 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_MainFunction_Call_Cntr_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction_Call_Cntr_10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_WdgFw_CODE) WdgM_MainFunction_Call_Cntr_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction_Call_Cntr_10ms
 *********************************************************************************************************************/
  /* DD-ID: {240B03E4-D9A3-4e21-A298-760CB80C1D4F}*/
    /* IMP NOTE -> This function must be called just after WdgM_MainFunction() */
    /* Increment counter for WdgM_MainFunction() function call */
    V_WdgmMainFuncCallCntr_u32 = V_WdgmMainFuncCallCntr_u32 + INCREMENT_BY_ONE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SWC_WdgFw_STOP_SEC_CODE
#include "SWC_WdgFw_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


static void WdgM_f_CpReached_v(UINT32 *b_prevCntr_u32, UINT32 i_taskFreq_u32, UINT32 i_taskId_u32)
{
  /* DD-ID: {6D418C09-E6D8-4904-A853-84983FCF5A2A}*/
    UINT32 V_WdgmMainFuncCallCntrNew_u32;
    UINT32 v_CpReachedCallCntr_u32;
    UINT32 v_idx_u32;

    /* Get current counter value of WdgM main function call */
    V_WdgmMainFuncCallCntrNew_u32 = V_WdgmMainFuncCallCntr_u32;

    /* How many time CP reached function need to call? */
    /* Note -> In case this task's freq is not same as WdgM main function's Freq 
       -> Devide below variable by (This task Freq/10) => 10 is WdgM main function call freq */
    v_CpReachedCallCntr_u32 = (UINT32)(V_WdgmMainFuncCallCntrNew_u32 -  *b_prevCntr_u32)/(i_taskFreq_u32/(UINT32)D_WDGM_TASK_FREQ);

    /* If WdgM Main function gets called single or multiple time from last call of this task for respective task */
    if (v_CpReachedCallCntr_u32 > (UINT32)0U)
    {
        /* Mark checkpoint progress mutiple time based on call counter value */
        for (v_idx_u32 = 0; v_idx_u32 < v_CpReachedCallCntr_u32; v_idx_u32++)
        {
            /* Mark Checkpoint Reached */
            switch (i_taskId_u32)
            {
                case D_Safety_Task_00_10_ID:
                {
                    (void)Rte_Call_R_WdgM_AliveSupervision_Safety_Task_00_10ms_CheckpointReached(0);
                    
                    break;
                }
                case D_Safety_Task_01_10_ID:
                {
                    (void)Rte_Call_R_WdgM_AliveSupervision_Safety_Task_01_10ms_CheckpointReached(0); 
                    break;
                }
                case D_Safety_Com_Task_01_10_ID:
                {
                    (void)Rte_Call_R_WdgM_AliveSupervision_Safety_Com_Task_10ms_CheckpointReached(0); 
                    break;
                }
                case D_Safety_Task_200_ID:
                {
                    (void)Rte_Call_R_WdgM_AliveSupervision_Safety_Task_200ms_CheckpointReached(0);
                    break;
                }                
                default:
                {
                    /* Do nothing */
                    break;
                }
            }
        }
        /* Update previous counter with new counter */
        *b_prevCntr_u32 = V_WdgmMainFuncCallCntrNew_u32 ;
    } else{ /* Do Nothing */ }
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
