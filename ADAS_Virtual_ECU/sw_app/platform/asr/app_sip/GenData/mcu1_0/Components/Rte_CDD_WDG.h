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
 *             File:  Rte_CDD_WDG.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_WDG>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_WDG_H
# define RTE_CDD_WDG_H

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

# include "Rte_CDD_WDG_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeDebug_Debugflag;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RpFailsafeDebug_Debugflag (0U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpKeepAliveResponse_KeepAliveResponse_t(P2VAR(KeepAliveResponse_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpFailsafeDebug_Debugflag Rte_Read_CDD_WDG_RpFailsafeDebug_Debugflag
#  define Rte_Read_CDD_WDG_RpFailsafeDebug_Debugflag(data) (*(data) = Rte_SWC_DIDMgr_PpFailsafeDebug_Debugflag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t Rte_Read_CDD_WDG_RpKeepAliveResponse_KeepAliveResponse_t
#  define Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t
#  define Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t
#  define Rte_Read_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t Rte_Read_CDD_WDG_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceReg RE_MCUReadDeviceReg
#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceRegData RE_MCUReadDeviceRegData
#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUWriteDeviceReg RE_MCUWriteDeviceReg
#  define Rte_Call_WdgM_AliveSupervision_MCU1_0_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)0, arg1))
#  define Rte_Call_WdgM_AliveSupervision_MCU2_0_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)1, arg1))
#  define Rte_Call_WdgM_AliveSupervision_MCU2_1_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)2, arg1))
#  define Rte_Call_WdgM_AliveSupervision_MPU1_0_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)3, arg1))

# endif /* !defined(RTE_CORE) */


# define CDD_WDG_START_SEC_CODE
# include "CDD_WDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_WDG_Init RE_WDG_Init
#  define RTE_RUNNABLE_RE_WDG_Main RE_WDG_Main
# endif

FUNC(void, CDD_WDG_CODE) RE_WDG_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_WDG_CODE) RE_WDG_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CDD_WDG_STOP_SEC_CODE
# include "CDD_WDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK (1U)

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_WDG_H */

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
