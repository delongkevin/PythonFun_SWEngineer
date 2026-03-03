/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  vDiagSecAcc_Cbk.h
 *        \brief  Security Access Callback Declaration
 *
 *      \details  Declaration of Callback function for Security Access
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VDIAGSECACC_CBK_H)
# define VDIAGSECACC_CBK_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vDiagSecAcc_Cfg.h"
# include "Csm_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VDIAGSECACC_START_SEC_CODE
# include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON)
/***********************************************************************************************************************
 *  vDiagSecAcc_CallbackNotificationRandomGenerate
 **********************************************************************************************************************/
/*! \brief       Callback Notification
 *  \details     Notifies the vDiagSecAcc that the random generate job has finished. This function is used by the underlying CSM.
 *  \param[in]   job          Contains the CSM job.
 *  \param[in]   result       Contains the result of the cryptographic operation.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      VDIAGSECACC_CSM_ASYNC_RANDOM_GENERATE == STD_ON
 **********************************************************************************************************************/
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_CallbackNotificationRandomGenerate( P2VAR(Crypto_JobType, AUTOMATIC, VDIAGSECACC_APPL_VAR) job, Std_ReturnType result); /* PRQA S 3449, 3451 */ /* MD_VDIAGSECACC_GLOBAL_CBK_FUNC */
# endif

# if (VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON)
/***********************************************************************************************************************
 *  vDiagSecAcc_CallbackNotificationCipher
 **********************************************************************************************************************/
/*! \brief       Callback Notification
 *  \details     Notifies the vDiagSecAcc that the cipher job has finished. This function is used by the underlying CSM.
 *  \param[in]   job          Contains the CSM job.
 *  \param[in]   result       Contains the result of the cryptographic operation.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      VDIAGSECACC_CSM_ASYNC_COMPARE_KEY == STD_ON
 **********************************************************************************************************************/
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_CallbackNotificationCipher( P2VAR(Crypto_JobType, AUTOMATIC, VDIAGSECACC_APPL_VAR) job, Std_ReturnType result); /* PRQA S 3449, 3451 */ /* MD_VDIAGSECACC_GLOBAL_CBK_FUNC */
# endif

# define VDIAGSECACC_STOP_SEC_CODE
# include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VDIAGSECACC_CBK_H */
/**********************************************************************************************************************
 *  END OF FILE: vDiagSecAcc_Cbk.h
 *********************************************************************************************************************/
