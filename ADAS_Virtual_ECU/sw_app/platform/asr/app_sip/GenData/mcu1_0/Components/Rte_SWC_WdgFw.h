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
 *             File:  Rte_SWC_WdgFw.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_WdgFw>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_WDGFW_H
# define RTE_SWC_WDGFW_H

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

# include "Rte_SWC_WdgFw_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_R_WdgM_AliveSupervision_Safety_Com_Task_10ms_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)6, arg1))
#  define Rte_Call_R_WdgM_AliveSupervision_Safety_Task_00_10ms_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)4, arg1))
#  define Rte_Call_R_WdgM_AliveSupervision_Safety_Task_01_10ms_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)5, arg1))
#  define Rte_Call_R_WdgM_AliveSupervision_Safety_Task_200ms_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)7, arg1))

# endif /* !defined(RTE_CORE) */


# define SWC_WdgFw_START_SEC_CODE
# include "SWC_WdgFw_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_WdgFw_10ms WdgFw_10ms
#  define RTE_RUNNABLE_WdgFw_Safety_Task_00_10ms_CP_10ms WdgFw_Safety_Task_00_10ms_CP_10ms
#  define RTE_RUNNABLE_WdgFw_Safety_Task_01_10ms_CP_10ms WdgFw_Safety_Task_01_10ms_CP_10ms
#  define RTE_RUNNABLE_WdgFw_Safety_Task_200ms_CP_200ms WdgFw_Safety_Task_200ms_CP_200ms
#  define RTE_RUNNABLE_WdgFw_Safety_Task_Com_10ms_CP_10ms WdgFw_Safety_Task_Com_10ms_CP_10ms
#  define RTE_RUNNABLE_WdgM_MainFunction_Call_Cntr_10ms WdgM_MainFunction_Call_Cntr_10ms
# endif

FUNC(void, SWC_WdgFw_CODE) WdgFw_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_00_10ms_CP_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_01_10ms_CP_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_200ms_CP_200ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_WdgFw_CODE) WdgFw_Safety_Task_Com_10ms_CP_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_WdgFw_CODE) WdgM_MainFunction_Call_Cntr_10ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_WdgFw_STOP_SEC_CODE
# include "SWC_WdgFw_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_WDGFW_H */

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
