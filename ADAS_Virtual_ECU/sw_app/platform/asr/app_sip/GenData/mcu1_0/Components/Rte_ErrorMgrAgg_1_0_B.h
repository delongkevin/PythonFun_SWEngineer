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
 *             File:  Rte_ErrorMgrAgg_1_0_B.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <ErrorMgrAgg_1_0_B>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ERRORMGRAGG_1_0_B_H
# define RTE_ERRORMGRAGG_1_0_B_H

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

# include "Rte_ErrorMgrAgg_1_0_B_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_P_SafeState2Reason_FaultEnum_u16 (0U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(P2VAR(ErrorMgr_ErrorCommPack_1_0_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B(P2VAR(ErrorMgr_ErrorCommPack_2_0_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B(P2VAR(ErrorMgr_ErrorCommPack_2_1_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B(P2VAR(ErrorMgr_ErrorCommPack_QNX_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B(P2CONST(DtcAddData_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B(P2CONST(DtcStatus_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B(P2CONST(uint32, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B(P2CONST(ErrorListArr_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp(P2CONST(SafeStateOpDef, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B
#  define Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B
#  define Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B
#  define Rte_Read_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_DtcData_Data_DtcAddData_B Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B
#  define Rte_Write_P_DtcData_Data_DtcStatus_B Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B
#  define Rte_Write_P_Errors_B_Errors_B Rte_Write_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B
#  define Rte_Write_P_SafeState_SafeStateOp Rte_Write_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp
#  define Rte_Write_P_SafeState2Reason_FaultEnum_u16 Rte_Write_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16
#  define Rte_Write_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16(data) (Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16 = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define ErrorMgrAgg_1_0_B_START_SEC_CODE
# include "ErrorMgrAgg_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_Init_ErrorMgrAgg_1_0_B RE_Init_ErrorMgrAgg_1_0_B
#  define RTE_RUNNABLE_RE_Periodic_ErrorMgrAgg_1_0_B RE_Periodic_ErrorMgrAgg_1_0_B
# endif

FUNC(void, ErrorMgrAgg_1_0_B_CODE) RE_Init_ErrorMgrAgg_1_0_B(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ErrorMgrAgg_1_0_B_CODE) RE_Periodic_ErrorMgrAgg_1_0_B(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define ErrorMgrAgg_1_0_B_STOP_SEC_CODE
# include "ErrorMgrAgg_1_0_B_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ERRORMGRAGG_1_0_B_H */

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
