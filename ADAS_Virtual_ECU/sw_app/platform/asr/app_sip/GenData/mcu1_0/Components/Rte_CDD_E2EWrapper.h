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
 *             File:  Rte_CDD_E2EWrapper.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_E2EWrapper>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_E2EWRAPPER_H
# define RTE_CDD_E2EWRAPPER_H

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

# include "Rte_CDD_E2EWrapper_Type.h"
# include "Rte_DataHandleType.h"


# define CDD_E2EWrapper_START_SEC_CODE
# include "CDD_E2EWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_E2EWrapperCheck RE_E2EWrapperCheck
#  define RTE_RUNNABLE_RE_E2EWrapperProtect RE_E2EWrapperProtect
#  define RTE_RUNNABLE_RE_E2EWrapper_Init RE_E2EWrapper_Init
# endif

FUNC(Std_ReturnType, CDD_E2EWrapper_CODE) RE_E2EWrapperCheck(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_VAR_NOINIT) ConfigPtr, P2VAR(E2E_MEP_CheckStateType, AUTOMATIC, RTE_VAR_NOINIT) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CDD_E2EWrapper_CODE) RE_E2EWrapperProtect(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_VAR_NOINIT) ConfigPtr, P2VAR(E2E_MEP_ProtectStateType, AUTOMATIC, RTE_VAR_NOINIT) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CDD_E2EWrapper_CODE) RE_E2EWrapper_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CDD_E2EWrapper_STOP_SEC_CODE
# include "CDD_E2EWrapper_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL (19U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG (23U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INTERR (25U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE (26U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_E2EWRAPPER_H */

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
