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
 *             File:  Cdd_RunTimeStats_QM.c
 *           Config:  C:/git/L2H4060_Software/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  Cdd_RunTimeStats_QM
 *  Generation Time:  2025-09-23 16:20:49
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <Cdd_RunTimeStats_QM>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Cdd_RunTimeStats_QM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "AddRuntimeStats.h"
#include "vstdlib.h"
#include "Enums.h"
#include "Os_Task_Types.h"
#include "Os_Task.h"
#include "Os.h"

#ifdef ADDRUNTIMESTATS
static void Cdd_RunTimeStats_QM_Start_Task(TaskType taskId);
static void Cdd_RunTimeStats_QM_Stop_Task(TaskType taskId);
#endif	
#define D_DEFAULT_FILL_PATTERN 0x00000004u
#define D_PERCENTAGE 100.0f

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
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 *
 * Array Types:
 * ============
 * RunTimeStatData: Array with 38 element(s) of type uint16
 * StackData_MCU1_0: Array with 19 element(s) of type float32
 *
 *********************************************************************************************************************/


#define Cdd_RunTimeStats_QM_START_SEC_CODE
#include "Cdd_RunTimeStats_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_ComTask_10ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_10ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_10ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_10ms_Start
 *********************************************************************************************************************/
/*DD-ID:{A515C0DE-2A21-4610-B2A1-C9933E76DEC0}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_ComTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_ComTask_10ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_10ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_10ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_10ms_Stop
 *********************************************************************************************************************/
/*DD-ID:{883E1F88-E548-409d-8171-B52F079D9FD9}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_ComTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_ComTask_5ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_5ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_5ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_5ms_Start
 *********************************************************************************************************************/
/*DD-ID:{C7C7FBFA-D3A8-40e7-9E58-BB1BCBE944D8}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_ComTask_5ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_ComTask_5ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_5ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_5ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_ComTask_5ms_Stop
 *********************************************************************************************************************/
	/*DD-ID:{E92F7B10-2640-45cb-A72F-DE807A00B6B5}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_ComTask_5ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_DiagTask_10ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_DiagTask_10ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_DiagTask_10ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_DiagTask_10ms_Start
 *********************************************************************************************************************/
/*DD-ID:{63BE2636-94CB-4d1d-9A6F-F0C49EC19A65}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_DiagTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_DiagTask_10ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_DiagTask_10ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_DiagTask_10ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_DiagTask_10ms_Stop
 *********************************************************************************************************************/
/*DD-ID:{3C776D6A-32FC-4043-855F-35BFADD07345}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_DiagTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_MemTask_10ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_MemTask_10ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_MemTask_10ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_MemTask_10ms_Start
 *********************************************************************************************************************/
	/*DD-ID:{08AE5401-9190-4204-AFC8-6CCE2EDF1344}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_MemTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_MemTask_10ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_MemTask_10ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_MemTask_10ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_MemTask_10ms_Stop
 *********************************************************************************************************************/
	/*DD-ID:{A92770D5-E0F1-4252-88B0-F5BE7578D702}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_MemTask_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_00_10ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_00_10ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_00_10ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_00_10ms_Start
 *********************************************************************************************************************/
/*DD-ID:{A1A3AE81-B812-4460-9453-2ABA491B323E}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_Task_00_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_00_10ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_00_10ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_00_10ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_00_10ms_Stop
 *********************************************************************************************************************/
/*DD-ID:{25FCC279-6206-4204-973E-F57074EE7C9D}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_Task_00_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_01_10ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_01_10ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_01_10ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_01_10ms_Start
 *********************************************************************************************************************/
/*DD-ID:{F29982E2-2463-4bb1-A42B-C7D854AE8D02}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_Task_01_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_01_10ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_01_10ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_01_10ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_01_10ms_Stop
 *********************************************************************************************************************/
/*DD-ID:{A5365D76-FD2B-45d9-B288-6A904047DB50}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_Task_01_10ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_200ms_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 200ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_200ms_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_200ms_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_200ms_Start
 *********************************************************************************************************************/
