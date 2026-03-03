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
/**        \file  vDiagSecAcc.h
 *        \brief  Security Access
 *
 *      \details  Implementation of the Security Access
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-06-09  visknb  SEC-1266      Initial creation
 *  01.01.00  2022-01-28  visknb  ESCAN00111067 Missing mapping of variables to memory sections
 *            2022-02-03  visknb  SEC-3631      Usage of <Mip>_MemMap
 *********************************************************************************************************************/

#if !defined (VDIAGSECACC_H)
# define VDIAGSECACC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vDiagSecAcc_Cfg.h"
 /* PRQA S 0292 EOF */ /* MD_VDIAGSECACC_CHARACTER_REQUIRED_FOR_VCA */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VDIAGSECACC_VENDOR_ID                                        (30u)
# define VDIAGSECACC_MODULE_ID                                        (0xFFu)
# define VDIAGSECACC_INSTANCE_ID                                      (0u)

/* AUTOSAR Software specification version information */
# define VDIAGSECACC_AR_RELEASE_MAJOR_VERSION                         (4u)
# define VDIAGSECACC_AR_RELEASE_MINOR_VERSION                         (3u)
# define VDIAGSECACC_AR_RELEASE_REVISION_VERSION                      (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VDIAGSECACC_SW_MAJOR_VERSION                                 (1u)
# define VDIAGSECACC_SW_MINOR_VERSION                                 (1u)
# define VDIAGSECACC_SW_PATCH_VERSION                                 (0u)

/* API service IDs */
# define VDIAGSECACC_SID_INIT                                         (0x00u)  /* Service ID: vDiagSecAcc_Init */
# define VDIAGSECACC_SID_INIT_MEMORY                                  (0x01u)  /* Service ID: vDiagSecAcc_InitMemory */
# define VDIAGSECACC_SID_GET_VERSION_INFO                             (0x02u)  /* Service ID: vDiagSecAcc_GetVersionInfo */
# define VDIAGSECACC_SID_GET_SEED                                     (0x03u)  /* Service ID: vDiagSecAcc_GetSeed */
# define VDIAGSECACC_SID_COMPARE_KEY                                  (0x04u)  /* Service ID: vDiagSecAcc_CompareKey */
# define VDIAGSECACC_SID_CALLBACKNOTIFICATION_CIPHER                  (0x05u)  /* Service ID: vDiagSecAcc_CallbackNotificationCipher */
# define VDIAGSECACC_SID_CALLBACKNOTIFICATION_RANDOMGENERATE          (0x06u)  /* Service ID: vDiagSecAcc_CallbackNotificationRandomGenerate */

/* Modes */
/* State: Uninitialized */
# define VDIAGSECACC_UNINIT                                           (0x00u)
/* State: Initialized */
# define VDIAGSECACC_INITIALIZED                                      (0x01u)

/* Development Error Types */
# ifndef VDIAGSECACC_E_NO_ERROR /* COV_VDIAGSECACC_LOCAL_DEFINE */
#  define VDIAGSECACC_E_NO_ERROR                                      (255u)
# endif
# ifndef VDIAGSECACC_E_UNINIT /* COV_VDIAGSECACC_LOCAL_DEFINE */
#  define VDIAGSECACC_E_UNINIT                                        (0u)
# endif
# ifndef VDIAGSECACC_E_INIT_FAILED /* COV_VDIAGSECACC_LOCAL_DEFINE */
#  define VDIAGSECACC_E_INIT_FAILED                                   (1u)
# endif
# ifndef VDIAGSECACC_E_PARAM_POINTER /* COV_VDIAGSECACC_LOCAL_DEFINE */
#  define VDIAGSECACC_E_PARAM_POINTER                                 (2u)
# endif
# ifndef VDIAGSECACC_E_PARAM_VALUE /* COV_VDIAGSECACC_LOCAL_DEFINE */
#  define VDIAGSECACC_E_PARAM_VALUE                                   (3u)
# endif

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

 /***********************************************************************************************************************
 *  vDiagSecAcc_Local_GetSeed
 **********************************************************************************************************************/
 /*! \brief       Get seed request handler
 *  \details     This function is internal and called only by an externally generated  function in vDiagSecAcc_Cfg.h.
 *  \param[in]   OpStatus     Current operation status of DCM
 *  \param[out]  Seed         Pointer to seed buffer
 *  \param[out]  ErrorCode    Error code for DCM
 *  \param[in]   levelIdx     Holds index of the security level.
 *  \return      E_OK           success
 *  \return      E_NOT_OK       failed
 *  \return      DCM_E_PENDING  Request pending.
 *  \pre         levelIdx     Needs to be a valid level idx.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_GetSeed(
  Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, VDIAGSECACC_APPL_VAR) Seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_APPL_VAR) ErrorCode,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx);

/***********************************************************************************************************************
 *  vDiagSecAcc_Local_CompareKey
 **********************************************************************************************************************/
/*! \brief       Compare key
 *  \details     Compare key against calculated one to grant security access. The algorithm is according to the specification.
 *               This function is internal and called only by an externally generated  function in vDiagSecAcc_Cfg.h.
 *  \param[in]   Key          Received key from tester
 *  \param[in]   OpStatus     operation status
 *  \param[out]  ErrorCode    Error code for DCM
 *  \param[in]   levelIdx     Holds index of the security level.
 *  \return      E_OK                      success
 *  \return      E_NOT_OK                  failed
 *  \return      DCM_E_COMPARE_KEY_FAILED  key compare failed
 *  \pre         levelIdx     Needs to be a valid level idx.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(Std_ReturnType, VDIAGSECACC_CODE) vDiagSecAcc_Local_CompareKey(
  P2CONST(uint8, AUTOMATIC, VDIAGSECACC_APPL_DATA) Key,
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, VDIAGSECACC_DCM_VAR) ErrorCode,
  vDiagSecAcc_SizeOfSecurityLevelType levelIdx);

/**********************************************************************************************************************
 * vDiagSecAcc_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes variables, which cannot be initialized with the startup code.
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_InitMemory(void);

/**********************************************************************************************************************
 * vDiagSecAcc_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     This function initializes the module vDiagSecAcc. It initializes all variables and sets the module state to
 *               initialized.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_Init(void);

# if (VDIAGSECACC_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vDiagSecAcc_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     vDiagSecAcc_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      VDIAGSECACC_VERSION_INFO_API == STD_ON
 *  \spec
 *    requires $valid(versioninfo);
 *  \endspec
 *********************************************************************************************************************/
FUNC(void, VDIAGSECACC_CODE) vDiagSecAcc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VDIAGSECACC_APPL_VAR) versioninfo);
# endif /* (VDIAGSECACC_VERSION_INFO_API == STD_ON) */

# define VDIAGSECACC_STOP_SEC_CODE
# include "vDiagSecAcc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VDIAGSECACC_H */
/**********************************************************************************************************************
 *  END OF FILE: vDiagSecAcc.h
 *********************************************************************************************************************/
