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
 *             File:  Rte_CDD_Safety.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_Safety>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_SAFETY_H
# define RTE_CDD_SAFETY_H

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

# include "Rte_CDD_Safety_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_Safety_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_CDD_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpMPUFaultStatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpMPUFaultStatus_Sts(P2CONST(MpuFltSts, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpSDLFaultstatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpSDLFaultstatus_Sts(P2CONST(Status, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SystemState_SystemState Rte_Read_CDD_Safety_R_SystemState_SystemState


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpMPUFaultStatus_Sts Rte_Write_CDD_Safety_PpMPUFaultStatus_Sts
#  define Rte_Write_PpSDLFaultstatus_Sts Rte_Write_CDD_Safety_PpSDLFaultstatus_Sts


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_B_APPL_CODE) RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_QM_APPL_CODE) RE_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_CDD_PMICLastResetReason_BISTStatus_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)79, arg1))
#  define Rte_Call_R_Error_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_R_Error_QM_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Arr_2Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_CDD_PMICLastResetReason_BISTStatus_DefaultValue() (&(Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue[0]))
#  else
#   define Rte_CData_CDD_PMICLastResetReason_BISTStatus_DefaultValue() (&Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue)
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Arr_2Byte, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock() (&((*RtePim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock())[0]))
#  else
#   define Rte_Pim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock() RtePim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock()
#  endif
#  define RtePim_CDD_PMICLastResetReason_BISTStatus_MirrorBlock() \
  (&Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CDD_Safety_START_SEC_CODE
# include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDD_Safety_Init CDD_Safety_Init
#  define RTE_RUNNABLE_CDD_Safety_MainFunction CDD_Safety_MainFunction
# endif

FUNC(void, CDD_Safety_CODE) CDD_Safety_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_Safety_CODE) CDD_Safety_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CDD_Safety_STOP_SEC_CODE
# include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_SAFETY_H */

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