/*DD-ID:{B560DECA-D5FA-4409-9175-BAA82D108263}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_Task_200ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_200ms_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 200ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_200ms_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_200ms_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_200ms_Stop
 *********************************************************************************************************************/
/*DD-ID:{61EF0754-945D-4694-A118-2CFE8CA56760}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_Task_200ms);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_Init_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_Init_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_Init_Start(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_Init_Start
 *********************************************************************************************************************/
/*DD-ID:{345A22A0-E68F-4546-B4BA-CA3414B3F22F}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Start_Task(QM_Task_Init);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_RunTimeStats_QM_Task_Init_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_Init_Stop_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_Init_Stop(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_RunTimeStats_QM_Task_Init_Stop
 *********************************************************************************************************************/
/*DD-ID:{DDC08DF8-63CB-4438-BF23-202C0A565979}*/
#ifdef ADDRUNTIMESTATS
	Cdd_RunTimeStats_QM_Stop_Task(QM_Task_Init);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_GetTaskStackUsage_Data
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Data> of PortPrototype <PpGetTaskStackUsage>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpPerformanceStatsEnable_StackUsageStatsEnable(boolean *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_GetTaskStackUsage_Data(float32 *Stackusage)
 *     Argument Stackusage: float32* is of type StackData_MCU1_0
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GetTaskStackUsage_Data_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_GetTaskStackUsage_Data(P2VAR(float32, AUTOMATIC, RTE_CDD_RUNTIMESTATS_QM_APPL_VAR) Stackusage) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_GetTaskStackUsage_Data
 *********************************************************************************************************************/
	/*DD-ID:{6619A1E7-7B0D-41ad-B984-CA84B8B2F99F}*/
	static uint8 Idx = (uint8)e_ZERO;
	uint32 StackUsageData[OS_TASKID_COUNT];
    uint32 StackSize[OS_TASKID_COUNT];
	P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task;
	boolean StackUsageEnableFlag;

	(void)Rte_Read_RpPerformanceStatsEnable_StackUsageStatsEnable(&StackUsageEnableFlag);

	if(StackUsageEnableFlag == TRUE)
	{
		for(Idx=(uint8)e_ZERO; Idx<(uint8)OS_TASKID_COUNT; Idx++)
		{
		/*Read stack usage of all mcu1_0 tasks*/
		StackUsageData[Idx] = Os_GetTaskStackUsage(Idx);
		/*Read stack size of all mcu1_0 tasks*/
		Task = Os_TaskId2Task(Idx);
			if ((uint32)(Task->Thread.Stack->HighAddress) >= (uint32)(Task->Thread.Stack->LowAddress)) 
			{
				StackSize[Idx] = (uint32)(Task->Thread.Stack->HighAddress) - (uint32)(Task->Thread.Stack->LowAddress);
			}
			else 
			{
				StackSize[Idx] = (uint32)e_ZERO;
			}
			/*Read High addresss is having excluded FILL_PATTERN of 4 byte, so added 4byte here to match with exact stack size*/
			StackSize[Idx] = (uint32)StackSize[Idx] + (uint32)D_DEFAULT_FILL_PATTERN;
			/*Calculate stack usage in percentage*/
			Stackusage[Idx] = (((float32)StackUsageData[Idx] /(float32) StackSize[Idx]) * D_PERCENTAGE);
		}
	}
	else
	{
		for(Idx=(uint8)e_ZERO; Idx<(uint8)OS_TASKID_COUNT; Idx++)
		{
         (void)VStdLib_MemSet(&Stackusage[Idx],0, (sizeof(Stackusage)));
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PpRunTimeStatCSData_GetData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Cdd_RunTimeStatQM_GetData> of PortPrototype <PpRunTimeStatCSData>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RpPerformanceStatsEnable_RunTimeStatsEnable(boolean *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_PpRunTimeStatCSData_GetData(uint16 *runTimeDataVoid)
 *     Argument runTimeDataVoid: uint16* is of type RunTimeStatData
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PpRunTimeStatCSData_GetData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_PpRunTimeStatCSData_GetData(P2VAR(uint16, AUTOMATIC, RTE_CDD_RUNTIMESTATS_QM_APPL_VAR) runTimeDataVoid) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PpRunTimeStatCSData_GetData
 *********************************************************************************************************************/
	/*DD-ID:{83912426-8F1A-40ee-AD19-0550AD0EF698}*/
	uint8_t Idx1 = 0u;
	uint8_t Idx2 = 0u;
	uint16_t bAvgPeriodicity = 0u;
	uint16_t AverageTime = 0u;
	#ifdef ADDRUNTIMESTATS
	const AdditionalRuntimeStats_Log* runTimeStatDataPtr = AdditionalRuntimeStats_GetData();
	#endif
	boolean RuntimeStatsEnableFlag;

    /*Read runtimsstats are enable or disable*/
	(void)Rte_Read_RpPerformanceStatsEnable_RunTimeStatsEnable(&RuntimeStatsEnableFlag);

	if(TRUE == RuntimeStatsEnableFlag)
	{
		while(Idx2 < ((uint8_t)OS_TASKID_COUNT))
		{
			#ifdef ADDRUNTIMESTATS
			/*Read average periodicty & avarage time of each task*/
			bAvgPeriodicity = (uint16_t)(runTimeStatDataPtr->AddRuntimeStats_OsTask_Time[Idx2].bAveragePeriodicity_ms * 100.0f);
			AverageTime = (uint16_t)(runTimeStatDataPtr->AddRuntimeStats_OsTask_Time[Idx2].AverageTime_ms * 100.0f);
			#endif
			Idx2 =Idx2+(uint8)e_ONE;
            /*fill average periodicty & avarage time of each task in buffer to send to DIDs*/
			runTimeDataVoid[Idx1] = (uint16_t)((bAvgPeriodicity >> 8u) | (bAvgPeriodicity << 8u));
			Idx1 = Idx1+(uint8)e_ONE;
			runTimeDataVoid[Idx1] = (uint16_t)((AverageTime >> 8u) |  (AverageTime << 8u));
			Idx1 = Idx1+(uint8)e_ONE;
		}
	}
	else
	{
		/*clear average periodicty & avarage time of each task*/
		(void)VStdLib_MemSet(runTimeDataVoid, 0x00u, ((uint8_t)(OS_TASKID_COUNT) * 4u));
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Cdd_RunTimeStats_QM_STOP_SEC_CODE
#include "Cdd_RunTimeStats_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


static void Cdd_RunTimeStats_QM_Start_Task(TaskType taskId)
{
	/*DD-ID:{1C58106A-1A4E-4528-ACAC-BB06778A62A2}*/
	boolean enableFlag;
	(void)Rte_Read_RpPerformanceStatsEnable_RunTimeStatsEnable(&enableFlag);

	if(TRUE == enableFlag)
	{
		#ifdef ADDRUNTIMESTATS
		AdditionalRuntimeStats_Start_Task(taskId);
		#endif /*ADDRUNTIMESTATS*/
	}
}

static void Cdd_RunTimeStats_QM_Stop_Task(TaskType taskId)
{
	/*DD-ID:{E136D138-943E-4bd6-A7C9-C6FBB8047373}*/
	boolean enableFlag;
	(void)Rte_Read_RpPerformanceStatsEnable_RunTimeStatsEnable(&enableFlag);

	if(TRUE == enableFlag)
	{
		#ifdef ADDRUNTIMESTATS
		AdditionalRuntimeStats_Stop_Task(taskId);
		#endif /*ADDRUNTIMESTATS*/
	}
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
