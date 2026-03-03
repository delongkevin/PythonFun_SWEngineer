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
 *             File:  Rte_Safety_Guard.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <Safety_Guard>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SAFETY_GUARD_H
# define RTE_SAFETY_GUARD_H

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

# include "Rte_Safety_Guard_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeAction_FailSafe_State;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16;
extern VAR(uint16, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpSafeState2RSTReason_FaultEnum_u16 (0U)
#  define Rte_InitValue_R_SafeState2Reason_FaultEnum_u16 (0U)
#  define Rte_InitValue_RpFailsafeAction_FailSafe_State (0U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_R_SafeState_B_SafeStateOp(P2VAR(SafeStateOpDef, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_R_SafeState_QM_SafeStateOp(P2VAR(SafeStateOpDef, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2CONST(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2CONST(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2CONST(TbAP_PAStateOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t(P2CONST(SvsToVCAN_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(P2CONST(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Safety_Guard_SafetyGuard_SafeState_Mode_Mode(uint8 nextMode);

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SafeState2Reason_FaultEnum_u16 Rte_Read_Safety_Guard_R_SafeState2Reason_FaultEnum_u16
#  define Rte_Read_Safety_Guard_R_SafeState2Reason_FaultEnum_u16(data) (*(data) = Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_SafeState_B_SafeStateOp Rte_Read_Safety_Guard_R_SafeState_B_SafeStateOp
#  define Rte_Read_R_SafeState_QM_SafeStateOp Rte_Read_Safety_Guard_R_SafeState_QM_SafeStateOp
#  define Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Read_Safety_Guard_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Read_Safety_Guard_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Read_RpFailsafeAction_FailSafe_State Rte_Read_Safety_Guard_RpFailsafeAction_FailSafe_State
#  define Rte_Read_Safety_Guard_RpFailsafeAction_FailSafe_State(data) (*(data) = Rte_SWC_DIDMgr_PpFailsafeAction_FailSafe_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPAStateOut_TbAP_PAStateOut_t Rte_Read_Safety_Guard_RpPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpSvsToVCAN_SvsToVCAN_t Rte_Read_Safety_Guard_RpSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t Rte_Read_Safety_Guard_RpVCActuatorOut_TbAP_VCActuatorOut_t


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Write_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Write_PpSafeGuardPAStateOut_TbAP_PAStateOut_t Rte_Write_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t
#  define Rte_Write_PpSafeGuardSvsToVCAN_SvsToVCAN_t Rte_Write_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t
#  define Rte_Write_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t Rte_Write_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t
#  define Rte_Write_PpSafeState2RSTReason_FaultEnum_u16 Rte_Write_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16
#  define Rte_Write_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16(data) (Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_SafetyGuard_SafeState_Mode_Mode Rte_Switch_Safety_Guard_SafetyGuard_SafeState_Mode_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)72, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)72, arg1))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_SafeStat2_ResetReason_DefaultValue() (Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SafeStat2_ResetReason_MirrorBlock() \
  (&Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Safety_Guard_START_SEC_CODE
# include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SafetyGuard_Main SafetyGuard_Main
# endif

FUNC(void, Safety_Guard_CODE) SafetyGuard_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Safety_Guard_STOP_SEC_CODE
# include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SAFETY_GUARD_H */

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
