/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cdd_RunTimeStats_QM.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <Cdd_RunTimeStats_QM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_RUNTIMESTATS_QM_H
# define RTE_CDD_RUNTIMESTATS_QM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Cdd_RunTimeStats_QM_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RpPerformanceStatsEnable_RunTimeStatsEnable (FALSE)
#  define Rte_InitValue_RpPerformanceStatsEnable_StackUsageStatsEnable (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpPerformanceStatsEnable_RunTimeStatsEnable Rte_Read_Cdd_RunTimeStats_QM_RpPerformanceStatsEnable_RunTimeStatsEnable
#  define Rte_Read_Cdd_RunTimeStats_QM_RpPerformanceStatsEnable_RunTimeStatsEnable(data) (*(data) = Rte_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPerformanceStatsEnable_StackUsageStatsEnable Rte_Read_Cdd_RunTimeStats_QM_RpPerformanceStatsEnable_StackUsageStatsEnable
#  define Rte_Read_Cdd_RunTimeStats_QM_RpPerformanceStatsEnable_StackUsageStatsEnable(data) (*(data) = Rte_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable, ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define Cdd_RunTimeStats_QM_START_SEC_CODE
# include "Cdd_RunTimeStats_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_ComTask_10ms_Start Cdd_RunTimeStats_QM_ComTask_10ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_ComTask_10ms_Stop Cdd_RunTimeStats_QM_ComTask_10ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_ComTask_5ms_Start Cdd_RunTimeStats_QM_ComTask_5ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_ComTask_5ms_Stop Cdd_RunTimeStats_QM_ComTask_5ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_DiagTask_10ms_Start Cdd_RunTimeStats_QM_DiagTask_10ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_DiagTask_10ms_Stop Cdd_RunTimeStats_QM_DiagTask_10ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_MemTask_10ms_Start Cdd_RunTimeStats_QM_MemTask_10ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_MemTask_10ms_Stop Cdd_RunTimeStats_QM_MemTask_10ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_00_10ms_Start Cdd_RunTimeStats_QM_Task_00_10ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_00_10ms_Stop Cdd_RunTimeStats_QM_Task_00_10ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_01_10ms_Start Cdd_RunTimeStats_QM_Task_01_10ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_01_10ms_Stop Cdd_RunTimeStats_QM_Task_01_10ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_200ms_Start Cdd_RunTimeStats_QM_Task_200ms_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_200ms_Stop Cdd_RunTimeStats_QM_Task_200ms_Stop
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_Init_Start Cdd_RunTimeStats_QM_Task_Init_Start
#  define RTE_RUNNABLE_Cdd_RunTimeStats_QM_Task_Init_Stop Cdd_RunTimeStats_QM_Task_Init_Stop
#  define RTE_RUNNABLE_RE_GetTaskStackUsage_Data RE_GetTaskStackUsage_Data
#  define RTE_RUNNABLE_RE_PpRunTimeStatCSData_GetData RE_PpRunTimeStatCSData_GetData
# endif

FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_10ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_10ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_5ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_ComTask_5ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_DiagTask_10ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_DiagTask_10ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_MemTask_10ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_MemTask_10ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_00_10ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_00_10ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_01_10ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_01_10ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_200ms_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_200ms_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_Init_Start(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_RunTimeStats_QM_CODE) Cdd_RunTimeStats_QM_Task_Init_Stop(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_GetTaskStackUsage_Data(P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Stackusage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_GetTaskStackUsage_Data(P2VAR(StackData_MCU1_0, AUTOMATIC, RTE_VAR_NOINIT) Stackusage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_PpRunTimeStatCSData_GetData(P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) runTimeDataVoid); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Cdd_RunTimeStats_QM_CODE) RE_PpRunTimeStatCSData_GetData(P2VAR(RunTimeStatData, AUTOMATIC, RTE_VAR_NOINIT) runTimeDataVoid); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define Cdd_RunTimeStats_QM_STOP_SEC_CODE
# include "Cdd_RunTimeStats_QM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_RUNTIMESTATS_QM_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
